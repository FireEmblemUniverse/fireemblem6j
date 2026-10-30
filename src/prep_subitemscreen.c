#include "prelude.h"
#include "proc.h"
#include "face.h"
#include "ui.h"
#include "oam.h"
#include "msg.h"
#include "supply.h"
#include "icon.h"
#include "util.h"
#include "sound.h"
#include "armfunc.h"
#include "helpbox.h"
#include "faction.h"
#include "item.h"
#include "action.h"
#include "prepscreen.h"

#include "constants/videoalloc_global.h"
#include "constants/msg.h"
#include "constants/songs.h"

extern const char String_Prep_083272AC[];
extern const char String_Prep_083272B8[];
extern const char String_Prep_083272C4[];
extern const char String_Prep_083272CC[];
extern const char String_Prep_083272D4[];
extern const char String_Prep_Yes[];
extern const char String_Prep_No[];

void func_fe6_0807E06C(bool act)
{
	int i;

	if (act) {
		for (i = 0; i < 15; i++) {
			gBg0Tm[TM_OFFSET(15 + i, 3)] = OAM2_CHR(BGCHR_PREPMENU_328) + OAM2_PAL(BGPAL_PREPMENU_3) + i;
			gBg0Tm[TM_OFFSET(15 + i, 4)] = OAM2_CHR(BGCHR_PREPMENU_368) + OAM2_PAL(BGPAL_PREPMENU_3) + i;
		}
	} else {
		for (i = 0; i < 15; i++) {
			gBg0Tm[TM_OFFSET(15 + i, 3)] = 0;
			gBg0Tm[TM_OFFSET(15 + i, 4)] = 0;
		}
	}

	EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT);
}

void PrepSubItemScreen_Init(struct PrepSubItemProc *proc)
{
	u8 i;

	if (proc->unk2D <= PREP_SUB2U2D_3)
		proc->unk4B = 0;

	ResetText();
	ResetTextFont();

	gDispIo.bg0_ct.priority = 0;
	gDispIo.bg1_ct.priority = 1;
	gDispIo.bg2_ct.priority = 0;
	gDispIo.bg3_ct.priority = 2;

	ClearIcons();

	for (i = 0; i < 20; i++)
		gPrepSubMenuIcons[i] = 0xFF;

	TmFill(gBg0Tm, 0);
	TmFill(gBg1Tm, 0);
	TmFill(gBg2Tm, 0);

	InitIcons();
	ApplyIconPalettes(BGPAL_ICONS);
	UnpackUiWindowFrameGraphics();

	InitText(&gPrepTexts3[0], 6);
	InitTextDb(&gPrepTexts3[1], 5);

	for (i = 0; i < 5; i++)
		InitTextDb(&gPrepTexts1[0][i], 7);

	for (i = 0; i < 8; i++)
		InitTextDb(&gPrepTexts1[1][i], 7);

	ApplyPalettes(Pal_SpinningArrow, 0x10 + OBPAL_PREPMENU_2, 3);
	ApplyPalettes( Pal_Sio_0831AABC, 0x10 + OBPAL_PREPMENU_8, 2);
	ApplyPalette( Pal_Prep_0831A248, BGPAL_PREPMENU_3);
	Decompress(Img_Prep_08319EE8, gBg0Tm + BGCHR_PREPMENU_280);
	Decompress(Img_Prep_0831A088, gBg1Tm + BGCHR_PREPMENU_280);

	proc->menu_scroll_bar_disp_idx = 0;
	proc->convoy_scrolling_pos = 0;
	proc->hand_disp_y = 0;
	proc->unk30 |= 0xFF;
	proc->sel_action |= 0xFF;
	proc->unk_48 = 0;
	proc->menu_scrolling_pos = 0;
	proc->timer = 0;
	proc->unk29 = 0;
	proc->unk_4E = 0;
	proc->unk_47 = 0;
	proc->proc_menuscroll = StartMenuScrollBar(proc);

	if (proc->unk2D <= 3) {
		Decompress(Img_Prep_0831AB1C, OBJ_VRAM0 + 0x1000);
		Decompress(Img_Prep_083198CC, OBJ_VRAM0 + OBCHR_PREPMENU_390 * CHR_SIZE);

		proc->units[0] = proc->proc_parent->unit1;
		proc->units[1] = proc->proc_parent->unit2;

		SetPrepMenuScrollBarOam2Info(proc->proc_menuscroll,
			OBCHR_PREPMENU_390 * CHR_SIZE, OBPAL_PREPMENU_2);

		if (proc->proc_parent->link_arena_flag & PREPMENU_FLAG_MULTIARENA)
			proc->unk_4C = 1;
		else
			proc->unk_4C = 0;
	} else {
		Decompress(Img_Prep_083198CC, OBJ_VRAM0 + OBCHR_PREPMENU_280 * CHR_SIZE);
		SetPrepMenuScrollBarOam2Info(proc->proc_menuscroll,
			OBCHR_PREPMENU_280 * CHR_SIZE, OBPAL_PREPMENU_2);

		proc->unk_4C = 0;
	}

	if (proc->unk4B == 0) {
		struct Text *text;

		PutUiWindowFrame(1, 8, 0xE, 0xC, 0);

		text = &gPrepTexts3[0];

		ClearText(text);
		Text_SetColor(text, TEXT_COLOR_SYSTEM_WHITE);
		Text_SetCursor(text, (0x30 - GetStringTextLen(DecodeMsg(proc->units[0]->pinfo->msg_name))) / 2);
		Text_DrawString(text, DecodeMsg(proc->units[0]->pinfo->msg_name));
		PutText(text, gBg0Tm);
		func_fe6_0807D6C0(0, proc->units[0]);
		StartFace(0, GetUnitFid(proc->units[0]), 0x40, -4, FACE_DISP_KIND(FACE_96x80_FLIPPED));
	}

	SetBgOffset(BG_0, 0, 0);
	SetBgOffset(BG_1, 0, 0);
	SetBgOffset(BG_2, proc->convoy_scrolling_pos, (proc->menu_scroll_bar_disp_idx - 0x28) & 0xFF);

	for (i = 0; i < 9; i++) {
		proc->unk_32[i] = 0;
		proc->unk_3B[i] = 0;
	}

	EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT | BG2_SYNC_BIT);

	if (proc->unk2D <= 3)
		Proc_Goto(proc, proc->unk2A);

	LoadHelpBoxGfx(NULL, -1);
}

void PrepSubItem_StartTradeScreen(struct PrepSubItemProc *proc)
{
	struct Text *text;

	PutUiWindowFrame(0xF, 8, 0xE, 0xC, 0);

	text = &gPrepTexts3[1];

	ClearText(text);
	Text_SetColor(text, TEXT_COLOR_SYSTEM_WHITE);
	Text_SetCursor(text, (0x28 - GetStringTextLen(DecodeMsg(proc->units[1]->pinfo->msg_name))) / 2);
	Text_DrawString(text, DecodeMsg(proc->units[1]->pinfo->msg_name));
	PutText(text, gBg0Tm + TM_OFFSET(0x18, 0));
	func_fe6_0807D6C0(1, proc->units[1]);
	StartFace(1, GetUnitFid(proc->units[1]), 0xAC, -4, FACE_DISP_KIND(FACE_96x80));

	if (proc->unk2D != 3) {
		if (GetUnitItemCount(proc->units[0]) == 0)
			proc->hand_disp_x = POS_R;
		else
			proc->hand_disp_x = POS_L;

		proc->hand_disp_y = 0;
	}

	proc->unk30 |= 0xFF;
	proc->sel_action |= 0xFF;
	PutUiEntryHover(
		proc->hand_disp_x * 14 + 2,
		proc->hand_disp_y * 2 + 9,
		0xC);

	EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT | BG2_SYNC_BIT | BG3_SYNC_BIT);

	proc->menu_scrolling_pos = 0;

	if (proc->unk2D == 0)
		NewSallyCir2(proc, -1);
	else if (proc->unk2D == 3)
		Proc_End(proc->subproc1);

	proc->subproc1 = func_fe6_0807D074(proc);
	proc->unk2D = 1;
}

void func_fe6_0807E544(struct PrepSubItemProc *proc)
{
	proc->unk_3B[0] = GetUnitItemCount(proc->units[0]);
	proc->unk_3B[1] = GetUnitItemCount(proc->units[1]);

	if (proc->unk30 == 1)
		if (proc->unk29 == 0)
			if (proc->unk_3B[0] < 5)
				proc->unk_3B[0]++;

	if (proc->unk30 == 0)
		if (proc->unk29 == 0)
			if (proc->unk_3B[1] < 5)
				proc->unk_3B[1]++;
}

