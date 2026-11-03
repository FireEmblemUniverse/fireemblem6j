#pragma once

#include "prelude.h"
#include "menu.h"
#include "proc.h"

enum video_augury {
    BGPAL_AUGURY_4 = 4,
};

enum AUGURY_HAND_STATE {
	AUGURY_HAND_HIDDEN,
	AUGURY_HAND_ACTIVE,
	AUGURY_HAND_FROZEN,
};

enum AUGURY_PROC_LABLE {
	PL_AUGURY_START,
	PL_AUGURY_REPROMPT,
	PL_AUGURY_SELECT,
	PL_AUGURY_DIVINE,
	PL_AUGURY_END,
};

struct AuguryDispConfig {
	u8 x, y;

	u8 _pad_[2];
};

struct AuguryConfig {
	/* 00 */ u8 fid;
	/* 01 */ u8 pid;
	/* 04 */ int *script_msgs;
	/* 08 */ int *rank_msgs;
	/* 0C */ int *desc_msgs;
};

struct AuguryAnimProc {
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
extern EWRAM_OVERLAY(0) i8 gAuguryHandState;
extern EWRAM_OVERLAY(0) struct Text gAuguryTexts[7];
extern EWRAM_OVERLAY(0) i16 gAuguryRitualDone;
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

bool AuguryMenu_End(struct MenuProc *proc);
fu8 GetAuguryIndex(void);
void StartAuguryDialogue1(int msg, ProcPtr proc);
void StartAuguryDialogue2(int msg);
void Augury_InitBG(void);
void Augury_InitIO(ProcPtr proc);
void AuguryHand_Loop(void);
void Augury_ShowHand(void);
void Augury_Init(void);
void Augury_FadeInBubble(ProcPtr proc);
void Augury_FadeOutBubbleAfterTalk(ProcPtr proc);
void Augury_PutSelectBars(u16 old, u16 new);
void Augury_TalkCategoryDesc(ProcPtr proc);
void Augury_SelectLoop(ProcPtr proc);
void Augury_WaitTalkOrCancel(ProcPtr proc);
void Augury_WaitTalk(ProcPtr proc);
void Augury_TalkPrompt(ProcPtr proc);
void Augury_TalkRitualStart(ProcPtr proc);
void Augury_TalkDivining(ProcPtr proc);
void Augury_TalkRankResult(ProcPtr proc);
void Augury_TalkResultEnd(ProcPtr proc);
void AuguryPaletteModify1(u16 *pal, int line, int start, int count, int val);
void AuguryPaletteModify2(u16 *pal, int line, int start, int count, int val);
void Augury_LerpMuralPalette(int lo0, int hi0, int lo1, int hi1, int x);
void AuguryMuralGlow_Init(struct AuguryAnimProc *proc);
void AuguryMuralGlow_Loop(struct AuguryAnimProc *proc);
void Augury_RitualInit(struct AuguryAnimProc *proc);
void Augury_RitualLoop(struct AuguryAnimProc *proc);
void Augury_End(ProcPtr proc);

extern CONST_DATA struct AuguryDispConfig gAuguryDispConfig[];
extern CONST_DATA struct AuguryConfig gAuguryConfig[];
extern CONST_DATA u16 Obj_AuguryUI[];
extern CONST_DATA u16 BgConf_Augury[];
extern CONST_DATA struct ProcScr ProcScr_AuguryHand[];
extern CONST_DATA struct ProcScr ProcScr_AuguryMuralGlow[];
extern CONST_DATA struct ProcScr ProcScr_Augury[];
