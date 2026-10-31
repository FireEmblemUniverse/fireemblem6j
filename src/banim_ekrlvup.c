#include "prelude.h"
#include "proc.h"
#include "face.h"
#include "unit.h"
#include "battle.h"
#include "face.h"
#include "text.h"
#include "msg.h"
#include "oam.h"
#include "hardware.h"
#include "datamove.h"
#include "util.h"
#include "manim.h"
#include "constants/iids.h"
#include "constants/songs.h"
#include "constants/videoalloc_banim.h"
#include "constants/videoalloc_global.h"

#include "banim.h"
#include "banim_ekrdragon.h"

EWRAM_OVERLAY(banim) struct ProcEkrlvup *gpProcEkrLevelup = NULL;
EWRAM_OVERLAY(banim) u32 gUnk_Banim_0201F05C[8] = {};
EWRAM_OVERLAY(banim) ProcPtr gpProcEfxPartsofScroll = NULL;
EWRAM_OVERLAY(banim) ProcPtr gpProcEfxleveluphb = NULL;
EWRAM_OVERLAY(banim) struct EkrTerrainfxDesc gEkrLvupTerrainfxDesc = {};
EWRAM_OVERLAY(banim) struct Unit *gpEkrLvupUnit = NULL;
EWRAM_OVERLAY(banim) struct BattleUnit *gpEkrLvupBattleUnit = NULL;
EWRAM_OVERLAY(banim) u16 gEkrLvupPreLevel = 0;
EWRAM_OVERLAY(banim) u16 gEkrLvupPostLevel = 0;
EWRAM_OVERLAY(banim) u16 gEkrLvupBaseStatus[EKRLVUP_STAT_MAX] = {};
EWRAM_OVERLAY(banim) u16 gEkrLvupPostStatus[EKRLVUP_STAT_MAX] = {};
EWRAM_OVERLAY(banim) u16 gEkrLvupScrollPos1 = 0;
EWRAM_OVERLAY(banim) u16 gEkrLvupScrollPos2 = 0;

struct FaceVramEnt CONST_DATA FaceConfig_EkrLevelup[] = {
	[0] = { 0, 0xF },
	[1] = {0},
	[2] = {0},
	[3] = {0},
};

struct ProcScr CONST_DATA ProcScr_EkrLevelup[] = {
	PROC_NAME_DEBUG("ekrLevelup"),
	PROC_REPEAT(EkrLvup_Init),
	PROC_SLEEP(1),

	PROC_REPEAT(EkrLvup_InitLevelUpBox),
	PROC_REPEAT(EkrLvup_SetBgs),
	PROC_REPEAT(EkrLvup_InitPalette),
	PROC_REPEAT(EkrLvup_PutWindowOnScreen),
	PROC_REPEAT(EkrLvup_PrepareApGfx),
	PROC_SLEEP(20),

	PROC_REPEAT(EkrLvup_Promo_WindowScroll0),
	PROC_REPEAT(EkrLvup_Promo_DrawPromoNewClassName),
	PROC_REPEAT(EkrLvup_Promo_WindowScroll1),
	PROC_REPEAT(EkrLvup_DrawNewLevel),
	PROC_REPEAT(EkrLvup_InitCounterForMainAnim),
	PROC_REPEAT(EkrLvup_MainAnime),
	PROC_REPEAT(EkrLvup_SetHBlank),
	PROC_REPEAT(EkrLvup_DoNothing),
	PROC_REPEAT(EkrLvup_PutWindowOffScreen),
	PROC_REPEAT(EkrLvup_ResetScreen),
	PROC_REPEAT(EkrLvup_OnEnd),
	PROC_END,
};

bool CheckEkrLvupDone(void)
{
	if (gpProcEkrLevelup->finished == true)
		return true;
	else
		return false;
}

void EndEkrLevelUp(void)
{
	Proc_End(gpProcEkrLevelup);
}

const char EkrLvupMsgsStr[8][5] = {
	TEXT("ＨＰ", "hp"),
	TEXT("力",   "str"),
	TEXT("技",   "skl"),
	TEXT("速さ", "spd"),
	TEXT("幸運", "lck"),
	TEXT("守備", "def"),
	TEXT("魔防", "res"),
	TEXT("体格", "con")
};

