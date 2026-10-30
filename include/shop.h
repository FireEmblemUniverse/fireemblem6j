#pragma once

#include "prelude.h"
#include "proc.h"
#include "unit.h"
#include "text.h"

#define SHOP_ITEMS_MAX_AMT 20

enum ShopProcLabel {
	PL_SHOP_ENTRY = 0,
	PL_SHOP_BUY,
	PL_SHOP_BUY_MAIN,
	PL_SHOP_BUY_DONE,
	PL_SHOP_SELL,
	PL_SHOP_SELL_MAIN,
	PL_SHOP_6_UNUSED, // unused
	PL_SHOP_SELL_NOITEM,
	PL_SHOP_ANYTHING_ELSE,
	PL_SHOP_SENDTO_INVENTORY,
	PL_SHOP_SENDTO_INVENTORY_EXT,
	PL_SHOP_BUY_FULL_NO_INEVNTORY,
	PL_SHOP_EXIT,
};

struct ProcShop {
	/* 00 */ PROC_HEADER;

	/* 2C */ struct Unit *unit;
	/* 30 */ u16 shopItems[20];

	/* 58 */ u16 unk_58;

	/* 5A */ u8 shopItemCount;
	/* 5B */ u8 unitItemCount;
	/* 5C */ u8 head_loc;
	/* 5D */ u8 hand_loc;
	/* 5E */ u8 head_idx;
	/* 5F */ u8 hand_idx; // maybe top visible item in menu?
	/* 60 */ u8 buy_or_sel;
	/* 61 */ u8 shopType;
	/* 62 */ u8 helpTextActive;

	/* 64 */ i16 goldbox_x, goldbox_y, goldbox_oam2;
};

enum ShopType {
	/* ProcShop::shopType */
	SHOP_TYPE_ARMORY	  = 0,
	SHOP_TYPE_VENDOR	  = 1,
	SHOP_TYPE_SECRET_SHOP = 2,

	SHOP_TYPE_MAX
};

enum ShopStatus {
	/* ProcShop::buy_or_sel */
	SHOP_ST_BUY,
	SHOP_ST_SELL
};

struct ProcShopInit {
	/* 00 */ PROC_HEADER;

	STRUCT_PAD(0x29, 0x54);

	/* 54 */ struct ProcShop *shopproc;
};

typedef void (* ShopFunc)(struct ProcShop *, int);

struct ShopState {
	/* 00 */ u16 head_loc;
	/* 02 */ u16 item_cnt;
	/* 04 */ u16 lines;
	/* 06 */ u16 hand_loc;
	/* 08 */ u16 px_per_line;
	/* 0A */ u16 trig;
	/* 0C */ u16 bg2_off;
	/* 10 */ int bg2_base;
	/* 14 */ ShopFunc draw_line;
	/* 18 */ ProcPtr proc;
};
extern CONST_DATA struct ShopState *gpShopSt;

#define SHOP_TEXT_LINES 5
extern struct Text gShopItemTexts[SHOP_TEXT_LINES + 1];

