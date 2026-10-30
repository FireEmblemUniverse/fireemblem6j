#include "prelude.h"
#include "proc.h"
#include "faction.h"
#include "item.h"
#include "util.h"
#include "augury.h"
#include "oam.h"
#include "msg.h"
#include "ui.h"
#include "armfunc.h"
#include "sprite.h"
#include "save_stats.h"
#include "save_xmap.h"
#include "secretscreen.h"
#include "gamecontroller.h"
#include "chapterinfo.h"
#include "constants/chapters.h"
#include "constants/msg.h"

#include "playrank.h"

// 0x868B1B0
CONST_DATA struct HelpBoxInfo HelpInfo_StatusScreen = {
	.adjacent_down =  &HelpInfo_0868B204,
	.adjacent_right = &HelpInfo_0868B1CC,
	.x = 0x08,
	.y = 0x29,
	.msg = MSG_6A1,
};

// 0x868B1CC
CONST_DATA struct HelpBoxInfo HelpInfo_0868B1CC = {
	.adjacent_down =  &HelpInfo_0868B1E8,
	.adjacent_left =  &HelpInfo_StatusScreen,
	.x = 0x8D,
	.y = 0x20,
	.msg = MSG_69D,
};

// 0x868B1E8
CONST_DATA struct HelpBoxInfo HelpInfo_0868B1E8 = {
	.adjacent_up =    &HelpInfo_0868B1CC,
	.adjacent_down =  &HelpInfo_0868B274,
	.adjacent_left =  &HelpInfo_StatusScreen,
	.x = 0x8D,
	.y = 0x30,
	.msg = MSG_6A2,
};

// 0x868B204
CONST_DATA struct HelpBoxInfo HelpInfo_0868B204 = {
	.adjacent_up =    &HelpInfo_StatusScreen,
	.adjacent_down =  &HelpInfo_0868B220,
	.adjacent_right = &HelpInfo_0868B23C,
	.x = 0x3C,
	.y = 0x48,
	.msg = MSG_69E,
};

// 0x868B220
CONST_DATA struct HelpBoxInfo HelpInfo_0868B220 = {
	.adjacent_up =    &HelpInfo_0868B204,
	.adjacent_down =  &HelpInfo_0868B2AC,
	.adjacent_right = &HelpInfo_0868B258,
	.x = 0x3C,
	.y = 0x68,
	.msg = MSG_69E,
};

// 0x868B23C
CONST_DATA struct HelpBoxInfo HelpInfo_0868B23C = {
	.adjacent_up =    &HelpInfo_0868B1E8,
	.adjacent_down =  &HelpInfo_0868B258,
	.adjacent_left =  &HelpInfo_0868B204,
	.adjacent_right = &HelpInfo_0868B274,
	.x = 0x7A,
	.y = 0x48,
	.msg = MSG_69F,
};

// 0x868B258
CONST_DATA struct HelpBoxInfo HelpInfo_0868B258 = {
	.adjacent_up =    &HelpInfo_0868B23C,
	.adjacent_down =  &HelpInfo_0868B2AC,
	.adjacent_left =  &HelpInfo_0868B220,
	.adjacent_right = &HelpInfo_0868B290,
	.x = 0x7A,
	.y = 0x68,
	.msg = MSG_69F,
};

// 0x868B274
CONST_DATA struct HelpBoxInfo HelpInfo_0868B274 = {
	.adjacent_up =    &HelpInfo_0868B1E8,
	.adjacent_down =  &HelpInfo_0868B290,
	.adjacent_left =  &HelpInfo_0868B23C,
	.x = 0x9C,
	.y = 0x48,
	.msg = MSG_6A0,
};

// 0x868B290
CONST_DATA struct HelpBoxInfo HelpInfo_0868B290 = {
	.adjacent_up =    &HelpInfo_0868B274,
	.adjacent_down =  &HelpInfo_0868B2AC,
	.adjacent_left =  &HelpInfo_0868B258,
	.x = 0x9C,
	.y = 0x68,
	.msg = MSG_6A0,
};

// 0x868B2AC
CONST_DATA struct HelpBoxInfo HelpInfo_0868B2AC = {
	.adjacent_up =    &HelpInfo_0868B290,
	.adjacent_left =  &HelpInfo_0868B258,
	.x = 0x9C,
	.y = 0x88,
	.msg = MSG_69C,
};

// 0x868B2C8
CONST_DATA struct HelpBoxInfo HelpInfo_StatusScreenExtraMap = {
	.adjacent_down =  &HelpInfo_0868B300,
	.adjacent_right = &HelpInfo_0868B2E4,
	.x = 0x08,
	.y = 0x31,
	.msg = MSG_6A1,
};

// 0x868B2E4
CONST_DATA struct HelpBoxInfo HelpInfo_0868B2E4 = {
	.adjacent_down =  &HelpInfo_0868B370,
	.adjacent_left =  &HelpInfo_StatusScreenExtraMap,
	.x = 0xA5,
	.y = 0x30,
	.msg = MSG_69D,
};

// 0x868B300
CONST_DATA struct HelpBoxInfo HelpInfo_0868B300 = {
	.adjacent_up =    &HelpInfo_StatusScreenExtraMap,
	.adjacent_down =  &HelpInfo_0868B31C,
	.adjacent_right = &HelpInfo_0868B338,
	.x = 0x3C,
	.y = 0x48,
	.msg = MSG_69E,
};

// 0x868B31C
CONST_DATA struct HelpBoxInfo HelpInfo_0868B31C = {
	.adjacent_up =    &HelpInfo_0868B300,
	.adjacent_down =  &HelpInfo_0868B3A8,
	.adjacent_right = &HelpInfo_0868B354,
	.x = 0x3C,
	.y = 0x68,
	.msg = MSG_69E,
};

// 0x868B338
CONST_DATA struct HelpBoxInfo HelpInfo_0868B338 = {
	.adjacent_up =    &HelpInfo_0868B2E4,
	.adjacent_down =  &HelpInfo_0868B354,
	.adjacent_left =  &HelpInfo_0868B300,
	.adjacent_right = &HelpInfo_0868B370,
	.x = 0x7A,
	.y = 0x48,
	.msg = MSG_69F,
};

// 0x868B354
CONST_DATA struct HelpBoxInfo HelpInfo_0868B354 = {
	.adjacent_up =    &HelpInfo_0868B338,
	.adjacent_down =  &HelpInfo_0868B3A8,
	.adjacent_left =  &HelpInfo_0868B31C,
	.adjacent_right = &HelpInfo_0868B38C,
	.x = 0x7A,
	.y = 0x68,
	.msg = MSG_69F,
};

// 0x868B370
CONST_DATA struct HelpBoxInfo HelpInfo_0868B370 = {
	.adjacent_up =    &HelpInfo_0868B2E4,
	.adjacent_down =  &HelpInfo_0868B38C,
	.adjacent_left =  &HelpInfo_0868B338,
	.x = 0x9C,
	.y = 0x48,
	.msg = MSG_6A0,
};

// 0x868B38C
CONST_DATA struct HelpBoxInfo HelpInfo_0868B38C = {
	.adjacent_up =    &HelpInfo_0868B370,
	.adjacent_down =  &HelpInfo_0868B3A8,
	.adjacent_left =  &HelpInfo_0868B354,
	.x = 0x9C,
	.y = 0x68,
	.msg = MSG_6A0,
};

// 0x868B3A8
CONST_DATA struct HelpBoxInfo HelpInfo_0868B3A8 = {
	.adjacent_up =    &HelpInfo_0868B38C,
	.adjacent_left =  &HelpInfo_0868B354,
	.x = 0x9C,
	.y = 0x88,
	.msg = MSG_69C,
};

// 0x868B3C4
CONST_DATA struct HelpBoxInfo HelpInfo_StatusScreenExtraMapInfo = {
	.adjacent_right = &HelpInfo_0868B3E0,
	.x = 0x08,
	.y = 0x31,
	.msg = MSG_6A1,
};

// 0x868B3E0
CONST_DATA struct HelpBoxInfo HelpInfo_0868B3E0 = {
	.adjacent_left =  &HelpInfo_StatusScreenExtraMapInfo,
	.x = 0xA5,
	.y = 0x30,
	.msg = MSG_69D,
};

CONST_DATA struct PlayRankSt *gpPlayRankSt = (void *)gBuf;

u16 CONST_DATA Sprite_0868B400[] =
{
	1,
	OAM0_SHAPE_16x16, OAM1_SIZE_16x16, 0,
};

u16 CONST_DATA Sprite_0868B408[] =
{
	1,
	OAM0_SHAPE_32x16, OAM1_SIZE_32x16 + OAM1_X(504), 0,
};

u16 CONST_DATA Sprite_0868B410[] =
{
	1,
	OAM0_SHAPE_16x32, OAM1_SIZE_16x32, 0,
};

u16 CONST_DATA Sprite_0868B418[] =
{
	1,
	OAM0_SHAPE_32x32, OAM1_SIZE_32x32, 0,
};

