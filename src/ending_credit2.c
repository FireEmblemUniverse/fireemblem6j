#include "prelude.h"
#include "hardware.h"
#include "oam.h"
#include "util.h"
#include "proc.h"
#include "armfunc.h"
#include "sprite.h"
#include "ending.h"

CONST_DATA struct EndingCreditWordLenConf gEndingCredit_WordLenConf[] = {
	{ 'a', 't', 9 },
	{ 't', 'a', 9 },
	{ 'o', 'm', 7 },
	{ 'I', 't', 6 },
	{ 'T', 'o', 7 },
	{ 'a', 'w', 9 },
	{ 'r', 'u', 9 },
	{}
};

void func_fe6_0808FFE0(struct ProcGameCredit *proc, int step)
{
	int x = gCreditInfo[step].x * 8 + 0x16;
	int y = (gCreditInfo[step].y + 2) * 8;
	int oam0;
	int i = 0;
	int kern = 0;
	int prev_ch = 0;
	int index, chr, ch, tmp;

	if ((u32)gCreditInfo[gCreditInfoDispStep].job - 1 <= 1)
		return;

	proc->unk_4C = 0;

	if (gCreditNameDispMode == 0)
		return;

	oam0 = 0;
	if (gCreditNameDispMode == 1)
		oam0 = OAM0_BLEND;

	while ((index = ch = gCreditInfo[step].staff[i]) != '\0') {
		switch (ch) {
		case '\n':
			y += 0x10;
			x = gCreditInfo[step].x * 8 + 0x16;
			kern = 0;
			break;

		case ' ':
			x += 7;
			break;

		case '&':
			index = 0x1C;
			goto put_symbol;

		case ',':
			index = 0x1A;
			goto put_symbol;

		case '.':
			index = 0x1B;

		put_symbol:
			PutOamHi(func_fe6_0808FF04(proc, x, y), y | oam0, Sprite_16x16, OAM2_PAL(OBPAL_CREDIT_GLYPH) | (OBCHR_CREDIT_GLYPH_CAP + 0x20 + index * 2));
			x += gEndingCredit_FontObjConf[26].unk_00 + 1;
			kern = gEndingCredit_FontObjConf[26].unk_02;
			break;

		default:
			if (index < 'a') {
				index -= 'A';
				chr = (index < 16) ? 0 : 0x20;

				if (kern != 0) {
					tmp = (gEndingCredit_FontObjConf[index].unk_01 + kern) & 0xFF;

					if (tmp < 0x80)
						x -= (tmp & 0xF) >> 1;
				} else if (gEndingCredit_FontObjConf[index].unk_01 & 0x40) {
					x -= 2;
				}

				x = EndingCredit_FindWordLen(x, prev_ch, ch);
				PutOamHi(func_fe6_0808FF04(proc, x, y), y | oam0, Sprite_16x16, OAM2_PAL(OBPAL_CREDIT_GLYPH) | (OBCHR_CREDIT_GLYPH_CAP + index * 2 + chr));
				x += gEndingCredit_FontObjConf[index].unk_00 + 1;
				kern = gEndingCredit_FontObjConf[index].unk_02;
			} else {
				index -= 'a';
				chr = (index < 16) ? 0 : 0x20;

				if (kern != 0) {
					tmp = (gEndingCredit_FontObjConf[index].unk_04 + kern) & 0xFF;

					if (tmp < 0x80)
						x -= (tmp & 0xF) >> 1;
				} else if (gEndingCredit_FontObjConf[index].unk_04 & 0x40) {
					x -= 2;
				}

				x = EndingCredit_FindWordLen(x, prev_ch, ch);
				PutOamHi(func_fe6_0808FF04(proc, x, y), (y + 1) | oam0, Sprite_16x16, OAM2_PAL(OBPAL_CREDIT_GLYPH) | (OBCHR_CREDIT_GLYPH_LOW + index * 2 + chr));
				x += gEndingCredit_FontObjConf[index].unk_03 + 1;
				kern = gEndingCredit_FontObjConf[index].unk_05;
			}
			break;
		}

		prev_ch = ch;
		i++;
	}

	if (gCreditNameAnimTimer < 20)
		gCreditNameAnimTimer++;
}

