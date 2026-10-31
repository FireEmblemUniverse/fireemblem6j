#include "prelude.h"

#include "armfunc.h"
#include "hardware.h"
#include "sound.h"
#include "icon.h"
#include "text.h"
#include "face.h"
#include "event.h"
#include "msg.h"
#include "util.h"
#include "item.h"
#include "unit.h"
#include "unitsprite.h"
#include "faction.h"
#include "chapterinfo.h"
#include "unitrearrange.h"
#include "ui.h"
#include "mu.h"
#include "map.h"
#include "bmio.h"
#include "shop.h"
#include "statscreen.h"
#include "helpbox.h"
#include "prepscreen.h"
#include "prepphase.h"
#include "savemenu.h"
#include "augury.h"
#include "secretscreen.h"
#include "unitlistscreen.h"

#include "constants/pids.h"
#include "constants/chapters.h"
#include "constants/msg.h"
#include "constants/songs.h"

#include "constants/videoalloc_global.h"

EWRAM_OVERLAY(0) struct Unit *gPrepUnitList[64] = {};
EWRAM_OVERLAY(0) u8 gPrepUnitCount = 0;
EWRAM_OVERLAY(0) int gPrepCursorUnitPid = 0;
EWRAM_OVERLAY(0) struct Text gPrepScreenText_PickLeftBar = {};
EWRAM_OVERLAY(0) struct Text gPrepScreenTexts_Units[16] = {};
EWRAM_OVERLAY(0) struct Text gPrepItemTexts[5] = {};
EWRAM_OVERLAY(0) struct Text gUnk_0200E88C[2] = {};
EWRAM_OVERLAY(0) struct Text gPrepScreenText_LeftPersonName = {};
EWRAM_OVERLAY(0) u16 gPrepTsaBuf[0x400] = {};
EWRAM_OVERLAY(0) u8 gPrepUnitPool[0x1000] = {};
EWRAM_OVERLAY(0) u16 gPrepFadePal[0x200] = {};
EWRAM_OVERLAY(0) u8 ImgBuf_PrepWorldMap[0x5000] = {};
EWRAM_OVERLAY(0) struct PrepMenuItem gPrepMenuItems[0x10] = {};
EWRAM_OVERLAY(0) u8 gPrepMenuItemCnt = 0;
EWRAM_OVERLAY(0) struct Text gPrepTexts1[2][10] = {};
EWRAM_OVERLAY(0) struct Text gPrepTexts3[2] = {};
EWRAM_OVERLAY(0) int gPrepSubMenuIcons[20] = {};
EWRAM_OVERLAY(0) struct PrepItemListEnt gPrepPageItemTable[400] = {};
EWRAM_OVERLAY(0) struct PrepItemListEnt gPrepItemListData[400] = {};
EWRAM_OVERLAY(0) u16 gPrepAllItemsCount = 0;
EWRAM_OVERLAY(0) u16 gPrepMenuScrollPos = 0;

void ResetSioPidPool(void)
{
	int i;

	for (i = 0; i < SID_PID_POOL_SIZE; i++)
		SioPidPool[i] = 0;
}

void RegisterSioPid(fu8 pid)
{
	int i;

	for (i = 0; i < SID_PID_POOL_SIZE; i++) {
		if (SioPidPool[i] == 0) {
			SioPidPool[i] = pid;
			return;
		}
	}
}

void RemoveSioPid(fu8 pid)
{
	int i, j;

	for (i = 0; i < SID_PID_POOL_SIZE; i++) {
		if (SioPidPool[i] == pid) {
			for (j = i; j < SID_PID_POOL_SIZE - 1; j++)
				SioPidPool[j] = SioPidPool[j + 1];

			SioPidPool[4] = 0;
			return;
		}
	}
}

void func_fe6_0807921C(void)
{
	FOR_UNITS_FACTION(FACTION_BLUE, unit, {
		if ((unit->flags & UNIT_FLAG_NOT_DEPLOYED) != 0) {
			// oof
			unit->flags |= UNIT_FLAG_DEAD;
		}
	})
}

void func_fe6_08079250(struct UnkProc_08678DE0 *proc)
{
	proc->unk_30 = 0;

	SetWinEnable(1, 1, 0);
	SetWin0Layers(0, 0, 0, 1, 0);
	SetWin1Layers(0, 0, 0, 1, 0);
	SetWOutLayers(1, 1, 1, 1, 1);
}

void func_fe6_080792C8(struct UnkProc_08678DE0 *proc)
{
	proc->unk_30 += 8;

	if (proc->unk_30 >= 0x40)
		proc->unk_30 = 0x40;

	SetWin0Box(0x68, 0x20, DISPLAY_WIDTH, 0x20 + proc->unk_30);
	SetWin1Box(0x68, DISPLAY_HEIGHT - proc->unk_30, DISPLAY_WIDTH, DISPLAY_HEIGHT);

	if (proc->unk_30 == 0x40) {
		Proc_Break(proc);

		proc->unk_30 = 0;

		if (proc->proc_parent->not_in_upper_menu == 0)
			proc->proc_parent->not_in_upper_menu = 1;
		else
			proc->proc_parent->not_in_upper_menu = 0;

		PrepScreen_DrawScreenInfo(proc->proc_parent);

		SetWinEnable(1, 0, 0);
		SetWin0Box(0x68, 0x20, DISPLAY_WIDTH, DISPLAY_HEIGHT);
	}
}

void func_fe6_08079388(struct UnkProc_08678DE0 *proc)
{
	proc->unk_30 += 8;

	if (proc->unk_30 >= 0x40)
		proc->unk_30 = 0x40;

	SetWin0Box(0x68, 0x20 + proc->unk_30, DISPLAY_WIDTH, DISPLAY_HEIGHT - proc->unk_30);

	if (proc->unk_30 == 0x40) {
		Proc_Break(proc);
		SetWinEnable(0, 0, 0);
	}
}

struct ProcScr CONST_DATA ProcScr_Unk_08678DE0[] = {
	PROC_CALL(func_fe6_08079250),
	PROC_REPEAT(func_fe6_080792C8),
	PROC_REPEAT(func_fe6_08079388),
	PROC_END,
};

void func_fe6_080793F0(struct PrepMenuProc *parent)
{
	SpawnProc(ProcScr_Unk_08678DE0, parent);
}

bool IsUnitMandatoryDeploy(struct Unit *unit)
{
	if (UNIT_PID(unit) == PID_ROY)
		return TRUE;

	if (gPlaySt.chapter == CHAPTER_24 && UNIT_PID(unit) == PID_FAE)
		return TRUE;

	return FALSE;
}

void InitPrepScreenMainMenu(struct PrepMenuProc *proc)
{
	SetPrepScreenMenuItem(PrepScreenMenu_OnPickUnits, 0, MSG_6AE, 0, MSG_659, PREPMENUITEM_UNITSEL);
	SetPrepScreenMenuItem(PrepScreenMenu_OnItems, 0, MSG_6AF, 0, MSG_65A, PREPMENUITEM_ITEMSEL);

	if (GetAuguryIndex() != 0xFF && (proc->link_arena_flag & PREPMENU_FLAG_MULTIARENA) == 0 && (gPlaySt.flags & PLAY_FLAG_COMPLETE) == 0) {
		// 占い
		SetPrepScreenMenuItem(PrepScreenMenu_Augury, 0, MSG_6B7, 0, MSG_6A3, PREPMENUITEM_AUGURY);
	}

	SetPrepScreenMenuItem(PrepScreenSubMenu_OnTrade, 1, MSG_6B3, proc->unk_2D == 1 ? 1 : 0, MSG_65F, PREPMENUITEM_TRADE);

	if ((proc->link_arena_flag & PREPMENU_FLAG_MULTIARENA) == 0) {
		if ((gPlaySt.flags & PLAY_FLAG_COMPLETE) == 0)
			SetPrepScreenMenuItem(PrepScreenMenu_OnSave, 0, MSG_6B1, 0, MSG_65C, PREPMENUITEM_SAVE);

		SetPrepScreenMenuItem(PrepScreenMenu_OnCheckMap, 0, MSG_6B2, 0, MSG_65D, PREPMENUITEM_CHECKMAP);
		SetPrepScreenMenuItem(PrepScreenSubMenu_OnDiscard, 1, MSG_6B4, 0, MSG_660, PREPMENUITEM_DISCARD);
	}

	SetPrepScreenMenuItem(PrepScreenSubMenu_Convoy, 1, MSG_6B5, 0, MSG_661, PREPMENUITEM_CONVOY);
	SetPrepScreenMenuItem(PrepScreenSubMenu_AllItems, 1, MSG_6B6, 0, MSG_662, PREPMENUITEM_ALLITEMS);

	if ((proc->link_arena_flag & PREPMENU_FLAG_MULTIARENA) == 0) {
		if ((gPlaySt.flags & (PLAY_FLAG_COMPLETE | PLAY_FLAG_HARD)) == 0)
			SetPrepScreenMenuItem(PrepScreenSubMenu_Shop, 1, MSG_6B9, 0, MSG_663, PREPMENUITEM_SHOP);
	}

	if ((proc->link_arena_flag & PREPMENU_FLAG_MULTIARENA) != 0)
		SetPrepScreenMenuItem(PrepScreenSubMenu_StartBattle, 0, MSG_6B0, 0, MSG_6F1, PREPMENUITEM_STARTBATTLE);
	else
		SetPrepScreenMenuItem(PrepScreenSubMenu_StartBattle, 0, MSG_6BA, 0, MSG_65E, PREPMENUITEM_STARTBATTLE);
}

