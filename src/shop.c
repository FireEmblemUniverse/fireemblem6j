#include "prelude.h"
#include "shop.h"
#include "ui.h"
#include "msg.h"
#include "util.h"
#include "bmio.h"
#include "mapui.h"
#include "item.h"
#include "talk.h"
#include "gold.h"
#include "mu.h"
#include "event.h"
#include "action.h"
#include "sound.h"
#include "supply.h"
#include "chapter.h"
#include "icon.h"
#include "oam.h"
#include "helpbox.h"
#include "manim.h"
#include "sprite.h"
#include "armfunc.h"

#include "constants/iids.h"
#include "constants/faces.h"
#include "constants/msg.h"
#include "constants/songs.h"

static struct Text Text_GoldBox;

u16 CONST_DATA gDefaultShopItems[] = {
	IID_IRONSWORD,
	IID_IRONLANCE,
	IID_IRONAXE,
	IID_IRONBOW,
	IID_FIRE,
	IID_HEALSTAFF,

	IID_NONE
};

int CONST_DATA gShopDislogueIdx[SHOP_TYPE_MAX] = {
	[SHOP_TYPE_ARMORY]	  = 0,
	[SHOP_TYPE_VENDOR]	  = 1,
	[SHOP_TYPE_SECRET_SHOP] = 2,
};

int CONST_DATA gShopFaces[SHOP_TYPE_MAX] = {
	[SHOP_TYPE_ARMORY]	  = FID_B9,
	[SHOP_TYPE_VENDOR]	  = FID_BB,
	[SHOP_TYPE_SECRET_SHOP] = FID_BC,
};

struct ProcScr CONST_DATA ProcScr_ShopFadeIn[] =
{
	PROC_CALL(LockGame),
	PROC_SLEEP(1),
	PROC_CALL_ARG(_FadeBgmOut, -1),
	PROC_CALL(StartMidFadeToBlack),
	PROC_REPEAT(WhileFadeExists),
	PROC_CALL(LockBmDisplay),
	PROC_END,
};

struct ProcScr CONST_DATA ProcScr_ShopFadeOut[] =
{
	PROC_CALL(ClearTalk),
	PROC_CALL(UnlockBmDisplay),
	PROC_CALL(InitBmDisplay),
	PROC_CALL(StartMapSongBgm),
	PROC_CALL(StartMidFadeFromBlack),
	PROC_REPEAT(WhileFadeExists),
	PROC_CALL(UnlockGame),
	PROC_END,
};

struct ProcScr CONST_DATA ProcScr_Shop[] =
{
	PROC_CALL(StartShopFadeIn),
	PROC_YIELD,
	PROC_CALL(Shop_Start),
	PROC_CALL(Shop_InitBuyState),
	PROC_START_CHILD(ProcScr_ShopDrawHand),
	PROC_CALL(FadeInBlackSpeed20),
	PROC_SLEEP(1),
	PROC_CALL(Shop_EntryDialogue),

PROC_LABEL(PL_SHOP_ENTRY),
	PROC_SLEEP(1),
	PROC_REPEAT(Shop_HandleEntryDialoguePrompt),

PROC_LABEL(PL_SHOP_BUY),
	PROC_CALL(Shop_BuyDialogue),

PROC_LABEL(PL_SHOP_BUY_MAIN),
	PROC_CALL(Shop_InitBuyState),
	PROC_SLEEP(1),
	PROC_REPEAT(Shop_Loop_BuyKeyHandler),
	PROC_CALL(Shop_HandleBuyConfirmPrompt),
	PROC_GOTO(PL_SHOP_SENDTO_INVENTORY),

PROC_LABEL(PL_SHOP_BUY_DONE),
	PROC_CALL(Shop_AnythingElseDialogue),
	PROC_GOTO(PL_SHOP_BUY_MAIN),

PROC_LABEL(PL_SHOP_SELL),
	PROC_CALL(Shop_SellDialogue),

PROC_LABEL(PL_SHOP_SELL_MAIN),
	PROC_CALL(Shop_InitSellState),
	PROC_SLEEP(1),
	PROC_REPEAT(Shop_Loop_SellKeyHandler),
	PROC_CALL(Shop_HandleSellConfirmPrompt),
	PROC_SLEEP(2),
	PROC_CALL(Shop_SellAnythingElseDialogue),
	PROC_GOTO(PL_SHOP_SELL_MAIN),

PROC_LABEL(PL_SHOP_SELL_NOITEM),
	PROC_SLEEP(2),
	PROC_CALL(Shop_AnythingElseRestartDialogue),
	PROC_GOTO(PL_SHOP_ENTRY),

PROC_LABEL(PL_SHOP_ANYTHING_ELSE),
	PROC_SLEEP(1),
	PROC_CALL(Shop_AnythingElseContinueDialogue),
	PROC_GOTO(PL_SHOP_ENTRY),

PROC_LABEL(PL_SHOP_SENDTO_INVENTORY),
	PROC_CALL(Shop_TryAddItemToInventory),
	PROC_YIELD,
	PROC_CALL(Shop_HandleSendToConvoyPrompt),
	PROC_YIELD,
	PROC_CALL(Shop_CheckIfConvoyFull),
	PROC_CALL(Shop_ConvoyFullDialogue),
	PROC_YIELD,
	PROC_GOTO(PL_SHOP_SELL_NOITEM),

PROC_LABEL(PL_SHOP_SENDTO_INVENTORY_EXT),
	PROC_CALL(Shop_AddItemToConvoy),
	PROC_YIELD,
	PROC_CALL(Shop_SendToConvoyDialogue),
	PROC_YIELD,
	PROC_GOTO(PL_SHOP_BUY_DONE),

PROC_LABEL(PL_SHOP_BUY_FULL_NO_INEVNTORY),
	PROC_YIELD,
	PROC_CALL(Shop_NoSendToConvoyDialogue),
	PROC_YIELD,
	PROC_GOTO(PL_SHOP_SELL_NOITEM),

PROC_LABEL(PL_SHOP_EXIT),
	PROC_CALL(Shop_ExitShopDialogue),
	PROC_SLEEP(1),
	PROC_CALL_ARG(_FadeBgmOut, 2),
	PROC_CALL(FadeInBlackWithCallBack_Speed20),
	PROC_SLEEP(1),
	PROC_CALL(Shop_OnExit),
	PROC_END_EACH(ProcScr_ShopDrawHand),
	PROC_CALL(StartShopFadeOut),
	PROC_YIELD,
	PROC_END,
};

