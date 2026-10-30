#include "prelude.h"
#include "m4a.h"
#include "item.h"
#include "arena.h"
#include "arena_ui.h"
#include "mu.h"
#include "shop.h"
#include "talk.h"
#include "util.h"
#include "hardware.h"
#include "manim.h"
#include "gold.h"
#include "action.h"
#include "armfunc.h"
#include "event.h"
#include "bmio.h"
#include "msg.h"
#include "ui.h"
#include "chapter.h"
#include "save_stats.h"
#include "systemlabels.h"
#include "constants/faces.h"
#include "constants/msg.h"
#include "constants/songs.h"

struct ProcScr CONST_DATA ProcScr_ArenaUiMain[] =
{
    PROC_CALL(LockGame),
    PROC_SLEEP(1),
    PROC_CALL_ARG(_FadeBgmOut, -1),
    PROC_CALL(StartMidFadeToBlack),
    PROC_REPEAT(WhileFadeExists),
    PROC_CALL(LockBmDisplay),
    PROC_CALL_ARG(_StartBgm, 57),
    PROC_CALL(ArenaUi_Init),
    PROC_CALL(FadeInBlackSpeed20),
    PROC_SLEEP(1),
    PROC_CALL(ArenaUi_WelcomeDialogue),
    PROC_SLEEP(1),
    PROC_CALL(ArenaUi_WagerGoldDialogue),
    PROC_SLEEP(1),
    PROC_CALL(ArenaUi_CheckConfirmation),
    PROC_SLEEP(1),
    PROC_CALL(ArenaUi_ConfirmWager),
    PROC_SLEEP(1),
    PROC_CALL(ArenaUi_InstructionsDialogue),
    PROC_SLEEP(1),
    PROC_CALL(ArenaUi_GoodLuckDialogue),
    PROC_SLEEP(1),

PROC_LABEL(0),
    PROC_CALL_ARG(_FadeBgmOut, 2),
    PROC_CALL(FadeInBlackWithCallBack_Speed20),
    PROC_SLEEP(1),
    PROC_CALL(ArenaUi_StartArenaBattle),
    PROC_SLEEP(1),
    PROC_CALL(UnlockGame),
    PROC_CALL(UnlockBmDisplay),
    PROC_GOTO_SCR(ProcScr_ArenaUiResults),

PROC_LABEL(2),
    PROC_SLEEP(1),
    PROC_CALL(FadeInBlackWithCallBack_Speed20),
    PROC_SLEEP(1),
    PROC_CALL(ArenaUi_OnEnd),
    PROC_CALL(ClearTalk),
    PROC_CALL(UnlockBmDisplay),
    PROC_CALL(InitBmDisplay),
    PROC_CALL(StartMapSongBgm),
    PROC_CALL(StartMidFadeFromBlack),
    PROC_REPEAT(WhileFadeExists),
    PROC_CALL(UnlockGame),
    PROC_END,
};

void StartArenaScreen(void)
{
    ArenaBegin(gActiveUnit);
    SpawnProc(ProcScr_ArenaUiMain, PROC_TREE_3);
}

struct ProcScr CONST_DATA ProcScr_ArenaUiResults[] =
{
PROC_LABEL(1),
    PROC_CALL(_StartPartialGameLock),
    PROC_CALL(LockGame),
    PROC_CALL(LockBmDisplay),
    PROC_YIELD,
    PROC_START_CHILD(ProcScr_ArenaUiResultBgm),
    PROC_CALL(ArenaUi_Init),
    PROC_CALL(FadeInBlackSpeed20),
    PROC_YIELD,
    PROC_CALL(ArenaUi_ResultsDialogue),
    PROC_YIELD,
    PROC_CALL(ArenaUi_ShowGoldBoxOnVictoryOrDraw),
    PROC_YIELD,

PROC_LABEL(2),
    PROC_SLEEP(1),
    PROC_END_EACH(ProcScr_ArenaUiResultBgm),
    PROC_YIELD,
    PROC_CALL_ARG(_FadeBgmOut, 2),
    PROC_CALL(FadeInBlackWithCallBack_Speed20),
    PROC_YIELD,
    PROC_CALL(ArenaUi_BmEnd),
    PROC_CALL(ArenaUi_OnEnd),
    PROC_CALL(ClearTalk),
    PROC_CALL(UnlockBmDisplay),
    PROC_CALL(InitBmDisplay),
    PROC_CALL(StartMapSongBgm),
    PROC_CALL(StartMidFadeFromBlack),
    PROC_REPEAT(WhileFadeExists),
    PROC_CALL(UnlockGame),
    PROC_END
};

