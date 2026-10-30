#pragma once

#include "prelude.h"
#include "proc.h"
#include "text.h"
#include "banim.h"
#include "banim_sprite.h"
#include "helpbox.h"

enum videoalloc_playrank {
	BGPAL_PLAYRANK_0 = 0,
	BGPAL_PLAYRANK_1 = 1,
	BGPAL_PLAYRANK_WM = 4,
	BGPAL_PLAYRANK_FOG = 6,

	BGPAL_PLAYRANK_TIME = 2,
	OBPAL_PLAYRANK_MISSION = 3,
	OBPAL_PLAYRANK_4 = 4,
	OBPAL_PLAYRANK_5 = 5,
	OBPAL_PLAYRANK_B = 0xB,
	OBPAL_PLAYRANK_C = 0xC,

	BGCHR_PLAYRANK_80 = 0x80,
	BGCHR_PLAYRANK_C0 = 0xC0,
	BGCHR_PLAYRANK_180 = 0x180,
	BGCHR_PLAYRANK_680 = 0x680,

	OBCHR_PLAYRANK_TIME = 0x80,
	OBCHR_PLAYRANK_84 = 0x84,
	OBCHR_PLAYRANK_98 = 0x98,
};

enum play_ranks {
	PALYRANK_D,
	PALYRANK_C,
	PALYRANK_B,
	PALYRANK_A,
	PALYRANK_MAX,

	PALYRANK_S = PALYRANK_MAX,
};

enum PlayRankSt_texts_idx {
	PLAYRANK_TEXT_0,
	PLAYRANK_TEXT_1,
	PLAYRANK_TEXT_2,
	PLAYRANK_TEXT_3,
	PLAYRANK_TEXT_4,
	PLAYRANK_TEXT_5,
	PLAYRANK_TEXT_6,
	PLAYRANK_TEXT_7,
	PLAYRANK_TEXT_8,

	PLAYRANK_TEXT_MAX
};

enum PlayRankSt_trail_texts_idx {
	PLAYRANK_TRAIL_TEXT_TACTICS,
	PLAYRANK_TRAIL_TEXT_SURVIVAL,
	PLAYRANK_TRAIL_TEXT_COMBAT,
	PLAYRANK_TRAIL_TEXT_TOTAL,

	PLAYRANK_TRAIL_TEXT_MAX
};

enum PlayRankSt_ranks {
	PLAYRANK_TACTICS = 0,
	PLAYRANK_COMBAT,
	PLAYRANK_SURVIVAL,
	PLAYRANK_EXPERIENCE,
	PLAYRANK_ASSET,
	PLAYRANK_POWER,
	PLAYRANK_TOTAL,

	PLAYRANK_MAX
};

enum PlayRankSt_Xmap_ranks {
	PLAYRANK_XMAP_TACTICS = 0,
	PLAYRANK_XMAP_SURVIVAL,
	PLAYRANK_XMAP_COMBAT,
	PLAYRANK_XMAP_TOTAL,

	PLAYRANK_XMAP_MAX
};

struct PlayRankSt {
	STRUCT_PAD(0x00, 0x32);

	/* 32 */ u16 unk_32;
	/* 34 */ u16 unk_34;
	/* 38 */ int x, y;
	/* 40 */ u8 x_step, y_step;
	/* 42 */ i16 xs[7];
	/* 50 */ i16 ys[7];
	/* 5E */ u16 unk_5E[7];
	/* 6C */ u16 ranks[7];
	/* 7A */ u16 unk_7A;
	/* 7C */ u16 *objs[7];
	/* 98 */ u8 unk_98[7];
	/* 9F */ u8 step;
	/* A0 */ struct Text texts[PLAYRANK_TEXT_MAX];
	/* E8 */ struct Text texts_rank_name[PLAYRANK_TEXT_MAX];
};

void SetupPlayRanks(void);
void SetupXmapPlayRanks(void);
void func_fe6_0808DE04(int lo, int hi, int x, int pal_bank);

struct Proc_0868B5E8 {
	PROC_HEADER;

	/* 2A */ i16 timer1;
	/* 2C */ i16 step;
	/* 2E */ u16 anim_duration;
	/* 30 */ u16 unk_30;
	/* 32 */ i16 x, y;
	/* 36 */ u16 pal_bank;
};

void func_fe6_0808DE5C(struct Proc_0868B5E8 *proc);
void func_fe6_0808DE70(struct Proc_0868B5E8 *proc);
void func_fe6_0808DEA4(struct Proc_0868B5E8 *proc);
void func_fe6_0808DF3C(u16 pal_bank, int x, int y);
void SetupPlayRankDispUnit(int step, int b);

