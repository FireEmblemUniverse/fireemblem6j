#include "prelude.h"
#include "proc.h"
#include "oam.h"
#include "msg.h"
#include "sprite.h"
#include "item.h"
#include "arena.h"
#include "unitlistscreen.h"
#include "helpbox.h"
#include "supply.h"
#include "constants/msg.h"

#include "prepscreen.h"

u8 GetTotalSupplyItemCount(void)
{
	u8 i, ret = 0;
	const u16 *supply = GetSupplyItems();

	for (i = 0; i < SUPPLY_ITEM_COUNT; i++) {
		if (supply[i] != 0)
			ret++;
		else
			break;
	}
	return ret;
}

struct ProcScr CONST_DATA ProcScr_ViewCounter[] = {
	PROC_NAME_DEBUG("ViewCounter"),
	PROC_SLEEP(0),
	PROC_REPEAT(ViewCounter_Loop),
	PROC_END,
};

void ViewCounter_Loop(struct ViewCounterProc *proc)
{
	if (proc->targetFrameCount == proc->counter) {
		SetDispEnable(1, 1, 1, 1, 1);
		Proc_Break(proc);
	}

	proc->counter++;
}

void StartViewCounter(u16 frames, ProcPtr parent)
{
	struct ViewCounterProc *proc = SpawnProc(ProcScr_ViewCounter, parent);

	proc->counter = 0;
	proc->targetFrameCount = frames;

	SetDispEnable(0, 0, 0, 0, 0);
}

void TryLockProc(ProcPtr proc)
{
	struct Proc *p = proc;

	p->proc_lock_cnt++;
}

void TryUnlockProc(ProcPtr proc)
{
	struct Proc *p = proc;

	if (p->proc_lock_cnt != 0)
		p->proc_lock_cnt--;
}

struct ProcScr CONST_DATA ProcScr_PrepErrorHelpboxLister[] = {
	PROC_SLEEP(1),
	PROC_REPEAT(PrepHbKeyListener_Loop),
	PROC_END,
};

void PrepHbKeyListener_Loop(ProcPtr proc)
{
	if (gKeySt->pressed & (KEY_BUTTON_A | KEY_BUTTON_B | KEY_DPAD_ANY)) {
		CloseHelpBox();
		Proc_Break(proc);
	}
}

ProcPtr StartPrepErrorHelpbox(int x, int y, int msg, ProcPtr parent)
{
	StartHelpBox(x, y, msg);

	return SpawnProcLocking(ProcScr_PrepErrorHelpboxLister, parent);
}

bool IsWeaponUsable(struct Unit *unit, int weapon)
{
	if (!CanUnitUseWeapon(unit, weapon))
		return false;

	if (GetItemAttributes(weapon) & ITEM_ATTR_UNCOUNTERABLE)
		return false;

	return true;
}

int CountUnitUsableWeapons(struct Unit *unit)
{
	int i, ret = 0;

	for (i = 0; i < ITEMSLOT_INV_COUNT; i++)
		if (IsWeaponUsable(unit, unit->items[i]) == true)
			ret++;

	return ret;
}

bool CanUnitUseWeaponsInArena(struct Unit *unit)
{
	if (!ArenaIsUnitAllowed(unit))
		return false;

	if (CountUnitUsableWeapons(unit) == 0)
		return false;

	return true;
}

bool CheckValidLinkArenaItemSwap(struct Unit *unit1, int slot1, struct Unit *unit2, int slot2)
{
	if (unit1 == unit2)
		return true;

	if (!(unit1->flags & UNIT_FLAG_NOT_DEPLOYED)) {
		if (IsWeaponUsable(unit1, unit1->items[slot1]))
			if (CountUnitUsableWeapons(unit1) <= 1)
				if (!IsWeaponUsable(unit1, unit2->items[slot2]))
					return false;
	}

	if (!(unit2->flags & UNIT_FLAG_NOT_DEPLOYED)) {
		if (IsWeaponUsable(unit2, unit2->items[slot2]))
			if (CountUnitUsableWeapons(unit2) <= 1)
				if (!IsWeaponUsable(unit2, unit1->items[slot1]))
					return false;
	}

	return true;
}

