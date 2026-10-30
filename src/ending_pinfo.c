#include "prelude.h"
#include "proc.h"
#include "unit.h"
#include "support.h"
#include "faction.h"
#include "item.h"
#include "util.h"
#include "hardware.h"
#include "face.h"
#include "oam.h"
#include "msg.h"
#include "text.h"
#include "helpbox.h"
#include "ui.h"
#include "util.h"
#include "armfunc.h"
#include "banim.h"
#include "sprite.h"
#include "armfunc.h"
#include "save_stats.h"
#include "save_xmap.h"
#include "gamecontroller.h"
#include "chapterinfo.h"

#include "constants/chapters.h"
#include "constants/pids.h"
#include "constants/msg.h"
#include "constants/videoalloc_global.h"

#include "playrank.h"
#include "ending.h"

EWRAM_DATA i8 gEndingUids1[55] = {};
EWRAM_DATA i8 gEndingUids2[14] = {};

bool CheckRoysBestPartner(u8 pid)
{
	struct Unit *roy = GetUnitByPid(PID_ROY);

	if (GetUnitSupportLevel(roy, GetUnitSupportNumByPid(roy, pid)) >= SUPPORT_LEVEL_A)
		return true;
	else
		return false;

}

void EndingFacePalCtrl(void)
{
	int i;

	for (i = 1; i < 0x10; i++) {
		if (gEndingPInfoPal1[0][i] != gPal[0x20 + i]) {
			for (i = 0; i < 8; i++) {
				CpuFastCopy(PAL_BG(2), gEndingPInfoPal1[i], 0x20);
				EfxPalBlackInOut(gEndingPInfoPal1[0], i, 1, i);
				CpuFastCopy(PAL_BG(3), gEndingPInfoPal2[i], 0x20);
				EfxPalBlackInOut(gEndingPInfoPal2[0], i, 1, i);
			}
			return;
		}
	}
}

void HBlank_Ending_SinglePInfo(void)
{
	int pal_bank = 0;

	switch (REG_VCOUNT) {
	case 0x18:
		REG_BG0VOFS = 4;
		break;

	case 0:
	case 0x30:
		REG_BG0VOFS = pal_bank;
		break;

	default:
		break;
	}

	switch (REG_VCOUNT) {
	case 0x3C:
		pal_bank++;

	case 0x3A:
	case 0x90:
		pal_bank++;

	case 0x38:
	case 0x92:
		pal_bank++;

	case 0x36:
	case 0x94:
		pal_bank++;

	case 0x34:
	case 0x96:
		pal_bank++;

	case 0x32:
	case 0x98:
		pal_bank++;

	case 0x30:
	case 0x9A:
		pal_bank++;

	case 0:
	case 0x9C: {
			int i;
			u16 *var_0 = ((u16 *)PLTT) + 0x20;
			u16 *var_1 = ((u16 *)PLTT) + 0x30;

			for (i = 0; i < 0x10; i++) {
				var_0[i] = gEndingPInfoPal1[pal_bank][i];
				var_1[i] = gEndingPInfoPal2[pal_bank][i];
			}
		}
		break;

	default:
		break;
	}
}

void HBlank_Ending_DyadPInfo(void)
{
	int i, vcount, pal_bank = 0;

	vcount = REG_VCOUNT;
	if (vcount == 0) {
		REG_BG0HOFS = EndingFaceXPos[0];
		REG_BG1HOFS = EndingFaceXPos[0];
	}

	vcount = REG_VCOUNT;
	if (vcount == 0x50) {
		REG_BG0HOFS = EndingFaceXPos[1];
		REG_BG1HOFS = EndingFaceXPos[1];
	}

	vcount = REG_VCOUNT;
	switch (vcount) {
	case 0:
	case 0x50:
		REG_BG0VOFS = 0;
		break;

	case 0x18:
	case 0x68:
		REG_BG0VOFS = 4;
		break;

	case 0x2A:
	case 0x7A:
		REG_BG0VOFS = 5;
		break;
	}

	switch (REG_VCOUNT) {
	case 72:
		pal_bank++;

		/* fallthrough */

	case 63:
	case 89:
		pal_bank++;

		/* fallthrough */

	case 54:
	case 98:
		pal_bank++;

		/* fallthrough */

	case 45:
	case 107:
		pal_bank++;

		/* fallthrough */

	case 36:
	case 116:
		pal_bank++;

		/* fallthrough */

	case 27:
	case 125:
		pal_bank++;

		/* fallthrough */

	case 18:
	case 134:
		pal_bank++;

		/* fallthrough */

	case 9:
	case 143: {
			u16 *var_0 = ((u16 *)PLTT) + 0x20;
			u16 *var_1 = ((u16 *)PLTT) + 0x30;

			for (i = 0; i < 0x10; i++) {
				var_0[i] = gEndingPInfoPal1[pal_bank][i];
				var_1[i] = gEndingPInfoPal2[pal_bank][i];
			}
			break;
		}

	default:
		break;
	}
}

