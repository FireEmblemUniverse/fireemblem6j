#include "prelude.h"
#include "proc.h"
#include "hardware.h"
#include "oam.h"
#include "datamove.h"
#include "banim.h"
#include "util.h"

EWRAM_DATA ProcPtr gpActiveClassReelSpellProc = NULL;
EWRAM_DATA ProcPtr gpActiveCRSpellBgColorProc = NULL;

void ResetClassReelSpell(void)
{
	gpActiveClassReelSpellProc = NULL;
	gpActiveCRSpellBgColorProc = NULL;
}

void EndActiveClassReelSpell(void)
{
	if (gpActiveClassReelSpellProc != NULL) {
		Proc_End(gpActiveClassReelSpellProc);
		gpActiveClassReelSpellProc = NULL;
	}
}

void EndActiveClassReelBgColorProc(void)
{
	if (gpActiveCRSpellBgColorProc != NULL) {
		Proc_End(gpActiveCRSpellBgColorProc);
		gpActiveCRSpellBgColorProc = NULL;
	}
}

void SetActiveClassReelSpell(ProcPtr proc)
{
	gpActiveClassReelSpellProc = proc;
}

void SetActiveCRSpellBgColorProc(ProcPtr proc)
{
	gpActiveCRSpellBgColorProc = proc;
}

struct EfxopMagicDesc *GetMagicEffectBufferFor(struct Anim *anim)
{
	return ((struct EkrMainMiniDesc *)anim->priv)->magicfx_desc;
}

void SetCRSpellBgPosition(struct Anim *anim, struct EfxopMagicDesc *magicFx)
{
	s16 x, y;

	if (GetAnimPosition(anim) == 0)
		x = anim->xPosition - BanimTypesPosLeft[0];
	else
		x = BanimTypesPosRight[0] - anim->xPosition;

	y = 88 - anim->yPosition;

	SetBgOffset(magicFx->bg, x - magicFx->xOffsetBg, y - magicFx->yOffsetBg);
}

void ClearCRSpellBgTmBuf(struct Anim *anim)
{
	struct EfxopMagicDesc *magicFx = GetMagicEffectBufferFor(anim);

	CpuFastFill(0, magicFx->bgTmBuf, 0x800);
	EnableBgSync(1 << magicFx->bg);
}

struct Anim *CRSpellCreateFrontAnim(struct Anim *anim, u16 scrIdx, void *scrA, void *scrB)
{
	struct Anim *newAnim;
	struct EfxopMagicDesc *magicFx = GetMagicEffectBufferFor(anim);

	if (scrIdx == 0)
		newAnim = BasCreate(scrA, 120);
	else
		newAnim = BasCreate(scrB, 120);

	newAnim->oam2 = (magicFx->objPalId << 12) | magicFx->objChr | OAM2_LAYER(2);
	newAnim->xPosition = anim->xPosition;
	newAnim->yPosition = anim->yPosition;

	return newAnim;
}

void CRSpell_WriteBgMap(struct Anim *anim, u16 notFlipped, void *src, u16 isCompressed)
{
	void *buf;
	struct EfxopMagicDesc *magicFx = GetMagicEffectBufferFor(anim);

	if (isCompressed == 1)
		LZ77UnCompWram(src, magicFx->bgTsaBuf);

	buf = src;
	if (isCompressed == 1)
		buf = magicFx->bgTsaBuf;

	if (notFlipped == 0)
		EfxTmCpyBgHFlip(buf, magicFx->bgTmBuf, 30, 20, magicFx->bgPalId, magicFx->bgChr);
	else
		EfxTmCpyBG(buf, magicFx->bgTmBuf, 30, 20, magicFx->bgPalId, magicFx->bgChr);

	EnableBgSync(1 << magicFx->bg);
}

void CRSpell_RegisterBgGfx(struct Anim *anim, const void *src)
{
	struct EfxopMagicDesc *magicFx = GetMagicEffectBufferFor(anim);

	void *dst = (void *)(VRAM + magicFx->bgChr *CHR_SIZE);

	LZ77UnCompWram(src, magicFx->bgImgBuf);
	RegisterDataMove(magicFx->bgImgBuf, dst, 0x2000);
}