int GetShopFace(struct ProcShop *proc);
void StartShopDialogue(int msg, struct ProcShop *proc);
void StartDefaultArmoryScreen(struct Unit *unit, ProcPtr proc);
void StartArmoryScreenOrphaned(struct Unit *unit, u16 const *iid_list);
void StartVendorScreenOrphaned(struct Unit *unit, u16 const *iid_list);
void StartSecretShopScreenOrphaned(struct Unit *unit, u16 const *iid_list);
void StartArmoryScreen(struct Unit *unit, u16 const *iid_list);
void StartShopScreen(struct Unit *unit, const u16 *iid_list, u8 type, ProcPtr parent);
void UpdateShopItemCounts(struct ProcShop *proc);
void TalkChoice_OnBuy(void);
void TalkChoice_OnSell(void);
void Shop_EntryDialogue(struct ProcShop *proc);
void Shop_HandleEntryDialoguePrompt(struct ProcShop *proc);
void Shop_BuyDialogue(struct ProcShop *proc);
void ShopDrawBuyItemLine(struct ProcShop *proc, int list_idx);
void ShopDrawSellItemLine(struct ProcShop *proc, int list_idx);
void Shop_InitBuyState(struct ProcShop *proc);
void Shop_Loop_BuyKeyHandler(struct ProcShop *proc);
void Shop_TryAddItemToInventory(struct ProcShop *proc);
void Shop_HandleBuyConfirmPrompt(struct ProcShop *proc);
void Shop_HandleSendToConvoyPrompt(struct ProcShop *proc);
void Shop_NoSendToConvoyDialogue(struct ProcShop *proc);
void Shop_AddItemToConvoy(struct ProcShop *proc);
void Shop_SendToConvoyDialogue(struct ProcShop *proc);
void Shop_CheckIfConvoyFull(struct ProcShop *proc);
void Shop_ConvoyFullDialogue(struct ProcShop *proc);
void Shop_AnythingElseDialogue(struct ProcShop *proc);
void Shop_SellDialogue(struct ProcShop *proc);
void Shop_InitSellState(struct ProcShop *proc);
void Shop_Loop_SellKeyHandler(struct ProcShop *proc);
void Shop_HandleSellConfirmPrompt(struct ProcShop *proc);
void Shop_SellAnythingElseDialogue(struct ProcShop *proc);
void Shop_AnythingElseRestartDialogue(struct ProcShop *proc);
void Shop_AnythingElseContinueDialogue(struct ProcShop *proc);
void Shop_ExitShopDialogue(struct ProcShop *proc);
void Shop_OnExit(struct ProcShop *proc);
void StartShopFadeIn(struct ProcShop *proc);
void StartShopFadeOut(struct ProcShop *proc);
void Shop_Start(struct ProcShop *proc);
void StartUiGoldBox(ProcPtr proc);
void InitGoldBoxText(u16 *tm);
void ClearGoldBoxTextTm2Line(u16 *tm, int lines);
void DisplayGoldBoxText(u16 *tm);
void ShopInitTexts_OnBuy(struct ProcShop *proc);
void DrawShopSoldItems(struct ProcShop *proc);
void InitShopBuyStatus(struct ProcShopInit *proc);
void ShopInitTexts_OnSell(struct ProcShop *proc);
void ShopDrawDefaultSellItemLine(struct ProcShop *proc);
void InitShopSellStatus(struct ProcShopInit *proc);
void DrawShopItemPriceLine(struct Text *text, int item, struct Unit *unit, u16 *tm);
void DrawShopItemLine(struct Text *text, int item, struct Unit *unit, u16 *tm);
u16 GetItemPurchasePrice(struct Unit *, int);
u16 GetItemSellPrice(int);
bool IsItemSellable(int item);
void GoldBox_OnLoop(struct ProcShop *proc);
void InitShopScreenConfig(void);
void Shop_DisplayShopUiArrows(struct ProcShop *proc);
void DisplayShopUiArrows(void);
void UnpackUiVArrowGfx(int, int);
void DisplayUiVArrow(int, int, u16, int);
void HandleShopBuyAction(struct ProcShop *proc);
int ShopTryMoveCursor(int pos, int pre, bool scroll);
void ShopSt_SetHeadLocBak(int unk);
int ShopTryScrollPage(int head_loc, int total, int lines, int hand_loc);
int ShopUpdateBg2Offset(int off, int tar, int trig);
void RegisterShopState(u16, u16 item_cnt, u16 lines, u16 cur_sel, int bg_off, void (* on_draw)(struct ProcShop *, int), struct ProcShop *proc);
void Shop_TryMoveHandPage(void);
u16 ShopSt_GetHeadLoc(void);
int ShopSt_GetBg2Offset(void);
u16 ShopSt_GetHandLoc(void);
void ShopSt_SetLineHeight(int px);
void ShopSt_SetSetPageScrollTrigOffset(int trig);
bool IsShopPageScrolling(void);
bool ShouldDisplayUpArrow(void);
bool ShouldDisplayDownArrow(void);
bool func_fe6_08097E2C(int a);

extern u16 CONST_DATA gDefaultShopItems[];
extern int CONST_DATA gShopDislogueIdx[SHOP_TYPE_MAX];
extern int CONST_DATA gShopFaces[SHOP_TYPE_MAX];
extern CONST_DATA struct ProcScr ProcScr_ShopFadeIn[];
extern CONST_DATA struct ProcScr ProcScr_ShopFadeOut[];
extern CONST_DATA struct ProcScr ProcScr_Shop[];
extern struct ProcScr CONST_DATA ProcScr_ShopBuyInit[];
extern struct ProcScr CONST_DATA ProcScr_ShopSellInit[];
extern CONST_DATA u16 Sprite_ShopGoldBox[];
extern CONST_DATA struct ProcScr ProcScr_GoldBox[];
extern CONST_DATA struct ProcScr ProcScr_ShopDrawHand[];
