#pragma once

#include "prelude.h"

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
    /* 60 */ u8 unk_60;
    /* 61 */ u8 unk_61;
    /* 62 */ u8 manim_kind;
};

struct UnkSt_030046D0
{
    /* 00 */ u16 unk_00;
    /* 02 */ u16 unk_02;
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

// TODO: split this different procs for each effect
struct ManimEffectProc
{
    /* 00 */ PROC_HEADER;
    /* 2C */ struct Unit * unit;
    /* 30 */ int x, y;
    /* 38 */ u8 pad_38[0x40 - 0x38];
    /* 40 */ u16 unk_40;
    /* 42 */ u16 unk_42;
    /* 44 */ u16 unk_44;
    /* 44 */ u8 pad_46[0x48 - 0x46];
    /* 48 */ i16 unk_48;
    /* 4A */ i16 unk_4A;
    /* 4C */ i16 unk_4C;
    /* 4E */ /* pad */
    /* 50 */ void const * img;
    /* 54 */ void const * pal;
    /* 58 */ u16 unk_58;
    /* 5A */ u8 pad_5A[0x64 - 0x5A];
    /* 64 */ short unk_64;
};

struct ManimExpBarProc
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x64);
    /* 64 */ i16 exp_from;
    /* 66 */ i16 exp_to;
    /* 68 */ i16 actor_id;
    /* 6A */ i16 unk_6A;
};