void CRSpell_RegisterBgPal(struct Anim *anim, const u16 *src)
{
	struct EfxopMagicDesc *magicFx = GetMagicEffectBufferFor(anim);

	CpuFastCopy(src, gPal + (magicFx->bgPalId *0x10), PLTT_SIZE_4BPP);
	EnablePalSync();
}

void CRSpell_RegisterObjGfx(struct Anim *anim, const void *src)
{
	struct EfxopMagicDesc *magicFx = GetMagicEffectBufferFor(anim);

	void *dst = (void *)(OBJ_VRAM0 + magicFx->objChr *CHR_SIZE);

	LZ77UnCompWram(src, magicFx->objImgBuf);
	RegisterDataMove(magicFx->objImgBuf, dst, 0x1000);
}

void CRSpell_RegisterObjPal(struct Anim *anim, const u16 *src)
{
	struct EfxopMagicDesc *magicFx = GetMagicEffectBufferFor(anim);

	CpuFastCopy(src, gPal + 0x100 + (magicFx->objPalId *0x10), PLTT_SIZE_4BPP);
	EnablePalSync();
}

void (* CONST_DATA gClassReelSpellAnimFuncLut[8])(struct Anim *anim) = {
	[CRSPELL_DUMMY]   = StartClassReelSpellAnimDummy,
	[CRSPELL_FIRE]    = StartClassReelSpellAnimFire,
	[CRSPELL_THUNDER] = StartClassReelSpellAnimThunder,
	[CRSPELL_HEAL]    = StartClassReelSpellAnimHeal,
};

void StartClassReelSpellAnim(struct Anim *anim)
{
	struct EfxopMagicDesc * magicFx = GetMagicEffectBufferFor(anim);

#if BUGFIX
	if (gClassReelSpellAnimFuncLut[magicFx->magicFuncIdx] == NULL)
		return;
#endif

	gClassReelSpellAnimFuncLut[magicFx->magicFuncIdx](anim);
}

/**
* efxop magicfx
*/
void StartClassReelSpellAnimDummy(struct Anim *anim) {}

struct ProcScr CONST_DATA ProcScr_EfxopFire[] = {
	PROC_19,
	PROC_REPEAT(EfxopFire_Loop),
	PROC_SLEEP(50),
	PROC_CALL(EndActiveClassReelSpell),
	PROC_END,
};

void StartClassReelSpellAnimFire(struct Anim * anim)
{
	struct ProcEfx *proc = SpawnProc(ProcScr_EfxopFire, PROC_TREE_3);

	SetActiveClassReelSpell(proc);
	proc->anim = anim;
}

void EfxopFire_Loop(struct ProcEfx *proc)
{
	NewEfxopFireBG(proc->anim, proc);
	NewEfxopFireOBJ(proc->anim, proc);

	Proc_Break(proc);
}

struct ProcScr CONST_DATA ProcScr_EfxopFireBG[] = {
	PROC_19,
	PROC_REPEAT(EfxopFireBG_Loop),
	PROC_END,
};

CONST_DATA u16 *TsaArray_EfxopFireBG[] = {
	Tsa_EfxFireBG_0812E4C4,
	Tsa_EfxFireBG_0812E56C,
	Tsa_EfxFireBG_0812E614,
	Tsa_EfxFireBG_0812E6CC,
	Tsa_EfxFireBG_0812E794,
	Tsa_EfxFireBG_0812E864,
	Tsa_EfxFireBG_0812E964,
	Tsa_EfxFireBG_0812EA6C,
	Tsa_EfxFireBG_0812EB80,
	Tsa_EfxFireBG_0812ECB8,
	Tsa_EfxFireBG_0812EDBC,
	Tsa_EfxFireBG_0812EE90
};

const u16 FrameArray_EfxopFireBG[] = {
	0, 3,
	1, 2,
	2, 2,
	3, 2,
	4, 2,
	5, 2,
	6, 2,
	7, 2,
	8, 2,
	9, 3,
	10, 3,
	11, 3,
	-1,
};

