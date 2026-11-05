#include "prelude.h"
#include "proc.h"
#include "oam.h"
#include "sprite.h"
#include "msg.h"
#include "item.h"
#include "icon.h"
#include "supply.h"
#include "ui.h"
#include "armfunc.h"

#include "prepscreen.h"

#include "constants/msg.h"
#include "constants/icons.h"

#include <string.h>

extern const char String_PrepItem_Affin[];
extern const char String_PrepItem_Might[];
extern const char String_PrepItem_Hit[];
extern const char String_PrepItem_Crit[];
extern const char String_PrepItem_Weight[];
extern const char String_PrepItem_None[];
extern const char Msg_Prep_Supply[]; // 輸送隊

CONST_DATA int HelpboxMsg_PrepSupplyActions[3] = { MSG_664, MSG_665, MSG_660 };

u16 CONST_DATA Sprite_PrepItemNamePlate[] = {
	2,
	OAM0_SHAPE_32x32, OAM1_SIZE_32x32, OAM2_CHR(0x2) + OAM2_LAYER(2) + OAM2_PAL(4),
	OAM0_SHAPE_32x32, OAM1_SIZE_32x32 + OAM1_X(32), OAM2_CHR(0x3) + OAM2_LAYER(2) + OAM2_PAL(4),
};

u16 CONST_DATA Sprite_PrepItemNamePlateFlipped[] = {
	2,
	OAM0_SHAPE_32x32, OAM1_SIZE_32x32 + OAM1_X(32), OAM2_CHR(0x2) + OAM2_LAYER(2) + OAM2_PAL(4),
	OAM0_SHAPE_32x32, OAM1_SIZE_32x32, OAM2_CHR(0x3) + OAM2_LAYER(2) + OAM2_PAL(4),
};

u16 CONST_DATA Sprite_PrepItemNamePlateWide[] = {
	4,
	OAM0_SHAPE_32x32, OAM1_SIZE_32x32, OAM2_CHR(0x2) + OAM2_LAYER(2) + OAM2_PAL(4),
	OAM0_SHAPE_32x32, OAM1_SIZE_32x32 + OAM1_X(32), OAM2_CHR(0x3) + OAM2_LAYER(2) + OAM2_PAL(4),
	OAM0_SHAPE_32x32, OAM1_SIZE_32x32 + OAM1_X(64), OAM2_CHR(0x3) + OAM2_LAYER(2) + OAM2_PAL(4),
	OAM0_SHAPE_32x32, OAM1_SIZE_32x32 + OAM1_X(72), OAM2_CHR(0x3) + OAM2_LAYER(2) + OAM2_PAL(4),
};

u16 CONST_DATA Sprite_PrepItemKindSword[] = {
	1,
	OAM0_SHAPE_16x16, OAM1_SIZE_16x16, OAM2_CHR(0x2C),
};

u16 CONST_DATA Sprite_PrepItemKindLance[] = {
	1,
	OAM0_SHAPE_16x16, OAM1_SIZE_16x16, OAM2_CHR(0x2E),
};

u16 CONST_DATA Sprite_PrepItemKindAxe[] = {
	1,
	OAM0_SHAPE_16x16, OAM1_SIZE_16x16, OAM2_CHR(0x30),
};

u16 CONST_DATA Sprite_PrepItemKindBow[] = {
	1,
	OAM0_SHAPE_16x16, OAM1_SIZE_16x16, OAM2_CHR(0x32),
};

u16 CONST_DATA Sprite_PrepItemKindStaff[] = {
	1,
	OAM0_SHAPE_16x16, OAM1_SIZE_16x16, OAM2_CHR(0x34),
};

u16 CONST_DATA Sprite_PrepItemKindAnima[] = {
	1,
	OAM0_SHAPE_16x16, OAM1_SIZE_16x16, OAM2_CHR(0x36),
};

u16 CONST_DATA Sprite_PrepItemKindLight[] = {
	1,
	OAM0_SHAPE_16x16, OAM1_SIZE_16x16, OAM2_CHR(0x38),
};

