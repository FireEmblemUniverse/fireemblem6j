#include "prelude.h"
#include "proc.h"
#include "banim.h"
#include "sound.h"
#include "oam.h"
#include "sprite.h"
#include "hardware.h"
#include "savemenu.h"
#include "gamecontroller.h"
#include "unit.h"
#include "util.h"
#include "unknown_objects.h"
#include "opinfo.h"

#include "constants/videoalloc.h"

EWRAM_OVERLAY(opinfo) u16 gOpInfoPalettes[0x200] = {};

struct ProcScr CONST_DATA ProcScr_OpInfo[] = {
	PROC_NAME_DEBUG("opinfo"),
	PROC_YIELD,
	PROC_CALL(OpInfo_Init),

PROC_LABEL(PL_OPINFO_BRANMCH),
	PROC_REPEAT(OpInfo_Branch),

PROC_LABEL(PL_OPINFO_IDLE),
	PROC_REPEAT(OpInfo_Idle),
	PROC_CALL(OpInfo_PostAnim),
	PROC_GOTO(PL_OPINFO_BRANMCH),

PROC_LABEL(PL_OPINFO_END_TITLE),
	PROC_CALL(StartSaveDrawFadeOut64),
	PROC_YIELD,
	PROC_GOTO(PL_OPINFO_END_EXT),

PROC_LABEL(PL_OPINFO_NAME_INTRO),
	PROC_CALL(OpInfo_FadeBgmOut),
	PROC_REPEAT(OpInfo_Idle),

PROC_LABEL(PL_OPINFO_END_EXT),
	PROC_CALL(OpInfo_EndSubProcs),
	PROC_YIELD,
	PROC_CALL(OpInfo_End),
	PROC_END,
};

void OpInfo_Init(struct ProcOpInfo *proc)
{
	gDispIo.disp_ct.mode = 0;

	InitBgs(NULL);
	NewEfxAnimeDrvProc();
	ResetClassReelSpell();

	proc->unk_2E = 0;
	proc->unk_30 = gUnk_0869056C[proc->class_set][0];
	proc->fade_speed = 0;
	proc->subproc1 = NULL;
	proc->anim_proc = NULL;
	proc->subproc1 = NewOpInfoEnter(proc, proc->unk_30);

	SetDispEnable(0, 0, 0, 0, 1);
	SetBgOffset(BG_0, 0, 0);
	SetBgOffset(BG_1, 0, 0);
	SetBgOffset(BG_2, 0, 0);
	SetBgOffset(BG_3, 0, 0);

	proc->proc_start_time = GetGameTime();
	proc->proc_run_time = 0;
	proc->mode = OPINFO_STATE_IDLE;
	proc->unk_32 = 0;
}

void OpInfo_Branch(struct ProcOpInfo *proc)
{
	proc->proc_run_time = GetGameTime() - proc->proc_start_time;

	switch (proc->mode) {
	case OPINFO_STATE_IDLE:
		if (gKeySt->held & (KEY_BUTTON_A | KEY_BUTTON_B | KEY_BUTTON_START)) {
			SetNextGameAction(GAME_ACTION_0);
			Proc_Goto(proc, PL_OPINFO_NAME_INTRO);
		}
		break;

	case OPINFO_STATE_2:
		if (proc->unk_30 >= (gUnk_0869056C[proc->class_set][proc->unk_2E] + 4)) {
			proc->unk_2E++;

			if (gUnk_0869056C[proc->class_set][proc->unk_2E] == 0xFF || proc->unk_2E > 3) {
				SetNextGameAction(GAME_ACTION_1);
				Proc_Goto(proc, PL_OPINFO_END_TITLE);
				FadeBgmOut(-1);
			} else {
				proc->unk_30 = gUnk_0869056C[proc->class_set][proc->unk_2E];
				Proc_Goto(proc, PL_OPINFO_IDLE);
			}
		} else {
			proc->unk_30 = proc->unk_30 + 1;
			Proc_Goto(proc, PL_OPINFO_IDLE);
		}
		break;

	case OPINFO_STATE_3:
		proc->anim_proc = StartClassAnimDisplay(proc, proc->unk_30);
		proc->mode = OPINFO_STATE_IDLE;
		break;
	}

	proc->fade_speed = 0;
}

