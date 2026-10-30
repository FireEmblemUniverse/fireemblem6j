#include "prelude.h"
#include "proc.h"
#include "util.h"
#include "map.h"
#include "oam.h"

#include "banim.h"
#include "banim_ekrdragon.h"

#include "constants/songs.h"

EWRAM_OVERLAY(banim) u16 gEkrBgPaletteBackup1[0x10] = {};
EWRAM_OVERLAY(banim) u16 gEkrBgPaletteBackup2[0x10] = {};
EWRAM_OVERLAY(banim) u16 gEkrBgPaletteBackup3[0x20] = {};

struct ProcScr CONST_DATA ProcScr_EkrDragonIdunn[] = {
	PROC_19,
	PROC_REPEAT(EkrIdunn_BgFadeIn),
	PROC_REPEAT(EkrIdunn_InitBanimfx),
	PROC_REPEAT(EkrIdunn_InitBodyfx),
	PROC_REPEAT(EkrIdunn_PreMainBodyIntro),
	PROC_REPEAT(EkrIdunn_InitIntroBodyPosition),
	PROC_REPEAT(func_fe6_0805A0BC),
	PROC_REPEAT(EkrIdunn_BodyFallInAndTriggerBattleStart),
	PROC_REPEAT(EkrIdunn_BlockingInBattle),
	PROC_REPEAT(EkrDragon_0805A270),
	PROC_REPEAT(EkrDragon_0805A2BC),
	PROC_REPEAT(EkrDragon_RemoveBackground),
	PROC_REPEAT(EkrDragon_RedrawMap),
	PROC_REPEAT(EkrDragon_SyncDone),
	PROC_END,
};

void NewEkrDragonIdunn(struct BaSprite *anim)
{
	struct ProcEkrDragon *proc;

	EkrDragonProcs[GetAnimPosition(anim)] = proc = SpawnProc(ProcScr_EkrDragonIdunn, PROC_TREE_3);;
	gEkrDragonState[GetAnimPosition(anim)] = DRAGON_STATE_1;

	proc->anim = anim;
	proc->timer = 0;
}

void EkrIdunn_BgFadeIn(struct ProcEkrDragon *proc)
{
	EfxChapterMapFadeOUT(Interpolate(INTERPOLATE_SQUARE, 4, 0x10, proc->timer, 8));

	if (++proc->timer == 0x9)
		Proc_Break(proc);
}

void EkrIdunn_InitBanimfx(struct ProcEkrDragon *proc)
{
	struct BaSprite *animf, *animr;

	EkrPrepareBanimfx(proc->anim, 0x74);

	animf = MAIN_ANIM_FRONT(POS_L);
	animr = MAIN_ANIM_BACK(POS_L);

	gEkrXPosReal[POS_L] = gEkrXPosBase[POS_L] + 0x54;
	animf->xPosition = gEkrXPosBase[POS_L] + 0x54 - gEkrBgPosition;
	animr->xPosition = gEkrXPosReal[POS_L] - gEkrBgPosition;

	if (CheckSkipDragonTransfer(proc->anim) != TRUE) {
		gEkrDragonDeamonProcs[0] = NewEkrIdunnIntroDeamon1(proc->anim);
		gEkrDragonDeamonProcs[0]->x_hi = gEkrXPosBase[POS_L] - (gEkrBgPosition - 0x4E);
		gEkrDragonDeamonProcs[0]->y_hi = 0x50;
	}
	proc->timer = 0;
	Proc_Break(proc);
}

void EkrIdunn_InitBodyfx(struct ProcEkrDragon *proc)
{
	LZ77UnCompVram(Img_EkrIdunn_081C1C94, (u8 *)BG_VRAM + 0x8000);
	LZ77UnCompWram(Tsa_EkrIdunnBody0, gEkrTsaBuffer);

	EfxTmFillB(0x001F001F);
	TmFill(gBg3Tm, 0x1F);
	EnableBgSync(BG3_SYNC_BIT);

	CpuFastCopy(Pal_081C4DE8, gPal + BGPAL_OFFSET(6), 0x20);

	CpuFastCopy(gPal + BGPAL_OFFSET(6), gEkrBgPaletteBackup1, 0x20);
	CpuFastCopy(gPal + OBPAL_OFFSET(7), gEkrBgPaletteBackup2, 0x20);
	CpuFastCopy(gPal + BGPAL_OFFSET(4), gEkrBgPaletteBackup3, 0x40);

	CpuFastFill16(0, gPal + BGPAL_OFFSET(6), 0x20);
	EnablePalSync();
	Proc_Break(proc);
}

