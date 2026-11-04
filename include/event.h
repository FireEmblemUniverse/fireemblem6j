#pragma once

#include "prelude.h"
#include "proc.h"
#include "text.h"
#include "unit.h"
#include "face.h"
#include "eventscript.h"

typedef uptr EventScr;

enum
{
    POPUP_CMD_END,
    POPUP_CMD_SPACE,
    POPUP_CMD_ITEM_NAME,
    POPUP_CMD_UNIT_NAME,
    POPUP_CMD_MSG,
    POPUP_CMD_STR,
    POPUP_CMD_COLOR,
    POPUP_CMD_ICON_ITEM,
    POPUP_CMD_ICON_IKIND,
    POPUP_CMD_NUMBER,
    POPUP_CMD_SONG,
};

enum
{
    BACKGROUND_0,
    BACKGROUND_1,
    BACKGROUND_2,
    BACKGROUND_3,
    BACKGROUND_4,
    BACKGROUND_5,
    BACKGROUND_6,
    BACKGROUND_7,
    BACKGROUND_8,
    BACKGROUND_9,
    BACKGROUND_10,
    BACKGROUND_11,
    BACKGROUND_12,
    BACKGROUND_13,
    BACKGROUND_14,
    BACKGROUND_15,
    BACKGROUND_16,
    BACKGROUND_17,
    BACKGROUND_18,
    BACKGROUND_19,
    BACKGROUND_20,
};

enum
{
    EVENT_CMDRET_CONTINUE,
    EVENT_CMDRET_JUMPED,
    EVENT_CMDRET_YIELD,
    EVENT_CMDRET_REPEAT,
};

enum
{
    EVENT_FLAG_UNITCAM = 1 << 0,
    EVENT_FLAG_TEXTSKIPPED = 1 << 1,
    EVENT_FLAG_SKIPPED = 1 << 2,
    EVENT_FLAG_DISABLESKIP = 1 << 3,
    EVENT_FLAG_DISABLETEXTSKIP = 1 << 4,
    EVENT_FLAG_ENDMAPMAIN = 1 << 5,
    EVENT_FLAG_NOAUTOCLEAR = 1 << 6,
};

#define EVTCMD_GET_X_RAW(script) (((script) & 0x0000FFFF))
#define EVTCMD_GET_Y_RAW(script) (((script) & 0xFFFF0000) >> 16)

#define EVTCMD_GET_X(script) (EVTCMD_GET_X_RAW(script) & 0x8000 ? -1 : EVTCMD_GET_X_RAW(script))
#define EVTCMD_GET_Y(script) (EVTCMD_GET_Y_RAW(script) & 0x8000 ? -1 : EVTCMD_GET_Y_RAW(script))

struct PopupInfo
{
    /* 00 */ u8 cmd;
    /* 04 */ int arg;
};

struct PopupProc
{
    /* 00 */ PROC_HEADER;

    /* 2C */ struct PopupInfo const * info;
    /* 30 */ int clock;

    /* 34 */ i8 xParam;
    /* 35 */ i8 yParam;

    /* 36 */ u8 window_kind;

    /* 37 */ u8 frameX;
    /* 38 */ u8 frameY;

    /* 39 */ u8 frameWidth;
    /* 3A */ u8 frameHeight;

    /* 3B */ u8 color;

    /* 3C */ u8 pad_3C[0x3E - 0x3C];

    /* 3E */ u16 icon;
    /* 40 */ u16 iconChr;
    /* 42 */ u8 iconPalid;
    /* 43 */ u8 pad_43;
    /* 44 */ u8 iconX;
    /* 45 */ u8 pad_45;

    /* 46 */ u16 widthPx;

    /* 48 */ u16 songPlayed;
};

struct EventProc
{
    /* 00 */ PROC_HEADER;

    /* 2C */ EventScr const * script_start;
    /* 30 */ EventScr const * script;
    /* 34 */ void (* on_skip)(void);
    /* 38 */ void (* on_idle)(struct EventProc * proc);
    /* 3C */ struct UnitInfo const * unit_info;
    /* 40 */ i32 msg_param;
    /* 44 */ i8 background;
    /* 45 */ bool8 no_map;
    /* 46 */ u8 flags;
    /* 47 */ // pad
    /* 48 */ u16 sleep_duration;
    /* 4A */ i16 cmd_short;
    /* 4C */ u8 cmd_byte;
    /* 4D */ // pad
    /* 50 */ i32 money_param;
    /* 54 */ u16 iid_param;
    /* 56 */ u8 pid_param;
    /* 57 */ u8 map_change_param;
};