bool CheckValidLinkArenaItemSupply(struct Unit *unit, int slot, int weapon)
{
	if (unit->flags & UNIT_FLAG_NOT_DEPLOYED)
		return true;

	if (IsWeaponUsable(unit, unit->items[slot]) == false)
		return true;

	if (CountUnitUsableWeapons(unit) != 1)
		return true;

	if (IsWeaponUsable(unit, weapon) != false)
		return true;

	return false;
}

bool PrepCanUnitPutItemToSupply(struct Unit *unit, int slot)
{
	if (unit->flags & UNIT_FLAG_NOT_DEPLOYED)
		return true;

	if (IsWeaponUsable(unit, unit->items[slot]) == false)
		return true;

	if (CountUnitUsableWeapons(unit) != 1)
		return true;

	return false;
}

void SetupPrepUiPalette(void)
{
	int i = 0;
	struct PlaySt *play_st = &gPlaySt;

	for (; i < 0x10; i++)
		gPrepUiPal[i] = gUnk_Ui_Pal_08321F24[play_st->config_window_theme * 0x10 + i];
}

ProcPtr func_fe6_08082CF4(ProcPtr parent)
{
	return SpawnProc(ProcScr_Prep_08679774, parent);
}

void func_fe6_08082D08(struct Proc_Prep_08679774 *proc, int unused_1, fu16 obpal)
{
	proc->vram = OBJ_VRAM0 + 0x6000;

	obpal = (obpal & 0xF) + 0x10;

	InitSpriteTextFont(&proc->font, (void *)proc->vram, (obpal));
	ApplyPalette(Pal_Text + 0x10, (obpal));
	InitSpriteText(&proc->text);
	SetTextFont(NULL);
	proc->oam2 = (((u32)proc->vram & 0xFFFF) >> 5) + OAM2_PAL(obpal);
}

int CONST_DATA Msgs_08679754[6] = {
	MSG_6BB, // ２人のユニットを選んでアイテムを交換します
	MSG_6BD, // いらなくなったアイテムを捨てます
	MSG_6BE, // 輸送隊が管理しているアイテムとのやりとりができます
	MSG_6BF, // 全員の持っているアイテムを見ることができます
	MSG_6C0, // 武器屋でアイテムの売買ができます
	MSG_6BC, // アイテムを交換する相手を選んでください
};

void func_fe6_08082D54(struct Proc_Prep_08679774 *proc, int msg_order_idx)
{
	SetTextFont(&proc->font);
	SpriteText_DrawBackgroundExt(&proc->text, 0);
	SetTextFontGlyphs(TEXT_GLYPHS_TALK);
	Text_SetColor(&proc->text, TEXT_COLOR_SYSTEM_WHITE);
	Text_SetCursor(&proc->text, 0);
	Text_DrawString(&proc->text, DecodeMsg(Msgs_08679754[msg_order_idx]));
	SetTextFont(NULL);
}

u16 CONST_DATA Sprite_Prep_0867976C[] = {
	1,
	OAM0_SHAPE_32x16 + OAM0_AFFINE_ENABLE, OAM1_SIZE_32x16 + OAM1_AFFINE_ID(1), OAM2_LAYER(3),
};

void func_fe6_08082DA4(struct Proc_Prep_08679774 *proc, int x, int y, u32 scale)
{
	int _y = y;
	u16 _scale;
	struct Proc_Prep_08679774 *_proc;
	scale <<= 16;
	scale >>= 16;
	_scale = scale;
	_proc = proc;

	if (scale >= 0x10) {
		int i;
		int tmp;

		y += 8;
		tmp = scale;
		_y = y - (tmp /= 32);

		SetObjAffineAuto(1, 0, 0x100, _scale);

		for (i = 0; i < 8; i++)
			PutSpriteExt(0xC, OAM1_X(x + i * 0x20), OAM1_X(_y) /* bug? */, Sprite_Prep_0867976C, _proc->oam2 + i * 4);
	}
}

struct ProcScr CONST_DATA ProcScr_Prep_08679774[] = {
	PROC_SLEEP(0),
	PROC_BLOCK,
	PROC_END
};
