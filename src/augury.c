#include "prelude.h"
#include "hardware.h"
#include "armfunc.h"
#include "menu.h"
#include "bm.h"
#include "faction.h"
#include "unit.h"
#include "talk.h"
#include "event.h"
#include "msg.h"
#include "ui.h"
#include "util.h"
#include "sound.h"
#include "oam.h"
#include "bmio.h"
#include "chapter.h"
#include "unitsprite.h"
#include "playrank.h"
#include "ending.h"
#include "constants/msg.h"
#include "constants/songs.h"
#include "constants/faces.h"
#include "constants/pids.h"

#include "augury.h"

CONST_DATA int AuguryMsgs0[] = {
	MSG_716, MSG_717, MSG_718, MSG_719, MSG_71A, MSG_71B, MSG_71C
};

CONST_DATA int AuguryMsgs1[] = {
	MSG_6F3, MSG_6F4, MSG_6FC,
};

CONST_DATA int AuguryMsgs2[] = {
	MSG_6FD, MSG_6FE, MSG_707,
};

CONST_DATA int AuguryMsgs3[] = {
	MSG_6FB, MSG_6FA, MSG_6F9, MSG_6F8, MSG_6F7, MSG_6F6, MSG_6F5
};

CONST_DATA int AuguryMsgs4[] = {
	MSG_706, MSG_705, MSG_704, MSG_703, MSG_702, MSG_701, MSG_700,
};

CONST_DATA int AuguryMsgs5[] = {
	MSG_708, MSG_709, MSG_70A, MSG_70B, MSG_70C, MSG_70D, MSG_70E,
};

CONST_DATA int AuguryMsgs6[] = {
	MSG_70F, MSG_710, MSG_711, MSG_712, MSG_713, MSG_714, MSG_715,
};

CONST_DATA struct AuguryDispConfig gAuguryDispConfig[] = {
	{ 0x0D, 2, 0, 0 },
	{ 0x0D, 4, 0, 0 },
	{ 0x0D, 6, 0, 0 },
	{ 0x0D, 8, 0, 0 },
	{ 0x14, 2, 0, 0 },
	{ 0x14, 4, 0, 0 },
	{ 0x14, 6, 0, 0 }
};

CONST_DATA struct AuguryConfig gAuguryConfig[] = {
	{
		FID_26, PID_LARUM,
		AuguryMsgs1, AuguryMsgs3, AuguryMsgs5,
	},
	{
		FID_2B, PID_ELFFIN,
		AuguryMsgs2, AuguryMsgs4, AuguryMsgs6,
	},
	{
		FID_02, PID_NONE,
		AuguryMsgs2, AuguryMsgs4, AuguryMsgs6,
	},
};

u16 CONST_DATA Obj_AuguryUI[] = {
	4,
	OAM0_SHAPE_32x8, OAM1_SIZE_32x8, 0,
	OAM0_SHAPE_16x8, OAM1_SIZE_16x8 + OAM1_X(32), OAM2_CHR(0x4),
	OAM0_SHAPE_32x8 + OAM0_Y(8), OAM1_SIZE_32x8, OAM2_CHR(0x20),
	OAM0_SHAPE_16x8 + OAM0_Y(8), OAM1_SIZE_16x8 + OAM1_X(32), OAM2_CHR(0x24),
};

u16 CONST_DATA BgConf_Augury[12] = {
	// tile offset  map offset  screen size
	0x0000,         0x6000,     0,          // BG 0
	0x0000,         0x6800,     0,          // BG 1
	0x0000,         0x7000,     0,          // BG 2
	0x8000,         0x7800,     0,          // BG 3
};