void PrepUnit_DrawLeftUnitInfo(struct Unit * unit, u16 * tm)
{
	int text_offset;

	PutNumberOrBlank(tm + TM_OFFSET(8, 1), TEXT_COLOR_SYSTEM_BLUE, unit->level);
	PutNumberOrBlank(tm + TM_OFFSET(11, 1), TEXT_COLOR_SYSTEM_BLUE, unit->exp);
	PutNumberOrBlank(tm + TM_OFFSET(11, 3), TEXT_COLOR_SYSTEM_BLUE, GetUnitCurrentHp(unit));
	PutNumberOrBlank(tm + TM_OFFSET(8, 3), TEXT_COLOR_SYSTEM_BLUE, GetUnitMaxHp(unit));

	text_offset = (0x38 - GetStringTextLen(DecodeMsg(unit->pinfo->msg_name))) >> 1;

	ClearText(&gPrepScreenText_LeftPersonName);

	PutDrawText(&gPrepScreenText_LeftPersonName, tm + TM_OFFSET(3, 5), TEXT_COLOR_SYSTEM_WHITE,
		text_offset, 0, DecodeMsg(unit->pinfo->msg_name));
}

void PrepScreen_ReloadLeftUnitInfo(struct Unit * unit)
{
	u16 const * tiles = Tsa_PrepLeftUnitInfo;
	int ix, iy;

	TmFillRect(gPrepTsaBuf, 29, 29, 0);

	for (iy = 0; iy < 8; iy++)
		for (ix = 0; ix < 13; ix++)
			gPrepTsaBuf[TM_OFFSET(ix, iy + 10)] = tiles[ix + (7 - iy) * 13] + TILEREF(0, 1);

	ClearText(&gPrepScreenText_LeftPersonName);

	PutSpecialChar(gPrepTsaBuf + TM_OFFSET(9, 3), TEXT_COLOR_SYSTEM_GOLD, TEXT_SPECIAL_SLASH);
	PutSpecialChar(gPrepTsaBuf + TM_OFFSET(5, 3), TEXT_COLOR_SYSTEM_GOLD, TEXT_SPECIAL_HP_A);
	PutSpecialChar(gPrepTsaBuf + TM_OFFSET(6, 3), TEXT_COLOR_SYSTEM_GOLD, TEXT_SPECIAL_HP_B);
	PutSpecialChar(gPrepTsaBuf + TM_OFFSET(5, 1), TEXT_COLOR_SYSTEM_GOLD, TEXT_SPECIAL_LV_A);
	PutSpecialChar(gPrepTsaBuf + TM_OFFSET(6, 1), TEXT_COLOR_SYSTEM_GOLD, TEXT_SPECIAL_LV_B);
	PutSpecialChar(gPrepTsaBuf + TM_OFFSET(9, 1), TEXT_COLOR_SYSTEM_GOLD, TEXT_SPECIAL_EXP_E);

	PrepUnit_DrawLeftUnitInfo(unit, gPrepTsaBuf);

	PutFaceChibi(GetUnitFid(unit), gPrepTsaBuf + TM_OFFSET(1, 1),
		BGCHR_PREPMENU_230, BGPAL_PREPMENU_2, FALSE);
}

void PrepUnitUpdatePinfoAsync_work(struct ProcPrepUnitPinfoAsync *proc)
{
	struct Unit * unit = proc->unit;

	TmFillRect(gBg0Tm + TM_OFFSET(7, 1), 1, 3, 0);
	TmFillRect(gBg0Tm + TM_OFFSET(10, 1), 1, 3, 0);
	PrepUnit_DrawLeftUnitInfo(unit, gBg0Tm);

	EnableBgSync(BG0_SYNC_BIT);

	Proc_Break(proc);
}

struct ProcScr CONST_DATA ProcScr_PrepUnitUpdatePinfoAsync[] =
{
	PROC_YIELD,
	PROC_REPEAT(PrepUnitUpdatePinfoAsync_work),
	PROC_END,
};

void UpdatePrepUnitPinfoAsync(struct PrepMenuProc * parent)
{
	struct ProcPrepUnitPinfoAsync *proc;

	proc = SpawnProc(ProcScr_PrepUnitUpdatePinfoAsync, parent);
	proc->unit = gPrepUnitList[parent->list_num_cur];
}

void func_fe6_08079804(struct PrepMenuProc *proc)
{
	u16 const * tiles = Tsa_PrepLeftUnitInfo;
	int ix, iy;

	PutSpecialChar(gBg0Tm + TM_OFFSET(9, 3), TEXT_COLOR_SYSTEM_GOLD, TEXT_SPECIAL_SLASH);
	PutSpecialChar(gBg0Tm + TM_OFFSET(5, 3), TEXT_COLOR_SYSTEM_GOLD, TEXT_SPECIAL_HP_A);
	PutSpecialChar(gBg0Tm + TM_OFFSET(6, 3), TEXT_COLOR_SYSTEM_GOLD, TEXT_SPECIAL_HP_B);
	PutSpecialChar(gBg0Tm + TM_OFFSET(5, 1), TEXT_COLOR_SYSTEM_GOLD, TEXT_SPECIAL_LV_A);
	PutSpecialChar(gBg0Tm + TM_OFFSET(6, 1), TEXT_COLOR_SYSTEM_GOLD, TEXT_SPECIAL_LV_B);
	PutSpecialChar(gBg0Tm + TM_OFFSET(9, 1), TEXT_COLOR_SYSTEM_GOLD, TEXT_SPECIAL_EXP_E);

	for (iy = 0; iy < 8; iy++)
		for (ix = 0; ix < 13; ix++)
			(gBg1Tm + TM_OFFSET(0, iy))[ix] = tiles[13 * (7 - iy) + ix] + TILEREF(0, 1);

	PutFaceChibi(GetUnitFid(gPrepUnitList[proc->list_num_cur]), gBg0Tm + TM_OFFSET(1, 1),
		BGCHR_PREPMENU_230, BGPAL_PREPMENU_2, FALSE);

	UpdatePrepUnitPinfoAsync(proc);

	EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT);
}

void func_fe6_080798EC(struct PrepMenuProc *proc)
{
	PutFaceChibi(GetUnitFid(gPrepUnitList[proc->list_num_cur]), gBg0Tm + TM_OFFSET(1, 1),
		BGCHR_PREPMENU_230, BGPAL_PREPMENU_2, FALSE);

	UpdatePrepUnitPinfoAsync(proc);
}

void func_fe6_08079928(struct PrepMenuProc *proc, int unit_id_or_pid, bool by_pid)
{
	fu8 i;

	for (i = 0; i < proc->unk_2D; i++) {
		if ((by_pid && UNIT_PID(gPrepUnitList[i]) == unit_id_or_pid) || (!by_pid && gPrepUnitList[i]->id == unit_id_or_pid)) {
			proc->list_num_cur = i;

			if (i / 2 == 0) {
				proc->hand_y_pos = 0;
				proc->yDiff_cur = 0;
			} else if (i / 2 == (proc->unk_2D - 1) / 2) {
				if (proc->unk_2D < 15) {
					proc->hand_y_pos = i / 2;
					proc->yDiff_cur = 0;
				} else {
					proc->hand_y_pos = 6;
					proc->yDiff_cur = ((proc->unk_2D - 0xd) / 2) * 16;
				}
			} else if (i / 2 > proc->yDiff_cur / 16 && i / 2 < proc->yDiff_cur / 16 + 6)
				proc->hand_y_pos = i / 2 - proc->yDiff_cur / 16;
			else if (proc->yDiff_cur / 16 > i / 2 - 1) {
				proc->hand_y_pos = 1;
				proc->yDiff_cur = (i / 2 - 1) * 16;
			} else if (proc->yDiff_cur / 16 < i / 2 - 5) {
				proc->hand_y_pos = 5;
				proc->yDiff_cur = (i / 2 - 5) * 16;
			}

			break;
		}
	}

	SetBgOffset(2, 0, proc->yDiff_cur - 0x28);
}

void ReorderPlayerUnitsBasedOnDeployment(void)
{
	UnitRearrangeInit((struct Unit *)gPrepUnitPool);

	FOR_UNITS(FACTION_BLUE + 1, FACTION_BLUE + 0x40, unit, {
		if ((unit->flags & (UNIT_FLAG_DEAD | UNIT_FLAG_NOT_DEPLOYED)) == 0)
			UnitRearrangeAdd(unit);
	})

	FOR_UNITS(FACTION_BLUE + 1, FACTION_BLUE + 0x40, unit, {
		if ((unit->flags & (UNIT_FLAG_DEAD | UNIT_FLAG_NOT_DEPLOYED)) != 0)
			UnitRearrangeAdd(unit);
	})

	UnitRearrangeApply();
}