void PrepSubItem_Trade_Loop(struct PrepSubItemProc *proc)
{
	char pre_sel_x;
	int pre_sel_y;

	pre_sel_x = proc->hand_disp_x;
	pre_sel_y = proc->hand_disp_y;

	func_fe6_0807E544(proc);

	if (proc->unk29 == 2 && (gKeySt->pressed & (KEY_BUTTON_B | KEY_BUTTON_R))) {
		CloseHelpBox();
		proc->unk29 = 0;
		return;
	}

	if ((gKeySt->repeated & KEY_DPAD_LEFT) && (proc->hand_disp_x == 1)) {
		if (proc->unk_3B[0] != 0) {
			PlaySe(0x67);

			RemoveUiEntryHover(
				proc->hand_disp_x * 14 + 2,
				proc->hand_disp_y * 2 + 9,
				0xC);

			proc->hand_disp_x--;

			if (proc->hand_disp_y >= proc->unk_3B[proc->hand_disp_x])
				proc->hand_disp_y = proc->unk_3B[proc->hand_disp_x] - 1;

			PutUiEntryHover(
				proc->hand_disp_x * 14 + 2,
				proc->hand_disp_y * 2 + 9,
				0xC);
		}
	} else if ((gKeySt->repeated & KEY_DPAD_RIGHT) && (proc->hand_disp_x == 0)) {
		if (proc->unk_3B[1] != 0) {
			PlaySe(0x67);

			RemoveUiEntryHover(
				proc->hand_disp_x * 14 + 2,
				proc->hand_disp_y * 2 + 9,
				0xC);

			proc->hand_disp_x++;

			if (proc->hand_disp_y >= proc->unk_3B[proc->hand_disp_x])
				proc->hand_disp_y = proc->unk_3B[proc->hand_disp_x] - 1;

			PutUiEntryHover(
				proc->hand_disp_x * 14 + 2,
				proc->hand_disp_y * 2 + 9,
				0xC);
		}
	} else if ((gKeySt->repeated & KEY_DPAD_UP) && (proc->unk_3B[proc->hand_disp_x] != 0)) {
		RemoveUiEntryHover(
			proc->hand_disp_x * 14 + 2,
			proc->hand_disp_y * 2 + 9,
			0xC);

		if (proc->hand_disp_y != 0) {
			proc->hand_disp_y--;
			PlaySe(0x66);
		} else if (gKeySt->pressed & KEY_DPAD_UP) {
			proc->hand_disp_y = proc->unk_3B[proc->hand_disp_x] - 1;
			PlaySe(0x66);
		}

		PutUiEntryHover(
			proc->hand_disp_x * 14 + 2,
			proc->hand_disp_y * 2 + 9,
			0xC);
	} else if ((gKeySt->repeated & KEY_DPAD_DOWN) && (proc->unk_3B[proc->hand_disp_x] != 0)) {
		RemoveUiEntryHover(
			proc->hand_disp_x * 14 + 2,
			proc->hand_disp_y * 2 + 9,
			0xC);

		if (proc->hand_disp_y < (proc->unk_3B[proc->hand_disp_x] - 1)) {
			proc->hand_disp_y++;
			PlaySe(0x66);
		} else if (gKeySt->pressed & KEY_DPAD_DOWN) {
			proc->hand_disp_y = 0;
			PlaySe(0x66);
		}

		PutUiEntryHover(
			proc->hand_disp_x * 14 + 2,
			proc->hand_disp_y * 2 + 9,
			0xC);
	} else if ((gKeySt->pressed & KEY_BUTTON_A) && (proc->unk29 == 0)) {
		PlaySe(0x6A);

		if (proc->unk30 == 0xFF) {
			proc->unk30 = proc->hand_disp_x;
			proc->sel_action = proc->hand_disp_y;

			RemoveUiEntryHover(
				proc->hand_disp_x * 14 + 2,
				proc->hand_disp_y * 2 + 9,
				0xC);

			proc->hand_disp_x = (proc->hand_disp_x + 1) & 1;

			if (GetUnitItemCount(proc->units[proc->hand_disp_x]) < 5)
				proc->hand_disp_y = proc->unk_3B[proc->hand_disp_x];

			PutUiEntryHover(
				proc->hand_disp_x * 14 + 2,
				proc->hand_disp_y * 2 + 9,
				0xC);
		} else {
			if ((proc->unk_4C != 0) && !CheckValidLinkArenaItemSwap(
					proc->units[proc->unk30], proc->sel_action,
					proc->units[proc->hand_disp_x], proc->hand_disp_y)) {

					proc->hand_disp_y = proc->hand_disp_y;
					StartPrepErrorHelpbox(
						proc->hand_disp_x * 0x70 + 0x10,
						proc->hand_disp_y * 0x10 + 0x48,
						MSG_6C2, proc);
			} else {
				int tmp = proc->units[proc->unk30]->items[proc->sel_action];

				proc->units[proc->unk30]->items[proc->sel_action] =
					proc->units[proc->hand_disp_x]->items[proc->hand_disp_y];

				proc->units[proc->hand_disp_x]->items[(*proc).hand_disp_y] = tmp;

				RemoveUiEntryHover(
					proc->hand_disp_x * 14 + 2,
					proc->hand_disp_y * 2 + 9,
					0xC);

				UnitRemoveInvalidItems(proc->units[0]);
				UnitRemoveInvalidItems(proc->units[1]);

				func_fe6_0807D6C0(0, proc->units[0]);
				func_fe6_0807D6C0(1, proc->units[1]);

				if (proc->units[proc->unk30]->items[proc->sel_action]) {
					proc->hand_disp_x = proc->unk30;
					proc->hand_disp_y = proc->sel_action;
				} else if (GetUnitItemCount(proc->units[proc->unk30]) > 0) {
					proc->hand_disp_x = proc->unk30;
					proc->hand_disp_y = proc->sel_action - 1;
				} else {
					proc->hand_disp_y = 0;
				}

				proc->unk30 = 0xFF;

				PutUiEntryHover(
					proc->hand_disp_x * 14 + 2,
					proc->hand_disp_y * 2 + 9,
					0xC);
			}
		}
	} else if ((gKeySt->pressed & KEY_BUTTON_B)) {
		PlaySe(0x6B);

		if (proc->unk30 == 0xFF) {
			if (proc->unk2A == 0)
				Proc_Goto(proc, PL_PREP_SUBITEM_7);
			else {
				NewSallyCir2(proc, 1);
				Proc_Goto(proc, PL_PREP_SUBITEM_6);
			}
		} else {
			RemoveUiEntryHover(
				proc->hand_disp_x * 14 + 2,
				proc->hand_disp_y * 2 + 9,
				0xC);

			proc->hand_disp_x = proc->unk30;
			proc->hand_disp_y = proc->sel_action;
			proc->unk30 = 0xFF;

			PutUiEntryHover(
				proc->hand_disp_x * 14 + 2,
				proc->hand_disp_y * 2 + 9,
				0xC);
		}
	} else if ((gKeySt->pressed & KEY_BUTTON_R) && (proc->unk29 == 0)) {
		if (proc->units[proc->hand_disp_x]->items[proc->hand_disp_y]) {
			proc->unk29 = 2;
			StartItemHelpBox(
				proc->hand_disp_x * 0x70 + 0x10,
				proc->hand_disp_y * 0x10 + 0x48,
				proc->units[proc->hand_disp_x]->items[proc->hand_disp_y]);
		}
	}

	if (proc->unk29 == 2) {
		if ((pre_sel_x != proc->hand_disp_x) || (pre_sel_y != proc->hand_disp_y)) {
			StartItemHelpBox(
				proc->hand_disp_x * 0x70 + 0x10,
				proc->hand_disp_y * 0x10 + 0x48,
				proc->units[proc->hand_disp_x]->items[proc->hand_disp_y]);
		}
	}
}

void PrepSubItem_StartViewAllScreen(struct PrepSubItemProc *proc)
{
	int iuid, tmp;
	u8 i, i2, count;
	const u16 *supply_items = GetSupplyItems();

	PutUiWindowFrame(15, 4, 15, 16, 0);

	gPrepAllItemsCount = 0;

	// FOR_UNITS_FACTION FACTION_BLUE
	for (iuid = FACTION_BLUE + 1; iuid < (FACTION_BLUE + 0x40); iuid++) {
		struct Unit *iunit = GetUnit(iuid);

		if (!iunit || !iunit->pinfo)
			continue;

		if (iunit->flags & UNIT_FLAG_DEAD)
			continue;

		if (iunit == proc->units[0])
			continue;

		i = GetUnitItemCount(iunit);

		for (i2 = 0; i2 < i; i2++) {
			gPrepItemListData[gPrepAllItemsCount].pid  = UNIT_PID(iunit);
			gPrepItemListData[gPrepAllItemsCount].item = iunit->items[i2];
			gPrepItemListData[gPrepAllItemsCount].slot = i2;
			gPrepAllItemsCount++;
		}
	}

	tmp = gPrepAllItemsCount;
	for (i = 0; i < SUPPLY_ITEM_COUNT && supply_items[i] != 0; i++) {
		gPrepItemListData[i + tmp].item = supply_items[i];
		gPrepItemListData[i + tmp].pid = 0;
		gPrepItemListData[i + tmp].slot = i;
		gPrepAllItemsCount++;
	}

	proc->convoy_page = proc->proc_parent->unk_39;
	func_fe6_0807D834(proc->convoy_page);
	proc->menu_scroll_bar_disp_idx = proc->unk_4E;
	proc->hand_disp_y = proc->unk_47;
	func_fe6_080823A0(&proc->hand_disp_y, &proc->menu_scroll_bar_disp_idx);
	func_fe6_0807D9E4(&gPrepTexts1[1][0], 1, proc->units[0], proc->menu_scroll_bar_disp_idx / 0x10, 0);
	func_fe6_0807D358(proc);
	proc->convoy_scrolling_pos = 0;
	proc->hand_disp_x = 1;
	proc->unk30 |= 0xFF;
	proc->sel_action |= 0xFF;

	PrepAllItems_PutPName(
		&gPrepTexts3[1],
		gPrepItemListData[proc->menu_scroll_bar_disp_idx / 0x10 + proc->hand_disp_y].pid,
		0x18, 0);

	PutUiEntryHover(
		proc->hand_disp_x * 14 + 2,
		proc->hand_disp_y * 2 + 9 - proc->hand_disp_x * 4,
		12);

	SetBgOffset(
		BG_2,
		proc->convoy_scrolling_pos,
		(proc->menu_scroll_bar_disp_idx - 0x28) & 0xFF);

	SetPrepMenuScrollBarBaseInfo(
		proc->proc_menuscroll,
		0xE0, 0x34, 0xB,
		proc->menu_scroll_bar_disp_idx,
		gPrepMenuScrollPos, 7);

	EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT | BG2_SYNC_BIT | BG3_SYNC_BIT);

	proc->menu_scrolling_pos = 0;

	if (proc->unk2D == 0)
		NewSallyCir2(proc, -1);
	else if (proc->unk2D == 1)
		Proc_End(proc->subproc1);

	proc->subproc1 = func_fe6_0807D16C(proc);
	func_fe6_0807E06C(true);
	proc->unk2D = 3;
}

