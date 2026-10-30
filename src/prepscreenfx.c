#include "prelude.h"
#include "proc.h"
#include "oam.h"
#include "sprite.h"
#include "msg.h"
#include "item.h"
#include "icon.h"
#include "ui.h"
#include "armfunc.h"

#include "prepscreen.h"

#include "constants/msg.h"
#include "constants/icons.h"

extern const char String_Prep_0832726C[];
extern const char String_Prep_08327274[];
extern const char String_Prep_0832727C[];
extern const char String_Prep_08327284[];
extern const char String_Prep_0832728C[];

CONST_DATA int HelpboxMsg_0867929C[3] = { MSG_664, MSG_665, MSG_660 };

u16 CONST_DATA Sprite_086792A8[] = {
	2,
	OAM0_SHAPE_32x32, OAM1_SIZE_32x32, OAM2_CHR(0x2) + OAM2_LAYER(2) + OAM2_PAL(4),
	OAM0_SHAPE_32x32, OAM1_SIZE_32x32 + OAM1_X(32), OAM2_CHR(0x3) + OAM2_LAYER(2) + OAM2_PAL(4),
};

u16 CONST_DATA Sprite_086792B6[] = {
	2,
	OAM0_SHAPE_32x32, OAM1_SIZE_32x32 + OAM1_X(32), OAM2_CHR(0x2) + OAM2_LAYER(2) + OAM2_PAL(4),
	OAM0_SHAPE_32x32, OAM1_SIZE_32x32, OAM2_CHR(0x3) + OAM2_LAYER(2) + OAM2_PAL(4),
};

u16 CONST_DATA Sprite_086792C4[] = {
	4,
	OAM0_SHAPE_32x32, OAM1_SIZE_32x32, OAM2_CHR(0x2) + OAM2_LAYER(2) + OAM2_PAL(4),
	OAM0_SHAPE_32x32, OAM1_SIZE_32x32 + OAM1_X(32), OAM2_CHR(0x3) + OAM2_LAYER(2) + OAM2_PAL(4),
	OAM0_SHAPE_32x32, OAM1_SIZE_32x32 + OAM1_X(64), OAM2_CHR(0x3) + OAM2_LAYER(2) + OAM2_PAL(4),
	OAM0_SHAPE_32x32, OAM1_SIZE_32x32 + OAM1_X(72), OAM2_CHR(0x3) + OAM2_LAYER(2) + OAM2_PAL(4),
};

u16 CONST_DATA Sprite_086792DE[] = {
	1,
	OAM0_SHAPE_16x16, OAM1_SIZE_16x16, OAM2_CHR(0x2C),
};

u16 CONST_DATA Sprite_086792E6[] = {
	1,
	OAM0_SHAPE_16x16, OAM1_SIZE_16x16, OAM2_CHR(0x2E),
};

u16 CONST_DATA Sprite_086792EE[] = {
	1,
	OAM0_SHAPE_16x16, OAM1_SIZE_16x16, OAM2_CHR(0x30),
};

u16 CONST_DATA Sprite_086792F6[] = {
	1,
	OAM0_SHAPE_16x16, OAM1_SIZE_16x16, OAM2_CHR(0x32),
};

u16 CONST_DATA Sprite_086792FE[] = {
	1,
	OAM0_SHAPE_16x16, OAM1_SIZE_16x16, OAM2_CHR(0x34),
};

u16 CONST_DATA Sprite_08679306[] = {
	1,
	OAM0_SHAPE_16x16, OAM1_SIZE_16x16, OAM2_CHR(0x36),
};

u16 CONST_DATA Sprite_0867930E[] = {
	1,
	OAM0_SHAPE_16x16, OAM1_SIZE_16x16, OAM2_CHR(0x38),
};

u16 CONST_DATA Sprite_08679316[] = {
	1,
	OAM0_SHAPE_16x16, OAM1_SIZE_16x16, OAM2_CHR(0x3A),
};

u16 CONST_DATA Sprite_0867931E[] = {
	1,
	OAM0_SHAPE_16x16, OAM1_SIZE_16x16, OAM2_CHR(0x3C),
};

u16 CONST_DATA Sprite_08679326[] = {
	1,
	OAM0_SHAPE_32x32, OAM1_SIZE_32x32, OAM2_CHR(0x7),
};