EWRAM_OVERLAY(0) i16 gAuguryIndex = 0;
EWRAM_OVERLAY(0) u16 gAuguryFadeStep = 0;
EWRAM_OVERLAY(0) u16 gAuguryBlendA = 0;
EWRAM_OVERLAY(0) u16 gAuguryBlendB = 0;
EWRAM_OVERLAY(0) u8 gAuguryStatus[7] = {};
EWRAM_OVERLAY(0) u8 gCurrentAuguryIndex = 0;
EWRAM_OVERLAY(0) i8 gAuguryChoice = 0;
EWRAM_OVERLAY(0) struct Text gAuguryTexts[7] = {};
EWRAM_OVERLAY(0) i16 ProcAugury_0868AFF0_EndEnable = 0;
EWRAM_OVERLAY(0) i16 unk_02016A1A = 0;
EWRAM_OVERLAY(0) u16 gPlayRankBg0Offset = 0;
EWRAM_OVERLAY(0) u16 gPlayRankBg1Offset = 0;
EWRAM_OVERLAY(0) u16 gPlayRankDispLine = 0;
EWRAM_OVERLAY(0) u16 gPlayRankBg0MoveStep = 0;
EWRAM_OVERLAY(0) u16 gPlayRankCurChapter = 0;
EWRAM_OVERLAY(0) u16 gPlayRankDispStep = 0;
EWRAM_OVERLAY(0) u16 gPlayRankLayer = 0;
EWRAM_OVERLAY(0) u16 gPlayRankMissonObjSelect = 0;
EWRAM_OVERLAY(0) u8 gPasswdScreenDisabled = 0;
EWRAM_OVERLAY(0) u8 gPlayRankMissionCompleted = 0;
EWRAM_OVERLAY(0) u16 gPlayRanks[7] = {};
EWRAM_OVERLAY(0) u8 gCreditInfoDispStep = 0;
EWRAM_OVERLAY(0) u8 gEndingCgIndex = 0;
EWRAM_OVERLAY(0) u8 gGameEndingFlag = 0;
EWRAM_OVERLAY(0) u8 gCreditNameDispMode = 0;
EWRAM_OVERLAY(0) u8 gEndingDoneFlag = 0;
EWRAM_OVERLAY(0) u8 gEndingDispType = 0;
EWRAM_OVERLAY(0) u8 gCreditNameAnimTimer = 0;
EWRAM_OVERLAY(0) u8 gCreditCharOffsets[0x80] = {};
EWRAM_OVERLAY(0) u8 gCreditCharDelays[0x81] = {};
EWRAM_OVERLAY(0) bool gEndingPInfoIsDyad = 0;
EWRAM_OVERLAY(0) struct Text gEndingPInfoTexts[6] = {};
EWRAM_OVERLAY(0) struct Text gEndingPInfo2Texts[2] = {};
EWRAM_OVERLAY(0) i8 gEndingUid1 = 0;
EWRAM_OVERLAY(0) i8 gEndingUid2 = 0;
EWRAM_OVERLAY(0) u8 gEndingDisplaySecondUnit = 0;
EWRAM_OVERLAY(0) ProcPtr gEndingFace2 = NULL;
EWRAM_OVERLAY(0) u16 EndingFaceXPos[2] = {};
EWRAM_OVERLAY(0) u16 gEndingPInfoPal1[8][0x10] = {};
EWRAM_OVERLAY(0) u16 gEndingPInfoPal2[8][0x10] = {};

bool func_fe6_0808D0C0(struct MenuProc *proc)
{
	TmFillRect(gBg0Tm + TM_OFFSET(12, 1), 6, 14, 0);
	TmFillRect(gBg1Tm + TM_OFFSET(11, 0), 8, 16, 0);

	EndMenu(proc);
	EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT);
	return true;
}

u8 GetAuguryIndex(void)
{
	if (gPlaySt.chapter > 12) {
		int i;

		for (i = 0; i < 2; i++) {
			struct Unit *prophet = GetUnitByPid(gAuguryConfig[i].pid);

			if (prophet) {
				FOR_UNITS_FACTION(FACTION_BLUE, unit, {
					if (UNIT_PID(unit) == gAuguryConfig[i].pid)
						return i ^ 1;
				})
			}
		}
	}
	return -1;
}