void SetupTrueEndingUids(void)
{
	int iuid;
	int c1 = 0;
	int c2 = 0;

	for (iuid = 1; iuid < (FACTION_BLUE + 0x40); iuid++) {
		struct Unit *unit = GetUnit(iuid);

		if (!UNIT_IS_VALID(unit))
			continue;

		if (!(unit->flags & UNIT_FLAG_NOT_DEPLOYED)) {
			if (c1 < 14)
				gEndingUids2[c1++] = iuid;
		} else {
			if (c2 < 54)
				gEndingUids1[c2++] = iuid;
		}
	}

	gEndingUids2[c1] = -1;
	gEndingUids1[c2] = -1;
}

void SetupFakeEndingUids(void)
{
	int iuid, count = 0;

	for (iuid = 1; iuid < (FACTION_BLUE + 0x40); iuid++) {
		struct Unit *unit = GetUnit(iuid);

		if (!UNIT_IS_VALID(unit))
			continue;

		if (count < 54)
			gEndingUids1[count++] = iuid;
	}

	gEndingUids1[count] = -1;
}

void SetupEndingPInfo2Uids(void)
{
	gEndingUid1 = 1;
	gEndingUid2 = 1;
}

void EndingPInfoDisp_InitDisp(struct ProcEndingPInfo1 *proc)
{
	u16 bg_config[12] = {
		0x0000, 0xD800, 1,
		0x0000, 0xE800, 1,
		0x8000, 0x7000, 0,
		0x8000, 0x7800, 0,
	};

	InitBgs(bg_config);
	SetDispEnable(1, 1, 0, 1, 1);
	SetBlendConfig(BLEND_EFFECT_NONE, 0, 0, 0);
	SetBlendTargetA(0, 0, 0, 0, 0);
	SetBlendTargetB(0, 0, 0, 0, 0);

	InitFaces();
	ResetText();
	ApplyPalettes(Pal_MonologueBG, 2, 2);
	Decompress(Img_MonologueBG, (u8 *)BG_VRAM + 0x8000);
	ApplyPalettes(Pal_EndingPInfoWindow, 4, 2);
	Decompress(Img_EndingPInfoWindow, (u8 *)BG_VRAM + 0x6000);
}

u8 PopNextEndingPerson(void)
{
	int uid = (i8)gEndingUid1;

	if (uid >= (FACTION_BLUE + 0x40))
		return uid;

	do {
		const i8 *it;
		struct Unit *unit;

		unit = GetUnit(uid);
		if (!UNIT_IS_VALID(unit))
			continue;

		if (UNIT_PID(unit) == PID_MERLINUS)
			continue;

		for (it = gEndingUids2; *it != -1; it++)
			if (*it == uid)
				return uid;
	} while ((++uid) < (FACTION_BLUE + 0x40));

	return uid;
}

u8 PopNextEnding2Person(u8 pos)
{
	int uid;
	int _uid;

	if (pos != POS_L)
		_uid = gEndingUid1;
	else
		_uid = gEndingUid2;

	uid = _uid;
	if (uid >= (FACTION_BLUE + 0x40))
		return uid;

	do {
		int i;
		struct Unit *unit;

		unit = GetUnit(uid);
		if (!UNIT_IS_VALID(unit))
			continue;

		if (UNIT_PID(unit) == PID_MERLINUS)
			continue;

		for (i = 0; gEndingUids1[i] != -1; i++)
			if (gEndingUids1[i] == uid)
				return uid;
	} while ((++uid) < (FACTION_BLUE + 0x40));

	return uid;
}