CONST_DATA struct TotalPlayRankConf gTotalPlayRankConf1[] = {
	{ MSG_71D, TEXT_COLOR_SYSTEM_WHITE, PlayRankGetter_Tactics, 5,  6 },
	{ MSG_71E, TEXT_COLOR_SYSTEM_WHITE, PlayRankGetter_Combat, 18, 6 },
	{ MSG_71F, TEXT_COLOR_SYSTEM_WHITE, PlayRankGetter_Survival, 5,  8 },
	{ MSG_720, TEXT_COLOR_SYSTEM_WHITE, PlayRankGetter_Experience, 18, 8 },
	{ MSG_721, TEXT_COLOR_SYSTEM_WHITE, PlayRankGetter_Asset, 5,  10 },
	{ MSG_722, TEXT_COLOR_SYSTEM_WHITE, PlayRankGetter_Power, 18, 10 },
	{ MSG_723, TEXT_COLOR_SYSTEM_GREEN, NULL, 5, 13 }
};

CONST_DATA struct TotalPlayRankConf gTotalPlayRankConf2[] = {
	{ MSG_71D, TEXT_COLOR_SYSTEM_WHITE, PlayRankGetter_XmapTactics, 5,  10 },
	{ MSG_71F, TEXT_COLOR_SYSTEM_WHITE, PlayRankGetter_XmapSurvival, 18, 10 },
	{ MSG_71E, TEXT_COLOR_SYSTEM_WHITE, PlayRankGetter_XmapCombat, 5,  13 },
	{ MSG_723, TEXT_COLOR_SYSTEM_GREEN, NULL, 18, 13 }
};

CONST_DATA struct UnkStruct_0868B4D0 Objs_0868B4D0[] = {
	{ Sprite_0868B400, 2 },
	{ Sprite_0868B400, 1 },
	{ Sprite_0868B400, 1 },
	{ Sprite_0868B400, 0 },
	{ Sprite_0868B400, 0 },
	{ Sprite_0868B400, 0 },
	{ Sprite_0868B408, 0 },
};

CONST_DATA struct UnkStruct_0868b508 Unk_0868B508[] = {
	{ 0x00, 0x10, 0x01, 0x00 },
	{ 0x02, 0x14, 0x01, 0x00 },
	{ 0x04, 0x15, 0x01, 0x00 },
	{ 0x06, 0x10, 0x01, 0x00 },
	{ 0x08, 0x11, 0x01, 0x00 },
	{ 0x0A, 0x1A, 0x01, 0x00 },
	{ 0x0A, 0x14, 0x01, 0x00 },
	{ 0x04, 0x17, 0x01, 0x00 },
	{ 0x0C, 0x15, 0x01, 0x00 },
	{ 0x0E, 0x12, 0x01, 0x00 },
	{ 0xFF, 0x00, 0x00, 0x00 },
};

CONST_DATA struct UnkStruct_0868b508 Unk_0868B534[] = {
	{ 0x00, 0x18, 0x01, 0x00 },
	{ 0x06, 0x09, 0x00, 0x00 },
	{ 0x07, 0x0B, 0x00, 0x00 },
	{ 0x07, 0x0D, 0x00, 0x00 },
	{ 0x06, 0x0A, 0x00, 0x00 },
	{ 0x08, 0x0C, 0x00, 0x00 },
	{ 0x09, 0x18, 0x00, 0x00 },
	{ 0x04, 0x12, 0x01, 0x00 },
	{ 0x08, 0x0C, 0x00, 0x00 },
	{ 0x0A, 0x0F, 0x00, 0x00 },
	{ 0x0B, 0x10, 0x00, 0x00 },
	{ 0x0C, 0x08, 0x00, 0x00 },
	{ 0x0D, 0x0B, 0x00, 0x00 },
	{ 0x0E, 0x0B, 0x00, 0x00 },
	{ 0x0D, 0x0B, 0x00, 0x00 },
	{ 0xFF, 0x00, 0x00, 0x00 },
};

CONST_DATA struct UnkStruct_0868b508 Unk_0868B574[] = {
	{ 0x00, 0x18, 0x01, 0x00 },
	{ 0x06, 0x09, 0x00, 0x00 },
	{ 0x07, 0x0B, 0x00, 0x00 },
	{ 0x07, 0x0D, 0x00, 0x00 },
	{ 0x06, 0x0A, 0x00, 0x00 },
	{ 0x08, 0x0C, 0x00, 0x00 },
	{ 0x09, 0x18, 0x00, 0x00 },
	{ 0x02, 0x10, 0x01, 0x00 },
	{ 0x0F, 0x0E, 0x00, 0x00 },
	{ 0x06, 0x0A, 0x00, 0x00 },
	{ 0x0C, 0x09, 0x00, 0x00 },
	{ 0x40, 0x0E, 0x00, 0x00 },
	{ 0x41, 0x0C, 0x00, 0x00 },
	{ 0x0D, 0x0C, 0x00, 0x00 },
	{ 0xFF, 0x00, 0x00, 0x00 },
};

CONST_DATA struct UnkStruct_0868B5B0 gPlayRankMissonObjInfo[] = {
	{ Unk_0868B508, 0x0E, 0x00 },
	{ Unk_0868B534, 0x10, 0x12 },
	{ Unk_0868B574, 0x1C, 0x12 }
};

void SetupPlayRanks(void)
{
	int i;

	for (i = 0; i < 7; i++) {
		gpPlayRankSt->xs[i] = gTotalPlayRankConf1[i].x;
		gpPlayRankSt->ys[i] = gTotalPlayRankConf1[i].y;
	}
}

void SetupXmapPlayRanks(void)
{
	int i;

	for (i = 0; i < 4; i++) {
		gpPlayRankSt->xs[i] = gTotalPlayRankConf2[i].x;
		gpPlayRankSt->ys[i] = gTotalPlayRankConf2[i].y;
	}

	gPlayRanks[PLAYRANK_XMAP_TACTICS] = gpPlayRankSt->ranks[PLAYRANK_XMAP_TACTICS] = PlayRankGetter_XmapTactics();
	gPlayRanks[PLAYRANK_XMAP_SURVIVAL] = gpPlayRankSt->ranks[PLAYRANK_XMAP_SURVIVAL] = PlayRankGetter_XmapSurvival();
	gPlayRanks[PLAYRANK_XMAP_COMBAT] = gpPlayRankSt->ranks[PLAYRANK_XMAP_COMBAT] = PlayRankGetter_XmapCombat();

	gpPlayRankSt->ranks[PLAYRANK_XMAP_TOTAL] = GameRank_GetTotalRankB();

	for (i = 0; i < PLAYRANK_XMAP_MAX; i++)
		SetupPlayRankDispUnit(i, 0);
}

CONST_DATA struct BaSpriteData BaSprite_0868B5C8[] = {
	// ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_32, 0x0000, -16, -16
	{ 
		.header = OAM0_SHAPE_32x32 | (OAM1_SIZE_32x32 << 16),
		.as = {.object = {
			.oam2 = 0,
			.x = -0x10,
			.y = -0x10
		}}
	},

	// ANIM_SPRITE_END
	{
		.header = 1
	},
};

CONST_DATA u8 gUnk_0868B5E0[] = {
	1, 2, 3, 3, 3, 2
};

struct ProcScr CONST_DATA ProcScr_0868B5E8[] = {
	PROC_19,
	PROC_CALL(func_fe6_0808DE5C),
	PROC_REPEAT(func_fe6_0808DE70),
	PROC_REPEAT(func_fe6_0808DEA4),
	PROC_END,
};

void func_fe6_0808DE04(int lo, int hi, int x, int pal_bank)
{
	int ret = Interpolate(INTERPOLATE_SQUARE, lo, hi, x, 8);

	CpuFastCopy(Pal_08342AB8, PAL_BG(pal_bank), 0x20);
	EfxPalWhiteInOut(gPal, pal_bank, 1, ret);
	EnablePalSync();
}

void func_fe6_0808DE5C(struct Proc_0868B5E8 *proc)
{
	proc->timer1 = 0;
	proc->step = 0;
	proc->anim_duration = gUnk_0868B5E0[0];
}

void func_fe6_0808DE70(struct Proc_0868B5E8 *proc)
{
	func_fe6_0808DE04(8, 0x10, proc->timer1, proc->pal_bank + 0x10 + OBPAL_PLAYRANK_4);

	proc->timer1++;
	if (proc->timer1 > 8) {
		proc->timer1 = 0;
		Proc_Break(proc);
	}
}

void func_fe6_0808DEA4(struct Proc_0868B5E8 *proc)
{
	struct Anim anim;
	int _tmp;

	if (proc->timer1 <= 8) {
		func_fe6_0808DE04(0x10, 0, proc->timer1, proc->pal_bank + 0x10 + OBPAL_PLAYRANK_4);
		proc->timer1++;
	}

	anim.oam01 = 0;
	anim.sprData = BaSprite_0868B5C8;
	anim.xPosition = (proc->x + 7) * 8;
	anim.yPosition = (proc->y + 1) * 8;
	anim.oam2 = (_tmp = 0xFFFFC000) | (0x100 + proc->step * 4);

	BasPutOam(&anim);

	proc->anim_duration--;
	if (proc->anim_duration == 0) {
		proc->step++;
		proc->anim_duration = gUnk_0868B5E0[proc->step];

		if (proc->anim_duration == 0)
			Proc_Break(proc);
	}
}

