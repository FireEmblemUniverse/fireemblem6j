#pragma once

#include "prelude.h"

#include "event.h"

#include "constants/flags.h"

enum { EVENT_NOSCRIPT = 1 };
enum { EVENT_MONEY_MAPCHANGE = 3 };

enum { MAX_CHAPTER_FLAGS = 32 };
enum { MAX_PERMANENT_FLAGS = 40 };

enum
{
    TILE_COMMAND_NONE,

    TILE_COMMAND_VISIT    = 0x0E,
    TILE_COMMAND_SEIZE    = 0x0F,
    TILE_COMMAND_DOOR     = 0x10,
    TILE_COMMAND_BRIDGE   = 0x11,
    TILE_COMMAND_CHEST    = 0x12,
    TILE_COMMAND_ARMORY   = 0x13,
    TILE_COMMAND_VENDOR   = 0x14,
    TILE_COMMAND_SECRET   = 0x15,
    TILE_COMMAND_SHOP_UNK = 0x16,

    TILE_COMMAND_PILLAGE  = 0x1D,
};

// NOTE: this uses the RNG that is usually used for aesthetic purposes
// this means that random events will not be the same accross suspend reloads
#define EventRandNext_N(upper_bound) (DivRem(RandNextB(), (upper_bound)))

typedef uptr EventListScr;

struct EventInfo
{
    /* 00 */ EventListScr const * list_script;
    /* 04 */ void const * script; // could be EventScr, could be item list, could be "1"...
    /* 08 */ u32 flag;
    /* 0C */ u32 tile_command;
    /* 10 */ u32 given_money;
    /* 14 */ u32 given_iid;
    /* 18 */ i8 x_location;
    /* 19 */ i8 y_location;
    /* 1A */ u8 pid_a;
    /* 1B */ u8 pid_b;
};

struct SupportTalkEnt
{
    /* +00 */ u8 pid_a, pid_b;
    /* +02 */ // pad
    /* +04 */ u32 msg_talk_c;
    /* +08 */ u32 msg_talk_b;
    /* +0C */ u32 msg_talk_a;
};

struct BattleTalkExtEnt
{
    /* 00 */ u8 pid_a;
    /* 01 */ u8 pid_b;
    /* 02 */ u8 chapter;
    /* 03 */ // pad
    /* 04 */ u32 msg;
    /* 08 */ u32 flag;
};

struct BattleTalkEnt
{
    /* 00 */ u8 pid;
    /* 01 */ u8 chapter;
    /* 02 */ // pad
    /* 04 */ u32 msg;
    /* 08 */ u32 flag;
    /* 0C */ u32 unk_0C;
};

struct HardModeBonusLevelsOverrideEnt
{
    /* 00 */ u8 pid;
    /* 04 */ int bonus_levels;
};

extern struct HardModeBonusLevelsOverrideEnt CONST_DATA gHardModeBonusLevelsOverrideList[];
extern struct ProcScr CONST_DATA ProcScr_EndingBgmLooper[];