u16 CONST_DATA Sprite_PrepItemKindDark[] = {
	1,
	OAM0_SHAPE_16x16, OAM1_SIZE_16x16, OAM2_CHR(0x3A),
};

u16 CONST_DATA Sprite_PrepItemKindItem[] = {
	1,
	OAM0_SHAPE_16x16, OAM1_SIZE_16x16, OAM2_CHR(0x3C),
};

u16 CONST_DATA Sprite_PrepItemKindCursor[] = {
	1,
	OAM0_SHAPE_32x32, OAM1_SIZE_32x32, OAM2_CHR(0x7),
};

u16 CONST_DATA * Sprites_PrepItemKinds[PREP_ITEMKIND_PAGE_COUNT] = {
	Sprite_PrepItemKindSword,
	Sprite_PrepItemKindLance,
	Sprite_PrepItemKindAxe,
	Sprite_PrepItemKindBow,
	Sprite_PrepItemKindStaff,
	Sprite_PrepItemKindAnima,
	Sprite_PrepItemKindLight,
	Sprite_PrepItemKindDark,
	Sprite_PrepItemKindItem,
};

u8 CONST_DATA PrepItemKindRefTable[20] = {
	0, 0, 1, 1, 2, 2,
	3, 3, 4, 4, 5, 5,
	6, 6, 7, 7,
	ITEM_KIND_ITEM, ITEM_KIND_DRAGONSTONE,
	0, 0
};

struct ProcScr CONST_DATA ProcScr_PrepItemDesc[] = {
	PROC_19,
	PROC_CALL(PrepItemDesc_Init),
	PROC_REPEAT(PrepItemDesc_Loop),
	PROC_END,
};

void PrepItemDesc_Init(struct ProcPrepItemDesc *proc)
{
	InitTextDb(&proc->texts[0], 12);
	InitTextDb(&proc->texts[1], 12);
	InitText(&proc->texts[2], 12);
}

void PrepItemDesc_Loop(struct ProcPrepItemDesc *proc) {}

struct ProcPrepItemDesc * StartPrepItemDesc(ProcPtr parent)
{
	return SpawnProc(ProcScr_PrepItemDesc, parent);
}

struct ProcScr CONST_DATA ProcScr_PrepTradeFx[] = {
	PROC_19,
	PROC_CALL(PrepTradeFx_Init),
	PROC_REPEAT(PrepTradeFx_Loop),
	PROC_END,
};

void PrepItemFx_Dummy(int a, int b, int c)
{
	return;
}

void PrepTradeFx_Init(struct ProcPrepSubItemfx *proc)
{
	proc->timer = 0;

	if (proc->proc_parent->unk2D <= 3)
		proc->obj_offset = OBCHR_PREPMENU_390 * CHR_SIZE;
	else
		proc->obj_offset = OBCHR_PREPMENU_280 * CHR_SIZE;
}

void PrepTradeFx_Loop(struct ProcPrepSubItemfx *proc)
{
	PutSpriteExt(0xB, OAM1_HFLIP, 0, Sprite_PrepItemNamePlateFlipped, proc->obj_offset / CHR_SIZE);
	PutSpriteExt(0xB, 0xB0,	   0, Sprite_PrepItemNamePlate, proc->obj_offset / CHR_SIZE);

	PutUiHand(
		proc->proc_parent->hand_disp_x * 0x70 + 0x10,
		proc->proc_parent->hand_disp_y * 0x10 + 0x48);

	if (proc->proc_parent->unk30 != 0xFF)
	{
		PutFrozenUiHand(
			proc->proc_parent->unk30 * 0x70 + 0x10,
			proc->proc_parent->sel_action * 0x10 + 0x48);
	}

	PrepItemFx_Dummy(0, 4, proc->timer);
	proc->timer++;
}

ProcPtr StartPrepTradeFx(ProcPtr parent)
{
	return SpawnProc(ProcScr_PrepTradeFx, parent);
}

struct ProcScr CONST_DATA ProcScr_PrepViewAllFx[] = {
	PROC_19,
	PROC_CALL(PrepViewAllFx_Init),
	PROC_REPEAT(PrepViewAllFx_Loop),
	PROC_END,
};

