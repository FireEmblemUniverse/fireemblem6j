#pragma once

/**
 * messed banim related struct/data/functions
 */

#include "prelude.h"
#include "banim_sprite.h"
#include "battle.h"
#include "face.h"

#define ANIM_REF_OFFSET(off_ref_round, off_ref_pos) ((off_ref_round) * 2 + off_ref_pos)

enum EkrDistanceType_idx {
    EKR_DISTANCE_CLOSE,
    EKR_DISTANCE_FAR,
    EKR_DISTANCE_FARFAR,
    EKR_DISTANCE_MONOCOMBAT,
    EKR_DISTANCE_PROMOTION,

    EKR_DISTANCE_MAX
};

extern i16 gEkrDistanceType;

extern struct BaSprite *gAnims[4];
#define MAIN_ANIM_FRONT(pos) (gAnims[pos * 2 + 0])
#define MAIN_ANIM_BACK(pos)  (gAnims[pos * 2 + 1])

enum banim_mode_index {
    BANIM_MODE_NORMAL_ATK,
    BANIM_MODE_NORMAL_ATK_PRIORITY_L,
    BANIM_MODE_CRIT_ATK,
    BANIM_MODE_CRIT_ATK_PRIORITY_L,
    BANIM_MODE_RANGED_ATK,
    BANIM_MODE_RANGED_CRIT_ATK,
    BANIM_MODE_CLOSE_DODGE,
    BANIM_MODE_RANGED_DODGE,
    BANIM_MODE_STANDING,
    BANIM_MODE_STANDING2,
    BANIM_MODE_RANGED_STANDING,
    BANIM_MODE_MISSED_ATK,

    BANIM_MODE_INVALID = -1,
};

#define EFX_BG_WIDTH 66
#define EFX_TILEMAP_LOC(aMap, aX, aY) (aMap + (aX) + EFX_BG_WIDTH * (aY))

enum video_banim {
    BGPAL_EFX_0 = 0,
    BGPAL_EFX_SPELL_BG = 1,
    BGPAL_EFX_2 = 2,
    BGPAL_EFX_3 = 3,
    BGPAL_EFX_4 = 4,
    BGPAL_EFXDRAGON_L = 6,
    BGPAL_EFXDRAGON_R = 7,

    OBPAL_EFX_SYSTEM_OBJ = 0,
    OBPAL_EFX_SPELL_BG = 1,
    OBPAL_EFX_SPELL_OBJ = 2,
    OBPAL_EFX_FACE = 3,
    OBPAL_EFX_4 = 4,
    OBPAL_EFX_5 = 5,
    OBPAL_EFX_BG = 6,
    OBPAL_EFX_UNIT_L = 7,
    OBPAL_EFX_UNIT_BAK_L = 8,
    OBPAL_EFX_UNIT_R = 9,
    OBPAL_EFX_UNIT_BAK_R = 10,
    OBPAL_EFXHPBAR_L = 11,
    OBPAL_EFXHPBAR_R = 12,
    OBPAL_EFX_ITEM_L = 13,
    OBPAL_EFX_ITEM_R = 14,

    BGCHR_BANIM_080 = 0x80,
    BGCHR_BANIM_PNAME_L = 0xA0,
    BGCHR_BANIM_INAME_L = 0xAC,
    BGCHR_BANIM_PNAME_R = 0xBA,
    BGCHR_BANIM_INAME_R = 0xC6,

    VRAMOFF_BANIM_SPELL_OBJ = 0x0800,
    VRAMOFF_BANIM_SPELL_BG  = 0x2000,
    VRAMOFF_BANIM_SPELL_23E0 = 0x23E0,
    VRAMOFF_BANIM_5000 = 0x5000,
    VRAMOFF_BANIM_5800 = 0x5800,
    VRAMOFF_BANIM_6800 = 0x6800,
    VRAMOFF_BANIM_7000 = 0x7000,
    VRAMOFF_BANIM_8000 = 0x8000,

    VRAMOFF_OBJ_1400 = 0x1400,
    VRAMOFF_OBJ_2000 = 0x2000,
    VRAMOFF_OBJ_2800 = 0x2800,
    VRAMOFF_OBJ_EKRGAUGE_SUBFIX = 0x3800,
    VRAMOFF_OBJ_EKRGAUGE_NUM_L  = 0x3A00,
    VRAMOFF_OBJ_EKRGAUGE_ICON_L = 0x3B80,
    VRAMOFF_OBJ_EKRGAUGE_ICON_R = 0x3BC0,
    VRAMOFF_OBJ_EKRGAUGE_ARROW  = 0x3C00,
    VRAMOFF_OBJ_EKRGAUGE_NUM_R  = 0x3E00,
    VRAMOFF_OBJ_4000            = 0x4000,
    VRAMOFF_OBJ_5000            = 0x5000,
    VRAMOFF_OBJ_6000            = 0x6000,

    VRAMOFF_BG_EKRLVUP_FONT = 0x2400,
};

enum ekr_hit {
    EKR_HITTED = 0,
    EKR_MISS
};

enum banim_sprites_size {
    BAS_SCR_MAX_SIZE = 0x2A00,
    BAS_OAM_MAX_SIZE = 0x5800,
    BAS_IMG_MAX_SIZE = 0x1000,

    BAS_OAM_REF_MAX_SIZE = BAS_OAM_MAX_SIZE - 0x10,
};

extern EWRAM_OVERLAY(banim) u8 gBanimScrs[2 * BAS_SCR_MAX_SIZE];
extern EWRAM_OVERLAY(banim) u8 gBanimOamBufs[2 * BAS_OAM_MAX_SIZE];
extern EWRAM_OVERLAY(banim) u8 gBanimImgSheetBuf_Left[BAS_IMG_MAX_SIZE * 2];
extern EWRAM_OVERLAY(banim) u8 gBanimImgSheetBuf_Right[BAS_IMG_MAX_SIZE * 2];
extern EWRAM_OVERLAY(banim) u8 gBanimTerrainfxBufObj[0x2000];

struct ProcEfx {
    PROC_HEADER;

    /* 29 */ u8 hitted;
    /* 2A */ u8 type;
    /* 2B */ STRUCT_PAD(0x2B, 0x2C);
    /* 2C */ i16 timer;
    /* 2E */ i16 step;
    /* 30 */ i16 unk30;
    /* 32 */ u16 unk32;
    /* 34 */ STRUCT_PAD(0x34, 0x44);
    /* 44 */ u32 unk44;
    /* 48 */ u32 unk48;
    /* 4C */ u32 frame;
    /* 50 */ u32 speed;
    /* 54 */ i16 * unk54;
    /* 58 */ i16 ** unk58;
    /* 5C */ struct Anim *anim;
    /* 60 */ void *priv1, *priv2;
};

struct ProcEfx2 {
    PROC_HEADER;

    STRUCT_PAD(0x29, 0x2C);

    /* 2C */ s16 timer;
    /* 2E */ s16 terminator;

    STRUCT_PAD(0x30, 0x5C);

    /* 5C */ struct Anim *anim;
    /* 60 */ ProcPtr procfx;
};

struct ProcEfxBG {
    PROC_HEADER;

    /* 29 */ u8 unk29;
    STRUCT_PAD(0x2A, 0x2C);
    /* 2C */ i16 timer;
    /* 2E */ i16 terminator;
    /* 30 */ i16 unk30;
    /* 32 */ i16 unk32;
    /* 34 */ i16 unk34;
    /* 36 */ i16 unk36;
    /* 38 */ i16 unk38;
    /* 3A */ i16 unk3A;
    /* 3C */ i16 unk3C;
    STRUCT_PAD(0x3E, 0x44);
    /* 44 */ u32 frame;
    /* 48 */ const u16 * frame_config;
    /* 4C */ u16 ** tsal;
    /* 50 */ u16 ** tsar;
    /* 54 */ u16 ** img;
    /* 58 */ u16 ** pal;
    /* 5C */ struct  BaSprite *anim;
    /* 60 */ struct  BaSprite *sub_anim;
};

struct ProcEfxBGCOL {
    PROC_HEADER;

    STRUCT_PAD(0x29, 0x2C);
    /* 2C */ i16 timer;
    /* 2E */ i16 timer2;
    /* 30 */ i16 terminator;
    /* 32 */ i16 unk32;
    STRUCT_PAD(0x34, 0x44);
    /* 44 */ u32 frame;
    /* 48 */ const u16 * frame_config;
    /* 4C */ const u16 * pal;
    STRUCT_PAD(0x50, 0x5C);
    /* 5C */ struct  BaSprite *anim;
};

struct ProcEfxRST
{
    PROC_HEADER;

    STRUCT_PAD(0x29, 0x2C);
    /* 2C */ i16 timer;
    /* 2E */ i16 duration;
    /* 30 */ i16 unk30;
    STRUCT_PAD(0x32, 0x5C);
    /* 5C */ struct  BaSprite *anim;
    STRUCT_PAD(0x60, 0x64);
    /* 64 */ ProcPtr efxproc;
};

struct ProcEfxOBJ {
    PROC_HEADER;

    /* 29 */ u8 unk29;
    /* 2A */ u8 unk2A;
    STRUCT_PAD(0x2B, 0x2C);
    /* 2C */ i16 timer;
    /* 2E */ i16 terminator;
    /* 30 */ u16 unk30;
    /* 32 */ u16 unk32;
    /* 34 */ u16 unk34;
    /* 36 */ u16 unk36;
    /* 38 */ u16 unk38;
    /* 3A */ u16 unk3A;
    /* 3C */ u16 unk3C;
    /* 3E */ u16 unk3E;
    /* 40 */ u16 unk40;
    /* 42 */ u16 unk42;
    /* 44 */ int unk44;
    /* 48 */ int unk48;
    /* 4C */ int unk4C;
    STRUCT_PAD(0x50, 0x5C);
    /* 5C */ struct  BaSprite *anim;
    /* 60 */ struct  BaSprite *anim2;
    /* 64 */ struct  BaSprite *anim3;
    /* 68 */ struct  BaSprite *anim4;
};

extern EWRAM_OVERLAY(banim) void *gpBanimTerrainfxBufs[2];
extern EWRAM_OVERLAY(banim) void *gpBanimTerrainTsaBufs[2];
extern EWRAM_OVERLAY(banim) u16 *gpBanimTerrainPalBufs[2];
extern EWRAM_OVERLAY(banim) int *gpBanimModesLeft;
extern EWRAM_OVERLAY(banim) int *gpBanimModesRight;

extern EWRAM_OVERLAY(banim) int gEkrDebugTimer;
extern EWRAM_OVERLAY(banim) int gEkrDebugFlag1;
extern EWRAM_OVERLAY(banim) int gEkrDebugFlag2;
extern EWRAM_OVERLAY(banim) int gAnimC01Blocking;
extern EWRAM_OVERLAY(banim) i16 gEkrXPosReal[2];
extern EWRAM_OVERLAY(banim) i16 gEkrYPosReal[2];
extern EWRAM_OVERLAY(banim) u16 gEkrXPosBase[2];
extern EWRAM_OVERLAY(banim) u16 gEkrYPosBase[2];
extern EWRAM_OVERLAY(banim) struct Vec2i gEkrBg0QuakeVec;
extern EWRAM_OVERLAY(banim) u16 *gpEfxUnitPaletteBackup[2];
extern i16 gEkrDebugModeMaybe;
extern EWRAM_OVERLAY(banim) u16 gBanimPaletteLeft[0x50];
extern EWRAM_OVERLAY(banim) u16 gBanimPaletteRight[0x50];
extern EWRAM_OVERLAY(banim) u16 gEfxPal[0x200];
extern EWRAM_OVERLAY(banim) struct Font gBanimFont;
extern EWRAM_OVERLAY(banim) struct Text gBanimText[20];
extern EWRAM_OVERLAY(banim) u32 gEkrBattleEndFlag;
extern i8 gEfxSplitedColorBufA[2][0x30];
extern i8 gEfxSplitedColorBufB[2][0x30];
extern i16 gEfxSplitedColorBufC[2][0x30];
extern int gProcEkrBaseAppearExist;
extern u32 gUnk_Banim_0201E0F8;
extern u32 gBanimDoneFlag[2];
extern ProcPtr gpProcEfxAnimeDrv;
extern const void * gpImgSheet[2];
extern ProcPtr gpProcEkrTogiColor;
extern int gEkrBg2ScrollFlip;
extern u16 * gpBg2ScrollOffsetStart;
extern u16 * gpBg2ScrollOffset;
extern u16 gpBg2ScrollOffsetTable1[];
extern u16 gpBg2ScrollOffsetTable2[];
extern int gEkrBg1ScrollFlip;
extern u16 * gpBg1ScrollOffsetStart;
extern u16 * gpBg1ScrollOffset;
extern u16 gpBg1ScrollOffsetList1[0xA0];
extern u16 gpBg1ScrollOffsetList2[0xA0];
extern u16 gpBg1ScrollOffsetList3_unused[0xA0];
extern int gEfxMagicChk_N;
extern int gEfxPurgeCounter;
extern u8 gEkrPids[2];
extern struct Unit * gpEkrTriangleUnits[2];
extern const u16 * gpBanimTriAtkPalettes[2];
extern const u8 * gBanimBallistaImages[2];
extern EWRAM_OVERLAY(banim) i16 gBanimBG;
extern EWRAM_OVERLAY(banim) i16 gEkrInitialHitSide;
extern EWRAM_OVERLAY(banim) i16 gEkrSnowWeather;
extern u32 gEkrInitPosReal;
extern u32 gEfxFarAttackExist;
extern u32 gEfxBgSemaphore;
extern u32 gEfxHpBarResireFlag;
extern u32 gUnk_Banim_0201774C;
extern u32 gEfxTeonoState;
extern u32 gEfxTerrainLayerLow;
extern struct Vec2i gEkrBg2QuakeVec;
extern i16 gUnk_Banim_0201775C[2];
extern u32 gEkrBgPosition;
extern i16 gBanimEffectiveness[2];
extern i16 gBanimUniquePaletteDisabled[2];
extern EWRAM_DATA i16 gBanimValid[2];
extern EWRAM_DATA i16 gBanimPosIsTarget[2];
extern EWRAM_DATA i16 gBanimIdx_bak[2];
extern EWRAM_DATA i16 gBanimUniquePal[2];
extern EWRAM_DATA i16 gBanimFactionPal[2];
extern EWRAM_DATA i16 gEkrSpellAnimIndex[2];
extern EWRAM_DATA i16 gBanimFloorfx[2];
extern i16 gBanimExpGain[2];
extern i16 gBanimTerrain[2];
extern i16 gBanimCon[2];
extern i16 gBanimWtaBonus[2];
extern i16 gEkrGaugeHp[2];
extern i16 gBanimMaxHP[2];
extern i16 gEkrGaugeHpBak[2];
extern i16 gEkrGaugeHit[2];
extern i16 gEkrGaugeDmg[2];
extern i16 gEkrGaugeCrt[2];
extern i16 gEkrBmLocation[4];
extern i16 gAnimRoundData[20];
extern i16 gEfxHpLutOff[2];
extern u16 gEfxHpLut[22];
extern i16 gBanimIdx[2];
extern struct BattleUnit * gpEkrBattleUnitLeft;
extern struct BattleUnit * gpEkrBattleUnitRight;
extern u32 gEkrHpBarCount;
extern u32 gEfxSpellAnimExists;
extern u32 gUnk_Banim_02017728;
extern u32 gEkrDeadExist;
extern u32 gEkrDeadEventExist;
extern u32 gEfxQuakeExist;
extern u32 gEfxHitQuakeExist;
extern i16 gEkrHitNow[2];
extern u8 gSpellAnimBgfx[0x1D00];
extern u16 gEkrBarfxBuf[0x300 / 2];
extern u16 gEkrTsaBuffer[0x1000 / 2];
extern u8 gBuf_Banim[0x2000];
extern u16 gPal_Banim[0xA0];
extern u16 gTmA_Banim[0xB58 / sizeof(u16)];
extern u16 gTmB_Banim[0xB58 / sizeof(u16)];
extern i16 gBanimExpPrevious[2];

void NewEkrLvlupFan(void);
void EkrLvupFanMain(struct ProcEfx *proc);
// func_fe6_080435EC

struct ProcEkrGauge {
    PROC_HEADER;

    /* 29 */ u8 battle_init;           /* 1 in battle-starting and 0 after battle started */
    /* 2A */ u8 valid;
    /* 2B */ u8 _pad_2B[0x32 - 0x2B];
    /* 32 */ i16 unk32;
    /* 34 */ u8 _pad_34[0x3A - 0x34];
    /* 3A */ i16 unk3A;
    /* 3C */ u8 _pad_3C[0x44 - 0x3C];
    /* 44 */ int unk44;
    /* 48 */ int unk48;
    /* 4C */ int unk4C;
    /* 50 */ int unk50;
    /* 54 */
};

extern struct ProcEkrGauge * gpProcEkrGauge;
extern EWRAM_OVERLAY(banim) u16 Buf_EkrGaugeNumImg[0x200];
extern EWRAM_OVERLAY(banim) u16 gEkrGaugeHpNumImgBuf[0x40];
extern EWRAM_OVERLAY(banim) u8 gEkrGaugeBuf[0x800];
extern EWRAM_OVERLAY(banim) u16 gEkrGaugeDecoder[18];

void EkrGaugeModDec(i16 val, u16 buf[]);
void NewEkrGauge(void);
void EndEkrGauge(void);
void EkrGauge_Clr4C50(void);
void EkrGauge_Set4C50(void);
void EkrGauge_Set4C(void);
void EkrGauge_Set50(void);
void EkrGauge_Setup44(u16 val);
void EkrGauge_Clr323A(i16 x, i16 y);
void EkrGauge_Setxy323A(i16 x, i16 y);
void EkrGauge_SetInitFlag(void);
void EkrGauge_ClrInitFlag(void);
void EnableEkrGauge(void);
void DisableEkrGauge(void);
void func_fe6_08043980(struct Anim * anim, int a, int b);
void EkrGauge_Loop(struct ProcEkrGauge *proc);

struct ProcEkrDispUP {
    PROC_HEADER;

    /* 29 */ u8 sync;
    /* 2A */ u8 asnyc;

    STRUCT_PAD(0x2B, 0x32);

    /* 32 */ u16 x; /* unused actually */

    STRUCT_PAD(0x34, 0x3A);

    /* 3A */ u16 y;

    STRUCT_PAD(0x3C, 0x4C);

    /* 4C */ u32 unk4C;
    /* 50 */ u32 unk50;
};

#define gBg0Tm2D ((u16 (*)[1])gBg0Tm)

void NewEkrDispUP(void);
void EndEkrDispUP(void);
void EkrDispUpClear4C50(void);
void EkrDispUpSet4C50(void);
void EkrDispUpSet4C(void);
void EkrDispUpSet50(void);
void EkrDispUP_SetPositionUnsync(u16 x, u16 y);
void EkrDispUP_SetPositionSync(u16 x, u16 y);
void SyncEkrDispUP(void);
void UnsyncEkrDispUP(void);
void AsyncEkrDispUP(void);
void UnAsyncEkrDispUP(void);
void EkrDispUP_Loop(struct ProcEkrDispUP *proc);

void EfxClearScreenFx(void);
void EkrDispUp_PutTerrainfx(void);
void EfxPrepareScreenFx(void);
int GetBanimInitPosReal(void);
void EkrEfxStatusClear(void);

struct ProcEfxHpBar {
    PROC_HEADER;

    /* 29 */ u8 death;
    STRUCT_PAD(0x2A, 0x2C);
    /* 2C */ i16 timer;
    /* 2E */ i16 cur;
    STRUCT_PAD(0x30, 0x48);
    /* 48 */ int diff;
    /* 4C */ int this;
    /* 50 */ int next;
    /* 54 */ u32 timer2;
    /* 58 */ int finished;
    /* 5C */ struct BaSprite *anim_main_other;
    /* 60 */ struct BaSprite *anim_main_this;
    /* 64 */ struct BaSprite *anim_this;
};

int CheckEkrHitDone(void);
i16 CheckEkrHitNow(int pos);
void NewEfxHpBar(struct BaSprite *anim);
void EfxHpBar_DeclineToDeath(struct ProcEfxHpBar *proc);
void EfxHpBar_MoveCameraOnEnd(struct ProcEfxHpBar *proc);
void EfxHpBar_WaitCameraMove(struct ProcEfxHpBar *proc);
void NewEfxHpBarResire(struct BaSprite *anim);
void EfxHpBarResire_WaitOnCurrentSide(struct ProcEfxHpBar *proc);
void EfxHpBarResire_SetAnotherSide(struct ProcEfxHpBar *proc);
void EfxHpBarResire_DeclineToDeath(struct ProcEfxHpBar *proc);
void NewEfxAvoid(struct BaSprite *anim);
void EfxAvoid_Loop(struct ProcEfxHpBar *proc);
void NewEfxHpBarLive(struct BaSprite *anim);
void EfxHpBarLive_Loop(struct ProcEfxHpBar *proc);
void NewEfxNoDamage(struct BaSprite *anim1, struct BaSprite *anim2, int death);
void EfxNoDmage_Loop(struct ProcEfxHpBar *proc);
void NewEfxNoDamageYure(struct BaSprite *anim1, struct BaSprite *anim2);
void EfxNoDamageYure_Loop(struct ProcEfxHpBar *proc);
void NewEfxStatusCHG(struct BaSprite *anim);
void EfxStatusCHG_Loop(struct ProcEfxHpBar *proc);

struct ProcEfxDead {
    PROC_HEADER;

    STRUCT_PAD(0x29, 0x2C);
    /* 2C */ i16 timer, terminator;
    STRUCT_PAD(0x30, 0x5C);
    /* 5C */ struct BaSprite *anim1, *anim2;
    /* 64 */ ProcPtr subproc;
};

void NewEfxDeadEvent(struct BaSprite *anim1, struct BaSprite *anim2);
void EfxDeathEvent_Init(struct ProcEfxDead *proc);
void EfxDeathEvent_RemoveUI(struct ProcEfxDead *proc);
void EfxDeathEvent_CallEvent(struct ProcEfxDead *proc);
void EfxDeathEvent_WaitEvent(struct ProcEfxDead *proc);
void EfxDeathEvent_End(struct ProcEfxDead *proc);
void NewEfxDead(struct BaSprite *anim1, struct BaSprite *anim2);
void EfxDead_StartPika(struct ProcEfxDead *proc);
void EfxDead_StartAlpha(struct ProcEfxDead *proc);
void NewEfxDeadPika(struct BaSprite *anim1, struct BaSprite *anim2);
void EfxDeadPika_Loop(struct ProcEfxDead *proc);
void NewEfxDeadAlpha(struct BaSprite *anim1, struct BaSprite *anim2);
void EfxDeadAlpha_Loop(struct ProcEfxDead *proc);
void NewEfxDeadDragonAlpha(struct BaSprite *anim1, struct BaSprite *anim2);
void EfxDeadDragonAlpha_Loop(struct ProcEfxDead *proc);

struct ProcEfxFarAttack
{
    /* 00 */ PROC_HEADER;
    /* 29 */ u8 pos;
    /* 2A */ u16 unk_2a;
    /* 2C */ i16 timer;
    /* 2E */ i16 unk_2e;
    /* 30 */ i16 terminator;
    /* 32 */ i16 unk_32;
    /* 34 */ i16 unk_34;
    /* 36 */ i16 unk_36;
    /* 38 */ i16 unk_38;
};

void NewEfxFarAttackWithDistance(struct Anim *anim, i16);
void func_fe6_08045D6C(struct ProcEfxFarAttack * unused, int x);
void func_fe6_08045DA4(struct ProcEfxFarAttack *proc);
void func_fe6_08045DDC(struct ProcEfxFarAttack *proc);
void func_fe6_08045E50(struct ProcEfxFarAttack *proc);
void BanimSetBg2Position(int);

struct ProcEfxQuake {
    /* 00 */ PROC_HEADER;

    /* 29 */ u8 quake_ui;
    /* 2A */ u8 kind;
    /* 2C */ i16 timer;
    /* 30 */ int unk_30;
    /* 34 */ i16 ix;
    /* 36 */ i16 unk_36;
    /* 38 */ i16 unk_38;
    /* 3A */ i16 unk_3a;
    /* 3C */ i16 iy;
    /* 3E */ i16 unk_3e;
    /* 40 */ int unk_40;
    /* 44 */ const i16 * vec;
    /* 48 */ int unk_48;
    STRUCT_PAD(0x4C, 0x5C);
    /* 5C */ struct Anim *anim_l;
    /* 60 */ struct Anim *anim_r;
    /* 64 */ struct Anim *unk_64;
};

#define SetEkrBg2QuakeVec(_x, _y) \
    gEkrBg2QuakeVec.x = (_x);     \
    gEkrBg2QuakeVec.y = (_y);

ProcPtr NewEfxQuakePure(int type, int stopped);
void EfxQuakePure_Loop(struct ProcEfxQuake *proc);
ProcPtr NewEfxHitQuakePure(void);
void EfxHitQuakePure_Loop(struct ProcEfxQuake *proc);
ProcPtr NewEfxQuake(int type);
void EfxQuake_Loop(struct ProcEfxQuake *proc);
void NewEfxHitQuake(struct Anim *anim1, struct Anim *anim2, int kind);
void EfxHitQuake_Loop(struct ProcEfxQuake *proc);

struct ProcEfxFlashing {
    PROC_HEADER;

    /* 29 */ u8 flag;

    STRUCT_PAD(0x2A, 0x2C);

    /* 2C */ i16 timer;
    /* 2E */ i16 terminator;
    /* 30 */ i16 terminator2;

    STRUCT_PAD(0x32, 0x5C);

    /* 5C */ struct Anim *anim;
};

struct ProcEfxApocalypseDummy {
    PROC_HEADER;

    STRUCT_PAD(0x29, 0x2C);
    /* 2C */ i16 timer;
    /* 2E */ i16 duration;
    STRUCT_PAD(0x30, 0x5C);
    /* 5C */ struct BaSprite *anim;
    STRUCT_PAD(0x60, 0x64);
    /* 64 */ ProcPtr efxproc;
};

void NewEfxFlashBgWhite(struct Anim *anim, int duartion);
void NewEfxFlashBgRed(struct Anim *anim, int duartion);
void EfxFlashBg_Loop(struct ProcEfxFlashing *proc);
void EfxFlashRestorePalSync(struct ProcEfxFlashing *proc);
void NewEfxWhiteIN(struct Anim *anim, int duartion, int duartion2);
void EfxWhiteIn_Loop1(struct ProcEfxFlashing *proc);
void EfxWhiteIn_Loop2(struct ProcEfxFlashing *proc);
void EfxBlackInRestorePalSync(struct ProcEfxFlashing *proc);

void NewEfxFlashHpBar(struct Anim *anim, int duartion, int duartion2);
void EfxFlashHpBar_Pause(struct ProcEfxFlashing *proc);
void EfxFlashHpBar_Loop(struct ProcEfxFlashing *proc);
void EfxFlashHpBar_RestorePal(struct ProcEfxFlashing *proc);

struct ProcEfxHpBarColorChange {
    PROC_HEADER;

    STRUCT_PAD(0x2A, 0x2C);

    /* 2C */ i16 timer;

    STRUCT_PAD(0x2E, 0x44);

    /* 44 */ u32 frame;
    /* 48 */ const u16 * frame_conf;
    /* 4C */ u32 frame_state;
    /* 50 */ int disabled;

    STRUCT_PAD(0x54, 0x5C);

    /* 5C */ struct Anim *anim;
};

extern struct ProcEfxHpBarColorChange * gpProcEfxHpBarColorChange;

void NewEfxHpBarColorChange(struct Anim *anim);
void EndEfxHPBarColorChange(void);
void DisableEfxHpBarColorChange(void);
void EnableEfxHpBarColorChange(void);
void EfxHpBarColorChange_Loop(struct ProcEfxHpBarColorChange *proc);

void NewEfxFlashUnit(struct Anim *anim, u16 dura1, u16 dura2, int c);
void EfxFlashUnit_Loop(struct ProcEfxFlashing *proc);
void EfxFlashUnit_RestorePal(struct ProcEfxFlashing *proc);