void StartAuguryDialogue1(int msg, ProcPtr proc)
{
	SetInitTalkTextFont();
	ClearTalkText();
	EndTalk();

	StartTalkExt(10, 14, DecodeMsg(msg), proc);
	SetTalkPrintColor(TEXT_COLOR_SYSTEM_GRAY);

	SetTalkFlag(TALK_FLAG_INSTANTSHIFT);
	SetTalkFlag(TALK_FLAG_NOBUBBLE);
	SetTalkFlag(TALK_FLAG_NOSKIP);

	SetTalkPrintDelay(3);
	SetActiveTalkFace(TALK_FACE_1);
}

void StartAuguryDialogue2(int msg)
{
	SetInitTalkTextFont();
	ClearTalkText();
	EndTalk();

	StartTalk(10, 14, DecodeMsg(msg));
	SetTalkPrintColor(TEXT_COLOR_SYSTEM_GRAY);

	SetTalkFlag(TALK_FLAG_INSTANTSHIFT);
	SetTalkFlag(TALK_FLAG_NOBUBBLE);
	SetTalkFlag(TALK_FLAG_NOSKIP);

	SetTalkPrintDelay(3);
	SetActiveTalkFace(TALK_FACE_1);
}

void Augury_InitBG(void)
{
	InitBgs(BgConf_Augury);
}

void Augury_InitIO(ProcPtr proc)
{
	SetBlendAlpha(0x10, 1);
	SetBlendTargetA(0, 1, 0, 0, 0);
	SetBlendTargetB(0, 0, 0, 1, 0);
	SetWinEnable(1, 0, 0);
	SetWin0Box(0x40, 0x68, -0x10, -0x68);
	SetWin0Layers(1, 1, 1, 1, 1);
	SetWOutLayers(1, 1, 1, 1, 1);
	gDispIo.win_ct.win0_enable_blend = 1;
	gDispIo.win_ct.wout_enable_blend = 0;

	PutTalkBubbleTm(9, 13, 20, 6);
	PutTalkBubbleTail(8, 16, 2);
	EnableBgSync(BG1_SYNC_BIT);
	func_fe6_0808D954(proc);
}

void func_fe6_0808D308(void)
{
	int x = gAuguryDispConfig[gAuguryIndex].x * 8 - 2;
	int y = gAuguryDispConfig[gAuguryIndex].y * 8;

	switch (gAuguryChoice) {
	case AUGURY_CHOICE_1:
		PutUiHand(x, y);
		break;

	case AUGURY_CHOICE_2:
		PutFrozenUiHand(x, y);
		break;

	default:
		break;
	}
	PutOamHi(0x20, 8, Obj_AuguryUI, 0x2080);
}

void func_fe6_0808D368(void)
{
	gAuguryChoice = AUGURY_CHOICE_1;
}

struct ProcScr CONST_DATA ProcScr_0868AFD8[] = {
	PROC_19,
	PROC_REPEAT(func_fe6_0808D308),
	PROC_END,
};