u16 CONST_DATA * Sprites_08679330[] = {
	Sprite_086792DE,
	Sprite_086792E6,
	Sprite_086792EE,
	Sprite_086792F6,
	Sprite_086792FE,
	Sprite_08679306,
	Sprite_0867930E,
	Sprite_08679316,
	Sprite_0867931E,
};

u8 CONST_DATA PrepItemKindRefTable[20] = {
	0, 0, 1, 1, 2, 2,
	3, 3, 4, 4, 5, 5,
	6, 6, 7, 7,
	ITEM_KIND_ITEM, ITEM_KIND_DRAGONSTONE,
	0, 0
};

struct ProcScr CONST_DATA ProcScr_08679368[] = {
	PROC_19,
	PROC_CALL(func_fe6_0807CF78),
	PROC_REPEAT(func_fe6_0807CFA0),
	PROC_END,
};

void func_fe6_0807CF78(struct ProcPrepSubItemSubfx *proc)
{
	InitTextDb(&proc->texts[0], 12);
	InitTextDb(&proc->texts[1], 12);
	InitText(&proc->texts[2], 12);
}

void func_fe6_0807CFA0(struct ProcPrepSubItemSubfx *proc) {}

struct ProcPrepSubItemSubfx * func_fe6_0807CFA4(ProcPtr parent)
{
	return SpawnProc(ProcScr_08679368, parent);
}

struct ProcScr CONST_DATA ProcScr_08679388[] = {
	PROC_19,
	PROC_CALL(func_fe6_0807CFBC),
	PROC_REPEAT(func_fe6_0807CFDC),
	PROC_END,
};

void dummy_0807CFB8(int a, int b, int c)
{
	return;
}

void func_fe6_0807CFBC(struct ProcPrepSubItemfx *proc)
{
	proc->timer = 0;

	if (proc->proc_parent->unk2D <= 3)
		proc->obj_offset = 0x7200;
	else
		proc->obj_offset = 0x5000;
}

void func_fe6_0807CFDC(struct ProcPrepSubItemfx *proc)
{
	PutSpriteExt(0xB, OAM1_HFLIP, 0, Sprite_086792B6, proc->obj_offset / 0x20);
	PutSpriteExt(0xB, 0xB0,	   0, Sprite_086792A8, proc->obj_offset / 0x20);

	PutUiHand(
		proc->proc_parent->hand_disp_x * 0x70 + 0x10,
		proc->proc_parent->hand_disp_y * 0x10 + 0x48);

	if (proc->proc_parent->unk30 != 0xFF)
	{
		PutFrozenUiHand(
			proc->proc_parent->unk30 * 0x70 + 0x10,
			proc->proc_parent->sel_action * 0x10 + 0x48);
	}

	dummy_0807CFB8(0, 4, proc->timer);
	proc->timer++;
}

ProcPtr func_fe6_0807D074(ProcPtr parent)
{
	return SpawnProc(ProcScr_08679388, parent);
}

struct ProcScr CONST_DATA ProcScr_086793A8[] = {
	PROC_19,
	PROC_CALL(func_fe6_0807D088),
	PROC_REPEAT(func_fe6_0807D0A8),
	PROC_END,
};

void func_fe6_0807D088(struct ProcPrepSubItemfx *proc)
{
	proc->timer = 0;

	if (proc->proc_parent->unk2D <= 3)
		proc->obj_offset = 0x7200;
	else
		proc->obj_offset = 0x5000;
}

void func_fe6_0807D0A8(struct ProcPrepSubItemfx *proc)
{
	PutSpriteExt(0xB, OAM1_HFLIP, 0, Sprite_086792B6, proc->obj_offset / 0x20);
	PutSpriteExt(0xB, 0xB0,	   0, Sprite_086792A8, proc->obj_offset / 0x20);

	if (proc->proc_parent->menu_scrolling_pos == 100)
		PutFrozenUiHand(
			0x80,
			proc->proc_parent->sel_action * 0x10 + 0x28);

	func_fe6_0807DFEC(proc->proc_parent->convoy_page, proc->timer, proc->obj_offset);

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

	dummy_0807CFB8(3, 4, proc->timer);

	proc->timer++;
}