void PrepSubItem_ViewAll_Loop(struct PrepSubItemProc *proc)
{
	u8 invalid_pid = 0xFF;
	int prev_page = proc->convoy_page;
	int prev_idx = proc->hand_disp_y + proc->menu_scroll_bar_disp_idx / 0x10;

	if (proc->unk29 != 0 && (gKeySt->pressed & (KEY_BUTTON_B | KEY_BUTTON_R))) {
		if (proc->unk29 != 1) {
			CloseHelpBox();
			proc->unk29 = 0;
			return;
		}

		proc->unk29 = 0;
	}

	switch (proc->menu_scrolling_pos) {
	case 100: {
		u8 count = GetUnitItemCount(proc->units[0]);

		if (proc->unk29 == 0 && count <= 4)
			count++;

		if ((gKeySt->repeated & KEY_DPAD_UP) && count > 1) {
			RemoveUiEntryHover(
				proc->hand_disp_x * 14 + 2,
				proc->hand_disp_y * 2 + 9 - proc->hand_disp_x * 4,
				12);

			if (proc->hand_disp_y == 0) {
				if (gKeySt->pressed & KEY_DPAD_UP) {
					proc->hand_disp_y = count - 1;
					PlaySe(SONG_66);
				}
			} else {
				proc->hand_disp_y--;
				PlaySe(SONG_66);
			}

			PutUiEntryHover(
				proc->hand_disp_x * 14 + 2,
				proc->hand_disp_y * 2 + 9 - proc->hand_disp_x * 4,
				12);
		} else if ((gKeySt->repeated & KEY_DPAD_DOWN) && count > 1) {
			RemoveUiEntryHover(
				proc->hand_disp_x * 14 + 2,
				proc->hand_disp_y * 2 + 9 - proc->hand_disp_x * 4,
				12);

			if (proc->hand_disp_y < count - 1) {
				proc->hand_disp_y++;
				PlaySe(SONG_66);
			} else if (gKeySt->pressed & KEY_DPAD_DOWN) {
				proc->hand_disp_y = 0;
				PlaySe(SONG_66);
			}

			PutUiEntryHover(
				proc->hand_disp_x * 14 + 2,
				proc->hand_disp_y * 2 + 9 - proc->hand_disp_x * 4,
				12);
		} else if ((gKeySt->pressed & KEY_BUTTON_A) && proc->unk29 == 0) {
			if (proc->unk_4C != 0 && !CheckValidLinkArenaItemSupply(
					proc->units[0], proc->hand_disp_y,
					gPrepItemListData[proc->menu_scroll_bar_disp_idx / 0x10 + proc->sel_action].item)) {
				StartPrepErrorHelpbox(
					proc->hand_disp_x * 0x70 + 0x10,
					proc->hand_disp_y * 0x10 + 0x48,
					MSG_6C2, proc);
				break;
			}

			PlaySe(SONG_6A);

			PrepAllItems_SwapItems(proc->units[0], proc->hand_disp_y, proc->menu_scroll_bar_disp_idx / 0x10 + proc->sel_action);

			RemoveUiEntryHover(
				proc->hand_disp_x * 14 + 2,
				proc->hand_disp_y * 2 + 9 - proc->hand_disp_x * 4,
				12);

			proc->hand_disp_y = proc->sel_action;
			proc->hand_disp_x = 1;

			func_fe6_080823A0(&proc->hand_disp_y, &proc->menu_scroll_bar_disp_idx);
			func_fe6_0807D6C0(0, proc->units[0]);
			func_fe6_0807D9E4(&gPrepTexts1[1][0], 1, proc->units[0], proc->menu_scroll_bar_disp_idx / 0x10, 0);

			PrepAllItems_PutPName(
				&gPrepTexts3[1],
				gPrepItemListData[proc->menu_scroll_bar_disp_idx / 0x10 + proc->hand_disp_y].pid,
				0x18, 0);

			PutUiEntryHover(
				proc->hand_disp_x * 14 + 2,
				proc->hand_disp_y * 2 + 9 - proc->hand_disp_x * 4,
				12);

			proc->menu_scrolling_pos = 0;
		} else if (gKeySt->pressed & KEY_BUTTON_B) {
			PlaySe(SONG_6B);

			RemoveUiEntryHover(
				proc->hand_disp_x * 14 + 2,
				proc->hand_disp_y * 2 + 9 - proc->hand_disp_x * 4,
				12);

			proc->hand_disp_y = proc->sel_action;
			proc->hand_disp_x = 1;
			proc->menu_scrolling_pos = 0;

			PutUiEntryHover(
				proc->hand_disp_x * 14 + 2,
				proc->hand_disp_y * 2 + 9 - proc->hand_disp_x * 4,
				12);
		} else if ((gKeySt->pressed & KEY_BUTTON_R) && proc->unk29 == 0) {
			if (proc->units[0]->items[proc->hand_disp_y] != 0) {
				proc->unk29 = 2;
				StartItemHelpBox(
					proc->hand_disp_x * 0x70 + 0x10,
					proc->hand_disp_y * 0x10 + 0x48 - proc->hand_disp_x * 0x20,
					proc->units[0]->items[proc->hand_disp_y]);
			}
		}
		break;
	}

	case 0:
		if (gKeySt->held & KEY_BUTTON_L)
			proc->unk_4A = 2;
		else
			proc->unk_4A = 1;

		if ((gKeySt->pressed & KEY_BUTTON_A) && proc->unk29 == 0) {
			if (gPrepMenuScrollPos == 0) {
				PlaySe(SONG_6C);
			} else if (gPrepItemListData[proc->hand_disp_y + proc->menu_scroll_bar_disp_idx / 0x10].pid == 0) {
				PlaySe(SONG_6A);

				proc->menu_scrolling_pos = 100;
				proc->sel_action = proc->hand_disp_y;

				RemoveUiEntryHover(
					proc->hand_disp_x * 14 + 2,
					proc->hand_disp_y * 2 + 9 - proc->hand_disp_x * 4,
					12);

				if (GetUnitItemCount(proc->units[0]) <= 4)
					proc->hand_disp_y = GetUnitItemCount(proc->units[0]);
				else
					proc->hand_disp_y = 0;

				proc->hand_disp_x = 0;

				PutUiEntryHover(
					proc->hand_disp_x * 14 + 2,
					proc->hand_disp_y * 2 + 9 - proc->hand_disp_x * 4,
					12);
				break;
			} else {
				PlaySe(SONG_6A);
				Proc_Goto(proc, PL_PREP_SUBITEM_7);
				break;
			}
		}

		if (gKeySt->pressed & KEY_BUTTON_B) {
			PlaySe(SONG_6B);
			NewSallyCir2(proc, 1);
			Proc_Goto(proc, PL_PREP_SUBITEM_6);
			return;
		}

		if ((gKeySt->pressed & KEY_BUTTON_R) && proc->unk29 == 0) {
			if (gPrepMenuScrollPos == 0)
				break;

			proc->unk29 = 2;
			StartItemHelpBox(
				proc->hand_disp_x * 0x70 + 0x10,
				proc->hand_disp_y * 0x10 + 0x48 - proc->hand_disp_x * 0x20,
				gPrepItemListData[proc->hand_disp_y + proc->menu_scroll_bar_disp_idx / 0x10].item);
			break;
		}

		if (((gKeySt->repeated & KEY_DPAD_UP) || ((gKeySt->pressed2 & KEY_DPAD_UP) && proc->unk_4A == 2)) && proc->hand_disp_y != 0) {
			PlaySe(SONG_66);

			if (proc->hand_disp_y == 1 && proc->menu_scroll_bar_disp_idx != 0) {
				func_fe6_0807DB80(&gPrepTexts1[1][0], 1, proc->menu_scroll_bar_disp_idx / 0x10 - 1, proc->units[0], 0);
				func_fe6_0807D358(proc);

				if (invalid_pid != gPrepItemListData[proc->menu_scroll_bar_disp_idx / 0x10 + proc->hand_disp_y - 1].pid)
					PrepAllItems_PutPName(&gPrepTexts3[1], gPrepItemListData[proc->menu_scroll_bar_disp_idx / 0x10 + proc->hand_disp_y - 1].pid, 0x18, 0);

				proc->menu_scroll_bar_disp_idx -= proc->unk_4A * 4;
				proc->menu_scrolling_pos = 1;
				break;
			}

			RemoveUiEntryHover(
				proc->hand_disp_x * 14 + 2,
				proc->hand_disp_y * 2 + 9 - proc->hand_disp_x * 4,
				12);

			proc->hand_disp_y--;

			if (invalid_pid != gPrepItemListData[proc->menu_scroll_bar_disp_idx / 0x10 + proc->hand_disp_y].pid)
				PrepAllItems_PutPName(&gPrepTexts3[1], gPrepItemListData[proc->menu_scroll_bar_disp_idx / 0x10 + proc->hand_disp_y].pid, 0x18, 0);

			PutUiEntryHover(
				proc->hand_disp_x * 14 + 2,
				proc->hand_disp_y * 2 + 9 - proc->hand_disp_x * 4,
				12);
			break;
		}

		if (((gKeySt->repeated & KEY_DPAD_DOWN) || ((gKeySt->pressed2 & KEY_DPAD_DOWN) && proc->unk_4A == 2)) && proc->hand_disp_y <= 5) {
			if (proc->hand_disp_y == 5 && proc->menu_scroll_bar_disp_idx / 0x10 + 7 < gPrepMenuScrollPos) {
				func_fe6_0807DB80(&gPrepTexts1[1][0], 1, proc->menu_scroll_bar_disp_idx / 0x10 + 7, proc->units[0], 0);
				func_fe6_0807D358(proc);

				if (invalid_pid != gPrepItemListData[proc->menu_scroll_bar_disp_idx / 0x10 + proc->hand_disp_y + 1].pid)
					PrepAllItems_PutPName(&gPrepTexts3[1], gPrepItemListData[proc->menu_scroll_bar_disp_idx / 0x10 + proc->hand_disp_y + 1].pid, 0x18, 0);

				proc->menu_scroll_bar_disp_idx += proc->unk_4A * 4;
				proc->menu_scrolling_pos = 2;
			} else {
				if (proc->menu_scroll_bar_disp_idx / 0x10 + proc->hand_disp_y + 1 >= gPrepMenuScrollPos)
					break;

				RemoveUiEntryHover(
					proc->hand_disp_x * 14 + 2,
					proc->hand_disp_y * 2 + 9 - proc->hand_disp_x * 4,
					12);

				proc->hand_disp_y++;

				if (invalid_pid != gPrepItemListData[proc->menu_scroll_bar_disp_idx / 0x10 + proc->hand_disp_y].pid)
					PrepAllItems_PutPName(&gPrepTexts3[1], gPrepItemListData[proc->menu_scroll_bar_disp_idx / 0x10 + proc->hand_disp_y].pid, 0x18, 0);

				PutUiEntryHover(
					proc->hand_disp_x * 14 + 2,
					proc->hand_disp_y * 2 + 9 - proc->hand_disp_x * 4,
					12);
			}

			PlaySe(SONG_66);
			break;
		}

		if (gKeySt->repeated & KEY_DPAD_RIGHT) {
			PlaySe(SONG_67);

			proc->unk_32[proc->convoy_page] = proc->menu_scroll_bar_disp_idx / 0x10;
			proc->unk_3B[proc->convoy_page] = proc->hand_disp_y;

			RemoveUiEntryHover(
				proc->hand_disp_x * 14 + 2,
				proc->hand_disp_y * 2 + 9 - proc->hand_disp_x * 4,
				12);

			proc->convoy_scrolling_pos = 0x38;
			proc->menu_scrolling_pos = 5;
		} else if (gKeySt->repeated & KEY_DPAD_LEFT) {
			PlaySe(SONG_67);

			proc->unk_32[proc->convoy_page] = proc->menu_scroll_bar_disp_idx / 0x10;
			proc->unk_3B[proc->convoy_page] = proc->hand_disp_y;

			RemoveUiEntryHover(
				proc->hand_disp_x * 14 + 2,
				proc->hand_disp_y * 2 + 9 - proc->hand_disp_x * 4,
				12);

			proc->convoy_scrolling_pos = 0xC8;
			proc->menu_scrolling_pos = 10;
		}
		break;

	case 1:
		proc->menu_scroll_bar_disp_idx -= proc->unk_4A * 4;

		if ((proc->menu_scroll_bar_disp_idx % 16) == 0) {
			TmFillRect(gBg2Tm + TM_OFFSET(15, ((proc->menu_scroll_bar_disp_idx / 0x10 + 7) * 2) & 0x1F), 15, 1, 0);
			EnableBgSync(BG2_SYNC_BIT);
			proc->menu_scrolling_pos = 0;
		}
		break;

	case 2:
		proc->menu_scroll_bar_disp_idx += proc->unk_4A * 4;

		if ((proc->menu_scroll_bar_disp_idx % 16) == 0) {
			TmFillRect(gBg2Tm + TM_OFFSET(15, ((proc->menu_scroll_bar_disp_idx / 0x10 - 1) * 2) & 0x1F), 15, 1, 0);
			EnableBgSync(BG2_SYNC_BIT);
			proc->menu_scrolling_pos = 0;
		}
		break;

	case 5:
		proc->convoy_scrolling_pos += 0x38;

		if (proc->convoy_scrolling_pos == 0x70)
			proc->menu_scrolling_pos = 6;
		break;

	case 6:
		proc->convoy_scrolling_pos = 0x90;

		if (proc->convoy_page == 8)
			proc->convoy_page = 0;
		else
			proc->convoy_page++;

		proc->menu_scroll_bar_disp_idx = proc->unk_32[proc->convoy_page] * 0x10;
		proc->hand_disp_y = proc->unk_3B[proc->convoy_page];

		func_fe6_0807D834(proc->convoy_page);
		func_fe6_080823A0(&proc->hand_disp_y, &proc->menu_scroll_bar_disp_idx);
		func_fe6_0807D9E4(&gPrepTexts1[1][0], 1, proc->units[0], proc->menu_scroll_bar_disp_idx / 0x10, 0);

		PutUiEntryHover(
			proc->hand_disp_x * 14 + 2,
			proc->hand_disp_y * 2 + 9 - proc->hand_disp_x * 4,
			12);

		if (invalid_pid != gPrepItemListData[proc->menu_scroll_bar_disp_idx / 0x10 + proc->hand_disp_y].pid || gPrepMenuScrollPos == 0)
			PrepAllItems_PutPName(&gPrepTexts3[1], gPrepItemListData[proc->menu_scroll_bar_disp_idx / 0x10 + proc->hand_disp_y].pid, 0x18, 0);

		func_fe6_0807D358(proc);

		proc->convoy_scrolling_pos += 0xE;
		proc->menu_scrolling_pos = 7;
		break;

	case 7:
		proc->convoy_scrolling_pos += 0xE;

		if (proc->convoy_scrolling_pos == 0)
			proc->menu_scrolling_pos = 0;
		break;

	case 10:
		proc->convoy_scrolling_pos -= 0x38;

		if (proc->convoy_scrolling_pos == 0x90)
			proc->menu_scrolling_pos = 11;
		break;

	case 11:
		proc->convoy_scrolling_pos = 0x70;

		if (proc->convoy_page == 0)
			proc->convoy_page = 8;
		else
			proc->convoy_page--;

		RemoveUiEntryHover(
			proc->hand_disp_x * 14 + 2,
			proc->hand_disp_y * 2 + 9 - proc->hand_disp_x * 4,
			12);

		proc->menu_scroll_bar_disp_idx = proc->unk_32[proc->convoy_page] * 0x10;
		proc->hand_disp_y = proc->unk_3B[proc->convoy_page];

		func_fe6_0807D834(proc->convoy_page);
		func_fe6_080823A0(&proc->hand_disp_y, &proc->menu_scroll_bar_disp_idx);
		func_fe6_0807D9E4(&gPrepTexts1[1][0], 1, proc->units[0], proc->menu_scroll_bar_disp_idx / 0x10, 0);

		PutUiEntryHover(
			proc->hand_disp_x * 14 + 2,
			proc->hand_disp_y * 2 + 9 - proc->hand_disp_x * 4,
			12);

		if (invalid_pid != gPrepItemListData[proc->menu_scroll_bar_disp_idx / 0x10 + proc->hand_disp_y].pid || gPrepMenuScrollPos == 0)
			PrepAllItems_PutPName(&gPrepTexts3[1], gPrepItemListData[proc->menu_scroll_bar_disp_idx / 0x10 + proc->hand_disp_y].pid, 0x18, 0);

		func_fe6_0807D358(proc);

		proc->convoy_scrolling_pos -= 0xE;
		proc->menu_scrolling_pos = 12;
		break;

	case 12:
		proc->convoy_scrolling_pos -= 0xE;

		if (proc->convoy_scrolling_pos == 0)
			proc->menu_scrolling_pos = 0;
		break;
	}

	SetBgOffset(BG_2, proc->convoy_scrolling_pos, (proc->menu_scroll_bar_disp_idx - 0x28) & 0xFF);

	if (proc->unk29 != 0) {
		if (prev_page != proc->convoy_page || prev_idx != proc->hand_disp_y + proc->menu_scroll_bar_disp_idx / 0x10) {
			if (proc->hand_disp_x == 0) {
				StartItemHelpBox(
					proc->hand_disp_x * 0x70 + 0x10,
					proc->hand_disp_y * 0x10 + 0x48 - proc->hand_disp_x * 0x20,
					proc->units[0]->items[proc->hand_disp_y]);
			} else if (gPrepMenuScrollPos == 0) {
				if (proc->unk29 != 1)
					CloseHelpBox();

				proc->unk29 = 1;
			} else {
				StartItemHelpBox(
					proc->hand_disp_x * 0x70 + 0x10,
					proc->hand_disp_y * 0x10 + 0x48 - proc->hand_disp_x * 0x20,
					gPrepItemListData[proc->hand_disp_y + proc->menu_scroll_bar_disp_idx / 0x10].item);

				proc->unk29 = 2;
			}
		}
	}

	if (proc->timer == 1) {
		SetWinEnable(1, 0, 0);
		SetWin0Box(0x80, 0x28, 0xE0, 0x98);
		SetWin0Layers(1, 1, 1, 1, 1);
		SetWOutLayers(1, 1, 0, 1, 1);
		proc->timer = 2;
	} else if (proc->timer < 2) {
		proc->timer++;
	}
}