void Augury_Init(void)
{
	int i;

	gAuguryFadeStep = 0;
	gAuguryChoice = AUGURY_CHOICE_0;
	gCurrentAuguryIndex = GetAuguryIndex();

	if (gCurrentAuguryIndex == (u8)-1)
		gCurrentAuguryIndex = 2;

	ResetText();
	UnpackUiWindowFrameGraphics();
	SetDispEnable(1, 1, 0, 1, 1);

	SetBgOffset(BG_0, 0, 0);
	SetBgOffset(BG_1, 0, 0);
	SetBgOffset(BG_3, 0, 0);

	TmFill(gBg0Tm, 0);
	TmFill(gBg1Tm, 0);
	TmFill(gBg3Tm, 0);

	ApplyPalette(Pal_0833C01C, 4);
	ApplyPalette(Pal_0833C01C + 0x10, 0x12);

	Decompress(Img_0833C09C, OBJ_VRAM0 + 0x1000);
	Decompress(Img_MuralBackground, (void *)BG_VRAM + GetBgChrOffset(BG_3));
	UnpackUiWindowFrameImg((void *)BG_VRAM + 0x3000);
	UnpackUiWindowFrameGraphics();

	TmApplyTsa(gBg1Tm, Tsa_0833C1D8, 0x1180);
	TmApplyTsa(gBg1Tm + TM_OFFSET(11, 1), Tsa_0833C234, 0x1180);
	PutEndingLinearTSA(gBg3Tm, 0x4000);
	ResetTextFont();

	for (i = 0; i < 7; i++) {
		struct Text *text = &gAuguryTexts[i];

		InitText(text, 6);
		ClearText(text);

		PutDrawText(
			text,
			gBg0Tm + TM_OFFSET(gAuguryDispConfig[i].x, gAuguryDispConfig[i].y),
			TEXT_COLOR_SYSTEM_WHITE, 0, 6,
			DecodeMsg(AuguryMsgs0[i])
		);
	}

	gAuguryIndex = 0;
	func_fe6_0808D6D4(0, 0);
	InitTalk(0x200, 2, 1);
	StartTalkFace(gAuguryConfig[gCurrentAuguryIndex].fid, 0x20, 0x50, FACE_DISP_FLIPPED | 2, TALK_FACE_1);
	SpawnProc(ProcScr_0868AFD8, PROC_TREE_3);
	EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT | BG3_SYNC_BIT);

	gPlayRanks[0] = gAuguryStatus[1] = PlayRankGetter_Tactics();
	gPlayRanks[1] = gAuguryStatus[2] = PlayRankGetter_Combat();
	gPlayRanks[2] = gAuguryStatus[3] = PlayRankGetter_Survival();
	gPlayRanks[3] = gAuguryStatus[4] = PlayRankGetter_Experience();
	gPlayRanks[4] = gAuguryStatus[5] = PlayRankGetter_Asset();
	gPlayRanks[5] = gAuguryStatus[6] = PlayRankGetter_Power();
	gAuguryStatus[0] = GameRank_GetTotalRankA();
}

void func_fe6_0808D59C(ProcPtr proc)
{
	int val;

	switch (gAuguryFadeStep) {
	case 0:
		gAuguryBlendA = 0;
		gAuguryBlendB = 0x10;
		gAuguryFadeStep += 1;
		break;

	case 1:
		val = gAuguryBlendB / 4;

		if (val == 0)
			val = 1;

		if (gAuguryBlendB > 1) {
			gAuguryBlendA += val;
			gAuguryBlendB -= val;

			SetBlendAlpha(gAuguryBlendA, gAuguryBlendB);
		} else {
			gAuguryFadeStep = 0;
			Proc_Break(proc);
		}
		break;

	default:
		break;
	}
}

void func_fe6_0808D630(ProcPtr proc)
{
	int val;

	switch (gAuguryFadeStep) {
	case 0:
		if (!IsTalkActive()) {
			ClearTalkText();
			EndTalk();
			EnableBgSync(BG0_SYNC_BIT);
			gAuguryBlendA = 0x10;
			gAuguryBlendB = 0;
			gAuguryFadeStep += 1;
		}
		break;

	case 1:
		val = gAuguryBlendA / 4;

		if (val == 0)
			val = 1;

		if (gAuguryBlendA >= 1) {
			gAuguryBlendA -= val;
			gAuguryBlendB += val;

			SetBlendAlpha(gAuguryBlendA, gAuguryBlendB);
		} else {
			gAuguryFadeStep = 0;
			Proc_Break(proc);
		}
		break;

	default:
		break;
	}
}