struct ProcScr CONST_DATA ProcScr_ShopBuyInit[] = {
	PROC_REPEAT(InitShopBuyStatus),
	PROC_END,
};

struct ProcScr CONST_DATA ProcScr_ShopSellInit[] = {
	PROC_REPEAT(InitShopSellStatus),
	PROC_END,
};

u16 CONST_DATA Sprite_ShopGoldBox[] = {
	9,
	OAM0_SHAPE_32x8, OAM1_SIZE_32x8, OAM2_LAYER(1),
	OAM0_SHAPE_16x8, OAM1_SIZE_16x8 + OAM1_X(32), OAM2_CHR(0x2) + OAM2_LAYER(1),
	OAM0_SHAPE_16x8, OAM1_SIZE_16x8 + OAM1_X(48), OAM2_CHR(0x4) + OAM2_LAYER(1),
	OAM0_SHAPE_32x8 + OAM0_Y(8), OAM1_SIZE_32x8, OAM2_CHR(0x6) + OAM2_LAYER(1),
	OAM0_SHAPE_16x8 + OAM0_Y(8), OAM1_SIZE_16x8 + OAM1_X(32), OAM2_CHR(0x8) + OAM2_LAYER(1),
	OAM0_SHAPE_16x8 + OAM0_Y(8), OAM1_SIZE_16x8 + OAM1_X(48), OAM2_CHR(0xA) + OAM2_LAYER(1),
	OAM0_SHAPE_32x8 + OAM0_Y(16), OAM1_SIZE_32x8, OAM2_CHR(0xC) + OAM2_LAYER(1),
	OAM0_SHAPE_16x8 + OAM0_Y(16), OAM1_SIZE_16x8 + OAM1_X(32), OAM2_CHR(0xE) + OAM2_LAYER(1),
	OAM0_SHAPE_16x8 + OAM0_Y(16), OAM1_SIZE_16x8 + OAM1_X(48), OAM2_CHR(0x10) + OAM2_LAYER(1),
};

struct ProcScr CONST_DATA ProcScr_GoldBox[] = {
	PROC_REPEAT(GoldBox_OnLoop),
	PROC_END,
};

struct ProcScr CONST_DATA ProcScr_ShopDrawHand[] = {
	PROC_REPEAT(Shop_DisplayShopUiArrows),
};

EWRAM_DATA  struct Text gShopItemTexts[SHOP_TEXT_LINES + 1] = {};
EWRAM_DATA static struct ShopState sShopSt = {};
CONST_DATA struct ShopState *gpShopSt = &sShopSt;

EWRAM_DATA int gShopHandLocBak = 0;

int GetShopFace(struct ProcShop *proc)
{
	return gShopFaces[proc->shopType];
}

void StartShopDialogue(int msg, struct ProcShop *proc)
{
	int msgId = msg + gShopDislogueIdx[proc->shopType];

	SetInitTalkTextFont();
	ClearTalkText();

	StartTalkExt(8, 2, DecodeMsg(msgId), proc);

	SetTalkPrintColor(TEXT_COLOR_SYSTEM_WHITE);

	SetTalkFlag(TALK_FLAG_INSTANTSHIFT);
	SetTalkFlag(TALK_FLAG_NOBUBBLE);
	SetTalkFlag(TALK_FLAG_NOSKIP);

	SetActiveTalkFace(TALK_FACE_1);
}

void StartDefaultArmoryScreen(struct Unit *unit, ProcPtr proc)
{
	StartShopScreen(unit, NULL, SHOP_TYPE_ARMORY, proc);
}

void StartArmoryScreenOrphaned(struct Unit *unit, u16 const * iid_list)
{
	StartShopScreen(unit, iid_list, SHOP_TYPE_ARMORY, NULL);
}

void StartVendorScreenOrphaned(struct Unit *unit, u16 const * iid_list)
{
	StartShopScreen(unit, iid_list, SHOP_TYPE_VENDOR, NULL);
}