void PrepViewAllFx_Init(struct ProcPrepSubItemfx *proc)
{
	proc->timer = 0;

	if (proc->proc_parent->unk2D <= 3)
		proc->obj_offset = OBCHR_PREPMENU_390 * CHR_SIZE;
	else
		proc->obj_offset = OBCHR_PREPMENU_280 * CHR_SIZE;
}

void PrepViewAllFx_Loop(struct ProcPrepSubItemfx *proc)
{
	PutSpriteExt(0xB, OAM1_HFLIP, 0, Sprite_PrepItemNamePlateFlipped, proc->obj_offset / CHR_SIZE);
	PutSpriteExt(0xB, 0xB0,	   0, Sprite_PrepItemNamePlate, proc->obj_offset / CHR_SIZE);

	if (proc->proc_parent->menu_scrolling_pos == 100)
		PutFrozenUiHand(
			0x80,
			proc->proc_parent->sel_action * 0x10 + 0x28);

	PrepAllItems_PutKindCursor(proc->proc_parent->convoy_page, proc->timer, proc->obj_offset);

	PutUiHand(
		proc->proc_parent->hand_disp_x * 0x70 + 0x10,
		proc->proc_parent->hand_disp_y * 0x10 + 0x48 - (proc->proc_parent->hand_disp_x * 0x20));

	SetPrepMenuScrollBarBaseInfo(
		proc->proc_parent->proc_menuscroll,
		0xE0,
		0x30,
		0xC,
		proc->proc_parent->menu_scroll_bar_disp_idx,
		gPrepMenuScrollPos,
		7);

	PrepItemFx_Dummy(3, 4, proc->timer);

	proc->timer++;
}

ProcPtr StartPrepViewAllFx(ProcPtr parent)
{
	return SpawnProc(ProcScr_PrepViewAllFx, parent);
}

struct ProcScr CONST_DATA ProcScr_PrepSupplyFx[] = {
	PROC_19,
	PROC_CALL(PrepSupplyFx_Init),
	PROC_REPEAT(PrepSupplyFx_Loop),
	PROC_END,
};

void PrepSupplyFx_Init(struct ProcPrepSubItemfx *proc)
{
	proc->timer = 0;

	proc->desc_proc = StartPrepItemDesc(proc);

	if (proc->proc_parent->unk2D <= 3)
		proc->obj_offset = OBCHR_PREPMENU_390 * CHR_SIZE;
	else
		proc->obj_offset = OBCHR_PREPMENU_280 * CHR_SIZE;
}

void PrepSupplyFx_Loop(struct ProcPrepSubItemfx *proc)
{
	PutSpriteExt(0xB, 0x88,	   0, Sprite_PrepItemNamePlateWide, proc->obj_offset / CHR_SIZE);

	if (proc->proc_parent->in_sel_action_menu == 0) {
		PutSpriteExt(0xB, OAM1_HFLIP, 0, Sprite_PrepItemNamePlateFlipped, proc->obj_offset / CHR_SIZE);

		PutUiHand(
			0xA0,
			proc->proc_parent->sel_action * 0x10 + 0x48);
	} else {
		if (proc->proc_parent->sel_action != 2)
			PutSpriteExt(0xB, OAM1_HFLIP, 0, Sprite_PrepItemNamePlateFlipped, proc->obj_offset / CHR_SIZE);

		if (proc->proc_parent->menu_scrolling_pos == 20) {
			PutFrozenUiHand(
				proc->proc_parent->hand_disp_x * 0x70 + 0x10,
				proc->proc_parent->hand_disp_y * 0x10 + 0x48 - (proc->proc_parent->hand_disp_x * 0x20));

			PutUiHand(
				proc->proc_parent->unk30 * 0x20 + 0x24,
				0x40);
		} else {
			PutUiHand(
				proc->proc_parent->hand_disp_x * 0x70 + 0x10,
				proc->proc_parent->hand_disp_y * 0x10 + 0x48 - (proc->proc_parent->hand_disp_x * 0x20));
		}

		PrepAllItems_PutKindCursor(proc->proc_parent->convoy_page, proc->timer, proc->obj_offset);

		SetPrepMenuScrollBarBaseInfo(
			proc->proc_parent->proc_menuscroll,
			0xE0,
			0x30,
			0xC,
			proc->proc_parent->menu_scroll_bar_disp_idx,
			gPrepMenuScrollPos,
			7);
	}

	if (proc->proc_parent->unk2D <= 3)
		PrepItemFx_Dummy(2, 4, proc->timer);

	proc->timer++;
}