void func_fe6_0808DF3C(u16 pal_bank, int _x, int _y)
{
	struct Proc_0868B5E8 *proc;
	u16 x = _x;
	u16 y = _y;

	ApplyPalette(Pal_08342AD8, 0x10 + OBPAL_PLAYRANK_C);

	proc = SpawnProc(ProcScr_0868B5E8, PROC_TREE_3);
	proc->pal_bank = pal_bank;
	proc->x = x;
	proc->y = y;
}

struct ProcScr CONST_DATA ProcScr_0868B610[] = {
	PROC_19,
PROC_LABEL(0),
	PROC_CALL(func_fe6_0808DFC4),
	PROC_REPEAT(func_fe6_0808DFCC),
	PROC_REPEAT(func_fe6_0808E0DC),
PROC_LABEL(1),
	PROC_END,
};

void SetupPlayRankDispUnit(int step, int b)
{
	gpPlayRankSt->unk_5E[step] = b;
	gpPlayRankSt->objs[step] = Objs_0868B4D0[b].obj;
	gpPlayRankSt->unk_98[step] = Objs_0868B4D0[b].unk_04;

	ApplyPalette(Pal_08342AB8, 0x10 + OBPAL_PLAYRANK_4 + step);
}

void func_fe6_0808DFC4(struct Proc_0868B5E8 *proc)
{
	proc->timer1 = 0;
}

void func_fe6_0808DFCC(struct Proc_0868B5E8 *proc)
{
	int x_scale = Interpolate(INTERPOLATE_RCUBIC, 2, 0x100, proc->timer1, 8);

	SetObjAffineAuto(0x1F, 0, x_scale, 0x100);

	if (gKeySt->held & KEY_BUTTON_A)
		proc->timer1++;

	if (proc->timer1++ >= 8) {
		struct PlayRankSt *st;
		struct PlayRankSt *bug_st;

		proc->timer1 = 8;

		st = gpPlayRankSt;
		bug_st = (struct PlayRankSt *)proc; // WTF

		if (st->unk_5E[bug_st->step] < st->ranks[bug_st->step]) {
			Proc_Break(proc);
			return;
		}

		if (bug_st->step <= 5 && st->unk_5E[bug_st->step] > 3)
			func_fe6_0808DF3C(bug_st->step, proc->x, proc->y);

		Proc_Goto(proc, 1);
	}
}

void func_fe6_0808E0DC(struct Proc_0868B5E8 *proc)
{
	int x_scale = Interpolate(INTERPOLATE_RCUBIC, 2, 0x100, 0x11 - proc->timer1, 8);

	SetObjAffineAuto(0x1F, 0, x_scale, 0x100);

	if (gKeySt->held & KEY_BUTTON_A)
		proc->timer1++;

	if (proc->timer1++ >= 0x10) {
		struct PlayRankSt *st;
		struct PlayRankSt *bug_st;
		int tmp;

		proc->timer1 = 0x10;

		st = gpPlayRankSt;
		bug_st = (struct PlayRankSt *)proc; // WTF

		tmp = st->unk_5E[bug_st->step];

		if (tmp <= 5) {
			SetupPlayRankDispUnit(bug_st->step, tmp + 1);
			Proc_Goto(proc, 0);
		}
	}
}

struct ProcScr CONST_DATA ProcScr_0868B648[] = {
	PROC_19,
	PROC_SLEEP(30),

PROC_LABEL(0),
	PROC_CALL(func_fe6_0808E284),
	PROC_SLEEP(1),
	PROC_CALL(func_fe6_0808E2D0),
	PROC_SLEEP(44),
PROC_LABEL(1),
	PROC_CALL(func_fe6_0808E264),
	PROC_SLEEP(20),
PROC_LABEL(2),
	PROC_CALL(func_fe6_0808E1D0),
	PROC_SLEEP(1),
	PROC_CALL(func_fe6_0808E1E4),
	PROC_GOTO(0),

PROC_LABEL(3),
	PROC_REPEAT(func_fe6_0808E2F0),
	PROC_END,
};

void func_fe6_0808E1D0(void)
{
	gpPlayRankSt->step++;
}

void func_fe6_0808E1E4(void)
{
	SetObjAffineAuto(0x1F, 0, 2, 0x100);
}

void func_fe6_0808E264(struct Proc_0868B648 *proc)
{
	if (gpPlayRankSt->step <= 4)
		Proc_Goto(proc, 2);
}

void func_fe6_0808E284(ProcPtr p)
{
	struct Proc_0868B5E8 *proc = SpawnProcLocking(ProcScr_0868B610, p);
	struct PlayRankSt *bug_st = (void *)proc;

	// ?
	bug_st->step = gpPlayRankSt->step;
	bug_st->unk_32 = gpPlayRankSt->xs[gpPlayRankSt->step];
	bug_st->unk_34 = gpPlayRankSt->ys[gpPlayRankSt->step];
}

void func_fe6_0808E2D0(struct Proc_0868B648 *proc)
{
	if (gpPlayRankSt->step > 5)
		Proc_Goto(proc, 3);
}

void func_fe6_0808E2F0(struct Proc_0868B648 *proc) {}

struct ProcScr CONST_DATA ProcScr_0868B6D8[] = {
	PROC_19,
	PROC_CALL(func_fe6_0808E2F4),
	PROC_SLEEP(20),
	PROC_REPEAT(func_fe6_0808E390),
	PROC_END,
};

void func_fe6_0808E2F4(void)
{
	SetObjAffine(0xA, 0x100, 0, 0, 0x100);
	SetObjAffineAuto(0x1F, 0, 2, 0x100);
	SpawnProc(ProcScr_0868B648, PROC_TREE_3);
}

void func_fe6_0808E390(void)
{
	int i;

	for (i = 0; i < (gpPlayRankSt->step + 1); i++) {
		int oam0, oam1, oam2;

		oam1 = (gpPlayRankSt->xs[i] + 6) << 3;
		oam0 = gpPlayRankSt->ys[i] << 3;

		if (i == gpPlayRankSt->step) {
			oam1 |= 0x3E00;
			oam0 |= 0x100;
		}

		oam2 = gpPlayRankSt->unk_5E[i] * 2 + 0xC0;

		PutSpriteExt(
			4,
			oam1,
			oam0,
			gpPlayRankSt->objs[i],
			(((i + 4) & 0xF) << 0xC) | oam2
		);
	}
}

struct ProcScr CONST_DATA ProcScr_0868B700[] = {
	PROC_19,
	PROC_CALL(func_fe6_0808E420),
	PROC_REPEAT(func_fe6_0808E434),
	PROC_END,
};

void func_fe6_0808E420(struct Proc_0868B700 *proc)
{
	proc->timer = 0;
	proc->layer = gPlayRankLayer - 1;
}

void func_fe6_0808E434(struct Proc_0868B700 *proc)
{
	int x_scale, time = proc->timer++;

	if (time > 7)
		Proc_Break(proc);

	x_scale = Interpolate(INTERPOLATE_RCUBIC, 2, 0x100, proc->timer, 8);
	SetObjAffineAuto(proc->layer, 0, 0x100, x_scale);
}

u16 CONST_DATA Sprite_PlayRankTrial_Time[] = {
	2,
	OAM0_SHAPE_32x8, OAM1_SIZE_32x8, 0,
	OAM0_SHAPE_32x8, OAM1_SIZE_32x8 + OAM1_X(32), OAM2_CHR(0x4),
};

struct ProcScr CONST_DATA ProcScr_0868B730[] = {
	PROC_19,
	PROC_CALL(func_fe6_0808E4E8),
	PROC_REPEAT(func_fe6_0808E5F0),
	PROC_END,
};

void func_fe6_0808E4E8(struct Proc_0868B730 *proc)
{
	int i;
	struct UnkStruct_0868b508 *ref;

	gPlayRankLayer = 0;
	proc->timer = 0;
	proc->total_sprites = 0;

	ref = gPlayRankMissonObjInfo[gPlayRankMissonObjSelect].unk_00;

	while (ref[proc->total_sprites].chr != -1)
		proc->total_sprites++;

	for (i = 0; i < proc->total_sprites; i++) {
		SetObjAffine(i, 0x100, 0, 0, 0x100);
		SetObjAffineAuto(i, 0, 0x100, 2);
	}
}