struct ProcScr CONST_DATA ProcScr_EndingP0InfoText[] = {
	PROC_19,
	PROC_CALL(EndingP0InfoText_Init),
	PROC_SLEEP(1),
	PROC_REPEAT(EndingP0InfoText_Loop),
	PROC_END,
};

void EndingP0InfoText_Init(struct ProcEndingPinfoText *proc)
{
	int i;
	i8 uid = gEndingUid1;
	struct Unit *unit = GetUnit(uid - 1);
	int pid = UNIT_PID(unit);
	struct PidStats *pid_status = GetPidStats(pid);
	struct ProcTypeWritter *type_writter =  SpawnProc(ProcScr_TypeWritter, PROC_TREE_3);

	for (i = 0; i < 6; i++) {
		struct Text *text = &gEndingPInfoTexts[i];

		InitText(text, (i < 2) ? 20: 30);
		Text_SetColor(text, TEXT_COLOR_SYSTEM_WHITE);
		PutText(text, gBg0Tm + TM_OFFSET(1, 0) + TM_OFFSET(0, 7 + i * 2));
		type_writter->text[i] = text;
	}

	if (unit->flags & UNIT_FLAG_DEAD) {
		proc->text_x = PlayRank_ChapterTurns_DrawBase(
			&gEndingPInfoTexts[0],
			GetChapterInfo(pid_status->defeat_chapter)->index_gaiden,
			false);

		Text_SetCursor(&gEndingPInfoTexts[0], proc->text_x + 3);
		type_writter->str_it = DecodeMsg(GetChapterInfo(pid_status->defeat_chapter)->msg_chapter_title);

		proc->text_x += GetStringTextLen(DecodeMsg(GetChapterInfo(pid_status->defeat_chapter)->msg_chapter_title)) + 6;
	} else {
		const char *str;

		if (CheckRoysBestPartner(pid) != false)
			str = DecodeMsg(gPersonEndingInfo[pid].msg_02);
		else
			str = DecodeMsg(gPersonEndingInfo[pid].msg_00);

		type_writter->str_it = str;
	}

	type_writter->line = 0;
	type_writter->font = NULL;
	type_writter->clock_interval = 4;
	type_writter->chars_per_print = 1;
	type_writter->clock = 0;
	EnableBgSync(BG0_SYNC_BIT);
}

void EndingP0InfoText_Loop(struct ProcEndingPinfoText *proc)
{
	i8 uid = gEndingUid1;

	if (GetUnit(uid - 1)->flags & UNIT_FLAG_DEAD) {
		int i;
		struct ProcTypeWritter *type_writter;

		if (FindProc(ProcScr_TypeWritter)) {
			/* waiting for exists typing done */
			return;
		}

		type_writter = SpawnProc(ProcScr_TypeWritter, PROC_TREE_3);

		for (i = 0; i < 6; i++)
			type_writter->text[i] = &gEndingPInfoTexts[i];

		Text_SetCursor(&gEndingPInfoTexts[0], proc->text_x);
		type_writter->str_it = DecodeMsg(MSG_A6E);
		type_writter->line = 0;
		type_writter->font = NULL;
		type_writter->clock_interval = 4;
		type_writter->chars_per_print = 1;
		type_writter->clock = 0;
		EnableBgSync(BG0_SYNC_BIT);
	}
	Proc_Break(proc);
}

struct ProcScr CONST_DATA ProcScr_EndingPInfo_x1[] = {
	PROC_19,
	PROC_CALL(FadeInBlackWithCallBack_Speed40),
	PROC_SLEEP(1),
	PROC_CALL(EndingPInfoDisp_InitDisp),
	PROC_CALL(EndingPInfo1_StartMerge),
	PROC_CALL(FadeInBlackSpeed08),
	PROC_SLEEP(1),
	PROC_CALL(EndingPInfo1_PutP0InfoText),
	PROC_REPEAT(EndingPInfo1_Idle),
	PROC_CALL(FadeInBlackWithCallBack_Speed08),
	PROC_SLEEP(1),
	PROC_CALL(EndingPInfo1_End),
	PROC_SLEEP(32),
PROC_LABEL(99),
	PROC_END,
};

