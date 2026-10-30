#include "prelude.h"
#include "hardware.h"
#include "proc.h"
#include "event.h"
#include "sound.h"
#include "sprite.h"
#include "spriteanim.h"
#include "armfunc.h"
#include "scanline.h"
#include "util.h"
#include "msg.h"
#include "oam.h"
#include "titlescreen.h"
#include "gamecontroller.h"
#include "banim.h"
#include "unknown_objects.h"
#include "worldmap.h"
#include "random.h"
#include "gbasvc.h"
#include "constants/songs.h"
#include "constants/msg.h"
#include "constants/videoalloc.h"
#include "opanim.h"

EWRAM_OVERLAY(opanim) u8 OpAnimGlyphBuffer[0x2800] = {};
EWRAM_OVERLAY(opanim) int OpAnimGlyphIndex = 0;
EWRAM_OVERLAY(opanim) u8 gOpAnimBgTmBuf[0x2000] = {};

CONST_DATA struct ProcScr ProcScr_TitleScreenHandler[] = {
	PROC_START_CHILD_LOCKING(ProcScr_TitleScreen),
	PROC_END
};

CONST_DATA int gUnk_08691490 = 0x180;
CONST_DATA int gUnk_08691494 = 0x40;
CONST_DATA int gUnk_08691498 = 0x6E;
CONST_DATA int gUnk_0869149C = 8;
CONST_DATA int gUnk_086914A0 = 0x28;
CONST_DATA int gUnk_086914A4 = 3;
CONST_DATA int gUnk_086914A8 = 0x1F4;
CONST_DATA int gUnk_086914AC = 0xA0;
CONST_DATA int gUnk_086914B0 = 0x96;
CONST_DATA int gUnk_086914B4 = 0x5C;
CONST_DATA int gUnk_086914B8 = 0xC8;
CONST_DATA int gUnk_086914BC = 0x64;
CONST_DATA int gUnk_086914C0 = 0x82;
CONST_DATA int gUnk_086914C4 = 0xB4;
CONST_DATA int gUnk_086914C8 = 0x80;
CONST_DATA int gUnk_086914CC = 0x30;
CONST_DATA int gUnk_086914D0 = 2;
CONST_DATA int gUnk_086914D4 = 4;
CONST_DATA int gUnk_086914D8 = 2;
CONST_DATA int gUnk_086914DC = 3;
CONST_DATA int gUnk_086914E0 = 0x1E0;
CONST_DATA int gUnk_086914E4[3] = { 2, 0x4B0, 0xC };
CONST_DATA int gUnk_086914F0 = 0x10;
CONST_DATA int gUnk_086914F4 = 0xF;
CONST_DATA int gUnk_086914F8 = 8;

void StartOpAnim_unused(void)
{
	SpawnProc(ProcScr_OpAnim, PROC_TREE_3);
}

CONST_DATA struct ProcScr ProcScr_OpAnimfxTerminator[] = {
	PROC_REPEAT(OpAnimfxTerminator_Loop),
	PROC_END
};

void OpAnimfxTerminator_Loop(ProcPtr proc)
{
	if (gKeySt->pressed & (KEY_BUTTON_A | KEY_BUTTON_B | KEY_BUTTON_START)) {
		SetNextGameAction(GAME_ACTION_2);

		bool_opanim_03005284 = true;

		Proc_EndEachMarked(PROC_MARK_OPANIM);
		OpAnim_ResetDispIO();
		FadeBgmOut(1);
		Proc_Break(proc);
	}
}

struct ProcScr CONST_DATA ProcScr_OpAnim[] = {
	PROC_ONEND(OpAnim_OnEnd),
	PROC_CALL(OpAnim_Init),
	PROC_SLEEP(0),
	PROC_START_CHILD(ProcScr_OpAnimfxTerminator),
	PROC_SLEEP(0),
	PROC_START_CHILD_LOCKING(ProcScr_OpAnim_Nintendo),
	PROC_SLEEP(0),
	PROC_CALL(OpAnim_StartBGM),
	PROC_CALL(OpAnim_StartTimer),
	PROC_START_CHILD_LOCKING(ProcScr_OpAnim1),
	PROC_SLEEP(0),
	PROC_CALL(OpAnimAdvance),
	PROC_START_CHILD_LOCKING(ProcScr_OpAnim2),
	PROC_SLEEP(0),
	PROC_CALL(OpAnimAdvance),
	PROC_START_CHILD_LOCKING(ProcScr_OpAnim3),
	PROC_SLEEP(0),
	PROC_CALL(OpAnimAdvance),
	PROC_START_CHILD_LOCKING(ProcScr_OpAnim4),
	PROC_SLEEP(0),
	PROC_CALL(OpAnimAdvance),
	PROC_START_CHILD_LOCKING(ProcScr_OpAnim5),
	PROC_SLEEP(0),
	PROC_CALL(OpAnimAdvance),
	PROC_START_CHILD_LOCKING(ProcScr_OpAnim6),
	PROC_SLEEP(0),
	PROC_CALL(OpAnimAdvance),
	PROC_END_EACH(ProcScr_OpAnimfxTerminator),
	PROC_START_CHILD_LOCKING(ProcScr_TitleScreenFromOp),
	PROC_SLEEP(0),
	PROC_END,
};

void OpAnim_ResetDispIO(void)
{
	gPal[0] = 0;

	SetDispEnable(0, 0, 0, 0, 0);
	SetWinEnable(0, 0, 0);
	SetBlendNone();
}

void OpAnim_OnEnd(void)
{}

u16 CONST_DATA BgConf_OpAnim_08691604[12] = {
	// tile offset  map offset  screen size
	0x0000,         0xA000,     0,          // BG 0
	0x0000,         0xA800,     0,          // BG 1
	0xC000,         0xB000,     0,          // BG 2
	0x8000,         0xB800,     0,          // BG 3
};

void OpAnim_Init(void)
{
	InitBgs(BgConf_OpAnim_08691604);
	SetDispEnable(1, 1, 1, 1, 1);
	SetWinEnable(0, 0, 0);
	SetAllBlackPals();
	EnablePalSync();
	OpAnim_SetupGlyph(0);
	bool_opanim_03005284 = false;
}

void func_fe6_080988BC(void)
{}

u16 CONST_DATA BgConf_OpAnim_0869161C[12] = {
	// tile offset  map offset  screen size
	0x0000,         0xA000,     0,          // BG 0
	0x4000,         0xA800,     0,          // BG 1
	0xC000,         0xB000,     0,          // BG 2
	0x8000,         0xB800,     0,          // BG 3
};

void OpAnim6_ResetBG(void)
{
	InitBgs(BgConf_OpAnim_0869161C);
	Clear4bppFirstTm();

	gDispIo.disp_ct.mode = 0;
	SetDispEnable(1, 1, 0, 0, 1);
	SetWinEnable(0, 0, 0);
	SetBlendNone();
}

void OpAnim_SetWin0Layers(int bg0, int bg1, int bg2, int bg3, int obj)
{
	SetWinEnable(1, 0, 0);
	SetWin0Box(0, 0x10, 0xF0, 0x90);
	SetWin0Layers(bg0, bg1, bg2, bg3, obj);
	SetWOutLayers(0, 0, 0, 0, 0);

	gDispIo.win_ct.win0_enable_blend = 1;
	gDispIo.win_ct.wout_enable_blend = 0;

	EnablePalSync();
}

void OpAnim_StartBGM(void)
{
	if (!bool_opanim_03005284)
		StartBgmCore(SONG_42, NULL);
}

struct ProcScr CONST_DATA ProcScr_OpAnimTimer[] = {
	PROC_CALL(OpAnimTimer_Init),
	PROC_REPEAT(OpAnimTimer_Loop),
};

void OpAnim_StartTimer(ProcPtr proc)
{
	int i;

	for (i = 0; i < 8; i++)
		gOpAnimStep[i] = 0;

	SpawnProc(ProcScr_OpAnimTimer, proc);
}

void OpAnimTimer_Init(struct ProcOpAnimTimer *proc)
{
	proc->timer = 0;
}

void OpAnimTimer_Loop(struct ProcOpAnimTimer *proc)
{
	proc->timer++;
}

void OpAnimAdvance(void)
{
	struct ProcOpAnimTimer *timer;

	timer = FindProc(ProcScr_OpAnimTimer);

	gOpAnimStep[0]++;
	gOpAnimStep[gOpAnimStep[0]] = timer->timer;
}

/* opanimfx */
CONST_DATA char OpAnimTextRef[] =
	"あいえかきくけこさしすそたちつてとにのはまもよりるれをがずだっ　神人近時代祝福英雄存亡未来戦世界光導剣闇炎宿尊紋章幾多空間物語　・「」２０ＮｉｎｔｅｄｏＰｒｓ　";