void func_fe6_0808E5F0(struct Proc_0868B730 *proc)
{
	int i, val, y;
	struct UnkStruct_0868b508 *ref;

	val = 0;

	y= 0x100 - gPlayRankBg1Offset;
	if (gPlayRankMissonObjSelect == 0) {
		y = OAM1_X(y + 0x80); // ?

		PutOamHi(0xA2, y, Sprite_PlayRankTrial_Time, OAM2_PAL(BGPAL_PLAYRANK_TIME) + OBCHR_PLAYRANK_84);
	}

	if (++proc->timer < 0xF) {
		proc->timer = 0;

		if (gPlayRankLayer < proc->total_sprites) {
			gPlayRankLayer++;
			SpawnProc(ProcScr_0868B700, PROC_TREE_3);
		}
	}

	ref = gPlayRankMissonObjInfo[gPlayRankMissonObjSelect].unk_00;
	for (i = 0; i < gPlayRankLayer; i++) {
		int oam1 = gPlayRankMissonObjInfo[gPlayRankMissonObjSelect].x + val + (i << 9);
		int oam0 = gPlayRankMissonObjInfo[gPlayRankMissonObjSelect].y + 0x108;


		PutSpriteExt(
			4,
			oam1,
			oam0,
			ref[i].size != 0 ? Sprite_0868B418 : Sprite_0868B410,
			ref[i].chr * 2 + 0x3180
		);

		val = ref[i].len + val;
	}
}

struct ProcScr CONST_DATA ProcScr_PlayRankTrialOBJ_Time[] = {
	PROC_19,
	PROC_REPEAT(PlayRankTrialOBJ_Time_Loop),
	PROC_END,
};

void PlayRankTrialOBJ_Time_Loop(void)
{
	PutOamHi(0x58, 0x3E, Sprite_PlayRankTrial_Time,  OAM2_CHR(OBCHR_PLAYRANK_84) + OAM2_PAL(BGPAL_PLAYRANK_TIME));
}

void NewPlayRankTrialOBJ_Time(void)
{
	SpawnProc(ProcScr_PlayRankTrialOBJ_Time, PROC_TREE_3);
}

struct ProcScr CONST_DATA ProcScr_PlayRankFogHandler[] = {
	PROC_19,
	PROC_CALL(PlayRankFogHandler_Init),
	PROC_REPEAT(PlayRankFogHandler_Loop),
	PROC_END,
};

void PlayRankFogHandler_Init(void)
{
	gpPlayRankSt->x = 0;
	gpPlayRankSt->y = 0;
	gpPlayRankSt->x_step = 0;
	gpPlayRankSt->y_step = 0;
	gpPlayRankSt->step = 0;
}

void PlayRankFogHandler_Loop(void)
{
	gpPlayRankSt->x_step += 3;
	gpPlayRankSt->y_step += 1;
	gpPlayRankSt->x += gpPlayRankSt->x_step / 4;
	gpPlayRankSt->y += gpPlayRankSt->y_step / 4;

	gpPlayRankSt->x_step &= 3;
	gpPlayRankSt->y_step &= 3;

	SetBgOffset(BG_2, gpPlayRankSt->x & 0xFF, gpPlayRankSt->y & 0xFF);
}

void PlayRank_InitTexts(void)
{
	int i;

	for (i = 0; i < 8; i++)
		InitText(&gpPlayRankSt->texts[i], 0xF);

	InitText(&gpPlayRankSt->texts[PLAYRANK_TEXT_8], 0x3);
}

CONST_DATA u16 Msgs_PlayRankNum[10] = {
	MSG_PLAYRANK_0, 
	MSG_PLAYRANK_1,
	MSG_PLAYRANK_2,
	MSG_PLAYRANK_3,
	MSG_PLAYRANK_4,
	MSG_PLAYRANK_5,
	MSG_PLAYRANK_6,
	MSG_PLAYRANK_7,
	MSG_PLAYRANK_8,
	MSG_PLAYRANK_9
};

int PlayRank_ChapterTurns_DrawBase(struct Text *text, int chapter_gaiden, u8 centered)
{
	int is_gaiden;
    int ret;
    int x;
	int hi, lo;
    int lens[4];

    x = 0;

	if (chapter_gaiden == (CHAPTER_FINAL << 1)) {
		ret = GetStringTextLen(DecodeMsg(MSG_PLAYRANK_FINAL));

		if (centered != false)
			x = (0x30 - ret) >> 1;

		Text_InsertDrawString(text, x, TEXT_COLOR_SYSTEM_WHITE, DecodeMsg(MSG_PLAYRANK_FINAL));
		return ret;
	}

	lens[0] = GetStringTextLen(DecodeMsg(MSG_PLAYRANK_PREFIX));
	ret = lens[0];

	hi = (chapter_gaiden >> 1) / 10;
	lo = (chapter_gaiden >> 1) % 10;

	if (hi != 0) {
		lens[1] = GetStringTextLen(DecodeMsg(Msgs_PlayRankNum[hi])) - 1;
		ret += lens[1];
	}

	lens[2] = GetStringTextLen(DecodeMsg(Msgs_PlayRankNum[lo])) - 1;
	ret += lens[2];

	lens[3] = GetStringTextLen(DecodeMsg(MSG_PLAYRANK_SUBFIX));
	ret += lens[3];

	is_gaiden = chapter_gaiden & 1;
	if (is_gaiden)
		ret += GetStringTextLen(DecodeMsg(MSG_PLAYRANK_GAIDEN));

	if (centered != false)
		x = (0x30 - ret) >> 1;

	Text_InsertDrawString(text, x, TEXT_COLOR_SYSTEM_WHITE, DecodeMsg(MSG_PLAYRANK_PREFIX));
	x += lens[0];

	if (hi != 0) {
		Text_InsertDrawString(text, x, TEXT_COLOR_SYSTEM_WHITE, DecodeMsg(Msgs_PlayRankNum[hi]));
		x += lens[1];
	}

	Text_InsertDrawString(text, x, TEXT_COLOR_SYSTEM_WHITE, DecodeMsg(Msgs_PlayRankNum[lo]));
	x += lens[2];

	Text_InsertDrawString(text, x, TEXT_COLOR_SYSTEM_WHITE, DecodeMsg(MSG_PLAYRANK_SUBFIX));
	x += lens[3];

	if (is_gaiden != 0)
		Text_InsertDrawString(text, x, TEXT_COLOR_SYSTEM_WHITE, DecodeMsg(MSG_PLAYRANK_GAIDEN));

	return ret;
}

bool PlayRank_ChapterTurns_DrawTurn(int line)
{
	if (gPlayRankCurChapter < GetNextChapterStatsSlot()) {
		struct ChapterStats *chapter_stat = GetChapterStats(gPlayRankCurChapter);
		int chapter_id, x;
		int index = gPlayRankCurChapter & 7;

		ClearText(&gpPlayRankSt->texts[index]);
		ClearText(&gpPlayRankSt->texts[PLAYRANK_TEXT_8]);

		chapter_id = GetChapterInfo(chapter_stat->chapter_id)->index_gaiden;
		PlayRank_ChapterTurns_DrawBase(
			&gpPlayRankSt->texts[index],
			chapter_id,
			true
		);

		x = (0x46 - GetStringTextLen(DecodeMsg(GetChapterInfo(chapter_stat->chapter_id)->msg_chapter_title))) / 2;
		Text_InsertDrawString(
			&gpPlayRankSt->texts[index],
			x + 0x28,
			TEXT_COLOR_SYSTEM_WHITE,
			DecodeMsg(GetChapterInfo(chapter_stat->chapter_id)->msg_chapter_title)
		);

		PutText(
			&gpPlayRankSt->texts[index],
			gBg0Tm + TM_OFFSET(1, line)
		);

		PutNumber(
			gBg0Tm + TM_OFFSET(0x10, line),
			TEXT_COLOR_SYSTEM_BLUE,
			chapter_stat->chapter_turn
		);

		PutDrawText(
			&gpPlayRankSt->texts[PLAYRANK_TEXT_8],
			gBg0Tm + TM_OFFSET(0x11, line),
			TEXT_COLOR_SYSTEM_WHITE,
			0, 3, DecodeMsg(MSG_Turn)
		);

		PutTime(
			gBg0Tm + TM_OFFSET(0x14, line),
			TEXT_COLOR_SYSTEM_BLUE,
			chapter_stat->chapter_time * 180,
			true
		);

		gPlayRankCurChapter++;
		EnableBgSync(BG0_SYNC_BIT);
		return false;
	}
	return true;
}

void PutPlayRankTexts(int line)
{
	int i;

	gPlayRanks[PLAYRANK_TACTICS] = gpPlayRankSt->ranks[PLAYRANK_TACTICS] = PlayRankGetter_Tactics();
	gPlayRanks[PLAYRANK_COMBAT] = gpPlayRankSt->ranks[PLAYRANK_COMBAT] = PlayRankGetter_Combat();
	gPlayRanks[PLAYRANK_SURVIVAL] = gpPlayRankSt->ranks[PLAYRANK_SURVIVAL] = PlayRankGetter_Survival();
	gPlayRanks[PLAYRANK_EXPERIENCE] = gpPlayRankSt->ranks[PLAYRANK_EXPERIENCE] = PlayRankGetter_Experience();
	gPlayRanks[PLAYRANK_ASSET] = gpPlayRankSt->ranks[PLAYRANK_ASSET] = PlayRankGetter_Asset();
	gPlayRanks[PLAYRANK_POWER] = gpPlayRankSt->ranks[PLAYRANK_POWER] = PlayRankGetter_Power();

	for (i = 0; i < (PLAYRANK_MAX - 1); i++)
		SetupPlayRankDispUnit(i, 0);

	gpPlayRankSt->ranks[PLAYRANK_TOTAL] = GameRank_GetTotalRankA();
	SetupPlayRankDispUnit(PLAYRANK_TOTAL, 0);

	for (i = 0; i < PLAYRANK_MAX; i++) {
		int _line;

		InitText(&gpPlayRankSt->texts_rank_name[i], 6);
		ClearText(&gpPlayRankSt->texts_rank_name[i]);

		PutDrawText(
			&gpPlayRankSt->texts_rank_name[i],
			gBg0Tm + TM_OFFSET(gpPlayRankSt->xs[i], (gpPlayRankSt->ys[i] + (_line = line - 6)) & 0x1F),
			gTotalPlayRankConf1[i].color,
			0, 6,
			DecodeMsg(gTotalPlayRankConf1[i].msg)
		);
	}
}

