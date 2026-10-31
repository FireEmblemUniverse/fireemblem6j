#include "prelude.h"
#include "proc.h"
#include "oam.h"
#include "util.h"
#include "banim.h"
#include "constants/songs.h"

EWRAM_OVERLAY(banim) struct ProcEfx *gpProcEkrClasschg = NULL;

bool EkrClasschgFinished(void)
{
	if (gpProcEkrClasschg->hitted == true)
		return true;

	return false;
}

void EndEkrClasschg(void)
{
	Proc_End(gpProcEkrClasschg);
}

CONST_DATA struct ProcScr ProcScr_EkrClasschg[] = {
	PROC_NAME_DEBUG("ekrClasschg"),
	PROC_REPEAT(EkrClasschg_Loop),
	PROC_REPEAT(EkrClasschg_Done),
	PROC_END
};

void NewEkrClassChg(struct Anim * anim)
{
	NewEfxSpellCast();

	gpProcEkrClasschg = SpawnProc(ProcScr_EkrClasschg, PROC_TREE_3);
	gpProcEkrClasschg->anim = anim;
	gpProcEkrClasschg->timer = 0;
	gpProcEkrClasschg->hitted = false;
}

void EkrClasschg_Loop(struct ProcEfx *proc)
{
	ProcPtr proc_rst;
	struct Anim *anim_other = GetAnimAnotherSide(proc->anim);

	proc->timer++;

	if (proc->timer == 0x01) {
		DisableEfxStatusUnits(proc->anim);
		DisableEfxStatusUnits(anim_other);

		NewEkrClasschgBG1(anim_other);
		NewEfxClasschgBGSE00(anim_other);

		SetWinEnable(0, 0, 0);
		return;
	}

	if (proc->timer == 0x5F) {
		NewEfxFlashBgWhite(proc->anim, 10);
		PlaySFX(SONG_13B, 0x100, proc->anim->xPosition, 1);
		SetBgOffset(BG_1, 0, 8);
		return;
	}

	if (proc->timer == 0x6A) {
		proc->anim->oam2 &= (0xFFFF & (~OAM2_LAYER_MASK));
		proc->anim->oam2 |= OAM2_LAYER(1);
		return;
	}

	if (proc->timer == 0x74) {
		NewEfxBlackInOutUnit(proc->anim, 12, false);
		return;
	}

	if (proc->timer == 0x78) {
		NewEfxClasschgOBJ(proc->anim);
		return;
	}

	if (proc->timer == 0x80) {
		SetAnimStateHidden(POS_R);
		return;
	}

	// ...
	if (proc->timer == 0x7E) {
		proc_rst = NewEfxRestRST(proc->anim, 0x38, 7, 0, 2);
		NewEfxClasschgRST(proc->anim, proc_rst, 0x38, 0, 0x40);
		NewEfxRestWINH_(proc->anim, 0x38, EfxRestWINH_DefaultHblank);
		NewEfxALPHA(proc->anim, 0, 0x38, 0x10, 0, 0);
		return;
	}

	if (proc->timer == 0xF2) {
		NewEkrClasschgBG2(proc->anim);
		NewEfxClasschgBGSE01(proc->anim);
		SetWinEnable(0, 0, 0);

		proc_rst = NewEfxRestRST(proc->anim, 0x38, 7, 0x40, 2);
		NewEfxClasschgRST(proc->anim, proc_rst, 0x38, 0x40, 0);
		NewEfxRestWINH_(proc->anim, 0x38, EfxRestWINH_DefaultHblank);
		SetBlendAlpha(0x0, 0x10);
		NewEfxALPHA(proc->anim, 0, 0x38, 0, 0x10, 0);
		PlaySFX(SONG_13C, 0x100, anim_other->xPosition, 1);
		return;
	}

	if (proc->timer == 0x138) {
		SetAnimStateUnHidden(POS_L);

		anim_other->oam2 &= (0xFFFF & (~OAM2_LAYER_MASK));
		anim_other->oam2 |= OAM2_LAYER(1);

		NewEfxBlackInOutUnit(anim_other, 12, true);
		return;
	}

	if (proc->timer == 0x13E) {
		NewEfxClasschgOBJ(anim_other);
		NewEfxFlashBgWhite(proc->anim, 10);
		SetBgOffset(BG_1, 0, 0);
		return;
	}

	if (proc->timer == 0x14A) {
		anim_other->oam2 &= (0xFFFF & (~OAM2_LAYER_MASK));
		anim_other->oam2 |= OAM2_LAYER(2);
		return;
	}

	if (proc->timer == 0x15A) {
		EndEfxSpellCastAsync();
		NewEfxWhiteIN(anim_other, 10, 70);
		return;
	}

	if (proc->timer == 0x164) {
		NewEfxClasschgFIN(anim_other, 0x82);
		NewEfxClasschgCLONE(anim_other, 0x82);
		NewEfxALPHA(anim_other, 0x5A, 0x28, 0xE, 0x0, 0x2);
		NewEfxRestRST(anim_other, 0x82, 0xA, 0x100, 0x1);
		NewEfxRestWINH_(anim_other, 0x82, EfxRestWINH_DefaultHblank);
		PlaySFX(SONG_13D, 0x100, anim_other->xPosition, 1);
		return;
	}

	if (proc->timer == 0x250) {
		Proc_Break(proc);
		return;
	}
}

