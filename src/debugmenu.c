#include "debugmenu.h"

#include "random.h"
#include "hardware.h"
#include "debugtext.h"
#include "gamecontroller.h"
#include "map.h"
#include "bmfx.h"
#include "bmio.h"
#include "chapter.h"
#include "chapterinfo.h"
#include "menuinfo.h"
#include "ui.h"
#include "statscreen.h" // StartMuralBackground
#include "save_core.h"
#include "save_game.h"
#include "savemenu.h"

#include "constants/chapters.h"
#include "constants/faces.h"

enum
{
    DEBUG_WEATHER_NONE,
    DEBUG_WEATHER_SANDSTORM,
    DEBUG_WEATHER_SNOW,
    DEBUG_WEATHER_SNOWSTORM,
    DEBUG_WEATHER_RAIN,
    DEBUG_WEATHER_NIGHT,
    DEBUG_WEATHER_FLAMES,

    DEBUG_WEATHER_COUNT,
};

// in main.c
extern void PutBuildInfo(u16 * tm);

static void DebugTextFrame_DoPut(struct ProcDebugTextFrame * proc);

struct ProcScr CONST_DATA ProcScr_DebugMonitor[] =
{
    PROC_END,
};

struct ProcScr CONST_DATA ProcScr_DebugTextFrame[] =
{
    PROC_SLEEP(1),

    PROC_CALL(DebugTextFrame_DoPut),
    PROC_END,
};

void DebugApplyBonusLevelsToCursorUnit(void)
{
    struct Unit * unit = GetUnit(gMapUnit[gBmSt.cursor.y][gBmSt.cursor.x]);

    if (unit)
        UnitApplyBonusLevels(unit, DEBUG_BONUS_LEVELS);
}

static void DebugTextFrame_DoPut(struct ProcDebugTextFrame * proc)
{
    struct Text text;

    int x = proc->x;
    int y = proc->y;

    int width = proc->width;
    char const * str = proc->str;

    InitText(&text, width);
    Text_DrawString(&text, str);

    PutUiWindowFrame(x, y, width + 2, 4, UI_WINDOW_REGULAR);
    PutText(&text, gBg0Tm + TM_OFFSET(x+1, y+1));

    EnableBgSync(BG0_SYNC_BIT + BG1_SYNC_BIT);
}

void PutDebugTextFrame(int x, int y, int width, char const * str)
{
    struct ProcDebugTextFrame * proc = SpawnProc(ProcScr_DebugTextFrame, PROC_TREE_3);

    proc->x = x;
    proc->y = y;
    proc->str = str;
    proc->width = width;
}

fu8 StartDebugMainMenu(struct MenuProc * menu)
{
    EndMenu(menu);
    ClearUi();

    StartMenu(&MenuInfo_DebugMain);
    DebugInitBg(BG_2, 0);

    return MENU_ACTION_NOCURSOR;
}

fu8 DebugMenu_Idle_Map(struct MenuProc * menu, struct MenuEntProc * ent)
{
    if (gKeySt->repeated & KEY_DPAD_RIGHT)
        ent->id++;

    if (gKeySt->repeated & KEY_DPAD_LEFT)
        ent->id--;

    if (ent->id >= CHAPTER_COUNT)
        ent->id = CHAPTER_COUNT - 1;

    if (ent->id < CHAPTER_1)
        ent->id = CHAPTER_1;

    if (gKeySt->repeated & (KEY_DPAD_LEFT | KEY_DPAD_RIGHT))
    {
        DebugPutStr(gBg0Tm + TM_OFFSET(7, 3), "        ");
        DebugPutStr(gBg0Tm + TM_OFFSET(7, 3), GetChapterInfo(ent->id)->debug_name);

        EnableBgSync(BG0_SYNC_BIT);
    }

#if BUGFIX
    return 0;
#endif
}