void func_fe6_0807FBE8(struct PrepSubItemProc *proc)
{
	SetWinEnable(1, 0, 0);
	SetWin0Box(0x80, 0x28, 0xE0, 0x98);
	SetWin0Layers(1, 1, 1, 1, 1);
	SetWOutLayers(1, 1, 0, 1, 1);

	PutUiWindowFrame(15, 4, 15, 16, 0);
	func_fe6_0807D9E4(&gPrepTexts1[1][0], 1, proc->units[0], proc->menu_scroll_bar_disp_idx / 0x10, 1);
	EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT | BG2_SYNC_BIT);

	SetBgOffset(
		BG_2,
		proc->convoy_scrolling_pos,
		(proc->menu_scroll_bar_disp_idx - 0x28) & 0xFF);

	SetPrepMenuScrollBarBaseInfo(
		proc->proc_menuscroll,
		0xE0, 0x30, 0xC,
		proc->menu_scroll_bar_disp_idx,
		gPrepMenuScrollPos, 7);

	PutUiEntryHover(
		proc->hand_disp_x * 14 + 2,
		proc->hand_disp_y * 2 + 9 - proc->hand_disp_x * 4,
		12);

	func_fe6_0807E06C(true);
	proc->in_sel_action_menu = true;
}

void PrepSubItem_StartSupplyScreen(struct PrepSubItemProc *proc)
{
	TmFillRect(gBg0Tm + TM_OFFSET(0xF, 0), 0xF, 0x13, 0);
	TmFillRect(gBg1Tm + TM_OFFSET(0xF, 0), 0xF, 0x13, 0);
	TmFillRect(gBg2Tm + TM_OFFSET(0xF, 0), 0xF, 0x1F, 0);

	SetPrepMenuScrollBarBaseInfo(
		proc->proc_menuscroll,
		0, 0, 0xD, 0, 0, 0);

	if (proc->unk30 == 0xFF) {
		const u16 *supply_items = GetSupplyItems();
		u16 i, j;

		proc->unk30 = 0;
		proc->sel_action = 0;
		gPrepAllItemsCount = 0;

		for (i = 0; i < SUPPLY_ITEM_COUNT && supply_items[i] != 0; i++) {
			gPrepItemListData[i].item = supply_items[i];
			gPrepItemListData[i].pid = 0;
			gPrepItemListData[i].slot = i;
			gPrepAllItemsCount++;
		}

		if (proc->unk2D < 4)
			proc->convoy_page = proc->proc_parent->unk_3A;
		else
			proc->convoy_page = 0;

		func_fe6_0807D834(proc->convoy_page);
	}

	proc->menu_scroll_bar_disp_idx = proc->unk_32[proc->convoy_page] * 0x10;
	proc->hand_disp_x = 1;
	proc->hand_disp_y = proc->unk_3B[proc->convoy_page];

	func_fe6_080823A0(&proc->hand_disp_y, &proc->menu_scroll_bar_disp_idx);

	if (proc->unk4B == 0) {
		PrepPutText(
			&gPrepTexts1[1][0],
			gBg2Tm + TM_OFFSET(0x15, 4),
			(GetUnitItemCount(proc->units[0]) != 0) 
				? TEXT_COLOR_SYSTEM_WHITE
				: TEXT_COLOR_SYSTEM_GRAY,
			0,
			String_Prep_083272AC
		);

		PrepPutText(
			&gPrepTexts1[1][1],
			gBg2Tm + TM_OFFSET(0x15, 6),
			(gPrepAllItemsCount != 0) 
				? TEXT_COLOR_SYSTEM_WHITE
				: TEXT_COLOR_SYSTEM_GRAY,
			0,
			String_Prep_083272B8
		);

		if (proc->unk_4C != 0)
			proc->unk_49 = 2;
		else {
			PrepPutText(
				&gPrepTexts1[1][2],
				gBg2Tm + TM_OFFSET(0x15, 8),
				(gPrepAllItemsCount != 0) 
					? TEXT_COLOR_SYSTEM_WHITE
					: TEXT_COLOR_SYSTEM_GRAY,
				0,
				String_Prep_083272C4
			);
			proc->unk_49 = 3;
		}
	}

	SetBgOffset(BG_2, 0, 0xD8);

	proc->menu_scrolling_pos = 0;
	proc->in_sel_action_menu = 0;
	EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT | BG2_SYNC_BIT);

	if (proc->unk2D == 0) {
		NewSallyCir2(proc, -1);
		proc->subproc1 = func_fe6_0807D2E0(proc);
	}

	PrepAllItems_PutTotalNum(0x18, 0);

	if (proc->unk2D == 4) {
		proc->subproc1 = func_fe6_0807D2E0(proc);
		proc->unk2D = 5;

		if (proc->unk4B != 0) {
			proc->sel_action = 2;
			func_fe6_0807FBE8(proc);
			Proc_Goto(proc, PL_PREP_SUBITEM_7);
			PrepItem_PutItemDesc(1, 0xB,
				gPrepItemListData[proc->menu_scroll_bar_disp_idx / 0x10 + proc->hand_disp_y].item,
				proc->subproc1);
			func_fe6_08071B80(0x10, 0x10, MSG_C47, proc);
			return;
		}
	} else if (proc->unk2D < 4) {
		proc->unk2D = 2;
		proc->unk4B = 0;
	}

	PutUiWindowFrame(18, 8, 10, proc->unk_49 * 2 + 2, 0);
	PutUiEntryHover(0x13, proc->sel_action * 2 + 9, 7);
}