CONST_DATA u8 OpAnimTextLenRef[] = {
	0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F,
	0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F,
	0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F,
	0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x06,
	0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F,
	0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F,
	0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F,
	0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x06,
	0x08, 0x08, 0x08, 0x07, 0x07, 0x09, 0x05, 0x07,
	0x06, 0x07, 0x07, 0x07, 0x08, 0x07, 0x06, 0x06,
	0x00,
};

CONST_DATA int Msgs_OpAnim_08691738[] = {
	MSG_C08,
	MSG_C09,
	MSG_C0A,
	MSG_C0C,
	MSG_C0D,
	MSG_C0E,
	MSG_C0F, // "２００２ Ｎｉｎｔｅｎｄｏ Ｐｒｅｓｅｎｔｓ"
	MSG_C0B, // "闇よりいずるものたち"
};

CONST_DATA u16 gUnk_08691758[][5] = {
	{ 0, 0, 0, 0, 0 },
	{ 60, 60, 0, 0, 0 },
	{ 0, 0, 0, 0, 0 },
};

CONST_DATA struct OpAnimSubtitleConf gOpAnimSubtitleConf[] = {
	{ .unk_00 = 60, .unk_02 = 0x180, .unk_04 = 0,     .unk_08 = gUnk_08691758[0] },
	{ .unk_00 = 50, .unk_02 = 0x180, .unk_04 = 0,     .unk_08 = gUnk_08691758[0] },
	{ .unk_00 = 60, .unk_02 = 0x180, .unk_04 = 0x400, .unk_08 = gUnk_08691758[1] },
	{ .unk_00 = 50, .unk_02 = 0x180, .unk_04 = 0,     .unk_08 = gUnk_08691758[0] },
	{ .unk_00 = 60, .unk_02 = 0x180, .unk_04 = 0,     .unk_08 = gUnk_08691758[0] },
	{ .unk_00 = 60, .unk_02 = 0x140, .unk_04 = 0,     .unk_08 = gUnk_08691758[2] },
	{ .unk_00 = 60, .unk_02 = 0,     .unk_04 = 0,     .unk_08 = gUnk_08691758[0] },
	{ .unk_00 = 70, .unk_02 = 0x180, .unk_04 = 0x400, .unk_08 = gUnk_08691758[0] },
};

void PutOpAnimSubtitle0(void)
{
	OpAnim_PutSubtitle(0);
}

void PutOpAnimSubtitle1(void)
{
	OpAnim_PutSubtitle(1);
}

void PutOpAnimSubtitle2(void)
{
	OpAnim_PutSubtitle(2);
}

void PutOpAnimSubtitle3(void)
{
	OpAnim_PutSubtitle(3);
}

void PutOpAnimSubtitle4(void)
{
	OpAnim_PutSubtitle(4);
}

void PutOpAnimSubtitle5(void)
{
	OpAnim_PutSubtitle(5);
}

void PutOpAnimSubtitle6(void)
{
	OpAnim_PutSubtitle(6);
}

void PutOpAnimSubtitle7(void)
{
	OpAnim_PutSubtitle(7);
}

void OpAnim_SetupGlyph(int pal_id)
{
	ApplyPalette(Pal_OpAnimGlyphs + PAL_OFFSET(pal_id), 0x10 + OBPAL_OPANIM_0F);
	ResetOpAnimTextIndexMask();
	PutImg_OpAnimGlyphs();
}

void OpAnim_PutSubtitle(int idx)
{
	const char *str = DecodeMsg(Msgs_OpAnim_08691738[idx]);
	u16 *unk_08 = gOpAnimSubtitleConf[idx].unk_08;
	int unk_00 = gOpAnimSubtitleConf[idx].unk_00;
	int unk_r8 = 0;

	while (str != NULL) {
		NewOpAnimSubtitleDisp(idx, unk_00, unk_r8, str);

		str = GetOpAnimTextPrNext(str);
		unk_00 += 20;

		if (gOpAnimSubtitleConf[idx].unk_02 != 0) {
			unk_r8 += gUnk_08691498 + *unk_08;
			unk_08++;
		}
	}
}

struct ProcScr CONST_DATA ProcScr_OpAnimSubtitleDisp[] = {
	PROC_MARK(9),
	PROC_CALL(OpAnimSubtitleDisp_Init),
	PROC_REPEAT(OpAnimSubtitleDisp_Wait),
	PROC_SLEEP(0),
	PROC_CALL(OpAnimSubtitleDisp_Setup),
	PROC_REPEAT(OpAnimSubtitleDisp_Loop),
	PROC_END,
};

struct ProcScr CONST_DATA ProcScr_Unk_08691810[] = {
	PROC_CALL(func_fe6_08098CC0),
	PROC_REPEAT(func_fe6_08098D10),
	PROC_END,
};

struct ProcScr CONST_DATA ProcScr_Unk_08691828[] = {
	PROC_CALL(func_fe6_08098DB0),
	PROC_REPEAT(func_fe6_08098DEC),
	PROC_END,
};

struct ProcScr CONST_DATA ProcScr_Unk_08691840[] = {
	PROC_CALL(func_fe6_08098E74),
	PROC_REPEAT(func_fe6_08098EC8),
	PROC_END,
};

struct ProcScr CONST_DATA ProcScr_OpAnimText[] = {
	PROC_MARK(9),
	PROC_SLEEP(0),
	PROC_CALL(OpAnimText_Init1),
	PROC_REPEAT(OpAnimText_Loop1),
	PROC_CALL(OpAnimText_Init2),
	PROC_REPEAT(OpAnimText_Loop2),
	PROC_END,
};

void NewOpAnimSubtitleDisp(int idx, int a, int delay, const char *str)
{
	struct ProcOpAnimText *proc;

	proc = SpawnProc(ProcScr_OpAnimSubtitleDisp, PROC_TREE_3);
	proc->delay_timer = delay;
	proc->str = str;
	proc->unk_30 = a;
	proc->index = idx;
}

void OpAnimSubtitleDisp_Init(struct ProcOpAnimText *proc)
{
	proc->delay_timer = 0;
}

void OpAnimSubtitleDisp_Wait(struct ProcOpAnimText *proc)
{
	proc->delay_timer--;

	if (proc->delay_timer <= 0)
		Proc_Break(proc);
}

void OpAnimSubtitleDisp_Setup(struct ProcOpAnimText *proc)
{
	proc->x_center = (0xF0 - GetOpAnimTextStrLength(proc->str)) / 2;
	proc->unk_64 = 0;
}

void OpAnimSubtitleDisp_Loop(struct ProcOpAnimText *proc)
{
	const char *str = proc->str;
	const struct OpAnimSubtitleConf *conf = &gOpAnimSubtitleConf[proc->index];

	proc->unk_64 = 1 - proc->unk_64;
	if (proc->unk_64 == 0)
		return;

	do {
		switch (*str) {
		case 4:
			str++;
			break;

		default: {
			struct ProcOpAnimText *child = SpawnProc(ProcScr_OpAnimText, PROC_TREE_3);

			child->index = proc->index;
			child->x_center = proc->x_center;
			child->unk_30 = conf->unk_04 + (proc->unk_30 & 0xFF);
			child->unk_4A = GetOpAnimTextIndex(str);
			proc->x_center += GetOpAnimTextChLength(str);
			str += 2;
			break;
		}

		case 0:
		case 1:
			Proc_Break(proc);
			return;
		}

		proc->str = str;
	} while (conf->unk_02 == 0);
}

void func_fe6_08098C90(void)
{
}

void RemoveOpAnimText(void)
{
	Proc_EndEach(ProcScr_OpAnimText);
}

void BreakOpAnimText(void)
{
	OpAnimGlyphIndex = 0;
	Proc_BreakEach(ProcScr_OpAnimText);
}

void func_fe6_08098CC0(struct ProcOpAnimText *proc)
{
	proc->unk_64 = 0;
	SetBlendTargetA(0, 0, 0, 0, 1);
	SetBlendTargetB(1, 1, 1, 0, 0);
	SetBlendBackdropB(1);
	SetBlendAlpha(0x10, 0);
}

void func_fe6_08098D10(struct ProcOpAnimText *proc)
{
	if (proc->unk_64 < 0x20) {
		proc->unk_64++;
		SetBlendAlpha(
			Interpolate(0, 0x10, 0, proc->unk_64, 0x20),
			Interpolate(0, 0, 0x10, proc->unk_64, 0x20));
	} else {
		SetBlendNone();
		RemoveOpAnimText();
		Proc_Break(proc);
	}
}

void func_fe6_08098DB0(struct ProcOpAnimText *proc)
{
	proc->unk_64 = 0;
	SetBlendTargetA(0, 0, 0, 0, 0);
	SetBlendTargetB(0, 0, 0, 0, 0);
	SetBlendBackdropB(1);
	SetBlendNone();
}

void func_fe6_08098DEC(struct ProcOpAnimText *proc)
{
	if (proc->unk_64 < 0x20) {
		proc->unk_64++;

		gDispIo.blend_ct.effect = 0;
		gDispIo.blend_coef_a = Interpolate(0, 0x10, 0, proc->unk_64, 0x20);
		gDispIo.blend_coef_b = 0;
		gDispIo.blend_y = 0;
	} else {
		SetBlendNone();
		RemoveOpAnimText();
		Proc_Break(proc);
	}
}