void func_fe6_0808D6D4(u16 a, u16 b)
{
	int offset, tmp, tileref0, tileref1;

	tileref0 = 0x11DE;
	tileref1 = 0x11DD;
	if (a <= 3) {
		tmp = tileref0;

		tileref0 = tileref1;
		tileref1 = tmp;
	}

	offset = TM_OFFSET(gAuguryDispConfig[a].x, gAuguryDispConfig[a].y + 1) - 1;

	gBg1Tm[offset + 0] = tileref0;
	gBg1Tm[offset + 1] = tileref1;
	gBg1Tm[offset + 2] = tileref0;
	gBg1Tm[offset + 3] = tileref1;
	gBg1Tm[offset + 4] = tileref0;
	gBg1Tm[offset + 5] = tileref1;
	gBg1Tm[offset + 6] = tileref0;


	tileref0 = 0x11F8;
	tileref1 = 0x11FB;
	if (b <= 3) {
		tmp = tileref0;

		tileref0 = tileref1;
		tileref1 = tmp;
	}

	offset = TM_OFFSET(gAuguryDispConfig[b].x, gAuguryDispConfig[b].y + 1) - 1;

	gBg1Tm[offset + 0] = tileref0;

	tileref0 += 1;
	tileref1 += 1;
	gBg1Tm[offset + 1] = tileref0;
	gBg1Tm[offset + 2] = tileref1;
	gBg1Tm[offset + 3] = tileref0;
	gBg1Tm[offset + 4] = tileref1;
	gBg1Tm[offset + 5] = tileref0;

	tileref1 += 1;
	gBg1Tm[offset + 6] = tileref1;

	EnableBgSync(BG1_SYNC_BIT);
}

void func_fe6_0808D7B4(ProcPtr proc)
{
	StartAuguryDialogue2(gAuguryConfig[gCurrentAuguryIndex].msgs3[gAuguryIndex]);
	PlaySe(SONG_66);
}

void func_fe6_0808D7F8(ProcPtr proc)
{
	int index;
	int ref_index = 4;

	switch (gKeySt->pressed) {
	case KEY_BUTTON_A:
		ClearTalkText();
		EndTalk();
		gAuguryChoice = AUGURY_CHOICE_2;
		PlaySe(SONG_6A);
		Proc_Goto(proc, PL_AUGURY_3);
		return;

	case KEY_BUTTON_B:
		ClearTalkText();
		EndTalk();
		TmFillRect(gBg1Tm + TM_OFFSET(8, 13), 0x15, 6, 0);
		EnableBgSync(BG1_SYNC_BIT);
		PlaySe(SONG_6B);
		Proc_Goto(proc, PL_AUGURY_4);
		return;

	default:
		index = gAuguryIndex;

		switch (gKeySt->repeated) {
		case KEY_DPAD_UP:
			if (index < ref_index) {
				if (index == 0)
					index = 3;
				else
					index = index - 1;
			} else if (index > ref_index)
				index = index - 1;
			else
				index = 6;
			break;

		case KEY_DPAD_DOWN:
			if (index < ref_index) {
				if (index >= (ref_index - 1))
					index = 0;
				else
					index = index + 1;
			} else if (index <= 5)
				index = index + 1;
			else
				index = 4;
			break;

		case KEY_DPAD_RIGHT:
		case KEY_DPAD_LEFT:
			if (index < ref_index) {
				index += ref_index;
				if (index > 6)
					index = 6;
			} else
				index -= ref_index;
			break;

		default:
			break;
		}
		if (gAuguryIndex != index) {
			func_fe6_0808D6D4(gAuguryIndex, index);

			gAuguryIndex = index;
			func_fe6_0808D7B4(proc);
		}
		break;
	}
}

void func_fe6_0808D900(ProcPtr proc)
{
	if (gKeySt->held & KEY_BUTTON_B) {
		Proc_Goto(proc, PL_AUGURY_4);
		return;
	}

	if (!IsTalkActive())
		Proc_Break(proc);
}

void func_fe6_0808D938(ProcPtr proc)
{
	if (!IsTalkActive())
		Proc_Break(proc);
}

void func_fe6_0808D954(ProcPtr proc)
{
	StartAuguryDialogue1(gAuguryConfig[gCurrentAuguryIndex].msgs1[0], proc);
}

void func_fe6_0808D978(ProcPtr proc)
{
	StartAuguryDialogue1(gAuguryConfig[gCurrentAuguryIndex].msgs1[1], proc);
}