struct EventCmdInfo
{
    int (* func)(struct EventProc * proc);
    int size;
};

extern struct EventCmdInfo CONST_DATA gEventCmdInfoTable[];

struct BackgroundEnt
{
    u8 const * img;
    u8 const * tsa;
    u16 const * pal;
};

extern EventScr const * gEventScriptQueue[]; // COMMON
extern u8 gEventScriptQueueIt; // COMMON

void func_fe6_0800CCD4(void);
void MoveUnitFromInfo(struct UnitInfo const * info, struct Unit * unit, ProcPtr parent);;
void LoadUnitWrapper(struct UnitInfo const * info, ProcPtr parent);
void FakeLoadUnit(struct UnitInfo const * info, struct Unit * unit);
void MoveUnitFromInfo(struct UnitInfo const * info, struct Unit * unit, ProcPtr parent);
bool func_fe6_0800CE44(void);
bool func_fe6_0800CE74(void);
int func_fe6_0800CE90(void);
int PreparePopup(struct PopupProc * proc);
void PutPopup(struct PopupInfo const * info, struct Text text);
void Popup_OnInit(struct PopupProc * proc);
void Popup_Prepare(struct PopupProc * proc);
void Popup_FadeBgmOut(struct PopupProc * proc);
void Popup_PlaySe(struct PopupProc * proc);
void Popup_FadeBgmIn(struct PopupProc * proc);
void PopupIconSprite_OnIdle(struct Proc * proc);
void Popup_Display(struct PopupProc * proc);
void Popup_WaitForEnd(struct PopupProc * proc);
void Popup_Clear(struct PopupProc * proc);
void SetPopupUnit(struct Unit * unit);
void SetPopupItem(u16 item);
void SetPopupNumber(int number);
ProcPtr StartPopup(struct PopupInfo const * info, int duration, int window_kind, ProcPtr parent);
ProcPtr StartPopupExt(struct PopupInfo const * info, int duration, int window_kind, int iconChr, int iconPal, ProcPtr parent);
void EndPopup(void);
void DisableEventSkip(void);
void EventDisableSkip(ProcPtr proc);
void Event_FadeOutOfBackgroundTalk(struct EventProc * proc);
void Event_FadeOutOfSkip(struct EventProc * proc);
void FadeFromBg_FadeToBlack(struct Proc * proc);
void FadeFromBg_FadeFromBlack(struct Proc * proc);
void FadeFromBg_ClearScreen(struct Proc * proc);
void FadeFromSkip_Start(struct Proc * proc);
ProcPtr StartEvent(EventScr const * script);
ProcPtr StartEventLocking(EventScr const * script, ProcPtr parent);
ProcPtr StartEventInternal(EventScr const * script, ProcPtr parent);
void Event_OnInit(struct EventProc * proc);
void Event_OnEnd(struct EventProc * proc);
void Event_ResetText(struct EventProc * proc);
void Event_RestartFromQueued(struct EventProc * proc);
void Event_MaybeEndMapMain(struct EventProc * proc);
void Event_ClearTextOnSkip(struct EventProc * proc);
bool Event_SkipAllowed(struct EventProc * proc);
void Event_DarkenThenFunc(void (* func)(struct EventProc * proc), struct EventProc * eproc);

struct DarkenFuncProc
{
    /* 00 */ PROC_HEADER;

    /* 29 */ u8 pad_29[0x4C - 0x29];

    /* 4C */ struct EventProc * eventProc;
    /* 50 */ void (* func)(struct EventProc * proc);

    /* 54 */ u8 pad_54[0x64 - 0x54];

    /* 64 */ short q4_darkenStep;
    /* 66 */ short q4_darken;
};