void PrepSubItem_SelLoop1(struct PrepSubItemProc *proc)
{
	u8 prev_sel = proc->sel_action;

	if (proc->unk29 != 0 && (gKeySt->pressed & (KEY_BUTTON_B | KEY_BUTTON_R))) {
		CloseHelpBox();
		proc->unk29 = 0;
		return;
	}

	if (gKeySt->repeated & KEY_DPAD_DOWN) {
		RemoveUiEntryHover(0x13, proc->sel_action * 2 + 9, 7);

		if (proc->sel_action < proc->unk_49 - 1) {
			proc->sel_action++;
			PlaySe(SONG_66);
		} else if (gKeySt->pressed & KEY_DPAD_DOWN) {
			proc->sel_action = 0;
			PlaySe(SONG_66);
		}

		PutUiEntryHover(0x13, proc->sel_action * 2 + 9, 7);
	} else if (gKeySt->repeated & KEY_DPAD_UP) {
		RemoveUiEntryHover(0x13, proc->sel_action * 2 + 9, 7);

		if (proc->sel_action != 0) {
			proc->sel_action--;
			PlaySe(SONG_66);
		} else if (gKeySt->pressed & KEY_DPAD_UP) {
			PlaySe(SONG_66);
			proc->sel_action = proc->unk_49 - 1;
		}

		PutUiEntryHover(0x13, proc->sel_action * 2 + 9, 7);
	} else if (gKeySt->pressed & KEY_BUTTON_B) {
		PlaySe(SONG_6B);

		if (proc->unk2D <= 3)
			NewSallyCir2(proc, 1);

		Proc_Goto(proc, PL_PREP_SUBITEM_6);
	} else if ((gKeySt->pressed & KEY_BUTTON_A) && proc->unk29 == 0) {
		if (proc->sel_action == 0) {
			if (GetUnitItemCount(proc->units[POS_L]) == 0) {
				PlaySe(SONG_6C);
				return;
			}

			PlaySe(SONG_6A);
			proc->hand_disp_y = 0;
			proc->hand_disp_x = 0;
		} else if (proc->sel_action == 1) {
			if (gPrepAllItemsCount == 0) {
				PlaySe(SONG_6C);
				return;
			}

			PlaySe(SONG_6A);
		} else if (proc->sel_action == 2) {
			if (gPrepAllItemsCount == 0) {
				PlaySe(SONG_6C);
				return;
			}

			PlaySe(SONG_6A);
			EndFaceById(0);
			TmFillRect(gBg0Tm, 0xF, 0x13, 0);
			TmFillRect(gBg1Tm, 0xF, 0x13, 0);
			TmFillRect(gBg2Tm, 0xF, 0x1F, 0);
			PrepItem_PutItemDesc(
				1, 0xB,
				gPrepItemListData[proc->menu_scroll_bar_disp_idx / 16 + proc->hand_disp_y].item,
				proc->subproc1);
		}

		func_fe6_0807FBE8(proc);
		Proc_Break(proc);
	} else if ((gKeySt->pressed & KEY_BUTTON_R) && proc->unk29 == 0) {
		proc->unk29 = 2;
		StartHelpBox(0xA0, proc->sel_action * 16 + 0x48, HelpboxMsg_0867929C[proc->sel_action]);
	}

	if (proc->unk29 == 2 && proc->sel_action != prev_sel) {
		StartHelpBox(0xA0, proc->sel_action * 16 + 0x48, HelpboxMsg_0867929C[proc->sel_action]);
	}
}