void func_fe6_0808DFC4(struct Proc_0868B5E8 *proc);
void func_fe6_0808DFCC(struct Proc_0868B5E8 *proc);
void func_fe6_0808E0DC(struct Proc_0868B5E8 *proc);

struct Proc_0868B648 {
	PROC_HEADER;
};

void func_fe6_0808E1D0(void);
void func_fe6_0808E1E4(void);
void func_fe6_0808E264(struct Proc_0868B648 *proc);
void func_fe6_0808E284(ProcPtr proc);
void func_fe6_0808E2D0(struct Proc_0868B648 *proc);
void func_fe6_0808E2F0(struct Proc_0868B648 *proc);

void func_fe6_0808E2F4(void);
void func_fe6_0808E390(void);

struct Proc_0868B700 {
	PROC_HEADER;

	i16 timer;
	i16 layer;
};

void func_fe6_0808E420(struct Proc_0868B700 *proc);
void func_fe6_0808E434(struct Proc_0868B700 *proc);

struct Proc_0868B730 {
	PROC_HEADER;

	u16 unk_2A;
	i16 timer;
	i16 total_sprites;
};

void func_fe6_0808E4E8(struct Proc_0868B730 *proc);
void func_fe6_0808E5F0(struct Proc_0868B730 *proc);

void PlayRankTrialOBJ_Time_Loop(void);
void NewPlayRankTrialOBJ_Time(void);

void PlayRankFogHandler_Init(void);
void PlayRankFogHandler_Loop(void);

struct ProcPlayRank {
	PROC_HEADER;

	STRUCT_PAD(0x29, 0x2E);

	i16 unk_2E;
	i16 unk_30;
};

void PlayRank_InitTexts(void);
int PlayRank_ChapterTurns_DrawBase(struct Text *text, int chapter_gaiden, u8 centered);
bool PlayRank_ChapterTurns_DrawTurn(int line);
void PutPlayRankTexts(int line);
void func_fe6_0808EB94(int line);
int PlayRank_GetTotalPlayTime(void);
void PlayRank_PutTotalPlayTime(int line);
void func_fe6_0808EC78(int x);
void FillPlayRankFogsToBG(u16 *tm, int a, int b);
void PlayRank_InitDisplay(void);
void func_fe6_0808F060(struct ProcPlayRank *proc);
void PlayRank_Loop(struct ProcPlayRank *proc);
void PlayRank_Idle(ProcPtr proc);
void PlayRank_End1(ProcPtr proc);
void PlayRank_PrepareEnd(ProcPtr proc);
void PlayRank_CheckSkipPassword(ProcPtr proc);

u16 PlayRank_GetTotalTurn(void);
u8 PlayRankGetter_Tactics(void);
u8 PlayRankGetter_XmapTactics(void);
u16 PlayRank_GetWinningRate(void);
u8 PlayRankGetter_Combat(void);
u8 PlayRankGetter_XmapCombat(void);
u16 PlayRank_GetDeadAllies(void);
u8 PlayRankGetter_Survival(void);
u8 PlayRankGetter_XmapSurvival(void);
u16 PlayRank_GetTotalLevelsGained(void);
u8 PlayRankGetter_Experience(void);
u8 PlayRankGetter_Asset(void);
u16 PlayRank_CalcTotalLevel(void);
u8 PlayRankGetter_Power(void);
int GameRank_GetTotalRankA(void);
int GameRank_GetTotalRankB(void);
void PlayRank_InitBgConf(void);
void func_fe6_0808F790(ProcPtr proc);
void func_fe6_0808F7B0(ProcPtr proc);

struct Proc_0868B88C {
	PROC_HEADER;

	i16 unk_2A;
	i16 unk_2C;
	i16 unk_2E;
};

void func_fe6_0808F7D0(int method, int lo, int hi, int x, int end, int pal_bank);
void func_fe6_0808F838(struct Proc_0868B88C *proc);
void func_fe6_0808F844(struct Proc_0868B88C *proc);

void PlayRankTrialOBJ_Init(ProcPtr proc);
void PlayRankTrialOBJ_Loop(ProcPtr proc);
void PlayRankTrail_Init(ProcPtr proc);
void PlayRankTrail_Loop(ProcPtr proc);
// NewPlayRank_unused
void NewPlayRankTrail(ProcPtr parent);

