#pragma once

#include "prelude.h"
#include "menu.h"
#include "proc.h"

enum video_augury {
    BGPAL_AUGURY_4 = 4,
};

enum AUGURY_CHOICE {
	AUGURY_CHOICE_0,
	AUGURY_CHOICE_1,
	AUGURY_CHOICE_2,
};

enum AUGURY_PROC_LABLE {
	PL_AUGURY_0,
	PL_AUGURY_1,
	PL_AUGURY_2,
	PL_AUGURY_3,
	PL_AUGURY_4,
	PL_AUGURY_5,
	PL_AUGURY_6,
};

struct AuguryDispConfig {
	u8 x, y;

	u8 _pad_[2];
};

struct AuguryConfig {
	/* 00 */ u8 fid;
	/* 01 */ u8 pid;
	/* 04 */ int *msgs1;
	/* 08 */ int *msgs2;
	/* 0C */ int *msgs3;
};

struct Proc_0868AFF0_Augury {
	PROC_HEADER;

	i16 timer1;
	i16 timer2;
	int current_bgm;
};

struct ProcAugury {
	PROC_HEADER;
};

extern EWRAM_OVERLAY(0) i16 gAuguryIndex;
extern EWRAM_OVERLAY(0) u16 gAuguryFadeStep;
extern EWRAM_OVERLAY(0) u16 gAuguryBlendA;
extern EWRAM_OVERLAY(0) u16 gAuguryBlendB;
extern EWRAM_OVERLAY(0) u8 gAuguryStatus[7];
extern EWRAM_OVERLAY(0) u8 gCurrentAuguryIndex;
extern EWRAM_OVERLAY(0) i8 gAuguryChoice;
extern EWRAM_OVERLAY(0) struct Text gAuguryTexts[7];
extern EWRAM_OVERLAY(0) i16 ProcAugury_0868AFF0_EndEnable;
extern EWRAM_OVERLAY(0) i16 unk_02016A1A;
extern EWRAM_OVERLAY(0) u16 gPlayRankBg0Offset;
extern EWRAM_OVERLAY(0) u16 gPlayRankBg1Offset;
extern EWRAM_OVERLAY(0) u16 gPlayRankDispLine;
extern EWRAM_OVERLAY(0) u16 gPlayRankBg0MoveStep;
extern EWRAM_OVERLAY(0) u16 gPlayRankCurChapter;
extern EWRAM_OVERLAY(0) u16 gPlayRankDispStep;
extern EWRAM_OVERLAY(0) u16 gPlayRankLayer;
extern EWRAM_OVERLAY(0) u16 gPlayRankMissonObjSelect;
extern EWRAM_OVERLAY(0) u8 gPasswdScreenDisabled;
extern EWRAM_OVERLAY(0) u8 gPlayRankMissionCompleted;
extern EWRAM_OVERLAY(0) u16 gPlayRanks[7];

bool func_fe6_0808D0C0(struct MenuProc *proc);
fu8 GetAuguryIndex(void);
void StartAuguryDialogue1(int msg, ProcPtr proc);
void StartAuguryDialogue2(int msg);
void Augury_InitBG(void);
void Augury_InitIO(ProcPtr proc);
void func_fe6_0808D308(void);
void func_fe6_0808D368(void);
void Augury_Init(void);
void func_fe6_0808D59C(ProcPtr proc);
void func_fe6_0808D630(ProcPtr proc);
void func_fe6_0808D6D4(u16 old, u16 new);
void func_fe6_0808D7B4(ProcPtr proc);
void func_fe6_0808D7F8(ProcPtr proc);
void func_fe6_0808D900(ProcPtr proc);
void func_fe6_0808D938(ProcPtr proc);
void func_fe6_0808D954(ProcPtr proc);
void func_fe6_0808D978(ProcPtr proc);
void func_fe6_0808D99C(ProcPtr proc);
void func_fe6_0808D9B0(ProcPtr proc);
void func_fe6_0808D9F0(ProcPtr proc);
void AuguryPaletteModify1(u16 *pal, int line, int start, int count, int val);
void AuguryPaletteModify2(u16 *pal, int line, int start, int count, int val);
void func_fe6_0808DB14(int lo0, int hi0, int lo1, int hi1, int x);
void func_fe6_0808DB90(struct Proc_0868AFF0_Augury *proc);
void func_fe6_0808DB98(struct Proc_0868AFF0_Augury *proc);
void func_fe6_0808DC30(struct Proc_0868AFF0_Augury *proc);
void func_fe6_0808DC4C(struct Proc_0868AFF0_Augury *proc);
void func_fe6_0808DD24(ProcPtr proc);

extern CONST_DATA int AuguryMsgs[];
extern CONST_DATA struct AuguryDispConfig gAuguryDispConfig[];
extern CONST_DATA struct AuguryConfig gAuguryConfig[];
extern CONST_DATA u16 Obj_AuguryUI[];
extern CONST_DATA u16 BgConf_Augury[];
extern CONST_DATA struct ProcScr ProcScr_0868AFD8[];
extern CONST_DATA struct ProcScr ProcScr_0868AFF0[];
extern CONST_DATA struct ProcScr ProcScr_Augury[];