void EndingCredit_PutJobName(int step)
{
	u16 oam2_base;
	i16 x = gCreditInfo[step].x + 1;
	int y = gCreditInfo[step].y * 0x20;
	int i = 0;

	SetBgOffset(BG_0, 0, 0);
	SetBgOffset(BG_1, 0, 0);

	gCreditNameAnimTimer = 0;

	if (step != 0) {
		int _y = gCreditInfo[step - 1].y;

		TmFillRect(gBg0Tm + TM_OFFSET(0, _y), 30, 2, 0);
		TmFillRect(gBg1Tm + TM_OFFSET(0, _y), 30, 2, 0);
	}

	oam2_base = 0x4080;

	if (gCreditInfo[step].job) {
		u16 *tm = gBg0Tm;

		while (1) {
			int ch = gCreditInfo[step].job[i];

			if (ch == '\0')
				break;

			switch (ch) {
			case '\n':
				x = gCreditInfo[step].x + 1;
				SetBgOffset(BG_0, 0, 10);
				SetBgOffset(BG_1, 0, 0xFE);
				tm = gBg1Tm;
				break;

			case ' ':
				break;

			case '&':
				tm[y + x] = oam2_base + 0x1C;
				tm[x + y + 1] = oam2_base + 0x1D;
				tm[x + y + 0x20] = oam2_base + 0x3C;
				tm[x + y + 0x21] = oam2_base + 0x3D;

				x++;
				break;

			case ',':
				ch = 0x1A;
				goto goto_here;

			case '.':
				ch = 0x1B;
				goto goto_here;

			case '(':
			case ')':
			default:
				ch = ch - 'A';

			goto_here:
				tm[x + y] = oam2_base + ch;
				tm[x + y + 0x20] = oam2_base + ch + 0x20;
				break;
			}
			x++, i++;
		}
	}

	EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT);
}

struct ProcScr CONST_DATA ProcScr_0868BB3C[] = {
	PROC_19,
	PROC_CALL(func_fe6_080904F0),
	PROC_REPEAT(func_fe6_08090508),
	PROC_END,
};

void func_fe6_080904F0(struct ProcGameEnding *proc)
{
	proc->timer = 0;
	proc->step = 0;
	gCreditNameDispMode = true;
}

void func_fe6_08090508(struct ProcGameEnding *proc)
{
	proc->step++;

	if ((proc->step & 7) == 0) {
		proc->timer++;
		if (proc->timer > 15)
			Proc_Break(proc);

		SetBlendAlpha(proc->timer, 0x10 - proc->timer);
		SetBlendTargetA(1, 1, 0, 0, 0);
		SetBlendTargetB(0, 0, 1, 1, 0);
	}
}

void func_fe6_0809058C(void)
{
	SpawnProc(ProcScr_0868BB3C, PROC_TREE_3);
}

struct ProcScr CONST_DATA ProcScr_0868BB5C[] = {
	PROC_19,
	PROC_CALL(func_fe6_080904F0),
	PROC_REPEAT(func_fe6_080905A0),
	PROC_END,
};

void func_fe6_080905A0(struct ProcGameEnding *proc)
{
	proc->step++;

	if ((proc->step & 3) == 0) {
		proc->timer++;
		if (proc->timer > 15) {
			Proc_Break(proc);
			gCreditNameDispMode = 0;
		}

		SetBlendAlpha(0x10 - proc->timer, proc->timer);
	}
}

void func_fe6_0809060C(void)
{
	SpawnProc(ProcScr_0868BB5C, PROC_TREE_3);
}

void TriggerEndingDone(void)
{
	gEndingDoneFlag++;
}

int func_fe6_08090630(void)
{
	return (gCreditInfoDispStep < 0x32) ? false : true;
}

struct ProcScr CONST_DATA ProcScr_0868BB7C[] = {
	PROC_19,
	PROC_CALL(func_fe6_08090644),
	PROC_REPEAT(func_fe6_08090660),
	PROC_END,
};

void func_fe6_08090644(ProcPtr proc)
{
	gCreditNameDispMode = -1;
	EndingCredit_PutJobName(gCreditInfoDispStep);
}

void func_fe6_08090660(ProcPtr proc)
{
	func_fe6_0808FFE0(proc, gCreditInfoDispStep);
}

struct ProcScr CONST_DATA ProcScr_EndingCredit[] = {
	PROC_19,
	PROC_CALL(EndingCredit_Init),
	PROC_CALL(FadeInBlackSpeed08),
	PROC_SLEEP(1),
	PROC_REPEAT(EndingCredit_Loop),
	PROC_CALL(FadeInBlackWithCallBack_Speed08),
	PROC_SLEEP(1),
	PROC_SLEEP(60),
	PROC_CALL(EndingCredit_End),
	PROC_END,
};

void EndingCredit_Init(struct ProcGameEnding *proc)
{
	proc->timer = 0;
	InitBgs(BgConf_Ending);

	SetDispEnable(1, 1, 0, 0, 1);
	SetBlendConfig(BLEND_EFFECT_NONE, 0, 0, 0);
	SetBlendTargetA(0, 0, 0, 0, 0);
	SetBlendTargetB(0, 0, 0, 0, 0);

	SetBgOffset(BG_0, 0, 0);
	SetBgOffset(BG_1, 0, 0);

	TmFill(gBg0Tm, 0);
	TmFill(gBg1Tm, 0);

	SetupCreditCharacterGlyphs();
	SpawnProc(ProcScr_0868BB7C, PROC_TREE_3);

	EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT);
}

