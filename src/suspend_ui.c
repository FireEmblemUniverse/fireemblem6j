#include "prelude.h"
#include "talk.h"
#include "save_game.h"
#include "gamecontroller.h"
#include "constants/msg.h"

#include "suspend_ui.h"

EventScr CONST_DATA EventScr_SuspendPrompt[] =
{
    EvtNoSkipNoTextSkip
    EvtTalk(MSG_2FD)
    EvtGotoIfFunc(0, SuspendPrompt_HandleInput)

    EvtGoto(1)

EvtLabel(0)
    EvtFunc(WriteSuspandPlaterIdle)
    EvtTalkMore(MSG_2FE)
    EvtFadeBgmOut(3)
    EvtFadeToBlack(4)
    EvtExitMap
    EvtFunc(PostGameOverHandler)

EvtLabel(1)
    EvtClearSkip
    EvtEnd
};

void StartSuspendEvent(void)
{
    StartEvent(EventScr_SuspendPrompt);
}

bool SuspendPrompt_HandleInput(ProcPtr proc)
{
    switch (GetTalkChoiceResult()) {
    case TALK_CHOICE_YES:
        return true;

    case TALK_CHOICE_NO:
        return false;

    case TALK_CHOICE_CANCEL:
    default:
        return false;
    }
}

void WriteSuspandPlaterIdle(void)
{
    gAction.suspend_point = SUSPEND_POINT_PLAYER_PHASE;
    WriteSuspendSave(SAVE_SUSPEND);
}

void PostGameOverHandler(ProcPtr proc)
{
	SetNextGameAction(GAME_ACTION_0);
	EventEndBattleMap(proc);
}
