#include "gamecontroller.h"

#include "hardware.h"
#include "util.h"
#include "bm.h"
#include "unit.h"
#include "chapter.h"
#include "battle.h"
#include "chapterinfo.h"
#include "ui.h"
#include "eventinfo.h"
#include "eventfunctions.h"
#include "statscreen.h"
#include "save_stats.h"
#include "save_game.h"
#include "save_xmap.h"
#include "savemenu.h"
#include "opinfo.h"
#include "opanim.h"
#include "augury.h"
#include "playrank.h"

#include "constants/chapters.h"

struct ProcScr CONST_DATA ProcScr_Unused_GameController_085C4A1C[] =
{
    PROC_CALL(GC_InitFastStartCheck),
    PROC_REPEAT(GC_FastStartCheck),

    PROC_END,
};

struct ProcScr CONST_DATA ProcScr_GameController[] =
{
    PROC_19,
    PROC_MARK(PROC_MARK_GAMECTRL),

    PROC_19,

    PROC_CALL(GC_CheckSramResetKeyCombo),

    PROC_CALL(GC_InitFastStartCheck),
    PROC_REPEAT(GC_FastStartCheck),

PROC_LABEL(L_GAMECTRL_OPENINGSEQ),
    PROC_CALL(ForceEnableSounds),

    PROC_START_CHILD_LOCKING(ProcScr_OpAnim),

    PROC_CALL(GC_PostIntro),
    PROC_YIELD,

    PROC_GOTO(L_GAMECTRL_TITLE),

PROC_LABEL(L_GAMECTRL_CLASSDEMO),
    PROC_CALL(GC_InitDemo),

    PROC_CALL_2(GC_StartClassDemo),

    PROC_CALL(GC_PostDemo),
    PROC_YIELD,

    PROC_GOTO(L_GAMECTRL_OPENINGSEQ),

PROC_LABEL(L_GAMECTRL_SCENEDEMO),
    PROC_CALL(GC_InitDemo),

    PROC_CALL_ARG(StartDemoSceneEvent, 0),
    PROC_YIELD,

    PROC_CALL(CleanupGame),

    PROC_CALL(GC_PostDemo),
    PROC_YIELD,

    PROC_GOTO(L_GAMECTRL_OPENINGSEQ),

PROC_LABEL(L_GAMECTRL_TITLE),
    PROC_CALL(ForceEnableSounds),

    PROC_START_CHILD_LOCKING(ProcScr_TitleScreenHandler),

    PROC_CALL(GC_PostIntro),
    PROC_YIELD,

    PROC_GOTO(L_GAMECTRL_OPENINGSEQ),

PROC_LABEL(L_GAMECTRL_MAINMENU),
    PROC_CALL(ForceEnableSounds),

    PROC_CALL(StartMainMenu),
    PROC_YIELD,

    PROC_CALL(GC_PostMainMenu),
    PROC_YIELD,

    // fallthrough?

PROC_LABEL(L_GAMECTRL_CHAPTER),
    PROC_CALL(GC_CheckForGameEnded),

    PROC_START_CHILD_LOCKING(ProcScr_WorldMapIntroEvent),

    PROC_CALL(GC_DarkenScreen),
    PROC_YIELD,

    PROC_CALL(StartChapter),

    // fallthrough

PROC_LABEL(L_GAMECTRL_POSTCHAPTER),
    PROC_YIELD,

    PROC_CALL(GC_PostChapter),
    PROC_YIELD,

    PROC_CALL(GC_InitNextChapter),

    PROC_CALL(StartSaveMenu),
    PROC_YIELD,

    PROC_GOTO(L_GAMECTRL_CHAPTER),

PROC_LABEL(L_GAMECTRL_LOADSUSPEND),
    PROC_CALL(GC_DarkenScreen),
    PROC_YIELD,

    PROC_CALL(ResumeChapterFromSuspend),

    PROC_CALL(GC_PostLoadSuspend),

    PROC_GOTO(L_GAMECTRL_POSTCHAPTER),

PROC_LABEL(L_GAMECTRL_TRIAL),
    PROC_CALL(GC_InitTrialChapter),

    PROC_CALL(StartChapter),

    // fallthrough

PROC_LABEL(L_GAMECTRL_POSTTRIAL),
    PROC_YIELD,

    PROC_CALL(GC_PostChapter),
    PROC_YIELD,

    PROC_CALL(GC_ClearSuspend),

    PROC_CALL(NewPlayRankTrail),
    PROC_YIELD,

    PROC_GOTO(L_GAMECTRL_TITLE),

PROC_LABEL(L_GAMECTRL_TUTORIAL),
    PROC_CALL(GC_InitTutorial),

    PROC_START_CHILD_LOCKING(ProcScr_WorldMapIntroEvent),

    PROC_CALL(StartChapter),
    PROC_YIELD,