void func_fe6_08098E74(struct ProcOpAnimText *proc)
{
	proc->unk_64 = 0;
	SetBlendTargetA(0, 0, 1, 0, 0);
	SetBlendTargetB(0, 0, 0, 0, 1);
	SetBlendBackdropB(0);
	SetBlendAlpha(0, 0x10);
}

void func_fe6_08098EC8(struct ProcOpAnimText *proc)
{
	if (proc->unk_64 < 0x20) {
		proc->unk_64++;
		SetBlendAlpha(
			Interpolate(0, 0, 0x10, proc->unk_64, 0x20),
			Interpolate(0, 0x10, 0, proc->unk_64, 0x20));
	} else {
		SetBlendNone();
		RemoveOpAnimText();
		Proc_Break(proc);
	}
}

void OpAnimText_Init1(struct ProcOpAnimText *proc)
{
	proc->unk_64 = 0;
	func_fe6_08099424(proc->unk_4A);
	proc->unk_4A = func_fe6_0809947C(
		proc->unk_4A,
		gOpAnimSubtitleConf[proc->index].unk_02,
		proc) - 0x1000;
}

void func_fe6_08098FA8(struct ProcOpAnimText *proc)
{
	if (proc->unk_58 >= gUnk_08691494) {
		proc->unk_58 = 0;
		ClearOpAnimTextIndex(proc->index);
		Proc_Break(proc);
		OpAnimText_Loop1(proc);
		return;
	}

	proc->unk_58++;

	PutSpriteExt(
		0,
		proc->x_center + (proc->index << 9),
		0x100 + Interpolate(4, proc->unk_30 + 8, proc->unk_30, proc->unk_58, gUnk_08691494),
		Sprite_16x16,
		proc->unk_4A);

	SetObjAffineAuto(
		proc->index, 0, 0x100,
		Interpolate(4, 1, 0x100, proc->unk_58, gUnk_08691494));
}

void OpAnimText_Loop1(struct ProcOpAnimText *proc)
{
	PutSpriteExt(
		0,
		proc->x_center,
		proc->unk_30,
		Sprite_16x16,
		proc->unk_4A + proc->unk_64);
}

void OpAnimText_Init2(struct ProcOpAnimText *proc)
{
	func_fe6_08099520(proc);
}

void OpAnimText_Loop2(struct ProcOpAnimText *proc)
{
	OpAnimText_Loop1(proc);
}

void func_fe6_080990FC(struct ProcOpAnimText *proc)
{
	proc->index = GetNextOpAnimTextIndex();
	proc->unk_58 = 1;
	SetObjAffineAuto(proc->index, 0, 1, 0x100);
}

void func_fe6_08099194(struct ProcOpAnimText *proc)
{
	if (proc->unk_58 >= gUnk_08691494) {
		proc->unk_58 = 0;
		ClearOpAnimTextIndex(proc->index);
		Proc_Break(proc);
		// OpAnimText_Loop1(proc);
		return;
	}

	proc->unk_58++;

	PutSpriteExt(
		0,
		Interpolate(4, proc->x_center, proc->x_center + 0x10, proc->unk_58, gUnk_08691494) + (proc->index << 9),
		Interpolate(4, proc->unk_30, proc->unk_30 + 0x10, proc->unk_58, gUnk_08691494) + 0x100,
		Sprite_16x16,
		proc->unk_4A);

	SetObjAffineAuto(
		proc->index, 0, Interpolate(0, 0x100, 2, proc->unk_58, gUnk_08691494), 0x100);
}

void func_fe6_080992B8(void)
{
	Proc_ForEach(ProcScr_OpAnimText, (ProcFunc)func_fe6_080992D0);
}

void func_fe6_080992D0(struct ProcOpAnimText *proc)
{
	proc->unk_64 = 0x800;
}

int GetOpAnimTextIndex(const char *str)
{
	const char *ref = OpAnimTextRef;
	int i = 0;

	// JTEXT
	for (; ref[0] != '\0'; i++, ref += 2) {
		if (ref[0] == str[0] && ref[1] == str[1])
			return i;
	}
	return '@';
}

int GetOpAnimTextChLength(const char *str)
{
	int index = GetOpAnimTextIndex(str);

	return OpAnimTextLenRef[index];
}

int GetOpAnimTextStrLength(const char *str)
{
	int len = 0;

	while (str[0] != '\0') {
		switch (str[0]) {
		case 1:
			return len;

		default:
			if (str[0] == 4)
				str++;
			else {
				len = len + GetOpAnimTextChLength(str);
				str = str + 2;
			}
			break;
		}
	}
	return len;
}

const char *GetOpAnimTextPrNext(const char *str)
{
	while (*str != '\0') {
		switch (str[0]) {
		case 4:
			str = str + 1;
			break;

		case 1:
			return str + 1;

		default:
			str = str + 2;
			break;
		}
	}
	return NULL;
}

void ResetOpAnimTextIndexMask(void)
{
	int i;

	for (i = 0; i < 0x20; i++)
		gOpAnimTextMask[i >> 3] &= ~(1 << (i & 7));
}

int GetNextOpAnimTextIndex(void)
{
	int i;

	for (i = 0; i < 0x20; i++) {
		if (((gOpAnimTextMask[i >> 3] >> (i & 7)) & 1) == 0) {
			gOpAnimTextMask[i >> 3] |= (1 << (i & 7));
			return i;
		}
	}
#if BUGFIX
	return i;
#endif
}

void ClearOpAnimTextIndex(int i)
{
	gOpAnimTextMask[i >> 3] &= ~(1 << (i & 7));
}

void PutImg_OpAnimGlyphs(void)
{
	Decompress(Img_OpAnimGlyphs, OpAnimGlyphBuffer);
	OpAnimGlyphIndex = 0;
}

void func_fe6_08099424(int index)
{
	void *dst = OBJ_VRAM0 + ((((OpAnimGlyphIndex & 0x0F) * 2 + (OpAnimGlyphIndex & 0xF0) * 4 + 0x200) & 0x3FF) << 5);
	void *src = OpAnimGlyphBuffer + ((((index & 0x0F) * 2 + (index & 0xF0) * 4 + 0) & 0x3FF) << 5);

	OpAnimTextPutGlyph(src, dst, 0);
}

struct ProcScr CONST_DATA ProcScr_OpAnimGlyphFallIn[] = {
	PROC_SLEEP(0),
	PROC_CALL(OpAnimGlyphFallIn_Init),
	PROC_REPEAT(OpAnimGlyphFallIn_Loop),
	PROC_END,
};

CONST_DATA u16 gUnk_086918B0[] = {
	0x15, 0x29, 0x39, 0x2C, 0x19, 0x1D, 0x00, 0x07,
	0x08, 0x09, 0x17, 0x1A, 0x31, 0x0C, 0x21, 0x1C,
	0x18, 0x2B, 0x1B, 0x13, 0x04, 0x0B, 0x35, 0x2A,
	0x26, 0x36, 0x2D, 0x2F, 0x06, 0x02, 0x11, 0x30,
	0x1F, 0x3D, 0x25, 0x33, 0x0D, 0x10, 0x3A, 0x27,
	0x03, 0x32, 0x23, 0x28, 0x3F, 0x37, 0x0A, 0x14,
	0x01, 0x12, 0x3E, 0x2E, 0x1E, 0x20, 0x05, 0x22,
	0x34, 0x38, 0x3B, 0x0E, 0x24, 0x0F, 0x16, 0x3C,
};

int func_fe6_0809947C(int index, int speed, ProcPtr parent)
{
	int chr;
	void *dst, *src;
	struct ProcOpAnimGlyphFallIn *proc;

	chr = (OpAnimGlyphIndex & 0x0F) * 2 + (OpAnimGlyphIndex & 0xF0) * 4 + 0x200;
	dst = OBJ_VRAM0 + ((chr & 0x3FF) << 5);
	src = OpAnimGlyphBuffer + ((((index & 0x0F) * 2 + (index & 0xF0) * 4 + 0) & 0x3FF) << 5);

	OpAnimGlyphIndex++;

	// BUGFIX ???
	while (speed == 0) {
		OpAnimTextPutGlyph(src, dst, 0xFFFF);
		return chr;
	}

	proc = SpawnProc(ProcScr_OpAnimGlyphFallIn, parent);
	proc->dst = dst;
	proc->src = src;
	proc->speed = speed;
	return chr;
}

int func_fe6_08099520(ProcPtr proc)
{
	return func_fe6_0809947C(0x1F, 0x180, proc);
}

void OpAnimGlyphFallIn_Init(struct ProcOpAnimGlyphFallIn *proc)
{
	proc->step = 0;
	proc->unk_38 = 0;
	proc->unk3A = proc->speed;
}