void EkrIdunn_PreMainBodyIntro(struct ProcEkrDragon *proc)
{
	struct ProcEkrDragonDeamon *procfx = gEkrDragonDeamonProcs[0];

	if (CheckSkipDragonTransfer(proc->anim) == TRUE) {
		Proc_Break(proc);
		return;
	}

	procfx->x = Interpolate(
		INTERPOLATE_SQUARE,
		procfx->x_hi + 0x30,
		procfx->x_hi,
		proc->timer,
		16);

	procfx->y = Interpolate(
		INTERPOLATE_SQUARE,
		procfx->y_hi - 0x80,
		procfx->y_hi,
		proc->timer,
		16);

	if (++proc->timer == 0x11) {
		CpuFastCopy(gEkrBgPaletteBackup1, gPal + BGPAL_OFFSET(6), 0x20);
		CpuFastCopy(gEkrBgPaletteBackup2, gPal + OBPAL_OFFSET(7), 0x20);
		EkrDragonTmCpy2(Tsa_EkrIdunn_081C4E28);
		NewEfxWhiteIN(proc->anim, 3, 100);
		EfxPlaySE(0x13F, 0x100);
		M4aPlayWithPostionCtrl(0x13F, proc->anim->xPosition, 1);

		/* ? */
		procfx = NewEfxQuake(6);
		procfx->y_hi = 0x72;

		Proc_Break(proc);
	}
}

void EkrIdunn_InitIntroBodyPosition(struct ProcEkrDragon *proc)
{
	if (CheckSkipDragonTransfer(proc->anim) == TRUE) {
		proc->procfx = NewEfxIdunnIntro(proc->anim);
		Proc_Break(proc);
		return;
	}

	gEkrDragonDeamonProcs[0]->x = gEkrXPosBase[POS_L] - (gEkrBgPosition - 0x4E);
	gEkrDragonDeamonProcs[0]->y = 0x50;

	if (gEkrBg2QuakeVec.x != 0x7FFF) {
		gEkrDragonDeamonProcs[0]->x += gEkrBg2QuakeVec.x;
		gEkrDragonDeamonProcs[0]->y += gEkrBg2QuakeVec.y;
	}

	if (gEfxQuakeExist == 0) {
		SetBgOffset(3, 0, 0x82);
		gEkrDragonDeamonProcs[0]->x = gEkrXPosBase[POS_L] - (gEkrBgPosition - 0x4E);
		gEkrDragonDeamonProcs[0]->y = 0x50;
		proc->procfx = NewEfxIdunnIntro(proc->anim);
		Proc_Break(proc);
	}
}

void func_fe6_0805A0BC(struct ProcEkrDragon *proc)
{
	int _0;
	u8 *pflag = &proc->procfx->flag;

	if (*pflag != EDRAGONFX_FLAG_DONE)
		return;

	if (CheckSkipDragonTransfer(proc->anim) == TRUE) {
		Proc_Break(proc);
		return;
	}

	_0 = 0;
	*pflag = EDRAGONFX_FLAG_END;
	proc->timer = _0;
	proc->procfx = NewEkrDragonfx_IdunnBodyAnime(proc->anim);

	gEkrDragonDeamonProcs[1] = NewEkrIdunnIntroDeamon2(proc->anim);

	if (gEkrDistanceType == EKR_DISTANCE_CLOSE)
		gEkrDragonDeamonProcs[1]->x = 0x54;
	else
		gEkrDragonDeamonProcs[1]->x = 0x34;

	gEkrDragonDeamonProcs[1]->y = -11;

	EfxPlaySE(0x144, 0x100);
	Proc_Break(proc);
}

void EkrIdunn_BodyFallInAndTriggerBattleStart(struct ProcEkrDragon *proc)
{
	int ret;
	struct ProcEkrDragonFx *procf = proc->procfx;
	struct ProcEkrDragonDeamon *procd1 = gEkrDragonDeamonProcs[0];
	struct ProcEkrDragonDeamon *procd2 = gEkrDragonDeamonProcs[1];

	if (CheckSkipDragonTransfer(proc->anim) == TRUE) {
		SetAnimStateUnHidden(GetAnimPosition(proc->anim));
		CpuFastCopy(gEkrBgPaletteBackup1, gPal + PAL_OFFSET(6), 0x20);
		gEkrDragonfxState[GetAnimPosition(proc->anim)] = TRUE;
		NewEkrIdunnBodyMain(proc->anim);
		Proc_Break(proc);
		return;
	}

	ret = Interpolate(INTERPOLATE_LINEAR, 0, 0x72, proc->timer, 0x120);
	procf->y = -ret + 0x82;
	procd1->y = ret + 0x50;
	procd2->y = ret - 11;

	if (++proc->timer == 0xFF) {
		procf->flag = 1;
		gEkrDragonDeamonProcs[0]->fxtype = 1;
		gEkrDragonDeamonProcs[1]->fxtype = 1;
		SetAnimStateUnHidden(GetAnimPosition(proc->anim));
		gEkrDragonfxState[GetAnimPosition(proc->anim)] = TRUE;
		NewEkrIdunnBodyMain(proc->anim);
		Proc_Break(proc);
		return;
	}
}

void EkrIdunn_BlockingInBattle(struct ProcEkrDragon *proc)
{
	if (gEkrDragonState[GetAnimPosition(proc->anim)] != DRAGON_STATE_ENDING)
		return;

	EndEkrIdunnBodyMain();

	if (gEkrDragonDeadFlags[GetAnimPosition(proc->anim)] == 1)
		proc->procfx = NewEkrIdunnExitAnim1(proc->anim);

	Proc_Break(proc);
}