void OpInfo_PostAnim(struct ProcOpInfo *proc)
{
	if (proc->anim_proc != NULL)
		Proc_Goto(proc->anim_proc, 4);

	SetDispEnable(0, 0, 0, 0, 1);

	proc->subproc1 = NewOpInfoEnter(proc, proc->unk_30);
	proc->mode = OPINFO_STATE_IDLE;
}

void OpInfo_Idle(struct ProcOpInfo *proc)
{
	if (gKeySt->held & (KEY_BUTTON_A | KEY_BUTTON_B | KEY_BUTTON_START) && proc->unk_32 == 0) {
		SetNextGameAction(GAME_ACTION_0);
		proc->unk_32 = 1;
		Proc_Goto(proc, PL_OPINFO_NAME_INTRO);
	}

	if (proc->fade_speed == 0)
		EndActiveClassReelBgColorProc();

	if ((++proc->fade_speed / 2) > 0xD) {
		SetDispEnable(0, 0, 0, 0, 0);
		Proc_Break(proc);
	} else
		OpInfo_FadeOut(proc->fade_speed);
}

void OpInfo_FadeBgmOut(struct ProcOpInfo *proc)
{
	FadeBgmOut(1);
}

void OpInfo_EndSubProcs(struct ProcOpInfo *proc)
{
	if (proc->subproc1 != NULL)
		Proc_Goto(proc->subproc1, 4);

	if (proc->anim_proc != NULL)
		Proc_Goto(proc->anim_proc, 4);
}

void OpInfo_End(struct ProcOpInfo *proc)
{
	EndEfxAnimeDrvProc();
	CleanupGame(proc);
}

void StartClassDemo(u8 class_set, ProcPtr parent)
{
	struct ProcOpInfo *proc;

	proc = SpawnProcLocking(ProcScr_OpInfo, parent);
	proc->class_set = class_set;
}

struct ProcScr CONST_DATA ProcScr_OpInfoFadeOut[] = {
	PROC_19,
	PROC_SLEEP(0),
	PROC_CALL(OpInfoFadeOut_Sync),
	PROC_END,
};

void OpInfoFadeOut_Sync(struct ProcOpInfoFadeOut *proc)
{
	int i;

	for (i = 0; i < 0x200; i++)
		gOpInfoPalettes[i] = gPal[i];

	EfxPalBlackInOut(gOpInfoPalettes, 0, 0x20, proc->speed / 2);

	for (i = 0; i < 0x200; i++)
		gPal[i] = gOpInfoPalettes[i];

	EnablePalSync();
}

void OpInfo_FadeOut(u8 speed)
{
	struct ProcOpInfoFadeOut *proc;

	proc = SpawnProc(ProcScr_OpInfoFadeOut, PROC_TREE_4);
	proc->speed = speed;
}

void PutOpInfoViewLetter(u16 char_base, u8 char_index, int x, int y, u16 x_scale, u16 y_scale, u8 pal_off)
{
	int i, pal;

	/**
	 * Copy palette
	 */
	for (i = 1; i < 0x10; i++) {
		if ((i + pal_off) >= 0x10) {
			int tmp = 0xF;

			gPal[0x100 + OBPAL_OFINFOVIEW_LETTER0 * 0x10 + char_index * 0x10 + i]
				= gPal[0x100 + OBPAL_OFINFOVIEW_LETTER_REF * 0x10 + tmp];

			pal = char_index + 1;
		} else {
			gPal[0x100 + OBPAL_OFINFOVIEW_LETTER0 * 0x10 + char_index * 0x10 + i]
				= gPal[0x100 + OBPAL_OFINFOVIEW_LETTER_REF * 0x10 + i + pal_off];

			pal = char_index + 1;
		}
	}
	EnablePalSync();

	if (x_scale < 8)
		x_scale = 8;

	if (y_scale < 8)
		y_scale = 8;

	SetObjAffineAuto(char_index, 0, x_scale, y_scale);


	PutSpriteExt(
		4,
		OAM1_X(x) + (char_index << 9),
		OAM1_X(y),
		Sprites_OpInfo_08690288[char_base + char_index],
		OAM2_PAL(pal)
	);
}