void EndingPInfo1_PutP0InfoText(struct ProcEndingPInfo1 *proc)
{
	i8 uid = gEndingUid1;

	if (GetUnit(uid - 1)->flags & UNIT_FLAG_DEAD)
		proc->duration = 0x12C;
	else
		proc->duration = 0x352;

	SpawnProc(ProcScr_EndingP0InfoText, PROC_TREE_3);
}

void EndingPInfo1_StartMerge(struct ProcEndingPInfo1 *proc)
{
	u8 fid, uid;
	struct Unit *unit;

	uid = PopNextEndingPerson();
	gEndingUid1 = uid + 1;
	unit = GetUnit(uid);
	fid = GetUnitFid(unit);


	ResetText();
	TmApplyTsa(gBg3Tm, Tsa_EndingPInfoBG, 0x2000);
	CpuFastFill16(0, (u8 *)BG_VRAM + 0xD800, 0x2000);
	StartFace(0, fid, 0xBE, 2, 0x42);
	Ending_DrawPInfoTitle(0, 0, unit, 0);

	proc->timer = 0;
	gEndingPInfoIsDyad = false;

	SpawnProc(ProcScr_EndingFacePosCtrl, PROC_TREE_VSYNC);
	SetOnHBlankA(HBlank_Ending_SinglePInfo);
	EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT);
}

void EndingPInfo1_Idle(struct ProcEndingPInfo1 *proc)
{
	proc->timer++;

	if (proc->timer == proc->duration)
		Proc_Break(proc);
}

void EndingPInfo1_End(struct ProcEndingPInfo1 *proc)
{
	EndFaceById(0);
	Proc_EndEach(ProcScr_TypeWritter);
	Proc_EndEach(ProcScr_EndingFacePosCtrl);
	SetOnHBlankA(NULL);
}

bool EndingPInfo1Exists(void)
{
	return Proc_Exists(ProcScr_EndingPInfo_x1);
}

struct ProcScr CONST_DATA ProcScr_EndingP1InfoText[] = {
	PROC_19,
	PROC_CALL(EndingP1InfoText_Init),
	PROC_SLEEP(1),
	PROC_REPEAT(EndingP1InfoText_Loop),
	PROC_END,
};

void EndingP1InfoText_Init(struct ProcEndingPinfoText *proc)
{
	int i;
	i8 uid = gEndingUid1;
	struct Unit *unit = GetUnit(uid - 1);
	int pid = UNIT_PID(unit);
	struct PidStats *pid_status = GetPidStats(pid);
	struct ProcTypeWritter *type_writter =  SpawnProc(ProcScr_TypeWritter, PROC_TREE_3);

	for (i = 0; i < 2; i++) {
		struct Text *text = &gEndingPInfoTexts[i];

		InitText(text, 20);
		Text_SetColor(text, TEXT_COLOR_SYSTEM_WHITE);
		PutText(text, gBg0Tm + TM_OFFSET(2, 0) + TM_OFFSET(0, 6 + i * 2));
		type_writter->text[i] = text;
	}

	if (unit->flags & UNIT_FLAG_DEAD) {
		proc->text_x = PlayRank_ChapterTurns_DrawBase(
			&gEndingPInfoTexts[0],
			GetChapterInfo(pid_status->defeat_chapter)->index_gaiden,
			false);

		Text_SetCursor(&gEndingPInfoTexts[0], proc->text_x + 3);
		type_writter->str_it = DecodeMsg(GetChapterInfo(pid_status->defeat_chapter)->msg_chapter_title);

		proc->text_x += GetStringTextLen(DecodeMsg(GetChapterInfo(pid_status->defeat_chapter)->msg_chapter_title)) + 6;
	} else {
		type_writter->str_it = DecodeMsg(gPersonEndingInfo[pid].msg_04);

	}

	type_writter->line = 0;
	type_writter->font = NULL;
	type_writter->clock_interval = 4;
	type_writter->chars_per_print = 1;
	type_writter->clock = 0;
	EnableBgSync(BG0_SYNC_BIT);
}