const char EkrLvupMsgsMag[8][5] = {
	TEXT("ＨＰ", "hp"),
	TEXT("魔力",  "str"),
	TEXT("技",   "skl"),
	TEXT("速さ", "spd"),
	TEXT("幸運", "lck"),
	TEXT("守備", "def"),
	TEXT("魔防", "res"),
	TEXT("体格", "con")
};

const u16 sEfxLvupPartsPos[] = {
	TM_OFFSET(2, 11),
	TM_OFFSET(2, 13),
	TM_OFFSET(2, 15),
	TM_OFFSET(2, 17),

	TM_OFFSET(10, 11),
	TM_OFFSET(10, 13),
	TM_OFFSET(10, 15),
	TM_OFFSET(10, 17),
};

const char gMsg_Lv[] = TEXT("ＬＶ", "LV");

void EkrLvup_InitStatusText(struct ProcEkrlvup *proc)
{
	int i;
	struct BattleUnit *bunit, *bunit2;
	struct Unit *unit;
	struct Text *th;
	const char *str;

	if (proc->anim_this == NULL) {
		struct BattleUnit ** test;
		bunit2 = gpEkrBattleUnitLeft;
		gpEkrLvupUnit = unit = &bunit2->unit;
		test = &gpEkrBattleUnitRight;
		gpEkrLvupBattleUnit = (bunit = *test);
	} else {
		struct BattleUnit ** test;
		bunit2 = gpEkrBattleUnitRight;
		gpEkrLvupUnit = unit = &bunit2->unit;
		test = &gpEkrBattleUnitLeft;
		gpEkrLvupBattleUnit = (bunit = *test);
	}

	if (proc->is_promotion == false) {
		unit = GetUnit(unit->id);

		gEkrLvupPreLevel = bunit2->previous_level;
		gEkrLvupBaseStatus[EKRLVUP_STAT_HP] = unit->max_hp;
		gEkrLvupBaseStatus[EKRLVUP_STAT_POW] = unit->pow;
		gEkrLvupBaseStatus[EKRLVUP_STAT_SKL] = unit->skl;
		gEkrLvupBaseStatus[EKRLVUP_STAT_LCK] = unit->lck;
		gEkrLvupBaseStatus[EKRLVUP_STAT_SPD] = unit->spd;
		gEkrLvupBaseStatus[EKRLVUP_STAT_DEF] = unit->def;
		gEkrLvupBaseStatus[EKRLVUP_STAT_RES] = unit->res;
		gEkrLvupBaseStatus[EKRLVUP_STAT_CON] = unit->jinfo->base_con + unit->pinfo->bonus_con;
		gEkrLvupPostLevel = bunit2->previous_level + 1;

		gEkrLvupPostStatus[EKRLVUP_STAT_HP] = unit->max_hp + bunit2->change_hp;
		gEkrLvupPostStatus[EKRLVUP_STAT_POW] = unit->pow + bunit2->change_pow;
		gEkrLvupPostStatus[EKRLVUP_STAT_SKL] = unit->skl + bunit2->change_skl;
		gEkrLvupPostStatus[EKRLVUP_STAT_LCK] = unit->lck + bunit2->change_lck;
		gEkrLvupPostStatus[EKRLVUP_STAT_SPD] = unit->spd + bunit2->change_spd;
		gEkrLvupPostStatus[EKRLVUP_STAT_DEF] = unit->def + bunit2->change_def;
		gEkrLvupPostStatus[EKRLVUP_STAT_RES] = unit->res + bunit2->change_res;
		gEkrLvupPostStatus[EKRLVUP_STAT_CON] = unit->jinfo->base_con + unit->pinfo->bonus_con + bunit2->change_con;
	} else {
		gEkrLvupPreLevel = unit->level;
		gEkrLvupBaseStatus[EKRLVUP_STAT_HP] = unit->max_hp;
		gEkrLvupBaseStatus[EKRLVUP_STAT_POW] = unit->pow;
		gEkrLvupBaseStatus[EKRLVUP_STAT_SKL] = unit->skl;
		gEkrLvupBaseStatus[EKRLVUP_STAT_LCK] = unit->lck;
		gEkrLvupBaseStatus[EKRLVUP_STAT_SPD] = unit->spd;
		gEkrLvupBaseStatus[EKRLVUP_STAT_DEF] = unit->def;
		gEkrLvupBaseStatus[EKRLVUP_STAT_RES] = unit->res;
		gEkrLvupBaseStatus[EKRLVUP_STAT_CON] = unit->jinfo->base_con + unit->pinfo->bonus_con;
		gEkrLvupPostLevel = 1;

		gEkrLvupPostStatus[EKRLVUP_STAT_HP] = bunit->unit.max_hp;
		gEkrLvupPostStatus[EKRLVUP_STAT_POW] = bunit->unit.pow;
		gEkrLvupPostStatus[EKRLVUP_STAT_SKL] = bunit->unit.skl;
		gEkrLvupPostStatus[EKRLVUP_STAT_LCK] = bunit->unit.lck;
		gEkrLvupPostStatus[EKRLVUP_STAT_SPD] = bunit->unit.spd;
		gEkrLvupPostStatus[EKRLVUP_STAT_DEF] = bunit->unit.def;
		gEkrLvupPostStatus[EKRLVUP_STAT_RES] = bunit->unit.res;
		gEkrLvupPostStatus[EKRLVUP_STAT_CON] = bunit->unit.jinfo->base_con + bunit->unit.pinfo->bonus_con;
	}

	InitTextFont(&gBanimFont, (u8 *)BG_VRAM + VRAMOFF_BG_EKRLVUP_FONT, VRAMOFF_BG_EKRLVUP_FONT / 0x20, 0);

	for (i = 0; i < EKRLVUP_STAT_MAX; i++) {
		int text_x;

		if (!UnitKnowsMagic(unit))
			str = EkrLvupMsgsStr[i];
		else
			str = EkrLvupMsgsMag[i];

		InitText(&gBanimText[i], 3);
		text_x = GetStringTextLen(str);
		text_x = (0x10 - text_x) >> 1;
		if (text_x < 0)
			text_x = 0;

		Text_SetCursor(&gBanimText[i], text_x);
		Text_SetColor(&gBanimText[i], TEXT_COLOR_SYSTEM_GOLD);
		Text_DrawString(&gBanimText[i], str);
		PutText(&gBanimText[i], gBg2Tm + sEfxLvupPartsPos[i]);
	}

	for (i = 0; i < EKRLVUP_STAT_MAX; i++) {
		InitText(&gBanimText[EKRLVUP_STAT_MAX + i], 2);
		Text_SetCursor(&gBanimText[EKRLVUP_STAT_MAX + i], 8);
		Text_SetColor(&gBanimText[EKRLVUP_STAT_MAX + i], TEXT_COLOR_SYSTEM_BLUE);
		Text_DrawNumber(&gBanimText[EKRLVUP_STAT_MAX + i], gEkrLvupBaseStatus[i]);
		PutText(&gBanimText[EKRLVUP_STAT_MAX + i], gBg2Tm + 3 + sEfxLvupPartsPos[i]);
	}

	/* class */
	th = &gBanimText[EKRLVUP_STAT_MAX + EKRLVUP_STAT_CLASS];
	InitText(th, 8);
	Text_DrawString(th,
		DecodeMsg(gpEkrLvupUnit->jinfo->msg_name));
	PutText(th, gBg2Tm + TM_OFFSET(2, 7));

	/* level msg */
	th = &gBanimText[EKRLVUP_STAT_MAX + EKRLVUP_STAT_LV_MSG];
	InitText(th, 3);
	Text_SetColor(th, TEXT_COLOR_SYSTEM_GOLD);
	Text_DrawString(th, gMsg_Lv);
	PutText(th, gBg2Tm + TM_OFFSET(10, 7));

	/* level value */
	th = &gBanimText[EKRLVUP_STAT_MAX + EKRLVUP_STAT_LV_VAL];
	InitText(th, 2);
	Text_SetCursor(th, 8);
	Text_SetColor(th, TEXT_COLOR_SYSTEM_BLUE);
	Text_DrawNumber(th, gEkrLvupPreLevel);
	PutText(th, gBg2Tm + TM_OFFSET(13, 7));
}