void func_fe6_08079A94(struct PrepMenuProc *proc)
{
	fu8 r7 = GetPrepMenuItemAmount(proc->submenu_level);

	if (proc->submenu_level == 0) {
		if (proc->cur_counter == 0)
			SetPrepMenuItemUsability(PREPMENUITEM_STARTBATTLE, TEXT_COLOR_SYSTEM_GRAY);
		else
			SetPrepMenuItemUsability(PREPMENUITEM_STARTBATTLE, TEXT_COLOR_SYSTEM_WHITE);

		TmFillRect(gBg0Tm, 12, 19, 0);
		TmFillRect(gBg1Tm, 12, 19, 0);

		PutUiWindowFrame(0, 4, 12, 2 + r7 * 2, UI_WINDOW_REGULAR);
		PutPrepScreenMenuItems(gPrepItemTexts, 0, gBg0Tm + TM_OFFSET(2, 5), r7);
		PutUiEntryHover(1, 5 + proc->disp_idx[proc->submenu_level] * 2, 10);
	} else {
		if (GetUnitItemCount(gPrepUnitList[proc->list_num_cur]) > 0)
			SetPrepMenuItemUsability(PREPMENUITEM_DISCARD, TEXT_COLOR_SYSTEM_WHITE);
		else
			SetPrepMenuItemUsability(PREPMENUITEM_DISCARD, TEXT_COLOR_SYSTEM_GRAY);

		TmFillRect(gBg0Tm + TM_OFFSET(0, 8), 12, 11, 0);
		TmFillRect(gBg1Tm + TM_OFFSET(0, 8), 12, 11, 0);

		PutUiWindowFrame(0, 8, 13, 2 + r7 * 2, UI_WINDOW_REGULAR);
		PutPrepScreenMenuItems(gPrepItemTexts, proc->submenu_level, gBg0Tm + TM_OFFSET(2, 9), r7);
		PutUiEntryHover(1, 9 + proc->disp_idx[proc->submenu_level] * 2, 10);
	}

	EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT);
}

void func_fe6_08079BC8(struct UnkProc_08678E18 *proc)
{
	proc->main_proc = proc->proc_parent;
	proc->unit = gPrepUnitList[proc->main_proc->list_num_cur];

	TmFillRect(gBg0Tm + TM_OFFSET(0, 8), 12, 11, 0);
	PutUiWindowFrame(0, 8, 13, 12, UI_WINDOW_REGULAR);
	EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT);

	proc->unk_34 = 0;
	proc->unk_35 = GetUnitItemCount(proc->unit);

	ClearIcons();

	if (proc->unk_35 == 0) {
		proc->main_proc->unk_5C = NULL;
		Proc_End(proc);
	}
}

void func_fe6_08079C38(struct UnkProc_08678E18 *proc)
{
	int i;

	for (i = 0; i < 5; i++)
	{
		ClearText(&gPrepItemTexts[proc->unk_34]);

		PutIcon(gBg0Tm + TM_OFFSET(1, 9 + proc->unk_34 * 2),
			GetItemIcon(proc->unit->items[proc->unk_34]), TILEREF(0, BGPAL_ICONS));

		Text_SetColor(&gPrepItemTexts[proc->unk_34],
			IsItemDisplayUsable(proc->unit, proc->unit->items[proc->unk_34])
				? TEXT_COLOR_SYSTEM_WHITE : TEXT_COLOR_SYSTEM_GRAY);
		Text_SetCursor(&gPrepItemTexts[proc->unk_34], 0);
		Text_DrawString(&gPrepItemTexts[proc->unk_34], GetItemName(proc->unit->items[proc->unk_34]));
		PutText(&gPrepItemTexts[proc->unk_34], gBg0Tm + TM_OFFSET(3, 9 + proc->unk_34 * 2));

		PutNumberOrBlank(gBg0Tm + TM_OFFSET(11, 9 + proc->unk_34 * 2),
			IsItemDisplayUsable(proc->unit, proc->unit->items[proc->unk_34])
				? TEXT_COLOR_SYSTEM_BLUE : TEXT_COLOR_SYSTEM_GRAY,
			GetItemUses(proc->unit->items[proc->unk_34]));

		proc->unk_34++;

		if (proc->unk_34 >= proc->unk_35)
		{
			proc->main_proc->unk_5C = NULL;
			Proc_Break(proc);
			break;
		}
	}
}

struct ProcScr CONST_DATA ProcScr_Unk_08678E18[] =
{
	PROC_YIELD,
	PROC_CALL(func_fe6_08079BC8),
	PROC_REPEAT(func_fe6_08079C38),
	PROC_END,
};

struct UnkProc_08678E18 * func_fe6_08079D70(struct PrepMenuProc * parent)
{
	return SpawnProc(ProcScr_Unk_08678E18, parent);
}

void func_fe6_08079D84(struct PrepMenuProc *proc)
{
	struct Unit * unit = gPrepUnitList[proc->list_num_cur];
	int i, count;

	TmFillRect(gBg0Tm + TM_OFFSET(0, 8), 12, 11, 0);
	PutUiWindowFrame(0, 8, 13, 12, UI_WINDOW_REGULAR);

	count = GetUnitItemCount(gPrepUnitList[proc->list_num_cur]);

	ClearIcons();

	for (i = 0; i < count; i++)
	{
		ClearText(&gPrepItemTexts[i]);

		PutIcon(gBg0Tm + TM_OFFSET(1, 9 + i * 2),
			GetItemIcon(unit->items[i]), TILEREF(0, BGPAL_ICONS));

		Text_SetColor(&gPrepItemTexts[i],
			IsItemDisplayUsable(unit, unit->items[i])
				? TEXT_COLOR_SYSTEM_WHITE : TEXT_COLOR_SYSTEM_GRAY);
		Text_SetCursor(&gPrepItemTexts[i], 0);
		Text_DrawString(&gPrepItemTexts[i], GetItemName(unit->items[i]));
		PutText(&gPrepItemTexts[i], gBg0Tm + TM_OFFSET(3, 9 + i * 2));

		PutNumberOrBlank(gBg0Tm + TM_OFFSET(11, 9 + i * 2),
			IsItemDisplayUsable(unit, unit->items[i])
				? TEXT_COLOR_SYSTEM_BLUE : TEXT_COLOR_SYSTEM_GRAY,
			GetItemUses(unit->items[i]));
	}

	EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT);
}

void PrepUnit_DrawPickLeftBar(struct PrepMenuProc *proc)
{
	ClearText(&gPrepScreenText_PickLeftBar);

	Text_SetCursor(&gPrepScreenText_PickLeftBar, 0);
	Text_SetColor(&gPrepScreenText_PickLeftBar, TEXT_COLOR_SYSTEM_WHITE);
	Text_DrawString(&gPrepScreenText_PickLeftBar, JTEXT("残り"));

	Text_SetCursor(&gPrepScreenText_PickLeftBar, 0x18);
	Text_SetColor(&gPrepScreenText_PickLeftBar, TEXT_COLOR_SYSTEM_BLUE);
	Text_DrawNumberOrBlank(&gPrepScreenText_PickLeftBar, proc->max_counter - proc->cur_counter);

	Text_SetColor(&gPrepScreenText_PickLeftBar, TEXT_COLOR_SYSTEM_WHITE);

	Text_SetCursor(&gPrepScreenText_PickLeftBar, 0x20);
	Text_DrawString(&gPrepScreenText_PickLeftBar, JTEXT("人"));

	Text_SetCursor(&gPrepScreenText_PickLeftBar, 0x28);
	Text_DrawString(&gPrepScreenText_PickLeftBar, JTEXT("／"));

	Text_SetCursor(&gPrepScreenText_PickLeftBar, 0x38);
	Text_SetColor(&gPrepScreenText_PickLeftBar, TEXT_COLOR_SYSTEM_BLUE);
	Text_DrawNumberOrBlank(&gPrepScreenText_PickLeftBar, proc->max_counter);

	PutText(&gPrepScreenText_PickLeftBar, gBg0Tm + TM_OFFSET(21, 1));

	EnableBgSync(BG0_SYNC_BIT);
}