void DarkenThenFunc_OnInit(struct DarkenFuncProc * proc);
void DarkenThenFunc_OnLoop(struct DarkenFuncProc * proc);
void DarkenThenFunc_StartDarken(struct DarkenFuncProc * proc);
void DarkenThenFunc_StepDarken(struct DarkenFuncProc * proc);
void Event_MainLoop(struct EventProc * proc);
void Event_WaitForFaceEnd(struct EventProc * proc);
int EvtCmd_Sleep(struct EventProc * proc);
int EvtCmd_Background(struct EventProc * proc);
int EvtCmd_BackgroundMore(struct EventProc * proc);
int EvtCmd_ClearTalk(struct EventProc * proc);
int EvtCmd_ClearSkip(struct EventProc * proc);
void DisplayBackground(int background);
void DisplayBackgroundNoClear(int background);
int EvtCmd_Talk(struct EventProc * proc);
int EvtCmd_TalkMore(struct EventProc * proc);
int EvtCmd_TalkAuto(struct EventProc * proc);
int EvtCmd_TalkContinue(struct EventProc * proc);
void EventTalkWait(struct EventProc * proc);
int EvtCmd_CameraPosition(struct EventProc * proc);
int EvtCmd_CameraPid(struct EventProc * proc);
bool CanDisplayUnitMovement(struct EventProc * proc, int x, int y);
int EvtCmd_MovePosition(struct EventProc * proc);
int EvtCmd_MovePid(struct EventProc * proc);
int EvtCmd_MovePidScript(struct EventProc * proc);
int EvtCmd_MovePositionScript(struct EventProc * proc);
int EvtCmd_MovePidNextTo(struct EventProc * proc);
void TryMoveUnit(struct Unit * unit, int x, int y, i8 moveClosest);
bool TryMoveUnitDisplayed(ProcPtr proc, struct Unit * unit, int x, int y);
bool DisplayMovement(struct EventProc * proc, struct Unit * unit, u8 const * movescr);
void WaitForMu_0800F094(struct Proc * proc);
void WaitForMu_OnLoop(struct Proc * proc);
int EvtCmd_LoadUnits(struct EventProc * proc);
int EvtCmd_LoadUnitsParty(struct EventProc * proc);
int GetNextAvailableBlueUnitId(int start);
bool UnitInfoRequiresNoMovement(struct UnitInfo const * info);
void EventUnitLoadWait(struct EventProc * proc);
void EventLoadUnitsAsParty(struct EventProc * proc);
void EventMovementWait(struct EventProc * proc);
int EvtCmd_WaitForMovement(struct EventProc * proc);
int EvtCmd_UnitCameraOn(struct EventProc * proc);
int EvtCmd_UnitCameraOff(struct EventProc * proc);
int EvtCmd_Func(struct EventProc * proc);
int EvtCmd_FuncUntil(struct EventProc * proc);
int EvtCmd_FuncWhile(struct EventProc * proc);
int EvtCmd_Stop(struct EventProc * proc);
int EvtCmd_Label(struct EventProc * proc);
int EventGotoLabel(ProcPtr proc, int label);
int EvtCmd_Goto(struct EventProc * proc);
int EvtCmd_GotoIfnAlive(struct EventProc * proc);
int EvtCmd_GotoIfnInTeam(struct EventProc * proc);
int EvtCmd_GotoIfyFunc(struct EventProc * proc);
int EvtCmd_GotoIfnFunc(struct EventProc * proc);
int EvtCmd_GotoIfySkip(struct EventProc * proc);
int EvtCmd_GotoIfyFlag(struct EventProc * proc);
int EvtCmd_GotoIfnFlag(struct EventProc * proc);
int EvtCmd_GotoIfyActive(struct EventProc * proc);
int EvtCmd_Jump(struct EventProc * proc);
int EvtCmd_GiveItem(struct EventProc * proc);
int EvtCmd_GiveItemTo(struct EventProc * proc);
int EventGiveItem(struct Unit * unit, u16 iid, struct EventProc * proc);
int EvtCmd_MapChange(struct EventProc * proc);
int EvtCmd_MapChangePosition(struct EventProc * proc);
int EvtCmd_SetFaction(struct EventProc * proc);
int EvtCmd_FlashCursorPosition(struct EventProc * proc);
int EvtCmd_FlashCursorPid(struct EventProc * proc);
void EventFlashCursorWait(struct EventProc * proc);
void FlashCursor_OnInit(struct Proc * proc);
void FlashCursor_OnLoop(struct Proc * proc);
int EvtCmd_PutCursor(struct EventProc * proc);
void EventCursor_OnLoop(struct Proc * proc);
int EvtCmd_ClearCursors(struct EventProc * proc);
int EvtCmd_RemovePid(struct EventProc * proc);
int EvtCmd_RemovePidDisplayed(struct EventProc * proc);
void EventRemoveDisplayedWait(struct EventProc * proc);
void SetUnitAi(struct Unit * unit, u8 ai_a, u8 ai_b, u8 unused);
int EvtCmd_SetAiPid(struct EventProc * proc);
int EvtCmd_SetAiPosition(struct EventProc * proc);
int EvtCmd_SetFlag(struct EventProc * proc);
int EvtCmd_ClearFlag(struct EventProc * proc);
int EvtCmd_PlayBgm(struct EventProc * proc);
int EvtCmd_OverrideBgm(struct EventProc * proc);
int EvtCmd_RestoreBgm(struct EventProc * proc);
int EvtCmd_FadeBgmOut(struct EventProc * proc);
int EvtCmd_LowerBgmVolume(struct EventProc * proc);
int EvtCmd_RestoreBgmVolume(struct EventProc * proc);
int EvtCmd_PlaySe(struct EventProc * proc);
int EventEndBattleMap(ProcPtr proc);
int EvtCmd_NextChapter(struct EventProc * proc);
int EvtCmd_EndGame(struct EventProc * proc);
int EvtCmd_SetMap(struct EventProc * proc);
int EvtCmd_NoSkip(struct EventProc * proc);
void EventFadeFromSkipWait(struct EventProc * proc);
int EvtCmd_NoSkipNoTextSkip(struct EventProc * proc);
int EvtCmd_YesSkip(struct EventProc * proc);
int EvtCmd_FadeToBlack(struct EventProc * proc);
int EvtCmd_FadeFromBlack(struct EventProc * proc);
int EvtCmd_FadeToWhite(struct EventProc * proc);
int EvtCmd_FadeFromWhite(struct EventProc * proc);
int EvtCmd_ExitMap(struct EventProc * proc);
int EvtCmd_EnterMap(struct EventProc * proc);
int EvtCmd_GiveMoney(struct EventProc * proc);
int EvtCmd_FightScript(struct EventProc * proc);
void EventScriptedBattleWait(struct EventProc * proc);
void EventScriptedBattleWaitB(struct EventProc * proc);
int EvtCmd_DisableAutoClear(struct EventProc * proc);
int EvtCmd_FuncOnSkip(struct EventProc * proc);
int EvtCmd_SetWeather(struct EventProc * proc);
void DoChangeWeather(struct Proc * proc);
int EvtCmd_WmStart(struct EventProc * proc);
int EvtCmd_WmEnd(struct EventProc * proc);
int EvtCmd_WmZoomTo(struct EventProc * proc);
int EvtCmd_WmZoomBack(struct EventProc * proc);
void EventWmZoomWait(struct EventProc * proc);
int EvtCmd_WmPutFace(struct EventProc * proc);

