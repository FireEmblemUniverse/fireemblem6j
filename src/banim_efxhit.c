#include "prelude.h"
#include "proc.h"
#include "hardware.h"
#include "banim.h"

struct ProcScr CONST_DATA ProcScr_EfxDamageMojiEffect[] =
{
    PROC_NAME_DEBUG("efxDamageMojiEffect"),
    PROC_REPEAT(EfxDamageMojiEffect_Loop),
    PROC_END,
};

void NewEfxDamageMojiEffect(struct Anim *anim, int hitted)
{
	struct ProcEfx *proc;

	proc = SpawnProc(ProcScr_EfxDamageMojiEffect, PROC_TREE_3);

	proc->anim = anim;
	proc->timer = 0;
	proc->hitted = hitted;
}

void EfxDamageMojiEffect_Loop(struct ProcEfx *proc)
{
	int time = ++proc->timer;

	if (time == 1) {
		NewEfxDamageMojiEffectOBJ(proc->anim, proc->hitted);
		return;
	}

	if (time == 0xA) {
		Proc_Break(proc);
		return;
	}
}

struct ProcScr CONST_DATA ProcScr_EfxDamageMojiEffectOBJ[] =
{
    PROC_NAME_DEBUG("efxDamageMojiEffectOBJ"),
    PROC_REPEAT(EfxDamageMojiEffectOBJ_Loop),
    PROC_END,
};

void NewEfxDamageMojiEffectOBJ(struct Anim *anim, int hitted)
{
    u16 val1;
    u32 *anim_scr;
    struct ProcEfxDamageMojiEffectOBJ *proc;

    proc = SpawnProc(ProcScr_EfxDamageMojiEffectOBJ, PROC_TREE_3);
    proc->anim = anim;
    proc->timer = 0;

    if (hitted == 0) {
        proc->terminator = 0x32;
        anim_scr = AnimScr_NoDamage;
    } else {
        proc->terminator = 0x32;
        anim_scr = AnimScr_Miss;
    }

    val1 = GetAnimPosition(anim) == POS_L ? 0x6100 : 0x5100;

    proc->sub_proc = NewEkrsubAnimeEmulator(
        anim->xPosition,
        anim->yPosition - 0x28,
        anim_scr,
        2, val1, 0, PROC_TREE_3
    );
}

void EfxDamageMojiEffectOBJ_Loop(struct ProcEfxDamageMojiEffectOBJ *proc)
{
	proc->sub_proc->x1 = proc->anim->xPosition;

	if (++proc->timer > proc->terminator) {
		Proc_End(proc->sub_proc);
		Proc_Break(proc);
	}
}

struct ProcScr CONST_DATA ProcScr_EfxCriricalEffect[] = {
    PROC_NAME_DEBUG("efxCriticalEffect"),
    PROC_REPEAT(EfxCriricalEffect_Loop),
    PROC_END
};