void EkrDragon_0805A270(struct ProcEkrDragon *proc)
{
	struct ProcEkrDragonFx *procfx = proc->procfx;

	if (gEkrDragonDeadFlags[GetAnimPosition(proc->anim)] == 0) {
		proc->procfx = NewEkrIdunnExitAnim2(proc->anim, 1, 0x20);
		Proc_Break(proc);
		return;
	}

	if (procfx->flag == EDRAGONFX_FLAG_DONE) {
		procfx->flag = EDRAGONFX_FLAG_END;
		Proc_Break(proc);
	}
}

void EkrDragon_0805A2BC(struct ProcEkrDragon *proc)
{
	struct ProcEkrDragonFx *procfx = proc->procfx;

	if (gEkrDragonDeadFlags[GetAnimPosition(proc->anim)] == 1) {
		proc->procfx = NewEkrDragonfx_IdunnBaseAppear(proc->anim);
		Proc_Break(proc);
		return;
	}

	if (CheckSkipDragonTransfer(proc->anim) == TRUE) {
		if (procfx->flag == EDRAGONFX_FLAG_DONE) {
			procfx->flag = EDRAGONFX_FLAG_END;
			proc->procfx = NewEkrDragonfx_IdunnBaseAppear(proc->anim);
			EfxChapterMapFadeOUT(0x10);
			Proc_Break(proc);
		}
		return;
	}

	if (procfx->flag == EDRAGONFX_FLAG_DONE) {
		procfx->flag = EDRAGONFX_FLAG_END;
		proc->procfx = NewEkrDragonfx_IdunnBaseAppear(proc->anim);
		EfxChapterMapFadeOUT(0x10);
		gBanimValid[GetAnimPosition(proc->anim)] = false;
		SetAnimStateHidden(GetAnimPosition(proc->anim));
		Proc_Break(proc);
	}
}

void EkrDragon_RemoveBackground(struct ProcEkrDragon *proc)
{
	if (proc->procfx->flag == EDRAGONFX_FLAG_DONE) {
		proc->procfx->flag = EDRAGONFX_FLAG_END;
		TmFill(gBg3Tm, 0xF000);
		EnableBgSync(BG3_SYNC_BIT);
		proc->timer = 0;
		Proc_Break(proc);
	}
}

void EkrDragon_RedrawMap(struct ProcEkrDragon *proc)
{
	int step;

	if (proc->timer == 0) {
		ApplyChapterMapGraphics(gPlaySt.chapter);
		RenderMap();
	}

	step = Interpolate(INTERPOLATE_RSQUARE, 0x10, 4, proc->timer, 8);
	EfxChapterMapFadeOUT(step);

	proc->timer++;
	if (proc->timer == 9) {
		proc->timer = 0;
		Proc_Break(proc);
	}
}

void EkrDragon_SyncDone(struct ProcEkrDragon *proc)
{
	gEkrDragonfxState[GetAnimPosition(proc->anim)] = DRAGONFX_STATE_2;
	Proc_Break(proc);
}

/**
 * EkrDragonfx
 */
struct ProcScr CONST_DATA ProcScr_EkrDragonfx_IdunnIntro[] = {
	PROC_19,
	PROC_REPEAT(EkrDragonfx_IdunnIntro_Main),
	PROC_REPEAT(EkrDragonfx_IdunnIntro_Block),
	PROC_END,
};

ProcPtr NewEfxIdunnIntro(struct BaSprite *anim)
{
	struct ProcEkrDragonFx *proc;

	proc = SpawnProc(ProcScr_EkrDragonfx_IdunnIntro, PROC_TREE_3);
	proc->anim = anim;
	proc->flag = EDRAGONFX_FLAG_START;
	proc->timer = 0;
	return proc;
}

void EkrDragonfx_IdunnIntro_Main(struct ProcEkrDragonFx *proc)
{
	int ret = Interpolate(INTERPOLATE_SQUARE, 0, 0x10, proc->timer, 8);

	CpuFastCopy(gEkrBgPaletteBackup3, PAL_BG(BGPAL_EFX_4), 0x40);
	EfxPalBlackInOut(PAL_BG(BGPAL_EFX_0), 4, 2, ret);
	EnablePalSync();

	proc->timer++;
	if (proc->timer == 9) {
		proc->timer = 0;
		proc->flag = EDRAGONFX_FLAG_DONE;
		FillBGRect(gBg2Tm + TM_OFFSET(0, 11), 30, 5, 0, 0);
		EnableBgSync(BG2_SYNC_BIT);
		Proc_Break(proc);
	}
}

void EkrDragonfx_IdunnIntro_Block(struct ProcEkrDragonFx *proc)
{
	if (proc->flag == EDRAGONFX_FLAG_END)
		Proc_Break(proc);
}