fu8 DebugMenu_OnSelect_Map(struct MenuProc * menu, struct MenuEntProc * ent)
{
    EndMapMain();

    gPlaySt.chapter = ent->id;
    CleanupUnitsBeforeChapter();
    RestartGameAndChapter();

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

fu8 DebugMenu_OnBPress(struct MenuProc * menu, struct MenuEntProc * ent)
{
    EndMenu(menu);

    EndFaceById(0);
    ClearUi();

    return MENU_ACTION_NOCURSOR;
}

u32 DebugMenu_Display_DebugInfo(struct MenuProc * menu, struct MenuEntProc * ent)
{
    char const * offon[] =
    {
        JTEXT("ＯＦＦ"),
        JTEXT("　ＯＮ"),
    };

    struct ProcDebugMonitor * proc = FindProc(ProcScr_DebugMonitor);

    ClearText(&ent->text);

    Text_InsertDrawString(&ent->text, 8, TEXT_COLOR_SYSTEM_WHITE, JTEXT("デブ情報"));
    Text_InsertDrawString(&ent->text, 64, TEXT_COLOR_SYSTEM_BLUE, offon[proc->debug_info]);

    PutText(&ent->text, gBg0Tm + TM_OFFSET(ent->x, ent->y));

#if BUGFIX
    return 0;
#endif
}

fu8 DebugMenu_Idle_DebugInfo(struct MenuProc * menu, struct MenuEntProc * ent)
{
    struct ProcDebugMonitor * proc = FindProc(ProcScr_DebugMonitor);

    if (gKeySt->pressed & (KEY_BUTTON_A | KEY_DPAD_RIGHT | KEY_DPAD_LEFT))
    {
        proc->debug_info ^= 1;
        DebugMenu_Display_DebugInfo(menu, ent);

        DebugInitObj(-1, 9);
    }

#if BUGFIX
    return 0;
#endif
}

fu8 DebugMenu_OnSelect_DebugInfo(struct MenuProc * menu, struct MenuEntProc * ent)
{
    return 0;
}

u32 DebugMenu_Display_Weather(struct MenuProc * menu, struct MenuEntProc * ent)
{
    char const * weatherNames[] =
    {
        [DEBUG_WEATHER_NONE]      = TEXT("晴れ", "None"),
        [DEBUG_WEATHER_SANDSTORM] = TEXT("砂嵐", "Sandstorm"),
        [DEBUG_WEATHER_SNOW]      = TEXT("雪", "Snow"),
        [DEBUG_WEATHER_SNOWSTORM] = TEXT("吹雪", "Snowstorm"),
        [DEBUG_WEATHER_RAIN]      = TEXT("雨", "Rain"),
        [DEBUG_WEATHER_NIGHT]     = TEXT("夜", "Night"),
        [DEBUG_WEATHER_FLAMES]    = TEXT("溶岩", "Flames"),
    };

    struct ProcDebugMonitor * proc = FindProc(ProcScr_DebugMonitor);

    ClearText(&ent->text);

    Text_InsertDrawString(&ent->text, 8,  TEXT_COLOR_SYSTEM_WHITE, TEXT("天気", "Weather"));
    Text_InsertDrawString(&ent->text, 64, TEXT_COLOR_SYSTEM_BLUE, weatherNames[proc->weather % DEBUG_WEATHER_COUNT]);

    PutText(&ent->text, gBg0Tm + TM_OFFSET(ent->x, ent->y));

#if BUGFIX
    return 0;
#endif
}

fu8 DebugMenu_Idle_Weather(struct MenuProc * menu, struct MenuEntProc * ent)
{
    if (gKeySt->pressed & (KEY_BUTTON_A | KEY_DPAD_RIGHT | KEY_DPAD_LEFT))
    {
        struct ProcDebugMonitor * proc = FindProc(ProcScr_DebugMonitor);

        proc->weather++;
        DebugMenu_Display_Weather(menu, ent);

        switch (proc->weather % DEBUG_WEATHER_COUNT)
        {

        case DEBUG_WEATHER_NONE:
            SetWeather(WEATHER_NONE);
            break;

        case DEBUG_WEATHER_SANDSTORM:
            SetWeather(WEATHER_SANDSTORM);
            break;

        case DEBUG_WEATHER_SNOW:
            SetWeather(WEATHER_SNOW);
            break;

        case DEBUG_WEATHER_SNOWSTORM:
            SetWeather(WEATHER_SNOWSTORM);
            break;

        case DEBUG_WEATHER_RAIN:
            SetWeather(WEATHER_RAIN);
            break;

        case DEBUG_WEATHER_NIGHT:
            SetWeather(WEATHER_NIGHT);
            break;

        case DEBUG_WEATHER_FLAMES:
            SetWeather(WEATHER_FLAMES);
            break;

        }
    }

#if BUGFIX
    return 0;
#endif
}

fu8 DebugMenu_OnSelect_Weather(struct MenuProc * menu, struct MenuEntProc * ent)
{
    return 0;
}

u32 DebugMenu_Display_Playthroughs(struct MenuProc * menu, struct MenuEntProc * ent)
{
    ClearText(&ent->text);

    Text_InsertDrawString(&ent->text, 8, TEXT_COLOR_SYSTEM_WHITE, "\x8E\xFC\x89\xF1\x90\x94"); // "周回数"
    Text_InsertDrawString(&ent->text, 72, TEXT_COLOR_SYSTEM_BLUE, "\x8E\xFC\x96\xDA"); // "周目"
    Text_InsertDrawNumberOrBlank(&ent->text, 64, TEXT_COLOR_SYSTEM_BLUE, GetGlobalCompletedPlaythroughCount() + 1);

    PutText(&ent->text, gBg0Tm + TM_OFFSET(ent->x, ent->y));

#if BUGFIX
    return 0;
#endif
}


fu8 DebugMenu_Idle_Playthroughs(struct MenuProc * menu, struct MenuEntProc * ent)
{
    struct GlobalSaveInfo save_info;
    int clearCount, i;

    if (!(gKeySt->repeated & (KEY_DPAD_RIGHT | KEY_DPAD_LEFT)))
        return 0;

    clearCount = GetGlobalCompletedPlaythroughCount();

    if (gKeySt->repeated & KEY_DPAD_LEFT)
    {
        if (clearCount >= 0)
            clearCount--;
    }

    if (gKeySt->repeated & KEY_DPAD_RIGHT)
    {
        if (clearCount < MAX_CLEARED_PLAYTHROUGHS)
            clearCount++;
    }

    ReadGlobalSaveInfo(&save_info);

    for (i = 0; i < MAX_CLEARED_PLAYTHROUGHS; ++i)
        save_info.cleared_playthroughs[i] = 0;

    i = 0;

    while (i < clearCount)
    {
        i++;
        RegisterCompletedPlaythrough(&save_info, i);
    }

    if (clearCount == 0)
    {
        save_info.completed = FALSE;
        save_info.completed_true = FALSE;
        save_info.completed_hard = FALSE;
        save_info.completed_true_hard = FALSE;
    }
    else
    {
        save_info.completed = TRUE;
    }

    WriteGlobalSaveInfo(&save_info);

    DebugMenu_Display_Playthroughs(menu, ent);

#if BUGFIX
    return 0;
#endif
}

fu8 DebugMenu_OnSelect_Playthroughs(struct MenuProc * menu, struct MenuEntProc * ent)
{
    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

fu8 DebugMenu_OnSelect_ClearFile(struct MenuProc * menu, struct MenuEntProc * ent)
{
    ClearUi();
    StartMenu(&MenuInfo_DebugClearFile);

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A;
}

fu8 DebugClearFileMenu_OnSelect_Confirm(struct MenuProc * menu, struct MenuEntProc * ent)
{
    // required for a match
    u32 unused[4];

    // required for a match
    if (gPlaySt.playthrough_id != 0) {}

    WriteCompletedPlaythroughSaveData();

    gPlaySt.flags &= ~PLAY_FLAG_PREP;

    CleanupUnitsBeforeChapter();
    WriteGameSave(ReadLastGameSaveId());

    SoftReset(GBA_RESET_ALL);

#if BUGFIX
    return 0;
#endif
}

fu8 DebugMenu_OnInit_Main(struct MenuProc * menu)
{
    DebugPutStr(gBg0Tm + TM_OFFSET(7, 3), GetChapterInfo(CHAPTER_1)->debug_name);
    EnableBgSync(BG0_SYNC_BIT);

#if BUGFIX
    return 0;
#endif
}

void StartDebugMenu_LoadGame(void)
{
    SetMainFunc(OnMain);
    SetOnVBlank(OnVBlank);

    InitBmDisplay();

    DebugInitBg(BG_2, 0);

    if (!IsSramWorking())
        PutDrawText(NULL, gBg0Tm + TM_OFFSET(0, 18), 0, 0, 30, JTEXT("ＳＲＡＭが装着されていません"));

    StartMuralBackground(StartMenu(&MenuInfo_Debug_LoadGame), (u8 *) BG_VRAM + CHR_SIZE * BGCHR_DEBUGMENU_MURAL, -1);

    PutBuildInfo(gBg2Tm + TM_OFFSET(0, 1));
    DebugPutStr(gBg2Tm + TM_OFFSET(0, 2), "DB INTERRUPT AVAILABLE");
}

fu8 DebugMenu_OnInit_LoadGame(struct MenuProc * menu)
{
    struct SaveBlockInfo blockInfo;

    EnableBgSync(BG0_SYNC_BIT);

    // default chapter for the removed DebugMenu_Idle_StartChapter entry; past the end of this menu
    menu->entries[3]->id = CHAPTER_1;

    if (ReadSaveBlockInfo(&blockInfo, SAVE_SUSPEND) != TRUE || ((blockInfo.checksum32 + (blockInfo.checksum32>>16)) & 0xFF) != 0)
    {
        StartFace(0, FID_63, 32, 80, FACE_DISP_KIND(FACE_96x80_FLIPPED) | FACE_DISP_HLAYER(4));
        StartFace(1, FID_61, DISPLAY_WIDTH - 32, 80, FACE_DISP_KIND(FACE_96x80) | FACE_DISP_HLAYER(4));

        return 0;
    }
    else
    {
        StartFace(0, FID_67, 32, 80, FACE_DISP_KIND(FACE_96x80_FLIPPED) | FACE_DISP_HLAYER(4));
        StartFace(1, FID_66, DISPLAY_WIDTH - 32, 80, FACE_DISP_KIND(FACE_96x80) | FACE_DISP_HLAYER(4));

        return 0;
    }
}

fu8 DebugMenu_OnEnd_LoadGame(struct MenuProc * menu)
{
    EndFaceById(0);
    EndFaceById(1);

    SetDispEnable(0, 0, 0, 0, 0);
    SetBackdropColor(0);

#if BUGFIX
    return 0;
#endif
}

fu8 DebugMenu_Idle_StartChapter(struct MenuProc * menu, struct MenuEntProc * ent)
{
    int x = menu->rect.x + 2;
    int y = menu->rect.y + 8;

    if (gKeySt->repeated & KEY_DPAD_RIGHT)
        ent->id++;

    if (gKeySt->repeated & KEY_DPAD_LEFT)
        ent->id--;

    if (ent->id >= CHAPTER_COUNT)
        ent->id = CHAPTER_COUNT - 1;

    if (ent->id < CHAPTER_1)
        ent->id = CHAPTER_1;

    if (gKeySt->repeated & (KEY_DPAD_RIGHT | KEY_DPAD_LEFT))
    {
        DebugPutStr(gBg0Tm + TM_OFFSET(x, y), "        ");
        DebugPutStr(gBg0Tm + TM_OFFSET(x, y), GetChapterInfo(ent->id)->debug_name);

        EnableBgSync(BG0_SYNC_BIT);
    }

#if BUGFIX
    return 0;
#endif
}

fu8 DebugMenu_OnSelect_StartChapter(struct MenuProc * menu, struct MenuEntProc * ent)
{
    RandInit(GetGameTime());

    InitUnits();

    WriteNewGameSave(SAVE_GAME0, FALSE);
    gPlaySt.chapter = ent->id;

    WriteGameSave(SAVE_GAME0);
    CleanupUnitsBeforeChapter();

    RestartGameAndChapter();

    return MENU_ACTION_END;
}

fu8 DebugMenu_OnSelect_Suspend(struct MenuProc * menu, struct MenuEntProc * ent)
{
    StartMenu(&MenuInfo_DebugSuspend);

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

fu8 DebugMenu_OnSelect_CpControl(struct MenuProc * menu, struct MenuEntProc * ent)
{
    StartMenu(&MenuInfo_DebugCpControl);

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

fu8 DebugMenu_OnSelect_SaveMenu(struct MenuProc * menu, struct MenuEntProc * ent)
{
    StartSaveMenu(PROC_TREE_3);

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

fu8 DebugMenu_Available_SaveAltSuspend(struct MenuEntInfo const * info, int id)
{
    return MENU_ENTRY_DISABLED;
}

fu8 DebugMenu_OnSelect_SaveAltSuspend(struct MenuProc * menu, struct MenuEntProc * ent)
{
    if (ent->availability != MENU_ENTRY_ENABLED)
        return MENU_ACTION_SE_6B;

    WriteSuspendSave(SAVE_SUSPEND_ALT);

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

fu8 DebugMenu_Available_LoadAltSuspend(struct MenuEntInfo const * info, int id)
{
    return !IsValidSuspendSave(SAVE_SUSPEND_ALT) ? MENU_ENTRY_DISABLED : MENU_ENTRY_ENABLED;
}

fu8 DebugMenu_OnSelect_LoadAltSuspend(struct MenuProc * menu, struct MenuEntProc * ent)
{
    if (ent->availability != MENU_ENTRY_ENABLED)
        return MENU_ACTION_SE_6B;

    if (FindProc(ProcScr_BmMain) != NULL)
        EndMapMain();

    ReadSuspendSave(SAVE_SUSPEND_ALT);
    RestartGameAndLoadSuspend();

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

fu8 DebugMenu_Available_LoadMainSuspend(struct MenuEntInfo const * info, int id)
{
    return !IsValidSuspendSave(SAVE_SUSPEND) ? MENU_ENTRY_DISABLED : MENU_ENTRY_ENABLED;
}

fu8 DebugMenu_OnSelect_LoadMainSuspend(struct MenuProc * menu, struct MenuEntProc * ent)
{
    if (ent->availability != MENU_ENTRY_ENABLED)
        return MENU_ACTION_SE_6B;

    ReadSuspendSave(SAVE_SUSPEND);
    RestartGameAndLoadSuspend();

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

u32 DebugMenu_Display_Fog(struct MenuProc * menu, struct MenuEntProc * ent)
{
    char const * offon[] =
    {
        JTEXT("ＯＦＦ"),
        JTEXT("ＯＮ"),
    };

    ClearText(&ent->text);

    Text_InsertDrawString(&ent->text, 8, TEXT_COLOR_SYSTEM_WHITE, JTEXT("さく敵"));
    Text_InsertDrawString(&ent->text, 64, TEXT_COLOR_SYSTEM_BLUE, offon[gPlaySt.vision != 0]);

    PutText(&ent->text, gBg0Tm + TM_OFFSET(ent->x, ent->y));

#if BUGFIX
    return 0;
#endif
}

fu8 DebugMenu_Idle_Fog(struct MenuProc * menu, struct MenuEntProc * ent)
{
    if (IsMapFadeActive())
        return 0;

    if (gKeySt->pressed & (KEY_BUTTON_A | KEY_DPAD_RIGHT | KEY_DPAD_LEFT))
    {
        if (gPlaySt.vision == 0)
            SetFogVision(GetChapterInfo(gPlaySt.chapter)->fog);
        else
            SetFogVision(0);

        DebugMenu_Display_Fog(menu, ent);
    }

#if BUGFIX
    return 0;
#endif
}

fu8 DebugMenu_OnSelect_Fog(struct MenuProc * menu, struct MenuEntProc * ent)
{
    return 0;
}

fu8 DebugMenu_OnSelect_ReleaseEntry(struct MenuProc * menu, struct MenuEntProc * ent)
{
    StartGame();

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A;
}

fu8 DebugMenu_OnSelect_Sleep(struct MenuProc * menu, struct MenuEntProc * ent)
{
    func_fe6_0800285C(KEY_BUTTON_L | KEY_BUTTON_R);

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

u32 DebugCpControlMenu_Entry_Display(struct MenuProc * menu, struct MenuEntProc * ent)
{
    char const * strings[] =
    {
        [DEBUG_CONTROL_CP]     = JTEXT("ＣＰ"),
        [DEBUG_CONTROL_HUMAN]  = JTEXT("人間"),
        [DEBUG_CONTROL_ABSENT] = JTEXT("不参加"),
    };

    int state;

    if (ent->id != DEBUG_CPCONTROL_ENTRY_RED)
        state = gPlaySt.debug_control_green;
    else
        state = gPlaySt.debug_control_red;

    ClearText(&ent->text);

    Text_InsertDrawString(&ent->text, 8, TEXT_COLOR_SYSTEM_WHITE, ent->id != DEBUG_CPCONTROL_ENTRY_RED ? JTEXT("緑軍") : JTEXT("赤軍"));
    Text_InsertDrawString(&ent->text, 32, TEXT_COLOR_SYSTEM_BLUE, strings[state]);

    PutText(&ent->text, gBg0Tm + TM_OFFSET(ent->x, ent->y));

    return 0;
}

fu8 DebugCpControlMenu_Entry_Idle(struct MenuProc * menu, struct MenuEntProc * ent)
{
    if (gKeySt->pressed & (KEY_BUTTON_A | KEY_DPAD_RIGHT | KEY_DPAD_LEFT))
    {
        int state;

        if (ent->id != DEBUG_CPCONTROL_ENTRY_RED)
            state = gPlaySt.debug_control_green;
        else
            state = gPlaySt.debug_control_red;

        if (gKeySt->pressed & KEY_DPAD_LEFT)
            state--;

        if (gKeySt->pressed & (KEY_DPAD_RIGHT | KEY_BUTTON_A))
            state++;

        if (state > DEBUG_CONTROL_ABSENT)
            state = DEBUG_CONTROL_ABSENT;

        if (state < DEBUG_CONTROL_CP)
            state = DEBUG_CONTROL_CP;

        if (ent->id != DEBUG_CPCONTROL_ENTRY_RED)
            gPlaySt.debug_control_green = state;
        else
            gPlaySt.debug_control_red = state;

        DebugCpControlMenu_Entry_Display(menu, ent);
    }

    return 0;
}

fu8 DebugMenu_OnSelect_SramReset(struct MenuProc * menu, struct MenuEntProc * ent)
{
    RestartGameAndChapter();
    Proc_Goto(FindProc(ProcScr_GameController), L_GAMECTRL_SRAMRESET);

#if BUGFIX
    return 0;
#endif
}