void func_fe6_0808D99C(ProcPtr proc)
{
	StartAuguryDialogue1(MSG_6FF, proc);
}

void func_fe6_0808D9B0(ProcPtr proc)
{
	StartAuguryDialogue1(gAuguryConfig[gCurrentAuguryIndex].msgs2[gAuguryStatus[gAuguryIndex]], proc);
}

void func_fe6_0808D9F0(ProcPtr proc)
{
	StartAuguryDialogue1(gAuguryConfig[gCurrentAuguryIndex].msgs1[2], proc);
}

void AuguryPaletteModify1(u16 *pal, int line, int start, int count, int val)
{
	int i, _v = Div(val * 0x20, 0x10);

	for (i = start; i < (start + count); i++) {
		u16 *cur = pal + PAL_COLOR_OFFSET(line, i);

		int r = RGB_R(*cur);
		int g = RGB_G(*cur);
		int b = RGB_B(*cur);

		r -= (r * _v) >> 5;
		g -= (g * _v) >> 5;
		b -= (b * _v) >> 5;

		*cur = _RGB(r, g, b);
	}
}

void AuguryPaletteModify2(u16 *pal, int line, int start, int count, int val)
{
	int i, _v = Div(val * 0x20, 0x10);

	for (i = start; i < (start + count); i++) {
		u16 *cur = pal + PAL_COLOR_OFFSET(line, i);

		int r = RGB_R(*cur);
		int g = RGB_G(*cur);
		int b = RGB_B(*cur);

		r += ((0x1F - r) * _v) >> 5;
		g += ((0x1F	- g) * _v) >> 5;
		b += ((0x1F - b) * _v) >> 5;

		*cur = _RGB(r, g, b);
	}
}

void func_fe6_0808DB14(int lo0, int hi0, int lo1, int hi1, int x)
{
	int v1 = Interpolate(INTERPOLATE_SQUARE, lo0, hi0, x, 0x37);
	int v2 = Interpolate(INTERPOLATE_SQUARE, lo1, hi1, x, 0x37);

	CpuFastCopy(Pal_0833C01C, gPal + PAL_OFFSET(BGPAL_AUGURY_4), 0x20);

	AuguryPaletteModify2(gPal, BGPAL_AUGURY_4, 10, 5, v1);
	AuguryPaletteModify1(gPal, BGPAL_AUGURY_4,  2, 8, v2);

	EnablePalSync();
}

struct ProcScr CONST_DATA ProcScr_0868AFF0[] = {
	PROC_19,
	PROC_CALL(func_fe6_0808DB90),
	PROC_REPEAT(func_fe6_0808DB98),
	PROC_END,
};

void func_fe6_0808DB90(struct Proc_0868AFF0_Augury *proc)
{
	proc->timer1 = 0;
	proc->timer2 = 0;
}

void func_fe6_0808DB98(struct Proc_0868AFF0_Augury *proc)
{
	switch (proc->timer2) {
	case 0:
		func_fe6_0808DB14(0, 5, 0, 4, proc->timer1);
		proc->timer1++;
		if (proc->timer1 > 0x37) {
			proc->timer1 = 0;
			proc->timer2++;
		}
		break;

	case 5:
		func_fe6_0808DB14(5, 0, 4, 0, proc->timer1);
		proc->timer1++;
		if (proc->timer1 > 0x37) {
			proc->timer1 = 0;
			proc->timer2++;

			if (ProcAugury_0868AFF0_EndEnable != 0)
				Proc_Break(proc);
		}
		break;

	case 10:
		proc->timer2 = 0;
		break;

	default:
		proc->timer2++;
		break;
	}
}

void func_fe6_0808DC30(struct Proc_0868AFF0_Augury *proc)
{
	proc->timer1 = 0;
	proc->current_bgm = GetCurrentBgmSong();
	ProcAugury_0868AFF0_EndEnable = 0;
}