void EndingCredit_Loop(struct ProcGameEnding *proc)
{
	proc->timer++;

	if (proc->timer > 300)
		Proc_Break(proc);
}

void EndingCredit_End(struct ProcGameEnding *proc)
{
	gCreditNameDispMode = false;
	TmFill(gBg0Tm, 0);
	EnableBgSync(BG0_SYNC_BIT);
	Proc_EndEach(ProcScr_0868BB7C);
}

struct ProcScr CONST_DATA ProcScr_EndingCopyRight[] = {
	PROC_19,
	PROC_SLEEP(60),
	PROC_CALL(EndingCopyRight_Init),
	PROC_CALL(FadeInBlackSpeed08),
	PROC_SLEEP(1),
	PROC_REPEAT(EndingCopyRight_Loop),
	PROC_CALL(FadeInBlackWithCallBack_Speed08),
	PROC_SLEEP(1),
	PROC_CALL_ARG(_FadeBgmOut, 6),
	PROC_SLEEP(90),
	PROC_END,
};

void EndingCopyRight_Init(struct ProcEndingCopyRight *proc)
{
	InitBgs(BgConf_Ending);
	proc->timer = 0x230;

	SetDispEnable(1, 0, 0, 0, 0);
	SetBlendConfig(BLEND_EFFECT_NONE, 0, 0, 0);
	SetBlendTargetA(0, 0, 0, 0, 0);
	SetBlendTargetB(0, 0, 0, 0, 0);

	SetBgOffset(BG_0, 0, 0);
	TmFill(gBg0Tm, 0);
	ApplyPalette(Pal_Ending_CopyRight, 2);
	Decompress(Img_Ending_CopyRight, (u8 *)BG_VRAM + GetBgChrOffset(BG_0));
	TmApplyTsa(gBg0Tm + TM_OFFSET(3, 5), Tsa_Ending_CopyRight, 0x2000);
	EnableBgSync(BG0_SYNC_BIT);
}

void EndingCopyRight_Loop(struct ProcEndingCopyRight *proc)
{
	proc->timer--;

	if (proc->timer == 0)
		Proc_Break(proc);
}

void PutEndingLinearTSA(u16 *tm, int oam2)
{
	int x, y;

	for (y = 0; y < 20; y++) {
		for (x = 0; x < 32; x++) {
			tm[TM_OFFSET(x, y)] = oam2 | (x + y * 0x20);
		}
	}
}

struct ProcScr CONST_DATA ProcScr_EndingStep1_PutFighterMonologue[] = {
	PROC_19,
	PROC_CALL(EndingStep1_Init),
	PROC_CALL(FadeInBlackSpeed08),
	PROC_SLEEP(1),
	PROC_REPEAT(EndingStep1_Loop),
	PROC_CALL(FadeInBlackWithCallBack_Speed08),
	PROC_SLEEP(1),
	PROC_CALL(EndingStep1_End),
	PROC_END,
};

void EndingStep1_End(struct ProcGameEnding *proc)
{
	SetBgOffset(BG_0, 0, 0);
	SetBlendBackdropB(0);
}

void EndingStep1_Init(struct ProcGameEnding *proc)
{
	int i;
	int oam2_base;

	proc->timer = 0;

	InitBgs(BgConf_Ending);
	SetDispEnable(1, 0, 0, 1, 0);
	SetBlendAlpha(10, 0);
	SetBlendTargetA(0, 0, 0, 1, 1);
	SetBlendTargetB(0, 0, 0, 0, 0);
	SetBlendBackdropB(1);

	SetBgOffset(BG_0, 4, 4);
	SetBgOffset(BG_3, 0, 0);

	TmFill(gBg0Tm, 0);
	TmFill(gBg3Tm, 0);

	ApplyPalette(Pal_Fin, 6);
	ApplyPalettes(Pal_MonologueBG, 4, 2);

	Decompress(Img_EndingFighterText, (u8 *)BG_VRAM + 0x1000);
	Decompress(Img_MonologueBG, (u8 *)BG_VRAM + GetBgChrOffset(BG_3));
	TmApplyTsa(gBg3Tm, Tsa_EndingPInfoBG, 0x4000);

	oam2_base = 0x6080;

	for (i = 0; i < 17; i++) {
		gBg0Tm[i + 0x107] = oam2_base + i;
		gBg0Tm[i + 0x127] = oam2_base + 0x20 + i;
		gBg0Tm[i + 0x147] = oam2_base + 0x40 + i;
		gBg0Tm[i + 0x167] = oam2_base + 0x60 + i;
		gBg0Tm[i + 0x187] = oam2_base + 0x80 + i;
	}

	EnableBgSync(BG0_SYNC_BIT | BG3_SYNC_BIT);
}


void EndingStep1_Loop(struct ProcGameEnding *proc)
{
	proc->timer++;

	if (proc->timer > 0xF0)
		Proc_Break(proc);
}
