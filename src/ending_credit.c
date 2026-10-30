#include "prelude.h"
#include "hardware.h"
#include "util.h"
#include "proc.h"
#include "ui.h"
#include "augury.h"
#include "playrank.h"
#include "ending.h"

u16 CONST_DATA BgConf_Ending[] = {
	// tile offset  map offset  screen size
	0x0000,         0x6000,     0,          // BG 0
	0x0000,         0x6800,     0,          // BG 1
	0x8000,         0x7000,     0,          // BG 2
	0x8000,         0x7800,     0,          // BG 3
};

void SetupCreditCharacterGlyphs(void)
{
	ApplyPalette(Pal_CreditCharacterGlyph, BGPAL_CREDIT_GLYPH);
	ApplyPalette(Pal_CreditCharacterGlyph, OBPAL_CREDIT_GLYPH + 0x10);

	Decompress(Img_CreditGlyph_Cap, OBJ_VRAM0 + OBCHR_CREDIT_GLYPH_CAP * CHR_SIZE);
	Decompress(Img_CreditGlyph_Low, OBJ_VRAM0 + OBCHR_CREDIT_GLYPH_LOW * CHR_SIZE);
	Decompress(Img_CreditGlyph_Narrow, (u8 *)BG_VRAM + BGCHR_CREDIT_GLYPH_NARROW * CHR_SIZE);
}

void PutEndingCreditTm(u16 *tm, u16 oam2, u8 w, u8 h)
{
	i16 ix, iy;
	u32 h_ = h;

	for (iy = h_; iy > 0; iy--) {
		u16 *local_tm = tm + TM_OFFSET(0, h - iy);

		for (ix = w; ix > 0; ix--) {
			*local_tm++ = oam2;
			oam2++;
		}
	}
}

void EndingCredit_Reinit(struct ProcGameCredit *proc)
{
	UnpackUiWindowFrameGraphics();

	proc->timer = 0;
	gCreditInfoDispStep = 0;
	gEndingCgIndex = 0;
	gCreditNameDispMode = 0;
	gEndingDoneFlag = 0;

	SetBlendAlpha(0, 0x10);
	SetBlendTargetA(1, 1, 0, 0, 0);
	SetBlendTargetB(0, 0, 1, 1, 0);

	SetupCreditCharacterGlyphs();
}

void GameCredit_Init(struct ProcGameCredit *proc)
{
	gEndingDispType = ENDING_DISP_1;
	EndingCredit_Reinit(proc);
	SetupEndingPInfo2Uids();
}

void EndingCredit_ReinitType2(struct ProcGameCredit *proc)
{
	gEndingDispType = ENDING_DISP_2;
	EndingCredit_Reinit(proc);
	SetupEndingPInfo2Uids();
}

void EndingCredit_ReinitType0(struct ProcGameCredit *proc)
{
	gEndingDispType = ENDING_DISP_0;
	EndingCredit_Reinit(proc);
}

u8 func_fe6_0808FF04(struct ProcGameCredit *proc, int b, int c)
{
	if (gCreditNameAnimTimer <= 0x13) {
		gCreditCharOffsets[proc->unk_4C] = 0x16;
		gCreditCharDelays[proc->unk_4C] = c >> 1;
	}

	else if (gCreditCharDelays[proc->unk_4C] != 0) {
		gCreditCharDelays[proc->unk_4C]--;
	} else {
		gCreditCharOffsets[proc->unk_4C] += 4;

		if (gCreditCharOffsets[proc->unk_4C] > b)
			gCreditCharOffsets[proc->unk_4C] = b;

		return gCreditCharOffsets[proc->unk_4C++];
	}

	proc->unk_4C++;
	return 0xF0;
}

int EndingCredit_FindWordLen(int x_cur, int ch1, int ch2)
{
	int i;

	for (i = 0; gEndingCredit_WordLenConf[i].unk_0 != 0; i++) {
		if (gEndingCredit_WordLenConf[i].unk_0 == ch1 && gEndingCredit_WordLenConf[i].unk_1 == ch2) {
			x_cur = gEndingCredit_WordLenConf[i].unk_2 + x_cur - 8;
			break;
		}
	}
	return x_cur;
}