void PrepUnit_DrawUnitListNames(struct PrepMenuProc *proc, fu8 row)
{
	fu8 i;

	fu8 first_ent = row * 2;
	int text_base = first_ent % 0x10;

	TmFillRect(gBg2Tm + TM_OFFSET(0, first_ent % 0x20), 15, 1, 0);

	for (i = 0; i < 2 && first_ent + i < proc->unk_2D; i++)
	{
		ClearText(&gPrepScreenTexts_Units[text_base + i]);
		Text_SetCursor(&gPrepScreenTexts_Units[text_base + i], 0);

		if ((proc->link_arena_flag & PREPMENU_FLAG_MULTIARENA) == 0 && IsUnitMandatoryDeploy(gPrepUnitList[first_ent + i]))
		{
			// force deployed color
			Text_SetColor(&gPrepScreenTexts_Units[text_base + i], TEXT_COLOR_SYSTEM_GREEN);
		}
		else if ((gPrepUnitList[first_ent + i]->flags & UNIT_FLAG_NOT_DEPLOYED) != 0)
		{
			// not selected color
			Text_SetColor(&gPrepScreenTexts_Units[text_base + i], TEXT_COLOR_SYSTEM_GRAY);
		}
		else
		{
			// selected color
			Text_SetColor(&gPrepScreenTexts_Units[text_base + i], TEXT_COLOR_SYSTEM_WHITE);
		}

		Text_DrawString(&gPrepScreenTexts_Units[text_base + i], DecodeMsg(gPrepUnitList[first_ent + i]->pinfo->msg_name));

		PutText(&gPrepScreenTexts_Units[text_base + i], gBg2Tm + TM_OFFSET(i * 8, first_ent % 0x20));
	}

	EnableBgSync(BG2_SYNC_BIT);
}

void RearrangeMandatoryDeployUnits(void)
{
	struct Unit * order[0x40];
	int i, j;

	fu8 deploy_max = GetPlayerMaxDeployCount();
	fu8 deploy_count = 0;
	fu8 order_count = 0;

	FOR_UNITS_FACTION(FACTION_BLUE, unit,
	{
		order[order_count] = unit;
		order_count++;
	})

	for (i = 0; i < order_count; i++)
	{
		if ((order[i]->flags & UNIT_FLAG_DEAD) == 0 && IsUnitMandatoryDeploy(order[i]))
		{
			for (j = i - 1; i > 0; i--, j--)
			{
				if (!IsUnitMandatoryDeploy(order[i - 1]))
				{
					struct Unit * tmp = order[i];
					order[i] = order[i - 1];
					order[i - 1] = tmp;
				}
				else
				{
					break;
				}
			}
		}
	}

	UnitRearrangeInit((struct Unit *)gPrepUnitPool);

	for (i = 0; i < order_count; i++)
		UnitRearrangeAdd(order[i]);

	UnitRearrangeApply();

	FOR_UNITS_FACTION(FACTION_BLUE, unit,
	{
		if ((unit->flags & UNIT_FLAG_DEAD) != 0)
			continue;

		if (deploy_max > deploy_count)
		{
			unit->flags &= ~UNIT_FLAG_NOT_DEPLOYED;
			deploy_count++;
		}
		else
		{
			unit->flags |= UNIT_FLAG_NOT_DEPLOYED;
		}
	})
}

void SioResetUnitItems(void)
{
	FOR_UNITS_FACTION(FACTION_BLUE, unit,
	{
		if ((unit->flags & UNIT_FLAG_DEAD) == 0)
			unit->flags |= UNIT_FLAG_NOT_DEPLOYED;
	})
}

void func_fe6_0807A1C8(struct PrepMenuProc *proc, bool load_sprites)
{
	proc->cur_counter = 0;
	proc->unk_2D = 0;
	gPrepUnitCount = 0;

	FOR_UNITS_FACTION(FACTION_BLUE, unit,
	{
		if ((unit->flags & UNIT_FLAG_DEAD) != 0)
			continue;

		gPrepUnitList[proc->unk_2D] = unit;

		if ((unit->flags & UNIT_FLAG_NOT_DEPLOYED) == 0)
		{
			unit->flags &= ~UNIT_FLAG_TURN_ENDED;
			proc->cur_counter++;
		}
		else
		{
			unit->flags |= UNIT_FLAG_NOT_DEPLOYED | UNIT_FLAG_TURN_ENDED;
		}

		gPrepUnitCount++;
		proc->unk_2D++;

		if (load_sprites)
			UseUnitSprite(GetUnitMapSprite(unit));
	})
}

void PrepMenu_InitScreenExt(struct PrepMenuProc *proc)
{
	int i;

	ResetTextFont();
	ClearIcons();
	ApplyUnitSpritePalettes();
	ResetText();
	InitIcons();
	ApplyIconPalettes(BGPAL_ICONS);
	UnpackUiWindowFrameGraphics();
	LoadHelpBoxGfx(NULL, BGPAL_PREPMENU_E);
	SetDispEnable(0, 0, 0, 0, 0);
	ApplySystemObjectsGraphics();
	ResetUnitSprites();
	StartGreenText(proc);
	SetupPrepUiPalette();

	if ((proc->link_arena_flag & PREPMENU_FLAG_MULTIARENA) != 0)
		proc->max_counter = 5;
	else
		proc->max_counter = GetPlayerMaxDeployCount();

	proc->unk_5C = NULL;

	func_fe6_0807A1C8(proc, TRUE);

	if (proc->max_counter > proc->unk_2D)
		proc->max_counter = proc->unk_2D;

	if (proc->sub2_action == 6)
		func_fe6_08079928(proc, GetLastStatScreenUnitId(), FALSE);
	else if (proc->sub2_action == 9)
		func_fe6_08079928(proc, gPrepCursorUnitPid, TRUE);

	TmFill(gBg0Tm, 0);
	TmFill(gBg1Tm, 0);
	TmFill(gBg2Tm, 0);

	for (i = 0; i < 5; i++)
		InitTextDb(&gPrepItemTexts[i], 7);

	InitText(&gUnk_0200E88C[0], 7);
	InitText(&gUnk_0200E88C[1], 7);

	for (i = 0; i < 16; i++)
		InitText(&gPrepScreenTexts_Units[i], 5);

	InitTextDb(&gPrepScreenText_PickLeftBar, 9);
	InitText(&gPrepScreenText_LeftPersonName, 7);

	Decompress(Img_Prep_0831A268, OBJ_VRAM0 + CHR_SIZE * OBCHR_PREPMENU_240);
	ApplyObPalettes(Pal_Sio_0831AABC, OBPAL_PREPMENU_2, 2);
	Decompress(Img_Prep_08326930, OBJ_VRAM0 + CHR_SIZE * OBCHR_PREPMENU_380);
	ApplyObPalettes(Pal_Prep_08326E64, OBPAL_PREPMENU_6, 4);
	ApplyObPalette(Pal_Prep_08327108, OBPAL_PREPMENU_4);

	for (i = 0; i < 10; i++) {
		gPal[OBPAL_OFFSET(OBPAL_PREPMENU_6) + 5 + i] =
			gPal[OBPAL_OFFSET(OBPAL_PREPMENU_6 + 3) + ((proc->scroll_timer / 4 + i) & 0x0F)];
	}

	EnablePalSync();

	gDispIo.bg0_ct.priority = 1;
	gDispIo.bg1_ct.priority = 2;
	gDispIo.bg2_ct.priority = 1;
	gDispIo.bg3_ct.priority = 3;

	SetWinEnable(0, 0, 0);
	SetWin0Box(0, 0, DISPLAY_WIDTH, DISPLAY_HEIGHT);
	SetWin0Layers(1, 1, 1, 1, 1);
	SetWin1Layers(1, 1, 1, 1, 1);
	SetWOutLayers(1, 1, 0, 1, 1);

	SetBgOffset(0, 0, 0);
	SetBgOffset(1, 0, 0);
	SetBgOffset(2, 0, proc->yDiff_cur - 0x28);

	Decompress(Img_VeriticalSpinningArrow, (void *) VRAM + CHR_SIZE * BGCHR_PREPMENU_240);
	ApplyBgPalette(Pal_SpinningArrow, BGPAL_PREPMENU_F);

	ResetPrepMenuItem();

	InitPrepScreenMainMenu(proc);

	if (proc->not_in_upper_menu == 1)
		func_fe6_08079804(proc);

	if (proc->sel_unit == 0)
		func_fe6_08079A94(proc);
	else if (proc->sel_unit == 1)
		func_fe6_08079D84(proc);

	PrepScreen_DrawScreenInfo(proc);
	EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT | BG2_SYNC_BIT | BG3_SYNC_BIT);
	func_fe6_08082D08(proc->unk_60, 0x6000, OBPAL_PREPMENU_D);
}

void PrepMenu_InitScreen(struct PrepMenuProc *proc)
{
	int i, j;

	InitBgs(NULL);

	PrepMenu_InitScreenExt(proc);

	if ((proc->link_arena_flag & PREPMENU_FLAG_MULTIARENA) != 0)
		proc->procbg = StartMuralBackground(NULL, NULL, BGPAL_PREPMENU_A);
	else {
		Decompress(Img_MonologueBG, (void *) VRAM + GetBgChrOffset(3));
		ApplyBgPalettes(Pal_MonologueBG, BGPAL_PREPMENU_A, 4);
		proc->procbg = func_fe6_08082560(proc);
	}

	Decompress(Img_PrepWorldMap, ImgBuf_PrepWorldMap);
	ApplyPalette(Pal_PrepWorldMap, BGPAL_PREPMENU_E);

	for (i = 0; i < 12; i++) {
		CpuFastCopy(
			ImgBuf_PrepWorldMap + (((GetChapterInfo(gPlaySt.chapter)->gmap_dispy + i) * 0x20)
				+ GetChapterInfo(gPlaySt.chapter)->gmap_dispx) * 0x20,
			(void *) VRAM + CHR_SIZE * BGCHR_PREPMENU_700 + 15 * CHR_SIZE * i, 15 * CHR_SIZE);
	}

	for (j = 0; j < CHR_SIZE; j++) {
		// BUG: 8bit VRAM writes!
		((u8 *) VRAM)[(BGCHR_PREPMENU_700 + 0xC0) * CHR_SIZE + j] = 0;
	}
}