void PrepSubItem_SelLoop2(struct PrepSubItemProc *proc)
{
	u8 prev_sel = proc->hand_disp_y + proc->menu_scroll_bar_disp_idx / 16;
	u8 prev_page = proc->convoy_page;
	i16 i;
	int sel;

	if (proc->unk29 != 0 && (gKeySt->pressed & (KEY_BUTTON_B | KEY_BUTTON_R))) {
		if (proc->unk29 != 1) {
			CloseHelpBox();
			proc->unk29 = 0;
			return;
		}

		proc->unk29 = 0;
	}

	switch (proc->menu_scrolling_pos) {
	case 0xFF:
		if (proc->sel_action == 0) {
			RemoveUiEntryHover(
				proc->hand_disp_x * 14 + 2,
				proc->hand_disp_y * 2 + 9 - proc->hand_disp_x * 4,
				12);
		} else {
			proc->unk_3B[proc->convoy_page] = proc->hand_disp_y;
			proc->unk_32[proc->convoy_page] = proc->menu_scroll_bar_disp_idx / 16;
		}

		if (proc->sel_action == 2) {
			StartFace(0, GetUnitFid(proc->units[0]), 0x40, -4, 3);

			TmFillRect(gBg0Tm, 0xF, 0x13, 0);
			TmFillRect(gBg1Tm, 0xF, 0x13, 0);
			TmFillRect(gBg2Tm, 0xF, 0x1F, 0);

			PutUiWindowFrame(1, 8, 14, 12, 0);
			PrepSubItem_ResetIcon();

			PrepPutText(
				&gPrepTexts3[0], gBg0Tm, 0,
				(0x30 - GetStringTextLen(DecodeMsg(proc->units[0]->pinfo->msg_name))) / 2,
				DecodeMsg(proc->units[0]->pinfo->msg_name));

			func_fe6_0807D6C0(0, proc->units[0]);
		}

		if (proc->unk2D <= 3)
			proc->proc_parent->unk_3A = proc->convoy_page;

		Proc_Goto(proc, PL_PREP_SUBITEM_CONVOY);
		break;

	case 0x14:
		if ((gKeySt->repeated & KEY_DPAD_LEFT) && proc->unk30 != 0) {
			proc->unk30 = 0;
			PlaySe(SONG_66);
		}

		if ((gKeySt->repeated & KEY_DPAD_RIGHT) && proc->unk30 != 1) {
			proc->unk30 = 1;
			PlaySe(SONG_66);
		}

		if (gKeySt->pressed & KEY_BUTTON_A) {
			PlaySe(SONG_6A);

			if (proc->unk30 == 0) {
				for (i = proc->menu_scroll_bar_disp_idx / 16 + proc->hand_disp_y; i < gPrepAllItemsCount; i++)
					gPrepItemListData[i].item = gPrepItemListData[i + 1].item;

				gPrepAllItemsCount--;
				gPrepMenuScrollPos--;

				func_fe6_080823A0(&proc->hand_disp_y, &proc->menu_scroll_bar_disp_idx);
				func_fe6_0807D9E4(&gPrepTexts1[1][0], 1, proc->units[0], proc->menu_scroll_bar_disp_idx / 16, 0);
				PrepAllItems_Update();
				gAction.id = ACTION_TRADED_SUPPLY;

				if (proc->unk4B != 0)
					Proc_Goto(proc, PL_PREP_SUBITEM_6);
			}

			proc->menu_scrolling_pos = 0;
		} else if (gKeySt->pressed & KEY_BUTTON_B) {
			PlaySe(SONG_6B);
			proc->menu_scrolling_pos = 0;
		}

		if (proc->menu_scrolling_pos == 0) {
			PutUiEntryHover(
				proc->hand_disp_x * 14 + 2,
				proc->hand_disp_y * 2 + 9 - proc->hand_disp_x * 4,
				12);

			TmFillRect(gBg0Tm, 0xE, 0x13, 0);
			TmFillRect(gBg1Tm, 0xE, 0x13, 0);

			PrepItem_PutItemDesc(1, 0xB,
				gPrepItemListData[proc->menu_scroll_bar_disp_idx / 16 + proc->hand_disp_y].item,
				proc->subproc1);

			EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT);

			if (gPrepAllItemsCount == 0)
				proc->menu_scrolling_pos = 0xFF;
		}
		break;

	case 0:
		if (gKeySt->pressed & KEY_BUTTON_B) {
			if (proc->unk4B != 0) {
				PlaySe(SONG_6C);
				break;
			}

			PlaySe(SONG_6B);
			proc->menu_scrolling_pos = 0xFF;
		} else if ((gKeySt->pressed & KEY_BUTTON_A) && proc->unk29 == 0) {
			RemoveUiEntryHover(
				proc->hand_disp_x * 14 + 2,
				proc->hand_disp_y * 2 + 9 - proc->hand_disp_x * 4,
				12);

			if (proc->sel_action == 0) {
				if (GetTotalSupplyItemCount() == 100) {
					PlaySe(SONG_6C);
				} else if (proc->unk_4C != 0 && !PrepCanUnitPutItemToSupply(proc->units[0], proc->hand_disp_y)) {
					StartPrepErrorHelpbox(0x10, proc->hand_disp_y * 0x10 + 0x48, MSG_6C2, proc);
				} else {
					PlaySe(SONG_6A);

					func_fe6_0807DEC8(proc, proc->units[0]->items[proc->hand_disp_y]);

					for (i = gPrepAllItemsCount; i >= proc->menu_scroll_bar_disp_idx / 16; i--) {
						gPrepItemListData[i + 1].item = gPrepItemListData[i].item;
						gPrepItemListData[i + 1].pid = 0;
					}

					gPrepItemListData[proc->menu_scroll_bar_disp_idx / 16].item = proc->units[0]->items[proc->hand_disp_y];
					gPrepItemListData[proc->menu_scroll_bar_disp_idx / 16].pid = 0;

					gPrepAllItemsCount++;
					gPrepMenuScrollPos++;

					UnitRemoveItem(proc->units[0], proc->hand_disp_y);
					func_fe6_0807D6C0(0, proc->units[0]);
					PrepAllItems_Update();
					gAction.id = ACTION_TRADED_SUPPLY;

					if (GetUnitItemCount(proc->units[0]) == 0) {
						func_fe6_0807D358(proc);

						if (proc->unk2D <= 3)
							proc->proc_parent->unk_3A = proc->convoy_page;

						Proc_Goto(proc, PL_PREP_SUBITEM_CONVOY);
						return;
					}

					func_fe6_0807D9E4(&gPrepTexts1[1][0], 1, proc->units[0], proc->menu_scroll_bar_disp_idx / 16, 0);

					if (GetUnitItemCount(proc->units[0]) < proc->hand_disp_y + 1)
						proc->hand_disp_y--;
				}
			} else if (proc->sel_action == 1) {
				if (gPrepMenuScrollPos != 0 && GetUnitItemCount(proc->units[0]) <= 4) {
					PlaySe(SONG_6A);

					proc->units[0]->items[GetUnitItemCount(proc->units[0])] =
						gPrepItemListData[proc->menu_scroll_bar_disp_idx / 16 + proc->hand_disp_y].item;

					UnitRemoveInvalidItems(proc->units[0]);

					for (i = proc->menu_scroll_bar_disp_idx / 16 + proc->hand_disp_y; i < gPrepAllItemsCount; i++)
						gPrepItemListData[i].item = gPrepItemListData[i + 1].item;

					gPrepAllItemsCount--;
					gPrepMenuScrollPos--;

					func_fe6_080823A0(&proc->hand_disp_y, &proc->menu_scroll_bar_disp_idx);
					func_fe6_0807D9E4(&gPrepTexts1[1][0], 1, proc->units[0], proc->menu_scroll_bar_disp_idx / 16, 0);
					func_fe6_0807D6C0(0, proc->units[0]);
					PrepAllItems_Update();
					gAction.id = ACTION_TRADED_SUPPLY;

					if (GetUnitItemCount(proc->units[0]) == 5 || gPrepAllItemsCount == 0)
						proc->menu_scrolling_pos = 0xFF;
				} else {
					PlaySe(SONG_6C);
				}
			}

			if (proc->sel_action == 2) {
				if (gPrepMenuScrollPos != 0) {
					if (GetItemAttributes(gPrepItemListData[proc->menu_scroll_bar_disp_idx / 16 + proc->hand_disp_y].item) & ITEM_ATTR_IMPORTANT) {
						StartPrepErrorHelpbox(
							proc->hand_disp_x * 0x70 + 0x10,
							proc->hand_disp_y * 0x10 + 0x48 - proc->hand_disp_x * 0x20,
							MSG_C33, proc);
					} else {
						PlaySe(SONG_6A);

						proc->unk30 = 1;
						proc->menu_scrolling_pos = 0x14;

						PutUiWindowFrame(2, 4, 12, 7, 0);
						PrepPutText(&gPrepTexts1[0][0], gBg0Tm + TM_OFFSET(4, 5), 0, 0, String_Prep_083272CC);
						PrepPutText(&gPrepTexts1[0][1], gBg0Tm + TM_OFFSET(7, 5), 0, 0, String_Prep_083272D4);
						PrepPutText(&gPrepTexts1[0][2], gBg0Tm + TM_OFFSET(5, 8), 0, 0, String_Prep_Yes);
						PrepPutText(&gPrepTexts1[0][3], gBg0Tm + TM_OFFSET(9, 8), 0, 0, String_Prep_No);
						break;
					}
				} else {
					PlaySe(SONG_6C);
					PutUiEntryHover(
						proc->hand_disp_x * 14 + 2,
						proc->hand_disp_y * 2 + 9 - proc->hand_disp_x * 4,
						12);
					break;
				}
			} else {
				func_fe6_0807D358(proc);
			}

			PutUiEntryHover(
				proc->hand_disp_x * 14 + 2,
				proc->hand_disp_y * 2 + 9 - proc->hand_disp_x * 4,
				12);
		} else if ((gKeySt->pressed & KEY_BUTTON_R) && proc->unk29 == 0) {
			if (proc->sel_action == 0) {
				proc->unk29 = 2;
				StartItemHelpBox(
					proc->hand_disp_x * 0x70 + 0x10,
					proc->hand_disp_y * 0x10 + 0x48 - proc->hand_disp_x * 0x20,
					proc->units[0]->items[proc->hand_disp_y]);
			} else if (gPrepMenuScrollPos != 0 && (proc->sel_action == 1 || proc->sel_action == 2)) {
				proc->unk29 = 2;
				StartItemHelpBox(
					proc->hand_disp_x * 0x70 + 0x10,
					proc->hand_disp_y * 0x10 + 0x48 - proc->hand_disp_x * 0x20,
					gPrepItemListData[proc->menu_scroll_bar_disp_idx / 16 + proc->hand_disp_y].item);
			}
		} else {
			if (proc->hand_disp_x == 1) {
				if (gKeySt->held & KEY_BUTTON_L)
					proc->unk_4A = 2;
				else
					proc->unk_4A = 1;

				if ((gKeySt->repeated & KEY_DPAD_UP) || ((gKeySt->pressed2 & KEY_DPAD_UP) && proc->unk_4A == 2)) {
					if (proc->hand_disp_y == 1 && proc->menu_scroll_bar_disp_idx != 0) {
						PlaySe(SONG_66);
						func_fe6_0807DB80(&gPrepTexts1[1][0], 1, proc->menu_scroll_bar_disp_idx / 16 - 1, proc->units[0], 0);
						func_fe6_0807D358(proc);
						proc->menu_scroll_bar_disp_idx -= proc->unk_4A * 4;
						proc->menu_scrolling_pos = 1;
						break;
					}

					if (proc->hand_disp_y == 0)
						break;

					PlaySe(SONG_66);
					RemoveUiEntryHover(
						proc->hand_disp_x * 14 + 2,
						proc->hand_disp_y * 2 + 9 - proc->hand_disp_x * 4,
						12);
					proc->hand_disp_y--;
					PutUiEntryHover(
						proc->hand_disp_x * 14 + 2,
						proc->hand_disp_y * 2 + 9 - proc->hand_disp_x * 4,
						12);
					break;
				}

				if (((gKeySt->repeated & KEY_DPAD_DOWN) || ((gKeySt->pressed2 & KEY_DPAD_DOWN) && proc->unk_4A == 2)) && proc->hand_disp_y <= 5) {
					if (proc->hand_disp_y == 5 && proc->menu_scroll_bar_disp_idx / 16 + 7 < gPrepMenuScrollPos) {
						PlaySe(SONG_66);
						func_fe6_0807DB80(&gPrepTexts1[1][0], 1, proc->menu_scroll_bar_disp_idx / 16 + 7, proc->units[0], 0);
						func_fe6_0807D358(proc);
						proc->menu_scroll_bar_disp_idx += proc->unk_4A * 4;
						proc->menu_scrolling_pos = 2;
						break;
					}

					if (proc->menu_scroll_bar_disp_idx / 16 + proc->hand_disp_y + 1 >= gPrepMenuScrollPos)
						break;

					PlaySe(SONG_66);
					RemoveUiEntryHover(
						proc->hand_disp_x * 14 + 2,
						proc->hand_disp_y * 2 + 9 - proc->hand_disp_x * 4,
						12);
					proc->hand_disp_y++;
					PutUiEntryHover(
						proc->hand_disp_x * 14 + 2,
						proc->hand_disp_y * 2 + 9 - proc->hand_disp_x * 4,
						12);
					break;
				}
			} else if (gKeySt->repeated & KEY_DPAD_UP) {
				RemoveUiEntryHover(
					proc->hand_disp_x * 14 + 2,
					proc->hand_disp_y * 2 + 9 - proc->hand_disp_x * 4,
					12);

				if (proc->hand_disp_y != 0) {
					PlaySe(SONG_66);
					proc->hand_disp_y--;
				} else if (gKeySt->pressed & KEY_DPAD_UP) {
					PlaySe(SONG_66);
					proc->hand_disp_y = GetUnitItemCount(proc->units[proc->hand_disp_x]) - 1;
				}

				PutUiEntryHover(
					proc->hand_disp_x * 14 + 2,
					proc->hand_disp_y * 2 + 9 - proc->hand_disp_x * 4,
					12);
			} else if (gKeySt->repeated & KEY_DPAD_DOWN) {
				RemoveUiEntryHover(
					proc->hand_disp_x * 14 + 2,
					proc->hand_disp_y * 2 + 9 - proc->hand_disp_x * 4,
					12);

				if (proc->hand_disp_y < GetUnitItemCount(proc->units[0]) - 1 && proc->hand_disp_y < 4) {
					PlaySe(SONG_66);
					proc->hand_disp_y++;
				} else if (gKeySt->pressed & KEY_DPAD_DOWN) {
					PlaySe(SONG_66);
					proc->hand_disp_y = 0;
				}

				PutUiEntryHover(
					proc->hand_disp_x * 14 + 2,
					proc->hand_disp_y * 2 + 9 - proc->hand_disp_x * 4,
					12);
			}

			if (proc->hand_disp_x == 1) {
				if (gKeySt->repeated & KEY_DPAD_RIGHT) {
					PlaySe(SONG_67);
					RemoveUiEntryHover(
						proc->hand_disp_x * 14 + 2,
						proc->hand_disp_y * 2 + 9 - proc->hand_disp_x * 4,
						12);
					proc->unk_32[proc->convoy_page] = proc->menu_scroll_bar_disp_idx / 16;
					proc->unk_3B[proc->convoy_page] = proc->hand_disp_y;
					proc->convoy_scrolling_pos = 0x38;
					proc->menu_scrolling_pos = 5;
				} else if (gKeySt->repeated & KEY_DPAD_LEFT) {
					PlaySe(SONG_67);
					RemoveUiEntryHover(
						proc->hand_disp_x * 14 + 2,
						proc->hand_disp_y * 2 + 9 - proc->hand_disp_x * 4,
						12);
					proc->unk_32[proc->convoy_page] = proc->menu_scroll_bar_disp_idx / 16;
					proc->unk_3B[proc->convoy_page] = proc->hand_disp_y;
					proc->convoy_scrolling_pos = 0xC8;
					proc->menu_scrolling_pos = 10;
				}
			}
		}
		break;

	case 1:
		proc->menu_scroll_bar_disp_idx -= proc->unk_4A * 4;

		if ((proc->menu_scroll_bar_disp_idx % 16) == 0) {
			TmFillRect(gBg2Tm + TM_OFFSET(0xF, ((proc->menu_scroll_bar_disp_idx / 16 + 7) * 2) & 0x1F), 0xF, 1, 0);
			EnableBgSync(BG2_SYNC_BIT);
			proc->menu_scrolling_pos = 0;
		}
		break;

	case 2:
		proc->menu_scroll_bar_disp_idx += proc->unk_4A * 4;

		if ((proc->menu_scroll_bar_disp_idx % 16) == 0) {
			TmFillRect(gBg2Tm + TM_OFFSET(0xF, ((proc->menu_scroll_bar_disp_idx / 16 - 1) * 2) & 0x1F), 0xF, 1, 0);
			EnableBgSync(BG2_SYNC_BIT);
			proc->menu_scrolling_pos = 0;
		}
		break;

	case 5:
		proc->convoy_scrolling_pos += 0x38;

		if (proc->convoy_scrolling_pos == 0x70)
			proc->menu_scrolling_pos = 6;
		break;

	case 6:
		proc->convoy_scrolling_pos = 0x90;

		if (proc->convoy_page == 8)
			proc->convoy_page = 0;
		else
			proc->convoy_page++;

		proc->menu_scroll_bar_disp_idx = proc->unk_32[proc->convoy_page] * 16;
		proc->hand_disp_y = proc->unk_3B[proc->convoy_page];

		func_fe6_0807D834(proc->convoy_page);
		func_fe6_080823A0(&proc->hand_disp_y, &proc->menu_scroll_bar_disp_idx);
		func_fe6_0807D9E4(&gPrepTexts1[1][0], 1, proc->units[0], proc->menu_scroll_bar_disp_idx / 16, 1);

		PutUiEntryHover(
			proc->hand_disp_x * 14 + 2,
			proc->hand_disp_y * 2 + 9 - proc->hand_disp_x * 4,
			12);

		func_fe6_0807D358(proc);

		proc->convoy_scrolling_pos += 0xE;
		proc->menu_scrolling_pos = 7;
		break;

	case 7:
		proc->convoy_scrolling_pos += 0xE;

		if (proc->convoy_scrolling_pos == 0)
			proc->menu_scrolling_pos = 0;
		break;

	case 10:
		proc->convoy_scrolling_pos -= 0x38;

		if (proc->convoy_scrolling_pos == 0x90)
			proc->menu_scrolling_pos = 11;
		break;

	case 11:
		proc->convoy_scrolling_pos = 0x70;

		if (proc->convoy_page == 0)
			proc->convoy_page = 8;
		else
			proc->convoy_page--;

		RemoveUiEntryHover(
			proc->hand_disp_x * 14 + 2,
			proc->hand_disp_y * 2 + 9 - proc->hand_disp_x * 4,
			12);

		proc->menu_scroll_bar_disp_idx = proc->unk_32[proc->convoy_page] * 16;
		proc->hand_disp_y = proc->unk_3B[proc->convoy_page];

		func_fe6_0807D834(proc->convoy_page);
		func_fe6_080823A0(&proc->hand_disp_y, &proc->menu_scroll_bar_disp_idx);
		func_fe6_0807D9E4(&gPrepTexts1[1][0], 1, proc->units[0], proc->menu_scroll_bar_disp_idx / 16, 1);

		PutUiEntryHover(
			proc->hand_disp_x * 14 + 2,
			proc->hand_disp_y * 2 + 9 - proc->hand_disp_x * 4,
			12);

		func_fe6_0807D358(proc);

		proc->convoy_scrolling_pos -= 0xE;
		proc->menu_scrolling_pos = 12;
		break;

	case 12:
		proc->convoy_scrolling_pos -= 0xE;

		if (proc->convoy_scrolling_pos == 0)
			proc->menu_scrolling_pos = 0;
		break;
	}

	sel = proc->menu_scroll_bar_disp_idx / 16 + proc->hand_disp_y;

	if (prev_sel != sel || prev_page != proc->convoy_page) {
		if (proc->unk29 != 0) {
			if (proc->sel_action == 0) {
				StartItemHelpBox(
					proc->hand_disp_x * 0x70 + 0x10,
					proc->hand_disp_y * 0x10 + 0x48 - proc->hand_disp_x * 0x20,
					proc->units[0]->items[proc->hand_disp_y]);
			} else if (gPrepMenuScrollPos == 0) {
				if (proc->unk29 != 1)
					CloseHelpBox();

				proc->unk29 = 1;
			} else {
				StartItemHelpBox(
					proc->hand_disp_x * 0x70 + 0x10,
					proc->hand_disp_y * 0x10 + 0x48 - proc->hand_disp_x * 0x20,
					gPrepItemListData[sel].item);

				proc->unk29 = 2;
			}
		}

		if (proc->sel_action == 2)
			PrepItem_PutItemDesc(1, 0xB,
				gPrepItemListData[proc->menu_scroll_bar_disp_idx / 16 + proc->hand_disp_y].item,
				proc->subproc1);
	}

	SetBgOffset(BG_2, proc->convoy_scrolling_pos, (proc->menu_scroll_bar_disp_idx - 0x28) & 0xFF);
	proc->timer++;
}