void func_fe6_0808EB94(int line)
{
	int index;
	int tile_width = 6;

	line += 0x16;
	index = PLAYRANK_TOTAL;

	InitText(gpPlayRankSt->texts_rank_name + index, 6);
	ClearText(gpPlayRankSt->texts_rank_name + index);

	PutDrawText(
		gpPlayRankSt->texts_rank_name + index,
		gBg0Tm + TM_OFFSET(gpPlayRankSt->xs[index], (gpPlayRankSt->ys[index] + line) & 0x1F),
		gTotalPlayRankConf1[index].color,
		0, tile_width, DecodeMsg(gTotalPlayRankConf1[index].msg)
	);
}

int PlayRank_GetTotalPlayTime(void)
{
	int i, ret = 0;
	int slot = GetNextChapterStatsSlot();

	for (i = 0; i < slot; i++)
		ret += GetChapterStats(i)->chapter_time * 180;

	return ret;
}

void PlayRank_PutTotalPlayTime(int line)
{
	int time = PlayRank_GetTotalPlayTime();

	PutTime(
		gBg0Tm + TM_OFFSET(0x14, (line + 3) & 0x1F),
		TEXT_COLOR_SYSTEM_BLUE,
		time, true
	);
	EnableBgSync(BG0_SYNC_BIT);
}

void func_fe6_0808EC78(int x)
{
	int x1 = ((x - 0x50) * 4) & 0x3C0;
	int x2 = (x1 + 0x40) & 0x3C0;
	int i;

	for (i = 0; i < 0x20; i++) {
		gBg0Tm[TM_OFFSET(x1 + i, 0)] = 0;
		gBg0Tm[TM_OFFSET(x1 + i, 1)] = 0;
		gBg0Tm[TM_OFFSET(x2 + i, 0)] = 0;
		gBg0Tm[TM_OFFSET(x2 + i, 1)] = 0;
	}
	EnableBgSync(BG0_SYNC_BIT);
}

// https://decomp.me/scratch/r3WgO
NAKEDFUNC
void FillPlayRankFogsToBG(u16 *tm, int a, int b)
{
asm("\
	.syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #0x28\n\
	str r0, [sp]\n\
	lsls r2, r2, #0x10\n\
	movs r3, #0\n\
	lsrs r2, r2, #4\n\
	mov ip, r2\n\
.L0808ECE6:\n\
	movs r2, #0\n\
	lsls r0, r3, #8\n\
	str r0, [sp, #0x10]\n\
	adds r3, #1\n\
	str r3, [sp, #8]\n\
.L0808ECF0:\n\
	lsls r0, r2, #3\n\
	ldr r3, [sp, #0x10]\n\
	adds r0, r3, r0\n\
	movs r6, #0\n\
	str r6, [sp, #4]\n\
	adds r2, #1\n\
	str r2, [sp, #0xc]\n\
	lsls r2, r0, #1\n\
	adds r0, r2, #0\n\
	adds r0, #0xc0\n\
	ldr r7, [sp]\n\
	adds r0, r0, r7\n\
	str r0, [sp, #0x14]\n\
	adds r0, r2, #0\n\
	adds r0, #0x80\n\
	adds r0, r0, r7\n\
	str r0, [sp, #0x18]\n\
	adds r0, r2, #0\n\
	adds r0, #0x40\n\
	adds r0, r0, r7\n\
	str r0, [sp, #0x1c]\n\
	adds r2, r2, r7\n\
	mov r0, ip\n\
	adds r0, #0xe0\n\
	adds r0, r0, r1\n\
	mov sl, r0\n\
	mov r0, ip\n\
	adds r0, #0xc0\n\
	adds r0, r0, r1\n\
	mov sb, r0\n\
	mov r0, ip\n\
	adds r0, #0xa0\n\
	adds r0, r0, r1\n\
	mov r8, r0\n\
	mov r0, ip\n\
	adds r0, #0x80\n\
	adds r0, r1, r0\n\
	str r0, [sp, #0x20]\n\
	mov r0, ip\n\
	adds r0, #0x60\n\
	adds r0, r1, r0\n\
	str r0, [sp, #0x24]\n\
	mov r0, ip\n\
	adds r0, #0x40\n\
	adds r5, r1, r0\n\
	subs r0, #0x20\n\
	adds r4, r1, r0\n\
	mov r0, ip\n\
	adds r3, r1, r0\n\
.L0808ED52:\n\
	strh r3, [r2]\n\
	ldr r6, [sp, #0x1c]\n\
	strh r4, [r6]\n\
	ldr r7, [sp, #0x18]\n\
	strh r5, [r7]\n\
	mov r0, sp\n\
	ldrh r6, [r0, #0x24]\n\
	ldr r0, [sp, #0x14]\n\
	strh r6, [r0]\n\
	movs r7, #0x80\n\
	lsls r7, r7, #1\n\
	adds r0, r2, r7\n\
	mov r6, sp\n\
	ldrh r6, [r6, #0x20]\n\
	strh r6, [r0]\n\
	adds r7, #0x40\n\
	adds r0, r2, r7\n\
	mov r6, r8\n\
	strh r6, [r0]\n\
	adds r7, #0x40\n\
	adds r0, r2, r7\n\
	mov r6, sb\n\
	strh r6, [r0]\n\
	adds r7, #0x40\n\
	adds r0, r2, r7\n\
	mov r6, sl\n\
	strh r6, [r0]\n\
	ldr r7, [sp, #0x14]\n\
	adds r7, #2\n\
	str r7, [sp, #0x14]\n\
	ldr r0, [sp, #0x18]\n\
	adds r0, #2\n\
	str r0, [sp, #0x18]\n\
	ldr r6, [sp, #0x1c]\n\
	adds r6, #2\n\
	str r6, [sp, #0x1c]\n\
	adds r2, #2\n\
	movs r7, #1\n\
	add sl, r7\n\
	movs r0, #1\n\
	add sb, r0\n\
	add r8, r0\n\
	ldr r6, [sp, #0x20]\n\
	adds r6, #1\n\
	str r6, [sp, #0x20]\n\
	ldr r7, [sp, #0x24]\n\
	adds r7, #1\n\
	str r7, [sp, #0x24]\n\
	adds r5, #1\n\
	adds r4, #1\n\
	adds r3, #1\n\
	ldr r0, [sp, #4]\n\
	adds r0, #1\n\
	str r0, [sp, #4]\n\
	cmp r0, #7\n\
	ble .L0808ED52\n\
	ldr r2, [sp, #0xc]\n\
	cmp r2, #3\n\
	ble .L0808ECF0\n\
	ldr r3, [sp, #8]\n\
	cmp r3, #3\n\
	ble .L0808ECE6\n\
	add sp, #0x28\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.syntax divided\n\
");
}