struct ProcEfxStatusUnit {
    PROC_HEADER;
    /* 29 */ u8 invalid;

    STRUCT_PAD(0x2A, 0x2C);

    /* 2C */ u16 timer;

    STRUCT_PAD(0x2E, 0x32);

    /* 32 */ i16 red, green, blue;

    STRUCT_PAD(0x38, 0x44);

    /* 44 */ u32 frame;
    /* 48 */ const u16 * frame_lut;
    /* 4C */ int debuff, debuf_bak;

    STRUCT_PAD(0x54, 0x5C);

    /* 5C */ struct Anim *anim;
};

extern struct ProcEfxStatusUnit * gpProcEfxStatusUnits[2];

void NewEfxStatusUnit(struct Anim *anim);
void EndEfxStatusUnits(struct Anim *anim);
void DisableEfxStatusUnits(struct Anim *anim);
void EnableEfxStatusUnits(struct Anim *anim);
void SetUnitEfxDebuff(struct Anim *anim, int debuff);
u32 GetUnitEfxDebuff(struct Anim *anim);
void EfxStatusUnitFlashing(struct Anim *anim, int r, int g, int b);
void EfxStatusUnit_Loop(struct ProcEfxStatusUnit *proc);
void EfxStatusUnit_End(struct ProcEfxStatusUnit *proc);

struct ProcEfxWeaponIcon {
    PROC_HEADER;

    STRUCT_PAD(0x29, 0x2C);

    /* 2C */ i16 timer;

    STRUCT_PAD(0x2E, 0x44);

    /* 44 */ u32 frame;
    /* 48 */ const u16 * frame_lut;
    /* 4C */ u32 frame_state;
    /* 50 */ u32 invalid;
    /* 54 */ int eff1, eff2;
};

extern struct ProcEfxWeaponIcon * gpProcEfxWeaponIcon;

void NewEfxWeaponIcon(i16 eff1, i16 eff2);
void EndProcEfxWeaponIcon(void);
void DisableEfxWeaponIcon(void);
void EnableEfxWeaponIcon(void);
void EfxWeaponIcon_Loop(struct ProcEfxWeaponIcon *proc);
void EfxWeaponIcon_End(struct ProcEfxWeaponIcon *proc);

struct ProcEfxSpellCast {
    PROC_HEADER;

    /* 29 */ u8 done;

    STRUCT_PAD(0x2A, 0x2C);

    /* 2C */ i16 timer;
    /* 2E */ i16 terminator;
};

extern struct ProcEfxSpellCast * gpProcEfxSpellCast;

void NewEfxSpellCast(void);
void UnsyncEkrDispUP(void);
void EndEfxSpellCastAsync(void);
void EndEfxSpellCastSync(void);
void EfxSpellCast_FlashIN(struct ProcEfxSpellCast *proc);
void EfxSpellCast_Pause(struct ProcEfxSpellCast *proc);
void EfxSpellCast_FlashOUT(struct ProcEfxSpellCast *proc);

void SpellFx_Begin(void);
void SpellFx_Finish(void);
void SpellFx_ClearBG1Position(void);
void SpellFx_ClearBG1(void);
void SpellFx_SetSomeColorEffect(void);
void SpellFx_ClearColorEffects(void);
void StartBattleAnimHitEffectsDefault(struct Anim *anim, int type);
void StartBattleAnimHitEffectsAlt(struct Anim *anim, int type);
void StartBattleAnimHitEffects(struct Anim *anim, int type, int quake_normal, int quake_crit);
void StartBattleAnimResireHitEffects(struct Anim *anim, int type);
void StartBattleAnimStatusChgHitEffects(struct Anim *anim, int type);
struct Anim * EfxCreateFrontAnim(struct Anim *anim, const AnimScr * scr1, const AnimScr * scr2, const AnimScr * scr3, const AnimScr * scr4);
void SpellFx_WriteBgMapUncomp(struct Anim *anim, const u16 * src1, const u16 * src2);
void SpellFx_WriteBgMap(struct Anim *anim, const u16 * src1, const u16 * src2);
void SpellFx_WriteBgMapExt(struct Anim *anim, const u16 * src, int width, int height);
void SpellFx_RegisterObjGfx(const void * img, u32 size);
void SpellFx_RegisterObjPal(const u16 * pal, u32 size);
void SpellFx_RegisterBgGfx(const void * img, u32 size);
void SpellFx_RegisterBgPal(const u16 * pal, u32 size);
void func_fe6_08047B10(const u16 * src, u16 * dst, u32 cur, u32 len_src, u32 len_dst);
void func_fe6_08047B3C(const u16 * src, u16 * dst, u32 cur, u32 len_src, u32 len_dst);
void func_fe6_08047B6C(const u16 * src, u16 * dst, u32 a, u32 b, u32 c);
i16 EfxAdvanceFrameLut(i16 * ptime, i16 * pcount, const i16 lut[]);
void PutEfxTerrainToLowerLayer(void);
int EfxGetCamMovDuration(void);
void EfxTmFillA(u32 val);
void EfxTmFillB(u32 val);
void SetEkrFrontAnimPostion(int pos, i16 x, i16 y);
bool SetupBanim(void);
void BeginAnimsOnBattleAnimations(void);
void EkrMainEndExec(void);
void OnMainBas(void);

struct ProcEkrBattleIntro {
    PROC_HEADER;

    STRUCT_PAD(0x29, 0x2C);

    /* 2C */ i16 timer, terminator;

    STRUCT_PAD(0x30, 0x32);

    /* 32 */ i16 x1, x2;

    STRUCT_PAD(0x36, 0x3A);

    /* 3A */ i16 y1, y2;
};

#define ProcEkrBattleStarting ProcEkrBattleIntro
#define ProcEkrBattleEnding   ProcEkrBattleIntro

void NewEkrBattleStarting(void);
void EkrBaStart_InitScreen(struct ProcEkrBattleStarting *proc);
void EkrBaStart_SreenFailIn(struct ProcEkrBattleStarting *proc);
void EkrBaStart_InitBattleScreen(struct ProcEkrBattleStarting *proc);
void EkrBaStart_ExecEkrBattle(struct ProcEkrBattleStarting *proc);
void EkrBaStart_BgFadeOut(struct ProcEkrBattleStarting *proc);
void EkrBaStart_MergeBG(struct ProcEkrBattleStarting *proc);
void EkrBaStart_BgPaletteIn(struct ProcEkrBattleStarting *proc);

void NewEkrbattleending(void);
void EkrBaEnd_BgPaletteIn(struct ProcEkrBattleEnding *proc);
void EkrBaEnd_RestoreChapterMap(struct ProcEkrBattleEnding *proc);
void EkrBaEnd_ChapterMapFadeOut(struct ProcEkrBattleEnding *proc);
void EkrBaEnd_InitOutroFx(struct ProcEkrBattleEnding *proc);
void EkrBaEnd_WaitOutroAndEndGauge(struct ProcEkrBattleEnding *proc);
void EkrBaEnd_RestoreMapDisplay(struct ProcEkrBattleEnding *proc);
void EkrBaEnd_ScreenFailOut(struct ProcEkrBattleEnding *proc);
void EkrBaEnd_Finish(struct ProcEkrBattleEnding *proc);

struct ProcEkrBaseKaiten {
    PROC_HEADER;

    /* 29 */ u8 unk29;
    /* 2A */ u16 unk2A;
    /* 2C */ s16 timer;
    /* 2E */ s16 terminator;
    /* 30 */ u16 unk30;

    /* 32 */ s16 x1;
    /* 34 */ s16 x2;
    /* 36 */ s16 unk36;

    /* 38 */ STRUCT_PAD(0x38, 0x3A);

    /* 3A */ s16 y1;
    /* 3C */ s16 y2;
    /* 3E */ s16 unk3E;

    /* 40 */ STRUCT_PAD(0x40, 0x44);

    /* 44 */ int type;

    /* 48 */ STRUCT_PAD(0x48, 0x5C);

    /* 5C */ struct Anim *anim;
    /* 60 */ const u16 *unk60;
};

void NewEkrBaseKaiten(int identifier);
void EkrBaseKaiten_Loop(struct ProcEkrBaseKaiten *proc);

struct ProcEkrUnitKakudai {
    PROC_HEADER;

    STRUCT_PAD(0x29, 0x2C);

    /* 2C */ s16 timer;
    /* 2E */ s16 terminator;
    /* 30 */ u16 unk30;

    /* 32 */ s16 x1;
    /* 34 */ s16 x2;
    /* 36 */ s16 left_pos;
    /* 38 */ s16 right_pos;
    /* 3A */ s16 y1;
    /* 3C */ s16 y2;

    STRUCT_PAD(0x3E, 0x44);

    /* 44 */ int type;

    STRUCT_PAD(0x48, 0x4C);

    /* 4C */ u32 valid_l;
    /* 50 */ u32 valid_r;
    /* 54 */ void *pOaml;
    /* 58 */ void *pOamr;
};

void NewEkrUnitKakudai(int identifier);
void EkrUnitKakudai_PrepareAnimScript(struct ProcEkrUnitKakudai *proc);
void EkrUnitKakudai_Main(struct ProcEkrUnitKakudai *proc);
void EkrUnitKakudai_End(struct ProcEkrUnitKakudai *proc);

struct ProcEkrIntroWindow {
    PROC_HEADER;

    STRUCT_PAD(0x29, 0x2C);

    /* 2C */ i16 timer, terminator, ymax;

    STRUCT_PAD(0x32, 0x44);

    /* 44 */ int type;
    /* 48 */ int ymax_name;
};

extern EWRAM_OVERLAY(banim) int gEkrWindowAppearUnexist;

void NewEkrWindowAppear(int identifier, int duration);
bool CheckEkrWindowAppearUnexist(void);
void EkrWindowAppear_Main(struct ProcEkrIntroWindow *proc);

extern EWRAM_OVERLAY(banim) int gEkrNameWinAppearExist;

void NewEkrNamewinAppear(int identifier, int duration, int delay);
bool CheckEkrNamewinAppearUnexist(void);
void EkrNamewinAppear_Delay(struct ProcEkrIntroWindow *proc);
void EkrNamewinAppear_Main(struct ProcEkrIntroWindow *proc);
void NewEkrBaseAppear(int identifier, int duration);
bool CheckEkrBaseAppearUnexist(void);
void EkrBaseAppear_Loop(struct ProcEkrIntroWindow *proc);
bool _SetupBanim(void);

enum banim_terrain_set_type {
    BANIM_TERRAIN_SET_0,
    BANIM_TERRAIN_SET_1,
    BANIM_TERRAIN_SET_2,
    BANIM_TERRAIN_SET_3,
    BANIM_TERRAIN_SET_4,
    BANIM_TERRAIN_SET_5,
    BANIM_TERRAIN_SET_6,
    BANIM_TERRAIN_SET_7,
    BANIM_TERRAIN_SET_8,
    BANIM_TERRAIN_SET_9
};

u16 GetBattleAnimationId(const struct BanimInfoEnt *animdef, u16 item);
int GetBanimTerrainGround(u16 terrain, u16 tileset);
int GetBanimBackgroundIndex(u16 terrain, u16 tileset);
i16 GetSpellAnimId(u16 jid, u16 weapon);
void UnsetMapStaffAnim(i16 * out, u16 pos, u16 weapon);
void ParseBattleHitToBanimCmd(void);
bool CheckBattleHasHit(void);
int GetBanimUniquePal(struct Unit * unit);
const u16 * GetBanimTriangleAttackPalette(i16 bid, u16 item);

enum banim_faction_palette_idx {
    BANIMPAL_BLUE = 0,
    BANIMPAL_RED = 1,
    BANIMPAL_GREEN = 2,
    BANIMPAL_PURPLE = 3,
};

int GetBanimFactionPalette(u32 faction);

void EkrPrepareBanimfx(struct Anim *anim, i16);

enum anim_round_type {
    ANIM_ROUND_BIT8 = 0x0100,
    ANIM_ROUND_PIERCE = 0x0200,
    ANIM_ROUND_GREAT_SHIELD = 0x0400,
    ANIM_ROUND_SURE_SHOT = 0x0800,
    ANIM_ROUND_SILENCER = 0x1000,
    ANIM_ROUND_POISON = 0x2000,
    ANIM_ROUND_BIT14 = 0x4000,
    ANIM_ROUND_DEVIL = 0x8000,
};

i16 GetBattleAnimRoundType(int index);
i16 func_fe6_0804A57C(int);

#define GetRoundFlagByAnim(aAnim) (func_fe6_0804A57C((aAnim->nextRoundId - 1) * 2 + GetAnimPosition(aAnim)))

i16 GetEfxHp(int index);
// func_fe6_0804A5C0
void BattleAIS_ExecCommands(void);
void NewEkrChienCHR(struct Anim *anim);
void EkrChienCHR_Loop(struct ProcEfx *proc);
void SyncBanimImage(struct Anim *anim);
void ApplyBanimUniquePalette(u32 *buf, int pos);
int GetBanimPalette(int banim_id, int pos);
void UpdateBanimFrame(void);
void InitMainAnims(void);
void InitBattleAnimFrame(int round_type_left, int round_type_right);
void InitLeftAnim(int round_type);
void InitRightAnim(int round_type);
void LoadAnimFrame(struct Anim *anim, int type);
int GetAnimLayer(struct Anim *anim);
int GetAnimPosition(struct Anim *anim);
int CheckRoundMiss(i16 type);
int CheckRound1(i16 type);
int CheckRound2(i16 type);
int CheckRoundCrit(struct Anim *anim);
struct Anim * GetAnimAnotherSide(struct Anim *anim);
i16 GetAnimRoundType(struct Anim *anim);
i16 GetAnimNextRoundType(struct Anim *anim);
i16 GetAnimRoundTypeAnotherSide(struct Anim *anim);
i16 GetAnimNextRoundTypeAnotherSide(struct Anim *anim);
void SetAnimStateHidden(int pos);
void SetAnimStateUnHidden(int pos);

/**
 * ekrmainmini
 */
struct EkrMainMiniDesc {
    /* 00 */ u8 valid;
    /* 01 */ u8 faction_pal;
    /* 02 */ u16 x, y;
    /* 06 */ u16 bid;

    // i16 chara_pal;

    /* 08 */ u16 round_type;
    /* 0A */ u16 pos;
    /* 0C */ u16 oam2_chr;
    /* 0E */ u16 oam2_pal;
    /* 10 */ struct Anim *anim1, *anim2;
    /* 18 */ u16 *img_buf;
    /* 1C */ u16 *pal_buf;
    /* 20 */ u16 *oam_buf;
    /* 24 */ u8  *scr_buf;
    /* 28 */ const u16 *img_sheet;
    /* 2C */ void *magicfx_desc;
    /* 30 */ ProcPtr proc;
};

void EkrMainMini_ExecCommands(struct EkrMainMiniDesc *desc, struct Anim *anim);
void EkrMainMini_C01_Blocking(struct Anim *anim);
void EkrMainMini_C0D_ExecNextRoundAfterAttack(struct Anim *anim);
void EkrMainMini_InitAnim(struct EkrMainMiniDesc *desc);
void EkrMainMini_UpdateAnim(struct EkrMainMiniDesc *desc);
void EkrMainMini_ChangeAnim(struct EkrMainMiniDesc *desc, int bid);
void EkrMainMini_SetAnimPosition(struct EkrMainMiniDesc *desc, u16 x, u16 y);
void EkrMainMini_SetAnimLayer(struct EkrMainMiniDesc *desc, u16 layer);
bool EkrMainMini_CheckBlocking(struct EkrMainMiniDesc *desc);
void EkrMainMini_EndBlock(struct EkrMainMiniDesc *desc);
bool EkrMainMini_CheckDone(struct EkrMainMiniDesc *desc);
void NewEfxAnimeDrvProc(void);
void EndEfxAnimeDrvProc(void);
void EkrAnimeDrv_Loop(void);

struct ProcEkrUnitMainMini {
    PROC_HEADER;

    STRUCT_PAD(0x29, 0x5C);

    struct EkrMainMiniDesc *desc;
};

void NewEkrUnitMainMini(struct EkrMainMiniDesc *desc);
void EndEkrMainMini(struct EkrMainMiniDesc *desc);
void EkrMainMini_Loop(struct ProcEkrUnitMainMini *proc);

/**
 * EkrTerrainfx
 */
struct EkrTerrainfxDesc {
    /* 00 */ i16 terrain_l;
    /* 02 */ i16 pal_l;
    /* 04 */ i16 chr_l;
    /* 06 */ i16 terrain_r;
    /* 0A */ i16 pal_r;
    /* 08 */ i16 chr_r;
    /* 0C */ i16 distance;
    /* 0E */ i16 bg_index;

    /* 10 */ u16 unk_10;

    /* 14 */ struct ProcEkrSubAnimeEmulator *proc1;
    /* 18 */ struct ProcEkrSubAnimeEmulator *proc2;
    /* 1C */ int vram_offset;
    /* 20 */ u8 *img_buf;

    /* 24 */ int _pad_24;
};

extern struct EkrTerrainfxDesc gEkrTerrainfxDesc, gEkrLvupTerrainfxDesc;

void NewEkrTerrainfx(struct EkrTerrainfxDesc *desc); // FE8: sub_805AA68
void EndEkrTerrainfx(struct EkrTerrainfxDesc *desc);
void EkrTerrainfx_SetPosition(struct EkrTerrainfxDesc *desc, i16 x1, i16 y1, i16 x2, i16 y2);
void EkrTerrainfx_PutTiles(struct EkrTerrainfxDesc *desc);
void BanimCopyBgTM(i16 distance, i16 pos);

/**
 * EkrArena
 */
void SetBanimArenaFlag(int flag);
int GetBattleAnimArenaFlag(void);
void EkrArena_ChangeBg3Offset(int x);
void PlayDeathSoundForArena(void);
void StopArenaBgmWhenSpeedUp(void);
void BeginAnimsOnBattle_Arena(void);
void ExecBattleAnimArenaExit(void);
void NewEkrTogiInitPROC(void);
void EkrTogiInit_Init(struct ProcEfxBG *proc);
void EkrTogiInit_LoadGfx(struct ProcEfxBG *proc);
void EkrTogiInit_Loop(struct ProcEfxBG *proc);
void EkrTogiInit_End(struct ProcEfxBG *proc);
void NewEkrTogiEndPROC(void);
void EkrTogiEnd_Init(struct ProcEfxBG *proc);
void EkrTogiEnd_Loop(struct ProcEfxBG *proc);
void EkrTogiEnd_End(struct ProcEfxBG *proc);

struct ProcEkrTogiColor {
    PROC_HEADER;

    STRUCT_PAD(0x29, 0x2C);

    /* 2C */ s16 timer;

    STRUCT_PAD(0x2E, 0x44);

    /* 44 */ u32 frame;
    /* 48 */ const u16 * frame_config;
    /* 4C */ const u16 **pal;
};

void NewEkrTogiColor(void);
void EndEkrTogiColor(void);
void EkrTogiColor_Loop(struct ProcEkrTogiColor *proc);

/* efxmagic */
void StartSpellAnimation(struct Anim *anim);
void func_fe6_0804C8D0(void);

struct ProcEfxRstWIN {
    PROC_HEADER;

    STRUCT_PAD(0x29, 0x2C);

    /* 2C */ i16 timer;
    /* 2E */ i16 step;

    STRUCT_PAD(0x30, 0x32);

    /* 32 */ u16 diff_per_step;

    STRUCT_PAD(0x34, 0x44);

    /* 44 */ u32 duration;
    /* 48 */ u32 timer2;

    STRUCT_PAD(0x4C, 0x54);

    /* 54 */ i16 *frame_conf;
    /* 58 */ i16 **bufs;

    /* 5C */ struct Anim *anim;
};

ProcPtr NewEfxRestRST(struct Anim *anim, int duration, int step, int frame, int speed);
void EfxRestRST_End(struct ProcEfx *proc);
void EfxRestRST_Loop(struct ProcEfx *proc);
void NewDummvRST(struct Anim *anim, int unk44);
void EfxDummyRST_End(struct ProcEfx *proc);
void EfxDummyRST_Loop(struct ProcEfx *proc);
void NewEfxRestWIN(struct Anim *anim, int unk44, void * unk54, void * unk58);
void EfxRestWIN_Loop(struct ProcEfxRstWIN *proc);
void NewEfxRestWINH(struct Anim *anim, int a, i16 b, void (* hblank)(void));
void NewEfxRestWINH_(struct Anim *anim, int a, void (* hblank)(void));
void EfxRestWINH_Dummy(struct ProcEfx *proc);
void EfxRestWINH_Loop(struct ProcEfx *proc);
void EfxRestWINH_DefaultHblank(void);

struct ProcEfxALPHA
{
    PROC_HEADER;

    /* 29 */ u8 unk29;

    STRUCT_PAD(0x2A, 0x2C);

    /* 2C */ i16 timer;
    /* 2E */ i16 delay;
    /* 30 */ i16 duration_total;

    STRUCT_PAD(0x32, 0x44);

    /* 44 */ int lo, hi, type;

    STRUCT_PAD(0x50, 0x5C);

    /* 5C */ struct Anim *anim;
};

void NewEfxALPHA(struct Anim *anim, int delay, int duration2, int lo, int hi, int type);
void EfxALPHA_Loop(struct ProcEfxALPHA *proc);

struct ProcEfxCircleWIN
{
    PROC_HEADER;
    STRUCT_PAD(0x29, 0x2c);

    /* 2C */ i16 timer;
    /* 2E */ i16 unk_2e;
    /* 30 */ i16 unk_30;
    /* 32 */ i16 unk_32;

    STRUCT_PAD(0x34, 0x3a);

    /* 3A */ u16 unk_3a;

    STRUCT_PAD(0x3c, 0x44);

    /* 44 */ int unk_44;

    STRUCT_PAD(0x48, 0x54);

    /* 54 */ u16 * unk_54;
    /* 58 */ int unk_58;
    /* 5C */ struct Anim *anim;
};

void NewEfxCircleWIN(struct Anim *anim, int terminator, u16 * c, u16 d, u16 e);
void EfxCircleWIN_Loop(struct ProcEfxCircleWIN *proc);

struct ProcEfxMagicQuake
{
    PROC_HEADER;
    STRUCT_PAD(0x29, 0x2c);

    /* 2C */ i16 timer, duration;

    STRUCT_PAD(0x30, 0x5c);

    /* 5C */ struct Anim *anim;
    /* 60 */ ProcPtr qproc;
};

void NewEfxMagicQUAKE(struct Anim *anim, int duration);
void EfxMagicQUAKE_Loop(struct ProcEfxMagicQuake *proc);

struct ProcEfxMagic {
    PROC_HEADER;

    /* 29 */ u8 hitted;
    /* 2A */ u8 type;
    /* 2B */ STRUCT_PAD(0x2B, 0x2C);
    /* 2C */ i16 timer;
    /* 2E */ i16 step;
    /* 30 */ i16 unk30;
    /* 32 */ u16 unk32;
    /* 34 */ STRUCT_PAD(0x34, 0x44);
    /* 44 */ u32 unk44;
    /* 48 */ u32 unk48;
    /* 4C */ u32 frame;
    /* 50 */ u32 speed;
    /* 54 */ i16 * unk54;
    /* 58 */ i16 ** unk58;
    /* 5C */ struct Anim *anim;
    STRUCT_PAD(0x60, 0x64);
    ProcPtr unk_64;
};

struct ProcEfxMagicOBJ {
    PROC_HEADER;

    STRUCT_PAD(0x29, 0x2C);

    /* 2C */ i16 timer;
    /* 2E */ i16 terminator;
    /* 30 */ i16 unk_30;

    STRUCT_PAD(0x32, 0x5C);

    /* 5C */ struct Anim *anim;
    /* 60 */ struct Anim *anim2;

    /* 64 */ ProcPtr seproc;
};

struct ProcEfxEclipseBG
{
    PROC_HEADER;

    /* 29 */ u8 unk29;

    STRUCT_PAD(0x2A, 0x2C);

    /* 2C */ i16 timer;
    /* 2E */ i16 terminator;
    /* 30 */ i16 unk30;

    STRUCT_PAD(0x32, 0x44);

    /* 44 */ u32 frame;
    /* 48 */ const u16 * frame_config;
    /* 4C */ u16 ** tsal;
    /* 50 */ u16 ** tsar;
    /* 54 */ u16 ** img;
    /* 58 */ u16 * pal;
    /* 5C */ struct Anim *anim;
};