ProcPtr StartPrepSupplyFx(ProcPtr parent)
{
	return SpawnProc(ProcScr_PrepSupplyFx, parent);
}

void PrepSubItem_InsertIcon(int icon)
{
	u8 i;

	for (i = 0; i < PREP_ICON_SLOT_COUNT; i++)
		if (gPrepSubMenuIcons[i] == icon)
			return;

	for (i = 0; i < PREP_ICON_SLOT_COUNT; i++) {
		if (gPrepSubMenuIcons[i] == PREP_ICON_SLOT_EMPTY) {
			gPrepSubMenuIcons[i] = icon;
			return;
		}
	}
}

void PrepSubItem_ResetIcon(void)
{
	int i;

	InitIcons();

	for (i = 0; i < PREP_ICON_SLOT_COUNT; i++)
		gPrepSubMenuIcons[i] = PREP_ICON_SLOT_EMPTY;
}

void PrepSubItem_ClearUnusedIcons(struct PrepSubItemProc *proc)
{
	u16 i, j, k;
	int icons[PREP_ICON_SLOT_COUNT];
	u16 bar_disp = proc->menu_scroll_bar_disp_idx / 0x10;
	struct Unit *unit = proc->units[0];
	u16 item_amt = GetUnitItemCount(unit);

	j = 0;
	for (i = 0; i < item_amt; i++) {
		icons[j] = GetItemIcon(unit->items[i]);
		j++;
	}

	if (gPrepMenuScrollPos != 0) {
		icons[j] = ICON_ITEM_KIND_BASE + GetItemKind(gPrepItemListData[
			proc->menu_scroll_bar_disp_idx / 0x10 + proc->hand_disp_y].item);

		j++;
	}

	if (bar_disp != 0)
		bar_disp--;

	for (i = bar_disp; (i < (bar_disp + 9)); i++) {
		if (i >= gPrepMenuScrollPos)
			break;

		icons[j] = GetItemIcon(gPrepItemListData[i].item);
		j++;
	}

	for (; j < PREP_ICON_SLOT_COUNT; j++)
		icons[j] = PREP_ICON_SLOT_EMPTY;

	for (i = 0; i < PREP_ICON_SLOT_COUNT; i++) {
		i8 used;

		if (gPrepSubMenuIcons[i] == PREP_ICON_SLOT_EMPTY)
			continue;

		used = false;

		for (k = 0; k < PREP_ICON_SLOT_COUNT; k++) {
			if (gPrepSubMenuIcons[i] == icons[k]) {
				used = true;
				break;
			}
		}

		if (used == false) {
			ClearIcon(gPrepSubMenuIcons[i]);
			gPrepSubMenuIcons[i] = PREP_ICON_SLOT_EMPTY;
		}
	}
}