struct ManimInfoWindowProc
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x2A);
    /* 2A */ i16 open_transition_value;
    /* 2C */ u16 unk_2C;
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
// func_fe6_08064C50
void func_fe6_08064CC0(struct ManimEffectProc * proc);
void func_fe6_08064DF8(struct ManimEffectProc * proc);
// func_fe6_08064F28
void func_fe6_08064F4C(struct ManimEffectProc * proc);
void func_fe6_08064FD0(struct ManimEffectProc * proc);
void func_fe6_080650A4(int x, int y, int square_size, int freeze_duration, int fadeout_duration, ProcPtr parent);
// func_fe6_080650F8
// func_fe6_0806511C
// func_fe6_08065140
// func_fe6_080651E0
// func_fe6_08065298
// func_fe6_080652E0
// func_fe6_080653BC
// func_fe6_0806543C
// func_fe6_08065540
// func_fe6_08065608
// func_fe6_08065674
// func_fe6_08065694
// func_fe6_080656F0
// func_fe6_08065830
// func_fe6_08065994
void func_fe6_08065AF8(ProcPtr proc);
// func_fe6_08065B90
// func_fe6_08065C30
// func_fe6_08065C9C
// func_fe6_08065CF4
// func_fe6_08065E08
// func_fe6_08065E78
// func_fe6_08065F9C
// func_fe6_08066094
// func_fe6_08066190
// func_fe6_080661A4
// func_fe6_08066214
// func_fe6_08066294
// func_fe6_08066300
// func_fe6_0806631C
// func_fe6_080663E0
// func_fe6_08066484
// func_fe6_08066544
// func_fe6_080665E4
// func_fe6_0806664C
// func_fe6_08066678
// func_fe6_0806671C
// func_fe6_08066784
// func_fe6_080667F0
// func_fe6_08066830
// func_fe6_0806686C
// func_fe6_080668D8
// func_fe6_080669BC
// func_fe6_08066A48
// func_fe6_08066AD4
// func_fe6_08066B3C
// func_fe6_08066C70
// func_fe6_08066D5C
// func_fe6_08066DFC
// func_fe6_08066E64
// func_fe6_08066F34
// func_fe6_08066FD8
// func_fe6_08067040
// func_fe6_08067084
// func_fe6_080670B8
// func_fe6_080671F4
// func_fe6_080672B0
void func_fe6_08067324(void);
void func_fe6_08067498(int bg, int x_inc, int y_inc, ProcPtr parent);
// func_fe6_08067514
// func_fe6_0806752C
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
// func_fe6_080685F0
// func_fe6_08068608
// func_fe6_08068628
void SetupManimStarImage(void);
// func_fe6_08068704
// func_fe6_0806875C
// func_fe6_080687BC
// func_fe6_08068858
// NewManimWarpStarDisp
// PutManimStar1
// PutManimStar2
struct ProcScr const * func_fe6_08068A48(void);
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
// func_fe6_08069028
// Manim_HitImpact
void ManimAnimateActorDamage(int actor_id, int damage);
// Manim_AwaitDamageAnim
// Manim_DefenderPoisonAnim
// func_fe6_08069560
// func_fe6_08069590
// func_fe6_080695C0
// func_fe6_080695F0
// func_fe6_0806962C
// func_fe6_08069668
// Manim_Heal
// Manim_Mend
// Manim_Recover
// func_fe6_08069758
// func_fe6_08069794
// func_fe6_0806984C
// Manim_Torch
// func_fe6_080698BC
// func_fe6_080698E4
// func_fe6_08069914
// func_fe6_08069944
// func_fe6_08069974
// func_fe6_080699A4
// func_fe6_080699D8
// func_fe6_08069A0C
// func_fe6_08069A40
// func_fe6_08069AB4
// func_fe6_08069B3C
// func_fe6_08069B70
// func_fe6_08069C04
// func_fe6_08069C1C

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
extern struct ProcScr CONST_DATA ProcScr_Unk_0866514C[];
extern struct ProcScr CONST_DATA ProcScr_Unk_08665194[];
extern struct ProcScr CONST_DATA ProcScr_Unk_086651AC[];
extern struct ProcScr CONST_DATA ProcScr_Unk_086651EC[];
extern struct ProcScr CONST_DATA ProcScr_Unk_08665234[];
extern struct ProcScr CONST_DATA ProcScr_Unk_08665254[];
extern struct ProcScr CONST_DATA ProcScr_Unk_0866528C[];
extern struct ProcScr CONST_DATA ProcScr_Unk_086652D4[];
extern struct ProcScr CONST_DATA ProcScr_Unk_0866531C[];
extern struct ProcScr CONST_DATA ProcScr_Unk_08665344[];
extern struct ProcScr CONST_DATA ProcScr_Unk_08665384[];
extern struct ProcScr CONST_DATA ProcScr_Unk_086653C4[];
extern struct ProcScr CONST_DATA ProcScr_Unk_08665404[];
extern struct ProcScr CONST_DATA ProcScr_Unk_08665454[];
extern struct ProcScr CONST_DATA ProcScr_Unk_08665494[];
extern struct ProcScr CONST_DATA ProcScr_Unk_086654BC[];
extern struct ProcScr CONST_DATA ProcScr_Unk_08665514[];
extern struct ProcScr CONST_DATA ProcScr_ManimLevelUpStatGainLabel[];
extern struct ProcScr CONST_DATA ProcScr_ManimLevelUpLabelColor[];
extern struct ProcScr CONST_DATA ProcScr_ManimLevelUp[];
extern struct ProcScr CONST_DATA ProcScr_ManimFadeIn[];
extern struct ProcScr CONST_DATA ProcScr_ManimFadeOut[];
extern struct ProcScr CONST_DATA ProcScr_Unk_086656B4[];
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
extern struct ProcScr CONST_DATA ProcScr_ManimHammern[];
extern struct ProcScr CONST_DATA ProcScr_Unk_08665ECC[];
extern struct ProcScr CONST_DATA ProcScr_PoisonDamageManimHit[];
extern struct ProcScr CONST_DATA ProcScr_TrapDamageManimHit[];
extern struct ProcScr CONST_DATA ProcScr_ManimBarrier[];
extern struct ProcScr CONST_DATA ProcScr_ManimWarp[];
extern struct ProcScr CONST_DATA ProcScr_ManimShiftingSineWaveScanlineBuf[];