void NewEfxopFireBG(struct Anim *anim, struct ProcEfx *parent)
{
	struct EfxopMagicDesc *magicFx = GetMagicEffectBufferFor(anim);
	struct ProcEfxBG *proc = SpawnProc(ProcScr_EfxopFireBG, parent);

	proc->anim = anim;
	proc->timer = 0;

	proc->frame = 0;
	proc->frame_config = FrameArray_EfxopFireBG;
	proc->tsal = TsaArray_EfxopFireBG;

	CRSpell_RegisterBgPal(anim, Pal_EfxFireBG);
	CRSpell_RegisterBgGfx(proc->anim, Img_EfxFireBG);

	magicFx->resetCallback();

	SetCRSpellBgPosition(proc->anim, magicFx);
}

void EfxopFireBG_Loop(struct ProcEfxBG *proc)
{
	s16 ret = EfxAdvanceFrameLut((s16 *)&proc->timer, (s16 *)&proc->frame, proc->frame_config);

	if (ret >= 0) {
		u16 **tsaL = proc->tsal;

		CRSpell_WriteBgMap(proc->anim, 1, *(tsaL + ret), 1);
		return;
	}

	if (ret == -1) {
		ClearCRSpellBgTmBuf(proc->anim);
		SpellFx_ClearColorEffects();
		Proc_Break(proc);
	}
}

struct ProcScr CONST_DATA ProcScr_EfxopFireOBJ[] = {
	PROC_19,
	PROC_REPEAT(EfxopFireOBJ_Loop),
	PROC_END,
};

void NewEfxopFireOBJ(struct Anim *anim, struct ProcEfx *parent)
{
	struct Anim *frontAnim;
	struct EfxopMagicDesc *magicFx = GetMagicEffectBufferFor(anim);
	struct ProcEfxOBJ *proc = SpawnProc(ProcScr_EfxopFireOBJ, parent);

	proc->anim = anim;
	proc->timer = 0;

	frontAnim = CRSpellCreateFrontAnim(anim, 1, AnimScr_EfxFireOBJ_R_Front, AnimScr_EfxFireOBJ_L_Front);
	proc->anim2 = frontAnim;

	if (GetAnimPosition(anim) == POS_L)
		frontAnim->xPosition = anim->xPosition - 8;
	else
		frontAnim->xPosition = anim->xPosition + 8;

	frontAnim->yPosition = anim->yPosition + 8;

	frontAnim->xPosition += magicFx->xOffsetObj;
	frontAnim->yPosition += magicFx->yOffsetObj;

	CRSpell_RegisterObjPal(proc->anim, Pal_EfxFireOBJ);
	CRSpell_RegisterObjGfx(proc->anim, Img_EfxFireOBJ);
}

void EfxopFireOBJ_Loop(struct ProcEfxOBJ * proc)
{
	proc->timer++;
	if (proc->timer > 50) {
		BasRemove(proc->anim2);
		Proc_Break(proc);
	}
}

struct ProcScr CONST_DATA ProcScr_EfxopThunder[] = {
	PROC_19,
	PROC_REPEAT(EfxopThunder_Loop),
	PROC_SLEEP(50),
	PROC_CALL(EndActiveClassReelSpell),
	PROC_END,
};

void StartClassReelSpellAnimThunder(struct Anim *anim)
{
	struct ProcEfx *proc = SpawnProc(ProcScr_EfxopThunder, PROC_TREE_3);

	SetActiveClassReelSpell(proc);
	proc->anim = anim;
}

void EfxopThunder_Loop(struct ProcEfx *proc)
{
	NewEfxopThunderBG(proc->anim, proc);
	NewEfxopThunderBGCOL(proc->anim, proc);
	NewEfxopThunderOBJ(proc->anim, proc);

	Proc_Break(proc);
}

struct ProcScr CONST_DATA ProcScr_EfxopThunderBG[] = {
	PROC_19,
	PROC_REPEAT(EfxopThunderBG_Loop),
	PROC_END,
};

