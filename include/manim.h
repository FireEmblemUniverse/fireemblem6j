#pragma once

#include "prelude.h"

#include "text.h"
#include "unit.h"
#include "battle.h"

enum
{
    MANIM_FACING_OPPONENT,
    MANIM_FACING_DEFAULT,
    MANIM_FACING_UNKNOWN,
};

enum
{
    MANIM_KIND_DAMAGE = 0,
    MANIM_KIND_STEAL = 1,
    MANIM_KIND_REFRESH = 2,
};

struct MapAnimActor
{
    /* 00 */ struct Unit * unit;
    /* 04 */ struct BattleUnit * bu;
    /* 08 */ struct MuProc * mu;
    /* 0C */ u8 hp_max;
    /* 0D */ u8 hp_cur;
    /* 0E */ u16 hp_displayed_q4;
    /* 10 */ u8 hp_info_x;
    /* 11 */ u8 hp_info_y;
    /* 12 */ STRUCT_PAD(0x12, 0x14);
};

struct ManimSt
{
    /* 00 */ struct MapAnimActor actor[4];
    /* 50 */ struct BattleHit * hit_it;
    /* 54 */ struct ProcScr const * special_proc_scr;
    /* 58 */ u8 attacker_actor;
    /* 59 */ u8 defender_actor;
    /* 5A */ u16 hit_attributes;
    /* 5C */ u8 hit_info;
    /* 5D */ i8 hit_damage;
    /* 5E */ u8 main_actor_count;
    /* 5F */ u8 hp_bar_busy;
    /* 60 */ u8 target_x;
    /* 61 */ u8 target_y;
    /* 62 */ u8 manim_kind;
};

struct ManimStarSt
{
    /* 00 */ u16 radius_q4;
    /* 02 */ u16 angle_q4;
    /* 04 */ STRUCT_PAD(0x04, 0x08);
};

enum { MAX_MANIM_DEBUG_HITS = 5 };

enum
{
    MANIM_DEBUG_PARAM_PID,
    MANIM_DEBUG_PARAM_X,
    MANIM_DEBUG_PARAM_Y,
    MANIM_DEBUG_PARAM_JID,
    MANIM_DEBUG_PARAM_IID,
    MANIM_DEBUG_PARAM_HITS,
    MAX_MANIM_DEBUG_PARAM = MANIM_DEBUG_PARAM_HITS + MAX_MANIM_DEBUG_HITS,
};

enum
{
    MANIM_DEBUG_HIT_KIND_NONE,
    MANIM_DEBUG_HIT_KIND_REGULAR,
    MANIM_DEBUG_HIT_KIND_REGULAR_DEVIL,
    MANIM_DEBUG_HIT_KIND_REGULAR_HPSTEAL,
    MANIM_DEBUG_HIT_KIND_REGULAR_POISON,
    MANIM_DEBUG_HIT_KIND_CRIT,
    MANIM_DEBUG_HIT_KIND_CRIT_DEVIL,
    MANIM_DEBUG_HIT_KIND_CRIT_HPSTEAL,
    MANIM_DEBUG_HIT_KIND_CRIT_POISON,
    MANIM_DEBUG_HIT_KIND_MISS,

    MAX_MANIM_DEBUG_HIT_KIND,
};

struct ManimDebugStEnt
{
    /* 00 */ short data[MAX_MANIM_DEBUG_PARAM];
    /* 14 */ struct Text text[MAX_MANIM_DEBUG_PARAM];
};

struct ManimDebugSt
{
    /* 00 */ STRUCT_PAD(0x00, 0x08);
    /* 08 */ struct ManimDebugStEnt ent[2];
};

struct ManimDebugParamInfo
{
    /* 00 */ u8 text_width;
    /* 01 */ i8 param_up;
    /* 02 */ i8 param_down;
    /* 03 */ i8 param_left;
    /* 04 */ i8 param_right;
    /* 05 */ u8 min;
    /* 06 */ u8 max;
};