void OpAnimGlyphFallIn_Loop(struct ProcOpAnimGlyphFallIn *proc)
{
	proc->unk_38 += proc->unk3A;

	while ((i16)proc->unk_38 > 0xFF) {
		OpAnimTextPutGlyph(proc->src, proc->dst, ++proc->step);
		proc->unk_38 -= 0x100;
	}

	if (proc->step >= 0x40)
		Proc_Break(proc);
}

void func_fe6_08099580(const u32 *src, u32 *dst, int index)
{
	int r3;

	r3 = 0xF << ((index & 7) << 2);
	index >>= 3;

	if (index >= 0x10)
		index += 0xF0;

	dst[index] = (dst[index] & ~r3) + (src[index] & r3);
}

void OpAnimTextPutGlyph(const void *src, void *dst, int index)
{
	switch (index) {
	case 0:
		CpuFastFill16(0, dst, 0x40);
		CpuFastFill16(0, dst + 0x400, 0x40);
		break;

	case 0xFFFF:
		CpuFastCopy(src, dst, 0x40);
		CpuFastCopy(src + 0x400, dst + 0x400, 0x40);
		break;

	default:
		index -= 1;

		func_fe6_08099580(src, dst, gUnk_086918B0[index] + 0x00);
		func_fe6_08099580(src, dst, gUnk_086918B0[index] + 0x40);
		func_fe6_08099580(src, dst, gUnk_086918B0[index] + 0x80);
		func_fe6_08099580(src, dst, gUnk_086918B0[index] + 0xC0);
		break;
	}
}

void func_fe6_08099644(void)
{
	func_fe6_08014ACC(0x1F, 1);
}

struct ProcScr CONST_DATA ProcScr_OpAnim1[] = {
	PROC_MARK(9),
	PROC_START_CHILD(ProcScr_Unk_086919E8),
	PROC_CALL(OpAnim1_Init),
	PROC_CALL(FadeInBlackSpeed04),
	PROC_SLEEP(0),
	PROC_SLEEP(60),
	PROC_CALL(PutOpAnimSubtitle0),
	PROC_SLEEP(30),
	PROC_CALL(func_fe6_08099750),
	PROC_SLEEP(230),
	PROC_CALL(func_fe6_08099768),
	PROC_SLEEP(44),
	PROC_CALL(func_fe6_08014790),
	PROC_CALL(func_fe6_08099644),
	PROC_SLEEP(0),
	PROC_SLEEP(8),
	PROC_CALL(BreakOpAnimText),
	PROC_SLEEP(48),
	PROC_CALL(RemoveOpAnimText),
	PROC_END,
};

struct ProcScr CONST_DATA ProcScr_Unk_086919D0[] = {
	PROC_CALL(func_fe6_08099794),
	PROC_REPEAT(func_fe6_0809979C),
	PROC_END,
};

struct ProcScr CONST_DATA ProcScr_Unk_086919E8[] = {
	PROC_CALL(func_fe6_0809980C),
	PROC_REPEAT(func_fe6_08099824),
	PROC_END,
};

void OpAnim1_Init(ProcPtr proc)
{
	if (bool_opanim_03005284) {
		Proc_End(proc);
		return;
	}

	func_fe6_08099BE4();
	func_fe6_080998D4(Tsa_OpAnim_0836A494, gBg0Tm, 320, 0);
	func_fe6_080998D4(Tsa_OpAnim_083674BC, gBg1Tm, 0,   1);
	func_fe6_080998D4(Tsa_OpAnim_0836A094, gBg3Tm, 320, 3);

	Decompress(ZPal_OpAnim_0836A888, gBuf);
	ApplyPalettes(gBuf, 0, 0x10);
	gPal[0] = 0;
	SetBlackPal(6);
	Decompress(Img_Title_08367B30, (u8 *)BG_VRAM + 0x2800 + GetBgChrOffset(BG_0));
	Decompress(Img_Title_08364AB4, (u8 *)BG_VRAM + GetBgChrOffset(BG_1));
	EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT | BG2_SYNC_BIT | BG3_SYNC_BIT);
	OpAnim_SetupGlyph(1);
	OpAnim_SetWin0Layers(1, 1, 0, 1, 1);
}

void func_fe6_08099738(ProcPtr proc)
{
	StartPalFade((const u16 *)gBuf + 0xF0, 0xE, 100, proc);
}

void func_fe6_08099750(ProcPtr proc)
{
	StartPalFade((const u16 *)gBuf + 0x60, 0x6, 180, proc);
}

void func_fe6_08099768(ProcPtr proc)
{
	SetPalFadeStop(StartPalFade(Pal_AllBlack, 0x6, 100, proc), 0x2C);
}

void func_fe6_08099784(ProcPtr proc)
{
	func_fe6_08014ACC(6, 1);
}

void func_fe6_08099794(struct Proc *proc)
{
	proc->timer1 = 0;
}

void func_fe6_0809979C(struct Proc *proc)
{
	if (proc->timer1 < 200)
		proc->timer1++;
	else
		Proc_Break(proc);

	SetBlendAlpha(Interpolate(0, 0, gUnk_0869149C, proc->timer1, 200), 0x10);
}

void func_fe6_0809980C(struct ProcOpAnimBgScroll *proc)
{
	int i;

	for (i = 0; i < 4; i++)
		proc->bg_off[i] = 0;

	proc->timer = 0;
}

void func_fe6_08099824(struct ProcOpAnimBgScroll *proc)
{
	int i;

	for (i = 0; i < 4; i++) {
		proc->bg_off[i] += gUnk_08380F4C[i];
		func_fe6_0809992C(i, proc->bg_off[i] >> 8);
		SetBgOffset(i, proc->bg_off[i] >> 8, 0);
	}
}

void func_fe6_08099868(struct ProcOpAnimBgScroll *proc)
{
	int i;
	int timer = proc->timer++;

	for (i = 0; i < 4; i++) {
		proc->bg_off[i] += Interpolate(0, gUnk_08380F4C[i], 0x200, timer, 60);
		func_fe6_0809992C(i, proc->bg_off[i] >> 8);
		SetBgOffset(i, proc->bg_off[i] >> 8, 0);
	}
}

void func_fe6_080998D4(const u16 *tsa, u16 *tm, int a, int b)
{
	Decompress(tsa, gBuf);
	PutTmLinear((u16 *)gBuf, tm, 0x800, a);
	PutTmLinear((u16 *)gBuf + 0x400, (u16 *)&gOpAnimBgTmBuf[b * 0x800], 0x800, a);
}

void func_fe6_0809992C(int bg, int x)
{
	int i;
	u16 *dst, *src;
	int col = (x / 8 - 1) & 0x1F;

	if (x > 8) {
		dst = GetTmOffsetById(bg, col, 0);
		src = (u16 *)&gOpAnimBgTmBuf[bg * 0x800 + col * 2];

		for (i = 0; i < 32; i++) {
			*dst = *src;
			dst += 0x20;
			src += 0x20;
		}

		EnableBgSyncById(bg);
	}
}

struct ProcScr CONST_DATA ProcScr_OpAnim2[] = {
	PROC_MARK(9),
	PROC_START_CHILD(ProcScr_OpAnim_08691B20),
	PROC_CALL(func_fe6_0809997C),
	PROC_CALL(FadeInBlackSpeed08),
	PROC_CALL(func_fe6_08099644),
	PROC_SLEEP(0),
	PROC_SLEEP(60),
	PROC_CALL(func_fe6_08099A2C),
	PROC_CALL(PutOpAnimSubtitle1),
	PROC_SLEEP(40),
	PROC_START_CHILD(ProcScr_Unk_08691AC0),
	PROC_SLEEP(80),
	PROC_BREAK_EACH(ProcScr_Unk_08691AC0),
	PROC_SLEEP(40),
	PROC_BREAK_EACH(ProcScr_Unk_08691AC0),
	PROC_SLEEP(80),
	PROC_BREAK_EACH(ProcScr_Unk_08691AC0),
	PROC_SLEEP(100),
	PROC_BREAK_EACH(ProcScr_OpAnim_08691B20),
	PROC_SLEEP(60),
	PROC_CALL(func_fe6_08014998),
	PROC_SLEEP(0),
	PROC_CALL(RemoveOpAnimText),
	PROC_END,
};

struct ProcScr CONST_DATA ProcScr_Unk_08691AC0[] = {
	PROC_ONEND(func_fe6_08099A84),
	PROC_CALL(func_fe6_08099A90),
	PROC_SLEEP(0),
	PROC_CALL(func_fe6_08099AD0),
	PROC_REPEAT(func_fe6_08099B18),
	PROC_CALL(func_fe6_08099AD0),
	PROC_REPEAT(func_fe6_08099B18),
	PROC_CALL(func_fe6_08099AD0),
	PROC_REPEAT(func_fe6_08099B18),
	PROC_CALL(func_fe6_08099AD0),
	PROC_REPEAT(func_fe6_08099B18),
	PROC_END,
};