void EndingP1InfoText_Loop(struct ProcEndingPinfoText *proc)
{
	i8 uid = gEndingUid1;

	if (GetUnit(uid - 1)->flags & UNIT_FLAG_DEAD) {
		int i;
		struct ProcTypeWritter *type_writter;

		if (FindProc(ProcScr_TypeWritter)) {
			/* waiting for exists typing done */
			return;
		}

		type_writter = SpawnProc(ProcScr_TypeWritter, PROC_TREE_3);

		for (i = 0; i < 2; i++)
			type_writter->text[i] = &gEndingPInfoTexts[i];

		Text_SetCursor(&gEndingPInfoTexts[0], proc->text_x);
		type_writter->str_it = DecodeMsg(MSG_A6E);
		type_writter->line = 0;
		type_writter->font = NULL;
		type_writter->clock_interval = 4;
		type_writter->chars_per_print = 1;
		type_writter->clock = 0;
		EnableBgSync(BG0_SYNC_BIT);
	}
	Proc_Break(proc);
}

void SpawnEndingP1InfoText(void)
{
	SpawnProc(ProcScr_EndingP1InfoText, PROC_TREE_3);
}

struct ProcScr CONST_DATA ProcScr_EndingP2InfoText[] = {
	PROC_19,
	PROC_CALL(EndingP2InfoText_Init),
	PROC_SLEEP(1),
	PROC_REPEAT(EndingP2InfoText_Loop),
	PROC_END,
};


void EndingP2InfoText_Init(struct ProcEndingPinfoText *proc)
{
	int i;
	i8 uid = gEndingUid2;
	struct Unit *unit = GetUnit(uid - 1);
	int pid = UNIT_PID(unit);
	struct PidStats *pid_status = GetPidStats(pid);
	struct ProcTypeWritter *type_writter =  SpawnProc(ProcScr_TypeWritter, PROC_TREE_3);

	for (i = 0; i < 2; i++) {
		struct Text *text = &gEndingPInfo2Texts[i];

		InitText(text, 20);
		Text_SetColor(text, TEXT_COLOR_SYSTEM_WHITE);
		PutText(text, gBg0Tm + TM_OFFSET(13, 0) + TM_OFFSET(0, 16 + i * 2));
		type_writter->text[i] = text;
	}

	if (unit->flags & UNIT_FLAG_DEAD) {
		proc->text_x = PlayRank_ChapterTurns_DrawBase(
			&gEndingPInfo2Texts[0],
			GetChapterInfo(pid_status->defeat_chapter)->index_gaiden,
			false);

		Text_SetCursor(&gEndingPInfo2Texts[0], proc->text_x + 3);
		type_writter->str_it = DecodeMsg(GetChapterInfo(pid_status->defeat_chapter)->msg_chapter_title);

		proc->text_x += GetStringTextLen(DecodeMsg(GetChapterInfo(pid_status->defeat_chapter)->msg_chapter_title)) + 6;
	} else {
		type_writter->str_it = DecodeMsg(gPersonEndingInfo[pid].msg_04);

	}

	type_writter->line = 0;
	type_writter->font = NULL;
	type_writter->clock_interval = 4;
	type_writter->chars_per_print = 1;
	type_writter->clock = 0;
	EnableBgSync(BG0_SYNC_BIT);
}

void EndingP2InfoText_Loop(struct ProcEndingPinfoText *proc)
{
	i8 uid = gEndingUid2;

	if (GetUnit(uid - 1)->flags & UNIT_FLAG_DEAD) {
		int i;
		struct ProcTypeWritter *type_writter;

		if (FindProc(ProcScr_TypeWritter)) {
			/* waiting for exists typing done */
			return;
		}

		type_writter = SpawnProc(ProcScr_TypeWritter, PROC_TREE_3);

		for (i = 0; i < 2; i++)
			type_writter->text[i] = &gEndingPInfo2Texts[i];

		Text_SetCursor(&gEndingPInfo2Texts[0], proc->text_x);
		type_writter->str_it = DecodeMsg(MSG_A6E);
		type_writter->line = 0;
		type_writter->font = NULL;
		type_writter->clock_interval = 4;
		type_writter->chars_per_print = 1;
		type_writter->clock = 0;
		EnableBgSync(BG0_SYNC_BIT);
	}
	Proc_Break(proc);
}