struct WmEventFaceProc
{
    /* 00 */ PROC_HEADER;

    /* 2A */ i16 face_slot;
    /* 2C */ i16 x;
    /* 2E */ i16 y;
    /* 30 */ i16 fid;
    /* 32 */ u16 disp;
    /* 34 */ i16 x_offset_start;
    /* 36 */ i16 blend_value;
};

void WmPutFace_OnInit(struct WmEventFaceProc * proc);
void WmPutFace_OnLoop(struct WmEventFaceProc * proc);
int EvtCmd_WmRemoveFace(struct EventProc * proc);
void WmRemoveFace_OnInit(struct WmEventFaceProc * proc);
void WmRemoveFace_OnLoop(struct WmEventFaceProc * proc);
void WmRemoveFace_OnEnd(struct WmEventFaceProc * proc);
int EvtCmd_WmMoveFace(struct EventProc * proc);
void WmMoveFace_OnInit(struct WmEventFaceProc * proc);
void WmMoveFace_OnLoop(struct WmEventFaceProc * proc);
int EvtCmd_WmNop54(struct EventProc * proc);
int EvtCmd_WmNop55(struct EventProc * proc);
int EvtCmd_WmTalk(struct EventProc * proc);
int EvtCmd_WmTalkBoxBottom(struct EventProc * proc);
int EvtCmd_WmTalkBoxTop(struct EventProc * proc);
int EvtCmd_WmTalkBoxRemove(struct EventProc * proc);
int EvtCmd_WmArrow(struct EventProc * proc);
int EvtCmd_WmPutHighlight(struct EventProc * proc);
int EvtCmd_WmRemoveHighlight(struct EventProc * proc);
void EventWmRemoveHighlightWait(struct EventProc * proc);
int EvtCmd_WmRemoveBothHighlights(struct EventProc * proc);
void EventWmRemoveHighlightsWait(struct EventProc * proc);
int EvtCmd_StartWmDot(struct EventProc * proc);
int EvtCmd_WmRemoveDot(struct EventProc * proc);
int EvtCmd_WmPutFlag(struct EventProc * proc);
int EvtCmd_WmRemoveFlag(struct EventProc * proc);
int EvtCmd_WmPutMapText(struct EventProc * proc);
int EvtCmd_WmRemoveMapText(struct EventProc * proc);
int EvtCmd_End(struct EventProc * proc);
int EvtCmd_Kill(struct EventProc * proc);
void EventClearTalkDisplayed(struct EventProc * proc);
void ClearTalk(void);
void func_fe6_08011F4C(void);
void func_fe6_08011F64(void);
bool IsEventRunning(void);
bool IsEventProcRunning(void);
void KillTalkAndEvent(void);
void SetFightEventFaceConfig(void);
ProcPtr StartTalkEvent(int msgid);
ProcPtr StartTalkSupportEvent(int msgid);
void StartWeaponBrokePopup(u16 item, ProcPtr parent);
void StartPopup_08012070(u16 item, ProcPtr parent);
void StartWeaponLevelGainedPopup(u16 item, ProcPtr parent);
void StartPopup_080120D0(int amount, ProcPtr parent);
void StartPopup_08012120(u16 item, ProcPtr parent);
void StartStoleItemPopup(u16 item, ProcPtr parent);
void StartSupportLevelGaindPopup(ProcPtr parent);
void StartGiveItem(struct Unit * unit, u16 iid, ProcPtr parent);
void GiveItem_DoPopup(struct Proc * proc);
void GiveItem_DoGiveItem(struct Proc * proc);
void StartGiveItemEvent(u16 iid);
void StartGiveItemToEvent(u16 pid, u16 iid);
void StartGiveMoneyEvent(int amount);
void StartMapChangeEvent(u8 id);
void StartChestItemEvent(u16 iid, u8 id);
void StartChestMoneyEvent(int amount, u8 id);
void SetEventTalkSkipped(void);
int GetPlayerMaxDeployCount(void);
void InitPlayerDeployUnits(void);
void InitPlayerDeployUnitPositions(void);
void MoveUnitToFirstAvailableDeployPosition(struct Unit * unit);
void func_fe6_080126FC(int a, int b);
void Event_SetExitMap(struct EventProc * proc);
void Event_SetEnterMap(struct EventProc * proc);
void ResetWeather(void);
void func_fe6_08012780(void);
void func_fe6_08012798(void);
void func_fe6_080127B0(void);