struct ProcScr CONST_DATA ProcScr_OpAnim_08691B20[] = {
	PROC_CALL(func_fe6_08099B34),
	PROC_REPEAT(func_fe6_08099B44),
	PROC_BLOCK,
};

void func_fe6_0809997C(ProcPtr proc)
{
	if (bool_opanim_03005284) {
		Proc_End(proc);
		return;
	}

	func_fe6_08099CCC();
	Decompress(Img_OpAnim_0836A9AC, (u8 *)BG_VRAM + GetBgChrOffset(BG_0));
	Decompress(Img_OpAnim_0836EEFC, gBg0Tm);
	Decompress(Tsa_OpAnim_0836F610, gBuf);
	ApplyPaletteExt(gBuf, 0, 0x200);
	gPal[0] = 0;
	Decompress(Img_OpAnim_083747A4, OBJ_VRAM0);
	ApplyPaletteExt(Pal_OpAnim_08375888, 0x200, 0x20);
	gPal[0] = 0;
	EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT | BG2_SYNC_BIT | BG3_SYNC_BIT);
	OpAnim_SetWin0Layers(1, 0, 1, 0, 1);
}

void func_fe6_08099A2C(ProcPtr proc)
{
	SetBlendAlpha(0x10, 6);
	SetBlendTargetA(1, 1, 0, 0, 0);
	SetBlendTargetB(0, 0, 0, 0, 1);
	OpAnim_SetupGlyph(2);
}

void func_fe6_08099A84(struct ProcOpAnimSprite *proc)
{
	EndSpriteAnim(proc->anim);
}

void func_fe6_08099A90(struct ProcOpAnimSprite *proc)
{
	SetBlackPal(0x10);
	SetBlackPal(0x11);
	SetBlackPal(0x12);
	SetBlackPal(0x13);

	proc->unk_64 = 0;

	proc->anim = StartSpriteAnim(SpriteAnim_OpAnim_08375908, 13);
	proc->anim->oam2 = 0xC00;
}

void func_fe6_08099AD0(struct ProcOpAnimSprite *proc)
{
	if (proc->unk_64 == 2)
		StartPalFade(Pal_OpAnim_083758A8, 0x11, gUnk_086914A0, proc);

	StartPalFade(Pal_OpAnim_08375888, proc->unk_64 + 0x10, gUnk_086914A0, proc);
	proc->unk_64++;
}

void func_fe6_08099B18(struct ProcOpAnimSprite *proc)
{
	DisplaySpriteAnim(proc->anim, 0xB4 - func_fe6_08099BCC(), 0x10);
}

void func_fe6_08099B34(struct ProcOpAnim5 *proc)
{
	proc->unk_64 = 0;
	proc->unk_66 = 0;
}

void func_fe6_08099B44(struct ProcOpAnim5 *proc)
{
	proc->unk_64 += 0x18;
	func_fe6_08099BA8(proc->unk_64 >> 8);
}

void func_fe6_08099B5C(struct ProcOpAnim5 *proc)
{
	proc->unk_64 += Interpolate(0, 0x100, 0x18, proc->unk_66++, 30);
	func_fe6_08099BA8(proc->unk_64 >> 8);

	if (proc->unk_66 >= 30)
		Proc_Break(proc);
}

void func_fe6_08099BA8(int offset)
{
	SetBgOffset(BG_0, offset, 0);
	SetBgOffset(BG_2, offset, 0);
}

int func_fe6_08099BCC(void)
{
	struct ProcOpAnim5 *proc = FindProc(ProcScr_OpAnim_08691B20);

	return proc->unk_64 >> 8;
}

u16 CONST_DATA BgConf_OpAnim_08691B38[] = {
	// tile offset  map offset  screen size
	0x8000,         0x6800,     0,          // BG 0
	0x0000,         0x7000,     0,          // BG 1
	0x8000,         0x7800,     0,          // BG 2
	0x8000,         0xF800,     0,          // BG 3
};

u16 CONST_DATA BgConf_OpAnim_08691B50[] = {
	// tile offset  map offset  screen size
	0x0000,         0xE000,     1,          // BG 0
	0x0000,         0xE800,     0,          // BG 1
	0x8000,         0xF000,     1,          // BG 2
	0x0000,         0xF800,     0,          // BG 3
};

void func_fe6_08099BE4(void)
{
	InitBgs(BgConf_OpAnim_08691B38);
	DisableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT | BG2_SYNC_BIT | BG3_SYNC_BIT);

	gDispIo.disp_ct.mode = 0;
	SetDispEnable(1, 1, 0, 1, 1);
	SetWinEnable(0, 0, 0);
	SetBlendNone();

	gDispIo.bg0_ct.priority = 0;
	gDispIo.bg1_ct.priority = 1;
	gDispIo.bg2_ct.priority = 2;
	gDispIo.bg3_ct.priority = 3;

	SetBlendAlpha(0x10, 0x10);
	SetBlendTargetA(1, 0, 0, 0, 0);
	SetBlendTargetB(0, 1, 1, 1, 0);
}

void func_fe6_08099CCC(void)
{
	InitBgs(BgConf_OpAnim_08691B50);
	DisableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT | BG2_SYNC_BIT | BG3_SYNC_BIT);

	gDispIo.disp_ct.mode = 0;
	SetDispEnable(1, 0, 1, 0, 1);
	SetWinEnable(0, 0, 0);
	SetBlendNone();
}

struct ProcScr CONST_DATA ProcScr_OpAnim4[] = {
	PROC_MARK(9),
	PROC_CALL(func_fe6_08099D3C),
	PROC_START_CHILD(ProcScr_OpAnimSparksOBJ),
	PROC_SLEEP(30),
	PROC_SLEEP(20),
	PROC_CALL(func_fe6_08099DA4),
	PROC_SLEEP(0),
	PROC_CALL(func_fe6_08099E50),
	PROC_START_CHILD_LOCKING(ProcScr_Unk_08691828),
	PROC_START_CHILD(ProcScr_Unk_08691C38),
	PROC_CALL(func_fe6_08099EC0),
	PROC_CALL(FadeInBlackSpeed08Unk),
	PROC_SLEEP(0),
	PROC_START_CHILD(ProcScr_Unk_08691C58),
	PROC_SLEEP(10),
	PROC_CALL(PutOpAnimSubtitle3),
	PROC_SLEEP(100),
	PROC_BREAK_EACH(ProcScr_Unk_08691C58),
	PROC_SLEEP(240),
	PROC_END_EACH(ProcScr_Unk_08691C58),
	PROC_CALL(FadeInBlackWithCallBack_Speed04),
	PROC_CALL(func_fe6_08099644),
	PROC_SLEEP(0),
	PROC_SLEEP(1),
	PROC_END_EACH(ProcScr_OpAnimSparksOBJ),
	PROC_END,
};

struct ProcScr CONST_DATA ProcScr_Unk_08691C38[] = {
	PROC_ONEND(func_fe6_08099F9C),
	PROC_CALL(func_fe6_08099FA8),
	PROC_REPEAT(func_fe6_08099FD0),
	PROC_END,
};

struct ProcScr CONST_DATA ProcScr_Unk_08691C58[] = {
	PROC_CALL(func_fe6_0809A014),
	PROC_REPEAT(func_fe6_0809A034),
	PROC_REPEAT(func_fe6_0809A048),
	PROC_END,
};

CONST_DATA u8 gUnk_08691C78[] = { 0, 2, 3, 4, 5, 4, 3, 2 };

void func_fe6_08099D3C(ProcPtr proc)
{
	if (bool_opanim_03005284) {
		Proc_End(proc);
		return;
	}

	OpAnim6_ResetBG();

	gDispIo.bg0_ct.priority = 0;
	gDispIo.bg1_ct.priority = 3;
	gDispIo.bg2_ct.priority = 0;
	gDispIo.bg3_ct.priority = 0;

	SetDispEnable(0, 0, 0, 0, 1);
}

void func_fe6_08099DA4(ProcPtr proc)
{
	OpAnim6_ResetBG();

	gDispIo.bg0_ct.priority = 0;
	gDispIo.bg1_ct.priority = 3;
	gDispIo.bg2_ct.priority = 0;
	gDispIo.bg3_ct.priority = 0;

	SetDispEnable(0, 0, 0, 0, 1);

	Decompress(Img1_EfxForblazeBG2, (u8 *)BG_VRAM + 0x20 + GetBgChrOffset(BG_1));
	Decompress(Tsa1_EfxForblazeBG2, gBuf);
	func_fe6_08014F70(gBg1Tm, 0, 1, 1, 0x20, 0x13, (u16 *)gBuf, 0);
	OpAnim_SetWin0Layers(1, 1, 0, 0, 1);
}

void func_fe6_08099E50(ProcPtr proc)
{
	if (bool_opanim_03005284) {
		Proc_End(proc);
		return;
	}

	Decompress(gUnk_08378F54, (u8 *)BG_VRAM + 0x20 + GetBgChrOffset(BG_0));
	Decompress(gUnk_08379DCC, gBuf);
	TmApplyTsa(gBg0Tm, gBuf, 1);
	Decompress(gUnk_08379F8C, OBJ_VRAM0 + 0x800);
}