void NewEfxDummyMagic(struct Anim *anim);
void EfxDummyMagic_Loop(struct ProcEfxMagic *proc);
void NewEfxTeono(struct Anim *anim);
void EfxTeono_Loop(struct ProcEfxMagic *proc);
void NewEfxTeonoOBJ(struct Anim *anim);
void EfxTeonoObj_Loop(struct ProcEfxMagicOBJ *proc);
void EfxTeonoObj_End(struct ProcEfxMagicOBJ *proc);
void NewEfxTeonoOBJ2(struct Anim *anim);
void EfxTeonoOBJ2_Loop(struct ProcEfxMagicOBJ *proc);
ProcPtr NewEfxTeonoSE(struct Anim *anim, struct Anim *anim2);
void EfxTeonoSE_End(struct ProcEfxMagicOBJ *proc);
void EfxTeonoSE_Loop(struct ProcEfxMagicOBJ *proc);
void NewEfxArrow(struct Anim *anim);
void EfxArrow_Loop(struct ProcEfx *proc);
void NewEfxArrowOBJ(struct Anim *anim);
void EfxArrowObj_Loop(struct ProcEfxMagicOBJ *proc);
void StartSpellAnimJavelin(struct Anim *anim);
void StartSpellAnimJavelinCavalier(struct Anim *anim);
void StartSpellAnimJavelinSoldier(struct Anim *anim);
void StartSpellAnimJavelinPaladin(struct Anim *anim);
void StartSpellAnimJavelinPrgasusKnight(struct Anim *anim);
void StartSpellAnimJavelinFalcon(struct Anim *anim);
void StartSpellAnimJavelinWyvernRider(struct Anim *anim);
void StartSpellAnimJavelinWyvernLord(struct Anim *anim);
void StartSpellAnimJavelinGenerial(struct Anim *anim);
void EfxTeyari_Loop(struct ProcEfx *proc);
void NewEfxTeyariOBJ(struct Anim *anim, int type);
void EfxTeyariObj_Loop(struct ProcEfxMagicOBJ *proc);
void StartSpellAnimSong(struct Anim *anim);
void EfxSong_Loop(struct ProcEfx *proc);
void NewEfxSongBG(struct Anim *anim);
void EfxSongBG_Loop(struct ProcEfxBG *proc);
void NewEfxSongBGCOL(struct Anim *anim);
void EfxSongBGCOL_Loop(struct ProcEfxBGCOL *proc);
void StartSpellAnimDance(struct Anim *anim);
void EfxDance_Loop(struct ProcEfx *proc);
void StartSpellAnimBallista(struct Anim *anim);
void EfxShooter_Loop(struct ProcEfx *proc);
void NewEfxShooterOBJ(struct Anim *anim);
void EfxShooterOBJ_Loop(struct ProcEfxOBJ *proc);
void StartSpellAnimEckesachs(struct Anim *anim);
void EfxEckesachs_Loop(struct ProcEfx *proc);
void NewEfxEckesachsBG(struct Anim *anim, int duration);
void EfxEckesachsBG_Loop(struct ProcEfxBG *proc);
void Pal_EfxEckesachsBGCtrl(struct Anim *anim, int duration);
void EfxEckesachsBGCtrl_Loop(struct ProcEfxBG *proc);
void NewEfxEckesachsBGCOL(struct Anim *anim);
void EfxEckesachsBGCOL_Loop(struct ProcEfxBGCOL *proc);
void StartSpellAnimBindingBlade(struct Anim *anim);
void EfxHurtmut_Loop(struct ProcEfx *proc);
void NewEfxHurtmutOBJ(struct Anim *anim);
void EfxHurtmutOBJ_Loop(struct ProcEfxOBJ *proc);
void StartSpellAnimFireBreath(struct Anim *anim);
void EfxFirebreath_Loop(struct ProcEfx *proc);
void NewEfxFirebreathOBJ(struct Anim *anim);
void EfxFirebreathOBJ_Loop(struct ProcEfxOBJ *proc);
void NewEfxFirebreathBG(struct Anim *anim);
void EfxFirebreathBG_Loop(struct ProcEfxBG *proc);
void NewEfxFirebreathBGCOL(struct Anim *anim);
void EfxFirebreathBGCOL_Loop(struct ProcEfxBGCOL *proc);
void StartSpellAnimIceBreath(struct Anim *anim);
void EfxIcebreath_Loop(struct ProcEfx *proc);
void NewEfxIcebreathOBJ(struct Anim *anim);
void EfxIcebreathOBJ_OnEnd(struct ProcEfxOBJ *proc);
void StartSpellAnimDarkBreath(struct Anim *anim);
void EfxDarkbreath_Loop(struct ProcEfx *proc);
void NewEfxDarkbreathBG(struct Anim *anim);
void EfxDarkbreathBG_Loop(struct ProcEfxBG *proc);
void NewEfxDarkbreathBGCOL(struct Anim *anim);
void EfxDarkbreathBGCOL_Loop(struct ProcEfxBGCOL *proc);
void NewEfxDarkbreathOBJ(struct Anim *anim);
void EfxDarkbreathOBJ_Loop(struct ProcEfxOBJ *proc);
void StartSpellAnimThunder(struct Anim *anim);
void EfxThunder_Loop(struct ProcEfx *proc);
void NewEfxThunderBG(struct Anim *anim);
void EfxThunderBG_Loop(struct ProcEfxBG *proc);
void NewEfxThunderBGCOL(struct Anim *anim);
void EfxThunderBGCOL_Loop(struct ProcEfxBGCOL *proc);
void NewEfxThunderOBJ(struct Anim *anim);
void EfxThunderOBJ_Loop(struct ProcEfxOBJ *proc);
void StartSpellAnimFire(struct Anim *anim);
void StartSpellAnimElfire(struct Anim *anim);
void EfxFire_Loop(struct ProcEfx *proc);
void NewEfxFireBG(struct Anim *anim);
void EfxFireBG_Loop(struct ProcEfxBG *proc);
void NewEfxFireOBJ(struct Anim *anim);
void EfxFireOBJ_Loop(struct ProcEfxOBJ *proc);
void NewEfxFireHITBG(struct Anim *anim);
void EfxFireHITBG_Loop(struct ProcEfxBG *proc);
void NewEfxElfireBG(struct Anim *anim);
void EfxElfireBG_Loop(struct ProcEfxBG *proc);
void NewEfxElfireBGCOL(struct Anim *anim);
void EfxElfireBGCOL_Loop(struct ProcEfxBGCOL *proc);
void NewEfxElfireOBJ(struct Anim *anim);
void EfxElfireOBJ_Loop(struct ProcEfxOBJ *proc);
void StartSpellAnimFimbulvetr(struct Anim *anim);
void EfxFimbulvetr_Loop(struct ProcEfx *proc);
void NewEfxFimbulvetrBGTR(struct Anim *anim);
void EfxFimbulvetrBGTR_Loop(struct ProcEfxBG *proc);
void NewEfxFimbulvetrBG(struct Anim *anim);
void EfxFimbulvetrBG_Loop(struct ProcEfxBG *proc);
void NewEfxFimbulvetrOBJ(struct Anim *anim);
void EfxFimbulvetrOBJ_Loop(struct ProcEfxOBJ *proc);
void NewEfxFimbulvetrOBJ2(struct Anim *anim);
void EfxFimbulvetrOBJ2_Loop(struct ProcEfxOBJ *proc);
void NewEfxFimbulvetrOBJ2Fall(struct Anim *anim, int kind);
void EfxFimbulvetrOBJ2Fall_Loop(struct ProcEfxOBJ *proc);
void StartSpellAnimBolting(struct Anim *anim);
void EfxThunderstorm_Loop(struct ProcEfx *proc);
void NewEfxThunderstormBG(struct Anim *anim);
void EfxThunderstormBG_Loop(struct ProcEfxBG *proc);
void NewEfxThunderstormOBJ(struct Anim *anim);
void EfxThunderstormOBJ_Loop(struct ProcEfxOBJ *proc);
void EfxThunderstormOBJ_End(struct ProcEfxOBJ *proc);
void NewEfxThunderstormCOLOR(struct Anim *anim);
void EfxThunderstormCOLOR_LoopA(struct ProcEfxBGCOL *proc);
void EfxThunderstormCOLOR_LoopB(struct ProcEfxBGCOL *proc);
void EfxThunderstormCOLOR_LoopC(struct ProcEfxBGCOL *proc);
void NewEfxThunderstormDARK(struct Anim *anim, int timer, int terminator);
void EfxThunderstormDARK_LoopA(struct ProcEfxBGCOL *proc);
void EfxThunderstormDARK_LoopB(struct ProcEfxBGCOL *proc);
void StartSpellAnimAircalibur(struct Anim *anim);
void EfxAlacalibur_Loop(struct ProcEfx *proc);
void NewEfxAlacaliburBG(struct Anim *anim);
void NewEfxAlacaliburBG(struct Anim *anim);
void EfxAlacaliburBG_Loop(struct ProcEfxBG *proc);
void NewEfxAlacaliburBGCOL(struct Anim *anim);
void EfxAlacaliburBGCOL_Loop(struct ProcEfxBGCOL *proc);
void NewEfxAlacaliburOBJ(struct Anim *anim);
void EfxAlacaliburOBJ_Loop(struct ProcEfxOBJ *proc);
void StartSpellAnimFlux(struct Anim *anim);
void EfxMistyrain_Loop(struct ProcEfx *proc);
void NewEfxMistyrainBG1(struct Anim *anim);
void NewEfxMistyrainBG2(struct Anim *anim);
void NewEfxMistyrainBG_Loop(struct ProcEfxBG *proc);
void NewEfxMistyrainOBJ(struct Anim *anim);
struct ProcEfxOBJ * NewEfxMistyrainOBJ2(struct Anim *anim);
void EfxMistyrainOBJ_OnEnd(struct ProcEfxOBJ *proc);
void EfxMistyrainOBJ1_Loop1(struct ProcEfxOBJ *proc);
void EfxMistyrainOBJ1_Loop2(struct ProcEfxOBJ *proc);
void EfxMistyrainOBJ1_Loop3(struct ProcEfxOBJ *proc);
void EfxMistyrainOBJ2_Loop1(struct ProcEfxOBJ *proc);
void EfxMistyrainOBJ2_Loop2(struct ProcEfxOBJ *proc);
void StartSpellAnimNosferatu(struct Anim *anim);
void EfxResire_Loop(struct ProcEfx *proc);
void NewEfxResireBG(struct Anim *anim, int type);
void NewEfxResireBG2(struct Anim *anim);
void EfxResireBG_Loop1(struct ProcEfxBG *proc);
void EfxResireBG_Loop2(struct ProcEfxBG *proc);
void EfxResireBG_Loop3(struct ProcEfxBG *proc);
void EfxResireBG_Loop4(struct ProcEfxBG *proc);
void EfxResireBG2_Loop(struct ProcEfxBG *proc);
void NewEfxResireRST(struct Anim *anim, ProcPtr proc_rst, int duration);
void EfxResireRST_Loop(struct ProcEfxRST *proc);
void StartSpellAnimLightning(struct Anim *anim);
void EfxLightning_Loop(struct ProcEfx *proc);
void NewEfxLightningBG(struct Anim *anim);
void EfxLightningBG_Loop(struct ProcEfxBG *proc);
void StartSpellAnimPurge(struct Anim *anim);
// EfxPurge_PlaySFX
void EfxPurge_Loop(struct ProcEfx *proc);
void NewEfxPurgeBG(struct Anim *anim);
void EfxPurgeBG_Loop(struct ProcEfxBG *proc);
void NewEfxPurgeOBJRND(struct Anim *anim);
void EfxPurgeOBJRND_Loop(struct ProcEfxOBJ *proc);
void NewEfxPurgeOBJ(struct Anim *anim, int x, int y);
void EfxPurgeOBJ_OnEnd(struct ProcEfxOBJ *proc);
void StartSpellAnimForblaze(struct Anim *anim);
void EfxForblaze_Loop(struct ProcEfx *proc);
void NewEfxForblazeBG1(struct Anim *anim);
void EfxForblazeBG1_Loop(struct ProcEfxBG *proc);
void NewEfxForblazeBGCOL1(struct Anim *anim, int duration);
void EfxForblazeBGCOL1_Loop(struct ProcEfxBGCOL *proc);
void NewEfxForblazeBGCtrl1(void);
void EfxForblazeBGCtrl1_Loop1(ProcPtr proc);
void EfxForblazeBGCtrl1_Loop2(ProcPtr proc);
void EfxForblazeBGCtrl1_Loop3(ProcPtr proc);
void NewEfxForblazeObjHandle(struct Anim *anim, int duration);
void EfxForblazeObjHandle_Loop(struct ProcEfx *proc);
void NewEfxForblazeOBJ(struct Anim *anim, int x, int y);
void EfxForblazeOBJ_Loop(struct ProcEfxMagicOBJ *proc);
void NewEfxForblazeBG2(struct Anim *anim, int duration);
void EfxForblazeBG2_Loop(struct ProcEfxBG *proc);
void NewEfxForblazeOBJCtrl(struct Anim *anim);
void EfxForblazeOBJCtrl_Loop(struct ProcEfxMagic *proc);
void NewEfxForblazeOBJFall(struct Anim *anim, int duration, int unused);
void EfxForblazeOBJFall_Loop(struct ProcEfxOBJ *proc);
void HBlank_EfxForblaze(void);
void NewEfxForblazeRST(int duration);
void EfxForblazeRST_Loop(struct ProcEfxMagic *proc);
void StartSpellAnimDivine(struct Anim *anim);
void EfxDivine_Loop(struct ProcEfx *proc);
void NewEfxDivineBG(struct Anim *anim);
void NewEfxDivineBG2(struct Anim *anim);
void NewEfxDivineBG3(struct Anim *anim);
void EfxDivineBG_Loop(struct ProcEfxBG *proc);
void NewEfxDivineOBJ(struct Anim *anim);
void EfxDivineOBJ_Loop(struct ProcEfxOBJ *proc);
void StartSpellAnimAureola(struct Anim *anim);
void EfxAureola_Loop(struct ProcEfx *proc);
void NewEfxAureolaBG(struct Anim *anim);
void EfxAureolaBG_Loop(struct ProcEfxBG *proc);
void NewEfxAureolaBG2(struct Anim *anim, int duration);
void EfxAureolaBG2_Loop(struct ProcEfxBG *proc);
void NewEfxAureolaBG2COL(struct Anim *anim, int);
void EfxAureolaBG2COL_Loop(struct ProcEfxBGCOL *proc);
void NewEfxAureolaOBJ(struct Anim *anim, int);
void EfxAureolaOBJ_Loop(struct ProcEfxMagic *proc);

struct ProcEfxAureolaOBJ {
    PROC_HEADER;

    /* 2B */ STRUCT_PAD(0x29, 0x2C);
    /* 2C */ i16 timer;
    /* 2E */ i16 step;
    /* 30 */ i16 unk30;
    /* 32 */ i16 unk32;
    /* 34 */ i16 unk34;
    /* 36 */ i16 unk36;
    /* 38 */ i16 unk38;
    /* 3A */ i16 unk3A;
    /* 3C */ i16 unk3C;
    /* 3E */ STRUCT_PAD(0x3E, 0x44);
    /* 44 */ u32 unk44;
    /* 48 */ u32 unk48;
    /* 4C */ u32 frame;
    /* 50 */ u32 speed;
    /* 54 */ i16 * unk54;
    /* 58 */ i16 ** unk58;
    /* 5C */ struct Anim *anim;
    /* 60 */ struct Anim *anim2;
    /* 64 */ struct Anim *anim3;
};

void NewEfxAureolaOBJCtrl(struct Anim *anim, int);
void EfxAureolaOBJCtrl_Loop(struct ProcEfxAureolaOBJ *proc);
void NewEfxAureolaOBJ2(struct Anim *anim, int);
void EfxAureolaOBJ2_Loop(struct ProcEfxAureolaOBJ *proc);
void NewEfxAureolaOBJ3(struct Anim *anim);
void EfxAureolaOBJ3_Loop(struct ProcEfxAureolaOBJ *proc);
void NewEfxAureolaOBJ3Ctrl(struct Anim *anim, int);
void EfxAureolaOBJ3Ctrl_Loop(struct ProcEfxAureolaOBJ *proc);
void StartSpellAnimApocalypse(struct Anim *anim);
void EfxApocalypse_Loop(struct ProcEfx *proc);
void NewEfxApocalypseBG(struct Anim *anim, int);
void EfxApocalypseBG_Loop(struct ProcEfxBG *proc);
void NewEfxApocalypseBGCtrl(struct Anim *anim);
void EfxApocalypseBGCtrl_Loop(struct ProcEfxBG *proc);
void NewEfxApocalypseBGCOL(struct Anim *anim);
void EfxApocalypseBGCOL_Loop(struct ProcEfxBGCOL *proc);
void NewEfxApocalypseOBJ(struct Anim *anim);
void EfxApocalypseOBJ_Loop2(struct ProcEfxOBJ *proc);
void EfxApocalypseOBJ_Loop3(struct ProcEfxOBJ *proc);
void EfxApocalypseOBJ_Loop4(struct ProcEfxOBJ *proc);
void EfxApocalypseOBJ_Loop1(struct ProcEfxOBJ *proc);
void NewEfxApocalypseBGCOL2(struct Anim *anim, int);
void EfxApocalypseBGCOL2_Loop(struct ProcEfxBGCOL *proc);
void NewEfxApocalypseDummy(struct Anim *anim, ProcPtr, int);
void EfxApocalypseDummy_Loop(struct ProcEfxApocalypseDummy *proc);
void NewEfxApocalypseBgFlash1(struct Anim *anim, int, int);
void EfxApocalypseBgFlash1_Loop(struct ProcEfxFlashing *proc);
void NewEfxApocalypseBgFlash2(struct Anim *anim, int, int);
void EfxApocalypseBgFlash2_Loop1(struct ProcEfxFlashing *proc);
void EfxApocalypseBgFlash2_Loop2(struct ProcEfxFlashing *proc);
void NewEfxApocalypseBG2(struct Anim *anim, int);
void EfxApocalypseBG2_Loop(struct ProcEfxBG *proc);

struct ProcEfxApocalypseOBJ2 {
	PROC_HEADER;

	STRUCT_PAD(0x29, 0x2C);
	/* 2C */ i16 timer;
	/* 2E */ i16 phase1_duration;
	/* 30 */ i16 phase2_duration;
	STRUCT_PAD(0x32, 0x5C);
	/* 5C */ struct Anim *anim;
	/* 60 */ struct Anim *anim2;
};

void NewEfxApocalypseOBJ2(struct Anim *anim, int, int);
void EfxApocalypseOBJ2_Loop1(struct ProcEfxApocalypseOBJ2 *proc);
void EfxApocalypseOBJ2_Loop2(struct ProcEfxApocalypseOBJ2 *proc);

struct ProcEfxApocalypseOBJ3 {
	PROC_HEADER;

	STRUCT_PAD(0x29, 0x2C);
	/* 2C */ i16 timer;
	/* 2E */ i16 duration;
	/* 30 */ i16 phase_counter;
	STRUCT_PAD(0x32, 0x44);
	/* 44 */ int spawn_threshold;
	/* 48 */ int unk48;
	/* 4C */ int rnd_index;
	STRUCT_PAD(0x50, 0x5C);
	/* 5C */ struct Anim *anim;
};

struct ProcEfxApocalypseOBJ3RND {
	PROC_HEADER;

	STRUCT_PAD(0x29, 0x2C);
	/* 2C */ i16 timer;
	/* 2E */ i16 duration;
	STRUCT_PAD(0x30, 0x32);
	/* 32 */ i16 x_center;
	STRUCT_PAD(0x34, 0x3A);
	/* 3A */ i16 y_center;
	STRUCT_PAD(0x3C, 0x44);
	/* 44 */ int lo;
	/* 48 */ int angle;
	STRUCT_PAD(0x4C, 0x5C);
	/* 5C */ struct Anim *anim;
	/* 60 */ struct Anim *anim2;
};

void NewEfxApocalypseOBJ3(struct Anim *anim, int);
void EfxApocalypseOBJ3_Loop(struct ProcEfxApocalypseOBJ3 *proc);
void NewEfxApocalypseOBJ3RND(struct Anim *anim, int duration, int lo, u32 state);
void EfxApocalypseOBJ3RND_Loop(struct ProcEfxApocalypseOBJ3RND *proc);
// StartSpellAnimEclipse
void EfxHazymoon_Loop(struct ProcEfx *proc);
void NewEfxHazymoonBG1(struct Anim *anim);
void NewEfxHazymoonBG2(struct Anim *anim);
void NewEfxHazymoonBG3(struct Anim *anim);
void EfxHazymoonBG_Loop(struct ProcEfxEclipseBG *proc);
void NewEfxHazymoonOBJ2(struct Anim *anim);
void EfxHazymoonOBJ2_OnEnd(struct ProcEfxMagicOBJ *proc);
void EfxHazymoonOBJ2_Loop1(struct ProcEfxMagicOBJ *proc);
void EfxHazymoonOBJ2_Loop2(struct ProcEfxMagicOBJ *proc);
void EfxHazymoonOBJ2_Loop3(struct ProcEfxMagicOBJ *proc);
void NewEfxHazymoonOBJ3(struct Anim *anim);
void EfxHazymoonOBJ3_Loop(struct ProcEfxMagicOBJ *proc);
void NewEfxHazymoonOBJ3RND(struct Anim *anim, int x, int y);
void EfxHazymoonOBJ3RND_Loop(struct ProcEfxMagicOBJ *proc);
void StartSpellAnimFenrir(struct Anim *anim);
void EfxFenrir_Loop(struct ProcEfx *proc);
void NewEfxFenrirBG(struct Anim *anim, int duration);
void EfxFenrirBG_OnEnd(void);
void EfxFenrirBG_Loop(struct ProcEfxBG *proc);
void NewEfxFenrirBGCOL(struct Anim *anim, int duration);
void EfxFenrirBGCOL_OnEnd(void);
void EfxFenrirBGCOL_Loop(struct ProcEfxBGCOL *proc);
void NewEfxFenrirOBJ(struct Anim *anim, int duration);
void EfxFenrirOBJ_Loop(struct ProcEfxOBJ *proc);
void NewEfxFenrirBG2_A(struct Anim *anim);
void NewEfxFenrirBG2_B(struct Anim *anim);
void EfxFenrirBG2_Loop(struct ProcEfxBG *proc);
void NewEfxFenrirOBJ2(struct Anim *anim);
void EfxFenrirOBJ2_Loop(struct ProcEfxOBJ *proc);
void NewEfxFenrirOBJ2Chiri(struct Anim *anim, int idx);
void EfxFenrirOBJ2Chiri_Loop(struct ProcEfxOBJ *proc);
void StartSpellAnimHeal(struct Anim *anim);
void EfxLive_Loop(struct ProcEfx *proc);
// StartSpellAnimMend
void StartSpellAnimMend(struct Anim *anim);
void EfxRelive_Loop(struct ProcEfx *proc);
// StartSpellAnimRecover
void StartSpellAnimRecover(struct Anim *anim);
void EfxRecover_Loop(struct ProcEfx *proc);
// StartSpellAnimPhysic
void StartSpellAnimPhysic(struct Anim *anim);
void EfxReblow_Loop(struct ProcEfx *proc);
void NewEfxLiveBG_A(struct Anim *anim, u32 type);
void NewEfxLiveBG_B(struct Anim *anim, u32 type);
void EfxLiveBG_Loop(struct ProcEfxBG *proc);
void NewEfxLiveBGCOL_A(struct Anim *anim, u32 type);
void NewEfxLiveBGCOL_B(struct Anim *anim, u32 type);
void EfxLiveBGCOL_Loop(struct ProcEfxBGCOL *proc);
void NewEfxLiveALPHA(struct Anim *anim, int timer, int duration, int type);
void EfxLiveALPHA_Delay(struct ProcEfxALPHA *proc);
void EfxLiveALPHA_Loop(struct ProcEfxALPHA *proc);
void NewEfxLiveOBJ(struct Anim *anim);
void NewEfxReserveOBJ(struct Anim *anim);
void EfxLiveOBJ_Loop(struct ProcEfxOBJ *proc);
void EfxReserveOBJ_Loop1(struct ProcEfxOBJ *proc);
void EfxReserveOBJ_Loop2(struct ProcEfxOBJ *proc);
void NewEfxReblowOBJ(struct Anim *anim, u32 kind);
void EfxReblowOBJ_Loop1(struct ProcEfxOBJ *proc);
void EfxReblowOBJ_Loop2(struct ProcEfxOBJ *proc);
void StartSpellAnimFortify(struct Anim *anim);
void StartSpellAnimLatona(struct Anim *anim);
void EfxReserve_Loop(struct ProcEfx *proc);
void NewEfxReserveBG(struct Anim *anim);
void EfxReserveBG_Loop(struct ProcEfxBG *proc);
void NewEfxReserveBGCOL(struct Anim *anim, u32 kind);
void EfxReserveBGCOL_Loop(struct ProcEfxBGCOL *proc);
void NewEfxReserveBG2(struct Anim *anim);
void EfxReserveBG2_Loop(struct ProcEfxBG *proc);
void NewEfxReserveBGCOL2(struct Anim *anim, u32 kind);
void EfxReserveBGCOL2_Loop(struct ProcEfxBGCOL *proc);
void StartSpellAnimRestore(struct Anim *anim);
void EfxRest_Loop(struct ProcEfx *proc);
void NewEfxRestBG(struct Anim *anim);
void EfxRestBG_Loop(struct ProcEfxBG *proc);
void NewEfxRestOBJ(struct Anim *anim);
void EfxRestOBJ_Loop(void);
void StartSpellAnimSilence(struct Anim *anim);
void EfxSilence_Loop(struct ProcEfx *proc);
void NewEfxSilenceBG(struct Anim *anim);
void EfxSilenceBG_Loop(struct ProcEfxBG *proc);
void NewEfxSilenceOBJ(struct Anim *anim);
void EfxSilenceOBJ_OnEnd(struct ProcEfxOBJ *proc);
void StartSpellAnimSleep(struct Anim *anim);
void EfxSleep_Loop(struct ProcEfx *proc);
void NewEfxSleepBG(struct Anim *anim);
void EfxSleepBG_Loop(struct ProcEfxBG *proc);
void NewEfxSleepOBJ(struct Anim *anim);
void NewEfxSleepOBJ2(struct Anim *anim);
void EfxSleepOBJ_OnEnd(void);
void NewEfxSleepSE(struct Anim *anim);
void EfxSleepSE_PlaySE(struct ProcEfx *proc);
void EfxSleepSE_OnEnd(void);
void StartSpellAnimHammerne(struct Anim *anim);
void EfxHammarne_Loop(struct ProcEfx *proc);
void NewEfxHammarneBG(struct Anim *anim);
void EfxHammarneBG_Loop(struct ProcEfxBG *proc);
void NewEfxHammarneOBJ(struct Anim *anim);
void EfxHammarneOBJ_OnEnd(void);
void StartSpellAnimBerserk(struct Anim *anim);
void EfxBerserk_Loop(struct ProcEfx *proc);
void NewEfxBerserkBG(struct Anim *anim, int duration);
void EfxBerserkBG_Loop(struct ProcEfxBG *proc);
void NewEfxBerserkCLONE(struct Anim *anim, int duration);
void EfxBerserkCLONE_Loop(struct ProcEfxBG *proc);
void EfxBerserkCLONE_OnEnd(void);
void NewEfxBerserkOBJ(struct Anim *anim);
void EfxBerserkOBJ_OnEnd(struct ProcEfxOBJ *proc);
void EfxBerserkOBJ_Loop1(struct ProcEfxOBJ *proc);
void EfxBerserkOBJ_Loop3(struct ProcEfxOBJ *proc);
void EfxBerserkOBJ_Loop5(struct ProcEfxOBJ *proc);
void EfxBerserkOBJ_Loop7(struct ProcEfxOBJ *proc);
void EfxBerserkOBJ_Loop9(struct ProcEfxOBJ *proc);
void EfxBerserkOBJ_Loop2(struct ProcEfxOBJ *proc);
void EfxBerserkOBJ_Loop4(struct ProcEfxOBJ *proc);
void EfxBerserkOBJ_Loop6(struct ProcEfxOBJ *proc);
void EfxBerserkOBJ_Loop8(struct ProcEfxOBJ *proc);
void EfxBerserkOBJ_Loop10(struct ProcEfxOBJ *proc);
void StartSpellAnimBarrier(struct Anim *anim);
void EfxMshield_Loop(struct ProcEfx *proc);
void NewEfxMshieldBG(struct Anim *anim);
void EfxMshieldBG_Loop(struct ProcEfxBG *proc);
void NewEfxMshieldOBJ(struct Anim *anim);
void NewEfxMshieldOBJ2(struct Anim *anim);
void EfxMshieldOBJ_OnEnd(struct ProcEfxOBJ *proc);

struct ProcEfxDamageMojiEffectOBJ {
    PROC_HEADER;

    STRUCT_PAD(0x29, 0x2C);
    /* 2C */ i16 timer;
    /* 2E */ i16 terminator;
    STRUCT_PAD(0x30, 0x5C);
    /* 5C */ struct Anim *anim;
    /* 60 */ struct ProcEkrSubAnimeEmulator *sub_proc;
};

void NewEfxDamageMojiEffect(struct Anim *anim, int hitted);
void EfxDamageMojiEffect_Loop(struct ProcEfx *proc);
void NewEfxDamageMojiEffectOBJ(struct Anim *anim, int hitted);
void EfxDamageMojiEffectOBJ_Loop(struct ProcEfxDamageMojiEffectOBJ *proc);
void NewEfxCriricalEffect(struct Anim *anim);
void EfxCriricalEffect_Loop(struct ProcEfx *proc);
void NewEfxCriricalEffectBG(struct Anim *anim);
void EfxCriricalEffectBG_Loop(struct ProcEfxBG *proc);
void NewEfxCriricalEffectBGCOL(struct Anim *anim);
void EfxCriricalEffectBGCOL_Loop(struct ProcEfxBGCOL *proc);
void NewEfxNormalEffect(struct Anim *anim);
void EfxNormalEffect_Loop(struct ProcEfx *proc);
void NewEfxNormalEffectBG(struct Anim *anim);
void EfxNormalEffectBG_Loop(struct ProcEfxBG *proc);

/**
 * efxmisc
 */
void NewEfxYushaSpinShield(struct Anim *anim, int state);
void EfxYushaSpinShield_Null(struct ProcEfx *proc);
void NewEfxYushaSpinShieldOBJ(struct Anim *anim, int state);
void EfxYushaSpinShieldOBJ_1(struct ProcEfxOBJ *proc);
void EfxYushaSpinShieldOBJ_2(struct ProcEfxOBJ *proc);
void EfxYushaSpinShieldOBJ_3(struct ProcEfxOBJ *proc);
void EfxYushaSpinShieldOBJ_4(struct ProcEfxOBJ *proc);
void NewEfxHurtmutEff00(struct Anim *anim);
void EfxHurtmutEff00_Null(struct ProcEfx *proc);
void NewEfxHurtmutEff00OBJ(struct Anim *anim);
void EfxHurtmutEff00OBJ_1(struct ProcEfxOBJ *proc);
void EfxHurtmutEff00OBJ_2(struct ProcEfxOBJ *proc);
void EfxHurtmutEff00OBJ_3(struct ProcEfxOBJ *proc);
void NewEfxHurtmutEff01OBJ(struct Anim *anim);
void EfxHurtmutEff01OBJ_1(struct ProcEfxOBJ *proc);
void EfxHurtmutEff01OBJ_2(struct ProcEfxOBJ *proc);
void EfxHurtmutEff01OBJ_3(struct ProcEfxOBJ *proc);
void NewEfxMagfcast(struct Anim *anim, int type);
void EfxMagfcast_Loop(struct ProcEfx *proc);
void NewEfxMagfcastBG(struct Anim *anim, u32 type);
void EfxMagfcastBG_Loop(struct ProcEfxBG *proc);
void NewEfxSunakemuri(struct Anim *anim, int type);
void EfxSunakemuri_Null(struct ProcEfx *proc);
void NewEfxSunakemuriOBJ(struct Anim *anim, int type);
void EfxSunakemuriOBJ_Loop(struct ProcEfxOBJ *proc);
void NewEfxKingPika(struct Anim *anim);
void EfxKingPika_Loop(struct ProcEfx *proc);
void NewEfxSongFE6(struct Anim *anim);
void EfxSongFE6_Loop(struct ProcEfxOBJ *proc);
void NewEfxDanceOBJ(struct Anim *anim);
void EfxDanceOBJ_Loop(struct ProcEfxOBJ *proc);
void NewEfxMosaicEffect(struct Anim *anim, int duration, int hi);
void EfxMosaicEffect_1(struct ProcEfxBG *proc);
void EfxMosaicEffect_2(struct ProcEfxBG *proc);

