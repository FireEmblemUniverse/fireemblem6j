#include "prelude.h"
#include "ai.h"
#include "faction.h"
#include "oam.h"
#include "util.h"
#include "mu.h"
#include "bmfx.h"
#include "helpbox.h"
#include "suspend_ui.h"

#include "eventinfo.h"
#include "eventfunctions.h"
#include "chapterunits.h"

#include "constants/pids.h"
#include "constants/msg.h"
#include "constants/songs.h"
#include "constants/iids.h"
#include "constants/chapters.h"

// EventScr @ 08673F24
EventScr CONST_DATA EventScr_Unk_08673F24[] =
{
    EvtFlashCursor(17, 19)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_7)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_986)
    EvtClearTalk
    EvtLoadUnitsParty(UnitInfo_Unk_086830B8)
    EvtMoveWait
    EvtCameraUnit(PID_ROY)
    EvtFlashCursorUnit(PID_ROY)
    EvtSetBgm(SONG_2B)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_7)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_987)
    EvtClearTalk
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08673FB0
EventScr CONST_DATA EventScr_Unk_08673FB0[] =
{
    EvtGotoIfFunc(9, IsBluePhase)

    EvtClearFlag(FLAG_CHAPTER18S_5)

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08673FD4
EventScr CONST_DATA EventScr_Unk_08673FD4[] =
{
    EvtNoSkip
    EvtClearFlag(FLAG_CHAPTER18S_5)
    EvtFunc(Chapter18S_UpdateReinforcementState)

EvtLabel(1)
    EvtGotoIfNotFunc(2, Chapter18S_CheckReinforcements)

    EvtLoadUnits(UnitInfo_Unk_08683438)
    EvtMoveWait

EvtLabel(2)
    EvtGotoIfNotFunc(3, Chapter18S_CheckReinforcements)

    EvtLoadUnits(UnitInfo_Unk_08683458)
    EvtMoveWait

EvtLabel(3)
    EvtGotoIfNotFunc(4, Chapter18S_CheckReinforcements)

    EvtLoadUnits(UnitInfo_Unk_08683478)
    EvtMoveWait

EvtLabel(4)
    EvtGotoIfNotFunc(5, Chapter18S_CheckReinforcements)

    EvtLoadUnits(UnitInfo_Unk_08683498)
    EvtMoveWait

EvtLabel(5)
    EvtGotoIfNotFunc(6, Chapter18S_CheckReinforcements)

    EvtLoadUnits(UnitInfo_Unk_086834B8)
    EvtMoveWait

EvtLabel(6)
    EvtGotoIfNotFunc(7, Chapter18S_CheckReinforcements)

    EvtLoadUnits(UnitInfo_Unk_086834D8)
    EvtMoveWait

EvtLabel(7)
    EvtGotoIfNotFunc(8, Chapter18S_CheckReinforcements)

    EvtLoadUnits(UnitInfo_Unk_086834F8)
    EvtMoveWait

EvtLabel(8)
    EvtGotoIfNotFunc(9, Chapter18S_CheckReinforcements)

    EvtLoadUnits(UnitInfo_Unk_08683518)
    EvtMoveWait

EvtLabel(9)
    EvtGotoIfNotFunc(10, Chapter18S_CheckReinforcements)

    EvtLoadUnits(UnitInfo_Unk_08683538)
    EvtMoveWait

EvtLabel(10)
    EvtGotoIfNotFunc(11, Chapter18S_CheckReinforcements)

    EvtLoadUnits(UnitInfo_Unk_08683558)
    EvtMoveWait

EvtLabel(11)
    EvtGotoIfNotFunc(12, Chapter18S_CheckReinforcements)

    EvtLoadUnits(UnitInfo_Unk_08683578)
    EvtMoveWait

EvtLabel(12)
    EvtGotoIfNotFunc(13, Chapter18S_CheckReinforcements)

    EvtLoadUnits(UnitInfo_Unk_08683598)
    EvtMoveWait

EvtLabel(13)
    EvtGotoIfNotFunc(14, Chapter18S_CheckReinforcements)

    EvtLoadUnits(UnitInfo_Unk_086835B8)
    EvtMoveWait

EvtLabel(14)
    EvtGotoIfNotFunc(15, Chapter18S_CheckReinforcements)

    EvtLoadUnits(UnitInfo_Unk_086835D8)
    EvtMoveWait

EvtLabel(15)
    EvtGotoIfNotFunc(0, Chapter18S_CheckReinforcements)

    EvtLoadUnits(UnitInfo_Unk_086835F8)
    EvtMoveWait

EvtLabel(0)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086741D8
EventScr CONST_DATA EventScr_Unk_086741D8[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_0)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_98C)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08674214
EventScr CONST_DATA EventScr_Unk_08674214[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_0)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_98D)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08674250
EventScr CONST_DATA EventScr_Unk_08674250[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_0)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_98E)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867428C
EventScr CONST_DATA EventScr_Unk_0867428C[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_0)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_98F)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086742C8
EventScr CONST_DATA EventScr_Unk_086742C8[] =
{
    EvtSetBgm(SONG_27)
    EvtTalk(MSG_992)
    EvtFunc(func_fe6_08012798)
    EvtSleep(30)
    EvtGotoIfSkipped(22)

    EvtFunc(PlayBgmSong2B)

EvtLabel(22)
    EvtTalkContinue
    EvtFunc(func_fe6_08012780)
    EvtSleep(30)
    EvtGotoIfSkipped(23)

    EvtFunc(func_fe6_080127B0)

EvtLabel(23)
    EvtTalkContinue
    EvtClearTalk
    EvtSleep(64)
    EvtNextChapter(CHAPTER_19_S)
    EvtSleep(1)
    EvtKill
    EvtClearSkip
    EvtEnd
};