void PrepItem_PutItemDesc(u8 x, u8 y, int item, struct ProcPrepSubItemfx *proc)
{
	struct ProcPrepItemDesc *subproc = proc->desc_proc;

	ClearText(&subproc->texts[0]);
	ClearText(&subproc->texts[1]);
	ClearText(&subproc->texts[2]);

	if (gPrepMenuScrollPos == 0) {
		TmFillRect(gBg0Tm, 0xE, 0x13, 0);
		TmFillRect(gBg1Tm, 0xE, 0x13, 0);
	} else {
		int i;
		const char *str;
		struct Text *text;
		int iy;
		int tm_offset;

		PutUiWindowFrame(x, y, 0xE, 8, 0);

		switch (GetItemKind(item)) {
		case ITEM_KIND_ITEM:
		case ITEM_KIND_STAFF:
		case ITEM_KIND_DRAGONSTONE:
			str = DecodeMsg(GetItemUseDescMsg(item));
			iy  = y + 1;
			text = &subproc->texts[0];
			tm_offset = TM_OFFSET(x + 1, iy);

			for (;;) {
				PrepPutText(
					text, (u16 *)(gBg0Tm + tm_offset),
					TEXT_COLOR_SYSTEM_WHITE,
					0, str);

				str = GetStringLineEnd(str);
				if (*str == '\0')
					break;

				str++, tm_offset += TM_OFFSET(0, 1) * 2, text++;
			}
			break;

		default:
			Text_InsertDrawString(&subproc->texts[2], 0,    TEXT_COLOR_SYSTEM_WHITE, String_PrepItem_Affin);
			Text_InsertDrawString(&subproc->texts[0], 2,    TEXT_COLOR_SYSTEM_WHITE, String_PrepItem_Might);
			Text_InsertDrawString(&subproc->texts[1], 2,    TEXT_COLOR_SYSTEM_WHITE, String_PrepItem_Hit);
			Text_InsertDrawString(&subproc->texts[0], 0x32, TEXT_COLOR_SYSTEM_WHITE, String_PrepItem_Crit);
			Text_InsertDrawString(&subproc->texts[1], 0x32, TEXT_COLOR_SYSTEM_WHITE, String_PrepItem_Weight);

			PutText(&subproc->texts[0], gBg0Tm + TM_OFFSET(x + 1, y + 3));
			PutText(&subproc->texts[2], gBg0Tm + TM_OFFSET(x + 5, y + 1));
			PutText(&subproc->texts[1], gBg0Tm + TM_OFFSET(x + 1, y + 5));

			PutNumber(gBg0Tm + TM_OFFSET(x + 5,  y + 3), TEXT_COLOR_SYSTEM_BLUE, GetItemMight(item));
			PutNumber(gBg0Tm + TM_OFFSET(x + 5,  y + 5), TEXT_COLOR_SYSTEM_BLUE, GetItemHit(item));
			PutNumber(gBg0Tm + TM_OFFSET(x + 11, y + 3), TEXT_COLOR_SYSTEM_BLUE, GetItemCrit(item));
			PutNumber(gBg0Tm + TM_OFFSET(x + 11, y + 5), TEXT_COLOR_SYSTEM_BLUE, GetItemWeight(item));
			PutIcon(gBg0Tm + TM_OFFSET(x + 7, y + 1), GetItemKind(item) + ICON_ITEM_KIND_BASE, OAM2_PAL(BGPAL_PREPMENU_AFFIN_ICON));
			PrepSubItem_InsertIcon(GetItemKind(item) + ICON_ITEM_KIND_BASE);
			break;
		}
	}

	EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT);
}

static inline int Tm_Offset_Inline(int x, int y)
{
	return (y << 5) + x;
}

void PrepItem_PutUnitItems(u8 index, struct Unit *unit)
{
	u8 i, item_count = GetUnitItemCount(unit);

	for (i = 0; i < ITEMSLOT_INV_COUNT; i++) {
		struct Text *text = &gPrepTexts1[index][i];

		ClearText(text);
		TmFillRect(gBg0Tm + (Tm_Offset_Inline(2, i * 2 + 9) + index * 14), 11, 1, 0);
	}

	for (i = 0; (i < ITEMSLOT_INV_COUNT) && (i < item_count); i++) {
		bool usable = !!IsItemDisplayUsable(unit, unit->items[i]);
		struct Text *text = &gPrepTexts1[index][i];

		Text_SetColor(text, usable ? TEXT_COLOR_SYSTEM_WHITE : TEXT_COLOR_SYSTEM_GRAY);
		Text_SetCursor(text, 0);
		Text_DrawString(text, GetItemName(unit->items[i]));
		PutText(text, gBg0Tm + (Tm_Offset_Inline(4, i * 2 + 9) + index * 14));
		PutNumberOrBlank(
			gBg0Tm + (Tm_Offset_Inline(13, i * 2 + 9) + index * 14),
			(usable) ? TEXT_COLOR_SYSTEM_BLUE : TEXT_COLOR_SYSTEM_GRAY,
			GetItemUses(unit->items[i]));

		PutIcon(gBg0Tm + (Tm_Offset_Inline(2, i * 2 + 9) + index * 14), GetItemIcon(unit->items[i]), OAM2_PAL(BGPAL_PREPMENU_ICON));
		PrepSubItem_InsertIcon(GetItemIcon(unit->items[i]));
	}

	EnableBgSync(BG0_SYNC_BIT);
}