struct ProcEfxSRankSCR2 {
    PROC_HEADER;
    STRUCT_PAD(0x29, 0x2C);

    /* 2C */ i16 timer;
    /* 2E */ i16 terminator;

    STRUCT_PAD(0x30, 0x44);

    /* 44 */ u32 unk44;

    STRUCT_PAD(0x48, 0x5C);

    /* 5C */ struct ProcEfx *seff_scr1;
};
extern EWRAM_OVERLAY(banim) i16 gEfxSpecalEffectExist[2];

void NewEfxSpecalEffect(struct Anim *anim);
void EfxSpecalEffect_Null(ProcPtr proc);
void NewEfxSRankWeaponEffect(struct Anim *anim);
void EfxSRankWeaponEffect_Loop(struct ProcEfx *proc);
void NewEfxSRankWeaponEffectBG(struct Anim *anim);
void EfxSRankWeaponEffectBG_Loop(struct ProcEfxBG *proc);
void HBlank_EfxSRankWeaponEffectSCR(void);
void NewEfxSRankWeaponEffectSCR(void);
void EfxSRankWeaponEffectSCR_Loop(struct ProcEfx *proc);
void NewEfxSRankWeaponEffectSCR2(struct ProcEfx *seff_scr);
void EfxSRankWeaponEffectSCR2_Loop(struct ProcEfxSRankSCR2 *proc);
void NewEfxMagdhisEffect(struct Anim *anim);
void EfxMagdhisEffect_Loop(struct ProcEfx *proc);
void NewEfxMagdhisEffectBG(struct Anim *anim, int);
void EfxMagdhisEffectBG_Loop(struct ProcEfxBG *proc);
void NewEfxMantBatabata(struct Anim *anim);
void EfxMantBatabata_1(struct ProcEfxOBJ *proc);
void EfxMantBatabata_2(struct ProcEfxOBJ *proc);

enum efxopmagic_index {
    CRSPELL_DUMMY,
    CRSPELL_FIRE,
    CRSPELL_THUNDER,
    CRSPELL_HEAL,
};

struct EfxopMagicDesc {
    /* 00 */ u16 magicFuncIdx;
    /* 02 */ s16 xOffsetBg;
    /* 04 */ s16 yOffsetBg;
    /* 06 */ u16 xOffsetObj;
    /* 08 */ u16 yOffsetObj;
    /* 0A */ u16 bgChr;
    /* 0C */ u16 bgPalId;
    /* 0E */ u16 objChr;
    /* 10 */ u16 objPalId;
    /* 12 */ u16 bg;
    /* 14 */ u16 * bgTmBuf;
    /* 18 */ void * bgImgBuf; // Used for decompression
    /* 1C */ void * bgTsaBuf; // Used for decompression
    /* 20 */ void * objImgBuf; // Used for decompression
    /* 24 */ void (*resetCallback)(void);
};

extern EWRAM_DATA ProcPtr gpActiveClassReelSpellProc;
extern EWRAM_DATA ProcPtr gpActiveCRSpellBgColorProc;

extern void (* CONST_DATA gClassReelSpellAnimFuncLut[8])(struct Anim *anim);

void ResetClassReelSpell(void);
void EndActiveClassReelSpell(void);
void EndActiveClassReelBgColorProc(void);
void SetActiveClassReelSpell(ProcPtr proc);
void SetActiveCRSpellBgColorProc(ProcPtr proc);
struct EfxopMagicDesc *GetMagicEffectBufferFor(struct Anim *anim);
void SetCRSpellBgPosition(struct Anim *anim, struct EfxopMagicDesc *magicFx);
void ClearCRSpellBgTmBuf(struct Anim *anim);
struct Anim *CRSpellCreateFrontAnim(struct Anim *anim, u16 scrIdx, void *scrA, void *scrB);
void CRSpell_WriteBgMap(struct Anim *anim, u16 notFlipped, void *src, u16 isCompressed);
void CRSpell_RegisterBgGfx(struct Anim *anim, const void *src);
void CRSpell_RegisterBgPal(struct Anim *anim, const u16 *src);
void CRSpell_RegisterObjGfx(struct Anim *anim, const void *src);
void CRSpell_RegisterObjPal(struct Anim *anim, const u16 *src);
void StartClassReelSpellAnim(struct Anim *anim);
void StartClassReelSpellAnimDummy(struct Anim *anim);
void StartClassReelSpellAnimFire(struct Anim *anim);
void EfxopFire_Loop(struct ProcEfx *proc);
void NewEfxopFireBG(struct Anim *anim, struct ProcEfx *proc);
void EfxopFireBG_Loop(struct ProcEfxBG *proc);
void NewEfxopFireOBJ(struct Anim *anim, struct ProcEfx *proc);
void EfxopFireOBJ_Loop(struct ProcEfxOBJ *proc);
void StartClassReelSpellAnimThunder(struct Anim *anim);
void EfxopThunder_Loop(struct ProcEfx *proc);
void NewEfxopThunderBG(struct Anim *anim, struct ProcEfx *proc);
void EfxopThunderBG_Loop(struct ProcEfxBG *proc);
void NewEfxopThunderBGCOL(struct Anim *anim, struct ProcEfx *proc);
void EfxopThunderBGCOL_Loop(struct ProcEfxBGCOL *proc);
void NewEfxopThunderOBJ(struct Anim *anim, struct ProcEfx *proc);
void EfxopThunderOBJ_Loop(struct ProcEfxOBJ *proc);
void StartClassReelSpellAnimHeal(struct Anim *anim);
void EfxopLive_Loop(struct ProcEfx *proc);
void NewEfxopLiveBG(struct Anim *anim, struct ProcEfx *proc);
void EfxopLiveBG_Loop(struct ProcEfxBG *proc);
void NewEfxopLiveBGCOL(struct Anim *anim, struct ProcEfx *proc);
void EfxopLiveBGCOL_Loop(struct ProcEfxBGCOL *proc);
void NewEfxopLiveALPHA(struct Anim *anim,
    int timer, int delay, int type, struct ProcEfx *unused);
void EfxopLiveALPHA_Loop1(struct ProcEfxALPHA *proc);
void EfxopLiveALPHA_Loop2(struct ProcEfxALPHA *proc);
void NewEfxopLiveOBJ(struct Anim *anim, struct ProcEfx *proc);
void EfxopLiveOBJ_Loop(struct ProcEfxOBJ *proc);

/* banim_ekrdragon.h */

void FillBGSafelyRect(u16 * tm, u16 width, u16 height, int pal, int chr);
void FillBGRect(u16 * tm, u16 width, u16 height, int pal, int chr);
void func_fe6_0805B0D4(u16 * tm, u16 width, u16 height, int pal, int chr);
void EfxTmModifyPal(u16 * tm, u16 width, u16 height);
void EfxTmCpyBG(const void * ptr1, void * ptr2, u16 width, u16 height, int pal, int chr);
void EfxTmCpyBgHFlip(const u16 * tsa, u16 * tm, u16 width, u16 height, int pal, int chr);
void EfxTmCpyExt(const u16 * src, i16 src_width, u16 * dst, i16 dst_width, u16 width, u16 hight, int pal, int chr);
void EfxTmCpyExtHFlip(const u16 * src, i16 src_width, u16 * dst, i16 dst_width, u16 width, u16 hight, int pal, int chr);
void func_fe6_0805B380(u16 * tm, int arg1, int arg2);
void EkrModifyBarfx(u16 * tm, int);
// func_fe6_0805B4D8
void EfxPalBlackInOut(u16 * pal_buf, int line, int length, int ref);
void EfxPalWhiteInOut(u16 * pal_buf, int line, int length, int ref);
void EfxPalFlashingInOut(u16 *pal_buf, int line, int length, int r0, int g0, int b0);
void EfxPalModifyPetrifyEffect(u16 * pal_buf, int line, int length);
void EfxSplitColor(u16 * pal, u8 * dst, u32 length);
void EfxSplitColorPetrify(u16 * src, u8 * dst, u32 length);
void func_fe6_0805B88C(i8 * src1, i8 * src2, i16 * pal, u32 length, int ref);
void EfxDecodeSplitedPalette(u16 * dst, i8 * src1, i8 * src2, i16 * src3, u32 length, int ref, int unk);
void EfxChapterMapFadeOUT(int speed);
int BanimSpawnRandB(int a);

struct ProcEkrSubAnimeEmulator {
    PROC_HEADER;

    /* 29 */ u8 act_type;
    /* 2A */ u8 valid;

    STRUCT_PAD(0x2B, 0x2C);

    /* 2C */ i16 timer;
    /* 2E */ i16 scr_offset;

    STRUCT_PAD(0x30, 0x32);

    /* 32 */ u16 x1;
    /* 34 */ u16 x2;

    STRUCT_PAD(0x36, 0x3A);

    /* 3A */ u16 y1;
    /* 3C */ u16 y2;

    STRUCT_PAD(0x40, 0x44);

    /* 44 */ const AnimScr *scr;
    /* 48 */ const void *sprite_data;
    /* 4C */ int oam2;
    /* 4C */ int oam;
};

enum {
    EKR_SUBANIMEMU_ACT_ONE_TURN,
    EKR_SUBANIMEMU_ACT_LOOP,
    EKR_SUBANIMEMU_ACT_END
};

ProcPtr NewEkrsubAnimeEmulator(int x, int y, u32 *anim_scr, int type, int oam2Base, int oamBase, ProcPtr parent);
void EkrsubAnimeEmulator_Loop(struct ProcEkrSubAnimeEmulator *proc);
int GetAnimSpriteRotScaleX(u32 header);
int GetAnimSpriteRotScaleY(u32 header);
void BanimUpdateSpriteRotScale(void * src, struct BaSpriteData * out, i16 x, i16 y, int unused);

enum efx_sound_type {
    EFX_SOUNDT_0,
    EFX_SOUNDT_1,
    EFX_SOUNDT_2,
    EFX_SOUNDT_3,
    EFX_SOUNDT_4,
    EFX_SOUNDT_5,
    EFX_SOUNDT_6,
};

struct ProcEfxSoundSE {
    PROC_HEADER;

    STRUCT_PAD(0x29, 0x2C);

    /* 2C */ s16 timer;

    STRUCT_PAD(0x2E, 0x44);

    /* 44 */ int volume;
    /* 48 */ int index;
};

extern EWRAM_OVERLAY(banim) int gEkrMainBgmPlaying;
extern EWRAM_OVERLAY(banim) int gEfxSoundSeExist;

extern CONST_DATA u16 *gBanimBossBGMs[];
extern CONST_DATA u16 *gBanimSongTable1[];
extern CONST_DATA u16 *gBanimSongTable2[];
extern CONST_DATA u16 *gBanimSongTable3[];

void EfxPlaySE(int songid, int volume);
void EfxSoundSE_Loop(struct ProcEfxSoundSE *proc);
void DoM4aSongNumStop(int num);
void EfxOverrideBgm(int songid, int volume);
void EfxStopBGM1(void);
void UnregisterEfxSoundSeExist(void);
void RegisterEfxSoundSeExist(void);
int CheckEfxSoundSeExist(void);
void M4aPlayWithPostionCtrl(int songid, int x, int flag);
void EfxPlaySEwithCmdCtrl(struct Anim *anim, int cmd);
u16 GetEfxSoundType1FromTerrain(u16 terrain);
int IsAnimSoundInPosition(struct Anim *anim);
u16 GetEfxSoundType2FromBaseCon(u16 basecon);

enum efx_hp_change_type {
    EFX_HPT_CHANGED = 0,
    EFX_HPT_DEFEATED = 1,
    EFX_HPT_NOT_CHANGE = 2
};

i16 GetEfxHpChangeType(struct Anim *anim);
void EfxPlayHittedSFX(struct Anim *anim);
void EfxPlayCriticalHittedSFX(struct Anim *anim);
int EfxCheckRetaliation(int is_retaliation);

enum efx_staff_type {
    EFX_STAFF_NOPE,

    EFX_STAFF_OFFSENSIVE,
    EFX_STAFF_HEAL,
};

int EfxCheckStaffType(int weapon);
void EkrPlayMainBGM(void);
void EkrRestoreBGM(void);
int GetProperAnimSoundLocation(struct Anim *anim);
void PlaySFX(int songid, int volume, int locate, int type);
void PlaySfxAutomatically(int songid, int volume, struct Anim *anim);

struct ProcEfxClasschgInOutUnit {
    PROC_HEADER;

    STRUCT_PAD(0x29, 0x2C);

    /* 2C */ s16 timer;
    /* 2E */ s16 terminator;

    STRUCT_PAD(0x30, 0x32);

    /* 32 */ s16 start;
    /* 34 */ s16 end;

    STRUCT_PAD(0x36, 0x5C);

    /* 5C */ struct Anim *anim;
};

struct ProcEkrClasschgRST {
    PROC_HEADER;

    STRUCT_PAD(0x29, 0x2C);

    /* 2C */ s16 timer;
    /* 2E */ s16 terminator;

    STRUCT_PAD(0x30, 0x44);

    /* 44 */ int start;
    /* 48 */ int end;

    STRUCT_PAD(0x4C, 0x5C);

    /* 5C */ struct Anim *anim;

    STRUCT_PAD(0x60, 0x64);

    /* 64 */ struct ProcEfx *procfx;
};

extern struct ProcEfx *gpProcEkrClasschg;

bool EkrClasschgFinished(void);
void EndEkrClasschg(void);
void NewEkrClassChg(struct BaSprite *anim);
void EkrClasschg_Loop(struct ProcEfx *proc);
void EkrClasschg_Done(struct ProcEfx *proc);
void NewEkrClasschgBG1(struct Anim *anim);
void NewEkrClasschgBG2(struct Anim *anim);
void EfxClasschgBG_Loop(struct ProcEfxBG *proc);
void NewEfxClasschgBGSE00(struct Anim *anim);
void EfxClasschgBGSE00_Loop(struct ProcEfxBG *proc);
void NewEfxClasschgBGSE01(struct Anim *anim);
void EfxClasschgBGSE01_Loop(struct ProcEfxBG *proc);
void NewEfxClasschgOBJ(struct Anim *anim);
void EfxClasschgOBJ_Loop(struct ProcEfxOBJ *proc);
void NewEfxClasschgFIN(struct Anim *anim, int duration);
void EfxClasschgFIN_Loop(struct ProcEfxBG *proc);
void NewEfxClasschgCLONE(struct Anim *anim, int duration);
void EfxClasschgCLONE_Loop(struct ProcEfxBG *proc);
void EfxClasschgCLONE_End(struct ProcEfxBG *proc);
void NewEfxBlackInOutUnit(struct Anim *anim, int duration, int direction);
void EfxBlackInOutUnit_Loop(struct ProcEfxClasschgInOutUnit *proc);
void NewEfxClasschgRST(struct Anim *anim, struct ProcEfx *procfx, int duration, int start, int end);
void EfxClasschgRST_Loop(struct ProcEkrClasschgRST *proc);

enum ekr_lvup_status_index {
    EKRLVUP_STAT_HP = 0,
    EKRLVUP_STAT_POW,
    EKRLVUP_STAT_SKL,
    EKRLVUP_STAT_SPD,
    EKRLVUP_STAT_LCK,
    EKRLVUP_STAT_DEF,
    EKRLVUP_STAT_RES,
    EKRLVUP_STAT_CON,
    EKRLVUP_STAT_MAX,

    EKRLVUP_STAT_CLASS = EKRLVUP_STAT_MAX,
    EKRLVUP_STAT_LV_MSG,
    EKRLVUP_STAT_LV_VAL,

    EKRLVUP_STAT_PNAME = EKRLVUP_STAT_MAX,
    EKRLVUP_STAT_LVPRE_MSG,
    EKRLVUP_STAT_LVPRE_VAL,

    EKRLVUP_TEXT_16 = 0x10,
    EKRLVUP_TEXT_18 = 0x12,
};

#define EKR_LVUP_UI_BASE 0x50

struct ProcEkrlvup {
    PROC_HEADER;

    /* 29 */ u8 finished;
    /* 2A */ u8 is_promotion;
    /* 2C */ i16 timer;
    /* 2E */ i16 index;

    STRUCT_PAD(0x30, 0x44);

    /* 44 */ int scroll_timer[4];

    STRUCT_PAD(0x54, 0x5C);

    struct Anim *anim_this, *anim_other;
};

extern struct ProcEkrlvup *gpProcEkrLevelup;
extern u32 gUnk_Banim_0201F05C[8]; // unused actually
extern ProcPtr gpProcEfxPartsofScroll;
extern ProcPtr gpProcEfxleveluphb;
extern struct Unit *gpEkrLvupUnit;
extern struct BattleUnit *gpEkrLvupBattleUnit;
extern u16 gEkrLvupPreLevel;
extern u16 gEkrLvupPostLevel;
extern u16 gEkrLvupBaseStatus[EKRLVUP_STAT_MAX];
extern u16 gEkrLvupPostStatus[EKRLVUP_STAT_MAX];
extern u16 gEkrLvupScrollPos1;
extern u16 gEkrLvupScrollPos2;
extern int gEkrLvupApfxUnexist;

extern const u16 sEfxLvupPartsPos[];
extern const char EkrLvupMsgsStr[][5];
extern const char EkrLvupMsgsMag[][5];

bool CheckEkrLvupDone(void);
void EndEkrLevelUp(void);
void EkrLvup_InitStatusText(struct ProcEkrlvup *proc);
void Ekrlvup_PutBaseStatus(struct ProcEkrlvup *proc, int index);
void Ekrlvup_PutJobname(struct ProcEkrlvup *proc);
void Ekrlvup_PutPreLevel(struct ProcEkrlvup *proc);
void NewEkrLevelup(struct BaSprite *anim);
void EkrLvup_Init(struct ProcEkrlvup *proc);
void EkrLvup_InitLevelUpBox(struct ProcEkrlvup *proc);
void EkrLvup_SetBgs(struct ProcEkrlvup *proc);
void EkrLvup_InitPalette(struct ProcEkrlvup *proc);
void EkrLvup_PutWindowOnScreen(struct ProcEkrlvup *proc);
void EkrLvup_PrepareApGfx(struct ProcEkrlvup *proc);
void EkrLvup_Promo_WindowScroll0(struct ProcEkrlvup *proc);
void EkrLvup_Promo_DrawPromoNewClassName(struct ProcEkrlvup *proc);
void EkrLvup_Promo_WindowScroll1(struct ProcEkrlvup *proc);
void EkrLvup_DrawNewLevel(struct ProcEkrlvup *proc);
void EkrLvup_InitCounterForMainAnim(struct ProcEkrlvup *proc);
void EkrLvup_MainAnime(struct ProcEkrlvup *proc);
void EkrLvup_SetHBlank(struct ProcEkrlvup *proc);
void EkrLvup_DoNothing(struct ProcEkrlvup *proc);
void EkrLvup_PutWindowOffScreen(struct ProcEkrlvup *proc);
void EkrLvup_ResetScreen(struct ProcEkrlvup *proc);
void EkrLvup_OnEnd(struct ProcEkrlvup *proc);

ProcPtr NewEkrlvupSubAnimeEmulator(int x, int y, const AnimScr *scr, int act_type);
void EkrlvupSubAnimeEmulator_Loop(struct ProcEkrSubAnimeEmulator *proc);
ProcPtr NewEfxPartsofScroll(void);
void EfxPartsofScroll_LoopExt(void);
void EfxPartsofScroll_OnEnd(ProcPtr proc);
void EfxPartsofScroll_Loop(ProcPtr proc);
ProcPtr NewEfxPartsofScroll2(void);
void EfxPartsofScroll2_OnEnd(ProcPtr proc);
void EfxPartsofScroll2_Loop(ProcPtr proc);
ProcPtr NewEfxleveluphb(void);
void Efxleveluphb_OnEnd(ProcPtr proc);
void Efxleveluphb_Init(ProcPtr proc);
void Efxleveluphb_Loop(ProcPtr proc);
void EkrLvupHBlank(void);
void EfxPartsofScroll2HBlank(void);

enum ekrtriangle_types {
    EKR_TRI_JTYPE_DEFAULT = 0,
    EKR_TRI_JTYPE_PROMOTED,

    EKR_TRI_WTYPE_DEFAULT = 0,
    EKR_TRI_WTYPE_ALTERNATIVE,
    EKR_TRI_WTYPE_ALTERNATIVE2,
};

struct ProcEkrTriClass {
    PROC_HEADER;

    /* 2E */ STRUCT_PAD(0x29, 0x2C);
    /* 2C */ s16 timer;
    /* 2E */ STRUCT_PAD(0x2E, 0x44);
    /* 44 */ int etype1;
    /* 48 */ int etype2;
    /* 4C */ int ewtype1;
    /* 50 */ int ewtype2;
    /* 54 */ STRUCT_PAD(0x54, 0x5C);
    /* 5C */ struct Anim *anim;
};

extern int gEkrTriangleInvalid;

bool CheckEkrTriangleInvalid(void);
void DebugEkrTriangleMsg(void);
void NewEkrTriangle(struct BaSprite *anim);
void EkrTriangle_Loop(struct ProcEfx *proc);
ProcPtr NewEkrTriPegasusKnight(struct Anim *anim, u32 etype1, u32 etype2, u32 ewtype1, u32 ewtype2);
void EkrTriPegasusKnight_Loop(struct ProcEkrTriClass *proc);
void NewEkrTriPegasusKnightBG(struct Anim *anim, u32 pos, u32 etype, u32 ewtype);
void EfxTriPegasusKnightBG_Loop(struct ProcEfxBG *proc);
void NewEkrTriPegasusKnightOBJ(struct Anim *anim, u32 pos, u32 etype, u32 ewtype);
void EkrTriPegasusKnightOBJ_Loop(struct ProcEfxOBJ *proc);
ProcPtr NewEkrTriArmorKnight(struct Anim *anim, u32 etype1, u32 etype2, u32 ewtype1, u32 ewtype2);
void EkrTriArmorKnight_Loop(struct ProcEkrTriClass *proc);
void NewEkrTriArmorKnightOBJ(struct Anim *anim, u32 etype1, u32 etype2, u32 ewtype1, u32 ewtype2);
void EkrTriArmorKnightOBJ_Loop(struct ProcEfxOBJ *proc);
void NewEkrTriArmorKnightOBJ2(struct Anim *anim, u32 pos, u32 etype, u32 ewtype);
void EkrTriArmorKnightOBJ2_Loop1(struct ProcEfxOBJ *proc);
void EkrTriArmorKnightOBJ2_Loop2(struct ProcEfxOBJ *proc);
void NewEfxTriangleQUAKE(struct Anim *anim, int duration);
void EfxTriangleQUAKE_Loop(struct ProcEfx2 *proc);

extern CONST_DATA u16 *gBattleBGDataTable[];

void PutBanimBgIMG(int index);
void PutBanimBgTSA(int index);
void PutBanimBgPAL(int);
void PutBanimBG(int);

struct ProcEkrPopup {
    PROC_HEADER;

    STRUCT_PAD(0x29, 0x2C);

    /* 2C */ i16 timer;
    /* 2E */ i16 terminator;

    STRUCT_PAD(0x30, 0x44);

    /* 44 */ int lbuff;
    /* 48 */ int ldebuf;
    /* 4C */ int rbuff;
    /* 50 */ int rdebuf;

    STRUCT_PAD(0x54, 0x60);

    /* 60 */ struct Anim *anim;
};

extern struct ProcEkrPopup * gpProcEkrPopup;
extern int gEkrPopupDone;

bool CheckEkrPopupDone(void);
void EndEkrPopup(void);
// EfxPlaySound5AVol100
// EfxPlaySound5CVol100
// MakeBattlePopupTileMap
// DrawBattlePopup
void NewEkrPopup(void);
void EkrPopup_BeginningPause(struct ProcEkrPopup *proc);
void EkrPopup_DrawRankUp1(struct ProcEkrPopup *proc);
void EkrPopup_WaitRankUp1(struct ProcEkrPopup *proc);
void EkrPopup_DrawRankUp2(struct ProcEkrPopup *proc);
void EkrPopup_WaitRankUp2(struct ProcEkrPopup *proc);
void EkrPopup_DrawWeaponBroken1(struct ProcEkrPopup *proc);
void EkrPopup_WaitWeaponBroken1(struct ProcEkrPopup *proc);
void EkrPopup_DrawWeaponBroken2(struct ProcEkrPopup *proc);
void EkrPopup_WaitWeaponBroken2(struct ProcEkrPopup *proc);
void EkrPopup_EndingPause(struct ProcEkrPopup *proc);
void EkrPopup_Blocked(struct ProcEkrPopup *proc);