extern u16 const Pal_ManimInfoFrameBlue[]; // pal blue
extern u16 const Pal_ManimInfoFrameRed[]; // pal red
extern u16 const Pal_ManimInfoFrameGreen[]; // pal green
extern u16 const Pal_ManimInfoFramePurple[]; // pal purple
extern u8 const Tsa_ManimInfoFrameSingle[]; // tsa
extern u8 const Tsa_ManimInfoFrameLeft[]; // tsa
extern u8 const Tsa_ManimInfoFrameRight[]; // tsa
extern u8 const Tsa_ShopWindows[];
extern u8 const Img_ShopGoldBox[];
extern u8 const Img_EkrExpBar[]; // img exp bar a
extern u8 const Tsa_EkrExpBar[];
extern u8 const Img_EkrExpBarChange[]; // img exp bar b
extern u8 const Img_BarNumfx[]; // img exp bar c
extern u16 const Pal_EkrExpBar[]; // pal exp bar
extern u8 const Tsa_ManimExpBar[]; // tsa exp bar
extern u32 const Img_ManimRubble[]; // img
extern u16 const Pal_ManimRubble[]; // pal
extern u16 const SpriteAnim_ManimRubble[]; // sprite anim
extern u8 const Img_ManimMissTag[]; // img
extern u16 const Ap_ManimMissTag[]; // sprite anim
extern u8 const Img_ManimNoDamageTag[]; // img
extern u16 const Ap_ManimNoDamageTag[]; // sprite anim
extern u32 const Img_ManimPoison[]; // img
extern u16 const Pal_ManimPoison[]; // pal
extern u16 const SpriteAnim_ManimPoison[]; // sprite anim
extern u8 const gUnk_082DE994[]; // img
extern u16 const gUnk_082DEFBC[]; // pal/colors
extern u8 const gUnk_082DEFFC[]; // img
extern u16 const gUnk_082DE354[]; // tm
extern u32 const Img_ManimWarp[]; // img
extern u16 const Pal_ManimWarp[]; // pal
extern u16 const TsaRef_ManimWarp[]; // tm
extern u8 const gUnk_082DF3D8[]; // img
extern u16 const gUnk_082DF690[]; // pal
extern u16 const SpriteAnim_082A8448[]; // sprite anim
extern u8 const gUnk_082E0E14[]; // img
extern u16 const gUnk_082E10EC[]; // pal
extern u16 const gUnk_082E110C[]; // sprite anim
extern u8 const gUnk_082DFAD4[]; // img
extern u16 const Pal_EfxHammarneBG[]; // pal
extern u8 const gUnk_082E07A8[]; // ???
extern u8 const gUnk_082DF868[]; // ??? ^
extern u8 const gUnk_08307928[]; // ???
// extern u8 const Img_EfxHammarneOBJ[]; // img
extern u16 const Pal_EfxRestOBJ[]; // pal
extern u16 const gUnk_082E0A14[]; // sprite anim
extern u8 const gUnk_082E161C[]; // img
extern u8 const gUnk_082E11DC[]; // img
extern u16 const gUnk_082E172C[]; // pal
extern u16 const gUnk_082E174C[]; // sprite anim
extern u8 const gUnk_082E1884[]; // img
extern u16 const Pal_EfxMshieldBG[]; // pal
extern u8 const gUnk_082E2440[]; // ???
extern u8 const gUnk_082DF724[]; // img
extern u8 const gUnk_082DF844[]; // ???
extern u8 const gUnk_082DF6B0[]; // img
extern u16 const gUnk_082DF704[]; // pal
extern u16 const gUnk_082DF824[]; // colors
extern u16 const SpriteAnim_082A84A4[]; // sprite anim
extern u8 const Img_ManimLevelUpStatGain[]; // img
extern u16 const Pal_ManimLevelUp[]; // pal
extern u8 const Img_ManimLevelUpStatGainDigits[]; // img (raw)
extern u16 const SpriteAnim_ManimStatGain[]; // sprite anim
extern u16 const Pal_ManimLevelUpStatGainCycling[]; // colors
extern u8 const Img_ManimLevelUpText[]; // img
extern u16 const SpriteAnim_082A7CBC[]; // sprite anim
extern u32 const Img_ManimStar[]; // img
extern u16 const Pal_ManimStar[]; // pal
extern u8 const gUnk_082DD848[]; // img
extern u16 const gUnk_082DE974[]; // ^ pal
extern u16 const gUnk_082DE954[]; // ^ pal
extern u8 const gUnk_082DED00[]; // img
extern u8 const gUnk_082DE994[]; // img
extern u8 const gUnk_082DEB08[]; // pal

extern struct ManimSt EWRAM_DATA gManimSt;

extern struct UnkSt_030046D0 gUnk_030046D0[0x10];
extern u16 gUnk_03004750[10 * 0x10];