void PrepSubItem_HandleAction(struct PrepSubItemProc *proc)
{
	if (proc->unk2D == PREP_SUB2U2D_3) {
		proc->proc_parent->unk_39 = proc->convoy_page;

		SetPrepMenuScrollBarBaseInfo(
			proc->proc_menuscroll,
			0, 0, 13, 0, 0, 0);

		proc->unk_4E = proc->menu_scroll_bar_disp_idx;
		proc->unk_47 = proc->hand_disp_y;

		if (gPrepItemListData[proc->hand_disp_y + proc->menu_scroll_bar_disp_idx / 16].pid == 0) {
			proc->menu_scrolling_pos = 0;
			proc->unk_48 = gPrepItemListData[proc->hand_disp_y + proc->menu_scroll_bar_disp_idx / 16].slot;
			return;
		}
	}

	if (proc->hand_disp_x == 0) {
		RemoveUiEntryHover(
			proc->hand_disp_x * 14 + 2,
			proc->hand_disp_y * 2 + 9 - proc->hand_disp_x * 4,
			12);
	}

	TmFillRect(gBg0Tm + TM_OFFSET(0xF, 0), 0xF, 0x13, 0);
	TmFillRect(gBg1Tm + TM_OFFSET(0xF, 0), 0xF, 0x13, 0);
	TmFillRect(gBg2Tm + TM_OFFSET(0xF, 0), 0xF, 0x1F, 0);

	if (proc->unk2D == PREP_SUB2U2D_3) {
		proc->proc_parent->unk_39 = proc->convoy_page;

		if (gPrepItemListData[proc->hand_disp_y + proc->menu_scroll_bar_disp_idx / 16].pid == 0) {
			proc->unk_48 = gPrepItemListData[proc->hand_disp_y + proc->menu_scroll_bar_disp_idx / 16].slot;
			Proc_Goto(proc, PL_PREP_SUBITEM_CONVOY);
		} else {
			proc->units[1] = GetUnitByPid(gPrepItemListData[proc->hand_disp_y + proc->menu_scroll_bar_disp_idx / 16].pid);
			proc->hand_disp_y = gPrepItemListData[proc->hand_disp_y + proc->menu_scroll_bar_disp_idx / 16].slot;
			Proc_Goto(proc, PL_PREP_SUBITEM_TRADE);
		}
	} else {
		EndFaceById(1);
		Proc_Goto(proc, PL_PREP_SUBITEM_VIEWALL);
	}

	EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT | BG2_SYNC_BIT);
}