struct ProcScr CONST_DATA ProcScr_EkrDragonfx_IdunnBaseAppear[] = {
	PROC_19,
	PROC_REPEAT(EkrDragonfx_IdunnBaseAppear_Main),
	PROC_REPEAT(EkrDragonfx_IdunnBaseAppear_Block),
	PROC_END,
};

ProcPtr NewEkrDragonfx_IdunnBaseAppear(struct BaSprite *anim)
{
	struct ProcEkrDragonFx *proc;

	proc = SpawnProc(ProcScr_EkrDragonfx_IdunnBaseAppear, PROC_TREE_3);
	proc->anim = anim;
	proc->flag = EDRAGONFX_FLAG_START;
	proc->timer = 0;

	NewEkrTerrainfx(&gEkrTerrainfxDesc);
	CpuFastCopy(PAL_BG(BGPAL_EFX_4), gEkrBgPaletteBackup3, 0x40);
	EfxPalBlackInOut(PAL_BG(BGPAL_EFX_0), 4, 2, 0x10);
	return proc;
}

void EkrDragonfx_IdunnBaseAppear_Main(struct ProcEkrDragonFx *proc)
{
	int ret = Interpolate(INTERPOLATE_SQUARE, 0x10, 0, proc->timer, 8);

	CpuFastCopy(gEkrBgPaletteBackup3, PAL_BG(BGPAL_EFX_4), 0x40);
	EfxPalBlackInOut(PAL_BG(BGPAL_EFX_0), 4, 2, ret);
	EnablePalSync();

	if (++proc->timer == 0x9) {
		proc->timer = 0;
		proc->flag = EDRAGONFX_FLAG_DONE;
		Proc_Break(proc);
	}
}

void EkrDragonfx_IdunnBaseAppear_Block(struct ProcEkrDragonFx *proc)
{
	if (proc->flag == EDRAGONFX_FLAG_END)
		Proc_Break(proc);
}

struct ProcScr CONST_DATA ProcScr_EkrDragonfx_IdunnBodyAnime[] = {
	PROC_19,
	PROC_REPEAT(EkrDragonfx_IdunnBodyAnime_Main),
	PROC_REPEAT(EkrDragonfx_IdunnBodyAnime_End),
	PROC_END,
};

ProcPtr NewEkrDragonfx_IdunnBodyAnime(struct BaSprite *anim)
{
	struct ProcEkrDragonFx *proc;

	proc = SpawnProc(ProcScr_EkrDragonfx_IdunnBodyAnime, PROC_TREE_3);
	proc->anim = anim;
	proc->x = 0;
	proc->y = 0;
	proc->timer = 9;
	proc->counter = 0;
	proc->flag = EDRAGONFX_FLAG_START;
	return proc;
}

void EkrDragonfx_IdunnBodyAnime_Main(struct ProcEkrDragonFx *proc)
{
	proc->timer++;

	if (proc->timer == 10) {
		if (proc->counter == 0)
			EkrDragonTmCpy2(Tsa_EkrIdunn_081C4E28);
		else if (proc->counter == 1)
			EkrDragonTmCpy2(Tsa_EkrIdunn_081C5264);
		else
			EkrDragonTmCpy2(Tsa_EkrIdunn_081C5688);

		proc->timer = 0;
		proc->counter++;

		if (proc->counter == 3)
			proc->counter = 0;
	}

	SetBgOffset(BG_3, proc->x, proc->y);

	if (proc->flag == EDRAGONFX_FLAG_DONE)
		Proc_Break(proc);
}

void EkrDragonfx_IdunnBodyAnime_End(struct ProcEkrDragonFx *proc)
{
	SetBgOffset(BG_3, proc->x, proc->y);
	Proc_Break(proc);
}

struct ProcScr CONST_DATA ProcScr_EkrDragonfx_IdunnExit2[] = {
	PROC_19,
	PROC_REPEAT(EkrDragonfx_IdunnExit2_Delay),
	PROC_REPEAT(EkrDragonfx_IdunnExit2_Loop2),
	PROC_REPEAT(EkrDragonfx_IdunnExit2_Done),
	PROC_END,
};

ProcPtr NewEkrIdunnExitAnim2(struct BaSprite *anim, int delay, int duration)
{
	struct ProcEkrDragonFx *proc;

	proc = SpawnProc(ProcScr_EkrDragonfx_IdunnExit2, PROC_TREE_3);

	proc->anim = anim;
	proc->flag = EDRAGONFX_FLAG_START;
	proc->timer = 0;
	proc->counter = duration;
	proc->delay = delay;

	CpuFastCopy(PAL_BG(BGPAL_EFXDRAGON_L), gEkrBgPaletteBackup1, 0x20);
	CpuFastCopy(PAL_OBJ(OBPAL_EFX_UNIT_L), gEkrBgPaletteBackup2, 0x20);

	return proc;
}

void EkrDragonfx_IdunnExit2_Delay(struct ProcEkrDragonFx *proc)
{
	proc->timer++;

	if (proc->timer == proc->delay) {
		proc->timer = 0;
		Proc_Break(proc);
	}
}

