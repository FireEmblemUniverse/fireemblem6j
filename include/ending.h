#pragma once

#include "prelude.h"
#include "proc.h"

enum video_alloc_credit {
	BGPAL_CREDIT_GLYPH = 4,
	OBPAL_CREDIT_GLYPH = 4,

	BGCHR_CREDIT_GLYPH_NARROW = 0x80,
	OBCHR_CREDIT_GLYPH_CAP = 0x280,
	OBCHR_CREDIT_GLYPH_LOW = 0x200,

	BGCHR_ENDING_CG = 0x140,
	BGPAL_ENDING_CG = 6,
};

enum ending_disp_type {
	ENDING_DISP_0 = 0,
	ENDING_DISP_1,
	ENDING_DISP_2,
	ENDING_DISP_3,
};

struct ProcGameCredit {
	PROC_HEADER;

	STRUCT_PAD(0x29, 0x4C);

	/* 4C */ i16 unk_4C;

	STRUCT_PAD(0x4E, 0x64);

	i16 timer;
};

struct ProcGameEnding {
	PROC_HEADER;

	STRUCT_PAD(0x29, 0x64);

	i16 timer;
	u16 step;
};

struct CreditInfo {
	const char *job;
	const char *staff;
	u8 x, y;
	u16 _pad_;
};

extern CONST_DATA struct CreditInfo gCreditInfo[];

struct PidEndingInfo {
	/* 00 */ u16 msg_00;
	/* 02 */ u16 msg_02;
	/* 04 */ u16 msg_04;
	/* 06 */ u16 msg_06;
};

extern CONST_DATA struct PidEndingInfo gPersonEndingInfo[];

extern EWRAM_OVERLAY(0) u8 gCreditInfoDispStep;
extern EWRAM_OVERLAY(0) u8 gEndingCgIndex;

enum game_ending_flags {
	GAME_ENDING_FLAG0 = 1 << 0,
	GAME_ENDING_FLAG1 = 1 << 1,
	GAME_ENDING_FLAG2 = 1 << 2,
	GAME_ENDING_FLAG3 = 1 << 3,
	GAME_ENDING_FLAG4 = 1 << 4,
	GAME_ENDING_FLAG5 = 1 << 5,
};
extern EWRAM_OVERLAY(0) u8 gGameEndingFlag;

extern EWRAM_OVERLAY(0) u8 gCreditNameDispMode;
extern EWRAM_OVERLAY(0) u8 gEndingDoneFlag;
extern EWRAM_OVERLAY(0) u8 gEndingDispType;
extern EWRAM_OVERLAY(0) u8 gCreditNameAnimTimer;
extern EWRAM_OVERLAY(0) u8 gCreditCharOffsets[0x80];
extern EWRAM_OVERLAY(0) u8 gCreditCharDelays[0x81];
extern EWRAM_OVERLAY(0) bool gEndingPInfoIsDyad;
extern EWRAM_OVERLAY(0) struct Text gEndingPInfoTexts[6];
extern EWRAM_OVERLAY(0) struct Text gEndingPInfo2Texts[2];
extern EWRAM_OVERLAY(0) i8 gEndingUid1;
extern EWRAM_OVERLAY(0) i8 gEndingUid2;
extern EWRAM_OVERLAY(0) u8 gEndingDisplaySecondUnit;
extern EWRAM_OVERLAY(0) ProcPtr gEndingFace2;
extern EWRAM_OVERLAY(0) u16 EndingFaceXPos[2];
extern EWRAM_OVERLAY(0) u16 gEndingPInfoPal1[8][0x10];
extern EWRAM_OVERLAY(0) u16 gEndingPInfoPal2[8][0x10];

extern EWRAM_DATA i8 gEndingUids1[55];
extern EWRAM_DATA i8 gEndingUids2[14];

void SetupCreditCharacterGlyphs(void);
void PutEndingCreditTm(u16 *tm, u16 oam2, u8 w, u8 h);
void EndingCredit_Reinit(struct ProcGameCredit *proc);
void GameCredit_Init(struct ProcGameCredit *proc);
void EndingCredit_ReinitType2(struct ProcGameCredit *proc);
void EndingCredit_ReinitType0(struct ProcGameCredit *proc);
u8 func_fe6_0808FF04(struct ProcGameCredit *proc, int b, int c);
int EndingCredit_FindWordLen(int a, int b, int c);
void func_fe6_0808FFE0(struct ProcGameCredit *proc, int step);
void EndingCredit_PutJobName(int step);

void func_fe6_080904F0(struct ProcGameEnding *proc);
void func_fe6_08090508(struct ProcGameEnding *proc);
void func_fe6_0809058C(void);
void func_fe6_080905A0(struct ProcGameEnding *proc);
void func_fe6_0809060C(void);
void TriggerEndingDone(void);
int func_fe6_08090630(void);
void func_fe6_08090644(ProcPtr proc);
void func_fe6_08090660(ProcPtr proc);
void EndingCredit_Init(struct ProcGameEnding *proc);
void EndingCredit_Loop(struct ProcGameEnding *proc);
void EndingCredit_End(struct ProcGameEnding *proc);

struct ProcEndingCopyRight {
	PROC_HEADER;

	STRUCT_PAD(0x29, 0x4E);

	u16 timer;
};

void EndingCopyRight_Init(struct ProcEndingCopyRight *proc);
void EndingCopyRight_Loop(struct ProcEndingCopyRight *proc);