void NewEfxCriricalEffect(struct Anim *anim)
{
	struct ProcEfx *proc;

#if FE8
	int is_pierce;
	struct Anim *anim1 = GetAnimAnotherSide(anim);

	is_pierce = GetRoundFlagByAnim(anim1) & ANIM_ROUND_PIERCE;
	if (is_pierce != 0) {
		NewEfxCriricalEffectEffect(anim);
		return;
	}
#endif

	SpellFx_ClearBG1Position();

	proc = SpawnProc(ProcScr_EfxCriricalEffect, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
}

void EfxCriricalEffect_Loop(struct ProcEfx *proc)
{
	int time = ++proc->timer;

	if (time == 1) {
		NewEfxCriricalEffectBG(proc->anim);
		NewEfxCriricalEffectBGCOL(proc->anim);
		return;
	}

	if (time == 0x11)
		Proc_Break(proc);
}

CONST_DATA struct ProcScr ProcScr_EfxCriricalEffectBG[] = {
	PROC_NAME_DEBUG("efxCriticalEffectBG"),
	PROC_REPEAT(EfxCriricalEffectBG_Loop),
	PROC_END
};

void NewEfxCriricalEffectBG(struct Anim *anim)
{
	struct ProcEfxBG *proc;

	proc = SpawnProc(ProcScr_EfxCriricalEffectBG, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;

	SpellFx_RegisterBgGfx(Img_EfxCriricalEffectBG, 0x2000);
	SpellFx_RegisterBgPal(Pal_EfxCriricalEffectBG, 0x20);
	SpellFx_WriteBgMap(proc->anim, Tsa_EfxCriricalEffectBG_L, Tsa_EfxCriricalEffectBG_R);
	SpellFx_SetSomeColorEffect();
}

void EfxCriricalEffectBG_Loop(struct ProcEfxBG *proc)
{
	if (++proc->timer == 0x11) {
		SpellFx_ClearBG1();
		SpellFx_ClearColorEffects();
		Proc_Break(proc);
	}
}

CONST_DATA struct ProcScr ProcScr_EfxCriricalEffectBGCOL[] = {
    PROC_NAME_DEBUG("efxCriticalEffectBGCOL"),
    PROC_MARK(PROC_MARK_PAL_CHG),
    PROC_REPEAT(EfxCriricalEffectBGCOL_Loop),
    PROC_END
};

void NewEfxCriricalEffectBGCOL(struct Anim *anim)
{
	static const u16 frams[] = {
		0x0, 1,
		0x1, 1,
		0x2, 1,
		0x3, 1,
		0x4, 1,
		0x5, 1,
		0x6, 1,
		0x7, 1,
		0x8, 1,
		0x9, 1,
		0xA, 1,
		0xB, 1,
		0xC, 1,
		0xD, 1,
		0xE, 1,
		0xF, 1,
		-1
	};

	struct ProcEfxBGCOL *proc;

	proc = SpawnProc(ProcScr_EfxCriricalEffectBGCOL, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->frame = 0;
	proc->frame_config = frams;
	proc->pal = Pal_EfxCriricalEffectBG;
}

void EfxCriricalEffectBGCOL_Loop(struct ProcEfxBGCOL *proc)
{
	int ret = EfxAdvanceFrameLut((i16 *)&proc->timer, (i16 *)&proc->frame, proc->frame_config);

	if (ret >= 0) {
		const u16 *pal = proc->pal;

		SpellFx_RegisterBgPal(pal + BGPAL_OFFSET(ret), 0x20);
		return;
	}

	if (ret == -1) {
		Proc_Break(proc);
		return;
	}
}

CONST_DATA struct ProcScr ProcScr_EfxNormalEffect[] = {
	PROC_NAME_DEBUG("efxNormalEffect"),
	PROC_REPEAT(EfxNormalEffect_Loop),
	PROC_END
};

void NewEfxNormalEffect(struct Anim *anim)
{
	struct ProcEfx *proc;

	SpellFx_ClearBG1Position();

#if FE8
{
	int is_pierce;

	is_pierce = GetRoundFlagByAnim(anim) & ANIM_ROUND_PIERCE;
	if (is_pierce != 0) {
		NewEfxPierceNormalEffect(anim);
		return;
	}
}
#endif

	proc = SpawnProc(ProcScr_EfxNormalEffect, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
}

void EfxNormalEffect_Loop(struct ProcEfx *proc)
{
	int time;
	struct Anim *anim1 = GetAnimAnotherSide(proc->anim);

	time = ++proc->timer;

	if (time == 1) {
		NewEfxFlashBgWhite(proc->anim, 0x4);
		return;
	}

	if (time == 0x4) {
		NewEfxNormalEffectBG(anim1);
		return;
	}

	if (time == 0x18) {
		Proc_Break(proc);
		return;
	}
}

CONST_DATA struct ProcScr ProcScr_EfxNormalEffectBG[] = {
	PROC_NAME_DEBUG("efxNormalEffectBG"),
	PROC_REPEAT(EfxNormalEffectBG_Loop),
	PROC_END
};

CONST_DATA u16 *TSAs_EfxNormalEffectBG[] = {
	Tsa1_EfxNormalEffectBG,
	Tsa2_EfxNormalEffectBG,
	Tsa3_EfxNormalEffectBG,
	Tsa4_EfxNormalEffectBG,
	Tsa5_EfxNormalEffectBG,
	Tsa6_EfxNormalEffectBG,
	Tsa7_EfxNormalEffectBG,
	Tsa8_EfxNormalEffectBG,
	Tsa9_EfxNormalEffectBG,
	TsaA_EfxNormalEffectBG,
};

void NewEfxNormalEffectBG(struct Anim *anim)
{
	static const u16 frames[] = {
		0, 2,
		1, 2,
		2, 2,
		3, 2,
		4, 2,
		5, 2,
		6, 1,
		7, 1,
		8, 1,
		9, 1,
		-1
	};

	struct ProcEfxBG *proc;
	gEfxBgSemaphore++;
	proc = SpawnProc(ProcScr_EfxNormalEffectBG, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->frame = 0;
	proc->frame_config = frames;
	proc->tsal = TSAs_EfxNormalEffectBG;
	proc->tsar = TSAs_EfxNormalEffectBG;

	SpellFx_RegisterBgPal(Pal_EfxNormalEffectBG, 0x20);
	SpellFx_RegisterBgGfx(Img_EfxNormalEffectBG, 0x2000);
	SpellFx_SetSomeColorEffect();

	if (gEkrDistanceType != EKR_DISTANCE_CLOSE) {
		if (GetAnimPosition(proc->anim) == POS_L)
			SetBgOffset(BG_1, 0x18, 0);
		else
			SetBgOffset(BG_1, 0xE8, 0);
	}
}

void EfxNormalEffectBG_Loop(struct ProcEfxBG *proc)
{
	int ret = EfxAdvanceFrameLut((i16 *)&proc->timer, (i16 *)&proc->frame, proc->frame_config);

	if (ret >= 0) {
		u16 **buf1 = proc->tsal;
		u16 **buf2 = proc->tsar;
		SpellFx_WriteBgMap(proc->anim, buf1[ret], buf2[ret]);
		return;
	}

	if (ret == -1) {
		SpellFx_ClearBG1();
		gEfxBgSemaphore--;
		SpellFx_ClearColorEffects();
		Proc_Break(proc);
	}
}