void PlayRank_InitDisplay(void)
{
	ResetText();
	UnpackUiWindowFrameGraphics();
	ResetTextFont();
	PlayRank_InitTexts();

	SetDispEnable(1, 1, 1, 1, 1);

	gPlayRankCurChapter = 0;
	gPlayRankDispStep = 0;
	gPasswdScreenDisabled = 0;
	gPlayRankBg0Offset = 0x80;
	gPlayRankBg1Offset = 0xE0;
	gPlayRankDispLine = 0xFF;

	SetBgOffset(BG_0, 0, 0x80);
	SetBgOffset(BG_1, 0, gPlayRankBg1Offset);
	SetBgOffset(BG_2, 0, 0);
	SetBgOffset(BG_3, 0, 0);

	SetWinEnable(1, 0, 0);
	SetWin0Box(0, 0x18, -0x10, -0x78);
	SetWin0Layers(1, 1, 1, 1, 1);
	SetWOutLayers(0, 1, 1, 1, 1);

	gDispIo.win_ct.win0_enable_blend = true;
	gDispIo.win_ct.wout_enable_blend = true;

	TmFill(gBg0Tm, 0);
	TmFill(gBg1Tm, 0);
	TmFill(gBg2Tm, 0);
	TmFill(gBg3Tm, 0);

	SetBlendAlpha(6, 0x10);
	SetBlendTargetA(0, 0, 1, 0, 0);
	SetBlendTargetB(0, 0, 0, 1, 0);

	SetupPlayRanks();

	ApplyBgPalettes(Pal_PlayRankWmBG, BGPAL_PLAYRANK_WM, 2);
	ApplyBgPalette(Pal_PlayRankFogBG, BGPAL_PLAYRANK_FOG);
	ApplyObPalette(Pal_PlayRankTimeOBJ, BGPAL_PLAYRANK_TIME);
	ApplyObPalette(Pal_08342A98, OBPAL_PLAYRANK_MISSION);
	ApplyObPalette(Pal_08342A98, OBPAL_PLAYRANK_B);

	Decompress(Img_PlayRankTimeOBJ, OBJ_VRAM0 + OBCHR_PLAYRANK_TIME * CHR_SIZE);
	Decompress(Img_PlayRankCharacters, OBJ_VRAM0 + BGCHR_PLAYRANK_C0 * CHR_SIZE);
	Decompress(Img_PlayRank, OBJ_VRAM0 + BGCHR_PLAYRANK_180 * CHR_SIZE);
	Decompress(Img_PlayRankFogBG, (u8 *)BG_VRAM + BGCHR_PLAYRANK_680 * CHR_SIZE);
	Decompress(Img_WorldMap_PlayRank, (u8 *)BG_VRAM + GetBgChrOffset(BG_3));
	TmApplyTsa(gBg1Tm + TM_OFFSET(0x13, 0x10), Tsa_08342AF8, OAM2_PAL(BGPAL_PLAYRANK_1));
	FillPlayRankFogsToBG(gBg2Tm, 0x280, BGPAL_PLAYRANK_FOG);
	TmApplyTsa(gBg3Tm, Tsa_08340ED8, OAM2_PAL(BGPAL_PLAYRANK_WM));

	SpawnProc(ProcScr_PlayRankFogHandler, PROC_TREE_3);
	EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT | BG2_SYNC_BIT | BG3_SYNC_BIT);
}

void func_fe6_0808F060(struct ProcPlayRank *proc)
{

	proc->unk_2E = 4;
	proc->unk_30 = 0;
	gPlayRankBg0Offset = gPlayRankBg0MoveStep = 0x7A;

	PlayRank_ChapterTurns_DrawTurn(0);
	gPlayRankCurChapter = 0;
	EnableBgSync(BG0_SYNC_BIT);
}

void PlayRank_Loop(struct ProcPlayRank *proc)
{
	int tmp1, tmp2;

	if (proc->unk_30 != 0) {
		func_fe6_0808EC78(gPlayRankBg0Offset);
		proc->unk_30 = 0;
	}

	if (gPlayRankDispStep <= 8) {
		if (proc->unk_2E++ < 4)
			return;
		proc->unk_2E = 0;
	}

	gPlayRankBg0Offset++;
	SetBgOffset(BG_0, 0, gPlayRankBg0Offset & 0xFF);

	if (gPlayRankDispStep > 0xC) {
		gPlayRankBg1Offset++;
		SetBgOffset(BG_1, 0, gPlayRankBg1Offset & 0xFF);
	}

	tmp1 = ((gPlayRankBg0Offset - gPlayRankBg0MoveStep) & 0xF0) >> 3;
	if (tmp1 == gPlayRankDispLine)
		return;

	gPlayRankDispLine = tmp1;

	proc->unk_30 = true;

	switch (gPlayRankDispStep) {
	case 0:
		if (!PlayRank_ChapterTurns_DrawTurn(gPlayRankDispLine))
			return;

		break;

	case 8:
		TmFill(gBg0Tm, 0);
		EnableBgSync(BG0_SYNC_BIT);
		break;

	case 9:
		tmp1 = 0x80;
		gPlayRankBg0MoveStep = tmp1;
		gPlayRankBg0Offset = tmp1;
		tmp2 = 0;
		gPlayRankDispLine = tmp2;
		PutPlayRankTexts(tmp2);
		break;

	case 11:
		func_fe6_0808EB94(gPlayRankDispLine);
		break;

	case 13:
		PlayRank_PutTotalPlayTime(gPlayRankDispLine);
		SetWOutLayers(1, 1, 1, 1, 1);
		break;

	case 14:
		gPlayRankMissonObjSelect = 0;
		SpawnProc(ProcScr_0868B730, PROC_TREE_3);
		SpawnProc(ProcScr_0868B6D8, PROC_TREE_3);
		Proc_Break(proc);
		return;
		break;

	default:
		break;
	}

	gPlayRankDispStep++;
}

void PlayRank_Idle(ProcPtr proc)
{
	if ((gKeySt->pressed & (KEY_BUTTON_A | KEY_BUTTON_B)) && gpPlayRankSt->step == 6) {
		Proc_Break(proc);
		return;
	}

	if (CheckDisplayPasswordScreenCombo()) {
		gPasswdScreenDisabled = 1;
		Proc_Break(proc);
	}
}

void PlayRank_End1(ProcPtr proc)
{
	Proc_EndEach(ProcScr_0868B5E8);
	Proc_EndEach(ProcScr_0868B88C);
	Proc_EndEach(ProcScr_0868B610);
	EndGreenText();
}

void PlayRank_PrepareEnd(ProcPtr proc)
{
	Proc_EndEach(ProcScr_0868B648);
	Proc_EndEach(ProcScr_PlayRankFogHandler);
	Proc_EndEach(ProcScr_0868B730);
	Proc_EndEach(ProcScr_0868B6D8);
	Proc_EndEach(ProcScr_0868B80C);
	Proc_EndEach(ProcScr_PlayRankTrialOBJ);
	Proc_EndEach(ProcScr_PlayRankTrialOBJ_Time);
}

void PlayRank_CheckSkipPassword(ProcPtr proc)
{
	if (gPasswdScreenDisabled == 0)
		Proc_Goto(proc, 1);
}

u16 PlayRank_GetTotalTurn(void)
{
	int i, total_turn = 0;
	int slot = GetNextChapterStatsSlot();

	for (i = 0; i < slot; i++)
		total_turn += GetChapterStats(i)->chapter_turn;

	return total_turn;
}

u8 PlayRankGetter_Tactics(void)
{
	int slot, total_turn = PlayRank_GetTotalTurn();
	int i, ranks[PALYRANK_MAX], *_ranks;

	for (i = 0; i < PALYRANK_MAX; i++)
		ranks[i] = 0;

	slot = GetNextChapterStatsSlot();
	for (i = 0; i < slot; i++) {
		struct ChapterStats *chapter_stat = GetChapterStats(i);

		ranks[0] += ChapterInfoTable[chapter_stat->chapter_id].tactics_ranks[PALYRANK_A];
		ranks[1] += ChapterInfoTable[chapter_stat->chapter_id].tactics_ranks[PALYRANK_B];
		ranks[2] += ChapterInfoTable[chapter_stat->chapter_id].tactics_ranks[PALYRANK_C];
		ranks[3] += ChapterInfoTable[chapter_stat->chapter_id].tactics_ranks[PALYRANK_D];
	}

	// WTF
	i = PALYRANK_D;
	_ranks = ranks;
	while (1) {
		if (total_turn > *_ranks)
			break;

		_ranks++;
		i++;

		if (i > 3)
			break;
	}

	return i;
}

u8 PlayRankGetter_XmapTactics(void)
{
	int total_turn;
	int i, ranks[PALYRANK_MAX];
	struct ChapterStats *chapter_stat = GetXmapChapterStats();

	ranks[PALYRANK_D] = ChapterInfoTable[chapter_stat->chapter_id].tactics_ranks[REFRANK_D];
	ranks[PALYRANK_C] = ChapterInfoTable[chapter_stat->chapter_id].tactics_ranks[REFRANK_C];
	ranks[PALYRANK_B] = ChapterInfoTable[chapter_stat->chapter_id].tactics_ranks[REFRANK_B];
	ranks[PALYRANK_A] = ChapterInfoTable[chapter_stat->chapter_id].tactics_ranks[REFRANK_A];

	total_turn = chapter_stat->chapter_turn;

	if (gPlayRankMissionCompleted == 0)
		return PALYRANK_D;

	i = 0;
	for (;;) {
		if (total_turn > ranks[i])
			break;

		if (++i > 3)
			break;
	}

	return i;
}

CONST_DATA u8 gPlayRank_CombatRef[4] = { 15, 25, 35, 40 };

u16 PlayRank_GetWinningRate(void)
{
	int denominator = PidStatsCountTotalBattles();
	int numerator   = PidStatsCountTotalWins() * 100;

	return numerator / denominator;
}

u8 PlayRankGetter_Combat(void)
{
	int winning_rate = PlayRank_GetWinningRate();
	int i = 0;

	for (;;) {
		if (winning_rate < gPlayRank_CombatRef[i])
			break;

		if (++i > 3)
			break;
	}
	return i;
}

u8 PlayRankGetter_XmapCombat(void)
{
	int denominator = PidStatsCountTotalBattles();
	int numerator   = PidStatsCountTotalWins() * 100;
	int winning_rate = numerator / denominator;
	int i;

	i = 0;
	for (;;) {
		if (winning_rate < gPlayRank_CombatRef[i])
			break;

		if (++i > 3)
			break;
	}
	return i;
}

CONST_DATA u8 gPlayRank_SurvivalRef[4] = { 6, 4, 2, 1 };