void StartEventFromInfo(struct EventInfo const * info);
struct EventInfo * SearchAvailableEvent(struct EventInfo * info);
struct EventInfo * SearchNextAvailableEvent(struct EventInfo * info);
int EvtListCmd_End(struct EventInfo * info);
int EvtListCmd_Flag(struct EventInfo * info);
int EvtListCmd_Turn(struct EventInfo * info);
int EvtListCmd_TurnHard(struct EventInfo * info);
int EvtListCmd_Talk(struct EventInfo * info);
int EvtListCmd_Tile(struct EventInfo * info);
int EvtListCmd_TileWithMapChange(struct EventInfo * info);
int EvtListCmd_ItemChest(struct EventInfo * info);
int EvtListCmd_Door(struct EventInfo * info);
int EvtListCmd_Drawbridge(struct EventInfo * info);
int EvtListCmd_Shop(struct EventInfo * info);
int EvtListCmd_Area(struct EventInfo * info);
int EvtListCmd_AreaHard(struct EventInfo * info);
int EvtListCmd_Func(struct EventInfo * info);
bool EventInfoCheckTalk(struct EventInfo * info, fu8 pid_a, fu8 pid_b);
int CheckActiveUnitArea(int x1, int y1, int x2, int y2);
bool CheckAnyBlueUnitArea(int x1, int y1, int x2, int y2);
bool func_fe6_0806AD48(struct EventInfo * info);
bool func_fe6_0806AD74(struct EventInfo * info);
bool func_fe6_0806ADC4(struct EventInfo * info);
bool func_fe6_0806ADDC(struct EventInfo * info);
bool func_fe6_0806AE04(struct EventInfo * info);
bool func_fe6_0806AE2C(struct EventInfo * info);
bool func_fe6_0806AE54(struct EventInfo * info);
bool func_fe6_0806AE7C(int x1, int y1, int x2, int y2);
bool CheckAvailableTurnEvent(void);
void StartAvailableTurnEvents(void);
bool CheckAvailableTalkEvent(fu8 pid_a, fu8 pid_b);
void StartAvailableTalkEvent(fu8 pid_a, fu8 pid_b);
void StartAvailableSupportEvent(fu8 pid_a, fu8 pid_b, int support_level);
int GetAvailableTileEventCommand(fi8 x, fi8 y);
void StartAvailableTileEvent(fi8 x, fi8 y);
void StartAvailableTileEvent_Unused(fi8 x, fi8 y);
bool CheckAvailableVisitTileEvent(fi8 x, fi8 y);
void StartAvailableVisitTileEvent(fi8 x, fi8 y);
bool CheckAvailableShopTileEvent(fi8 x, fi8 y);
void StartAvailableShopTileEvent(fi8 x, fi8 y);
bool CheckAvailableChestTileEvent(fi8 x, fi8 y);
void StartAvailableChestTileEvent(fi8 x, fi8 y);
bool CheckAvailableDoorTileEvent(fi8 x, fi8 y);
void StartAvailableDoorTileEvent(fi8 x, fi8 y);
bool CheckAvailableBridgeTileEvent(fi8 x, fi8 y);
void StartAvailableBridgeTileEvent(fi8 x, fi8 y);
bool CheckAvailableVictoryEvent(void);
void StartAvailableVictoryEvent(void);
bool StartAvailableMoveSelectEvent(void);
bool CheckAvailableActionSelectEvent(void);
bool StartAvailableActionSelectEvent(void);
bool CheckAvailableMoveSelectConfirmEvent(void);
bool StartAvailableMoveSelectConfirmEvent(void);
bool StartAvailableAttackMenuEvent(void);
bool StartAvailableAttackMenuItemEvent(void);
bool StartAvailableMapMenuEvent(void);
bool CheckAvailableMoveEvent(void);
void StartAvailableMoveEvent(void);
bool CheckChapterVictory(void);
void StartChapterVictoryEvent(void);
void CreateInitialRedUnits(void);
struct UnitInfo const * GetDeployUnitInfoList(void);
struct BattleTalkEnt const * GetAvailableBattleTalkExt(fu8 pid_a, fu8 pid_b);
struct BattleTalkEnt const * GetAvailableBattleTalk(fu8 pid, struct BattleTalkEnt const * it);
bool CheckBattleTalk(fu8 pid_a, fu8 pid_b);
void StartBattleTalk(fu8 pid_a, fu8 pid_b);
bool CheckBattleDefeatTalk(fu8 pid);
void StartBattleDefeatTalk(fu8 pid);
bool func_fe6_0806B898(void);
void func_fe6_0806B89C(void);
void func_fe6_0806B8A0(void);
bool func_fe6_0806B8A4(void);
void func_fe6_0806B8A8(void);
bool func_fe6_0806B8AC(void);
bool func_fe6_0806B8B0(void);
void func_fe6_0806B8B4(void);
void func_fe6_0806B8B8(void);
void func_fe6_0806B8BC(void);
void func_fe6_0806B8C0(void);
void func_fe6_0806B8C4(void);
void SetChapterFlag(int flag);
bool CheckChapterFlag(int flag);
void ClearChapterFlag(int flag);
void ResetChapterFlags(void);
void SetPermanentFlag(int flag);
bool CheckPermanentFlag(int flag);
void ClearPermanentFlag(int flag);
void ResetPermanentFlags(void);
void SetFlag(int flag);
bool CheckFlag(int flag);
void ClearFlag(int flag);
u8 * GetPermanentFlagBits(void);
int GetPermanentFlagBitsSize(void);
u8 * GetChapterFlagBits(void);
int GetChapterFlagBitsSize(void);

extern u8 gChapterFlagBits[(MAX_CHAPTER_FLAGS + CHAR_BIT - 1) / CHAR_BIT];
extern u8 gPermanentFlagBits[(MAX_PERMANENT_FLAGS + CHAR_BIT - 1) / CHAR_BIT];

