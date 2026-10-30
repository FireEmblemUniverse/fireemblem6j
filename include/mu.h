#pragma once

#include "prelude.h"

#include "proc.h"
#include "unit.h"
#include "spriteanim.h"
#include "constants/videoalloc.h"

enum
{
    MU_STATE_NONE,
    MU_STATE_INACTIVE,
    MU_STATE_MOVEMENT,
    MU_STATE_SLEEPING,
    MU_STATE_UNK4,
    MU_STATE_BUMPING,
    MU_STATE_DISPLAY_UI,
    MU_STATE_DEATHFADE,
};

enum
{
    MU_FLASH_WHITE,
    MU_FLASH_BLACK,
    MU_FLASH_RED,
    MU_FLASH_GREEN,
    MU_FLASH_BLUE,
    MU_FLASH_5,
};

struct MuInfo
{
    u8 const * img;
    u16 const * anim;
};

struct MuConfig;

struct MuProc
{
    /* 00 */ PROC_HEADER;

    /* 2C */ struct Unit * unit;
    /* 30 */ struct SpriteAnim * sprite_anim;
    /* 34 */ struct MuConfig * config;

    /* 38 */ u8 cam_b;
    /* 39 */ u8 state;
    /* 3A */ u8 hidden_b;
    /* 3B */ u8 jid;
    /* 3C */ i8 facing;
    /* 3D */ u8 step_sound_clock;
    /* 3E */ u8 fast_walk_b;
    /* 3F */ // pad
    /* 40 */ u16 move_clock_q4;
    /* 42 */ i16 move_config;
    /* 44 */ i16 x_q4, y_q4;
    /* 48 */ i16 x_offset_q4, y_offset_q4;
};

struct MuConfig
{
    /* 00 */ u8 id;
    /* 01 */ u8 pal;
    /* 02 */ u16 chr;
    /* 04 */ u8 pc;
    /* 05 */ i8 movescr[0x40];
    /* 45 */ // 3 byte padding
    /* 48 */ struct MuProc * mu;
};

enum { MU_COUNT = 4 };
extern u8 gMuImgBuf[4 * 0x110 * CHR_SIZE]; // OVERLAY

typedef void (* MuStateFunc)(struct MuProc * mu);
extern MuStateFunc CONST_DATA sMuStateFuncs[];

void InitMus(void);
struct MuProc * StartMuExt(int x, int y, int jid, int arg_3);
struct MuProc * StartMu(struct Unit * unit);
void UpdateMu(struct MuProc * mu);
void EnableMuCamera(struct MuProc * mu);
void DisableMuCamera(struct MuProc * mu);
struct MuProc * StartUiMu(struct Unit * unit, int x, int y);
struct MuProc * StartMuInternal(u16 x, u16 y, u16 jid, int pal);
void SetMuFacing(struct MuProc * mu, int facing);
void SetMuDefaultFacing(struct MuProc * mu);
void SetAutoMuDefaultFacing(void);
void SetAutoMuMoveScript(u8 const * movescr);
bool MuExists(void);
bool MuExistsActive(void);
bool IsMuActive(struct MuProc * proc);
void SetMuMoveScript(struct MuProc * mu, u8 const * movescr);
void MuStepSe_Init(struct Proc * proc);
void MuStepSe_PlaySeA(struct Proc * proc);
void MuStepSe_PlaySeB(struct Proc * proc);
struct MuProc * StartMuScripted(u16 x, u16 y, u16 jid, int pal, u8 const * movescr);
void StartPlayMuStepSe(int song, int alt_offset, int x);
void PlayMuStepSe(struct MuProc * mu);
void EndMuMovement(struct MuProc * mu);
void RunMuMoveScript(struct MuProc * mu);
void StartMuFogBump(int x, int y);

struct MuFogBumpProc
{
    /* 00 */ PROC_HEADER;

    /* 2C */ int x, y;
    /* 34 */ u8 pad_34[0x50 - 0x34];
    /* 50 */ struct SpriteAnim * anim;
    /* 54 */ u8 pad_54[0x64 - 0x54];
    /* 64 */ short clock;
};