u16 PlayRank_GetDeadAllies(void)
{
	int ret = 0;

	FOR_UNITS_FACTION(FACTION_BLUE, unit, {
		if (unit->flags & UNIT_FLAG_DEAD)
			ret++;
	})
	return ret;
}

u8 PlayRankGetter_Survival(void)
{
	int dead_allies = PlayRank_GetDeadAllies();
	u8 i = 0;

	for (;;) {
		if (dead_allies >= gPlayRank_SurvivalRef[i])
			break;

		if (++i > 3)
			break;
	}
	return i;
}

CONST_DATA u8 gPlayRank_XmapSurvivalRef[4] = { 4, 3, 2, 1 };

u8 PlayRankGetter_XmapSurvival(void)
{
	int dead_allies = 0;
	u8 i;

	FOR_UNITS_FACTION(FACTION_BLUE, unit, {
		if (unit->flags & UNIT_FLAG_DEAD)
			dead_allies++;
	})

	i = 0;
	for (;;) {
		if (dead_allies >= gPlayRank_XmapSurvivalRef[i])
			break;

		if (++i > 3)
			break;
	}
	return i;
}

u16 PlayRank_GetTotalLevelsGained(void)
{
	return PidStatsCountTotalLevelsGained();
}

u8 PlayRankGetter_Experience(void)
{
	int total_level = PlayRank_GetTotalLevelsGained();
	int chapter_id = GetChapterStats(GetNextChapterStatsSlot() - 1)->chapter_id;
	int ret;

	/**
	 * What a horrible coding style....
	 */
	ret = PALYRANK_D;
	if (total_level > ChapterInfoTable[chapter_id].exp_ranks[REFRANK_D]) {
		ret = PALYRANK_C;

		if (total_level > ChapterInfoTable[chapter_id].exp_ranks[REFRANK_C]) {
			ret = PALYRANK_B;

			if (total_level > ChapterInfoTable[chapter_id].exp_ranks[REFRANK_B]) {
				ret = PALYRANK_A;

				if (total_level > ChapterInfoTable[chapter_id].exp_ranks[REFRANK_A])
					ret = PALYRANK_S;
			}
		}
	}
	return ret;
}

CONST_DATA int gPlayRank_AssetRef[4] = { 1600, 3200, 4800, 6000 };

u8 PlayRankGetter_Asset(void)
{
	u32 total_asset = GetTotalAsset();
	_UNUSED struct ChapterStats *chapter_state = GetChapterStats(GetNextChapterStatsSlot());
	u32 ref = GetChapterInfo(gPlaySt.chapter)->index_gaiden / 2;

	int i = 0;
	int *ref_assets = gPlayRank_AssetRef;

	for (;;) {
		u32 ref_asset = *ref_assets;

		if (total_asset < (ref_asset * ref))
			break;

		ref_assets++;
		i++;
		if (i > 3)
			break;
	}
	return i;
}

u16 PlayRank_CalcTotalLevel(void)
{
	int ret = 0;

	FOR_UNITS_FACTION(FACTION_BLUE, unit, {
		if (UNIT_ATTRIBUTES(unit) & UNIT_ATTR_PROMOTED)
			ret += 20;

		ret += unit->level;
	})
	return ret;
}

u8 PlayRankGetter_Power(void)
{
	int total_level = PlayRank_CalcTotalLevel();
	int chapter_id = GetChapterStats(GetNextChapterStatsSlot() - 1)->chapter_id;
	int ret;

	/**
	 * What a horrible coding style....
	 */
	ret = PALYRANK_D;
	if (total_level > ChapterInfoTable[chapter_id].combat_ranks[REFRANK_D]) {
		ret = PALYRANK_C;

		if (total_level > ChapterInfoTable[chapter_id].combat_ranks[REFRANK_C]) {
			ret = PALYRANK_B;

			if (total_level > ChapterInfoTable[chapter_id].combat_ranks[REFRANK_B]) {
				ret = PALYRANK_A;

				if (total_level > ChapterInfoTable[chapter_id].combat_ranks[REFRANK_A])
					ret = PALYRANK_S;
			}
		}
	}
	return ret;
}

CONST_DATA u8 TotalRankA_Ref1[6][5] = {
	{ 40, 80, 120, 160, 200 }, // Tactics
	{ 10, 30, 50,  70,  90  }, // Combat
	{ 15, 35, 55,  75,  95  }, // Surcical
	{ 0,  20, 40,  60,  80  }, // Exp
	{ 0,  20, 40,  60,  80  }, // Asset
	{ 5,  25, 45,  65,  85  }, // Power
};

CONST_DATA u16 TotalRankA_Ref2[6] = {
	120,
	250,
	390,
	530,
	630,
	630
};

int GameRank_GetTotalRankA(void)
{
	int i;
	u16 ref = 0;

	for (i = 0; i < 6; i++) {
		ref += TotalRankA_Ref1[i][gPlayRanks[i]];
	}

	i = 0;
	for (;;) {
		if (ref < TotalRankA_Ref2[i])
			return i;

		i++;
		if (i > 4)
			break;
	}

	if (gPlaySt.flags & PLAY_FLAG_HARD)
		i++;

	return i;
}

CONST_DATA u8 TotalRankB_Ref1[6] = {
	20, 40, 60, 80, 100, 0
};

CONST_DATA u16 TotalRankB_Ref2[6] = {
	100, 150, 200, 250, 300, 300
};

int GameRank_GetTotalRankB(void)
{
	int i;
	u16 ref = 0;

	for (i = 0; i < 3; i++) {
		ref += TotalRankB_Ref1[gPlayRanks[i]];
	}

	i = 0;
	for (;;) {
		if (ref < TotalRankB_Ref2[i])
			return i;

		i++;
		if (i > 4)
			break;
	}

	return i;
}

u16 CONST_DATA BgConfig_PlayRank[] = {
	// tile offset  map offset  screen size
	0x0000,         0x6000,     0,          // BG 0
	0x0000,         0x6800,     0,          // BG 1
	0x8000,         0x7000,     0,          // BG 2
	0x8000,         0x7800,     0,          // BG 3
};

void PlayRank_InitBgConf(void)
{
	InitBgs(BgConfig_PlayRank);
}

struct ProcScr CONST_DATA ProcScr_0868B80C[] = {
	PROC_19,
PROC_LABEL(0),
	PROC_CALL(func_fe6_0808E284),
	PROC_SLEEP(30),
	PROC_CALL(func_fe6_0808F7B0),
	PROC_SLEEP(45),
	PROC_CALL(func_fe6_0808F790),
	PROC_SLEEP(20),
PROC_LABEL(2),
	PROC_CALL(func_fe6_0808E1D0),
	PROC_SLEEP(1),
	PROC_CALL(func_fe6_0808E1E4),
	PROC_GOTO(0),
PROC_LABEL(3),
	PROC_REPEAT(func_fe6_0808E2F0),
	PROC_END,
};

void func_fe6_0808F7B0(ProcPtr proc)
{
	if (gpPlayRankSt->step > 2)
		Proc_Goto(proc, 3);
}

void func_fe6_0808F790(ProcPtr proc)
{
	if (gpPlayRankSt->step < 2)
		Proc_Goto(proc, 2);
}

struct ProcScr CONST_DATA ProcScr_0868B88C[] =
{
	PROC_19,
	PROC_CALL(func_fe6_0808F838),
	PROC_REPEAT(func_fe6_0808F844),
	PROC_END,
};

void func_fe6_0808F7D0(int method, int lo, int hi, int x, int end, int pal_bank)
{
	int ret = Interpolate(method, lo, hi, x, end);

	CpuFastCopy(
		(gPlayRankMissionCompleted) ? Pal_PlayRankMissionCompletesOBJ : (Pal_PlayRankMissionCompletesOBJ + 0x10),
		PAL_BG(pal_bank),
		0x20
	);

	if (gPlayRankMissionCompleted)
		AuguryPaletteModify2(PAL_BG(BGPAL_PLAYRANK_0), pal_bank, 1, 7, ret);
	else
		AuguryPaletteModify1(PAL_BG(BGPAL_PLAYRANK_0), pal_bank, 1, 11, ret);

	EnablePalSync();
}

void func_fe6_0808F838(struct Proc_0868B88C *proc)
{
	proc->unk_2A = 0;
	proc->unk_2C = 0;
	proc->unk_2E = 0;
}

void func_fe6_0808F844(struct Proc_0868B88C *proc)
{
	switch (proc->unk_2E) {
	case 0:
		if (proc->unk_2A < 0x5A) {
			func_fe6_0808F7D0(INTERPOLATE_LINEAR, 0, 0xF, proc->unk_2A, 0x5A, 0x10 + OBPAL_PLAYRANK_MISSION);
			proc->unk_2A++;
			return;
		}
		break;

	case 2:
		if (proc->unk_2A < 0x78) {
			func_fe6_0808F7D0(INTERPOLATE_LINEAR, 0xF, 0, proc->unk_2A, 0x78, 0x10 + OBPAL_PLAYRANK_MISSION);
			proc->unk_2A++;
			return;
		}
		break;

	case 0x11:
		proc->unk_2E = 0;
		return;

	default:
		break;
	}

	proc->unk_2A = 0;
	proc->unk_2E++;
}

