#include "prelude.h"
#include "proc.h"
#include "hardware.h"
#include "util.h"

#include "ending.h"

struct ProcScr CONST_DATA ProcScr_Fin[] = {
	PROC_19,
	PROC_SLEEP(60),
	PROC_CALL(Fin_Init),
	PROC_CALL(FadeInBlackSpeed08),
	PROC_SLEEP(1),
	PROC_REPEAT(Fin_Loop),
	PROC_CALL_ARG(_FadeBgmOut, 8),
	PROC_CALL(FadeInBlackWithCallBack_Speed08),
	PROC_SLEEP(1),
	PROC_SLEEP(180),
	PROC_END,
};

void Fin_Init(struct ProcGameEnding *proc)
{
	int i;
	int oam2_base;

	proc->timer = 0;

	InitBgs(BgConf_Ending);
	SetDispEnable(1, 0, 0, 0, 0);
	SetBlendConfig(BLEND_EFFECT_NONE, 0, 0, 0);
	SetBlendTargetA(0, 0, 0, 0, 0);
	SetBlendTargetB(0, 0, 0, 0, 0);

	SetBgOffset(BG_0, 0, 0);
	SetBgOffset(BG_3, 0, 0);

	TmFill(gBg0Tm, 0);
	TmFill(gBg3Tm, 0);

	ApplyPalette(Pal_MuralBackground, 4);
	ApplyPalette(Pal_Fin, 6);

	Decompress(Img_Fin, BG_CHAR_ADDR(0) + 0x80 * CHR_SIZE);
	Decompress(Img_MuralBackground, (u8 *)BG_VRAM + GetBgChrOffset(BG_3));
	PutEndingLinearTSA(gBg3Tm, 0x4000);

	oam2_base = 0x6080;

	for (i = 0; i < 6; i++) {
		gBg0Tm[i + 0x10C] = oam2_base + i;
		gBg0Tm[i + 0x12C] = oam2_base + 0x20 + i;
		gBg0Tm[i + 0x14c] = oam2_base + 0x40 + i;
		gBg0Tm[i + 0x16c] = oam2_base + 0x60 + i;
	}

	EnableBgSync(BG0_SYNC_BIT | BG3_SYNC_BIT);
}

void Fin_Loop(struct ProcGameEnding *proc)
{
	proc->timer++;

	if (proc->timer > 0xF0)
		Proc_Break(proc);
}