struct ProcScr CONST_DATA ProcScr_ArenaUiResultBgm[] =
{
    PROC_CALL(Arena_PlayResultSong),
    PROC_SLEEP(210),
    PROC_CALL(Arena_PlayArenaSong),
    PROC_END,
};

void StartArenaResultsScreen(void)
{
    ProcPtr proc;
    proc = SpawnProc(ProcScr_ArenaUiResults, PROC_TREE_3);
}

void ArenaUi_Init(ProcPtr proc)
{
    Proc_ForEach(ProcScr_Mu, (ProcFunc) HideMu);

    InitShopScreenConfig();

    gDispIo.bg0_ct.priority = 0;
    gDispIo.bg1_ct.priority = 2;
    gDispIo.bg2_ct.priority = 0;
    gDispIo.bg3_ct.priority = 3;

    InitTalk(0x200, 2, 0);
    InitFaces();
    StartTalkFace(FID_BA, 0x20, 8, 3, 1);

    Decompress(Tsa_ShopWindows, gBuf);
    TmApplyTsa(gBg1Tm, gBuf, 0x1000);
    TmFillRect(gBg1Tm + 0x100, 0x1E, 0xC, 0);
    EnableBgSync(BG1_SYNC_BIT);

    StartUiGoldBox(proc);

	SetWinEnable(1, 1, 0);
	SetWin0Layers(1, 1, 1, 1, 1);
	SetWin1Layers(1, 1, 0, 1, 1);
	SetWOutLayers(1, 1, 0, 1, 1);
	SetWin0Box(88, 72, 240, 152);
	SetWin1Box(0, 8, 240, 56);

    gDispIo.win_ct.win0_enable_blend = 0;
    gDispIo.win_ct.win1_enable_blend = 1;
    gDispIo.win_ct.wout_enable_blend = 0;

    SetBlendConfig(3, 0, 0, 8);

    SetBlendTargetA(0, 0, 0, 1, 0);
    SetBlendTargetB(0, 0, 0, 0, 0);

    Decompress(Img_UiArenaBG, (void *)BG_VRAM + GetBgChrOffset(BG_3));
    TmApplyTsa(gBg3Tm, Tsa_UiArenaBG, 0xC000);
    ApplyPalettes(Pal_UiArenaBG, 0xC, 4);

    EnableBgSync(BG3_SYNC_BIT);
}

void ArenaUi_BmEnd(ProcPtr proc)
{
    UpdateUnitFromBattle(gArenaSt.player, &gBattleUnitA);
    StartMu(gActiveUnit);
    SetAutoMuDefaultFacing();
}

void ArenaUi_WelcomeDialogue(ProcPtr proc)
{
	StartArenaDialogue(MSG_2F3, proc);
}

void ArenaUi_WagerGoldDialogue(ProcPtr proc)
{
    SetTalkNumber(ArenaGetMatchupGoldValue());
    StartArenaDialogue(MSG_2F4, proc);
}

void ArenaUi_CheckConfirmation(ProcPtr proc)
{
    switch (GetTalkChoiceResult()) {
    case TALK_CHOICE_CANCEL:
    case TALK_CHOICE_NO:
    default:
        StartArenaDialogue(MSG_2F6, proc);
        Proc_Goto(proc, 2);
        return;

    case TALK_CHOICE_YES:
        if (ArenaGetMatchupGoldValue() <= GetGold())
        {
            return;
        }
        else
        {
            StartArenaDialogue(MSG_2FC, proc);
            Proc_Goto(proc, 2);
        }
    }

    // ?
    return;
}

void ArenaUi_ConfirmWager(ProcPtr proc)
{
    int gold = GetGold();

    gold -= ArenaGetMatchupGoldValue();
    SetGold(gold);

    PlaySe(SONG_B9);
    DisplayGoldBoxText(gBg0Tm + TM_OFFSET(0x1B, 0x6));
    DrawArenaOpponentDetailsText(proc);
}

void ArenaUi_InstructionsDialogue(ProcPtr proc)
{
    StartArenaDialogue(MSG_2F7, proc);
}

void ArenaUi_GoodLuckDialogue(ProcPtr proc)
{
    StartArenaDialogue(MSG_2F5, proc);
}