void OpInfoEnter_Init(struct ProcOpInfoEnter *proc)
{
	int i, count;

	SetWinEnable(0, 0, 0);

	proc->timer = 0;

	if (proc->class_index == 0) {
		proc->sprite_base = 0;
	} else {
		count = 0;
		i = 0;

		while (1) {
			count++;

			if (Sprites_OpInfo_08690288[count] == NULL) {
				i++;

				if (i == proc->class_index) {
					proc->sprite_base = count + 1;
					break;
				}
			}
		}
	}

	proc->letter_count = 0;

	for (i = proc->sprite_base; Sprites_OpInfo_08690288[i] != NULL; i++)
		proc->letter_count++;

	if (proc->class_index > 0x13)
		Decompress(Img_OpInfoViewLettersA, OBJ_VRAM0);
	else
		Decompress(Img_OpInfoViewLettersB, OBJ_VRAM0);

	ApplyPalette(Pal_OpInfoViewLetters, 0x10);
	ApplyPalette(Pal_OpInfoViewIcon, 0x10 + OBPAL_OFINFOICON_LINE);
	ApplyPalette(Pal_OpInfoViewIcon, 0x10 + OBPAL_OFINFOICON);
	Decompress(Img_OpInfoViewIcon, OBJ_VRAM0 + 0x6000);

	for (i = 0; i < 10; i++)
		proc->letter_procs[i] = NULL;

	proc->x = (((DISPLAY_WIDTH - proc->letter_count * 28) >> 1) - 0x10) & 0x1FF;

	proc->letter_procs[0] = NewOpInfoView(proc, 0);
	proc->icon_proc = NewOpInfoIcon(proc, proc->class_index);
}

void func_fe6_08094B28(struct ProcOpInfoEnter *proc)
{
	SetBlendBrighten(0x10 - proc->timer / 2);
	SetBlendBackdropA(1);

	if (++proc->timer == 0x20) {
		proc->timer = 0;
		Proc_Break(proc);
	}
}

void OpInfoEnter_Loop_In(struct ProcOpInfoEnter *proc)
{
	if (proc->timer >= 0x60) {
		Proc_Break(proc);
		proc->timer = 0;
		return;
	}

	if (proc->timer >= 0x10) {
		int t = proc->timer - 0x10;

		if ((t & 3) == 0 && (t / 4 + 1) < proc->letter_count)
			proc->letter_procs[t / 4 + 1] = NewOpInfoView(proc, t / 4 + 1);
	}

	proc->timer++;
}

void OpInfoEnter_Loop_Out(struct ProcOpInfoEnter *proc)
{
	if (proc->timer == 20)
		Proc_Goto(proc->icon_proc, 4);

	if (proc->timer >= 80) {
		Proc_Break(proc);
		proc->timer = 0;
		proc->class_index++;
		return;
	}

	if ((u16) (proc->timer % 6) == 0 && (u16) (proc->timer / 6) < proc->letter_count)
		Proc_Break(proc->letter_procs[(u16) (proc->timer / 6)]);

	proc->timer++;
}

void OpInfoEnter_OnEnd(struct ProcOpInfoEnter *proc)
{
	int i;

	for (i = 0; i < 8; i++) {
		if (proc->letter_procs[i] != NULL)
			Proc_End(proc->letter_procs[i]);
	}

	proc->opinfo->subproc1 = NULL;
	proc->opinfo->mode = OPINFO_STATE_3;
}

ProcPtr NewOpInfoEnter(struct ProcOpInfo *parent, u8 class_index)
{
	int i;
	struct ProcOpInfoEnter *proc;

	proc = SpawnProc(ProcScr_OpInfoEnter, parent);
	proc->opinfo = parent;
	proc->class_index = class_index;

	for (i = 0; i < 10; i++)
		proc->letter_procs[i] = NULL;

	proc->icon_proc = NULL;

	return proc;
}