void EkrDragonfx_IdunnExit2_Loop2(struct ProcEkrDragonFx *proc)
{
	int val = Interpolate(INTERPOLATE_SQUARE, 0, 0x10, proc->timer, proc->counter);
	i16 time;

	CpuFastCopy(gEkrBgPaletteBackup1, PAL_BG(BGPAL_EFXDRAGON_L), 0x20);
	CpuFastCopy(gEkrBgPaletteBackup2, PAL_OBJ(OBPAL_EFX_UNIT_L), 0x20);

	EfxPalBlackInOut(PAL_BG(0), BGPAL_EFXDRAGON_L, 1, val);
	EfxPalBlackInOut(PAL_BG(0), OBPAL_EFX_UNIT_L + 0x10, 1, val);

	EnablePalSync();

	time = ++proc->timer;
	if (time == (proc->counter + 1)) {
		proc->flag = EDRAGONFX_FLAG_DONE;
		Proc_Break(proc);
	}
}

void EkrDragonfx_IdunnExit2_Done(struct ProcEkrDragonFx *proc)
{
	if (proc->flag == EDRAGONFX_FLAG_END)
		Proc_Break(proc);
}

struct ProcScr CONST_DATA ProcScr_EkrIdunnDeamon1[] = {
	PROC_19,
	PROC_REPEAT(EkrIdunnDeamon1_Loop),
	PROC_END,
};

ProcPtr NewEkrIdunnIntroDeamon1(struct BaSprite *anim)
{
	struct ProcEkrDragonFx *proc;
	struct BaSprite *new_anim;

	proc = SpawnProc(ProcScr_EkrIdunnDeamon1, PROC_TREE_3);
	proc->anim = anim;

	new_anim = BasCreate(AnimScr_EkrIdunnDeamon1, 0x78);

	new_anim->oam2 = OAM2_PAL(OBPAL_EFX_UNIT_L)
		+ OAM2_LAYER(2) + OAM2_CHR(VRAMOFF_OBJ_4000 / 0x20);

	new_anim->xPosition = proc->x = 0x180;
	new_anim->yPosition = proc->y = 0x180;

	proc->sub_anim = new_anim;
	proc->flag = EDRAGONFX_FLAG_START;
	return proc;
}

void EkrIdunnDeamon1_Loop(struct ProcEkrDragonFx *proc)
{
	struct BaSprite *anim = proc->sub_anim;

	anim->xPosition = proc->x;
	anim->yPosition = proc->y;

	if (proc->flag == EDRAGONFX_FLAG_DONE) {
		BasRemove(proc->sub_anim);
		Proc_Break(proc);
	}
}

ProcPtr NewEkrIdunnIntroDeamon2(struct BaSprite *anim)
{
	struct ProcEkrDragonFx *proc;
	struct BaSprite *new_anim;

	proc = SpawnProc(ProcScr_EkrIdunnDeamon2, PROC_TREE_3);
	proc->anim = anim;

	new_anim = BasCreate(AnimScr_EkrIdunnDeamon2, 0x78);

	new_anim->oam2 = OAM2_PAL(OBPAL_EFX_UNIT_L)
		+ OAM2_LAYER(2) + OAM2_CHR(VRAMOFF_OBJ_4000 / 0x20);

	new_anim->xPosition = 0x180;
	new_anim->yPosition = 0x180;

	proc->sub_anim = new_anim;
	proc->flag = EDRAGONFX_FLAG_START;
	return proc;
}

struct ProcScr CONST_DATA ProcScr_EkrIdunnDeamon2[] = {
	PROC_19,
	PROC_REPEAT(EkrIdunnDeamon2_Loop),
	PROC_END,
};

void EkrIdunnDeamon2_Loop(struct ProcEkrDragonFx *proc)
{
	struct BaSprite *anim = proc->sub_anim;

	anim->xPosition = proc->x;
	anim->yPosition = proc->y;

	if (proc->flag == EDRAGONFX_FLAG_DONE) {
		BasRemove(proc->sub_anim);
		Proc_Break(proc);
	}
}

struct ProcScr CONST_DATA ProcScr_EkrIdunnBodyMain[] = {
	PROC_19,
	PROC_REPEAT(EkrIdunnBodyMain_Loop),
	PROC_END,
};

const u16 *CONST_DATA TsaArray_EkrIdunnBody[] = {
	Tsa_EkrIdunnBody0,
	Tsa_EkrIdunnBody1,
	Tsa_EkrIdunnBody2,
	Tsa_EkrIdunnBody3,
	Tsa_EkrIdunnBody4,
	Tsa_EkrIdunnBody5,
	Tsa_EkrIdunnBody6,
	Tsa_EkrIdunnBody7,
	Tsa_EkrIdunnBody8
};

ProcPtr NewEkrIdunnBodyMain(struct BaSprite *anim)
{
	struct ProcEkrIdunnfx *proc;

	proc = SpawnProc(ProcScr_EkrIdunnBodyMain, PROC_TREE_3);

	proc->anim = anim;
	proc->timer = 0;
	proc->duration = false;
	proc->frame = 0;
	proc->frame_config = FrameArray_EkrIdunnBody0;
	proc->tsa = TsaArray_EkrIdunnBody;
	proc->round = anim->currentRoundType;

	gpProcEkrIdunnBodyMain = proc;
	return proc;
}