void ArenaUi_FadeOutBgm(ProcPtr proc)
{
    FadeBgmOut(-1);
}

void ArenaUi_StartArenaBattle(ProcPtr proc)
{
    Proc_Mark(proc, PROC_MARK_EVENT_ANIM);

    ClearTalk();

    Proc_EndEach(ProcScr_GoldBox);

    gAction.id = ACTION_16;

    gActiveUnit->flags |= UNIT_FLAG_HAD_ACTION;

    PidStatsAddBattle(gActiveUnit);
    EndAllMus();

    gAction.extra = 0;

    BattleGenerateArena(gActiveUnit);

    BeginBattleAnimations();
}

void _StartPartialGameLock(ProcPtr proc)
{
    StartPartialGameLock(proc);
}

void _ArenaUi_Init(ProcPtr proc)
{
    ArenaUi_Init(proc);
}

void ArenaUi_ResultsDialogue(ProcPtr proc)
{
    u32 gold = GetGold();

    switch (ArenaGetResult()) {
    case ARENA_RESULT_WIN:
        SetTalkNumber(ArenaGetMatchupGoldValue() * 2);
        StartArenaDialogue(MSG_2F8, proc);

        gold += ArenaGetMatchupGoldValue() * 2;
        SetGold(gold);
        break;

    case ARENA_RESULT_LOSS:
        StartArenaDialogue(MSG_2F9, proc);
        break;

    case ARENA_RESULT_TIES:
        StartArenaDialogue(MSG_2FB, proc);

        gold += ArenaGetMatchupGoldValue();
        SetGold(gold);
        break;

    case ARENA_RESULT_YIELD:
        StartArenaDialogue(MSG_2FA, proc);
        break;
    }
}

void ArenaUi_ShowGoldBoxOnVictoryOrDraw(ProcPtr proc)
{
    switch (ArenaGetResult()) {
    case ARENA_RESULT_WIN:
    case ARENA_RESULT_TIES:
        DisplayGoldBoxText(gBg0Tm + TM_OFFSET(0x1B, 0x6));
        PlaySe(SONG_B9);
        StartTemporaryLock(proc, 60);
        break;

    case ARENA_RESULT_LOSS:
        break;

    case ARENA_RESULT_YIELD:
        break;
    }
}

void ArenaUi_OnEnd(ProcPtr proc)
{
    Proc_EndEach(ProcScr_GoldBox);
    Proc_ForEach(ProcScr_Mu, (ProcFunc) ShowMu);
}

void StartArenaDialogue(int msg, ProcPtr proc)
{

    SetInitTalkTextFont();
    ClearTalkText();

    StartTalkExt(8, 2, DecodeMsg(msg), proc);
    SetTalkPrintColor(TEXT_COLOR_SYSTEM_WHITE);

    SetTalkFlag(TALK_FLAG_INSTANTSHIFT);
    SetTalkFlag(TALK_FLAG_NOBUBBLE);
    SetTalkFlag(TALK_FLAG_NOSKIP);

    SetActiveTalkFace(TALK_FACE_1);
}

void DrawArenaOpponentDetailsText(ProcPtr proc)
{
    PutUiWindowFrame(7, 9, 0x10, 6, 0);
    SetTextFont(0);
    InitSystemTextFont();

    PutString(gBg0Tm + TM_OFFSET(8, 10),  0, SystemLabel_Level[GetLang()]);
    PutNumber(gBg0Tm + TM_OFFSET(12, 10), 2, gArenaSt.opponent->level);
    PutString(gBg0Tm + TM_OFFSET(8, 12),  0, DecodeMsg(gArenaSt.opponent->pinfo->msg_name));
    PutString(gBg0Tm + TM_OFFSET(15, 10), 0, DecodeMsg(gArenaSt.opponent->jinfo->msg_name));
    PutString(gBg0Tm + TM_OFFSET(15, 12), 0, GetItemName(gArenaSt.opponent_weapon));
}

void Arena_PlayResultSong(ProcPtr proc)
{
    switch (ArenaGetResult()) {
    case ARENA_RESULT_WIN:
        PlayBgm(SONG_46);
        break;

    default:
        PlayBgm(SONG_39);
        Proc_End(proc);
        break;
    }
}

void Arena_PlayArenaSong(ProcPtr proc)
{
    StartBgmExt(SONG_39, 0, 0);
}