void Ekrlvup_PutBaseStatus(struct ProcEkrlvup *proc, int index)
{
	struct Text *text = &gBanimText[EKRLVUP_STAT_CLASS + index];

	ClearText(text);
	Text_SetCursor(text, 8);
	Text_SetColor(text, TEXT_COLOR_SYSTEM_BLUE);
	Text_DrawNumber(text, gEkrLvupBaseStatus[index]);
	PutText(text, gBg2Tm + TM_OFFSET(3, 0) + sEfxLvupPartsPos[index]);
}

void Ekrlvup_PutJobname(struct ProcEkrlvup *proc)
{
	struct Text *text = &gBanimText[EKRLVUP_TEXT_16];

	ClearText(text);
	Text_DrawString(text, DecodeMsg(gpEkrLvupUnit->jinfo->msg_name));
	PutText(text, gBg2Tm + TM_OFFSET(2, 7));
}

void Ekrlvup_PutPreLevel(struct ProcEkrlvup *proc)
{
	struct Text *text = &gBanimText[EKRLVUP_TEXT_18];

	ClearText(text);
	Text_SetCursor(text, 8);
	Text_SetColor(text, TEXT_COLOR_SYSTEM_BLUE);
	Text_DrawNumber(text, gEkrLvupPreLevel);
	PutText(text, gBg2Tm + TM_OFFSET(13, 7));
}