void PutEndingLinearTSA(u16 *tm, int oam2);
void EndingStep1_End(struct ProcGameEnding *proc);
void EndingStep1_Init(struct ProcGameEnding *proc);
void EndingStep1_Loop(struct ProcGameEnding *proc);
void Fin_Init(struct ProcGameEnding *proc);
void Fin_Loop(struct ProcGameEnding *proc);
bool CheckDisplayEndingCG(void);
void EndingCG_Init(struct ProcGameEnding *proc);
void EndingCG_Loop(struct ProcGameEnding *proc);

/* ending handler */
bool CheckGameEndingDone(void);
void Ending_Init(struct ProcGameEnding *proc);
void Ending_Loop(struct ProcGameEnding *proc);
void StartGameEnding(ProcPtr parent);
void GameCredit_Loop(struct ProcGameCredit *proc);
void StartGameCredit(void);

/* ending pinfo */
bool CheckRoysBestPartner(u8 pid);
void EndingFacePalCtrl(void);
void HBlank_Ending_SinglePInfo(void);
void HBlank_Ending_DyadPInfo(void);
void SetupTrueEndingUids(void);
void SetupFakeEndingUids(void);
void SetupEndingPInfo2Uids(void);

struct ProcEndingPInfo1 {
	PROC_HEADER;

	/* 2C */ int timer;
	/* 30 */ int duration;
};

struct ProcEndingPInfoDisp {
	PROC_HEADER;

	STRUCT_PAD(0x29, 0x2C);

	/* 2C */ int timer;
};

struct ProcEndingPinfoText {
	PROC_HEADER;

	STRUCT_PAD(0x29, 0x54);

	int text_x;
};

extern IWRAM_DATA ProcPtr gEndingFace1;

void EndingPInfoDisp_InitDisp(struct ProcEndingPInfo1 *proc);
u8 PopNextEndingPerson(void);
u8 PopNextEnding2Person(u8 pos);
void EndingP0InfoText_Init(struct ProcEndingPinfoText *proc);
void EndingP0InfoText_Loop(struct ProcEndingPinfoText *proc);
void EndingPInfo1_PutP0InfoText(struct ProcEndingPInfo1 *proc);
void EndingPInfo1_StartMerge(struct ProcEndingPInfo1 *proc);
void EndingPInfo1_Idle(struct ProcEndingPInfo1 *proc);
void EndingPInfo1_End(struct ProcEndingPInfo1 *proc);

bool EndingPInfo1Exists(void);
void EndingP1InfoText_Init(struct ProcEndingPinfoText *proc);
void EndingP1InfoText_Loop(struct ProcEndingPinfoText *proc);
void SpawnEndingP1InfoText(void);
void EndingP2InfoText_Init(struct ProcEndingPinfoText *proc);
void EndingP2InfoText_Loop(struct ProcEndingPinfoText *proc);
void SpawnEndingP2InfoText(void);
void Ending_DrawDyadPInfo(struct ProcEndingPInfoDisp *proc);
void EndingPInfoDisp_Loop(struct ProcEndingPInfoDisp *proc);
void EndingPInfoDisp_End(struct ProcEndingPInfoDisp *proc);
bool EndingFacePosCtrlExists(void);
void EndingFacePosCtrl_Init(ProcPtr proc);
void EndingFacePosCtrl_Loop(ProcPtr proc);
void Ending_DrawPInfoTitle(u8 x, u8 y, struct Unit *unit, u8 type);

extern CONST_DATA u16 BgConf_Ending[];

struct EndingCreditFontObjConf {
	u8 unk_00;
	u8 unk_01;
	u8 unk_02;
	u8 unk_03;
	u8 unk_04;
	u8 unk_05;

	u16 _pad_6;
};
extern CONST_DATA struct EndingCreditFontObjConf gEndingCredit_FontObjConf[];

struct EndingCreditWordLenConf {
	u8 unk_0;
	u8 unk_1;
	u8 unk_2;
	u8 unk_3;
};

extern CONST_DATA struct EndingCreditWordLenConf gEndingCredit_WordLenConf[];
extern CONST_DATA struct ProcScr ProcScr_0868BB3C[];
extern CONST_DATA struct ProcScr ProcScr_0868BB5C[];
extern CONST_DATA struct ProcScr ProcScr_0868BB7C[];
extern CONST_DATA struct ProcScr ProcScr_EndingCredit[];
extern CONST_DATA struct ProcScr ProcScr_EndingCopyRight[];
extern CONST_DATA struct ProcScr ProcScr_EndingStep1_PutFighterMonologue[];
extern CONST_DATA struct ProcScr ProcScr_Fin[];

struct EndingCgConf {
	const u8 *img1;
	const u16 *pal1;
	const u8 *img2;
	const u16 *pal2;
};

extern CONST_DATA struct EndingCgConf gEndingCgConf[];
extern CONST_DATA struct ProcScr ProcScr_EndingCG[];
extern CONST_DATA struct ProcScr ProcScr_Ending[];
extern CONST_DATA struct ProcScr ProcScr_GameCredit[];
extern CONST_DATA struct ProcScr ProcScr_EndingP0InfoText[];
extern CONST_DATA struct ProcScr ProcScr_EndingPInfo_x1[];
extern CONST_DATA struct ProcScr ProcScr_EndingP1InfoText[];
extern CONST_DATA struct ProcScr ProcScr_EndingP2InfoText[];
extern CONST_DATA struct ProcScr ProcScr_EndingPInfo_x2[];
extern CONST_DATA struct ProcScr ProcScr_EndingFacePosCtrl[];