void PrepScreen_DrawScreenInfo(struct PrepMenuProc *proc)
{
	int i, j;

	if (proc->not_in_upper_menu == 0) {
		u16 const * tiles = Tsa_Prep_08326EE6;

		SetBgChrOffset(2, 0x8000);
		SetBgOffset(2, 0, 0);
		TmFill(GetBgTilemap(2), TILE_CHR_SAFE(BGCHR_PREPMENU_700 + 0xC0) + TILE_PAL_SAFE(BGPAL_PREPMENU_E));

		for (i = 0; i < 12; i++)
			for (j = 0; j < 15; j++)
				gBg2Tm[TM_OFFSET(14 + j, 5 + i)] =
					i * 15 + j + TILE_CHR_SAFE(BGCHR_PREPMENU_700) + TILE_PAL_SAFE(BGPAL_PREPMENU_E);

		for (i = 0; i < 16; i++)
			for (j = 0; j < 17; j++)
				gBg1Tm[TM_OFFSET(13 + j, 4 + i)] = tiles[(15 - i) * 17 + j] + TILE_PAL_SAFE(1);

		gBg0Tm[TM_OFFSET(20, 4)] = 0;
		gBg0Tm[TM_OFFSET(21, 4)] = 0;
		gBg0Tm[TM_OFFSET(20, 19)] = 0;
		gBg0Tm[TM_OFFSET(21, 19)] = 0;

		ClearText(&gPrepScreenText_PickLeftBar);

		Text_SetCursor(&gPrepScreenText_PickLeftBar, (0x48 - GetStringTextLen(DecodeMsg(GetChapterInfo(gPlaySt.chapter)->msg_wm_location))) >> 1);
		Text_SetColor(&gPrepScreenText_PickLeftBar, TEXT_COLOR_SYSTEM_WHITE);
		Text_DrawString(&gPrepScreenText_PickLeftBar, DecodeMsg(GetChapterInfo(gPlaySt.chapter)->msg_wm_location));

		PutText(&gPrepScreenText_PickLeftBar, gBg0Tm + TM_OFFSET(17, 17));
	} else {
		SetBgChrOffset(2, 0x0000);
		TmFill(gBg2Tm, 0);

		for (i = proc->yDiff_cur / 16; i < proc->yDiff_cur / 16 + 7; i++)
			PrepUnit_DrawUnitListNames(proc, i);

		PutUiWindowFrame(13, 4, 17, 16, UI_WINDOW_REGULAR);

		SetBgOffset(2, -0x80, (proc->yDiff_cur - 0x28) & 0xFF);

		if (proc->disp_idx[0] == 0)
			PrepUnit_DrawPickLeftBar(proc);
	}

	EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT | BG2_SYNC_BIT);
}

void PrepMenu_InitExt(struct PrepMenuProc *proc)
{
	int i;

	gPrepCursorUnitPid = 0;

	proc->unit1 = 0;
	proc->unit2 = 0;
	proc->yDiff_cur = 0;
	proc->list_num_cur = 0;
	proc->unk_31 = 0xFF;
	proc->sel_unit = 0;
	proc->not_in_upper_menu = 0;
	proc->unk_2B = 0;
	proc->hand_y_pos = 0;

	if (CheckInLinkArena() == 1)
		proc->link_arena_flag = PREPMENU_FLAG_MULTIARENA;
	else {
		proc->link_arena_flag = 0;
		StartBgm(SONG_22, NULL);
	}

	proc->unk_38 = 0;
	proc->unk_39 = 0;
	proc->unk_3A = 0;
	proc->sub2_action = 0;
	proc->do_help = 0;
	proc->a_button_actions = 0;
	proc->end_prep = 0;

	// BUG: this should be 2, not 3
	for (i = 0; i < 3; i++)
		proc->disp_idx[i] = 0;

	proc->submenu_level = 0;

	proc->unk_60 = func_fe6_08082CF4(proc);

	PrepMenu_InitScreen(proc);

	PrepDisp_SetWorlMapInfo((proc->disp_proc = StartPrepUpperDisp(proc)),
		GetChapterInfo(gPlaySt.chapter)->gmap_cursorx * 8,
		GetChapterInfo(gPlaySt.chapter)->gmap_cursory * 8,
		GetChapterInfo(gPlaySt.chapter)->index_gaiden);
}

fi8 PrepUnitSel_Loop(struct PrepMenuProc *proc)
{
	int old_list_num_cur = proc->list_num_cur;

	if ((gKeySt->held & KEY_BUTTON_L) != 0)
		proc->unk_3F = 2;
	else
		proc->unk_3F = 1;

	if ((gKeySt->pressed & KEY_BUTTON_START) != 0 && (proc->link_arena_flag & PREPMENU_FLAG_MULTIARENA) == 0) {
		if ((proc->a_button_actions & 1) != 0 && proc->cur_counter != 0) {
			Proc_Goto(proc, L_PREPMENU_5);
			proc->disp_proc->unk_2A = 1;
			PlaySe(SONG_6A);
		} else {
			PlaySe(SONG_6C);
		}
	} else {
		if (((gKeySt->repeated & KEY_DPAD_DOWN) != 0) || ((gKeySt->pressed2 & KEY_DPAD_DOWN) != 0 && proc->unk_3F == 2)) {
			if ((proc->a_button_actions & 2) != 0 && (proc->a_button_actions & 1) != 0) {
				proc->a_button_actions &= 1;
				PlaySe(SONG_66);
			} else if (proc->list_num_cur + 2 < proc->unk_2D) {
				proc->list_num_cur = proc->list_num_cur + 2;
				proc->hand_y_pos++;
				proc->a_button_actions &= 1;
			}
		} else if (((gKeySt->repeated & KEY_DPAD_UP) != 0) || ((gKeySt->pressed2 & KEY_DPAD_UP) != 0 && proc->unk_3F == 2)) {
			if ((proc->a_button_actions & 1) != 0 && proc->hand_y_pos == 0 && proc->yDiff_cur == 0) {
				if ((gKeySt->pressed & KEY_DPAD_UP) != 0 && proc->cur_counter != 0 && (proc->link_arena_flag & PREPMENU_FLAG_MULTIARENA) == 0) {
					proc->a_button_actions |= 2;
					PlaySe(SONG_66);
				}
			} else if (proc->list_num_cur - 2 >= 0) {
				proc->list_num_cur = proc->list_num_cur - 2;
				proc->hand_y_pos--;
			}
		} else if ((gKeySt->repeated & KEY_DPAD_LEFT) != 0) {
			if ((proc->list_num_cur % 2) != 0 && (proc->a_button_actions & (1 | 2)) != (1 | 2))
				proc->list_num_cur--;
		} else if ((gKeySt->repeated & KEY_DPAD_RIGHT) != 0) {
			if ((proc->a_button_actions & (1 | 2)) != (1 | 2) && (proc->list_num_cur % 2) == 0 && (proc->list_num_cur + 1) < proc->unk_2D)
				proc->list_num_cur++;
		}
	}

	if (proc->list_num_cur != old_list_num_cur) {
		func_fe6_080798EC(proc);

		if (proc->unk_5C != NULL)
			Proc_End(proc->unk_5C);

		proc->unk_5C = func_fe6_08079D70(proc);

		PlaySe(SONG_66);
	}

	if (proc->hand_y_pos == 6 && ((proc->list_num_cur + 2) / 2) <= (proc->unk_2D - 1) / 2) {
		proc->hand_y_pos = 5;
		return +1;
	}

	if (proc->hand_y_pos == 0 && proc->list_num_cur / 2 != 0) {
		proc->hand_y_pos = 1;
		return -1;
	}

	return 0;
}

void PrepSubMenu_FinishMoving(struct PrepMenuProc *proc)
{
	int i, r4 = proc->yDiff_cur / 16;

	proc->list_num_cur = proc->unk_31;
	proc->unk_31 = 0xFF;

	if (proc->yDiff_cur == proc->unk_40 || (proc->list_num_cur / 2 > r4 && proc->list_num_cur / 2 < r4 + 6))
	{
		proc->hand_y_pos = proc->list_num_cur / 2 - r4;
		return;
	}

	proc->yDiff_cur = proc->unk_40;
	proc->hand_y_pos = proc->unk_37;

	TmFill(gBg2Tm, 0);
	SetBgOffset(2, -0x80, (proc->yDiff_cur - 0x28) & 0xFF);

	for (i = proc->yDiff_cur / 16; i < proc->yDiff_cur / 16 + 7; i++)
	{
		PrepUnit_DrawUnitListNames(proc, i);
	}

	EnableBgSync(BG2_SYNC_BIT);
}