void PrepAllItems_SortByKind(fu8 page)
{
	fu8 category_offset = page * 2;

	int i, j;
	int gap;

	gPrepMenuScrollPos = 0;

	for (i = 0; i < gPrepAllItemsCount; i++)
	{
		fu8 item_kind = GetItemKind(gPrepItemListData[i].item);

		if (item_kind >= PrepItemKindRefTable[category_offset + 0] && item_kind <= PrepItemKindRefTable[category_offset + 1])
		{
			gPrepPageItemTable[gPrepMenuScrollPos] = gPrepItemListData[i];
			gPrepMenuScrollPos++;
		}
	}

	/* this is a variant of shellsort
	 * <https://en.wikipedia.org/wiki/Shellsort> */

	gap = 1;

	while (gap < gPrepMenuScrollPos / 3)
	{
		gap = gap * 3 + 1;
	}

	while (gap > 0)
	{
		for (i = gap; i < gPrepMenuScrollPos; i++)
		{
			for (j = i - gap; j >= 0; j -= gap)
			{
				if (GetItemIid(gPrepPageItemTable[j].item) > GetItemIid(gPrepPageItemTable[j + gap].item))
				{
					/* swap if greater IID */
					struct PrepItemListEnt tmp = gPrepPageItemTable[j];
					gPrepPageItemTable[j] = gPrepPageItemTable[j + gap];
					gPrepPageItemTable[j + gap] = tmp;
				}
				else
				{
					if (GetItemIid(gPrepPageItemTable[j].item) != GetItemIid(gPrepPageItemTable[j + gap].item))
						break;

					if (gPrepPageItemTable[j].item > gPrepPageItemTable[j + gap].item)
					{
						/* swap if greater item value (=> greater uses) */
						struct PrepItemListEnt tmp = gPrepPageItemTable[j];
						gPrepPageItemTable[j] = gPrepPageItemTable[j + gap];
						gPrepPageItemTable[j + gap] = tmp;
					}
				}
			}
		}

		gap = gap / 3;
	}

	/* import in the remaining items */

	j = 0;

	for (i = 0; i < gPrepAllItemsCount; i++)
	{
		fu8 item_kind = GetItemKind(gPrepItemListData[i].item);

		if (item_kind < PrepItemKindRefTable[category_offset + 0] || item_kind > PrepItemKindRefTable[category_offset + 1])
		{
			gPrepPageItemTable[gPrepMenuScrollPos + j] = gPrepItemListData[i];
			j++;
		}
	}

	memcpy(gPrepItemListData, gPrepPageItemTable, sizeof(gPrepItemListData));
}