void EkrClasschg_Done(struct ProcEfx *proc)
{
	proc->hitted = true;
}

CONST_DATA struct ProcScr ProcScr_EfxClasschgBG[] = {
	PROC_NAME_DEBUG("efxClasschgBG"),
	PROC_REPEAT(EfxClasschgBG_Loop),
	PROC_END
};

CONST_DATA u16 *TsaArray_EkrClasschgBG[] = {
	Tsa_EkrClasschgBG_08127798,
	Tsa_EkrClasschgBG_08127950,
	Tsa_EkrClasschgBG_08127AE4,
	Tsa_EkrClasschgBG_08127C9C,
	Tsa_EkrClasschgBG_08127E60,
	Tsa_EkrClasschgBG_08127F9C,
	Tsa_EkrClasschgBG_08128034,
	Tsa_EkrClasschgBG_08128128,
	Tsa_EkrClasschgBG_08128218,
	Tsa_EkrClasschgBG_08128308,
	Tsa_EkrClasschgBG_08128470,
	Tsa_EkrClasschgBG_08128584,
	Tsa_EkrClasschgBG_08128700,
	Tsa_EkrClasschgBG_08128828,
	Tsa_EkrClasschgBG_08128A0C,
	Tsa_EkrClasschgBG_08128B5C,
	Tsa_EkrClasschgBG_08128CE8,
	Tsa_EkrClasschgBG_08128DD4,
	Tsa_EkrClasschgBG_08128EB4,
	Tsa_EkrClasschgBG_08128FAC,
	Tsa_EkrClasschgBG_081290D0,
	Tsa_EkrClasschgBG_0812921C,
	Tsa_EkrClasschgBG_0812938C,
};

CONST_DATA u16 *ImgArray_EkrClasschgBG[] = {
	Img_EkrClasschgBG_0812542C,
	Img_EkrClasschgBG_0812542C,
	Img_EkrClasschgBG_0812542C,
	Img_EkrClasschgBG_0812542C,
	Img_EkrClasschgBG_0812542C,
	Img_EkrClasschgBG_0812542C,
	Img_EkrClasschgBG_0812542C,
	Img_EkrClasschgBG_0812542C,
	Img_EkrClasschgBG_0812542C,
	Img_EkrClasschgBG_0812542C,
	Img_EkrClasschgBG_0812542C,
	Img_EkrClasschgBG_0812542C,
	Img_EkrClasschgBG_0812542C,
	Img_EkrClasschgBG_0812542C,
	Img_EkrClasschgBG_0812542C,
	Img_EkrClasschgBG_0812542C,
	Img_EkrClasschgBG_0812542C,
	Img_EkrClasschgBG_081269BC,
	Img_EkrClasschgBG_081269BC,
	Img_EkrClasschgBG_081269BC,
	Img_EkrClasschgBG_081269BC,
	Img_EkrClasschgBG_081269BC,
	Img_EkrClasschgBG_081269BC,
};