void func_fe6_08099EC0(ProcPtr proc)
{
	SetBlendAlpha(0xE, 0x10);
	SetBlendTargetA(1, 0, 0, 0, 0);
	SetBlendTargetB(0, 1, 0, 0, 1);
	SetBlendBackdropB(1);
	SetDispEnable(1, 1, 0, 0, 1);

	OpAnim_SetupGlyph(1);
	EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT | BG2_SYNC_BIT | BG3_SYNC_BIT);

	ApplyPaletteExt(gUnk_08379D0C + 0x10, 0x20, 0x20);
	gPal[0] = 0;
	ApplyPaletteExt(gUnk_08379D0C, 0, 0x20);
	gPal[0] = 0;
	SetBlackPal(0x10);

	InitScanlineEffect();
	SetOnHBlankA(OnHBlank_0806A040);
	SpawnProc(ProcScr_OpAnim_08691CC0, proc);
}

void func_fe6_08099F98(void)
{
}

void func_fe6_08099F9C(struct ProcOpAnim4 *proc)
{
	EndSpriteAnim(proc->anim);
}

void func_fe6_08099FA8(struct ProcOpAnim4 *proc)
{
	proc->anim = StartSpriteAnim(SpriteAnim_OpAnim_0837AAE8, 2);
	proc->anim->oam2 = 0x440;
	proc->y = 0xC8;
	proc->timer = 0;
}

void func_fe6_08099FD0(struct ProcOpAnim4 *proc)
{
	if (proc->timer <= gUnk_086914E0)
		proc->y = Interpolate(0, 0xC8, 0x80, proc->timer++, gUnk_086914E0);

	DisplaySpriteAnim(proc->anim, 0x78, proc->y);
}

void func_fe6_0809A014(struct ProcOpAnim4 *proc)
{
	proc->unk_64 = 0;
	StartPalFade(gUnk_0837AAC8, 0x10, 0x104, proc);
}

void func_fe6_0809A034(struct ProcOpAnim4 *proc)
{
	proc->unk_64++;
	func_fe6_0809A0A8(proc);
}

void func_fe6_0809A048(struct ProcOpAnim4 *proc)
{
	proc->unk_64++;
	func_fe6_0809A068(proc);
	func_fe6_0809A0A8(proc);
}

void func_fe6_0809A068(struct ProcOpAnim4 *proc)
{
	int idx = (proc->unk_64 >> 2) % 6;

	ApplyPaletteExt(gUnk_0837AA68 + gUnk_08380F54[idx] * 0x10, 0x200, 0x20);
	gPal[0] = 0;
}

void func_fe6_0809A0A8(struct ProcOpAnim4 *proc)
{
	int idx = (proc->unk_64 >> 3) & 7;

	ApplyPaletteExt(gUnk_08379D0C + gUnk_08691C78[idx] * 0x10, 0, 0x20);
	gPal[0] = 0;
}

struct ProcScr CONST_DATA ProcScr_OpAnimSparksOBJ[] = {
	PROC_END_IF_DUP,
	PROC_CALL(OpAnimSparksOBJ_Init),
	PROC_REPEAT(OpAnimSparksOBJ_Loop),
	PROC_SLEEP(30),
	PROC_END,
};

struct ProcScr CONST_DATA ProcScr_OpAnimSparksOBJFALL[] = {
	PROC_CALL(OpAnimSparksOBJFALL_Init),
	PROC_REPEAT(OpAnimSparksOBJFALL_Loop),
	PROC_END,
};

void OpAnimSparksOBJ_Init(struct ProcOpAnim5 *proc)
{
	PutOpAnimSparksObjGfx();
	proc->unk_64 = 0;
}

void OpAnimSparksOBJ_Loop(struct ProcOpAnim5 *proc)
{
	proc->unk_64++;

	if ((proc->unk_64 & 7) == 0)
		func_fe6_0809A13C(proc);
}

void PutOpAnimSparksObjGfx(void)
{
	Decompress(Img_OpAnimSparksOBJ, OBJ_VRAM0);
	ApplyPaletteExt(Pal_OpAnimSparksOBJ, 0x220, 0x20);
}

void func_fe6_0809A13C(ProcPtr proc)
{
	struct ProcOpAnimSparksFall *child = SpawnProc(ProcScr_OpAnimSparksOBJFALL, proc);

	child->x = DivRem(RandNextB(), 241) + 0x28;
	child->y = 0xA0;
	child->type = gUnk_08380F5A[DivRem(RandNextB(), 8)];
	child->dx = DivRem(RandNextB(), 4) + 2;
	child->dy = DivRem(RandNextB(), 4) + 3;
	child->phase = DivRem(RandNextB(), 257);
}

void OpAnimSparksOBJFALL_Init(struct ProcOpAnimSparksFall *proc)
{
	proc->timer = 0;
}

void OpAnimSparksOBJFALL_Loop(struct ProcOpAnimSparksFall *proc)
{
	int x_off = (SIN_Q12(proc->phase + proc->timer * 4) * 0x10) >> 12;
	int frame = proc->timer >> 4;
	int chr;

	if (frame > 7)
		frame = 7;

	chr = gUnk_08380F62[proc->type * 8 + frame] * 2;

	proc->x -= proc->dx;
	proc->y -= proc->dy;
	proc->timer++;

	if (proc->x + x_off < 0 || proc->y < 0) {
		Proc_Break(proc);
		return;
	}

	PutSpriteExt(2, proc->x + x_off, proc->y, Sprite_16x16, OAM2_PAL(1) + OAM2_LAYER(1) + chr);
}

struct ProcScr CONST_DATA ProcScr_OpAnim_08691CC0[] = {
	PROC_ONEND(func_fe6_08069DD8),
	PROC_CALL(func_fe6_0809A264),
	PROC_REPEAT(func_fe6_0809A26C),
	PROC_END,
};

void func_fe6_0809A264(struct ProcOpAnim5 *proc)
{
	proc->unk_64 = 0;
}

void func_fe6_0809A26C(struct ProcOpAnim5 *proc)
{
	PrepareSineWaveScanlineBuf(func_fe6_0806A87C(1, 0), proc->unk_64, gUnk_086914D4, gUnk_086914D0);
	PrepareSineWaveScanlineBuf(func_fe6_0806A87C(1, DISPLAY_HEIGHT), proc->unk_64, gUnk_086914DC, gUnk_086914D8);
	SwapScanlineBufs();
	proc->unk_64 += 2;
}

struct ProcScr CONST_DATA ProcScr_OpAnim3[] = {
	PROC_MARK(9),
	PROC_CALL(func_fe6_0809A2CC),
	PROC_CALL(func_fe6_08014984),
	PROC_SLEEP(0),
	PROC_START_CHILD(ProcScr_Unk_08691DB8),
	PROC_SLEEP(30),
	PROC_CALL(PutOpAnimSubtitle2),
	PROC_SLEEP(84),
	PROC_START_CHILD(ProcScr_Unk_08691D88),
	PROC_SLEEP(270),
	PROC_CALL(BreakOpAnimText),
	PROC_SLEEP(40),
	PROC_CALL(RemoveOpAnimText),
	PROC_SLEEP(30),
	PROC_CALL(PutOpAnimSubtitle7),
	PROC_SLEEP(90),
	PROC_START_CHILD_LOCKING(ProcScr_Unk_08691D70),
	PROC_END,
};

struct ProcScr CONST_DATA ProcScr_Unk_08691D70[] = {
	PROC_CALL(func_fe6_0809A3A4),
	PROC_REPEAT(func_fe6_0809A3D4),
	PROC_END,
};

struct ProcScr CONST_DATA ProcScr_Unk_08691D88[] = {
	PROC_CALL(func_fe6_0809A484),
	PROC_REPEAT(func_fe6_0809A4C4),
	PROC_REPEAT(func_fe6_0809A53C),
	PROC_CALL(func_fe6_0809A564),
	PROC_REPEAT(func_fe6_0809A588),
	PROC_END,
};

struct ProcScr CONST_DATA ProcScr_Unk_08691DB8[] = {
	PROC_LABEL(0),
	PROC_CALL(func_fe6_0809A6DC),
	PROC_REPEAT(func_fe6_0809A6E4),
	PROC_CALL(func_fe6_0809A804),
	PROC_REPEAT(func_fe6_0809A80C),
	PROC_END,
};

struct ProcScr CONST_DATA ProcScr_OpAnim_08691DE8[] = {
	PROC_CALL(func_fe6_0809A8A4),
	PROC_REPEAT(func_fe6_0809A8B4),
};