struct ManimFortifyFxProc
{
    /* 00 */ PROC_HEADER;
    /* 2C */ struct Unit * unit;
    /* 30 */ int x, y;
    /* 38 */ STRUCT_PAD(0x38, 0x40);
    /* 40 */ u16 unused_40;
    /* 42 */ u16 shine_count;
};

struct ManimFortifyBlinkProc
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x64);
    /* 64 */ i16 clock;
};

struct ManimExpBarProc
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x64);
    /* 64 */ i16 exp_from;
    /* 66 */ i16 exp_to;
    /* 68 */ i16 actor_id;
    /* 6A */ i16 open_transition_value;
};

struct ManimInfoWindowProc
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x2A);
    /* 2A */ i16 open_transition_value;
    /* 2C */ STRUCT_PAD(0x2C, 0x2E);
    /* 2E */ u8 x_tile;
    /* 2F */ u8 y_tile;
    /* 30 */ ProcPtr main_proc;
};

void Manim_StoleItemPopup(ProcPtr proc);
void Manim_WeaponBrokePopup(ProcPtr proc);
bool ManimShouldBuDisplayWeaponBroke(struct BattleUnit * bu);
void Manim_WeaponLevelGainedPopup(ProcPtr proc);
bool ManimShouldBuDisplayWeaponLevelGained(struct BattleUnit * bu);
void Manim_PrepareBattleTalk(ProcPtr proc);
void Manim_Finish(ProcPtr proc);
void PrepareManimHit(void);
void Manim_NextHit(ProcPtr proc);
void Manim_HitAnim(ProcPtr proc);
void Manim_HitPoisonAnim(ProcPtr proc);
void Manim_WatchActorA(ProcPtr proc);
void Manim_WatchActorB(ProcPtr proc);
void Manim_StartBattleDefeatTalk(ProcPtr proc);
void Manim_StartDeathFade(ProcPtr proc);
void Manim_ExpBar(ProcPtr proc);
void Manim_OpenInfoWindow(ProcPtr proc);
void Manim_StartBattleTalk(ProcPtr proc);
// ManimActorTransformAnim
void Manim_TransformAnim(ProcPtr proc);
void Manim_StealSe(void);
// InitManimActor
void SetManimActorFacing(int actor_num, int opponent_actor_num, int manim_facing);
void InitManimActorFacings(void);
void SortManimMuLayers(void);
void StartPoisonDamageManim(void);
void StartTrapDamageManim(void);
void StartStealManim(void);
// StartRefreshManim
void StartBattleManim(void);
void InitManimHits(struct BattleUnit * bu_a, struct BattleUnit * bu_b, struct BattleHit * battle_hits);
void InitManimActors(struct BattleUnit * bu_a, struct BattleUnit * bu_b, struct BattleHit * battle_hits);
int GetFacingFromTo(int xa, int ya, int xb, int yb);
// UnpackManimWindowDigits
// PutManimWindowNumber
// UnpackManimWindowGraphics
// PutManimWindowBarTile
// PutManimWindowBar
void EndManimInfoWindow(void);
void StartManimInfoWindow(int x, int y, ProcPtr proc);
// Manim_StartBattleTalk
// ManimInfoWindow_Init
// ManimInfoWindow_Loop
// PutManimInfoWindowActorValues
// GetUnitManimInfoFramePal
// InitManimActorInfoWindow
// ManimInfoWindow_OpenInit
// ManimInfoWindow_OpenLoop
// PutManimExpBar
// ManimExpBar_Init
// ManimExpBar_PlaySe
// ManimExpBar_Fill
// ManimExpBar_OpenInit
// ManimExpBar_OpenLoop
// ManimExpBar_LevelUp
// StartDebugManim
// PutManimDebugParamText
// ManimDebug_Init
// ManimDebug_Display
// ManimDebug_Loop
// ManimDebugInitBu
bool ManimDebugInitBattleScr(void);
// ManimDebug_StartBattleManim
// StartManimMissTag
// StartManimNoDamageTag
// StartManimRubbleAnim
// ManimRubbleAnim_Init
void StartManimPoisonAnim(struct Unit * unit);
// ManimPoisonAnim_Init
// StartManimFortifyFx
void ManimFortifyFx_Init(struct ManimFortifyFxProc * proc);
void ManimFortifyFx_Loop(struct ManimFortifyFxProc * proc);
// ManimFortifyFx_ClearBg2
void ManimFortifyBlink_Init(struct ManimFortifyBlinkProc * proc);
void ManimFortifyBlink_Loop(struct ManimFortifyBlinkProc * proc);
void StartManimFortifyShine(int x, int y, int square_size, int freeze_duration, int fadeout_duration, ProcPtr parent);
// ManimFortifyShine_End
// ManimFortifyShine_Init
// ManimFortifyShine_Start
// ManimFortifyShine_FadeIn
// ManimFortifyShine_Wait
// ManimFortifyShine_FadeOut
// StartManimAntitoxinFx
// ManimAntitoxinFx_Init
// ManimAntitoxinFx_Loop
// StartManimStatusHealSe
// ManimStatusHealSe_Play
// StartManimHealFx
// ManimHealFx_Init
// ManimHealFx_FadeIn
// ManimHealFx_FadeOut
void ManimFx_End(ProcPtr proc);
// ManimFx_EndWithHBlank
// StartManimWarpFx
// ManimWarpFx_Init
// ManimWarpFx_Loop
// StartManimTorchFx
// ManimTorchFx_Init
// ManimTorchFx_Expand
// ManimTorchFx_Fade
// ManimTorchFx_ResetHBlank
// StartManimBerserkFx
// ManimBerserkFx_Init
// StartManimHammerneFx
// ManimHammerneFx_PlaySe
// ManimHammerneFx_Init
// ManimHammerneFx_Loop
// ManimHammerneFx_Blink
// ManimHammerneFx_FadeOut
// StartManimRestoreFx
// ManimRestoreFx_Init
// ManimRestoreFx_Loop
// StartManimSleepFx
// ManimSleepFx_Init
// ManimSleepFx_Anim2
// ManimSleepFx_Anim3
// StartManimWaveFx
// ManimWaveFx_Init
// ManimWaveFx_Expand
// ManimWaveFx_Shrink
// StartManimSilenceFx
// ManimSilenceFx_Init
// ManimSilenceFx_Start
// ManimSilenceFx_Loop
// StartManimBarrierFx
// ManimBarrierFx_Init
// ManimBarrierFx_Loop
// StartManimUnlockFx
// ManimUnlockFx_HideUnitAndOpenDoor
// ManimUnlockFx_UnhideUnit
// ManimUnlockFx_Init
// ManimUnlockFx_Open
// ManimUnlockFx_Close
void SetDefaultManimScreenConf(void);
void StartManimBgScroll(int bg, int x_inc, int y_inc, ProcPtr parent);
// EndManimBgScroll
// ManimBgScroll_Loop
// PutManimLevelUpFrame
// PutManimLevelUpStat
int GetManimLevelUpStatGain(int actor_id, int stat_num);
int GetManimLevelUpBaseStat(int actor_id, int stat_num);

