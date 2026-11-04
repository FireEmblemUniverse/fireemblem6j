#include "prelude.h"
#include "proc.h"
#include "bmio.h"
#include "mu.h"
#include "oam.h"
#include "map.h"
#include "util.h"
#include "unitsprite.h"
#include "chapter.h"
#include "banim.h"
#include "banim_ekrbattle.h"
#include "banim_ekrdragon.h"

struct ProcScr CONST_DATA ProcScr_EkrBattleStarting[] = {
	PROC_NAME_DEBUG("ekrBattleStarting"),
	PROC_REPEAT(EkrBaStart_InitScreen),
	PROC_REPEAT(EkrBaStart_SreenFailIn),
	PROC_REPEAT(EkrBaStart_InitBattleScreen),
	PROC_REPEAT(EkrBaStart_ExecEkrBattle),
	PROC_REPEAT(EkrBaStart_BgFadeOut),
	PROC_REPEAT(EkrBaStart_MergeBG),
	PROC_REPEAT(EkrBaStart_BgPaletteIn),
	PROC_END,
};

void NewEkrBattleStarting(void)
{
	SpawnProc(ProcScr_EkrBattleStarting, PROC_TREE_3);
}

void EkrBaStart_InitScreen(struct ProcEkrBattleStarting *proc)
{
	int val;

	proc->timer = 0;
	proc->terminator = 0xF;

	val = (gEkrBmLocation[0] + gEkrBmLocation[2]) * 8 + 8;
	proc->x2 = val;
	proc->x1 = val;

	val = (gEkrBmLocation[1] + gEkrBmLocation[3]) * 8 + 8;
	proc->y2 = val;
	proc->y1 = val;

	CpuFastFill(0, gBg2Tm, 0x800);
	EnableBgSync(BG2_SYNC_BIT);

	SetBlendConfig(3, 0, 0, 4);
	SetBlendTargetA(0, 0, 0, 1, 0);

	SetWinEnable(1, 0, 0);
	SetWin0Box(0, 0, 0xF0, 0xA0);

	SetWin0Layers(1, 1, 1, 1, 1);
	SetWOutLayers(1, 1, 1, 1, 0);

	gDispIo.win_ct.win0_enable_blend = false;
	gDispIo.win_ct.wout_enable_blend = true;

	Proc_Break(proc);
}

void EkrBaStart_SreenFailIn(struct ProcEkrBattleStarting *proc)
{
	int left, top, right, bottom;
	
	if (proc->timer != proc->terminator)
		proc->timer++;

	left   = Interpolate(INTERPOLATE_LINEAR, 0,	proc->x1, proc->timer, proc->terminator);
	top	= Interpolate(INTERPOLATE_LINEAR, 0,	proc->y1, proc->timer, proc->terminator);
	right  = Interpolate(INTERPOLATE_LINEAR, 0xF0, proc->x2, proc->timer, proc->terminator);
	bottom = Interpolate(INTERPOLATE_LINEAR, 0xA0, proc->y2, proc->timer, proc->terminator);

	SetWin0Box(left, top, right, bottom);

	if (proc->timer == proc->terminator) {
		SetWOutLayers(1, 1, 1, 1, 1);
		InitOam(0);
		LockBmDisplay();
		SetWin0Box(0, 0, 0xF0, 0xA0);
		EfxPalBlackInOut(gPal, BGPAL_EFXDRAGON_L, 0xA, 0x4);
		EnablePalSync();
		EndAllMus();
		Proc_Break(proc);
	}
}