extern CONST_DATA struct HelpBoxInfo HelpInfo_StatusScreen;
extern CONST_DATA struct HelpBoxInfo HelpInfo_0868B1CC;
extern CONST_DATA struct HelpBoxInfo HelpInfo_0868B1E8;
extern CONST_DATA struct HelpBoxInfo HelpInfo_0868B204;
extern CONST_DATA struct HelpBoxInfo HelpInfo_0868B220;
extern CONST_DATA struct HelpBoxInfo HelpInfo_0868B23C;
extern CONST_DATA struct HelpBoxInfo HelpInfo_0868B258;
extern CONST_DATA struct HelpBoxInfo HelpInfo_0868B274;
extern CONST_DATA struct HelpBoxInfo HelpInfo_0868B290;
extern CONST_DATA struct HelpBoxInfo HelpInfo_0868B2AC;
extern CONST_DATA struct HelpBoxInfo HelpInfo_StatusScreenExtraMap;
extern CONST_DATA struct HelpBoxInfo HelpInfo_0868B2E4;
extern CONST_DATA struct HelpBoxInfo HelpInfo_0868B300;
extern CONST_DATA struct HelpBoxInfo HelpInfo_0868B31C;
extern CONST_DATA struct HelpBoxInfo HelpInfo_0868B338;
extern CONST_DATA struct HelpBoxInfo HelpInfo_0868B354;
extern CONST_DATA struct HelpBoxInfo HelpInfo_0868B370;
extern CONST_DATA struct HelpBoxInfo HelpInfo_0868B38C;
extern CONST_DATA struct HelpBoxInfo HelpInfo_0868B3A8;
extern CONST_DATA struct HelpBoxInfo HelpInfo_StatusScreenExtraMapInfo;
extern CONST_DATA struct HelpBoxInfo HelpInfo_0868B3E0;
extern CONST_DATA struct PlayRankSt *gpPlayRankSt;
extern u16 CONST_DATA Sprite_0868B410[];
extern u16 CONST_DATA Sprite_0868B418[];

struct TotalPlayRankConf {
	/* 00 */ u16 msg;
	/* 04 */ int color;
	/* 08 */ u8 (*func)(void);
	/* 0C */ u8 x;
	/* 0D */ u8 y;
	/* 0E */ u8 unk_0E;
};

extern CONST_DATA struct TotalPlayRankConf gTotalPlayRankConf1[];
extern CONST_DATA struct TotalPlayRankConf gTotalPlayRankConf2[];

struct UnkStruct_0868B4D0 {
	/* 00 */ u16 *obj;
	/* 04 */ u8 unk_04;
};

extern CONST_DATA struct UnkStruct_0868B4D0 Objs_0868B4D0[];

struct UnkStruct_0868b508 {
	i8 chr;
	u8 len, size;
	u8 _pad_;
};
extern CONST_DATA struct UnkStruct_0868b508 Unk_0868b508[];

struct UnkStruct_0868B5B0 {
	struct UnkStruct_0868b508 *unk_00;
	u8 x, y, _pad_[2];
};
extern CONST_DATA struct UnkStruct_0868B5B0 gPlayRankMissonObjInfo[];

extern CONST_DATA struct BaSpriteData BaSprite_0868B5C8[];
extern CONST_DATA u8 gUnk_0868B5E0[];
extern CONST_DATA struct ProcScr ProcScr_0868B5E8[];
extern CONST_DATA struct ProcScr ProcScr_0868B610[];
extern CONST_DATA struct ProcScr ProcScr_0868B648[];
extern CONST_DATA struct ProcScr ProcScr_0868B6D8[];
extern CONST_DATA struct ProcScr ProcScr_0868B700[];
extern CONST_DATA u16 Sprite_PlayRankTrial_Time[];
extern CONST_DATA struct ProcScr ProcScr_0868B730[];
extern CONST_DATA struct ProcScr ProcScr_PlayRankTrialOBJ_Time[];
extern CONST_DATA struct ProcScr ProcScr_PlayRankFogHandler[];
extern CONST_DATA u16 Msgs_PlayRankNum[10];
extern CONST_DATA u8 gPlayRank_CombatRef[4];
extern CONST_DATA u8 gPlayRank_SurvivalRef[4];
extern CONST_DATA u8 gPlayRank_XmapSurvivalRef[4];
extern CONST_DATA int gPlayRank_AssetRef[4];
extern CONST_DATA u8 TotalRankA_Ref1[6][5];
extern CONST_DATA u16 TotalRankA_Ref2[6];
extern CONST_DATA u8 TotalRankB_Ref1[6];
extern CONST_DATA u16 TotalRankB_Ref2[6];
// extern CONST_DATA ??? BgConfig_PlayRank
extern CONST_DATA struct ProcScr ProcScr_0868B80C[];
extern CONST_DATA struct ProcScr ProcScr_0868B88C[];
extern CONST_DATA struct ProcScr ProcScr_PlayRankTrialOBJ[];
extern CONST_DATA struct ProcScr ProcScr_PlayRank[];
extern CONST_DATA struct ProcScr ProcScr_PlayRankTrail[];