void NewEkrLevelup(struct Anim *anim)
{
	struct ProcEkrlvup *proc;

	gpProcEkrLevelup = proc = SpawnProc(ProcScr_EkrLevelup, PROC_TREE_3);
	proc->anim_this = anim;
	proc->anim_other = GetAnimAnotherSide(anim);
	proc->timer = 0;
	proc->finished = false;

	if (gEkrDistanceType != EKR_DISTANCE_PROMOTION)
		proc->is_promotion = false;
	else
		proc->is_promotion = true;
}

void EkrLvup_Init(struct ProcEkrlvup *proc)
{
	struct EkrTerrainfxDesc *desc = &gEkrLvupTerrainfxDesc;

	CpuFastFill(0, gBg1Tm, 0x800);
	CpuFastFill(0, gBg2Tm, 0x800);

	RegisterDataMove(gBg1Tm, (u8 *)BG_VRAM + VRAMOFF_BANIM_6800, 0x800);
	RegisterDataMove(gBg1Tm, (u8 *)BG_VRAM + VRAMOFF_BANIM_7000, 0x800);
	RegisterDataMove(gBg2Tm, (u8 *)BG_VRAM + VRAMOFF_BANIM_5000, 0x800);
	RegisterDataMove(gBg2Tm, (u8 *)BG_VRAM + VRAMOFF_BANIM_5800, 0x800);

	desc->terrain_l = gBanimFloorfx[POS_L];
	desc->pal_l = OBPAL_EFX_FACE;
	desc->chr_l = VRAMOFF_OBJ_2000 / CHR_SIZE;
	desc->terrain_r = gBanimFloorfx[POS_R];
	desc->pal_r = OBPAL_EFX_4;
	desc->chr_r = VRAMOFF_OBJ_2800 / CHR_SIZE;
	desc->distance = gEkrDistanceType;
	desc->bg_index = -1;
	desc->vram_offset = (int)OBJ_VRAM0; // bug?
	desc->img_buf = (u8 *)gBanimTerrainfxBufObj;
	desc->unk_10 = (u16)gEkrSnowWeather;

	if (gEkrDistanceType == EKR_DISTANCE_FARFAR) {
		if (gEkrInitPosReal == POS_L)
			desc->terrain_r = -1;
		else
			desc->terrain_l = -1;
	}

	if (GetBattleAnimArenaFlag() == false) {
		struct ProcEkrSubAnimeEmulator *emu;

		NewEkrTerrainfx(desc);

		emu = desc->proc1;
		emu->oam2 &= (u16)~OAM2_LAYER(0x3);
		emu->oam2 |=       OAM2_LAYER(0x3);

		emu = desc->proc2;
		emu->oam2 &= (u16)~OAM2_LAYER(0x3);
		emu->oam2 |=       OAM2_LAYER(0x3);
	}

	proc->anim_this->oam2  &= ~OAM2_LAYER(0x3);
	proc->anim_this->oam2  |=  OAM2_LAYER(0x3);
	proc->anim_other->oam2 &= ~OAM2_LAYER(0x3);
	proc->anim_other->oam2 |=  OAM2_LAYER(0x3);

	gDispIo.bg2_ct.priority = 0;
	gDispIo.bg1_ct.priority = 1;
	gDispIo.bg0_ct.priority = 2;
	gDispIo.bg3_ct.priority = 3;

	if (*GetEkrDragonWeapon(POS_L) == IID_FIRESTONE) {
		proc->anim_other->oam2 &= ~OAM2_LAYER(0x3);
		proc->anim_other->oam2 |=  OAM2_LAYER(0x2);

		gDispIo.bg0_ct.priority = 2;
		gDispIo.bg1_ct.priority = 1;
		gDispIo.bg2_ct.priority = 0;
		gDispIo.bg3_ct.priority = 2;
	}

	gEkrLvupScrollPos1 = 0x90;
	gEkrLvupScrollPos2 = 0x90;

	SetBgOffset(BG_2, 0, 8);
	SetBgOffset(BG_1, 0, 8);

	SetBgTilemapOffset(BG_0, 0x6000);
	SetBgTilemapOffset(BG_1, 0x6800);
	SetBgTilemapOffset(BG_2, 0x5000);

	SetBgScreenSize(BG_1, 1);
	SetBgScreenSize(BG_2, 1);

	gpProcEfxPartsofScroll = NewEfxPartsofScroll();
	gpProcEfxleveluphb = NewEfxleveluphb();

	EfxPartsofScroll_LoopExt();
	EkrGauge_Setup44(2);
	DisableEfxStatusUnits(proc->anim_this);
	DisableEfxStatusUnits(proc->anim_other);
	DisableEfxWeaponIcon();
	DisableEfxHpBarColorChange();

	SetWinEnable(0, 0, 0);
	SetBlendNone();
	Proc_Break(proc);
}