void EkrBaStart_InitBattleScreen(struct ProcEkrBattleStarting *proc)
{
	if (gEkrDebugModeMaybe == 0) {
		NewEkrGauge();
		NewEkrDispUP();

		switch (gEkrDistanceType) {
		case EKR_DISTANCE_CLOSE:
		case EKR_DISTANCE_FAR:
		case EKR_DISTANCE_FARFAR:
			break;

		case EKR_DISTANCE_MONOCOMBAT:
			if (gBanimValid[POS_L] == false) {
				EkrGauge_Set4C();
				EkrDispUpSet4C();
			}

			if (gBanimValid[POS_R] == false) {
				EkrGauge_Set50();
				EkrDispUpSet50();
			}
			break;

		case EKR_DISTANCE_PROMOTION:
			EkrGauge_Set4C();
			EkrDispUpSet4C();
			break;

		default:
			break;
		}
	}

	EfxClearScreenFx();
	NewEkrUnitKakudai(0);
	NewEkrBaseKaiten(0);
	NewEkrWindowAppear(0, 0xB);
	NewEkrNamewinAppear(0, 0xB, 0);
	NewEkrBaseAppear(0, 0xB);

	proc->timer = 0;
	Proc_Break(proc);
}

void EkrBaStart_ExecEkrBattle(struct ProcEkrBattleStarting *proc)
{
	if (++proc->timer > 0xB) {
		if (gBanimBG == 0 || GetEkrDragonStateType() != 0) {
			/* In normal battle, here will directly end the proc */
			NewEkrBattle();
			Proc_End(proc);
		} else {
			proc->timer = 0;
			NewEkrBattle();
			Proc_Break(proc);
		}
	}
}

void EkrBaStart_BgFadeOut(struct ProcEkrBattleStarting *proc)
{
	EfxChapterMapFadeOUT(Interpolate(0, 4, 0x10, proc->timer, 8));

	if (++proc->timer == 0x9) {
		proc->timer = 0;
		Proc_Break(proc);
	}
}

void EkrBaStart_MergeBG(struct ProcEkrBattleStarting *proc)
{
	if (gEkrSnowWeather == 0)
		gUnk_Banim_0201E0F8 = 0x6;
	else
		gUnk_Banim_0201E0F8 = 0xA;

	PutBanimBG(gBanimBG - 1);
	EfxPalBlackInOut(gPal, BGPAL_EFXDRAGON_L, 0xA, 0x10);
	Proc_Break(proc);
}

void EkrBaStart_BgPaletteIn(struct ProcEkrBattleStarting *proc)
{
	int val = Interpolate(0, 0x10, 0, proc->timer, 8);

	PutBanimBgPAL(gBanimBG - 1);
	EfxPalBlackInOut(gPal, BGPAL_EFXDRAGON_L, 0xA, val);
	EnablePalSync();

	if (++proc->timer == 0x9) {
		proc->timer = 0;
		Proc_Break(proc);
	}
}

struct ProcScr CONST_DATA ProcScr_Ekrbattleending[] =
{
	PROC_NAME_DEBUG("ekrBattleEnding"),
	PROC_REPEAT(EkrBaEnd_BgPaletteIn),
	PROC_REPEAT(EkrBaEnd_RestoreChapterMap),
	PROC_REPEAT(EkrBaEnd_ChapterMapFadeOut),
	PROC_REPEAT(EkrBaEnd_InitOutroFx),
	PROC_REPEAT(EkrBaEnd_WaitOutroAndEndGauge),
	PROC_REPEAT(EkrBaEnd_RestoreMapDisplay),
	PROC_REPEAT(EkrBaEnd_ScreenFailOut),
	PROC_REPEAT(EkrBaEnd_Finish),
	PROC_END,
};

void NewEkrbattleending(void)
{
	struct ProcEkrBattleEnding *proc;
	proc = SpawnProc(ProcScr_Ekrbattleending, PROC_TREE_3);
	proc->timer = 0;
}

void EkrBaEnd_BgPaletteIn(struct ProcEkrBattleEnding *proc)
{
	int ret;

	if (gBanimBG == 0 || GetEkrDragonStateType() != 0) {
		Proc_Break(proc);
		return;
	}

	ret = Interpolate(INTERPOLATE_LINEAR, 0, 0x10, proc->timer, 0x8);
	PutBanimBgPAL(gBanimBG - 1);
	EfxPalBlackInOut(gPal, BGPAL_EFXDRAGON_L, 0xA, ret);
	EnablePalSync();

	if (++proc->timer == 0x9) {
		proc->timer = 0;
		Proc_Break(proc);
	}
}