void StartSecretShopScreenOrphaned(struct Unit *unit, u16 const * iid_list)
{
	StartShopScreen(unit, iid_list, SHOP_TYPE_SECRET_SHOP, NULL);
}

void StartArmoryScreen(struct Unit *unit, u16 const * iid_list)
{
	StartShopScreen(unit, iid_list, SHOP_TYPE_ARMORY, NULL);
}

void StartShopScreen(struct Unit *unit, u16 const *iid_list, u8 shopType, ProcPtr parent)
{
	struct ProcShop *proc;
	const u16 *items;
	int i;

	EndMapUi();

	if (parent)
		proc = SpawnProcLocking(ProcScr_Shop, parent);
	else
		proc = SpawnProc(ProcScr_Shop, PROC_TREE_3);

	proc->shopType = shopType;
	proc->unit = unit;

	if (iid_list != NULL)
		items = iid_list;
	else
		items = gDefaultShopItems;

	for (i = 0; i <= SHOP_ITEMS_MAX_AMT; i++)
		proc->shopItems[i] = CreateItem(*items++);

	UpdateShopItemCounts(proc);
}

void UpdateShopItemCounts(struct ProcShop *proc)
{
	int i;
	for (i = 0; proc->shopItems[i] != 0; i++);

	proc->shopItemCount = i;
	proc->unitItemCount = GetUnitItemCount(proc->unit);
}

void TalkChoice_OnBuy(void)
{
	struct ProcShop *proc = FindProc(ProcScr_Shop);
	if (proc->buy_or_sel == SHOP_ST_BUY)
		return;

	ShopInitTexts_OnBuy(proc);
}

void TalkChoice_OnSell(void)
{
	struct ProcShop *proc = FindProc(ProcScr_Shop);
	if (proc->buy_or_sel == SHOP_ST_SELL)
		return;

	ShopInitTexts_OnSell(proc);
}

void Shop_EntryDialogue(struct ProcShop *proc)
{
	StartShopDialogue(MSG_SHOP_00, proc);
}

void Shop_HandleEntryDialoguePrompt(struct ProcShop *proc)
{
	switch (GetTalkChoiceResult()) {
	case TALK_CHOICE_CANCEL:
	default:
		Proc_Goto(proc, PL_SHOP_EXIT);
		return;

	case TALK_CHOICE_YES:
		Proc_Goto(proc, PL_SHOP_BUY);
		return;

	case TALK_CHOICE_NO:
		if (GetUnitItemCount(proc->unit) == 0) {
			StartShopDialogue(MSG_SHOP_12, proc);
			Proc_Goto(proc, PL_SHOP_SELL_NOITEM);
		} else
			Proc_Goto(proc, PL_SHOP_SELL);
	}
}

void Shop_BuyDialogue(struct ProcShop *proc)
{
	StartShopDialogue(MSG_SHOP_09, proc);
}

void ShopDrawBuyItemLine(struct ProcShop *_proc, int list_idx)
{
	struct ProcShop *proc = _proc;
	int index, item;

	index = DivRem(list_idx, 6);

	SetTextFont(NULL);
	InitSystemTextFont();

	EnableBgSync(BG2_SYNC_BIT);

	ClearText(&gShopItemTexts[index]);

	item = proc->shopItems[list_idx];
	if (item == 0)
		return;

	DrawShopItemPriceLine(
		&gShopItemTexts[index],
		item,
		proc->unit,
		gBg2Tm + TM_OFFSET(7, (list_idx * 2 & 0x1F))
	);
}

void ShopDrawSellItemLine(struct ProcShop *_proc, int list_idx)
{
	struct ProcShop *proc = _proc;
	int index, item;

	index = DivRem(list_idx, 6);

	SetTextFont(NULL);
	InitSystemTextFont();

	EnableBgSync(BG2_SYNC_BIT);

	ClearText(&gShopItemTexts[index]);

	item = proc->shopItems[list_idx];
	if (item == 0)
		return;

	DrawShopItemLine(
		&gShopItemTexts[index],
		item,
		proc->unit,
		gBg2Tm + TM_OFFSET(7, (list_idx * 2 & 0x1F))
	);
}

void Shop_InitBuyState(struct ProcShop *proc)
{
	RegisterShopState(
		proc->head_idx,
		proc->shopItemCount,
		5,
		proc->hand_idx,
		72,
		ShopDrawBuyItemLine,
		proc);
}