void PrepMenu_CancelAction(struct PrepMenuProc *proc)
{
	if (proc->submenu_level == 0) {
		Proc_Goto(proc, L_PREPMENU_6);
	} else if (proc->submenu_level == 1) {
		PrepSubMenu_FinishMoving(proc);
		proc->sel_unit = 1;
		func_fe6_08079D84(proc);
		proc->submenu_level = 0;
	}

	PlaySe(SONG_6B);
}

void PrepItem_BlockUpperfxDisp(struct PrepMenuProc *proc)
{
	Proc_Goto(proc->disp_proc, 2);
	EndGreenText();
}

void PrepMenu_EndIfNoUnit(struct PrepMenuProc *proc)
{
	fu8 dead_count = 0;

	SetDispEnable(0, 0, 0, 0, 0);

	FOR_UNITS_FACTION(FACTION_BLUE, unit,
	{
		if ((unit->flags & UNIT_FLAG_DEAD) == 0)
			dead_count++;
	})

	if (dead_count == 0)
	{
		proc->procbg = NULL;
		proc->end_prep = 1;

		Proc_Goto(proc, L_PREPMENU_B);

		proc->disp_proc = NULL;
	}
}

void PrepMenu_Init(struct PrepMenuProc *proc)
{
	PrepMenu_InitExt(proc);
}

void PrepMenu_Loop(struct PrepMenuProc *proc)
{
	u8 pre_item = proc->disp_idx[proc->submenu_level];
	u8 pre_idx = proc->submenu_level;

	switch (proc->sel_unit) {
	case 0:
		if (proc->do_help && (gKeySt->pressed & (KEY_BUTTON_B | KEY_BUTTON_R))) {
			CloseHelpBox();
			proc->do_help = FALSE;
			return;
		}

		if (gKeySt->pressed & KEY_BUTTON_A) {
			if (proc->do_help == FALSE) {
				if (PrepMenuOnSelected(proc) == FALSE) {
					PlaySe(0x6C);
				}
			}
		} else if (gKeySt->pressed & KEY_BUTTON_R) {
			if (proc->do_help == FALSE)
				PrepMenuHelpbox(proc);
		} else {
			if (gKeySt->repeated & KEY_DPAD_UP) {
				if (proc->disp_idx[proc->submenu_level] != 0)
					proc->disp_idx[proc->submenu_level]--;
				else if (gKeySt->pressed & KEY_DPAD_UP)
					proc->disp_idx[proc->submenu_level] = GetPrepMenuItemAmount(proc->submenu_level) - 1;
			} else if (gKeySt->repeated & KEY_DPAD_DOWN) {
				if (proc->disp_idx[proc->submenu_level] < GetPrepMenuItemAmount(proc->submenu_level) - 1)
					proc->disp_idx[proc->submenu_level]++;
				else if (gKeySt->pressed & KEY_DPAD_DOWN)
					proc->disp_idx[proc->submenu_level] = 0;
			} else if (gKeySt->pressed & KEY_BUTTON_B)
				PrepMenu_CancelAction(proc);
		}

		if (pre_idx == proc->submenu_level) {
			if (pre_item != proc->disp_idx[proc->submenu_level]) {
				if (proc->do_help != FALSE)
					PrepMenuHelpbox(proc);
				if (proc->submenu_level == 1)
					func_fe6_0807B8B0(proc->disp_proc, GetPrepScreenMenuDispItemIndex(proc->disp_idx[1], 1) - 5);
	
				PlaySe(0x66);
			}
		}
		break;

	case 1:
		if (gKeySt->pressed & KEY_BUTTON_A) {
			if (PrepMenuOnSelected(proc) == FALSE) {
				PlaySe(0x6C);
			}
		} else if (gKeySt->pressed & KEY_BUTTON_B) {
			i16 _pre_idx = pre_idx;

			if (_pre_idx == 0) {
				TmFillRect(gBg0Tm + TM_OFFSET(0x14, 0), 10, 3, 0);
				EnableBgSync(BG0_SYNC_BIT);

				proc->a_button_actions &= 2;
				if (proc->unk_31 != 0xFF)
					proc->unk_31 = 0xFF;
				else
					Proc_Goto(proc, 0xA);
			} else if (_pre_idx == 1) {
				proc->sel_unit = 0;
				func_fe6_0807B8B0(proc->disp_proc, GetPrepScreenMenuDispItemIndex(proc->disp_idx[1], 1) - 5);
				func_fe6_08079A94(proc);
				proc->unk_32 = proc->list_num_cur;
				proc->list_num_cur = proc->unk_31;
				func_fe6_080798EC(proc);
			}
			PlaySe(0x6B);
		} else {
			int _ret = PrepUnitSel_Loop(proc);
			i8 __ret = _ret;

			if (_ret != 0) {
				if (__ret == -1)
					Proc_Goto(proc, 7);

				if (__ret == 1)
					Proc_Goto(proc, 8);
			} else {
				if (gKeySt->pressed & KEY_BUTTON_R && (proc->a_button_actions & 3) != 3) {
					proc->sub2_action = 6;
					Proc_Goto(proc, 0x3);
				} else if (gKeySt->pressed & KEY_BUTTON_SELECT && proc->submenu_level != 1) {
					gPrepCursorUnitPid = UNIT_PID(gPrepUnitList[proc->list_num_cur]);

					PlaySe(0x6A);
					proc->sub2_action = 9;
					Proc_Goto(proc, 0xD);
				}
			}
		}
		break;
	}
}

void AtMenu_SetEndFlag(struct PrepMenuProc *proc)
{
	proc->end_prep = 1;
}

void AtMenu_ResetBmUiEffect(struct PrepMenuProc *proc)
{
	if (proc->end_prep != 0) {
		ReorderPlayerUnitsBasedOnDeployment();
		func_fe6_0802B7E4();
	} else if (proc->link_arena_flag & 1)
		func_fe6_08036994();

	EndGreenText();
	Proc_End(proc->procbg);

	if (proc->disp_proc)
		Proc_Goto(proc->disp_proc, 0x5);

	InitPlayerDeployUnitPositions();
	ResetUnitSprites();
	RefreshEntityMaps();
	RefreshUnitSprites();
	SetBlendDarken(0x10);
	SetBlendTargetA(0, 0, 0, 0, 0);
	SetBlendTargetA(1, 1, 1, 1, 1);
	SetBlendBackdropA(1);
}

void PrepUnit_HandleScrollUp(struct PrepMenuProc *proc)
{
	if ((proc->yDiff_cur % 0x10) == 0)
		PrepUnit_DrawUnitListNames(proc, proc->yDiff_cur / 0x10 - 1);

	proc->yDiff_cur -= proc->unk_3F * 4;

	if ((proc->yDiff_cur % 0x10) == 0) {
		i8 _ret = PrepUnitSel_Loop(proc);
		if (_ret == 0)
			Proc_Goto(proc, 0x1);

		if (_ret == 1)
			Proc_Goto(proc, 0x8);

		TmFillRect(gBg2Tm + TM_OFFSET(0, (proc->yDiff_cur / 8 + 14) & 0x1F), 12, 1, 0);
		EnableBgSync(BG2_SYNC_BIT);
	}
}

void PrepUnit_HandleScrollDown(struct PrepMenuProc *proc)
{
	if ((proc->yDiff_cur % 0x10) == 0)
		PrepUnit_DrawUnitListNames(proc, proc->yDiff_cur / 0x10 + 7);

	proc->yDiff_cur += proc->unk_3F * 4;

	if ((proc->yDiff_cur % 0x10) == 0) {
		i8 _ret = PrepUnitSel_Loop(proc);

		if (_ret == 0)
			Proc_Goto(proc, 0x1);

		if (_ret == -1)
			Proc_Goto(proc, 0x7);

		TmFillRect(gBg2Tm + TM_OFFSET(0, (proc->yDiff_cur / 8 - 2) & 0x1F), 12, 1, 0);
		EnableBgSync(BG2_SYNC_BIT);
	}
}