void MuFogBump_Init(struct MuFogBumpProc * proc);
void MuFogBump_ScaleLoop(struct MuFogBumpProc * proc);
void MuFogBump_EndLoop(struct MuFogBumpProc * proc);
bool IsMuFogBumpActive(void);
void Mu_OnStateBump(struct MuProc * mu);
void Mu_OnState_08060460(struct MuProc * mu);
void Mu_OnStateSleeping(struct MuProc * mu);
void Mu_OnStateNone(struct MuProc * mu);
void Mu_OnStateDoNothing(struct MuProc * mu);
void Mu_OnStateMovement(struct MuProc * mu);
void UpdateMuStepSounds(struct MuProc * mu);
void Mu_OnLoop(struct MuProc * mu);
void Mu_OnEnd(struct MuProc * mu);
void EndAllMus(void);
void EndMu(struct MuProc * proc);
void func_fe6_08060904(struct MuProc * mu);
void HaltMu(struct MuProc * mu);
void LockMus(void);
void ReleaseMus(void);
void ApplyMoveScriptToCoordinates(int * x, int * y, u8 const * movescr);
bool CanStartMu(void);
void ResetMuAnims(void);
struct MuConfig * GetNewMuConfig(void);
bool GetMuDisplayPosition(struct MuProc * mu, struct Vec2i * pos_out);
void PutMu(struct MuProc * mu);
u16 GetMuQ4MovementSpeed(struct MuProc * mu);
u8 * GetMuImgBufById(int id);
u8 const * GetMuImg(struct MuProc * proc);
u16 const * GetMuAnimForJid(u16 jid);
void StartMuDeathFade(struct MuProc * mu);
void MuDeathFade_OnLoop(struct Proc * proc);
void HideMu(struct MuProc * mu);
void ShowMu(struct MuProc * mu);
void SetMuScreenPosition(struct MuProc * mu, int x, int y);
void SetMuScreenOffset(struct MuProc * mu, int x_offset, int y_offset);
void StartMuFadeIntoFlash(struct MuProc * mu, int flash);
void StartMuFadeFromFlash(struct MuProc * mu);
void MuRestorePalInfo_Apply(struct Proc * proc);
void StartMuActionAnim(struct MuProc * mu);
void MuActionAnimFinishFunc(int arg);
void StartMuDelayedFaceDefender(struct MuProc * mu);
void MuDelayedFaceDefenderFunc(int arg);
void StartMuSpeedUpAnim(struct MuProc * mu);
void MuSlowDownAnimFreezeFunc(int arg);

struct MuFadeProc
{
    /* 00 */ PROC_HEADER;
    /* 2C */ struct MuProc * mu;
    /* 30 */ u8 clock;
};

void func_fe6_0806142C(struct MuProc * mu, int flash);
void func_fe6_08061474(struct MuFadeProc * proc);
void func_fe6_08061494(struct MuFadeProc * proc);
void func_fe6_080614C8(struct MuFadeProc * proc);
void func_fe6_08061518(struct MuFadeProc * proc);
void func_fe6_08061554(struct MuFadeProc * proc);
void func_fe6_080615D4(struct MuFadeProc * proc);
void StartMuFlashFadeFrom(struct MuProc * mu, int flash);
void MuFlashFadeFrom_RestorePal(struct MuFadeProc * proc);
void SetMuMaxWalkSpeed(void);
void MuMaxWalkSpeedFunc(ProcPtr mu);
void SetMuSpecialSprite(struct MuProc * mu, int jid, u16 const * pal);
void SetMuPal(struct MuProc * mu, int pal);

extern u16 const * CONST_DATA gMuFlashPalLut[];
extern struct ProcScr CONST_DATA ProcScr_MuStepSe[];
extern short CONST_DATA sMoveOffsetLut[4 * 2];
extern u16 CONST_DATA MuSoundScr_Foot[];
extern u16 CONST_DATA MuSoundScr_FootHeavy[];
extern u16 CONST_DATA MuSoundScr_Mounted[];
extern u16 CONST_DATA MuSoundScr_Wyvern[];
extern u16 CONST_DATA MuSoundScr_Pegasus[];
extern struct ProcScr CONST_DATA ProcScr_MuFogBump[];
extern struct ProcScr CONST_DATA ProcScr_Mu[];
extern u16 CONST_DATA sMuChrOffLut[MU_COUNT];
extern u8 CONST_DATA sMuWalkSpeedLut[];
extern u8 CONST_DATA sMuImgBufOffLut[];
extern struct ProcScr CONST_DATA ProcScr_MuDeathFade[];
extern struct ProcScr CONST_DATA ProcScr_MuRestorePalInfo[];
extern struct ProcScr CONST_DATA ProcScr_Unk_08664914[];
extern struct ProcScr CONST_DATA ProcScr_MuFlashFadeFrom[];
extern struct MuInfo CONST_DATA MuInfoTable[];
