#include "prelude.h"
#include "armfunc.h"
#include "faction.h"
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
#include "constants/chapters.h"
#include "constants/msg.h"
#include "constants/songs.h"
#include "constants/faces.h"
#include "constants/pids.h"

#include "augury.h"

CONST_DATA int AuguryCategoryMsgs[] = {
	MSG_716, MSG_717, MSG_718, MSG_719, MSG_71A, MSG_71B, MSG_71C
};

CONST_DATA int AuguryScriptMsgsA[] = {
	MSG_6F3, MSG_6F4, MSG_6FC,
};

CONST_DATA int AuguryScriptMsgsB[] = {
	MSG_6FD, MSG_6FE, MSG_707,
};

CONST_DATA int AuguryRankMsgsA[] = {
	MSG_6FB, MSG_6FA, MSG_6F9, MSG_6F8, MSG_6F7, MSG_6F6, MSG_6F5
};

CONST_DATA int AuguryRankMsgsB[] = {
	MSG_706, MSG_705, MSG_704, MSG_703, MSG_702, MSG_701, MSG_700,
};

CONST_DATA int AuguryDescMsgsA[] = {
	MSG_708, MSG_709, MSG_70A, MSG_70B, MSG_70C, MSG_70D, MSG_70E,
};

CONST_DATA int AuguryDescMsgsB[] = {
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
		AuguryScriptMsgsA, AuguryRankMsgsA, AuguryDescMsgsA,
	},
	{
		FID_2B, PID_ELFFIN,
		AuguryScriptMsgsB, AuguryRankMsgsB, AuguryDescMsgsB,
	},
	{
		FID_02, PID_NONE,
		AuguryScriptMsgsB, AuguryRankMsgsB, AuguryDescMsgsB,
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
EWRAM_OVERLAY(0) u8 gAuguryStatus[PLAYRANK_MAX] = {};
EWRAM_OVERLAY(0) u8 gCurrentAuguryIndex = 0;
EWRAM_OVERLAY(0) i8 gAuguryHandState = 0;
EWRAM_OVERLAY(0) struct Text gAuguryTexts[PLAYRANK_MAX] = {};
EWRAM_OVERLAY(0) i16 gAuguryRitualDone = 0;
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
EWRAM_OVERLAY(0) u16 gPlayRanks[PLAYRANK_MAX] = {};
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

bool AuguryMenu_End(struct MenuProc *proc)
{
	TmFillRect(gBg0Tm + TM_OFFSET(12, 1), 6, 14, 0);
	TmFillRect(gBg1Tm + TM_OFFSET(11, 0), 8, 16, 0);

	EndMenu(proc);
	EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT);
	return true;
}