void AtMenu_StartSubmenu(struct PrepMenuProc *proc)
{
	switch (proc->sub2_action) {
	case PREP_SUB2ACT_TRADE_ITEM:
		StartPrepSubItemScreen(proc, PL_PREP_SUBITEM_TRADE);
		PrepItem_BlockUpperfxDisp(proc);
		break;

	case PREP_SUB2ACT_DISCARD_ITEM:
		StartPrepDiscardItemScreen(proc);
		PrepItem_BlockUpperfxDisp(proc);
		break;

	case PREP_SUB2ACT_CONVOY:
		StartPrepSubItemScreen(proc, PL_PREP_SUBITEM_CONVOY);
		PrepItem_BlockUpperfxDisp(proc);
		break;

	case PREP_SUB2ACT_CHECK_ALL_ITEM:
		StartPrepSubItemScreen(proc, PL_PREP_SUBITEM_VIEWALL);
		PrepItem_BlockUpperfxDisp(proc);
		break;

	case PREP_SUB2ACT_8:
		Proc_End(proc->procbg);
		SpawnProcLocking(ProcScr_Augury, proc);
		PrepItem_BlockUpperfxDisp(proc);
		SetDispEnable(0, 0, 0, 0, 0);
		break;

	case PREP_SUB2ACT_SAVEMENU:
		Proc_End(proc->procbg);
		StartBgmVolumeChange(0x100, 0x80, 0x20, NULL);
		InitPlayerDeployUnitPositions();
		StartSaveMenu(proc);
		PrepItem_BlockUpperfxDisp(proc);
		SetDispEnable(0, 0, 0, 0, 0);
		break;

	case PREP_SUB2ACT_9:
		Proc_End(proc->procbg);
		func_fe6_08076250(proc);
		PrepItem_BlockUpperfxDisp(proc);
		SetDispEnable(0, 0, 0, 0, 0);
		break;

	case PREP_SUB2ACT_ARMORY:
		Proc_End(proc->procbg);
		StartDefaultArmoryScreen(GetUnitFromPrepList(proc->list_num_cur), proc);
		PrepItem_BlockUpperfxDisp(proc);
		SetDispEnable(0, 0, 0, 0, 0);
		break;

	case PREP_SUB2ACT_STATSCREEN:
		Proc_End(proc->procbg);
		PrepItem_BlockUpperfxDisp(proc);
		SetDispEnable(0, 0, 0, 0, 0);
		SetStatScreenExcludedUnitFlags(UNIT_FLAG_DEAD);
		StartStatScreen(GetUnitFromPrepList(proc->list_num_cur), proc);
		break;

	default:
		break;
	}

	Proc_Break(proc);
}

void AtMenu_OnSubmenuEnd(struct PrepMenuProc *proc)
{
	switch (proc->sub2_action) {
	case PREP_SUB2ACT_TRADE_ITEM:
	case PREP_SUB2ACT_CONVOY:
	case PREP_SUB2ACT_DISCARD_ITEM:
	case PREP_SUB2ACT_CHECK_ALL_ITEM:
		PrepMenu_InitScreenExt(proc);
		Proc_Goto(proc->disp_proc, 0x0);
		NewSallyCir2(proc, -1);
		break;

	case PREP_SUB2ACT_SAVEMENU:
		StartBgmVolumeChange(0x80, 0x100, 0x20, NULL);

		/* Fall through */

	case PREP_SUB2ACT_ARMORY:
		StartBgm(0x22, NULL);
		PrepMenu_InitScreen(proc);
		Proc_Goto(proc->disp_proc, 0x0);
		break;

	case PREP_SUB2ACT_STATSCREEN:
	case PREP_SUB2ACT_8:
	case PREP_SUB2ACT_9:
		PrepMenu_InitScreen(proc);
		Proc_Goto(proc->disp_proc, 0x0);
		break;

	default:
		break;
	}

	if (proc->sub2_action == PREP_SUB2ACT_STATSCREEN)
		Proc_Goto(proc, 0xF);
	else if (proc->sub2_action > PREP_SUB2ACT_STATSCREEN)
		Proc_Goto(proc, 0xC);
	else
		Proc_Break(proc);

	proc->sub2_action = PREP_SUB2ACT_NONE;
}

void PrepScreen_ReloadLeftUnitInfoFromStatscreen(struct PrepMenuProc *proc)
{
	PrepScreen_ReloadLeftUnitInfo(GetUnitFromPrepList(proc->list_num_cur));
	proc->scroll_timer = 0;
}

/* https://decomp.me/scratch/UR3Es */
#if NONMATCHING

void func_fe6_0807B4C0(struct PrepMenuProc *proc)
{
	int i, j;
	int scroll_timer;

	if (proc->scroll_timer == 0)
	{
		proc->sel_unit = TRUE;
		proc->not_in_upper_menu = TRUE;
		proc->unk_2B = TRUE;

		PrepScreen_DrawScreenInfo(proc);
		TmFillRect(gBg0Tm, 12, 19, 0);
		TmFillRect(gBg1Tm, 12, 19, 0);
		func_fe6_08079D84(proc);
	}

	scroll_timer = (proc->scroll_timer += 0x10 - (proc->scroll_timer / 0xC)) >> 3;

	for (i = 0; i < 7; i++)
	{
		for (j = 0; j != scroll_timer; j++)
		{
			gBg1Tm[TM_OFFSET(j, i)] = gPrepTsaBuf[TM_OFFSET(j - scroll_timer + 13, i)];
			gBg0Tm[TM_OFFSET(j, i)] = gPrepTsaBuf[TM_OFFSET(j - scroll_timer + 13, i + 10)];
		}
	}

	EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT);

	if ((scroll_timer) > 12)
		Proc_Break(proc);
}

#else

NAKEDFUNC
void func_fe6_0807B4C0(struct PrepMenuProc *proc)
{
asm("\
	.syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #4\n\
	mov r8, r0\n\
	mov r5, r8\n\
	adds r5, #0x42\n\
	ldrh r0, [r5]\n\
	cmp r0, #0\n\
	bne .L0807B50C\n\
	mov r1, r8\n\
	adds r1, #0x29\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
	adds r1, #1\n\
	strb r0, [r1]\n\
	adds r1, #1\n\
	strb r0, [r1]\n\
	mov r0, r8\n\
	bl PrepScreen_DrawScreenInfo\n\
	ldr r0, .L0807B594 @ =gBg0Tm\n\
	movs r1, #0xc\n\
	movs r2, #0x13\n\
	movs r3, #0\n\
	bl TmFillRect_thm\n\
	ldr r0, .L0807B598 @ =gBg1Tm\n\
	movs r1, #0xc\n\
	movs r2, #0x13\n\
	movs r3, #0\n\
	bl TmFillRect_thm\n\
	mov r0, r8\n\
	bl func_fe6_08079D84\n\
.L0807B50C:\n\
	ldrh r4, [r5]\n\
	adds r4, #0x10\n\
	ldrh r0, [r5]\n\
	movs r1, #0xc\n\
	bl __udivsi3\n\
	subs r4, r4, r0\n\
	strh r4, [r5]			@ scroll_timer = proc->scroll_timer += 0x10 - (proc->scroll_timer / 0xC);\n\
	lsls r4, r4, #0x10\n\
	lsrs r7, r4, #0x13		@ _scroll_timer = scroll_timer / 8\n\
	movs r0, #0\n\
	rsbs r1, r7, #0\n\
	str r1, [sp]			@ [_sp] = -_scroll_timer\n\
.L0807B526:					@ for (i = 0; i < 7; i++)\n\
	adds r1, r0, #1\n\
	mov ip, r1\n\
	cmp r7, #0\n\
	beq .L0807B56C			@ if (_scroll_timer != 0)\n\
	ldr r3, .L0807B59C @ =gPrepTsaBuf\n\
	adds r2, r0, #0\n\
	adds r2, #0xa\n\
	lsls r2, r2, #6			@ r2 = (i + 10) << 6\n\
	ldr r1, [sp]\n\
	adds r1, #0xd 			@ off2 = -_scroll_timer + 13\n\
	lsls r4, r0, #6			@ r4 = i << 6\n\
	ldr r0, .L0807B598 		@ sl=gBg1Tm\n\
	mov sl, r0\n\
	ldr r0, .L0807B594 		@ sb=gBg0Tm\n\
	mov sb, r0\n\
	adds r6, r7, #0			@ for (j = _scroll_timer; j != 0; j--)\n\
	lsls r1, r1, #1 		@ off2 * 2\n\
	adds r0, r4, r3\n\
	adds r5, r1, r0			@ r5 = src2 = gPrepTsaBuf + (i << 6) + (-_scroll_timer + 13) * 2\n\
	adds r2, r2, r3\n\
	adds r2, r1, r2			@ r2 = src1 = gPrepTsaBuf + (i + 10) << 6\n\
.L0807B550:\n\
	mov r0, sl\n\
	adds r1, r4, r0			@ r1 = gBg1Tm + (r4) + j\n\
	ldrh r0, [r2]\n\
	strh r0, [r1]\n\
	mov r0, sb\n\
	adds r1, r4, r0			@ r1 = gBg0Tm + (r4) + j\n\
	ldrh r0, [r5]\n\
	strh r0, [r1]\n\
	adds r5, #2\n\
	adds r2, #2\n\
	adds r4, #2\n\
	subs r6, #1\n\
	cmp r6, #0\n\
	bne .L0807B550\n\
.L0807B56C:\n\
	mov r0, ip\n\
	cmp r0, #7\n\
	ble .L0807B526\n\
	movs r0, #3\n\
	bl EnableBgSync\n\
	cmp r7, #0xc\n\
	ble .L0807B582\n\
	mov r0, r8\n\
	bl Proc_Break\n\
.L0807B582:\n\
	add sp, #4\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
.L0807B594: .4byte gBg0Tm\n\
.L0807B598: .4byte gBg1Tm\n\
.L0807B59C: .4byte gPrepTsaBuf\n\
	.syntax divided\n\
");
}

#endif

/* https://decomp.me/scratch/JZCk9 */
#if NONMATCHING

void func_fe6_0807B5A0(struct PrepMenuProc *proc)
{
	int i, j, r8;
	u16 scroll_timer;
	if (proc->scroll_timer == 0)
	{
		proc->unk_2B = 0;
	}

	scroll_timer = (proc->scroll_timer += 0x10 - (proc->scroll_timer / 0xC)) / 8;
	r8 = 14 - scroll_timer;

	for (i = 0; i < 7; i++)
	{
		for (j = 0; j < 13; j++)
		{
			if (i < r8)
			{
				gBg1Tm[TM_OFFSET(j, i)] = gPrepTsaBuf[TM_OFFSET(scroll_timer, i)];
				gBg0Tm[TM_OFFSET(j, i)] = gPrepTsaBuf[TM_OFFSET(scroll_timer, i + 10)];
			}
			else
			{
				gBg1Tm[TM_OFFSET(j, i)] = 0;
				gBg0Tm[TM_OFFSET(j, i)] = 0;
			}
		}
	}

	EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT);

	if (scroll_timer > 12)
	{
		u8 pid;

		proc->sel_unit = 0;
		proc->not_in_upper_menu = 0;
		func_fe6_08079A94(proc);
		Proc_Break(proc);

		pid = UNIT_PID(gPrepUnitList[proc->list_num_cur]);

		ReorderPlayerUnitsBasedOnDeployment();
		func_fe6_0807A1C8(proc, FALSE);
		func_fe6_08079928(proc, pid, 1);
		PrepScreen_DrawScreenInfo(proc);
	}
}