u16 *CONST_DATA TsaArray_EfxopThunderBG[] = {
	Tsa_EfxThuderBg1,
	Tsa_EfxThuderBg2,
};

void NewEfxopThunderBG(struct Anim *anim, struct ProcEfx *unused)
{
	static const u16 frames[] = {
		0, 4,
		1, 40,
		-1,
	};

	struct EfxopMagicDesc *magicFx = GetMagicEffectBufferFor(anim);
	struct ProcEfxBG *proc = SpawnProc(ProcScr_EfxopThunderBG, PROC_TREE_3);

	proc->anim = anim;
	proc->timer = 0;

	proc->frame = 0;
	proc->frame_config = frames;

	proc->tsal = TsaArray_EfxopThunderBG;

	CRSpell_RegisterBgPal(anim, Pal_EfxThunderBGCOL);
	CRSpell_RegisterBgGfx(proc->anim, Img_EfxThunderBG);

	magicFx->resetCallback();

	SetCRSpellBgPosition(proc->anim, magicFx);
}

void EfxopThunderBG_Loop(struct ProcEfxBG *proc)
{
	u16 chr = 0;
	struct EfxopMagicDesc *magicFx = GetMagicEffectBufferFor(proc->anim);

	s16 ret = EfxAdvanceFrameLut((s16 *)&proc->timer, (s16 *)&proc->frame, proc->frame_config);

	if (ret >= 0) {
		u16 **tsaL = proc->tsal;

		CRSpell_WriteBgMap(proc->anim, 0, *(tsaL + ret), 1);

		if (ret == 0)
			chr = magicFx->bgChr + 31;

		if (ret == 1)
			chr = magicFx->bgChr + 80;

		FillBGRect(magicFx->bgTmBuf + 0x1E, 2, 20, magicFx->bgPalId, chr);
		return;
	}

	if (ret == -1) {
		ClearCRSpellBgTmBuf(proc->anim);
		SpellFx_ClearColorEffects();
		Proc_Break(proc);
	}
}

struct ProcScr CONST_DATA ProcScr_EfxopThunderBGCOL[] = {
	PROC_19,
	PROC_MARK(10),
	PROC_REPEAT(EfxopThunderBGCOL_Loop),
	PROC_END,
};

void NewEfxopThunderBGCOL(struct Anim *anim, struct ProcEfx *unused)
{
	static const u16 frames[] = {
		0, 4,
		1, 4,
		2, 2,
		3, 2,
		4, 20,
		5, 2,
		6, 1,
		7, 1,
		8, 1,
		9, 1,
		10, 1,
		11, 1,
		12, 1,
		13, 1,
		14, 1,
		15, 1,
		-1,
	};

	struct ProcEfxBGCOL *proc = SpawnProc(ProcScr_EfxopThunderBGCOL, PROC_TREE_3);
	SetActiveCRSpellBgColorProc(proc);

	proc->anim = anim;
	proc->timer = 0;

	proc->frame = 0;
	proc->frame_config = frames;

	proc->pal = Pal_EfxThunderBGCOL;
}

void EfxopThunderBGCOL_Loop(struct ProcEfxBGCOL * proc)
{
	s16 ret = EfxAdvanceFrameLut((s16 *)&proc->timer, (s16 *)&proc->frame, proc->frame_config);

	if (ret >= 0) {
		const u16 *pal = proc->pal;

		CRSpell_RegisterBgPal(proc->anim, pal + ret * 0x10);
		return;
	}

	if (ret == -1) {
		EndActiveClassReelBgColorProc();
		Proc_Break(proc);
	}
}

struct ProcScr CONST_DATA ProcScr_EfxopThunderOBJ[] = {
	PROC_19,
	PROC_REPEAT(EfxopThunderOBJ_Loop),
	PROC_END,
};