    PROC_GOTO(L_GAMECTRL_MAINMENU),

PROC_LABEL(L_GAMECTRL_LINK),
    PROC_CALL(StartLinkArenaMainMenu),
    PROC_YIELD,

    PROC_GOTO(L_GAMECTRL_MAINMENU),

PROC_LABEL(L_GAMECTRL_PREENDING),
    PROC_CALL(func_fe6_08029654),

    PROC_CALL(StartSaveMenu),
    PROC_YIELD,

    // fallthrough

PROC_LABEL(L_GAMECTRL_ENDING),
    PROC_CALL(StartGameEndingScene),
    PROC_YIELD,

    PROC_GOTO(L_GAMECTRL_TITLE),

PROC_LABEL(L_GAMECTRL_SRAMRESET),
    PROC_CALL(GC_InitSramResetScreen),

    PROC_CALL(StartMidFadeFromBlack),
    PROC_REPEAT(WhileFadeExists),

    PROC_CALL(StartEvent_SioXmap_0803C080),
    PROC_YIELD,

    PROC_CALL(StartMidFadeToBlack),
    PROC_REPEAT(WhileFadeExists),

    PROC_CALL(EndMuralBackground),

    PROC_GOTO(L_GAMECTRL_OPENINGSEQ),

    PROC_END,
};

int GetFurthestSaveChapter(void)
{
    struct PlaySt play_st;
    int i, chapter, number;

    chapter = 0;
    number = 0;

    for (i = SAVE_GAME0; i <= SAVE_GAME2; ++i)
    {
        if (!IsSaveValid(i))
            continue;

        ReadGameSavePlaySt(i, &play_st);

        if (number < GetChapterInfo(play_st.chapter)->index_gaiden)
        {
            number = GetChapterInfo(play_st.chapter)->index_gaiden;
            chapter = play_st.chapter;
        }
    }

    return chapter;
}

bool GC_StartClassDemo(struct GameController * proc)
{
    int class_set, chapter;

    chapter = GetFurthestSaveChapter();
    class_set = GetChapterInfo(chapter)->class_roll_set;

    if (class_set == 6)
    {
        if (proc->previous_demo_class_set == 6)
            class_set = 7;
        else
            class_set = 6;
    }

    if (chapter == 0)
        class_set = 0;

    proc->previous_demo_class_set = class_set;
    StartClassDemo(class_set, proc);

    return FALSE;
}

void GC_CheckSramResetKeyCombo(struct GameController * proc)
{
    if (gKeySt->held == (KEY_BUTTON_SELECT | KEY_DPAD_RIGHT | KEY_BUTTON_L))
        Proc_Goto(proc, L_GAMECTRL_SRAMRESET);
}

void GC_InitSramResetScreen(struct GameController * proc)
{
    InitBgs(NULL);
    ApplySystemGraphics();

    gPlaySt.config_talk_speed = PLAY_TALKSPEED_NORMAL;

    StartMuralBackground(PROC_TREE_3, NULL, -1);
}

void GC_InitFastStartCheck(struct GameController * proc)
{
    proc->clock = 20;
}

void GC_FastStartCheck(struct GameController * proc)
{
    if (!(gKeySt->held & KEY_BUTTON_START))
    {
        Proc_Break(proc);
        return;
    }

    proc->clock--;

    if (proc->clock < 0)
        Proc_Goto(proc, L_GAMECTRL_MAINMENU);
}

void EndIfNotGameController(ProcPtr proc)
{
    if (((struct Proc *) proc)->proc_mark == PROC_MARK_GAMECTRL)
        return;

    Proc_End(proc);
}

void CleanupGame(ProcPtr proc)
{
    CpuFastFill16(RGB_BLACK, gPal, sizeof(gPal));
    EnablePalSync();

    Proc_ForAll(EndIfNotGameController);

    SetMainFunc(OnMain);
}

void GC_PostIntro(struct GameController * proc)
{
    switch (proc->next_action)
    {

    case GAME_ACTION_2:
        Proc_Goto(proc, L_GAMECTRL_TITLE);
        break;

    case GAME_ACTION_0:
        Proc_Goto(proc, L_GAMECTRL_MAINMENU);
        break;

    case GAME_ACTION_1:
        switch (proc->demo_counter & 1)
        {
            case 0:
                Proc_Goto(proc, L_GAMECTRL_CLASSDEMO);
                break;

            case 1:
                Proc_Goto(proc, L_GAMECTRL_SCENEDEMO);
                break;
        }

        break;

    }
}

void GC_PostDemo(struct GameController * proc)
{
    switch (proc->next_action)
    {
        case GAME_ACTION_0:
            Proc_Goto(proc, L_GAMECTRL_TITLE);
            break;

        case GAME_ACTION_1:
            Proc_Goto(proc, L_GAMECTRL_OPENINGSEQ);
            break;
    }
}