void EndEkrIdunnBodyMain(void)
{
	if (gpProcEkrIdunnBodyMain) {
		Proc_End(gpProcEkrIdunnBodyMain);
		gpProcEkrIdunnBodyMain = NULL;
	}
}

void EkrIdunnBodyMain_Loop(struct ProcEkrIdunnfx *proc)
{
	int ret;
	int round = proc->anim->currentRoundType;

	if (proc->round != round) {
		proc->round = round;
		proc->timer = 0;
		proc->duration = false;
		proc->frame = 0;

		switch (round) {
		case ANIM_ROUND_HIT_CLOSE:
		case ANIM_ROUND_MISS_CLOSE:
			proc->frame_config = FrameArray_EkrIdunnBody1;
			break;

		case ANIM_ROUND_NONCRIT_FAR:
			proc->frame_config = FrameArray_EkrIdunnBody2;
			break;

		case ANIM_ROUND_CRIT_FAR:
			proc->frame_config = FrameArray_EkrIdunnBody3;
			break;

		case ANIM_ROUND_CRIT_CLOSE:
			proc->frame_config = FrameArray_EkrIdunnBody4;
			NewEfxMagdhisEffect(proc->anim);
			break;

		case ANIM_ROUND_TAKING_MISS_CLOSE:
		case ANIM_ROUND_TAKING_MISS_FAR:
		case ANIM_ROUND_TAKING_HIT_CLOSE:
		case ANIM_ROUND_STANDING:
		case ANIM_ROUND_TAKING_HIT_FAR:
			proc->frame_config = FrameArray_EkrIdunnBody0;
			break;

		default:
			break;
		}
	}

	ret = EfxAdvanceFrameLut(&proc->timer, (i16 *)&proc->frame, proc->frame_config);

	if (ret >= 0) {
		EkrDragonTmCpy3((const u8 *)proc->tsa[ret]);
		return;
	}

	if (ret == -4) {
		if (proc->duration == 0) {
			struct Anim *anim_b = GetAnimAnotherSide(proc->anim);

			if (anim_b->flags3 & ANIM_BIT2_0008)
				proc->duration = 1;

			return;
		}

		if (CheckEkrHitDone() == true) {
			proc->timer = 0;
			proc->duration = 0;
			proc->frame++;
		}
	}
}

struct ProcScr CONST_DATA ProcScr_EkrIdunnAvoid[] = {
	PROC_19,
	PROC_REPEAT(EfxAvoidForIdunn_Loop1),
	PROC_SLEEP(20),
	PROC_REPEAT(EfxAvoidForIdunn_Loop2),
	PROC_REPEAT(EfxAvoidForIdunn_Loop3),
	PROC_END,
};

ProcPtr NewEfxAvoidForIdunn(struct BaSprite *anim)
{
	struct ProcEkrIdunnfx *proc;

	proc = SpawnProc(ProcScr_EkrIdunnAvoid, PROC_TREE_3);

	proc->anim = anim;
	proc->flag = EDRAGONFX_FLAG_START;
	proc->timer = 0;
	proc->duration = 0x10;

	CpuFastCopy(PAL_BG(BGPAL_EFXDRAGON_L), gEkrBgPaletteBackup1, 0x20);
	CpuFastCopy(PAL_OBJ(OBPAL_EFX_UNIT_L), gEkrBgPaletteBackup2, 0x20);

	EfxPlaySE(SONG_143, 0x100);

	return proc;
}

void EfxAvoidForIdunn_Loop1(struct ProcEkrIdunnfx *proc)
{
	int val = Interpolate(INTERPOLATE_SQUARE, 0, 0x10, proc->timer, proc->duration);
	i16 time;

	CpuFastCopy(gEkrBgPaletteBackup1, PAL_BG(BGPAL_EFXDRAGON_L), 0x20);
	CpuFastCopy(gEkrBgPaletteBackup2, PAL_OBJ(OBPAL_EFX_UNIT_L), 0x20);

	EfxPalBlackInOut(PAL_BG(0), BGPAL_EFXDRAGON_L, 1, val);
	EfxPalBlackInOut(PAL_BG(0), OBPAL_EFX_UNIT_L + 0x10, 1, val);

	PAL_OBJ(OBPAL_EFX_UNIT_L)[14] = gEkrBgPaletteBackup2[14];
	PAL_OBJ(OBPAL_EFX_UNIT_L)[15] = gEkrBgPaletteBackup2[15];

	EnablePalSync();

	time = ++proc->timer;
	if (time == (proc->duration + 1)) {
		proc->timer = 0;
		Proc_Break(proc);
	}
}