void NewEfxopThunderOBJ(struct Anim *anim, struct ProcEfx *unused)
{
	struct Anim *frontAnim;
	struct EfxopMagicDesc *magicFx = GetMagicEffectBufferFor(anim);
	struct ProcEfxOBJ *proc = SpawnProc(ProcScr_EfxopThunderOBJ, PROC_TREE_3);

	proc->anim = anim;
	proc->timer = 0;

	frontAnim = CRSpellCreateFrontAnim(anim, 1, AnimScr_EfxThunderOBJ_L, AnimScr_EfxThunderOBJ_R);
	proc->anim2 = frontAnim;

	if (GetAnimPosition(anim) == POS_L)
		frontAnim->xPosition = anim->xPosition + 56;
	else
		frontAnim->xPosition = anim->xPosition - 56;

	frontAnim->xPosition += magicFx->xOffsetObj;
	frontAnim->yPosition += magicFx->yOffsetObj;

	CRSpell_RegisterObjPal(proc->anim, Pal_EfxThunderOBJ);
	CRSpell_RegisterObjGfx(proc->anim, Img_EfxThunderOBJ);
}

void EfxopThunderOBJ_Loop(struct ProcEfxOBJ *proc)
{
	proc->timer++;

	if (proc->timer > 50) {
		BasRemove(proc->anim2);
		Proc_Break(proc);
	}
}

struct ProcScr CONST_DATA ProcScr_EfxopLive[] = {
	PROC_19,
	PROC_REPEAT(EfxopLive_Loop),
	PROC_SLEEP(70),
	PROC_CALL(EndActiveClassReelSpell),
	PROC_END,
};

void StartClassReelSpellAnimHeal(struct Anim *anim)
{
	struct ProcEfx *proc = SpawnProc(ProcScr_EfxopLive, PROC_TREE_3);

	proc->anim = anim;
	proc->timer = 0;
}

void EfxopLive_Loop(struct ProcEfx * proc)
{
	NewEfxopLiveOBJ(proc->anim, proc);
	NewEfxopLiveBG(proc->anim, proc);
	NewEfxopLiveBGCOL(proc->anim, proc);

	SetBlendAlpha(0, 16);

	NewEfxopLiveALPHA(proc->anim, 1, 12, 0, proc);
	NewEfxopLiveALPHA(proc->anim, 35, 25, 1, proc);

	Proc_Break(proc);
}

struct ProcScr CONST_DATA ProcScr_EfxopLiveBG[] = {
	PROC_19,
	PROC_REPEAT(EfxopLiveBG_Loop),
	PROC_END,
};

u16 *CONST_DATA TsaArray_EfxopLiveBG[] = {
	Tsa_Uncomp_EfxLiveBG_BB_L
};

void NewEfxopLiveBG(struct Anim *anim, struct ProcEfx *unused)
{
	static const u16 frames[] = {
		0, 62,
		-1,
	};

	struct EfxopMagicDesc *magicFx = GetMagicEffectBufferFor(anim);
	struct ProcEfxBG * proc = SpawnProc(ProcScr_EfxopLiveBG, PROC_TREE_3);

	SetActiveClassReelSpell(proc);

	proc->anim = anim;
	proc->timer = 0;
	proc->frame = 0;
	proc->frame_config = frames;
	proc->tsal = TsaArray_EfxopLiveBG;

	CRSpell_RegisterBgGfx(anim, Img_EfxHealCommon);
	magicFx->resetCallback();
	SetCRSpellBgPosition(proc->anim, magicFx);
}

void EfxopLiveBG_Loop(struct ProcEfxBG *proc)
{
	s16 ret = EfxAdvanceFrameLut((s16 *)&proc->timer, (s16 *)&proc->frame, proc->frame_config);

	if (ret >= 0) {
		u16 ** tsaL = proc->tsal;

		CRSpell_WriteBgMap(proc->anim, 1, *(tsaL + ret), 0);
		return;
	}

	if (ret == -1) {
		ClearCRSpellBgTmBuf(proc->anim);
		SpellFx_ClearColorEffects();
		Proc_Break(proc);
	}
}

struct ProcScr CONST_DATA ProcScr_EfxopLiveBGCOL[] = {
	PROC_19,
	PROC_MARK(10),
	PROC_REPEAT(EfxopLiveBGCOL_Loop),
	PROC_END,
};