void Shop_Loop_BuyKeyHandler(struct ProcShop *proc)
{
	bool cursor_at_head;
	int price;

	cursor_at_head = FALSE;

	Shop_TryMoveHandPage();

	SetBgOffset(2, 0, ShopSt_GetBg2Offset());

	if (proc->head_loc != ShopSt_GetHeadLoc())
		cursor_at_head = TRUE;

	proc->head_loc = ShopSt_GetHeadLoc();
	proc->hand_loc = ShopSt_GetHandLoc();

	proc->head_idx = proc->head_loc;
	proc->hand_idx = proc->hand_loc;

	PutUiHand(0x38, proc->head_loc * 16 + 72 - proc->hand_loc * 16);

	if ((proc->helpTextActive != 0) && (cursor_at_head != 0)) {
		StartItemHelpBox(56, proc->head_loc * 16 + 72 - proc->hand_loc * 16, proc->shopItems[proc->head_loc]);
	}

	DisplayShopUiArrows();

	if (IsShopPageScrolling() != 0)
		return;

	if (proc->helpTextActive != 0) {
		if (gKeySt->pressed & (KEY_BUTTON_B | KEY_BUTTON_R)) {
			proc->helpTextActive = 0;
			CloseHelpBox();
		}

		return;
	} else {
		if (gKeySt->pressed & KEY_BUTTON_R) {
			proc->helpTextActive = 1;
			StartItemHelpBox(56, proc->head_loc * 16 + 72 - proc->hand_loc * 16, proc->shopItems[proc->head_loc]);
			return;
		}
	}

	price = GetItemPurchasePrice(proc->unit, proc->shopItems[proc->head_loc]);

	if (gKeySt->pressed & KEY_BUTTON_A) {
		if (price > GetGold()) {
			StartShopDialogue(0x2DB, proc);
			Proc_Goto(proc, 1);
		} else {
			SetTalkNumber(price);
			StartShopDialogue(0x2DE, proc);
			Proc_Break(proc);
		}
		return;
	}

	if (gKeySt->pressed & KEY_BUTTON_B) {
		PlaySe(0x6B);
		Proc_Goto(proc, PL_SHOP_SELL_NOITEM);
		return;
	}
}

void Shop_HandleBuyConfirmPrompt(struct ProcShop *proc)
{
	switch (GetTalkChoiceResult()) {
	case TALK_CHOICE_YES:
		break;

	case TALK_CHOICE_CANCEL:
	case TALK_CHOICE_NO:
	default:
		Proc_Goto(proc, PL_SHOP_BUY);
		break;

	}
}

void Shop_TryAddItemToInventory(struct ProcShop *proc)
{
	if (proc->unitItemCount >= ITEMSLOT_INV_COUNT) {
		StartShopDialogue(MSG_SHOP_24, proc);
		return;
	}

	UnitAddItem(proc->unit, proc->shopItems[proc->head_loc]);
	HandleShopBuyAction(proc);
	Proc_Goto(proc, PL_SHOP_BUY_DONE);
}

void Shop_HandleSendToConvoyPrompt(struct ProcShop *proc)
{
	switch (GetTalkChoiceResult()) {
	case TALK_CHOICE_YES:
		break;

	case TALK_CHOICE_CANCEL:
	case TALK_CHOICE_NO:
	default:
		Proc_Goto(proc, PL_SHOP_BUY_FULL_NO_INEVNTORY);
		break;

	}
}

void Shop_NoSendToConvoyDialogue(struct ProcShop *proc)
{
	StartShopDialogue(MSG_SHOP_2A, proc);
}

void Shop_AddItemToConvoy(struct ProcShop *proc)
{
	AddSupplyItem(proc->shopItems[proc->head_loc]);
	HandleShopBuyAction(proc);
}

void Shop_SendToConvoyDialogue(struct ProcShop *proc)
{
	StartShopDialogue(MSG_SHOP_27, proc);
}

void Shop_CheckIfConvoyFull(struct ProcShop *proc)
{
	if (CountSupplyItems() < SUPPLY_ITEM_COUNT)
		Proc_Goto(proc, PL_SHOP_SENDTO_INVENTORY_EXT);
}

void Shop_ConvoyFullDialogue(struct ProcShop *proc)
{
	StartShopDialogue(MSG_SHOP_2D, proc);
}

void Shop_AnythingElseDialogue(struct ProcShop *proc)
{
	StartShopDialogue(MSG_SHOP_0C, proc);
}

void Shop_SellDialogue(struct ProcShop *proc)
{
	StartShopDialogue(MSG_SHOP_0F, proc);
}

void Shop_InitSellState(struct ProcShop *proc)
{
	RegisterShopState(
		proc->head_loc,
		proc->unitItemCount,
		5,
		0,
		72,
		ShopDrawSellItemLine,
		proc);
}

void Shop_Loop_SellKeyHandler(struct ProcShop *proc)
{
	bool cursor_at_head;

	cursor_at_head = false;
	Shop_TryMoveHandPage();

	SetBgOffset(BG_2, 0, ShopSt_GetBg2Offset());

	if (proc->head_loc != ShopSt_GetHeadLoc())
		cursor_at_head = true;

	proc->head_loc = ShopSt_GetHeadLoc();
	proc->hand_loc = ShopSt_GetHandLoc();


	PutUiHand(56, (proc->head_loc * 16) + 0x48 - (proc->hand_loc * 16));

	if (proc->helpTextActive && (cursor_at_head != 0))
		StartItemHelpBox(56, (proc->head_loc * 16) + 0x48 - (proc->hand_loc * 16), proc->unit->items[proc->head_loc]);

	if (IsShopPageScrolling() != 0)
		return;

	if (proc->helpTextActive) {
		if (gKeySt->pressed & (KEY_BUTTON_B | KEY_BUTTON_R)) {
			proc->helpTextActive = false;
			CloseHelpBox();
		}
		return;
	} else if (gKeySt->pressed & KEY_BUTTON_R) {
		proc->helpTextActive = true;
		StartItemHelpBox(56, (proc->head_loc * 16) + 0x48 - (proc->hand_loc * 16), proc->unit->items[proc->head_loc]);
		return;
	}


	if (gKeySt->pressed & KEY_BUTTON_A) {
		if (!IsItemSellable(proc->unit->items[proc->head_loc])) {
			StartShopDialogue(MSG_SHOP_21, proc);
			Proc_Goto(proc, PL_SHOP_SELL);
		} else {
			SetTalkNumber(GetItemSellPrice(proc->unit->items[proc->head_loc]));
			StartShopDialogue(MSG_SHOP_1B, proc);
			Proc_Break(proc);
		}
		return;
	}

	if (gKeySt->pressed & KEY_BUTTON_B) {
		PlaySe(SONG_6B);
		Proc_Goto(proc, PL_SHOP_ANYTHING_ELSE);
		return;
	}
}

