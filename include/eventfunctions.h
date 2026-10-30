#pragma once

// NOTE: this may end up getting merged with chapterevents

#include "prelude.h"

#include "proc.h"
#include "event.h"
#include "eventinfo.h"

struct TutorialHighlightProc
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x64);
    /* 64 */ i16 clock;
    /* 66 */ i16 fading_out;
};

struct TutorialHighlightEndProc
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x64);
    /* 64 */ i16 timer;
};

bool IsHard(void);
// GetHardModeBonusLevelsByPid
void ApplyAllHardModeBonusLevels(void);
bool Chapter11A_CheckTalkShannaThea(struct EventInfo * info);
bool Chapter11A_CheckShannaRecruitsThea(struct EventInfo * info);
bool Chapter11A_CheckTalkShannaTheaAfterKlein(struct EventInfo * info);
bool Chapter13_CheckBlueEntersEast(struct EventInfo * info);
// CheckFindHiddenItemNoThief
bool Chapter15_CheckTalkRoyPerceval(struct EventInfo * info);
bool Chapter24_CheckReinforcementWave1(struct EventInfo * info);
bool Chapter24_CheckReinforcementWave2(struct EventInfo * info);
bool Chapter24_CheckReinforcementWave3(struct EventInfo * info);
bool Chapter24_CheckReinforcementWave4(struct EventInfo * info);
bool Chapter24_CheckReinforcementWave5(struct EventInfo * info);
bool Chapter24_CheckReinforcementWave6(struct EventInfo * info);
bool Chapter10B_CheckTalkShannaThea(struct EventInfo * info);
bool Chapter10B_CheckTalkShannaTheaAfterKlein(struct EventInfo * info);
bool Chapter10B_CheckShannaRecruitsThea(struct EventInfo * info);
// CheckTalkShannaTheaWhileDouglasEnemy
// CheckTalkShannaTheaAfterDouglas
bool TrialC_CheckRedOnTile(struct EventInfo * info);
bool TrialD_CheckBerserkerDefeated(struct EventInfo * info);
bool IsGuinivereAround(void);
// SoftResetKeepEwram
// IsAButtonNotPressed
// SoftResetKeepEwram2
// IsAButtonPressed
void RemoveFog(void);
void AddFiveThousandGold(void);
// RemoveGold
// WeakenUnitStats
// WeakenUnitStatsByPid
// IsPidBlueDeployed
bool IsLilinaBlueDeployed(void);
bool IsMarcusBlueDeployed(void);
bool IsMerlinusBlueDeployed(void);
bool IsJunoBlueDeployed(void);
bool IsZelotBlueDeployed(void);
bool IsSinBlueDeployed(void);
bool IsDayanBlueDeployed(void);
bool IsSueBlueDeployed(void);
bool IsMeladyBlueDeployed(void);
bool IsZeissBlueDeployed(void);
bool IsPercivalBlueDeployed(void);
// IsPidBlue
bool IsBorsBlue(void);
bool IsLilinaBlue(void);
bool IsElenBlue(void);
// IsRaighBlue
bool IsSueBlue(void);
// IsCathBlue
bool IsMeladyBlue(void);
bool IsZeissBlue(void);
bool IsSophiaBlue(void);
bool IsJunoBlue(void);
bool IsZelotBlue(void);
bool IsElffinBlue(void);
// IsFaeBlue
bool IsSinBlue(void);
bool IsDayanBlue(void);
bool IsKleinBlue(void);
bool IsTheaBlue(void);
bool IsDouglasBlue(void);
// IsAnyNonBlueUnitAlive
bool AreAllNonBlueUnitsDead(void);
bool IsPidNonBlue(fu8 pid);
// IsTheaNonBlue
bool IsUnknown5ENonBlue(void);
bool IsKleinNonBlue(void);
bool IsCathNonBlue(void);
bool IsHughNonBlue(void);
bool IsGalleNonBlue(void);
bool IsUnknownC4NonBlue(void);
bool IsUnknownC6NonBlue(void);
bool IsDouglasNonBlue(void);
bool IsPercevalNonBlue(void);
bool IsUnknownD5NonBlue(void);
bool IsUnknownD6NonBlue(void);
bool IsUnknownD7NonBlue(void);
// CountFactionUnitsByPid
// CountFactionUnits
bool IsPastTurn20(void);
bool IsPastTurn25(void);
bool IsPastTurn30(void);
bool IsBluePhase(void);
bool IsRedPhase(void);
bool IsActiveUnitMale(void);
bool HasTenThousandGold(void);
bool HasEightThousandGold(void);
bool HasSixThousandGold(void);
bool HasFiveThousandGold(void);
bool IsTalkChoiceYes(void);
bool AreWeGoingToSacae(void);
void GameOver_FadeOutBgm(void);
bool GameOver_ShouldSkipScreen(void);
void Tutorial_InitActionSelectHelp(void);
void Tutorial_FreezeMenuOnce(void);
bool Tutorial_IsMenuFrozen(void);
void Tutorial_ResumeMenu(void);
void Tutorial_StartMoveSelectEvent(void);
void Tutorial_StartAttackMenuEvent(void);
void Tutorial_StartAttackMenuItemEvent(void);
void Tutorial_StartMapMenuEvent(void);
// TutorialHighlight_SetFade
void TutorialHighlight_Init(struct TutorialHighlightProc * proc);
void TutorialHighlight_Loop(struct TutorialHighlightProc * proc);
void TutorialHighlightEnd_Init(struct TutorialHighlightEndProc * proc);
void TutorialHighlightEnd_Loop(struct TutorialHighlightEndProc * proc);
// Tutorial_StartHighlight
bool Tutorial_EndHighlightAfterHelp(void);
void Tutorial_HelpMoveRange(void);
void Tutorial_HelpAttackRange(void);
void Tutorial_HelpBowRange(void);
void Tutorial_HelpBowAttack(void);
void Tutorial_HelpBowMove(void);
void Tutorial_HelpMagicRange(void);
void Tutorial_HelpMagicAttack(void);
void Tutorial_HelpMagicMove(void);
void Tutorial_HelpWeaponSelect(void);
void Tutorial_HelpTargetSelect(void);
void Tutorial_HelpConfirmAttack(void);
void Tutorial_HelpAlenMove(void);
void Tutorial_HelpVisit(void);
// Tutorial_HelpUnused
void Tutorial_HelpMapMenu(void);
void Tutorial_HelpMeleeMove(void);
void Tutorial_HelpTrade(void);
void Tutorial_HelpRescue(void);
void Tutorial_HelpSeize(void);
void Tutorial_HelpUnitMenu(void);
void Tutorial_HelpAttackCommand(void);
bool IsActiveUnitRoy(void);
bool IsActiveUnitWolt(void);
bool IsActiveUnitLilina(void);
// IsActiveUnitAlen
bool Tutorial_CanAttackAfterMove(void);
bool IsCombatAction(void);
bool Tutorial_CheckFirstVisit(void);
// Tutorial_FalseStub
void Tutorial_DisableUnitMenuHelp(void);
bool IsAnyTutorialUnitDamaged(void);
bool IsAnyTutorialUnitPastColumn16(void);
bool IsBossDefeated(void);
// IsPastTurn1
bool Tutorial_ShouldHelpAttack(void);
bool Tutorial_CanVisit(void);
bool Tutorial_CanSeize(void);
bool Tutorial_ShouldHelpUnitMenu(void);
bool Tutorial_ShouldHelpRescue(void);
bool Tutorial_ShouldHelpTrade(void);
void RefreshClarine(void);
bool Chapter6_CheckWestDoorReinforcements(void);
bool Chapter6_CheckEastDoorReinforcements(void);
void Chapter8_WeakenNorthWestWall(void);
// PlayBgmSong28
void PlayBgmSong2B(void);
void PlayBgmSong2A(void);
// PlayBgmSong26
void PlaySeC4(void);
void StopEarthQuakeSound(void);
bool Chapter14_CheckFindHiddenItem(void);
void Chapter16_PayHughCost(void);
void PromoteRoyWithBindingBlade(void);
// IsItemOwned
bool HaveAllLegendaryWeapons(void);
void Chapter23_StartMapChange(void);
void Chapter24_ResetReinforcementCount(void);
void Chapter24_CountReinforcementWave(void);
void FinalChapter_InitUnitQuotes(void);
bool FinalChapter_PlayUnitQuotes(struct EventProc * proc);
bool IsThreeOrMoreNonBlueAlive(void);
bool EventRandOneInFive(void);
bool Chapter18S_CheckReinforcements(void);
void Chapter18S_UpdateReinforcementState(void);
void AddChapter8xFireTraps(void);
void SetChapter8x(void);
void AddChapter12xGasTraps(void);
void AddChapter14xTimedMapChanges(void);
void AddChapter16xArrowTraps(void);
void Chapter20xS_ChooseRealSeizeTile(void);
void AddChapter21xStepTraps(void);
void Chapter21x_ChooseTrappedChests(void);