#else

NAKEDFUNC
void func_fe6_0807B5A0(struct PrepMenuProc *proc)
{
asm("\
	.syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	adds r6, r0, #0\n\
	adds r5, r6, #0\n\
	adds r5, #0x42\n\
	ldrh r1, [r5]\n\
	cmp r1, #0\n\
	bne .L0807B5BA\n\
	adds r0, #0x2b\n\
	strb r1, [r0]\n\
.L0807B5BA:\n\
	ldrh r4, [r5]\n\
	adds r4, #0x10\n\
	ldrh r0, [r5]\n\
	movs r1, #0xc\n\
	bl __udivsi3\n\
	subs r4, r4, r0\n\
	strh r4, [r5]\n\
	lsls r4, r4, #0x10\n\
	lsrs r4, r4, #0x13\n\
	mov sl, r4 			@ sl = scroll_timer\n\
	movs r2, #0\n\
	movs r0, #0xd\n\
	mov r1, sl\n\
	subs r1, r0, r1\n\
	mov r8, r1			@ r8 = 14 - scroll_timer\n\
	movs r3, #0\n\
	mov sb, r3			@ sb = 0\n\
	mov r0, sl\n\
	lsls r7, r0, #1		@ r7 = scroll_timer << 1\n\
.L0807B5E2:\n\
	movs r5, #0\n\
	lsls r1, r2, #6\n\
	adds r3, r2, #1\n\
	mov ip, r3\n\
	adds r0, r7, r1\n\
	ldr r3, .L0807B610 @ =gPrepTsaBuf\n\
	adds r4, r0, r3							@ r4 = gPrepTsaBuf + (x = scroll_timer, y = j)\n\
	ldr r0, .L0807B614 @ =gBg0Tm\n\
	adds r3, r1, r0							@ r3 = gBg0Tm + (x = )\n\
	ldr r0, .L0807B618 @ =gBg1Tm\n\
	adds r1, r1, r0\n\
	adds r0, r2, #0\n\
	adds r0, #0xa\n\
	lsls r0, r0, #6\n\
	ldr r2, .L0807B610 @ =gPrepTsaBuf\n\
	adds r0, r0, r2\n\
	adds r2, r7, r0\n\
.L0807B604:\n\
	cmp r5, r8\n\
	blt .L0807B61C\n\
	mov r0, sb\n\
	strh r0, [r1]\n\
	b .L0807B622\n\
	.align 2, 0\n\
.L0807B610: .4byte gPrepTsaBuf\n\
.L0807B614: .4byte gBg0Tm\n\
.L0807B618: .4byte gBg1Tm\n\
.L0807B61C:\n\
	ldrh r0, [r2]\n\
	strh r0, [r1]\n\
	ldrh r0, [r4]\n\
.L0807B622:\n\
	strh r0, [r3]\n\
	adds r4, #2\n\
	adds r3, #2\n\
	adds r2, #2\n\
	adds r1, #2\n\
	adds r5, #1\n\
	cmp r5, #0xc\n\
	ble .L0807B604\n\
	mov r2, ip\n\
	cmp r2, #7\n\
	ble .L0807B5E2\n\
	movs r0, #3\n\
	bl EnableBgSync\n\
	mov r1, sl\n\
	cmp r1, #0xc\n\
	ble .L0807B68A\n\
	adds r1, r6, #0\n\
	adds r1, #0x29\n\
	movs r0, #0\n\
	strb r0, [r1]\n\
	adds r1, #1\n\
	strb r0, [r1]\n\
	adds r0, r6, #0\n\
	bl func_fe6_08079A94\n\
	adds r0, r6, #0\n\
	bl Proc_Break\n\
	ldr r1, .L0807B698 @ =gPrepUnitList\n\
	adds r0, r6, #0\n\
	adds r0, #0x30\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	ldr r0, [r0]\n\
	ldrb r4, [r0, #4]\n\
	bl ReorderPlayerUnitsBasedOnDeployment\n\
	adds r0, r6, #0\n\
	movs r1, #0\n\
	bl func_fe6_0807A1C8\n\
	adds r0, r6, #0\n\
	adds r1, r4, #0\n\
	movs r2, #1\n\
	bl func_fe6_08079928\n\
	adds r0, r6, #0\n\
	bl PrepScreen_DrawScreenInfo\n\
.L0807B68A:\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
.L0807B698: .4byte gPrepUnitList\n\
	.syntax divided\n\
");
}

#endif

void func_fe6_0807B69C(struct PrepMenuProc *proc)
{
	SetDispEnable(1, 1, 1, 1, 1);
}

struct ProcScr CONST_DATA ProcScr_AtMenu[] =
{
	PROC_19,
	PROC_CALL(LockGame),
	PROC_CALL(StartMidFadeToBlack),
	PROC_REPEAT(WhileFadeExists),
	PROC_CALL(LockBmDisplay),
	PROC_CALL(PrepMenu_EndIfNoUnit),
	PROC_YIELD,
	PROC_CALL(PrepMenu_Init),
	PROC_CALL(StartPrepMenuFadeOut),
	PROC_YIELD,
PROC_LABEL(1),
	PROC_REPEAT(PrepMenu_Loop),
	PROC_GOTO(L_PREPMENU_5),
PROC_LABEL(7),
	PROC_REPEAT(PrepUnit_HandleScrollUp),
PROC_LABEL(8),
	PROC_REPEAT(PrepUnit_HandleScrollDown),
PROC_LABEL(3),
	PROC_REPEAT(AtMenu_StartSubmenu),
PROC_LABEL(4),
	PROC_REPEAT(AtMenu_OnSubmenuEnd),
	PROC_GOTO(1),
PROC_LABEL(15),
	PROC_SLEEP(1),
	PROC_CALL(func_fe6_0807B69C),
	PROC_GOTO(1),
PROC_LABEL(9),
	PROC_CALL(PrepScreen_ReloadLeftUnitInfoFromStatscreen),
	PROC_REPEAT(func_fe6_0807B4C0),
	PROC_GOTO(1),
PROC_LABEL(10),
	PROC_CALL(PrepScreen_ReloadLeftUnitInfoFromStatscreen),
	PROC_REPEAT(func_fe6_0807B5A0),
	PROC_GOTO(1),
PROC_LABEL(13),
	PROC_CALL(StartPrepMenuFadeIn),
	PROC_YIELD,
	PROC_GOTO(3),
PROC_LABEL(12),
	PROC_CALL(StartPrepMenuFadeOut),
	PROC_YIELD,
	PROC_GOTO(1),
PROC_LABEL(14),
	PROC_CALL(AtMenu_SetEndFlag),
	PROC_GOTO(6),
PROC_LABEL(L_PREPMENU_5),
	PROC_CALL(AtMenu_SetEndFlag),
	PROC_SLEEP(60),
PROC_LABEL(L_PREPMENU_6),
	PROC_CALL(StartPrepMenuFadeIn),
	PROC_SLEEP(1),
PROC_LABEL(11),
	PROC_CALL(AtMenu_ResetBmUiEffect),
	PROC_YIELD,
	PROC_CALL(EndAllMus),
	PROC_CALL(UnlockBmDisplay),
	PROC_CALL(UnlockGame),
	PROC_END,
};

void StartPrepAtMenu(void)
{
	SpawnProc(ProcScr_AtMenu, PROC_TREE_3);
}

void StartSioPrepMenu(void)
{
	SpawnProc(ProcScr_AtMenu, PROC_TREE_3);
	SioResetUnitItems();
	ResetSioPidPool();
}