#define POPUP_END { POPUP_CMD_END, 0 }
#define POPUP_SPACE(len) { POPUP_CMD_SPACE, (len) }
#define POPUP_ITEM_NAME { POPUP_CMD_ITEM_NAME, 0 }
#define POPUP_UNIT_NAME { POPUP_CMD_UNIT_NAME, 0 }
#define POPUP_MSG(msg) { POPUP_CMD_MSG, (msg) }
#define POPUP_STR(str) { POPUP_CMD_STR, (int) (char const *) (str) }
#define POPUP_COLOR(color) { POPUP_CMD_COLOR, (color) }
#define POPUP_ICON_ITEM { POPUP_CMD_ICON_ITEM, 0 }
#define POPUP_ICON_IKIND { POPUP_CMD_ICON_IKIND, 0 }
#define POPUP_NUMBER { POPUP_CMD_NUMBER, 0 }
#define POPUP_SONG(song) { POPUP_CMD_SONG, (song) }

#define _EventCmds \
    [EVT_CMD_END] = { EvtCmd_End, 1 }, \
    [EVT_CMD_KILL] = { EvtCmd_Kill, 1 }, \
    [EVT_CMD_SLEEP] = { EvtCmd_Sleep, 2 }, \
    [EVT_CMD_BACKGROUND] = { EvtCmd_Background, 2 }, \
    [EVT_CMD_BACKGROUNDMORE] = { EvtCmd_BackgroundMore, 2 }, \
    [EVT_CMD_CLEARTALK] = { EvtCmd_ClearTalk, 1 }, \
    [EVT_CMD_CLEARSKIP] = { EvtCmd_ClearSkip, 1 }, \
    [EVT_CMD_TALK] = { EvtCmd_Talk, 2 }, \
    [EVT_CMD_TALKMORE] = { EvtCmd_TalkMore, 2 }, \
    [EVT_CMD_TALKAUTO] = { EvtCmd_TalkAuto, 1 }, \
    [EVT_CMD_TALKCONT] = { EvtCmd_TalkContinue, 1 }, \
    [EVT_CMD_CAMERA_POS] = { EvtCmd_CameraPosition, 2 }, \
    [EVT_CMD_CAMERA_PID] = { EvtCmd_CameraPid, 2 }, \
    [EVT_CMD_MOVE_POS] = { EvtCmd_MovePosition, 3 }, \
    [EVT_CMD_MOVE_POS_MANUAL] = { EvtCmd_MovePositionScript, 3 }, \
    [EVT_CMD_MOVE_PID] = { EvtCmd_MovePid, 3 }, \
    [EVT_CMD_MOVE_PID_MANUAL] = { EvtCmd_MovePidScript, 3 }, \
    [EVT_CMD_MOVE_PID_NEXTTO] = { EvtCmd_MovePidNextTo, 3 }, \
    [EVT_CMD_LOADUNITS] = { EvtCmd_LoadUnits, 2 }, \
    [EVT_CMD_LOADUNITS_PARTY] = { EvtCmd_LoadUnitsParty, 2 }, \
    [EVT_CMD_MOVEWAIT] = { EvtCmd_WaitForMovement, 1 }, \
    [EVT_CMD_UNITCAM_ON] = { EvtCmd_UnitCameraOn, 1 }, \
    [EVT_CMD_UNITCAM_OFF] = { EvtCmd_UnitCameraOff, 1 }, \
    [EVT_CMD_FUNC] = { EvtCmd_Func, 2 }, \
    [EVT_CMD_FUNC_UNTIL] = { EvtCmd_FuncUntil, 2 }, \
    [EVT_CMD_FUNC_WHILE] = { EvtCmd_FuncWhile, 2 }, \
    [EVT_CMD_STOP] = { EvtCmd_Stop, 1 }, \
    [EVT_CMD_LABEL] = { EvtCmd_Label, 2 }, \
    [EVT_CMD_GOTO] = { EvtCmd_Goto, 2 }, \
    [EVT_CMD_GOTO_IFN_ALIVE] = { EvtCmd_GotoIfnAlive, 3 }, \
    [EVT_CMD_GOTO_IFN_INTEAM] = { EvtCmd_GotoIfnInTeam, 3 }, \
    [EVT_CMD_GOTO_IFY_FUNC] = { EvtCmd_GotoIfyFunc, 3 }, \
    [EVT_CMD_GOTO_IFN_FUNC] = { EvtCmd_GotoIfnFunc, 3 }, \
    [EVT_CMD_GOTO_IFY_SKIPPED] = { EvtCmd_GotoIfySkip, 2 }, \
    [EVT_CMD_GOTO_IFY_FLAG] = { EvtCmd_GotoIfyFlag, 3 }, \
    [EVT_CMD_GOTO_IFN_FLAG] = { EvtCmd_GotoIfnFlag, 3 }, \
    [EVT_CMD_GOTO_IFY_ACTIVE] = { EvtCmd_GotoIfyActive, 3 }, \
    [EVT_CMD_JUMP] = { EvtCmd_Jump, 2 }, \
    [EVT_CMD_ITEM] = { EvtCmd_GiveItem, 2 }, \
    [EVT_CMD_ITEM_PID] = { EvtCmd_GiveItemTo, 3 }, \
    [EVT_CMD_MONEY] = { EvtCmd_GiveMoney, 2 }, \
    [EVT_CMD_MAPCHANGE] = { EvtCmd_MapChange, 2 }, \
    [EVT_CMD_MAPCHANGE_POS] = { EvtCmd_MapChangePosition, 2 }, \
    [EVT_CMD_FACTION] = { EvtCmd_SetFaction, 3 }, \
    [EVT_CMD_FLASHCURSOR_POS] = { EvtCmd_FlashCursorPosition, 2 }, \
    [EVT_CMD_FLASHCURSOR_PID] = { EvtCmd_FlashCursorPid, 2 }, \
    [EVT_CMD_CURSOR] = { EvtCmd_PutCursor, 2 }, \
    [EVT_CMD_CLEARCURSOR] = { EvtCmd_ClearCursors, 1 }, \
    [EVT_CMD_REMOVEUNIT] = { EvtCmd_RemovePid, 2 }, \
    [EVT_CMD_REMOVEUNIT_DISPLAYED] = { EvtCmd_RemovePidDisplayed, 2 }, \
    [EVT_CMD_SETAI_PID] = { EvtCmd_SetAiPid, 3 }, \
    [EVT_CMD_SETAI_POS] = { EvtCmd_SetAiPosition, 3 }, \
    [EVT_CMD_SETFLAG] = { EvtCmd_SetFlag, 2 }, \
    [EVT_CMD_CLEARFLAG] = { EvtCmd_ClearFlag, 2 }, \
    [EVT_CMD_BGM] = { EvtCmd_PlayBgm, 2 }, \
    [EVT_CMD_BGM_OVERRIDE] = { EvtCmd_OverrideBgm, 2 }, \
    [EVT_CMD_BGM_RESTORE] = { EvtCmd_RestoreBgm, 1 }, \
    [EVT_CMD_BGM_FADEOUT] = { EvtCmd_FadeBgmOut, 2 }, \
    [EVT_CMD_BGM_LOWER_ON] = { EvtCmd_LowerBgmVolume, 1 }, \
    [EVT_CMD_BGM_LOWER_OFF] = { EvtCmd_RestoreBgmVolume, 1 }, \
    [EVT_CMD_SE] = { EvtCmd_PlaySe, 2 }, \
    [EVT_CMD_CHAPTER] = { EvtCmd_NextChapter, 2 }, \
    [EVT_CMD_GAMEEND] = { EvtCmd_EndGame, 1 }, \
    [EVT_CMD_SETMAP] = { EvtCmd_SetMap, 4 }, \
    [EVT_CMD_NOSKIP] = { EvtCmd_NoSkip, 1 }, \
    [EVT_CMD_NOSKIP_NOTEXTSKIP] = { EvtCmd_NoSkipNoTextSkip, 1 }, \
    [EVT_CMD_YESSKIP] = { EvtCmd_YesSkip, 1 }, \
    [EVT_CMD_FADE_TOBLACK] = { EvtCmd_FadeToBlack, 2 }, \
    [EVT_CMD_FADE_FROMBLACK] = { EvtCmd_FadeFromBlack, 2 }, \
    [EVT_CMD_FADE_TOWHITE] = { EvtCmd_FadeToWhite, 2 }, \
    [EVT_CMD_FADE_FROMWHITE] = { EvtCmd_FadeFromWhite, 2 }, \
    [EVT_CMD_EXIT_MAP] = { EvtCmd_ExitMap, 1 }, \
    [EVT_CMD_ENTER_MAP] = { EvtCmd_EnterMap, 1 }, \
    [EVT_CMD_FIGHTSCR] = { EvtCmd_FightScript, 5 }, \
    [EVT_CMD_NOCLEARTALK] = { EvtCmd_DisableAutoClear, 1 }, \
    [EVT_CMD_FUNC_ONSKIP] = { EvtCmd_FuncOnSkip, 2 }, \
    [EVT_CMD_WEATHER] = { EvtCmd_SetWeather, 2 }, \
    [EVT_CMD_WM_START] = { EvtCmd_WmStart, 2 }, \
    [EVT_CMD_WM_END] = { EvtCmd_WmEnd, 1 }, \
    [EVT_CMD_WM_ZOOMTO] = { EvtCmd_WmZoomTo, 2 }, \
    [EVT_CMD_WM_ZOOMBACK] = { EvtCmd_WmZoomBack, 1 }, \
    [EVT_CMD_WM_PUTFACE] = { EvtCmd_WmPutFace, 4 }, \
    [EVT_CMD_WM_REMOVEFACE] = { EvtCmd_WmRemoveFace, 2 }, \
    [EVT_CMD_WM_MOVEFACE] = { EvtCmd_WmMoveFace, 3 }, \
    [EVT_CMD_WM_NOP54] = { EvtCmd_WmNop54, 4 }, \
    [EVT_CMD_WM_NOP55] = { EvtCmd_WmNop55, 2 }, \
    [EVT_CMD_WM_TALK] = { EvtCmd_WmTalk, 2 }, \
    [EVT_CMD_WM_TALKBOX_BOTTOM] = { EvtCmd_WmTalkBoxBottom, 1 }, \
    [EVT_CMD_WM_TALKBOX_TOP] = { EvtCmd_WmTalkBoxTop, 1 }, \
    [EVT_CMD_WM_TALKBOX_REMOVE] = { EvtCmd_WmTalkBoxRemove, 1 }, \
    [EVT_CMD_WM_ARROW] = { EvtCmd_WmArrow, 2 }, \
    [EVT_CMD_WM_HIGHLIGHT] = { EvtCmd_WmPutHighlight, 2 }, \
    [EVT_CMD_WM_HIGHLIGHT_REMOVE] = { EvtCmd_WmRemoveHighlight, 2 }, \
    [EVT_CMD_WM_HIGHLIGHT_REMOVEBOTH] = { EvtCmd_WmRemoveBothHighlights, 1 }, \
    [EVT_CMD_WM_DOT] = { EvtCmd_StartWmDot, 4 }, \
    [EVT_CMD_WM_DOT_REMOVE] = { EvtCmd_WmRemoveDot, 2 }, \
    [EVT_CMD_WM_FLAG] = { EvtCmd_WmPutFlag, 4 }, \
    [EVT_CMD_WM_FLAG_REMOVE] = { EvtCmd_WmRemoveFlag, 2 }, \
    [EVT_CMD_WM_MAPTEXT] = { EvtCmd_WmPutMapText, 5 }, \
    [EVT_CMD_WM_MAPTEXT_REMOVE] = { EvtCmd_WmRemoveMapText, 2 }, \