void PrepSubItem_OnEnd(struct PrepSubItemProc *proc)
{
	if (proc->unk2D != PL_PREP_SUBITEM_5) {
		if (proc->unk2A == 0)
			proc->proc_parent->unk_39 = proc->convoy_page;

		if (proc->unk2A == 4)
			proc->proc_parent->unk_3A = proc->convoy_page;

		InitBmBgLayers();
	} else {
		Proc_End(proc->subproc1);
	}

	EndFaceById(0);
	EndFaceById(1);

	TmFill(gBg0Tm, 0);
	TmFill(gBg1Tm, 0);
	TmFill(gBg2Tm, 0);

	EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT | BG2_SYNC_BIT);
}

struct ProcScr CONST_DATA ProcScr_PrepSubItemScreen[] = {
	PROC_19,
	PROC_YIELD,
	PROC_CALL(PrepSubItemScreen_Init),
PROC_LABEL(PL_PREP_SUBITEM_VIEWALL),
	PROC_CALL(PrepSubItem_StartViewAllScreen),
PROC_LABEL(1),
	PROC_REPEAT(PrepSubItem_ViewAll_Loop),
PROC_LABEL(PL_PREP_SUBITEM_TRADE),
	PROC_CALL(PrepSubItem_StartTradeScreen),
PROC_LABEL(3),
	PROC_REPEAT(PrepSubItem_Trade_Loop),
PROC_LABEL(PL_PREP_SUBITEM_CONVOY),
	PROC_CALL(PrepSubItem_StartSupplyScreen),
PROC_LABEL(5),
	PROC_REPEAT(PrepSubItem_SelLoop1),
	PROC_REPEAT(PrepSubItem_SelLoop2),
PROC_LABEL(PL_PREP_SUBITEM_7),
	PROC_CALL(PrepSubItem_HandleAction),
PROC_LABEL(6),
	PROC_CALL(PrepSubItem_OnEnd),
	PROC_END,
};

void StartPrepSubItemScreen(struct PrepMenuProc *parent, u8 type)
{
	struct PrepSubItemProc *proc;

	proc = SpawnProcLocking(ProcScr_PrepSubItemScreen, parent);
	proc->unk2A = type;
	proc->unk2D = 0; // TODO: enum
}

struct ProcScr CONST_DATA ProcScr_BmSupplyScreen[] = {
	PROC_19,
	PROC_CALL(LockGame),
	PROC_YIELD,
	PROC_CALL(PrepSubItemScreen_Init),
PROC_LABEL(4),
	PROC_CALL(PrepSubItem_StartSupplyScreen),
	PROC_YIELD,
PROC_LABEL(5),
	PROC_REPEAT(PrepSubItem_SelLoop1),
PROC_LABEL(7),
	PROC_YIELD,
	PROC_REPEAT(PrepSubItem_SelLoop2),
PROC_LABEL(6),
	PROC_CALL(PrepSubItem_OnEnd),
	PROC_YIELD,
	PROC_CALL(UnlockGame),
	PROC_END,
};

void StartBmSupply(struct Unit *unit, ProcPtr parent)
{
	struct PrepSubItemProc *proc;

	if (parent == NULL)
		proc = SpawnProc(ProcScr_BmSupplyScreen, PROC_TREE_3);
	else
		proc = SpawnProcLocking(ProcScr_BmSupplyScreen, parent);

	proc->unk2D = 4; // TODO: enum
	proc->units[0] = unit;
	proc->unk4B = 0;
}

void StartBmSupplyForDrop(struct Unit *unit, ProcPtr parent)
{
	struct PrepSubItemProc *proc;

	if (parent == NULL)
		proc = SpawnProc(ProcScr_BmSupplyScreen, PROC_TREE_3);
	else
		proc = SpawnProcLocking(ProcScr_BmSupplyScreen, parent);

	proc->unk2D = 4; // TODO: enum
	proc->units[0] = unit;
	proc->unk4B = 1;
}

const char String_Prep_0832726C[] = TEXT("属性", "Affin");
const char String_Prep_08327274[] = TEXT("威力", "Mt");
const char String_Prep_0832727C[] = TEXT("命中", "Hit");
const char String_Prep_08327284[] = TEXT("必殺", "Crt");
const char String_Prep_0832728C[] = TEXT("重さ", "Wt");
const char String_Prep_08327294[] = TEXT("何もありません", "None");
const char Msg_Prep_Supply[] = TEXT("輸送隊", "Supply");
const char String_Prep_083272AC[] = TEXT("あずける", "Save");
const char String_Prep_083272B8[] = TEXT("うけとる", "Load");
const char String_Prep_083272C4[] = TEXT("すてる", "Discard");
const char String_Prep_083272CC[] = TEXT("本当に", "Are you sure");
const char String_Prep_083272D4[] = TEXT("すてますか", "Are you sure");
const char String_Prep_Yes[] = TEXT("はい", "Yes");
const char String_Prep_No[] = TEXT("いいえ", "No");