u8 GetAuguryIndex(void)
{
	if (gPlaySt.chapter > CHAPTER_12) {
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
	Augury_TalkPrompt(proc);
}

void AuguryHand_Loop(void)
{
	int x = gAuguryDispConfig[gAuguryIndex].x * 8 - 2;
	int y = gAuguryDispConfig[gAuguryIndex].y * 8;

	switch (gAuguryHandState) {
	case AUGURY_HAND_ACTIVE:
		PutUiHand(x, y);
		break;

	case AUGURY_HAND_FROZEN:
		PutFrozenUiHand(x, y);
		break;

	default:
		break;
	}
	PutOamHi(0x20, 8, Obj_AuguryUI, OAM2_PAL(OBPAL_AUGURY_UI) + OAM2_CHR(OBCHR_AUGURY_UI));
}

void Augury_ShowHand(void)
{
	gAuguryHandState = AUGURY_HAND_ACTIVE;
}

struct ProcScr CONST_DATA ProcScr_AuguryHand[] = {
	PROC_19,
	PROC_REPEAT(AuguryHand_Loop),
	PROC_END,
};

void Augury_Init(void)
{
	int i;

	gAuguryFadeStep = 0;
	gAuguryHandState = AUGURY_HAND_HIDDEN;
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

	ApplyPalette(Pal_AuguryMural, BGPAL_AUGURY_MURAL);
	ApplyPalette(Pal_AuguryMural + 0x10, 0x10 + OBPAL_AUGURY_UI);

	Decompress(Img_AuguryUIObj, OBJ_VRAM0 + OBCHR_AUGURY_UI * CHR_SIZE);
	Decompress(Img_MuralBackground, (void *)BG_VRAM + GetBgChrOffset(BG_3));
	UnpackUiWindowFrameImg((void *)BG_VRAM + BGCHR_AUGURY_WINDOWFRAME * CHR_SIZE);
	UnpackUiWindowFrameGraphics();

	TmApplyTsa(gBg1Tm, Tsa_AuguryTitleFrame, TILEREF(BGCHR_AUGURY_WINDOWFRAME, BGPAL_WINDOWFRAME));
	TmApplyTsa(gBg1Tm + TM_OFFSET(11, 1), Tsa_AuguryMenuFrame, TILEREF(BGCHR_AUGURY_WINDOWFRAME, BGPAL_WINDOWFRAME));
	PutEndingLinearTSA(gBg3Tm, TILEREF(0, BGPAL_AUGURY_MURAL));
	ResetTextFont();

	for (i = 0; i < PLAYRANK_MAX; i++) {
		struct Text *text = &gAuguryTexts[i];

		InitText(text, 6);
		ClearText(text);

		PutDrawText(
			text,
			gBg0Tm + TM_OFFSET(gAuguryDispConfig[i].x, gAuguryDispConfig[i].y),
			TEXT_COLOR_SYSTEM_WHITE, 0, 6,
			DecodeMsg(AuguryCategoryMsgs[i])
		);
	}

	gAuguryIndex = 0;
	Augury_PutSelectBars(0, 0);
	InitTalk(0x200, 2, 1);
	StartTalkFace(gAuguryConfig[gCurrentAuguryIndex].fid, 0x20, 0x50, FACE_DISP_FLIPPED | 2, TALK_FACE_1);
	SpawnProc(ProcScr_AuguryHand, PROC_TREE_3);
	EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT | BG3_SYNC_BIT);

	gPlayRanks[PLAYRANK_TACTICS] = gAuguryStatus[1] = PlayRankGetter_Tactics();
	gPlayRanks[PLAYRANK_COMBAT] = gAuguryStatus[2] = PlayRankGetter_Combat();
	gPlayRanks[PLAYRANK_SURVIVAL] = gAuguryStatus[3] = PlayRankGetter_Survival();
	gPlayRanks[PLAYRANK_EXPERIENCE] = gAuguryStatus[4] = PlayRankGetter_Experience();
	gPlayRanks[PLAYRANK_ASSET] = gAuguryStatus[5] = PlayRankGetter_Asset();
	gPlayRanks[PLAYRANK_POWER] = gAuguryStatus[6] = PlayRankGetter_Power();
	gAuguryStatus[0] = GameRank_GetTotalRankA();
}

void Augury_FadeInBubble(ProcPtr proc)
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

void Augury_FadeOutBubbleAfterTalk(ProcPtr proc)
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

void Augury_PutSelectBars(u16 a, u16 b)
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

void Augury_TalkCategoryDesc(ProcPtr proc)
{
	StartAuguryDialogue2(gAuguryConfig[gCurrentAuguryIndex].desc_msgs[gAuguryIndex]);
	PlaySe(SONG_66);
}

void Augury_SelectLoop(ProcPtr proc)
{
	int index;
	int ref_index = 4;

	switch (gKeySt->pressed) {
	case KEY_BUTTON_A:
		ClearTalkText();
		EndTalk();
		gAuguryHandState = AUGURY_HAND_FROZEN;
		PlaySe(SONG_6A);
		Proc_Goto(proc, PL_AUGURY_DIVINE);
		return;

	case KEY_BUTTON_B:
		ClearTalkText();
		EndTalk();
		TmFillRect(gBg1Tm + TM_OFFSET(8, 13), 0x15, 6, 0);
		EnableBgSync(BG1_SYNC_BIT);
		PlaySe(SONG_6B);
		Proc_Goto(proc, PL_AUGURY_END);
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
			Augury_PutSelectBars(gAuguryIndex, index);

			gAuguryIndex = index;
			Augury_TalkCategoryDesc(proc);
		}
		break;
	}
}