void EkrLvup_InitLevelUpBox(struct ProcEkrlvup *proc)
{
	int fid;
	struct BattleUnit *bu1 = gpEkrBattleUnitLeft;
	struct BattleUnit *bu2 = gpEkrBattleUnitRight;
	struct Anim *anim = proc->anim_this;

	LZ77UnCompWram(Img_LevelUpFrame, gSpellAnimBgfx);
	LZ77UnCompWram(Tm_LevelUpFrame, gEkrTsaBuffer);
	EfxTmCpyBG(gEkrTsaBuffer, gBg1Tm + TM_OFFSET(0, 0x6),
		0x20, 0x14, BGPAL_EFX_SPELL_BG, OAM2_CHR(VRAMOFF_BANIM_SPELL_BG / CHR_SIZE));
	RegisterDataMove(gSpellAnimBgfx, (void *)BG_VRAM + VRAMOFF_BANIM_SPELL_BG, 0x400);
	CpuFastCopy(Pal_LevelUpFrame, PAL_BG(BGPAL_EFX_SPELL_BG), 0x20);
	LZ77UnCompWram(Img_LvupApfx, gBuf_Banim);
	RegisterDataMove(gBuf_Banim, OBJ_VRAM0 + VRAMOFF_OBJ_1400, 0xC00);
	CpuFastCopy(Pal_LvupApfx, PAL_OBJ(OBPAL_EFX_SPELL_BG), 0x20);
	EnablePalSync();

	if (proc->is_promotion == false) {
		struct ProcEkrSubAnimeEmulator *child;

		child = NewEkrlvupSubAnimeEmulator(
			anim->xPosition, 0x30, AnimScr_EkrlvupfxUnk_085CCC40, EKR_SUBANIMEMU_ACT_ONE_TURN);
		child->oam2 = OAM2_PAL(OBPAL_EFX_SPELL_BG) + OAM2_CHR(VRAMOFF_OBJ_1400 / CHR_SIZE);
		proc->timer = 0;
	} else
		proc->timer = EKR_LVUP_UI_BASE;

	if (GetAnimPosition(anim) == POS_L)
		fid = bu1->unit.pinfo->fid;
	else
		fid = bu2->unit.pinfo->fid;

	SetFaceConfig(FaceConfig_EkrLevelup);
	StartFace(0, fid, 0xBC, EKR_LVUP_UI_BASE, 0x42);
	gFaces[0]->y_disp = 0xA0;

	CpuFastFill16(0, gBg2Tm, 0x800);
	EkrLvup_InitStatusText(proc);
	Proc_Break(proc);
}