void Shop_HandleSellConfirmPrompt(struct ProcShop *proc)
{
	int gold;

	switch (GetTalkChoiceResult()) {
	case TALK_CHOICE_YES:
		PlaySeDelayed(SONG_B9, 8);

		gAction.id = ACTION_SHOPPED;

		gold = GetGold();
		gold = gold + GetItemSellPrice(proc->unit->items[proc->head_loc]);
		SetGold(gold);

		UnitRemoveItem(proc->unit, proc->head_loc);

		UpdateShopItemCounts(proc);
		ShopInitTexts_OnSell(proc);
		DisplayGoldBoxText(gBg0Tm + TM_OFFSET(0x1B, 6));

		if (proc->unitItemCount == 0) {
			Proc_Goto(proc, PL_SHOP_SELL_NOITEM);
			break;
		}

		break;

	case TALK_CHOICE_CANCEL:
	case TALK_CHOICE_NO:
	default:
		Proc_Goto(proc, PL_SHOP_SELL);
		return;
	}
}

void Shop_SellAnythingElseDialogue(struct ProcShop *proc)
{
	StartShopDialogue(MSG_SHOP_15, proc);
}

void Shop_AnythingElseRestartDialogue(struct ProcShop *proc)
{
	proc->head_loc = 0;
	StartShopDialogue(MSG_SHOP_03, proc);
}

void Shop_AnythingElseContinueDialogue(struct ProcShop *proc)
{
	StartShopDialogue(MSG_SHOP_06, proc);
}

void Shop_ExitShopDialogue(struct ProcShop *proc)
{
	StartShopDialogue(MSG_SHOP_1E, proc);
}

void Shop_OnExit(struct ProcShop *proc)
{
	Proc_EndEach(ProcScr_GoldBox);
	Proc_ForEach(ProcScr_Mu, (ProcFunc)ShowMu);
}

void StartShopFadeIn(struct ProcShop *proc)
{
	if (!(gBmSt.flags & BM_FLAG_PREP))
		SpawnProcLocking(ProcScr_ShopFadeIn, proc);
}

void StartShopFadeOut(struct ProcShop *proc)
{
	if (!(gBmSt.flags & BM_FLAG_PREP))
		SpawnProcLocking(ProcScr_ShopFadeOut, proc);
	else
		ClearTalk();
}

void Shop_Start(struct ProcShop *proc)
{
	int i;

	StartBgm(SONG_38, NULL);
	Proc_ForEach(ProcScr_Mu, (ProcFunc)HideMu);

	InitShopScreenConfig();

	gDispIo.bg0_ct.priority = 0;
	gDispIo.bg1_ct.priority = 2;
	gDispIo.bg2_ct.priority = 0;
	gDispIo.bg3_ct.priority = 3;

	InitTalk(BGCHR_SHOP_TALKTEXT, 2, 0);
	InitFaces();

	proc->head_loc = 0;
	proc->head_idx = 0;
	proc->hand_idx = 0;
	proc->hand_loc = 0;
	proc->buy_or_sel = SHOP_ST_BUY;
	proc->helpTextActive = 0;

	UnpackUiVArrowGfx(OBJCHR_SHOP_SPINARROW, OBJPAL_SHOP_SPINARROW);
	StartTalkFace(GetShopFace(proc), 32, 8, 3, 1);
	Decompress(Tsa_ShopWindows, gBuf);
	TmApplyTsa(gBg1Tm, gBuf, 0x1000);
	PutUiWindowFrame(6, 8, 20, 12, 0);
	EnableBgSync(BG1_SYNC_BIT);

	StartUiGoldBox(proc);

	for (i = 0; i <= SHOP_TEXT_LINES; i++)
		InitText(&gShopItemTexts[i], 20);

	DrawShopSoldItems(proc);

	SetWinEnable(1, 1, 0);
	SetWin0Layers(1, 1, 1, 1, 1);
	SetWin1Layers(1, 1, 0, 1, 1);
	SetWOutLayers(1, 1, 0, 1, 1);

	SetWin0Box(56, 72, 240, 152);
	SetWin1Box(0, 8, 240, 56);

	gDispIo.win_ct.win0_enable_blend = 0;
	gDispIo.win_ct.win1_enable_blend = 1;
	gDispIo.win_ct.wout_enable_blend = 0;

	SetBlendConfig(3, 0, 0, 8);

	SetBlendTargetA(0, 0, 0, 1, 0);
	SetBlendTargetB(0, 0, 0, 0, 0);

	Decompress(Img_MuralBackground, (void *)BG_VRAM + GetBgChrOffset(BG_3));
	TmApplyTsa(gBg3Tm, Tsa_CommGameBgScreenInShop, OAM2_PAL(BGPAL_SHOP_MAINBG1));
	ApplyPalettes(Pal_CommGameBgScreenInShop, BGPAL_SHOP_MAINBG2, 2);

	EnableBgSync(BG3_SYNC_BIT);
}