extern CONST_DATA char gNopStr[];
extern CONST_DATA struct ProcScr ProcScr_EkrBattleDeamon[];
extern CONST_DATA struct ProcScr ProcScr_EkrBattle[];
extern CONST_DATA struct ProcScr ProcScr_EkrLvupFan[];
extern CONST_DATA struct ProcScr ProcScr_EkrGauge[];
extern CONST_DATA u16 AnimSprite_EkrGauge_1[];
extern CONST_DATA u16 AnimSprite_EkrGauge_2[];
extern CONST_DATA u8 AnimSprite_EkrGauge_3[];
extern CONST_DATA u8 AnimSprite_EkrGauge_4[];
extern CONST_DATA u8 AnimSprite_EkrGauge_5[];
extern CONST_DATA u8 AnimSprite_EkrGauge_6[];
extern CONST_DATA u16 AnimSprite_EkrGauge_7[];
extern CONST_DATA u16 AnimSprite_EkrGauge_8[];
extern CONST_DATA u16 AnimSprite_EkrGauge_8[];
extern CONST_DATA u16 AnimSprite_EkrGauge_9[];
extern CONST_DATA u16 AnimSprite_EkrGauge_10[];
extern CONST_DATA u16 AnimSprite_EkrGauge_11[];
extern CONST_DATA u16 AnimSprite_EkrGauge_12[];
extern CONST_DATA struct ProcScr ProcScr_EkrDispUP[];
extern CONST_DATA struct ProcScr ProcScr_EfxHpBar[];
extern CONST_DATA struct ProcScr ProcScr_EfxHpBarResire[];
extern CONST_DATA struct ProcScr ProcScr_EfxAvoid[];
extern CONST_DATA struct ProcScr ProcScr_EfxNoDmage[];
extern CONST_DATA struct ProcScr ProcScr_EfxHpBarLive[];
extern CONST_DATA struct ProcScr ProcScr_EfxNoDamageYure[];
extern CONST_DATA struct ProcScr ProcScr_EfxStatusCHG[];
extern CONST_DATA struct ProcScr ProcScr_EfxDeadEvent[];
extern CONST_DATA struct ProcScr ProcScr_EfxDead[];
extern CONST_DATA struct ProcScr ProcScr_EfxDeadPika[];
extern CONST_DATA struct ProcScr ProcScr_EfxDeadAlpha[];
extern CONST_DATA struct ProcScr ProcScr_EfxDeadDragonAlpha[];
extern CONST_DATA struct ProcScr ProcScr_EfxFarAttack[];
extern CONST_DATA struct ProcScr ProcScr_EfxQuakePure[];
// ??? EfxQuakePureVecs
extern CONST_DATA struct ProcScr ProcScr_EfxHitQuakePure[];
extern CONST_DATA struct ProcScr ProcScr_EfxQuake[];
extern CONST_DATA struct ProcScr ProcScr_EfxHitQuake[];
extern CONST_DATA struct ProcScr ProcScr_EfxFlashBG[];
extern CONST_DATA struct ProcScr ProcScr_EfxWhiteIN[];
extern CONST_DATA struct ProcScr ProcScr_EfxFlashHpBar[];
extern CONST_DATA struct ProcScr ProcScr_EfxStatusUnit[];
extern CONST_DATA struct ProcScr ProcScr_EfxWeaponIcon[];
extern CONST_DATA struct ProcScr ProcScr_EfxHpBarColorChange[];
extern CONST_DATA struct ProcScr ProcScr_EfxSpellCast[];
extern CONST_DATA struct ProcScr ProcScr_EkrBattleStarting[];
extern CONST_DATA struct ProcScr ProcScr_Ekrbattleending[];
extern CONST_DATA struct ProcScr ProcScr_EkrBaseKaiten[];
// ??? Imgs_EkrBaseKaiten1
// ??? Imgs_EkrBaseKaiten2
extern CONST_DATA AnimScr *AnimScrs_EkrBaseKaiten1[];
extern CONST_DATA AnimScr *AnimScrs_EkrBaseKaiten2[];
extern CONST_DATA AnimScr *AnimScrs_EkrBaseKaiten3[];
extern CONST_DATA AnimScr *AnimScrs_EkrBaseKaiten4[];
extern CONST_DATA AnimScr *AnimScrs_EkrBaseKaiten5[];
extern CONST_DATA AnimScr *AnimScrs_EkrBaseKaiten6[];
extern const u16 *CONST_DATA EkrBaseKaiten_Table1[];
extern const u16 *CONST_DATA EkrBaseKaiten_Table2[];
extern const u16 *CONST_DATA EkrBaseKaiten_Table3[];
extern CONST_DATA struct ProcScr ProcScr_EkrUnitKakudai[];
extern CONST_DATA struct ProcScr ProcScr_EkrWindowAppear[];
extern CONST_DATA struct ProcScr ProcScr_EkrNamewinAppear[];
extern CONST_DATA struct ProcScr ProcScr_EkrBaseAppear[];
extern CONST_DATA AnimScr AnimScr_DefaultAnim[];
extern CONST_DATA u16 *TsaConfs_BanimTmA[];
extern CONST_DATA struct ProcScr ProcScr_EkrChienCHR[];
extern CONST_DATA struct ProcScr ProcScr_EfxAnimeDrv[];
extern CONST_DATA struct ProcScr ProcScr_EkrUnitMainMini[];
extern CONST_DATA struct ProcScr ProcScr_EkrTogiInitPROC[];
extern CONST_DATA struct ProcScr ProcScr_EkrTogiEndPROC[];
extern CONST_DATA struct ProcScr ProcScr_EkrTogiColor[];
// ??? Pals_ArenaBattleBg[];
extern CONST_DATA AnimScr AnimScr_EkrlvupfxUnk_085CCC40[];
extern CONST_DATA AnimScr AnimScr_EkrTerrainfx_R_Far[];
extern CONST_DATA AnimScr AnimScr_EkrTerrainfx_L_Far[];
extern CONST_DATA AnimScr AnimScr_EkrTerrainfx_R_Close[];
extern CONST_DATA AnimScr AnimScr_EkrTerrainfx_L_Close[];
extern u32 AnimScr_EkrBaseKaiten_085CE168[];
extern u32 AnimScr_EkrBaseKaiten_085CE18C[];
extern u32 AnimScr_EkrBaseKaiten_085CEDF8[];
extern u32 AnimScr_EkrBaseKaiten_085CEE18[];
extern u32 AnimScr_EkrBaseKaiten_085CEE3C[];
extern u32 AnimScr_EkrBaseKaiten_085CEE60[];
extern u32 AnimScr_EkrBaseKaiten_085CEE80[];
extern u32 AnimScr_EkrBaseKaiten_085CEEA4[];
extern u32 AnimScr_EkrBaseKaiten_085CF6A8[];
extern u32 AnimScr_EkrBaseKaiten_085CF6CC[];
extern u32 AnimScr_EkrBaseKaiten_085CF6F0[];
extern u32 AnimScr_EkrBaseKaiten_085CF714[];
extern u32 AnimScr_EkrBaseKaiten_085D04E8[];
extern u32 AnimScr_EkrBaseKaiten_085D050C[];
extern u32 AnimScr_EkrBaseKaiten_085D0530[];
extern u32 AnimScr_EkrBaseKaiten_085D0554[];
extern u32 AnimScr_EkrBaseKaiten_085D0578[];
extern u32 AnimScr_EkrBaseKaiten_085D059C[];
extern u32 AnimScr_EkrBaseKaiten_085D05C0[];
extern u32 AnimScr_EkrBaseKaiten_085D05E4[];
extern u32 AnimScr_EkrBaseKaiten_085D0D10[];
extern u32 AnimScr_EkrBaseKaiten_085D0D34[];
extern u32 AnimScr_EkrBaseKaiten_085D0D58[];
extern u32 AnimScr_EkrBaseKaiten_085D0D7C[];
extern u32 AnimScr_NoDamage[];
extern u32 AnimScr_Miss[];

typedef void (* SpellAnimFunc)(struct Anim *anim);
extern CONST_DATA SpellAnimFunc gEkrSpellAnimLut[];

extern u32 AnimScr_Common[];
extern CONST_DATA struct ProcScr ProcScr_EfxRestRST[];
extern CONST_DATA struct ProcScr ProcScr_EfxDummyRST[];
extern CONST_DATA struct ProcScr ProcScr_EfxRestWIN[];
extern CONST_DATA struct ProcScr ProcScr_EfxRestWINH[];
extern CONST_DATA struct ProcScr ProcScr_EfxALPHA[];
extern CONST_DATA struct ProcScr ProcScr_EfxCircleWIN[];
extern CONST_DATA struct ProcScr ProcScr_EfxMagicQUAKE[];
extern CONST_DATA struct ProcScr ProcScr_EfxDummyMagic[];
extern CONST_DATA struct ProcScr ProcScr_EfxTeono[];
extern CONST_DATA struct ProcScr ProcScr_EfxTeonoOBJ[];
extern CONST_DATA struct ProcScr ProcScr_EfxTeonoOBJ2[];
extern CONST_DATA struct ProcScr ProcScr_EfxTeonoSE[];
extern CONST_DATA struct ProcScr ProcScr_EfxArrow[];
extern CONST_DATA struct ProcScr ProcScr_EfxArrowOBJ[];
extern CONST_DATA struct ProcScr ProcScr_EfxTeyari[];
extern CONST_DATA struct ProcScr ProcScr_EfxTeyariOBJ[];
extern CONST_DATA struct ProcScr ProcScr_EfxSong[];
extern CONST_DATA struct ProcScr ProcScr_EfxSongBG[];
extern CONST_DATA struct ProcScr ProcScr_EfxSongBGCOL[];
extern CONST_DATA struct ProcScr ProcScr_EfxDance[];
extern CONST_DATA struct ProcScr ProcScr_EfxShooter[];
extern CONST_DATA struct ProcScr ProcScr_EfxShooterOBJ[];
extern CONST_DATA struct ProcScr ProcScr_EfxEckesachs[];
extern CONST_DATA struct ProcScr ProcScr_EfxEckesachsBG[];
extern CONST_DATA struct ProcScr ProcScr_EfxEckesachsBGCtrl[];
extern CONST_DATA struct ProcScr ProcScr_EfxEckesachsBGCOL[];
extern CONST_DATA struct ProcScr ProcScr_EfxHurtmut[];
extern CONST_DATA struct ProcScr ProcScr_EfxHurtmutOBJ[];
extern CONST_DATA struct ProcScr ProcScr_EfxFirebreath[];
extern CONST_DATA struct ProcScr ProcScr_EfxFirebreathOBJ[];
extern CONST_DATA struct ProcScr ProcScr_EfxFirebreathBG[];
extern CONST_DATA struct ProcScr ProcScr_EfxFirebreathBGCOL[];
extern CONST_DATA struct ProcScr ProcScr_EfxIcebreath[];
extern CONST_DATA struct ProcScr ProcScr_EfxIcebreathOBJ[];
extern CONST_DATA struct ProcScr ProcScr_EfxDarkbreath[];
extern CONST_DATA struct ProcScr ProcScr_EfxDarkbreathBG[];
extern CONST_DATA u16 *Tsa_EfxDarkbreathBG[];
extern CONST_DATA struct ProcScr ProcScr_EfxDarkbreathBGCOL[];
extern CONST_DATA struct ProcScr ProcScr_EfxDarkbreathOBJ[];
extern CONST_DATA struct ProcScr ProcScr_EfxThunder[];
extern CONST_DATA struct ProcScr ProcScr_EfxThunderBG[];
extern CONST_DATA u16 *TsaArray_EfxThunderBG_L[];
extern CONST_DATA u16 *TsaArray_EfxThunderBG_R[];
extern CONST_DATA struct ProcScr ProcScr_EfxThunderBGCOL[];
extern CONST_DATA struct ProcScr ProcScr_EfxThunderOBJ[];
extern CONST_DATA struct ProcScr ProcScr_EfxFire[];
extern CONST_DATA struct ProcScr ProcScr_EfxFireBG[];
extern CONST_DATA u16 *TsaArray_EfxFireBG_L[];
extern CONST_DATA u16 *TsaArray_EfxFireBG_R[];
extern CONST_DATA struct ProcScr ProcScr_EfxFireOBJ[];
extern CONST_DATA struct ProcScr ProcScr_EfxFireHITBG[];
extern CONST_DATA u16 *ImgArray_EfxFireHITBG[];
extern CONST_DATA u16 *TsaArray_EfxFireHITBG[];
extern CONST_DATA struct ProcScr ProcScr_EfxElfireBG[];
extern CONST_DATA struct ProcScr ProcScr_EfxElfireBGCOL[];
extern CONST_DATA struct ProcScr ProcScr_EfxElfireOBJ[];
extern CONST_DATA struct ProcScr ProcScr_EfxFimbulvetr[];
extern CONST_DATA struct ProcScr ProcScr_EfxFimbulvetrBGTR[];
extern CONST_DATA u16 *TsaArray_EfxFimbulvetrBGTR[];
extern CONST_DATA u16 *ImgArray_EfxFimbulvetrBGTR[];
extern CONST_DATA struct ProcScr ProcScr_EfxFimbulvetrBG[];
extern CONST_DATA u16 *TsaArray_EfxFimbulvetrBG[];
extern CONST_DATA u16 *ImgArray_EfxFimbulvetrBG[];
extern CONST_DATA struct ProcScr ProcScr_EfxFimbulvetrOBJ[];
extern CONST_DATA struct ProcScr ProcScr_EfxFimbulvetrOBJ2[];
extern CONST_DATA struct ProcScr ProcScr_EfxFimbulvetrOBJ2Fall[];
extern CONST_DATA struct ProcScr ProcScr_EfxThunderstorm[];
extern CONST_DATA struct ProcScr ProcScr_EfxThunderstormBG[];
extern CONST_DATA u16 *ImgArray_EfxThunderstormBG[];
extern CONST_DATA u16 *TsaArray_EfxThunderstormBG[];
extern CONST_DATA struct ProcScr ProcScr_EfxThunderstormOBJ[];
extern CONST_DATA struct ProcScr ProcScr_EfxThunderstormCOLOR[];
extern CONST_DATA struct ProcScr ProcScr_EfxThunderstormDARK[];
extern CONST_DATA struct ProcScr ProcScr_EfxAlacalibur[];
extern CONST_DATA struct ProcScr ProcScr_EfxAlacaliburBG[];
extern CONST_DATA u16 *TsaArray_EfxAlacaliburBG[];
extern CONST_DATA struct ProcScr ProcScr_EfxAlacaliburBGCOL[];
extern CONST_DATA struct ProcScr ProcScr_EfxAlacaliburOBJ[];
extern CONST_DATA struct ProcScr ProcScr_EfxMistyrain[];
extern CONST_DATA struct ProcScr ProcScr_EfxMistyrainBG[];
extern CONST_DATA u16 *TsaArray_EfxMistyrainBG[];
extern CONST_DATA u16 *ImgArray_EfxMistyrainBG[];
extern CONST_DATA struct ProcScr ProcScr_EfxMistyrainOBJ[];
extern CONST_DATA struct ProcScr ProcScr_EfxMistyrainOBJ2[];
extern CONST_DATA struct ProcScr ProcScr_EfxResire[];
extern CONST_DATA struct ProcScr ProcScr_EfxResireBG[];
extern CONST_DATA struct ProcScr ProcScr_EfxResireBG2[];
extern CONST_DATA u16 *ImgArray_EfxResireBG[];
extern CONST_DATA u16 *TsaArray_EfxResireBG[];
extern CONST_DATA struct ProcScr ProcScr_EfxResireRST[];
extern CONST_DATA struct ProcScr ProcScr_EfxLightning[];
extern CONST_DATA struct ProcScr ProcScr_EfxLightningBG[];
extern CONST_DATA u16 *ImgArray_EfxLightningBG[];
extern CONST_DATA u16 *PalArray_EfxLightningBG[];
extern CONST_DATA u16 *TsaArray_EfxLightningBG[];
extern CONST_DATA struct ProcScr ProcScr_EfxPurge[];
extern CONST_DATA struct ProcScr ProcScr_EfxPurgeBG[];
extern CONST_DATA u16 *ImgArray_EfxPurgeBG[];
extern CONST_DATA u16 *PalArray_EfxPurgeBG[];
extern CONST_DATA u16 *TsaArray_EfxPurgeBG[];
extern CONST_DATA struct ProcScr ProcScr_EfxPurgeOBJRND[];
extern CONST_DATA int Vecs_EfxPurgeOBJRND[];
extern CONST_DATA struct ProcScr ProcScr_EfxPurgeOBJ[];
extern CONST_DATA struct ProcScr ProcScr_EfxForblaze[];
extern CONST_DATA struct ProcScr ProcScr_EfxForblazeBG1[];
extern CONST_DATA u16 *TsaArray_EfxForblazeBG1[];
extern CONST_DATA u16 *ImgArray_EfxForblazeBG1[];
extern CONST_DATA struct ProcScr ProcScr_EfxForblazeBGCOL1[];
extern CONST_DATA struct ProcScr ProcScr_EfxForblazeBGCtrl1[];
extern CONST_DATA struct ProcScr ProcScr_EfxForblazeObjHandle[];
extern CONST_DATA int XposArray_EfxForblazeOBJ[];
extern CONST_DATA struct ProcScr ProcScr_EfxForblazeOBJ[];
extern CONST_DATA struct ProcScr ProcScr_EfxForblazeBG2[];
extern CONST_DATA struct ProcScr ProcScr_EfxForblazeOBJCtrl[];
extern CONST_DATA struct ProcScr ProcScr_EfxForblazeOBJFall[];
extern CONST_DATA struct ProcScr ProcScr_EfxForblazeRST[];
extern CONST_DATA struct ProcScr ProcScr_EfxDivine[];
extern CONST_DATA struct ProcScr ProcScr_EfxDivineBG[];
extern CONST_DATA u16 *ImgArray_EfxDivineBG[];
extern CONST_DATA u16 *TsaArray_EfxDivineBG[];
extern CONST_DATA u16 *ImgArray_EfxDivineBG2[];
extern CONST_DATA u16 *TsaArray_EfxDivineBG2[];
extern CONST_DATA u16 *ImgArray_EfxDivineBG3[];
extern CONST_DATA u16 *TsaArray_EfxDivineBG3[];
extern CONST_DATA struct ProcScr ProcScr_EfxDivineOBJ[];
extern CONST_DATA struct ProcScr ProcScr_EfxAureola[];
extern CONST_DATA struct ProcScr ProcScr_EfxAureolaBG[];
extern CONST_DATA u16 *ImgArray_EfxAureolaBG[];
extern CONST_DATA u16 *TsaArray_EfxAureolaBG[];
extern CONST_DATA struct ProcScr ProcScr_EfxAureolaBG2[];
extern CONST_DATA struct ProcScr ProcScr_EfxAureolaBG2COL[];
extern CONST_DATA struct ProcScr ProcScr_EfxAureolaOBJ[];
extern CONST_DATA struct ProcScr ProcScr_EfxAureolaOBJCtrl[];
extern CONST_DATA struct ProcScr ProcScr_EfxAureolaOBJ2[];
extern CONST_DATA struct ProcScr ProcScr_EfxAureolaOBJ3[];
extern CONST_DATA struct ProcScr ProcScr_EfxAureolaOBJ3Ctrl[];
extern CONST_DATA struct ProcScr ProcScr_EfxApocalypse[];
extern CONST_DATA struct ProcScr ProcScr_EfxApocalypseBG[];
extern CONST_DATA struct ProcScr ProcScr_EfxApocalypseBGCtrl[];
extern CONST_DATA struct ProcScr ProcScr_EfxApocalypseBGCOL[];
extern CONST_DATA struct ProcScr ProcScr_EfxApocalypseOBJ[];
extern CONST_DATA u32 *AnimArray_EfxApocalypseOBJ[];
extern CONST_DATA struct ProcScr ProcScr_EfxApocalypseBGCOL2[];
extern CONST_DATA struct ProcScr ProcScr_EfxApocalypseDummy[];
extern CONST_DATA struct ProcScr ProcScr_EfxApocalypseBgFlash1[];
extern CONST_DATA struct ProcScr ProcScr_EfxApocalypseBgFlash2[];
extern CONST_DATA struct ProcScr ProcScr_EfxApocalypseBG2[];
extern CONST_DATA u16 *ImgArray_EfxApocalypseBG2[];
extern CONST_DATA u16 *TsaArray_EfxApocalypseBG2[];
extern CONST_DATA struct ProcScr ProcScr_EfxApocalypseOBJ2[];
extern CONST_DATA struct ProcScr ProcScr_EfxApocalypseOBJ3[];
extern int DuraArray_EfxApocalypseOBJ3RND[];
extern int LoArray_EfxApocalypseOBJ3RND[];
extern int StateArray_EfxApocalypseOBJ3RND[];
extern CONST_DATA struct ProcScr ProcScr_EfxApocalypseOBJ3RND[];
extern CONST_DATA struct ProcScr ProcScr_EfxHazymoon[];
extern CONST_DATA struct ProcScr ProcScr_EfxHazymoonBG[];
extern CONST_DATA u16 *TsaArray_EfxHazymoonBG[];
extern CONST_DATA u16 *ImgArray_EfxHazymoonBG[];
extern CONST_DATA struct ProcScr ProcScr_EfxHazymoonOBJ2[];
extern CONST_DATA struct ProcScr ProcScr_EfxHazymoonOBJ3[];
extern u16 gEclipseAnimSpriteCoordinates[];
extern CONST_DATA struct ProcScr ProcScr_EfxHazymoonOBJ3RND[];
extern CONST_DATA struct ProcScr ProcScr_EfxFenrir[];
extern CONST_DATA struct ProcScr ProcScr_EfxFenrirBG[];
extern CONST_DATA struct ProcScr ProcScr_EfxFenrirBGCOL[];
extern CONST_DATA struct ProcScr ProcScr_EfxFenrirOBJ[];
extern CONST_DATA struct ProcScr ProcScr_EfxFenrirBG2[];
extern CONST_DATA u16 *ImgArray_EfxFenrirBG2_A[];
extern CONST_DATA u16 *TsaArray_EfxFenrirBG2_A[];
extern CONST_DATA struct ProcScr ProcScr_EfxFenrirOBJ2[];
extern CONST_DATA struct ProcScr ProcScr_EfxFenrirOBJ2Chiri[];
extern int gFenrirSpriteAngles[];
extern CONST_DATA struct ProcScr ProcScr_EfxLive[];
extern CONST_DATA struct ProcScr ProcScr_EfxRelive[];
extern CONST_DATA struct ProcScr ProcScr_EfxRecover[];
extern CONST_DATA struct ProcScr ProcScr_EfxReblow[];
extern CONST_DATA struct ProcScr ProcScr_EfxLiveBG[];
extern CONST_DATA struct ProcScr ProcScr_EfxLiveBGCOL[];
extern CONST_DATA struct ProcScr ProcScr_EfxLiveALPHA[];
extern CONST_DATA struct ProcScr ProcScr_EfxLiveOBJ[];
extern CONST_DATA struct ProcScr ProcScr_EfxReserveOBJ[];
extern CONST_DATA struct ProcScr ProcScr_EfxReblowOBJ[];
extern CONST_DATA struct ProcScr ProcScr_EfxReserve[];
extern CONST_DATA struct ProcScr ProcScr_EfxReserveBG[];
extern CONST_DATA u16 *TsaArray_EfxReserveBG[];
extern CONST_DATA struct ProcScr ProcScr_EfxReserveBGCOL[];
extern CONST_DATA struct ProcScr ProcScr_EfxReserveBG2[];
extern CONST_DATA u16 *TsaArray_EfxReserveBG2[];
extern CONST_DATA struct ProcScr ProcScr_EfxReserveBGCOL2[];
extern CONST_DATA struct ProcScr ProcScr_EfxRest[];
extern CONST_DATA struct ProcScr ProcScr_EfxRestBG[];
extern CONST_DATA u16 *TsaArray_EfxRestBG[];
extern CONST_DATA u16 *ImgArray_EfxRestBG[];
extern CONST_DATA struct ProcScr ProcScr_EfxRestOBJ[];
extern CONST_DATA struct ProcScr ProcScr_EfxSilence[];
extern CONST_DATA struct ProcScr ProcScr_EfxSilenceBG[];
extern CONST_DATA u16 *TsaArray_EfxSilenceBG[];
extern CONST_DATA struct ProcScr ProcScr_EfxSilenceOBJ[];
extern CONST_DATA struct ProcScr ProcScr_EfxSleep[];
extern CONST_DATA struct ProcScr ProcScr_EfxSleepBG[];
extern CONST_DATA u16 *TsaArray_EfxSleepBG[];
extern CONST_DATA struct ProcScr ProcScr_EfxSleepOBJ[];
extern CONST_DATA struct ProcScr ProcScr_EfxSleepOBJ2[];
extern CONST_DATA struct ProcScr ProcScr_EfxSleepSE[];
extern CONST_DATA struct ProcScr ProcScr_EfxHammarne[];
extern CONST_DATA struct ProcScr ProcScr_EfxHammarneBG[];
extern CONST_DATA u16 *TsaArray_EfxHammarneBG[];
extern CONST_DATA u16 *ImgArray_EfxHammarneBG[];
extern CONST_DATA struct ProcScr ProcScr_EfxHammarneOBJ[];
extern CONST_DATA struct ProcScr ProcScr_EfxBerserk[];
extern CONST_DATA struct ProcScr ProcScr_EfxBerserkBG[];
extern CONST_DATA struct ProcScr ProcScr_EfxBerserkCLONE[];
extern CONST_DATA struct ProcScr ProcScr_EfxBerserkOBJ[];
extern CONST_DATA struct ProcScr ProcScr_EfxMshield[];
extern CONST_DATA struct ProcScr ProcScr_EfxMshieldBG[];
extern CONST_DATA u16 *TsaArray_EfxMshieldBG[];
extern CONST_DATA struct ProcScr ProcScr_EfxMshieldOBJ[];
extern CONST_DATA struct ProcScr ProcScr_EfxMshieldOBJ2[];
extern CONST_DATA struct ProcScr ProcScr_EfxDamageMojiEffect[];
extern CONST_DATA struct ProcScr ProcScr_EfxDamageMojiEffectOBJ[];
extern CONST_DATA struct ProcScr ProcScr_EfxCriricalEffect[];
extern CONST_DATA struct ProcScr ProcScr_EfxCriricalEffectBG[];
extern CONST_DATA struct ProcScr ProcScr_EfxCriricalEffectBGCOL[];
extern CONST_DATA struct ProcScr ProcScr_EfxNormalEffect[];
extern CONST_DATA struct ProcScr ProcScr_EfxNormalEffectBG[];
extern CONST_DATA u16 *TSAs_EfxNormalEffectBG[];
extern CONST_DATA struct ProcScr ProcScr_EfxYushaSpinShield[];
extern CONST_DATA struct ProcScr ProcScr_EfxYushaSpinShieldOBJ[];
extern CONST_DATA struct ProcScr ProcScr_EfxHurtmutEff00[];
extern CONST_DATA struct ProcScr ProcScr_EfxHurtmutEff00OBJ[];
extern CONST_DATA struct ProcScr ProcScr_EfxHurtmutEff01OBJ[];
extern CONST_DATA struct ProcScr ProcScr_EfxMagfcast[];
extern CONST_DATA struct ProcScr ProcScr_EfxMagfcastBG[];
extern CONST_DATA u16 *TsaLut1_EfxMagfcastBG[];
extern CONST_DATA u16 *TsaLut2_EfxMagfcastBG[];
extern CONST_DATA struct ProcScr ProcScr_EfxSunakemuri[];
extern CONST_DATA struct ProcScr ProcScr_EfxSunakemuriOBJ[];
extern CONST_DATA struct ProcScr ProcScr_EfxKingPika[];
extern CONST_DATA struct ProcScr ProcScr_EfxSongFE6[];
extern CONST_DATA struct ProcScr ProcScr_EfxDanceOBJ[];
extern CONST_DATA struct ProcScr ProcScr_EfxMosaicEffect[];
extern CONST_DATA struct ProcScr ProcScr_EfxSpecalEffect[];
extern CONST_DATA struct ProcScr ProcScr_EfxSRankWeaponEffect[];
extern CONST_DATA struct ProcScr ProcScr_EfxSRankWeaponEffectBG[];
extern CONST_DATA struct ProcScr ProcScr_EfxSRankWeaponEffectSCR[];
extern CONST_DATA struct ProcScr ProcScr_EfxSRankWeaponEffectSCR2[];
extern CONST_DATA i16 EfxSRankWeaponEffectSCR_Ref[];
extern CONST_DATA struct ProcScr ProcScr_EfxMagdhisEffect[];
extern CONST_DATA struct ProcScr ProcScr_EfxMagdhisEffectBG[];
extern CONST_DATA u16 *TsaArray_EfxMagdhisEffectBG[];
extern CONST_DATA struct ProcScr ProcScr_EfxMantBatabata[];
extern CONST_DATA struct ProcScr ProcScr_EfxopFire[];
extern CONST_DATA struct ProcScr ProcScr_EfxopFireBG[];
extern CONST_DATA u16 *TsaArray_EfxopFireBG[];
extern CONST_DATA struct ProcScr ProcScr_EfxopFireOBJ[];
extern CONST_DATA struct ProcScr ProcScr_EfxopThunder[];
extern CONST_DATA struct ProcScr ProcScr_EfxopThunderBG[];
extern CONST_DATA u16 *TsaArray_EfxopThunderBG[];
extern CONST_DATA struct ProcScr ProcScr_EfxopThunderBGCOL[];
extern CONST_DATA struct ProcScr ProcScr_EfxopThunderOBJ[];
extern CONST_DATA struct ProcScr ProcScr_EfxopLive[];
// ??? ProcScr_EfxopLiveBG
// ??? TsaArray_EfxopLiveBG
// ??? ProcScr_EfxopLiveBGCOL
// ??? ProcScr_EfxopLiveALPHA
// ??? ProcScr_EfxopLiveOBJ
extern u32 AnimScr_TeonoObjCloseRight[];
extern u32 AnimScr_TeonoObjFarRight[];
extern u32 AnimScr_TeonoObj2Right[];
extern u32 AnimScr_TeonoObjCloseLeft[];
extern u32 AnimScr_TeonoObjFarLeft[];
extern u32 AnimScr_TeonoObj2Left[];
extern u32 AnimScr_ArrowCloseRight[];
extern u32 AnimScr_ArrowFarRight[];
extern u32 AnimScr_ArrowCloseLeft[];
extern u32 AnimScr_ArrowFarLeft[];
extern u32 AnimScr_EfxTeyariObjType0Right[];
extern u32 AnimScr_EfxTeyariObjType0Left[];
extern u32 AnimScr_EfxTeyariObjType1Right[];
extern u32 AnimScr_EfxTeyariObjType1Left[];
extern u32 AnimScr_EfxShooterOBJ_L[];
extern u32 AnimScr_EfxShooterOBJ_R[];
extern u32 AnimScr_EfxDanceObj[];
extern u32 AnimScr_EfxSongFE6[];
extern u32 AnimScr_EfxBindingBlade_L[];
extern u32 AnimScr_EfxBindingBlade_R[];
extern u32 AnimScr_HurtmutEff00OBJ1_Right[];
extern u32 AnimScr_HurtmutEff01OBJ1_Right[];
extern u32 AnimScr_HurtmutEff00OBJ1_Left[];
extern u32 AnimScr_HurtmutEff01OBJ1_Left[];
extern u32 AnimScr_HurtmutEff00OBJ2_Right[];
extern u32 AnimScr_HurtmutEff01OBJ2_Right[];
extern u32 AnimScr_HurtmutEff00OBJ2_Left[];
extern u32 AnimScr_HurtmutEff01OBJ2_Left[];
extern u32 AnimScr_FirebreathOBJ_L[];
extern u32 AnimScr_FirebreathOBJ_R[];
extern u32 AnimScr_IcebreathOBJ_R[];
extern u32 AnimScr_IcebreathOBJ_L[];
extern u32 AnimScr_DarkBreath[];
extern u32 AnimScr_YushaSpinShieldOBJ_LeftTypeA[];
extern u32 AnimScr_YushaSpinShieldOBJ2_RightTypeA[];
extern u32 AnimScr_YushaSpinShieldOBJ3_RightTypeA[];
extern u32 AnimScr_YushaSpinShieldOBJ_RightTypeA[];
extern u32 AnimScr_YushaSpinShieldOBJ2_LeftTypeA[];
extern u32 AnimScr_YushaSpinShieldOBJ3_LeftTypeA[];
extern u32 AnimScr_YushaSpinShieldOBJ_LeftTypeB[];
extern u32 AnimScr_YushaSpinShieldOBJ2_RightTypeB[];
extern u32 AnimScr_YushaSpinShieldOBJ3_RightTypeB[];
extern u32 AnimScr_YushaSpinShieldOBJ_RightTypeB[];
extern u32 AnimScr_YushaSpinShieldOBJ2_LeftTypeB[];
extern u32 AnimScr_YushaSpinShieldOBJ3_LeftTypeB[];
extern u32 AnimScr_EfxSunakemuriOBJ1_R[];
extern u32 AnimScr_EfxSunakemuriOBJ1_L[];
extern u32 AnimScr_EfxSunakemuriOBJ2_R[];
extern u32 AnimScr_EfxSunakemuriOBJ2_L[];
extern u32 AnimScr_EfxSunakemuriOBJ3_R[];
extern u32 AnimScr_EfxSunakemuriOBJ3_L[];
extern u32 AnimScr_EfxMantBatabata1_R[];
extern u32 AnimScr_EfxMantBatabata1_L[];
extern u32 AnimScr_EfxMantBatabata2_R[];
extern u32 AnimScr_EfxMantBatabata2_L[];
extern u32 AnimScr_EfxMantBatabata3_R[];
extern u32 AnimScr_EfxMantBatabata3_L[];
extern u32 AnimScr_EfxThunderOBJ_R[];
extern u32 AnimScr_EfxThunderOBJ_L[];
extern u32 AnimScr_EfxFireOBJ_L_Front[];
extern u32 AnimScr_EfxFireOBJ_L_Back[];
extern u32 AnimScr_EfxFireOBJ_R_Front[];
extern u32 AnimScr_EfxFireOBJ_R_Back[];
extern u32 AnimScr_EfxElfireOBJ_R[];
extern u32 AnimScr_EfxElfireOBJ_L[];
extern CONST_DATA AnimScr AnimScr_EfxThunderstormOBJ[];
extern CONST_DATA AnimScr AnimScr_EfxForblazeOBJ[];
extern CONST_DATA AnimScr AnimScr_EfxForblazeOBJ3[];
extern CONST_DATA AnimScr AnimScr_EfxForblazeOBJ4[];
extern CONST_DATA AnimScr AnimScr_EfxForblazeOBJ5[];
extern CONST_DATA AnimScr AnimScr_EfxForblazeOBJ6[];
extern CONST_DATA AnimScr AnimScr_EfxFimbulvetrOBJ1[];
extern CONST_DATA AnimScr AnimScr_EfxFimbulvetrOBJ2Fall[];
extern CONST_DATA AnimScr AnimScr_FimbulvetrOBJ2Fall_TypeA[];
extern CONST_DATA AnimScr AnimScr_FimbulvetrOBJ2Fall_TypeB[];
extern CONST_DATA AnimScr AnimScr_EfxAlacaliburOBJ_RF[];
extern CONST_DATA AnimScr AnimScr_EfxAlacaliburOBJ_RB[];
extern CONST_DATA AnimScr AnimScr_EfxAlacaliburOBJ_LF[];
extern CONST_DATA AnimScr AnimScr_EfxAlacaliburOBJ_LB[];
extern CONST_DATA AnimScr AnimScr_EfxMistyrainOBJ1_1[];
extern CONST_DATA AnimScr AnimScr_EfxHazymoonOBJ3RND[];
extern CONST_DATA AnimScr AnimScr_EfxMistyrainOBJ1_2[];
extern CONST_DATA AnimScr AnimScr_EfxMistyrainOBJ2_1[];
extern CONST_DATA AnimScr AnimScr_EfxMistyrainOBJ2_2[];
extern CONST_DATA AnimScr AnimScr_EfxMistyrainOBJ1_3[];
extern CONST_DATA AnimScr AnimScr_EfxDivineOBJ[];
extern CONST_DATA AnimScr AnimScr_EfxApocalypseOBJ2_1[];
extern CONST_DATA AnimScr AnimScr_EfxApocalypseOBJ3RND_1[];
extern CONST_DATA AnimScr AnimScr_EfxApocalypseOBJ3RND_2[];
extern CONST_DATA AnimScr AnimScr_EfxApocalypseOBJ3RND_3[];
extern CONST_DATA AnimScr AnimScr_EfxApocalypseOBJ2_2[];
extern CONST_DATA AnimScr AnimScr_EfxHazymoonOBJ2_1[];
extern CONST_DATA AnimScr AnimScr_EfxHazymoonOBJ2_2[];
extern CONST_DATA AnimScr AnimScr_EfxHazymoonOBJ2_3[];
extern CONST_DATA AnimScr AnimScr_EfxFenrirOBJ2Chiri1[];
extern CONST_DATA AnimScr AnimScr_EfxFenrirOBJ2Chiri2[];
extern CONST_DATA AnimScr AnimScr_EfxFenrirOBJ[];
extern CONST_DATA AnimScr AnimScr_EfxPurgeOBJ[];
extern CONST_DATA AnimScr AnimScr_EfxLiveOBJ[];
extern CONST_DATA AnimScr AnimScr_EfxReserveOBJ[];
extern CONST_DATA AnimScr AnimScr_EfxReblowOBJ_L_A[];
extern CONST_DATA AnimScr AnimScr_EfxReblowOBJ_L_B[];
extern CONST_DATA AnimScr AnimScr_EfxReblowOBJ_R_A[];
extern CONST_DATA AnimScr AnimScr_EfxReblowOBJ_R_B[];
extern CONST_DATA AnimScr AnimScr_EfxRestOBJ[];
extern CONST_DATA AnimScr AnimScr_EfxSilenceOBJ[];
extern CONST_DATA AnimScr AnimScr_EfxHammarneOBJ[];
extern CONST_DATA AnimScr AnimScr_EfxSleepOBJ2[];
extern CONST_DATA AnimScr AnimScr_EfxSleepOBJ[];
extern CONST_DATA AnimScr AnimScr_EfxBerserk1[];
extern CONST_DATA AnimScr AnimScr_EfxBerserk2[];
extern CONST_DATA AnimScr AnimScr_EfxBerserk3[];
extern CONST_DATA AnimScr AnimScr_EfxBerserk4[];
extern CONST_DATA AnimScr AnimScr_EfxBerserk5[];
extern CONST_DATA AnimScr AnimScr_EfxBerserk6[];
extern CONST_DATA AnimScr AnimScr_EfxBerserk7[];
extern CONST_DATA AnimScr AnimScr_EfxBerserk8[];
extern CONST_DATA AnimScr AnimScr_EfxBerserk9[];
extern CONST_DATA AnimScr AnimScr_EfxBerserk10[];
extern CONST_DATA AnimScr AnimScr_EfxMshieldOBJ[];
extern CONST_DATA AnimScr AnimScr_EfxMshieldOBJ2[];
extern CONST_DATA AnimScr AnimScr_EfxAureolaOBJCtrl1[];
extern CONST_DATA AnimScr AnimScr_EfxAureolaOBJCtrl2[];
extern CONST_DATA AnimScr AnimScr_EfxAureolaOBJCtrl3[];
extern CONST_DATA AnimScr AnimScr_EfxAureolaOBJ2_1[];
extern CONST_DATA AnimScr AnimScr_EfxAureolaOBJ2_2[];
extern CONST_DATA AnimScr AnimScr_EfxAureolaOBJ3_1[];
extern CONST_DATA AnimScr AnimScr_EfxAureolaOBJ3_2[];
extern CONST_DATA struct ProcScr ProcScr_EkrDragonMoveBg3[];
extern CONST_DATA struct ProcScr ProcScr_EkrDragonBark[];
extern CONST_DATA struct ProcScr ProcScr_EkrManakete[];
extern CONST_DATA struct ProcScr ProcScr_EkrManaketeEnterfx[];
extern CONST_DATA struct ProcScr ProcScr_EkrManaketeExitfx[];
extern CONST_DATA struct ProcScr ProcScr_EkrManaketefx[];
extern CONST_DATA struct ProcScr ProcScr_EkrDragonFae[];
extern CONST_DATA struct ProcScr ProcScr_EkrFaefx[];
extern const u16 * CONST_DATA TsaArray_EkrFaefx[];
extern CONST_DATA struct ProcScr ProcScr_EkrDragonIdunn[];
extern CONST_DATA struct ProcScr ProcScr_EkrDragonfx_IdunnIntro[];
extern CONST_DATA struct ProcScr ProcScr_EkrDragonfx_IdunnBaseAppear[];
extern CONST_DATA struct ProcScr ProcScr_EkrDragonfx_IdunnBodyAnime[];
extern CONST_DATA struct ProcScr ProcScr_EkrDragonfx_IdunnExit2[];
extern CONST_DATA struct ProcScr ProcScr_EkrIdunnDeamon1[];
extern CONST_DATA struct ProcScr ProcScr_EkrIdunnDeamon2[];
extern CONST_DATA struct ProcScr ProcScr_EkrIdunnBodyMain[];
extern const u16 * CONST_DATA TsaArray_EkrIdunnBody[];
extern CONST_DATA struct ProcScr ProcScr_EkrIdunnAvoid[];
extern CONST_DATA struct ProcScr ProcScr_EkrIdunnExitAnim1[];
extern CONST_DATA struct ProcScr ProcScr_EkrIdunnDeadFlashing[];
extern CONST_DATA struct ProcScr ProcScr_EkrDragonDeath[];
extern AnimScr AnimScr_ManaketeEnter1[];
extern AnimScr AnimScr_ManaketeExit3[];
extern AnimScr AnimScr_ManaketeEnter2[];
extern AnimScr AnimScr_ManaketeExit2[];
extern AnimScr AnimScr_ManaketeEnter3[];
extern AnimScr AnimScr_ManaketeExit1[];
extern CONST_DATA AnimScr AnimScr_EkrIdunnDeamon1[];
extern CONST_DATA AnimScr AnimScr_EkrIdunnDeamon2[];
extern i16 PosArray_EfxApocalypseBGCtrl[];
// ??? gEfxTmyPalRefs
extern CONST_DATA struct ProcScr ProcScr_EkrSubAnimeEmulator[];
extern CONST_DATA struct ProcScr ProcScr_EfxSoundSE[];

