#pragma once

#include "prelude.h"
#include "proc.h"
#include "menu.h"

enum
{
    BGCHR_DEBUGMENU_MURAL = 0x580,
};

enum
{
    DEBUG_CONTROL_CP,
    DEBUG_CONTROL_HUMAN,
    DEBUG_CONTROL_ABSENT,
};

enum
{
    DEBUG_CPCONTROL_ENTRY_RED,
    DEBUG_CPCONTROL_ENTRY_GREEN,
};

enum
{
    DEBUG_BONUS_LEVELS = 20,
};

struct ProcDebugTextFrame
{
    /* 00 */ PROC_HEADER;
    /* 2C */ int x, y;
    STRUCT_PAD(0x34, 0x52);
    /* 52 */ u16 width;
    /* 54 */ char const * str;
};

struct ProcDebugMonitor
{
    /* 00 */ PROC_HEADER;
    STRUCT_PAD(0x29, 0x58);
    /* 58 */ int weather;
    STRUCT_PAD(0x5C, 0x66);
    /* 66 */ short debug_info;
};

void DebugApplyBonusLevelsToCursorUnit(void);
void PutDebugTextFrame(int x, int y, int width, char const * str);
fu8 StartDebugMainMenu(struct MenuProc * menu);
fu8 DebugMenu_Idle_Map(struct MenuProc * menu, struct MenuEntProc * ent);
fu8 DebugMenu_OnSelect_Map(struct MenuProc * menu, struct MenuEntProc * ent);
fu8 DebugMenu_OnBPress(struct MenuProc * menu, struct MenuEntProc * ent);
u32 DebugMenu_Display_DebugInfo(struct MenuProc * menu, struct MenuEntProc * ent);
fu8 DebugMenu_Idle_DebugInfo(struct MenuProc * menu, struct MenuEntProc * ent);
fu8 DebugMenu_OnSelect_DebugInfo(struct MenuProc * menu, struct MenuEntProc * ent);
u32 DebugMenu_Display_Weather(struct MenuProc * menu, struct MenuEntProc * ent);
fu8 DebugMenu_Idle_Weather(struct MenuProc * menu, struct MenuEntProc * ent);
fu8 DebugMenu_OnSelect_Weather(struct MenuProc * menu, struct MenuEntProc * ent);
u32 DebugMenu_Display_Playthroughs(struct MenuProc * menu, struct MenuEntProc * ent);
fu8 DebugMenu_Idle_Playthroughs(struct MenuProc * menu, struct MenuEntProc * ent);
fu8 DebugMenu_OnSelect_Playthroughs(struct MenuProc * menu, struct MenuEntProc * ent);
fu8 DebugMenu_OnSelect_ClearFile(struct MenuProc * menu, struct MenuEntProc * ent);
fu8 DebugClearFileMenu_OnSelect_Confirm(struct MenuProc * menu, struct MenuEntProc * ent);
fu8 DebugMenu_OnInit_Main(struct MenuProc * menu);
void StartDebugMenu_LoadGame(void);
fu8 DebugMenu_OnInit_LoadGame(struct MenuProc * menu);
fu8 DebugMenu_OnEnd_LoadGame(struct MenuProc * menu);
fu8 DebugMenu_Idle_StartChapter(struct MenuProc * menu, struct MenuEntProc * ent);
fu8 DebugMenu_OnSelect_StartChapter(struct MenuProc * menu, struct MenuEntProc * ent);
fu8 DebugMenu_OnSelect_Suspend(struct MenuProc * menu, struct MenuEntProc * ent);
fu8 DebugMenu_OnSelect_CpControl(struct MenuProc * menu, struct MenuEntProc * ent);
fu8 DebugMenu_OnSelect_SaveMenu(struct MenuProc * menu, struct MenuEntProc * ent);
fu8 DebugMenu_Available_SaveAltSuspend(struct MenuEntInfo const * info, int id);
fu8 DebugMenu_OnSelect_SaveAltSuspend(struct MenuProc * menu, struct MenuEntProc * ent);
fu8 DebugMenu_Available_LoadAltSuspend(struct MenuEntInfo const * info, int id);
fu8 DebugMenu_OnSelect_LoadAltSuspend(struct MenuProc * menu, struct MenuEntProc * ent);
fu8 DebugMenu_Available_LoadMainSuspend(struct MenuEntInfo const * info, int id);
fu8 DebugMenu_OnSelect_LoadMainSuspend(struct MenuProc * menu, struct MenuEntProc * ent);
u32 DebugMenu_Display_Fog(struct MenuProc * menu, struct MenuEntProc * ent);
fu8 DebugMenu_Idle_Fog(struct MenuProc * menu, struct MenuEntProc * ent);
fu8 DebugMenu_OnSelect_Fog(struct MenuProc * menu, struct MenuEntProc * ent);
fu8 DebugMenu_OnSelect_ReleaseEntry(struct MenuProc * menu, struct MenuEntProc * ent);
fu8 DebugMenu_OnSelect_Sleep(struct MenuProc * menu, struct MenuEntProc * ent);
u32 DebugCpControlMenu_Entry_Display(struct MenuProc * menu, struct MenuEntProc * ent);
fu8 DebugCpControlMenu_Entry_Idle(struct MenuProc * menu, struct MenuEntProc * ent);
fu8 DebugMenu_OnSelect_SramReset(struct MenuProc * menu, struct MenuEntProc * ent);

extern struct ProcScr CONST_DATA ProcScr_DebugMonitor[];