void EfxAvoidForIdunn_Loop2(struct ProcEkrIdunnfx *proc)
{
	int val = Interpolate(INTERPOLATE_SQUARE, 0x10, 0, proc->timer, proc->duration);
	i16 time;

	CpuFastCopy(gEkrBgPaletteBackup1, PAL_BG(BGPAL_EFXDRAGON_L), 0x20);
	CpuFastCopy(gEkrBgPaletteBackup2, PAL_OBJ(OBPAL_EFX_UNIT_L), 0x20);

	EfxPalBlackInOut(PAL_BG(0), BGPAL_EFXDRAGON_L, 1, val);
	EfxPalBlackInOut(PAL_BG(0), OBPAL_EFX_UNIT_L + 0x10, 1, val);

	PAL_OBJ(OBPAL_EFX_UNIT_L)[14] = gEkrBgPaletteBackup2[14];
	PAL_OBJ(OBPAL_EFX_UNIT_L)[15] = gEkrBgPaletteBackup2[15];

	EnablePalSync();

	time = ++proc->timer;
	if (time == (proc->duration + 1)) {
		proc->timer = 0;
		proc->flag = EDRAGONFX_FLAG_DONE;
		Proc_Break(proc);
	}
}

void EfxAvoidForIdunn_Loop3(struct ProcEkrIdunnfx *proc)
{
	Proc_Break(proc);
}

struct ProcScr CONST_DATA ProcScr_EkrIdunnExitAnim1[] = {
	PROC_19,
	PROC_REPEAT(EkrIdunnExitAnim1_Loop1),
	PROC_REPEAT(EkrIdunnExitAnim1_Loop2),
	PROC_REPEAT(EkrIdunnExitAnim1_Loop3),
	PROC_REPEAT(EkrIdunnExitAnim1_Loop4),
	PROC_END,
};

ProcPtr NewEkrIdunnExitAnim1(struct BaSprite *anim)
{
	struct ProcEkrIdunnfx *proc;

	proc = SpawnProc(ProcScr_EkrIdunnExitAnim1, PROC_TREE_3);

	proc->anim = anim;
	proc->flag = EDRAGONFX_FLAG_START;
	proc->timer = 0;

	LZ77UnCompWram(Tsa_EkrIdunn_081C4E28, gEkrTsaBuffer);
	EfxTmCpyExt(gEkrTsaBuffer, -1, gBg3Tm, 32, 30, 30, 6, 0);
	proc->procfx = NewEkrIdunnExitAnim2(proc->anim, 0x64, 0xC8);

	return proc;
}

void EkrIdunnExitAnim1_Loop1(struct ProcEkrIdunnfx *proc)
{
	proc->timer++;

	if (proc->timer == 1) {
		NewEkrIdunnDeadFlashing(proc->anim, 3, 2, 3);
		EfxPlaySE(SONG_147, 0x100);
	}

	if (proc->timer == 0x23) {
		NewEkrIdunnDeadFlashing(proc->anim, 3, 2, 3);
		EfxPlaySE(SONG_147, 0x100);
	}

	if (proc->timer == 0x32) {
		NewEkrIdunnDeadFlashing(proc->anim, 3, 2, 3);
		EfxPlaySE(SONG_147, 0x100);
	}

	if (proc->timer == 0x64) {
		proc->timer = 0;
		proc->duration = 0x12C;
		DoM4aSongNumStop(SONG_145);
		EfxPlaySE(SONG_146, 0x100);
		Proc_Break(proc);
	}
}

void EkrIdunnExitAnim1_Loop2(struct ProcEkrIdunnfx *proc)
{
	int ret, y;
	struct Anim *anim1, *anim2;

	ret = Interpolate(1, 0, 0xA0, proc->timer, proc->duration);
	y = ((-ret + 0xF0) & 0xFF) >> 3;

	SetBgOffset(BG_3, 0, 0x20 - ret);
	CpuFill16(0x1F, gBg3Tm + TM_OFFSET(0, y), 0x40);
	EnableBgSync(BG3_SYNC_BIT);

	anim1 = MAIN_ANIM_FRONT(POS_L);
	anim2 = MAIN_ANIM_BACK(POS_L);

	anim1->xPosition = gEkrXPosReal[POS_L] - gEkrBgPosition;
	anim1->yPosition = gEkrYPosReal[POS_L] + ret;
	anim2->xPosition = gEkrXPosReal[POS_L] - gEkrBgPosition;
	anim2->yPosition = gEkrYPosReal[POS_L] + ret;

	gDispIo.bg_off[3].x += gEkrBg2QuakeVec.x;
	gDispIo.bg_off[3].y += gEkrBg2QuakeVec.y;

	anim1->xPosition -= gEkrBg2QuakeVec.x;
	anim1->yPosition -= gEkrBg2QuakeVec.y;
	anim2->xPosition -= gEkrBg2QuakeVec.x;
	anim2->yPosition -= gEkrBg2QuakeVec.y;

	proc->timer++;

	if (proc->timer == 1) {
		// <!> BUGFIX
		// proc->procfx
		// bug, same  as others
		proc->anim = NewEfxQuakePure(8, 0);
	}

	if (proc->timer == 0x3C) {
		Proc_End(proc->anim);
		proc->anim = NewEfxQuakePure(9, 0);
	}

	if (proc->timer == 0x5A) {
		Proc_End(proc->anim);
		proc->anim = NewEfxQuakePure(10, 0);
	}

	if (proc->timer == 0x87)
		NewEkrIdunnDeadFlashing(proc->anim, 0x3C, 0x1E, 0x78);

	if (proc->timer == 0xC8) {
		CpuFill16(0, PAL_BG(BGPAL_EFXDRAGON_L), 0x20);
		CpuFill16(0, PAL_OBJ(OBPAL_EFX_UNIT_L), 0x20);
		EnablePalSync();

		// WTF!!!
		Proc_End(proc->procfx);
	}

	if (proc->timer == (proc->duration + 1)) {
		proc->timer = 0;

		// ...
		Proc_End(proc->anim);
		Proc_Break(proc);
	}
}