void func_fe6_0809A2CC(ProcPtr proc)
{
	if (bool_opanim_03005284) {
		Proc_End(proc);
		return;
	}

	func_fe6_0809A900();
	SetAllBlackPals();

	Decompress(Img_OpAnim_Fog, (u8 *)BG_VRAM + GetBgChrOffset(BG_0));
	Decompress(Tsa_OpAnim_Fog, gBg0Tm);
	Decompress(Tsa_OpAnim_Fog, gBg1Tm);
	Decompress(Tsa_OpAnim_08375B84, (u8 *)BG_VRAM + GetBgChrOffset(BG_2));
	Decompress(gUnk_08376B70, gBg2Tm);

	Decompress(Pal_Lz_OpAnim_Fog, gBuf);
	ApplyPaletteExt(gBuf, 0, 0x200);
	gPal[0] = 0;

	EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT | BG2_SYNC_BIT | BG3_SYNC_BIT);
	SpawnProc(ProcScr_OpAnim_08691DE8, proc);
	OpAnim_SetupGlyph(3);
	OpAnim_SetWin0Layers(1, 1, 1, 0, 1);
}

void func_fe6_0809A3A4(struct ProcOpAnim5 *proc)
{
	proc->unk_64 = 0;
	SetBlendTargetA(1, 0, 0, 0, 0);
	SetBlendDarken(0);
}

void func_fe6_0809A3D4(struct ProcOpAnim5 *proc)
{
	proc->unk_64++;

	SetBlendDarken(Interpolate(0, 0, gUnk_086914CC, proc->unk_64, gUnk_086914C8));

	if (proc->unk_64 == 0x20) {
		Proc_Break(proc);
		SetDispEnable(0, 0, 0, 0, 1);
		SetBlendNone();
	}
}

void func_fe6_0809A484(struct ProcOpAnim6 *proc)
{
	proc->unk_64 = 0x10;
	proc->unk_44 = 0;
	SetBlendAlpha(0, 0x10);
}

void func_fe6_0809A4C4(struct ProcOpAnim6 *proc)
{
	proc->unk_64++;
	SetBlendAlpha(Interpolate(0, 0, 0x10, proc->unk_64, gUnk_086914BC), 0x10);

	if (proc->unk_64 == gUnk_086914BC)
		Proc_Break(proc);
}

void func_fe6_0809A53C(struct ProcOpAnim6 *proc)
{
	if (proc->unk_44++ >= gUnk_086914C4)
		Proc_Break(proc);
}

void func_fe6_0809A564(struct ProcOpAnim6 *proc)
{
	proc->unk_64 = 0;
	SetBlendTargetB(0, 1, 1, 0, 0);
}

void func_fe6_0809A588(struct ProcOpAnim6 *proc)
{
	proc->unk_64++;
	SetBlendAlpha(0x10, Interpolate(0, 0x10, 0, proc->unk_64, gUnk_086914C0));

	if (proc->unk_64 == gUnk_086914C0)
		Proc_Break(proc);
}

void func_fe6_0809A600(struct ProcOpAnim6 *proc)
{
	proc->unk_64 = 0;
	SetDispEnable(1, 0, 0, 0, 1);
	SetBlendTargetA(1, 0, 0, 0, 0);
}

void func_fe6_0809A638(struct ProcOpAnim6 *proc)
{
	SetBlendDarken(Interpolate(0, 0, 0x10, proc->unk_64++, 0x20));

	if (proc->unk_64 >= 0x20) {
		SetBlendNone();
		SetDispEnable(0, 0, 0, 0, 1);
		Proc_Break(proc);
	}
}

void func_fe6_0809A6DC(struct ProcOpAnim3Zoom *proc)
{
	proc->timer = 0;
}

void func_fe6_0809A6E4(struct ProcOpAnim3Zoom *proc)
{
	int angle, radius, x, y, zoom, unk;

	SetDispEnable(1, 1, 1, 0, 1);

	if (proc->timer < gUnk_086914B8)
		proc->timer++;
	else
		Proc_Break(proc);

	angle = Interpolate(4, 0x100, 0x500, proc->timer, gUnk_086914B8);
	radius = Interpolate(4, gUnk_086914A8, 0, proc->timer, gUnk_086914B8);

	x = (gSinLut_u32[(angle + 0x100) & 0x3FF] * radius) >> 7;
	y = (gSinLut_u32[angle & 0x3FF] * radius) >> 7;

	zoom = Interpolate(4, 0, 0x4000, proc->timer, gUnk_086914B8) * 4;
	unk = Interpolate(4, gUnk_086914A4 << 8, 0x100, proc->timer, gUnk_086914B8);

	func_fe6_0809A868(x, y, zoom, unk);

	proc->x = x;
	proc->y = y;
	proc->zoom = zoom;
	proc->unk_58 = unk;
}

void func_fe6_0809A804(struct ProcOpAnim3Zoom *proc)
{
	proc->timer2 = 0;
}

void func_fe6_0809A80C(struct ProcOpAnim3Zoom *proc)
{
	int y = Interpolate(0, proc->y, proc->y - (gUnk_086914B4 << 8), proc->timer2, gUnk_086914B0);

	func_fe6_0809A868(proc->x, y, proc->zoom, proc->unk_58);

	if (proc->timer2 < gUnk_086914B0)
		proc->timer2++;
	else
		Proc_Break(proc);
}

void func_fe6_0809A868(int x, int y, int zoom, int unk)
{
	WmZoomCore(x - 0x1000, y + (gUnk_086914AC - 0x50) * 0x100, 0x6800, gUnk_086914AC * 0x100, zoom, unk, unk);
}

void func_fe6_0809A8A4(struct ProcOpAnim5 *proc)
{
	proc->unk_64 = 0;
	proc->unk_66 = 0;
}

void func_fe6_0809A8B4(struct ProcOpAnim5 *proc)
{
	proc->unk_64 += 2;
	proc->unk_66 += 3;

	SetBgOffset(BG_0, (proc->unk_64 >> 4) + 0x10, proc->unk_64 >> 3);
	SetBgOffset(BG_1, -(proc->unk_66 >> 4), proc->unk_66 >> 3);
}

u16 CONST_DATA BgConf_OpAnim_08691DF8[] = {
	// tile offset  map offset  screen size
	0x0000,         0x6800,     0,          // BG 0
	0x0000,         0x6800,     0,          // BG 1
	0x8000,         0xF000,     2,          // BG 2
	0x8000,         0xF800,     0,          // BG 3
};

void func_fe6_0809A900(void)
{
	InitBgs(BgConf_OpAnim_08691DF8);
	DisableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT | BG2_SYNC_BIT | BG3_SYNC_BIT);

	gDispIo.disp_ct.mode = 1;
	SetDispEnable(1, 1, 0, 0, 1);
	SetWinEnable(0, 0, 0);

	gDispIo.bg0_ct.priority = 0;
	gDispIo.bg1_ct.priority = 2;
	gDispIo.bg2_ct.priority = 1;
	gDispIo.bg3_ct.priority = 0;

	SetBlendAlpha(0, 0x10);
	SetBlendTargetA(1, 0, 0, 0, 0);
	SetBlendTargetB(0, 1, 1, 0, 0);
	SetBlendBackdropB(1);

	SetBgBpp(BG_0, 4);
	SetBgBpp(BG_1, 4);
	SetBgBpp(BG_2, 8);
}

void OpAnim_PutThunderStormGfx(void)
{
	Decompress(Img_OpAnimThunderStorm, (u8 *)BG_VRAM + GetBgChrOffset(BG_0));
	Decompress(Tsa_OpAnimThunderStorm, gBuf);
}

CONST_DATA struct OpAnim_08691E10 OpAnim_08691E10[] = {
	{ 0,  12, 0, 0 },
	{ 12,  5, 0, 0 },
	{ 18,  3, 0, 0 },
	{ 21, 10, 0, 0},
	{  0, 12, 1, 0 },
	{ 12,  5, 1, 0 },
	{ 18,  3, 1, 0 },
	{ 21, 10, 1, 0 },
};

void func_fe6_0809AA20(int a, int b)
{
	TmFill(gBg0Tm, 0xFF);

	func_fe6_08014E98(
		gBg0Tm, b, 0, 0,
		OpAnim_08691E10[a].tileref, 20,
		(u16 *)gBuf + OpAnim_08691E10[a].unk_00,
		OpAnim_08691E10[a].unk_02
	);

	EnableBgSync(BG0_SYNC_BIT);
}

void OpAnim6_StartBGM(struct ProcOpAnim6 *proc)
{
	if (bool_opanim_03005284 == false)
		StartBgmCore(SONG_44, 0);
}

void OpAnim6_PutThunderStormGfx(struct ProcOpAnim6 *proc)
{
	if (bool_opanim_03005284) {
		Proc_End(proc);
		return;
	}

	OpAnim6_ResetBG();
	SetAllBlackPals();
	SetDispEnable(1, 0, 0, 0, 1);
	OpAnim_PutThunderStormGfx();
	proc->unk_64 = 0;
	proc->unk_44 = 0;
}

CONST_DATA struct OpAnim_08691E30 OpAnim_08691E30[] = {
	{ 0,  8, 0x32 },
	{ 1,  4, 0xA },
	{ 3, 13, 0xF },
	{ 5, 12, 0x5 },
	{ 7,  8, 0x5 },
	{},
};