void StartUiGoldBox(ProcPtr parent)
{
	struct ProcShop *proc;

	Decompress(Img_ShopGoldBox, OBJ_VRAM0 + OBJCHR_SHOP_GOLDBOX * CHR_SIZE);

	proc = SpawnProc(ProcScr_GoldBox, parent);
	proc->goldbox_x = 0xAC;
	proc->goldbox_y = 0x2C;
	proc->goldbox_oam2 = OAM2_PAL(OBJPAL_SHOP_GOLDBOX) + OAM2_CHR(OBJCHR_SHOP_GOLDBOX);
	ApplyPalette(Pal_UiWindowFrame_ThemeBlue, 0x10 + OBJPAL_SHOP_GOLDBOX);
	InitGoldBoxText(gBg0Tm + TM_OFFSET(28, 6));
	DisplayGoldBoxText(gBg0Tm + TM_OFFSET(27, 6));
}

void InitGoldBoxText(u16 *tm)
{
	SetTextFont(NULL);
	InitSystemTextFont();
	InitText(&Text_GoldBox, 1);
	PutString(tm, TEXT_COLOR_SYSTEM_GOLD, "Ｇ");
}

void ClearGoldBoxTextTm2Line(u16 * tm, int col)
{
	while (col > 0)
	{
		*tm = 0;
		*(tm + 0x20) = 0;

		tm--;
		col--;
	}
}

void DisplayGoldBoxText(u16 *tm)
{
	SetTextFont(NULL);
	InitSystemTextFont();
	ClearGoldBoxTextTm2Line(tm, SHOP_TEXT_LINES + 1);
	PutNumber(tm, 2, GetGold());
	EnableBgSync(BG0_SYNC_BIT);
}

void ShopInitTexts_OnBuy(struct ProcShop *parent)
{
	int i, tmp;
	struct ProcShopInit *proc;

	parent->buy_or_sel = SHOP_ST_BUY;

	proc = SpawnProc(ProcScr_ShopBuyInit, PROC_TREE_3);
	proc->shopproc = parent;

	SetTextFont(NULL);
	InitSystemTextFont();

	for (i = parent->hand_idx; i < parent->hand_idx + SHOP_TEXT_LINES; i++)
		PutBlankText(
			&gShopItemTexts[tmp = DivRem(i, SHOP_TEXT_LINES + 1)],
			gBg2Tm + TM_OFFSET(7, ((i * 2) & 0x1F)));

	SetBgOffset(BG_2, 0, (parent->hand_idx * 0x10) - 0x48);
	EnableBgSync(BG2_SYNC_BIT);
}

void DrawShopSoldItems(struct ProcShop *proc)
{
	int i;
	int item;
	int index;

	SetTextFont(0);
	InitSystemTextFont();

	for (i = proc->hand_idx; i < proc->hand_idx + SHOP_TEXT_LINES; i++) {
		index = DivRem(i, SHOP_TEXT_LINES + 1);

		ClearText(&gShopItemTexts[index]);
	}

	for (i = proc->hand_idx; i < proc->hand_idx + SHOP_TEXT_LINES; i++) {
		index = DivRem(i, SHOP_TEXT_LINES + 1);

		item = proc->shopItems[i];

		if (item == 0)
			break;

		DrawShopItemPriceLine(
			&gShopItemTexts[index],
			item,
			proc->unit,
			gBg2Tm + TM_OFFSET(7, ((i * 2) & 0x1F))
		);
	}
	SetBgOffset(BG_2, 0, (proc->hand_idx * 0x10) - 0x48);
	EnableBgSync(BG2_SYNC_BIT);
}

void InitShopBuyStatus(struct ProcShopInit *proc)
{
	Shop_InitBuyState(proc->shopproc);
	DrawShopSoldItems(proc->shopproc);

	Proc_Break(proc);
}

void ShopInitTexts_OnSell(struct ProcShop *parent)
{
	int i, tmp;
	struct ProcShopInit *proc;

	parent->buy_or_sel = SHOP_ST_SELL;

	proc = SpawnProc(ProcScr_ShopSellInit, PROC_TREE_3);
	proc->shopproc = parent;

	SetTextFont(NULL);
	InitSystemTextFont();

	for (i = 0; i < SHOP_TEXT_LINES; i++)
		PutBlankText(
			&gShopItemTexts[tmp = DivRem(i, SHOP_TEXT_LINES + 1)],
			gBg2Tm + TM_OFFSET(7, ((i * 2) & 0x1F)));

	SetBgOffset(2, 0, -0x48);
	EnableBgSync(BG2_SYNC_BIT);
}