void EkrIdunnExitAnim1_Loop3(struct ProcEkrIdunnfx *proc)
{
	proc->timer++;

	if (proc->timer == 0xC8) {
		proc->flag = EDRAGONFX_FLAG_DONE;
		Proc_Break(proc);
	}
}

void EkrIdunnExitAnim1_Loop4(struct ProcEkrIdunnfx *proc)
{
	if (proc->flag == EDRAGONFX_FLAG_END)
		Proc_Break(proc);
}

struct ProcScr CONST_DATA ProcScr_EkrIdunnDeadFlashing[] = {
	PROC_19,
	PROC_REPEAT(EkrIdunnDeadFlashing_Loop1),
	PROC_REPEAT(EkrIdunnDeadFlashing_Loop2),
	PROC_REPEAT(EkrIdunnDeadFlashing_Loop3),
	PROC_REPEAT(EkrIdunnDeadFlashing_Loop4),
	PROC_END,
};

void NewEkrIdunnDeadFlashing(struct BaSprite *anim, int t0, int t1, int t2)
{
	struct ProcIdunnfxFlashing *proc;

	proc = SpawnProc(ProcScr_EkrIdunnDeadFlashing, PROC_TREE_VSYNC);
	proc->anim = anim;
	proc->timer = 0;
	proc->dura0 = t0;
	proc->dura1 = t1;
	proc->dura2 = t2;

	SetBlendBackdropA(0);
	SetBlendBackdropB(0);
}

void EkrIdunnDeadFlashing_Loop1(struct ProcIdunnfxFlashing *proc)
{
	int ret = Interpolate(0, 0, 0x10, proc->timer, proc->dura0);

	CpuFastCopy(gPal, gEfxPal, PLTT_SIZE);
	EfxPalWhiteInOut(gEfxPal, 0, 0x20, ret);
	CpuFastCopy(gEfxPal, (u16 *)PLTT, PLTT_SIZE);
	DisablePalSync();

	if (++proc->timer > proc->dura0) {
		proc->timer = 0;
		Proc_Break(proc);
	}
}

void EkrIdunnDeadFlashing_Loop2(struct ProcIdunnfxFlashing *proc)
{
	CpuFastCopy(gPal, gEfxPal, PLTT_SIZE);
	EfxPalWhiteInOut(gEfxPal, 0, 0x20, 0x10);
	CpuFastCopy(gEfxPal, (u16 *)PLTT, PLTT_SIZE);
	DisablePalSync();

	if (++proc->timer > proc->dura1) {
		proc->timer = 0;
		Proc_Break(proc);
	}
}

void EkrIdunnDeadFlashing_Loop3(struct ProcIdunnfxFlashing *proc)
{
	int ret = Interpolate(0, 0x10, 0, proc->timer, proc->dura2);

	CpuFastCopy(gPal, gEfxPal, PLTT_SIZE);
	EfxPalWhiteInOut(gEfxPal, 0, 0x20, ret);
	CpuFastCopy(gEfxPal, (u16 *)PLTT, PLTT_SIZE);
	DisablePalSync();

	if (++proc->timer > proc->dura2) {
		proc->timer = 0;
		Proc_Break(proc);
	}
}

void EkrIdunnDeadFlashing_Loop4(struct ProcIdunnfxFlashing *proc)
{
	SetBlendBackdropA(1);
	SetBlendBackdropB(1);

	EnablePalSync();
	Proc_Break(proc);
}

struct ProcScr CONST_DATA ProcScr_EkrDragonDeath[] = {
	PROC_19,
	PROC_REPEAT(EkrDragonDeath_Loop),
	PROC_END,
};

void StartEkrDragonDeath(void)
{
	struct ProcEkrIdunnfx *proc;

	proc = SpawnProc(ProcScr_EkrDragonDeath, PROC_TREE_3);

	proc->timer = 0;
}

void EkrDragonDeath_Loop(struct ProcEkrIdunnfx *proc)
{
	if (++proc->timer == 20) {
		EfxPlaySE(SONG_145, 0x100);
		EfxStopBGM1();
		Proc_Break(proc);
	}
}