void OpInfoView_Init(struct ProcOpInfoView *proc)
{
	struct ProcOpInfoEnter *parent;

	proc->timer = 0;

	parent = proc->proc_parent;
	proc->sprite_base = parent->sprite_base;
	proc->x = (parent->x + proc->index * 28) & 0x1FF;
}

void OpInfoView_Loop_FadeIn(struct ProcOpInfoView *proc)
{
	int x, y;

	if (proc->index == 0) {
		int x0, y0, angle;
		u16 scale;

		x0 = (gSinLut[0x40 + 0x60] * 0x40) >> 12;
		y0 = (gSinLut[0x60] * 0x18) >> 12;

		angle = 0xC0 - proc->timer;
		x = (gSinLut[0x40 + (angle & 0xFF)] * 0x40) >> 12;
		y = (gSinLut[angle & 0xFF] * 0x18) >> 12;

		scale = 0x200 - ((proc->timer << 8) / 0x60);

		PutOpInfoViewLetter(proc->sprite_base, proc->index, ((proc->x + x) - x0) & 0x1FF, ((0x18 + y) - y0) & 0x1FF,
			scale, scale, 8 - proc->timer * 8 / 0x60);

		proc->timer += 4;

		if (proc->timer == 0x60) {
			proc->timer = 0;
			Proc_Break(proc);
		}
	} else {
		// FAKEMATCH: the first sign check is redundant, but the original needs two.
		if (proc->timer * 0x10 / 0x100 <= 0)
			y = 0x10;

		x = 0x10 - proc->timer * 0x10 / 0x100;

		if (proc->timer * 0x10 / 0x100 < 0)
			y = 0x10;
		else
			y = x;

		PutOpInfoViewLetter(proc->sprite_base, proc->index, proc->x - y, 0x18 - y, proc->timer, 0x100, 0x10 - proc->timer * 0x10 / 0x100);

		proc->timer += 0x10;

		if (proc->timer == 0x100) {
			proc->timer = 0;
			Proc_Break(proc);
		}
	}
}

void OpInfoView_Loop_Display(struct ProcOpInfoView *proc)
{
	PutOpInfoViewLetter(proc->sprite_base, proc->index, proc->x, 0x18, 0x100, 0x100, 0);
	proc->timer = 0;
}

void OpInfoView_Loop_FadeOut(struct ProcOpInfoView *proc)
{
	struct ProcOpInfoEnter *parent;
	int timer = proc->timer;
	int x_scale = 0x100 + timer;
	int y_scale = 0x100 - timer;
	int dx;

	if (proc->x > 0xFF)
		dx = -0x58 * ((timer * timer) >> 7) / 0x100;
	else
		dx = ((proc->x & 0xFF) - 0x58) * ((timer * timer) >> 7) / 0x100;

	PutOpInfoViewLetter(proc->sprite_base, proc->index, proc->x + dx, 0x18, x_scale, y_scale, proc->timer * 0x10 / 0x100);

	if (proc->timer == 0x100) {
		parent = proc->proc_parent;
		parent->letter_procs[proc->index] = NULL;
		Proc_Break(proc);
	}

	proc->timer += 8;
}

ProcPtr NewOpInfoView(struct ProcOpInfoEnter *parent, u8 index)
{
	struct ProcOpInfoView *proc;

	proc = SpawnProc(ProcScr_OpInfoView, parent);
	proc->index = index;

	return proc;
}

void func_fe6_08094F08(void)
{
	EnablePalSync();
}

void OpInfoIcon_Init(struct ProcOpInfoIcon *proc)
{
	int i;

	proc->timer = 0;

	for (i = 0; i < 0x10; i++)
		gPal[0x100 + OBPAL_OFINFOICON * 0x10 + i] = 0;

	proc->icon_bits = 0;
	proc->icon_count = 0;

	for (i = 0; i < 8; i++) {
		if (GetJInfo(OpClassDemo_JidConfig[proc->class_index])->wexp[i] == 0)
			continue;

		proc->icon_bits |= 1 << i;
		proc->icon_count++;
	}

	EnablePalSync();
}