extern u16 const Pal_08342A98[]; // colors
extern struct ProcScr CONST_DATA ProcScr_DemoSceneIntro[];
extern struct ProcScr CONST_DATA ProcScr_TrueEnding_EarthQuake[];
extern struct ProcScr CONST_DATA ProcScr_Unk_08676854[];
extern struct ProcScr CONST_DATA ProcScr_EndingCreditFade[];
extern u8 gUnk_030048A8;
extern u32 EWRAM_DATA gUnk_0203D354;
extern u32 EWRAM_DATA gUnk_0203D358;
extern u8 EWRAM_DATA gUnk_0203D35C;
extern u8 EWRAM_DATA gUnk_0203D35D;
extern u8 EWRAM_DATA gUnk_0203D360;
extern u8 EWRAM_DATA gUnk_0203D361;
extern u8 EWRAM_DATA gUnk_0203D362;
extern u16 EWRAM_DATA gUnk_0203D364;
extern struct ProcScr CONST_DATA ProcScr_DemoMonologueDisp[];
extern u32 EWRAM_DATA gUnk_0203D368;
extern u32 EWRAM_DATA gDemoMonologueId;
extern struct Text EWRAM_DATA Texts_DemoMonologue[];
extern struct Text EWRAM_DATA Text_EndingTimeFlowMonologue;
extern struct ProcScr CONST_DATA ProcScr_EndingTimeFlowMonologue[];
extern struct ProcScr CONST_DATA ProcScr_TrueEnding_SortAllies[];
extern u8 EWRAM_DATA gUnk_0203D3D8; // ending related value
extern EventScr const * CONST_DATA EventScrs_DemoScene[];
extern struct ProcScr CONST_DATA ProcScr_EndingMonologueText[];
extern struct ProcScr CONST_DATA ProcScr_Epilogue_BgmFadeIn[];
extern struct ProcScr CONST_DATA ProcScr_Epilogue_BgmFadeOut[];

extern struct ChapterEventInfo CONST_DATA ChapterEventInfo_Ch10a;
extern struct ChapterEventInfo CONST_DATA ChapterEventInfo_Ch17d;
extern struct ChapterEventInfo CONST_DATA ChapterEventInfo_Xmap5;
extern struct ChapterEventInfo CONST_DATA ChapterEventInfo_Ch14;
extern struct ChapterEventInfo CONST_DATA ChapterEventInfo_Chapter1;
extern struct ChapterEventInfo CONST_DATA ChapterEventInfo_Ch8x;
extern struct ChapterEventInfo CONST_DATA ChapterEventInfo_Ch6;
extern struct ChapterEventInfo CONST_DATA ChapterEventInfo_Ch21x;
extern struct ChapterEventInfo CONST_DATA ChapterEventInfo_Xmap4;
extern struct ChapterEventInfo CONST_DATA ChapterEventInfo_Ch22;
extern struct ChapterEventInfo CONST_DATA ChapterEventInfo_Ch7;
extern struct ChapterEventInfo CONST_DATA ChapterEventInfo_Ch10b;
extern struct ChapterEventInfo CONST_DATA ChapterEventInfo_Xmap2;
extern struct ChapterEventInfo CONST_DATA ChapterEventInfo_Ch12x;
extern struct ChapterEventInfo CONST_DATA ChapterEventInfo_Ch21;
extern struct ChapterEventInfo CONST_DATA ChapterEventInfo_Ch14x;
extern struct ChapterEventInfo CONST_DATA ChapterEventInfo_Chapter2;
extern struct ChapterEventInfo CONST_DATA ChapterEventInfo_Ch9;
extern struct ChapterEventInfo CONST_DATA ChapterEventInfo_Xmap1;
extern struct ChapterEventInfo CONST_DATA ChapterEventInfo_Ch18c;
extern struct ChapterEventInfo CONST_DATA ChapterEventInfo_Chapter4;
extern struct ChapterEventInfo CONST_DATA ChapterEventInfo_Tutorial;
extern struct ChapterEventInfo CONST_DATA ChapterEventInfo_Ch11b;
extern struct ChapterEventInfo CONST_DATA ChapterEventInfo_Ch13;
extern struct ChapterEventInfo CONST_DATA ChapterEventInfo_Ch17c;
extern struct ChapterEventInfo CONST_DATA ChapterEventInfo_Ch20cx;
extern struct ChapterEventInfo CONST_DATA ChapterEventInfo_Ch20dx;
extern struct ChapterEventInfo CONST_DATA ChapterEventInfo_Ch18d;
extern struct ChapterEventInfo CONST_DATA ChapterEventInfo_Ch12;
extern struct ChapterEventInfo CONST_DATA ChapterEventInfo_Ch11a;
extern struct ChapterEventInfo CONST_DATA ChapterEventInfo_Ch19c;
extern struct ChapterEventInfo CONST_DATA ChapterEventInfo_Chapter5;
extern struct ChapterEventInfo CONST_DATA ChapterEventInfo_Ch16;
extern struct ChapterEventInfo CONST_DATA ChapterEventInfo_Ch25;
extern struct ChapterEventInfo CONST_DATA ChapterEventInfo_Ch20d;
extern struct ChapterEventInfo CONST_DATA ChapterEventInfo_Ch24;
extern struct ChapterEventInfo CONST_DATA ChapterEventInfo_Ch16x;
extern struct ChapterEventInfo CONST_DATA ChapterEventInfo_Ch15;
extern struct ChapterEventInfo CONST_DATA ChapterEventInfo_Ch8;
extern struct ChapterEventInfo CONST_DATA ChapterEventInfo_Ch19d;
extern struct ChapterEventInfo CONST_DATA ChapterEventInfo_Chapter3;
extern struct ChapterEventInfo CONST_DATA ChapterEventInfo_Ch20c;
extern struct ChapterEventInfo CONST_DATA ChapterEventInfo_Xmap3;
extern struct ChapterEventInfo CONST_DATA ChapterEventInfo_Ch23;

