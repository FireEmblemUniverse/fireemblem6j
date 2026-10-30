#include "prelude.h"
#include "hardware.h"
#include "util.h"
#include "oam.h"
#include "datamove.h"
#include "banim.h"
#include "banim_ekrdragon.h"
#include "constants/songs.h"
#include "constants/videoalloc.h"

EWRAM_OVERLAY(banim) int gEkrBg2ScrollFlip = 0;
EWRAM_OVERLAY(banim) u16 *gpBg2ScrollOffsetStart = NULL;
EWRAM_OVERLAY(banim) u16 *gpBg2ScrollOffset = NULL;
EWRAM_OVERLAY(banim) u16 gpBg2ScrollOffsetTable1[0xA0] = {};
EWRAM_OVERLAY(banim) u16 gpBg2ScrollOffsetTable2[0xA0] = {};
EWRAM_OVERLAY(banim) int gEkrBg1ScrollFlip = 0;
EWRAM_OVERLAY(banim) u16 *gpBg1ScrollOffsetStart = NULL;
EWRAM_OVERLAY(banim) u16 *gpBg1ScrollOffset = NULL;
EWRAM_OVERLAY(banim) u16 gpBg1ScrollOffsetList1[0xA0] = {};
EWRAM_OVERLAY(banim) u16 gpBg1ScrollOffsetList2[0xA0] = {};
EWRAM_OVERLAY(banim) u16 gpBg1ScrollOffsetList3_unused[0xA0] = {};
EWRAM_OVERLAY(banim) int gEfxMagicChk_N = 0;
EWRAM_OVERLAY(banim) int gEfxPurgeCounter = 0;

void StartSpellAnimation(struct Anim *anim)
{
	i16 index = gEkrSpellAnimIndex[GetAnimPosition(anim)];
	SpellAnimFunc func = gEkrSpellAnimLut[index];

#if BUGFIX
	if (func != NULL)
#else
	if (1)
#endif
	{
		gEfxMagicChk_N = false;
		func(anim);
	}
}

void func_fe6_0804C8D0(void)
{
	return;
}

struct ProcScr CONST_DATA ProcScr_EfxRestRST[] =
{
	PROC_NAME_DEBUG("efxRestRST"),
	PROC_ONEND(EfxRestRST_End),
	PROC_REPEAT(EfxRestRST_Loop),
	PROC_END,
};

ProcPtr NewEfxRestRST(struct Anim *anim, int duration, int step, int frame, int speed)
{
	struct ProcEfx *proc;

	gEfxBgSemaphore++;
	proc = SpawnProc(ProcScr_EfxRestRST, PROC_TREE_3);

	proc->anim = anim;
	proc->timer = 0,
	proc->step = 0;
	proc->unk44 = duration;
	proc->unk48 = step;
	proc->frame = frame;
	proc->speed = speed;

	return proc;
}

void EfxRestRST_End(struct ProcEfx *proc)
{
	gEfxBgSemaphore--;
}

void EfxRestRST_Loop(struct ProcEfx *proc)
{
	u8 val1;
	u32 i;
	u16 *buf;

	if (gEkrBg1ScrollFlip == 0)
		buf = gpBg1ScrollOffsetList2;
	else
		buf = gpBg1ScrollOffsetList1;

	val1 = proc->step;
	proc->step += proc->speed;

	for (i = 0; i < 0x78; buf++, i++) {
		val1 += proc->unk48;
		*buf = (((PosArray_EfxApocalypseBGCtrl[val1] *proc->frame) << 8) >> 0x10) + gDispIo.bg_off[BG_1].x;
	}

	if (++proc->timer == proc->unk44)
		Proc_End(proc);
}

struct ProcScr CONST_DATA ProcScr_EfxDummyRST[] =
{
	PROC_NAME_DEBUG("efxDummyRST"),
	PROC_ONEND(EfxDummyRST_End),
	PROC_REPEAT(EfxDummyRST_Loop),
	PROC_END,
};

void NewDummvRST(struct Anim *anim, int unk44)
{
	struct ProcEfx *proc;

	gEfxBgSemaphore++;
	proc = SpawnProc(ProcScr_EfxDummyRST, PROC_TREE_3);

	proc->anim = anim;
	proc->timer = 0;
	proc->step = 0;
	proc->unk44 = unk44;
}

void EfxDummyRST_End(struct ProcEfx *proc)
{
	gEfxBgSemaphore--;
}

void EfxDummyRST_Loop(struct ProcEfx *proc)
{
	u32 i;
	u16 * buf;

	if (gEkrBg1ScrollFlip == 0)
		buf = gpBg1ScrollOffsetList2;
	else
		buf = gpBg1ScrollOffsetList1;

	for (i = 0; i < 0x78; i++)
		buf[i] = gDispIo.bg_off[1].x;

	if (++proc->timer == proc->unk44)
		Proc_End(proc);
}

struct ProcScr CONST_DATA ProcScr_EfxRestWIN[] =
{
	PROC_NAME_DEBUG("efxRestWIN"),
	PROC_REPEAT(EfxRestWIN_Loop),
	PROC_END
};

void NewEfxRestWIN(struct Anim *anim, int duration, void *frame_conf, void *bufs)
{
	struct ProcEfxRstWIN *proc;

	gEfxBgSemaphore++;
	proc = SpawnProc(ProcScr_EfxRestWIN, PROC_TREE_3);

	proc->anim = anim;
	proc->timer = 0;
	proc->step = 0;
	proc->duration = duration;
	proc->frame_conf = frame_conf;
	proc->bufs = bufs;

	if (GetAnimPosition(GetAnimAnotherSide(anim)) == POS_L)
		proc->diff_per_step = -0x48;
	else
		proc->diff_per_step = -8;

	if (gEkrDistanceType != EKR_DISTANCE_CLOSE) {
		if (GetAnimPosition(anim) == POS_L)
			proc->diff_per_step += 0x18;
		else
			proc->diff_per_step -= 0x18;
	}
}

void EfxRestWIN_Loop(struct ProcEfxRstWIN *proc)
{
	u32 i;
	u16 val2;
	u16 * buf;
	i16 * buf2, * base;

	if (gEkrBg2ScrollFlip == 0)
		buf = gpBg2ScrollOffsetTable2;
	else
		buf = gpBg2ScrollOffsetTable1;

	base = proc->frame_conf;
	val2 = base[proc->step];
	buf2 = proc->bufs[val2];

	if (val2 != 0xFFFF) {
		proc->step++;
		for (i = 0; i < 0x78; buf2 = buf2 + 2, buf++, i++) {
			if (buf2[0] == 0x7FFF)
				buf[0] = 0;
			else {
				i16 tmp3 = buf2[0] + proc->diff_per_step;
				i16 tmp4 = buf2[1] + proc->diff_per_step;

				buf[0] = (tmp3 * 0x100) | tmp4;
			}
		}
	} else {
		for (i = 0; i < 0x78; i++)
			*buf++ = 0;
	}

	proc->timer++;
	if (proc->timer == proc->duration) {
		gEfxBgSemaphore--;
		Proc_Break(proc);
	}
}

struct ProcScr CONST_DATA ProcScr_EfxRestWINH[] =
{
	PROC_NAME_DEBUG("efxRestWINH"),
	PROC_REPEAT(EfxRestWINH_Dummy),
	PROC_REPEAT(EfxRestWINH_Loop),
	PROC_END,
};

void NewEfxRestWINH(struct Anim *anim, int a, i16 b, void (* hblank)(void))
{
	u32 i;
	u16 * buf;
	struct ProcEfx *proc;

	gEfxBgSemaphore++;

	buf = gpBg2ScrollOffsetTable1;
	for (i = 0; i < 0xA0; buf++, i++)
		*buf = b;

	buf = gpBg2ScrollOffsetTable2;
	for (i = 0; i < 0xA0; buf++, i++)
		*buf = b;

	buf = gpBg1ScrollOffsetList1;
	for (i = 0; i < 0xA0; buf++, i++)
		*buf = b;

	buf = gpBg1ScrollOffsetList2;
	for (i = 0; i < 0xA0; buf++, i++)
		*buf = b;

	gEkrBg2ScrollFlip = 0;
	gEkrBg1ScrollFlip = 0;

	gpBg2ScrollOffsetStart = gpBg2ScrollOffsetTable1;
	gpBg1ScrollOffsetStart = gpBg1ScrollOffsetList1;
	gpBg2ScrollOffset = gpBg2ScrollOffsetTable1;
	gpBg1ScrollOffset = gpBg1ScrollOffsetList1;

	SetOnHBlankA(hblank);
	gEfxMagicChk_N = true;
	proc = SpawnProc(ProcScr_EfxRestWINH, PROC_TREE_VSYNC);
	proc->anim = anim;
	proc->timer = 0;
	proc->unk44 = a;
}

void NewEfxRestWINH_(struct Anim *anim, int a, void (* hblank)(void))
{
	NewEfxRestWINH(anim, a, 0, hblank);
}

void EfxRestWINH_Dummy(struct ProcEfx *proc)
{
	Proc_Break(proc);
}

void EfxRestWINH_Loop(struct ProcEfx *proc)
{
	if (gBmSt.main_loop_ended != false) {
		if (gEkrBg2ScrollFlip == 1) {
			gEkrBg2ScrollFlip = 0;
			gpBg2ScrollOffsetStart = gpBg2ScrollOffsetTable1;
		} else {
			gEkrBg2ScrollFlip = 1;
			gpBg2ScrollOffsetStart = gpBg2ScrollOffsetTable2;
		}

		if (gEkrBg1ScrollFlip == 1) {
			gEkrBg1ScrollFlip = 0;
			gpBg1ScrollOffsetStart = gpBg1ScrollOffsetList1;
		} else {
			gEkrBg1ScrollFlip = 1;
			gpBg1ScrollOffsetStart = gpBg1ScrollOffsetList2;
		}

		gpBg2ScrollOffset = gpBg2ScrollOffsetStart;
		gpBg1ScrollOffset = gpBg1ScrollOffsetStart;
	}

	if (++proc->timer == proc->unk44)
	{
		gEfxBgSemaphore--;
		SetOnHBlankA(NULL);
		gEfxMagicChk_N = false;
		Proc_Break(proc);
	}
}

void EfxRestWINH_DefaultHblank(void)
{
	if (!(REG_DISPSTAT & DISPSTAT_VBLANK)) {
		REG_WIN0H   = *gpBg2ScrollOffset++; // ?
		REG_BG1HOFS = *gpBg1ScrollOffset++;
	}
}

struct ProcScr CONST_DATA ProcScr_EfxALPHA[] =
{
	PROC_NAME_DEBUG("efxALPHA"),
	PROC_REPEAT(EfxALPHA_Loop),
	PROC_END,
};

void NewEfxALPHA(struct Anim *anim, int delay, int duration2, int lo, int hi, int type)
{
	struct ProcEfxALPHA *proc;

	gEfxBgSemaphore++;

	proc = SpawnProc(ProcScr_EfxALPHA, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->delay = delay;
	proc->duration_total = delay + duration2;
	proc->lo = lo;
	proc->hi = hi;
	proc->type = type;
}

void EfxALPHA_Loop(struct ProcEfxALPHA *proc)
{
	int bldA, bldB;

	proc->timer++;
	if (proc->timer < proc->delay)
		return;

	bldA = Interpolate(
		INTERPOLATE_LINEAR,
		proc->lo,
		proc->hi,
		proc->timer - proc->delay,
		proc->duration_total - proc->delay);

	switch (proc->type) {
	case 0:
		SetBlendAlpha(bldA, 16);
		break;

	case 1:
		SetBlendBrighten(bldA);
		break;

	case 2:
		bldB = Interpolate(
			INTERPOLATE_LINEAR,
			8, 16,
			proc->timer - proc->delay,
			proc->duration_total - proc->delay);

		SetBlendAlpha(bldA, bldB);
		break;
	}

	if (proc->timer >= proc->duration_total) {
		gEfxBgSemaphore--;
		Proc_Break(proc);
	}
}

struct ProcScr CONST_DATA ProcScr_EfxCircleWIN[] =
{
	PROC_NAME_DEBUG("efxCircleWIN"),
	PROC_REPEAT(EfxCircleWIN_Loop),
	PROC_END,
};

void NewEfxCircleWIN(struct Anim *anim, int terminator, u16 * c, u16 d, u16 e)
{
	struct ProcEfxCircleWIN *proc;

	gEfxBgSemaphore++;

	proc = SpawnProc(ProcScr_EfxCircleWIN, PROC_TREE_3);

	proc->anim = anim;

	proc->timer = 0;
	proc->unk_2e = 0;

	proc->unk_44 = terminator;
	proc->unk_54 = c;

	GetAnimAnotherSide(anim);

	proc->unk_32 = d;
	proc->unk_3a = e;

	return;
}

void EfxCircleWIN_Loop(struct ProcEfxCircleWIN *proc)
{
	u16 * unk_54;
	struct Vec2i * vec;
	i16 a, b;
	i16 x, y;
	u16 var;
	u32 i;

	u16 * buf = (gEkrBg2ScrollFlip == 0)
			  ? gpBg2ScrollOffsetTable2
			  : gpBg2ScrollOffsetTable1;

	unk_54 = proc->unk_54;
	var = unk_54[proc->unk_2e];

	vec = func_fe6_08013F7C(var);

	if (unk_54[proc->unk_2e + 1] != 0xFFFF)
		proc->unk_2e++;

	a = proc->unk_3a - var;
	if (a < 0)
		a = 0;

	b = var + proc->unk_3a;
	if (b > DISPLAY_HEIGHT)
		b = DISPLAY_HEIGHT;

	for (i = 0; i < DISPLAY_HEIGHT; buf++, i++) {
		if ((a > i) || (b < i)) {
			*buf = 0;
			continue;
		}

		x = vec->x + proc->unk_32;
		if (x < 0)
			x = 0;

		y = vec->y + proc->unk_32;
		if (y > DISPLAY_WIDTH)
			y = DISPLAY_WIDTH;

		*buf = y | (x << 8);
		vec++;
	}

	proc->timer++;

	if (proc->timer == proc->unk_44) {
		gEfxBgSemaphore--;
		SetBlendNone();
		Proc_Break(proc);
	}
}

struct ProcScr CONST_DATA ProcScr_EfxMagicQUAKE[] =
{
	PROC_NAME_DEBUG("efxMagicQUAKE"),
	PROC_REPEAT(EfxMagicQUAKE_Loop),
	PROC_END,
};

void NewEfxMagicQUAKE(struct Anim *anim, int duration)
{
	struct ProcEfxMagicQuake *proc;

	gEfxBgSemaphore++;

	proc = SpawnProc(ProcScr_EfxMagicQUAKE, PROC_TREE_3);
	proc->anim = anim;
	proc->qproc = NewEfxQuakePure(6, 0);
	proc->timer = 0;
	proc->duration = duration;
}

void EfxMagicQUAKE_Loop(struct ProcEfxMagicQuake *proc)
{
	i16 x1, y1, x2, y2;

	SetBgOffset(BG_2, gEkrBg2QuakeVec.x, gEkrBg2QuakeVec.y);
	SetBgOffset(BG_0, gEkrBg2QuakeVec.x + gEkrBg0QuakeVec.x, gEkrBg2QuakeVec.y + gEkrBg0QuakeVec.y);

	EkrGauge_Setxy323A(-(gEkrBg2QuakeVec.x + gEkrBg0QuakeVec.x), -(gEkrBg2QuakeVec.y + gEkrBg0QuakeVec.y));
	EkrDispUP_SetPositionSync(-(gEkrBg2QuakeVec.x + gEkrBg0QuakeVec.x), -(gEkrBg2QuakeVec.y + gEkrBg0QuakeVec.y));

	if (GetEkrDragonStateType() != 0)
		SetBgOffset(BG_3, gEkrBg2QuakeVec.x, gEkrBg2QuakeVec.y + 0x10);

	if (GetEkrDragonStateType() != 0) {
		x1 = (gEkrXPosReal[0] - gEkrBg2QuakeVec.x) - gEkrBgPosition;
		y1 = (gEkrYPosReal[0] - gEkrBg2QuakeVec.y);
	} else {
		x1 = (gEkrXPosReal[0] + gEkrBg2QuakeVec.x) - gEkrBgPosition;
		y1 = (gEkrYPosReal[0] - gEkrBg2QuakeVec.y);
	}

	x2 = ((gEkrXPosReal[1] + gEkrBg2QuakeVec.x) - gEkrBgPosition);
	y2 = (gEkrYPosReal[1] - gEkrBg2QuakeVec.y);

	SetEkrFrontAnimPostion(POS_L, x1, y1);
	SetEkrFrontAnimPostion(POS_R, x2, y2);

	proc->timer++;
	if (proc->timer > proc->duration) {
		gEfxBgSemaphore--;

		SetBgOffset(BG_2, 0, 0);
		SetBgOffset(BG_0, gEkrBg0QuakeVec.x, gEkrBg0QuakeVec.y);

		EkrGauge_Setxy323A(-gEkrBg0QuakeVec.x, -gEkrBg0QuakeVec.y);
		EkrDispUP_SetPositionSync(-gEkrBg0QuakeVec.x, -gEkrBg0QuakeVec.y);

		if (GetEkrDragonStateType() != 0)
			SetBgOffset(BG_3, 0, 0x10);

		x1 = (gEkrXPosReal[0] - gEkrBgPosition);
		y1 = gEkrYPosReal[0];

		x2 = (gEkrXPosReal[1] - gEkrBgPosition);
		y2 = gEkrYPosReal[1];

		SetEkrFrontAnimPostion(0, x1, y1);
		SetEkrFrontAnimPostion(1, x2, y2);

		Proc_End(proc->qproc);
		Proc_Break(proc);
	}
}

struct ProcScr CONST_DATA ProcScr_EfxDummyMagic[] =
{
	PROC_NAME_DEBUG("efxDummymagic"),
	PROC_REPEAT(EfxDummyMagic_Loop),
	PROC_END,
};

void NewEfxDummyMagic(struct Anim *anim)
{
	struct ProcEfx *proc;

	SpellFx_Begin();
	SpellFx_ClearBG1Position();

	proc = SpawnProc(ProcScr_EfxDummyMagic, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
}

void EfxDummyMagic_Loop(struct ProcEfxMagic *proc)
{
	struct Anim *anim_other = GetAnimAnotherSide(proc->anim);
	int time = ++proc->timer;

	if (time == 1) {
		anim_other->flags3 |= ANIM_BIT3_C02_BLOCK_END | ANIM_BIT3_C01_BLOCK_END_INBATTLE;
		return;
	}

	if (time == 10) {
		if (GetAnimNextRoundType(anim_other) != ANIM_ROUND_INVALID)
			anim_other->flags3 |= ANIM_BIT3_NEXT_ROUND_START;

		SpellFx_Finish();
		Proc_Break(proc);
		return;
	}
}

/* HandAxe */
struct ProcScr CONST_DATA ProcScr_EfxTeono[] =
{
	PROC_NAME_DEBUG("efxTeono"),
	PROC_REPEAT(EfxTeono_Loop),
	PROC_END,
};

void NewEfxTeono(struct Anim *anim)
{
	struct ProcEfxMagic *proc;

	SpellFx_Begin();
	SpellFx_ClearBG1Position();

	proc = SpawnProc(ProcScr_EfxTeono, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->hitted = CheckRoundMiss(GetAnimRoundTypeAnotherSide(anim));
}

void EfxTeono_Loop(struct ProcEfxMagic *proc)
{
	struct Anim *animc = GetAnimAnotherSide(proc->anim);

	if (++proc->timer == 1) {
		NewEfxFarAttackWithDistance(proc->anim, -1);
		NewEfxTeonoOBJ(proc->anim);

		if (proc->timer == 1) {
			animc->flags3 |= ANIM_BIT3_C02_BLOCK_END | ANIM_BIT3_C01_BLOCK_END_INBATTLE;
			StartBattleAnimHitEffectsDefault(animc, proc->hitted);

			if (GetEfxHpChangeType(animc) != EFX_HPT_NOT_CHANGE) {
				if (CheckRoundCrit(proc->anim) == true)
					NewEfxCriricalEffect(animc);
				else if (proc->hitted != false)
					return;
				else
					NewEfxNormalEffect(proc->anim);
			}

			if (proc->hitted == false)
				EfxPlayHittedSFX(animc);

			return;
		}
	}

	if (proc->timer == 0x46)
		return;

	if (proc->timer == 0x50) {
		SpellFx_Finish();
		Proc_Break(proc);
		return;
	}
}

struct ProcScr CONST_DATA ProcScr_EfxTeonoOBJ[] =
{
	PROC_NAME_DEBUG("efxTeonoOBJ"),
	PROC_REPEAT(EfxTeonoObj_Loop),
	PROC_REPEAT(EfxTeonoObj_End),
	PROC_END,
};

void NewEfxTeonoOBJ(struct Anim *anim)
{
	struct Anim *anim2;
	struct ProcEfxMagicOBJ *proc;

	gEfxBgSemaphore++;
	proc = SpawnProc(ProcScr_EfxTeonoOBJ, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	anim2 = EfxCreateFrontAnim(anim, AnimScr_TeonoObjCloseLeft, AnimScr_TeonoObjCloseRight, AnimScr_TeonoObjFarLeft, AnimScr_TeonoObjFarRight);
	proc->anim2 = anim2;

	if (GetAnimPosition(anim) == POS_L)
		anim2->xPosition += 0x48;
	else
		anim2->xPosition -= 0x48;

	if (gEkrDistanceType == EKR_DISTANCE_CLOSE)
		proc->terminator = 35;
	else
		proc->terminator = 10;

	proc->seproc = NewEfxTeonoSE(proc->anim, proc->anim2);

	SpellFx_RegisterObjPal(Pal_TeonoOBJ, 0x20);
	SpellFx_RegisterObjGfx(Img_TeonoOBJ, 0x1000);
}

void EfxTeonoObj_Loop(struct ProcEfxMagicOBJ *proc)
{
	if (++proc->timer == proc->terminator) {
		gEfxBgSemaphore--;
		BasRemove(proc->anim2);

		if (gEkrDistanceType == EKR_DISTANCE_CLOSE) {
			gEfxTeonoState = 1;
			Proc_End(proc->seproc);
			Proc_End(proc);
		} else
			Proc_Break(proc);
	}
}

void EfxTeonoObj_End(struct ProcEfxMagicOBJ *proc)
{
	gUnk_Banim_0201774C = 0;
	Proc_End(proc->seproc);
	NewEfxTeonoOBJ2(proc->anim);
	Proc_Break(proc);
}

struct ProcScr CONST_DATA ProcScr_EfxTeonoOBJ2[] =
{
	PROC_NAME_DEBUG("efxTeonoOBJ2"),
	PROC_REPEAT(EfxTeonoOBJ2_Loop),
	PROC_END
};

void NewEfxTeonoOBJ2(struct Anim *anim)
{
	struct Anim *anim2;
	struct ProcEfxMagicOBJ *proc;

	gEfxBgSemaphore++;
	proc = SpawnProc(ProcScr_EfxTeonoOBJ2, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	anim2 = EfxCreateFrontAnim(anim, AnimScr_TeonoObj2Left, AnimScr_TeonoObj2Right, AnimScr_TeonoObj2Left, AnimScr_TeonoObj2Right);
	proc->anim2 = anim2;

	if (GetAnimPosition(anim) == POS_L)
		anim2->xPosition += 0x48;
	else
		anim2->xPosition -= 0x48;

	SpellFx_RegisterObjPal(Pal_TeonoOBJ, 0x20);
	SpellFx_RegisterObjGfx(Img_TeonoOBJ, 0x1000);
	proc->seproc = NewEfxTeonoSE(proc->anim, proc->anim2);
}

void EfxTeonoOBJ2_Loop(struct ProcEfxMagicOBJ *proc)
{
	if (++proc->timer == 17) {
		gEfxBgSemaphore--;
		gEfxTeonoState = 1;
		Proc_End(proc->seproc);
		BasRemove(proc->anim2);
		Proc_Break(proc);
	}
}

struct ProcScr CONST_DATA ProcScr_EfxTeonoSE[] =
{
	PROC_NAME_DEBUG("efxTeonoSE"),
	PROC_ONEND(EfxTeonoSE_End),
	PROC_REPEAT(EfxTeonoSE_Loop),
	PROC_END,
};

ProcPtr NewEfxTeonoSE(struct Anim *anim, struct Anim *anim2)
{
	struct ProcEfxMagicOBJ *proc;

	gEfxBgSemaphore++;
	proc = SpawnProc(ProcScr_EfxTeonoSE, PROC_TREE_3);
	proc->anim = anim;
	proc->anim2 = anim2;
	proc->timer = 0;
	proc->terminator = 1;
	PlaySFX(SONG_CD, 0x100, anim->xPosition, 1);
	return proc;
}

void EfxTeonoSE_End(struct ProcEfxMagicOBJ *proc)
{
	gEfxBgSemaphore--;
}

void EfxTeonoSE_Loop(struct ProcEfxMagicOBJ *proc)
{
	if (++proc->timer == 0x8) {
		int sound_pos;

		sound_pos = (u16)proc->anim2->xPosition + GetProperAnimSoundLocation(proc->anim2);
		PlaySFX(SONG_CD, 0x100, (i16)sound_pos, 1);
		proc->timer = 0;
		if (proc->terminator <= 8)
			proc->terminator++;
	}
}

/* Arrow */
struct ProcScr CONST_DATA ProcScr_EfxArrow[] =
{
	PROC_NAME_DEBUG("efxArrowOBJ"),
	PROC_REPEAT(EfxArrow_Loop),
	PROC_END,
};

void NewEfxArrow(struct Anim *anim)
{
	struct ProcEfx *proc;

	SpellFx_Begin();
	SpellFx_ClearBG1Position();

	proc = SpawnProc(ProcScr_EfxArrow, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->hitted = CheckRoundMiss(GetAnimRoundTypeAnotherSide(anim));
}

void EfxArrow_Loop(struct ProcEfx *proc)
{
	struct Anim *animc = GetAnimAnotherSide(proc->anim);
	int frame = EfxGetCamMovDuration();

	if (++proc->timer == 1) {
		NewEfxFarAttackWithDistance(proc->anim, -1);
		NewEfxArrowOBJ(proc->anim);
		PlaySFX(SONG_CC, 0x100, proc->anim->xPosition, 1);

		if (proc->timer == 1) {
			animc->flags3 |= ANIM_BIT3_C02_BLOCK_END | ANIM_BIT3_C01_BLOCK_END_INBATTLE;
			StartBattleAnimHitEffectsDefault(animc, proc->hitted);

			if (GetEfxHpChangeType(animc) != EFX_HPT_NOT_CHANGE) {
				if (CheckRoundCrit(proc->anim) == true)
					NewEfxCriricalEffect(animc);
				else if (proc->hitted != false)
					return;
				else
					NewEfxNormalEffect(proc->anim);
			}
			if (proc->hitted == false)
				EfxPlayHittedSFX(animc);

			return;
		}
	}

	if (proc->timer == (frame + 9)) {
#if !BUGFIX
		GetAnimAnotherSide(proc->anim);
#endif
		return;
	}

	if (proc->timer == (frame + 10)) {
		SpellFx_Finish();
		Proc_Break(proc);
		return;
	}
}

struct ProcScr CONST_DATA ProcScr_EfxArrowOBJ[] = {
	PROC_NAME_DEBUG("efxArrowOBJ"),
	PROC_REPEAT(EfxArrowObj_Loop),
	PROC_END
};

void NewEfxArrowOBJ(struct Anim *anim)
{
	struct ProcEfxMagicOBJ *proc;

	gEfxBgSemaphore++;
	proc = SpawnProc(ProcScr_EfxArrowOBJ, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->anim2 = EfxCreateFrontAnim(anim, AnimScr_ArrowCloseLeft, AnimScr_ArrowCloseRight, AnimScr_ArrowFarLeft, AnimScr_ArrowFarRight);

	SpellFx_RegisterObjPal(Pal_TeonoOBJ, 0x20);
	SpellFx_RegisterObjGfx(Img_EfxArrowOBJ, 0x60);
}

void EfxArrowObj_Loop(struct ProcEfxMagicOBJ *proc)
{
	if (++proc->timer == 4)
	{
		gEfxBgSemaphore--;
		BasRemove(proc->anim2);
		Proc_Break(proc);
	}
}

struct ProcScr CONST_DATA ProcScr_EfxTeyari[] = {
	PROC_NAME_DEBUG("efxTeyariOBJ"),
	PROC_REPEAT(EfxTeyari_Loop),
	PROC_END,
};

void StartSpellAnimJavelin(struct Anim *anim)
{
	struct ProcEfx *proc;

	SpellFx_Begin();
	SpellFx_ClearBG1Position();

	proc = SpawnProc(ProcScr_EfxTeyari, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->hitted = CheckRoundMiss(GetAnimRoundTypeAnotherSide(anim));

	NewEfxTeyariOBJ(anim, 0);
	SpellFx_RegisterObjPal(Pal_SpellJavelin, 0x20);
	SpellFx_RegisterObjGfx(Img_SpellJavelin, 0x1000);
}

void StartSpellAnimJavelinCavalier(struct Anim *anim)
{
	struct ProcEfx *proc;

	SpellFx_Begin();
	SpellFx_ClearBG1Position();

	proc = SpawnProc(ProcScr_EfxTeyari, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->hitted = CheckRoundMiss(GetAnimRoundTypeAnotherSide(anim));

	NewEfxTeyariOBJ(anim, 1);
	SpellFx_RegisterObjPal(Pal_SpellJavelinCavalier, 0x20);
	SpellFx_RegisterObjGfx(Img_SpellJavelinCavalier, 0x1000);
}

void StartSpellAnimJavelinSoldier(struct Anim *anim)
{
	struct ProcEfx *proc;

	SpellFx_Begin();
	SpellFx_ClearBG1Position();

	proc = SpawnProc(ProcScr_EfxTeyari, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->hitted = CheckRoundMiss(GetAnimRoundTypeAnotherSide(anim));

	NewEfxTeyariOBJ(anim, 0);
	SpellFx_RegisterObjPal(Pal_SpellJavelinSoldier, 0x20);
	SpellFx_RegisterObjGfx(Img_SpellJavelinSoldier, 0x1000);
}

void StartSpellAnimJavelinPaladin(struct Anim *anim)
{
	struct ProcEfx *proc;

	SpellFx_Begin();
	SpellFx_ClearBG1Position();

	proc = SpawnProc(ProcScr_EfxTeyari, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->hitted = CheckRoundMiss(GetAnimRoundTypeAnotherSide(anim));

	NewEfxTeyariOBJ(anim, 1);
	SpellFx_RegisterObjPal(Pal_SpellJavelinPaladin, 0x20);
	SpellFx_RegisterObjGfx(Img_SpellJavelinPaladin, 0x1000);
}

void StartSpellAnimJavelinPrgasusKnight(struct Anim *anim)
{
	struct ProcEfx *proc;

	SpellFx_Begin();
	SpellFx_ClearBG1Position();

	proc = SpawnProc(ProcScr_EfxTeyari, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->hitted = CheckRoundMiss(GetAnimRoundTypeAnotherSide(anim));

	NewEfxTeyariOBJ(anim, 1);
	SpellFx_RegisterObjPal(Pal_SpellJavelinPrgasusKnight, 0x20);
	SpellFx_RegisterObjGfx(Img_SpellJavelinPrgasusKnight, 0x1000);
}

void StartSpellAnimJavelinFalcon(struct Anim *anim)
{
	struct ProcEfx *proc;

	SpellFx_Begin();
	SpellFx_ClearBG1Position();

	proc = SpawnProc(ProcScr_EfxTeyari, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->hitted = CheckRoundMiss(GetAnimRoundTypeAnotherSide(anim));

	NewEfxTeyariOBJ(anim, 1);
	SpellFx_RegisterObjPal(Pal_SpellJavelinFalcon, 0x20);
	SpellFx_RegisterObjGfx(Img_SpellJavelinFalcon, 0x1000);
}

void StartSpellAnimJavelinWyvernRider(struct Anim *anim)
{
	struct ProcEfx *proc;

	SpellFx_Begin();
	SpellFx_ClearBG1Position();

	proc = SpawnProc(ProcScr_EfxTeyari, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->hitted = CheckRoundMiss(GetAnimRoundTypeAnotherSide(anim));

	NewEfxTeyariOBJ(anim, 1);
	SpellFx_RegisterObjPal(Pal_SpellJavelinWyvernRider, 0x20);
	SpellFx_RegisterObjGfx(Img_SpellJavelinWyvernRider, 0x1000);
}

void StartSpellAnimJavelinWyvernLord(struct Anim *anim)
{
	struct ProcEfx *proc;

	SpellFx_Begin();
	SpellFx_ClearBG1Position();

	proc = SpawnProc(ProcScr_EfxTeyari, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->hitted = CheckRoundMiss(GetAnimRoundTypeAnotherSide(anim));

	NewEfxTeyariOBJ(anim, 1);
	SpellFx_RegisterObjPal(Pal_SpellJavelinWyvernLord, 0x20);
	SpellFx_RegisterObjGfx(Img_SpellJavelinWyvernLord, 0x1000);
}

void StartSpellAnimJavelinGenerial(struct Anim *anim)
{
	struct ProcEfx *proc;

	SpellFx_Begin();
	SpellFx_ClearBG1Position();

	proc = SpawnProc(ProcScr_EfxTeyari, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->hitted = CheckRoundMiss(GetAnimRoundTypeAnotherSide(anim));

	NewEfxTeyariOBJ(anim, 1);
	SpellFx_RegisterObjPal(Pal_SpellJavelinGenerial, 0x20);
	SpellFx_RegisterObjGfx(Img_SpellJavelinGenerial, 0x1000);
}

void EfxTeyari_Loop(struct ProcEfx *proc)
{
	if (++proc->timer == 1) {
		NewEfxFarAttackWithDistance(proc->anim, -1);
		PlaySFX(SONG_CA, 0x100, proc->anim->xPosition, 1);

		if (proc->timer == 1) {
			struct Anim *animc = GetAnimAnotherSide(proc->anim);

			animc->flags3 |= ANIM_BIT3_C02_BLOCK_END | ANIM_BIT3_C01_BLOCK_END_INBATTLE;
			StartBattleAnimHitEffectsDefault(animc, proc->hitted);

			if (GetEfxHpChangeType(animc) != EFX_HPT_NOT_CHANGE) {
				if (CheckRoundCrit(proc->anim) == true)
					NewEfxCriricalEffect(animc);
				else if (proc->hitted != false)
					return;
				else
					NewEfxNormalEffect(proc->anim);
			}

			if (proc->hitted == false)
				EfxPlayHittedSFX(animc);

			return;
		}
	}

	if (proc->timer == 0xE) {
#if !BUGFIX
		GetAnimAnotherSide(proc->anim);
#endif
		return;
	}

	if (proc->timer == 0x10) {
		SpellFx_Finish();
		Proc_Break(proc);
		return;
	}
}

struct ProcScr CONST_DATA ProcScr_EfxTeyariOBJ[] =
{
	PROC_NAME_DEBUG("efxTeyariOBJ"),
	PROC_REPEAT(EfxTeyariObj_Loop),
	PROC_END,
};

void NewEfxTeyariOBJ(struct Anim *anim, int type)
{
	struct Anim *anim2;
	struct ProcEfxMagicOBJ *proc;
	u32 *scr1, *scr2;

	gEfxBgSemaphore++;
	proc = SpawnProc(ProcScr_EfxTeyariOBJ, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;

	if (type == 0) {
		scr2 = AnimScr_EfxTeyariObjType0Right;
		scr1 = AnimScr_EfxTeyariObjType0Left;
	} else {
		scr2 = AnimScr_EfxTeyariObjType1Right;
		scr1 = AnimScr_EfxTeyariObjType1Left;
	}

	anim2 = EfxCreateFrontAnim(anim, scr1, scr2, scr1, scr2);
	proc->anim2 = anim2;

	if (GetAnimPosition(anim) == POS_L)
		anim2->xPosition += 0x38;
	else
		anim2->xPosition -= 0x38;
}

void EfxTeyariObj_Loop(struct ProcEfxMagicOBJ *proc)
{
	if (++proc->timer == 0xC) {
		gEfxBgSemaphore--;
		BasRemove(proc->anim2);
		Proc_Break(proc);
	}
}

/**
 * Efx song
 */
struct ProcScr CONST_DATA ProcScr_EfxSong[] =
{
	PROC_NAME_DEBUG("efxSong"),
	PROC_REPEAT(EfxSong_Loop),
	PROC_END,
};

void StartSpellAnimSong(struct Anim *anim)
{
	struct ProcEfx *proc;

	SpellFx_Begin();
	SpellFx_ClearBG1Position();

	proc = SpawnProc(ProcScr_EfxSong, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->hitted = CheckRoundMiss(GetAnimRoundTypeAnotherSide(anim));
}

void EfxSong_Loop(struct ProcEfx *proc)
{
	struct Anim *anim = GetAnimAnotherSide(proc->anim);

	proc->timer++;

	if (proc->timer == 39) {
		NewEfxSongBG(anim);
		NewEfxSongBGCOL(anim);

#if FE8U
		NewEfxRestWINH_(anim, 130, 1);
		NewEfxTwobaiRST(anim, 100);
		SetBlendAlpha(0, 16);
		NewEfxALPHA(anim, 0, 8, 0, 16, 0);
		NewEfxALPHA(anim, 60, 40, 16, 0, 0);
#endif

		PlaySFX(SONG_EF, 0x100, anim->xPosition, 1);
	}

	if (proc->timer == 69) {
		anim->flags3 |= (ANIM_BIT3_C02_BLOCK_END | ANIM_BIT3_C01_BLOCK_END_INBATTLE);

		StartBattleAnimStatusChgHitEffects(anim, proc->hitted);

		if (GetAnimPosition(anim) == POS_L) {
			CpuFastCopy(gpEfxUnitPaletteBackup[0], gPal + PAL_OFFSET(0x17), 0x20);
		} else {
			CpuFastCopy(gpEfxUnitPaletteBackup[1], gPal + PAL_OFFSET(0x19), 0x20);
		}

		EnableEfxStatusUnits(anim);
	} else if (proc->timer == 100) {
		anim->flags3 |= ANIM_BIT3_NEXT_ROUND_START;
		SpellFx_Finish();
		Proc_Break(proc);
	}
}

struct ProcScr CONST_DATA ProcScr_EfxSongBG[] = {
	PROC_NAME_DEBUG("efxSongBG"),
	PROC_REPEAT(EfxSongBG_Loop),
	PROC_END,
};

void NewEfxSongBG(struct Anim *anim)
{
	struct ProcEfxBG *proc;

	gEfxBgSemaphore++;

	proc = SpawnProc(ProcScr_EfxSongBG, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;

	SpellFx_RegisterBgGfx(Img_EfxSongBG, 0x2000);
	SpellFx_RegisterBgPal(Pal_EfxSongBG, 0x20);
	SpellFx_WriteBgMap(proc->anim, Tsa_EfxSongBG, Tsa_EfxSongBG);

	SpellFx_ClearBG1Position();
	SpellFx_SetSomeColorEffect();
}

void EfxSongBG_Loop(struct ProcEfxBG *proc)
{
	if (++proc->timer == 0x1F) {
		SpellFx_ClearBG1();
		SpellFx_ClearColorEffects();
		gEfxBgSemaphore--;
		Proc_Break(proc);
	}
}

struct ProcScr CONST_DATA ProcScr_EfxSongBGCOL[] = {
	PROC_NAME_DEBUG("efxSongBGCOL"),
	PROC_MARK(PROC_MARK_PAL_CHG),
	PROC_REPEAT(EfxSongBGCOL_Loop),
	PROC_END,
};

void NewEfxSongBGCOL(struct Anim *anim)
{
	static const u16 frames[] = {
		0, 1,
		1, 1,
		2, 1,
		3, 1,
		4, 1,
		5, 1,
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
		16, 1,
		17, 1,
		18, 1,
		19, 1,
		20, 1,
		21, 1,
		22, 1,
		23, 1,
		24, 1,
		25, 1,
		26, 1,
		27, 1,
		28, 1,
		29, 1,
		-1
	};

	struct ProcEfxBGCOL *proc;

	gEfxBgSemaphore++;

	proc = SpawnProc(ProcScr_EfxSongBGCOL, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->frame = 0;
	proc->frame_config = frames;
	proc->pal = Pal_EfxSongBG;
}

void EfxSongBGCOL_Loop(struct ProcEfxBGCOL *proc)
{
	int ret = EfxAdvanceFrameLut((i16 *)&proc->timer, (i16 *)&proc->frame, proc->frame_config);

	if (ret >= 0) {
		const u16 *pal = proc->pal;

		SpellFx_RegisterBgPal(pal + PAL_OFFSET(ret), 0x20);
		return;
	}

	if (ret == -1) {
		gEfxBgSemaphore--;
		Proc_Break(proc);
	}
}

/**
 * Dance
 */
struct ProcScr CONST_DATA ProcScr_EfxDance[] =
{
	PROC_NAME_DEBUG("efxDance"),
	PROC_REPEAT(EfxDance_Loop),
	PROC_END,
};


void StartSpellAnimDance(struct Anim *anim)
{
	struct ProcEfx *proc;

	SpellFx_Begin();
	SpellFx_ClearBG1Position();

	proc = SpawnProc(ProcScr_EfxDance, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->hitted = CheckRoundMiss(GetAnimRoundTypeAnotherSide(anim));
}

void EfxDance_Loop(struct ProcEfx *proc)
{
	struct Anim *anim = GetAnimAnotherSide(proc->anim);

	proc->timer++;

	if (proc->timer == 25) {
		NewEfxSongBG(anim);
		NewEfxSongBGCOL(anim);

		PlaySFX(SONG_EF, 0x100, anim->xPosition, 1);
	}

	if (proc->timer == 55) {
		anim->flags3 |= (ANIM_BIT3_C02_BLOCK_END | ANIM_BIT3_C01_BLOCK_END_INBATTLE);

		StartBattleAnimStatusChgHitEffects(anim, proc->hitted);

		if (GetAnimPosition(anim) == 0)
			CpuFastCopy(gpEfxUnitPaletteBackup[0], gPal + OBPAL_OFFSET(OBPAL_EFX_UNIT_L), 0x20);
		else
			CpuFastCopy(gpEfxUnitPaletteBackup[1], gPal + OBPAL_OFFSET(OBPAL_EFX_UNIT_R), 0x20);

		EnableEfxStatusUnits(anim);
		return;
	}

	if (proc->timer == 100) {
		anim->flags3 |= ANIM_BIT3_NEXT_ROUND_START;
		SpellFx_Finish();
		Proc_Break(proc);
	}
}

/**
 * Ballista
 */
struct ProcScr CONST_DATA ProcScr_efxShooter[] =
{
	PROC_NAME_DEBUG("efxShooter"),
	PROC_REPEAT(EfxShooter_Loop),
	PROC_END,
};

void StartSpellAnimBallista(struct Anim *anim)
{
	struct ProcEfx *proc;

	SpellFx_Begin();
	SpellFx_ClearBG1Position();

	proc = SpawnProc(ProcScr_efxShooter, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->hitted = CheckRoundMiss(GetAnimRoundTypeAnotherSide(anim));

	PlaySFX(SONG_136, 0x100, proc->anim->xPosition, 1);
}

void EfxShooter_Loop(struct ProcEfx *proc)
{
	int timer;
	struct Anim *anim = GetAnimAnotherSide(proc->anim);

	proc->timer++;

	if (proc->timer == 2) {
		NewEfxFarAttackWithDistance(proc->anim, -1);
		return;
	}

	timer = proc->timer;

	if (timer == 34) {
		PlaySFX(SONG_137, 0x100, proc->anim->xPosition, 1);
		return;
	}

	if (timer == 42) {
		NewEfxShooterOBJ(anim);
		return;
	}

	if (timer == 45) {
		anim->flags3 |= (ANIM_BIT3_C02_BLOCK_END | ANIM_BIT3_C01_BLOCK_END_INBATTLE);

		StartBattleAnimHitEffectsDefault(anim, proc->hitted);

		if (GetEfxHpChangeType(anim) != 2) {
			if (CheckRoundCrit(proc->anim) == 1)
				NewEfxCriricalEffect(anim);
			else {
				if (proc->hitted)
					return;

				NewEfxNormalEffect(proc->anim);
			}
		}

		if (!proc->hitted)
			EfxPlayHittedSFX(anim);

		return;
	}

	if (timer == 62)
		return;

	if (timer == 64) {
		SpellFx_Finish();
		Proc_Break(proc);
	}
}

struct ProcScr CONST_DATA ProcScr_EfxShooterOBJ[] =
{
	PROC_NAME_DEBUG("efxShooterOBJ"),
	PROC_REPEAT(EfxShooterOBJ_Loop),
	PROC_END,
};

void NewEfxShooterOBJ(struct Anim *anim)
{
	struct ProcEfxOBJ *proc;
	struct Anim * frontAnim;

	gEfxBgSemaphore++;

	proc = SpawnProc(ProcScr_EfxShooterOBJ, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;

	frontAnim = EfxCreateFrontAnim(anim, AnimScr_EfxShooterOBJ_L, AnimScr_EfxShooterOBJ_R, AnimScr_EfxShooterOBJ_L, AnimScr_EfxShooterOBJ_R);
	proc->anim2 = frontAnim;

	frontAnim->yPosition += 16;
	frontAnim->oam2 &= OAM2_LAYER(3);

	if (GetAnimPosition(anim) == POS_R)
		frontAnim->oam2 |= OAM2_CHR(VRAMOFF_OBJ_4000 / CHR_SIZE) + OAM2_PAL(OBPAL_EFX_UNIT_L);
	else
		frontAnim->oam2 |= OAM2_CHR(VRAMOFF_OBJ_6000 / CHR_SIZE) + OAM2_PAL(OBPAL_EFX_UNIT_R);
}

void EfxShooterOBJ_Loop(struct ProcEfxOBJ *proc)
{
	proc->timer++;

	if (proc->timer > 10) {
		BasRemove(proc->anim2);
		gEfxBgSemaphore--;
		Proc_Break(proc);
	}

	return;
}

/**
 * Eckesachs
 */
struct ProcScr CONST_DATA ProcScr_EfxEckesachs[] = {
	PROC_19,
	PROC_REPEAT(EfxEckesachs_Loop),
	PROC_END,
};

void StartSpellAnimEckesachs(struct Anim *anim)
{
	struct ProcEfx *proc;

	SpellFx_Begin();
	NewEfxSpellCast();
	SpellFx_ClearBG1Position();

	proc = SpawnProc(ProcScr_EfxEckesachs, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->hitted = CheckRoundMiss(GetAnimRoundTypeAnotherSide(anim)); // missed...
}

void EfxEckesachs_Loop(struct ProcEfx *proc)
{
	struct Anim *anim_other = GetAnimAnotherSide(proc->anim);
	int time = ++proc->timer;

	if (time == 1) {
		NewEfxFlashBgWhite(proc->anim, 6);
		return;
	}

	if (time == 6) {
		NewEfxFarAttackWithDistance(proc->anim, -1);
		NewEfxEckesachsBG(anim_other, 9);
		Pal_EfxEckesachsBGCtrl(anim_other, 9);
		NewEfxEckesachsBGCOL(anim_other);
		PlaySFX(SONG_10C, 0x100, anim_other->xPosition, 1);
		return;
	}

	if (time == 10) {
		anim_other->flags3 |= ANIM_BIT3_C02_BLOCK_END | ANIM_BIT3_C01_BLOCK_END_INBATTLE;
		StartBattleAnimHitEffectsDefault(anim_other, proc->hitted);

		if (!proc->hitted)
			EfxPlayHittedSFX(anim_other);

		return;
	}

	if (time == 25)
		return;

	if (time == 30) {
		SpellFx_Finish();
		EndEfxSpellCastAsync();
		Proc_Break(proc);
		return;
	}
}

struct ProcScr CONST_DATA ProcScr_EfxEckesachsBG[] = {
	PROC_19,
	PROC_REPEAT(EfxEckesachsBG_Loop),
	PROC_END,
};

void NewEfxEckesachsBG(struct Anim *anim, int duration)
{
	struct ProcEfxBG *proc;

	gEfxBgSemaphore++;
	proc = SpawnProc(ProcScr_EfxEckesachsBG, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->terminator = duration;

	SpellFx_RegisterBgPal(Pal_EfxEckesachsBG, 0x20);
	SpellFx_RegisterBgGfx(Img_EfxEckesachsBG, 0x2000);
	LZ77UnCompWram(Tsa_EfxEckesachsBG, gEkrTsaBuffer);

	if (GetAnimPosition(proc->anim) == POS_L)
		EfxTmCpyBG(gEkrTsaBuffer, gBg1Tm, 0x20, 0x14, BGPAL_EFX_SPELL_BG, VRAMOFF_BANIM_SPELL_BG / CHR_SIZE);
	else
		EfxTmCpyBgHFlip(gEkrTsaBuffer, gBg1Tm, 0x20, 0x14, BGPAL_EFX_SPELL_BG, VRAMOFF_BANIM_SPELL_BG / CHR_SIZE);

	EnableBgSync(BG1_SYNC_BIT);
	SpellFx_SetSomeColorEffect();
	SetWinEnable(0, 0, 0);
}

void EfxEckesachsBG_Loop(struct ProcEfxBG *proc)
{
	if (++proc->timer == proc->terminator) {
		SpellFx_ClearBG1();
		gEfxBgSemaphore--;
		SpellFx_ClearColorEffects();
		Proc_Break(proc);
	}
}

struct ProcScr CONST_DATA ProcScr_EfxEckesachsBGCtrl[] =
{
	PROC_19,
	PROC_REPEAT(EfxEckesachsBGCtrl_Loop),
	PROC_END,
};

void Pal_EfxEckesachsBGCtrl(struct Anim *anim, int duration)
{
	struct ProcEfxBG *proc;

	gEfxBgSemaphore++;

	proc = SpawnProc(ProcScr_EfxEckesachsBGCtrl, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->terminator = duration;

	if (GetAnimPosition(anim) == POS_L)
		proc->frame = 0xD8;
	else
		proc->frame = -0xD8;
}

void EfxEckesachsBGCtrl_Loop(struct ProcEfxBG *proc)
{
	int x;

	gDispIo.bg_off[BG_1].x = Interpolate(INTERPOLATE_LINEAR, 0, proc->frame, proc->timer, proc->terminator);

	if (GetAnimPosition(proc->anim) == POS_L)
		x = (gDispIo.bg_off[BG_1].x / 8) + 30;
	else
		x = (gDispIo.bg_off[BG_1].x / 8) - 1;

	FillBGRect(gBg1Tm + TM_OFFSET((x + 0) & 0x1F, 0), 1, 20, BGPAL_EFX_SPELL_BG, VRAMOFF_BANIM_SPELL_BG / CHR_SIZE);
	FillBGRect(gBg1Tm + TM_OFFSET((x + 1) & 0x1F, 0), 1, 20, BGPAL_EFX_SPELL_BG, VRAMOFF_BANIM_SPELL_BG / CHR_SIZE);
	FillBGRect(gBg1Tm + TM_OFFSET((x + 2) & 0x1F, 0), 1, 20, BGPAL_EFX_SPELL_BG, VRAMOFF_BANIM_SPELL_BG / CHR_SIZE);

	EnableBgSync(BG1_SYNC_BIT);

	if (++proc->timer > proc->terminator) {
		gEfxBgSemaphore--;
		SpellFx_ClearBG1();
		Proc_Break(proc);
	}
}

struct ProcScr CONST_DATA ProcScr_EfxEckesachsBGCOL[] = {
	PROC_19,
	PROC_MARK(10),
	PROC_REPEAT(EfxEckesachsBGCOL_Loop),
	PROC_END,
};

void NewEfxEckesachsBGCOL(struct Anim *anim)
{
	static const u16 frames[] = {
		0, 1,
		1, 1,
		2, 1,
		3, 1,
		4, 2,
		5, 1,
		6, 1,
		7, 1,
		-1
	};

	struct ProcEfxBGCOL *proc;

	gEfxBgSemaphore++;

	proc = SpawnProc(ProcScr_EfxEckesachsBGCOL, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->frame = 0;
	proc->frame_config = frames;
	proc->pal = Pal_EfxEckesachsBG;
}

void EfxEckesachsBGCOL_Loop(struct ProcEfxBGCOL *proc)
{
	int ret = EfxAdvanceFrameLut((i16 *)&proc->timer, (i16 *)&proc->frame, proc->frame_config);

	if (ret >= 0) {
		const u16 *pal = proc->pal;

		SpellFx_RegisterBgPal(pal + PAL_OFFSET(ret), 0x20);
		return;
	}

	if (ret == -1) {
		SpellFx_ClearColorEffects();
		gEfxBgSemaphore--;
		Proc_Break(proc);
	}
}

/**
 * Binding blade
 */
struct ProcScr CONST_DATA ProcScr_EfxHurtmut[] =
{
	PROC_NAME_DEBUG("efxHurtmut"),
	PROC_REPEAT(EfxHurtmut_Loop),
	PROC_END,
};

void StartSpellAnimBindingBlade(struct Anim *anim)
{
	struct ProcEfx *proc;

	SpellFx_Begin();
	NewEfxSpellCast();
	SpellFx_ClearBG1Position();

	proc = SpawnProc(ProcScr_EfxHurtmut, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->hitted = CheckRoundMiss(GetAnimRoundTypeAnotherSide(anim));
}

void EfxHurtmut_Loop(struct ProcEfx *proc)
{
	struct Anim *anim = GetAnimAnotherSide(proc->anim);
	int duration = EfxGetCamMovDuration();

	proc->timer++;

	if (proc->timer == 1)
		NewEfxFarAttackWithDistance(proc->anim, -1);

	if (proc->timer == duration + 1) {
		PlaySFX(0x10D, 0x100, anim->xPosition, 1);
		NewEfxHurtmutOBJ(anim);

		NewEfxFlashBgWhite(proc->anim, 6);

		anim->flags3 |= (ANIM_BIT3_C02_BLOCK_END | ANIM_BIT3_C01_BLOCK_END_INBATTLE);

		StartBattleAnimHitEffectsDefault(anim, proc->hitted);

		if (!proc->hitted)
			EfxPlayHittedSFX(anim);

		return;
	}

	if (proc->timer == duration + 28) {
		NewEfxALPHA(anim, 0, 14, 16, 0, 0);
		return;
	}

	if (proc->timer == duration + 50)
		return;

	if (proc->timer == duration + 55) {
		SpellFx_Finish();
		EndEfxSpellCastAsync();
		Proc_Break(proc);
	}
}

struct ProcScr CONST_DATA ProcScr_EfxHurtmutOBJ[] =
{
	PROC_NAME_DEBUG("efxHurtmutOBJ"),
	PROC_REPEAT(EfxHurtmutOBJ_Loop),
	PROC_END,
};

void NewEfxHurtmutOBJ(struct Anim *anim)
{
	struct ProcEfxOBJ *proc;
	u32 * scr;

	gEfxBgSemaphore++;

	proc = SpawnProc(ProcScr_EfxHurtmutOBJ, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->terminator = 52;

	if (GetAnimPosition(anim) == POS_L)
		scr = AnimScr_EfxBindingBlade_L;
	else
		scr = AnimScr_EfxBindingBlade_R;

	proc->anim2 = EfxCreateFrontAnim(anim, scr, scr, scr, scr);

	SpellFx_RegisterObjPal(Pal_EfxBindingBlade, PLTT_SIZE_4BPP);
	SpellFx_RegisterObjGfx(Img_BreathSprites, 0x1000);
}

void EfxHurtmutOBJ_Loop(struct ProcEfxOBJ *proc)
{
	proc->timer++;

	if (proc->timer > proc->terminator) {
		BasRemove(proc->anim2);
		gEfxBgSemaphore--;
		Proc_Break(proc);
	}
}

/**
 * Fire breath
 */
struct ProcScr CONST_DATA ProcScr_EfxFirebreath[] =
{
	PROC_NAME_DEBUG("efxFirebreath"),
	PROC_REPEAT(EfxFirebreath_Loop),
	PROC_END,
};

void StartSpellAnimFireBreath(struct Anim *anim)
{
	struct ProcEfx *proc;

	SpellFx_Begin();
	SpellFx_ClearBG1Position();

	proc = SpawnProc(ProcScr_EfxFirebreath, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->hitted = CheckRoundMiss(GetAnimRoundTypeAnotherSide(anim));

	return;
}

void EfxFirebreath_Loop(struct ProcEfx *proc)
{
	int timer;
	struct Anim *anim = GetAnimAnotherSide(proc->anim);

	timer = ++proc->timer;

	if (timer == 1) {
		NewEfxMagicQUAKE(proc->anim, 90);

		NewEfxFirebreathOBJ(anim);
		NewEfxFirebreathBG(anim);
		NewEfxFirebreathBGCOL(anim);

		NewEfxALPHA(anim, 40, 15, 16, 0, 0);

		PlaySFX(0x11D, 0x100, anim->xPosition, 1);
		return;
	}

	if (timer == 15) {
		anim->flags3 |= (ANIM_BIT3_C02_BLOCK_END | ANIM_BIT3_C01_BLOCK_END_INBATTLE);

		StartBattleAnimHitEffectsDefault(anim, proc->hitted);

		if (!proc->hitted)
			EfxPlayHittedSFX(anim);

		return;
	}

	if (timer == 120)
		return;

	if (timer == 130) {
		SpellFx_Finish();
		Proc_Break(proc);
		return;
	}
}

struct ProcScr CONST_DATA ProcScr_EfxFirebreathOBJ[] =
{
	PROC_NAME_DEBUG("efxFirebreathOBJ"),
	PROC_REPEAT(EfxFirebreathOBJ_Loop),
	PROC_END,
};

void NewEfxFirebreathOBJ(struct Anim *anim)
{
	struct ProcEfxOBJ *proc;
	struct Anim * frontAnim;
	u32 * scr;

	gEfxBgSemaphore++;

	proc = SpawnProc(ProcScr_EfxFirebreathOBJ, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->terminator = 52;

	if (GetAnimPosition(anim) == 0)
		scr = AnimScr_FirebreathOBJ_L;
	else
		scr = AnimScr_FirebreathOBJ_R;

	frontAnim = EfxCreateFrontAnim(anim, scr, scr, scr, scr);
	proc->anim2 = frontAnim;

	if (GetAnimPosition(anim) == 0)
		frontAnim->xPosition += 32;
	else
		frontAnim->xPosition -= 32;

	SpellFx_RegisterObjPal(Pal_EfxBindingBlade, PLTT_SIZE_4BPP);
	SpellFx_RegisterObjGfx(Img_BreathSprites, 32 * 4 * CHR_SIZE);
}

void EfxFirebreathOBJ_Loop(struct ProcEfxOBJ *proc)
{
	proc->timer++;

	if (proc->timer > proc->terminator) {
		BasRemove(proc->anim2);
		gEfxBgSemaphore--;
		Proc_Break(proc);
	}
}

struct ProcScr CONST_DATA ProcScr_EfxFirebreathBG[] = {
	PROC_NAME_DEBUG("efxFirebreathBG"),
	PROC_REPEAT(EfxFirebreathBG_Loop),
	PROC_END,
};

void NewEfxFirebreathBG(struct Anim *anim)
{
	struct ProcEfxBG *proc;

	gEfxBgSemaphore++;

	proc = SpawnProc(ProcScr_EfxFirebreathBG, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->terminator = 112;

	SpellFx_RegisterBgGfx(Img_EfxElfireBG, 32 * 8 * CHR_SIZE);
	SpellFx_WriteBgMap(proc->anim, Tsa_FireBreathBg, Tsa_FireBreathBg);
	SpellFx_ClearBG1Position();
	SpellFx_SetSomeColorEffect();

#if FE6
	if (gEkrDistanceType == EKR_DISTANCE_CLOSE)
		return;

	if (GetAnimPosition(proc->anim) == POS_L)
		SetBgOffset(BG_1, 0x18, 0);
	else
		SetBgOffset(BG_1, 0xE8, 0);

	func_fe6_0805B0D4(gBg1Tm + TM_OFFSET(0x1E, 0), 2, 20, BGPAL_EFX_SPELL_BG, VRAMOFF_BANIM_SPELL_BG / CHR_SIZE);
#endif
}

void EfxFirebreathBG_Loop(struct ProcEfxBG *proc)
{
	proc->timer++;

	if (proc->timer == proc->terminator) {
		SpellFx_ClearBG1();
		SpellFx_ClearColorEffects();
		gEfxBgSemaphore--;
		Proc_Break(proc);
	}
}

struct ProcScr CONST_DATA ProcScr_EfxFirebreathBGCOL[] =
{
	PROC_NAME_DEBUG("efxFirebreathBGCOL"),
	PROC_MARK(PROC_MARK_PAL_CHG),
	PROC_REPEAT(EfxFirebreathBGCOL_Loop),
	PROC_END,
};

void NewEfxFirebreathBGCOL(struct Anim *anim)
{
	// clang-format off
	static const u16 frames[] =
	{
		4, 2,
		5, 2, 6, 2, 5, 2, 6, 2,
		5, 2, 6, 2, 5, 2, 6, 2,
		5, 2, 6, 2, 5, 2, 6, 2,
		5, 2, 6, 2, 5, 2, 6, 2,
		5, 2, 6, 2, 5, 2, 6, 2,
		5, 2, 6, 2, 5, 2, 6, 2,
		5, 2, 6, 2, 4, 2,
		-1
	};

	struct ProcEfxBGCOL *proc;

	gEfxBgSemaphore++;
	proc = SpawnProc(ProcScr_EfxFirebreathBGCOL, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->frame = 0;
	proc->frame_config = frames;
	proc->pal = Pal_EfxElfireBGCOL;
}

void EfxFirebreathBGCOL_Loop(struct ProcEfxBGCOL *proc)
{
	int ret = EfxAdvanceFrameLut((i16 *)&proc->timer, (i16 *)&proc->frame, proc->frame_config);

	if (ret >= 0) {
#if FE8
		CpuFastSet(proc->pal, gEfxPal, 8);
		EfxPalWhiteInOut(gEfxPal, 0, 1, ret);
		SpellFx_RegisterBgPal(gEfxPal, PLTT_SIZE_4BPP);
#elif FE6
		const u16 *pal = proc->pal;

		SpellFx_RegisterBgPal(pal + PAL_OFFSET(ret), PLTT_SIZE_4BPP);
#endif
		return;
	}

	if (ret == -1) {
		gEfxBgSemaphore--;
		Proc_Break(proc);
	}
}

/**
 * Ice breath (by Fae)
 */
struct ProcScr CONST_DATA ProcScr_EfxIcebreath[] = {
	PROC_NAME_DEBUG("efxIcebreath"),
	PROC_REPEAT(EfxIcebreath_Loop),
	PROC_END,
};

void StartSpellAnimIceBreath(struct Anim *anim)
{
	struct ProcEfx *proc;

	SpellFx_Begin();
	NewEfxSpellCast();
	SpellFx_ClearBG1Position();

	proc = SpawnProc(ProcScr_EfxIcebreath, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->hitted = CheckRoundMiss(GetAnimRoundTypeAnotherSide(anim));
}

void EfxIcebreath_Loop(struct ProcEfx *proc)
{
	int timer;
	struct Anim *anim = GetAnimAnotherSide(proc->anim);

	proc->timer++;

	if (proc->timer == 1) {
		NewEfxMagicQUAKE(proc->anim, 90);
		NewEfxIcebreathOBJ(proc->anim);

		PlaySFX(SONG_11E, 0x100, anim->xPosition, 1);
	}

	timer = proc->timer;

	if (timer == 4) {
		anim->flags3 |= (ANIM_BIT3_C02_BLOCK_END | ANIM_BIT3_C01_BLOCK_END_INBATTLE);

		StartBattleAnimHitEffectsDefault(anim, proc->hitted);

		if (!proc->hitted)
			EfxPlayHittedSFX(anim);

		return;
	}
	if (timer == 50)
		return;

	if (timer == 60) {
		SpellFx_Finish();
		EndEfxSpellCastAsync();
		Proc_Break(proc);
		return;
	}
}

struct ProcScr CONST_DATA ProcScr_EfxIcebreathOBJ[] =
{
	PROC_NAME_DEBUG("efxIcebreathOBJ"),
	PROC_ONEND(EfxIcebreathOBJ_OnEnd),
	PROC_SLEEP(52),
	PROC_END,
};

void NewEfxIcebreathOBJ(struct Anim *anim)
{
	struct ProcEfxOBJ *proc;
	struct Anim * frontAnim;
	u32 * scrA;
	u32 * scrB;

	gEfxBgSemaphore++;

	proc = SpawnProc(ProcScr_EfxIcebreathOBJ, PROC_TREE_3);
	proc->anim = anim;

	scrB = AnimScr_IcebreathOBJ_R;
	scrA = AnimScr_IcebreathOBJ_L;
	frontAnim = EfxCreateFrontAnim(anim, scrA, scrB, scrA, scrB);
	proc->anim2 = frontAnim;

	if (GetAnimPosition(anim) == 0)
		frontAnim->xPosition += 32;
	else
		frontAnim->xPosition -= 32;

	SpellFx_RegisterObjPal(Pal_IceBreathSprites, PLTT_SIZE_4BPP);
	SpellFx_RegisterObjGfx(Img_BreathSprites, 32 * 4 * CHR_SIZE);
}

void EfxIcebreathOBJ_OnEnd(struct ProcEfxOBJ *proc)
{
	gEfxBgSemaphore--;
	BasRemove(proc->anim2);
}

/**
 * Dark breath (by Idunn)
 */
struct ProcScr CONST_DATA ProcScr_EfxDarkbreath[] =
{
	PROC_NAME_DEBUG("efxDarkbreath"),
	PROC_REPEAT(EfxDarkbreath_Loop),
	PROC_END,
};

void StartSpellAnimDarkBreath(struct Anim *anim)
{
	struct ProcEfx *proc;

	SpellFx_Begin();
	SpellFx_ClearBG1Position();

	proc = SpawnProc(ProcScr_EfxDarkbreath, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->hitted = CheckRoundMiss(GetAnimRoundTypeAnotherSide(anim));
}

void EfxDarkbreath_Loop(struct ProcEfx *proc)
{
	int timer;
	struct Anim *anim = GetAnimAnotherSide(proc->anim);

	proc->timer++;

	if (proc->timer == 1) {
#if FE8
		NewEfxFarAttackWithDistance(proc->anim, -1);
#endif

		NewEfxMagicQUAKE(proc->anim, 90);
		NewEfxDarkbreathBG(proc->anim);
		NewEfxDarkbreathBGCOL(proc->anim);
		NewEfxDarkbreathOBJ(proc->anim);

		PlaySFX(SONG_11F, 0x100, anim->xPosition, 1);
	}

	timer = proc->timer;

	if (timer == 4) {
		anim->flags3 |= (ANIM_BIT3_C02_BLOCK_END | ANIM_BIT3_C01_BLOCK_END_INBATTLE);

		StartBattleAnimHitEffectsDefault(anim, proc->hitted);

		if (!proc->hitted)
			EfxPlayHittedSFX(anim);

		return;
	}

	if (timer == 32)
		return;

	if (timer == 48) {
		SpellFx_Finish();
		Proc_Break(proc);
		return;
	}
}

struct ProcScr CONST_DATA ProcScr_EfxDarkbreathBG[] =
{
	PROC_NAME_DEBUG("efxDarkbreathBG"),
	PROC_REPEAT(EfxDarkbreathBG_Loop),
	PROC_END,
};

u16 * CONST_DATA Tsa_EfxDarkbreathBG[] = {
	Tsa_EfxDarkbreathBG1,
	Tsa_EfxDarkbreathBG2,
	Tsa_EfxDarkbreathBG3,
	Tsa_EfxDarkbreathBG4,
	Tsa_EfxDarkbreathBG5,
	Tsa_EfxDarkbreathBG6,
	Tsa_EfxDarkbreathBG7,
	Tsa_EfxDarkbreathBG8,
	Tsa_EfxDarkbreathBG9,
	Tsa_EfxDarkbreathBG10,
	Tsa_EfxDarkbreathBG11,
	Tsa_EfxDarkbreathBG12,
};

void NewEfxDarkbreathBG(struct Anim *anim)
{
	static const u16 frames[] = {
		11, 12,
		0, 2,
		1, 2,
		2, 2,
		1, 2,
		3, 2,
		4, 2,
		5, 2,
		6, 2,
		11, 2,
		7, 2,
		8, 2,
		11, 2,
		9, 2,
		10, 2,
		8, 2,
		11, 10,
		-1
	};
	// clang-format on

	struct ProcEfxBG *proc;

	gEfxBgSemaphore++;

	proc = SpawnProc(ProcScr_EfxDarkbreathBG, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->frame = 0;
	proc->frame_config = frames;

	proc->tsal = Tsa_EfxDarkbreathBG;
	proc->tsar = Tsa_EfxDarkbreathBG;
	SpellFx_RegisterBgGfx(Img_EfxDarkbreathBG, 32 * 8 * CHR_SIZE);
	SpellFx_SetSomeColorEffect();
}

void EfxDarkbreathBG_Loop(struct ProcEfxBG *proc)
{
	int ret = EfxAdvanceFrameLut((i16 *)&proc->timer, (i16 *)&proc->frame, proc->frame_config);

	if (ret >= 0) {
		u16 **tsaL = proc->tsal;
		u16 **tsaR = proc->tsar;

		SpellFx_WriteBgMap(proc->anim, *(tsaL + ret), *(tsaR + ret));
		return;
	}

	if (ret == -1) {
		SpellFx_ClearBG1();
		gEfxBgSemaphore--;
		SpellFx_ClearColorEffects();
		Proc_Break(proc);
	}
}

struct ProcScr CONST_DATA ProcScr_EfxDarkbreathBGCOL[] =
{
	PROC_NAME_DEBUG("efxDarkbreathBGCOL"),
	PROC_MARK(PROC_MARK_PAL_CHG),
	PROC_REPEAT(EfxDarkbreathBGCOL_Loop),
	PROC_END,
};

void NewEfxDarkbreathBGCOL(struct Anim *anim)
{
	static const u16 frames[] = {
		0, 2,
		1, 2,
		2, 2,
		1, 2,
		0, 2,
		1, 2,
		2, 2,
		1, 2,
		0, 2,
		1, 2,
		2, 2,
		1, 2,
		0, 2,
		1, 2,
		2, 2,
		1, 2,
		0, 2,
		1, 2,
		2, 2,
		1, 2,
		0, 2,
		1, 2,
		2, 2,
		1, 2,
		0, 2,
		1, 2,
		2, 2,
		1, 2,
		0, 2,
		1, 2,
		2, 2,
		1, 2,
		0, 2,
		1, 2,
		2, 2,
		1, 2,
		0, 2,
		1, 2,
		2, 2,
		1, 2,
		-1,
	};

	struct ProcEfxBGCOL *proc;

	gEfxBgSemaphore++;

	proc = SpawnProc(ProcScr_EfxDarkbreathBGCOL, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->frame = 0;
	proc->frame_config = frames;
	proc->pal = Pal_EfxThunderstormBG;
}

void EfxDarkbreathBGCOL_Loop(struct ProcEfxBGCOL *proc)
{
	int ret = EfxAdvanceFrameLut((i16 *)&proc->timer, (i16 *)&proc->frame, proc->frame_config);

	if (ret >= 0) {
		const u16 * pal = proc->pal;

		SpellFx_RegisterBgPal(pal + PAL_OFFSET(ret), PLTT_SIZE_4BPP);
		return;
	}

	if (ret == -1) {
		SpellFx_ClearColorEffects();
		gEfxBgSemaphore--;
		Proc_Break(proc);
	}
}

struct ProcScr CONST_DATA ProcScr_EfxDarkbreathOBJ[] =
{
	PROC_NAME_DEBUG("efxDarkbreathOBJ"),
	PROC_REPEAT(EfxDarkbreathOBJ_Loop),
	PROC_END,
};

void NewEfxDarkbreathOBJ(struct Anim *anim)
{
	struct ProcEfxOBJ *proc;
	struct Anim * frontAnim;

	gEfxBgSemaphore++;

	proc = SpawnProc(ProcScr_EfxDarkbreathOBJ, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->terminator = 55;

	frontAnim = EfxCreateFrontAnim(anim, AnimScr_DarkBreath, AnimScr_DarkBreath, AnimScr_DarkBreath, AnimScr_DarkBreath);
	proc->anim2 = frontAnim;

	if (GetAnimPosition(anim) == 0)
		frontAnim->xPosition += 0x24;
	else
		frontAnim->xPosition -= 0x24;

	frontAnim->yPosition += 0xC;

	SpellFx_RegisterObjPal(Pal_DarkBreathSprites, PLTT_SIZE_4BPP);
	SpellFx_RegisterObjGfx(Img_BreathSprites, 32 * 4 * CHR_SIZE);
}

void EfxDarkbreathOBJ_Loop(struct ProcEfxOBJ *proc)
{
	proc->timer++;

	if (proc->timer == proc->terminator) {
		gEfxBgSemaphore--;
		BasRemove(proc->anim2);
		Proc_Break(proc);
	}
}

/**
 * Thunder
 */
struct ProcScr CONST_DATA ProcScr_EfxThunder[] = {
	PROC_NAME_DEBUG("efxThunder"),
	PROC_REPEAT(EfxThunder_Loop),
	PROC_END,
};

void StartSpellAnimThunder(struct Anim *anim)
{
	struct ProcEfx *proc;

	SpellFx_Begin();
	NewEfxSpellCast();
	SpellFx_ClearBG1Position();

	proc = SpawnProc(ProcScr_EfxThunder, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->hitted = CheckRoundMiss(GetAnimRoundTypeAnotherSide(anim));
}

void EfxThunder_Loop(struct ProcEfx *proc)
{
	struct Anim *animc = GetAnimAnotherSide(proc->anim);
	int cur, frame = EfxGetCamMovDuration();

	if (++proc->timer == 1)
		NewEfxFarAttackWithDistance(proc->anim, -1);
	
	cur = proc->timer;
	if (cur == (frame + 1)) {
		NewEfxThunderBG(animc);
		NewEfxThunderBGCOL(animc);
		NewEfxThunderOBJ(animc);
		return;
	}

	if (cur == (frame + 4)) {
		animc->flags3 |= ANIM_BIT3_C02_BLOCK_END | ANIM_BIT3_C01_BLOCK_END_INBATTLE;
		StartBattleAnimHitEffectsDefault(animc, proc->hitted);
		PlaySFX(0xF5, 0x100, animc->xPosition, 1);

		if (proc->hitted == EKR_HITTED)
			EfxPlayHittedSFX(animc);
		
		return;
	}

	if (cur == (frame + 0x50))
		return;
	
	if (cur == (frame + 0x60)) {
		SpellFx_Finish();
		EndEfxSpellCastAsync();
		Proc_Break(proc);
	}
}

struct ProcScr CONST_DATA ProcScr_EfxThunderBG[] = {
	PROC_NAME_DEBUG("efxThunderBG"),
	PROC_REPEAT(EfxThunderBG_Loop),
	PROC_END,
};

void NewEfxThunderBG(struct Anim *anim)
{
	static const u16 frame_config[] = {
		0, 4, 1, 40, -1
	};

	static CONST_DATA u16 * tsa_l[] = {
		Tsa_EfxThuderBg1,
		Tsa_EfxThuderBg2
	};

	static CONST_DATA u16 * tsa_r[] = {
		Tsa_EfxThuderBg1,
		Tsa_EfxThuderBg2
	};

	struct ProcEfxBG *proc;

	gEfxBgSemaphore++;
	proc = SpawnProc(ProcScr_EfxThunderBG, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->frame = 0;
	proc->frame_config = frame_config;
	proc->tsal = tsa_l;
	proc->tsar = tsa_r;

	SpellFx_RegisterBgGfx(Img_EfxThunderBG, 0x10C0);
	SpellFx_SetSomeColorEffect();

	if (gEkrDistanceType != EKR_DISTANCE_CLOSE) {
		if (GetAnimPosition(proc->anim) == POS_L)
			SetBgOffset(BG_1, 0x18, 0x0);
		else
			SetBgOffset(BG_1, 0xE8, 0x0);
	}
}

void EfxThunderBG_Loop(struct ProcEfxBG *proc)
{
	int val, ret;

	val = 0;
	ret = EfxAdvanceFrameLut((i16 *)&proc->timer, (i16 *)&proc->frame, proc->frame_config);
	if (ret >= 0) {
		u16 **buf1 = proc->tsal;
		u16 **buf2 = proc->tsar;

		SpellFx_WriteBgMap(proc->anim, buf1[ret], buf2[ret]);

		if (ret == 0)
			val = 0x11F;
		
		if (ret == 1)
			val = 0x150;
		
		FillBGRect(gBg1Tm+ TM_OFFSET(0x1E, 0x0), 0x2, 0x14, 0x1, val);
		return;
	}

	if (ret == -1) {
		SpellFx_ClearBG1();
		gEfxBgSemaphore--;
		SpellFx_ClearColorEffects();
		Proc_Break(proc);
	}
}

struct ProcScr CONST_DATA ProcScr_EfxThunderBGCOL[] = {
	PROC_NAME_DEBUG("efxThunderBGCOL"),
	PROC_MARK(PROC_MARK_PAL_CHG),
	PROC_REPEAT(EfxThunderBGCOL_Loop),
	PROC_END,
};

void NewEfxThunderBGCOL(struct Anim *anim)
{
	static const u16 frame_config[] = {
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
		-1
	};

	struct ProcEfxBGCOL *proc;
	gEfxBgSemaphore++;
	proc = SpawnProc(ProcScr_EfxThunderBGCOL, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->frame = 0;
	proc->frame_config = frame_config;
	proc->pal = Pal_EfxThunderBGCOL;
}

void EfxThunderBGCOL_Loop(struct ProcEfxBGCOL *proc)
{
	int ret;
	ret = EfxAdvanceFrameLut((i16 *)&proc->timer, (i16 *)&proc->frame, proc->frame_config);
	if (ret >= 0) {
		const u16 * pal = proc->pal;

		SpellFx_RegisterBgPal(pal + PAL_OFFSET(ret), 0x20);
		return;
	}

	if (ret == -1) {
		SpellFx_ClearColorEffects();
		gEfxBgSemaphore--;
		Proc_Break(proc);
	}
}

struct ProcScr CONST_DATA ProcScr_EfxThunderOBJ[] = {
	PROC_NAME_DEBUG("efxThunderOBJ"),
	PROC_REPEAT(EfxThunderOBJ_Loop),
	PROC_END,
};

void NewEfxThunderOBJ(struct Anim *anim)
{
	struct ProcEfxOBJ *proc;

	gEfxBgSemaphore++;
	proc = SpawnProc(ProcScr_EfxThunderOBJ, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->anim2 = EfxCreateFrontAnim(anim, AnimScr_EfxThunderOBJ_L, AnimScr_EfxThunderOBJ_R, AnimScr_EfxThunderOBJ_L, AnimScr_EfxThunderOBJ_R);

	SpellFx_RegisterObjPal(Pal_EfxThunderOBJ, 0x20);
	SpellFx_RegisterObjGfx(Img_EfxThunderOBJ, 0x1000);
}

void EfxThunderOBJ_Loop(struct ProcEfxOBJ *proc)
{
	if (++proc->timer > 0x32) {
		BasRemove(proc->anim2);
		gEfxBgSemaphore--;
		Proc_Break(proc);
	}
}

struct ProcScr CONST_DATA ProcScr_EfxFire[] = {
	PROC_NAME_DEBUG("efxFire"),
	PROC_REPEAT(EfxFire_Loop),
	PROC_END,
};

void StartSpellAnimFire(struct Anim *anim)
{
	struct ProcEfx *proc;

	SpellFx_Begin();
	NewEfxSpellCast();
	SpellFx_ClearBG1Position();

	proc = SpawnProc(ProcScr_EfxFire, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->type = 0;
	proc->hitted = CheckRoundMiss(GetAnimRoundTypeAnotherSide(anim));
}

void StartSpellAnimElfire(struct Anim *anim)
{
	struct ProcEfx *proc;

	SpellFx_Begin();
	NewEfxSpellCast();
	SpellFx_ClearBG1Position();

	proc = SpawnProc(ProcScr_EfxFire, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->type = 1;
	proc->hitted = CheckRoundMiss(GetAnimRoundTypeAnotherSide(anim));
}

void EfxFire_Loop(struct ProcEfx *proc)
{
	int r5, r7, r8, r9, time;
	struct Anim *animc = GetAnimAnotherSide(proc->anim);

	if (0 == gEkrDistanceType) {
		r5 = 0x20;
		r7 = 0x34;
		r8 = 0x36;
		r9 = 0x55;
	} else {
		r5 = 0x28;
		r7 = 0x3C;
		r8 = 0x41;
		r9 = 0x60;
	}

	if (++proc->timer == 1) {
		NewEfxFireBG(proc->anim);
		NewEfxFireOBJ(proc->anim);
		PlaySFX(0xF1, 0x100, proc->anim->xPosition, 1);
	}

	time = proc->timer;
	if (time == r5) {
		NewEfxFarAttackWithDistance(proc->anim, -1);
		return;
	}

	if (time == r7) {
		animc->flags3 |= ANIM_BIT3_C02_BLOCK_END | ANIM_BIT3_C01_BLOCK_END_INBATTLE;
		StartBattleAnimHitEffectsDefault(animc, proc->hitted);

		if (proc->hitted != EKR_HITTED)
			return;

		if (proc->type == 0) {
			PlaySFX(SONG_F7, 0x100, animc->xPosition, 1);
			NewEfxFireHITBG(animc);
		} else {
			PlaySFX(SONG_F8, 0x100, animc->xPosition, 1);
			NewEfxElfireBG(animc);
			NewEfxElfireBGCOL(animc);
			NewEfxElfireOBJ(animc);
		}
		EfxPlayHittedSFX(animc);
		return;
	}

	if (time == r8)
		return;

	if (time == r9) {
		SpellFx_Finish();
		EndEfxSpellCastAsync();
		Proc_Break(proc);
	}
}

struct ProcScr CONST_DATA ProcScr_EfxFireBG[] = {
	PROC_NAME_DEBUG("efxFireBG"),
	PROC_REPEAT(EfxFireBG_Loop),
	PROC_END,
};

void NewEfxFireBG(struct Anim *anim)
{
	static const u16 frame_config[] = {
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
		-1
	};

	static CONST_DATA u16 *tsal[] = {
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
		Tsa_EfxFireBG_0812EE90,
	};

	static CONST_DATA u16 *tsar[] = {
		Tsa_EfxFireBG_0812EF50,
		Tsa_EfxFireBG_0812EFF8,
		Tsa_EfxFireBG_0812F0A0,
		Tsa_EfxFireBG_0812F158,
		Tsa_EfxFireBG_0812F220,
		Tsa_EfxFireBG_0812F2F0,
		Tsa_EfxFireBG_0812F3F0,
		Tsa_EfxFireBG_0812F4F8,
		Tsa_EfxFireBG_0812F60C,
		Tsa_EfxFireBG_0812F744,
		Tsa_EfxFireBG_0812F848,
		Tsa_EfxFireBG_0812F91C,
	};

	struct ProcEfxBG *proc;

	gEfxBgSemaphore++;
	proc = SpawnProc(ProcScr_EfxFireBG, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->frame = 0;
	proc->frame_config = frame_config;
	proc->tsal = tsal;
	proc->tsar = tsar;

	SpellFx_RegisterBgPal(Pal_EfxFireBG, 0x20);
	SpellFx_RegisterBgGfx(Img_EfxFireBG, 0x2000);
	SpellFx_SetSomeColorEffect();
}

void EfxFireBG_Loop(struct ProcEfxBG *proc)
{
	int ret;

	ret = EfxAdvanceFrameLut((i16 *)&proc->timer, (i16 *)&proc->frame, proc->frame_config);
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

struct ProcScr CONST_DATA ProcScr_efxFireOBJ[] = {
	PROC_NAME_DEBUG("efxFireOBJ"),
	PROC_REPEAT(EfxFireOBJ_Loop),
	PROC_END,
};

void NewEfxFireOBJ(struct Anim *anim)
{
	struct Anim *anim2;
	struct ProcEfxOBJ *proc;

	gEfxBgSemaphore++;
	proc = SpawnProc(ProcScr_efxFireOBJ, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	anim2 = EfxCreateFrontAnim(anim, AnimScr_EfxFireOBJ_R_Front, AnimScr_EfxFireOBJ_L_Front, AnimScr_EfxFireOBJ_R_Back, AnimScr_EfxFireOBJ_L_Back);
	proc->anim2 = anim2;

	if (GetAnimPosition(anim) == POS_L)
		anim2->xPosition = anim->xPosition - 0x8;
	else
		anim2->xPosition = anim->xPosition + 0x8;
	
	anim2->yPosition = anim->yPosition + 0x8;

	SpellFx_RegisterObjPal(Pal_EfxFireOBJ, 0x20);
	SpellFx_RegisterObjGfx(Img_EfxFireOBJ, 0x1000);
}

void EfxFireOBJ_Loop(struct ProcEfxOBJ *proc)
{
	int time = ++proc->timer;

	if (time == 0x25) {
		PlaySFX(SONG_F2, 0x100, proc->anim->xPosition, 0x1);
		return;
	}

	if (time > 0x32) {
		BasRemove(proc->anim2);
		gEfxBgSemaphore--;
		Proc_Break(proc);
	}
}

struct ProcScr CONST_DATA ProcScr_EfxFireHITBG[] = {
	PROC_NAME_DEBUG("efxFireHITBG"),
	PROC_REPEAT(EfxFireHITBG_Loop),
	PROC_END,
};

CONST_DATA u16 *ImgArray_EfxFireHITBG[] = {
	Img_EfxFireHITBG_0812FFF8,
	Img_EfxFireHITBG_0812FFF8,
	Img_EfxFireHITBG_0812FFF8,
	Img_EfxFireHITBG_0812FFF8,
	Img_EfxFireHITBG_0812FFF8,
	Img_EfxFireHITBG_0812FFF8,
	Img_EfxFireHITBG_08130D34,
	Img_EfxFireHITBG_08130D34,
	Img_EfxFireHITBG_08130D34,
	Img_EfxFireHITBG_08131A10,
	Img_EfxFireHITBG_08131A10,
	Img_EfxFireHITBG_08132838,
	Img_EfxFireHITBG_08132838,
	Img_EfxFireHITBG_0813382C,
	Img_EfxFireHITBG_0813382C,
	Img_EfxFireHITBG_08134AC8,
	Img_EfxFireHITBG_08135694,
	Img_EfxFireHITBG_0813628C,
	Img_EfxFireHITBG_08136DE4,
	Img_EfxFireHITBG_081378E0,
	Img_EfxFireHITBG_081382E8
};

CONST_DATA u16 *TsaArray_EfxFireHITBG[] = {
	Tsa_EfxFireHITBG_08138C10,
	Tsa_EfxFireHITBG_08138CBC,
	Tsa_EfxFireHITBG_08138D74,
	Tsa_EfxFireHITBG_08138E40,
	Tsa_EfxFireHITBG_08138F20,
	Tsa_EfxFireHITBG_08139014,
	Tsa_EfxFireHITBG_0813912C,
	Tsa_EfxFireHITBG_08139258,
	Tsa_EfxFireHITBG_08139390,
	Tsa_EfxFireHITBG_081394D4,
	Tsa_EfxFireHITBG_08139628,
	Tsa_EfxFireHITBG_08139780,
	Tsa_EfxFireHITBG_081398E8,
	Tsa_EfxFireHITBG_08139A54,
	Tsa_EfxFireHITBG_08139BD0,
	Tsa_EfxFireHITBG_08139D64,
	Tsa_EfxFireHITBG_08139F04,
	Tsa_EfxFireHITBG_0813A0A4,
	Tsa_EfxFireHITBG_0813A244,
	Tsa_EfxFireHITBG_0813A3E4,
	Tsa_EfxFireHITBG_0813A574
};

const u16 FrameConf_EfxFireHITBG[] = {
	0, 1,
	1, 1,
	2, 1,
	3, 1,
	4, 1,
	5, 1,
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
	16, 1,
	17, 1,
	18, 2,
	19, 2,
	20, 4,
	-1
};

void NewEfxFireHITBG(struct Anim *anim)
{
	struct ProcEfxBG *proc;

	gEfxBgSemaphore++;
	proc = SpawnProc(ProcScr_EfxFireHITBG, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->frame = 0;
	proc->frame_config = FrameConf_EfxFireHITBG;
	proc->tsal = TsaArray_EfxFireHITBG;
	proc->tsar = TsaArray_EfxFireHITBG;
	proc->img = ImgArray_EfxFireHITBG;

	SpellFx_RegisterBgPal(Pal_EfxFireHITBG, 0x20);
	SpellFx_SetSomeColorEffect();

	if (gEkrDistanceType == EKR_DISTANCE_CLOSE)
		return;
	
	if (GetAnimPosition(proc->anim) == POS_L)
		SetBgOffset(BG_1, 0x18, 0x0);
	else
		SetBgOffset(BG_1, 0xE8, 0x0);
}

void EfxFireHITBG_Loop(struct ProcEfxBG *proc)
{
	int ret = EfxAdvanceFrameLut((i16 *)&proc->timer, (i16 *)&proc->frame, proc->frame_config);

	if (ret >= 0) {
		u16 **buf1 = proc->tsal;
		u16 **buf2 = proc->tsar;

		SpellFx_RegisterBgGfx(proc->img[ret], 0x2000);
		SpellFx_WriteBgMap(proc->anim, buf1[ret], buf2[ret]);
		return;
	}

	if (ret == -1) {
		SpellFx_ClearBG1();
		gEfxBgSemaphore--;
		SpellFx_ClearColorEffects();
		Proc_End(proc);
	}
}

struct ProcScr CONST_DATA ProcScr_EfxElfireBG[] = {
	PROC_NAME_DEBUG("efxElfireBG"),
	PROC_REPEAT(EfxElfireBG_Loop),
	PROC_END,
};

void NewEfxElfireBG(struct Anim *anim)
{
	struct ProcEfxBG *proc;

	gEfxBgSemaphore++;
	proc = SpawnProc(ProcScr_EfxElfireBG, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	SpellFx_RegisterBgGfx(Img_EfxElfireBG, 0x2000);
	SpellFx_WriteBgMap(proc->anim, Tsa_EfxElfireBG, Tsa_EfxElfireBG);
	SpellFx_ClearBG1Position();
	SpellFx_SetSomeColorEffect();

	if (gEkrDistanceType == EKR_DISTANCE_CLOSE)
		return;
	
	if (GetAnimPosition(proc->anim) == POS_L)
		SetBgOffset(BG_1, 0x18, 0x0);
	else
		SetBgOffset(BG_1, 0xE8, 0x0);
	
	func_fe6_0805B0D4(
		gBg1Tm + TM_OFFSET(0x1E, 0x0),
		2, 20,
		BGPAL_EFX_SPELL_BG,
		VRAMOFF_BANIM_SPELL_BG / CHR_SIZE);
}

void EfxElfireBG_Loop(struct ProcEfxBG *proc)
{
	if (++proc->timer == 0x28) {
		SpellFx_ClearBG1();
		SpellFx_ClearColorEffects();
		gEfxBgSemaphore--;
		Proc_Break(proc);
	}
}

struct ProcScr CONST_DATA ProcScr_EfxElfireBGCOL[] = {
	PROC_NAME_DEBUG("efxElfireBGCOL"),
	PROC_MARK(PROC_MARK_PAL_CHG),
	PROC_REPEAT(EfxElfireBGCOL_Loop),
	PROC_END,
};

void NewEfxElfireBGCOL(struct Anim *anim)
{
	static const u16 frame_config[] = {
		0, 2,
		1, 2,
		2, 2,
		3, 2,
		4, 2,
		5, 2,
		6, 2,
		4, 2,
		6, 2,
		4, 2,
		6, 2,
		7, 2,
		8, 1,
		9, 1,
		10, 1,
		11, 1,
		12, 1,
		13, 2,
		14, 2,
		15, 3,
		0, 2,
		-1
	};

	struct ProcEfxBGCOL *proc;

	gEfxBgSemaphore++;
	proc = SpawnProc(ProcScr_EfxElfireBGCOL, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->frame = 0;
	proc->frame_config = frame_config;
	proc->pal = Pal_EfxElfireBGCOL;
	SpellFx_RegisterBgPal(Pal_EfxElfireBGCOL, 0x20);
}

void EfxElfireBGCOL_Loop(struct ProcEfxBGCOL *proc)
{
	int ret = EfxAdvanceFrameLut((i16 *)&proc->timer, (i16 *)&proc->frame, proc->frame_config);

	if (ret >= 0) {
		const u16 *pal = proc->pal;

		SpellFx_RegisterBgPal(pal + PAL_OFFSET(ret), 0x20);
		return;
	}

	if (ret == -1) {
		gEfxBgSemaphore--;
		Proc_Break(proc);
	}
}

struct ProcScr CONST_DATA ProcScr_EfxElfireOBJ[] = {
	PROC_NAME_DEBUG("efxElfireOBJ"),
	PROC_REPEAT(EfxElfireOBJ_Loop),
	PROC_END,
};

void NewEfxElfireOBJ(struct Anim *anim)
{
	struct Anim *anim2;
	struct ProcEfxOBJ *proc;

	gEfxBgSemaphore++;
	proc = SpawnProc(ProcScr_EfxElfireOBJ, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	anim2 = EfxCreateFrontAnim(anim, AnimScr_EfxElfireOBJ_L, AnimScr_EfxElfireOBJ_R, AnimScr_EfxElfireOBJ_L, AnimScr_EfxElfireOBJ_R);
	proc->anim2 = anim2;

	if (GetAnimPosition(anim) == POS_L)
		anim2->xPosition = anim2->xPosition - 0x8;
	else
		anim2->xPosition = anim2->xPosition + 0x8;
	
	anim2->oam01 = anim2->oam01 | OAM1_AFFINE_ID(2);

	SpellFx_RegisterObjPal(Pal_EfxElfireOBJ, 0x20);
	SpellFx_RegisterObjGfx(Img_EfxElfireOBJ, 0x800);
}

void EfxElfireOBJ_Loop(struct ProcEfxOBJ *proc)
{
	if (++proc->timer > 0x28) {
		BasRemove(proc->anim2);
		gEfxBgSemaphore--;
		Proc_Break(proc);
	}
}

/**
 * Fimbulvetr
 */
struct ProcScr CONST_DATA ProcScr_EfxFimbulvetr[] =
{
	PROC_NAME_DEBUG("efxFimbulvetr"),
	PROC_REPEAT(EfxFimbulvetr_Loop),
	PROC_END,
};

struct ProcScr CONST_DATA ProcScr_EfxFimbulvetrBGTR[] = {
	PROC_NAME_DEBUG("efxFimbulvetrBGTR"),
	PROC_REPEAT(EfxFimbulvetrBGTR_Loop),
	PROC_END,
};

CONST_DATA u16 *TsaArray_EfxFimbulvetrBGTR[] = {
	Tsa_EfxFimbulvetrBGTR_081521E0,
	Tsa_EfxFimbulvetrBGTR_081523CC,
	Tsa_EfxFimbulvetrBGTR_081525A4,
	Tsa_EfxFimbulvetrBGTR_0815276C,
	Tsa_EfxFimbulvetrBGTR_081529A0,
	Tsa_EfxFimbulvetrBGTR_08152BE8,
};

CONST_DATA u16 *ImgArray_EfxFimbulvetrBGTR[] = {
	Img_EfxFimbulvetrBGTR_0814B39C,
	Img_EfxFimbulvetrBGTR_0814C5A4,
	Img_EfxFimbulvetrBGTR_0814D700,
	Img_EfxFimbulvetrBGTR_0814E784,
	Img_EfxFimbulvetrBGTR_0814FBC4,
	Img_EfxFimbulvetrBGTR_08150F7C,
};

struct ProcScr CONST_DATA ProcScr_EfxFimbulvetrBG[] = {
	PROC_NAME_DEBUG("efxFimbulvetrBG"),
	PROC_REPEAT(EfxFimbulvetrBG_Loop),
	PROC_END,
};

CONST_DATA u16 *TsaArray_EfxFimbulvetrBG[] = {
	Tsa_EfxFimbulvetrBG_0814A4B8,
	Tsa_EfxFimbulvetrBG_0814A55C,
	Tsa_EfxFimbulvetrBG_0814A604,
	Tsa_EfxFimbulvetrBG_0814A6C0,
	Tsa_EfxFimbulvetrBG_0814A794,
	Tsa_EfxFimbulvetrBG_0814A890,
	Tsa_EfxFimbulvetrBG_0814A9D0,
	Tsa_EfxFimbulvetrBG_0814AB68,
	Tsa_EfxFimbulvetrBG_0814AD3C,
	Tsa_EfxFimbulvetrBG_0814AF4C,
	Tsa_EfxFimbulvetrBG_0814B16C,
};

CONST_DATA u16 *ImgArray_EfxFimbulvetrBG[] = {
	Img_EfxFimbulvetrBG_08144A20,
	Img_EfxFimbulvetrBG_08144A20,
	Img_EfxFimbulvetrBG_08144A20,
	Img_EfxFimbulvetrBG_08144A20,
	Img_EfxFimbulvetrBG_08144A20,
	Img_EfxFimbulvetrBG_08144A20,
	Img_EfxFimbulvetrBG_08145CF0,
	Img_EfxFimbulvetrBG_08145CF0,
	Img_EfxFimbulvetrBG_081475A0,
	Img_EfxFimbulvetrBG_081489E4,
	Img_EfxFimbulvetrBG_081489E4,
};

struct ProcScr CONST_DATA ProcScr_EfxFimbulvetrOBJ[] = {
	PROC_NAME_DEBUG("efxFimbulvetrOBJ"),
	PROC_REPEAT(EfxFimbulvetrOBJ_Loop),
	PROC_END,
};

struct ProcScr CONST_DATA ProcScr_EfxFimbulvetrOBJ2[] = {
	PROC_NAME_DEBUG("efxFimbulvetrOBJ2"),
	PROC_REPEAT(EfxFimbulvetrOBJ2_Loop),
	PROC_END,
};

struct ProcScr CONST_DATA ProcScr_EfxFimbulvetrOBJ2Fall[] = {
	PROC_NAME_DEBUG("efxFimbulvetrOBJ2Fall"),
	PROC_REPEAT(EfxFimbulvetrOBJ2Fall_Loop),
	PROC_END,
};

void StartSpellAnimFimbulvetr(struct Anim *anim)
{
	struct ProcEfx *proc;

	SpellFx_Begin();
	NewEfxSpellCast();

	SpellFx_ClearBG1Position();

	proc = SpawnProc(ProcScr_EfxFimbulvetr, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->hitted = CheckRoundMiss(GetAnimRoundTypeAnotherSide(anim));
}

void EfxFimbulvetr_Loop(struct ProcEfx *proc)
{
	struct Anim *anim = GetAnimAnotherSide(proc->anim);
	int duration = EfxGetCamMovDuration();

	proc->timer++;

	if (proc->timer == 1)
		NewEfxFarAttackWithDistance(proc->anim, -1);

	if (proc->timer == duration + 1) {
		NewEfxFimbulvetrBGTR(anim);
		NewEfxFimbulvetrOBJ2(anim);
		SetBlendAlpha(0, 16);
		NewEfxALPHA(anim, 0, 16, 0, 16, 0);
		PlaySFX(0x122, 0x100, anim->xPosition, 1);

		// return;
	}

	if (proc->timer == duration + 82) {
		NewEfxFlashBgWhite(proc->anim, 4);
		return;
	}

	if (proc->timer == duration + 85) {
		NewEfxFimbulvetrBG(anim);
		NewEfxFimbulvetrOBJ(anim);
		NewEfxALPHA(anim, 24, 16, 16, 0, 0);
		PlaySFX(0x123, 0x100, anim->xPosition, 1);
		return;
	}

	if (proc->timer == duration + 88) {
		anim->flags3 |= (ANIM_BIT3_C02_BLOCK_END | ANIM_BIT3_C01_BLOCK_END_INBATTLE);
		StartBattleAnimHitEffectsDefault(anim, proc->hitted);

		if (!proc->hitted)
			EfxPlayHittedSFX(anim);

		return;
	}

	if ((proc->timer != duration + 136) && (proc->timer == duration + 161)) {
		SpellFx_Finish();
		EndEfxSpellCastAsync();
		Proc_Break(proc);
		return;
	}
}

void NewEfxFimbulvetrBGTR(struct Anim *anim)
{
	struct ProcEfxBG *proc;

	static const u16 frames[] = {
		 0, 3,
		 1, 3,
		 2, 3,
		 0, 3,
		 1, 3,
		 2, 3,
		 0, 3,
		 1, 3,
		 2, 3,
		 0, 3,
		 1, 3,
		 2, 3,
		 0, 3,
		 1, 3,
		 2, 3,
		 0, 3,
		 1, 3,
		 2, 3,
		 0, 3,
		 1, 3,
		 2, 3,
		 0, 3,
		 1, 3,
		 2, 3,
		 3, 3,
		 4, 3,
		 5, 3,
		-1,
	};

	gEfxBgSemaphore++;

	proc = SpawnProc(ProcScr_EfxFimbulvetrBGTR, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->frame = 0;
	proc->frame_config = frames;
	proc->tsal = TsaArray_EfxFimbulvetrBGTR;
	proc->tsar = TsaArray_EfxFimbulvetrBGTR;
	proc->img = ImgArray_EfxFimbulvetrBGTR;

	SpellFx_RegisterBgPal(Pal_EfxFimbulvetrBGTR, PLTT_SIZE_4BPP);

	if (gEkrDistanceType != EKR_DISTANCE_CLOSE) {
		if (GetAnimPosition(proc->anim) == POS_L)
			SetBgOffset(BG_1, 0x18, 0);
		else
			SetBgOffset(BG_1, 0xE8, 0);
	}

	SpellFx_SetSomeColorEffect();
}

void EfxFimbulvetrBGTR_Loop(struct ProcEfxBG *proc)
{
	int ret = EfxAdvanceFrameLut((i16 *)&proc->timer, (i16 *)&proc->frame, proc->frame_config);

	if (ret >= 0) {
		u16 **tsaL = proc->tsal;
		u16 **tsaR = proc->tsar;
		u16 **img = proc->img;

		SpellFx_WriteBgMap(proc->anim, *(tsaL + ret), *(tsaR + ret));
		SpellFx_RegisterBgGfx(*(img + ret), 32 * 8 * CHR_SIZE);
		return;
	}

	if (ret == -1) {
		SpellFx_ClearBG1();
		gEfxBgSemaphore--;
		SpellFx_ClearColorEffects();
		Proc_Break(proc);
		return;
	}
}

void NewEfxFimbulvetrBG(struct Anim *anim)
{
	struct ProcEfxBG *proc;

	// clang-format off
	static const u16 frames[] =
	{
		 0,  1,
		 1,  1,
		 2,  1,
		 3,  1,
		 4,  1,
		 5,  1,
		 6,  1,
		 7,  1,
		 8,  1,
		 9,  1,
		10, 30,
		-1,
	};
	// clang-format on

	gEfxBgSemaphore++;

	proc = SpawnProc(ProcScr_EfxFimbulvetrBG, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->frame = 0;
	proc->frame_config = frames;
	proc->tsal = TsaArray_EfxFimbulvetrBG;
	proc->tsar = TsaArray_EfxFimbulvetrBG;
	proc->img = ImgArray_EfxFimbulvetrBG;

	SpellFx_RegisterBgPal(Pal_EfxFimbulvetrBG, PLTT_SIZE_4BPP);

	if (gEkrDistanceType != EKR_DISTANCE_CLOSE) {
		if (GetAnimPosition(proc->anim) == POS_L)
			SetBgOffset(BG_1, 0x18, 0);
		else
			SetBgOffset(BG_1, 0xE8, 0);
	}

	SpellFx_SetSomeColorEffect();
}

void EfxFimbulvetrBG_Loop(struct ProcEfxBG *proc)
{
	int ret;

	ret = EfxAdvanceFrameLut((i16 *)&proc->timer, (i16 *)&proc->frame, proc->frame_config);

	if (ret >= 0) {
		u16 **tsaL = proc->tsal;
		u16 **tsaR = proc->tsar;
		u16 **img = proc->img;

		SpellFx_WriteBgMap(proc->anim, *(tsaL + ret), *(tsaR + ret));
		SpellFx_RegisterBgGfx(*(img + ret), 32 * 8 * CHR_SIZE);
		return;
	}

	if (ret == -1) {
		SpellFx_ClearBG1();
		gEfxBgSemaphore--;
		SpellFx_ClearColorEffects();
		Proc_Break(proc);
		return;
	}
}

void NewEfxFimbulvetrOBJ(struct Anim *anim)
{
	struct ProcEfxOBJ *proc;

	gEfxBgSemaphore++;

	proc = SpawnProc(ProcScr_EfxFimbulvetrOBJ, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;

	proc->anim2 = EfxCreateFrontAnim(anim, AnimScr_EfxFimbulvetrOBJ1, AnimScr_EfxFimbulvetrOBJ1, AnimScr_EfxFimbulvetrOBJ1, AnimScr_EfxFimbulvetrOBJ1);
	proc->anim2->xPosition += 24;

	SpellFx_RegisterObjPal(Pal_EfxFimbulvetrOBJ, PLTT_SIZE_4BPP);
	SpellFx_RegisterObjGfx(Img_EfxFimbulvetrOBJ, 32 * 4 * CHR_SIZE);
}

void EfxFimbulvetrOBJ_Loop(struct ProcEfxOBJ *proc)
{
	proc->timer++;

	if (proc->timer > 51) {
		BasRemove(proc->anim2);
		gEfxBgSemaphore--;
		Proc_Break(proc);
	}
}

void NewEfxFimbulvetrOBJ2(struct Anim *anim)
{
	struct ProcEfxOBJ *proc;

	gEfxBgSemaphore++;

	proc = SpawnProc(ProcScr_EfxFimbulvetrOBJ2, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->terminator = 0;
	proc->unk44 = 1;
	proc->unk48 = 0;

	SpellFx_RegisterObjPal(Pal_EfxFimbulvetrOBJ, PLTT_SIZE_4BPP);
	SpellFx_RegisterObjGfx(Img_EfxFimbulvetrOBJ, 32 * 4 * CHR_SIZE);
}

void EfxFimbulvetrOBJ2_Loop(struct ProcEfxOBJ *proc)
{
	int i;

	for (i = 0; i < 32; i++)
		NewEfxFimbulvetrOBJ2Fall(proc->anim, i);

	gEfxBgSemaphore--;
	Proc_Break(proc);
}

void NewEfxFimbulvetrOBJ2Fall(struct Anim *anim, int unk)
{
	struct ProcEfxOBJ *proc;
	struct Anim *anim2;

	u8 array[8] = { 0, 0, 0, 0, 0, 0, 1, 1 };

	gEfxBgSemaphore++;

	proc = SpawnProc(ProcScr_EfxFimbulvetrOBJ2Fall, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->terminator = 100;
	proc->unk29 = array[unk & 7];

	anim2 = BasCreate(AnimScr_EfxFimbulvetrOBJ2Fall, 120);
	proc->anim2 = anim2;
	anim2->oam2 = OAM2_CHR(0x40) + OAM2_LAYER(2) + OAM2_PAL(2);
	anim2->xPosition = 256;
	anim2->yPosition = 256;

	proc->unk32 = BanimSpawnRandB(UINT16_MAX);
	proc->unk3A = BanimSpawnRandB(UINT16_MAX);

	if (array[unk & 7] == 0)
		proc->unk34 = (BanimSpawnRandB(UINT16_MAX) & 0x1FF) + 0x700;
	else
		proc->unk34 = (BanimSpawnRandB(UINT16_MAX) & 0x1FF) + 0xa00;

	proc->unk3C = (BanimSpawnRandB(UINT16_MAX - 240) & 0x3FF) - 0x100;
	proc->unk36 = BanimSpawnRandB(UINT16_MAX - 240);
	proc->unk3E = BanimSpawnRandB(UINT16_MAX - 240);

	if (array[unk & 7] == 0)
		proc->unk38 = (BanimSpawnRandB(UINT16_MAX - 240) & 0x1FF) + 0x700;
	else
		proc->unk38 = (BanimSpawnRandB(UINT16_MAX - 240) & 0x1FF) + 0xa00;

	proc->unk40 = (BanimSpawnRandB(UINT16_MAX - 240) & 0x3FF) - 0x100;
}

void EfxFimbulvetrOBJ2Fall_Loop(struct ProcEfxOBJ *proc)
{
	struct Anim *anim = proc->anim2;

	proc->timer++;

	if (proc->timer > proc->terminator) {
		gEfxBgSemaphore--;
		BasRemove(anim);
		Proc_Break(proc);
		return;
	}

	if (!(proc->timer & 1)) {
		if (proc->unk29 == 0) {
			anim->script = AnimScr_FimbulvetrOBJ2Fall_TypeA;
			anim->scrCur = AnimScr_FimbulvetrOBJ2Fall_TypeA;
		} else {
			anim->script = AnimScr_FimbulvetrOBJ2Fall_TypeB;
			anim->scrCur = AnimScr_FimbulvetrOBJ2Fall_TypeB;
		}

		anim->timer = 0;

		proc->unk32 += proc->unk34;
		proc->unk3A += proc->unk3C;
		anim->xPosition = proc->unk32 >> 8;
		anim->yPosition = proc->unk3A >> 8;
	} else {
		if (proc->unk29 == 0) {
			anim->script = AnimScr_FimbulvetrOBJ2Fall_TypeA;
			anim->scrCur = AnimScr_FimbulvetrOBJ2Fall_TypeA;
		} else {
			anim->script = AnimScr_FimbulvetrOBJ2Fall_TypeB;
			anim->scrCur = AnimScr_FimbulvetrOBJ2Fall_TypeB;
		}

		anim->timer = 0;

		proc->unk3E += proc->unk38;
		proc->unk3E += proc->unk40;
		anim->xPosition = proc->unk36 >> 8;
		anim->yPosition = proc->unk3E >> 8;
	}
}

/**
 * Bloting
 */
struct ProcScr CONST_DATA ProcScr_EfxThunderstorm[] = {
	PROC_NAME_DEBUG("efxThunderstorm"),
	PROC_REPEAT(EfxThunderstorm_Loop),
	PROC_END,
};

struct ProcScr CONST_DATA ProcScr_EfxThunderstormBG[] = {
	PROC_NAME_DEBUG("efxThunderstormBG"),
	PROC_REPEAT(EfxThunderstormBG_Loop),
	PROC_END,
};

CONST_DATA u16 *ImgArray_EfxThunderstormBG[] = {
	Img_EfxThunderstormBG_0813BD94,
	Img_EfxThunderstormBG_0813BD94,
	Img_EfxThunderstormBG_0813BD94,
	Img_EfxThunderstormBG_0813BD94,
	Img_EfxThunderstormBG_0813C964,
	Img_EfxThunderstormBG_0813C964,
	Img_EfxThunderstormBG_0813C964,
	Img_EfxThunderstormBG_0813C964,
	Img_EfxThunderstormBG_0813C964,
	Img_EfxThunderstormBG_0813C964,
	Img_EfxThunderstormBG_0813D9D0,
};

CONST_DATA u16 *TsaArray_EfxThunderstormBG[] = {
	Tsa_EfxThunderstormBG_0813E7BC,
	Tsa_EfxThunderstormBG_0813E950,
	Tsa_EfxThunderstormBG_0813EB58,
	Tsa_EfxThunderstormBG_0813ECBC,
	Tsa_EfxThunderstormBG_0813ED9C,
	Tsa_EfxThunderstormBG_0813EEB4,
	Tsa_EfxThunderstormBG_0813F060,
	Tsa_EfxThunderstormBG_0813F180,
	Tsa_EfxThunderstormBG_0813F26C,
	Tsa_EfxThunderstormBG_0813F354,
	Tsa_EfxThunderstormBG_0813F3EC,
};

struct ProcScr CONST_DATA ProcScr_EfxThunderstormOBJ[] = {
	PROC_NAME_DEBUG("efxThunderstormOBJ"),
	PROC_REPEAT(EfxThunderstormOBJ_Loop),
	PROC_SLEEP(100),
	PROC_REPEAT(EfxThunderstormOBJ_End),
	PROC_END,
};

struct ProcScr CONST_DATA ProcScr_EfxThunderstormCOLOR[] = {
	PROC_NAME_DEBUG("efxThunderstormCOLOR"),
	PROC_SLEEP(94),
	PROC_REPEAT(EfxThunderstormCOLOR_LoopA),
	PROC_SLEEP(3),
	PROC_REPEAT(EfxThunderstormCOLOR_LoopB),
	PROC_SLEEP(20),
	PROC_REPEAT(EfxThunderstormCOLOR_LoopC),
	PROC_END,
};

struct ProcScr CONST_DATA ProcScr_EfxThunderstormDARK[] = {
	PROC_NAME_DEBUG("efxThunderstormDARK"),
	PROC_REPEAT(EfxThunderstormDARK_LoopA),
	PROC_REPEAT(EfxThunderstormDARK_LoopB),
	PROC_END,
};

void StartSpellAnimBolting(struct Anim *anim)
{
	struct ProcEfx *proc;

	SpellFx_Begin();
	NewEfxSpellCast();
	SpellFx_ClearBG1Position();

	proc = SpawnProc(ProcScr_EfxThunderstorm, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->hitted = CheckRoundMiss(GetAnimRoundTypeAnotherSide(anim));
}

void EfxThunderstorm_Loop(struct ProcEfx *proc)
{
	struct Anim *anim = GetAnimAnotherSide(proc->anim);

	int duration = EfxGetCamMovDuration();

	proc->timer++;

	if (proc->timer == 1)
		NewEfxFarAttackWithDistance(proc->anim, -1);

	if (proc->timer == duration + 1) {
		PlaySFX(0x119, 0x100, anim->xPosition, 1);
		NewEfxThunderstormBG(anim);
		NewEfxThunderstormCOLOR(anim);
	}

	if (proc->timer == duration + 89)
		NewEfxThunderstormDARK(anim, 2, 3);

	if (proc->timer == duration + 94) {
		NewEfxThunderstormOBJ(anim);

		anim->flags3 |= (ANIM_BIT3_C02_BLOCK_END | ANIM_BIT3_C01_BLOCK_END_INBATTLE);
		StartBattleAnimHitEffectsDefault(anim, proc->hitted);

		if (!proc->hitted)
			EfxPlayHittedSFX(anim);
	} else if ((proc->timer != duration + 195) && (proc->timer == duration + 200)) {
		SpellFx_Finish();
		EndEfxSpellCastAsync();
		Proc_Break(proc);
	}
}

void NewEfxThunderstormBG(struct Anim *anim)
{
	// clang-format off
	static const u16 frames[] =
	{
		 0,  2,
		 1,  2,
		 2,  2,
		 3,  2,
		 7,  8,
		 4,  3,
		 9,  8,
		 7,  1,
		 9,  8,
		 5,  2,
		 9,  8,
		 8,  1,
		 9,  8,
		 6,  2,
		 9,  6,
		 9, 38,
		10, 38,
		-1,
	};
	// clang-format on

	struct ProcEfxBG *proc;

	gEfxBgSemaphore++;

	proc = SpawnProc(ProcScr_EfxThunderstormBG, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->frame = 0;
	proc->frame_config = frames;
	proc->tsal = TsaArray_EfxThunderstormBG;
	proc->tsar = TsaArray_EfxThunderstormBG;
	proc->img = ImgArray_EfxThunderstormBG;

	SpellFx_RegisterBgPal(Pal_EfxThunderstormBG, PLTT_SIZE_4BPP);
	SpellFx_SetSomeColorEffect();
}

void EfxThunderstormBG_Loop(struct ProcEfxBG *proc)
{
	int ret = EfxAdvanceFrameLut((i16 *)&proc->timer, (i16 *)&proc->frame, proc->frame_config);

	if (ret >= 0) {
		u16 **tsaL = proc->tsal;
		u16 **tsaR = proc->tsar;
		u16 **img = proc->img;

		SpellFx_RegisterBgGfx(*(img + ret), 32 * 8 * CHR_SIZE);
		SpellFx_WriteBgMap(proc->anim, *(tsaL + ret), *(tsaR + ret));
		return;
	}

	if (ret == -1) {
		gEfxBgSemaphore--;
		Proc_End(proc);
		return;
	}
}

void NewEfxThunderstormOBJ(struct Anim *anim)
{
	struct ProcEfxOBJ *proc;

	gEfxBgSemaphore++;

	proc = SpawnProc(ProcScr_EfxThunderstormOBJ, PROC_TREE_3);
	proc->anim = anim;
}

void EfxThunderstormOBJ_Loop(struct ProcEfxOBJ *proc)
{
	proc->anim2 = EfxCreateFrontAnim(proc->anim, AnimScr_EfxThunderstormOBJ, AnimScr_EfxThunderstormOBJ, AnimScr_EfxThunderstormOBJ, AnimScr_EfxThunderstormOBJ);

	SpellFx_RegisterObjPal(Pal_EfxThunderOBJ, PLTT_SIZE_4BPP);
	SpellFx_RegisterObjGfx(Img_EfxThunderOBJ, 32 * 4 * CHR_SIZE);

	Proc_Break(proc);
}

void EfxThunderstormOBJ_End(struct ProcEfxOBJ *proc)
{
	BasRemove(proc->anim2);

	gEfxBgSemaphore--;
	Proc_Break(proc);
}

void NewEfxThunderstormCOLOR(struct Anim *anim)
{
	struct ProcEfxBGCOL *proc;

	gEfxBgSemaphore++;

	proc = SpawnProc(ProcScr_EfxThunderstormCOLOR, PROC_TREE_3);
	proc->anim = anim;
}

void EfxThunderstormCOLOR_LoopA(struct ProcEfxBGCOL *proc)
{
	PlaySFX(SONG_11A, 0x100, proc->anim->xPosition, 1);

	NewEfxFlashBgWhite(proc->anim, 38);

	proc->timer = 0;
	proc->timer2 = 5;

	Proc_Break(proc);
}

void EfxThunderstormCOLOR_LoopB(struct ProcEfxBGCOL *proc)
{
	int ret = Interpolate(INTERPOLATE_LINEAR, 16, 0, proc->timer, proc->timer2);

	CpuFastCopy(gPal, gEfxPal, PLTT_SIZE);

	EfxPalWhiteInOut(gEfxPal, 0, 32, ret);

	proc->timer++;

	if (proc->timer > proc->timer2) {
		proc->timer = 0;
		proc->timer2 = 10;
		Proc_Break(proc);
	}
}

void EfxThunderstormCOLOR_LoopC(struct ProcEfxBGCOL *proc)
{
	int ret = Interpolate(INTERPOLATE_LINEAR, 16, 0, proc->timer, proc->timer2);
	SetBlendAlpha(ret, 16);

	proc->timer++;

	if (proc->timer > proc->timer2) {
		SpellFx_ClearBG1();
		SpellFx_ClearColorEffects();

		gEfxBgSemaphore--;

		Proc_Break(proc);
	}
}

void NewEfxThunderstormDARK(struct Anim *anim, int timer, int terminator)
{
	struct ProcEfxBGCOL *proc;

	gEfxBgSemaphore++;

	CpuFastCopy(gPal, gEfxPal, PLTT_SIZE);

	proc = SpawnProc(ProcScr_EfxThunderstormDARK, 0);
	proc->anim = anim;
	proc->timer = 0;
	proc->timer2 = timer;
	proc->terminator = terminator;
}

void EfxThunderstormDARK_LoopA(struct ProcEfxBGCOL *proc)
{
	int ret = Interpolate(INTERPOLATE_LINEAR, 0, 16, proc->timer, proc->timer2);

	EfxPalBlackInOut(gEfxPal, 0, 32, ret);
	CpuFastCopy(gEfxPal, (u16 *)PLTT, PLTT_SIZE);
	DisablePalSync();

	proc->timer++;

	if (proc->timer > proc->timer2) {
		proc->timer = 0;
		Proc_Break(proc);
	}
}

void EfxThunderstormDARK_LoopB(struct ProcEfxBGCOL *proc)
{
	CpuFastCopy(gEfxPal, (u16 *)PLTT, PLTT_SIZE);
	DisablePalSync();

	proc->timer++;

	if (proc->timer > proc->terminator) {
		gEfxBgSemaphore--;
		Proc_Break(proc);
	}
}

/**
 * Ex-calibur
 */
struct ProcScr CONST_DATA ProcScr_EfxAlacalibur[] = {
	PROC_NAME_DEBUG("efxAlacalibur"),
	PROC_REPEAT(EfxAlacalibur_Loop),
	PROC_END,
};

struct ProcScr CONST_DATA ProcScr_EfxAlacaliburBG[] = {
	PROC_NAME_DEBUG("efxAlacaliburBG"),
	PROC_REPEAT(EfxAlacaliburBG_Loop),
	PROC_END,
};

CONST_DATA u16 *TsaArray_EfxAlacaliburBG[] = {
	Tsa_EfxAlacaliburBG_0815B424,
	Tsa_EfxAlacaliburBG_0815B5AC,
};

struct ProcScr CONST_DATA ProcScr_EfxAlacaliburBGCOL[] = {
	PROC_NAME_DEBUG("efxAlacaliburBGCOL"),
	PROC_MARK(PROC_MARK_PAL_CHG),
	PROC_REPEAT(EfxAlacaliburBGCOL_Loop),
	PROC_END,
};

struct ProcScr CONST_DATA ProcScr_EfxAlacaliburOBJ[] = {
	PROC_NAME_DEBUG("efxAlacaliburOBJ"),
	PROC_REPEAT(EfxAlacaliburOBJ_Loop),
	PROC_END,
};

void StartSpellAnimAircalibur(struct Anim *anim)
{
	struct ProcEfx *proc;

	SpellFx_Begin();
	NewEfxSpellCast();
	SpellFx_ClearBG1Position();

	proc = SpawnProc(ProcScr_EfxAlacalibur, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;

	proc->hitted = CheckRoundMiss(GetAnimRoundTypeAnotherSide(anim));
}

void EfxAlacalibur_Loop(struct ProcEfx *proc)
{
	int time;
	struct Anim *anim = GetAnimAnotherSide(proc->anim);
	int duration = EfxGetCamMovDuration();

	time = (gEkrDistanceType != 0) ? 50 : 58;
	proc->timer++;

	if (proc->timer == 1) {
		NewEfxAlacaliburOBJ(proc->anim);
		PlaySFX(SONG_108, 0x100, proc->anim->xPosition, 1);
		NewEfxFarAttackWithDistance(proc->anim, -1);
		return;
	}

	if (proc->timer == time + duration) {
		NewEfxFlashBgWhite(proc->anim, 6);
		return;
	}

	if (proc->timer == time + 6 + duration) {
		NewEfxAlacaliburBG(anim);
		NewEfxAlacaliburBGCOL(anim);

		NewEfxALPHA(anim, 6, 5, 16, 0, 0);
		PlaySFX(SONG_109, 0x100, anim->xPosition, 1);
		return;
	}

	if (proc->timer == time + 8 + duration) {
		anim->flags3 |= (ANIM_BIT3_C02_BLOCK_END | ANIM_BIT3_C01_BLOCK_END_INBATTLE);
		StartBattleAnimHitEffectsDefault(anim, proc->hitted);

		if (!proc->hitted)
			EfxPlayHittedSFX(anim);

		return;
	}

	if ((proc->timer != time + 12 + duration) && (proc->timer == time + 14 + duration)) {
		SpellFx_Finish();
		EndEfxSpellCastAsync();
		Proc_Break(proc);
		return;
	}
}

void NewEfxAlacaliburBG(struct Anim *anim)
{
	static const u16 frames[] = {
		0, 2,
		1, 9,
		-1,
	};

	struct ProcEfxBG *proc;

	gEfxBgSemaphore++;

	proc = SpawnProc(ProcScr_EfxAlacaliburBG, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->frame = 0;
	proc->frame_config = frames;
	proc->tsal = TsaArray_EfxAlacaliburBG;

	SpellFx_RegisterBgGfx(Img_EfxAlacaliburBG, 0x2000);
	SpellFx_SetSomeColorEffect();

	if (GetAnimPosition(proc->anim) == 0)
		SetBgOffset(BG_1, 0x18, 0);
	else
		SetBgOffset(BG_1, 0xE8, 0);
}

void EfxAlacaliburBG_Loop(struct ProcEfxBG *proc)
{
	int ret = EfxAdvanceFrameLut((i16 *)&proc->timer, (i16 *)&proc->frame, proc->frame_config);

	if (ret >= 0) {
		u16 **tsa = proc->tsal;

		SpellFx_WriteBgMapExt(proc->anim, *(tsa + ret), 32, 20);
		return;
	}

	if (ret == -1) {
		SpellFx_ClearBG1();
		gEfxBgSemaphore--;
		SpellFx_ClearColorEffects();
		Proc_Break(proc);
		return;
	}
}

void NewEfxAlacaliburBGCOL(struct Anim *anim)
{
	static const u16 frames[] = {
		2, 1,
		3, 1,
		4, 1,
		5, 1,
		0, 5,
		1, 2,
		-1,
	};

	struct ProcEfxBGCOL *proc;

	gEfxBgSemaphore++;

	proc = SpawnProc(ProcScr_EfxAlacaliburBGCOL, PROC_TREE_3);

	proc->anim = anim;
	proc->timer = 0;
	proc->timer2 = 0;
	proc->frame = 0;
	proc->frame_config = frames;
	proc->pal = Pal_EfxAlacaliburBGCOL;

	SpellFx_RegisterBgPal(Pal_EfxAlacaliburBGCOL, 0x20);
}

void EfxAlacaliburBGCOL_Loop(struct ProcEfxBGCOL *proc)
{
	int ret = EfxAdvanceFrameLut((s16 *)&proc->timer, (s16 *)&proc->frame, proc->frame_config);

	if (ret >= 0) {
		const u16 *pal = proc->pal;

		SpellFx_RegisterBgPal((pal + (ret * 0x10)), 0x20);
		return;
	}

	if (ret == -1) {
		gEfxBgSemaphore--;
		Proc_Break(proc);
		return;
	}
}

void NewEfxAlacaliburOBJ(struct Anim *anim)
{
	struct ProcEfxOBJ *proc;
	struct Anim * frontAnim;

	gEfxBgSemaphore++;

	proc = SpawnProc(ProcScr_EfxAlacaliburOBJ, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	frontAnim = EfxCreateFrontAnim(anim, AnimScr_EfxAlacaliburOBJ_LF, AnimScr_EfxAlacaliburOBJ_RF, AnimScr_EfxAlacaliburOBJ_LB, AnimScr_EfxAlacaliburOBJ_RB);
	proc->anim2 = frontAnim;

	if (GetAnimPosition(anim) == 0)
		frontAnim->xPosition += 72;
	else
		frontAnim->xPosition -= 72;

	proc->terminator = 96;

	SpellFx_RegisterObjPal(Pal_EfxAlacaliburOBJ, 0x20);
	SpellFx_RegisterObjGfx(Img_EfxAlacaliburOBJ, 0x1000);
}

void EfxAlacaliburOBJ_Loop(struct ProcEfxOBJ *proc)
{
	proc->timer++;

	if (proc->timer == proc->terminator) {
		gEfxBgSemaphore--;
		Proc_Break(proc);
	}
}

/**
 * Flux
 */
struct ProcScr CONST_DATA ProcScr_EfxMistyrain[] = {
	PROC_NAME_DEBUG("efxMistyrain"),
	PROC_REPEAT(EfxMistyrain_Loop),
	PROC_END,
};

struct ProcScr CONST_DATA ProcScr_EfxMistyrainBG[] = {
	PROC_NAME_DEBUG("efxMistyrainBG"),
	PROC_REPEAT(NewEfxMistyrainBG_Loop),
	PROC_END,
};

CONST_DATA u16 *TsaArray_EfxMistyrainBG[] = {
	Tsa_EfxMistyrainBG_0815F8C0,
	Tsa_EfxMistyrainBG_0815F9BC,
	Tsa_EfxMistyrainBG_0815FABC,
	Tsa_EfxMistyrainBG_0815FBC0,
	Tsa_EfxMistyrainBG_0815FCB8,
	Tsa_EfxMistyrainBG_0815FDC4,
	Tsa_EfxMistyrainBG_0815FED0,
	Tsa_EfxMistyrainBG_0815FFF0,
	Tsa_EfxMistyrainBG_08160114,
	Tsa_EfxMistyrainBG_081601FC,
	Tsa_EfxMistyrainBG_081602D8,
	Tsa_EfxMistyrainBG_08160398,
	Tsa_EfxMistyrainBG_08160450,
	Tsa_EfxMistyrainBG_081604F8,
	Tsa_EfxMistyrainBG_081605B4,
	Tsa_EfxMistyrainBG_0816068C,
	Tsa_EfxMistyrainBG_0816076C,
	Tsa_EfxMistyrainBG_0816085C,
	Tsa_EfxMistyrainBG_08160958,
	Tsa_EfxMistyrainBG_08160A4C,
	Tsa_EfxMistyrainBG_08160B44,
	Tsa_EfxMistyrainBG_08160C30,
	Tsa_EfxMistyrainBG_08160D14,
	Tsa_EfxMistyrainBG_08160DEC,
	Tsa_EfxMistyrainBG_08160EBC,
	Tsa_EfxMistyrainBG_08160F88,
	Tsa_EfxMistyrainBG_08161050,
	Tsa_EfxMistyrainBG_08161104,
	Tsa_EfxMistyrainBG_081611B8,
	Tsa_EfxMistyrainBG_08161258,
	Tsa_EfxMistyrainBG_0816130C,
	Tsa_EfxMistyrainBG_081613C8,
	Tsa_EfxMistyrainBG_081614A4,
	Tsa_EfxMistyrainBG_0816158C,
	Tsa_EfxMistyrainBG_081616B0,
	Tsa_EfxMistyrainBG_081617D0,
	Tsa_EfxMistyrainBG_081618DC,
	Tsa_EfxMistyrainBG_081619E8,
	Tsa_EfxMistyrainBG_08161AE4,
	Tsa_EfxMistyrainBG_08161BE4,
	Tsa_EfxMistyrainBG_08161CE0,
};

CONST_DATA u16 *ImgArray_EfxMistyrainBG[] = {
	Img_EfxMistyrainBG_0815BEF4,
	Img_EfxMistyrainBG_0815BEF4,
	Img_EfxMistyrainBG_0815BEF4,
	Img_EfxMistyrainBG_0815CAC4,
	Img_EfxMistyrainBG_0815CAC4,
	Img_EfxMistyrainBG_0815CAC4,
	Img_EfxMistyrainBG_0815D7D4,
	Img_EfxMistyrainBG_0815D7D4,
	Img_EfxMistyrainBG_0815D7D4,
	Img_EfxMistyrainBG_0815D7D4,
	Img_EfxMistyrainBG_0815D7D4,
	Img_EfxMistyrainBG_0815D7D4,
	Img_EfxMistyrainBG_0815EA30,
	Img_EfxMistyrainBG_0815EA30,
	Img_EfxMistyrainBG_0815EA30,
	Img_EfxMistyrainBG_0815EA30,
	Img_EfxMistyrainBG_0815EA30,
	Img_EfxMistyrainBG_0815EA30,
	Img_EfxMistyrainBG_0815F0B4,
	Img_EfxMistyrainBG_0815F0B4,
	Img_EfxMistyrainBG_0815F0B4,
	Img_EfxMistyrainBG_0815F0B4,
	Img_EfxMistyrainBG_0815F610,
	Img_EfxMistyrainBG_0815F610,
	Img_EfxMistyrainBG_0815F610,
	Img_EfxMistyrainBG_0815F610,
	Img_EfxMistyrainBG_0815F610,
	Img_EfxMistyrainBG_0815F610,
	Img_EfxMistyrainBG_0815F610,
	Img_EfxMistyrainBG_0815D7D4,
	Img_EfxMistyrainBG_0815D7D4,
	Img_EfxMistyrainBG_0815D7D4,
	Img_EfxMistyrainBG_0815D7D4,
	Img_EfxMistyrainBG_0815D7D4,
	Img_EfxMistyrainBG_0815D7D4,
	Img_EfxMistyrainBG_0815CAC4,
	Img_EfxMistyrainBG_0815CAC4,
	Img_EfxMistyrainBG_0815CAC4,
	Img_EfxMistyrainBG_0815BEF4,
	Img_EfxMistyrainBG_0815BEF4,
	Img_EfxMistyrainBG_0815BEF4,
};

struct ProcScr CONST_DATA ProcScr_EfxMistyrainOBJ[] = {
	PROC_NAME_DEBUG("efxMistyrainOBJ"),
	PROC_ONEND(EfxMistyrainOBJ_OnEnd),
	PROC_REPEAT(EfxMistyrainOBJ1_Loop1),
	PROC_SLEEP(80),
	PROC_REPEAT(EfxMistyrainOBJ1_Loop2),
	PROC_SLEEP(11),
	PROC_REPEAT(EfxMistyrainOBJ1_Loop3),
	PROC_SLEEP(22),
	PROC_END,
};

struct ProcScr CONST_DATA ProcScr_EfxMistyrainOBJ2[] = {
	PROC_NAME_DEBUG("efxMistyrainOBJ2"),
	PROC_ONEND(EfxMistyrainOBJ_OnEnd),
	PROC_REPEAT(EfxMistyrainOBJ2_Loop1),
	PROC_SLEEP(14),
	PROC_REPEAT(EfxMistyrainOBJ2_Loop2),
	PROC_END,
};

void StartSpellAnimFlux(struct Anim *anim)
{
	struct ProcEfx *proc;

	SpellFx_Begin();
	NewEfxSpellCast();
	SpellFx_ClearBG1Position();

	proc = SpawnProc(ProcScr_EfxMistyrain, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->hitted = CheckRoundMiss(GetAnimRoundTypeAnotherSide(anim));
}

void EfxMistyrain_Loop(struct ProcEfx *proc)
{
	struct Anim *anim = GetAnimAnotherSide(proc->anim);
	int duration = EfxGetCamMovDuration();

	proc->timer++;

	if (proc->timer == 1) {
		PlaySFX(0x10a, 0x100, proc->anim->xPosition, 1);
		NewEfxMistyrainBG1(anim);
		return;
	}

	if (proc->timer == 24) {
		NewEfxMistyrainOBJ(proc->anim);
		return;
	}

	if (proc->timer == 130) {
		NewEfxFarAttackWithDistance(proc->anim, -1);
		return;
	}

	if (proc->timer == duration + 131) {
		proc->priv2 = NewEfxMistyrainOBJ2(anim);
		return;
	}

	if (proc->timer == duration + 150) {
		PlaySFX(SONG_10B, 0x100, anim->xPosition, 1);
		NewEfxMistyrainBG2(proc->anim);
		return;
	}

	if (proc->timer == duration + 170) {
		Proc_End(proc->priv2);
		return;
	}

	if (proc->timer == duration + 195) {
		NewEfxFlashBgWhite(proc->anim, 6);
		anim->flags3 |= 9;

		StartBattleAnimHitEffectsDefault(anim, proc->hitted);
		if (!proc->hitted)
			EfxPlayHittedSFX(anim);

		return;
	}

	if (proc->timer == duration + 230)
		return;

	if (proc->timer == duration + 240) {
		SpellFx_Finish();
		EndEfxSpellCastAsync();
		Proc_Break(proc);
		return;
	}
}

void NewEfxMistyrainBG1(struct Anim *anim)
{
	static const u16 frames[] = {
		 0, 2,
		 1, 2,
		 2, 2,
		 3, 3,
		 4, 3,
		 5, 3,
		 6, 3,
		 7, 3,
		 8, 3,
		 9, 3,
		10, 3,
		11, 2,
		-1,
	};

	struct ProcEfxBG *proc;

	gEfxBgSemaphore++;

	proc = SpawnProc(ProcScr_EfxMistyrainBG, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->frame = 0;
	proc->frame_config = frames;
	proc->tsar = proc->tsal = TsaArray_EfxMistyrainBG;
	proc->img = ImgArray_EfxMistyrainBG;
	SpellFx_RegisterBgPal(Pal_EfxMistyrainBG1, 0x20);
	SpellFx_SetSomeColorEffect();

	if (gEkrDistanceType != 0) {
		if (GetAnimPosition(proc->anim) == 0)
			SetBgOffset(1, 0xE8, 0);
		else
			SetBgOffset(1, 0x18, 0);
	}

	if (GetAnimPosition(proc->anim) == 0)
		gDispIo.bg_off[1].x += 4;
	else
		gDispIo.bg_off[1].x -= 4;

	gDispIo.bg_off[1].y += 8;
}

void NewEfxMistyrainBG2(struct Anim *anim)
{
	static const u16 frames[] = {
		12, 6,
		13, 3,
		14, 3,
		15, 3,
		16, 3,
		17, 3,
		18, 3,
		19, 3,
		20, 3,
		21, 2,
		22, 2,
		23, 2,
		24, 2,
		25, 2,
		26, 2,
		27, 2,
		28, 2,
		29, 3,
		30, 3,
		31, 3,
		32, 3,
		33, 3,
		34, 3,
		35, 3,
		36, 3,
		37, 3,
		38, 3,
		39, 3,
		40, 3,
		-1
	};

	struct ProcEfxBG *proc;

	gEfxBgSemaphore++;

	proc = SpawnProc(ProcScr_EfxMistyrainBG, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->frame = 0;
	proc->frame_config = frames;
	proc->tsar = proc->tsal = TsaArray_EfxMistyrainBG;
	proc->img = ImgArray_EfxMistyrainBG;

	SpellFx_RegisterBgPal(Pal_EfxMistyrainBG2, 0x20);
	SpellFx_SetSomeColorEffect();

	SetBlendAlpha(10, 7);

	if (gEkrDistanceType != 0) {
		if (GetAnimPosition(proc->anim) == 0)
			SetBgOffset(1, 0xE8, 0);
		else
			SetBgOffset(1, 0x18, 0);
	}
}

void NewEfxMistyrainBG_Loop(struct ProcEfxBG *proc)
{
	int ret = EfxAdvanceFrameLut(&proc->timer, (s16 *)&proc->frame, proc->frame_config);

	if (ret >= 0) {
		u16 **tsaLeft = proc->tsal;
		u16 **tsaRight = proc->tsar;

		SpellFx_RegisterBgGfx(proc->img[ret], 0x2000);
		SpellFx_WriteBgMap(proc->anim, tsaLeft[ret], tsaRight[ret]);
		return;
	}

	if (ret == -1) {
		SpellFx_ClearBG1();
		gEfxBgSemaphore--;
		SpellFx_ClearColorEffects();
		Proc_End(proc);
		return;
	}
}

void NewEfxMistyrainOBJ(struct Anim *anim)
{
	struct ProcEfxOBJ *proc;
	const AnimScr *scr;

	gEfxBgSemaphore++;

	proc = SpawnProc(ProcScr_EfxMistyrainOBJ, PROC_TREE_3);
	proc->anim = anim;

	GetAnimAnotherSide(anim);

	scr = AnimScr_Common;
	proc->anim2 = EfxCreateFrontAnim(proc->anim, scr, scr, scr, scr);
}

struct ProcEfxOBJ * NewEfxMistyrainOBJ2(struct Anim *anim)
{
	struct ProcEfxOBJ *proc;
	u32 * scr;

	gEfxBgSemaphore++;

	proc = SpawnProc(ProcScr_EfxMistyrainOBJ2, PROC_TREE_3);
	proc->anim = anim;
	GetAnimAnotherSide(anim);

	scr = AnimScr_Common;
	proc->anim2 = EfxCreateFrontAnim(proc->anim, scr, scr, scr, scr);
	proc->anim2->yPosition -= 4;

	return proc;
}

void EfxMistyrainOBJ_OnEnd(struct ProcEfxOBJ *proc)
{
	gEfxBgSemaphore--;
	BasRemove(proc->anim2);
}

void EfxMistyrainOBJ1_Loop1(struct ProcEfxOBJ *proc)
{
	proc->anim2->script = AnimScr_EfxMistyrainOBJ1_1;
	proc->anim2->scrCur = AnimScr_EfxMistyrainOBJ1_1;

	proc->anim2->timer = 0;

	SpellFx_RegisterObjPal(Pal_EfxMistyrainOBJ1, 0x20);
	SpellFx_RegisterObjGfx(Img_EfxMistyrainOBJ1_1, 0x1000);

	Proc_Break(proc);
}

void EfxMistyrainOBJ1_Loop2(struct ProcEfxOBJ *proc)
{
	proc->anim2->script = AnimScr_EfxMistyrainOBJ1_2;
	proc->anim2->scrCur = AnimScr_EfxMistyrainOBJ1_2;

	proc->anim2->timer = 0;

	SpellFx_RegisterObjPal(Pal_EfxMistyrainOBJ1, 0x20);
	SpellFx_RegisterObjGfx(Img_EfxMistyrainOBJ1_2, 0x1000);

	Proc_Break(proc);
}

void EfxMistyrainOBJ1_Loop3(struct ProcEfxOBJ *proc)
{
	proc->anim2->script = AnimScr_EfxMistyrainOBJ1_3;
	proc->anim2->scrCur = AnimScr_EfxMistyrainOBJ1_3;

	proc->anim2->timer = 0;

	SpellFx_RegisterObjPal(Pal_EfxMistyrainOBJ1, 0x20);
	SpellFx_RegisterObjGfx(Img_EfxMistyrainOBJ1_3, 0x1000);

	Proc_Break(proc);
}

void EfxMistyrainOBJ2_Loop1(struct ProcEfxOBJ *proc)
{
	struct Anim *anim = proc->anim2;

	anim->script = AnimScr_EfxMistyrainOBJ2_1;
	anim->scrCur = AnimScr_EfxMistyrainOBJ2_1;
	anim->timer = 0;
	anim->priority = 20;

	BasSort();

	proc->timer = 39;
	Proc_Break(proc);
}

void EfxMistyrainOBJ2_Loop2(struct ProcEfxOBJ *proc)
{
	struct Anim *anim = proc->anim2;

	proc->timer++;

	if (proc->timer == 40) {
		anim->script = AnimScr_EfxMistyrainOBJ2_2;
		anim->scrCur = AnimScr_EfxMistyrainOBJ2_2;
		anim->timer = 0;

		proc->timer = 0;
	}
}

/**
 * Nosferatu
 */
struct ProcScr CONST_DATA ProcScr_EfxResire[] = {
	PROC_NAME_DEBUG("efxResire"),
	PROC_REPEAT(EfxResire_Loop),
	PROC_END,
};

struct ProcScr CONST_DATA ProcScr_EfxResireBG[] = {
	PROC_NAME_DEBUG("efxResireBG"),
	PROC_REPEAT(EfxResireBG_Loop1),
	PROC_REPEAT(EfxResireBG_Loop2),
	PROC_REPEAT(EfxResireBG_Loop3),
	PROC_REPEAT(EfxResireBG_Loop4),
	PROC_END,
};

struct ProcScr CONST_DATA ProcScr_EfxResireBG2[] = {
	PROC_NAME_DEBUG("efxResireBG2"),
	PROC_REPEAT(EfxResireBG2_Loop),
	PROC_END,
};

CONST_DATA u16 *ImgArray_EfxResireBG[] = {
	Img_EfxResireBG_081629F4,
	Img_EfxResireBG_081629F4,
	Img_EfxResireBG_081629F4,
	Img_EfxResireBG_081629F4,
	Img_EfxResireBG_081629F4,
	Img_EfxResireBG_081629F4,
	Img_EfxResireBG_081629F4,
	Img_EfxResireBG_081629F4,
	Img_EfxResireBG_081634C4,
	Img_EfxResireBG_081634C4,
	Img_EfxResireBG_081634C4,
	Img_EfxResireBG_0816406C,
	Img_EfxResireBG_0816406C,
	Img_EfxResireBG_08164BC4,
	Img_EfxResireBG_08164BC4,
	Img_EfxResireBG_08165678,
	Img_EfxResireBG_08165678,
	Img_EfxResireBG_08166148,
	Img_EfxResireBG_08166148,
	Img_EfxResireBG_08166148,
	Img_EfxResireBG_08166E0C,
	Img_EfxResireBG_08166E0C,
	Img_EfxResireBG_08166E0C,
	Img_EfxResireBG_08167710,
	Img_EfxResireBG_08167710,
	Img_EfxResireBG_08167710,
	Img_EfxResireBG_08167710,
	Img_EfxResireBG_08167710,
	Img_EfxResireBG_08167C64,
	Img_EfxResireBG_08167C64,
	Img_EfxResireBG_08167C64,
	Img_EfxResireBG_08167C64,
	Img_EfxResireBG_08167C64,
	Img_EfxResireBG_08167C64,
	Img_EfxResireBG_08167C64,
	Img_EfxResireBG_08167C64,
	Img_EfxResireBG_0816857C,
	Img_EfxResireBG_0816857C,
	Img_EfxResireBG_0816857C,
	Img_EfxResireBG_0816857C,
	Img_EfxResireBG_081691B0,
	Img_EfxResireBG_081691B0,
	Img_EfxResireBG_081691B0,
	Img_EfxResireBG_08169E54,
	Img_EfxResireBG_08169E54,
	Img_EfxResireBG_08169E54,
	Img_EfxResireBG_0816AA48,
	Img_EfxResireBG_0816AA48,
	Img_EfxResireBG_0816AA48,
	Img_EfxResireBG_0816AA48,
	Img_EfxResireBG_0816AA48,
};

CONST_DATA u16 *TsaArray_EfxResireBG[] = {
	Tsa_EfxResireBG_0816B348,
	Tsa_EfxResireBG_0816B478,
	Tsa_EfxResireBG_0816B524,
	Tsa_EfxResireBG_0816B5D4,
	Tsa_EfxResireBG_0816B68C,
	Tsa_EfxResireBG_0816B74C,
	Tsa_EfxResireBG_0816B818,
	Tsa_EfxResireBG_0816B8F8,
	Tsa_EfxResireBG_0816B9E0,
	Tsa_EfxResireBG_0816BAE8,
	Tsa_EfxResireBG_0816BC04,
	Tsa_EfxResireBG_0816BD40,
	Tsa_EfxResireBG_0816BE90,
	Tsa_EfxResireBG_0816BFE8,
	Tsa_EfxResireBG_0816C140,
	Tsa_EfxResireBG_0816C294,
	Tsa_EfxResireBG_0816C3E4,
	Tsa_EfxResireBG_0816C534,
	Tsa_EfxResireBG_0816C66C,
	Tsa_EfxResireBG_0816C798,
	Tsa_EfxResireBG_0816C8B4,
	Tsa_EfxResireBG_0816C9C0,
	Tsa_EfxResireBG_0816CAB8,
	Tsa_EfxResireBG_0816CBA4,
	Tsa_EfxResireBG_0816CC74,
	Tsa_EfxResireBG_0816CD30,
	Tsa_EfxResireBG_0816CDE4,
	Tsa_EfxResireBG_0816CE94,
	Tsa_EfxResireBG_0816CF40,
	Tsa_EfxResireBG_0816CFE8,
	Tsa_EfxResireBG_0816D09C,
	Tsa_EfxResireBG_0816D15C,
	Tsa_EfxResireBG_0816D228,
	Tsa_EfxResireBG_0816D2F0,
	Tsa_EfxResireBG_0816D3B8,
	Tsa_EfxResireBG_0816D48C,
	Tsa_EfxResireBG_0816D568,
	Tsa_EfxResireBG_0816D650,
	Tsa_EfxResireBG_0816D744,
	Tsa_EfxResireBG_0816D84C,
	Tsa_EfxResireBG_0816D954,
	Tsa_EfxResireBG_0816DA78,
	Tsa_EfxResireBG_0816DB98,
	Tsa_EfxResireBG_0816DCB4,
	Tsa_EfxResireBG_0816DDC4,
	Tsa_EfxResireBG_0816DED0,
	Tsa_EfxResireBG_0816DFD0,
	Tsa_EfxResireBG_0816E0C0,
	Tsa_EfxResireBG_0816E19C,
	Tsa_EfxResireBG_0816E268,
	Tsa_EfxResireBG_0816E320,
};

struct ProcScr CONST_DATA ProcScr_EfxResireRST[] = {
	PROC_NAME_DEBUG("efxResireRST"),
	PROC_REPEAT(EfxResireRST_Loop),
	PROC_END,
};


void StartSpellAnimNosferatu(struct Anim *anim)
{
	struct ProcEfx *proc;

	SpellFx_Begin();
	NewEfxSpellCast();
	SpellFx_ClearBG1Position();

	proc = SpawnProc(ProcScr_EfxResire, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->hitted = CheckRoundMiss(GetAnimRoundTypeAnotherSide(anim));
}

void EfxResire_Loop(struct ProcEfx *proc)
{
	struct Anim *anim = GetAnimAnotherSide(proc->anim);
	int duration = EfxGetCamMovDuration();

	proc->timer++;

	if (proc->timer == 1)
		NewEfxFarAttackWithDistance(proc->anim, -1);

	if (proc->timer == duration + 1) {
		SetBlendAlpha(0, 16);
		NewEfxALPHA(anim, 0, 10, 0, 16, 0);
		NewEfxALPHA(anim, 0x28, 0x28, 16, 0, 0);
		NewEfxResireBG2(anim);
		PlaySFX(0x124, 0x100, anim->xPosition, 1);
		return;
	}

	if (proc->timer == duration + 15) {
		NewEfxResireRST(anim, NewEfxRestRST(anim, 0x52, 15, 0, 2), 0x3C);
		NewEfxRestWINH(anim, 0x53, gDispIo.bg_off[BG_1].x, EfxRestWINH_DefaultHblank);
		return;
	}

	if (proc->timer == duration + 0x64) {
		NewEfxResireBG(anim, proc->hitted);
		PlaySFX(0x125, 0x100, anim->xPosition, 1);
		return;
	}

	if (proc->timer == duration + 0x69) {
		anim->flags3 |= (ANIM_BIT3_C02_BLOCK_END | ANIM_BIT3_C01_BLOCK_END_INBATTLE);

		StartBattleAnimResireHitEffects(anim, proc->hitted);

		if (!proc->hitted)
			EfxPlayHittedSFX(anim);

		return;
	}

	if (proc->timer == duration + 0x96)
		return;

	if (proc->timer == duration + 0xAA) {
		SpellFx_Finish();
		Proc_Break(proc);
	}
}

void NewEfxResireBG(struct Anim *anim, int type)
{
	static const u16 frames[] = {
		1, 3,
		2, 2,
		3, 2,
		4, 2,
		5, 2,
		6, 2,
		7, 1,
		8, 1,
		9, 1,
		10, 1,
		11, 1,
		12, 1,
		13, 1,
		14, 1,
		15, 1,
		16, 1,
		17, 1,
		18, 1,
		19, 1,
		20, 1,
		21, 1,
		22, 1,
		23, 1,
		24, 1,
		25, 1,
		26, 1,
		27, 1,
		-1
	};

	struct ProcEfxBG *proc;

	gEfxBgSemaphore++;

	proc = SpawnProc(ProcScr_EfxResireBG, PROC_TREE_3);
	proc->anim = anim;
	proc->unk29 = type;
	proc->timer = 0;
	proc->frame = 0;
	proc->frame_config = frames;
	proc->tsal = TsaArray_EfxResireBG;
	proc->tsar = TsaArray_EfxResireBG;
	proc->img = ImgArray_EfxResireBG;

	SpellFx_RegisterBgPal(Pal_EfxResireBG, PLTT_SIZE_4BPP);
	SpellFx_SetSomeColorEffect();

	if (gEkrDistanceType != EKR_DISTANCE_CLOSE) {
		if (GetAnimPosition(proc->anim) == POS_L)
			SetBgOffset(BG_1, 24, 0);
		else
			SetBgOffset(BG_1, 232, 0);
	}
}

const u16 FrameConf_EfxResireBG3[] = {
	0x1C, 1,
	0x1D, 1,
	0x1E, 1,
	0x1F, 1,
	0x20, 1,
	0x21, 1,
	0x22, 1,
	0x23, 1,
	0x24, 1,
	0x25, 1,
	0x26, 1,
	0x27, 1,
	0x28, 1,
	0x29, 1,
	0x2A, 1,
	0x2B, 1,
	0x2C, 1,
	0x2D, 1,
	0x2E, 1,
	0x2F, 1,
	0x30, 1,
	0x31, 1,
	0x32, 1,
	-1
};

const u16 FrameConf_EfxResireBG2[] = {
	0, 90,
	-1
};

void NewEfxResireBG2(struct Anim *anim)
{
	struct ProcEfxBG *proc;

	gEfxBgSemaphore++;

	proc = SpawnProc(ProcScr_EfxResireBG2, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->frame = 0;
	proc->frame_config = FrameConf_EfxResireBG2;
	proc->tsal = TsaArray_EfxResireBG;
	proc->tsar = TsaArray_EfxResireBG;
	proc->img = ImgArray_EfxResireBG;

	SpellFx_RegisterBgPal(Pal_EfxResireBG, PLTT_SIZE_4BPP);
	SpellFx_SetSomeColorEffect();

	SetWinEnable(0, 0, 0);

	if (gEkrDistanceType != EKR_DISTANCE_CLOSE) {
		if (GetAnimPosition(proc->anim) == POS_L)
			SetBgOffset(BG_1, 24, 0);
		else
			SetBgOffset(BG_1, 232, 0);
	}
}

void EfxResireBG_Loop1(struct ProcEfxBG *proc)
{
	int ret = EfxAdvanceFrameLut((s16 *)&proc->timer, (s16 *)&proc->frame, proc->frame_config);

	if (ret >= 0) {
		u16 **tsaL = proc->tsal;
		u16 **tsaR = proc->tsar;
		u16 **img = proc->img;

		SpellFx_RegisterBgGfx(*(img + ret), 32 * 8 * CHR_SIZE);
		SpellFx_WriteBgMap(proc->anim, *(tsaL + ret), *(tsaR + ret));
		return;
	}

	if (ret == -1) {
		SpellFx_ClearBG1();

		if (proc->unk29 == 1) {
			gEfxBgSemaphore--;

			SpellFx_ClearColorEffects();
			EndEfxSpellCastAsync();

			Proc_End(proc);
		} else {
			proc->timer = 0;
			proc->terminator = 30;
			Proc_Break(proc);
		}
	}
}

void EfxResireBG_Loop2(struct ProcEfxBG *proc)
{
	if (gEfxHpBarResireFlag == 2) {
		gEfxBgSemaphore--;

		SpellFx_ClearColorEffects();
		EndEfxSpellCastAsync();

		Proc_End(proc);
		return;
	}

	proc->timer++;

	if (proc->timer > proc->terminator)
		proc->timer = proc->terminator;

	if ((proc->timer == proc->terminator) && (gEfxHpBarResireFlag == 1)) {
		proc->timer = 0;
		proc->terminator = 0;
		proc->frame = 0;
		proc->frame_config = FrameConf_EfxResireBG3;
		proc->tsal = TsaArray_EfxResireBG;
		proc->tsar = TsaArray_EfxResireBG;
		proc->img = ImgArray_EfxResireBG;

		if (gEkrDistanceType != EKR_DISTANCE_CLOSE) {
			proc->terminator = EfxGetCamMovDuration();
			NewEfxFarAttackWithDistance(proc->anim, -1);
		}

		Proc_Break(proc);
	}
}

void EfxResireBG_Loop3(struct ProcEfxBG *proc)
{
	struct Anim *anim = GetAnimAnotherSide(proc->anim);

	proc->timer++;

	if (proc->timer > proc->terminator) {
		if (gEkrDistanceType != EKR_DISTANCE_CLOSE) {
			if (GetAnimPosition(proc->anim) == POS_L)
				SetBgOffset(BG_1, 232, 0);
			else
				SetBgOffset(BG_1, 24, 0);
		}

		proc->timer = 0;
		PlaySFX(SONG_126, 0x100, anim->xPosition, 1);

		Proc_Break(proc);
	}
}

void EfxResireBG_Loop4(struct ProcEfxBG *proc)
{
	int ret = EfxAdvanceFrameLut((s16 *)&proc->timer, (s16 *)&proc->frame, proc->frame_config);

	if (ret >= 0) {
		u16 **tsaL = proc->tsal;
		u16 **tsaR = proc->tsar;
		u16 **img = proc->img;

		SpellFx_RegisterBgGfx(*(img + ret), 32 * 8 * CHR_SIZE);
		SpellFx_WriteBgMap(proc->anim, *(tsaL + ret), *(tsaR + ret));
		return;
	}

	if (ret == -1) {
		SpellFx_ClearBG1();

		gEfxBgSemaphore--;

		SpellFx_ClearColorEffects();
		EndEfxSpellCastAsync();

		Proc_Break(proc);
	}
}

void EfxResireBG2_Loop(struct ProcEfxBG *proc)
{
	int ret = EfxAdvanceFrameLut((s16 *)&proc->timer, (s16 *)&proc->frame, proc->frame_config);

	if (ret >= 0) {
		u16 **tsaL = proc->tsal;
		u16 **tsaR = proc->tsar;
		u16 **img = proc->img;

		SpellFx_RegisterBgGfx(*(img + ret), 32 * 8 * CHR_SIZE);
		SpellFx_WriteBgMap(proc->anim, *(tsaL + ret), *(tsaR + ret));
		return;
	}

	if (ret == -1) {
		SpellFx_ClearBG1();
		gEfxBgSemaphore--;
		SpellFx_ClearColorEffects();
		Proc_Break(proc);
		return;
	}
}

void NewEfxResireRST(struct Anim *anim, ProcPtr efxproc, int c)
{
	struct ProcEfxRST *proc;

	gEfxBgSemaphore++;

	proc = SpawnProc(ProcScr_EfxResireRST, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->duration = c;
	proc->efxproc = efxproc;
}

void EfxResireRST_Loop(struct ProcEfxRST *proc)
{
	struct ProcEfx * otherProc = proc->efxproc;

	otherProc->frame = Interpolate(INTERPOLATE_RSQUARE, 0, 128, proc->timer, proc->duration);

	proc->timer++;

	if (proc->timer > proc->duration) {
		gEfxBgSemaphore--;
		Proc_Break(proc);
	}
}

/**
 * Light
 */
struct ProcScr CONST_DATA ProcScr_EfxLightning[] = {
	PROC_NAME_DEBUG("efxLightning"),
	PROC_REPEAT(EfxLightning_Loop),
	PROC_END,
};

struct ProcScr CONST_DATA ProcScr_EfxLightningBG[] = {
	PROC_NAME_DEBUG("efxLightningBG"),
	PROC_REPEAT(EfxLightningBG_Loop),
	PROC_END,
};

CONST_DATA u16 *ImgArray_EfxLightningBG[] = {
	Img_EfxLightningBG_081531C8,
	Img_EfxLightningBG_081531C8,
	Img_EfxLightningBG_081531C8,
	Img_EfxLightningBG_08153A90,
	Img_EfxLightningBG_08153A90,
	Img_EfxLightningBG_08153A90,
	Img_EfxLightningBG_081541E0,
	Img_EfxLightningBG_081541E0,
	Img_EfxLightningBG_081541E0,
	Img_EfxLightningBG_081541E0,
	Img_EfxLightningBG_08154BA4,
	Img_EfxLightningBG_08154BA4,
	Img_EfxLightningBG_08154BA4,
	Img_EfxLightningBG_081556F8,
	Img_EfxLightningBG_081556F8,
	Img_EfxLightningBG_081556F8,
	Img_EfxLightningBG_08156200,
	Img_EfxLightningBG_08156200,
	Img_EfxLightningBG_08156200,
	Img_EfxLightningBG_08156200,
	Img_EfxLightningBG_08156200,
	Img_EfxLightningBG_08156200,
	Img_EfxLightningBG_08156200,
	Img_EfxLightningBG_08156200,
	Img_EfxLightningBG_08156200,
	Img_EfxLightningBG_08156518,
	Img_EfxLightningBG_08156518,
	Img_EfxLightningBG_08156518,
	Img_EfxLightningBG_081571C8,
	Img_EfxLightningBG_081571C8,
	Img_EfxLightningBG_081571C8,
	Img_EfxLightningBG_081571C8,
	Img_EfxLightningBG_081571C8,
};

CONST_DATA u16 *PalArray_EfxLightningBG[] = {
	Pal_EfxLightningBG_08157BE8,
	Pal_EfxLightningBG_08157BE8,
	Pal_EfxLightningBG_08157BE8,
	Pal_EfxLightningBG_08157BE8,
	Pal_EfxLightningBG_08157BE8,
	Pal_EfxLightningBG_08157BE8,
	Pal_EfxLightningBG_08157BE8,
	Pal_EfxLightningBG_08157BE8,
	Pal_EfxLightningBG_08157BE8,
	Pal_EfxLightningBG_08157BE8,
	Pal_EfxLightningBG_08157BE8,
	Pal_EfxLightningBG_08157BE8,
	Pal_EfxLightningBG_08157BE8,
	Pal_EfxLightningBG_08157BE8,
	Pal_EfxLightningBG_08157BE8,
	Pal_EfxLightningBG_08157BE8,
	Pal_EfxLightningBG_08157BE8,
	Pal_EfxLightningBG_08157BE8,
	Pal_EfxLightningBG_08157BE8,
	Pal_EfxLightningBG_08157BE8,
	Pal_EfxLightningBG_08157BE8,
	Pal_EfxLightningBG_08157BE8,
	Pal_EfxLightningBG_08157BE8,
	Pal_EfxLightningBG_08157BE8,
	Pal_EfxLightningBG_08157BE8,
	Pal_EfxLightningBG_08157C08,
	Pal_EfxLightningBG_08157C08,
	Pal_EfxLightningBG_08157C08,
	Pal_EfxLightningBG_08157C08,
	Pal_EfxLightningBG_08157C08,
	Pal_EfxLightningBG_08157C08,
	Pal_EfxLightningBG_08157C08,
	Pal_EfxLightningBG_08157C08,
};

CONST_DATA u16 *TsaArray_EfxLightningBG[] = {
	Tsa_EfxLightningBG_08157C28,
	Tsa_EfxLightningBG_08157D4C,
	Tsa_EfxLightningBG_08157E6C,
	Tsa_EfxLightningBG_08157F78,
	Tsa_EfxLightningBG_08158074,
	Tsa_EfxLightningBG_0815815C,
	Tsa_EfxLightningBG_08158244,
	Tsa_EfxLightningBG_08158328,
	Tsa_EfxLightningBG_08158404,
	Tsa_EfxLightningBG_081584E4,
	Tsa_EfxLightningBG_081585D8,
	Tsa_EfxLightningBG_081586CC,
	Tsa_EfxLightningBG_081587D0,
	Tsa_EfxLightningBG_081588D8,
	Tsa_EfxLightningBG_081589F0,
	Tsa_EfxLightningBG_08158B14,
	Tsa_EfxLightningBG_08158C28,
	Tsa_EfxLightningBG_08158CD8,
	Tsa_EfxLightningBG_08158DE0,
	Tsa_EfxLightningBG_08158F1C,
	Tsa_EfxLightningBG_08159090,
	Tsa_EfxLightningBG_08159228,
	Tsa_EfxLightningBG_0815939C,
	Tsa_EfxLightningBG_081594A8,
	Tsa_EfxLightningBG_0815957C,
	Tsa_EfxLightningBG_0815961C,
	Tsa_EfxLightningBG_0815973C,
	Tsa_EfxLightningBG_08159858,
	Tsa_EfxLightningBG_0815996C,
	Tsa_EfxLightningBG_08159A64,
	Tsa_EfxLightningBG_08159B4C,
	Tsa_EfxLightningBG_08159C1C,
	Tsa_EfxLightningBG_08159CE0,
};

struct ProcScr CONST_DATA ProcScr_EfxPurge[] = {
	PROC_NAME_DEBUG("efxPurge"),
	PROC_REPEAT(EfxPurge_Loop),
	PROC_END,
};

struct ProcScr CONST_DATA ProcScr_EfxPurgeBG[] = {
	PROC_NAME_DEBUG("efxPurgeBG"),
	PROC_REPEAT(EfxPurgeBG_Loop),
	PROC_END,
};

CONST_DATA u16 *ImgArray_EfxPurgeBG[] = {
	Img_EfxLightningBG_081531C8,
	Img_EfxLightningBG_081531C8,
	Img_EfxLightningBG_081531C8,
	Img_EfxLightningBG_08153A90,
	Img_EfxLightningBG_08153A90,
	Img_EfxLightningBG_08153A90,
	Img_EfxLightningBG_081541E0,
	Img_EfxLightningBG_081541E0,
	Img_EfxLightningBG_081541E0,
	Img_EfxLightningBG_081541E0,
	Img_EfxLightningBG_08154BA4,
	Img_EfxLightningBG_08154BA4,
	Img_EfxLightningBG_08154BA4,
	Img_EfxLightningBG_081556F8,
	Img_EfxLightningBG_081556F8,
	Img_EfxLightningBG_081556F8,
	Img_EfxLightningBG_081531C8,
	Img_EfxLightningBG_081531C8,
	Img_EfxLightningBG_081531C8,
	Img_EfxLightningBG_08153A90,
	Img_EfxLightningBG_08153A90,
	Img_EfxLightningBG_08153A90,
	Img_EfxLightningBG_081541E0,
	Img_EfxLightningBG_081541E0,
	Img_EfxLightningBG_081541E0,
	Img_EfxLightningBG_081541E0,
	Img_EfxLightningBG_08154BA4,
	Img_EfxLightningBG_08154BA4,
	Img_EfxLightningBG_08154BA4,
	Img_EfxLightningBG_081556F8,
	Img_EfxLightningBG_081556F8,
	Img_EfxLightningBG_081556F8,
	Img_EfxLightningBG_081531C8,
	Img_EfxLightningBG_081531C8,
	Img_EfxLightningBG_081531C8,
	Img_EfxLightningBG_08153A90,
	Img_EfxLightningBG_08153A90,
	Img_EfxLightningBG_08153A90,
	Img_EfxLightningBG_081541E0,
	Img_EfxLightningBG_081541E0,
	Img_EfxLightningBG_081541E0,
	Img_EfxLightningBG_081541E0,
	Img_EfxLightningBG_08154BA4,
	Img_EfxLightningBG_08154BA4,
	Img_EfxLightningBG_08154BA4,
	Img_EfxLightningBG_081556F8,
	Img_EfxLightningBG_081556F8,
	Img_EfxLightningBG_081556F8,
	Img_EfxPurgeBG_0819879C,
	Img_EfxPurgeBG_0819879C,
	Img_EfxPurgeBG_08198CF8,
	Img_EfxPurgeBG_08198CF8,
	Img_EfxPurgeBG_08199374,
	Img_EfxPurgeBG_08199374,
	Img_EfxPurgeBG_081999C0,
	Img_EfxPurgeBG_081999C0,
	Img_EfxPurgeBG_0819A174,
	Img_EfxPurgeBG_0819A174,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	Img_EfxPurgeBG_0819A87C,
	Img_EfxPurgeBG_0819AD98,
	Img_EfxPurgeBG_0819B698,
	Img_EfxPurgeBG_0819C04C,
	Img_EfxPurgeBG_0819C9C0,
	Img_EfxPurgeBG_0819D394,
	Img_EfxPurgeBG_0819D394,
	Img_EfxPurgeBG_0819E398,
	Img_EfxPurgeBG_0819E398,
	Img_EfxPurgeBG_0819F1E8,
	Img_EfxPurgeBG_0819FCCC,
	Img_EfxPurgeBG_081A0874,
	Img_EfxPurgeBG_081A1410,
	Img_EfxPurgeBG_081A1ED0,
	Img_EfxPurgeBG_081A2948,
};

CONST_DATA u16 *PalArray_EfxPurgeBG[] = {
	Pal_EfxLightningBG_08157BE8,
	Pal_EfxLightningBG_08157BE8,
	Pal_EfxLightningBG_08157BE8,
	Pal_EfxLightningBG_08157BE8,
	Pal_EfxLightningBG_08157BE8,
	Pal_EfxLightningBG_08157BE8,
	Pal_EfxLightningBG_08157BE8,
	Pal_EfxLightningBG_08157BE8,
	Pal_EfxLightningBG_08157BE8,
	Pal_EfxLightningBG_08157BE8,
	Pal_EfxLightningBG_08157BE8,
	Pal_EfxLightningBG_08157BE8,
	Pal_EfxLightningBG_08157BE8,
	Pal_EfxLightningBG_08157BE8,
	Pal_EfxLightningBG_08157BE8,
	Pal_EfxLightningBG_08157BE8,
	Pal_EfxLightningBG_08157BE8,
	Pal_EfxLightningBG_08157BE8,
	Pal_EfxLightningBG_08157BE8,
	Pal_EfxLightningBG_08157BE8,
	Pal_EfxLightningBG_08157BE8,
	Pal_EfxLightningBG_08157BE8,
	Pal_EfxLightningBG_08157BE8,
	Pal_EfxLightningBG_08157BE8,
	Pal_EfxLightningBG_08157BE8,
	Pal_EfxLightningBG_08157BE8,
	Pal_EfxLightningBG_08157BE8,
	Pal_EfxLightningBG_08157BE8,
	Pal_EfxLightningBG_08157BE8,
	Pal_EfxLightningBG_08157BE8,
	Pal_EfxLightningBG_08157BE8,
	Pal_EfxLightningBG_08157BE8,
	Pal_EfxLightningBG_08157BE8,
	Pal_EfxLightningBG_08157BE8,
	Pal_EfxLightningBG_08157BE8,
	Pal_EfxLightningBG_08157BE8,
	Pal_EfxLightningBG_08157BE8,
	Pal_EfxLightningBG_08157BE8,
	Pal_EfxLightningBG_08157BE8,
	Pal_EfxLightningBG_08157BE8,
	Pal_EfxLightningBG_08157BE8,
	Pal_EfxLightningBG_08157BE8,
	Pal_EfxLightningBG_08157BE8,
	Pal_EfxLightningBG_08157BE8,
	Pal_EfxLightningBG_08157BE8,
	Pal_EfxLightningBG_08157BE8,
	Pal_EfxLightningBG_08157BE8,
	Pal_EfxLightningBG_08157BE8,
	Pal_EfxPurgeBG_081A3C4C,
	Pal_EfxPurgeBG_081A3C4C,
	Pal_EfxPurgeBG_081A3C4C,
	Pal_EfxPurgeBG_081A3C4C,
	Pal_EfxPurgeBG_081A3C4C,
	Pal_EfxPurgeBG_081A3C4C,
	Pal_EfxPurgeBG_081A3C4C,
	Pal_EfxPurgeBG_081A3C4C,
	Pal_EfxPurgeBG_081A3C4C,
	Pal_EfxPurgeBG_081A3C4C,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	Pal_EfxPurgeBG_081A3C6C,
	Pal_EfxPurgeBG_081A3C6C,
	Pal_EfxPurgeBG_081A3C6C,
	Pal_EfxPurgeBG_081A3C6C,
	Pal_EfxPurgeBG_081A3C6C,
	Pal_EfxPurgeBG_081A3C6C,
	Pal_EfxPurgeBG_081A3C6C,
	Pal_EfxPurgeBG_081A3C6C,
	Pal_EfxPurgeBG_081A3C6C,
	Pal_EfxPurgeBG_081A3C6C,
	Pal_EfxPurgeBG_081A3C6C,
	Pal_EfxPurgeBG_081A3C6C,
	Pal_EfxPurgeBG_081A3C6C,
	Pal_EfxPurgeBG_081A3C6C,
	Pal_EfxPurgeBG_081A3C6C,
};

CONST_DATA u16 *TsaArray_EfxPurgeBG[] = {
	Tsa_EfxPurgeBG_081A3C8C,
	Tsa_EfxPurgeBG_081A3DB0,
	Tsa_EfxPurgeBG_081A3ED0,
	Tsa_EfxPurgeBG_081A3FDC,
	Tsa_EfxPurgeBG_081A40D8,
	Tsa_EfxPurgeBG_081A41C0,
	Tsa_EfxPurgeBG_081A42A8,
	Tsa_EfxPurgeBG_081A4388,
	Tsa_EfxPurgeBG_081A4464,
	Tsa_EfxPurgeBG_081A4544,
	Tsa_EfxPurgeBG_081A4638,
	Tsa_EfxPurgeBG_081A472C,
	Tsa_EfxPurgeBG_081A4830,
	Tsa_EfxPurgeBG_081A4938,
	Tsa_EfxPurgeBG_081A4A50,
	Tsa_EfxPurgeBG_081A4B74,
	Tsa_EfxPurgeBG_081A4C88,
	Tsa_EfxPurgeBG_081A4DAC,
	Tsa_EfxPurgeBG_081A4ED0,
	Tsa_EfxPurgeBG_081A4FE0,
	Tsa_EfxPurgeBG_081A50E0,
	Tsa_EfxPurgeBG_081A51C8,
	Tsa_EfxPurgeBG_081A52A8,
	Tsa_EfxPurgeBG_081A5384,
	Tsa_EfxPurgeBG_081A5460,
	Tsa_EfxPurgeBG_081A5544,
	Tsa_EfxPurgeBG_081A5638,
	Tsa_EfxPurgeBG_081A5728,
	Tsa_EfxPurgeBG_081A582C,
	Tsa_EfxPurgeBG_081A5934,
	Tsa_EfxPurgeBG_081A5A48,
	Tsa_EfxPurgeBG_081A5B6C,
	Tsa_EfxPurgeBG_081A5C80,
	Tsa_EfxPurgeBG_081A5DA4,
	Tsa_EfxPurgeBG_081A5EC4,
	Tsa_EfxPurgeBG_081A5FD0,
	Tsa_EfxPurgeBG_081A60CC,
	Tsa_EfxPurgeBG_081A61B4,
	Tsa_EfxPurgeBG_081A629C,
	Tsa_EfxPurgeBG_081A637C,
	Tsa_EfxPurgeBG_081A6458,
	Tsa_EfxPurgeBG_081A6538,
	Tsa_EfxPurgeBG_081A662C,
	Tsa_EfxPurgeBG_081A6720,
	Tsa_EfxPurgeBG_081A6824,
	Tsa_EfxPurgeBG_081A692C,
	Tsa_EfxPurgeBG_081A6A44,
	Tsa_EfxPurgeBG_081A6B68,
	Tsa_EfxPurgeBG_081A6C78,
	Tsa_EfxPurgeBG_081A6E8C,
	Tsa_EfxPurgeBG_081A7048,
	Tsa_EfxPurgeBG_081A7224,
	Tsa_EfxPurgeBG_081A7428,
	Tsa_EfxPurgeBG_081A7630,
	Tsa_EfxPurgeBG_081A7844,
	Tsa_EfxPurgeBG_081A7AA4,
	Tsa_EfxPurgeBG_081A7CD8,
	Tsa_EfxPurgeBG_081A7F4C,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	Tsa_EfxPurgeBG_081A8194,
	Tsa_EfxPurgeBG_081A84F4,
	Tsa_EfxPurgeBG_081A8848,
	Tsa_EfxPurgeBG_081A8B58,
	Tsa_EfxPurgeBG_081A8E3C,
	Tsa_EfxPurgeBG_081A910C,
	Tsa_EfxPurgeBG_081A93A4,
	Tsa_EfxPurgeBG_081A963C,
	Tsa_EfxPurgeBG_081A9868,
	Tsa_EfxPurgeBG_081A9B1C,
	Tsa_EfxPurgeBG_081A9DDC,
	Tsa_EfxPurgeBG_081AA10C,
	Tsa_EfxPurgeBG_081AA45C,
	Tsa_EfxPurgeBG_081AA7D4,
	Tsa_EfxPurgeBG_081AAB5C,
};

struct ProcScr CONST_DATA ProcScr_EfxPurgeOBJRND[] = {
	PROC_NAME_DEBUG("efxPurgeOBJRND"),
	PROC_REPEAT(EfxPurgeOBJRND_Loop),
	PROC_SLEEP(69),
	PROC_END,
};

CONST_DATA int Vecs_EfxPurgeOBJRND[] = {
	0xD0, 0x30,
	0xA0, 0x90,
	0x40, 0x40,
	0xC0, 0x60,
	0x80, 0x30,
	0x20, 0x60,
	0x50, 0x80,
};

struct ProcScr CONST_DATA ProcScr_EfxPurgeOBJ[] = {
	PROC_NAME_DEBUG("efxPurgeOBJ"),
	PROC_ONEND(EfxPurgeOBJ_OnEnd),
	PROC_SLEEP(69),
	PROC_END,
};


void StartSpellAnimLightning(struct Anim *anim)
{
	struct ProcEfx *proc;

	SpellFx_Begin();
	NewEfxSpellCast();
	SpellFx_ClearBG1Position();

	proc = SpawnProc(ProcScr_EfxLightning, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->hitted = CheckRoundMiss(GetAnimRoundTypeAnotherSide(anim));
}

void EfxLightning_Loop(struct ProcEfx *proc)
{
	struct Anim *anim = GetAnimAnotherSide(proc->anim);
	int duration = EfxGetCamMovDuration();

	proc->timer++;

	if (proc->timer == 1)
		NewEfxFarAttackWithDistance(proc->anim, -1);

	if (proc->timer == duration + 1) {
		PlaySFX(SONG_120, 0x100, anim->xPosition, 1);
		NewEfxLightningBG(anim);
		return;
	}

	if (proc->timer == duration + 0x1A) {
		PlaySFX(SONG_121, 0x100, anim->xPosition, 1);
		NewEfxFlashBgWhite(proc->anim, 4);

		anim->flags3 |= (ANIM_BIT3_C02_BLOCK_END | ANIM_BIT3_C01_BLOCK_END_INBATTLE);

		StartBattleAnimHitEffectsDefault(anim, proc->hitted);

		if (!proc->hitted)
			EfxPlayHittedSFX(anim);

		return;
	}

	if (proc->timer == duration + 0x2F)
		return;

	if (proc->timer == duration + 0x30) {
		SpellFx_Finish();
		EndEfxSpellCastAsync();
		Proc_Break(proc);
		return;
	}
}

void NewEfxLightningBG(struct Anim *anim)
{
	struct ProcEfxBG *proc;

	static const u16 frame_config[] = {
		0x19, 2,
		0x1A, 2,
		0x1B, 2,
		0x1C, 2,
		0x1D, 2,
		0x1E, 2,
		0x1F, 2,
		0x20, 2,
		0x10, 1,
		0x11, 1,
		0x12, 1,
		0x13, 1,
		0x14, 1,
		0x15, 1,
		0x16, 1,
		0x17, 1,
		0x18, 1,
		0x0, 7,
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

	gEfxBgSemaphore++;

	proc = SpawnProc(ProcScr_EfxLightningBG, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->frame = 0;
	proc->frame_config = frame_config;
	proc->tsal = TsaArray_EfxLightningBG;
	proc->tsar = TsaArray_EfxLightningBG;
	proc->img = ImgArray_EfxLightningBG;
	proc->pal = PalArray_EfxLightningBG;

	SpellFx_SetSomeColorEffect();

	if (gEkrDistanceType != EKR_DISTANCE_CLOSE) {
		if (GetAnimPosition(proc->anim) == POS_L)
			SetBgOffset(BG_1, 24, 0);
		else
			SetBgOffset(BG_1, 232, 0);
	}
}

void EfxLightningBG_Loop(struct ProcEfxBG *proc)
{
	int ret = EfxAdvanceFrameLut((s16 *)&proc->timer, (s16 *)&proc->frame, proc->frame_config);

	if (ret >= 0) {
		u16 **tsaL = proc->tsal;
		u16 **tsaR = proc->tsar;
		u16 **img = proc->img;
		u16 **pal = proc->pal;

		SpellFx_RegisterBgGfx(*(img + ret), 32 * 8 * CHR_SIZE);
		SpellFx_RegisterBgPal(*(pal + ret), PLTT_SIZE_4BPP);
		SpellFx_WriteBgMap(proc->anim, *(tsaL + ret), *(tsaR + ret));

		if (gEkrDistanceType != EKR_DISTANCE_CLOSE) {
			if (GetAnimPosition(proc->anim) == POS_L)
				FillBGRect(gBg1Tm, 3, 20, 0, 0);
			else
				FillBGRect(gBg1Tm + TM_OFFSET(29, 0), 3, 20, 0, 0);
		}
		return;
	}

	if (ret == -1) {
		SpellFx_ClearBG1();
		gEfxBgSemaphore--;
		SpellFx_ClearColorEffects();
		Proc_End(proc);
		return;
	}
}

void StartSpellAnimPurge(struct Anim *anim)
{
	struct ProcEfx *proc;

	SpellFx_Begin();
	NewEfxSpellCast();
	SpellFx_ClearBG1Position();

	proc = SpawnProc(ProcScr_EfxPurge, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->hitted = CheckRoundMiss(GetAnimRoundTypeAnotherSide(anim));

	gEfxPurgeCounter = 0;
}

void EfxPurge_PlaySFX(int location, int type)
{
	if (gEfxPurgeCounter & 1)
		PlaySFX(SONG_FE, 0x100, location, type);
	else
		PlaySFX(SONG_FF, 0x100, location, type);

	gEfxPurgeCounter++;
}

void EfxPurge_Loop(struct ProcEfx *proc)
{
	struct Anim *anim = GetAnimAnotherSide(proc->anim);
	int duration = EfxGetCamMovDuration();

	proc->timer++;

	if (proc->timer == 1)
		NewEfxFarAttackWithDistance(proc->anim, -1);

	if (proc->timer == duration + 1) {
		NewEfxFlashBgWhite(anim, 4);
		NewEfxPurgeBG(anim);
		NewEfxPurgeOBJRND(anim);
		EfxPurge_PlaySFX(0x30, 0);
		return;
	}

	if (proc->timer == duration + 21) {
		NewEfxFlashBgWhite(anim, 4);
		EfxPurge_PlaySFX(0xa0, 0);
		return;
	}

	if (proc->timer == duration + 41) {
		NewEfxFlashBgWhite(anim, 4);
		EfxPurge_PlaySFX(0x70, 0);
		return;
	}

	if (proc->timer == duration + 61) {
		NewEfxFlashBgWhite(anim, 4);
		NewEfxALPHA(anim, 3, 10, 0, 16, 0);
		PlaySFX(0x100, 0x100, anim->xPosition, 1);
		return;
	}

	if (proc->timer == duration + 94) {
		NewEfxFlashBgWhite(anim, 4);
		anim->flags3 |= (ANIM_BIT3_C02_BLOCK_END | ANIM_BIT3_C01_BLOCK_END_INBATTLE);

		StartBattleAnimHitEffectsDefault(anim, proc->hitted);

		PlaySFX(0x101, 0x100, anim->xPosition, 1);

		if (!proc->hitted)
			EfxPlayHittedSFX(anim);

		return;
	}

	if (proc->timer == duration + 105) {
		NewEfxALPHA(anim, 0, 20, 8, 0, 0);
		return;
	}

	if (proc->timer == duration + 113) {
		SpellFx_Finish();
		EndEfxSpellCastAsync();
		Proc_Break(proc);
		return;
	}
}

void NewEfxPurgeBG(struct Anim *anim)
{
	struct ProcEfxBG *proc;

	static const u16 frame_config[] = {
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
		0xF, 5,
		0x10, 1,
		0x11, 1,
		0x12, 1,
		0x13, 1,
		0x14, 1,
		0x15, 1,
		0x16, 1,
		0x17, 1,
		0x18, 1,
		0x19, 1,
		0x1A, 1,
		0x1B, 1,
		0x1C, 1,
		0x1D, 1,
		0x1E, 1,
		0x1F, 5,
		0x20, 1,
		0x21, 1,
		0x22, 1,
		0x23, 1,
		0x24, 1,
		0x25, 1,
		0x26, 1,
		0x27, 1,
		0x28, 1,
		0x29, 1,
		0x2A, 1,
		0x2B, 1,
		0x2C, 1,
		0x2D, 1,
		0x2E, 1,
		0x2F, 5,
		0x30, 1,
		0x31, 1,
		0x32, 1,
		0x33, 1,
		0x34, 1,
		0x35, 1,
		0x36, 1,
		0x37, 1,
		0x38, 1,
		0x39, 1,
		0x30, 1,
		0x31, 1,
		0x32, 1,
		0x33, 1,
		0x34, 1,
		0x35, 1,
		0x36, 1,
		0x37, 1,
		0x38, 1,
		0x39, 1,
		0x30, 1,
		0x31, 1,
		0x32, 1,
		0x33, 1,
		0x34, 1,
		0x35, 1,
		0x36, 1,
		0x37, 1,
		0x38, 1,
		0x39, 4,
		0x3F, 2,
		0x40, 2,
		0x41, 2,
		0x42, 2,
		0x43, 2,
		0x44, 2,
		0x45, 2,
		0x46, 2,
		0x47, 2,
		0x48, 2,
		0x49, 2,
		0x4A, 2,
		0x4B, 2,
		0x4C, 2,
		0x4D, 2,
		-1
	};

	gEfxBgSemaphore++;

	proc = SpawnProc(ProcScr_EfxPurgeBG, PROC_TREE_3);

	proc->anim = anim;
	proc->timer = 0;

	proc->frame = 0;
	proc->frame_config = frame_config;

	proc->tsal = TsaArray_EfxPurgeBG;
	proc->tsar = TsaArray_EfxPurgeBG;
	proc->img = ImgArray_EfxPurgeBG;
	proc->pal = PalArray_EfxPurgeBG;

	SpellFx_SetSomeColorEffect();
}

void EfxPurgeBG_Loop(struct ProcEfxBG *proc)
{
	int ret = EfxAdvanceFrameLut((s16 *)&proc->timer, (s16 *)&proc->frame, proc->frame_config);

	if (ret >= 0) {
		u16 **tsaL = proc->tsal;
		u16 **tsaR = proc->tsar;
		u16 **img = proc->img;
		u16 **pal = proc->pal;

		SpellFx_RegisterBgGfx(*(img + ret), 32 * 8 * CHR_SIZE);
		SpellFx_RegisterBgPal(*(pal + ret), PLTT_SIZE_4BPP);
		SpellFx_WriteBgMap(proc->anim, *(tsaL + ret), *(tsaR + ret));
		return;
	}

	if (ret == -1) {
		SpellFx_ClearBG1();
		gEfxBgSemaphore--;
		SpellFx_ClearColorEffects();
		Proc_End(proc);
	}
}

void NewEfxPurgeOBJRND(struct Anim *anim)
{
	struct ProcEfxOBJ *proc;

	gEfxBgSemaphore++;

	proc = SpawnProc(ProcScr_EfxPurgeOBJRND, PROC_TREE_3);

	proc->anim = anim;
	proc->timer = 0;
	proc->unk44 = 7;
	proc->terminator = 0;
	proc->unk48 = 6;
}

void EfxPurgeOBJRND_Loop(struct ProcEfxOBJ *proc)
{
	if (++proc->timer > proc->unk44) {
		int x, y;

		proc->timer = 0;

		x = Vecs_EfxPurgeOBJRND[proc->terminator * 2 + 0];
		y = Vecs_EfxPurgeOBJRND[proc->terminator * 2 + 1];

		NewEfxPurgeOBJ(proc->anim2, x, y);
		EfxPurge_PlaySFX(x, 1);

		if (++proc->terminator > proc->unk48)
		{
			gEfxBgSemaphore--;
			Proc_Break(proc);
		}
	}
}

void NewEfxPurgeOBJ(struct Anim *anim, int x, int y)
{
	struct ProcEfxOBJ *proc;
	struct Anim * frontAnim;

	gEfxBgSemaphore++;

	proc = SpawnProc(ProcScr_EfxPurgeOBJ, PROC_TREE_3);
	proc->anim = anim;

	frontAnim = EfxCreateFrontAnim(anim, AnimScr_EfxPurgeOBJ, AnimScr_EfxPurgeOBJ, AnimScr_EfxPurgeOBJ, AnimScr_EfxPurgeOBJ);

	proc->anim2 = frontAnim;
	frontAnim->xPosition = x;
	frontAnim->yPosition = y;

	SpellFx_RegisterObjPal(Pal_EfxPurgeOBJ, PLTT_SIZE_4BPP);
	SpellFx_RegisterObjGfx(Img_EfxPurgeOBJ, 32 * 4 * CHR_SIZE);
}

void EfxPurgeOBJ_OnEnd(struct ProcEfxOBJ *proc)
{
	BasRemove(proc->anim2);
	gEfxBgSemaphore--;
}

/**
 * Forblaze
 */
struct ProcScr CONST_DATA ProcScr_EfxForblaze[] = {
	PROC_NAME_DEBUG("efxForblaze"),
	PROC_REPEAT(EfxForblaze_Loop),
	PROC_END,
};

struct ProcScr CONST_DATA ProcScr_EfxForblazeBG1[] = {
	PROC_NAME_DEBUG("efxForblazeBG1"),
	PROC_REPEAT(EfxForblazeBG1_Loop),
	PROC_END,
};

CONST_DATA u16 *TsaArray_EfxForblazeBG1[] = {
	Tsa_EfxForblazeBG1_0814092C,
	Tsa_EfxForblazeBG1_081409DC,
	Tsa_EfxForblazeBG1_08140A98,
	Tsa_EfxForblazeBG1_08140B60,
	Tsa_EfxForblazeBG1_08140C30,
	Tsa_EfxForblazeBG1_08140D00,
	Tsa_EfxForblazeBG1_08140DCC,
	Tsa_EfxForblazeBG1_08140E98,
	Tsa_EfxForblazeBG1_08140F7C,
	Tsa_EfxForblazeBG1_08141050,
	Tsa_EfxForblazeBG1_08141114,
	Tsa_EfxForblazeBG1_081411D4,
	Tsa_EfxForblazeBG1_08141288,
};

CONST_DATA u16 *ImgArray_EfxForblazeBG1[] = {
	Img_EfxForblazeBG1_0813F5E0,
	Img_EfxForblazeBG1_0813F5E0,
	Img_EfxForblazeBG1_0813F5E0,
	Img_EfxForblazeBG1_0813F5E0,
	Img_EfxForblazeBG1_0813F5E0,
	Img_EfxForblazeBG1_0813F5E0,
	Img_EfxForblazeBG1_0813FF7C,
	Img_EfxForblazeBG1_0813FF7C,
	Img_EfxForblazeBG1_0813FF7C,
	Img_EfxForblazeBG1_0813FF7C,
	Img_EfxForblazeBG1_0813FF7C,
	Img_EfxForblazeBG1_0813FF7C,
	Img_EfxForblazeBG1_0813FF7C,
};

struct ProcScr CONST_DATA ProcScr_EfxForblazeBGCOL1[] = {
	PROC_NAME_DEBUG("efxForblazeBGCOL1"),
	PROC_MARK(PROC_MARK_PAL_CHG),
	PROC_REPEAT(EfxForblazeBGCOL1_Loop),
	PROC_END,
};

struct ProcScr CONST_DATA ProcScr_EfxForblazeBGCtrl1[] = {
	PROC_NAME_DEBUG("efxForblazeBGCtrl1"),
	PROC_SLEEP(35),
	PROC_REPEAT(EfxForblazeBGCtrl1_Loop1),
	PROC_SLEEP(35),
	PROC_REPEAT(EfxForblazeBGCtrl1_Loop2),
	PROC_SLEEP(35),
	PROC_REPEAT(EfxForblazeBGCtrl1_Loop3),
	PROC_END,
};

struct ProcScr CONST_DATA ProcScr_EfxForblazeObjHandle[] = {
	PROC_NAME_DEBUG("efxForblazeObjHandle"),
	PROC_REPEAT(EfxForblazeObjHandle_Loop),
	PROC_END,
};

CONST_DATA int XposArray_EfxForblazeOBJ[] = {
	0x14,
	0x6B,
	0xE4,
	0x2C,
	0xC3,
	0x54,
	0x85,
	0x1B,
	0xAC,
	0xDA,
	0x40,
	0x6C,
	0x94,
	0xE5,
	0xBF,
	0x56,
	0x20,
	0x81,
	0x0D,
	0x88,
	0xAC,
	-1,
};

struct ProcScr CONST_DATA ProcScr_EfxForblazeOBJ[] = {
	PROC_NAME_DEBUG("efxForblazeOBJ"),
	PROC_REPEAT(EfxForblazeOBJ_Loop),
	PROC_END,
};

struct ProcScr CONST_DATA ProcScr_EfxForblazeBG2[] = {
	PROC_NAME_DEBUG("efxForblazeBG2"),
	PROC_REPEAT(EfxForblazeBG2_Loop),
	PROC_END,
};

struct ProcScr CONST_DATA ProcScr_EfxForblazeOBJCtrl[] = {
	PROC_NAME_DEBUG("efxForblazeOBJCtrl"),
	PROC_REPEAT(EfxForblazeOBJCtrl_Loop),
	PROC_END,
};

struct ProcScr CONST_DATA ProcScr_EfxForblazeOBJFall[] = {
	PROC_NAME_DEBUG("efxForblazeOBJFall"),
	PROC_REPEAT(EfxForblazeOBJFall_Loop),
	PROC_END,
};

struct ProcScr CONST_DATA ProcScr_EfxForblazeRST[] = {
	PROC_NAME_DEBUG("efxForblazeRST"),
	PROC_REPEAT(EfxForblazeRST_Loop),
	PROC_END,
};

void StartSpellAnimForblaze(struct Anim *anim)
{
	struct ProcEfx *proc;

	SpellFx_Begin();
	NewEfxSpellCast();
	SpellFx_ClearBG1Position();

	proc = SpawnProc(ProcScr_EfxForblaze, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->hitted = CheckRoundMiss(GetAnimRoundTypeAnotherSide(anim));
}

void EfxForblaze_Loop(struct ProcEfx *proc)
{
	struct Anim *anim = GetAnimAnotherSide(proc->anim);
	int duration = EfxGetCamMovDuration();

	proc->timer++;

	if (proc->timer == 1)
		NewEfxFarAttackWithDistance(proc->anim, -1);

	if (proc->timer == (duration + 1)) {
		NewEfxForblazeBG1(anim);
		NewEfxForblazeBGCtrl1();
		NewEfxForblazeBGCOL1(anim, 0xA0);
		PlaySFX(SONG_12D, 0x100, anim->xPosition, 1);
		return;
	}

	if (proc->timer == (duration + 0x5A)) {
		NewEfxForblazeObjHandle(anim, 0x3C);
		PlaySFX(SONG_12E, 0x100, 0x78, 0);
		return;
	}

	if (proc->timer == (duration + 0xA0)) {
		NewEfxFlashBgRed(proc->anim, 3);
		return;
	}

	if (proc->timer == (duration + 0xA3)) {
		NewEfxMagicQUAKE(anim, 0x64);
		NewEfxForblazeBG2(anim, 0x64);
		NewEfxALPHA(anim, 0x50, 0x14, 0x10, 0, 0);
		NewEfxRestWINH_(anim, 0x64, HBlank_EfxForblaze);
		NewEfxForblazeRST(0x64);
		NewEfxForblazeOBJCtrl(anim);
		PlaySFX(SONG_12F, 0x100, 0x78, 0);

		anim->flags3 |= (ANIM_BIT3_C02_BLOCK_END | ANIM_BIT3_C01_BLOCK_END_INBATTLE);

		StartBattleAnimHitEffectsDefault(anim, proc->hitted);

		if (!proc->hitted)
			EfxPlayHittedSFX(anim);

		return;
	}

	if (proc->timer == (duration + 0xFA))
		return;

	if (proc->timer == (duration + 0x104))
	{
		SpellFx_Finish();
		EndEfxSpellCastAsync();
		Proc_Break(proc);
	}
}

void NewEfxForblazeBG1(struct Anim *anim)
{
	struct ProcEfxBG *proc;

	static const u16 frame_config[] = {
		0x0, 3,
		0x1, 3,
		0x2, 3,
		0x3, 3,
		0x4, 3,
		0x5, 3,
		0x6, 3,
		0x7, 3,
		0x8, 3,
		0x9, 3,
		0xA, 3,
		0xB, 3,
		0x0, 3,
		0x1, 3,
		0x2, 3,
		0x3, 3,
		0x4, 3,
		0x5, 3,
		0x6, 3,
		0x7, 3,
		0x8, 3,
		0x9, 3,
		0xA, 3,
		0xB, 3,
		0x0, 3,
		0x1, 3,
		0x2, 3,
		0x3, 3,
		0x4, 3,
		0x5, 3,
		0x6, 3,
		0x7, 3,
		0x8, 3,
		0x9, 3,
		0xA, 3,
		0xB, 3,
		0xC, 52,
		-1
	};

	gEfxBgSemaphore++;

	proc = SpawnProc(ProcScr_EfxForblazeBG1, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->frame = 0;
	proc->frame_config = frame_config;
	proc->tsal = TsaArray_EfxForblazeBG1;
	proc->tsar = TsaArray_EfxForblazeBG1;
	proc->img = ImgArray_EfxForblazeBG1;

	SpellFx_RegisterBgPal(Pal_EfxForblazeBG1, PLTT_SIZE_4BPP);

	if (gEkrDistanceType != EKR_DISTANCE_CLOSE) {
		if (GetAnimPosition(proc->anim) == POS_L)
			SetBgOffset(BG_1, 0x18, 0);
		else
			SetBgOffset(BG_1, 0xE8, 0);
	}

	SpellFx_SetSomeColorEffect();
}

void EfxForblazeBG1_Loop(struct ProcEfxBG *proc)
{
	int ret = EfxAdvanceFrameLut((s16 *)&proc->timer, (s16 *)&proc->frame, proc->frame_config);

	if (ret >= 0) {
		u16 ** tsaL = proc->tsal;
		u16 ** tsaR = proc->tsar;
		u16 ** img = proc->img;

		SpellFx_RegisterBgGfx(*(img + ret), 32 * 8 * CHR_SIZE);
		SpellFx_WriteBgMap(proc->anim, *(tsaL + ret), *(tsaR + ret));

		FillBGRect(gBg1Tm + TM_OFFSET(0x1E, 0), 2, 20,
			BGPAL_EFX_SPELL_BG, VRAMOFF_BANIM_SPELL_23E0 / CHR_SIZE);
		return;
	}

	if (ret == -1) {
		SpellFx_ClearBG1();
		gEfxBgSemaphore--;
		SpellFx_ClearColorEffects();
		Proc_Break(proc);
	}
}

void NewEfxForblazeBGCOL1(struct Anim *anim, int duration)
{
	struct ProcEfxBGCOL *proc;

	static const u16 frame_config[] = {
		0x0, 2,
		0x1, 2,
		0x2, 2,
		0x1, 2,
		-2 // !
	};

	gEfxBgSemaphore++;

	proc = SpawnProc(ProcScr_EfxForblazeBGCOL1, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->timer2 = 0;
	proc->terminator = duration;
	proc->frame = 0;
	proc->frame_config = frame_config;
	proc->pal = Pal_EfxForblazeBG1;

	SpellFx_RegisterBgPal(Pal_EfxForblazeBG1, PLTT_SIZE_4BPP);
}

void EfxForblazeBGCOL1_Loop(struct ProcEfxBGCOL *proc)
{
	int ret = EfxAdvanceFrameLut((i16 *)&proc->timer, (i16 *)&proc->frame, proc->frame_config);

	if (ret >= 0) {
		const u16 *pal = proc->pal;

		SpellFx_RegisterBgPal(pal + PAL_OFFSET(ret), PLTT_SIZE_4BPP);
	}

	proc->timer2++;
	if (proc->timer2 == proc->terminator) {
		gEfxBgSemaphore--;
		Proc_Break(proc);
	}
}

void NewEfxForblazeBGCtrl1(void)
{
	gEfxBgSemaphore++;

	SpawnProc(ProcScr_EfxForblazeBGCtrl1, PROC_TREE_3);
}

void EfxForblazeBGCtrl1_Loop1(ProcPtr proc)
{
	gDispIo.bg_off[BG_1].y = 8;

	Proc_Break(proc);
}

void EfxForblazeBGCtrl1_Loop2(ProcPtr proc)
{
	gDispIo.bg_off[BG_1].y = 16;

	Proc_Break(proc);
}

void EfxForblazeBGCtrl1_Loop3(ProcPtr proc)
{
	gDispIo.bg_off[BG_1].y = 24;

	gEfxBgSemaphore--;
	Proc_Break(proc);
}

void NewEfxForblazeObjHandle(struct Anim *anim, int duration)
{
	struct ProcEfx *proc;

	gEfxBgSemaphore++;

	proc = SpawnProc(ProcScr_EfxForblazeObjHandle, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->step = duration;

	proc->unk30 = 0;
	proc->unk44 = 1;
	proc->unk48 = 0;

	SpellFx_RegisterObjGfx(Img_EfxForblazeOBJ, 0x1000);
	SpellFx_RegisterObjPal(Pal_EfxForblazeOBJ, PLTT_SIZE_4BPP);
}

void EfxForblazeObjHandle_Loop(struct ProcEfx *proc)
{
	int x;

	proc->timer++;

	if (proc->timer == proc->step) {
		gEfxBgSemaphore--;
		Proc_Break(proc);
		return;
	}

	if (++proc->unk30 != proc->unk44)
		return;

	proc->unk30 = 0;
	proc->unk44 = 2;

	if (XposArray_EfxForblazeOBJ[proc->unk48] == -1)
        proc->unk48 = 0;

    x =  XposArray_EfxForblazeOBJ[proc->unk48++];

	NewEfxForblazeOBJ(proc->anim, x, 0x50);
}

void NewEfxForblazeOBJ(struct Anim *anim, int x, int y)
{
	struct Anim *anim2;
	struct ProcEfxMagicOBJ *proc;

	gEfxBgSemaphore++;
	proc = SpawnProc(ProcScr_EfxForblazeOBJ, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->terminator = 0xC;
	anim2 = EfxCreateFrontAnim(anim, AnimScr_EfxForblazeOBJ, AnimScr_EfxForblazeOBJ, AnimScr_EfxForblazeOBJ, AnimScr_EfxForblazeOBJ);
	proc->anim2 = anim2;

	anim2->xPosition = x;
	anim2->yPosition = y;
}

void EfxForblazeOBJ_Loop(struct ProcEfxMagicOBJ *proc)
{
	proc->timer++;

	if (proc->timer > proc->terminator) {
		gEfxBgSemaphore--;
		BasRemove(proc->anim2);
		Proc_Break(proc);
	}
}

void NewEfxForblazeBG2(struct Anim *anim, int duration)
{
	struct ProcEfxBG *proc;

	gEfxBgSemaphore++;
	proc = SpawnProc(ProcScr_EfxForblazeBG2, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->terminator = duration;
	proc->unk30 = 0;

	LZ77UnCompWram(Img1_EfxForblazeBG2, gSpellAnimBgfx);
	LZ77UnCompWram(Img2_EfxForblazeBG2, gBuf_Banim + 0x1000);
	LZ77UnCompWram(Tsa1_EfxForblazeBG2, gEkrTsaBuffer);
	LZ77UnCompWram(Tsa2_EfxForblazeBG2, gEkrTsaBuffer + 0x400);

	EnableBgSync(BG1_SYNC_BIT);

	SpellFx_SetSomeColorEffect();
	SetWinEnable(0, 0, 0);
}

void EfxForblazeBG2_Loop(struct ProcEfxBG *proc)
{
	if ((proc->timer & 1) == 0) {
		const u16 *pal_src;

		switch (proc->unk30) {
		case 0:
			pal_src = Pal1_EfxForblazeBG2;
			break;

		case 1:
			pal_src = Pal2_EfxForblazeBG2;
			break;

		case 2:
			pal_src = Pal3_EfxForblazeBG2;
			break;

		default:
			pal_src = NULL;
			break;
		}

		SpellFx_RegisterBgPal(pal_src, PLTT_SIZE_4BPP);

		proc->unk30++;
		if (proc->unk30 == 3)
			proc->unk30 = 0;

		RegisterDataMove(
			gSpellAnimBgfx,
			(u8 *)BG_VRAM + BGCHR_EFXMAGIC_100 * CHR_SIZE,
			CHR_SIZE * 0x100);

		EfxTmCpyBG(
			gEkrTsaBuffer,
			gBg1Tm,
			0x20, 0x10, BGPAL_EFXMAGIC_1, OAM2_CHR(BGCHR_EFXMAGIC_100));

		EnableBgSync(BG1_SYNC_BIT);
	} else {
		SpellFx_RegisterBgPal(Pal4_EfxForblazeBG2, PLTT_SIZE_4BPP);

		RegisterDataMove(
			gBuf_Banim + 0x1000,
			(u8 *)BG_VRAM + BGCHR_EFXMAGIC_100 * CHR_SIZE,
			CHR_SIZE * 0x80);

		EfxTmCpyBG(
			gEkrTsaBuffer + 0x800 / sizeof(gEkrTsaBuffer[0]),
			gBg1Tm,
			0x20, 0x10, BGPAL_EFXMAGIC_1, OAM2_CHR(BGCHR_EFXMAGIC_100));

		EnableBgSync(BG1_SYNC_BIT);
	}

	proc->timer++;
	if (proc->timer == proc->terminator) {
		SpellFx_ClearBG1();
		gEfxBgSemaphore--;
		SpellFx_ClearColorEffects();
		Proc_End(proc);
	}
}

void NewEfxForblazeOBJCtrl(struct Anim *anim)
{
	struct ProcEfxMagic *proc;

	gEfxBgSemaphore++;

	proc = SpawnProc(ProcScr_EfxForblazeOBJCtrl, PROC_TREE_3);

	proc->anim = anim;
	proc->timer = 0;
	proc->step = 0;
	proc->unk44 = 2;
	proc->unk48 = 0;

	SpellFx_RegisterObjGfx(Img_EfxForblazeOBJ, 0x1000);
	SpellFx_RegisterObjPal(Pal_EfxForblazeOBJ, PLTT_SIZE_4BPP);
}

void EfxForblazeOBJCtrl_Loop(struct ProcEfxMagic *proc)
{
	proc->timer++;

	if (proc->timer == 0x41) {
		gEfxBgSemaphore--;
		Proc_Break(proc);
		return;
	}

	if (++proc->step == proc->unk44) {
		struct Anim *anim;
		int tmp1;
		int tmp2;

		proc->step = 0;
		proc->unk44 = 2;

		anim = proc->anim;
		tmp2 = proc->unk48;
		tmp1 = tmp2++;
		proc->unk48 = tmp2;
		NewEfxForblazeOBJFall(anim, tmp1, tmp2);

		anim = proc->anim;
		tmp2 = proc->unk48;
		tmp1 = tmp2++;
		proc->unk48 = tmp2;
		NewEfxForblazeOBJFall(anim, tmp1, tmp2);
	}
}

void NewEfxForblazeOBJFall(struct Anim *anim, int type, int unused)
{
	u32 tmp;
	struct Anim *new_anim;
	struct ProcEfxOBJ *proc;

	u16 array[] = {
		10, 15, 27, 12, 20, 22, 18, 30
	};

	gEfxBgSemaphore++;

	proc = SpawnProc(ProcScr_EfxForblazeOBJFall, PROC_TREE_3);

	proc->anim = anim;

	new_anim = NULL;

	proc->timer = 0;
	proc->terminator = array[type & 7];
	proc->unk32 = BanimSpawnRandB(0xE0) + 8;
	proc->unk3A = 0;

	tmp = BanimSpawnRandB(9);

	switch (tmp) {
	case 0 ... 6:
		proc->anim2 = new_anim = BasCreate(AnimScr_EfxForblazeOBJ6, 0x78);
		break;

	case 7:
		proc->anim2 = new_anim = BasCreate(AnimScr_EfxForblazeOBJ5, 0x78);
		break;

	case 8:
		proc->anim2 = new_anim = BasCreate(AnimScr_EfxForblazeOBJ4, 0x78);
		break;

	case 9:
		proc->anim2 = new_anim = BasCreate(AnimScr_EfxForblazeOBJ3, 0x78);
		break;

	default:
		break;
	}

	if (new_anim == NULL) {
		gEfxBgSemaphore--;
		Proc_End(proc);
		return;
	}

	new_anim->oam2 = OAM2_PAL(2) + OAM2_CHR(0x40) + OAM2_LAYER(1);
	new_anim->xPosition = proc->unk32;
	new_anim->yPosition = proc->unk3A;
}

void EfxForblazeOBJFall_Loop(struct ProcEfxOBJ *proc)
{
	int ret;
	struct Anim *sub_anim = proc->anim2;

	if (proc->timer > proc->terminator) {
		gEfxBgSemaphore--;
		BasRemove(sub_anim);
		Proc_Break(proc);
		return;
	}

	ret = Interpolate(
		INTERPOLATE_SQUARE,
		0x78,
		8,
		proc->timer,
		proc->terminator);

	sub_anim->yPosition = ret;
	proc->timer++;
}

void HBlank_EfxForblaze(void)
{
	if (!(REG_DISPSTAT & DISPSTAT_VBLANK)) {
		REG_BG1HOFS = *gpBg2ScrollOffset;
		REG_BG1VOFS = *gpBg2ScrollOffset;

		gpBg2ScrollOffset++;
	}
}

void NewEfxForblazeRST(int duration)
{
	struct ProcEfxMagic *proc;

	gEfxBgSemaphore++;
	proc = SpawnProc(ProcScr_EfxForblazeRST, PROC_TREE_3);

	proc->timer = 0,
	proc->step = duration;
	proc->unk30 = 0;
}

void EfxForblazeRST_Loop(struct ProcEfxMagic *proc)
{
	u32 i;
	u16 *buf;

	if (gEkrBg1ScrollFlip == 0)
		buf = gpBg2ScrollOffsetTable2;
	else
		buf = gpBg2ScrollOffsetTable1;

	for (i = 0; i < 0xA0; i++) {
		int tang = SIN_Q12(i * 2 + proc->unk30);

		*(buf++) = (tang >> 10) + 4;
	}

	proc->unk30 += 2;
	proc->timer++;

	if (proc->timer > proc->step) {
		gEfxBgSemaphore--;
		Proc_Break(proc);
	}
}

struct ProcScr CONST_DATA ProcScr_EfxDivine[] = {
	PROC_NAME_DEBUG("efxDivine"),
	PROC_REPEAT(EfxDivine_Loop),
	PROC_END,
};

struct ProcScr CONST_DATA ProcScr_EfxDivineBG[] = {
	PROC_NAME_DEBUG("efxDivineBG"),
	PROC_REPEAT(EfxDivineBG_Loop),
	PROC_END,
};

CONST_DATA u16 *ImgArray_EfxDivineBG[] = {
	Img_EfxDivineBG1_081762DC,
	Img_EfxDivineBG1_081762DC,
	Img_EfxDivineBG1_081762DC,
	Img_EfxDivineBG1_081762DC,
	Img_EfxDivineBG1_081762DC,
	Img_EfxDivineBG1_081762DC,
	Img_EfxDivineBG1_081762DC,
	Img_EfxDivineBG1_081762DC,
	Img_EfxDivineBG1_081762DC,
	Img_EfxDivineBG1_081762DC,
	Img_EfxDivineBG1_081762DC,
	Img_EfxDivineBG1_081762DC,
	Img_EfxDivineBG1_081762DC,
	Img_EfxDivineBG1_081762DC,
	Img_EfxDivineBG1_081762DC,
	Img_EfxDivineBG1_081762DC,
	Img_EfxDivineBG1_081762DC,
	Img_EfxDivineBG1_081762DC,
	Img_EfxDivineBG1_081762DC,
	Img_EfxDivineBG1_081762DC,
};

CONST_DATA u16 *TsaArray_EfxDivineBG[] = {
	Tsa_EfxDivineBG1_08179AB8,
	Tsa_EfxDivineBG1_08179B58,
	Tsa_EfxDivineBG1_08179C00,
	Tsa_EfxDivineBG1_08179CA8,
	Tsa_EfxDivineBG1_08179D58,
	Tsa_EfxDivineBG1_08179E10,
	Tsa_EfxDivineBG1_08179EDC,
	Tsa_EfxDivineBG1_08179FA8,
	Tsa_EfxDivineBG1_0817A07C,
	Tsa_EfxDivineBG1_0817A154,
	Tsa_EfxDivineBG1_0817A230,
	Tsa_EfxDivineBG1_0817A30C,
	Tsa_EfxDivineBG1_0817A3F0,
	Tsa_EfxDivineBG1_0817A4A4,
	Tsa_EfxDivineBG1_0817A540,
	Tsa_EfxDivineBG1_0817A5DC,
	Tsa_EfxDivineBG1_0817A678,
	Tsa_EfxDivineBG1_0817A714,
	Tsa_EfxDivineBG1_0817A7B0,
	Tsa_EfxDivineBG1_0817A84C,
};

CONST_DATA u16 *ImgArray_EfxDivineBG2[] = {
	Img_EfxDivineBG1_081762DC,
	Img_EfxDivineBG1_081762DC,
	Img_EfxDivineBG1_081762DC,
};

CONST_DATA u16 *TsaArray_EfxDivineBG2[] = {
	Tsa_EfxDivineBG2_0817A8E8,
	Tsa_EfxDivineBG2_0817A984,
	Tsa_EfxDivineBG2_0817AA20,
};

CONST_DATA u16 *ImgArray_EfxDivineBG3[] = {
	Img_EfxDivineBG3_0816E3CC,
	Img_EfxDivineBG3_0816E3CC,
	Img_EfxDivineBG3_0816E980,
	Img_EfxDivineBG3_0816F048,
	Img_EfxDivineBG3_0816F688,
	Img_EfxDivineBG3_0816FC90,
	Img_EfxDivineBG3_081702F0,
	Img_EfxDivineBG3_08170960,
	Img_EfxDivineBG3_08170F9C,
	Img_EfxDivineBG3_081715E4,
	Img_EfxDivineBG3_08171CE8,
	Img_EfxDivineBG3_081724A0,
	Img_EfxDivineBG3_08172C94,
	Img_EfxDivineBG3_0817346C,
	Img_EfxDivineBG3_08173C88,
	Img_EfxDivineBG3_08174408,
	Img_EfxDivineBG3_08174B9C,
	Img_EfxDivineBG3_081752D0,
	Img_EfxDivineBG3_081752D0,
	Img_EfxDivineBG3_08175D7C,
	Img_EfxDivineBG3_08175D7C,
};

CONST_DATA u16 *TsaArray_EfxDivineBG3[] = {
	Tsa_EfxDivineBG3_08176A8C,
	Tsa_EfxDivineBG3_08176C20,
	Tsa_EfxDivineBG3_08176E24,
	Tsa_EfxDivineBG3_081770F4,
	Tsa_EfxDivineBG3_081773C4,
	Tsa_EfxDivineBG3_08177674,
	Tsa_EfxDivineBG3_08177928,
	Tsa_EfxDivineBG3_08177BB4,
	Tsa_EfxDivineBG3_08177E38,
	Tsa_EfxDivineBG3_081780AC,
	Tsa_EfxDivineBG3_08178340,
	Tsa_EfxDivineBG3_081785C8,
	Tsa_EfxDivineBG3_08178864,
	Tsa_EfxDivineBG3_08178AEC,
	Tsa_EfxDivineBG3_08178D68,
	Tsa_EfxDivineBG3_08178F98,
	Tsa_EfxDivineBG3_081791E8,
	Tsa_EfxDivineBG3_08179418,
	Tsa_EfxDivineBG3_08179610,
	Tsa_EfxDivineBG3_081797F4,
	Tsa_EfxDivineBG3_08179990,
};

struct ProcScr CONST_DATA ProcScr_EfxDivineOBJ[] = {
	PROC_NAME_DEBUG("efxDivineOBJ"),
	PROC_REPEAT(EfxDivineOBJ_Loop),
	PROC_END,
};

struct ProcScr CONST_DATA ProcScr_EfxAureola[] = {
	PROC_NAME_DEBUG("efxAureola"),
	PROC_REPEAT(EfxAureola_Loop),
	PROC_END,
};

struct ProcScr CONST_DATA ProcScr_EfxAureolaBG[] = {
	PROC_NAME_DEBUG("efxAureolaBG"),
	PROC_REPEAT(EfxAureolaBG_Loop),
	PROC_END,
};

CONST_DATA u16 *ImgArray_EfxAureolaBG[] = {
	Img_EfxAureolaBG2,
	Img_EfxAureolaBG_081BA374,
	Img_EfxAureolaBG_081BA374,
	Img_EfxAureolaBG_081BA374,
	Img_EfxAureolaBG_081BA374,
};

CONST_DATA u16 *TsaArray_EfxAureolaBG[] = {
	Tsa_EfxAureolaBG_081BB3DC,
	Tsa_EfxAureolaBG_081BB75C,
	Tsa_EfxAureolaBG_081BB8E0,
	Tsa_EfxAureolaBG_081BBA04,
	Tsa_EfxAureolaBG_081BBB00,
};

struct ProcScr CONST_DATA ProcScr_EfxAureolaBG2[] = {
	PROC_NAME_DEBUG("efxAureolaBG2"),
	PROC_REPEAT(EfxAureolaBG2_Loop),
	PROC_END,
};

struct ProcScr CONST_DATA ProcScr_EfxAureolaBG2COL[] = {
	PROC_NAME_DEBUG("efxAureolaBG2COL"),
	PROC_MARK(PROC_MARK_PAL_CHG),
	PROC_REPEAT(EfxAureolaBG2COL_Loop),
	PROC_END,
};

struct ProcScr CONST_DATA ProcScr_EfxAureolaOBJ[] = {
	PROC_NAME_DEBUG("efxAureolaOBJ"),
	PROC_REPEAT(EfxAureolaOBJ_Loop),
	PROC_END,
};

struct ProcScr CONST_DATA ProcScr_EfxAureolaOBJCtrl[] = {
	PROC_NAME_DEBUG("efxAureolaOBJCtrl"),
	PROC_REPEAT(EfxAureolaOBJCtrl_Loop),
	PROC_END,
};

struct ProcScr CONST_DATA ProcScr_EfxAureolaOBJ2[] = {
	PROC_NAME_DEBUG("efxAureolaOBJ2"),
	PROC_REPEAT(EfxAureolaOBJ2_Loop),
	PROC_END,
};

struct ProcScr CONST_DATA ProcScr_EfxAureolaOBJ3[] = {
	PROC_NAME_DEBUG("efxAureolaOBJ3"),
	PROC_REPEAT(EfxAureolaOBJ3_Loop),
	PROC_END,
};

struct ProcScr CONST_DATA ProcScr_EfxAureolaOBJ3Ctrl[] = {
	PROC_NAME_DEBUG("efxAureolaOBJ3Ctrl"),
	PROC_REPEAT(EfxAureolaOBJ3Ctrl_Loop),
	PROC_END,
};

/**
 * Divine
 */
void StartSpellAnimDivine(struct Anim *anim)
{
	struct ProcEfx *proc;

	SpellFx_Begin();
	NewEfxSpellCast();
	SpellFx_ClearBG1Position();

	proc = SpawnProc(ProcScr_EfxDivine, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->hitted = CheckRoundMiss(GetAnimRoundTypeAnotherSide(anim));
}

void EfxDivine_Loop(struct ProcEfx *proc)
{
	struct Anim *anim = GetAnimAnotherSide(proc->anim);
	int duration = EfxGetCamMovDuration();

	proc->timer++;

	if (proc->timer == 1) {
		PlaySFX(0x127, 0x100, proc->anim->xPosition, 1);
		NewEfxDivineBG(anim);
		NewEfxDivineOBJ(proc->anim);
		return;
	}

	if (proc->timer == 20) {
		PlaySFX(0x128, 0x100, proc->anim->xPosition, 1);
		return;
	}

	if (proc->timer == 50) {
		NewEfxFarAttackWithDistance(proc->anim, -1);
		return;
	}

	if (proc->timer == duration + 70) {
		NewEfxDivineBG2(anim);
		PlaySFX(0x129, 0x100, anim->xPosition, 1);
		return;
	}

	if (proc->timer == duration + 73) {
		NewEfxFlashBgWhite(proc->anim, 10);
		return;
	}

	if (proc->timer == duration + 75) {
		NewEfxDivineBG3(anim);

		anim->flags3 |= (ANIM_BIT3_C02_BLOCK_END | ANIM_BIT3_C01_BLOCK_END_INBATTLE);

		StartBattleAnimHitEffectsDefault(anim, proc->hitted);

		if (!proc->hitted)
			EfxPlayHittedSFX(anim);

		return;
	}

	if (proc->timer == duration + 90)
		return;

	if (proc->timer == 100) {
		SpellFx_Finish();
		EndEfxSpellCastAsync();
		Proc_Break(proc);
	}
}

void NewEfxDivineBG(struct Anim *anim)
{
	struct ProcEfxBG *proc;

	static const u16 frames[] = {
		0x0, 2,
		0x1, 2,
		0x2, 2,
		0x3, 2,
		0x4, 2,
		0x5, 2,
		0x7, 1,
		0x5, 1,
		0x7, 1,
		0x5, 1,
		0x7, 1,
		0x5, 1,
		0x7, 1,
		0x6, 2,
		0x7, 2,
		0x8, 2,
		0x9, 2,
		0xA, 2,
		0xB, 2,
		0xC, 2,
		0xD, 2,
		0xE, 2,
		0xF, 2,
		0x10, 2,
		0x11, 2,
		0x12, 2,
		0x13, 2,
		-1
	};

	gEfxBgSemaphore++;

	proc = SpawnProc(ProcScr_EfxDivineBG, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->frame = 0;
	proc->frame_config = frames;
	proc->tsal = TsaArray_EfxDivineBG;
	proc->tsar = TsaArray_EfxDivineBG;
	proc->img = ImgArray_EfxDivineBG;

	SpellFx_RegisterBgPal(Pal_EfxDivineBG, PLTT_SIZE_4BPP);

	if (gEkrDistanceType != EKR_DISTANCE_CLOSE) {
		if (GetAnimPosition(proc->anim) == POS_L)
			SetBgOffset(BG_1, 232, 0);
		else
			SetBgOffset(BG_1, 24, 0);
	}

	SpellFx_SetSomeColorEffect();
}

void NewEfxDivineBG2(struct Anim *anim)
{
	struct ProcEfxBG *proc;

	static const u16 frames[] = {
		0x0, 1,
		0x1, 1,
		0x2, 1,
		-1
	};

	gEfxBgSemaphore++;

	proc = SpawnProc(ProcScr_EfxDivineBG, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->frame = 0;
	proc->frame_config = frames;
	proc->tsal = TsaArray_EfxDivineBG2;
	proc->tsar = TsaArray_EfxDivineBG2;
	proc->img = ImgArray_EfxDivineBG2;

	SpellFx_RegisterBgPal(Pal_EfxDivineBG, PLTT_SIZE_4BPP);

	if (gEkrDistanceType != EKR_DISTANCE_CLOSE) {
		if (GetAnimPosition(proc->anim) == POS_L)
			SetBgOffset(BG_1, 24, 0);
		else
			SetBgOffset(BG_1, 232, 0);
	}

	SpellFx_SetSomeColorEffect();
}

void NewEfxDivineBG3(struct Anim *anim)
{
	struct ProcEfxBG *proc;

	static const u16 frames[] = {
		0x0, 2,
		0x1, 2,
		0x2, 2,
		0x3, 2,
		0x4, 2,
		0x5, 2,
		0x6, 2,
		0x7, 2,
		0x8, 2,
		0x9, 2,
		0xA, 2,
		0xB, 2,
		0xC, 2,
		0xD, 2,
		0xE, 2,
		0xF, 2,
		0x10, 2,
		0x11, 2,
		0x12, 2,
		0x13, 2,
		0x14, 2,
		-1
	};

	gEfxBgSemaphore++;

	proc = SpawnProc(ProcScr_EfxDivineBG, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->frame = 0;
	proc->frame_config = frames;

	proc->tsal = TsaArray_EfxDivineBG3;
	proc->tsar = TsaArray_EfxDivineBG3;
	proc->img = ImgArray_EfxDivineBG3;

	SpellFx_RegisterBgPal(Pal_EfxDivineBG3, PLTT_SIZE_4BPP);

	if (gEkrDistanceType != EKR_DISTANCE_CLOSE) {
		if (GetAnimPosition(proc->anim) == POS_L)
			SetBgOffset(BG_1, 24, 0);
		else
			SetBgOffset(BG_1, 232, 0);
	}

	SpellFx_SetSomeColorEffect();
}

void EfxDivineBG_Loop(struct ProcEfxBG *proc)
{
	int ret = EfxAdvanceFrameLut((s16 *)&proc->timer, (s16 *)&proc->frame, proc->frame_config);

	if (ret >= 0) {
		u16 ** tsaL = proc->tsal;
		u16 ** tsaR = proc->tsar;
		u16 ** img = proc->img;

		SpellFx_RegisterBgGfx(*(img + ret), 32 * 8 * CHR_SIZE);
		SpellFx_WriteBgMap(proc->anim, *(tsaL + ret), *(tsaR + ret));
		return;
	}

	if (ret == -1) {
		SpellFx_ClearBG1();
		gEfxBgSemaphore--;
		SpellFx_ClearColorEffects();
		Proc_Break(proc);
	}
}

void NewEfxDivineOBJ(struct Anim *anim)
{
	struct ProcEfxOBJ *proc;
	struct Anim * frontAnim;

	gEfxBgSemaphore++;

	proc = SpawnProc(ProcScr_EfxDivineOBJ, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;

	frontAnim = EfxCreateFrontAnim(anim, AnimScr_EfxDivineOBJ, AnimScr_EfxDivineOBJ, AnimScr_EfxDivineOBJ, AnimScr_EfxDivineOBJ);
	proc->anim2 = frontAnim;

	if (GetAnimPosition(anim) == POS_L)
		frontAnim->xPosition -= 6;
	else
		frontAnim->xPosition += 6;

	SpellFx_RegisterObjPal(Pal_EfxDivineOBJ, PLTT_SIZE_4BPP);
	SpellFx_RegisterObjGfx(Img_EfxDivineOBJ, 32 * 4 * CHR_SIZE);
}

void EfxDivineOBJ_Loop(struct ProcEfxOBJ *proc)
{
	proc->timer++;

	if (proc->timer == 44) {
		BasRemove(proc->anim2);
		gEfxBgSemaphore--;
		Proc_Break(proc);
	}
}

/**
 * Aureola
 */
void StartSpellAnimAureola(struct Anim *anim)
{
	struct ProcEfx *proc;

	SpellFx_Begin();
	NewEfxSpellCast();
	SpellFx_ClearBG1Position();

	proc = SpawnProc(ProcScr_EfxAureola, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->hitted = CheckRoundMiss(GetAnimRoundTypeAnotherSide(anim));
}

void EfxAureola_Loop(struct ProcEfx *proc)
{
	struct Anim *anim = GetAnimAnotherSide(proc->anim);
	int duration = EfxGetCamMovDuration();

	proc->timer++;

	if (proc->timer == 1)
		NewEfxFarAttackWithDistance(proc->anim, -1);

	if (proc->timer == duration + 1) {
		NewEfxAureolaBG(anim);

		SetBlendAlpha(0, 0x10);
		NewEfxALPHA(anim, 0, 0x20, 0, 0x10, 0);
		NewEfxAureolaOBJ(anim, 0xAA);
		PlaySFX(SONG_12A, 0x100, anim->xPosition, 1);
		return;
	}

	if (proc->timer == duration + 0x11B) {
		PlaySFX(SONG_12B, 0x100, anim->xPosition, 1);
		return;
	}

	if (proc->timer == duration + 0x13B) {
		NewEfxAureolaOBJ2(anim, 0x19);
		return;
	}

	if (proc->timer == duration + 0x154) {
		NewEfxFlashBgWhite(anim, 0xC);
		anim->flags3 |= ANIM_BIT3_C02_BLOCK_END | ANIM_BIT3_C01_BLOCK_END_INBATTLE;
		StartBattleAnimHitEffectsAlt(anim, proc->hitted);

		if (proc->hitted == EKR_HITTED)
			EfxPlayHittedSFX(anim);

		return;
	}

	if (proc->timer == duration + 0x15A) {
		PlaySFX(SONG_12C, 0x100,0x78, 0);
		NewEfxMagicQUAKE(anim, 0x64);
		NewEfxAureolaBG2(anim, 0x64);
		NewEfxAureolaBG2COL(anim, 0x64);
		NewEfxALPHA(anim, 0x46, 0x1E, 0x10, 0, 0);
		NewEfxAureolaOBJ3(anim);
		return;
	}

	if (proc->timer == duration + 0x1EA) {
		SpellFx_Finish();
		EndEfxSpellCastAsync();
		Proc_Break(proc);
	}
}

void NewEfxAureolaBG(struct Anim *anim)
{
	struct ProcEfxBG *proc;

	static const u16 frames[] = {
		0x0, 200,
		0x1, 2,
		0x2, 2,
		0x3, 2,
		0x4, 134,
		-1
	};

	gEfxBgSemaphore++;

	proc = SpawnProc(ProcScr_EfxAureolaBG, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->frame = 0;
	proc->frame_config = frames;
	proc->tsal = TsaArray_EfxAureolaBG;
	proc->img  = ImgArray_EfxAureolaBG;

	SpellFx_RegisterBgPal(Pal_EfxAureolaBG, 0x20);
	SpellFx_ClearBG1Position();
	SpellFx_SetSomeColorEffect();

	if (gEkrDistanceType == EKR_DISTANCE_CLOSE) {	
		if (GetAnimPosition(proc->anim) == POS_L)
			SetBgOffset(BG_1, 0xF8, 0x0);
		else
			SetBgOffset(BG_1, 0x18, 0x0);
	} else {
		if (GetAnimPosition(proc->anim) == POS_L)
			SetBgOffset(BG_1, 0x10, 0x0);
	}
}

void EfxAureolaBG_Loop(struct ProcEfxBG *proc)
{
	int ret = EfxAdvanceFrameLut((i16 *)&proc->timer, (i16 *)&proc->frame, proc->frame_config);

	if (ret >= 0) {
		u16 **buf = proc->tsal;
		u16 **img = proc->img;

		SpellFx_RegisterBgGfx(img[ret], 0x2000);
		SpellFx_WriteBgMapExt(proc->anim, buf[ret],0x20, 0x14);
		return;
	}

	if (ret == -1) {
		SpellFx_ClearBG1();
		gEfxBgSemaphore--;
		SpellFx_ClearColorEffects();
		Proc_Break(proc);
	}
}

void NewEfxAureolaBG2(struct Anim *anim, int duration)
{
	struct ProcEfxBG *proc;

	gEfxBgSemaphore++;

	proc = SpawnProc(ProcScr_EfxAureolaBG2, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->terminator = duration;
	proc->unk32 = 0;
	proc->unk3A = 0;
	proc->unk34 = 0;
	proc->unk3C = 0;

	SpellFx_RegisterBgGfx(Img_EfxAureolaBG2, 0x2000);
	SpellFx_RegisterBgPal(Pal_EfxAureolaBG2, 0x20);
	SpellFx_ClearBG1Position();
	SpellFx_SetSomeColorEffect();
}

void EfxAureolaBG2_Loop(struct ProcEfxBG *proc)
{
	if (1 & proc->timer) {
		int x = (proc->unk32 -= 12);
		int y = (proc->unk3A += 12);

		gDispIo.bg_off[BG_1].x = x;
		gDispIo.bg_off[BG_1].y = y;

		LZ77UnCompWram(Tsa_EfxAureolaBG2, gEkrTsaBuffer);
		EfxTmCpyBG(gEkrTsaBuffer, gBg1Tm, 32, 32, BGPAL_EFX_SPELL_BG, VRAMOFF_BANIM_SPELL_BG / CHR_SIZE);
		EnableBgSync(BG1_SYNC_BIT);
	} else {
		int x = (proc->unk34 += 8);
		int y = (proc->unk3C += 8);

		gDispIo.bg_off[BG_1].x = x;
		gDispIo.bg_off[BG_1].y = y;

		LZ77UnCompWram(Tsa_EfxAureolaBG2, gEkrTsaBuffer);
		EfxTmCpyBgHFlip(gEkrTsaBuffer, gBg1Tm, 32, 32, BGPAL_EFX_SPELL_BG, VRAMOFF_BANIM_SPELL_BG / CHR_SIZE);
		EnableBgSync(BG1_SYNC_BIT);
	}

	proc->timer++;
	if (proc->timer == proc->terminator) {
		SpellFx_ClearBG1();
		SpellFx_ClearColorEffects();
		gEfxBgSemaphore--;
		Proc_Break(proc);
	}
}

void NewEfxAureolaBG2COL(struct Anim *anim, int duration)
{
	struct ProcEfxBGCOL *proc;

	static const u16 frames[] = {
		0x0, 1,
		0x1, 1,
		0x2, 1,
		0x1, 1,
		-2
	};

	gEfxBgSemaphore++;
	proc = SpawnProc(ProcScr_EfxAureolaBG2COL, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->timer2 = 0;
	proc->terminator = duration;
	proc->frame = 0;
	proc->frame_config = frames;
	proc->pal = Pal_EfxAureolaBG2;

	SpellFx_RegisterBgPal(Pal_EfxAureolaBG2, 0x20);
}

void EfxAureolaBG2COL_Loop(struct ProcEfxBGCOL *proc)
{
	int ret = EfxAdvanceFrameLut((i16 *)&proc->timer, (i16 *)&proc->frame, proc->frame_config);

	if (ret >= 0) {
		const u16 *pal = proc->pal;

		SpellFx_RegisterBgPal(pal + PAL_OFFSET(ret), 0x20);
	}

	proc->timer2++;
	if (proc->timer2 == proc->terminator) {
		gEfxBgSemaphore--;
		Proc_Break(proc);
	}
}

void NewEfxAureolaOBJ(struct Anim *anim, int duration)
{
	struct ProcEfxMagic *proc;

	gEfxBgSemaphore++;
	proc = SpawnProc(ProcScr_EfxAureolaOBJ, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->step = duration;
	proc->unk30 = 0;
	proc->unk44 = 10;
	proc->unk48 = 0;


	SpellFx_RegisterObjPal(Pal_EfxAureolaOBJ, 0x20);
	SpellFx_RegisterObjGfx(Img_EfxAureolaOBJ, 0x1000);
}

void EfxAureolaOBJ_Loop(struct ProcEfxMagic *proc)
{
	int i;

	proc->timer++;

	if (proc->timer == proc->step) {
		gEfxBgSemaphore--;
		Proc_Break(proc);
		return;
	}

	i = ++proc->unk30;
	if (i == proc->unk44) {
		proc->unk30 = 0;
		proc->unk44 = 10;
		NewEfxAureolaOBJCtrl(proc->anim, proc->unk48++);
	}
}

void NewEfxAureolaOBJCtrl(struct Anim *anim, int unused)
{
	int rn1, rn2;
	struct Anim *anim2;
	struct ProcEfxAureolaOBJ *proc;

	gEfxBgSemaphore++;

	proc = SpawnProc(ProcScr_EfxAureolaOBJCtrl, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->step = BanimSpawnRandB(0x1E) + 0x8C;

	rn1 = BanimSpawnRandB(0x1E);
	rn2 = BanimSpawnRandB(0x1E);
	proc->unk32 = rn1 + 0x46;
	proc->unk34 = rn2 + 0x28;
	proc->unk3A = 0xFFEC;
	proc->unk3C = 0xA0;

	if (gEkrDistanceType == EKR_DISTANCE_CLOSE) {
		proc->unk32 = rn1 + 0x5E;
		proc->unk34 = rn2 + 0x40;
	}

	if (GetAnimPosition(anim) == POS_R) {
		proc->unk32 = 0xF0 - proc->unk32;
		proc->unk34 = 0xF0 - proc->unk34;
	}

	switch (BanimSpawnRandB(2)) {
	case 0:
		anim2 = BasCreate(AnimScr_EfxAureolaOBJCtrl1, 0x78);
		break;

	case 1:
		anim2 = BasCreate(AnimScr_EfxAureolaOBJCtrl2, 0x78);
		break;

	default:
		anim2 = BasCreate(AnimScr_EfxAureolaOBJCtrl3, 0x78);
		break;
	}
	proc->anim2 = anim2;
	if (anim2 == NULL) {
		gEfxBgSemaphore--;
		Proc_End(proc);
		return;
	}

	anim2->oam2 = 0x2440;
	anim2->xPosition = 0x100;
	anim2->yPosition = 0x100;
}

void EfxAureolaOBJCtrl_Loop(struct ProcEfxAureolaOBJ *proc)
{
	u16 x, y;
	struct Anim *anim = proc->anim2;

	if (proc->timer > proc->step) {
		gEfxBgSemaphore--;
		BasRemove(anim);
		Proc_Break(proc);
		return;
	}

	x = Interpolate(0, proc->unk32, proc->unk34, proc->timer, proc->step);
	y = Interpolate(0, proc->unk3A, proc->unk3C, proc->timer, proc->step);

	anim->xPosition = x;
	anim->yPosition = y;
	proc->timer++;
}

void NewEfxAureolaOBJ2(struct Anim *anim, int duration)
{
	struct Anim *anim2, *anim3;
	struct ProcEfxAureolaOBJ *proc;

	gEfxBgSemaphore++;

	proc = SpawnProc(ProcScr_EfxAureolaOBJ2, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->step = 0;
	proc->unk30 = duration;
	proc->unk32 = 0x5B;
	proc->unk34 = 0x3F;
	proc->unk3A = 0xFFF6;
	proc->unk3C = 0x64;

	if (gEkrDistanceType == EKR_DISTANCE_CLOSE) {
		proc->unk32 = 0x73;
		proc->unk34 = 0x57;
	}

	if (GetAnimPosition(anim) == POS_R) {
		proc->unk32 = 0xF0 - proc->unk32;
		proc->unk34 = 0xF0 - proc->unk34;
	}

	anim2 = EfxCreateFrontAnim(anim,
		AnimScr_EfxAureolaOBJ2_1, AnimScr_EfxAureolaOBJ2_1,
		AnimScr_EfxAureolaOBJ2_1, AnimScr_EfxAureolaOBJ2_1);
	proc->anim2 = anim2;
	anim2->xPosition = proc->unk32;
	anim2->yPosition = proc->unk3A;

	anim3 = EfxCreateFrontAnim(anim,
		AnimScr_EfxAureolaOBJ2_2, AnimScr_EfxAureolaOBJ2_2,
		AnimScr_EfxAureolaOBJ2_2, AnimScr_EfxAureolaOBJ2_2);
	proc->anim3 = anim3;
	anim3->xPosition = proc->unk32;
	anim3->yPosition = proc->unk3A;
}

void EfxAureolaOBJ2_Loop(struct ProcEfxAureolaOBJ *proc)
{
	int x, y;
	struct Anim *anim2 = proc->anim2;
	struct Anim *anim3 = proc->anim3;

	anim2->xPosition = anim3->xPosition = Interpolate(0, proc->unk32, proc->unk34, proc->step, proc->unk30);
	anim2->yPosition = anim3->yPosition = Interpolate(0, proc->unk3A, proc->unk3C, proc->step, proc->unk30);

	proc->timer++;
	if (proc->timer == 0x11) {
		proc->timer = 0;
		anim3->scrCur = anim3->script = AnimScr_EfxAureolaOBJ2_2;
		anim2->timer = 0;
	}

	proc->step++;
	if (proc->step > proc->unk30) {
		BasRemove(anim2);
		BasRemove(anim3);
        gEfxBgSemaphore--;
		Proc_Break(proc);
		return;
	}
}

void NewEfxAureolaOBJ3(struct Anim *anim)
{
	struct ProcEfxAureolaOBJ *proc;

	gEfxBgSemaphore++;
	proc = SpawnProc(ProcScr_EfxAureolaOBJ3, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->step = 0;
	proc->unk44 = 1;
	proc->unk48 = 0;
}

void EfxAureolaOBJ3_Loop(struct ProcEfxAureolaOBJ *proc)
{
	int i;

	proc->timer++;

	if (proc->timer == 0x2F) {
		gEfxBgSemaphore--;
		Proc_Break(proc);
		return;
	}

	i = ++proc->step;
	if (i == proc->unk44) {
		proc->step = 0;
		proc->unk44 = 1;
		NewEfxAureolaOBJ3Ctrl(proc->anim, proc->unk48++);
	}
}

void NewEfxAureolaOBJ3Ctrl(struct Anim *anim, int unused)
{
	u32 rn, tmp1, tmp2;
	struct Anim *anim2;
	struct ProcEfxAureolaOBJ *proc;

	gEfxBgSemaphore++;

	proc = SpawnProc(ProcScr_EfxAureolaOBJ3Ctrl, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->step = 20;

	rn = BanimSpawnRandB(0x78);
	proc->unk32 = rn - 0x3C;
	proc->unk34 = rn + 0xB4;

	tmp1 = (proc->unk32 * 3) >> 1;
	tmp2 = (proc->unk34 * 3) >> 1;

	proc->unk3A = tmp1 + 0xC0;
	proc->unk3C = tmp2 - 0x148;

	switch (BanimSpawnRandB(2)) {
	case 1:
		anim2 = BasCreate(AnimScr_EfxAureolaOBJ3_1, 0x78);
		break;

	default:
		anim2 = BasCreate(AnimScr_EfxAureolaOBJ3_2, 0x78);
		break;
	}
	proc->anim2 = anim2;
	if (anim2 == NULL) {
		gEfxBgSemaphore--;
		Proc_End(proc);
		return;
	}

	anim2->oam2 = 0x2440;
	anim2->xPosition = 0x100;
	anim2->yPosition = 0x100;
}

void EfxAureolaOBJ3Ctrl_Loop(struct ProcEfxAureolaOBJ *proc)
{
	u16 x, y;
	struct Anim *anim = proc->anim2;

	if (proc->timer > proc->step) {
		gEfxBgSemaphore--;
		BasRemove(anim);
		Proc_Break(proc);
		return;
	}

	x = Interpolate(0, proc->unk32, proc->unk34, proc->timer, proc->step);
	y = Interpolate(0, proc->unk3A, proc->unk3C, proc->timer, proc->step);

	anim->xPosition = x;
	anim->yPosition = y;
	proc->timer++;
}

struct ProcScr CONST_DATA ProcScr_EfxApocalypse[] = {
	PROC_NAME_DEBUG("efxApocalypse"),
	PROC_REPEAT(EfxApocalypse_Loop),
	PROC_END,
};

struct ProcScr CONST_DATA ProcScr_EfxApocalypseBG[] = {
	PROC_NAME_DEBUG("efxApocalypseBG"),
	PROC_REPEAT(EfxApocalypseBG_Loop),
	PROC_END,
};

struct ProcScr CONST_DATA ProcScr_EfxApocalypseBGCtrl[] = {
	PROC_NAME_DEBUG("efxApocalypseBGCtrl"),
	PROC_SLEEP(145),
	PROC_REPEAT(EfxApocalypseBGCtrl_Loop),
	PROC_END,
};

struct ProcScr CONST_DATA ProcScr_EfxApocalypseBGCOL[] = {
	PROC_NAME_DEBUG("efxApocalypseBGCOL"),
	PROC_MARK(PROC_MARK_PAL_CHG),
	PROC_REPEAT(EfxApocalypseBGCOL_Loop),
	PROC_END,
};

struct ProcScr CONST_DATA ProcScr_EfxApocalypseOBJ[] = {
	PROC_NAME_DEBUG("efxApocalypseOBJ"),
	PROC_SLEEP(195),
	PROC_REPEAT(EfxApocalypseOBJ_Loop1),
	PROC_REPEAT(EfxApocalypseOBJ_Loop2),
	PROC_REPEAT(EfxApocalypseOBJ_Loop3),
	PROC_REPEAT(EfxApocalypseOBJ_Loop4),
	PROC_END,
};

extern CONST_DATA AnimScr AnimScr_085EB93C[];
extern CONST_DATA AnimScr AnimScr_085EB944[];
extern CONST_DATA AnimScr AnimScr_085EB94C[];
extern CONST_DATA AnimScr AnimScr_085EB954[];
extern CONST_DATA AnimScr AnimScr_085EB95C[];
extern CONST_DATA AnimScr AnimScr_085EB964[];
extern CONST_DATA AnimScr AnimScr_085EB96C[];
extern CONST_DATA AnimScr AnimScr_085EB974[];

CONST_DATA u32 *AnimArray_EfxApocalypseOBJ[] = {
	(u32 *)AnimScr_085EB93C,
	(u32 *)AnimScr_085EB944,
	(u32 *)AnimScr_085EB94C,
	(u32 *)AnimScr_085EB954,
	(u32 *)AnimScr_085EB95C,
	(u32 *)AnimScr_085EB964,
	(u32 *)AnimScr_085EB96C,
	(u32 *)AnimScr_085EB974,
};

struct ProcScr CONST_DATA ProcScr_EfxApocalypseBGCOL2[] = {
	PROC_NAME_DEBUG("efxApocalypseBGCOL2"),
	PROC_MARK(PROC_MARK_PAL_CHG),
	PROC_REPEAT(EfxApocalypseBGCOL2_Loop),
	PROC_END,
};

struct ProcScr CONST_DATA ProcScr_EfxApocalypseDummy[] = {
	PROC_NAME_DEBUG("efxApocalypseDummy"),
	PROC_REPEAT(EfxApocalypseDummy_Loop),
	PROC_END,
};

struct ProcScr CONST_DATA ProcScr_EfxApocalypseBgFlash1[] = {
	PROC_NAME_DEBUG("efxApocalypseBgFlash1"),
	PROC_REPEAT(EfxApocalypseBgFlash1_Loop),
	PROC_END,
};

struct ProcScr CONST_DATA ProcScr_EfxApocalypseBgFlash2[] = {
	PROC_NAME_DEBUG("efxApocalypseBgFlash2"),
	PROC_REPEAT(EfxApocalypseBgFlash2_Loop1),
	PROC_REPEAT(EfxApocalypseBgFlash2_Loop2),
	PROC_END,
};

struct ProcScr CONST_DATA ProcScr_EfxApocalypseBG2[] = {
	PROC_NAME_DEBUG("efxApocalypseBG2"),
	PROC_REPEAT(EfxApocalypseBG2_Loop),
	PROC_END,
};

CONST_DATA u16 *ImgArray_EfxApocalypseBG2[] = {
	Img_EfxApocalypseBG2_0817BBD4,
	Img_EfxApocalypseBG2_0817D4E0,
	Img_EfxApocalypseBG2_0817ED8C,
	Img_EfxApocalypseBG2_081804F4,
};

CONST_DATA u16 *TsaArray_EfxApocalypseBG2[] = {
	Tsa_EfxApocalypseBG2_08181E80,
	Tsa_EfxApocalypseBG2_08182320,
	Tsa_EfxApocalypseBG2_081827B0,
	Tsa_EfxApocalypseBG2_08182C4C,
};

struct ProcScr CONST_DATA ProcScr_EfxApocalypseOBJ2[] = {
	PROC_NAME_DEBUG("efxApocalypseOBJ2"),
	PROC_REPEAT(EfxApocalypseOBJ2_Loop1),
	PROC_REPEAT(EfxApocalypseOBJ2_Loop2),
	PROC_END,
};

struct ProcScr CONST_DATA ProcScr_EfxApocalypseOBJ3[] = {
	PROC_NAME_DEBUG("efxApocalypseOBJ3"),
	PROC_REPEAT(EfxApocalypseOBJ3_Loop),
	PROC_END,
};

CONST_DATA int DuraArray_EfxApocalypseOBJ3RND[] = {
	43, 38, 44, 36, 43, 41, 50, 44,
	48, 35, 36, 34, 44, 45, 35, 35,
	49, 38, 35, 44, 50, 46, 31, 45,
	36, 50, 48, 42, 45, 36, 30, 41,
	40, 44, 32, 34, 32, 34, 35, 36,
	46, 33, 33, 45, 50, 33, 37, 39,
	42, 49, -1,
};

CONST_DATA int LoArray_EfxApocalypseOBJ3RND[] = {
	0x7C34, 0x85C7, 0x3FB2, 0x7C4D, 0x8810, 0xFF13, 0xDB8E, 0xA559,
	0x7A6C, 0x585F, 0x9EEA, 0x3365, 0xFD48, 0xA3AB, 0x83C6, 0xC871,
	0x5AA4, 0x12F7, 0x2422, 0x267D, 0x7C80, 0xF843, 0xB9FE, 0x2F89,
	0xECDC, 0xC58F, 0x1F5A, 0xE595, 0xD5B8, 0x0CDB, 0xCE36, 0x6AA1,
	0x0114, 0x8027, 0xE092, 0x00AD, 0xD8F0, 0xF173, 0x106E, 0x09B9,
	0x674C, 0x52BF, 0xB7CA, 0x07C5, 0x5628, 0xB60B, 0xD0A6, 0x9CD1,
	0xEF84, 0x4D57,
};

CONST_DATA int StateArray_EfxApocalypseOBJ3RND[] = {
	1, 0, 6, 0, 2, 3, 4, 4,
	0, 3, 4, 5, 6, 4, 5, 6,
	4, 5, 1, 6, 3, 2, 4, 0,
	3, 5, 2, 6, 6, 4, 4, 5,
	0, 4, 6, 3, 4, 4, 1, 1,
	4, 4, 3, 0, 0, 5, 2, 2,
	3, 2,
};

struct ProcScr CONST_DATA ProcScr_EfxApocalypseOBJ3RND[] = {
	PROC_NAME_DEBUG("efxApocalypseOBJ3RND"),
	PROC_REPEAT(EfxApocalypseOBJ3RND_Loop),
	PROC_END,
};

/**
 * AnimApocalypse
 */
void StartSpellAnimApocalypse(struct Anim *anim)
{
	struct ProcEfxMagic *proc;

	SpellFx_Begin();
	NewEfxSpellCast();
	SpellFx_ClearBG1Position();

	proc = SpawnProc(ProcScr_EfxApocalypse, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->hitted = CheckRoundMiss(GetAnimRoundTypeAnotherSide(anim));
}

void EfxApocalypse_Loop(struct ProcEfx *proc)
{
	struct Anim *anim_other = GetAnimAnotherSide(proc->anim);
	int duration = EfxGetCamMovDuration();

	proc->timer++;

	if (proc->timer == 1)
		NewEfxFarAttackWithDistance(proc->anim, -1);

	if (proc->timer == duration + 1) {
		NewEfxApocalypseBG(anim_other, 0x1D1);
		NewEfxApocalypseBGCOL(anim_other);
		NewEfxApocalypseBGCtrl(anim_other);
		NewEfxApocalypseBgFlash1(anim_other, 0x18B, 10);
		NewEfxApocalypseBgFlash2(anim_other, 0x19F, 20);
		NewEfxApocalypseOBJ(anim_other);
		NewEfxApocalypseBGCOL2(anim_other, 0x1D1);
		NewEfxApocalypseDummy(
			anim_other,
			NewEfxRestRST(anim_other, 0x1D1, 20, 0x80, 3),
			0x8C);
		NewEfxRestWINH_(anim_other, 0x1D1, EfxRestWINH_DefaultHblank);
		PlaySFX(SONG_104, 0x100, 0x78, 0);
		return;
	}

	if (proc->timer == duration + 0x92) {
        PlaySFX(SONG_105, 0x100, 0x78, 0);
		return;
	}

	if (proc->timer == duration + 0x1CC) {
		NewEfxWhiteIN(anim_other, 10, 20);
		return;
	}

	if (proc->timer == duration + 0x1D5) {
		NewEfxApocalypseBG2(anim_other, 0xA0);
		NewEfxALPHA(anim_other, 0x6E, 0x28, 0x10, 0, 0);
		NewEfxApocalypseOBJ2(anim_other, 0x8C, 0x18);
		NewEfxApocalypseOBJ3(anim_other, 0x3C);
		NewEfxMagicQUAKE(anim_other, 0x5A);
		PlaySFX(SONG_106, 0x100, 0x78, 0);
		return;
	}

	if (proc->timer == duration + 0x20D) {
		anim_other->flags3 |= ANIM_BIT3_C02_BLOCK_END | ANIM_BIT3_C01_BLOCK_END_INBATTLE;
		StartBattleAnimHitEffectsDefault(anim_other, proc->hitted);

		if (!proc->hitted)
			EfxPlayHittedSFX(anim_other);

		return;
	}

	if (proc->timer == duration + 0x271)
		return;

	if (proc->timer == duration + 0x27B) {
		SpellFx_Finish();
		EndEfxSpellCastAsync();
		Proc_Break(proc);
		return;
	}
}

void NewEfxApocalypseBG(struct Anim *anim, int duration)
{
	struct ProcEfxBG *proc;

	gEfxBgSemaphore++;
	proc = SpawnProc(ProcScr_EfxApocalypseBG, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->terminator = duration;

	SpellFx_RegisterBgGfx(Img_EfxApocalypseBG, 0x1080);
	SpellFx_ClearBG1();
	LZ77UnCompWram(Tsa_EfxApocalypseBG, gEkrTsaBuffer);
	EfxTmCpyBG(gEkrTsaBuffer, gBg1Tm, 0x20, 0x14, BGPAL_EFX_SPELL_BG, VRAMOFF_BANIM_SPELL_BG / CHR_SIZE);

	SpellFx_SetSomeColorEffect();
	SetWinEnable(0, 0, 0);
}

void EfxApocalypseBG_Loop(struct ProcEfxBG *proc)
{
	if (++proc->timer == proc->terminator) {
		SpellFx_ClearBG1();
		gEfxBgSemaphore--;
		SpellFx_ClearColorEffects();
		Proc_End(proc);
	}
}

void NewEfxApocalypseBGCtrl(struct Anim *anim)
{
	struct ProcEfxBG *proc;

	gEfxBgSemaphore++;

	proc = SpawnProc(ProcScr_EfxApocalypseBGCtrl, PROC_TREE_3);

	SetBgOffset(BG_1, 0, 0x10);
	proc->timer = 0;
	proc->terminator = 0;
	proc->unk30 = 0;
}

void EfxApocalypseBGCtrl_Loop(struct ProcEfxBG *proc)
{
	u16 ret = Interpolate(INTERPOLATE_LINEAR, 0, 0xFF, proc->unk30, 0x96);
	int tmp1;
	i16 tmp2;
	i16 pos;

	if (proc->unk30 <= 0x96)
		proc->unk30++;

	tmp1 = proc->terminator & 0xFF;
	tmp2 = ret;

	pos = PosArray_EfxApocalypseBGCtrl[tmp1] * tmp2;
    pos = pos >> 8;
	gDispIo.bg_off[BG_1].x = pos;

	pos = PosArray_EfxApocalypseBGCtrl[tmp1 + 0x40] * tmp2;
    pos = pos >> 8;
	gDispIo.bg_off[BG_1].y = pos + 0x10;

	proc->terminator += 2;

	if (!(1 & proc->timer))
		SetBgOffset(BG_1, 0, 0x10);

	proc->timer++;
	if (proc->timer == 0x140) {
		gEfxBgSemaphore--;
		Proc_Break(proc);
	}
}

void NewEfxApocalypseBGCOL(struct Anim *anim)
{
	struct ProcEfxBGCOL *proc;

	gEfxBgSemaphore++;

	proc = SpawnProc(ProcScr_EfxApocalypseBGCOL, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->timer2 = 0x10;

	SpellFx_RegisterBgPal(Pal_EfxApocalypse_0817B418, 0x20);
	EfxPalBlackInOut(gPal, BGPAL_EFX_SPELL_BG, 1, 0x10);
	EnablePalSync();
}

void EfxApocalypseBGCOL_Loop(struct ProcEfxBGCOL *proc)
{
	int ret = Interpolate(0, 0x10, 0, proc->timer, proc->timer2);

	SpellFx_RegisterBgPal(Pal_EfxApocalypse_0817B418, 0x20);
	EfxPalBlackInOut(gPal, BGPAL_EFX_SPELL_BG, 1, ret);
	EnablePalSync();

	proc->timer++;
	if (proc->timer > proc->timer2) {
		gEfxBgSemaphore--;
		Proc_Break(proc);
	}
}

void NewEfxApocalypseOBJ(struct Anim *anim)
{
	u32 i;
	struct ProcEfxOBJ *proc;

	for (i = 0; i < 8; i++) {
		proc = SpawnProc(ProcScr_EfxApocalypseOBJ, PROC_TREE_3);
		proc->anim = anim;
		proc->unk44 = i;
	}

	SpellFx_RegisterObjPal(Pal_EfxApocalypseOBJ, 0x20);
	SpellFx_RegisterObjGfx(Img_EfxApocalypseOBJ, 0x800);
}

void EfxApocalypseOBJ_Loop1(struct ProcEfxOBJ *proc)
{
	struct Anim *sub_anim;
	const u32 *scr;

	gEfxBgSemaphore++;

	proc->timer = 0;
	proc->terminator = 0;
	proc->unk30 = proc->unk44 << 0xD;

	scr = AnimArray_EfxApocalypseOBJ[proc->unk44];
	sub_anim = EfxCreateFrontAnim(proc->anim, scr, scr, scr, scr);
	proc->anim2 = sub_anim;

	sub_anim->oam2 &= 0xF3FF;
	sub_anim->oam2 |= 0x0400;

	sub_anim->xPosition = 0x100;
	sub_anim->yPosition = 0x100;

	proc->unk32 = 0x78;
	proc->unk3A = 0x40;

	Proc_Break(proc);
}

void EfxApocalypseOBJ_Loop2(struct ProcEfxOBJ *proc)
{
	struct BaSprite *anim2 = proc->anim2;
	i16 interp = Interpolate(0, 0xB4, 0x32, proc->timer, 0x3C);
	unsigned index = proc->unk30;
	i16 xSin;
	i16 ySin;
	int x;
	int y;
	int xPos;
	int yPos;

	proc->unk30 = index + 0x300;
	index = (index + 0x300) >> 8;
	xSin = gSinLut[index];
	ySin = gSinLut[index + 0x40];
	x = (xSin * (i16)interp) << 4;
	y = ((i16)interp * ySin) << 4;
	xPos = proc->unk32 + (x >> 16);
	yPos = proc->unk3A + (y >> 16);
	anim2->xPosition = xPos;
	anim2->yPosition = yPos;
	proc->timer++;
	if (proc->timer > 0x3C)
		proc->timer = 0x3C;
	proc->terminator++;
	if (proc->terminator > 0x78) {
		proc->timer = 0;
		proc->terminator = 0;
		Proc_Break(proc);
	}
}

void EfxApocalypseOBJ_Loop3(struct ProcEfxOBJ *proc)
{
	struct BaSprite *anim2 = proc->anim2;
	i16 interp = Interpolate(0, 0x32, 0, proc->timer, 0x50);
	unsigned index = proc->unk30;
	i16 xSin;
	i16 ySin;
	int x;
	int y;
	int xPos;
	int yPos;

	proc->unk30 = index + 0x300;
	index = (index + 0x300) >> 8;
	xSin = gSinLut[index];
	ySin = gSinLut[index + 0x40];
	x = (xSin * (i16)interp) << 4;
	y = ((i16)interp * ySin) << 4;
	xPos = proc->unk32 + (x >> 16);
	yPos = proc->unk3A + (y >> 16);
	anim2->xPosition = xPos;
	anim2->yPosition = yPos;

	proc->timer++;

	if (proc->timer > 0x50)
		proc->timer = 0x50;

	proc->terminator++;

	if (proc->terminator > 0x50) {
		proc->timer = 0;
		proc->terminator = 0;
		Proc_Break(proc);
	}
}

void EfxApocalypseOBJ_Loop4(struct ProcEfxOBJ *proc)
{
	struct BaSprite *anim2 = proc->anim2;
	i16 interp;
	int timer;
	unsigned index;
	i16 xSin;
	i16 ySin;
	int x;
	int y;
	int xPos;
	int yPos;

	timer = proc->timer;
	interp = Interpolate(1, 0, 0xB4, timer, 0x32);

	index = proc->unk30;
	proc->unk30 = index + 0x800;
	index = (index + 0x800) >> 8;
	xSin = gSinLut[index];
	ySin = gSinLut[index + 0x40];
	x = (xSin * (i16)interp) << 4;
	y = ((i16)interp * ySin) << 4;
	xPos = proc->unk32 + (x >> 16);
	yPos = proc->unk3A + (y >> 16);
	anim2->xPosition = xPos;
	anim2->yPosition = yPos;

	proc->timer++;

	if (proc->timer > 0x32)
		proc->timer = 0x32;

	proc->terminator++;

	if (proc->terminator > 0x32) {
		gEfxBgSemaphore--;
		BasRemove(proc->anim2);
		Proc_Break(proc);
	}
}

void NewEfxApocalypseBGCOL2(struct Anim *anim, int duration)
{
	struct ProcEfxBGCOL *proc;

	static const u16 frames[] = {
		0x0, 2,
		0x1, 2,
		0x2, 2,
		0x3, 2,
		0x4, 2,
		0x5, 2,
		0x6, 2,
		0x7, 2,
		0x8, 2,
		0x9, 2,
		0xA, 2,
		0xB, 2,
		0xC, 2,
		0xD, 2,
		0xE, 2,
		-2
	};

	gEfxBgSemaphore++;

	proc = SpawnProc(ProcScr_EfxApocalypseBGCOL2, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->timer2 = 0;
	proc->terminator = duration;
	proc->frame = 0;
	proc->frame_config = frames;
	proc->pal = Pals_EfxApocalypseBGCOL2;
}

void EfxApocalypseBGCOL2_Loop(struct ProcEfxBGCOL *proc)
{
	int ret;

	ret = EfxAdvanceFrameLut((i16 *)&proc->timer, (i16 *)&proc->frame,
				 proc->frame_config);

	if (ret >= 0)
		func_fe6_08047B6C(proc->pal, (u16 *)((char *)gPal + 2), ret, 0xf, 0xf);

	proc->timer2++;

	if (proc->timer2 > proc->terminator) {
		gEfxBgSemaphore--;
		Proc_Break(proc);
	}
}

void NewEfxApocalypseDummy(struct Anim *anim, ProcPtr efxproc, int duration)
{
	struct ProcEfxApocalypseDummy *proc;

	gEfxBgSemaphore++;

	proc = SpawnProc(ProcScr_EfxApocalypseDummy, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->duration = duration;
	proc->efxproc = efxproc;
}

void EfxApocalypseDummy_Loop(struct ProcEfxApocalypseDummy *proc)
{
	struct ProcEfx *efxproc = proc->efxproc;

	efxproc->frame = Interpolate(4, 0x80, 0, proc->timer, proc->duration);

	proc->timer++;

	if (proc->timer > proc->duration) {
		gEfxBgSemaphore--;
		Proc_Break(proc);
	}
}

void NewEfxApocalypseBgFlash1(struct Anim *anim, int terminator, int duration)
{
	struct ProcEfxFlashing *proc;

	gEfxBgSemaphore++;

	proc = SpawnProc(ProcScr_EfxApocalypseBgFlash1, PROC_TREE_3);
	proc->timer = 0;
	proc->terminator = terminator;
	proc->terminator2 = duration;
	proc->anim = anim;
}

void EfxApocalypseBgFlash1_Loop(struct ProcEfxFlashing *proc)
{
	proc->timer++;

	if (proc->timer > proc->terminator) {
		gEfxBgSemaphore--;
		NewEfxFlashBgWhite(proc->anim, proc->terminator2);
		Proc_Break(proc);
	}
}

void NewEfxApocalypseBgFlash2(struct Anim *anim, int terminator, int duration)
{
	struct ProcEfxFlashing *proc;

	gEfxBgSemaphore++;

	proc = SpawnProc(ProcScr_EfxApocalypseBgFlash2, PROC_TREE_3);
	proc->timer = 0;
	proc->terminator = terminator;
	proc->terminator2 = duration;
	proc->anim = anim;
}

void EfxApocalypseBgFlash2_Loop1(struct ProcEfxFlashing *proc)
{
	proc->timer++;

	if (proc->timer > proc->terminator) {
		proc->timer = 0;
		Proc_Break(proc);
	}
}

void EfxApocalypseBgFlash2_Loop2(struct ProcEfxFlashing *proc)
{
	int ret;

	ret = Interpolate(0, 0, 0x10, proc->timer, proc->terminator2);

	SpellFx_RegisterBgPal(Pal_EfxApocalypse_0817B418, 0x20);
	EfxPalWhiteInOut(gPal, 1, 1, ret);

	proc->timer++;

	if (proc->timer > proc->terminator2) {
		gEfxBgSemaphore--;
		Proc_Break(proc);
	}
}

void NewEfxApocalypseBG2(struct Anim *anim, int duration)
{
	struct ProcEfxBG *proc;
	struct Anim *anim_other;

	static const u16 frames[] = {
		0x0, 3,
		0x1, 3,
		0x2, 3,
		0x3, 3,
		-2
	};

	gEfxBgSemaphore++;

	proc = SpawnProc(ProcScr_EfxApocalypseBG2, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->terminator = 0;
	proc->unk30 = duration;
	proc->frame = 0;
	proc->frame_config = frames;
	proc->tsal = TsaArray_EfxApocalypseBG2;
	proc->tsar = TsaArray_EfxApocalypseBG2;
	proc->img = ImgArray_EfxApocalypseBG2;

	SpellFx_RegisterBgPal(Pal_EfxApocalypseBG2, 0x20);
	SpellFx_SetSomeColorEffect();
	SetBgOffset(BG_1, 0, 0);

	if (GetEkrDragonStateType() != 0) {
		anim_other = GetAnimAnotherSide(proc->anim);

		gDispIo.bg0_ct.priority = 0;
		gDispIo.bg3_ct.priority = 1;
		gDispIo.bg1_ct.priority = 2;
		gDispIo.bg2_ct.priority = 3;

		anim->oam2 = (anim->oam2 & ~OAM2_LAYER_MASK) | OAM2_LAYER(1);
		anim_other->oam2 = (anim_other->oam2 & ~OAM2_LAYER_MASK) | OAM2_LAYER(1);
	}
}

void EfxApocalypseBG2_Loop(struct ProcEfxBG *proc)
{
	struct Anim *anim_other;
	int ret;

	anim_other = GetAnimAnotherSide(proc->anim);

	ret = EfxAdvanceFrameLut((i16 *)&proc->timer, (i16 *)&proc->frame,
				 proc->frame_config);

	if (ret >= 0) {
		u16 **tsal = proc->tsal;
		u16 **tsar = proc->tsar;
		u16 **img = proc->img;

		SpellFx_RegisterBgGfx(*(img + ret), 0x2000);
		SpellFx_WriteBgMap(proc->anim, *(tsal + ret), *(tsar + ret));
	}

	proc->terminator++;

	if (proc->terminator != proc->unk30)
		return;

	if (GetEkrDragonStateType() != 0) {
		gDispIo.bg0_ct.priority = 0;
		gDispIo.bg1_ct.priority = 1;
		gDispIo.bg3_ct.priority = 2;
		gDispIo.bg2_ct.priority = 3;

		proc->anim->oam2 &= ~OAM2_LAYER_MASK;
		proc->anim->oam2 |= OAM2_LAYER(2);
		anim_other->oam2 = (anim_other->oam2 & ~OAM2_LAYER_MASK) | OAM2_LAYER(2);
	}

	SpellFx_ClearBG1();
	gEfxBgSemaphore--;
	SpellFx_ClearColorEffects();
	Proc_End(proc);
}

void NewEfxApocalypseOBJ2(struct Anim *anim, int duration1, int duration2)
{
	struct ProcEfxApocalypseOBJ2 *proc;
	struct Anim *anim2;
	const AnimScr *scr;

	gEfxBgSemaphore++;

	proc = SpawnProc(ProcScr_EfxApocalypseOBJ2, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->phase1_duration = duration1;
	proc->phase2_duration = duration2;

	scr = AnimScr_EfxApocalypseOBJ2_1;
	anim2 = EfxCreateFrontAnim(anim, scr, scr, scr, scr);
	proc->anim2 = anim2;
	anim2->xPosition = 0x78;
	anim2->yPosition = 0x48;
	anim2->priority = 0x14;
	BasSort();

	if (GetEkrDragonStateType() != 0)
		anim2->oam2 = (anim2->oam2 & ~OAM2_LAYER_MASK) | OAM2_LAYER(3);

	SpellFx_RegisterObjPal(Pal_EfxMistyrainOBJ1, 0x20);
	SpellFx_RegisterObjGfx(Img_EfxApocalypseOBJ2_1, 0x1000);
}

void EfxApocalypseOBJ2_Loop1(struct ProcEfxApocalypseOBJ2 *proc)
{
	struct Anim *anim2 = proc->anim2;

	proc->timer++;

	if (proc->timer > proc->phase1_duration) {
		proc->timer = 0;
		anim2->script = AnimScr_EfxApocalypseOBJ2_2;
		anim2->scrCur = AnimScr_EfxApocalypseOBJ2_2;
		anim2->timer = 0;
		SpellFx_RegisterObjGfx(Img_EfxApocalypseOBJ2_2, 0x1000);
		Proc_Break(proc);
	}
}

void EfxApocalypseOBJ2_Loop2(struct ProcEfxApocalypseOBJ2 *proc)
{
	proc->timer++;

	if (proc->timer > proc->phase2_duration) {
		BasRemove(proc->anim2);
		gEfxBgSemaphore--;
		Proc_Break(proc);
	}
}

void NewEfxApocalypseOBJ3(struct Anim *anim, int duration)
{
	struct ProcEfxApocalypseOBJ3 *proc;

	gEfxBgSemaphore++;

	proc = SpawnProc(ProcScr_EfxApocalypseOBJ3, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->duration = duration;
	proc->phase_counter = 0;
	proc->spawn_threshold = 1;
	proc->unk48 = 0;
	proc->rnd_index = 0;
}

void EfxApocalypseOBJ3_Loop(struct ProcEfxApocalypseOBJ3 *proc)
{
	int *dura_arr;
	int idx;
	int dura;
	int lo;
	int state;

	proc->timer++;

	if (proc->timer == proc->duration) {
		gEfxBgSemaphore--;
		Proc_Break(proc);
		return;
	}

	if (++proc->phase_counter != proc->spawn_threshold)
		return;

	proc->phase_counter = 0;
	proc->spawn_threshold = 2;

	dura_arr = DuraArray_EfxApocalypseOBJ3RND;
	idx = proc->rnd_index;
	dura = dura_arr[idx];
	lo = LoArray_EfxApocalypseOBJ3RND[idx];
	state = StateArray_EfxApocalypseOBJ3RND[idx];
	proc->rnd_index = idx + 1;

	if (dura_arr[proc->rnd_index] == -1)
		proc->rnd_index = 0;

	NewEfxApocalypseOBJ3RND(proc->anim, dura, lo, state);
}

void NewEfxApocalypseOBJ3RND(struct Anim *anim, int duration, int lo, u32 state)
{
	struct ProcEfxApocalypseOBJ3RND *proc;
	const AnimScr *scr;
	struct Anim *anim2;

	gEfxBgSemaphore++;

	proc = SpawnProc(ProcScr_EfxApocalypseOBJ3RND, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->duration = duration;
	proc->lo = lo;
	proc->angle = lo + (duration << 11);
	proc->x_center = 0x78;
	proc->y_center = 0x48;

	switch (state) {
	case 0:
		scr = AnimScr_EfxApocalypseOBJ3RND_3;
		break;
	case 1:
		scr = AnimScr_EfxApocalypseOBJ3RND_3;
		break;
	case 2:
		scr = AnimScr_EfxApocalypseOBJ3RND_3;
		break;
	case 3:
		scr = AnimScr_EfxApocalypseOBJ3RND_3;
		break;
	case 4:
		scr = AnimScr_EfxApocalypseOBJ3RND_3;
		break;
	case 5:
		scr = AnimScr_EfxApocalypseOBJ3RND_2;
		break;
	case 6:
		scr = AnimScr_EfxApocalypseOBJ3RND_1;
		break;
	default:
		scr = AnimScr_EfxApocalypseOBJ3RND_1;
		break;
	}

	anim2 = EfxCreateFrontAnim(anim, scr, scr, scr, scr);
	proc->anim2 = anim2;
	anim2->xPosition = 0x100;
	anim2->yPosition = 0x100;

	if (GetEkrDragonStateType() != 0)
		anim2->oam2 = (anim2->oam2 & 0xF3FF) | 0x400;
}

void EfxApocalypseOBJ3RND_Loop(struct ProcEfxApocalypseOBJ3RND *proc)
{
	struct Anim *anim2 = proc->anim2;
	i16 radius;
	u8 angle_idx;
	i16 x_sin;
	i16 y_sin;
	int x;
	int y;

	radius = Interpolate(INTERPOLATE_SQUARE, 0x6E, 0,
			     proc->timer, proc->duration);

	angle_idx = (Interpolate(INTERPOLATE_SQUARE, proc->lo, proc->angle,
				 proc->timer, proc->duration) << 16) >> 24;

	x_sin = SIN_Q12(angle_idx);
	y_sin = COS_Q12(angle_idx);
	x = (x_sin * radius) << 4;
	y = (y_sin * radius) << 4;

	{
		i16 x_pos = proc->x_center + (x >> 16);
		i16 y_pos = proc->y_center + (y >> 16);

		anim2->xPosition = x_pos;
		anim2->yPosition = y_pos;
	}

	proc->timer++;

	if (proc->timer > proc->duration) {
		BasRemove(proc->anim2);
		gEfxBgSemaphore--;
		Proc_Break(proc);
	}
}
struct ProcScr CONST_DATA ProcScr_EfxHazymoon[] = {
	PROC_NAME_DEBUG("efxHazymoon"),
	PROC_REPEAT(EfxHazymoon_Loop),
	PROC_END,
};

struct ProcScr CONST_DATA ProcScr_EfxHazymoonBG[] = {
	PROC_NAME_DEBUG("efxHazymoonBG"),
	PROC_REPEAT(EfxHazymoonBG_Loop),
	PROC_END,
};

CONST_DATA u16 *TsaArray_EfxHazymoonBG[] = {
	Tsa_EfxHazymoonBG_0818BC0C,
	Tsa_EfxHazymoonBG_0818BDB0,
	Tsa_EfxHazymoonBG_0818BE50,
	Tsa_EfxHazymoonBG_0818BEF0,
	Tsa_EfxHazymoonBG_0818BFA4,
	Tsa_EfxHazymoonBG_0818C058,
	Tsa_EfxHazymoonBG_0818C10C,
	Tsa_EfxHazymoonBG_0818C1E8,
	Tsa_EfxHazymoonBG_0818C2C4,
	Tsa_EfxHazymoonBG_0818C3D8,
	Tsa_EfxHazymoonBG_0818C4EC,
	Tsa_EfxHazymoonBG_0818C600,
	Tsa_EfxHazymoonBG_0818C714,
	Tsa_EfxHazymoonBG_0818C828,
	Tsa_EfxHazymoonBG_0818C934,
	Tsa_EfxHazymoonBG_0818CA0C,
	Tsa_EfxHazymoonBG_0818CB1C,
	Tsa_EfxHazymoonBG_0818CC84,
	Tsa_EfxHazymoonBG_0818CE48,
	Tsa_EfxHazymoonBG_0818D00C,
	Tsa_EfxHazymoonBG_0818D1C8,
	Tsa_EfxHazymoonBG_0818D378,
	Tsa_EfxHazymoonBG_0818D528,
	Tsa_EfxHazymoonBG_0818D6D8,
	Tsa_EfxHazymoonBG_0818D87C,
	Tsa_EfxHazymoonBG_0818DA14,
	Tsa_EfxHazymoonBG_0818DBA4,
};

CONST_DATA u16 *ImgArray_EfxHazymoonBG[] = {
	Img_EfxHazymoonBG_0818398C,
	Img_EfxHazymoonBG_08183CD4,
	Img_EfxHazymoonBG_08183CD4,
	Img_EfxHazymoonBG_08183CD4,
	Img_EfxHazymoonBG_08183CD4,
	Img_EfxHazymoonBG_08183CD4,
	Img_EfxHazymoonBG_08183CD4,
	Img_EfxHazymoonBG_08183CD4,
	Img_EfxHazymoonBG_08183CD4,
	Img_EfxHazymoonBG_08183CD4,
	Img_EfxHazymoonBG_08183CD4,
	Img_EfxHazymoonBG_08183CD4,
	Img_EfxHazymoonBG_08183CD4,
	Img_EfxHazymoonBG_08183CD4,
	Img_EfxHazymoonBG_081845A8,
	Img_EfxHazymoonBG_081845A8,
	Img_EfxHazymoonBG_081845A8,
	Img_EfxHazymoonBG_081855E4,
	Img_EfxHazymoonBG_08186250,
	Img_EfxHazymoonBG_08186E6C,
	Img_EfxHazymoonBG_081879C4,
	Img_EfxHazymoonBG_08188518,
	Img_EfxHazymoonBG_08188FC8,
	Img_EfxHazymoonBG_081899F0,
	Img_EfxHazymoonBG_0818A2EC,
	Img_EfxHazymoonBG_0818ABB8,
	Img_EfxHazymoonBG_0818B438,
};

struct ProcScr CONST_DATA ProcScr_EfxHazymoonOBJ2[] = {
	PROC_NAME_DEBUG("efxHazymoonOBJ2"),
	PROC_ONEND(EfxHazymoonOBJ2_OnEnd),
	PROC_REPEAT(EfxHazymoonOBJ2_Loop1),
	PROC_REPEAT(EfxHazymoonOBJ2_Loop2),
	PROC_REPEAT(EfxHazymoonOBJ2_Loop3),
	PROC_REPEAT(EfxHazymoonOBJ2_Loop1),
	PROC_REPEAT(EfxHazymoonOBJ2_Loop2),
	PROC_REPEAT(EfxHazymoonOBJ2_Loop3),
	PROC_END,
};

struct ProcScr CONST_DATA ProcScr_EfxHazymoonOBJ3[] = {
	PROC_NAME_DEBUG("efxHazymoonOBJ3"),
	PROC_REPEAT(EfxHazymoonOBJ3_Loop),
	PROC_END,
};

CONST_DATA u16 gEclipseAnimSpriteCoordinates[] = {
	0x60, 0x38, 0x30, 0x68, 0xA0, 0x40, 0x58, 0x88,
	0xA0, 0x88, 0xC0, 0x60,
};

struct ProcScr CONST_DATA ProcScr_EfxHazymoonOBJ3RND[] = {
	PROC_NAME_DEBUG("efxHazymoonOBJ3RND"),
	PROC_ONEND(EfxHazymoonOBJ3RND_Loop),
	PROC_SLEEP(100),
	PROC_END,
};

struct ProcScr CONST_DATA ProcScr_EfxFenrir[] = {
	PROC_NAME_DEBUG("efxFenrir"),
	PROC_REPEAT(EfxFenrir_Loop),
	PROC_END,
};

struct ProcScr CONST_DATA ProcScr_EfxFenrirBG[] = {
	PROC_NAME_DEBUG("efxFenrirBG"),
	PROC_ONEND(EfxFenrirBG_OnEnd),
	PROC_REPEAT(EfxFenrirBG_Loop),
	PROC_END,
};

struct ProcScr CONST_DATA ProcScr_EfxFenrirBGCOL[] = {
	PROC_NAME_DEBUG("efxFenrirBGCOL"),
	PROC_MARK(PROC_MARK_PAL_CHG),
	PROC_ONEND(EfxFenrirBGCOL_OnEnd),
	PROC_REPEAT(EfxFenrirBGCOL_Loop),
	PROC_END,
};

struct ProcScr CONST_DATA ProcScr_EfxFenrirOBJ[] = {
	PROC_NAME_DEBUG("efxFenrirOBJ"),
	PROC_REPEAT(EfxFenrirOBJ_Loop),
	PROC_END,
};

struct ProcScr CONST_DATA ProcScr_EfxFenrirBG2[] = {
	PROC_NAME_DEBUG("efxFenrirBG2"),
	PROC_REPEAT(EfxFenrirBG2_Loop),
	PROC_END,
};

CONST_DATA u16 *ImgArray_EfxFenrirBG2_A[] = {
	Img_EfxFenrirBG2_A_0818F5EC,
	Img_EfxFenrirBG2_A_0818F5EC,
	Img_EfxFenrirBG2_A_0818F5EC,
	Img_EfxFenrirBG2_A_0818F5EC,
	Img_EfxFenrirBG2_A_0818F5EC,
	Img_EfxFenrirBG2_A_0818F5EC,
	Img_EfxFenrirBG2_A_0818F5EC,
	Img_EfxFenrirBG2_A_0818F5EC,
	Img_EfxFenrirBG2_A_0818F5EC,
	Img_EfxFenrirBG2_A_0818F5EC,
	Img_EfxFenrirBG2_A_0818F5EC,
	Img_EfxFenrirBG2_A_0818F5EC,
	Img_EfxFenrirBG2_A_0818F5EC,
	Img_EfxFenrirBG2_A_0818F5EC,
	Img_EfxFenrirBG2_A_0818F5EC,
	Img_EfxFenrirBG2_A_0818F5EC,
	Img_EfxFenrirBG2_A_0818F5EC,
	Img_EfxFenrirBG2_A_0818F5EC,
	Img_EfxFenrirBG2_A_0818F5EC,
	Img_EfxFenrirBG2_A_0818F5EC,
	Img_EfxFenrirBG2_A_0818F5EC,
	Img_EfxFenrirBG2_A_0818F5EC,
	Img_EfxFenrirBG2_A_0818F5EC,
	Img_EfxFenrirBG2_A_0818F5EC,
	Img_EfxFenrirBG2_A_0818F5EC,
	Img_EfxFenrirBG2_A_0818F5EC,
	Img_EfxFenrirBG2_A_0818F5EC,
	Img_EfxFenrirBG2_A_0818F5EC,
	Img_EfxFenrirBG2_A_0818F5EC,
	Img_EfxFenrirBG2_A_0818F5EC,
	Img_EfxFenrirBG2_A_0818F5EC,
	Img_EfxFenrirBG2_A_0818F5EC,
	Img_EfxFenrirBG2_A_0818F5EC,
	Img_EfxFenrirBG2_A_0818F5EC,
	Img_EfxFenrirBG2_A_0818F5EC,
	Img_EfxFenrirBG2_A_0818F5EC,
	Img_EfxFenrirBG2_A_0818F5EC,
	Img_EfxFenrirBG2_A_0818F5EC,
	Img_EfxFenrirBG2_A_0818F5EC,
	Img_EfxFenrirBG2_A_0818F5EC,
	Img_EfxFenrirBG2_A_0818F5EC,
	Img_EfxFenrirBG2_A_0818F5EC,
	Img_EfxFenrirBG2_A_0818F5EC,
	Img_EfxFenrirBG2_A_0818F5EC,
	Img_EfxFenrirBG2_A_0818F5EC,
	Img_EfxFenrirBG2_A_0818F5EC,
	Img_EfxFenrirBG2_A_0818F5EC,
	Img_EfxFenrirBG2_A_0818F5EC,
	Img_EfxFenrirBG2_A_08190804,
	Img_EfxFenrirBG2_A_08191B54,
	Img_EfxFenrirBG2_A_081929D0,
};

CONST_DATA u16 *TsaArray_EfxFenrirBG2_A[] = {
	Tsa_EfxFenrirBG2_A_081935D8,
	Tsa_EfxFenrirBG2_A_08193694,
	Tsa_EfxFenrirBG2_A_08193750,
	Tsa_EfxFenrirBG2_A_0819380C,
	Tsa_EfxFenrirBG2_A_081938C8,
	Tsa_EfxFenrirBG2_A_08193984,
	Tsa_EfxFenrirBG2_A_08193A40,
	Tsa_EfxFenrirBG2_A_08193B44,
	Tsa_EfxFenrirBG2_A_08193C48,
	Tsa_EfxFenrirBG2_A_08193D4C,
	Tsa_EfxFenrirBG2_A_08193E50,
	Tsa_EfxFenrirBG2_A_08193F54,
	Tsa_EfxFenrirBG2_A_08194058,
	Tsa_EfxFenrirBG2_A_08194198,
	Tsa_EfxFenrirBG2_A_081942DC,
	Tsa_EfxFenrirBG2_A_08194420,
	Tsa_EfxFenrirBG2_A_08194564,
	Tsa_EfxFenrirBG2_A_081946A8,
	Tsa_EfxFenrirBG2_A_081947EC,
	Tsa_EfxFenrirBG2_A_0819496C,
	Tsa_EfxFenrirBG2_A_08194AF0,
	Tsa_EfxFenrirBG2_A_08194C74,
	Tsa_EfxFenrirBG2_A_08194DD4,
	Tsa_EfxFenrirBG2_A_08194F34,
	Tsa_EfxFenrirBG2_A_08195094,
	Tsa_EfxFenrirBG2_A_08195238,
	Tsa_EfxFenrirBG2_A_081953DC,
	Tsa_EfxFenrirBG2_A_08195580,
	Tsa_EfxFenrirBG2_A_081956F0,
	Tsa_EfxFenrirBG2_A_08195860,
	Tsa_EfxFenrirBG2_A_081959D0,
	Tsa_EfxFenrirBG2_A_08195B74,
	Tsa_EfxFenrirBG2_A_08195D18,
	Tsa_EfxFenrirBG2_A_08195EBC,
	Tsa_EfxFenrirBG2_A_08196030,
	Tsa_EfxFenrirBG2_A_081961A4,
	Tsa_EfxFenrirBG2_A_08196318,
	Tsa_EfxFenrirBG2_A_081964C8,
	Tsa_EfxFenrirBG2_A_08196678,
	Tsa_EfxFenrirBG2_A_08196828,
	Tsa_EfxFenrirBG2_A_0819699C,
	Tsa_EfxFenrirBG2_A_08196B10,
	Tsa_EfxFenrirBG2_A_08196C84,
	Tsa_EfxFenrirBG2_A_08196E38,
	Tsa_EfxFenrirBG2_A_08196FEC,
	Tsa_EfxFenrirBG2_A_081971A0,
	Tsa_EfxFenrirBG2_A_08197318,
	Tsa_EfxFenrirBG2_A_08197490,
	Tsa_EfxFenrirBG2_A_08197608,
	Tsa_EfxFenrirBG2_A_08197860,
	Tsa_EfxFenrirBG2_A_08197A68,
};

struct ProcScr CONST_DATA ProcScr_EfxFenrirOBJ2[] = {
	PROC_NAME_DEBUG("efxFenrirOBJ2"),
	PROC_REPEAT(EfxFenrirOBJ2_Loop),
	PROC_END,
};

struct ProcScr CONST_DATA ProcScr_EfxFenrirOBJ2Chiri[] = {
	PROC_NAME_DEBUG("efxFenrirOBJ2Chiri"),
	PROC_REPEAT(EfxFenrirOBJ2Chiri_Loop),
	PROC_END,
};

CONST_DATA int gFenrirSpriteAngles[] = {
	184, 85, 66, 119, 158, 39, 135, 210,
};

/**
 * Eclipse
 */
void StartSpellAnimEclipse(struct Anim * anim)
{
	struct ProcEfx * proc;

	SpellFx_Begin();
	NewEfxSpellCast();
	SpellFx_ClearBG1Position();

	proc = SpawnProc(ProcScr_EfxHazymoon, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->hitted = CheckRoundMiss(GetAnimRoundTypeAnotherSide(anim));
}

void EfxHazymoon_Loop(struct ProcEfx *proc)
{
	struct Anim *anim = GetAnimAnotherSide(proc->anim);
	int duration = EfxGetCamMovDuration();

	proc->timer++;

	if (proc->timer == 1)
		NewEfxFarAttackWithDistance(proc->anim, -1);

	if (proc->timer == duration + 1) {
		SetBlendAlpha(0, 16);
		NewEfxALPHA(anim, 0, 30, 0, 16, 0);
		NewEfxALPHA(anim, 0xA0, 30, 16, 0, 0);
		NewEfxHazymoonBG1(proc->anim);
		NewEfxHazymoonOBJ3(proc->anim);
		PlaySFX(SONG_138, 0x100, 0x78, 0);
		return;
	}

	if (proc->timer == duration + 0x7F) {
		NewEfxResireRST(anim, NewEfxRestRST(anim, 0x52, 15, 0, 2), 0x3C);
		NewEfxRestWINH_(anim, 0x53, EfxRestWINH_DefaultHblank);
		return;
	}

	if (proc->timer == duration + 0xD2) {
		NewEfxHazymoonBG2(anim);
		return;
	}

	if (proc->timer == duration + 0xD7) {
		PlaySFX(SONG_139, 0x100, anim->xPosition, 1);
		return;
	}

	if (proc->timer == duration + 0xF1) {
		NewEfxHazymoonOBJ2(proc->anim);
		return;
	}

	if (proc->timer == duration + 0x13C) {
		PlaySFX(SONG_13A, 0x100, anim->xPosition, 1);
		NewEfxFlashBgWhite(anim, 10);
		anim->flags3 |= ANIM_BIT3_C02_BLOCK_END | ANIM_BIT3_C01_BLOCK_END_INBATTLE;
		StartBattleAnimHitEffectsDefault(anim, proc->hitted);

		if (!proc->hitted)
			EfxPlayHittedSFX(anim);

		return;
	}

	if (proc->timer == duration + 0x146) {
		NewEfxHazymoonBG3(anim);
		NewEfxALPHA(anim, 16, 10, 16, 0, 0);
		return;
	}

	if (proc->timer == duration + 0x15E)
		return;

	if (proc->timer == duration + 0x168) {
		SpellFx_Finish();
		EndEfxSpellCastAsync();
		Proc_Break(proc);
	}
}

void NewEfxHazymoonBG1(struct Anim *anim)
{
	struct ProcEfxEclipseBG *proc;

	static const u16 frames[] = {
		0x0, 190,
		-1
	};

	gEfxBgSemaphore++;

	proc = SpawnProc(ProcScr_EfxHazymoonBG, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->frame = 0;
	proc->frame_config = frames;
	proc->tsal = TsaArray_EfxHazymoonBG;
	proc->tsar = TsaArray_EfxHazymoonBG;
	proc->img = ImgArray_EfxHazymoonBG;

	SpellFx_RegisterBgPal(Pal_EfxResireBG, PLTT_SIZE_4BPP);
	SpellFx_SetSomeColorEffect();

	SetWinEnable(0, 0, 0);
}

void NewEfxHazymoonBG2(struct Anim *anim)
{
	struct ProcEfxEclipseBG *proc;

	static const u16 frames[] = {
		0x1, 1,
		0x2, 1,
		0x3, 1,
		0x4, 1,
		0x5, 2,
		0x6, 2,
		0x7, 2,
		0x8, 3,
		0x9, 3,
		0xA, 3,
		0xB, 3,
		0xC, 4,
		0xD, 5,
		0xC, 4,
		0xB, 3,
		0xA, 3,
		0xB, 3,
		0xC, 4,
		0xD, 5,
		0xC, 4,
		0xB, 3,
		0xA, 3,
		0xB, 3,
		0xC, 4,
		0xD, 5,
		0xC, 4,
		0xB, 3,
		0xA, 3,
		0xB, 3,
		0xC, 4,
		0xD, 5,
		0x9, 1,
		0x8, 1,
		0x7, 1,
		0x6, 1,
		0x5, 1,
		0x4, 1,
		0x3, 1,
		0x2, 1,
		0x1, 1,
		-1
	};

	gEfxBgSemaphore++;

	proc = SpawnProc(ProcScr_EfxHazymoonBG, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->frame = 0;
	proc->frame_config = frames;
	proc->tsal = TsaArray_EfxHazymoonBG;
	proc->tsar = TsaArray_EfxHazymoonBG;
	proc->img = ImgArray_EfxHazymoonBG;

	SpellFx_RegisterBgPal(Pal_EfxHazymoonBG2, PLTT_SIZE_4BPP);
	SpellFx_SetSomeColorEffect();

	SetBlendAlpha(12, 6);
}

void NewEfxHazymoonBG3(struct Anim *anim)
{
	struct ProcEfxEclipseBG *proc;

	static const u16 frames[] = {
		0xE, 3,
		0xF, 3,
		0x10, 3,
		0x11, 3,
		0x12, 3,
		0x13, 2,
		0x14, 2,
		0x15, 2,
		0x16, 2,
		0x17, 2,
		0x18, 2,
		0x19, 2,
		0x1A, 2,
		-1
	};

	gEfxBgSemaphore++;

	proc = SpawnProc(ProcScr_EfxHazymoonBG, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->frame = 0;
	proc->frame_config = frames;
	proc->tsal = TsaArray_EfxHazymoonBG;
	proc->tsar = TsaArray_EfxHazymoonBG;
	proc->img = ImgArray_EfxHazymoonBG;

	SpellFx_RegisterBgPal(Pal_EfxHazymoonBG3, PLTT_SIZE_4BPP);
	SpellFx_SetSomeColorEffect();
}

void EfxHazymoonBG_Loop(struct ProcEfxEclipseBG * proc)
{
	i16 ret = EfxAdvanceFrameLut((s16 *)&proc->timer, (s16 *)&proc->frame, proc->frame_config);

	if (ret >= 0) {
		u16 **tsaL = proc->tsal;
		u16 **tsaR = proc->tsar;
		u16 **img = proc->img;

		SpellFx_RegisterBgGfx(*(img + ret), 32 * 8 * CHR_SIZE);
		SpellFx_WriteBgMap(proc->anim, *(tsaL + ret), *(tsaR + ret));
		return;
	}

	if (ret == -1) {
		SpellFx_ClearBG1();
		gEfxBgSemaphore--;
		SpellFx_ClearColorEffects();
		Proc_Break(proc);
	}
}

void NewEfxHazymoonOBJ2(struct BaSprite *anim)
{
	struct ProcEfxMagicOBJ *proc;
	struct BaSprite *anim_front;
	struct BaSprite *anim_other;

	gEfxBgSemaphore++;

	proc = (struct ProcEfxMagicOBJ *)SpawnProc(ProcScr_EfxHazymoonOBJ2, PROC_TREE_3);
	proc->anim = anim;

	anim_other = GetAnimAnotherSide(anim);

	proc->timer = 0;

	anim_front = EfxCreateFrontAnim(anim_other, AnimScr_Common, AnimScr_Common,
					AnimScr_Common, AnimScr_Common);
	proc->anim2 = anim_front;

	anim_front->oam2 = (anim_front->oam2 & 0xF3FF) | 0x400;

	if (GetAnimPosition(anim_other) == POS_L)
		anim_front->xPosition -= 8;
	else
		anim_front->xPosition += 8;

	anim_front->yPosition -= 0x10;

	if (GetEkrDragonStateTypeIdunn() != 0)
		anim_front->xPosition -= 0x10;
}

void EfxHazymoonOBJ2_OnEnd(struct ProcEfxMagicOBJ *proc)
{
	gEfxBgSemaphore--;
	BasRemove(proc->anim2);
}

void EfxHazymoonOBJ2_Loop1(struct ProcEfxMagicOBJ *proc)
{
	struct BaSprite *anim = proc->anim2;

	proc->timer++;

	if (proc->timer == 1) {
		anim->script = AnimScr_EfxHazymoonOBJ2_1;
		anim->scrCur = AnimScr_EfxHazymoonOBJ2_1;
		anim->timer = 0;
		proc->terminator = 0xa;
		SpellFx_RegisterObjPal(Pal_EfxHazymoonOBJ2, 0x20);
		SpellFx_RegisterObjGfx(Img_EfxHazymoonOBJ2_1, 0x1000);
	} else if (proc->timer == proc->terminator) {
		proc->timer = 0;
		Proc_Break(proc);
	}
}

void EfxHazymoonOBJ2_Loop2(struct ProcEfxMagicOBJ *proc)
{
	struct BaSprite *anim = proc->anim2;

	proc->timer++;

	if (proc->timer == 1) {
		anim->script = AnimScr_EfxHazymoonOBJ2_2;
		anim->scrCur = AnimScr_EfxHazymoonOBJ2_2;
		anim->timer = 0;
		proc->terminator = 0xa;
		SpellFx_RegisterObjPal(Pal_EfxHazymoonOBJ2, 0x20);
		SpellFx_RegisterObjGfx(Img_EfxHazymoonOBJ2_2, 0x1000);
	} else if (proc->timer == proc->terminator) {
		proc->timer = 0;
		Proc_Break(proc);
	}
}

void EfxHazymoonOBJ2_Loop3(struct ProcEfxMagicOBJ *proc)
{
	struct BaSprite *anim = proc->anim2;

	proc->timer++;

	if (proc->timer == 1) {
		anim->script = AnimScr_EfxHazymoonOBJ2_3;
		anim->scrCur = AnimScr_EfxHazymoonOBJ2_3;
		anim->timer = 0;
		proc->terminator = 0xa;
		SpellFx_RegisterObjPal(Pal_EfxHazymoonOBJ2, 0x20);
		SpellFx_RegisterObjGfx(Img_EfxHazymoonOBJ2_3, 0x1000);
	} else if (proc->timer == proc->terminator) {
		proc->timer = 0;
		Proc_Break(proc);
	}
}

void NewEfxHazymoonOBJ3(struct BaSprite *anim)
{
	struct ProcEfxMagicOBJ *proc;

	gEfxBgSemaphore++;

	proc = (struct ProcEfxMagicOBJ *)SpawnProc(ProcScr_EfxHazymoonOBJ3, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->terminator = 0;
	proc->unk_30 = 0x64;

	SpellFx_RegisterObjPal(Pal_EfxMistyrainOBJ1, 0x20);
	SpellFx_RegisterObjGfx(Img_EfxMistyrainOBJ1_1, 0x1000);
}

void EfxHazymoonOBJ3_Loop(struct ProcEfxMagicOBJ *proc)
{
	i16 r0, r2;
	void *coord;
	i16 x, y;

	proc->timer++;

	if (proc->timer == 0x12) {
		proc->timer = 0;

		r2 = proc->terminator;
		coord = gEclipseAnimSpriteCoordinates;

		x = gEclipseAnimSpriteCoordinates[r2 * 2 + 0];
		y = gEclipseAnimSpriteCoordinates[r2 * 2 + 1];

		NewEfxHazymoonOBJ3RND(proc->anim, x, y);

		proc->terminator++;

		if (proc->terminator == 6) {
			gEfxBgSemaphore--;
			Proc_Break(proc);
		}
	}
}

void NewEfxHazymoonOBJ3RND(struct BaSprite *anim, int x, int y)
{
	struct ProcEfxMagicOBJ *proc;
	struct BaSprite *anim_front;

	gEfxBgSemaphore++;

	proc = (struct ProcEfxMagicOBJ *)SpawnProc(ProcScr_EfxHazymoonOBJ3RND, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;

	anim_front = EfxCreateFrontAnim(anim, AnimScr_EfxHazymoonOBJ3RND, AnimScr_EfxHazymoonOBJ3RND,
					AnimScr_EfxHazymoonOBJ3RND, AnimScr_EfxHazymoonOBJ3RND);
	proc->anim2 = anim_front;
	anim_front->xPosition = x;
	anim_front->yPosition = y;
}

void EfxHazymoonOBJ3RND_Loop(struct ProcEfxMagicOBJ *proc)
{
	gEfxBgSemaphore--;
	BasRemove(proc->anim2);
}

/**
 * Fenrir
 */
void StartSpellAnimFenrir(struct Anim *anim)
{
	struct ProcEfx *proc;

	SpellFx_Begin();
	NewEfxSpellCast();
	SpellFx_ClearBG1Position();

	proc = SpawnProc(ProcScr_EfxFenrir, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->hitted = CheckRoundMiss(GetAnimRoundTypeAnotherSide(anim));
}

void EfxFenrir_Loop(struct ProcEfx *proc)
{
	struct Anim *anim;
	int duration;

	anim = GetAnimAnotherSide(proc->anim);
	duration = EfxGetCamMovDuration();

	proc->timer++;

	if (proc->timer == 1)
		NewEfxFarAttackWithDistance(proc->anim, -1);

	if (proc->timer == duration + 1) {
		NewEfxFenrirBG(anim, 0x64);
		NewEfxFenrirBGCOL(anim, 0x64);
		NewEfxRestRST(anim, 0x64, 2, 0x100, 1);
		NewEfxRestWINH_(anim, 0x69, EfxRestWINH_DefaultHblank);

		SetBlendAlpha(0, 0x10);
		NewEfxALPHA(anim, 0, 0xF, 0, 0x10, 0);
		NewEfxALPHA(anim, 0x46, 0xF, 0x10, 0, 0);
		PlaySFX(SONG_130, 0x100, 0x78, 0);
	} else if (proc->timer == duration + 0x28) {
		NewEfxFenrirOBJ(anim, 0x4A);
		PlaySFX(SONG_131, 0x100, anim->xPosition, 1);
	} else if (proc->timer == duration + 0x6E) {
		NewEfxFenrirBG2_A(anim);
	} else if (proc->timer == duration + 0x6F) {
		PlaySFX(SONG_132, 0x100, anim->xPosition, 1);
	} else if (proc->timer == duration + 0x8B) {
		PlaySFX(SONG_132, 0x100, anim->xPosition, 1);
	} else if (proc->timer == duration + 0xA7) {
		PlaySFX(SONG_132, 0x100, anim->xPosition, 1);
	} else if (proc->timer == duration + 0xC3) {
		PlaySFX(SONG_132, 0x100, anim->xPosition, 1);
	} else if (proc->timer == duration + 0xDF) {
		PlaySFX(SONG_132, 0x100, anim->xPosition, 1);
	} else if (proc->timer == duration + 0xFB) {
		PlaySFX(SONG_132, 0x100, anim->xPosition, 1);
	} else if (proc->timer == duration + 0x117) {
		PlaySFX(SONG_132, 0x100, anim->xPosition, 1);
	} else if (proc->timer == duration + 0x133) {
		PlaySFX(SONG_132, 0x100, anim->xPosition, 1);
	} else if (proc->timer == duration + 0x166) {
		NewEfxFlashBgWhite(anim, 0xA);
		NewEfxFenrirOBJ2(anim);
		anim->flags3 |= ANIM_BIT3_C02_BLOCK_END | ANIM_BIT3_C01_BLOCK_END_INBATTLE;
		StartBattleAnimHitEffectsDefault(anim, proc->hitted);
		PlaySFX(SONG_133, 0x100, anim->xPosition, 1);

		if (!proc->hitted)
			EfxPlayHittedSFX(anim);
	} else if (proc->timer == duration + 0x170) {
		NewEfxFenrirBG2_B(anim);
		NewEfxALPHA(anim, 0x12, 8, 0x10, 0, 0);
	} else if (proc->timer == duration + 0x19A) {
	} else if (proc->timer == duration + 0x1A4) {
		SpellFx_Finish();
		EndEfxSpellCastAsync();
		Proc_Break(proc);
	}
}

void NewEfxFenrirBG(struct Anim *anim, int duration)
{
	struct ProcEfxBG *proc;

	gEfxBgSemaphore++;

	proc = SpawnProc(ProcScr_EfxFenrirBG, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->terminator = duration;

	SpellFx_RegisterBgGfx(Img_EfxFenrirBG, 32 * 8 * CHR_SIZE);
	SpellFx_ClearBG1();

	LZ77UnCompWram(Tsa_EfxFenrirBG, gEkrTsaBuffer);
	EfxTmCpyBG(gEkrTsaBuffer, gBg1Tm, 0x20, 0x20,
		   BGPAL_EFX_SPELL_BG, VRAMOFF_BANIM_SPELL_BG / CHR_SIZE);

	EnableBgSync(BG1_SYNC_BIT);
	SpellFx_SetSomeColorEffect();
	SetWinEnable(0, 0, 0);
}

void EfxFenrirBG_OnEnd(void)
{
	SpellFx_ClearBG1();
	gEfxBgSemaphore--;
	SpellFx_ClearColorEffects();
}

void EfxFenrirBG_Loop(struct ProcEfxBG *proc)
{
	gDispIo.bg_off[BG_1].y++;
	gDispIo.bg_off[BG_1].x--;

	proc->timer++;

	if (proc->timer > proc->terminator)
		Proc_Break(proc);
}

void NewEfxFenrirBGCOL(struct Anim *anim, int duration)
{
	struct ProcEfxBGCOL *proc;

	static const u16 frames[] = {
		0x0, 4,
		0x1, 4,
		0x2, 4,
		0x3, 4,
		0x4, 4,
		0x5, 4,
		0x6, 4,
		0x7, 4,
		0x8, 4,
		0x9, 4,
		0xA, 4,
		0xB, 4,
		0xC, 4,
		0xD, 4,
		0xE, 4,
		-2
	};

	gEfxBgSemaphore++;

	proc = SpawnProc(ProcScr_EfxFenrirBGCOL, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->timer2 = 0;
	proc->terminator = duration;
	proc->frame = 0;
	proc->frame_config = frames;
	proc->pal = Pal_EfxFenrirBGCOL;

	SpellFx_RegisterBgPal(Pal_EfxFenrirBGCOL, 0x20);
}

void EfxFenrirBGCOL_OnEnd(void)
{
	gEfxBgSemaphore--;
}

void EfxFenrirBGCOL_Loop(struct ProcEfxBGCOL *proc)
{
	int ret;
	const u16 *pal;

	ret = EfxAdvanceFrameLut((i16 *)&proc->timer, (i16 *)&proc->frame,
				 proc->frame_config);

	if (ret >= 0) {
		pal = proc->pal;
		SpellFx_RegisterBgPal(pal + ret * 0x10, 0x20);
	}

	proc->timer2++;

	if (proc->timer2 > proc->terminator)
		Proc_Break(proc);
}

void NewEfxFenrirOBJ(struct Anim *anim, int duration)
{
	struct ProcEfxOBJ *proc;

	gEfxBgSemaphore++;

	proc = SpawnProc(ProcScr_EfxFenrirOBJ, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->terminator = duration;
	proc->anim2 = EfxCreateFrontAnim(anim, AnimScr_EfxFenrirOBJ,
					 AnimScr_EfxFenrirOBJ,
					 AnimScr_EfxFenrirOBJ,
					 AnimScr_EfxFenrirOBJ);

	SpellFx_RegisterObjPal(Pal_EfxFenrirOBJ, 0x20);
	SpellFx_RegisterObjGfx(Img_EfxFenrirOBJ, 32 * 4 * CHR_SIZE);
}

void EfxFenrirOBJ_Loop(struct ProcEfxOBJ *proc)
{
	proc->timer++;

	if (proc->timer > proc->terminator) {
		gEfxBgSemaphore--;
		BasRemove(proc->anim2);
		Proc_Break(proc);
	}
}

void NewEfxFenrirBG2_A(struct Anim *anim)
{
	struct ProcEfxBG *proc;

	static const u16 frames[] = {
		0x0, 4,
		0x1, 4,
		0x2, 4,
		0x3, 4,
		0x4, 4,
		0x5, 4,
		0x3, 4,
		0x6, 4,
		0x7, 4,
		0x8, 4,
		0x9, 4,
		0xA, 4,
		0xB, 4,
		0x9, 4,
		0xC, 4,
		0xD, 4,
		0xE, 4,
		0xF, 4,
		0x10, 4,
		0x11, 4,
		0xF, 4,
		0x12, 4,
		0x13, 4,
		0x14, 4,
		0x15, 4,
		0x16, 4,
		0x17, 4,
		0x15, 4,
		0x18, 4,
		0x19, 4,
		0x1A, 4,
		0x1B, 4,
		0x1C, 4,
		0x1D, 4,
		0x1B, 4,
		0x1E, 4,
		0x1F, 4,
		0x20, 4,
		0x21, 4,
		0x22, 4,
		0x23, 4,
		0x21, 4,
		0x24, 4,
		0x25, 4,
		0x26, 4,
		0x27, 4,
		0x28, 4,
		0x29, 4,
		0x27, 4,
		0x2A, 4,
		0x2B, 4,
		0x2C, 4,
		0x2D, 4,
		0x2E, 4,
		0x2F, 4,
		0x2D, 4,
		0x2E, 4,
		0x2F, 4,
		0x2D, 4,
		0x2E, 4,
		0x2F, 4,
		0x30, 1,
		0x31, 1,
		0x32, 1,
		-1
	};

	gEfxBgSemaphore++;

	proc = SpawnProc(ProcScr_EfxFenrirBG2, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->frame = 0;
	proc->frame_config = frames;
	proc->tsal = TsaArray_EfxFenrirBG2_A;
	proc->tsar = TsaArray_EfxFenrirBG2_A;
	proc->img = ImgArray_EfxFenrirBG2_A;

	SpellFx_RegisterBgPal(Pal_EfxFenrirBG2_A, 0x20);
	SpellFx_SetSomeColorEffect();

	SetBgOffset(BG_1, 0, 0);

	if (gEkrDistanceType != EKR_DISTANCE_CLOSE) {
		if (GetAnimPosition(proc->anim) == POS_L)
			SetBgOffset(BG_1, 0x18, 0);
		else
			SetBgOffset(BG_1, 0xE8, 0);
	}
}

void NewEfxFenrirBG2_B(struct Anim *anim)
{
	struct ProcEfxBG *proc;

	gEfxBgSemaphore++;

	proc = SpawnProc(ProcScr_EfxFenrirBG2, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->frame = 0;
	proc->frame_config = FrameConf_EfxFireHITBG;
	proc->tsal = TsaArray_EfxFireHITBG;
	proc->tsar = TsaArray_EfxFireHITBG;
	proc->img = ImgArray_EfxFireHITBG;

	SpellFx_RegisterBgPal(Pal_EfxFenrirBG2_B, 0x20);
	SpellFx_SetSomeColorEffect();

	if (gEkrDistanceType != EKR_DISTANCE_CLOSE) {
		if (GetAnimPosition(proc->anim) == POS_L)
			SetBgOffset(BG_1, 0x18, 0);
		else
			SetBgOffset(BG_1, 0xE8, 0);
	}
}

void EfxFenrirBG2_Loop(struct ProcEfxBG *proc)
{
	int ret;
	u16 **tsal;
	u16 **tsar;

	ret = EfxAdvanceFrameLut((i16 *)&proc->timer, (i16 *)&proc->frame, proc->frame_config);

	if (ret >= 0) {
		tsal = proc->tsal;
		tsar = proc->tsar;

		SpellFx_RegisterBgGfx(proc->img[ret], 32 * 8 * CHR_SIZE);
		SpellFx_WriteBgMap(proc->anim, tsal[ret], tsar[ret]);

		if (gEkrDistanceType != EKR_DISTANCE_CLOSE) {
			if (GetAnimPosition(proc->anim) == POS_L)
				FillBGRect(gBg1Tm, 3, 20, 0, 0);
			else
				FillBGRect(gBg1Tm + TM_OFFSET(29, 0), 3, 20, 0, 0);

			EnableBgSync(BG1_SYNC_BIT);
		}
	} else if (ret == -1) {
		SpellFx_ClearBG1();
		gEfxBgSemaphore--;
		SpellFx_ClearColorEffects();
		Proc_Break(proc);
	}
}

void NewEfxFenrirOBJ2(struct Anim *anim)
{
	struct ProcEfxOBJ *proc;

	gEfxBgSemaphore++;

	proc = SpawnProc(ProcScr_EfxFenrirOBJ2, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->terminator = 0;
	proc->unk44 = 0;

	SpellFx_RegisterObjPal(Pal_EfxFenrirOBJ2, 0x20);
	SpellFx_RegisterObjGfx(Img_EfxFenrirOBJ, 32 * 4 * CHR_SIZE);
}

void EfxFenrirOBJ2_Loop(struct ProcEfxOBJ *proc)
{
	proc->timer++;

	if (proc->timer == 2) {
		proc->timer = 0;

		NewEfxFenrirOBJ2Chiri(proc->anim, proc->unk44++);

		proc->terminator++;

		if (proc->terminator == 8) {
			gEfxBgSemaphore--;
			Proc_Break(proc);
		}
	}
}

void NewEfxFenrirOBJ2Chiri(struct Anim *anim, int idx)
{
	struct ProcEfxOBJ *proc;
	struct Anim *anim2;

	gEfxBgSemaphore++;

	proc = SpawnProc(ProcScr_EfxFenrirOBJ2Chiri, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->terminator = 30;
	proc->unk44 = gFenrirSpriteAngles[idx & 7];

	anim2 = NULL;

	switch (idx & 1) {
	case 0:
		anim2 = BasCreate(AnimScr_EfxFenrirOBJ2Chiri1, 0x78);
		proc->anim2 = anim2;
		break;

	case 1:
		anim2 = BasCreate(AnimScr_EfxFenrirOBJ2Chiri2, 0x78);
		proc->anim2 = anim2;
		break;
	}

	anim2->oam2 = OAM2_CHR(0x40) + OAM2_LAYER(2) + OAM2_PAL(2);
	anim2->xPosition = anim->xPosition;
	proc->unk32 = anim->xPosition;
	anim2->yPosition = anim->yPosition;
	proc->unk3A = anim->yPosition;
}

void EfxFenrirOBJ2Chiri_Loop(struct ProcEfxOBJ *proc)
{
	struct Anim *anim2 = proc->anim2;
	int ret = Interpolate(INTERPOLATE_LINEAR, 0, 300, proc->timer, proc->terminator);
	int x = ret * gSinLut[proc->unk44];
	int y = ret * gSinLut[proc->unk44 + 0x40];

	anim2->xPosition = proc->unk32 + (x >> 12);
	anim2->yPosition = proc->unk3A + (y >> 12);

	proc->timer++;

	if (proc->timer > proc->terminator) {
		gEfxBgSemaphore--;
		BasRemove(proc->anim2);
		Proc_Break(proc);
	}
}

/**
 * Heal
 */
CONST_DATA struct ProcScr ProcScr_EfxLive[] = {
	PROC_NAME_DEBUG("efxLive"),
	PROC_REPEAT(EfxLive_Loop),
	PROC_END,
};


void StartSpellAnimHeal(struct Anim *anim)
{
	struct ProcEfx *proc;

	SpellFx_Begin();
	NewEfxSpellCast();
	SpellFx_ClearBG1Position();

	proc = SpawnProc(ProcScr_EfxLive, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
}

void EfxLive_Loop(struct ProcEfx *proc)
{
	struct Anim *target = GetAnimAnotherSide(proc->anim);

	proc->timer++;

	if (proc->timer == 1) {
		NewEfxLiveOBJ(proc->anim);
		PlaySFX(SONG_F3, 0x100, proc->anim->xPosition, 1);
	} else if (proc->timer == 52) {
		NewEfxLiveBG_A(proc->anim, 0);
		NewEfxLiveBGCOL_A(proc->anim, 0);

		SetBlendAlpha(0, 16);

		NewEfxLiveALPHA(proc->anim, 1, 12, 0);
		NewEfxLiveALPHA(proc->anim, 35, 25, 1);

		PlaySFX(SONG_10E, 0x100, proc->anim->xPosition, 1);
	} else if (proc->timer == 55) {
		target->flags3 |= ANIM_BIT3_C02_BLOCK_END | ANIM_BIT3_C01_BLOCK_END_INBATTLE;
	} else if (proc->timer == 113) {
		NewEfxLiveBG_B(proc->anim, 0);
		NewEfxLiveBGCOL_B(proc->anim, 0);

		NewEfxLiveALPHA(proc->anim, 1, 12, 0);
		NewEfxLiveALPHA(proc->anim, 29, 25, 1);

		PlaySFX(SONG_10F, 0x100, target->xPosition, 1);
	} else if (proc->timer == 166) {
		NewEfxHpBarLive(target);
	} else if (proc->timer == 181) {
		SpellFx_Finish();
		EndEfxSpellCastAsync();

		if (GetAnimNextRoundType(target) != -1)
			target->flags3 |= ANIM_BIT3_NEXT_ROUND_START;

		Proc_Break(proc);
	}
}

CONST_DATA struct ProcScr ProcScr_EfxRelive[] = {
	PROC_NAME_DEBUG("efxRelive"),
	PROC_REPEAT(EfxRelive_Loop),
	PROC_END,
};


void StartSpellAnimMend(struct Anim *anim)
{
	struct ProcEfx *proc;

	SpellFx_Begin();
	NewEfxSpellCast();
	SpellFx_ClearBG1Position();

	proc = SpawnProc(ProcScr_EfxRelive, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
}

void EfxRelive_Loop(struct ProcEfx *proc)
{
	struct Anim *target = GetAnimAnotherSide(proc->anim);
	int duration = EfxGetCamMovDuration();

	proc->timer++;

	if (proc->timer == 1) {
		NewEfxLiveOBJ(proc->anim);
		PlaySFX(SONG_F3, 0x100, proc->anim->xPosition, 1);
	} else if (proc->timer == 52) {
		NewEfxLiveBG_A(proc->anim, 1);
		NewEfxLiveBGCOL_A(proc->anim, 1);

		SetBlendAlpha(0, 16);

		NewEfxLiveALPHA(proc->anim, 1, 12, 0);
		NewEfxLiveALPHA(proc->anim, 35, 25, 1);

		PlaySFX(SONG_110, 0x100, proc->anim->xPosition, 1);
	} else if (proc->timer == 55) {
		target->flags3 |= ANIM_BIT3_C02_BLOCK_END | ANIM_BIT3_C01_BLOCK_END_INBATTLE;
	} else if (proc->timer == 113) {
		NewEfxFarAttackWithDistance(proc->anim, -1);
	} else if (proc->timer == duration + 114) {
		NewEfxLiveBG_B(proc->anim, 1);
		NewEfxLiveBGCOL_B(proc->anim, 1);

		SetBlendAlpha(0, 16);

		NewEfxLiveALPHA(proc->anim, 1, 12, 0);
		NewEfxLiveALPHA(proc->anim, 29, 25, 1);

		PlaySFX(SONG_111, 0x100, target->xPosition, 1);
	} else if (proc->timer == duration + 166) {
		NewEfxHpBarLive(target);
	} else if (proc->timer == duration + 181) {
		SpellFx_Finish();
		EndEfxSpellCastAsync();

		if (GetAnimNextRoundType(target) != -1)
			target->flags3 |= ANIM_BIT3_NEXT_ROUND_START;

		Proc_Break(proc);
	}
}

CONST_DATA struct ProcScr ProcScr_EfxRecover[] = {
	PROC_NAME_DEBUG("efxRecover"),
	PROC_REPEAT(EfxRecover_Loop),
	PROC_END,
};


void StartSpellAnimRecover(struct Anim *anim)
{
	struct ProcEfx *proc;

	SpellFx_Begin();
	NewEfxSpellCast();
	SpellFx_ClearBG1Position();

	proc = SpawnProc(ProcScr_EfxRecover, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
}

void EfxRecover_Loop(struct ProcEfx *proc)
{
	struct Anim *target = GetAnimAnotherSide(proc->anim);
	int duration = EfxGetCamMovDuration();

	proc->timer++;

	if (proc->timer == 1) {
		NewEfxLiveOBJ(proc->anim);
		PlaySFX(SONG_F3, 0x100, proc->anim->xPosition, 1);
	} else if (proc->timer == 52) {
		NewEfxLiveBG_A(proc->anim, 2);
		NewEfxLiveBGCOL_A(proc->anim, 2);

		SetBlendAlpha(0, 16);

		NewEfxLiveALPHA(proc->anim, 1, 12, 0);
		NewEfxLiveALPHA(proc->anim, 35, 25, 1);

		PlaySFX(SONG_112, 0x100, proc->anim->xPosition, 1);
	} else if (proc->timer == 55) {
		target->flags3 |= ANIM_BIT3_C02_BLOCK_END | ANIM_BIT3_C01_BLOCK_END_INBATTLE;
	} else if (proc->timer == 113) {
		NewEfxFarAttackWithDistance(proc->anim, -1);
	} else if (proc->timer == duration + 114) {
		NewEfxLiveBG_B(proc->anim, 2);
		NewEfxLiveBGCOL_B(proc->anim, 2);

		SetBlendAlpha(0, 16);

		NewEfxLiveALPHA(proc->anim, 1, 12, 0);
		NewEfxLiveALPHA(proc->anim, 29, 25, 1);

		PlaySFX(SONG_113, 0x100, target->xPosition, 1);
	} else if (proc->timer == duration + 166) {
		NewEfxHpBarLive(target);
	} else if (proc->timer == duration + 181) {
		SpellFx_Finish();
		EndEfxSpellCastAsync();

		if (GetAnimNextRoundType(target) != -1)
			target->flags3 |= ANIM_BIT3_NEXT_ROUND_START;

		Proc_Break(proc);
	}
}

CONST_DATA struct ProcScr ProcScr_EfxReblow[] = {
	PROC_NAME_DEBUG("efxReblow"),
	PROC_REPEAT(EfxReblow_Loop),
	PROC_END,
};

void StartSpellAnimPhysic(struct Anim *anim)
{
	struct ProcEfx *proc;

	SpellFx_Begin();
	NewEfxSpellCast();
	SpellFx_ClearBG1Position();

	proc = SpawnProc(ProcScr_EfxReblow, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
}

void EfxReblow_Loop(struct ProcEfx *proc)
{
	struct Anim *target = GetAnimAnotherSide(proc->anim);
	int duration = EfxGetCamMovDuration();

	proc->timer++;

	if (proc->timer == 1) {
		NewEfxLiveOBJ(proc->anim);
		NewEfxReblowOBJ(proc->anim, 0);
		PlaySFX(SONG_F3, 0x100, proc->anim->xPosition, 1);
	} else if (proc->timer == 52) {
		NewEfxLiveBG_A(proc->anim, 0);
		NewEfxLiveBGCOL_A(proc->anim, 0);

		SetBlendAlpha(0, 16);

		NewEfxLiveALPHA(proc->anim, 1, 12, 0);
		NewEfxLiveALPHA(proc->anim, 35, 25, 1);

		PlaySFX(SONG_10E, 0x100, proc->anim->xPosition, 1);
	} else if (proc->timer == 55) {
		target->flags3 |= ANIM_BIT3_C02_BLOCK_END | ANIM_BIT3_C01_BLOCK_END_INBATTLE;
	} else if (proc->timer == 151) {
		NewEfxReblowOBJ(proc->anim, 1);
		NewEfxFarAttackWithDistance(proc->anim, -1);
	} else if (proc->timer == duration + 161) {
		NewEfxLiveBG_B(proc->anim, 0);
		NewEfxLiveBGCOL_B(proc->anim, 0);

		SetBlendAlpha(0, 16);

		NewEfxLiveALPHA(proc->anim, 1, 12, 0);
		NewEfxLiveALPHA(proc->anim, 29, 25, 1);

		PlaySFX(SONG_10F, 0x100, target->xPosition, 1);
	} else if (proc->timer == duration + 211) {
		NewEfxHpBarLive(target);
	} else if (proc->timer == duration + 221) {
		SpellFx_Finish();
		EndEfxSpellCastAsync();

		if (GetAnimNextRoundType(target) != -1)
			target->flags3 |= ANIM_BIT3_NEXT_ROUND_START;

		Proc_Break(proc);
	}
}

CONST_DATA struct ProcScr ProcScr_EfxLiveBG[] = {
	PROC_NAME_DEBUG("efxLiveBG"),
	PROC_REPEAT(EfxLiveBG_Loop),
	PROC_END,
};


CONST_DATA struct ProcScr ProcScr_EfxLiveBGCOL[] = {
	PROC_NAME_DEBUG("efxLiveBGCOL"),
	PROC_MARK(PROC_MARK_PAL_CHG),
	PROC_REPEAT(EfxLiveBGCOL_Loop),
	PROC_END,
};


CONST_DATA struct ProcScr ProcScr_EfxLiveALPHA[] = {
	PROC_NAME_DEBUG("efxLiveALPHA"),
	PROC_REPEAT(EfxLiveALPHA_Delay),
	PROC_REPEAT(EfxLiveALPHA_Loop),
	PROC_END,
};


CONST_DATA struct ProcScr ProcScr_EfxLiveOBJ[] = {
	PROC_NAME_DEBUG("efxLiveOBJ"),
	PROC_REPEAT(EfxLiveOBJ_Loop),
	PROC_END,
};


static const u16 EfxLiveBG_frames_1[] = {
	0x0, 62,
	-1,
};

static const u16 EfxLiveBG_frames_2[] = {
	0x1, 62,
	-1,
};

static const u16 EfxLiveBG_frames_3[] = {
	0x0, 62,
	-1,
};

static const u16 EfxLiveBG_frames_4[] = {
	0x1, 62,
	-1,
};

void NewEfxLiveBG_A(struct Anim *anim, u32 type)
{
	struct ProcEfxBG *proc;

	gEfxBgSemaphore++;
	proc = SpawnProc(ProcScr_EfxLiveBG, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->frame = 0;

	switch (type) {
	case 0:
		proc->unk29 = 1;
		proc->frame_config = EfxLiveBG_frames_1;
		proc->tsal = (u16 **)Tsa_Uncomp_EfxLiveBG_BB_L;
		proc->tsar = (u16 **)Tsa_Uncomp_EfxLiveBG_BB_L;
		SpellFx_RegisterBgGfx(Img_EfxHealCommon, 0x80 << 3);

		if (gEkrDistanceType != 0) {
			if (GetAnimPosition(proc->anim) == 0)
				SetBgOffset(BG_1, 0x18, 0);
			else
				SetBgOffset(BG_1, 0xe8, 0);
		}
		break;

	case 1:
	case 2:
		proc->unk29 = 1;
		proc->frame_config = EfxLiveBG_frames_3;
		proc->tsal = (u16 **)Tsa_Uncomp_EfxLiveBG_BA_L;
		proc->tsar = (u16 **)Tsa_Uncomp_EfxLiveBG_BA_R;
		SpellFx_RegisterBgGfx(Img_EfxLiveBG, 0xa8 * 0x20);
		break;

	default:
		break;
	}

	SpellFx_SetSomeColorEffect();
}

void NewEfxLiveBG_B(struct Anim *anim, u32 type)
{
	struct ProcEfxBG *proc;

	gEfxBgSemaphore++;
	proc = SpawnProc(ProcScr_EfxLiveBG, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->frame = 0;
	proc->unk29 = 0;

	switch (type) {
	case 0:
		proc->frame_config = EfxLiveBG_frames_2;
		proc->tsal = (u16 **)Tsa_Uncomp_EfxLiveBG_BB_L;
		proc->tsar = (u16 **)Tsa_Uncomp_EfxLiveBG_BB_L;
		SpellFx_RegisterBgGfx(Img_EfxHealCommon, 0x80 << 3);

		if (gEkrDistanceType != 0) {
			if (GetAnimPosition(proc->anim) == 0)
				SetBgOffset(BG_1, 0xe8, 0);
			else
				SetBgOffset(BG_1, 0x18, 0);
		}
		break;

	case 1:
	case 2:
		proc->frame_config = EfxLiveBG_frames_4;
		proc->tsal = (u16 **)Tsa_Uncomp_EfxLiveBG_BA_L;
		proc->tsar = (u16 **)Tsa_Uncomp_EfxLiveBG_BA_R;
		SpellFx_RegisterBgGfx(Img_EfxLiveBG, 0xa8 * 0x20);
		break;

	default:
		break;
	}

	SpellFx_SetSomeColorEffect();
}

void EfxLiveBG_Loop(struct ProcEfxBG *proc)
{
	int ret = EfxAdvanceFrameLut((i16 *)&proc->timer, (i16 *)&proc->frame, proc->frame_config);

	if (ret >= 0) {
		u16 *tsaL = (u16 *)proc->tsal;
		u16 *tsaR = (u16 *)proc->tsar;

		SpellFx_WriteBgMapUncomp(proc->anim, tsaL + ret * 600, tsaR + ret * 600);
		return;
	}

	if (ret != -1)
		return;

	if (proc->unk29 == 0) {
		SpellFx_ClearBG1();
		SpellFx_ClearColorEffects();
	}

	SetBgOffset(BG_1, 0, 0);
	gEfxBgSemaphore--;
	Proc_Break(proc);
}

static const u16 EfxLiveBGCOL_frames_1[] = {
	0x0, 3,
	0x1, 3,
	0x2, 3,
	0x3, 4,
	0x4, 4,
	0x5, 4,
	0x6, 4,
	0x7, 4,
	0x8, 4,
	0x9, 4,
	0xA, 4,
	0xB, 4,
	0xC, 4,
	0xD, 4,
	0xE, 4,
	0xF, 5,
	-1,
};

static const u16 EfxLiveBGCOL_frames_2[] = {
	0xF, 5,
	0xE, 4,
	0xD, 4,
	0xC, 4,
	0xB, 4,
	0xA, 4,
	0x9, 4,
	0x8, 4,
	0x7, 4,
	0x6, 4,
	0x5, 4,
	0x4, 4,
	0x3, 4,
	0x2, 3,
	0x1, 3,
	0x0, 3,
	-1,
};

static const u16 EfxLiveBGCOL_frames_3[] = {
	0x0, 3,
	0x1, 3,
	0x2, 3,
	0x3, 4,
	0x4, 4,
	0x5, 4,
	0x6, 4,
	0x7, 4,
	0x8, 4,
	0x9, 4,
	0xA, 4,
	0xB, 4,
	-1,
};

static const u16 EfxLiveBGCOL_frames_4[] = {
	0x0, 3,
	0x1, 3,
	0x2, 3,
	0x3, 4,
	0x4, 4,
	0x5, 4,
	0x6, 4,
	0x7, 4,
	0x8, 4,
	0x9, 4,
	0xA, 4,
	0xB, 4,
	0xC, 4,
	0xD, 4,
	0xE, 4,
	0xF, 5,
	-1,
};

void NewEfxLiveBGCOL_A(struct Anim *anim, u32 type)
{
	struct ProcEfxBGCOL *proc;

	gEfxBgSemaphore++;
	proc = SpawnProc(ProcScr_EfxLiveBGCOL, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->frame = 0;

	if (type == 0)
		proc->frame_config = EfxLiveBGCOL_frames_1;
	else if (type == 1)
		proc->frame_config = EfxLiveBGCOL_frames_3;
	else
		proc->frame_config = EfxLiveBGCOL_frames_4;

	if (type == 0)
		proc->pal = Pals1_EfxLiveBGCOL;
	else if (type == 1)
		proc->pal = Pals2_EfxLiveBGCOL;
	else
		proc->pal = Pals3_EfxLiveBGCOL;
}

void NewEfxLiveBGCOL_B(struct Anim *anim, u32 type)
{
	struct ProcEfxBGCOL *proc;

	gEfxBgSemaphore++;
	proc = SpawnProc(ProcScr_EfxLiveBGCOL, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->frame = 0;

	if (type == 0)
		proc->frame_config = EfxLiveBGCOL_frames_2;
	else if (type == 1)
		proc->frame_config = EfxLiveBGCOL_frames_3;
	else
		proc->frame_config = EfxLiveBGCOL_frames_4;

	if (type == 0)
		proc->pal = Pals1_EfxLiveBGCOL;
	else if (type == 1)
		proc->pal = Pals2_EfxLiveBGCOL;
	else
		proc->pal = Pals3_EfxLiveBGCOL;
}

void EfxLiveBGCOL_Loop(struct ProcEfxBGCOL *proc)
{
	int ret = EfxAdvanceFrameLut((i16 *)&proc->timer, (i16 *)&proc->frame, proc->frame_config);

	if (ret >= 0) {
		const u16 *pal = proc->pal;

		SpellFx_RegisterBgPal(pal + ret * 0x10, 0x20);
	} else if (ret == -1) {
		gEfxBgSemaphore--;
		Proc_Break(proc);
	}
}

void NewEfxLiveALPHA(struct Anim *anim, int timer, int duration, int type)
{
	struct ProcEfxALPHA *proc;

	gEfxBgSemaphore++;
	proc = SpawnProc(ProcScr_EfxLiveALPHA, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = timer;
	proc->delay = duration;
	proc->unk29 = type;
}

void EfxLiveALPHA_Delay(struct ProcEfxALPHA *proc)
{
	proc->timer--;

	if ((proc->timer << 16) != 0)
		return;

	Proc_Break(proc);
}

void EfxLiveALPHA_Loop(struct ProcEfxALPHA *proc)
{
	int bldA;

	if (proc->timer > proc->delay) {
		gEfxBgSemaphore--;
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

void NewEfxLiveOBJ(struct Anim *anim)
{
	struct ProcEfxOBJ *proc;

	gEfxBgSemaphore++;
	proc = SpawnProc(ProcScr_EfxLiveOBJ, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->terminator = 0x33;
	proc->anim2 = EfxCreateFrontAnim(anim, AnimScr_EfxLiveOBJ, AnimScr_EfxLiveOBJ,
					 AnimScr_EfxLiveOBJ, AnimScr_EfxLiveOBJ);

	SpellFx_RegisterObjPal(Pal_EfxFimbulvetrOBJ, 0x20);
	SpellFx_RegisterObjGfx(Img_EfxLiveOBJ, 0x80 << 5);
}

CONST_DATA struct ProcScr ProcScr_EfxReserveOBJ[] = {
	PROC_NAME_DEBUG("efxReserveOBJ"),
	PROC_REPEAT(EfxReserveOBJ_Loop1),
	PROC_REPEAT(EfxReserveOBJ_Loop2),
	PROC_END,
};


void NewEfxReserveOBJ(struct Anim *anim)
{
	struct ProcEfxOBJ *proc;

	gEfxBgSemaphore++;
	proc = SpawnProc(ProcScr_EfxReserveOBJ, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->terminator = 0x33;
	proc->unk30 = 0x34;
	proc->anim2 = EfxCreateFrontAnim(anim, AnimScr_EfxLiveOBJ, AnimScr_EfxLiveOBJ,
					 AnimScr_EfxLiveOBJ, AnimScr_EfxLiveOBJ);

	SpellFx_RegisterObjPal(Pal_EfxFimbulvetrOBJ, 0x20);
	SpellFx_RegisterObjGfx(Img_EfxLiveOBJ, 0x80 << 5);
}

void EfxLiveOBJ_Loop(struct ProcEfxOBJ *proc)
{
	proc->timer++;

	if (proc->timer == proc->terminator) {
		gEfxBgSemaphore--;
		BasRemove(proc->anim2);
		Proc_Break(proc);
	}
}

void EfxReserveOBJ_Loop1(struct ProcEfxOBJ *proc)
{
	struct BaSprite *anim = proc->anim2;

	proc->timer++;

	if (proc->timer != proc->terminator)
		return;

	anim->script = AnimScr_EfxReserveOBJ;
	anim->scrCur = AnimScr_EfxReserveOBJ;
	anim->timer = 0;
	proc->timer = 0;
	Proc_Break(proc);
}

void EfxReserveOBJ_Loop2(struct ProcEfxOBJ *proc)
{
	proc->timer++;

	if (proc->timer == (i16)proc->unk30) {
		gEfxBgSemaphore--;
		BasRemove(proc->anim2);
		Proc_Break(proc);
	}
}

CONST_DATA struct ProcScr ProcScr_EfxReblowOBJ[] = {
	PROC_NAME_DEBUG("efxReblowOBJ"),
	PROC_REPEAT(EfxReblowOBJ_Loop1),
	PROC_REPEAT(EfxReblowOBJ_Loop2),
	PROC_END,
};

void NewEfxReblowOBJ(struct Anim *anim, u32 kind)
{
	struct ProcEfxOBJ *proc;

	gEfxBgSemaphore++;
	proc = SpawnProc(ProcScr_EfxReblowOBJ, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->unk29 = kind;

	if (kind == 0) {
		proc->terminator = 0x2b;
		proc->unk30 = 0x44;
	} else {
		proc->terminator = 0x1f;
		proc->unk30 = 0x3d;
	}
}

void EfxReblowOBJ_Loop1(struct ProcEfxOBJ *proc)
{
	struct BaSprite *anim2;
	const AnimScr *scrL;
	const AnimScr *scrR;
	s16 x;
	s16 y;
	int pos;

	proc->timer++;

	if (proc->timer != proc->terminator)
		return;

	proc->timer = 0;

	switch (proc->unk29) {
	case 0:
		scrL = AnimScr_EfxReblowOBJ_L_A;
		scrR = AnimScr_EfxReblowOBJ_R_A;

		if (gEkrDistanceType != 0) {
			pos = GetAnimPosition(proc->anim);
			x = 0x88;
			if (pos == 0)
				x = 0x68;
		} else {
			pos = GetAnimPosition(proc->anim);
			x = 0x70;
			if (pos == 0)
				x = 0x80;
		}

		y = 0x4e;
		break;

	default:
		scrL = AnimScr_EfxReblowOBJ_L_B;
		scrR = AnimScr_EfxReblowOBJ_R_B;

		if (gEkrDistanceType != 0) {
			pos = GetAnimPosition(proc->anim);
			x = 0x4c;
			if (pos == 0)
				x = 0xa4;
		} else {
			pos = GetAnimPosition(proc->anim);
			x = 0x64;
			if (pos == 0)
				x = 0x8c;
		}

		y = 0x40;
		break;
	}

	anim2 = EfxCreateFrontAnim(proc->anim, scrR, scrL, scrR, scrL);
	proc->anim2 = anim2;
	anim2->xPosition = x;
	anim2->yPosition = y;
	Proc_Break(proc);
}

void EfxReblowOBJ_Loop2(struct ProcEfxOBJ *proc)
{
	proc->timer++;

	if (proc->timer == (i16)proc->unk30) {
		gEfxBgSemaphore--;
		BasRemove(proc->anim2);
		Proc_Break(proc);
	}
}

CONST_DATA struct ProcScr ProcScr_EfxReserve[] = {
	PROC_NAME_DEBUG("efxReserve"),
	PROC_REPEAT(EfxReserve_Loop),
	PROC_END,
};


CONST_DATA struct ProcScr ProcScr_EfxReserveBG[] = {
	PROC_NAME_DEBUG("efxReserveBG"),
	PROC_REPEAT(EfxReserveBG_Loop),
	PROC_END,
};


CONST_DATA u16 *TsaArray_EfxReserveBG[] = {
	Tsa_EfxReserveBG_081ADFEC,
	Tsa_EfxReserveBG_081AE0F8,
	Tsa_EfxReserveBG_081AE1F8,
	Tsa_EfxReserveBG_081AE304,
};


CONST_DATA struct ProcScr ProcScr_EfxReserveBGCOL[] = {
	PROC_NAME_DEBUG("efxReserveBGCOL"),
	PROC_MARK(PROC_MARK_PAL_CHG),
	PROC_REPEAT(EfxReserveBGCOL_Loop),
	PROC_END,
};


CONST_DATA struct ProcScr ProcScr_EfxReserveBG2[] = {
	PROC_NAME_DEBUG("efxReserveBG2"),
	PROC_REPEAT(EfxReserveBG2_Loop),
	PROC_END,
};


CONST_DATA u16 *TsaArray_EfxReserveBG2[] = {
	Tsa_EfxReserveBG2_081AE410,
};


CONST_DATA struct ProcScr ProcScr_EfxReserveBGCOL2[] = {
	PROC_NAME_DEBUG("efxReserveBGCOL2"),
	PROC_MARK(PROC_MARK_PAL_CHG),
	PROC_REPEAT(EfxReserveBGCOL2_Loop),
	PROC_END,
};


void StartSpellAnimFortify(struct Anim *anim)
{
	struct ProcEfx *proc;

	SpellFx_Begin();
	NewEfxSpellCast();
	SpellFx_ClearBG1Position();

	proc = SpawnProc(ProcScr_EfxReserve, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->hitted = 0;
}

void StartSpellAnimLatona(struct Anim *anim)
{
	struct ProcEfx *proc;

	SpellFx_Begin();
	NewEfxSpellCast();
	SpellFx_ClearBG1Position();

	proc = SpawnProc(ProcScr_EfxReserve, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->hitted = 1;
}

void EfxReserve_Loop(struct ProcEfx *proc)
{
	proc->timer++;

	if (proc->timer == 1) {
		NewEfxReserveOBJ(proc->anim);
		PlaySFX(SONG_F3, 0x100, proc->anim->xPosition, 1);
	} else if (proc->timer == 52) {
		NewEfxReserveBG(proc->anim);
		NewEfxReserveBGCOL(proc->anim, proc->hitted);
	} else if (proc->timer == 183) {
		PlaySFX(SONG_114, 0x100, 0x78, 0);
		NewEfxReserveBG2(proc->anim);
		NewEfxReserveBGCOL2(proc->anim, proc->hitted);

		SetBlendAlpha(0, 16);

		NewEfxLiveALPHA(proc->anim, 1, 20, 0);
		NewEfxLiveALPHA(proc->anim, 180, 40, 1);
	} else if (proc->timer == 453) {
		SpellFx_Finish();
		EndEfxSpellCastAsync();
		Proc_Break(proc);
	}
}

void NewEfxReserveBG(struct Anim *anim)
{
	struct ProcEfxBG *proc;

	static const u16 frames[] = {
		0x0, 32,
		0x1, 32,
		0x2, 32,
		0x3, 32,
		-1,
	};

	gEfxBgSemaphore++;
	proc = SpawnProc(ProcScr_EfxReserveBG, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->frame = 0;
	proc->frame_config = frames;
	proc->tsal = TsaArray_EfxReserveBG;
	proc->tsar = TsaArray_EfxReserveBG;
	SpellFx_RegisterBgGfx(Img_EfxHealCommon, 0x80 << 3);
	SpellFx_SetSomeColorEffect();
}

void EfxReserveBG_Loop(struct ProcEfxBG *proc)
{
	static const u16 sfx[] = {
		270,
		271,
		270,
		271,
	};

	static const u16 sfx_loc[] = {
		160,
		56,
		128,
		40,
	};

	struct Anim *target = GetAnimAnotherSide(proc->anim);
	int ret = EfxAdvanceFrameLut((i16 *)&proc->timer, (i16 *)&proc->frame, proc->frame_config);

	if (ret >= 0) {
		u16 **tsaL = proc->tsal;
		u16 **tsaR = proc->tsar;
		u16 song;
		u16 loc;

		SpellFx_WriteBgMap(target, tsaL[ret], tsaR[ret]);
		song = sfx[ret];
		loc = sfx_loc[ret];
		PlaySFX(song, 0x100, loc, 0);
		return;
	}

	if (ret != -1)
		return;

	SpellFx_ClearBG1();
	gEfxBgSemaphore--;
	SpellFx_ClearColorEffects();
	Proc_Break(proc);
}

void NewEfxReserveBGCOL(struct Anim *anim, u32 kind)
{
	struct ProcEfxBGCOL *proc;

	static const u16 frames[] = {
		0x0, 2,
		0x1, 2,
		0x2, 2,
		0x3, 2,
		0x4, 2,
		0x5, 2,
		0x6, 2,
		0x7, 2,
		0x8, 2,
		0x9, 2,
		0xA, 2,
		0xB, 2,
		0xC, 2,
		0xD, 2,
		0xE, 2,
		0xF, 2,
		0x0, 2,
		0x1, 2,
		0x2, 2,
		0x3, 2,
		0x4, 2,
		0x5, 2,
		0x6, 2,
		0x7, 2,
		0x8, 2,
		0x9, 2,
		0xA, 2,
		0xB, 2,
		0xC, 2,
		0xD, 2,
		0xE, 2,
		0xF, 2,
		0x0, 2,
		0x1, 2,
		0x2, 2,
		0x3, 2,
		0x4, 2,
		0x5, 2,
		0x6, 2,
		0x7, 2,
		0x8, 2,
		0x9, 2,
		0xA, 2,
		0xB, 2,
		0xC, 2,
		0xD, 2,
		0xE, 2,
		0xF, 2,
		0x0, 2,
		0x1, 2,
		0x2, 2,
		0x3, 2,
		0x4, 2,
		0x5, 2,
		0x6, 2,
		0x7, 2,
		0x8, 2,
		0x9, 2,
		0xA, 2,
		0xB, 2,
		0xC, 2,
		0xD, 2,
		0xE, 2,
		0xF, 2,
		-1,
	};

	gEfxBgSemaphore++;
	proc = SpawnProc(ProcScr_EfxReserveBGCOL, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->frame = 0;
	proc->frame_config = frames;

	if (kind == 0)
		proc->pal = Pals1_EfxReserveBGCOL;
	else if (kind == 1)
		proc->pal = Pals2_EfxReserveBGCOL;
	else
		proc->pal = Pals2_EfxReserveBGCOL;
}

void EfxReserveBGCOL_Loop(struct ProcEfxBGCOL *proc)
{
	int ret;

	ret = EfxAdvanceFrameLut((i16 *)&proc->timer, (i16 *)&proc->frame,
				 proc->frame_config);

	if (ret >= 0) {
		const u16 *pal = proc->pal;

		SpellFx_RegisterBgPal(pal + ret * 0x10, 0x20);
	} else if (ret == -1) {
		gEfxBgSemaphore--;
		Proc_Break(proc);
	}
}

void NewEfxReserveBG2(struct Anim *anim)
{
	struct ProcEfxBG *proc;

	static const u16 frames[] = {
		0x0, 220,
		-1,
	};

	gEfxBgSemaphore++;
	proc = SpawnProc(ProcScr_EfxReserveBG2, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->frame = 0;
	proc->frame_config = frames;
	proc->tsal = TsaArray_EfxReserveBG2;
	proc->tsar = TsaArray_EfxReserveBG2;
	SpellFx_RegisterBgGfx(Img_EfxLiveBG, 0xa8 * 0x20);

	gDispIo.bg0_ct.priority = 0;
	gDispIo.bg2_ct.priority = 1;
	gDispIo.bg1_ct.priority = 2;
	gDispIo.bg3_ct.priority = 3;

	PutEfxTerrainToLowerLayer();

	anim->oam2 = (anim->oam2 & 0xF3FF) | OAM2_LAYER(1);

	SpellFx_SetSomeColorEffect();
	SetBlendTargetA(0, 1, 0, 0, 0);
	SetBlendTargetB(0, 0, 0, 1, 0);
}

void EfxReserveBG2_Loop(struct ProcEfxBG *proc)
{
	struct Anim *target = GetAnimAnotherSide(proc->anim);
	struct Anim *caster = proc->anim;
	int ret = EfxAdvanceFrameLut((i16 *)&proc->timer, (i16 *)&proc->frame,
				     proc->frame_config);

	if (ret >= 0) {
		u16 **tsaL = proc->tsal;
		u16 **tsaR = proc->tsar;

		SpellFx_WriteBgMap(target, tsaL[ret], tsaR[ret]);
		return;
	}

	if (ret != -1)
		return;

	SpellFx_ClearBG1();
	gEfxBgSemaphore--;

	gDispIo.bg0_ct.priority = 0;
	gDispIo.bg1_ct.priority = 1;
	gDispIo.bg2_ct.priority = 2;
	gDispIo.bg3_ct.priority = 3;

	caster->oam2 = (caster->oam2 & 0xF3FF) | OAM2_LAYER(2);

	SpellFx_ClearColorEffects();
	Proc_Break(proc);
}

void NewEfxReserveBGCOL2(struct Anim *anim, u32 kind)
{
	struct ProcEfxBGCOL *proc;

	static const u16 frames[] = {
		0x0, 4,
		0x1, 4,
		0x2, 4,
		0x3, 4,
		0x4, 4,
		0x5, 4,
		0x6, 4,
		0x7, 4,
		0x8, 4,
		0x9, 4,
		0xA, 4,
		0xB, 4,
		0xC, 4,
		0xD, 4,
		0xE, 4,
		0x0, 4,
		0x1, 4,
		0x2, 4,
		0x3, 4,
		0x4, 4,
		0x5, 4,
		0x6, 4,
		0x7, 4,
		0x8, 4,
		0x9, 4,
		0xA, 4,
		0xB, 4,
		0xC, 4,
		0xD, 4,
		0xE, 4,
		0x0, 4,
		0x1, 4,
		0x2, 4,
		0x3, 4,
		0x4, 4,
		0x5, 4,
		0x6, 4,
		0x7, 4,
		0x8, 4,
		0x9, 4,
		0xA, 4,
		0xB, 4,
		0xC, 4,
		0xD, 4,
		0xE, 4,
		0x0, 4,
		0x1, 4,
		0x2, 4,
		0x3, 4,
		0x4, 4,
		0x5, 4,
		0x6, 4,
		0x7, 4,
		0x8, 4,
		0x9, 4,
		-1,
	};

	gEfxBgSemaphore++;
	proc = SpawnProc(ProcScr_EfxReserveBGCOL2, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->frame = 0;
	proc->frame_config = frames;

	if (kind == 0)
		proc->pal = Pals1_EfxLiveBGCOL;
	else if (kind == 1)
		proc->pal = Pals2_EfxReserveBGCOL2;
	else
		proc->pal = Pals2_EfxReserveBGCOL2;
}

void EfxReserveBGCOL2_Loop(struct ProcEfxBGCOL *proc)
{
	int ret;

	ret = EfxAdvanceFrameLut((i16 *)&proc->timer, (i16 *)&proc->frame,
				 proc->frame_config);

	if (ret >= 0) {
		const u16 *pal = proc->pal;

		SpellFx_RegisterBgPal(pal + ret * 0x10, 0x20);
	} else if (ret == -1) {
		gEfxBgSemaphore--;
		Proc_Break(proc);
	}
}

CONST_DATA struct ProcScr ProcScr_EfxRest[] = {
	PROC_NAME_DEBUG("efxRest"),
	PROC_REPEAT(EfxRest_Loop),
	PROC_END,
};


CONST_DATA struct ProcScr ProcScr_EfxRestBG[] = {
	PROC_NAME_DEBUG("efxRestBG"),
	PROC_REPEAT(EfxRestBG_Loop),
	PROC_END,
};


CONST_DATA u16 *TsaArray_EfxRestBG[] = {
	Tsa_EfxRestBG_081B1730,
	Tsa_EfxRestBG_081B17DC,
	Tsa_EfxRestBG_081B1890,
	Tsa_EfxRestBG_081B1950,
	Tsa_EfxRestBG_081B1A18,
	Tsa_EfxRestBG_081B1AF4,
	Tsa_EfxRestBG_081B1BD4,
	Tsa_EfxRestBG_081B1CBC,
	Tsa_EfxRestBG_081B1DAC,
	Tsa_EfxRestBG_081B1EAC,
	Tsa_EfxRestBG_081B1FB8,
	Tsa_EfxRestBG_081B20D8,
	Tsa_EfxRestBG_081B2208,
};


CONST_DATA u16 *ImgArray_EfxRestBG[] = {
	Img_EfxRestBG_081AFC70,
	Img_EfxRestBG_081AFC70,
	Img_EfxRestBG_081AFC70,
	Img_EfxRestBG_081AFC70,
	Img_EfxRestBG_081AFC70,
	Img_EfxRestBG_081AFC70,
	Img_EfxRestBG_081B029C,
	Img_EfxRestBG_081B029C,
	Img_EfxRestBG_081B029C,
	Img_EfxRestBG_081B0994,
	Img_EfxRestBG_081B0994,
	Img_EfxRestBG_081B0FB4,
	Img_EfxRestBG_081B0FB4,
};


CONST_DATA struct ProcScr ProcScr_EfxRestOBJ[] = {
	PROC_NAME_DEBUG("efxRestOBJ"),
	PROC_ONEND(EfxRestOBJ_Loop),
	PROC_SLEEP(80),
	PROC_END,
};


void StartSpellAnimRestore(struct Anim *anim)
{
	struct ProcEfx *proc;

	SpellFx_Begin();
	NewEfxSpellCast();
	SpellFx_ClearBG1Position();

	proc = SpawnProc(ProcScr_EfxRest, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->hitted = CheckRoundMiss(GetAnimRoundTypeAnotherSide(anim));
}

void EfxRest_Loop(struct ProcEfx *proc)
{
	struct Anim *target;
	int duration;

	target = GetAnimAnotherSide(proc->anim);
	duration = EfxGetCamMovDuration();

	proc->timer++;

	if (proc->timer == 1)
		NewEfxFarAttackWithDistance(proc->anim, -1);

	if (proc->timer == duration + 1) {
		NewEfxRestBG(target);
		NewEfxALPHA(target, 40, 30, 16, 8, 0);
		NewEfxALPHA(target, 71, 30, 8, 16, 0);
		NewEfxALPHA(target, 102, 30, 16, 8, 0);
		NewEfxALPHA(target, 133, 30, 8, 16, 0);
		NewEfxALPHA(target, 164, 60, 16, 0, 0);
		PlaySFX(SONG_FD, 0x100, target->xPosition, 1);
	} else if (proc->timer == duration + 80) {
		NewEfxRestOBJ(target);
	} else if (proc->timer == duration + 164) {
		NewEfxFlashUnit(target, 1, 5, 0);
	} else if (proc->timer == duration + 200) {
		target->flags3 |= ANIM_BIT3_C02_BLOCK_END | ANIM_BIT3_C01_BLOCK_END_INBATTLE;
		StartBattleAnimStatusChgHitEffects(target, proc->hitted);
		SetUnitEfxDebuff(target, 0);
	} else if (proc->timer == duration + 300) {
		target->flags3 |= ANIM_BIT3_NEXT_ROUND_START;
		SpellFx_Finish();
		EndEfxSpellCastAsync();
		Proc_Break(proc);
	}
}

void NewEfxRestBG(struct Anim *anim)
{
	struct ProcEfxBG *proc;

	static const u16 frames[] = {
		0x0, 4,
		0x1, 4,
		0x2, 4,
		0x3, 4,
		0x4, 3,
		0x5, 3,
		0x6, 3,
		0x7, 3,
		0x8, 3,
		0x9, 2,
		0xA, 2,
		0xB, 2,
		0xC, 250,
		-1,
	};

	gEfxBgSemaphore++;
	proc = SpawnProc(ProcScr_EfxRestBG, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->frame = 0;
	proc->frame_config = frames;
	proc->tsal = TsaArray_EfxRestBG;
	proc->tsar = TsaArray_EfxRestBG;
	proc->img = ImgArray_EfxRestBG;
	SpellFx_RegisterBgPal(Pal_EfxRestBG, 0x20);
	SpellFx_SetSomeColorEffect();
}

void EfxRestBG_Loop(struct ProcEfxBG *proc)
{
	int ret = EfxAdvanceFrameLut((i16 *)&proc->timer, (i16 *)&proc->frame, proc->frame_config);

	if (ret >= 0) {
		u16 **tsaL = proc->tsal;
		u16 **tsaR = proc->tsar;
		u16 **img = proc->img;

		SpellFx_WriteBgMap(proc->anim, tsaL[ret], tsaR[ret]);
		SpellFx_RegisterBgGfx(img[ret], 0x80 << 6);
		return;
	}

	if (ret != -1)
		return;

	SpellFx_ClearBG1();
	gEfxBgSemaphore--;
	SpellFx_ClearColorEffects();
	Proc_Break(proc);
}

void NewEfxRestOBJ(struct Anim *anim)
{
	struct ProcEfxOBJ *proc;
	struct BaSprite *anim2;

	gEfxBgSemaphore++;
	proc = SpawnProc(ProcScr_EfxRestOBJ, PROC_TREE_3);
	proc->anim = anim;
	anim2 = EfxCreateFrontAnim(anim, AnimScr_EfxRestOBJ, AnimScr_EfxRestOBJ,
				   AnimScr_EfxRestOBJ, AnimScr_EfxRestOBJ);
	proc->anim2 = anim2;

	if (GetAnimPosition(anim) == 0)
		anim2->xPosition -= 8;
	else
		anim2->xPosition += 8;
	anim2->yPosition -= 8;

	SpellFx_RegisterObjPal(Pal_EfxRestOBJ, 0x20);
	SpellFx_RegisterObjGfx(Img_EfxHammarneOBJ, 0x80 << 4);
}

void EfxRestOBJ_Loop(void)
{
	gEfxBgSemaphore--;
}

CONST_DATA struct ProcScr ProcScr_EfxSilence[] = {
	PROC_NAME_DEBUG("efxSilence"),
	PROC_REPEAT(EfxSilence_Loop),
	PROC_END,
};


CONST_DATA struct ProcScr ProcScr_EfxSilenceBG[] = {
	PROC_NAME_DEBUG("efxSilenceBG"),
	PROC_REPEAT(EfxSilenceBG_Loop),
	PROC_END,
};


CONST_DATA u16 *TsaArray_EfxSilenceBG[] = {
	Tsa_EfxSilenceBG_081B2E10,
	Tsa_EfxSilenceBG_081B2F0C,
	Tsa_EfxSilenceBG_081B2FF4,
	Tsa_EfxSilenceBG_081B30DC,
	Tsa_EfxSilenceBG_081B31C4,
	Tsa_EfxSilenceBG_081B32C0,
	Tsa_EfxSilenceBG_081B33A8,
	Tsa_EfxSilenceBG_081B3440,
	Tsa_EfxSilenceBG_081B3528,
	Tsa_EfxSilenceBG_081B35C0,
	Tsa_EfxSilenceBG_081B36A8,
	Tsa_EfxSilenceBG_081B37A4,
	Tsa_EfxSilenceBG_081B383C,
	Tsa_EfxSilenceBG_081B3924,
	Tsa_EfxSilenceBG_081B39BC,
	Tsa_EfxSilenceBG_081B3AB8,
	Tsa_EfxSilenceBG_081B3B50,
	Tsa_EfxSilenceBG_081B3C60,
};


CONST_DATA struct ProcScr ProcScr_EfxSilenceOBJ[] = {
	PROC_NAME_DEBUG("efxSilenceOBJ"),
	PROC_ONEND(EfxSilenceOBJ_OnEnd),
	PROC_SLEEP(40),
	PROC_END,
};


void StartSpellAnimSilence(struct Anim *anim)
{
	struct ProcEfx *proc;

	SpellFx_Begin();
	NewEfxSpellCast();
	SpellFx_ClearBG1Position();

	proc = SpawnProc(ProcScr_EfxSilence, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->hitted = CheckRoundMiss(GetAnimRoundTypeAnotherSide(anim));
}

void EfxSilence_Loop(struct ProcEfx *proc)
{
	struct Anim *target;
	int duration;

	target = GetAnimAnotherSide(proc->anim);
	duration = EfxGetCamMovDuration();

	proc->timer++;

	if (proc->timer == 1) {
		NewEfxSilenceOBJ(proc->anim);
		PlaySFX(SONG_FA, 0x100, proc->anim->xPosition, 1);
	}

	if (proc->timer == 41)
		NewEfxFarAttackWithDistance(proc->anim, -1);
	else if (proc->timer == duration + 68) {
		NewEfxSilenceBG(proc->anim);
		PlaySFX(SONG_FB, 0x100, target->xPosition, 1);
		NewEfxALPHA(proc->anim, 66, 20, 16, 0, 0);
	} else if (proc->timer == duration + 134) {
		PlaySFX(SONG_FC, 0x100, target->xPosition, 1);
		EfxStopBGM1();
		target->flags3 |= ANIM_BIT3_C02_BLOCK_END | ANIM_BIT3_C01_BLOCK_END_INBATTLE;
		StartBattleAnimStatusChgHitEffects(target, proc->hitted);
		NewEfxFlashBgWhite(proc->anim, 10);

		if (!proc->hitted && GetUnitEfxDebuff(target) == 0)
			SetUnitEfxDebuff(target, 3);
	} else if (proc->timer == duration + 158) {
		target->flags3 |= ANIM_BIT3_NEXT_ROUND_START;
		SpellFx_Finish();
		EndEfxSpellCastAsync();
		Proc_Break(proc);
	}
}

void NewEfxSilenceBG(struct Anim *anim)
{
	struct ProcEfxBG *proc;

	static const u16 frames[] = {
		0x0, 2,
		0x1, 1,
		0x2, 1,
		0x3, 1,
		0x4, 1,
		0x5, 1,
		0x6, 4,
		0x7, 1,
		0x8, 5,
		0x9, 2,
		0xA, 2,
		0xB, 2,
		0xC, 2,
		0xD, 2,
		0xE, 2,
		0xF, 1,
		0x10, 5,
		0x11, 50,
		-1,
	};

	gEfxBgSemaphore++;
	proc = SpawnProc(ProcScr_EfxSilenceBG, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->frame = 0;
	proc->frame_config = frames;
	proc->tsal = (u16 **)TsaArray_EfxSilenceBG;
	proc->tsar = (u16 **)TsaArray_EfxSilenceBG;
	SpellFx_RegisterBgPal(Pal_EfxSilenceBG, 0x20);
	SpellFx_RegisterBgGfx(Img_EfxSilenceBG, 0x80 << 6);
	SpellFx_SetSomeColorEffect();

	if (gEkrDistanceType != 0) {
		if (GetAnimPosition(proc->anim) == 0)
			SetBgOffset(BG_1, 0xe8, 0);
		else
			SetBgOffset(BG_1, 0x18, 0);
	}
}

void EfxSilenceBG_Loop(struct ProcEfxBG *proc)
{
	int ret = EfxAdvanceFrameLut((i16 *)&proc->timer, (i16 *)&proc->frame, proc->frame_config);

	if (ret >= 0) {
		u16 **tsaL = proc->tsal;
		u16 **tsaR = proc->tsar;

		SpellFx_WriteBgMap(proc->anim, tsaL[ret], tsaR[ret]);
		return;
	}

	if (ret != -1)
		return;

	SpellFx_ClearBG1();
	gEfxBgSemaphore--;
	SpellFx_ClearColorEffects();
	Proc_Break(proc);
}

void NewEfxSilenceOBJ(struct Anim *anim)
{
	struct ProcEfxOBJ *proc;

	gEfxBgSemaphore++;
	proc = SpawnProc(ProcScr_EfxSilenceOBJ, PROC_TREE_3);
	proc->anim = anim;
	proc->anim2 = EfxCreateFrontAnim(anim, AnimScr_EfxSilenceOBJ, AnimScr_EfxSilenceOBJ,
					 AnimScr_EfxSilenceOBJ, AnimScr_EfxSilenceOBJ);
	SpellFx_RegisterObjPal(Pal_EfxSilenceBG, 0x20);
	SpellFx_RegisterObjGfx(Img_EfxSilenceOBJ, 0x80 << 5);
}

void EfxSilenceOBJ_OnEnd(struct ProcEfxOBJ *proc)
{
	BasRemove(proc->anim2);
	gEfxBgSemaphore--;
}

CONST_DATA struct ProcScr ProcScr_EfxSleep[] = {
	PROC_NAME_DEBUG("efxSleep"),
	PROC_REPEAT(EfxSleep_Loop),
	PROC_END,
};


CONST_DATA struct ProcScr ProcScr_EfxSleepBG[] = {
	PROC_NAME_DEBUG("efxSleepBG"),
	PROC_REPEAT(EfxSleepBG_Loop),
	PROC_END,
};


CONST_DATA u16 *TsaArray_EfxSleepBG[] = {
	Tsa_EfxSleepBG_081B66A8,
	Tsa_EfxSleepBG_081B6784,
	Tsa_EfxSleepBG_081B6860,
	Tsa_EfxSleepBG_081B693C,
	Tsa_EfxSleepBG_081B6A18,
	Tsa_EfxSleepBG_081B6AF4,
	Tsa_EfxSleepBG_081B6BD0,
	Tsa_EfxSleepBG_081B6CAC,
	Tsa_EfxSleepBG_081B6D88,
	Tsa_EfxSleepBG_081B6E64,
	Tsa_EfxSleepBG_081B6F40,
	Tsa_EfxSleepBG_081B701C,
	Tsa_EfxSleepBG_081B70F8,
	Tsa_EfxSleepBG_081B71D4,
	Tsa_EfxSleepBG_081B72B0,
	Tsa_EfxSleepBG_081B738C,
};


CONST_DATA struct ProcScr ProcScr_EfxSleepOBJ[] = {
	PROC_NAME_DEBUG("efxSleepOBJ"),
	PROC_ONEND(EfxSleepOBJ_OnEnd),
	PROC_SLEEP(80),
	PROC_END,
};


CONST_DATA struct ProcScr ProcScr_EfxSleepOBJ2[] = {
	PROC_NAME_DEBUG("efxSleepOBJ2"),
	PROC_ONEND(EfxSleepOBJ_OnEnd),
	PROC_SLEEP(200),
	PROC_END,
};


CONST_DATA struct ProcScr ProcScr_EfxSleepSE[] = {
	PROC_NAME_DEBUG("efxSleepSE"),
	PROC_ONEND(EfxSleepSE_OnEnd),
	PROC_SLEEP(1),
	PROC_CALL(EfxSleepSE_PlaySE),
	PROC_SLEEP(54),
	PROC_CALL(EfxSleepSE_PlaySE),
	PROC_SLEEP(65),
	PROC_CALL(EfxSleepSE_PlaySE),
	PROC_END,
};


void StartSpellAnimSleep(struct Anim *anim)
{
	struct ProcEfx *proc;

	SpellFx_Begin();
	NewEfxSpellCast();
	SpellFx_ClearBG1Position();

	proc = SpawnProc(ProcScr_EfxSleep, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->hitted = CheckRoundMiss(GetAnimRoundTypeAnotherSide(anim));
}

void EfxSleep_Loop(struct ProcEfx *proc)
{
	struct Anim *target;
	int duration;

	target = GetAnimAnotherSide(proc->anim);
	duration = EfxGetCamMovDuration();

	proc->timer++;

	if (proc->timer == 1) {
		NewEfxSleepOBJ(proc->anim);
		PlaySFX(SONG_11B, 0x100, proc->anim->xPosition, 1);
	}

	if (proc->timer == 100)
		NewEfxFarAttackWithDistance(proc->anim, -1);

	if (proc->timer == duration + 130) {
		NewEfxSleepOBJ2(target);
		NewEfxSleepSE(target);
		NewEfxSleepBG(proc->anim);
		NewEfxALPHA(target, 0, 20, 0, 16, 0);
		NewEfxALPHA(target, 230, 20, 16, 0, 0);
	} else if (proc->timer == duration + 330) {
		target->flags3 |= ANIM_BIT3_C02_BLOCK_END | ANIM_BIT3_C01_BLOCK_END_INBATTLE;
		StartBattleAnimStatusChgHitEffects(target, proc->hitted);

		if (!proc->hitted && GetUnitEfxDebuff(target) == 0)
			SetUnitEfxDebuff(target, 2);
	} else if (proc->timer == duration + 370) {
		target->flags3 |= ANIM_BIT3_NEXT_ROUND_START;
		SpellFx_Finish();
		EndEfxSpellCastAsync();
		Proc_Break(proc);
	}
}

void NewEfxSleepBG(struct Anim *anim)
{
	struct ProcEfxBG *proc;

	static const u16 frames[] = {
		0x0, 4,
		0x1, 4,
		0x2, 4,
		0x3, 4,
		0x4, 4,
		0x5, 4,
		0x6, 4,
		0x7, 4,
		0x8, 4,
		0x9, 4,
		0xA, 4,
		0xB, 4,
		0xC, 4,
		0xD, 4,
		0xE, 4,
		0xF, 4,
		0x0, 4,
		0x1, 4,
		0x2, 4,
		0x3, 4,
		0x4, 4,
		0x5, 4,
		0x6, 4,
		0x7, 4,
		0x8, 4,
		0x9, 4,
		0xA, 4,
		0xB, 4,
		0xC, 4,
		0xD, 4,
		0xE, 4,
		0xF, 4,
		0x0, 4,
		0x1, 4,
		0x2, 4,
		0x3, 4,
		0x4, 4,
		0x5, 4,
		0x6, 4,
		0x7, 4,
		0x8, 4,
		0x9, 4,
		0xA, 4,
		0xB, 4,
		0xC, 4,
		0xD, 4,
		0xE, 4,
		0xF, 4,
		0x0, 4,
		0x1, 4,
		0x2, 4,
		0x3, 4,
		0x4, 4,
		0x5, 4,
		0x6, 4,
		0x7, 4,
		0x8, 4,
		0x9, 4,
		0xA, 4,
		0xB, 4,
		0xC, 4,
		0xD, 4,
		0xE, 4,
		0xF, 4,
		-1,
	};

	gEfxBgSemaphore++;
	proc = SpawnProc(ProcScr_EfxSleepBG, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->frame = 0;
	proc->frame_config = frames;
	proc->tsal = (u16 **)TsaArray_EfxSleepBG;
	proc->tsar = (u16 **)TsaArray_EfxSleepBG;
	SpellFx_RegisterBgPal(Pal_EfxSleepBG, 0x20);
	SpellFx_RegisterBgGfx(Img_EfxSleepBG, 0x80 << 6);
	SpellFx_SetSomeColorEffect();

	if (gEkrDistanceType != 0) {
		if (GetAnimPosition(proc->anim) == 0)
			SetBgOffset(BG_1, 0xe8, 0);
		else
			SetBgOffset(BG_1, 0x18, 0);
	}
}

void EfxSleepBG_Loop(struct ProcEfxBG *proc)
{
	int ret = EfxAdvanceFrameLut((i16 *)&proc->timer, (i16 *)&proc->frame, proc->frame_config);

	if (ret >= 0) {
		u16 **tsaL = proc->tsal;
		u16 **tsaR = proc->tsar;

		SpellFx_WriteBgMap(proc->anim, tsaL[ret], tsaR[ret]);
		return;
	}

	if (ret != -1)
		return;

	SpellFx_ClearBG1();
	gEfxBgSemaphore--;
	SpellFx_ClearColorEffects();
	Proc_Break(proc);
}

void NewEfxSleepOBJ(struct Anim *anim)
{
	struct ProcEfxOBJ *proc;

	gEfxBgSemaphore++;
	proc = SpawnProc(ProcScr_EfxSleepOBJ, PROC_TREE_3);
	proc->anim = anim;
	proc->anim2 = EfxCreateFrontAnim(anim, AnimScr_EfxSleepOBJ, AnimScr_EfxSleepOBJ,
					 AnimScr_EfxSleepOBJ, AnimScr_EfxSleepOBJ);
	SpellFx_RegisterObjPal(Pal_EfxRestOBJ, 0x20);
	SpellFx_RegisterObjGfx(Img_EfxHammarneOBJ, 0x80 << 4);
}

void NewEfxSleepOBJ2(struct Anim *anim)
{
	struct ProcEfxOBJ *proc;
	struct BaSprite *sprite;

	gEfxBgSemaphore++;
	proc = SpawnProc(ProcScr_EfxSleepOBJ2, PROC_TREE_3);
	proc->anim = anim;
	sprite = EfxCreateFrontAnim(anim, AnimScr_EfxSleepOBJ2, AnimScr_EfxSleepOBJ2,
				    AnimScr_EfxSleepOBJ2, AnimScr_EfxSleepOBJ2);
	proc->anim2 = sprite;
	sprite->yPosition -= 8;

	if (GetEkrDragonStateTypeIdunn() != 0)
		sprite->xPosition -= 0x10;
}

void EfxSleepOBJ_OnEnd(void)
{
	gEfxBgSemaphore--;
}

void NewEfxSleepSE(struct Anim *anim)
{
	struct ProcEfx *proc;

	gEfxBgSemaphore++;
	proc = SpawnProc(ProcScr_EfxSleepSE, PROC_TREE_3);
	proc->anim = anim;
}

void EfxSleepSE_PlaySE(struct ProcEfx *proc)
{
	PlaySFX(SONG_11C, 0x100, proc->anim->xPosition, 1);
}

void EfxSleepSE_OnEnd(void)
{
	gEfxBgSemaphore--;
}

CONST_DATA struct ProcScr ProcScr_EfxHammarne[] = {
	PROC_NAME_DEBUG("efxHammarne"),
	PROC_REPEAT(EfxHammarne_Loop),
	PROC_END,
};


CONST_DATA struct ProcScr ProcScr_EfxHammarneBG[] = {
	PROC_NAME_DEBUG("efxHammarneBG"),
	PROC_REPEAT(EfxHammarneBG_Loop),
	PROC_END,
};


CONST_DATA u16 *TsaArray_EfxHammarneBG[] = {
	Tsa_EfxHammarneBG_081B4294,
	Tsa_EfxHammarneBG_081B4340,
	Tsa_EfxHammarneBG_081B43F0,
	Tsa_EfxHammarneBG_081B44B0,
	Tsa_EfxHammarneBG_081B4578,
	Tsa_EfxHammarneBG_081B4650,
	Tsa_EfxHammarneBG_081B472C,
	Tsa_EfxHammarneBG_081B4814,
	Tsa_EfxHammarneBG_081B4904,
	Tsa_EfxHammarneBG_081B4A04,
	Tsa_EfxHammarneBG_081B4B10,
	Tsa_EfxHammarneBG_081B4C30,
	Tsa_EfxHammarneBG_081B4D60,
};


CONST_DATA u16 *ImgArray_EfxHammarneBG[] = {
	Img_EfxRestBG_081AFC70,
	Img_EfxRestBG_081AFC70,
	Img_EfxRestBG_081AFC70,
	Img_EfxRestBG_081AFC70,
	Img_EfxRestBG_081AFC70,
	Img_EfxRestBG_081AFC70,
	Img_EfxRestBG_081B029C,
	Img_EfxRestBG_081B029C,
	Img_EfxRestBG_081B029C,
	Img_EfxRestBG_081B0994,
	Img_EfxRestBG_081B0994,
	Img_EfxRestBG_081B0FB4,
	Img_EfxRestBG_081B0FB4,
};


CONST_DATA struct ProcScr ProcScr_EfxHammarneOBJ[] = {
	PROC_NAME_DEBUG("efxHammarneOBJ"),
	PROC_ONEND(EfxHammarneOBJ_OnEnd),
	PROC_SLEEP(80),
	PROC_END,
};


void StartSpellAnimHammerne(struct Anim *anim)
{
	struct ProcEfx *proc;

	SpellFx_Begin();
	NewEfxSpellCast();
	SpellFx_ClearBG1Position();

	proc = SpawnProc(ProcScr_EfxHammarne, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->hitted = CheckRoundMiss(GetAnimRoundTypeAnotherSide(anim));
}

void EfxHammarne_Loop(struct ProcEfx *proc)
{
	struct Anim *target;
	int duration;

	target = GetAnimAnotherSide(proc->anim);
	duration = EfxGetCamMovDuration();

	proc->timer++;

	if (proc->timer == 1)
		NewEfxFarAttackWithDistance(proc->anim, -1);

	if (proc->timer == duration + 1) {
		NewEfxHammarneBG(target);
		NewEfxALPHA(target, 40, 30, 16, 8, 0);
		NewEfxALPHA(target, 71, 30, 8, 16, 0);
		NewEfxALPHA(target, 102, 30, 16, 8, 0);
		NewEfxALPHA(target, 133, 30, 8, 16, 0);
		NewEfxALPHA(target, 164, 60, 16, 0, 0);
		PlaySFX(SONG_103, 0x100, target->xPosition, 1);
	} else if (proc->timer == duration + 80) {
		NewEfxHammarneOBJ(target);
	} else if (proc->timer == duration + 164) {
		NewEfxFlashUnit(target, 1, 5, 0);
	} else if (proc->timer == duration + 200) {
		target->flags3 |= ANIM_BIT3_C02_BLOCK_END | ANIM_BIT3_C01_BLOCK_END_INBATTLE;
		StartBattleAnimStatusChgHitEffects(target, proc->hitted);
	} else if (proc->timer == duration + 300) {
		target->flags3 |= ANIM_BIT3_NEXT_ROUND_START;
		SpellFx_Finish();
		EndEfxSpellCastAsync();
		Proc_Break(proc);
	}
}

void NewEfxHammarneBG(struct Anim *anim)
{
	struct ProcEfxBG *proc;

	static const u16 frames[] = {
		0x0, 4,
		0x1, 4,
		0x2, 4,
		0x3, 4,
		0x4, 3,
		0x5, 3,
		0x6, 3,
		0x7, 3,
		0x8, 3,
		0x9, 2,
		0xA, 2,
		0xB, 2,
		0xC, 250,
		-1,
	};

	gEfxBgSemaphore++;
	proc = SpawnProc(ProcScr_EfxHammarneBG, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->frame = 0;
	proc->frame_config = frames;
	proc->tsal = (u16 **)TsaArray_EfxHammarneBG;
	proc->tsar = (u16 **)TsaArray_EfxHammarneBG;
	proc->img = (u16 **)ImgArray_EfxHammarneBG;
	SpellFx_RegisterBgPal(Pal_EfxHammarneBG, 0x20);
	SpellFx_SetSomeColorEffect();
}

void EfxHammarneBG_Loop(struct ProcEfxBG *proc)
{
	int ret = EfxAdvanceFrameLut((i16 *)&proc->timer, (i16 *)&proc->frame, proc->frame_config);

	if (ret >= 0) {
		u16 **tsaL = proc->tsal;
		u16 **tsaR = proc->tsar;
		u16 **img = proc->img;

		SpellFx_WriteBgMap(proc->anim, tsaL[ret], tsaR[ret]);
		SpellFx_RegisterBgGfx(img[ret], 0x80 << 6);
		return;
	}

	if (ret != -1)
		return;

	SpellFx_ClearBG1();
	gEfxBgSemaphore--;
	SpellFx_ClearColorEffects();
	Proc_Break(proc);
}

void NewEfxHammarneOBJ(struct Anim *anim)
{
	struct ProcEfxOBJ *proc;

	gEfxBgSemaphore++;
	proc = SpawnProc(ProcScr_EfxHammarneOBJ, PROC_TREE_3);
	proc->anim = anim;
	proc->anim2 = EfxCreateFrontAnim(anim, AnimScr_EfxHammarneOBJ, AnimScr_EfxHammarneOBJ,
					 AnimScr_EfxHammarneOBJ, AnimScr_EfxHammarneOBJ);
	SpellFx_RegisterObjPal(Pal_EfxHammarneOBJ, 0x20);
	SpellFx_RegisterObjGfx(Img_EfxHammarneOBJ, 0x80 << 4);
}

void EfxHammarneOBJ_OnEnd(void)
{
	gEfxBgSemaphore--;
}

CONST_DATA struct ProcScr ProcScr_EfxBerserk[] = {
	PROC_NAME_DEBUG("efxBerserk"),
	PROC_REPEAT(EfxBerserk_Loop),
	PROC_END,
};


CONST_DATA struct ProcScr ProcScr_EfxBerserkBG[] = {
	PROC_NAME_DEBUG("efxBerserkBG"),
	PROC_REPEAT(EfxBerserkBG_Loop),
	PROC_END,
};


CONST_DATA struct ProcScr ProcScr_EfxBerserkCLONE[] = {
	PROC_NAME_DEBUG("efxBerserkCLONE"),
	PROC_ONEND(EfxBerserkCLONE_OnEnd),
	PROC_REPEAT(EfxBerserkCLONE_Loop),
	PROC_END,
};


CONST_DATA struct ProcScr ProcScr_EfxBerserkOBJ[] = {
	PROC_NAME_DEBUG("efxBerserkOBJ"),
	PROC_ONEND(EfxBerserkOBJ_OnEnd),
	PROC_REPEAT(EfxBerserkOBJ_Loop1),
	PROC_SLEEP(7),
	PROC_REPEAT(EfxBerserkOBJ_Loop2),
	PROC_SLEEP(3),
	PROC_REPEAT(EfxBerserkOBJ_Loop3),
	PROC_SLEEP(7),
	PROC_REPEAT(EfxBerserkOBJ_Loop4),
	PROC_SLEEP(3),
	PROC_REPEAT(EfxBerserkOBJ_Loop5),
	PROC_SLEEP(7),
	PROC_REPEAT(EfxBerserkOBJ_Loop6),
	PROC_SLEEP(3),
	PROC_REPEAT(EfxBerserkOBJ_Loop7),
	PROC_SLEEP(7),
	PROC_REPEAT(EfxBerserkOBJ_Loop8),
	PROC_SLEEP(3),
	PROC_REPEAT(EfxBerserkOBJ_Loop9),
	PROC_SLEEP(7),
	PROC_REPEAT(EfxBerserkOBJ_Loop10),
	PROC_SLEEP(17),
	PROC_END,
};


void StartSpellAnimBerserk(struct Anim *anim)
{
	struct ProcEfx *proc;

	SpellFx_Begin();
	NewEfxSpellCast();
	SpellFx_ClearBG1Position();

	proc = SpawnProc(ProcScr_EfxBerserk, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->hitted = CheckRoundMiss(GetAnimRoundTypeAnotherSide(anim));
}

void EfxBerserk_Loop(struct ProcEfx *proc)
{
	struct Anim *target;
	int duration;

	target = GetAnimAnotherSide(proc->anim);
	duration = EfxGetCamMovDuration();

	proc->timer++;

	if (proc->timer == 1)
		NewEfxFarAttackWithDistance(proc->anim, -1);

	if (proc->timer == duration + 1) {
		NewEfxBerserkOBJ(target);
		NewEfxBerserkBG(target, 0x4a);
		NewEfxBerserkCLONE(target, 0x4a);
		NewEfxRestRST(target, 0x4a, 10, 0x100, 1);
		NewEfxRestWINH_(target, 0x4a, EfxRestWINH_DefaultHblank);
		PlaySFX(SONG_F9, 0x100, target->xPosition, 1);
	} else if (proc->timer == duration + 0x4a) {
		NewEfxFlashBgWhite(target, 5);
		target->flags3 |= ANIM_BIT3_C02_BLOCK_END | ANIM_BIT3_C01_BLOCK_END_INBATTLE;
		StartBattleAnimStatusChgHitEffects(target, proc->hitted);

		if (!proc->hitted && GetUnitEfxDebuff(target) == 0)
			SetUnitEfxDebuff(target, 4);
	} else if (proc->timer == duration + 0x5a) {
		target->flags3 |= ANIM_BIT3_NEXT_ROUND_START;
		SpellFx_Finish();
		EndEfxSpellCastAsync();
		Proc_Break(proc);
	}
}

void NewEfxBerserkBG(struct Anim *anim, int duration)
{
	struct ProcEfxBG *proc;

	gEfxBgSemaphore++;
	proc = SpawnProc(ProcScr_EfxBerserkBG, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->terminator = duration;
	SpellFx_RegisterBgPal(Pal_EfxBerserkBG, 0x20);
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
	anim->oam2 &= 0xF3FF;
	anim->oam2 |= 0x0400;
}

void EfxBerserkBG_Loop(struct ProcEfxBG *proc)
{
	struct Anim *anim = proc->anim;

	gDispIo.bg_off[BG_1].y--;

	if (++proc->timer == proc->terminator) {
		SpellFx_ClearBG1();
		SpellFx_ClearColorEffects();
		anim->oam01 &= ~0x0800;
		anim->oam2 &= 0xF3FF;
		anim->oam2 |= 0x0800;
		gEfxBgSemaphore--;
		Proc_Break(proc);
	}
}

void NewEfxBerserkCLONE(struct Anim *anim, int duration)
{
	struct ProcEfxBG *proc;

	gEfxBgSemaphore++;
	proc = SpawnProc(ProcScr_EfxBerserkCLONE, PROC_TREE_4);
	proc->anim = anim;
	proc->timer = 0;
	proc->terminator = duration;
}

void EfxBerserkCLONE_Loop(struct ProcEfxBG *proc)
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

void EfxBerserkCLONE_OnEnd(void)
{
	gEfxBgSemaphore--;
}

void NewEfxBerserkOBJ(struct Anim *anim)
{
	struct ProcEfxOBJ *proc;
	struct BaSprite *anim2;
	struct Anim *arg;
	const AnimScr *scr;
	u16 oam2;

	gEfxBgSemaphore++;
	proc = SpawnProc(ProcScr_EfxBerserkOBJ, PROC_TREE_3);
	proc->anim = anim;
	GetAnimAnotherSide(anim);
	scr = AnimScr_Common;
	arg = proc->anim;
	anim2 = EfxCreateFrontAnim(arg, scr, scr, scr, scr);
	proc->anim2 = anim2;
	oam2 = anim2->oam2 & 0xF3FF;
	oam2 |= 0x0400;
	anim2->oam2 = oam2;
}

void EfxBerserkOBJ_OnEnd(struct ProcEfxOBJ *proc)
{
	gEfxBgSemaphore--;
	BasRemove(proc->anim2);
}

void EfxBerserkOBJ_Loop1(struct ProcEfxOBJ *proc)
{
	struct BaSprite *anim2 = proc->anim2;

	anim2->script = AnimScr_EfxBerserk1;
	anim2->scrCur = AnimScr_EfxBerserk1;
	anim2->timer = 0;
	SpellFx_RegisterObjPal(Pal_EfxBerserk, 0x20);
	SpellFx_RegisterObjGfx(Img_EfxBerserk1, 0x80 << 5);
	Proc_Break(proc);
}

void EfxBerserkOBJ_Loop3(struct ProcEfxOBJ *proc)
{
	struct BaSprite *anim2 = proc->anim2;

	anim2->script = AnimScr_EfxBerserk2;
	anim2->scrCur = AnimScr_EfxBerserk2;
	anim2->timer = 0;
	SpellFx_RegisterObjPal(Pal_EfxBerserk, 0x20);
	SpellFx_RegisterObjGfx(Img_EfxBerserk1, 0x80 << 5);
	Proc_Break(proc);
}

void EfxBerserkOBJ_Loop5(struct ProcEfxOBJ *proc)
{
	struct BaSprite *anim2 = proc->anim2;

	anim2->script = AnimScr_EfxBerserk3;
	anim2->scrCur = AnimScr_EfxBerserk3;
	anim2->timer = 0;
	SpellFx_RegisterObjPal(Pal_EfxBerserk, 0x20);
	SpellFx_RegisterObjGfx(Img_EfxBerserk1, 0x80 << 5);
	Proc_Break(proc);
}

void EfxBerserkOBJ_Loop7(struct ProcEfxOBJ *proc)
{
	struct BaSprite *anim2 = proc->anim2;

	anim2->script = AnimScr_EfxBerserk4;
	anim2->scrCur = AnimScr_EfxBerserk4;
	anim2->timer = 0;
	SpellFx_RegisterObjPal(Pal_EfxBerserk, 0x20);
	SpellFx_RegisterObjGfx(Img_EfxBerserk1, 0x80 << 5);
	Proc_Break(proc);
}

void EfxBerserkOBJ_Loop9(struct ProcEfxOBJ *proc)
{
	struct BaSprite *anim2 = proc->anim2;

	anim2->script = AnimScr_EfxBerserk5;
	anim2->scrCur = AnimScr_EfxBerserk5;
	anim2->timer = 0;
	SpellFx_RegisterObjPal(Pal_EfxBerserk, 0x20);
	SpellFx_RegisterObjGfx(Img_EfxBerserk1, 0x80 << 5);
	Proc_Break(proc);
}

void EfxBerserkOBJ_Loop2(struct ProcEfxOBJ *proc)
{
	struct BaSprite *anim2 = proc->anim2;

	anim2->script = AnimScr_EfxBerserk6;
	anim2->scrCur = AnimScr_EfxBerserk6;
	anim2->timer = 0;
	SpellFx_RegisterObjPal(Pal_EfxBerserk, 0x20);
	SpellFx_RegisterObjGfx(Img_EfxBerserk2, 0x80 << 5);
	Proc_Break(proc);
}

void EfxBerserkOBJ_Loop4(struct ProcEfxOBJ *proc)
{
	struct BaSprite *anim2 = proc->anim2;

	anim2->script = AnimScr_EfxBerserk7;
	anim2->scrCur = AnimScr_EfxBerserk7;
	anim2->timer = 0;
	SpellFx_RegisterObjPal(Pal_EfxBerserk, 0x20);
	SpellFx_RegisterObjGfx(Img_EfxBerserk2, 0x80 << 5);
	Proc_Break(proc);
}

void EfxBerserkOBJ_Loop6(struct ProcEfxOBJ *proc)
{
	struct BaSprite *anim2 = proc->anim2;

	anim2->script = AnimScr_EfxBerserk8;
	anim2->scrCur = AnimScr_EfxBerserk8;
	anim2->timer = 0;
	SpellFx_RegisterObjPal(Pal_EfxBerserk, 0x20);
	SpellFx_RegisterObjGfx(Img_EfxBerserk2, 0x80 << 5);
	Proc_Break(proc);
}

void EfxBerserkOBJ_Loop8(struct ProcEfxOBJ *proc)
{
	struct BaSprite *anim2 = proc->anim2;

	anim2->script = AnimScr_EfxBerserk9;
	anim2->scrCur = AnimScr_EfxBerserk9;
	anim2->timer = 0;
	SpellFx_RegisterObjPal(Pal_EfxBerserk, 0x20);
	SpellFx_RegisterObjGfx(Img_EfxBerserk2, 0x80 << 5);
	Proc_Break(proc);
}

void EfxBerserkOBJ_Loop10(struct ProcEfxOBJ *proc)
{
	struct BaSprite *anim2 = proc->anim2;

	anim2->script = AnimScr_EfxBerserk10;
	anim2->scrCur = AnimScr_EfxBerserk10;
	anim2->timer = 0;
	SpellFx_RegisterObjPal(Pal_EfxBerserk, 0x20);
	SpellFx_RegisterObjGfx(Img_EfxBerserk2, 0x80 << 5);
	Proc_Break(proc);
}

CONST_DATA struct ProcScr ProcScr_EfxMshield[] = {
	PROC_NAME_DEBUG("efxMshield"),
	PROC_REPEAT(EfxMshield_Loop),
	PROC_END,
};


CONST_DATA struct ProcScr ProcScr_EfxMshieldBG[] = {
	PROC_NAME_DEBUG("efxMshieldBG"),
	PROC_REPEAT(EfxMshieldBG_Loop),
	PROC_END,
};


CONST_DATA u16 *TsaArray_EfxMshieldBG[] = {
	Tsa_EfxMshieldBG_081B8974,
	Tsa_EfxMshieldBG_081B8A2C,
	Tsa_EfxMshieldBG_081B8AF0,
	Tsa_EfxMshieldBG_081B8BE0,
	Tsa_EfxMshieldBG_081B8D10,
};


CONST_DATA struct ProcScr ProcScr_EfxMshieldOBJ[] = {
	PROC_NAME_DEBUG("efxMshieldOBJ"),
	PROC_ONEND(EfxMshieldOBJ_OnEnd),
	PROC_SLEEP(220),
	PROC_END,
};


CONST_DATA struct ProcScr ProcScr_EfxMshieldOBJ2[] = {
	PROC_NAME_DEBUG("efxMshieldOBJ2"),
	PROC_ONEND(EfxMshieldOBJ_OnEnd),
	PROC_SLEEP(110),
	PROC_END,
};

void StartSpellAnimBarrier(struct Anim *anim)
{
	struct ProcEfx *proc;

	SpellFx_Begin();
	NewEfxSpellCast();
	SpellFx_ClearBG1Position();

	proc = SpawnProc(ProcScr_EfxMshield, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->hitted = CheckRoundMiss(GetAnimRoundTypeAnotherSide(anim));
}

void EfxMshield_Loop(struct ProcEfx *proc)
{
	struct Anim *target;
	int duration;

	target = GetAnimAnotherSide(proc->anim);
	duration = EfxGetCamMovDuration();

	proc->timer++;

	if (proc->timer == 1)
		NewEfxFarAttackWithDistance(proc->anim, -1);

	if (proc->timer == duration + 1) {
		NewEfxMshieldBG(proc->anim);
		NewEfxMshieldOBJ(target);
		NewEfxMshieldOBJ2(target);
		PlaySFX(SONG_102, 0x100, target->xPosition, 1);
	} else if (proc->timer == duration + 0x28) {
		NewEfxMshieldOBJ2(target);
	} else if (proc->timer == duration + 0x50) {
		NewEfxMshieldOBJ2(target);
	} else if (proc->timer == duration + 0xb0) {
		NewEfxFlashUnit(target, 1, 5, 0);
	} else if (proc->timer == duration + 0xe1) {
		target->flags3 |= ANIM_BIT3_C02_BLOCK_END | ANIM_BIT3_C01_BLOCK_END_INBATTLE;
		StartBattleAnimStatusChgHitEffects(target, proc->hitted);
	} else if (proc->timer == duration + 0xe6) {
		target->flags3 |= ANIM_BIT3_NEXT_ROUND_START;
		SpellFx_Finish();
		EndEfxSpellCastAsync();
		Proc_Break(proc);
	}
}

void NewEfxMshieldBG(struct Anim *anim)
{
	struct ProcEfxBG *proc;

	static const u16 frames[] = {
		0x0, 2,
		0x1, 2,
		0x2, 2,
		0x3, 3,
		0x4, 5,
		0x3, 3,
		0x4, 5,
		0x3, 3,
		0x4, 5,
		0x3, 3,
		0x4, 5,
		0x3, 3,
		0x4, 5,
		0x3, 3,
		0x4, 5,
		0x3, 3,
		0x4, 5,
		0x3, 3,
		0x4, 5,
		0x3, 3,
		0x4, 5,
		0x3, 3,
		0x4, 5,
		0x3, 3,
		0x4, 5,
		0x3, 3,
		0x4, 5,
		0x3, 3,
		0x4, 5,
		0x3, 3,
		0x4, 5,
		0x3, 3,
		0x4, 5,
		0x3, 3,
		0x4, 5,
		0x3, 3,
		0x4, 5,
		0x3, 3,
		0x4, 5,
		0x3, 3,
		0x4, 5,
		0x3, 3,
		0x4, 5,
		0x3, 3,
		0x4, 5,
		0x3, 3,
		0x4, 5,
		0x2, 3,
		0x1, 2,
		0x0, 2,
		-1,
		0,
	};

	gEfxBgSemaphore++;
	proc = SpawnProc(ProcScr_EfxMshieldBG, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->frame = 0;
	proc->frame_config = frames;
	proc->tsal = (u16 **)TsaArray_EfxMshieldBG;
	proc->tsar = (u16 **)TsaArray_EfxMshieldBG;
	SpellFx_RegisterBgPal(Pal_EfxMshieldBG, 0x20);
	SpellFx_RegisterBgGfx(Img_EfxMshieldBG, 0x2000);
	SpellFx_SetSomeColorEffect();
}

void EfxMshieldBG_Loop(struct ProcEfxBG *proc)
{
	int ret = EfxAdvanceFrameLut((i16 *)&proc->timer, (i16 *)&proc->frame, proc->frame_config);

	if (ret >= 0) {
		u16 **tsaL = proc->tsal;
		u16 **tsaR = proc->tsar;

		SpellFx_WriteBgMap(proc->anim, tsaL[ret], tsaR[ret]);
		return;
	}

	if (ret != -1)
		return;

	SpellFx_ClearBG1();
	gEfxBgSemaphore--;
	SpellFx_ClearColorEffects();
	Proc_Break(proc);
}

void NewEfxMshieldOBJ(struct Anim *anim)
{
	struct ProcEfxOBJ *proc;
	struct BaSprite *anim2;
	const AnimScr *scr;

	gEfxBgSemaphore++;
	proc = SpawnProc(ProcScr_EfxMshieldOBJ, PROC_TREE_3);
	proc->anim = anim;
	scr = AnimScr_EfxMshieldOBJ;
	anim2 = EfxCreateFrontAnim(anim, scr, scr, scr, scr);
	proc->anim2 = anim2;
	SpellFx_RegisterObjPal(Pal_EfxMshieldOBJ, 0x20);
	SpellFx_RegisterObjGfx(Img_EfxHammarneOBJ, 0x80 << 4);
}

void NewEfxMshieldOBJ2(struct Anim *anim)
{
	struct ProcEfxOBJ *proc;
	struct BaSprite *anim2;
	const AnimScr *scr;

	gEfxBgSemaphore++;
	proc = SpawnProc(ProcScr_EfxMshieldOBJ2, PROC_TREE_3);
	proc->anim = anim;
	scr = AnimScr_EfxMshieldOBJ2;
	anim2 = EfxCreateFrontAnim(anim, scr, scr, scr, scr);
	proc->anim2 = anim2;
}

void EfxMshieldOBJ_OnEnd(struct ProcEfxOBJ *proc)
{
	BasRemove(proc->anim2);
	gEfxBgSemaphore--;
}