struct ManimLevelUpStatGainLabelProc {
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x2A);
    /* 2A */ u16 chr;
    /* 2C */ u16 pal;
    /* 2E */ u16 sprite_layer;
};

void ManimLevelUpStatGainLabel_Finish(struct ManimLevelUpStatGainLabelProc * proc);
void StartManimLevelUpStatGainLabels(int chr, int pal, int sprite_layer, ProcPtr parent);

struct ManimLevelUpProc {
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x2E);
    /* 2E */ i16 actor_id;
    /* 30 */ u8 next_stat_num;
    /* 31 */ u8 clock;
    /* 32 */ i16 y_scroll_offset;
};

void EndManimLevelUpStatGainLabels(void);
void StartManimLevelUpStatGainLabelAnim(int x, int y, int stat_num, int stat_gain);
void StartManimLevelUp(int actor_id, ProcPtr parent);
void InitManimLevelUpWindow(void);
void ClearManimLevelUpWindow(void);
void ManimLevelUp_InitMainScreen(struct ManimLevelUpProc * proc);

struct ManimLevelUpLabelColorProc {
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x54);
    /* 54 */ i32 clock;
    /* 58 */ STRUCT_PAD(0x58, 0x64);
    /* 64 */ i16 pal;
};

void ManimLevelUpLabelColor_Init(struct ManimLevelUpLabelColorProc * proc);
void ManimLevelUpLabelColor_Loop(struct ManimLevelUpLabelColorProc * proc);
void ManimLevelUp_ScrollIn(struct ManimLevelUpProc * proc);
void ManimLevelUp_ScrollOut(struct ManimLevelUpProc * proc);
void ManimLevelUp_PutStatGainLabels(struct ManimLevelUpProc * proc);
void ManimLevelUp_DimBgm(struct ManimLevelUpProc * proc);
void ManimLevelUp_StartLevelUpText(struct ManimLevelUpProc * proc);
void ManimLevelUp_EndLevelUpText(struct ManimLevelUpProc * proc);
void ManimLevelUp_RestoreBgm(struct ManimLevelUpProc * proc);
void ManimLevelUp_Clear(struct ManimLevelUpProc * proc);
// NewManimFadeIn
// ManimFadeIn_Loop
// NewManimFadeOut
// ManimFadeOut_Loop
// StartManimBgShake
// ManimBgShake_Init
// ManimBgShake_Loop
void SetupManimStarImage(void);
// PutManimStar
// PutManimStarAtAngle
// ManimWarpStarDisp_Init
// ManimWarpStarDisp_Loop
// NewManimWarpStarDisp
// PutManimStar1
// PutManimStar2
struct ProcScr const * GetManimRoundProcScr(void);
// Manim_AttackerActionAnim
// Manim_AttackerFaceDefenderDelayed
void Manim_AttackerRefreshAnim(ProcPtr proc);
void ManimAttackerDanceSe(void);
void ManimAttackerPlaySe(void);
void Manim_FreezeAttacker(ProcPtr proc);
void Manim_AttackerSpeedUp(ProcPtr proc);
// ManimShiftMuTowardsMu
// ManimShiftMuAwayFromMu
void Manim_ShiftAttackerTowardsDefender(ProcPtr proc);
void Manim_ShiftAttackerAwayFromDefender(ProcPtr proc);
void Manim_WatchAttacker(ProcPtr proc);
void Manim_WatchDefender(ProcPtr proc);
// Manim_WatchTarget
// Manim_HitImpact
void ManimAnimateActorDamage(int actor_id, int damage);
// Manim_AwaitDamageAnim
// Manim_DefenderPoisonAnim
// Manim_Silence
// Manim_Barrier
// Manim_Fortify
// Manim_Antitoxin
// Manim_PureWater
// Manim_Elixir
// Manim_Heal
// Manim_Mend
// Manim_Recover
// Manim_Vulnerary
// Manim_WarpOut
// Manim_WarpIn
// Manim_Torch
// Manim_Unlock
// Manim_Berserk
// Manim_Restore
// Manim_Sleep
// Manim_Hammerne
// Manim_DefenderFadeIntoFlash
// Manim_DefenderFadeFromFlash
// Manim_HideDefender
// Manim_DefenderStarExplosion
// Manim_DefenderStarImplosion
// Manim_ShowDefender
// Manim_MoveDefenderToTarget
// Manim_FadeIn
// Manim_FadeOut