void OpAnim6_StartThunderStorm(struct ProcOpAnim6 *proc)
{
	const struct OpAnim_08691E30 *conf = &OpAnim_08691E30[proc->unk_64];

	if (conf->unk_02 == 0) {
		Proc_Break(proc);
		return;
	}

	if (proc->unk_44 != 0) {
		proc->unk_44--;
		return;
	}

	func_fe6_0809AA20(conf->unk_00, conf->tileref);
	SpawnProc(ProcScr_OpAnimThunderStorm, proc);
	proc->unk_44 = conf->unk_02;
	proc->unk_64++;
}

void OpAnimThunderStorm_Init(struct ProcOpAnim6 *proc)
{
	PlaySe(SONG_93);
	SetBlendBrighten(0x10);
	SetBlendTargetA(1, 1, 1, 1, 1);
	SetBlendBackdropA(1);
}

void OpAnimThunderStorm_PutPal1(struct ProcOpAnim6 *proc)
{
	SetBlendBrighten(0x8);
	ApplyPalette(Pal_OpAnimThunderStorm1, 0);
	gPal[0] = 0;
}

void OpAnimThunderStorm_PutPal2(struct ProcOpAnim6 *proc)
{
	SetBlendNone();
	ApplyPalette(Pal_OpAnimThunderStorm2, 0);
	gPal[0] = 0;
}

void OpAnimThunderStorm_PutPal3(struct ProcOpAnim6 *proc)
{
	ApplyPalette(Pal_OpAnimThunderStorm3, 0);
	gPal[0] = 0;
}

void OpAnimThunderStorm_PutPal4(struct ProcOpAnim6 *proc)
{
	ApplyPalette(Pal_OpAnimThunderStorm4, 0);
	gPal[0] = 0;
}

void OpAnimThunderStorm_PutPal5(struct ProcOpAnim6 *proc)
{
	ApplyPalette(Pal_AllBlack, 0);
	gPal[0] = 0;
}

void OpAnim6_PutIdunnGfx(struct ProcOpAnim6 *proc)
{
	PlaySe(SONG_94);

	TmFill(gBg0Tm, 0);
	Decompress(Img_OpAnim_Dragon, (u8 *)BG_VRAM + GetBgChrOffset(BG_0));
	Decompress(Tsa_Opanim6_0837EEB4, gBg0Tm);
	ApplyPalettes(Pal_Opanim6_0837F418, 0, 3);
	EnableBgSync(BG0_SYNC_BIT);
	SetBlendBrighten(0x10);
	SetBlendTargetA(0, 1, 1, 1, 1);
	SetBlendBackdropA(1);
}

void func_fe6_0809AD3C(struct ProcOpAnim6 *proc)
{
	SetBlendNone();
}

void func_fe6_0809AD64(struct ProcOpAnim6 *proc)
{
	SetDispEnable(0, 0, 0, 0, 0);
}

void func_fe6_0809AD88(ProcPtr proc)
{
	if (bool_opanim_03005284) {
		Proc_End(proc);
		return;
	}

	SetDispEnable(0, 0, 0, 0, 1);
}

void func_fe6_0809ADCC(ProcPtr proc)
{
	func_fe6_0809B0E8();
	Decompress(gUnk_08375ADC, (u8 *)BG_VRAM + 0x20 + GetBgChrOffset(BG_0));
	func_fe6_0809AED4();
	Decompress(Img_EndingMonologue, (u8 *)BG_VRAM + GetBgChrOffset(BG_2));
	Decompress(Tsa_EndingMonologue, (u8 *)BG_VRAM + GetBgTilemapOffset(BG_2));
	Decompress(Zpal_EndingMonologue, gBuf);
	VramCopy(gUnk_08375B64, gBuf + 0x1A0, 0x20);
	OpAnim_SetWin0Layers(1, 1, 1, 0, 1);
}

void func_fe6_0809AE60(ProcPtr proc)
{
	SetDispEnable(1, 1, 1, 0, 1);
	ApplyPaletteExt(gBuf, 0, 0x200);
	gPal[0] = 0;
}

void func_fe6_0809AEA0(void)
{
	SetDispEnable(0, 0, 0, 0, 1);
}

void func_fe6_0809AEC4(void)
{
	func_fe6_08014ACC(0xD, 1);
}

void func_fe6_0809AED4(void)
{
	int i;

	for (i = 0; i < gUnk_086914F8; i++) {
		int x = DivRem(RandNextB(), 29);
		int y = DivRem(RandNextB(), 29);

		func_fe6_08014E30(gBg0Tm, x, y, TILEREF(1, 13), 4, 4);
	}

	EnableBgSync(BG0_SYNC_BIT);
}

void func_fe6_0809AF30(ProcPtr proc)
{
	if (bool_opanim_03005284) {
		Proc_End(proc);
		return;
	}

	func_fe6_0809B188();
	EnableBgSync(BG0_SYNC_BIT | BG2_SYNC_BIT | BG3_SYNC_BIT);
	OpAnim_SetupGlyph(2);
	OpAnim_SetWin0Layers(1, 0, 1, 0, 1);
}

void func_fe6_0809AF74(struct ProcOpAnim5 *proc)
{
	proc->unk_64 = 0;
	proc->unk_66 = 0;
}

void func_fe6_0809AF84(struct ProcOpAnim5 *proc)
{
	int x0, x1, off;

	proc->unk_64++;

	x0 = proc->unk_64 * gUnk_086914F0;
	x1 = proc->unk_64 * gUnk_086914F4;

	if (proc->unk_64 & 1)
		off = 0;
	else
		off = 0x30;

	SetBgOffset(BG_0, x0 + off, off - 0x10);
	SetBgOffset(BG_1, x1 + 0x18 + off, off + 8);
}

void func_fe6_0809AFE4(struct ProcOpAnim5 *proc)
{
	func_fe6_0809AF84(proc);

	proc->unk_66++;

	SetBgOffset(BG_2, proc->unk_66 >> 3, 0);
	SetBgOffset(BG_3, proc->unk_66 >> 3, 0);
}

void func_fe6_0809B01C(struct ProcOpAnim5 *proc)
{
	proc->unk_64 = 0;
}

void func_fe6_0809B024(struct ProcOpAnim5 *proc)
{
	proc->unk_64++;

	if (proc->unk_64 >= 0x20)
		Proc_Break(proc);

	SetBlendAlpha(
		Interpolate(0, 6, 4, proc->unk_64, 0x20),
		Interpolate(0, 0, 0x10, proc->unk_64, 0x20));
}

void func_fe6_0809B094(struct ProcOpAnim5 *proc)
{
	proc->unk_64 = 0;
	proc->unk_66 = 0;
}

void func_fe6_0809B0A4(struct ProcOpAnim5 *proc)
{
	proc->unk_64 += 0xA0;
	proc->unk_66 += 0x40;

	SetBgOffset(BG_0, 0, proc->unk_64 >> 8);
	SetBgOffset(BG_2, 0, 0xB4 - (proc->unk_66 >> 8));
}

void func_fe6_0809B0E8(void)
{
	InitBgs(BgConf_OpAnim_086920A0);
	DisableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT | BG2_SYNC_BIT | BG3_SYNC_BIT);

	gDispIo.disp_ct.mode = 0;
	SetDispEnable(1, 1, 0, 0, 1);

	gDispIo.bg0_ct.priority = 0;
	gDispIo.bg1_ct.priority = 0;
	gDispIo.bg2_ct.priority = 1;
	gDispIo.bg3_ct.priority = 0;

	SetWinEnable(0, 0, 0);
	SetBlendNone();
}

void func_fe6_0809B188(void)
{
	InitBgs(BgConf_OpAnim_086920B8);
	DisableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT | BG2_SYNC_BIT | BG3_SYNC_BIT);

	gDispIo.disp_ct.mode = 0;
	SetDispEnable(1, 0, 1, 0, 1);
	SetWinEnable(0, 0, 0);
	SetBlendAlpha(6, 0);
	SetBlendTargetA(1, 0, 0, 0, 0);
	SetBlendTargetB(0, 0, 1, 0, 0);

	SetAllBlackPals();
}

void func_fe6_0809B220(u16 *tm, u16 tileref, int width, int height)
{
	int x, y, ix, iy;

	for (y = 0; y < 32; y += height) {
		for (iy = 0; iy < height; iy++) {
			for (x = 0; x < 32; x += width) {
				for (ix = 0; ix < width; ix++)
					*tm++ = tileref + iy * 0x20 + ix;
			}
		}
	}
}

void func_fe6_0809B280(ProcPtr proc)
{
	if (bool_opanim_03005284) {
		Proc_End(proc);
		return;
	}

	OpAnim6_ResetBG();
	SetAllBlackPals();
	SetDispEnable(0, 0, 0, 0, 1);
	SetBlendNone();
	OpAnim_SetupGlyph(0);
	PutOpAnimSubtitle6();
}