extern struct ProcScr CONST_DATA ProcScr_Popup[];
extern struct ProcScr CONST_DATA ProcScr_PopupIconSprite[];
extern struct ProcScr CONST_DATA ProcScr_SceneReturnFromBackgroundTalk[];
extern struct ProcScr CONST_DATA ProcScr_SceneEndFade[];
extern struct ProcScr CONST_DATA ProcScr_Event[];
extern struct ProcScr CONST_DATA ProcScr_Event_Unused_085C4104[];
extern struct ProcScr CONST_DATA ProcScr_DarkenThenFunc[];
extern struct ProcScr CONST_DATA ProcScr_EventWaitForMu[];
extern struct ProcScr CONST_DATA ProcScr_FlashCursor[];
extern struct ProcScr CONST_DATA ProcScr_EventCursor[];
extern struct ProcScr CONST_DATA ProcScr_Unused_085C45B8[];
extern struct ProcScr CONST_DATA ProcScr_WeatherChangeFade[];
extern struct ProcScr CONST_DATA ProcScr_WmEventShowFace[];
extern struct ProcScr CONST_DATA ProcScr_WmEventHideFace[];
extern struct ProcScr CONST_DATA ProcScr_WmEventMoveFace[];

extern struct BackgroundEnt CONST_DATA gBackgroundTable[];
extern struct FaceVramEnt CONST_DATA gWmEventFaceConfig[];
extern struct FaceVramEnt CONST_DATA gFightEventFaceConfig[];