extern struct ProcScr CONST_DATA ProcScr_PoisonDamageManim[];
extern struct ProcScr CONST_DATA ProcScr_TrapDamageManim[];
extern struct ProcScr CONST_DATA ProcScr_StealManim[];
extern struct ProcScr CONST_DATA ProcScr_RefreshManim[];
extern struct ProcScr CONST_DATA ProcScr_BattleManim[];
extern struct ProcScr CONST_DATA ProcScr_EndManim[];
extern struct ProcScr CONST_DATA ProcScr_ManimInfoWindow[];
extern struct ProcScr CONST_DATA ProcScr_ManimExpBar[];
extern struct ProcScr CONST_DATA ProcScr_ManimDebug[];
extern struct ProcScr CONST_DATA ProcScr_ManimRubbleAnim[];
extern struct ProcScr CONST_DATA ProcScr_ManimPoisonAnim[];
extern struct ProcScr CONST_DATA ProcScr_ManimFortifyFx[];
extern struct ProcScr CONST_DATA ProcScr_ManimFortifyBlink[];
extern struct ProcScr CONST_DATA ProcScr_ManimFortifyShine[];
extern struct ProcScr CONST_DATA ProcScr_ManimAntitoxinFx[];
extern struct ProcScr CONST_DATA ProcScr_ManimStatusHealSe[];
extern struct ProcScr CONST_DATA ProcScr_ManimHealFx[];
extern struct ProcScr CONST_DATA ProcScr_ManimWarpFx[];
extern struct ProcScr CONST_DATA ProcScr_ManimTorchFx[];
extern struct ProcScr CONST_DATA ProcScr_ManimBerserkFx[];
extern struct ProcScr CONST_DATA ProcScr_ManimHammerneFx[];
extern struct ProcScr CONST_DATA ProcScr_ManimRestoreFx[];
extern struct ProcScr CONST_DATA ProcScr_ManimSleepFx[];
extern struct ProcScr CONST_DATA ProcScr_ManimWaveFx[];
extern struct ProcScr CONST_DATA ProcScr_ManimSilenceFx[];
extern struct ProcScr CONST_DATA ProcScr_ManimBarrierFx[];
extern struct ProcScr CONST_DATA ProcScr_ManimUnlockFx[];
extern struct ProcScr CONST_DATA ProcScr_ManimBgScroll[];
extern struct ProcScr CONST_DATA ProcScr_ManimLevelUpStatGainLabel[];
extern struct ProcScr CONST_DATA ProcScr_ManimLevelUpLabelColor[];
extern struct ProcScr CONST_DATA ProcScr_ManimLevelUp[];
extern struct ProcScr CONST_DATA ProcScr_ManimFadeIn[];
extern struct ProcScr CONST_DATA ProcScr_ManimFadeOut[];
extern struct ProcScr CONST_DATA ProcScr_ManimBgShake[];
extern struct ProcScr CONST_DATA ProcScr_ManimWarpStarDisp[];
extern struct ProcScr CONST_DATA ProcScr_DefaultManimRound[];
extern struct ProcScr CONST_DATA ProcScr_ManimFortify[];
extern struct ProcScr CONST_DATA ProcScr_ManimAntitoxin[];
extern struct ProcScr CONST_DATA ProcScr_ManimPureWater[];
extern struct ProcScr CONST_DATA ProcScr_ManimElixir[];
extern struct ProcScr CONST_DATA ProcScr_ManimVulnerary[];
extern struct ProcScr CONST_DATA ProcScr_ManimHeal[];
extern struct ProcScr CONST_DATA ProcScr_ManimMend[];
extern struct ProcScr CONST_DATA ProcScr_ManimRecover[];
extern struct ProcScr CONST_DATA ProcScr_ManimPhysic[];
extern struct ProcScr CONST_DATA ProcScr_ManimTorch[];
extern struct ProcScr CONST_DATA ProcScr_ManimUnlock[];
extern struct ProcScr CONST_DATA ProcScr_ManimWatch[];
extern struct ProcScr CONST_DATA ProcScr_ManimSleep[];
extern struct ProcScr CONST_DATA ProcScr_ManimSilence[];
extern struct ProcScr CONST_DATA ProcScr_ManimRestore[];
extern struct ProcScr CONST_DATA ProcScr_ManimHammerne[];
extern struct ProcScr CONST_DATA ProcScr_PoisonManimNoDamageHit[];
extern struct ProcScr CONST_DATA ProcScr_PoisonDamageManimHit[];
extern struct ProcScr CONST_DATA ProcScr_TrapDamageManimHit[];
extern struct ProcScr CONST_DATA ProcScr_ManimBarrier[];
extern struct ProcScr CONST_DATA ProcScr_ManimWarp[];
extern struct ProcScr CONST_DATA ProcScr_ManimShiftingSineWaveScanlineBuf[];