void PrepAllItems_PutList(struct Text *text, u8 x, struct Unit *unit, u16 off, int unused)
{
	u16 i;

	TmFill(gBg2Tm, 0);

	if (gPrepMenuScrollPos == 0) {
		ClearText(text);
		Text_SetCursor(text, 0);
		Text_SetColor(text, TEXT_COLOR_SYSTEM_GRAY);
		Text_DrawString(text, String_PrepItem_None);
		PutText(text, gBg2Tm + TM_OFFSET(x * 14 + 4, 0));
	}

	for (i = off; i < (off + 7) && i < gPrepMenuScrollPos; i++) {
		bool usable;

		ClearText(&text[i & 7]);
		Text_SetCursor(&text[i & 7], 0);
		PutIcon(
			gBg2Tm + TM_OFFSET(x * 14 + 2, (i * 2) & 0x1F),
			GetItemIcon(gPrepItemListData[i].item),
			OAM2_PAL(BGPAL_PREPMENU_ICON));
		PrepSubItem_InsertIcon(GetItemIcon(gPrepItemListData[i].item));

		if (!unit || IsItemDisplayUsable(unit, gPrepItemListData[i].item))
			usable = true;
		else
			usable = false;

		Text_SetColor(&text[i & 7], usable ? TEXT_COLOR_SYSTEM_WHITE : TEXT_COLOR_SYSTEM_GRAY);
		Text_DrawString(&text[i & 7], GetItemName(gPrepItemListData[i].item));
		PutText(&text[i & 7], gBg2Tm + TM_OFFSET(x * 14 + 4, (i * 2) & 0x1F));
		PutNumberOrBlank(
			gBg2Tm + TM_OFFSET(x * 14 + 0xD, (i * 2) & 0x1F),
			usable ? TEXT_COLOR_SYSTEM_BLUE : TEXT_COLOR_SYSTEM_GRAY,
			GetItemUses(gPrepItemListData[i].item));
	}

	EnableBgSync(BG2_SYNC_BIT);
}

void PrepAllItems_PutListRow(struct Text *texts, u8 x, u16 y, struct Unit *unit, int unused)
{
	i8 tmp;
	struct Text *text;
	u8 _y = y & 0xF;

	TmFillRect(gBg2Tm + TM_OFFSET(x * 14, _y * 2), 0x10, 1, 0);
	ClearText(&texts[y & 0x7]);
	PutIcon(
		gBg2Tm + TM_OFFSET(x * 14 + 2, _y * 2),
		GetItemIcon(gPrepItemListData[y].item),
		OAM2_PAL(BGPAL_PREPMENU_ICON));
	PrepSubItem_InsertIcon(GetItemIcon(gPrepItemListData[y].item));

	if (unit == NULL || IsItemDisplayUsable(unit, gPrepItemListData[y].item) != false)
		tmp = 1;
	else
		tmp = 0;

	text = &texts[y & 0x7];

	Text_SetColor(text, (tmp == 0) ? TEXT_COLOR_SYSTEM_GRAY : TEXT_COLOR_SYSTEM_WHITE);
	Text_SetCursor(text, 0);
	Text_DrawString(text, GetItemName(gPrepItemListData[y].item));
	PutText(text, gBg2Tm + TM_OFFSET(x * 14 + 4, _y * 2));
	PutNumberOrBlank(
		gBg2Tm + TM_OFFSET(x * 14 + 13, _y * 2),
		(tmp != 0) ? TEXT_COLOR_SYSTEM_BLUE : TEXT_COLOR_SYSTEM_GRAY,
		GetItemUses(gPrepItemListData[y].item));

	EnableBgSync(BG2_SYNC_BIT);
}

void PrepAllItems_PutPName(struct Text *text, u8 pid, u8 x, u8 y)
{
	TmFillRect(gBg0Tm + TM_OFFSET(0xF, 0), 0xF, 1, 0);

	if (gPrepMenuScrollPos == 0)
		TmFillRect(gBg0Tm + TM_OFFSET(20, 0), 9, 1, 0);
	else if (pid == 0) {
		ClearText(text);
		Text_SetColor(text, TEXT_COLOR_SYSTEM_WHITE);
		Text_SetCursor(text, (0x28 - GetStringTextLen(Msg_Prep_Supply)) / 2);
		Text_DrawString(text, Msg_Prep_Supply);
		PutText(text, gBg0Tm + TM_OFFSET(x, y));
	} else {
		struct Unit *unit = GetUnitByPid(pid);

		ClearText(text);
		Text_SetColor(text, TEXT_COLOR_SYSTEM_WHITE);
		Text_SetCursor(text, (0x28 - GetStringTextLen(DecodeMsg(unit->pinfo->msg_name))) / 2);
		Text_DrawString(text, DecodeMsg(unit->pinfo->msg_name));
		PutText(text, gBg0Tm + TM_OFFSET(x, y));
	}

	EnableBgSync(BG0_SYNC_BIT);
}

