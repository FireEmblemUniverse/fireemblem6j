#include "prelude.h"
#include "proc.h"
#include "item.h"
#include "oam.h"
#include "util.h"
#include "banim.h"
#include "banim_ekrdragon.h"
#include "constants/terrains.h"
#include "constants/songs.h"
#include "constants/banims.h"

/**
 * C26: banim_code_toss_sword
 * C27: banim_code_toss_shield
 */
struct ProcScr CONST_DATA ProcScr_EfxYushaSpinShield[] = {
	PROC_NAME_DEBUG("efxYushaSpinShield"),
	PROC_REPEAT(EfxYushaSpinShield_Null),
	PROC_END,
};

void NewEfxYushaSpinShield(struct Anim *anim, int r1)
{
	struct ProcEfx *proc;

	proc = SpawnProc(ProcScr_EfxYushaSpinShield, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	NewEfxYushaSpinShieldOBJ(anim, r1);
}

void EfxYushaSpinShield_Null(struct ProcEfx *proc)
{
    Proc_Break(proc);
}

struct ProcScr CONST_DATA ProcScr_EfxYushaSpinShieldOBJ[] = {
	PROC_NAME_DEBUG("efxYushaSpinShieldOBJ"),
	PROC_REPEAT(EfxYushaSpinShieldOBJ_1),
	PROC_REPEAT(EfxYushaSpinShieldOBJ_2),
	PROC_REPEAT(EfxYushaSpinShieldOBJ_3),
	PROC_REPEAT(EfxYushaSpinShieldOBJ_4),
	PROC_END,
};

void NewEfxYushaSpinShieldOBJ(struct Anim *anim, int r1)
{
	u32 *scr1, *scr2;
	struct ProcEfxOBJ *proc;
	struct Anim *anim2;

	proc = SpawnProc(ProcScr_EfxYushaSpinShieldOBJ, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->unk29 = r1;

	if (r1 == 0) {
		scr1 = AnimScr_YushaSpinShieldOBJ_LeftTypeA;
		scr2 = AnimScr_YushaSpinShieldOBJ_RightTypeA;
	} else {
		scr1 = AnimScr_YushaSpinShieldOBJ_LeftTypeB;
		scr2 = AnimScr_YushaSpinShieldOBJ_RightTypeB;
	}

	anim2 = EfxCreateFrontAnim(anim, scr2, scr1, scr2, scr1);
	proc->anim2 = anim2;

	/**
	 * oam2_data::chr = 0;
	 * oam2_data::pal = 0;
	 */
	anim2->oam2 &= 0xC00;

	if (GetAnimPosition(anim) == POS_L)
		anim2->oam2 |= OAM2_PAL(OBPAL_EFX_UNIT_L) + VRAMOFF_OBJ_4000 / CHR_LINE;
	else
		anim2->oam2 |= OAM2_PAL(OBPAL_EFX_UNIT_R) + VRAMOFF_OBJ_6000 / CHR_SIZE;
}

void EfxYushaSpinShieldOBJ_1(struct ProcEfxOBJ *proc)
{
	struct Anim *anim2 = proc->anim2;
	if (++proc->timer != 0x45)
		return;
	
	if (proc->unk29 == 0) {
		if (GetAnimPosition(proc->anim) == POS_L) {
			anim2->script = AnimScr_YushaSpinShieldOBJ2_LeftTypeA;
			anim2->scrCur = AnimScr_YushaSpinShieldOBJ2_LeftTypeA;
		} else {
			anim2->script = AnimScr_YushaSpinShieldOBJ2_RightTypeA;
			anim2->scrCur = AnimScr_YushaSpinShieldOBJ2_RightTypeA;
		}
	} else {
		if (GetAnimPosition(proc->anim) == POS_L) {
			anim2->script = AnimScr_YushaSpinShieldOBJ2_LeftTypeB;
			anim2->scrCur = AnimScr_YushaSpinShieldOBJ2_LeftTypeB;
		} else {
			anim2->script = AnimScr_YushaSpinShieldOBJ2_RightTypeB;
			anim2->scrCur = AnimScr_YushaSpinShieldOBJ2_RightTypeB;
		}
	}

	anim2->timer = 0;
	proc->timer = 0;
	Proc_Break(proc);
}

void EfxYushaSpinShieldOBJ_2(struct ProcEfxOBJ *proc)
{
	if (!(proc->anim->flags3 & ANIM_BIT3_C01_BLOCK_END_PREBATTLE))
		return;

	if (!(proc->anim->flags3 & ANIM_BIT3_C01_BLOCK_END_INBATTLE))
		return;

	proc->timer = 0;
	Proc_Break(proc);
}

void EfxYushaSpinShieldOBJ_3(struct ProcEfxOBJ *proc)
{
	struct Anim *anim2 = proc->anim2;

	if (CheckEkrHitDone() != true)
		return;

	if (proc->unk29 == 0) {
		if (GetAnimPosition(proc->anim) == POS_L) {
			anim2->script = AnimScr_YushaSpinShieldOBJ3_LeftTypeA;
			anim2->scrCur = AnimScr_YushaSpinShieldOBJ3_LeftTypeA;
		} else {
			anim2->script = AnimScr_YushaSpinShieldOBJ3_RightTypeA;
			anim2->scrCur = AnimScr_YushaSpinShieldOBJ3_RightTypeA;
		}
	} else {
		if (GetAnimPosition(proc->anim) == POS_L) {
			anim2->script = AnimScr_YushaSpinShieldOBJ3_LeftTypeB;
			anim2->scrCur = AnimScr_YushaSpinShieldOBJ3_LeftTypeB;
		} else {
			anim2->script = AnimScr_YushaSpinShieldOBJ3_RightTypeB;
			anim2->scrCur = AnimScr_YushaSpinShieldOBJ3_RightTypeB;
		}
	}

	anim2->timer = 0;
	proc->timer = 0;
	Proc_Break(proc);
}

void EfxYushaSpinShieldOBJ_4(struct ProcEfxOBJ *proc)
{
	if (++proc->timer == 0x14) {
		proc->timer = 0;
		BasRemove(proc->anim2);
		Proc_Break(proc);
	}
}

/**
 * C2C: banim_code_effect_sealed_sword_fire
 */
CONST_DATA struct ProcScr ProcScr_EfxHurtmutEff00[] = {
	PROC_NAME_DEBUG("efxHurtmutEff00"),
	PROC_REPEAT(EfxHurtmutEff00_Null),
	PROC_END,
};

void NewEfxHurtmutEff00(struct Anim *anim)
{
	struct ProcEfx *proc;

	if (gEfxBgSemaphore != 0)
		return;
	
	proc = SpawnProc(ProcScr_EfxHurtmutEff00, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;

	if (gEkrDistanceType == POS_L)
		NewEfxHurtmutEff00OBJ(anim);
	else
		NewEfxHurtmutEff01OBJ(anim);
}

void EfxHurtmutEff00_Null(struct ProcEfx *proc)
{
	Proc_Break(proc);
}

struct ProcScr CONST_DATA ProcScr_EfxHurtmutEff00OBJ[] = {
	PROC_NAME_DEBUG("efxHurtmutEff00OBJ"),
	PROC_REPEAT(EfxHurtmutEff00OBJ_1),
	PROC_SLEEP(26),
	PROC_REPEAT(EfxHurtmutEff00OBJ_2),
	PROC_SLEEP(8),
	PROC_REPEAT(EfxHurtmutEff00OBJ_3),
	PROC_END,
};

void NewEfxHurtmutEff00OBJ(struct Anim *anim)
{
	struct ProcEfxOBJ *proc;
	gEfxBgSemaphore++;
	proc = SpawnProc(ProcScr_EfxHurtmutEff00OBJ, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->anim2 = EfxCreateFrontAnim(anim, AnimScr_Common, AnimScr_Common, AnimScr_Common, AnimScr_Common);
}

void EfxHurtmutEff00OBJ_1(struct ProcEfxOBJ *proc)
{
	struct Anim *anim2 = proc->anim2;

	if (GetAnimPosition(proc->anim) == POS_R) {
		anim2->script = AnimScr_HurtmutEff00OBJ1_Right;
		anim2->scrCur = AnimScr_HurtmutEff00OBJ1_Right;
	} else {
		anim2->script = AnimScr_HurtmutEff00OBJ1_Left;
		anim2->scrCur = AnimScr_HurtmutEff00OBJ1_Left;
	}

	anim2->timer = 0;

	SpellFx_RegisterObjPal(Pal_EfxHurtmutEff00OBJ, 0x20);
	SpellFx_RegisterObjGfx(Img_EfxHurtmutEff00OBJ1, 0x1000);
	Proc_Break(proc);
}

void EfxHurtmutEff00OBJ_2(struct ProcEfxOBJ *proc)
{
	struct Anim *anim2 = proc->anim2;

	if (GetAnimPosition(proc->anim) == POS_R) {
		anim2->script = AnimScr_HurtmutEff00OBJ2_Right;
		anim2->scrCur = AnimScr_HurtmutEff00OBJ2_Right;
	} else {
		anim2->script = AnimScr_HurtmutEff00OBJ2_Left;
		anim2->scrCur = AnimScr_HurtmutEff00OBJ2_Left;
	}

	anim2->timer = 0;

	SpellFx_RegisterObjPal(Pal_EfxHurtmutEff00OBJ, 0x20);
	SpellFx_RegisterObjGfx(Img_EfxHurtmutEff00OBJ2, 0x1000);
	Proc_Break(proc);
}

void EfxHurtmutEff00OBJ_3(struct ProcEfxOBJ *proc)
{
	gEfxBgSemaphore--;
	BasRemove(proc->anim2);
	Proc_Break(proc);
}

struct ProcScr CONST_DATA ProcScr_EfxHurtmutEff01OBJ[] = {
	PROC_NAME_DEBUG("efxHurtmutEff01OBJ"),
	PROC_REPEAT(EfxHurtmutEff01OBJ_1),
	PROC_SLEEP(58),
	PROC_REPEAT(EfxHurtmutEff01OBJ_2),
	PROC_SLEEP(21),
	PROC_REPEAT(EfxHurtmutEff01OBJ_3),
	PROC_END,
};

void NewEfxHurtmutEff01OBJ(struct Anim *anim)
{
	struct ProcEfxOBJ *proc;

	gEfxBgSemaphore++;
	proc = SpawnProc(ProcScr_EfxHurtmutEff01OBJ, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->anim2 = EfxCreateFrontAnim(anim, AnimScr_Common, AnimScr_Common, AnimScr_Common, AnimScr_Common);
}

void EfxHurtmutEff01OBJ_1(struct ProcEfxOBJ *proc)
{
	struct Anim *anim2 = proc->anim2;
	if (GetAnimPosition(proc->anim) == POS_R) {
		anim2->script = AnimScr_HurtmutEff01OBJ1_Right;
		anim2->scrCur = AnimScr_HurtmutEff01OBJ1_Right;
	} else {
		anim2->script = AnimScr_HurtmutEff01OBJ1_Left;
		anim2->scrCur = AnimScr_HurtmutEff01OBJ1_Left;
	}

	anim2->timer = 0;

	SpellFx_RegisterObjPal(Pal_EfxHurtmutEff00OBJ, 0x20);
	SpellFx_RegisterObjGfx(Img_EfxHurtmutEff00OBJ1, 0x1000);
	Proc_Break(proc);
}

void EfxHurtmutEff01OBJ_2(struct ProcEfxOBJ *proc)
{
	struct Anim *anim2 = proc->anim2;
	if (GetAnimPosition(proc->anim) == POS_R) {
		anim2->script = AnimScr_HurtmutEff01OBJ2_Right;
		anim2->scrCur = AnimScr_HurtmutEff01OBJ2_Right;
	} else {
		anim2->script = AnimScr_HurtmutEff01OBJ2_Left;
		anim2->scrCur = AnimScr_HurtmutEff01OBJ2_Left;
	}

	anim2->timer = 0;

	SpellFx_RegisterObjPal(Pal_EfxHurtmutEff00OBJ, 0x20);
	SpellFx_RegisterObjGfx(Img_EfxHurtmutEff00OBJ2, 0x1000);
	Proc_Break(proc);
}

void EfxHurtmutEff01OBJ_3(struct ProcEfxOBJ *proc)
{
	gEfxBgSemaphore--;
	BasRemove(proc->anim2);
	Proc_Break(proc);
}

/**
 * C2E: banim_code_effect_magic_rune_normal
 * C2F: banim_code_effect_magic_rune_critical
 */
struct ProcScr CONST_DATA ProcScr_EfxMagfcast[] = {
	PROC_NAME_DEBUG("efxMagfcast"),
	PROC_REPEAT(EfxMagfcast_Loop),
	PROC_END,
};

void NewEfxMagfcast(struct Anim *anim, int type)
{
    i16 banim_index;
    struct ProcEfx *proc;

    if (gEfxBgSemaphore != 0)
        return;

    SpellFx_ClearBG1Position();
    proc = SpawnProc(ProcScr_EfxMagfcast, PROC_TREE_3);

    proc->anim = anim;
    proc->timer = 0;

    banim_index = gBanimIdx[GetAnimPosition(anim)];

    if (banim_index != 0x11) {
        if (banim_index <= 0x11) {
        switch (banim_index) {
        case 0xC:
        case 0xD:
            NewEfxMagfcastBG(proc->anim, type);
            return;
        }
        }
    }

    NewEfxMagfcastBG(proc->anim, type + 2);
}

void EfxMagfcast_Loop(struct ProcEfx *proc)
{
	if (++proc->timer == 0x14)
		Proc_Break(proc);
}

const u16 FrameConfig_EfxMagFcastBg1[] = {
	0, 3,
	1, 4,
	2, 8,
	3, 4,
	4, 3,

	-1
};

const u16 FrameConfig_EfxMagFcastBg2[] = {
	5, 3,

	-1
};

const u16 FrameConfig_EfxMagFcastBg3[] = {
	0, 7,
	1, 7,
	2, 8,
	3, 11,
	4, 2,
	5, 2,
	6, 2,
	7, 2,

	-1
};

const u16 FrameConfig_EfxMagFcastBg4[] = {
	8, 3,
	9, 23,
	10, 4,
	11, 23,
	12, 4,
	13, 26,
	14, 4,
	15, 4,

	-1
};

struct ProcScr CONST_DATA ProcScr_EfxMagfcastBG[] = {
	PROC_NAME_DEBUG("efxMagfcastBG"),
	PROC_REPEAT(EfxMagfcastBG_Loop),
	PROC_END,
};

CONST_DATA u16 *TsaLut1_EfxMagfcastBG[] = {
	Tsa1_EfxMagfcastBG,
	Tsa2_EfxMagfcastBG,
	Tsa3_EfxMagfcastBG,
	Tsa4_EfxMagfcastBG,
	Tsa5_EfxMagfcastBG,
	Tsa6_EfxMagfcastBG,
};

CONST_DATA u16 *TsaLut2_EfxMagfcastBG[] = {
	Tsa7_EfxMagfcastBG,
	Tsa8_EfxMagfcastBG,
	Tsa9_EfxMagfcastBG,
	Tsa10_EfxMagfcastBG,
	Tsa11_EfxMagfcastBG,
	Tsa12_EfxMagfcastBG,
	Tsa13_EfxMagfcastBG,
	Tsa14_EfxMagfcastBG,
	Tsa15_EfxMagfcastBG,
	Tsa16_EfxMagfcastBG,
	Tsa17_EfxMagfcastBG,
	Tsa18_EfxMagfcastBG,
	Tsa19_EfxMagfcastBG,
	Tsa20_EfxMagfcastBG,
	Tsa21_EfxMagfcastBG,
	Tsa22_EfxMagfcastBG,
};

void NewEfxMagfcastBG(struct Anim *anim, u32 type)
{
	struct ProcEfxBG *proc;

	gEfxBgSemaphore++;
	proc = SpawnProc(ProcScr_EfxMagfcastBG, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->frame = 0;

	switch (type) {
	case 0:
		proc->frame_config = FrameConfig_EfxMagFcastBg1;
		proc->tsal = TsaLut1_EfxMagfcastBG;
		proc->tsar = TsaLut1_EfxMagfcastBG;
		break;

	case 1:
		proc->frame_config = FrameConfig_EfxMagFcastBg2;
		proc->tsal = TsaLut1_EfxMagfcastBG;
		proc->tsar = TsaLut1_EfxMagfcastBG;
		break;

	case 2:
		proc->frame_config = FrameConfig_EfxMagFcastBg3;
		proc->tsal = TsaLut2_EfxMagfcastBG;
		proc->tsar = TsaLut2_EfxMagfcastBG;
		break;

	case 3:
		proc->frame_config = FrameConfig_EfxMagFcastBg4;
		proc->tsal = TsaLut2_EfxMagfcastBG;
		proc->tsar = TsaLut2_EfxMagfcastBG;
		break;

	default:
		break;
	}

	SpellFx_RegisterBgGfx(Img_EfxMagfcastBG, 0x2000);
	SpellFx_RegisterBgPal(Pal_EfxMagfcastBG, 0x20);
	SpellFx_SetSomeColorEffect();

	if (gEkrDistanceType != EKR_DISTANCE_CLOSE) {
		if (GetAnimPosition(proc->anim) == POS_L)
			SetBgOffset(BG_1, 0x18, 0x0);
		else
			SetBgOffset(BG_1, 0xE8, 0x0);
	}
}

void EfxMagfcastBG_Loop(struct ProcEfxBG *proc)
{
	i16 ret = EfxAdvanceFrameLut(
		(void *)&proc->timer,
		(void *)&proc->frame,
		proc->frame_config
	);

	if (ret >= 0) {
		u16 **tsa1;
		u16 **tsa2;

		tsa1 = proc->tsal;
		tsa2 = proc->tsar;

		SpellFx_WriteBgMap(
			proc->anim,
			tsa1[ret],
			tsa2[ret]
		);

		return;
	}

	if (ret == -1) {
		SpellFx_ClearBG1();
		gEfxBgSemaphore--;
		SpellFx_ClearColorEffects();
		Proc_End(proc);
	}
}

/**
 * C30: banim_code_effect_dirt_kick
 * C31: banim_code_effect_dirt_wave_small
 * C32: banim_code_effect_dirt_wave_medium
 */
struct ProcScr CONST_DATA ProcScr_EfxSunakemuri[] = {
	PROC_NAME_DEBUG("efxSunakemuri"),
	PROC_REPEAT(EfxSunakemuri_Null),
	PROC_END,
};

void NewEfxSunakemuri(struct Anim *anim, int type)
{
	if (gEfxBgSemaphore == 0) {
		struct ProcEfx *proc;

		proc = SpawnProc(ProcScr_EfxSunakemuri, PROC_TREE_3);
		proc->anim = anim;
		proc->timer = 0;
		NewEfxSunakemuriOBJ(anim, type);
	}
}

void EfxSunakemuri_Null(struct ProcEfx *proc)
{
	Proc_Break(proc);
}

struct ProcScr CONST_DATA ProcScr_EfxSunakemuriOBJ[] = {
	PROC_NAME_DEBUG("efxSunakemuriOBJ"),
	PROC_REPEAT(EfxSunakemuriOBJ_Loop),
	PROC_END,
};

void NewEfxSunakemuriOBJ(struct Anim *anim, int type)
{
	int terrain;
	u32 *scr1, *scr2;
	struct ProcEfxOBJ *proc;

	gEfxBgSemaphore++;
	proc = SpawnProc(ProcScr_EfxSunakemuriOBJ, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;

	scr1 = AnimScr_EfxSunakemuriOBJ1_R;
	if (type != 0) {
		scr1 = AnimScr_EfxSunakemuriOBJ3_R;
		if (type == 1)
			scr1 = AnimScr_EfxSunakemuriOBJ2_R;
	}

	scr2 = AnimScr_EfxSunakemuriOBJ1_L;
	if (type != 0) {
		scr2 = AnimScr_EfxSunakemuriOBJ3_L;
		if (type == 1)
			scr2 = AnimScr_EfxSunakemuriOBJ2_L;
	}

	proc->anim2 = EfxCreateFrontAnim(anim, scr2, scr1, scr2, scr1);

	terrain = gBanimTerrain[GetAnimPosition(proc->anim)];
	switch (terrain) {
	case TERRAIN_PLAINS:
	case TERRAIN_ROAD:
	case TERRAIN_VILLAGE:
	case TERRAIN_VILLAGE_CLOSED:
	case TERRAIN_HOUSE:
	case TERRAIN_FORT:
	case TERRAIN_FOREST:
	case TERRAIN_THICKET:
	case TERRAIN_SAND:
	case TERRAIN_DESERT:
	case TERRAIN_MOUNTAIN:
	case TERRAIN_PEAK:
	case TERRAIN_BRIDGE:
	case TERRAIN_FENCE_19:
	case TERRAIN_WALL:
	case TERRAIN_WALL_BREAKABLE:
	case TERRAIN_RUBBLE:
	case TERRAIN_ROOF:
	case TERRAIN_GATE_23:
	case TERRAIN_RUINS:
	case TERRAIN_CLIFF:
	case TERRAIN_BALLISTA:
	case TERRAIN_LONGBALLISTA:
	case TERRAIN_KILLERBALLISTA:
	case TERRAIN_SHIP_FLAT:
	case TERRAIN_SHIP_WRECK:
	case TERRAIN_GLACIER:
#if FE8
	case TERRAIN_SNAG:
	case TERRAIN_INN:
	case TERRAIN_BARREL:
	case TERRAIN_BONE:
	case TERRAIN_DARK:
	case TERRAIN_GUNNELS:
	case TERRAIN_BRACE:
	case TERRAIN_MAST:
#endif
		SpellFx_RegisterObjPal(Pal_EfxSunakemuriOBJ1, 0x20);
		break;
	
	case TERRAIN_DRAWBRIDGE:
		if (IsAnimSoundInPosition(proc->anim) != POS_L)
			SpellFx_RegisterObjPal(Pal_EfxSunakemuriOBJ1, 0x20);
		else
			SpellFx_RegisterObjPal(Pal_EfxSunakemuriOBJ2, 0x20);
		break;

	case TERRAIN_RIVER:
	case TERRAIN_SEA:
	case TERRAIN_LAKE:
#if FE8
	case TERRAIN_DEEPS:
	case TERRAIN_WATER:
#endif
		SpellFx_RegisterObjPal(Pal_EfxSunakemuriOBJ2, 0x20);
		break;

	case TERRAIN_ARMORY:
	case TERRAIN_VENDOR:
	case TERRAIN_ARENA_08:
	case TERRAIN_C_ROOM_09:
	case TERRAIN_GATE_0B:
	case TERRAIN_FLOOR_17:
	case TERRAIN_FLOOR_18:
	case TERRAIN_PILLAR:
	case TERRAIN_DOOR:
	case TERRAIN_THRONE:
	case TERRAIN_CHEST_OPENED:
	case TERRAIN_CHEST:
	case TERRAIN_CHURCH:
	case TERRAIN_STAIRS:
	case TERRAIN_ARENA_30:
	case TERRAIN_VALLEY:
	case TERRAIN_FENCE_32:
#if FE8
	case TERRAIN_RUINS_37:
	case TERRAIN_DECK:
#endif
		SpellFx_RegisterObjPal(Pal_EfxSunakemuriOBJ3, 0x20);
		break;

	case TERRAIN_TILE_00:
	default:
		break;
	}

	SpellFx_RegisterObjGfx(Img_EfxSunakemuriOBJ, 0x1000);
}

void EfxSunakemuriOBJ_Loop(struct ProcEfxOBJ *proc)
{
	if (++proc->timer == 0x9) {
		gEfxBgSemaphore--;
		BasRemove(proc->anim2);
		Proc_Break(proc);
	}
}

/**
 * C39: banim_code_hit_fake
 */
struct ProcScr CONST_DATA ProcScr_EfxKingPika[] = {
	PROC_NAME_DEBUG("efxKingPika"),
	PROC_REPEAT(EfxKingPika_Loop),
	PROC_END,
};

void NewEfxKingPika(struct Anim *anim)
{
	struct ProcEfx *proc;

	proc = SpawnProc(ProcScr_EfxKingPika, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
}

void EfxKingPika_Loop(struct ProcEfx *proc)
{
	struct Anim *anim = proc->anim;
	int time = ++proc->timer;

	if (time == 0x1) {
		NewEfxFlashUnit(anim, 0x1, 0x28, 0x0);
		return;
	}

	if (time == 0xA) {
		NewEfxFlashBgWhite(anim, 0x14);
		return;
	}

	if (time == 0x2D) {
		struct Anim *anim1 = gAnims[GetAnimPosition(anim) * 2];
		struct Anim *anim2 = gAnims[GetAnimPosition(anim) * 2 + 1];

		anim1->flags3 |= ANIM_BIT3_BLOCKEND;
		anim2->flags3 |= ANIM_BIT3_BLOCKEND;
		Proc_Break(proc);
	}
}

/**
 * C44: singer
 */
struct ProcScr CONST_DATA ProcScr_EfxSongFE6[] =
{
	PROC_19,
	PROC_REPEAT(EfxSongFE6_Loop),
	PROC_END,
};

void NewEfxSongFE6(struct Anim *anim)
{
	struct ProcEfxOBJ *proc;

	gEfxBgSemaphore++;

	proc = SpawnProc(ProcScr_EfxSongFE6, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->terminator = 40;

	proc->anim2 = EfxCreateFrontAnim(
						proc->anim,
						AnimScr_EfxSongFE6,
						AnimScr_EfxSongFE6,
						AnimScr_EfxSongFE6,
						AnimScr_EfxSongFE6);

	SpellFx_RegisterObjPal(Pal_EfxSongFE6, 0x20);
	SpellFx_RegisterObjGfx(Img_EfxSongFE6, 0x1000);
	PlaySFX(SONG_EE, 0x100, proc->anim->xPosition, 1);
}

void EfxSongFE6_Loop(struct ProcEfxOBJ *proc)
{
	if (++proc->timer == 0x18)
		PlaySFX(0xEE, 0x100, proc->anim->xPosition, 0x1);

	if (proc->timer > proc->terminator) {
		BasRemove(proc->anim2);
		gEfxBgSemaphore--;
		Proc_Break(proc);
	}
}

/**
 * C45: dancer
 */
struct ProcScr CONST_DATA ProcScr_EfxDanceOBJ[] = {
	PROC_NAME_DEBUG("efxDanceOBJ"),
	PROC_REPEAT(EfxDanceOBJ_Loop),
	PROC_END,
};

void NewEfxDanceOBJ(struct Anim *anim)
{
	struct ProcEfxOBJ *proc;

	gEfxBgSemaphore++;

	proc = SpawnProc(ProcScr_EfxDanceOBJ, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->terminator = 25;

	proc->anim2 = EfxCreateFrontAnim(
						proc->anim,
						AnimScr_EfxDanceObj,
						AnimScr_EfxDanceObj,
						AnimScr_EfxDanceObj,
						AnimScr_EfxDanceObj);

	SpellFx_RegisterObjPal(Pal_EfxSongFE6, 0x20);
	SpellFx_RegisterObjGfx(Img_EfxSongFE6, 0x1000);
	PlaySFX(SONG_E1, 0x100, proc->anim->xPosition, 1);
}

void EfxDanceOBJ_Loop(struct ProcEfxOBJ *proc)
{
	if (++proc->timer > proc->terminator) {
		BasRemove(proc->anim2);
		gEfxBgSemaphore--;
		Proc_Break(proc);
	}
}

/**
 * Unused mosaic effect
 */
struct ProcScr CONST_DATA ProcScr_EfxMosaicEffect[] =
{
	PROC_19,
	PROC_REPEAT(EfxMosaicEffect_1),
	PROC_REPEAT(EfxMosaicEffect_2),
	PROC_END,
};

void NewEfxMosaicEffect(struct Anim *anim, int duration, int hi)
{
	struct ProcEfxBG *proc;

	if (GetEkrDragonStateType() != 0)
		return;

	gEfxBgSemaphore++;
	proc = SpawnProc(ProcScr_EfxMosaicEffect, PROC_TREE_3);
	proc->anim = anim;

	proc->timer = 0;
	proc->terminator = duration;
	proc->unk30 = hi;

	gDispIo.bg3_ct.mosaic = true;
	SetMosaicDisp(0);
}

void EfxMosaicEffect_1(struct ProcEfxBG *proc)
{
	int ret = Interpolate(
		INTERPOLATE_LINEAR,
		0, proc->unk30,
		proc->timer, proc->terminator
	);

	SetMosaicDisp(ret);

	if (++proc->timer > proc->terminator) {
		proc->timer = 0;
		Proc_Break(proc);
	}
}

void EfxMosaicEffect_2(struct ProcEfxBG *proc)
{
	int ret = Interpolate(
		INTERPOLATE_LINEAR,
		proc->unk30, 0,
		proc->timer, proc->terminator
	);

	SetMosaicDisp(ret);

	if (++proc->timer > proc->terminator) {
		gEfxBgSemaphore--;
		gDispIo.bg3_ct.mosaic = false;
		SetMosaicDisp(0);
		Proc_Break(proc);
	}
}

/**
 * Shinning effect for legend weapon
 */
struct ProcScr CONST_DATA ProcScr_EfxSpecalEffect[] = {
	PROC_NAME_DEBUG("efxSpecalEffect"),
	PROC_REPEAT(EfxSpecalEffect_Null),
	PROC_END,
};

void NewEfxSpecalEffect(struct Anim *anim)
{
	struct ProcEfx *proc;
	struct Anim *anim1, *anim2;

	if (gEfxSpecalEffectExist[GetAnimPosition(anim)] == false) {
		int is_legency;
		struct BattleUnit *bu;

		gEfxSpecalEffectExist[GetAnimPosition(anim)] = true;

		if (GetAnimPosition(anim) == POS_L)
			bu = gpEkrBattleUnitLeft;
		else
			bu = gpEkrBattleUnitRight;

#if 0
		// FE8
		not_legency = !(IsWeaponLegency(bu->weapon_before) == false);
#endif
		(void)GetItemKind(bu->weapon_before);
		is_legency = (GetItemRequiredExp(bu->weapon_before) == 0xFB) ? true : false;

		if (!is_legency) {
			anim1 = gAnims[GetAnimPosition(anim) * 2];
			anim2 = gAnims[GetAnimPosition(anim) * 2 + 1];

			anim1->flags3 |= ANIM_BIT3_BLOCKEND;
			anim2->flags3 |= ANIM_BIT3_BLOCKEND;
			return;
		}
	} else {
		anim1 = gAnims[GetAnimPosition(anim) * 2];
		anim2 = gAnims[GetAnimPosition(anim) * 2 + 1];

		anim1->flags3 |= ANIM_BIT3_BLOCKEND;
		anim2->flags3 |= ANIM_BIT3_BLOCKEND;
		return;
	}

	proc = SpawnProc(ProcScr_EfxSpecalEffect, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0x0;
	PlaySFX(SONG_F0, 0x100, 0x78, 0x0);
	NewEfxSRankWeaponEffect(anim);
}

void EfxSpecalEffect_Null(ProcPtr proc)
{
	Proc_Break(proc);
}

struct ProcScr CONST_DATA ProcScr_EfxSRankWeaponEffect[] = {
	PROC_NAME_DEBUG("efxSRankWeaponEffect"),
	PROC_REPEAT(EfxSRankWeaponEffect_Loop),
	PROC_END,
};

void NewEfxSRankWeaponEffect(struct Anim *anim)
{
	struct ProcEfx *proc;

	SpellFx_ClearBG1Position();

	proc = SpawnProc(ProcScr_EfxSRankWeaponEffect, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0x0;
}

void EfxSRankWeaponEffect_Loop(struct ProcEfx *proc)
{
	int time = ++proc->timer;

	if (time == 1) {
		NewEfxSRankWeaponEffectBG(proc->anim);
		return;
	}

	if (time == 0x15) {
		NewEfxRestWINH_(proc->anim, 0x2D, HBlank_EfxSRankWeaponEffectSCR);
		NewEfxSRankWeaponEffectSCR();
		return;
	}

	if (time == 0x46) {
		struct Anim *anim1, *anim2;

		anim1 = gAnims[GetAnimPosition(proc->anim) * 2];
		anim2 = gAnims[GetAnimPosition(proc->anim) * 2 + 1];
		
		anim1->flags3 |= ANIM_BIT3_BLOCKEND;
		anim2->flags3 |= ANIM_BIT3_BLOCKEND;
		Proc_Break(proc);
	}
}

struct ProcScr CONST_DATA ProcScr_EfxSRankWeaponEffectBG[] = {
	PROC_NAME_DEBUG("efxSRankWeaponEffectBG"),
	PROC_REPEAT(EfxSRankWeaponEffectBG_Loop),
	PROC_END,
};

void NewEfxSRankWeaponEffectBG(struct Anim *anim)
{
	struct ProcEfxBG *proc;

	proc = SpawnProc(ProcScr_EfxSRankWeaponEffectBG, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;

	SpellFx_RegisterBgGfx(Img_EfxSRankWeaponEffectBG, 0x2000);
	SpellFx_RegisterBgPal(Pal_EfxSRankWeaponEffectBG, 0x20);
	SpellFx_WriteBgMap(proc->anim, Tsa_EfxSRankWeaponEffectBG, Tsa_EfxSRankWeaponEffectBG);
	SpellFx_SetSomeColorEffect();
}

void EfxSRankWeaponEffectBG_Loop(struct ProcEfxBG *proc)
{
	if (++proc->timer == 0x3C) {
		SpellFx_ClearBG1();
		SpellFx_ClearColorEffects();
		Proc_Break(proc);
	}
}

void HBlank_EfxSRankWeaponEffectSCR(void)
{
	if (!(REG_DISPSTAT & DISPSTAT_VBLANK))
		REG_BG1VOFS = *gpBg1ScrollOffset++;
}

struct ProcScr CONST_DATA ProcScr_EfxSRankWeaponEffectSCR[] = {
	PROC_NAME_DEBUG("efxSRankWeaponEffectSCR"),
	PROC_REPEAT(EfxSRankWeaponEffectSCR_Loop),
	PROC_END,
};

struct ProcScr CONST_DATA ProcScr_EfxSRankWeaponEffectSCR2[] = {
	PROC_NAME_DEBUG("efxSRankWeaponEffectSCR2"),
	PROC_REPEAT(EfxSRankWeaponEffectSCR2_Loop),
	PROC_END,
};

CONST_DATA i16 EfxSRankWeaponEffectSCR_Ref[] = {
	0xFF00, 0xFF05, 0xFF09, 0xFF0E, 0xFF12, 0xFF16, 0xFF1B, 0xFF1F,
	0xFF23, 0xFF28, 0xFF2C, 0xFF30, 0xFF35, 0xFF39, 0xFF3D, 0xFF42,
	0xFF46, 0xFF4A, 0xFF4F, 0xFF53, 0xFF57, 0xFF5C, 0xFF60, 0xFF64,
	0xFF69, 0xFF6D, 0xFF71, 0xFF76, 0xFF7A, 0xFF7E, 0xFF83, 0xFF87,
	0xFF8B, 0xFF90, 0xFF94, 0xFF98, 0xFF9D, 0xFFA1, 0xFFA5, 0xFFAA,
	0xFFAE, 0xFFB2, 0xFFB7, 0xFFBB, 0xFFBF, 0xFFC4, 0xFFC8, 0xFFCC,
	0xFFD1, 0xFFD5, 0xFFD9, 0xFFDE, 0xFFE2, 0xFFE6, 0xFFEB, 0xFFEF,
	0xFFF3, 0xFFF8, 0xFFFC, 0x0000, 0x0000, 0x0004, 0x0008, 0x000D,
	0x0011, 0x0015, 0x001A, 0x001E, 0x0022, 0x0027, 0x002B, 0x002F,
	0x0034, 0x0038, 0x003C, 0x0041, 0x0045, 0x0049, 0x004E, 0x0052,
	0x0056, 0x005B, 0x005F, 0x0063, 0x0068, 0x006C, 0x0070, 0x0075,
	0x0079, 0x007D, 0x0082, 0x0086, 0x008A, 0x008F, 0x0093, 0x0097,
	0x009C, 0x00A0, 0x00A4, 0x00A9, 0x00AD, 0x00B1, 0x00B6, 0x00BA,
	0x00BE, 0x00C3, 0x00C7, 0x00CB, 0x00D0, 0x00D4, 0x00D8, 0x00DD,
	0x00E1, 0x00E5, 0x00EA, 0x00EE, 0x00F2, 0x00F7, 0x00FB, 0x0100,
};

void NewEfxSRankWeaponEffectSCR(void)
{
	struct ProcEfx *proc;

	proc = SpawnProc(ProcScr_EfxSRankWeaponEffectSCR, PROC_TREE_3);
	proc->timer = 0;
	proc->step = 0;
	proc->unk44 = 0;
	NewEfxSRankWeaponEffectSCR2(proc);
}

void EfxSRankWeaponEffectSCR_Loop(struct ProcEfx *proc)
{
	u32 i;
	u16 *dst1, *dst2;

	dst1 = !gEkrBg1ScrollFlip
		? gpBg2ScrollOffsetTable2
		: gpBg2ScrollOffsetTable1;

	dst2 = !gEkrBg1ScrollFlip
		? gpBg1ScrollOffsetList2
		: gpBg1ScrollOffsetList1;

	for (i = 0; i < 160;  i++) {
		if (i < 120) {
			i16 ref = EfxSRankWeaponEffectSCR_Ref[i] *proc->unk44 >> 0xC;

			if (ref) {
				if (i < 60) {
					if (ref < i - 0x88)
						ref = i + -0x88; // required for matching
				} else {
					if (ref > 0x88 - i)
						ref = 0x88 - i;
				}
			}
			*dst1++ = ref;
			*dst2++ = ref;
		} else {
			*dst1++ = 0;
			*dst2++ = 0;
		}
	}
}

void NewEfxSRankWeaponEffectSCR2(struct ProcEfx *seff_scr)
{
	struct ProcEfxSRankSCR2 *proc;

	proc = SpawnProc(ProcScr_EfxSRankWeaponEffectSCR2, PROC_TREE_3);
	proc->timer = 0;
	proc->terminator = 0x28;
	proc->seff_scr1 = seff_scr;
}

void EfxSRankWeaponEffectSCR2_Loop(struct ProcEfxSRankSCR2 *proc)
{
	struct ProcEfx *seff_scr = proc->seff_scr1;

	seff_scr->unk44 = 
		Interpolate(INTERPOLATE_LINEAR, 0, 0x40000, proc->timer, proc->terminator);

	if (++proc->timer > proc->terminator) {
		Proc_End(seff_scr);
		Proc_Break(proc);
	}
}

/**
 * Some efx-dragon effects?
 */
struct ProcScr CONST_DATA ProcScr_EfxMagdhisEffect[] = {
	PROC_NAME_DEBUG("efxMagdhisEffect"),
	PROC_REPEAT(EfxMagdhisEffect_Loop),
	PROC_END,
};

void NewEfxMagdhisEffect(struct Anim *anim)
{
	struct ProcEfx *proc;

	SpellFx_ClearBG1Position();
	proc = SpawnProc(ProcScr_EfxMagdhisEffect, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
}

void EfxMagdhisEffect_Loop(struct ProcEfx *proc)
{
	if (++proc->timer == 0x11) {
		NewEfxMagdhisEffectBG(proc->anim, 0x49);
		EfxPlaySE(SONG_140, 0x100);
		M4aPlayWithPostionCtrl(SONG_140, proc->anim->xPosition, 1);
	}

	if (proc->timer == 0x64)
		Proc_Break(proc);
}

struct ProcScr CONST_DATA ProcScr_EfxMagdhisEffectBG[] = {
	PROC_NAME_DEBUG("efxMagdhisEffectBG"),
	PROC_REPEAT(EfxMagdhisEffectBG_Loop),
	PROC_END,
};

CONST_DATA u16 * TsaArray_EfxMagdhisEffectBG[] = {
	Tsa1_EfxMagdhisEffectBG,
	Tsa2_EfxMagdhisEffectBG,
	Tsa3_EfxMagdhisEffectBG,
	Tsa4_EfxMagdhisEffectBG
};

const u16 FrameConf_EfxMagdhisEffectBG[] = {
	0, 2,
	1, 2,
	2, 2,
	3, 2,
	2, 2,
	1, 2,
	0, 2,

	-2
};

void NewEfxMagdhisEffectBG(struct Anim *anim, int arg1)
{
	struct ProcEfxBG *proc;
	gEfxBgSemaphore++;

	proc = SpawnProc(ProcScr_EfxMagdhisEffectBG, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->terminator = 0;
	proc->unk30 = arg1;
	proc->frame = 0;
	proc->frame_config = FrameConf_EfxMagdhisEffectBG;
	proc->tsal = TsaArray_EfxMagdhisEffectBG;
	proc->tsar = TsaArray_EfxMagdhisEffectBG;

	SpellFx_RegisterBgPal(Pal_EfxMagdhisEffectBG, 0x20);
	SpellFx_RegisterBgGfx(Img_EfxMagdhisEffectBG, 0x2000);
	SpellFx_SetSomeColorEffect();

	gDispIo.bg0_ct.priority = 0;
	gDispIo.bg2_ct.priority = 1;
	gDispIo.bg1_ct.priority = 2;
	gDispIo.bg3_ct.priority = 3;
	SetBgOffset(BG_1, 0x10, 0x0);
}

void EfxMagdhisEffectBG_Loop(struct ProcEfxBG *proc)
{
	i16 ret = EfxAdvanceFrameLut(
		(void *)&proc->timer,
		(void *)&proc->frame,
		proc->frame_config
	);

	if (ret >= 0) {
		u16 **buf1 = proc->tsal;
		u16 **buf2 = proc->tsar;
		SpellFx_WriteBgMap(proc->anim, buf1[ret], buf2[ret]);
	}

	if (++proc->terminator == proc->unk30) {
		gDispIo.bg0_ct.priority = 0;
		gDispIo.bg1_ct.priority = 1;
		gDispIo.bg3_ct.priority = 2;
		gDispIo.bg2_ct.priority = 3;

		SpellFx_ClearBG1();
		gEfxBgSemaphore--;
		SpellFx_ClearColorEffects();
		Proc_Break(proc);
	}
}

/**
 * C47: banim_code_cape_flowing
 */
struct ProcScr CONST_DATA ProcScr_EfxMantBatabata[] = {
    PROC_NAME_DEBUG("efxMantBatabata"),
    PROC_REPEAT(EfxMantBatabata_1),
    PROC_REPEAT(EfxMantBatabata_2),
    PROC_END,
};

void NewEfxMantBatabata(struct Anim *anim)
{
	i16 banim_index;
	u32 *scr1, *scr2;
	struct ProcEfxOBJ *proc;
	struct Anim *anim2;

	banim_index = gBanimIdx[GetAnimPosition(anim)] - 0xC;
	switch (banim_index) {
	case BANIM_0C - 0xC:
	case BANIM_0D - 0xC:
		scr1 = AnimScr_EfxMantBatabata1_R;
		scr2 = AnimScr_EfxMantBatabata1_L;
		break;

	case BANIM_11 - 0xC:
	case BANIM_35 - 0xC:
		scr1 = AnimScr_EfxMantBatabata2_R;
		scr2 = AnimScr_EfxMantBatabata2_L;
		break;

	case BANIM_0E - 0xC:
	case BANIM_0F - 0xC:
	case BANIM_10 - 0xC:
	case (BANIM_12 - 0xC) ... (BANIM_34 - 0xC):
	default:
		scr1 = AnimScr_EfxMantBatabata3_R;
		scr2 = AnimScr_EfxMantBatabata3_L;
		break;
	}

	proc = SpawnProc(ProcScr_EfxMantBatabata, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	anim2 = EfxCreateFrontAnim(anim, scr2, scr1, scr2, scr1);
	proc->anim2 = anim2;

#if FE8
	gUnknown_02000010[GetAnimPosition(proc->anim)] = proc->anim2;
#endif

	anim2->oam2 &= 0xC00;

	anim2->priority = 100;
	BasSort();

	if (GetAnimPosition(anim) == POS_L)
		anim2->oam2 |= OAM2_PAL(OBPAL_EFX_UNIT_L) + OAM2_CHR(VRAMOFF_OBJ_4000 / CHR_SIZE);
	else
		anim2->oam2 |= OAM2_PAL(OBPAL_EFX_UNIT_R) + OAM2_CHR(VRAMOFF_OBJ_6000 / CHR_SIZE);
	
	SetAnimStateHidden(GetAnimPosition(proc->anim));
}

void EfxMantBatabata_1(struct ProcEfxOBJ *proc)
{
    proc->anim2->xPosition = proc->anim->xPosition;

    if (!(proc->anim->flags3 & ANIM_BIT3_C01_BLOCK_END_PREBATTLE))
        return;

    if (!(proc->anim->flags3 & ANIM_BIT3_C01_BLOCK_END_INBATTLE))
        return;

    Proc_Break(proc);
}

void EfxMantBatabata_2(struct ProcEfxOBJ *proc)
{
    proc->anim2->xPosition = proc->anim->xPosition;

    if (CheckEkrHitDone() == 0x1) {
        SetAnimStateUnHidden(GetAnimPosition(proc->anim));
        BasRemove(proc->anim2);
        Proc_Break(proc);
    }
}