void GC_PostMainMenu(struct GameController * proc)
{
    switch (proc->next_action)
    {
        case GAME_ACTION_0:
        case GAME_ACTION_1:
        case GAME_ACTION_2:
            Proc_Goto(proc, L_GAMECTRL_CHAPTER);
            break;

        case GAME_ACTION_3:
            Proc_Goto(proc, L_GAMECTRL_LOADSUSPEND);
            break;

        case GAME_ACTION_4:
            Proc_Goto(proc, L_GAMECTRL_TITLE);
            break;

        case GAME_ACTION_5:
            Proc_Goto(proc, L_GAMECTRL_LINK);
            break;

        case GAME_ACTION_8:
            Proc_Goto(proc, L_GAMECTRL_TUTORIAL);
            break;

        case GAME_ACTION_6:
            Proc_Goto(proc, L_GAMECTRL_TRIAL);
            break;
    }
}

void GC_InitTutorial(struct GameController * proc)
{
    InitPlayConfig(FALSE);

    gPlaySt.flags |= PLAY_FLAG_TUTORIAL;

    ResetPermanentFlags();
    ResetChapterFlags();

    InitUnits();

    gPlaySt.chapter = CHAPTER_TUTORIAL;
}

void GC_InitTrialChapter(struct GameController * proc)
{
    CreateTrialChapterBonusUnits();
    ClearPidStats();
    CleanupUnitsBeforeChapter();
}

void GC_ClearSuspend(struct GameController * proc)
{
    InvalidateSuspendSave(SAVE_SUSPEND);
}

void GC_PostChapter(struct GameController * proc)
{
    switch (proc->next_action)
    {
        case GAME_ACTION_0:
            Proc_Goto(proc, L_GAMECTRL_TITLE);
            break;

        case GAME_ACTION_2:
            Proc_Goto(proc, L_GAMECTRL_PREENDING);
            break;

        case GAME_ACTION_1:
            break;
    }
}

void GC_CheckForGameEnded(struct GameController * proc)
{
    if (!(gPlaySt.flags & PLAY_FLAG_COMPLETE))
        return;

    Proc_Goto(proc, L_GAMECTRL_ENDING);
}

void GC_PostLoadSuspend(struct GameController * proc)
{
    if (gPlaySt.flags & PLAY_FLAG_COMPLETE)
        Proc_Goto(proc, L_GAMECTRL_POSTTRIAL);
    else
        Proc_Goto(proc, L_GAMECTRL_POSTCHAPTER);
}

void GC_InitNextChapter(struct GameController * proc)
{
    RegisterChapterStats(&gPlaySt);
    gPlaySt.chapter = proc->next_chapter;

    CleanupUnitsBeforeChapter();
}

void GC_InitDemo(struct GameController * proc)
{
    proc->demo_counter++;
}

void GC_DarkenScreen(struct GameController * proc)
{
    SetBlendDarken(0x10);

    SetBlendTargetA(1, 1, 1, 1, 1);
    SetBlendBackdropA(1);
}

void StartGame(void)
{
    struct GameController * proc;

    SetMainFunc(OnMain);
    SetOnVBlank(OnVBlank);

    proc = SpawnProc(ProcScr_GameController, PROC_TREE_3);

    proc->next_action = GAME_ACTION_0;
    proc->next_chapter = 0;

    proc->demo_counter = 0;
}

struct GameController * GetGameController(void)
{
    return FindProc(ProcScr_GameController);
}

void SetNextGameAction(int action)
{
    struct GameController * proc = GetGameController();
    proc->next_action = action;
}

void SetNextChapter(int chapter)
{
    struct GameController * proc = GetGameController();
    proc->next_chapter = chapter;
}

bool HasNextChapter(void)
{
    struct GameController * proc = GetGameController();
    return proc->next_chapter == 0 ? FALSE : TRUE;
}

void RestartGameAndChapter(void)
{
    struct GameController * proc;

    Proc_EndEach(ProcScr_GameController);
    proc = SpawnProc(ProcScr_GameController, PROC_TREE_3);

    Proc_Goto(proc, L_GAMECTRL_CHAPTER);
}

void RestartGameAndLoadSuspend(void)
{
    struct GameController * proc;

    Proc_EndEach(ProcScr_GameController);
    proc = SpawnProc(ProcScr_GameController, PROC_TREE_3);

    Proc_Goto(proc, L_GAMECTRL_LOADSUSPEND);
}

void ForceEnableSounds(void)
{
    gPlaySt.config_bgm_disable = FALSE;
    gPlaySt.config_se_disable = FALSE;
}

void func_fe6_08013A64(void)
{
    gPlaySt.config_battle_anim = PLAY_ANIMCONF_ON;
    gPlaySt.config_talk_speed = PLAY_TALKSPEED_NORMAL;
    gPlaySt.config_walk_speed = 0;
    gPlaySt.config_bgm_disable = FALSE;
    gPlaySt.config_se_disable = TRUE;
    gPlaySt.config_window_theme = UI_WINDOW_THEME_BLUE;
    gPlaySt.config_unique_pal = 0;
}