ProcPtr func_fe6_0807D16C(ProcPtr parent)
{
	return SpawnProc(ProcScr_086793A8, parent);
}

struct ProcScr CONST_DATA ProcScr_086793C8[] = {
	PROC_19,
	PROC_CALL(func_fe6_0807D180),
	PROC_REPEAT(func_fe6_0807D1AC),
	PROC_END,
};

void func_fe6_0807D180(struct ProcPrepSubItemfx *proc)
{
	proc->timer = 0;

	proc->procfx = func_fe6_0807CFA4(proc);

	if (proc->proc_parent->unk2D <= 3)
		proc->obj_offset = 0x7200;
	else
		proc->obj_offset = 0x5000;
}

void func_fe6_0807D1AC(struct ProcPrepSubItemfx *proc)
{
	PutSpriteExt(0xB, 0x88,	   0, Sprite_086792C4, proc->obj_offset / 0x20);

	if (proc->proc_parent->in_sel_action_menu == 0) {
		PutSpriteExt(0xB, OAM1_HFLIP, 0, Sprite_086792B6, proc->obj_offset / 0x20);

		PutUiHand(
			0xA0,
			proc->proc_parent->sel_action * 0x10 + 0x48);
	} else {
		if (proc->proc_parent->sel_action != 2)
			PutSpriteExt(0xB, OAM1_HFLIP, 0, Sprite_086792B6, proc->obj_offset / 0x20);

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

		func_fe6_0807DFEC(proc->proc_parent->convoy_page, proc->timer, proc->obj_offset);

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
		dummy_0807CFB8(2, 4, proc->timer);

	proc->timer++;
}

ProcPtr func_fe6_0807D2E0(ProcPtr parent)
{
	return SpawnProc(ProcScr_086793C8, parent);
}

void PrepSubItem_InsertIcon(int icon)
{
	u8 i;

	for (i = 0; i < 20; i++)
		if (gPrepSubMenuIcons[i] == icon)
			return;

	for (i = 0; i < 20; i++) {
		if (gPrepSubMenuIcons[i] == 0xFF) {
			gPrepSubMenuIcons[i] = icon;
			return;
		}
	}
}

void PrepSubItem_ResetIcon(void)
{
	int i;

	InitIcons();

	for (i = 0; i < 20; i++)
		gPrepSubMenuIcons[i] = 0xFF;
}

void func_fe6_0807D358(struct PrepSubItemProc *proc)
{
	u16 i, j, k;
	int icons[20];
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

	for (; j < 20; j++)
		icons[j] = 0xFF;

	for (i = 0; i < 20; i++) {
		i8 used;

		if (gPrepSubMenuIcons[i] == 0xFF)
			continue;

		used = false;

		for (k = 0; k < 20; k++) {
			if (gPrepSubMenuIcons[i] == icons[k]) {
				used = true;
				break;
			}
		}

		if (used == false) {
			ClearIcon(gPrepSubMenuIcons[i]);
			gPrepSubMenuIcons[i] = 0xFF;
		}
	}
}

void PrepItem_PutItemDesc(u8 x, u8 y, int item, struct ProcPrepSubItemfx *proc)
{
	struct ProcPrepSubItemSubfx *subproc = proc->procfx;

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
			Text_InsertDrawString(&subproc->texts[2], 0,    TEXT_COLOR_SYSTEM_WHITE, String_Prep_0832726C); // affin 属性
			Text_InsertDrawString(&subproc->texts[0], 2,    TEXT_COLOR_SYSTEM_WHITE, String_Prep_08327274); // wt 威力
			Text_InsertDrawString(&subproc->texts[1], 2,    TEXT_COLOR_SYSTEM_WHITE, String_Prep_0832727C); // hit 命中
			Text_InsertDrawString(&subproc->texts[0], 0x32, TEXT_COLOR_SYSTEM_WHITE, String_Prep_08327284); // crit 必殺
			Text_InsertDrawString(&subproc->texts[1], 0x32, TEXT_COLOR_SYSTEM_WHITE, String_Prep_0832728C); // mt 重さ

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

void func_fe6_0807D6C0(u8 index, struct Unit *unit)
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
