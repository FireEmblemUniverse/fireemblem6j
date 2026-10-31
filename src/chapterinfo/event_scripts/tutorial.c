#include "prelude.h"
#include "mapselect.h"
#include "bmfx.h"
#include "helpbox.h"

#include "eventfunctions.h"
#include "chapterunits.h"

#include "constants/pids.h"
#include "constants/msg.h"
#include "constants/songs.h"
#include "constants/iids.h"

// EventScr @ 0866AD18
EventScr CONST_DATA EventScr_Unk_0866AD18[] =
{
    EvtNoSkipNoTextSkip
    EvtUnitCameraOff
    EvtSetFlag(FLAG_TUTORIAL_4)
    EvtTalk(MSG_014)
    EvtClearTalk
    EvtPutCursor(7, 6)
    EvtTalk(MSG_015)
    EvtRemoveCursor
    EvtTalkContinue
    EvtClearTalk
    EvtLoadUnits(UnitInfo_Unk_086799E4)
    EvtMoveWait
    EvtLoadUnits(UnitInfo_Unk_08679974)
    EvtMoveWait
    EvtFunc(StartMapSongBgm)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866AD78
EventScr CONST_DATA EventScr_Unk_0866AD78[] =
{
    EvtNoSkipNoTextSkip
    EvtLoadUnits(UnitInfo_Unk_08679994)
    EvtMoveWait
    EvtTalk(MSG_036)
    EvtClearTalk
    EvtCameraUnit(PID_ROY)
    EvtTalk(MSG_037)
    EvtClearTalk
    EvtCamera(0, 2)
    EvtPutCursor(12, 3)
    EvtSleep(32)
    EvtTalk(MSG_038)
    EvtRemoveCursor
    EvtTalkContinue
    EvtClearTalk
    EvtCameraUnit(PID_ROY)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866ADE4
EventScr CONST_DATA EventScr_Unk_0866ADE4[] =
{
    EvtNoSkipNoTextSkip
    EvtLoadUnits(UnitInfo_Unk_086799B4)
    EvtMoveWait
    EvtCamera(12, 9)
    EvtTalk(MSG_039)
    EvtClearTalk
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866AE10
EventScr CONST_DATA EventScr_Unk_0866AE10[] =
{
    EvtNoSkipNoTextSkip
    EvtTalk(MSG_016)
    EvtClearTalk
    EvtCamera(22, 4)
    EvtPutCursor(22, 4)
    EvtTalk(MSG_017)
    EvtRemoveCursor
    EvtTalkContinue
    EvtClearTalk
    EvtCameraUnit(PID_ROY)
    EvtTalk(MSG_018)
    EvtClearTalk
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866AE60
EventScr CONST_DATA EventScr_Unk_0866AE60[] =
{
    EvtNoSkipNoTextSkip
    EvtTalk(MSG_035)
    EvtClearTalk
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866AE78
EventScr CONST_DATA EventScr_Unk_0866AE78[] =
{
    EvtNoSkipNoTextSkip
    EvtTalk(MSG_03B)
    EvtClearTalk
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866AE90
EventScr CONST_DATA EventScr_Unk_0866AE90[] =
{
    EvtNoSkipNoTextSkip
    EvtTalk(MSG_044)
    EvtClearTalk
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866AEA8
EventScr CONST_DATA gUnk_0866AEA8[] =
{
    EvtNoSkipNoTextSkip
    EvtSetFlag(FLAG_TUTORIAL_9)
    EvtDisableAutoClear
    EvtFunc(FreezeMenu)
    EvtFunc(Tutorial_HelpWeaponSelect)
    EvtFuncWhile(func_fe6_080718E0)
    EvtFunc(ResumeMenu)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866AEE0
EventScr CONST_DATA gUnk_0866AEE0[] =
{
    EvtNoSkipNoTextSkip
    EvtSetFlag(FLAG_TUTORIAL_10)
    EvtDisableAutoClear
    EvtFunc(FreezeMapSelect)
    EvtFunc(Tutorial_HelpTargetSelect)
    EvtFuncWhile(func_fe6_080718E0)
    EvtFunc(Tutorial_HelpConfirmAttack)
    EvtFuncWhile(func_fe6_080718E0)
    EvtFunc(ResumeMapSelect)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866AF28
EventScr CONST_DATA gUnk_0866AF28[] =
{
    EvtNoSkipNoTextSkip
    EvtSetFlag(FLAG_TUTORIAL_11)
    EvtFunc(FreezeMenu)
    EvtFunc(Tutorial_HelpMapMenu)
    EvtFuncWhile(func_fe6_080718E0)
    EvtFunc(ResumeMenu)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866AF5C
EventScr CONST_DATA gUnk_0866AF5C[] =
{
    EvtNoSkipNoTextSkip
    EvtGotoIfFlag(10, FLAG_TUTORIAL_5)

    EvtSetFlag(FLAG_TUTORIAL_5)
    EvtFunc(Tutorial_HelpMoveRange)
    EvtFuncWhile(func_fe6_080718E0)
    EvtSleep(20)

EvtLabel(10)
    EvtGotoIfNotFunc(99, Tutorial_CanAttackAfterMove)

    EvtGotoIfFlag(99, FLAG_TUTORIAL_14)

    EvtFunc(Tutorial_HelpAttackRange)
    EvtFuncWhile(func_fe6_080718E0)
    EvtSleep(20)
    EvtFunc(Tutorial_HelpMeleeMove)
    EvtSleep(20)
    EvtFuncWhile(Tutorial_EndHighlightAfterHelp)

EvtLabel(99)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866AFEC
EventScr CONST_DATA gUnk_0866AFEC[] =
{
    EvtNoSkipNoTextSkip
    EvtGotoIfFlag(10, FLAG_TUTORIAL_6)

    EvtSetFlag(FLAG_TUTORIAL_6)
    EvtFunc(Tutorial_HelpBowRange)
    EvtFuncWhile(func_fe6_080718E0)
    EvtSleep(20)

EvtLabel(10)
    EvtGotoIfNotFunc(99, Tutorial_CanAttackAfterMove)

    EvtGotoIfFlag(99, FLAG_TUTORIAL_15)

    EvtFunc(Tutorial_HelpBowAttack)
    EvtFuncWhile(func_fe6_080718E0)
    EvtSleep(20)
    EvtFunc(Tutorial_HelpBowMove)
    EvtSleep(20)
    EvtFuncWhile(Tutorial_EndHighlightAfterHelp)

EvtLabel(99)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866B07C
EventScr CONST_DATA gUnk_0866B07C[] =
{
    EvtNoSkipNoTextSkip
    EvtGotoIfFlag(10, FLAG_TUTORIAL_7)

    EvtSetFlag(FLAG_TUTORIAL_7)
    EvtFunc(Tutorial_HelpMagicRange)
    EvtFuncWhile(func_fe6_080718E0)
    EvtSleep(20)

EvtLabel(10)
    EvtGotoIfNotFunc(99, Tutorial_CanAttackAfterMove)

    EvtGotoIfFlag(99, FLAG_TUTORIAL_16)

    EvtFunc(Tutorial_HelpMagicAttack)
    EvtFuncWhile(func_fe6_080718E0)
    EvtSleep(20)
    EvtFunc(Tutorial_HelpMagicMove)
    EvtSleep(20)
    EvtFuncWhile(Tutorial_EndHighlightAfterHelp)

EvtLabel(99)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866B10C
EventScr CONST_DATA gUnk_0866B10C[] =
{
    EvtNoSkipNoTextSkip
    EvtGotoIfFlag(99, FLAG_TUTORIAL_8)

    EvtSetFlag(FLAG_TUTORIAL_8)
    EvtFunc(Tutorial_HelpAlenMove)
    EvtSleep(20)
    EvtFuncWhile(Tutorial_EndHighlightAfterHelp)

EvtLabel(99)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866B14C
EventScr CONST_DATA EventScr_Unk_0866B14C[] =
{
    EvtNoSkipNoTextSkip
    EvtFunc(Tutorial_InitActionSelectHelp)
    EvtGotoIfNotFunc(5, Tutorial_CanSeize)

    EvtFunc(Tutorial_FreezeMenuOnce)
    EvtFunc(Tutorial_HelpSeize)
    EvtFuncWhile(func_fe6_080718E0)
    EvtSleep(30)
    EvtGoto(10)

EvtLabel(5)
    EvtGotoIfNotFunc(6, Tutorial_CanVisit)

    EvtFunc(Tutorial_FreezeMenuOnce)
    EvtFunc(Tutorial_HelpVisit)
    EvtFuncWhile(func_fe6_080718E0)
    EvtSleep(30)
    EvtGoto(10)

EvtLabel(6)
    EvtGotoIfNotFunc(7, Tutorial_ShouldHelpAttack)

    EvtFunc(Tutorial_FreezeMenuOnce)
    EvtFunc(Tutorial_HelpAttackCommand)
    EvtFuncWhile(func_fe6_080718E0)
    EvtSleep(30)

EvtLabel(7)
    EvtGotoIfNotFunc(72, Tutorial_ShouldHelpRescue)

    EvtSetFlag(FLAG_TUTORIAL_20)
    EvtFunc(Tutorial_FreezeMenuOnce)
    EvtFunc(Tutorial_HelpRescue)
    EvtFuncWhile(func_fe6_080718E0)
    EvtSleep(30)

EvtLabel(72)
    EvtGotoIfNotFunc(8, Tutorial_ShouldHelpTrade)

    EvtSetFlag(FLAG_TUTORIAL_21)
    EvtFunc(Tutorial_FreezeMenuOnce)
    EvtFunc(Tutorial_HelpTrade)
    EvtFuncWhile(func_fe6_080718E0)
    EvtSleep(30)
    EvtGoto(10)

EvtLabel(8)
    EvtGotoIfNotFunc(10, Tutorial_ShouldHelpUnitMenu)

    EvtSetFlag(FLAG_TUTORIAL_19)
    EvtFunc(Tutorial_FreezeMenuOnce)
    EvtFunc(Tutorial_HelpUnitMenu)
    EvtFuncWhile(func_fe6_080718E0)
    EvtSleep(30)

EvtLabel(10)
    EvtGotoIfNotFunc(99, Tutorial_IsMenuFrozen)

    EvtFunc(Tutorial_ResumeMenu)

EvtLabel(99)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866B2E4
EventScr CONST_DATA EventScr_Unk_0866B2E4[] =
{
    EvtNoSkipNoTextSkip
    EvtTalk(MSG_009)
    EvtClearTalk
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866B2FC
EventScr CONST_DATA EventScr_Unk_0866B2FC[] =
{
    EvtNoSkipNoTextSkip
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_1)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_049)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtMapChange(0)
    EvtNoSkip
    EvtGiveItem(IID_VULNERARY)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866B350
EventScr CONST_DATA EventScr_Unk_0866B350[] =
{
    EvtNoSkipNoTextSkip
    EvtGotoIfFunc(10, IsActiveUnitRoy)

    EvtGotoIfFunc(20, IsActiveUnitWolt)

    EvtGotoIfFunc(30, IsActiveUnitLilina)

    EvtGoto(99)

EvtLabel(10)
    EvtGotoIfNotFunc(12, IsCombatAction)

    EvtGotoIfFlag(12, FLAG_TUTORIAL_14)

    EvtSetFlag(FLAG_TUTORIAL_14)
    EvtTalk(MSG_01D)
    EvtClearTalk
    EvtGoto(99)

EvtLabel(12)
    EvtGotoIfNotFunc(14, Tutorial_CheckFirstVisit)

    EvtTalk(MSG_02F)
    EvtClearTalk
    EvtGoto(99)

EvtLabel(14)
    EvtFunc(Tutorial_DisableUnitMenuHelp)
    EvtGoto(99)

EvtLabel(20)
    EvtGotoIfNotFunc(22, IsCombatAction)

    EvtGotoIfFlag(22, FLAG_TUTORIAL_15)

    EvtSetFlag(FLAG_TUTORIAL_15)
    EvtTalk(MSG_022)
    EvtClearTalk
    EvtGoto(99)

EvtLabel(22)
    EvtGotoIfNotFunc(24, Tutorial_CheckFirstVisit)

    EvtTalk(MSG_02F)
    EvtClearTalk
    EvtGoto(99)

EvtLabel(24)
    EvtFunc(Tutorial_DisableUnitMenuHelp)
    EvtGoto(99)

EvtLabel(30)
    EvtGotoIfNotFunc(32, IsCombatAction)

    EvtGotoIfFlag(32, FLAG_TUTORIAL_16)

    EvtSetFlag(FLAG_TUTORIAL_16)
    EvtTalk(MSG_028)
    EvtClearTalk
    EvtGoto(99)

EvtLabel(32)
    EvtGotoIfNotFunc(34, Tutorial_CheckFirstVisit)

    EvtTalk(MSG_02F)
    EvtClearTalk
    EvtGoto(99)

EvtLabel(34)
    EvtFunc(Tutorial_DisableUnitMenuHelp)

EvtLabel(99)
    EvtGotoIfFlag(100, FLAG_TUTORIAL_25)

    EvtGotoIfNotFunc(100, IsAnyTutorialUnitDamaged)

    EvtSetFlag(FLAG_TUTORIAL_25)
    EvtTalk(MSG_02C)
    EvtClearTalk

EvtLabel(100)
    EvtGotoIfFlag(109, FLAG_TUTORIAL_26)

    EvtGotoIfNotFunc(109, IsBossDefeated)

    EvtSetFlag(FLAG_TUTORIAL_26)
    EvtTalk(MSG_03D)
    EvtClearTalk

EvtLabel(109)
    EvtGotoIfFlag(129, FLAG_TUTORIAL_24)

    EvtGotoIfNotFunc(129, IsAnyTutorialUnitPastColumn16)

    EvtSetFlag(FLAG_TUTORIAL_24)
    EvtCamera(22, 4)
    EvtTalk(MSG_03C)
    EvtClearTalk

EvtLabel(129)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866B5A0
EventScr CONST_DATA EventScr_Unk_0866B5A0[] =
{
    EvtSetBgm(SONG_27)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_6)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_04A)
    EvtClearTalk
    EvtSleep(64)
    EvtNextChapter(0)
    EvtSleep(1)
    EvtKill
    EvtClearSkip
    EvtEnd
};