void func_fe6_08094F94(u8 len, u8 flag)
{
	int i;
	u16 oam2 = OAM2_PAL(OBPAL_OFINFOICON_LINE);

	if (flag)
		oam2 = OAM2_PAL(OBPAL_OFINFOICON);

	PutSpriteExt(4, 0x74, 0x48, Sprite_OpInfo_086900F8, oam2);

	for (i = 0; i < len; i++) {
		if (i < len - 1) {
			PutSpriteExt(4, 0x74 - i * 8, 0x48, Sprite_OpInfo_086900F8, oam2);
			PutSpriteExt(4, 0x74 + i * 8, 0x48, Sprite_OpInfo_086900F8, oam2);
		} else {
			PutSpriteExt(4, 0x74 - i * 8, 0x48, Sprite_OpInfo_086900F0, oam2);
			PutSpriteExt(4, 0x74 + i * 8, 0x48, Sprite_OpInfo_08690100, oam2);
		}
	}
}

void func_fe6_08095034(u8 fade, u8 count, u8 bits)
{
	int i, j;
	u16 oam2 = OAM2_PAL(OBPAL_OFINFOICON_LINE);

	if (fade != 0)
		oam2 = OAM2_PAL(OBPAL_OFINFOICON);

	for (i = 0; i < 0x10; i++) {
		u16 color;

		if (fade + i < 0x10)
			color = fade + i;
		else
			color = 0xF;

		gPal[0x100 + OBPAL_OFINFOICON * 0x10 + i] = gPal[0x100 + OBPAL_OFINFOICON_LINE * 0x10 + color];
	}

	EnablePalSync();

	for (i = 0, j = 0; i < 8; i++) {
		if ((bits >> i) & 1) {
			PutSpriteExt(4, (0x88 + j * 0x20 - count * 0x20) & 0x1FF, 0x50, Sprites_OpInfo_086900BC[i], OAM2_PAL(OBPAL_OFINFOICON));
			j++;
		}
	}

	PutSpriteExt(4, 0x90, 0x50, Sprite_OpInfo_086900DC, oam2);
}

void OpInfoIcon_Loop_FadeIn(struct ProcOpInfoIcon *proc)
{
	if (++proc->timer < 0xE) {
		func_fe6_08094F94(proc->timer, 0);
	} else {
		func_fe6_08094F94(0xE, 0);
		proc->timer = 0;
		Proc_Break(proc);
	}
}

void OpInfoIcon_LoopA(struct ProcOpInfoIcon *proc)
{
	u8 fade;

	proc->timer++;

	if (proc->timer > 0x10) {
		fade = 0;
		Proc_Break(proc);
	} else {
		fade = 0x10 - proc->timer;
	}

	func_fe6_08094F94(0xE, 0);
	func_fe6_08095034(fade, proc->icon_count, proc->icon_bits);
}

void OpInfoIcon_LoopB(struct ProcOpInfoIcon *proc)
{
	func_fe6_08094F94(0xE, 0);
	func_fe6_08095034(0, proc->icon_count, proc->icon_bits);
	proc->timer = 0;
}

void OpInfoIcon_Loop_FadeOut(struct ProcOpInfoIcon *proc)
{
	proc->timer++;

	if ((proc->timer >> 1) > 0x10) {
		Proc_Break(proc);
	} else {
		func_fe6_08095034(proc->timer >> 1, proc->icon_count, proc->icon_bits);
		func_fe6_08094F94(0xE, 1);
	}
}

ProcPtr NewOpInfoIcon(struct ProcOpInfoEnter *parent, u8 class_index)
{
	struct ProcOpInfoIcon *proc;

	proc = SpawnProc(ProcScr_OpInfoIcon, parent);
	proc->class_index = class_index;

	return proc;
}