extern EventScr CONST_DATA EventScr_AutoTalk[];
extern EventScr CONST_DATA EventScr_085C46DC[];

extern struct PopupInfo CONST_DATA Popup_085C46FC[];
extern struct PopupInfo CONST_DATA Popup_085C473C[];
extern struct PopupInfo CONST_DATA Popup_085C477C[];
extern struct PopupInfo CONST_DATA Popup_085C47A4[];
extern struct PopupInfo CONST_DATA Popup_085C47DC[];
extern struct PopupInfo CONST_DATA Popup_085C4814[];
extern struct PopupInfo CONST_DATA Popup_085C4854[];
extern struct PopupInfo CONST_DATA Popup_PlayerStoleItem[];
extern struct PopupInfo CONST_DATA Popup_AiStoleItem[];
extern struct PopupInfo CONST_DATA Popup_085C4914[];
extern struct ProcScr CONST_DATA ProcScr_GiveItem[];

extern EventScr CONST_DATA EventScr_Item[];
extern EventScr CONST_DATA EventScr_ItemTo[];
extern EventScr CONST_DATA EventScr_Money[];
extern EventScr CONST_DATA EventScr_MapChange[];
extern EventScr CONST_DATA EventScr_ItemChest[];
extern EventScr CONST_DATA EventScr_MoneyChest[];