void EkrBaEnd_RestoreChapterMap(struct ProcEkrBattleEnding *proc)
{
	if (gBanimBG == 0 || GetEkrDragonStateType() != 0) {
		Proc_Break(proc);
		return;
	}

	ApplyChapterMapGraphics(gPlaySt.chapter);
	EfxChapterMapFadeOUT(0x10);
	RenderMap();
	SetBgOffset(BG_3, 0, 0);
	Proc_Break(proc);
}

void EkrBaEnd_ChapterMapFadeOut(struct ProcEkrBattleEnding *proc)
{
	if (gBanimBG == 0 || GetEkrDragonStateType() != 0) {
		Proc_Break(proc);
		return;
	}

	EfxChapterMapFadeOUT(Interpolate(INTERPOLATE_LINEAR, 0x10, 0x4, proc->timer, 0x8));

	if (++proc->timer == 0x9) {
		proc->timer = 0;
		Proc_Break(proc);
	}
}

void EkrBaEnd_InitOutroFx(struct ProcEkrBattleEnding *proc)
{
	int val;

	proc->timer = 0;

	val = (gEkrBmLocation[0] + gEkrBmLocation[2]) * 8 + 8;
	proc->x2 = val;
	proc->x1 = val;

	val = (gEkrBmLocation[1] + gEkrBmLocation[3]) * 8 + 8;
	proc->y2 = val;
	proc->y1 = val;

	BasInit();
	NewEkrUnitKakudai(1);
	NewEkrBaseKaiten(1);
	NewEkrWindowAppear(1, 0xB);
	NewEkrBaseAppear(1, 0xB);
	Proc_Break(proc);
}

void EkrBaEnd_WaitOutroAndEndGauge(struct ProcEkrBattleEnding *proc)
{
	if (++proc->timer > 0xC) {
		EndEkrGauge();
		Proc_Break(proc);
		InitBmBgLayers();
		
		SetWinEnable(1, 0, 0);
		SetWin0Box(0, 0, 0, 0);
		SetWin0Layers(1, 1, 1, 1, 1);
		SetWOutLayers(1, 1, 1, 1, 0);
	}
}

void EkrBaEnd_RestoreMapDisplay(struct ProcEkrBattleEnding *proc)
{
	proc->timer = 0;
	proc->terminator = 0xF;
	ResetUnitSprites();
	func_fe6_080292B8();
	RefreshUnitSprites();
	ForceSyncUnitSpriteSheet();
	ApplyUnitSpritePalettes();

	SetBlendConfig(3, 0, 0, 4);
	SetBlendTargetA(0, 0, 0, 1, 0);

	gDispIo.win_ct.win0_enable_blend = false;
	gDispIo.win_ct.wout_enable_blend = true;

	if (GetBattleAnimArenaFlag() != 1)
		ApplyChapterMapPalettes();

	if (GetBanimLinkArenaFlag() == 1)
		func_fe6_0803CF58();
	
	Proc_Break(proc);
}

void EkrBaEnd_ScreenFailOut(struct ProcEkrBattleEnding *proc)
{
	int left, top, right, bottom;

	if (proc->timer != proc->terminator)
		proc->timer++;

	left   = Interpolate(INTERPOLATE_LINEAR, proc->x1, 0,	proc->timer, proc->terminator);
	top	= Interpolate(INTERPOLATE_LINEAR, proc->y1, 0,	proc->timer, proc->terminator);
	right  = Interpolate(INTERPOLATE_LINEAR, proc->x2, 0xF0, proc->timer, proc->terminator);
	bottom = Interpolate(INTERPOLATE_LINEAR, proc->y2, 0xA0, proc->timer, proc->terminator);

	SetWin0Box(left, top, right, bottom);
	CpuFastFill16(0, gBg2Tm, 0x800);
	EnableBgSync(BG2_SYNC_BIT);

	if (proc->timer == proc->terminator) {
		proc->timer = 0;
		SetWin0Box(0, 0, 0xF0, 0xA0);
		EnablePalSync();
		Proc_Break(proc);
	}
}

void EkrBaEnd_Finish(struct ProcEkrBattleEnding *proc)
{
	EndEkrBattleDeamon();
	func_fe6_08029240();
	Proc_Break(proc);
}
