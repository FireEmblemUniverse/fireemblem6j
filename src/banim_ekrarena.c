#include "prelude.h"
#include "oam.h"
#include "proc.h"
#include "util.h"
#include "banim.h"
#include "banim_ekrbattle.h"
#include "constants/songs.h"

EWRAM_OVERLAY(banim) ProcPtr gpProcEkrTogiColor = NULL;
EWRAM_DATA int gBaArenaFlag = 0;

void SetBanimArenaFlag(int flag)
{
	gBaArenaFlag = flag;
}

int GetBattleAnimArenaFlag(void)
{
	return gBaArenaFlag;
}

void EkrArena_ChangeBg3Offset(int x)
{
	int x1 = x >> 3;
	int x2 = x & 7;

	SetBgOffset(BG_3, x2, 0);
	EfxTmCpyExt(gTmB_Banim + 8 + x1, 66, gBg3Tm, 32, 32, 22, -1, -1);

	EnableBgSync(BG3_SYNC_BIT);
}

void PlayDeathSoundForArena(void)
{
	if (GetBattleAnimArenaFlag() != 0)
		EfxPlaySE(SONG_8F, 0x100);
}

void StopArenaBgmWhenSpeedUp(void)
{
	if (GetBattleAnimArenaFlag() != 0)
		DoM4aSongNumStop(SONG_8E);
}

void BeginAnimsOnBattle_Arena(void)
{
	u32 pos;

	NewEkrBattleDeamon();
	BasInit();

	pos = GetBanimInitPosReal();
	gEkrInitPosReal = pos;

	NewEkrTogiInitPROC();
	SetOnHBlankA(NULL);
}

void ExecBattleAnimArenaExit(void)
{
	BasInit();
	NewEkrTogiEndPROC();

	SetMainFunc(OnMainBas);
}

struct ProcScr CONST_DATA ProcScr_EkrTogiInitPROC[] = {
	PROC_NAME_DEBUG("ekrTogiInitPROC"),
	PROC_REPEAT(EkrTogiInit_Init),
	PROC_REPEAT(EkrTogiInit_LoadGfx),
	PROC_REPEAT(EkrTogiInit_Loop),
	PROC_REPEAT(EkrTogiInit_End),
	PROC_END,
};

void NewEkrTogiInitPROC(void)
{
	SpawnProc(ProcScr_EkrTogiInitPROC, PROC_TREE_3);
}

void EkrTogiInit_Init(struct ProcEfxBG *proc)
{
	InitOam(0);

	gEkrInitPosReal = gEkrInitialHitSide;

	EfxClearScreenFx();
	UpdateBanimFrame();

	NewEkrGauge();
	NewEkrDispUP();
	NewEkrBattle();

	CpuFastCopy(Pal_ArenaBattleBg_A, gPal + PAL_OFFSET(BGPAL_EFXDRAGON_L), 0x80);
	CpuFastCopy(gPal, gEfxPal, 0x400);
	CpuFastCopy(gEfxPal, gPal, 0x400);
	EfxPalBlackInOut(gPal, 0, 0x20, 0x10);
	EnablePalSync();

	Proc_Break(proc);
}

void EkrTogiInit_LoadGfx(struct ProcEfxBG *proc)
{
	LZ77UnCompVram(Img_ArenaBattleBg, (u8 *)BG_VRAM + VRAMOFF_BANIM_8000);
	LZ77UnCompWram(Tsa_ArenaBattleBg, gEkrTsaBuffer);
	EfxTmCpyExt(gEkrTsaBuffer, -1, gTmB_Banim, 66, 46, 20, 6, 0);
	EkrArena_ChangeBg3Offset(0);
	EnableBgSync(BG3_SYNC_BIT);

	proc->timer = 0;
	proc->terminator = 16;

	EfxPlaySE(SONG_8E, 0x100);

	Proc_Break(proc);
}

void EkrTogiInit_Loop(struct ProcEfxBG *proc)
{
	int ret = Interpolate(INTERPOLATE_LINEAR, 0x10, 0, proc->timer, proc->terminator);

	CpuFastCopy(gEfxPal, gPal, 0x400);

	EfxPalBlackInOut(gPal, 0, 0x20, ret);
	EnablePalSync();

	if (++proc->timer == proc->terminator + 1)
		Proc_Break(proc);
}

void EkrTogiInit_End(struct ProcEfxBG *proc)
{
	NewEkrTogiColor();
	Proc_Break(proc);
}

struct ProcScr CONST_DATA ProcScr_EkrTogiEndPROC[] = {
	PROC_NAME_DEBUG("ekrTogiEndPROC"),

	PROC_REPEAT(EkrTogiEnd_Init),
	PROC_REPEAT(EkrTogiEnd_Loop),
	PROC_REPEAT(EkrTogiEnd_End),

	PROC_END,
};

void NewEkrTogiEndPROC(void)
{
	SpawnProc(ProcScr_EkrTogiEndPROC, PROC_TREE_3);
	EndEkrTogiColor();
}

void EkrTogiEnd_Init(struct ProcEfxBG *proc)
{
	CpuFastCopy(gPal, gEfxPal, 0x400);

	proc->timer = 0;
	proc->terminator = 16;

	Proc_Break(proc);
}

void EkrTogiEnd_Loop(struct ProcEfxBG *proc)
{
	int ret = Interpolate(INTERPOLATE_LINEAR, 0, 16, proc->timer, proc->terminator);

	CpuFastCopy(gEfxPal, gPal, 0x400);
	EfxPalBlackInOut(gPal, 0, 0x20, ret);
	EnablePalSync();

	if (++proc->timer == proc->terminator + 1)
		Proc_Break(proc);
}

void EkrTogiEnd_End(struct ProcEfxBG *proc)
{
	EndEkrBattleDeamon();
	EndEkrGauge();

	SetMainFunc(OnMain);
	SetOnVBlank(OnVBlank);

	Proc_Break(proc);
}

struct ProcScr CONST_DATA ProcScr_EkrTogiColor[] = {
	PROC_NAME_DEBUG("ekrTogiColor"),
	PROC_REPEAT(EkrTogiColor_Loop),
	PROC_END,
};

const u16 CONST_DATA *Pals_ArenaBattleBg[] = {
	Pal_ArenaBattleBg_A,
	Pal_ArenaBattleBg_B,
	Pal_ArenaBattleBg_C,
};

void NewEkrTogiColor(void)
{
	const static u16 frames[] = {
		0, 10,
		1, 10,
		2, 10,
		-2,
	};

	struct ProcEkrTogiColor *proc;

	gpProcEkrTogiColor = proc = SpawnProc(ProcScr_EkrTogiColor, PROC_TREE_3);

	proc->timer = 0;
	proc->frame = 0;
	proc->frame_config = frames;
	proc->pal = Pals_ArenaBattleBg;
}

void EndEkrTogiColor(void)
{
	Proc_End(gpProcEkrTogiColor);
}

void EkrTogiColor_Loop(struct ProcEkrTogiColor * proc)
{
	i16 ret = EfxAdvanceFrameLut((i16 *)&proc->timer, (i16 *)&proc->frame, proc->frame_config);

	if (ret > -1) {
		const u16 **pal = proc->pal;

		CpuFastCopy(pal[ret], gPal + PAL_OFFSET(BGPAL_EFXDRAGON_L), 0x80);
		EnablePalSync();
	}
}