extern CONST_DATA EventScr EventScr_Wm_Tutorial[];
extern CONST_DATA EventScr EventScr_Wm_Ch1[];
extern CONST_DATA EventScr EventScr_Wm_Ch2[];
extern CONST_DATA EventScr EventScr_Wm_Ch3[];
extern CONST_DATA EventScr EventScr_Wm_Ch4[];
extern CONST_DATA EventScr EventScr_Wm_Ch5[];
extern CONST_DATA EventScr EventScr_Wm_Ch6[];
extern CONST_DATA EventScr EventScr_Wm_Ch7[];
extern CONST_DATA EventScr EventScr_Wm_Ch8[];
extern CONST_DATA EventScr EventScr_Wm_Ch9[];
extern CONST_DATA EventScr EventScr_Wm_Ch10a[];
extern CONST_DATA EventScr EventScr_Wm_Ch11a[];
extern CONST_DATA EventScr EventScr_Wm_Ch12[];
extern CONST_DATA EventScr EventScr_Wm_Ch10b[];
extern CONST_DATA EventScr EventScr_Wm_Ch11b[];
extern CONST_DATA EventScr EventScr_Wm_Ch13[];
extern CONST_DATA EventScr EventScr_Wm_Ch14[];
extern CONST_DATA EventScr EventScr_Wm_Ch15[];
extern CONST_DATA EventScr EventScr_Wm_Ch16[];
extern CONST_DATA EventScr EventScr_Wm_Ch17c[];
extern CONST_DATA EventScr EventScr_Wm_Ch18c[];
extern CONST_DATA EventScr EventScr_Wm_Ch19c[];
extern CONST_DATA EventScr EventScr_Wm_Ch20c[];
extern CONST_DATA EventScr EventScr_Wm_Ch17d[];
extern CONST_DATA EventScr EventScr_Wm_Ch18d[];
extern CONST_DATA EventScr EventScr_Wm_Ch19d[];
extern CONST_DATA EventScr EventScr_Wm_Ch20d[];
extern CONST_DATA EventScr EventScr_Wm_Ch21[];
extern CONST_DATA EventScr EventScr_Wm_Ch22[];
extern CONST_DATA EventScr EventScr_Wm_Ch23[];
extern CONST_DATA EventScr EventScr_Wm_Ch24[];
extern CONST_DATA EventScr EventScr_0868F84C[];
extern CONST_DATA EventScr EventScr_Wm_Ch8x[];
extern CONST_DATA EventScr EventScr_Wm_Ch12x[];
extern CONST_DATA EventScr EventScr_Wm_Ch14x[];
extern CONST_DATA EventScr EventScr_Wm_Ch16x[];
extern CONST_DATA EventScr EventScr_Wm_Ch20cx[];
extern CONST_DATA EventScr EventScr_Wm_Ch20dx[];
extern CONST_DATA EventScr EventScr_Wm_Ch21x[];
extern CONST_DATA EventScr EventScr_0868FD8C[];