void SpawnEndingP2InfoText(void)
{
	if (gEndingDisplaySecondUnit == true)
		SpawnProc(ProcScr_EndingP2InfoText, PROC_TREE_3);
}

struct ProcScr CONST_DATA ProcScr_EndingPInfo_x2[] = {
	PROC_19,
	PROC_CALL(FadeInBlackWithCallBack_Speed40),
	PROC_SLEEP(1),
	PROC_CALL(EndingPInfoDisp_InitDisp),
	PROC_CALL(Ending_DrawDyadPInfo),
	PROC_CALL(FadeInBlackSpeed08),
	PROC_SLEEP(1),
	PROC_REPEAT(EndingPInfoDisp_Loop),
	PROC_CALL(FadeInBlackWithCallBack_Speed08),
	PROC_SLEEP(1),
	PROC_CALL(EndingPInfoDisp_End),
	PROC_SLEEP(32),
PROC_LABEL(99),
	PROC_END,
};

void Ending_DrawDyadPInfo(struct ProcEndingPInfoDisp *proc)
{
	int uid1, uid2;
	u8 fid;
	struct Unit *unit;
	ProcPtr faceproc1;
	ProcPtr faceproc2;

	gEndingDisplaySecondUnit = true;
	uid1 = PopNextEnding2Person(POS_L);
	gEndingUid1 = uid1 + 1;

	uid2 = PopNextEnding2Person(POS_R);
	if (uid2 >= FACTION_GREEN)
		gEndingDisplaySecondUnit = false;

	gEndingUid2 = uid2 + 1;

	ResetText();
	TmApplyTsa(gBg3Tm, Tsa_EndingPInfoBG, 0x2000);
	CpuFastFill16(0, (u8 *)BG_VRAM + 0xD800, 0x2000);

	unit = GetUnit(uid1);
	fid = GetUnitFid(unit);
	SetBgOffset(BG_0, 0xFF00, 0);
	faceproc1 = StartFace(0, fid, 0x1BE, 0, 0x42);
	gEndingFace1 = faceproc1;
	Ending_DrawPInfoTitle(0, 0, unit, 1);

	if (gEndingDisplaySecondUnit == true) {
		unit = GetUnit(uid2);
		fid = GetUnitFid(unit);
		SetBgOffset(BG_1, 0x100, 0);
		faceproc2 = StartFace(1, fid, -0xCE, 0x50, 0x43);
		gEndingFace2 = faceproc2;
		Ending_DrawPInfoTitle(0xB, 0xA, unit, 1);
	}

	proc->timer = 0;
	gEndingPInfoIsDyad = true;
	SpawnProc(ProcScr_EndingFacePosCtrl, PROC_TREE_VSYNC);
	SetOnHBlankA(HBlank_Ending_DyadPInfo);
	EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT);
}

void EndingPInfoDisp_Loop(struct ProcEndingPInfoDisp *proc)
{
	switch (proc->timer) {
	default:
		if (proc->timer <= 0x2C){
			struct FaceProc *faceproc;
			
			faceproc = gEndingFace1;
			faceproc->x_disp = 0xBE - EndingFaceXPos[0];

			if (gEndingDisplaySecondUnit == true) {
				faceproc = gEndingFace2;
				faceproc->x_disp = 0x32 - EndingFaceXPos[1];
			}
		}
		break;

	case 0x2D:
		SetBgOffset(BG_0, 0, 0);
		SetBgOffset(BG_1, 0, 0);
		break;

	case 0x3C:
		SpawnEndingP1InfoText();
		break;

	case 0xC8:
		SpawnEndingP2InfoText();
		break;

	case 0x1E0:
		Proc_Break(proc);
		break;
	}
	proc->timer++;
}

void EndingPInfoDisp_End(struct ProcEndingPInfoDisp *proc)
{
	EndFaceById(0);
	EndFaceById(1);
	Proc_EndEach(ProcScr_TypeWritter);
	Proc_EndEach(ProcScr_EndingFacePosCtrl);
	SetOnHBlankA(NULL);
}