extern u16 const Pal_ManimInfoFrameBlue[];
extern u16 const Pal_ManimInfoFrameRed[];
extern u16 const Pal_ManimInfoFrameGreen[];
extern u16 const Pal_ManimInfoFramePurple[];
extern u8 const Tsa_ManimInfoFrameSingle[];
extern u8 const Tsa_ManimInfoFrameLeft[];
extern u8 const Tsa_ManimInfoFrameRight[];
extern u8 const Tsa_ShopWindows[];
extern u8 const Img_ShopGoldBox[];
extern u8 const Img_EkrExpBar[];
extern u8 const Tsa_EkrExpBar[];
extern u8 const Img_EkrExpBarChange[];
extern u8 const Img_BarNumfx[];
extern u16 const Pal_EkrExpBar[];
extern u8 const Tsa_ManimExpBar[];
extern u32 const Img_ManimRubble[];
extern u16 const Pal_ManimRubble[];
extern u16 const SpriteAnim_ManimRubble[];
extern u8 const Img_ManimMissTag[];
extern u16 const Ap_ManimMissTag[];
extern u8 const Img_ManimNoDamageTag[];
extern u16 const Ap_ManimNoDamageTag[];
extern u32 const Img_ManimPoison[];
extern u16 const Pal_ManimPoison[];
extern u16 const SpriteAnim_ManimPoison[];
extern u8 const Img_ManimHeal[];
extern u16 const Pal_ManimHeal[];
extern u8 const Img_ManimFortify[];
extern u16 const Tsa_ManimAntitoxin[];
extern u32 const Img_ManimWarp[];
extern u16 const Pal_ManimWarp[];
extern u16 const TsaRef_ManimWarp[];
extern u8 const Img_ManimTorch[];
extern u16 const Pal_ManimTorch[];
extern u16 const SpriteAnim_ManimTorch[];
extern u8 const Img_ManimBerserk[];
extern u16 const Pal_ManimBerserk[];
extern u16 const SpriteAnim_ManimBerserk[];
extern u8 const Img_ManimHammerne[];
extern u16 const Pal_EfxHammarneBG[];
extern u8 const Tsa_ManimHammerne[];
extern u8 const Tsa_ManimRestore[];
extern u16 const Pal_EfxRestOBJ[];
extern u16 const SpriteAnim_ManimSleep[];
extern u8 const Img_ManimSilenceBg[];
extern u8 const Img_ManimSilenceObj[];
extern u16 const Pal_ManimSilence[];
extern u16 const SpriteAnim_ManimSilence[];
extern u8 const Img_ManimBarrier[];
extern u16 const Pal_EfxMshieldBG[];
extern u8 const Tsa_ManimBarrier[];
extern u8 const Img_ManimUnlockBg[];
extern u8 const Tsa_ManimUnlockBg[];
extern u8 const Img_ManimUnlockObj[];
extern u16 const Pal_ManimUnlockObj[];
extern u16 const Pal_ManimUnlockBg[];
extern u16 const SpriteAnim_ManimUnlock[];
extern u8 const Img_ManimLevelUpStatGain[];
extern u16 const Pal_ManimLevelUp[];
extern u8 const Img_ManimLevelUpStatGainDigits[];
extern u16 const SpriteAnim_ManimStatGain[];
extern u16 const Pal_ManimLevelUpStatGainCycling[];
extern u8 const Img_ManimLevelUpText[];
extern u16 const SpriteAnim_ManimLevelUpText[];
extern u32 const Img_ManimStar[];
extern u16 const Pal_ManimStar[];
extern u8 const Img_ManimAntitoxin[];
extern u16 const Pal_ManimAntitoxin[];
extern u16 const Pal_ManimPureWater[];
extern u8 const Img_ManimRecover[];
extern u8 const Img_ManimMend[];

extern struct ManimSt EWRAM_DATA gManimSt;

extern struct ManimStarSt gManimStars[0x10];
extern u16 gManimPalBackup[10 * 0x10];