struct DemoMonologueMsg
{
    /* 00 */ u16 msg;
    /* 02 */ u8 y_offset;
};

extern struct DemoMonologueMsg CONST_DATA gDemoMonologueMsg[];

struct ProcDemoSceneIntro
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x4C);
    /* 4C */ i16 timer;
};

void DemoScene_StartMonologue(void);
void SetBanimConfigUniqueBG(void);
void SetBanimConfigON(void);
void CleanupDemoSceneIntro(void);
void EndDemoSceneIntro(void);
void DemoSceneIntro_Blocked(ProcPtr proc);
void DemoSceneIntro_Init(struct ProcDemoSceneIntro * proc);
void DemoSceneIntro_FadeOut(struct ProcDemoSceneIntro * proc);
void DemoSceneIntro_StartExt(void);
void PutDemoMonologueMsg(void);
void DemoScene_TmpCleanup(void);
void DemoScene_JumpToChapterDirectly(int chapter, int x, int y);
void DemoScene_JumpToCh4(void);
void DemoScene_JumpToCh1(void);
void DemoScene_JumpToCh10A(void);
void DemoScene_JumpToCh2(void);
void DemoScene_JumpToCh22(void);
void DemoScene_SetRoyHp_10(void);
EventScr const * GetDemoSceneEvent_Unused(int arg_0, int arg_1);
void StartDemoSceneEvent(int arg_0, ProcPtr proc);
void EndAllProcsMark1(void);
void TrueEnding_EarthQuake_Main(void);
void TrueEnding_EarthQuake(ProcPtr proc);
void TrueEnding_EarthQuakeEnd(void);

