#include "prelude.h"
#include "oam.h"
#include "util.h"
#include "proc.h"
#include "eventfunctions.h"

#include "ending.h"

CONST_DATA struct EndingCgConf gEndingCgConf[] = {
	[1]  = { EndingCG_Img5, EndingCG_Pal5, NULL, NULL },
	[3]  = { EndingCG_Img3, EndingCG_Pal3, NULL, NULL },
	[6]  = { EndingCG_Img1, EndingCG_Pal1, NULL, NULL },
	[8]  = { EndingCG_Img10, EndingCG_Pal10, NULL, NULL },
	[10] = { EndingCG_Img7, EndingCG_Pal7, EndingCG_Img6, EndingCG_Pal6 },
	[11] = { EndingCG_Img8, EndingCG_Pal8, EndingCG_Img9, EndingCG_Pal9 },
	[12] = { EndingCG_Img4, EndingCG_Pal4, EndingCG_Img2, EndingCG_Pal2 },
};

bool CheckDisplayEndingCG(void)
{
	if (gEndingCgIndex < 13 && gEndingCgConf[gEndingCgIndex].img1)
		return true;

	return false;
}

struct ProcScr CONST_DATA ProcScr_EndingCG[] = {
	PROC_19,
	PROC_CALL(EndingCG_Init),
	PROC_CALL(FadeInBlackSpeed08),
	PROC_SLEEP(1),
	PROC_REPEAT(EndingCG_Loop),
	PROC_CALL(FadeInBlackWithCallBack_Speed08),
	PROC_SLEEP(1),
	PROC_END,
};

void EndingCG_Init(struct ProcGameEnding *proc)
{
	const void *img;
	const void *pal;
	bool ret = false;

	proc->timer = 0;

	InitBgs(BgConf_Ending);
	SetDispEnable(0, 0, 1, 0, 0);
	SetBlendConfig(BLEND_EFFECT_NONE, 0, 0, 0);
	SetBlendTargetA(0, 0, 0, 0, 0);
	SetBlendTargetB(0, 0, 0, 0, 0);

	SetBgOffset(BG_2, 0, -4);
	TmFill(gBg2Tm, 0);

	switch (gEndingCgIndex) {
	case 10:
		ret = !CheckFlag(FLAG_107);

		break;

	case 11:
		ret = GetEndingId() == FAKE_ENDING;

		break;

	case 12:
		ret = GetEndingId() != TRUE_ENDING;

		break;

	default:
		break;
	}

	if (ret)
		img = gEndingCgConf[gEndingCgIndex].img2;
	else
		img = gEndingCgConf[gEndingCgIndex].img1;

	Decompress(img, (u8 *)BG_VRAM + BGCHR_ENDING_CG * CHR_SIZE + GetBgChrOffset(BG_2));

	if (ret)
		pal = gEndingCgConf[gEndingCgIndex].pal2;
	else
		pal = gEndingCgConf[gEndingCgIndex].pal1;

	ApplyPalette(pal, BGPAL_ENDING_CG);

	PutEndingCreditTm(gBg2Tm + TM_OFFSET(7, 5), OAM2_PAL(BGPAL_ENDING_CG) + BGCHR_ENDING_CG, 15, 10);
	EnableBgSync(BG2_SYNC_BIT);
}

void EndingCG_Loop(struct ProcGameEnding *proc)
{
	proc->timer++;

	if (proc->timer > 0xF0)
		Proc_Break(proc);
}