void Augury_WaitTalkOrCancel(ProcPtr proc)
{
	if (gKeySt->held & KEY_BUTTON_B) {
		Proc_Goto(proc, PL_AUGURY_END);
		return;
	}

	if (!IsTalkActive())
		Proc_Break(proc);
}

void Augury_WaitTalk(ProcPtr proc)
{
	if (!IsTalkActive())
		Proc_Break(proc);
}

void Augury_TalkPrompt(ProcPtr proc)
{
	StartAuguryDialogue1(gAuguryConfig[gCurrentAuguryIndex].script_msgs[0], proc);
}

void Augury_TalkRitualStart(ProcPtr proc)
{
	StartAuguryDialogue1(gAuguryConfig[gCurrentAuguryIndex].script_msgs[1], proc);
}

void Augury_TalkDivining(ProcPtr proc)
{
	StartAuguryDialogue1(MSG_6FF, proc);
}

void Augury_TalkRankResult(ProcPtr proc)
{
	StartAuguryDialogue1(gAuguryConfig[gCurrentAuguryIndex].rank_msgs[gAuguryStatus[gAuguryIndex]], proc);
}

void Augury_TalkResultEnd(ProcPtr proc)
{
	StartAuguryDialogue1(gAuguryConfig[gCurrentAuguryIndex].script_msgs[2], proc);
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

void Augury_LerpMuralPalette(int lo0, int hi0, int lo1, int hi1, int x)
{
	int v1 = Interpolate(INTERPOLATE_SQUARE, lo0, hi0, x, 0x37);
	int v2 = Interpolate(INTERPOLATE_SQUARE, lo1, hi1, x, 0x37);

	CpuFastCopy(Pal_AuguryMural, gPal + PAL_OFFSET(BGPAL_AUGURY_MURAL), 0x20);

	AuguryPaletteModify2(gPal, BGPAL_AUGURY_MURAL, 10, 5, v1);
	AuguryPaletteModify1(gPal, BGPAL_AUGURY_MURAL,  2, 8, v2);

	EnablePalSync();
}

struct ProcScr CONST_DATA ProcScr_AuguryMuralGlow[] = {
	PROC_19,
	PROC_CALL(AuguryMuralGlow_Init),
	PROC_REPEAT(AuguryMuralGlow_Loop),
	PROC_END,
};

void AuguryMuralGlow_Init(struct AuguryAnimProc *proc)
{
	proc->timer = 0;
	proc->phase = 0;
}

void AuguryMuralGlow_Loop(struct AuguryAnimProc *proc)
{
	switch (proc->phase) {
	case 0:
		Augury_LerpMuralPalette(0, 5, 0, 4, proc->timer);
		proc->timer++;
		if (proc->timer > 0x37) {
			proc->timer = 0;
			proc->phase++;
		}
		break;

	case 5:
		Augury_LerpMuralPalette(5, 0, 4, 0, proc->timer);
		proc->timer++;
		if (proc->timer > 0x37) {
			proc->timer = 0;
			proc->phase++;

			if (gAuguryRitualDone != 0)
				Proc_Break(proc);
		}
		break;

	case 10:
		proc->phase = 0;
		break;

	default:
		proc->phase++;
		break;
	}
}

void Augury_RitualInit(struct AuguryAnimProc *proc)
{
	proc->timer = 0;
	proc->current_bgm = GetCurrentBgmSong();
	gAuguryRitualDone = 0;
}

void Augury_RitualLoop(struct AuguryAnimProc *proc)
{
	if (gCurrentAuguryIndex == 0) {
		switch (proc->timer) {
		case 0:
			SpawnProc(ProcScr_AuguryMuralGlow, PROC_TREE_3);
			break;

		case 0x1E:
			PlaySe(SONG_41);
			break;

		case 0xD2:
			FadeBgmOut(-1);
			break;

		case 0xE6:
			gAuguryRitualDone++;
			break;
		}
	} else {
		switch (proc->timer) {
		case 0:
			SpawnProc(ProcScr_AuguryMuralGlow, PROC_TREE_3);
			PlaySe(SONG_EE);
			break;

		case 0x41:
		case 0x69:
		case 0x73:
		case 0x96:
			PlaySe(SONG_EE);
			break;

		case 0xE6:
			gAuguryRitualDone++;
			break;
		}
	}

	proc->timer++;

	if (gAuguryRitualDone) {
		StartBgm(proc->current_bgm, NULL);
		Proc_Break(proc);
	}
}

void Augury_End(ProcPtr proc)
{
	ClearPutTalkText();
	EndTalk();
	ClearTalk();
	Proc_EndEach(ProcScr_AuguryHand);
}

struct ProcScr CONST_DATA ProcScr_Augury[] =
{
	PROC_19,
	PROC_CALL(LockGame),
	PROC_CALL(StartMidFadeToBlack),
	PROC_REPEAT(WhileFadeExists),
	PROC_CALL(LockBmDisplay),

PROC_LABEL(PL_AUGURY_START),
	PROC_CALL(Augury_InitBG),
	PROC_CALL(Augury_Init),
	PROC_CALL(StartMidFadeFromBlack),
	PROC_REPEAT(WhileFadeExists),
	PROC_CALL(Augury_InitIO),
	PROC_REPEAT(Augury_WaitTalkOrCancel),
	PROC_GOTO(PL_AUGURY_SELECT),

PROC_LABEL(PL_AUGURY_REPROMPT),
	PROC_SLEEP(20),
	PROC_CALL(Augury_ShowHand),
	PROC_REPEAT(Augury_FadeInBubble),
	PROC_CALL(Augury_TalkPrompt),
	PROC_REPEAT(Augury_WaitTalkOrCancel),

PROC_LABEL(PL_AUGURY_SELECT),
	PROC_CALL(Augury_ShowHand),
	PROC_SLEEP(5),
	PROC_CALL(Augury_TalkCategoryDesc),
	PROC_REPEAT(Augury_SelectLoop),

PROC_LABEL(PL_AUGURY_DIVINE),
	PROC_SLEEP(30),
	PROC_CALL(Augury_TalkRitualStart),
	PROC_REPEAT(Augury_FadeOutBubbleAfterTalk),
	PROC_SLEEP(1),
	PROC_CALL_ARG(_FadeBgmOut, -1),
	PROC_SLEEP(30),
	PROC_CALL(Augury_RitualInit),
	PROC_REPEAT(Augury_RitualLoop),
	PROC_SLEEP(10),
	PROC_REPEAT(Augury_FadeInBubble),
	PROC_CALL(Augury_TalkDivining),
	PROC_SLEEP(30),
	PROC_REPEAT(Augury_WaitTalk),
	PROC_CALL(Augury_TalkRankResult),
	PROC_REPEAT(Augury_WaitTalk),
	PROC_CALL(Augury_TalkResultEnd),
	PROC_REPEAT(Augury_FadeOutBubbleAfterTalk),
	PROC_GOTO(PL_AUGURY_REPROMPT),

PROC_LABEL(PL_AUGURY_END),
	PROC_CALL(StartMidFadeToBlack),
	PROC_REPEAT(WhileFadeExists),
	PROC_CALL(Augury_End),
	PROC_CALL(UnlockBmDisplay),
	PROC_CALL(ResetUnitSprites),
	PROC_CALL(InitBmDisplay),
	PROC_CALL(UnlockGame),
	PROC_END,
};