void EkrLvup_SetBgs(struct ProcEkrlvup *proc)
{
	SetOnHBlankA(EkrLvupHBlank);

	EnableBgSync(BG0_SYNC_BIT);
	EnableBgSync(BG2_SYNC_BIT);
	EnableBgSync(BG1_SYNC_BIT);
	EnablePalSync();

	Proc_Break(proc);
}

void EkrLvup_InitPalette(struct ProcEkrlvup *proc)
{
	if (++proc->timer > EKR_LVUP_UI_BASE) {

		proc->timer = 0;

		proc->scroll_timer[0] = 0;
		proc->scroll_timer[1] = 0;
		proc->scroll_timer[2] = -2;
		proc->scroll_timer[3] = -4;

		CpuFastCopy(PAL_BG(0), gEfxPal, 0x400);

		Proc_Break(proc);
	}
}

void EkrLvup_PutWindowOnScreen(struct ProcEkrlvup *proc)
{
	int a, b, c, d, pos, pal;

	a = proc->scroll_timer[0];
	b = proc->scroll_timer[1];
	c = proc->scroll_timer[2];
	d = proc->scroll_timer[3];

	LIMIT_AREA2(a, 0, 8);
	LIMIT_AREA2(b, 0, 8);
	LIMIT_AREA2(c, 0, 8);
	LIMIT_AREA2(d, 0, 8);

	proc->scroll_timer[0]++;
	proc->scroll_timer[1]++;
	proc->scroll_timer[2]++;
	proc->scroll_timer[3]++;

	pos = Interpolate(INTERPOLATE_LINEAR, -EKR_LVUP_UI_BASE, 0, a, 8);
	pal = Interpolate(INTERPOLATE_LINEAR, 0, 8, b, 8);

	gEkrLvupScrollPos1 = Interpolate(INTERPOLATE_LINEAR, 0x90, 0, c, 8);
	gEkrLvupScrollPos2 = Interpolate(INTERPOLATE_LINEAR, 0x90, 0, d, 8);

	gFaces[0]->y_disp = EKR_LVUP_UI_BASE - pos;

	CpuFastCopy(gEfxPal, PAL_BG(0), 0x400);
	EfxPalBlackInOut(PAL_BG(0), 2, 4, pal);
	EfxPalBlackInOut(PAL_BG(0), 0x13, 0xC, pal);
	EnablePalSync();

	if (++proc->timer > 0x14) {
		proc->timer = 0;
		Proc_Break(proc);
	}
}

void EkrLvup_PrepareApGfx(struct ProcEkrlvup *proc)
{
	int i;

	StartManimLevelUpStatGainLabels(
		OAM2_CHR(VRAMOFF_OBJ_1400 / CHR_SIZE), OBPAL_EFX_SPELL_BG, 1, PROC_TREE_3);

	Proc_Break(proc);

	for (i = 0; i < 8; i++)
		gUnk_Banim_0201F05C[i] = 0;
}

void EkrLvup_Promo_WindowScroll0(struct ProcEkrlvup *proc)
{
	if (proc->is_promotion == false) {
		Proc_Break(proc);
		return;
	}

	SetOnHBlankA(EfxPartsofScroll2HBlank);

	Proc_End(gpProcEfxPartsofScroll);
	gpProcEfxPartsofScroll = NewEfxPartsofScroll2();

	EfxPlaySE(SONG_76, 0x100);
	M4aPlayWithPostionCtrl(SONG_76, 0x38, 0);
	
	proc->timer = 0;
	proc->index = 8;
	Proc_Break(proc);
}

