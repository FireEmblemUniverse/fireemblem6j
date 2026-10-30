#include "prelude.h"
#include "ai.h"
#include "faction.h"
#include "oam.h"
#include "util.h"
#include "mu.h"
#include "bmfx.h"
#include "helpbox.h"
#include "suspend_ui.h"
#include "map.h"
#include "unitsprite.h"

#include "eventinfo.h"
#include "eventfunctions.h"
#include "chapterunits.h"

#include "constants/pids.h"
#include "constants/msg.h"
#include "constants/songs.h"
#include "constants/iids.h"
#include "constants/chapters.h"

// EventScr @ 08672BE4
EventScr CONST_DATA EventScr_Unk_08672BE4[] =
{
    EvtFunc(InitPlayerDeployUnits)
    EvtFunc(InitPlayerDeployUnitPositions)
    EvtFunc(RefreshEntityMaps)
    EvtFunc(RefreshUnitSprites)
    EvtUnitCameraOff
    EvtSleep(16)
    EvtMoveUnit(PID_ROY, 8, 9)
    EvtMoveWait
    EvtSleep(16)
    EvtCameraUnit(PID_IDUNN)
    EvtSetBgm(SONG_29)
    EvtTalk(MSG_201)
    EvtClearTalk
    EvtFunc(PlaySe269)
    EvtFadeToWhite(4)
    EvtExitMap
    EvtSleep(30)
    EvtRemoveUnit(PID_IDUNN)
    EvtLoadUnits(UnitInfo_Unk_08681DF4)
    EvtMoveWait
    EvtSleep(32)
    EvtFadeFromWhite(4)
    EvtEnterMap
    EvtSleep(16)
    EvtCamera(8, 15)
    EvtSleep(16)
    EvtFunc(FinalChapter_InitUnitQuotes)
    EvtFuncWhile(FinalChapter_PlayUnitQuotes)
    EvtClearTalk
    EvtCameraUnit(PID_ROY)
    EvtUnitCameraOn
    EvtGotoIfFlag(5, FLAG_108)

    EvtTalk(MSG_236)
    EvtGoto(6)

EvtLabel(5)
    EvtTalk(MSG_237)

EvtLabel(6)
    EvtClearTalk
    EvtMoveUnit(PID_ROY, 8, 16)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08672D10
EventScr CONST_DATA EventScr_Unk_08672D10[] =
{
    EvtGotoIfFunc(0, IsThreeOrMoreNonBlueAlive)

EvtLabel(1)
    EvtGotoIfNotFunc(2, EventRandOneInFive)

    EvtLoadUnits(UnitInfo_Unk_08681E14)
    EvtGoto(9)

EvtLabel(2)
    EvtGotoIfNotFunc(3, EventRandOneInFive)

    EvtLoadUnits(UnitInfo_Unk_08681E34)
    EvtGoto(9)

EvtLabel(3)
    EvtGotoIfNotFunc(4, EventRandOneInFive)

    EvtLoadUnits(UnitInfo_Unk_08681E54)
    EvtGoto(9)

EvtLabel(4)
    EvtLoadUnits(UnitInfo_Unk_08681E74)

EvtLabel(9)
    EvtMoveWait

EvtLabel(0)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08672DB4
EventScr CONST_DATA EventScr_Unk_08672DB4[] =
{
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_7)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtClearTalk
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08672DE0
EventScr CONST_DATA EventScr_Unk_08672DE0[] =
{
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_7)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtClearTalk
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08672E0C
EventScr CONST_DATA EventScr_FinalEnding[] =
{
    EvtFunc(SetFlagIfDefeatedByBindingBlade)
    EvtFunc(UpdateEndingId)
    EvtFadeBgmOut(4)
    EvtFadeToBlack(4)
    EvtExitMap
    EvtGameEnd
    EvtKill
    EvtClearSkip
    EvtEnd
};