void ShopDrawDefaultSellItemLine(struct ProcShop *proc)
{
	int i;
	int item;
	int index;

	SetTextFont(NULL);
	InitSystemTextFont();

	for (i = 0; i < SHOP_TEXT_LINES; i++) {
		index = DivRem(i, SHOP_TEXT_LINES + 1);
		ClearText(&gShopItemTexts[index]);
	}

	for (i = 0; i < SHOP_TEXT_LINES; i++) {
		index = DivRem(i, SHOP_TEXT_LINES + 1);
		item = proc->unit->items[i];

		if (item == 0)
			break;

		DrawShopItemLine(
			&gShopItemTexts[index],
			item,
			proc->unit,
			gBg2Tm + TM_OFFSET(7, ((i * 2) & 0x1F)));
	}
	EnableBgSync(BG2_SYNC_BIT);
}

void InitShopSellStatus(struct ProcShopInit *proc)
{
	Shop_InitSellState(proc->shopproc);
	ShopDrawDefaultSellItemLine(proc->shopproc);
	Proc_Break(proc);
}

void DrawShopItemPriceLine(struct Text *th, int item, struct Unit *unit, u16 *dst)
{

	int price = (u16)GetItemPurchasePrice(unit, item);

	DrawItemMenuLine(th, item, IsItemDisplayUsable(unit, item), dst);

	PutNumber(
		dst + 0x11,
		GetGold() >= price
			? TEXT_COLOR_SYSTEM_BLUE
			: TEXT_COLOR_SYSTEM_GRAY,
		price
	);
}

void DrawShopItemLine(struct Text *th, int item, struct Unit *unit, u16 *dst)
{
	DrawItemMenuLine(th, item, IsItemDisplayUsable(unit, item), dst);

	if (IsItemSellable(item) != 0)
		PutNumber(dst + 0x11, TEXT_COLOR_SYSTEM_BLUE, GetItemSellPrice(item));
	else
		Text_InsertDrawString(th, 0x5C, TEXT_COLOR_SYSTEM_BLUE, "ーーーー");
}

u16 GetItemPurchasePrice(struct Unit *unit, int item)
{
	int cost = GetItemValue(item);

	if (gBmSt.flags & BM_FLAG_PREP) {
		// WTF
		cost = cost * 1.5; // cost + (cost / 2);
	}

	if (UnitHasItem(unit, IID_SILVERCARD))
		return (cost / 2);
	else
		return cost;
}

u16 GetItemSellPrice(int item)
{
	return GetItemValue(item) / 2;
}

bool IsItemSellable(int item)
{
	if (GetItemAttributes(item) & ITEM_ATTR_IMPORTANT)
		return false;

	if (GetItemSellPrice(item) == 0)
		return false;

	return true;
}

void GoldBox_OnLoop(struct ProcShop *proc)
{
	PutOamHi(
		proc->goldbox_x,
		proc->goldbox_y,
		Sprite_ShopGoldBox,
		proc->goldbox_oam2);
}

void InitShopScreenConfig(void)
{
	SetDispEnable(1, 1, 1, 1, 1);
	SetWinEnable(0, 0, 0);

	SetBgOffset(BG_0, 0, 0);
	SetBgOffset(BG_1, 0, 0);
	SetBgOffset(BG_2, 0, 0);
	SetBgOffset(BG_3, 0, 0);

	TmFill(gBg0Tm, 0);
	TmFill(gBg1Tm, 0);
	TmFill(gBg2Tm, 0);
	TmFill(gBg3Tm, 0);

	EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT | BG2_SYNC_BIT | BG3_SYNC_BIT);

	ResetText();
	UnpackUiWindowFrameGraphics();
	InitIcons();
	ApplyIconPalettes(BGPAL_SHOP_ICON);
	LoadHelpBoxGfx(NULL, -1);
}

void Shop_DisplayShopUiArrows(struct ProcShop *proc)
{
	DisplayShopUiArrows();
}

void DisplayShopUiArrows(void)
{
	if (ShouldDisplayUpArrow())
		DisplayUiVArrow(
			120, 64,
			OAM2_PAL(OBJPAL_SHOP_SPINARROW) + OAM2_CHR(OBJCHR_SHOP_SPINARROW),
			true);

	if (ShouldDisplayDownArrow())
		DisplayUiVArrow(
			120, 152,
			OAM2_PAL(OBJPAL_SHOP_SPINARROW) + OAM2_CHR(OBJCHR_SHOP_SPINARROW),
			false);
}

void UnpackUiVArrowGfx(int chr, int pal)
{
	Decompress(Img_VeriticalSpinningArrow, OBJ_VRAM0 + (OAM2_CHR(chr) << 5));
	ApplyPalette(Pal_SpinningArrow, pal + 0x10);
}

void DisplayUiVArrow(int x, int y, u16 oam2Base, int flip_en)
{
	int offset, flip;

	offset = DivRem(GetGameTime(), 40);
	offset = Div(offset, 8) * 2;

	if (flip_en == 0)
		flip = OAM1_VFLIP;
	else
		flip = 0;

	PutSpriteExt(
		2,
		x | flip,
		y,
		Sprite_16x8,
		(oam2Base) + offset
	);
}