void func_fe6_0808DC4C(struct Proc_0868AFF0_Augury *proc)
{
	if (gCurrentAuguryIndex == 0) {
		switch (proc->timer1) {
		case 0:
			SpawnProc(ProcScr_0868AFF0, PROC_TREE_3);
			break;

		case 0x1E:
			PlaySe(SONG_41);
			break;

		case 0xD2:
			FadeBgmOut(-1);
			break;

		case 0xE6:
			ProcAugury_0868AFF0_EndEnable++;
			break;
		}
	} else {
		switch (proc->timer1) {
		case 0:
			SpawnProc(ProcScr_0868AFF0, PROC_TREE_3);
			PlaySe(SONG_EE);
			break;

		case 0x41:
		case 0x69:
		case 0x73:
		case 0x96:
			PlaySe(SONG_EE);
			break;

		case 0xE6:
			ProcAugury_0868AFF0_EndEnable++;
			break;
		}
	}

	proc->timer1++;

	if (ProcAugury_0868AFF0_EndEnable) {
		StartBgm(proc->current_bgm, NULL);
		Proc_Break(proc);
	}
}

void func_fe6_0808DD24(ProcPtr proc)
{
	ClearPutTalkText();
	EndTalk();
	ClearTalk();
	Proc_EndEach(ProcScr_0868AFD8);
}

struct ProcScr CONST_DATA ProcScr_Augury[] =
{
	PROC_19,
	PROC_CALL(LockGame),
	PROC_CALL(StartMidFadeToBlack),
	PROC_REPEAT(WhileFadeExists),
	PROC_CALL(LockBmDisplay),

PROC_LABEL(PL_AUGURY_0),
	PROC_CALL(Augury_InitBG),
	PROC_CALL(Augury_Init),
	PROC_CALL(StartMidFadeFromBlack),
	PROC_REPEAT(WhileFadeExists),
	PROC_CALL(Augury_InitIO),
	PROC_REPEAT(func_fe6_0808D900),
	PROC_GOTO(PL_AUGURY_2),

PROC_LABEL(PL_AUGURY_1),
	PROC_SLEEP(20),
	PROC_CALL(func_fe6_0808D368),
	PROC_REPEAT(func_fe6_0808D59C),
	PROC_CALL(func_fe6_0808D954),
	PROC_REPEAT(func_fe6_0808D900),

PROC_LABEL(PL_AUGURY_2),
	PROC_CALL(func_fe6_0808D368),
	PROC_SLEEP(5),
	PROC_CALL(func_fe6_0808D7B4),
	PROC_REPEAT(func_fe6_0808D7F8),

PROC_LABEL(PL_AUGURY_3),
	PROC_SLEEP(30),
	PROC_CALL(func_fe6_0808D978),
	PROC_REPEAT(func_fe6_0808D630),
	PROC_SLEEP(1),
	PROC_CALL_ARG(_FadeBgmOut, -1),
	PROC_SLEEP(30),
	PROC_CALL(func_fe6_0808DC30),
	PROC_REPEAT(func_fe6_0808DC4C),
	PROC_SLEEP(10),
	PROC_REPEAT(func_fe6_0808D59C),
	PROC_CALL(func_fe6_0808D99C),
	PROC_SLEEP(30),
	PROC_REPEAT(func_fe6_0808D938),
	PROC_CALL(func_fe6_0808D9B0),
	PROC_REPEAT(func_fe6_0808D938),
	PROC_CALL(func_fe6_0808D9F0),
	PROC_REPEAT(func_fe6_0808D630),
	PROC_GOTO(PL_AUGURY_1),

PROC_LABEL(PL_AUGURY_4),
	PROC_CALL(StartMidFadeToBlack),
	PROC_REPEAT(WhileFadeExists),
	PROC_CALL(func_fe6_0808DD24),
	PROC_CALL(UnlockBmDisplay),
	PROC_CALL(ResetUnitSprites),
	PROC_CALL(InitBmDisplay),
	PROC_CALL(UnlockGame),
	PROC_END,
};