struct ProcScr CONST_DATA ProcScr_PlayRankTrialOBJ[] = {
	PROC_19,
	PROC_CALL(NewPlayRankTrialOBJ_Time),
	PROC_SLEEP(30),
	PROC_CALL(PlayRankTrialOBJ_Init),
	PROC_SLEEP(20),
	PROC_REPEAT(PlayRankTrialOBJ_Loop),
	PROC_END,
};

void PlayRankTrialOBJ_Init(ProcPtr proc)
{
	SetObjAffine(0xA, 0x100, 0, 0, 0x100);
	SetObjAffineAuto(0x1F, 0, 2, 0x100);

	gPlayRankMissonObjSelect = (gPlayRankMissionCompleted) ? 1 : 2;

	SpawnProc(ProcScr_0868B730, PROC_TREE_3);
	SpawnProc(ProcScr_0868B80C, PROC_TREE_3);
	SpawnProc(ProcScr_0868B88C, PROC_TREE_3);
}

void PlayRankTrialOBJ_Loop(ProcPtr proc)
{
	int i;

	for (i = 0; i < (gpPlayRankSt->step + 1); i++) {
		int oam0_y, oam1_x, oam2;

		oam1_x = (gpPlayRankSt->xs[i] + 6) * 8;
		oam0_y = (gpPlayRankSt->ys[i] + 0) * 8;

		if (i == gpPlayRankSt->step) {
			oam1_x |= 0x3E00;
			oam0_y |= 0x0100;
		}

		oam2 = gpPlayRankSt->unk_5E[i] * 2 + 0xC0;

		PutSpriteExt(4, oam1_x, oam0_y, gpPlayRankSt->objs[i], OAM2_PAL(i + OBPAL_PLAYRANK_4) | oam2);
	}
}

struct ProcScr CONST_DATA ProcScr_PlayRank[] = {
	PROC_19,
	PROC_CALL_ARG(_StartBgm, 53),
	PROC_CALL(LockGame),
	PROC_CALL(PlayRank_InitBgConf),
	PROC_CALL(PlayRank_InitDisplay),
	PROC_CALL(FadeInBlackSpeed08),
	PROC_SLEEP(1),
	PROC_CALL(StartGreenText),
	PROC_CALL(func_fe6_0808F060),
	PROC_REPEAT(PlayRank_Loop),
	PROC_REPEAT(PlayRank_Idle),
PROC_LABEL(0),
	PROC_CALL(PlayRank_End1),
	PROC_CALL(FadeInBlackWithCallBack_Speed08),
	PROC_SLEEP(1),
	PROC_CALL(PlayRank_PrepareEnd),
	PROC_CALL(PlayRank_CheckSkipPassword),
	PROC_CALL(NewPassword),
PROC_LABEL(1),
	PROC_CALL(StartFastFadeFromBlack),
	PROC_REPEAT(WhileFadeExists),
	PROC_CALL(UnlockGame),
	PROC_END,
};

struct ProcScr CONST_DATA ProcScr_PlayRankTrail[] =
{
	PROC_19,
	PROC_CALL_ARG(_StartBgm, 53),
	PROC_CALL(LockGame),
	PROC_CALL(PlayRank_InitBgConf),
	PROC_CALL(PlayRankTrail_Init),
	PROC_CALL(FadeInBlackSpeed08),
	PROC_SLEEP(1),
	PROC_CALL(StartGreenText),
	PROC_REPEAT(PlayRankTrail_Loop),
	PROC_CALL(PlayRank_End1),
	PROC_CALL(FadeInBlackWithCallBack_Speed08),
	PROC_SLEEP(1),
	PROC_CALL(PlayRank_PrepareEnd),
	PROC_CALL(StartFastFadeFromBlack),
	PROC_REPEAT(WhileFadeExists),
	PROC_CALL(UnlockGame),
	PROC_END,
};

void PlayRankTrail_Init(ProcPtr proc)
{
	int i;
	struct ChapterStats *chapter_states;

	gPlayRankMissionCompleted = HasNextChapter();

	ResetText();
	UnpackUiWindowFrameGraphics();
	ResetTextFont();
	PlayRank_InitTexts();

	SetDispEnable(1, 1, 1, 1, 1);

	SetBgOffset(BG_0, 0, 0);
	SetBgOffset(BG_1, 0, 0);
	SetBgOffset(BG_2, 0, 0);
	SetBgOffset(BG_3, 0, 0);

	SetWinEnable(1, 0, 0);
	SetWin0Box(0, 0x18, -0x10, -0x78);
	SetWin0Layers(1, 1, 1, 1, 1);
	SetWOutLayers(0, 1, 1, 1, 1);

	gDispIo.win_ct.win0_enable_blend = true;
	gDispIo.win_ct.wout_enable_blend = true;

	TmFill(gBg0Tm, 0);
	TmFill(gBg1Tm, 0);
	TmFill(gBg2Tm, 0);
	TmFill(gBg3Tm, 0);

	SetBlendAlpha(6, 0x10);
	SetBlendTargetA(0, 0, 1, 0, 0);
	SetBlendTargetB(0, 0, 0, 1, 0);

	SetupXmapPlayRanks();

	ApplyBgPalettes(Pal_PlayRankWmBG, BGPAL_PLAYRANK_WM, 2);
	ApplyBgPalette(Pal_PlayRankFogBG, BGPAL_PLAYRANK_FOG);
	ApplyObPalette(Pal_PlayRankTimeOBJ, BGPAL_PLAYRANK_TIME);
	ApplyObPalette(
		gPlayRankMissionCompleted == false
			? Pal_PlayRankMissionCompletesOBJ + 0x10
			: Pal_PlayRankMissionCompletesOBJ,
		OBPAL_PLAYRANK_MISSION);
	ApplyObPalette(Pal_08342A98, OBPAL_PLAYRANK_B);

	Decompress(Img_PlayRankTimeOBJ, OBJ_VRAM0 + OBCHR_PLAYRANK_TIME * CHR_SIZE);
	Decompress(Img_PlayRankCharacters, OBJ_VRAM0 + BGCHR_PLAYRANK_C0 * CHR_SIZE);
	Decompress(Img_PlayRankMissionCompletesOBJ, OBJ_VRAM0 + BGCHR_PLAYRANK_180 * CHR_SIZE);
	Decompress(Img_PlayRankFogBG, (u8 *)BG_VRAM + BGCHR_PLAYRANK_680 * CHR_SIZE);
	Decompress(Img_WorldMap_PlayRank, (u8 *)BG_VRAM + GetBgChrOffset(BG_3));
	FillPlayRankFogsToBG(gBg2Tm, 0x280, BGPAL_PLAYRANK_FOG);
	TmApplyTsa(gBg3Tm, Tsa_08340ED8, OAM2_PAL(BGPAL_PLAYRANK_WM));

	for (i = 0; i < PLAYRANK_TRAIL_TEXT_MAX; i++)
		InitText(&gpPlayRankSt->texts_rank_name[i], 6);

	chapter_states = GetXmapChapterStats();

	PutNumber(gBg0Tm + TM_OFFSET(5, 7), TEXT_COLOR_SYSTEM_BLUE, chapter_states->chapter_turn);
	PutDrawText(NULL, gBg0Tm + TM_OFFSET(6, 7), TEXT_COLOR_SYSTEM_WHITE, 0, 6, DecodeMsg(MSG_Turn));
	PutTime(gBg0Tm + TM_OFFSET(18, 7), TEXT_COLOR_SYSTEM_BLUE, chapter_states->chapter_time * 180, true);

	for (i = 0; i < PLAYRANK_TRAIL_TEXT_MAX; i++) {
		PutDrawText(
			&gpPlayRankSt->texts_rank_name[i],
			gBg0Tm + TM_OFFSET(gTotalPlayRankConf2[i].x - 1, gTotalPlayRankConf2[i].y),
			gTotalPlayRankConf2[i].color,
			0, 6,
			DecodeMsg(gTotalPlayRankConf2[i].msg)
		);
	}

	SpawnProc(ProcScr_PlayRankFogHandler, PROC_TREE_3);
	SpawnProc(ProcScr_PlayRankTrialOBJ, PROC_TREE_3);
	EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT | BG2_SYNC_BIT | BG3_SYNC_BIT);
}

void PlayRankTrail_Loop(ProcPtr proc)
{
	if (gKeySt->pressed & (KEY_BUTTON_A | KEY_BUTTON_B))
		if (gpPlayRankSt->step == 3)
			Proc_Break(proc);
}

void NewPlayRank_unused(ProcPtr proc)
{
	if (!proc)
		SpawnProc(ProcScr_PlayRank, PROC_TREE_3);
	else
		SpawnProcLocking(ProcScr_PlayRank, proc);
}

void NewPlayRankTrail(ProcPtr proc)
{
	if (!proc)
		SpawnProc(ProcScr_PlayRankTrail, PROC_TREE_3);
	else
		SpawnProcLocking(ProcScr_PlayRankTrail, proc);
}