void HandleShopBuyAction(struct ProcShop * proc)
{
	int gold;

	PlaySeDelayed(SONG_B9, 8);

	gAction.id = ACTION_SHOPPED;

	gold = GetGold();
	gold = gold - GetItemPurchasePrice(proc->unit, proc->shopItems[proc->head_loc]);
	SetGold(gold);


	UpdateShopItemCounts(proc);
	DrawShopSoldItems(proc);

	DisplayGoldBoxText(gBg0Tm + TM_OFFSET(27, 6));
}

int ShopTryMoveCursor(int pos, int pre, bool hscroll_en)
{
	int previous;

	if (pos < 0)
		pos = 0;

	if (pos >= pre)
		pos = pre - 1;

	previous = pos;

	if (gKeySt->repeated & KEY_DPAD_UP) {
		if (pos == 0) {
			if (hscroll_en && (gKeySt->pressed & KEY_DPAD_UP))
				pos = pre - 1;
		} else
			pos--;
	} else if (gKeySt->repeated & KEY_DPAD_DOWN) {
		if (pos == (pre - 1)) {
			if (hscroll_en && (gKeySt->pressed & KEY_DPAD_DOWN))
				pos = 0;
		} else
			pos++;
	}

	if (previous != pos) {
		PlaySe(SONG_66);
	}
	return pos;
}

void ShopSt_SetHeadLocBak(int unk)
{
	gShopHandLocBak = unk;
}

int ShopTryScrollPage(int head_loc, int total, int lines, int hand_loc)
{
	int __head_loc_bak;

	__head_loc_bak = gShopHandLocBak;
	gShopHandLocBak = head_loc;

	if (head_loc == __head_loc_bak)
		return false;

	if (lines > total)
		return false;

	if (head_loc < __head_loc_bak) {
		if (hand_loc == 0)
			return 0;

		if ((head_loc - hand_loc) < 1)
			return -1;
	} else {
		if ((lines + hand_loc) == total)
		return 0;
		if ((head_loc - hand_loc) >= (lines - 1))
		return +1;
	}

	return false;
}

int ShopUpdateBg2Offset(int off, int tar, int trig)
{
	if ((off - tar) >= 0 ? (off - tar) < trig : (tar - off) < trig)
		return tar;

	off = ((tar - off) <= 0) ? (((tar - off) < 0) ? (off +  -1 * trig) : off) : (off + trig);

	return off;
}

void RegisterShopState(u16 head_loc, u16 item_cnt, u16 lines, u16 hand_loc, int bg2_base, ShopFunc func, struct ProcShop * proc)
{

	ShopSt_SetHeadLocBak(head_loc);

	gpShopSt->head_loc = head_loc;
	gpShopSt->item_cnt = item_cnt;
	gpShopSt->lines = lines;
	gpShopSt->hand_loc = hand_loc;
	gpShopSt->px_per_line = 16;
	gpShopSt->trig = 4;
	gpShopSt->draw_line = func;
	gpShopSt->proc = proc;
	gpShopSt->bg2_base = -bg2_base;
	gpShopSt->bg2_off = hand_loc * 16;
}

void Shop_TryMoveHandPage(void)
{

	gpShopSt->head_loc = ShopTryMoveCursor(gpShopSt->head_loc, gpShopSt->item_cnt, 0);

	switch (ShopTryScrollPage(gpShopSt->head_loc, gpShopSt->item_cnt, gpShopSt->lines, gpShopSt->hand_loc)) {
	case 0:
	default:
		break;

	case +1:
		gpShopSt->hand_loc++;
		gpShopSt->draw_line(gpShopSt->proc, gpShopSt->hand_loc + gpShopSt->lines - 1);
		break;

	case -1:
		gpShopSt->hand_loc--;
		gpShopSt->draw_line(gpShopSt->proc, gpShopSt->hand_loc);
		break;
	}

	gpShopSt->bg2_off = ShopUpdateBg2Offset(
							gpShopSt->bg2_off,
							gpShopSt->hand_loc * gpShopSt->px_per_line,
							gpShopSt->trig);
}

u16 ShopSt_GetHeadLoc(void)
{
	return gpShopSt->head_loc;
}

int ShopSt_GetBg2Offset(void)
{
	return gpShopSt->bg2_base + gpShopSt->bg2_off;
}

u16 ShopSt_GetHandLoc(void)
{
	return gpShopSt->hand_loc;
}

void ShopSt_SetLineHeight(int px)
{
	gpShopSt->px_per_line = px;
}

void ShopSt_SetSetPageScrollTrigOffset(int trig)
{
	gpShopSt->trig = trig;
}

bool IsShopPageScrolling(void)
{
	if (gpShopSt->bg2_off != (gpShopSt->hand_loc * gpShopSt->px_per_line))
		return true;

	return false;
}

bool ShouldDisplayUpArrow(void)
{
	if (gpShopSt->hand_loc != 0) {
		return true;
	}

	return false;
}

bool ShouldDisplayDownArrow(void)
{
	if (gpShopSt->hand_loc + gpShopSt->lines < gpShopSt->item_cnt)
		return true;

	return false;
}


bool func_fe6_08097E2C(int a)
{
	struct MusicPlayer *info = gMusicPlayerTable[gSongTable[0x39].ms].music_player;

	if (((info->status & MUSICPLAYER_STATUS_TRACK) == 0) && ((info->status & MUSICPLAYER_STATUS_PAUSE) == 0))
		return false;
	else
		return true;
}