extern CONST_DATA struct ProcScr ProcScr_EkrClasschg[];
extern CONST_DATA struct ProcScr ProcScr_EfxClasschgBG[];
extern CONST_DATA u16 *TsaArray_EkrClasschgBG[];
extern CONST_DATA u16 *ImgArray_EkrClasschgBG[];
extern CONST_DATA u16 *PalArray_EkrClasschgBG[];
extern CONST_DATA struct ProcScr ProcScr_EfxClasschgBGSE00[];
extern CONST_DATA struct ProcScr ProcScr_EfxClasschgBGSE01[];
extern CONST_DATA struct ProcScr ProcScr_EfxClasschgOBJ[];
extern CONST_DATA struct ProcScr ProcScr_EfxClasschgFIN[];
extern CONST_DATA struct ProcScr ProcScr_EfxClasschgCLONE[];
extern CONST_DATA struct ProcScr ProcScr_EfxBlackInOutUnit[];
extern CONST_DATA struct ProcScr ProcScr_EfxClasschgRST[];
extern CONST_DATA struct FaceVramEnt FaceConfig_EkrLevelup[];
extern CONST_DATA struct ProcScr ProcScr_EkrLevelup[];
extern CONST_DATA struct ProcScr ProcScr_EkrlvupSubAnimeEmulator[];
extern CONST_DATA struct ProcScr ProcScr_EfxPartsofScroll[];
extern CONST_DATA struct ProcScr ProcScr_EfxPartsofScroll2[];
extern CONST_DATA s16 EfxPartsofScroll2_RefTable[];
extern CONST_DATA struct ProcScr ProcScr_Efxleveluphb[];
extern CONST_DATA struct ProcScr ProcScr_EkrTriangle[];
extern CONST_DATA struct ProcScr ProcScr_EkrTriPegasusKnight[];
extern CONST_DATA struct ProcScr ProcScr_EkrTriPegasusKnightBG[];
extern CONST_DATA u16 *TsaArray_EkrTriPegagusBG[];
extern CONST_DATA struct ProcScr ProcScr_EkrTriPegasusKnightOBJ[];
extern CONST_DATA struct ProcScr ProcScr_EkrTriArmorKnight[];
extern CONST_DATA struct ProcScr ProcScr_EkrTriArmorKnightOBJ[];
extern CONST_DATA struct ProcScr ProcScr_EkrTriArmorKnightOBJ2[];
extern CONST_DATA struct ProcScr ProcScr_EfxTriangleQUAKE[];
extern CONST_DATA AnimScr AnimScr_TriAtkLeft[];
extern CONST_DATA AnimScr AnimScr_TriAtkRight[];
extern CONST_DATA AnimScr AnimScr_TriKnightOBJ[];
extern CONST_DATA AnimScr AnimScr_TriGenerialLanceOBJ[];
extern CONST_DATA AnimScr AnimScr_TriGenerialAxeOBJ[];
extern CONST_DATA AnimScr AnimScr_TriGenerialHandAxeOBJ[];
extern CONST_DATA AnimScr AnimScr_TriKnightAtkOBJ[];
extern CONST_DATA AnimScr AnimScr_TriGenerialLanceAtkOBJ[];
extern CONST_DATA AnimScr AnimScr_TriGenerialAxeAtkOBJ[];
extern CONST_DATA AnimScr AnimScr_TriGenerialHandAxeAtkOBJ[];
extern CONST_DATA AnimScr AnimScr_EkrPopup[];
extern CONST_DATA struct ProcScr ProcScr_EkrPopup[];

extern i16 const gEfxNoDmgBgShakeOff[];
extern i16 const gEfxQuakePureVec1[];
extern i16 const gEfxQuakePureVec2[];
extern i16 const gEfxQuakePureVec3[];
extern i16 const gEfxQuakePureVec4[];
extern i16 const gEfxQuakePureVec5[];
extern i16 const gEfxQuakePureVec6[];
extern i16 const gEfxQuakeVec_08111E14[];
extern i16 const gEfxQuakePureVec7[];
extern i16 const gEfxQuakePureVec8[];
extern i16 const gEfxQuakePureVec9[];
extern i16 const gEfxQuakePureVec10[];
extern i16 const gEfxQuakePureVec11[];
extern i16 const gEfxQuakeVec_08111F30[];
extern i16 const gEfxQuakeVec_08111FC6[];
// extern ??? RoundTypes_NormalPhy
// extern ??? RoundTypes_MissedPhy
// extern ??? RoundTypes_CriticalPhy
// extern ??? RoundTypes_TargetMiss
// extern ??? RoundTypes_TargetHitted
// extern ??? RoundTypes_NormalMag
// extern ??? RoundTypes_CriticalMag
// extern ??? RoundTypes_Dragon1
// extern ??? RoundTypes_Dragon2
// extern ??? RoundTypes_Dragon3
extern const u8 BanimDefaultModeConfig[ANIM_ROUND_MAX * 4];
extern const u8 BanimDefaultStandingTypes[5];
extern const u8 BanimTypesPosLeft[5];
extern const u8 BanimTypesPosRight[5];
extern const u16 BanimLeftDefaultPos[5];
extern const u16 Tsa_EkrTerrainfx_081122DA[];
extern u16 const FrameArray_EkrTogiColor[];
extern u16 TsaConf_BanimTmA_08112380[];
extern u16 TsaConf_BanimTmA_08112418[];
extern u16 TsaConf_BanimTmA_081124B0[];
extern u16 TsaConf_BanimTmA_08112548[];
extern u8 const Img_081125E0[];
extern u8 const Img_EfxLeftNameBox[];
extern u8 const Img_EfxLeftItemBox[];
extern u8 const Img_EfxRightNameBox[];
extern u8 const Img_EfxRightItemBox[];
extern u8 const Tsa_EkrDispUP_08112968[];
extern u8 const Tsa_EkrDispUP_08112A1C[];
extern u8 const gUnk_08112AD0[];
extern u8 const gUnk_08112BA4[];
extern u16 const Tsa_08112C84[];
extern u16 const Pal_08112CD4[];