struct ProcScr CONST_DATA ProcScr_EndingFacePosCtrl[] = {
	PROC_19,
	PROC_CALL(EndingFacePosCtrl_Init),
	PROC_REPEAT(EndingFacePosCtrl_Loop),
	PROC_END,
};

bool EndingFacePosCtrlExists(void)
{
	return Proc_Exists(ProcScr_EndingPInfo_x2);
}

void EndingFacePosCtrl_Init(ProcPtr proc)
{
	EndingFaceXPos[0] = 0xFF00;
	EndingFaceXPos[1] = 0x100;
}

void EndingFacePosCtrl_Loop(ProcPtr proc)
{
	if (gEndingPInfoIsDyad != false && EndingFaceXPos[1] != 0) {
		struct ProcEndingPInfoDisp *procfx = FindProc(ProcScr_EndingPInfo_x2);

		EndingFaceXPos[0] = Interpolate(INTERPOLATE_RSQUARE, 0xFFFFFF00, 0, procfx->timer, 0x2D);
		EndingFaceXPos[1] = Interpolate(INTERPOLATE_RSQUARE, 0x100, 0, procfx->timer, 0x2D);
	}
	EndingFacePalCtrl();
}

void Ending_DrawPInfoTitle(u8 x, u8 y, struct Unit *unit, u8 type)
{
	struct Text text;
	int off;
	struct PidStats *pid_status = GetPidStats(UNIT_PID(unit));
	int pid = UNIT_PID(unit);
	int var;

	if (type == 0) {
		TmApplyTsa(gBg1Tm + TM_OFFSET(0, 0),  Tsa_GameRank_083461C4, 0x4300);
		TmApplyTsa(gBg1Tm + TM_OFFSET(17, 6), Tsa_GameRank_08346330, 0x4300);
		TmApplyTsa(gBg1Tm + TM_OFFSET(0, 19), Tsa_GameRank_083463B4, 0x4300);
	} else {
		TmApplyTsa(gBg1Tm + TM_OFFSET(x, y), Tsa_GameRank_083463F4, 0x4300);
	}

	var = (0x48 - GetStringTextLen(DecodeMsg(gPersonEndingInfo[pid].msg_06))) / 2;
	PutDrawText(
		NULL,
		gBg0Tm + TM_OFFSET(x + 2, y + 1),
		TEXT_COLOR_SYSTEM_WHITE,
		var,
		9,
		DecodeMsg(gPersonEndingInfo[pid].msg_06)
	);

	var = (0x28 - GetStringTextLen(DecodeMsg(unit->pinfo->msg_name))) / 2;
	PutDrawText(
		NULL,
		gBg0Tm + TM_OFFSET(x + 0xB, y + 1),
		TEXT_COLOR_SYSTEM_WHITE,
		var,
		5,
		DecodeMsg(unit->pinfo->msg_name)
	);

	InitText(&text, 0xF);
	PutText(&text, gBg0Tm + TM_OFFSET(x + 2, y + 4));

	Text_InsertDrawNumberOrBlank(&text, 0x1E, TEXT_COLOR_SYSTEM_WHITE, pid_status->battle_count);
	Text_InsertDrawString(&text, 0x26, TEXT_COLOR_SYSTEM_WHITE, DecodeMsg(MSG_9C6)); // 戦
	off = pid_status->loss_count >= 100 ? 0 : 6;
	Text_InsertDrawNumberOrBlank(&text, off + 0x3F, TEXT_COLOR_SYSTEM_WHITE, pid_status->win_count);
	Text_InsertDrawString(&text, off + 0x47, TEXT_COLOR_SYSTEM_WHITE, DecodeMsg(MSG_9C7)); // 勝
	Text_InsertDrawNumberOrBlank(&text, 0x5F, TEXT_COLOR_SYSTEM_WHITE, pid_status->loss_count);
	Text_InsertDrawString(&text, 0x67, TEXT_COLOR_SYSTEM_WHITE, DecodeMsg(MSG_9C8)); // 敗
}