void NewEfxopLiveBGCOL(struct Anim *anim, struct ProcEfx *unused)
{
	static const u16 frames[] = {
		0, 3,
		1, 3,
		2, 3,
		3, 4,
		4, 4,
		5, 4,
		6, 4,
		7, 4,
		8, 4,
		9, 4,
		10, 4,
		11, 4,
		12, 4,
		13, 4,
		14, 4,
		15, 5,
		-1,
	};

	struct ProcEfxBGCOL *proc = SpawnProc(ProcScr_EfxopLiveBGCOL, PROC_TREE_3);
	SetActiveCRSpellBgColorProc(proc);

	proc->anim = anim;
	proc->timer = 0;
	proc->frame = 0;
	proc->frame_config = frames;
	proc->pal = Pals1_EfxLiveBGCOL;
}

void EfxopLiveBGCOL_Loop(struct ProcEfxBGCOL *proc)
{
	s16 ret = EfxAdvanceFrameLut((s16 *)&proc->timer, (s16 *)&proc->frame, proc->frame_config);

	if (ret >= 0) {
		const u16 *pal = proc->pal;

		CRSpell_RegisterBgPal(proc->anim, pal + ret * 0x10);
		return;
	}

	if (ret == -1) {
		EndActiveClassReelBgColorProc();
		Proc_Break(proc);
	}
}

struct ProcScr CONST_DATA ProcScr_EfxopLiveALPHA[] = {
	PROC_19,
	PROC_REPEAT(EfxopLiveALPHA_Loop1),
	PROC_REPEAT(EfxopLiveALPHA_Loop2),
	PROC_END,
};

void NewEfxopLiveALPHA(struct Anim * anim, int timer, int delay, int type, struct ProcEfx *unused)
{
	struct ProcEfxALPHA *proc = SpawnProc(ProcScr_EfxopLiveALPHA, PROC_TREE_3);

	proc->anim = anim;
	proc->timer = timer;
	proc->delay = delay;
	proc->unk29 = type;
}

void EfxopLiveALPHA_Loop1(struct ProcEfxALPHA *proc)
{
	if (--proc->timer == 0)
		Proc_Break(proc);
}

void EfxopLiveALPHA_Loop2(struct ProcEfxALPHA * proc)
{
	int bldA;

	if (proc->timer > proc->delay) {
		Proc_Break(proc);
		return;
	}

	if (proc->unk29 == 0)
		bldA = Interpolate(INTERPOLATE_LINEAR, 0, 16, proc->timer, proc->delay);
	else
		bldA = Interpolate(INTERPOLATE_LINEAR, 16, 0, proc->timer, proc->delay);

	SetBlendAlpha(bldA, 16);
	proc->timer++;
}

struct ProcScr CONST_DATA ProcScr_EfxopLiveOBJ[] = {
	PROC_19,
	PROC_REPEAT(EfxopLiveOBJ_Loop),
	PROC_END,
};

void NewEfxopLiveOBJ(struct Anim *anim, struct ProcEfx *unused)
{
	struct Anim *frontAnim;

	struct EfxopMagicDesc *magicFx = GetMagicEffectBufferFor(anim);
	struct ProcEfxOBJ *proc = SpawnProc(ProcScr_EfxopLiveOBJ, PROC_TREE_3);

	proc->anim = anim;
	proc->timer = 0;
	proc->terminator = 51;

	frontAnim = CRSpellCreateFrontAnim(anim, 1, AnimScr_EfxLiveOBJ, AnimScr_EfxLiveOBJ);
	proc->anim2 = frontAnim;

	frontAnim->xPosition += magicFx->xOffsetObj;
	frontAnim->yPosition += magicFx->yOffsetObj;

	CRSpell_RegisterObjPal(proc->anim, Pal_EfxFimbulvetrOBJ);
	CRSpell_RegisterObjGfx(proc->anim, Img_EfxLiveOBJ);
}

void EfxopLiveOBJ_Loop(struct ProcEfxOBJ *proc)
{
	proc->timer++;

	if (proc->timer == proc->terminator) {
		BasRemove(proc->anim2);
		Proc_Break(proc);
	}
}