extern u8 const Img_EfxSideHitDmgCrit[];
extern u8 const Img_EfxArrowWTA[];
extern u16 Img_EkrGaugeNumber[];
extern u16 Pal_EkrGauge_081131A4[];
extern u16 Pal_08113224[];
extern u16 gPalEfxHpBarPurple[];
extern u16 gPalEfxHpBarGreen[];
extern u16 Pal_081134C4[];
extern u16 const Pal_BanimUnitFlashing[];
extern u8 const Img_EkrExpBar[];
extern u8 const Img_EkrExpBarChange[];
extern u8 const Img_BarNumfx[];
extern u8 const Tsa_EkrExpBar[];
extern u16 const Pal_EkrExpBar[];
extern u8 const gUnk_08113D70[];
extern u16 const Pal_08113F98[];
extern u16 const Pal_08113FB8[];
extern u16 const Pal_08113FD8[];
extern u8 const Img_BanimArcherFBallistaIntro[];
extern u8 const Img_BanimArcherMBallistaIntro[];
extern u8 const Img_BanimSnipperFBallistaIntro[];
extern u8 const Img_LevelUpFrame[]; // img (stat gains)
extern u8 const Tm_LevelUpFrame[]; // tiles (stat gains)
extern u16 const Pal_LevelUpFrame[]; // pal (stat gains)
extern u8 const Img_LvupApfx[];
extern u16 const Pal_LvupApfx[];
extern u8 const Img_EkrPopup[];
extern u8 const Img_EkrUnkPopup[];
extern u16 const Pal_EkrPopup[];
extern u8 const Tsa_EkrPopup[];
extern u8 const Img_ArenaBattleBg[];
extern u8 const Tsa_ArenaBattleBg[];
extern u16 const Pal_ArenaBattleBg_A[];
extern u16 const Pal_ArenaBattleBg_B[];
extern u16 const Pal_ArenaBattleBg_C[];
extern u8 const Img_EkrBaseKaiten1[];
extern u8 const Img_EkrBaseKaiten2[];
extern u8 const Img_EkrBaseKaiten3[];
extern u8 const Img_EkrBaseKaiten4[];
extern u8 const Img_EkrBaseKaiten5[];
extern u16 const Pal_EkrBaseKaiten[];
extern u16 const FrameArray_EfxSongBGCOL[];
extern u16 const FrameConf_EfxEckesachsBGCOL[];
extern u16 const gUnk_08119D78[];
extern u16 const FrameConf_EfxDarkbreathBG[];
extern u16 const FrameConf_EfxDarkbreathBGCOL[];
extern u16 const FrameConf_EfxThunderBG[];
extern u16 const FrameConf_EfxThunderBGCOL[];
extern u16 const FrameConf_EfxFireBG[];
extern u16 const FrameConf_EfxFireHITBG[];
extern u16 const FrameConf_EfxElfireBGCOL[];
extern u16 const FrameConf_EfxFimbulvetrBGTR[];
extern u16 const FrameConf_EfxFimbulvetrBG[];
extern u16 const FrameConf_EfxThunderstormBG[];
extern u16 const FrameConf_EfxAlacaliburBG[];
extern u16 const FrameConf_EfxAlacaliburBGCOL[];
extern u16 const FrameConf_EfxMistyrainBG1[];
extern u16 const FrameConf_EfxMistyrainBG2[];
extern u16 const FrameConf_EfxResireBG[];
extern u16 const FrameConf_EfxResireBG3[];
extern u16 const FrameConf_EfxResireBG2[];
extern u16 const FrameConf_EfxLightningBG[];
extern u16 const FrameArray_EfxPurgeBG[];
extern u16 const FrameConf_EfxForblazeBG1[];
extern u16 const FrameArray_EfxForblazeBGCOL1[];
// extern ??? gUnk_0811A520
extern u16 const FrameArray_EfxDivineBG[];
extern u16 const FrameArray_EfxDivineBG2[];
extern u16 const FrameArray_EfxDivineBG3[];
extern u16 const FrameArray_EfxAureolaBG[];
extern u16 const FrameArray_EfxAureolaBG2COL[];
extern u16 const FrameArray_EfxApocalypseBGCOL2[];
extern u16 const FrameArray_EfxApocalypseBG2[];
extern u16 const FrameArray_EfxHazymoonBG1[];
extern u16 const FrameArray_EfxHazymoonBG2[];
extern u16 const FrameArray_EfxHazymoonBG3[];
extern u16 const FrameArray_EfxFenrirBGCOL[];
extern u16 const FrameArray_EfxFenrirBG2_A[];
extern const u16 Frames_EfxCriricalEffectBGCOL[];
extern const u16 FrameConf_EfxNormalEffectBG[];
extern u16 const FrameConfig_EfxMagFcastBg1[];
extern u16 const FrameConfig_EfxMagFcastBg2[];
extern u16 const FrameConfig_EfxMagFcastBg3[];
extern u16 const FrameConfig_EfxMagFcastBg4[];
extern u16 const FrameConf_EfxMagdhisEffectBG[];
extern u16 const FrameArray_EfxopFireBG[];
extern u16 const FrameArray_EfxopThunderBG[];
extern u16 const FrameArray_EfxopThunderBGCOL[];
// extern ??? frames
// extern ??? frames_EfxopLiveBGCOL
extern const u8 Img_TeonoOBJ[];
extern const u16 Pal_TeonoOBJ[];
extern const u8 Img_EfxArrowOBJ[];
extern const u8 Img_SpellJavelin[];
extern const u16 Pal_SpellJavelin[];
extern const u8 Img_SpellJavelinCavalier[];
extern const u16 Pal_SpellJavelinCavalier[];
extern const u8 Img_SpellJavelinSoldier[];
extern const u16 Pal_SpellJavelinSoldier[];
extern const u8 Img_SpellJavelinPaladin[];
extern const u16 Pal_SpellJavelinPaladin[];
extern const u8 Img_SpellJavelinPrgasusKnight[];
extern const u16 Pal_SpellJavelinPrgasusKnight[];
extern const u8 Img_SpellJavelinFalcon[];
extern const u16 Pal_SpellJavelinFalcon[];
extern const u8 Img_SpellJavelinWyvernRider[];
extern const u16 Pal_SpellJavelinWyvernRider[];
extern const u8 Img_SpellJavelinWyvernLord[];
extern const u16 Pal_SpellJavelinWyvernLord[];
extern const u8 Img_SpellJavelinGenerial[];
extern const u16 Pal_SpellJavelinGenerial[];
extern const u8 Img_EfxSongFE6[];
extern const u16 Pal_EfxSongFE6[];
extern const u8 Img_EfxSongBG[];
extern const u16 Pal_EfxSongBG[];
extern const u16 Tsa_EfxSongBG[];
extern const u8 Img_EfxEckesachsBG[];
extern const u16 Pal_EfxEckesachsBG[];
extern const u16 Tsa_EfxEckesachsBG[];
extern const u8 Img_BreathSprites[];
extern u16 Pal_EfxBindingBlade[];
extern u16 Img_EfxHurtmutEff00OBJ1[];
extern u16 Img_EfxHurtmutEff00OBJ2[];
extern u16 Pal_EfxHurtmutEff00OBJ[];
extern u16 Pal_IceBreathSprites[];
extern u16 Pal_DarkBreathSprites[];
extern u16 Img_EfxDarkbreathBG[];
extern u16 Tsa_EfxDarkbreathBG1[];
extern u16 Tsa_EfxDarkbreathBG2[];
extern u16 Tsa_EfxDarkbreathBG3[];
extern u16 Tsa_EfxDarkbreathBG4[];
extern u16 Tsa_EfxDarkbreathBG5[];
extern u16 Tsa_EfxDarkbreathBG6[];
extern u16 Tsa_EfxDarkbreathBG7[];
extern u16 Tsa_EfxDarkbreathBG8[];
extern u16 Tsa_EfxDarkbreathBG9[];
extern u16 Tsa_EfxDarkbreathBG10[];
extern u16 Tsa_EfxDarkbreathBG11[];
extern u16 Tsa_EfxDarkbreathBG12[];
extern u16 Img_EfxCriricalEffectBG[];
extern u16 Pal_EfxCriricalEffectBG[];
extern u16 Tsa_EfxCriricalEffectBG_L[];
extern u16 Tsa_EfxCriricalEffectBG_R[];
extern u16 Img_EfxSRankWeaponEffectBG[];
extern u16 Pal_EfxSRankWeaponEffectBG[];
extern u16 Tsa_EfxSRankWeaponEffectBG[];
extern u16 Img_EfxNormalEffectBG[];
extern u16 Pal_EfxNormalEffectBG[];
extern u16 Tsa1_EfxNormalEffectBG[];
extern u16 Tsa2_EfxNormalEffectBG[];
extern u16 Tsa3_EfxNormalEffectBG[];
extern u16 Tsa4_EfxNormalEffectBG[];
extern u16 Tsa5_EfxNormalEffectBG[];
extern u16 Tsa6_EfxNormalEffectBG[];
extern u16 Tsa7_EfxNormalEffectBG[];
extern u16 Tsa8_EfxNormalEffectBG[];
extern u16 Tsa9_EfxNormalEffectBG[];
extern u16 TsaA_EfxNormalEffectBG[];
extern u16 Img_EkrClasschgBG_0812542C[];
extern u16 Img_EkrClasschgBG_081269BC[];
extern u16 Pal_EkrClasschgBG_08127738[];
extern u16 Pal_EkrClasschgBG_08127758[];
extern u16 Pal_EfxClasschgFIN[];
extern u16 Tsa_EkrClasschgBG_08127798[];
extern u16 Tsa_EkrClasschgBG_08127950[];
extern u16 Tsa_EkrClasschgBG_08127AE4[];
extern u16 Tsa_EkrClasschgBG_08127C9C[];
extern u16 Tsa_EkrClasschgBG_08127E60[];
extern u16 Tsa_EkrClasschgBG_08127F9C[];
extern u16 Tsa_EkrClasschgBG_08128034[];
extern u16 Tsa_EkrClasschgBG_08128128[];
extern u16 Tsa_EkrClasschgBG_08128218[];
extern u16 Tsa_EkrClasschgBG_08128308[];
extern u16 Tsa_EkrClasschgBG_08128470[];
extern u16 Tsa_EkrClasschgBG_08128584[];
extern u16 Tsa_EkrClasschgBG_08128700[];
extern u16 Tsa_EkrClasschgBG_08128828[];
extern u16 Tsa_EkrClasschgBG_08128A0C[];
extern u16 Tsa_EkrClasschgBG_08128B5C[];
extern u16 Tsa_EkrClasschgBG_08128CE8[];
extern u16 Tsa_EkrClasschgBG_08128DD4[];
extern u16 Tsa_EkrClasschgBG_08128EB4[];
extern u16 Tsa_EkrClasschgBG_08128FAC[];
extern u16 Tsa_EkrClasschgBG_081290D0[];
extern u16 Tsa_EkrClasschgBG_0812921C[];
extern u16 Tsa_EkrClasschgBG_0812938C[];
extern u16 Img_EfxMagfcastBG[];
extern u16 Pal_EfxMagfcastBG[];
extern u16 Tsa1_EfxMagfcastBG[];
extern u16 Tsa2_EfxMagfcastBG[];
extern u16 Tsa3_EfxMagfcastBG[];
extern u16 Tsa4_EfxMagfcastBG[];
extern u16 Tsa5_EfxMagfcastBG[];
extern u16 Tsa6_EfxMagfcastBG[];
extern u16 Tsa7_EfxMagfcastBG[];
extern u16 Tsa8_EfxMagfcastBG[];
extern u16 Tsa9_EfxMagfcastBG[];
extern u16 Tsa10_EfxMagfcastBG[];
extern u16 Tsa11_EfxMagfcastBG[];
extern u16 Tsa12_EfxMagfcastBG[];
extern u16 Tsa13_EfxMagfcastBG[];
extern u16 Tsa14_EfxMagfcastBG[];
extern u16 Tsa15_EfxMagfcastBG[];
extern u16 Tsa16_EfxMagfcastBG[];
extern u16 Tsa17_EfxMagfcastBG[];
extern u16 Tsa18_EfxMagfcastBG[];
extern u16 Tsa19_EfxMagfcastBG[];
extern u16 Tsa20_EfxMagfcastBG[];
extern u16 Tsa21_EfxMagfcastBG[];
extern u16 Tsa22_EfxMagfcastBG[];
extern u16 Img_EfxMagdhisEffectBG[];
extern u16 Pal_EfxMagdhisEffectBG[];
extern u16 Tsa1_EfxMagdhisEffectBG[];
extern u16 Tsa2_EfxMagdhisEffectBG[];
extern u16 Tsa3_EfxMagdhisEffectBG[];
extern u16 Tsa4_EfxMagdhisEffectBG[];
extern u16 Img_EfxSunakemuriOBJ[];
extern u16 Pal_EfxSunakemuriOBJ1[];
extern u16 Pal_EfxSunakemuriOBJ2[];
extern u16 Pal_EfxSunakemuriOBJ3[];
extern u16 Img_EfxThunderBG[];
extern u16 Pal_EfxThunderBGCOL[];
extern u16 Tsa_EfxThuderBg1[];
extern u16 Tsa_EfxThuderBg2[];
extern u16 Img_EfxThunderOBJ[];
extern u16 Pal_EfxThunderOBJ[];
extern u16 Img_EfxFireBG[];
extern u16 Pal_EfxFireBG[];
extern u16 Tsa_EfxFireBG_0812E4C4[];
extern u16 Tsa_EfxFireBG_0812E56C[];
extern u16 Tsa_EfxFireBG_0812E614[];
extern u16 Tsa_EfxFireBG_0812E6CC[];
extern u16 Tsa_EfxFireBG_0812E794[];
extern u16 Tsa_EfxFireBG_0812E864[];
extern u16 Tsa_EfxFireBG_0812E964[];
extern u16 Tsa_EfxFireBG_0812EA6C[];
extern u16 Tsa_EfxFireBG_0812EB80[];
extern u16 Tsa_EfxFireBG_0812ECB8[];
extern u16 Tsa_EfxFireBG_0812EDBC[];
extern u16 Tsa_EfxFireBG_0812EE90[];
extern u16 Tsa_EfxFireBG_0812EF50[];
extern u16 Tsa_EfxFireBG_0812EFF8[];
extern u16 Tsa_EfxFireBG_0812F0A0[];
extern u16 Tsa_EfxFireBG_0812F158[];
extern u16 Tsa_EfxFireBG_0812F220[];
extern u16 Tsa_EfxFireBG_0812F2F0[];
extern u16 Tsa_EfxFireBG_0812F3F0[];
extern u16 Tsa_EfxFireBG_0812F4F8[];
extern u16 Tsa_EfxFireBG_0812F60C[];
extern u16 Tsa_EfxFireBG_0812F744[];
extern u16 Tsa_EfxFireBG_0812F848[];
extern u16 Tsa_EfxFireBG_0812F91C[];
extern u16 Img_EfxFireOBJ[];
extern u16 Pal_EfxFireOBJ[];
extern u16 Img_EfxFireHITBG_0812FFF8[];
extern u16 Img_EfxFireHITBG_08130D34[];
extern u16 Img_EfxFireHITBG_08131A10[];
extern u16 Img_EfxFireHITBG_08132838[];
extern u16 Img_EfxFireHITBG_0813382C[];
extern u16 Img_EfxFireHITBG_08134AC8[];
extern u16 Img_EfxFireHITBG_08135694[];
extern u16 Img_EfxFireHITBG_0813628C[];
extern u16 Img_EfxFireHITBG_08136DE4[];
extern u16 Img_EfxFireHITBG_081378E0[];
extern u16 Img_EfxFireHITBG_081382E8[];
extern u16 Tsa_EfxFireHITBG_08138C10[];
extern u16 Tsa_EfxFireHITBG_08138CBC[];
extern u16 Tsa_EfxFireHITBG_08138D74[];
extern u16 Tsa_EfxFireHITBG_08138E40[];
extern u16 Tsa_EfxFireHITBG_08138F20[];
extern u16 Tsa_EfxFireHITBG_08139014[];
extern u16 Tsa_EfxFireHITBG_0813912C[];
extern u16 Tsa_EfxFireHITBG_08139258[];
extern u16 Tsa_EfxFireHITBG_08139390[];
extern u16 Tsa_EfxFireHITBG_081394D4[];
extern u16 Tsa_EfxFireHITBG_08139628[];
extern u16 Tsa_EfxFireHITBG_08139780[];
extern u16 Tsa_EfxFireHITBG_081398E8[];
extern u16 Tsa_EfxFireHITBG_08139A54[];
extern u16 Tsa_EfxFireHITBG_08139BD0[];
extern u16 Tsa_EfxFireHITBG_08139D64[];
extern u16 Tsa_EfxFireHITBG_08139F04[];
extern u16 Tsa_EfxFireHITBG_0813A0A4[];
extern u16 Tsa_EfxFireHITBG_0813A244[];
extern u16 Tsa_EfxFireHITBG_0813A3E4[];
extern u16 Tsa_EfxFireHITBG_0813A574[];
extern u16 Pal_EfxFireHITBG[];
extern u16 Img_EfxElfireBG[];
extern u16 Pal_EfxElfireBGCOL[];
extern u16 Tsa_EfxElfireBG[];
extern u16 Tsa_FireBreathBg[];
extern u16 Img_EfxElfireOBJ[];
extern u16 Pal_EfxElfireOBJ[];
extern u16 Img_EfxThunderstormBG_0813BD94[];
extern u16 Img_EfxThunderstormBG_0813C964[];
extern u16 Img_EfxThunderstormBG_0813D9D0[];
extern u16 Pal_EfxThunderstormBG[];
extern u16 Tsa_EfxThunderstormBG_0813E7BC[];
extern u16 Tsa_EfxThunderstormBG_0813E950[];
extern u16 Tsa_EfxThunderstormBG_0813EB58[];
extern u16 Tsa_EfxThunderstormBG_0813ECBC[];
extern u16 Tsa_EfxThunderstormBG_0813ED9C[];
extern u16 Tsa_EfxThunderstormBG_0813EEB4[];
extern u16 Tsa_EfxThunderstormBG_0813F060[];
extern u16 Tsa_EfxThunderstormBG_0813F180[];
extern u16 Tsa_EfxThunderstormBG_0813F26C[];
extern u16 Tsa_EfxThunderstormBG_0813F354[];
extern u16 Tsa_EfxThunderstormBG_0813F3EC[];
extern u16 Img_EfxForblazeBG1_0813F5E0[];
extern u16 Img_EfxForblazeBG1_0813FF7C[];
extern u16 Tsa_EfxForblazeBG1_0814092C[];
extern u16 Tsa_EfxForblazeBG1_081409DC[];
extern u16 Tsa_EfxForblazeBG1_08140A98[];
extern u16 Tsa_EfxForblazeBG1_08140B60[];
extern u16 Tsa_EfxForblazeBG1_08140C30[];
extern u16 Tsa_EfxForblazeBG1_08140D00[];
extern u16 Tsa_EfxForblazeBG1_08140DCC[];
extern u16 Tsa_EfxForblazeBG1_08140E98[];
extern u16 Tsa_EfxForblazeBG1_08140F7C[];
extern u16 Tsa_EfxForblazeBG1_08141050[];
extern u16 Tsa_EfxForblazeBG1_08141114[];
extern u16 Tsa_EfxForblazeBG1_081411D4[];
extern u16 Tsa_EfxForblazeBG1_08141288[];
extern u16 Pal_EfxForblazeBG1[];
extern u16 Img1_EfxForblazeBG2[];
extern u16 Img2_EfxForblazeBG2[];
extern u16 Pal1_EfxForblazeBG2[];
extern u16 Pal2_EfxForblazeBG2[];
extern u16 Pal3_EfxForblazeBG2[];
extern u16 Pal4_EfxForblazeBG2[];
extern u16 Tsa1_EfxForblazeBG2[];
extern u16 Tsa2_EfxForblazeBG2[];
extern u16 Img_EfxForblazeOBJ[];
extern u16 Pal_EfxForblazeOBJ[];
extern u16 Img_EfxFimbulvetrBG_08144A20[];
extern u16 Img_EfxFimbulvetrBG_08145CF0[];
extern u16 Img_EfxFimbulvetrBG_081475A0[];
extern u16 Img_EfxFimbulvetrBG_081489E4[];
extern u16 Pal_EfxFimbulvetrBG[];
extern u16 Tsa_EfxFimbulvetrBG_0814A4B8[];
extern u16 Tsa_EfxFimbulvetrBG_0814A55C[];
extern u16 Tsa_EfxFimbulvetrBG_0814A604[];
extern u16 Tsa_EfxFimbulvetrBG_0814A6C0[];
extern u16 Tsa_EfxFimbulvetrBG_0814A794[];
extern u16 Tsa_EfxFimbulvetrBG_0814A890[];
extern u16 Tsa_EfxFimbulvetrBG_0814A9D0[];
extern u16 Tsa_EfxFimbulvetrBG_0814AB68[];
extern u16 Tsa_EfxFimbulvetrBG_0814AD3C[];
extern u16 Tsa_EfxFimbulvetrBG_0814AF4C[];
extern u16 Tsa_EfxFimbulvetrBG_0814B16C[];
extern u16 Img_EfxFimbulvetrBGTR_0814B39C[];
extern u16 Img_EfxFimbulvetrBGTR_0814C5A4[];
extern u16 Img_EfxFimbulvetrBGTR_0814D700[];
extern u16 Img_EfxFimbulvetrBGTR_0814E784[];
extern u16 Img_EfxFimbulvetrBGTR_0814FBC4[];
extern u16 Img_EfxFimbulvetrBGTR_08150F7C[];
extern u16 Pal_EfxFimbulvetrBGTR[];
extern u16 Tsa_EfxFimbulvetrBGTR_081521E0[];
extern u16 Tsa_EfxFimbulvetrBGTR_081523CC[];
extern u16 Tsa_EfxFimbulvetrBGTR_081525A4[];
extern u16 Tsa_EfxFimbulvetrBGTR_0815276C[];
extern u16 Tsa_EfxFimbulvetrBGTR_081529A0[];
extern u16 Tsa_EfxFimbulvetrBGTR_08152BE8[];
extern u16 Img_EfxFimbulvetrOBJ[];
extern u16 Img_EfxLightningBG_081531C8[];
extern u16 Img_EfxLightningBG_08153A90[];
extern u16 Img_EfxLightningBG_081541E0[];
extern u16 Img_EfxLightningBG_08154BA4[];
extern u16 Img_EfxLightningBG_081556F8[];
extern u16 Img_EfxLightningBG_08156200[];
extern u16 Img_EfxLightningBG_08156518[];
extern u16 Img_EfxLightningBG_081571C8[];
extern u16 Pal_EfxLightningBG_08157BE8[];
extern u16 Pal_EfxLightningBG_08157C08[];
extern u16 Tsa_EfxLightningBG_08157C28[];
extern u16 Tsa_EfxLightningBG_08157D4C[];
extern u16 Tsa_EfxLightningBG_08157E6C[];
extern u16 Tsa_EfxLightningBG_08157F78[];
extern u16 Tsa_EfxLightningBG_08158074[];
extern u16 Tsa_EfxLightningBG_0815815C[];
extern u16 Tsa_EfxLightningBG_08158244[];
extern u16 Tsa_EfxLightningBG_08158328[];
extern u16 Tsa_EfxLightningBG_08158404[];
extern u16 Tsa_EfxLightningBG_081584E4[];
extern u16 Tsa_EfxLightningBG_081585D8[];
extern u16 Tsa_EfxLightningBG_081586CC[];
extern u16 Tsa_EfxLightningBG_081587D0[];
extern u16 Tsa_EfxLightningBG_081588D8[];
extern u16 Tsa_EfxLightningBG_081589F0[];
extern u16 Tsa_EfxLightningBG_08158B14[];
extern u16 Tsa_EfxLightningBG_08158C28[];
extern u16 Tsa_EfxLightningBG_08158CD8[];
extern u16 Tsa_EfxLightningBG_08158DE0[];
extern u16 Tsa_EfxLightningBG_08158F1C[];
extern u16 Tsa_EfxLightningBG_08159090[];
extern u16 Tsa_EfxLightningBG_08159228[];
extern u16 Tsa_EfxLightningBG_0815939C[];
extern u16 Tsa_EfxLightningBG_081594A8[];
extern u16 Tsa_EfxLightningBG_0815957C[];
extern u16 Tsa_EfxLightningBG_0815961C[];
extern u16 Tsa_EfxLightningBG_0815973C[];
extern u16 Tsa_EfxLightningBG_08159858[];
extern u16 Tsa_EfxLightningBG_0815996C[];
extern u16 Tsa_EfxLightningBG_08159A64[];
extern u16 Tsa_EfxLightningBG_08159B4C[];
extern u16 Tsa_EfxLightningBG_08159C1C[];
extern u16 Tsa_EfxLightningBG_08159CE0[];
extern u16 Img_EfxAlacaliburBG[];
extern u16 Pal_EfxAlacaliburBGCOL[];
extern u16 Tsa_EfxAlacaliburBG_0815B424[];
extern u16 Tsa_EfxAlacaliburBG_0815B5AC[];
extern u16 Img_EfxAlacaliburOBJ[];
extern u16 Pal_EfxAlacaliburOBJ[];
extern u16 Img_EfxMistyrainBG_0815BEF4[];
extern u16 Img_EfxMistyrainBG_0815CAC4[];
extern u16 Img_EfxMistyrainBG_0815D7D4[];
extern u16 Img_EfxMistyrainBG_0815EA30[];
extern u16 Img_EfxMistyrainBG_0815F0B4[];
extern u16 Img_EfxMistyrainBG_0815F610[];
extern u16 Pal_EfxMistyrainBG1[];
extern u16 Tsa_EfxMistyrainBG_0815F8C0[];
extern u16 Tsa_EfxMistyrainBG_0815F9BC[];
extern u16 Tsa_EfxMistyrainBG_0815FABC[];
extern u16 Tsa_EfxMistyrainBG_0815FBC0[];
extern u16 Tsa_EfxMistyrainBG_0815FCB8[];
extern u16 Tsa_EfxMistyrainBG_0815FDC4[];
extern u16 Tsa_EfxMistyrainBG_0815FED0[];
extern u16 Tsa_EfxMistyrainBG_0815FFF0[];
extern u16 Tsa_EfxMistyrainBG_08160114[];
extern u16 Tsa_EfxMistyrainBG_081601FC[];
extern u16 Tsa_EfxMistyrainBG_081602D8[];
extern u16 Tsa_EfxMistyrainBG_08160398[];
extern u16 Tsa_EfxMistyrainBG_08160450[];
extern u16 Tsa_EfxMistyrainBG_081604F8[];
extern u16 Tsa_EfxMistyrainBG_081605B4[];
extern u16 Tsa_EfxMistyrainBG_0816068C[];
extern u16 Tsa_EfxMistyrainBG_0816076C[];
extern u16 Tsa_EfxMistyrainBG_0816085C[];
extern u16 Tsa_EfxMistyrainBG_08160958[];
extern u16 Tsa_EfxMistyrainBG_08160A4C[];
extern u16 Tsa_EfxMistyrainBG_08160B44[];
extern u16 Tsa_EfxMistyrainBG_08160C30[];
extern u16 Tsa_EfxMistyrainBG_08160D14[];
extern u16 Tsa_EfxMistyrainBG_08160DEC[];
extern u16 Tsa_EfxMistyrainBG_08160EBC[];
extern u16 Tsa_EfxMistyrainBG_08160F88[];
extern u16 Tsa_EfxMistyrainBG_08161050[];
extern u16 Tsa_EfxMistyrainBG_08161104[];
extern u16 Tsa_EfxMistyrainBG_081611B8[];
extern u16 Tsa_EfxMistyrainBG_08161258[];
extern u16 Tsa_EfxMistyrainBG_0816130C[];
extern u16 Tsa_EfxMistyrainBG_081613C8[];
extern u16 Tsa_EfxMistyrainBG_081614A4[];
extern u16 Tsa_EfxMistyrainBG_0816158C[];
extern u16 Tsa_EfxMistyrainBG_081616B0[];
extern u16 Tsa_EfxMistyrainBG_081617D0[];
extern u16 Tsa_EfxMistyrainBG_081618DC[];
extern u16 Tsa_EfxMistyrainBG_081619E8[];
extern u16 Tsa_EfxMistyrainBG_08161AE4[];
extern u16 Tsa_EfxMistyrainBG_08161BE4[];
extern u16 Tsa_EfxMistyrainBG_08161CE0[];
extern u16 Pal_EfxMistyrainBG2[];
extern u16 Img_EfxMistyrainOBJ1_1[];
extern u16 Img_EfxMistyrainOBJ1_2[];
extern u16 Img_EfxMistyrainOBJ1_3[];
extern u16 Pal_EfxMistyrainOBJ1[];
extern u16 Img_EfxResireBG_081629F4[];
extern u16 Img_EfxResireBG_081634C4[];
extern u16 Img_EfxResireBG_0816406C[];
extern u16 Img_EfxResireBG_08164BC4[];
extern u16 Img_EfxResireBG_08165678[];
extern u16 Img_EfxResireBG_08166148[];
extern u16 Img_EfxResireBG_08166E0C[];
extern u16 Img_EfxResireBG_08167710[];
extern u16 Img_EfxResireBG_08167C64[];
extern u16 Img_EfxResireBG_0816857C[];
extern u16 Img_EfxResireBG_081691B0[];
extern u16 Img_EfxResireBG_08169E54[];
extern u16 Img_EfxResireBG_0816AA48[];
extern u16 Pal_EfxResireBG[];
extern u16 Tsa_EfxResireBG_0816B348[];
extern u16 Tsa_EfxResireBG_0816B478[];
extern u16 Tsa_EfxResireBG_0816B524[];
extern u16 Tsa_EfxResireBG_0816B5D4[];
extern u16 Tsa_EfxResireBG_0816B68C[];
extern u16 Tsa_EfxResireBG_0816B74C[];
extern u16 Tsa_EfxResireBG_0816B818[];
extern u16 Tsa_EfxResireBG_0816B8F8[];
extern u16 Tsa_EfxResireBG_0816B9E0[];
extern u16 Tsa_EfxResireBG_0816BAE8[];
extern u16 Tsa_EfxResireBG_0816BC04[];
extern u16 Tsa_EfxResireBG_0816BD40[];
extern u16 Tsa_EfxResireBG_0816BE90[];
extern u16 Tsa_EfxResireBG_0816BFE8[];
extern u16 Tsa_EfxResireBG_0816C140[];
extern u16 Tsa_EfxResireBG_0816C294[];
extern u16 Tsa_EfxResireBG_0816C3E4[];
extern u16 Tsa_EfxResireBG_0816C534[];
extern u16 Tsa_EfxResireBG_0816C66C[];
extern u16 Tsa_EfxResireBG_0816C798[];
extern u16 Tsa_EfxResireBG_0816C8B4[];
extern u16 Tsa_EfxResireBG_0816C9C0[];
extern u16 Tsa_EfxResireBG_0816CAB8[];
extern u16 Tsa_EfxResireBG_0816CBA4[];
extern u16 Tsa_EfxResireBG_0816CC74[];
extern u16 Tsa_EfxResireBG_0816CD30[];
extern u16 Tsa_EfxResireBG_0816CDE4[];
extern u16 Tsa_EfxResireBG_0816CE94[];
extern u16 Tsa_EfxResireBG_0816CF40[];
extern u16 Tsa_EfxResireBG_0816CFE8[];
extern u16 Tsa_EfxResireBG_0816D09C[];
extern u16 Tsa_EfxResireBG_0816D15C[];
extern u16 Tsa_EfxResireBG_0816D228[];
extern u16 Tsa_EfxResireBG_0816D2F0[];
extern u16 Tsa_EfxResireBG_0816D3B8[];
extern u16 Tsa_EfxResireBG_0816D48C[];
extern u16 Tsa_EfxResireBG_0816D568[];
extern u16 Tsa_EfxResireBG_0816D650[];
extern u16 Tsa_EfxResireBG_0816D744[];
extern u16 Tsa_EfxResireBG_0816D84C[];
extern u16 Tsa_EfxResireBG_0816D954[];
extern u16 Tsa_EfxResireBG_0816DA78[];
extern u16 Tsa_EfxResireBG_0816DB98[];
extern u16 Tsa_EfxResireBG_0816DCB4[];
extern u16 Tsa_EfxResireBG_0816DDC4[];
extern u16 Tsa_EfxResireBG_0816DED0[];
extern u16 Tsa_EfxResireBG_0816DFD0[];
extern u16 Tsa_EfxResireBG_0816E0C0[];
extern u16 Tsa_EfxResireBG_0816E19C[];
extern u16 Tsa_EfxResireBG_0816E268[];
extern u16 Tsa_EfxResireBG_0816E320[];
extern u16 Img_EfxDivineBG1_081762DC[];
extern u16 Img_EfxDivineBG3_0816E3CC[];
extern u16 Img_EfxDivineBG3_0816E980[];
extern u16 Img_EfxDivineBG3_0816F048[];
extern u16 Img_EfxDivineBG3_0816F688[];
extern u16 Img_EfxDivineBG3_0816FC90[];
extern u16 Img_EfxDivineBG3_081702F0[];
extern u16 Img_EfxDivineBG3_08170960[];
extern u16 Img_EfxDivineBG3_08170F9C[];
extern u16 Img_EfxDivineBG3_081715E4[];
extern u16 Img_EfxDivineBG3_08171CE8[];
extern u16 Img_EfxDivineBG3_081724A0[];
extern u16 Img_EfxDivineBG3_08172C94[];
extern u16 Img_EfxDivineBG3_0817346C[];
extern u16 Img_EfxDivineBG3_08173C88[];
extern u16 Img_EfxDivineBG3_08174408[];
extern u16 Img_EfxDivineBG3_08174B9C[];
extern u16 Img_EfxDivineBG3_081752D0[];
extern u16 Img_EfxDivineBG3_08175D7C[];
extern u16 Pal_EfxDivineBG3[];
extern u16 Pal_EfxDivineBG[];
extern u16 Tsa_EfxDivineBG3_08176A8C[];
extern u16 Tsa_EfxDivineBG3_08176C20[];
extern u16 Tsa_EfxDivineBG3_08176E24[];
extern u16 Tsa_EfxDivineBG3_081770F4[];
extern u16 Tsa_EfxDivineBG3_081773C4[];
extern u16 Tsa_EfxDivineBG3_08177674[];
extern u16 Tsa_EfxDivineBG3_08177928[];
extern u16 Tsa_EfxDivineBG3_08177BB4[];
extern u16 Tsa_EfxDivineBG3_08177E38[];
extern u16 Tsa_EfxDivineBG3_081780AC[];
extern u16 Tsa_EfxDivineBG3_08178340[];
extern u16 Tsa_EfxDivineBG3_081785C8[];
extern u16 Tsa_EfxDivineBG3_08178864[];
extern u16 Tsa_EfxDivineBG3_08178AEC[];
extern u16 Tsa_EfxDivineBG3_08178D68[];
extern u16 Tsa_EfxDivineBG3_08178F98[];
extern u16 Tsa_EfxDivineBG3_081791E8[];
extern u16 Tsa_EfxDivineBG3_08179418[];
extern u16 Tsa_EfxDivineBG3_08179610[];
extern u16 Tsa_EfxDivineBG3_081797F4[];
extern u16 Tsa_EfxDivineBG3_08179990[];
extern u16 Tsa_EfxDivineBG1_08179AB8[];
extern u16 Tsa_EfxDivineBG1_08179B58[];
extern u16 Tsa_EfxDivineBG1_08179C00[];
extern u16 Tsa_EfxDivineBG1_08179CA8[];
extern u16 Tsa_EfxDivineBG1_08179D58[];
extern u16 Tsa_EfxDivineBG1_08179E10[];
extern u16 Tsa_EfxDivineBG1_08179EDC[];
extern u16 Tsa_EfxDivineBG1_08179FA8[];
extern u16 Tsa_EfxDivineBG1_0817A07C[];
extern u16 Tsa_EfxDivineBG1_0817A154[];
extern u16 Tsa_EfxDivineBG1_0817A230[];
extern u16 Tsa_EfxDivineBG1_0817A30C[];
extern u16 Tsa_EfxDivineBG1_0817A3F0[];
extern u16 Tsa_EfxDivineBG1_0817A4A4[];
extern u16 Tsa_EfxDivineBG1_0817A540[];
extern u16 Tsa_EfxDivineBG1_0817A5DC[];
extern u16 Tsa_EfxDivineBG1_0817A678[];
extern u16 Tsa_EfxDivineBG1_0817A714[];
extern u16 Tsa_EfxDivineBG1_0817A7B0[];
extern u16 Tsa_EfxDivineBG1_0817A84C[];
extern u16 Tsa_EfxDivineBG2_0817A8E8[];
extern u16 Tsa_EfxDivineBG2_0817A984[];
extern u16 Tsa_EfxDivineBG2_0817AA20[];
extern u16 Img_EfxDivineOBJ[];
extern u16 Pal_EfxDivineOBJ[];
extern u8 Img_EfxApocalypseBG[];
extern u16 Pal_EfxApocalypse_0817B418[];
extern u16 Tsa_EfxApocalypseBG[];
extern u16 Img_EfxApocalypseOBJ[];
extern u16 Pal_EfxApocalypseOBJ[];
extern u16 Pals_EfxApocalypseBGCOL2[];
extern u16 Img_EfxApocalypseBG2_0817BBD4[];
extern u16 Img_EfxApocalypseBG2_0817D4E0[];
extern u16 Img_EfxApocalypseBG2_0817ED8C[];
extern u16 Img_EfxApocalypseBG2_081804F4[];
extern u16  Pal_EfxApocalypseBG2[];
extern u16 Tsa_EfxApocalypseBG2_08181E80[];
extern u16 Tsa_EfxApocalypseBG2_08182320[];
extern u16 Tsa_EfxApocalypseBG2_081827B0[];
extern u16 Tsa_EfxApocalypseBG2_08182C4C[];
extern u16  Img_EfxApocalypseOBJ2_1[];
extern u16  Img_EfxApocalypseOBJ2_2[];
extern u16 Img_EfxHazymoonBG_0818398C[];
extern u16 Img_EfxHazymoonBG_08183CD4[];
extern u16 Img_EfxHazymoonBG_081845A8[];
extern u16 Img_EfxHazymoonBG_081855E4[];
extern u16 Img_EfxHazymoonBG_08186250[];
extern u16 Img_EfxHazymoonBG_08186E6C[];
extern u16 Img_EfxHazymoonBG_081879C4[];
extern u16 Img_EfxHazymoonBG_08188518[];
extern u16 Img_EfxHazymoonBG_08188FC8[];
extern u16 Img_EfxHazymoonBG_081899F0[];
extern u16 Img_EfxHazymoonBG_0818A2EC[];
extern u16 Img_EfxHazymoonBG_0818ABB8[];
extern u16 Img_EfxHazymoonBG_0818B438[];
extern u16  Pal_EfxHazymoonBG2[];
extern u16  Pal_EfxHazymoonBG3[];
extern u16 Tsa_EfxHazymoonBG_0818BC0C[];
extern u16 Tsa_EfxHazymoonBG_0818BDB0[];
extern u16 Tsa_EfxHazymoonBG_0818BE50[];
extern u16 Tsa_EfxHazymoonBG_0818BEF0[];
extern u16 Tsa_EfxHazymoonBG_0818BFA4[];
extern u16 Tsa_EfxHazymoonBG_0818C058[];
extern u16 Tsa_EfxHazymoonBG_0818C10C[];
extern u16 Tsa_EfxHazymoonBG_0818C1E8[];
extern u16 Tsa_EfxHazymoonBG_0818C2C4[];
extern u16 Tsa_EfxHazymoonBG_0818C3D8[];
extern u16 Tsa_EfxHazymoonBG_0818C4EC[];
extern u16 Tsa_EfxHazymoonBG_0818C600[];
extern u16 Tsa_EfxHazymoonBG_0818C714[];
extern u16 Tsa_EfxHazymoonBG_0818C828[];
extern u16 Tsa_EfxHazymoonBG_0818C934[];
extern u16 Tsa_EfxHazymoonBG_0818CA0C[];
extern u16 Tsa_EfxHazymoonBG_0818CB1C[];
extern u16 Tsa_EfxHazymoonBG_0818CC84[];
extern u16 Tsa_EfxHazymoonBG_0818CE48[];
extern u16 Tsa_EfxHazymoonBG_0818D00C[];
extern u16 Tsa_EfxHazymoonBG_0818D1C8[];
extern u16 Tsa_EfxHazymoonBG_0818D378[];
extern u16 Tsa_EfxHazymoonBG_0818D528[];
extern u16 Tsa_EfxHazymoonBG_0818D6D8[];
extern u16 Tsa_EfxHazymoonBG_0818D87C[];
extern u16 Tsa_EfxHazymoonBG_0818DA14[];
extern u16 Tsa_EfxHazymoonBG_0818DBA4[];
extern u16  Img_EfxHazymoonOBJ2_1[];
extern u16  Img_EfxHazymoonOBJ2_2[];
extern u16  Img_EfxHazymoonOBJ2_3[];
extern u16  Pal_EfxHazymoonOBJ2[];
extern u16  Img_EfxFenrirBG[];
extern u16  Pal_EfxFenrirBGCOL[];
extern u16  Tsa_EfxFenrirBG[];
extern u16 Img_EfxFenrirBG2_A_0818F5EC[];
extern u16 Img_EfxFenrirBG2_A_08190804[];
extern u16 Img_EfxFenrirBG2_A_08191B54[];
extern u16 Img_EfxFenrirBG2_A_081929D0[];
extern u16  Pal_EfxFenrirBG2_A[];
extern u16  Pal_EfxFenrirBG2_B[];
extern u16 Tsa_EfxFenrirBG2_A_081935D8[];
extern u16 Tsa_EfxFenrirBG2_A_08193694[];
extern u16 Tsa_EfxFenrirBG2_A_08193750[];
extern u16 Tsa_EfxFenrirBG2_A_0819380C[];
extern u16 Tsa_EfxFenrirBG2_A_081938C8[];
extern u16 Tsa_EfxFenrirBG2_A_08193984[];
extern u16 Tsa_EfxFenrirBG2_A_08193A40[];
extern u16 Tsa_EfxFenrirBG2_A_08193B44[];
extern u16 Tsa_EfxFenrirBG2_A_08193C48[];
extern u16 Tsa_EfxFenrirBG2_A_08193D4C[];
extern u16 Tsa_EfxFenrirBG2_A_08193E50[];
extern u16 Tsa_EfxFenrirBG2_A_08193F54[];
extern u16 Tsa_EfxFenrirBG2_A_08194058[];
extern u16 Tsa_EfxFenrirBG2_A_08194198[];
extern u16 Tsa_EfxFenrirBG2_A_081942DC[];
extern u16 Tsa_EfxFenrirBG2_A_08194420[];
extern u16 Tsa_EfxFenrirBG2_A_08194564[];
extern u16 Tsa_EfxFenrirBG2_A_081946A8[];
extern u16 Tsa_EfxFenrirBG2_A_081947EC[];
extern u16 Tsa_EfxFenrirBG2_A_0819496C[];
extern u16 Tsa_EfxFenrirBG2_A_08194AF0[];
extern u16 Tsa_EfxFenrirBG2_A_08194C74[];
extern u16 Tsa_EfxFenrirBG2_A_08194DD4[];
extern u16 Tsa_EfxFenrirBG2_A_08194F34[];
extern u16 Tsa_EfxFenrirBG2_A_08195094[];
extern u16 Tsa_EfxFenrirBG2_A_08195238[];
extern u16 Tsa_EfxFenrirBG2_A_081953DC[];
extern u16 Tsa_EfxFenrirBG2_A_08195580[];
extern u16 Tsa_EfxFenrirBG2_A_081956F0[];
extern u16 Tsa_EfxFenrirBG2_A_08195860[];
extern u16 Tsa_EfxFenrirBG2_A_081959D0[];
extern u16 Tsa_EfxFenrirBG2_A_08195B74[];
extern u16 Tsa_EfxFenrirBG2_A_08195D18[];
extern u16 Tsa_EfxFenrirBG2_A_08195EBC[];
extern u16 Tsa_EfxFenrirBG2_A_08196030[];
extern u16 Tsa_EfxFenrirBG2_A_081961A4[];
extern u16 Tsa_EfxFenrirBG2_A_08196318[];
extern u16 Tsa_EfxFenrirBG2_A_081964C8[];
extern u16 Tsa_EfxFenrirBG2_A_08196678[];
extern u16 Tsa_EfxFenrirBG2_A_08196828[];
extern u16 Tsa_EfxFenrirBG2_A_0819699C[];
extern u16 Tsa_EfxFenrirBG2_A_08196B10[];
extern u16 Tsa_EfxFenrirBG2_A_08196C84[];
extern u16 Tsa_EfxFenrirBG2_A_08196E38[];
extern u16 Tsa_EfxFenrirBG2_A_08196FEC[];
extern u16 Tsa_EfxFenrirBG2_A_081971A0[];
extern u16 Tsa_EfxFenrirBG2_A_08197318[];
extern u16 Tsa_EfxFenrirBG2_A_08197490[];
extern u16 Tsa_EfxFenrirBG2_A_08197608[];
extern u16 Tsa_EfxFenrirBG2_A_08197860[];
extern u16 Tsa_EfxFenrirBG2_A_08197A68[];
extern u16  Img_EfxFenrirOBJ[];
extern u16  Pal_EfxFenrirOBJ[];
extern u16  Pal_EfxFenrirOBJ2[];
extern u16 Img_EfxPurgeBG_0819879C[];
extern u16 Img_EfxPurgeBG_08198CF8[];
extern u16 Img_EfxPurgeBG_08199374[];
extern u16 Img_EfxPurgeBG_081999C0[];
extern u16 Img_EfxPurgeBG_0819A174[];
extern u16 Img_EfxPurgeBG_0819A87C[];
extern u16 Img_EfxPurgeBG_0819AD98[];
extern u16 Img_EfxPurgeBG_0819B698[];
extern u16 Img_EfxPurgeBG_0819C04C[];
extern u16 Img_EfxPurgeBG_0819C9C0[];
extern u16 Img_EfxPurgeBG_0819D394[];
extern u16 Img_EfxPurgeBG_0819E398[];
extern u16 Img_EfxPurgeBG_0819F1E8[];
extern u16 Img_EfxPurgeBG_0819FCCC[];
extern u16 Img_EfxPurgeBG_081A0874[];
extern u16 Img_EfxPurgeBG_081A1410[];
extern u16 Img_EfxPurgeBG_081A1ED0[];
extern u16 Img_EfxPurgeBG_081A2948[];
extern u16 Pal_EfxPurgeBG_00000000[];
extern u16 Pal_EfxPurgeBG_081A3C4C[];
extern u16 Pal_EfxPurgeBG_081A3C6C[];
extern u16 Tsa_EfxPurgeBG_00000000[];
extern u16 Tsa_EfxPurgeBG_081A3C8C[];
extern u16 Tsa_EfxPurgeBG_081A3DB0[];
extern u16 Tsa_EfxPurgeBG_081A3ED0[];
extern u16 Tsa_EfxPurgeBG_081A3FDC[];
extern u16 Tsa_EfxPurgeBG_081A40D8[];
extern u16 Tsa_EfxPurgeBG_081A41C0[];
extern u16 Tsa_EfxPurgeBG_081A42A8[];
extern u16 Tsa_EfxPurgeBG_081A4388[];
extern u16 Tsa_EfxPurgeBG_081A4464[];
extern u16 Tsa_EfxPurgeBG_081A4544[];
extern u16 Tsa_EfxPurgeBG_081A4638[];
extern u16 Tsa_EfxPurgeBG_081A472C[];
extern u16 Tsa_EfxPurgeBG_081A4830[];
extern u16 Tsa_EfxPurgeBG_081A4938[];
extern u16 Tsa_EfxPurgeBG_081A4A50[];
extern u16 Tsa_EfxPurgeBG_081A4B74[];
extern u16 Tsa_EfxPurgeBG_081A4C88[];
extern u16 Tsa_EfxPurgeBG_081A4DAC[];
extern u16 Tsa_EfxPurgeBG_081A4ED0[];
extern u16 Tsa_EfxPurgeBG_081A4FE0[];
extern u16 Tsa_EfxPurgeBG_081A50E0[];
extern u16 Tsa_EfxPurgeBG_081A51C8[];
extern u16 Tsa_EfxPurgeBG_081A52A8[];
extern u16 Tsa_EfxPurgeBG_081A5384[];
extern u16 Tsa_EfxPurgeBG_081A5460[];
extern u16 Tsa_EfxPurgeBG_081A5544[];
extern u16 Tsa_EfxPurgeBG_081A5638[];
extern u16 Tsa_EfxPurgeBG_081A5728[];
extern u16 Tsa_EfxPurgeBG_081A582C[];
extern u16 Tsa_EfxPurgeBG_081A5934[];
extern u16 Tsa_EfxPurgeBG_081A5A48[];
extern u16 Tsa_EfxPurgeBG_081A5B6C[];
extern u16 Tsa_EfxPurgeBG_081A5C80[];
extern u16 Tsa_EfxPurgeBG_081A5DA4[];
extern u16 Tsa_EfxPurgeBG_081A5EC4[];
extern u16 Tsa_EfxPurgeBG_081A5FD0[];
extern u16 Tsa_EfxPurgeBG_081A60CC[];
extern u16 Tsa_EfxPurgeBG_081A61B4[];
extern u16 Tsa_EfxPurgeBG_081A629C[];
extern u16 Tsa_EfxPurgeBG_081A637C[];
extern u16 Tsa_EfxPurgeBG_081A6458[];
extern u16 Tsa_EfxPurgeBG_081A6538[];
extern u16 Tsa_EfxPurgeBG_081A662C[];
extern u16 Tsa_EfxPurgeBG_081A6720[];
extern u16 Tsa_EfxPurgeBG_081A6824[];
extern u16 Tsa_EfxPurgeBG_081A692C[];
extern u16 Tsa_EfxPurgeBG_081A6A44[];
extern u16 Tsa_EfxPurgeBG_081A6B68[];
extern u16 Tsa_EfxPurgeBG_081A6C78[];
extern u16 Tsa_EfxPurgeBG_081A6E8C[];
extern u16 Tsa_EfxPurgeBG_081A7048[];
extern u16 Tsa_EfxPurgeBG_081A7224[];
extern u16 Tsa_EfxPurgeBG_081A7428[];
extern u16 Tsa_EfxPurgeBG_081A7630[];
extern u16 Tsa_EfxPurgeBG_081A7844[];
extern u16 Tsa_EfxPurgeBG_081A7AA4[];
extern u16 Tsa_EfxPurgeBG_081A7CD8[];
extern u16 Tsa_EfxPurgeBG_081A7F4C[];
extern u16 Tsa_EfxPurgeBG_081A8194[];
extern u16 Tsa_EfxPurgeBG_081A84F4[];
extern u16 Tsa_EfxPurgeBG_081A8848[];
extern u16 Tsa_EfxPurgeBG_081A8B58[];
extern u16 Tsa_EfxPurgeBG_081A8E3C[];
extern u16 Tsa_EfxPurgeBG_081A910C[];
extern u16 Tsa_EfxPurgeBG_081A93A4[];
extern u16 Tsa_EfxPurgeBG_081A963C[];
extern u16 Tsa_EfxPurgeBG_081A9868[];
extern u16 Tsa_EfxPurgeBG_081A9B1C[];
extern u16 Tsa_EfxPurgeBG_081A9DDC[];
extern u16 Tsa_EfxPurgeBG_081AA10C[];
extern u16 Tsa_EfxPurgeBG_081AA45C[];
extern u16 Tsa_EfxPurgeBG_081AA7D4[];
extern u16 Tsa_EfxPurgeBG_081AAB5C[];
extern u16 Img_EfxPurgeOBJ[];
extern u16 Pal_EfxPurgeOBJ[];
extern u16  Img_EfxHealCommon[];
extern u16  Tsa_Uncomp_EfxLiveBG_BB_L[];
extern u16 Pals1_EfxLiveBGCOL[];
extern u16  Img_EfxLiveOBJ[];
extern u16 Pal_EfxFimbulvetrOBJ[];
extern u16  Img_EfxLiveBG[];
extern u16  Tsa_Uncomp_EfxLiveBG_BA_L[];
extern u16  Tsa_Uncomp_EfxLiveBG_BA_R[];
extern u16 Pals3_EfxLiveBGCOL[];
extern u16 Pals2_EfxLiveBGCOL[];
extern u16 Tsa_EfxReserveBG_081ADFEC[];
extern u16 Tsa_EfxReserveBG_081AE0F8[];
extern u16 Tsa_EfxReserveBG_081AE1F8[];
extern u16 Tsa_EfxReserveBG_081AE304[];
extern u16 Tsa_EfxReserveBG2_081AE410[];
extern u16 const Pals1_EfxReserveBGCOL[];
extern u16 const Pals2_EfxReserveBGCOL[];
extern u16 const Pals2_EfxReserveBGCOL2[];
extern u16 Img_EfxRestBG_081AFC70[];
extern u16 Img_EfxRestBG_081B029C[];
extern u16 Img_EfxRestBG_081B0994[];
extern u16 Img_EfxRestBG_081B0FB4[];
extern u16 const Pal_EfxRestBG[];
extern u16 Tsa_EfxRestBG_081B1730[];
extern u16 Tsa_EfxRestBG_081B17DC[];
extern u16 Tsa_EfxRestBG_081B1890[];
extern u16 Tsa_EfxRestBG_081B1950[];
extern u16 Tsa_EfxRestBG_081B1A18[];
extern u16 Tsa_EfxRestBG_081B1AF4[];
extern u16 Tsa_EfxRestBG_081B1BD4[];
extern u16 Tsa_EfxRestBG_081B1CBC[];
extern u16 Tsa_EfxRestBG_081B1DAC[];
extern u16 Tsa_EfxRestBG_081B1EAC[];
extern u16 Tsa_EfxRestBG_081B1FB8[];
extern u16 Tsa_EfxRestBG_081B20D8[];
extern u16 Tsa_EfxRestBG_081B2208[];
extern u16  Img_EfxSilenceBG[];
extern u16 Tsa_EfxSilenceBG_081B2E10[];
extern u16 Tsa_EfxSilenceBG_081B2F0C[];
extern u16 Tsa_EfxSilenceBG_081B2FF4[];
extern u16 Tsa_EfxSilenceBG_081B30DC[];
extern u16 Tsa_EfxSilenceBG_081B31C4[];
extern u16 Tsa_EfxSilenceBG_081B32C0[];
extern u16 Tsa_EfxSilenceBG_081B33A8[];
extern u16 Tsa_EfxSilenceBG_081B3440[];
extern u16 Tsa_EfxSilenceBG_081B3528[];
extern u16 Tsa_EfxSilenceBG_081B35C0[];
extern u16 Tsa_EfxSilenceBG_081B36A8[];
extern u16 Tsa_EfxSilenceBG_081B37A4[];
extern u16 Tsa_EfxSilenceBG_081B383C[];
extern u16 Tsa_EfxSilenceBG_081B3924[];
extern u16 Tsa_EfxSilenceBG_081B39BC[];
extern u16 Tsa_EfxSilenceBG_081B3AB8[];
extern u16 Tsa_EfxSilenceBG_081B3B50[];
extern u16 Tsa_EfxSilenceBG_081B3C60[];
extern u16  Img_EfxSilenceOBJ[];
extern u16  Pal_EfxSilenceBG[];
extern u16 const Pal_EfxHammarneBG[];
extern u16 Tsa_EfxHammarneBG_081B4294[];
extern u16 Tsa_EfxHammarneBG_081B4340[];
extern u16 Tsa_EfxHammarneBG_081B43F0[];
extern u16 Tsa_EfxHammarneBG_081B44B0[];
extern u16 Tsa_EfxHammarneBG_081B4578[];
extern u16 Tsa_EfxHammarneBG_081B4650[];
extern u16 Tsa_EfxHammarneBG_081B472C[];
extern u16 Tsa_EfxHammarneBG_081B4814[];
extern u16 Tsa_EfxHammarneBG_081B4904[];
extern u16 Tsa_EfxHammarneBG_081B4A04[];
extern u16 Tsa_EfxHammarneBG_081B4B10[];
extern u16 Tsa_EfxHammarneBG_081B4C30[];
extern u16 Tsa_EfxHammarneBG_081B4D60[];
extern u16  Img_EfxClasschgFIN[];
extern u16  Tsa_EfxBerserkBG[];
extern u16  Img_EfxSleepBG[];
extern u16  Pal_EfxSleepBG[];
extern u16 Tsa_EfxSleepBG_081B66A8[];
extern u16 Tsa_EfxSleepBG_081B6784[];
extern u16 Tsa_EfxSleepBG_081B6860[];
extern u16 Tsa_EfxSleepBG_081B693C[];
extern u16 Tsa_EfxSleepBG_081B6A18[];
extern u16 Tsa_EfxSleepBG_081B6AF4[];
extern u16 Tsa_EfxSleepBG_081B6BD0[];
extern u16 Tsa_EfxSleepBG_081B6CAC[];
extern u16 Tsa_EfxSleepBG_081B6D88[];
extern u16 Tsa_EfxSleepBG_081B6E64[];
extern u16 Tsa_EfxSleepBG_081B6F40[];
extern u16 Tsa_EfxSleepBG_081B701C[];
extern u16 Tsa_EfxSleepBG_081B70F8[];
extern u16 Tsa_EfxSleepBG_081B71D4[];
extern u16 Tsa_EfxSleepBG_081B72B0[];
extern u16 Tsa_EfxSleepBG_081B738C[];
extern u16 const Img_EfxHammarneOBJ[];
extern u16 const Pal_EfxRestOBJ[];
extern u16  Pal_EfxHammarneOBJ[];
extern u16  Pal_EfxBerserkBG[];
extern u16  Img_EfxBerserk1[];
extern u16  Img_EfxBerserk2[];
extern u16  Pal_EfxBerserk[];
extern u16  Img_EfxMshieldBG[];
extern u16 const Pal_EfxMshieldBG[];
extern u16 Tsa_EfxMshieldBG_081B8974[];
extern u16 Tsa_EfxMshieldBG_081B8A2C[];
extern u16 Tsa_EfxMshieldBG_081B8AF0[];
extern u16 Tsa_EfxMshieldBG_081B8BE0[];
extern u16 Tsa_EfxMshieldBG_081B8D10[];
extern u16  Pal_EfxMshieldOBJ[];
extern u16  Img_EfxAureolaBG2[];
extern u16 Img_EfxAureolaBG_081BA374[];
extern u16  Pal_EfxAureolaBG[];
extern u16  Pal_EfxAureolaBG2[];
extern u16 Tsa_EfxAureolaBG_081BB3DC[];
extern u16  Tsa_EfxAureolaBG2[];
extern u16 Tsa_EfxAureolaBG_081BB75C[];
extern u16 Tsa_EfxAureolaBG_081BB8E0[];
extern u16 Tsa_EfxAureolaBG_081BBA04[];
extern u16 Tsa_EfxAureolaBG_081BBB00[];
extern u16  Img_EfxAureolaOBJ[];
extern u16  Pal_EfxAureolaOBJ[];
extern i16 const FrameArray_EkrManaketefxNormalAttack[];
extern i16 const FrameArray_EkrManaketefxCriticalAttack[];
extern i16 const FrameArray_EkrFaefx[];
extern i16 const FrameArray_EkrIdunnBody0[];
extern i16 const FrameArray_EkrIdunnBody1[];
extern i16 const FrameArray_EkrIdunnBody2[];
extern i16 const FrameArray_EkrIdunnBody3[];
extern i16 const FrameArray_EkrIdunnBody4[];
extern u8 const Img_ManaketeBodyIntro2[];
extern u8 const Img_ManaketeBodyIntro1[];
extern u8 const Img_ManaketeBodyStd[];
extern u8 const Img_081BE490[];
extern const u16 Pal_EkrManaketefx[0xC0];
extern u8 const Tsa_ManaketeBodyIntro2[];
extern u8 const Tsa_ManaketeBodyIntro1[];
extern u8 const Tsa_ManaketeBodyStd[];
extern u8 const Tsa_081BFA34[];
extern u8 const Img_ManaketeObjfx1[];
extern u8 const Img_ManaketeObjfx2[];
extern u8 const Img_ManaketeObjfx3[];
extern u16 const Pal_ManaketeBodyStd[];
extern u8 const Img_EkrIdunn_081C1C94[];
extern u16 const Pal_081C4DE8[];
extern u8 const Tsa_EkrIdunn_081C4E28[];
extern u8 const Tsa_EkrIdunn_081C5264[];
extern u8 const Tsa_EkrIdunn_081C5688[];
extern u16 const Tsa_EkrIdunnBody0[];
extern u16 const Tsa_EkrIdunnBody1[];
extern u16 const Tsa_EkrIdunnBody2[];
extern u16 const Tsa_EkrIdunnBody3[];
extern u16 const Tsa_EkrIdunnBody4[];
extern u16 const Tsa_EkrIdunnBody5[];
extern u16 const Tsa_EkrIdunnBody6[];
extern u16 const Tsa_EkrIdunnBody7[];
extern u16 const Tsa_EkrIdunnBody8[];
extern u8 const Img_EkrFaefx[];
extern u16 const Pal_EkrFaefx[];
extern u16 const Tsa_EkrFaefx1[];
extern u16 const Tsa_EkrFaefx2[];
extern u16 const Tsa_EkrFaefx3[];
extern u16 const Tsa_EkrFaefx4[];
extern u16 const Tsa_EkrFaefx5[];
extern u16 const Tsa_EkrFaefx6[];
extern u16 const Tsa_EkrFaefx7[];
extern u16 const Tsa_EkrFaefx8[];
extern u16 const Tsa_EkrFaefx9[];
extern u16 const Tsa_EkrFaefx10[];
extern u16 const Tsa_EkrFaefx11[];
extern u16 const Tsa_EkrFaefx12[];
extern const s16 gAnimSpriteRotScalePosX[][4];
extern const s16 gAnimSpriteRotScalePosY[][4];
// extern ??? EkrLvupMsgsStr
// extern ??? EkrLvupMsgsMag
// extern ??? sEfxLvupPartsPos
extern const char gMsg_Lv[];
extern const i16 FrameArray_EkrTriPegagusBGLeft[];
extern const i16 FrameArray_EkrTriPegagusBGRight[];
extern const u16 Img_TriPegasusKnightBG[];
extern const u16 Img_TriFalconKnightLanceBG[];
extern const u16 Img_TriFalconKnightSwordBG[];
extern u16 Tsa_EkrTriPegagusBG1[];
extern u16 Tsa_EkrTriPegagusBG2[];
extern u16 Tsa_EkrTriPegagusBG3[];
extern u16 Tsa_EkrTriPegagusBG4[];
extern u16 Tsa_EkrTriPegagusBG5[];
extern u16 Tsa_EkrTriPegagusBG6[];
extern const u16 Img_TriPegasusKnightOBJ[];
extern const u16 Img_TriFalconKnightLanceOBJ[];
extern const u16 Img_TriFalconKnightSwordOBJ[];
extern const u16 Img_TriKnightOBJ[];
extern const u16 Img_TriGenerialLanceOBJ[];
extern const u16 Img_TriGenerialAxeOBJ[];
extern const u16 Img_TriGenerialHandAxeOBJ[];
extern const u16 Img_TriKnightAtkOBJ[];
extern const u16 Img_TriGenerialLanceAtkOBJ[];
extern const u16 Img_TriGenerialAxeAtkOBJ[];
extern const u16 Img_TriGenerialHandAxeAtkOBJ[];
extern u16 BanimBG_081D0B4C[];
extern u16 BanimBG_081D41C8[];
extern u16 BanimBG_081D8E04[];
extern u16 BanimBG_081DD1D4[];
extern u16 BanimBG_081DD2C0[];
extern u16 BanimBG_081DD3F4[];
extern u16 BanimBG_081DD4DC[];
extern u16 BanimBG_081DD5D4[];
extern u16 BanimBG_081DD6D4[];
extern u16 BanimBG_081DD7E4[];
extern u16 BanimBG_081DD890[];
extern u16 BanimBG_081DD950[];
extern u16 BanimBG_081DD9DC[];
extern u16 BanimBG_081DDA68[];
extern u16 BanimBG_081DDAD4[];
extern u16 BanimBG_081DDB8C[];
extern u16 BanimBG_081DDCBC[];
extern u16 BanimBG_081DDDAC[];
extern u16 BanimBG_081DDE3C[];
extern u16 BanimBG_081DDF24[];
extern u16 BanimBG_081DE008[];
extern u16 BanimBG_081DE120[];
extern u16 BanimBG_081DE1E8[];
extern u16 BanimBG_081DE2E4[];
extern u16 BanimBG_081DE3FC[];
extern u16 BanimBG_081DE4BC[];
extern u16 BanimBG_081DE528[];
extern u16 BanimBG_081DE680[];
extern u16 BanimBG_081DE740[];
extern u16 BanimBG_081DE830[];
extern u16 BanimBG_081DE8A0[];
extern u16 BanimBG_081DEA58[];
extern u16 BanimBG_081DED04[];
extern u16 BanimBG_081DEF48[];
extern u16 BanimBG_081DF110[];
extern u16 BanimBG_081DF3DC[];
extern u16 BanimBG_081DF650[];
extern u16 BanimBG_081DF7DC[];
extern u16 BanimBG_081DF9E0[];
extern u16 BanimBG_081DFBBC[];
extern u16 BanimBG_081DFE78[];
extern u16 BanimBG_081E0158[];
extern u16 BanimBG_081E048C[];
extern u16 BanimBG_081E0724[];
extern u16 BanimBG_081E09CC[];
extern u16 BanimBG_081E0BF4[];