void EkrLvup_Promo_DrawPromoNewClassName(struct ProcEkrlvup *proc)
{
	if (proc->is_promotion == false) {
		Proc_Break(proc);
		return;
	}

	gEkrLvupScrollPos1 = Interpolate(1, 0, 0x1000, proc->timer, proc->index);

	if (++proc->timer > proc->index) {
		gpEkrLvupUnit = &gpEkrLvupBattleUnit->unit;
		Ekrlvup_PutJobname(proc);

		gEkrLvupPreLevel = gEkrLvupPostLevel;
		Ekrlvup_PutPreLevel(proc);

		proc->timer = 0;
		proc->index = 8;

		Proc_Break(proc);
	}
}

void EkrLvup_Promo_WindowScroll1(struct ProcEkrlvup *proc)
{
	if (proc->is_promotion == false) {
		Proc_Break(proc);
		return;
	}

	gEkrLvupScrollPos1 = Interpolate(4, 0x1000, 0, proc->timer, proc->index);
	if (++proc->timer > proc->index)
		Proc_Break(proc);
}

void EkrLvup_DrawNewLevel(struct ProcEkrlvup *proc)
{
	if (proc->is_promotion == false) {
		proc->timer = 0;
		StartManimLevelUpStatGainLabelAnim(0x84, 0x3C, 0, 0);
		gEkrLvupPreLevel = gEkrLvupPostLevel;
		Ekrlvup_PutPreLevel(proc);
		EfxPlaySE(SONG_76, 0x100);
		M4aPlayWithPostionCtrl(SONG_76, 0x38, 0);
		Proc_Break(proc);
		return;
	}

	Proc_End(gpProcEfxPartsofScroll);
	gpProcEfxPartsofScroll = NewEfxPartsofScroll();
	proc->timer = 0;
	proc->index = 0;
	Proc_Break(proc);
}

void EkrLvup_InitCounterForMainAnim(struct ProcEkrlvup *proc)
{
	if (proc->is_promotion != false) {
		Proc_Break(proc);
		return;
	}

	if (++proc->timer < 0x1E) {
		proc->timer = 0;
		proc->index = 0;
		Proc_Break(proc);
	}
}

void EkrLvup_MainAnime(struct ProcEkrlvup *proc)
{
	int base, diff;
	s16 stat_index;

	if (++proc->timer == 0x14) {
		proc->timer = 0;

		for (; proc->index != EKRLVUP_STAT_MAX; proc->index++) {
			base = gEkrLvupBaseStatus[proc->index];
			diff = gEkrLvupPostStatus[proc->index] - base;

			if (diff != 0) {
				gEkrLvupBaseStatus[proc->index] = gEkrLvupPostStatus[proc->index];
				Ekrlvup_PutBaseStatus(proc, proc->index);
				EfxPlaySE(SONG_76, 0x100);
				M4aPlayWithPostionCtrl(SONG_76, 0x38, 0);

				StartManimLevelUpStatGainLabelAnim(
					0x35 + (sEfxLvupPartsPos[proc->index] & 0x1F) * 8,
					6 + (sEfxLvupPartsPos[proc->index] & 0x7E0) / 4,
					proc->index + 1,
					diff);

				if (proc->index == EKRLVUP_STAT_HP) {
					gBanimMaxHP[1] = gEkrLvupBaseStatus[proc->index];
					gEkrGaugeHpBak[1] = -1;
				}
				proc->timer = 0;
				break;
			}
		}
	}

	if (proc->index == EKRLVUP_STAT_MAX) {
		proc->timer = 0;
		Proc_Break(proc);
	}
}

void EkrLvup_SetHBlank(struct ProcEkrlvup *proc)
{
	if (++proc->timer > 0x3B) {
		proc->timer = 0;
		EndManimLevelUpStatGainLabels();
		SetOnHBlankA(EkrLvupHBlank);
		Proc_Break(proc);
	}
}

void EkrLvup_DoNothing(struct ProcEkrlvup *proc)
{
	Proc_Break(proc);
}