CONST_DATA u16 *PalArray_EkrClasschgBG[] = {
	Pal_EkrClasschgBG_08127738,
	Pal_EkrClasschgBG_08127738,
	Pal_EkrClasschgBG_08127738,
	Pal_EkrClasschgBG_08127738,
	Pal_EkrClasschgBG_08127738,
	Pal_EkrClasschgBG_08127738,
	Pal_EkrClasschgBG_08127738,
	Pal_EkrClasschgBG_08127738,
	Pal_EkrClasschgBG_08127738,
	Pal_EkrClasschgBG_08127738,
	Pal_EkrClasschgBG_08127738,
	Pal_EkrClasschgBG_08127738,
	Pal_EkrClasschgBG_08127738,
	Pal_EkrClasschgBG_08127738,
	Pal_EkrClasschgBG_08127738,
	Pal_EkrClasschgBG_08127738,
	Pal_EkrClasschgBG_08127738,
	Pal_EkrClasschgBG_08127758,
	Pal_EkrClasschgBG_08127758,
	Pal_EkrClasschgBG_08127758,
	Pal_EkrClasschgBG_08127758,
	Pal_EkrClasschgBG_08127758,
	Pal_EkrClasschgBG_08127758,
};

void NewEkrClasschgBG1(struct Anim * anim)
{
	static const u16 frame_array[] = {
		7, 2,
		5, 15,
		8, 2,
		5, 15,
		6, 2,
		5, 4,
		7, 2,
		5, 4,
		8, 2,
		5, 4,
		9, 2,
		5, 4,
		10, 2,
		5, 2,
		11, 2,
		5, 2,
		0, 2,
		1, 2,
		2, 2,
		3, 2,
		4, 2,
		5, 20,
		17, 12,
		18, 2,
		19, 2,
		20, 2,
		21, 2,
		22, 66,
		-1
	};

	struct ProcEfxBG *proc;

	proc = SpawnProc(ProcScr_EfxClasschgBG, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->frame = 0;
	proc->frame_config = frame_array;
	proc->tsal = TsaArray_EkrClasschgBG;
	proc->tsar = TsaArray_EkrClasschgBG;
	proc->img = ImgArray_EkrClasschgBG;
	proc->pal = PalArray_EkrClasschgBG;

	SpellFx_SetSomeColorEffect();
}

void NewEkrClasschgBG2(struct Anim * anim)
{
	static const u16 frame_array[] = {
		22, 66,
		21, 2,
		20, 2,
		19, 2,
		18, 2,
		17, 12,
		0, 2,
		1, 2,
		2, 2,
		3, 2,
		4, 2,
		5, 2,
		12, 2,
		13, 2,
		14, 2,
		15, 2,
		16, 2,
		-1
	};

	struct ProcEfxBG *proc;

	proc = SpawnProc(ProcScr_EfxClasschgBG, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->frame = 0;
	proc->frame_config = frame_array;
	proc->tsal = TsaArray_EkrClasschgBG;
	proc->tsar = TsaArray_EkrClasschgBG;
	proc->img = ImgArray_EkrClasschgBG;
	proc->pal = PalArray_EkrClasschgBG;

	SpellFx_SetSomeColorEffect();
}

void EfxClasschgBG_Loop(struct ProcEfxBG *proc)
{
	int ret = EfxAdvanceFrameLut(&proc->timer, (s16 *)&proc->frame, proc->frame_config);

	if (ret >= 0) {
		u16 ** tsal = proc->tsal;
		u16 ** tsar = proc->tsar;
		u16 ** img  = proc->img;
		u16 ** pal  = proc->pal;

		SpellFx_RegisterBgGfx(img[ret], 0x2000);
		SpellFx_RegisterBgPal(pal[ret], 0x20);
		SpellFx_WriteBgMap(proc->anim, tsal[ret], tsar[ret]);
		return;
	}

	if (ret == -1) {
		SpellFx_ClearBG1();
		SpellFx_ClearColorEffects();
		Proc_End(proc);
		return;
	}
}

CONST_DATA struct ProcScr ProcScr_EfxClasschgBGSE00[] = {
	PROC_NAME_DEBUG("efxClasschgBGSE00"),
	PROC_REPEAT(EfxClasschgBGSE00_Loop),
	PROC_END
};

void NewEfxClasschgBGSE00(struct Anim * anim)
{
	struct ProcEfxBG *proc;

	proc = SpawnProc(ProcScr_EfxClasschgBGSE00, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
}

void EfxClasschgBGSE00_Loop(struct ProcEfxBG *proc)
{
	proc->timer++;

	if (0x01 == proc->timer)
		PlaySFX(SONG_13E, 0x100, proc->anim->xPosition, 0x1);
	else if (0x11 == proc->timer)
		PlaySFX(SONG_13E, 0x100, proc->anim->xPosition, 0x1);
	else if (0x22 == proc->timer)
		PlaySFX(SONG_13E, 0x100, proc->anim->xPosition, 0x1);
	else if (0x28 == proc->timer)
		PlaySFX(SONG_13E, 0x100, proc->anim->xPosition, 0x1);
	else if (0x2E == proc->timer)
		PlaySFX(SONG_13E, 0x100, proc->anim->xPosition, 0x1);
	else if (0x34 == proc->timer)
		PlaySFX(SONG_13E, 0x100, proc->anim->xPosition, 0x1);
	else if (0x3A == proc->timer)
		PlaySFX(SONG_13E, 0x100, proc->anim->xPosition, 0x1);
	else if (0x3E == proc->timer)
		PlaySFX(SONG_13E, 0x100, proc->anim->xPosition, 0x1);
	else if (0x42 == proc->timer)
		PlaySFX(SONG_13E, 0x100, proc->anim->xPosition, 0x1);
	else if (0x44 == proc->timer)
		PlaySFX(SONG_13E, 0x100, proc->anim->xPosition, 0x1);
	else if (0x46 == proc->timer)
		PlaySFX(SONG_13E, 0x100, proc->anim->xPosition, 0x1);
	else if (0x48 == proc->timer)
		PlaySFX(SONG_13E, 0x100, proc->anim->xPosition, 0x1);
	else if (0x50 == proc->timer)
		Proc_Break(proc);
}

CONST_DATA struct ProcScr ProcScr_EfxClasschgBGSE01[] = {
	PROC_NAME_DEBUG("efxClasschgBGSE01"),
	PROC_REPEAT(EfxClasschgBGSE01_Loop),
	PROC_END
};

void NewEfxClasschgBGSE01(struct Anim * anim)
{
	struct ProcEfxBG *proc;

	proc = SpawnProc(ProcScr_EfxClasschgBGSE01, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
}

void EfxClasschgBGSE01_Loop(struct ProcEfxBG *proc)
{
	proc->timer++;

	if (0x56 == proc->timer)
		PlaySFX(SONG_13E, 0x100, proc->anim->xPosition, 0x1);
	else if (0x58 == proc->timer)
		PlaySFX(SONG_13E, 0x100, proc->anim->xPosition, 0x1);
	else if (0x5A == proc->timer)
		PlaySFX(SONG_13E, 0x100, proc->anim->xPosition, 0x1);
	else if (0x5C == proc->timer)
		PlaySFX(SONG_13E, 0x100, proc->anim->xPosition, 0x1);
	else if (0x5E == proc->timer)
		PlaySFX(SONG_13E, 0x100, proc->anim->xPosition, 0x1);
	else if (0x60 == proc->timer)
		PlaySFX(SONG_13E, 0x100, proc->anim->xPosition, 0x1);
	else if (0x62 == proc->timer)
		PlaySFX(SONG_13E, 0x100, proc->anim->xPosition, 0x1);
	else if (0x64 == proc->timer)
		PlaySFX(SONG_13E, 0x100, proc->anim->xPosition, 0x1);
	else if (0x66 == proc->timer)
		PlaySFX(SONG_13E, 0x100, proc->anim->xPosition, 0x1);
	else if (0x68 == proc->timer)
		PlaySFX(SONG_13E, 0x100, proc->anim->xPosition, 0x1);
	else if (0x6A == proc->timer)
		PlaySFX(SONG_13E, 0x100, proc->anim->xPosition, 0x1);
	else if (0x6E == proc->timer)
		Proc_Break(proc);
}

struct ProcScr CONST_DATA ProcScr_EfxClasschgOBJ[] = {
	PROC_NAME_DEBUG("EfxClasschgOBJ"),
	PROC_SLEEP(100),
	PROC_REPEAT(EfxClasschgOBJ_Loop),
	PROC_END,
};

void NewEfxClasschgOBJ(struct Anim *anim)
{
	struct ProcEfxOBJ *proc;

	proc = SpawnProc(ProcScr_EfxClasschgOBJ, PROC_TREE_3);
	proc->anim = anim;
	proc->anim2 = EfxCreateFrontAnim(anim, AnimScr_EfxThunderstormOBJ, AnimScr_EfxThunderstormOBJ, AnimScr_EfxThunderstormOBJ, AnimScr_EfxThunderstormOBJ);

	SpellFx_RegisterObjPal(Pal_EfxThunderOBJ, 0x20);
	SpellFx_RegisterObjGfx(Img_EfxThunderOBJ, 0x1000);
}

void EfxClasschgOBJ_Loop(struct ProcEfxOBJ *proc)
{
	BasRemove(proc->anim2);
	Proc_Break(proc);
}

CONST_DATA struct ProcScr ProcScr_EfxClasschgFIN[] = {
	PROC_NAME_DEBUG("efxClasschgFIN"),
	PROC_REPEAT(EfxClasschgFIN_Loop),
	PROC_END
};

void NewEfxClasschgFIN(struct Anim *anim, int duration)
{
	struct ProcEfxBG *proc;

	proc = SpawnProc(ProcScr_EfxClasschgFIN, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->terminator = duration;

	SpellFx_RegisterBgPal(Pal_EfxClasschgFIN, 0x20);
	SpellFx_RegisterBgGfx(Img_EfxClasschgFIN, 0x2000);

	EfxTmCpyBG(Tsa_EfxBerserkBG, gBg1Tm, 0x20, 0x20, 1, 0x100);
	EnableBgSync(BG1_SYNC_BIT);
	SpellFx_SetSomeColorEffect();
	SetBlendConfig(0x1, 0xE, 0x8, 0x0);

	gDispIo.win_ct.wobj_enable_blend = true;
	SetWinEnable(0, 0, 1);
	SetWObjLayers(0, 1, 1, 1, 1);
	SetBlendTargetA(0, 1, 0, 0, 0);
	SetBlendTargetB(0, 0, 1, 1, 1);
	gDispIo.blend_ct.target2_enable_bd = true;

	anim->oam01 |= 0x0800;
	anim->oam2  &= 0xF3FF;
	anim->oam2  |= 0x0400;
}

void EfxClasschgFIN_Loop(struct ProcEfxBG *proc)
{
	struct Anim * anim = proc->anim;

	gDispIo.bg_off[BG_1].y--;
	
	if (++proc->timer == proc->terminator) {
		SpellFx_ClearBG1();
		SpellFx_ClearColorEffects();
		anim->oam01 &= ~0x800;
		anim->oam2  &= 0xF3FF;
		anim->oam2  |= 0x0800;
		Proc_Break(proc);
	}
}

struct ProcScr CONST_DATA ProcScr_EfxClasschgCLONE[] = {
	PROC_NAME_DEBUG("efxClasschgCLONE"),
	PROC_ONEND(EfxClasschgCLONE_End),
	PROC_REPEAT(EfxClasschgCLONE_Loop),
	PROC_END,
};

void NewEfxClasschgCLONE(struct Anim *anim, int duration)
{
	struct ProcEfxBG *proc;

	proc = SpawnProc(ProcScr_EfxClasschgCLONE, PROC_TREE_4);
	proc->anim = anim;
	proc->timer = 0;
	proc->terminator = duration;
}

void EfxClasschgCLONE_Loop(struct ProcEfxBG *proc)
{
	struct Anim _anim;
	struct Anim *anim = proc->anim;

	_anim.xPosition = anim->xPosition;
	_anim.yPosition = anim->yPosition;
	_anim.sprData = anim->sprData;
	_anim.oam01 = anim->oam01 & ~0x0800;
	_anim.oam2 = anim->oam2;
	
	_anim.oam2 &= 0xF3FF;
	_anim.oam2 |= 0x0800;

	BasPutOam(&_anim);

	if (++proc->timer == proc->terminator)
		Proc_Break(proc);
}

void EfxClasschgCLONE_End(struct ProcEfxBG *proc) {}

CONST_DATA struct ProcScr ProcScr_EfxBlackInOutUnit[] = {
	PROC_NAME_DEBUG("efxWhiteInOutUnit"),
	PROC_REPEAT(EfxBlackInOutUnit_Loop),
	PROC_END
};

void NewEfxBlackInOutUnit(struct Anim * anim, int duration, int arg)
{
	struct ProcEfxClasschgInOutUnit *proc;

	proc = SpawnProc(ProcScr_EfxBlackInOutUnit, PROC_TREE_4);
	proc->anim = anim;
	proc->timer = 0;
	proc->terminator = duration;

	if (arg == 0) {
		proc->start = 0;
		proc->end = 0x10;
	} else {
		proc->start = 0x10;
		proc->end = 0;
	}
}

void EfxBlackInOutUnit_Loop(struct ProcEfxClasschgInOutUnit *proc)
{
	int ret = Interpolate(INTERPOLATE_LINEAR, proc->start, proc->end, proc->timer, proc->terminator);

	if (GetAnimPosition(proc->anim) == POS_L) {
		CpuFastCopy(gpEfxUnitPaletteBackup[POS_L], PAL_OBJ(0x7), 0x20);
		EfxPalBlackInOut(PAL_BG(0x0), 0x17, 0x1, ret);
	} else {
		CpuFastCopy(gpEfxUnitPaletteBackup[POS_R], PAL_OBJ(0x9), 0x20);
		EfxPalBlackInOut(PAL_BG(0x0), 0x19, 0x1, ret);
	}

	EnablePalSync();

	if (++proc->timer > proc->terminator)
		Proc_Break(proc);
}

CONST_DATA struct ProcScr ProcScr_EfxClasschgRST[] = {
	PROC_NAME_DEBUG("efxClasschgRST"),
	PROC_REPEAT(EfxClasschgRST_Loop),
	PROC_END
};

void NewEfxClasschgRST(struct Anim *anim, struct ProcEfx *procfx, int duration, int start, int end)
{
	struct ProcEkrClasschgRST *proc;

	gEfxBgSemaphore++;
	proc = SpawnProc(ProcScr_EfxClasschgRST, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->terminator = duration;
	proc->start = start;
	proc->end = end;
	proc->procfx = procfx;
}

void EfxClasschgRST_Loop(struct ProcEkrClasschgRST *proc)
{
	struct ProcEfx *procfx = proc->procfx;
	int ret = Interpolate(INTERPOLATE_RSQUARE, proc->start, proc->end, proc->timer, proc->terminator);

	procfx->frame = ret;

	if (++proc->timer > proc->terminator) {
		gEfxBgSemaphore--;
		Proc_Break(proc);
	}
}