struct ProcMapShake
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x64);
    /* 64 */ i16 timer;
};

void MapShake_Init(struct ProcMapShake * proc);
void MapShake_Loop(struct ProcMapShake * proc);
void StartMapShake(ProcPtr parent);
void EndMapShake(void);

struct ProcGameCreditFade
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x64);
    /* 64 */ i16 timer;
};

void EndingCreditFade_Init(struct ProcGameCreditFade * proc);
void EndingCreditFade_FadeBg(struct ProcGameCreditFade * proc);
void Epilogue_StartCredit(ProcPtr parent);
void RemoveEndingMonologueBG(void);

void EndingTimeFlowMonologue_Init(void);
void DrawEndingTimeFlowMonologue(ProcPtr parent);
bool EndingTimeFlowMonologueExists(void);

void Epilogue_RemoveEventEngineBG(struct EventProc * proc);
void Epilogue_RemoveEventEngineNoMap(struct EventProc * proc);
void TrueEnding_SetNiceWeather(void);
void Epilogue_StartWind(void);
void PlaySe269(void);
void TrueEnding_PlaySe269(void);
void PlaySe6A(void);

struct ProcEndingBgmLooper
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x64);
    /* 64 */ u16 timer;
};

void EndingBgmLooper_Init(struct ProcEndingBgmLooper * proc);
void EndingBgmLooper_Loop(struct ProcEndingBgmLooper * proc);
void NewEndingBgmLooper(ProcPtr parent);
void EndEndingBgmLooper(void);

void RenderMapForDirectJump(void);

struct ProcTrueEndingSortAllies
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x4C);
    /* 4C */ ProcPtr parent;
    /* 50 */ STRUCT_PAD(0x50, 0x64);
    /* 64 */ i16 uid;
};

void TrueEnding_SortAllies_Init(struct ProcTrueEndingSortAllies * proc);
void TrueEnding_SortAllies_Loop(struct ProcTrueEndingSortAllies * proc);
void TrueEnding_SortAllies(ProcPtr parent);
bool TrueEnding_SortAlliesExists(void);

struct ProcEpilogueBgmFade
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x64);
    /* 64 */ i16 timer;
    /* 66 */ i16 timer2;
};


void Epilogue_BgmFadeIn_Init(struct ProcEpilogueBgmFade * proc);
void Epilogue_BgmFadeOut_Init(struct ProcEpilogueBgmFade * proc);
void Epilogue_BgmFadeIn_Loop(struct ProcEpilogueBgmFade * proc);
void Epilogue_BgmFadeOut_Loop(struct ProcEpilogueBgmFade * proc);
void EarthQuakeSoundFadeOutDefault(void);
void Epilogue_BgmFadeIn(ProcPtr parent);
void Epilogue_BgmFadeOut(ProcPtr parent);

void RestoreBlueUnits(void);

struct GameEndingPosition { u8 x, y; u16 more; };

extern struct GameEndingPosition CONST_DATA gGameEndingPosition1[];
extern struct GameEndingPosition CONST_DATA gGameEndingPosition2[];

void GameEnding_PutUnitsOnPosition1(void);
void GameEnding_PutUnitsOnPosition2(void);
void GameEnding_DeployRoy(void);
void SetFlagIfDefeatedByBindingBlade(void);

enum ending_id {
    TRUE_ENDING,
    NORMAL_ENDING,
    FAKE_ENDING,
};
extern u8 EWRAM_DATA gEndingId;

void UpdateEndingId(void);
fu8 GetEndingId(void);

extern EventScr CONST_DATA EventScr_TrueEnding_IndunnNotDie[];
extern EventScr CONST_DATA EventScr_TrueEnding_IndunnDie[];
extern EventScr const * CONST_DATA EventScrs_EndingScene[];
extern EventScr CONST_DATA EventScr_TrueEnding[];
extern EventScr CONST_DATA EventScr_FalseEnding[];
extern EventScr CONST_DATA EventScr_CharacterEnding[];

void StartGameEndingScene(ProcPtr parent);
void SetupEndingUids(void);