void EkrLvup_PutWindowOffScreen(struct ProcEkrlvup *proc)
{
	int i, pos, pal;

	gEkrLvupScrollPos1 = Interpolate(INTERPOLATE_LINEAR, 0, 0x90, proc->timer, 8);
	gEkrLvupScrollPos2 = Interpolate(INTERPOLATE_LINEAR, 0, 0x90, proc->timer, 8);

	pos = Interpolate(INTERPOLATE_LINEAR, 0, -EKR_LVUP_UI_BASE, proc->timer, 8);
	pal = Interpolate(INTERPOLATE_LINEAR, 8, 0, proc->timer, 8);

	gFaces[0]->y_disp = EKR_LVUP_UI_BASE - pos;

	CpuFastCopy(gEfxPal, PAL_BG(0), 0x400);
	EfxPalBlackInOut(PAL_BG(0), 2, 4, pal);
	EfxPalBlackInOut(PAL_BG(0), 0x13, 0xC, pal);
	EnablePalSync();

	/* Maybe some debug routine? */
	for (i = 0; i < 8; i++)
		;

	if (++proc->timer > 8) {
		proc->timer = 0;
		Proc_Break(proc);
	}
}

void EkrLvup_ResetScreen(struct ProcEkrlvup *proc)
{
	struct EkrTerrainfxDesc *buf;
	struct EkrTerrainfxDesc _buf;

	buf = &gEkrLvupTerrainfxDesc;

	if (GetBattleAnimArenaFlag() == false)
		EndEkrTerrainfx(buf);

	SetBgTilemapOffset(0, 0x6000);
	SetBgTilemapOffset(1, 0x6800);
	SetBgTilemapOffset(2, 0x7000);

	SetBgScreenSize(1, 0);
	SetBgScreenSize(2, 0);

	buf = &_buf;

	buf->terrain_l = gBanimFloorfx[0];
	buf->pal_l = OBPAL_EFX_4;
	buf->chr_l = VRAMOFF_OBJ_5000 / CHR_SIZE;
	buf->terrain_r = gBanimFloorfx[1];
	buf->pal_r = OBPAL_EFX_5;
	buf->chr_r = VRAMOFF_OBJ_5000 / CHR_SIZE;
	buf->distance = gEkrDistanceType;
	buf->bg_index = BG_2;
	buf->vram_offset = 0;
	buf->img_buf = gBanimTerrainfxBufObj;
	buf->unk_10 = gEkrSnowWeather;

	if (GetBattleAnimArenaFlag() == false) {
		SetBgOffset(2, 0, 0);
		NewEkrTerrainfx(&_buf);
	}

	proc->anim_this->oam2 &= ~OAM2_LAYER(0x3);
	proc->anim_this->oam2 |=  OAM2_LAYER(0x2);
	proc->anim_other->oam2 &= ~OAM2_LAYER(0x3);
	proc->anim_other->oam2 |=  OAM2_LAYER(0x2);

	CpuFastFill(0, gBg1Tm, 0x800);
	EnableBgSync(BG1_SYNC_BIT);
	EkrGauge_Setup44(0);

	if (*GetEkrDragonWeapon(POS_L) == IID_FIRESTONE) {
		gDispIo.bg0_ct.priority = 0;
		gDispIo.bg1_ct.priority = 1;
		gDispIo.bg3_ct.priority = 2;
		gDispIo.bg2_ct.priority = 3;
	} else {
		gDispIo.bg0_ct.priority = 0;
		gDispIo.bg1_ct.priority = 1;
		gDispIo.bg2_ct.priority = 2;
		gDispIo.bg3_ct.priority = 3;
	}

	EndFaceById(0);
	Proc_Break(proc);
}

void EkrLvup_OnEnd(struct ProcEkrlvup *proc)
{
	Proc_End(gpProcEfxPartsofScroll);
	Proc_End(gpProcEfxleveluphb);

	EnableEfxStatusUnits(proc->anim_this);
	EnableEfxStatusUnits(proc->anim_other);
	EnableEfxWeaponIcon();
	EnableEfxHpBarColorChange();
	proc->finished = true;
}