void PrepAllItems_PutTotalNum(u8 x, u8 y)
{
	u8 total_num = GetTotalSupplyItemCount();

	TmFillRect(gBg0Tm + TM_OFFSET(x - 3, y), 6, 1, 0);
	PrepPutText(&gPrepTexts3[1], gBg0Tm + TM_OFFSET(0x12, 0), TEXT_COLOR_SYSTEM_WHITE, 4, Msg_Prep_Supply);

	PutNumber(gBg0Tm + TM_OFFSET(x, y), TEXT_COLOR_SYSTEM_BLUE, total_num);
	PutNumber(gBg0Tm + TM_OFFSET(x + 4, y), TEXT_COLOR_SYSTEM_BLUE, SUPPLY_ITEM_COUNT);
	PutSpecialChar(gBg0Tm + TM_OFFSET(x + 1, y), TEXT_COLOR_SYSTEM_BLUE, TEXT_SPECIAL_SLASH);

	EnableBgSync(BG0_SYNC_BIT);
}

void PrepAllItems_Update(void)
{
	u16 *supply_items = GetSupplyItems();
	u16 i, j = 0;

	for (i = 0; i < gPrepAllItemsCount; i++) {
		if (gPrepItemListData[i].pid == 0) {
			supply_items[j] = gPrepItemListData[i].item;
			j++;
		}
	}

	for (; j < SUPPLY_ITEM_COUNT; j++)
		supply_items[j] = 0;

	PrepAllItems_PutTotalNum(0x18, 0);
}

void PrepSupply_SwitchToItemKindPage(struct PrepSubItemProc *proc, u16 item)
{
	u8 i;
	u8 kind;

	kind = GetItemKind(item);

	for (i = 0; i < PREP_ITEMKIND_PAGE_COUNT; i++) {
		if ((kind == PrepItemKindRefTable[i * 2 + 0]) || (kind == PrepItemKindRefTable[i * 2 + 1]))
			break;
	}

	if (proc->convoy_page != i) {
		proc->convoy_page = i;
		proc->menu_scroll_bar_disp_idx = proc->unk_32[proc->convoy_page] * 0x10;
		PrepAllItems_SortByKind(proc->convoy_page);
		func_fe6_080823A0(proc->unk_3B + proc->convoy_page, &proc->menu_scroll_bar_disp_idx);
		PrepAllItems_PutList(&gPrepTexts1[1][0], 1, proc->units[0], proc->menu_scroll_bar_disp_idx / 0x10, 1);
		PrepSubItem_ClearUnusedIcons(proc);
	}
}

bool PrepAllItems_SwapItems(struct Unit *unit, u8 u_slot, u16 c_slot)
{
	struct PrepItemListEnt tmp;

	tmp = gPrepItemListData[c_slot];
	gPrepItemListData[c_slot].item = unit->items[u_slot];
	unit->items[u_slot] = tmp.item;

	UnitRemoveInvalidItems(unit);

	if (gPrepItemListData[c_slot].item == 0) {
		u16 i;

		for (i = c_slot; i < gPrepAllItemsCount; i++) {
			gPrepItemListData[i] = gPrepItemListData[i + 1];

			if (gPrepItemListData[i].pid == 0)
				gPrepItemListData[i].slot--;
		}

		gPrepMenuScrollPos--;
		gPrepAllItemsCount--;
		PrepAllItems_Update();
		return true;
	}

	PrepAllItems_Update();
	return false;
}

void PrepAllItems_PutKindCursor(u8 page, int timer, int obj_off)
{
	u8 tmp = timer;
	const u16 *src = Pal_Prep_0831B068;

	gPal[PAL_COLOR_OFFSET(0x10 + OBPAL_PREPMENU_2, 0xD)] = src[(tmp >> 2) & 0xF];

	EnablePalSync();

	PutSprite(4, page * 12 + 0x7C, 0x18, Sprites_PrepItemKinds[page], OAM2_PAL(OBPAL_PREPMENU_2) + obj_off / CHR_SIZE);
	PutSprite(4, page * 12 + 0x7C, 0x18, Sprite_PrepItemKindCursor,	 OAM2_PAL(OBPAL_PREPMENU_2) + obj_off / CHR_SIZE);
}
