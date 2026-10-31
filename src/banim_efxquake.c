#include "prelude.h"
#include "proc.h"
#include "hardware.h"
#include "oam.h"
#include "datamove.h"
#include "banim.h"
#include "banim_ekrbattle.h"
#include "banim_ekrdragon.h"

struct ProcScr CONST_DATA ProcScr_EfxQuakePure[] =
{
	PROC_19,
	PROC_REPEAT(EfxQuakePure_Loop),
	PROC_END,
};

const void * CONST_DATA EfxQuakePureVecs[] =
{
	gEfxQuakePureVec1, 0,
	gEfxQuakePureVec2, 0,
	gEfxQuakePureVec3, 0,
	gEfxQuakePureVec4, 0,
	gEfxQuakePureVec5, 0,
	gEfxQuakePureVec6, 0,
	gEfxQuakePureVec7, 0,
	gEfxQuakePureVec8, 0,
	gEfxQuakePureVec9, 0,
	gEfxQuakePureVec10, 0,
	gEfxQuakePureVec11, 0,
};

ProcPtr NewEfxQuakePure(int index, int kind)
{
	struct ProcEfxQuake * proc = SpawnProc(ProcScr_EfxQuakePure, PROC_TREE_3);

	proc->vec = (i16 *)EfxQuakePureVecs[index * 2];
	proc->quake_ui = (int)EfxQuakePureVecs[index * 2 + 1];

	proc->kind = kind;
	proc->timer = 0;

	return proc;
}

void EfxQuakePure_Loop(struct ProcEfxQuake * proc)
{
	const i16 * vec = proc->vec;

	if (vec[proc->timer * 2 + 0] != INT16_MAX)
	{
		SetEkrBg2QuakeVec(vec[proc->timer * 2 + 0], vec[proc->timer * 2 + 1]);
		proc->timer++;
	}
	else
	{
		switch (proc->kind) {
		case 0:
			proc->timer = 0;
			SetEkrBg2QuakeVec(vec[0], vec[1]);
			break;

		case 1:
			gEkrBg2QuakeVec.y = 0;
			gEkrBg2QuakeVec.x = 0;
			break;
		}
	}
}

struct ProcScr CONST_DATA ProcScr_EfxHitQuakePure[] =
{
	PROC_19,
	PROC_REPEAT(EfxHitQuakePure_Loop),
	PROC_END,
};

ProcPtr NewEfxHitQuakePure(void)
{
	return SpawnProc(ProcScr_EfxHitQuakePure, PROC_TREE_3);
}

void EfxHitQuakePure_Loop(struct ProcEfxQuake * proc)
{
	return;
}

struct ProcScr CONST_DATA ProcScr_EfxQuake[] =
{
	PROC_19,
	PROC_REPEAT(EfxQuake_Loop),
	PROC_END,
};

ProcPtr NewEfxQuake(int kind)
{
	struct ProcEfxQuake *proc;

	if (gEfxFarAttackExist == 1)
		return NULL;

	gEfxQuakeExist = 1;
	proc = SpawnProc(ProcScr_EfxQuake, PROC_TREE_3);

	proc->timer = 0;

	proc->anim_l = MAIN_ANIM_FRONT(POS_L);
	proc->anim_r = MAIN_ANIM_FRONT(POS_R);

	switch (kind) {
	case 0:
		proc->vec = gEfxQuakePureVec1;
		proc->quake_ui = 0;

		break;

	case 1:
		proc->vec = gEfxQuakePureVec2;
		proc->quake_ui = 0;

		break;

	case 2:
		proc->vec = gEfxQuakePureVec3;
		proc->quake_ui = 0;

		break;

	case 3:
		proc->vec = gEfxQuakePureVec4;
		proc->quake_ui = 0;

		break;

	case 4:
		proc->vec = gEfxQuakePureVec5;
		proc->quake_ui = 0;

		break;

	case 5:
		proc->vec = gEfxQuakePureVec6;
		proc->quake_ui = 1;

		break;

	case 6:
		proc->vec = gEfxQuakeVec_08111E14;
		proc->quake_ui = 1;

		break;

	default:
		proc->vec = gEfxQuakePureVec1;
		proc->quake_ui = 0;

		break;
	}

	proc->ix = 0;
	proc->iy = 0;

	return proc;
}

void EfxQuake_Loop(struct ProcEfxQuake * proc)
{
	int x1, y1, x2, y2;
	const i16 * vec = proc->vec;
	u32 time = (u16)proc->timer;

	if (vec[proc->timer * 2 + 0] == INT16_MAX)
	{
		x1 = gEkrXPosReal[POS_L] - gEkrBgPosition;
		y1 = gEkrYPosReal[POS_L];
		x2 = gEkrXPosReal[POS_R] - gEkrBgPosition;
		y2 = gEkrYPosReal[POS_R];

		SetEkrFrontAnimPostion(POS_L, x1, y1);
		SetEkrFrontAnimPostion(POS_R, x2, y2);

		SetBgOffset(2, 0, 0);

		if (GetEkrDragonStateType() != 0)
			SetBgOffset(3, proc->ix, proc->iy + 0x10);

		gEfxQuakeExist = 0;
		Proc_End(proc);
	}
	else
	{
		SetEkrBg2QuakeVec(vec[proc->timer * 2 + 0], vec[proc->timer * 2 + 1]);
		proc->timer = time + 1;
		SetBgOffset(2, gEkrBg2QuakeVec.x, gEkrBg2QuakeVec.y);

		if (GetEkrDragonStateType() != 0)
			SetBgOffset(3, proc->ix + gEkrBg2QuakeVec.x, proc->iy + gEkrBg2QuakeVec.y + 0x10);

		if (GetEkrDragonStateType() != 0)
		{
			x1 = (gEkrXPosReal[0] - gEkrBg2QuakeVec.x) - gEkrBgPosition;
			y1 = gEkrYPosReal[0] - gEkrBg2QuakeVec.y;
		}
		else
		{
			x1 = (gEkrXPosReal[0] + gEkrBg2QuakeVec.x) - gEkrBgPosition;
			y1 = gEkrYPosReal[0] - gEkrBg2QuakeVec.y;
		}

		x2 = (gEkrXPosReal[1] + gEkrBg2QuakeVec.x) - gEkrBgPosition;
		y2 = gEkrYPosReal[1] - gEkrBg2QuakeVec.y;

		switch (gEkrDistanceType) {
		case EKR_DISTANCE_CLOSE:
			SetEkrFrontAnimPostion(POS_L, x1, y1);
			SetEkrFrontAnimPostion(POS_R, x2, y2);
			break;

		case EKR_DISTANCE_FAR:
		case EKR_DISTANCE_FARFAR:
			if (GetAnimPosition(proc->anim_l) == POS_L)
				SetEkrFrontAnimPostion(POS_L, x1, y1);
			else
				SetEkrFrontAnimPostion(POS_R, x2, y2);

			break;
		}
	}
}

struct ProcScr CONST_DATA ProcScr_EfxHitQuake[] =
{
	PROC_19,
	PROC_REPEAT(EfxHitQuake_Loop),
	PROC_END,
};

void NewEfxHitQuake(struct Anim *anim1, struct Anim *anim2, int kind)
{
	i16 x;
	struct ProcEfxQuake *proc;
	struct Anim * anim;

	if (gEfxHitQuakeExist != 0)
		return;

	gEfxHitQuakeExist = 1;

	proc = SpawnProc(ProcScr_EfxHitQuake, PROC_TREE_3);

	proc->anim_l = anim1;
	proc->anim_r = anim2;
	proc->timer = 0;
	proc->quake_ui = 1;

	if (kind == 0)
		proc->vec = gEfxQuakePureVec1;
	else if (kind == 1)
		proc->vec = gEfxQuakePureVec2;
	else if (kind == 2)
		proc->vec = gEfxQuakePureVec3;
	else if (kind == 3)
		proc->vec = gEfxQuakePureVec4;
	else if (kind == 4)
		proc->vec = gEfxQuakeVec_08111F30;
	else if (kind == 5)
		proc->vec = gEfxQuakeVec_08111FC6;
	else
		proc->vec = gEfxQuakePureVec1;

	proc->unk_48 = 1;

	if (GetEkrDragonStateTypeIdunn() != 0) {
		proc->unk_64 = NULL;
		return;
	}

	if (GetBattleAnimArenaFlag() != 0) {
		proc->unk_64 = NULL;
		return;
	}

	if (gEkrDistanceType == EKR_DISTANCE_CLOSE) {
		proc->unk_64 = NULL;
		return;
	}

	x = gEkrBgPosition - gEkrXPosBase[GetAnimPosition(proc->anim_l)];

	if (GetAnimPosition(anim1) == POS_L) {
		proc->unk_36 = 64;
		proc->unk_3e = 104;
		anim = BasCreate(AnimScr_EkrTerrainfx_L_Far, 5);
	} else {
		proc->unk_36 = 176;
		proc->unk_3e = 104;
		anim = BasCreate(AnimScr_EkrTerrainfx_R_Far, 5);
	}

	anim->xPosition = proc->unk_36 - x;
	anim->yPosition = proc->unk_3e;

	if (gEfxTerrainLayerLow == 1)
		anim->oam2 = OAM2_CHR(0xC0) + OAM2_LAYER(1) + OAM2_PAL(3);
	else
		anim->oam2 = OAM2_CHR(0xC0) + OAM2_LAYER(3) + OAM2_PAL(3);

	proc->unk_64 = anim;

	RegisterDataMove(gpBanimTerrainfxBufs[GetAnimPosition(anim1)], (void *)0x06011800, 0x800);

	CpuFastCopy(gpBanimTerrainPalBufs[GetAnimPosition(anim1)], gPal + 0x130, PLTT_SIZE_4BPP);
	EnablePalSync();

	BanimCopyBgTM(gEkrDistanceType, GetAnimPosition(anim1));
	BanimSetBg2Position(gEkrBgPosition);
}

void EfxHitQuake_Loop(struct ProcEfxQuake *proc)
{
	int x1;
	int y1;
	int x2;
	int y2;

	const i16 *vec = proc->vec;

	if (vec[proc->timer * 2 + 0] == INT16_MAX) {
		switch (gEkrDistanceType) {
		case EKR_DISTANCE_CLOSE:
			SetBgOffset(BG_2, 0, 0);

			if (GetEkrDragonStateType() != 0) {
#if FE8
				SetBgOffset(BG_3, 0, 0);
#else
				SetBgOffset(BG_3, 0, 0x10);
#endif
			}

			break;

		case EKR_DISTANCE_FAR:
		case EKR_DISTANCE_FARFAR:
			if (GetEkrDragonStateType() != 0) {
#if FE8
				SetBgOffset(BG_3, 0, 0);
#else
				SetBgOffset(BG_3, 0, 0x10);
#endif
			}

			BanimSetBg2Position(gEkrBgPosition);
			break;
		}

		if (proc->unk_64 != NULL) {
			BasRemove(proc->unk_64);
			EkrTerrainfx_PutTiles(&gEkrTerrainfxDesc);
		}

		x1 = gEkrXPosReal[0] - gEkrBgPosition;
		y1 = gEkrYPosReal[0];
		x2 = gEkrXPosReal[1] - gEkrBgPosition;
		y2 = gEkrYPosReal[1];

		SetEkrFrontAnimPostion(0, x1, y1);
		SetEkrFrontAnimPostion(1, x2, y2);

		gEfxHitQuakeExist = 0;

		if (proc->quake_ui == 1) {
			if (GetEkrDragonStateType() != 0) {
#if FE8
				SetBgOffset(BG_3, 0, 0);
#else
				SetBgOffset(BG_3, 0, 0x10);
#endif
			}

			SetBgOffset(BG_0, gEkrBg0QuakeVec.x, gEkrBg0QuakeVec.y);
			EkrGauge_Setxy323A(-gEkrBg0QuakeVec.x, -gEkrBg0QuakeVec.y);
			EkrDispUP_SetPositionSync(-gEkrBg0QuakeVec.x, -gEkrBg0QuakeVec.y);
		}

		Proc_End(proc);
	} else {
		int x;
		int y;

		if ((proc->timer == 0) && (proc->unk_64 != NULL)) {
#if FE8
			FillBGRect(GetAnimPosition(proc->anim_l) * 15 + gBg2Tm + TM_OFFSET(16, 5), 0xf, 5, 0, 0);
#else
			FillBGRect(GetAnimPosition(proc->anim_l) * 15 + gBg2Tm + TM_OFFSET(0, 11), 0xF, 5, 0, 0);
#endif
		}

		gEkrBg2QuakeVec.x = x = vec[proc->timer * 2 + 0];
		gEkrBg2QuakeVec.y = y = vec[proc->timer * 2 + 1];
		// SetEkrBg2QuakeVec(vec[proc->timer * 2 + 0], vec[proc->timer * 2 + 1]);

		proc->timer++;

		if (proc->unk_64 != NULL) {
			s16 hm = gEkrBgPosition - gEkrXPosBase[GetAnimPosition(proc->anim_l)];

			struct Anim * anim = proc->unk_64;

			anim->xPosition = (proc->unk_36 + gEkrBg2QuakeVec.x) - hm;
			anim->yPosition = proc->unk_3e - gEkrBg2QuakeVec.y;
		} else
			SetBgOffset(BG_2, gEkrBg2QuakeVec.x, gEkrBg2QuakeVec.y);

		if (proc->quake_ui == 1) {
#if FE8
			if (GetEkrDragonStateType() != 0)
				SetBgOffset(BG_3, -x, y);
#endif

			SetBgOffset(BG_0, gEkrBg2QuakeVec.x + gEkrBg0QuakeVec.x, gEkrBg2QuakeVec.y + gEkrBg0QuakeVec.y);
			EkrGauge_Setxy323A(-(gEkrBg2QuakeVec.x + gEkrBg0QuakeVec.x), -(gEkrBg2QuakeVec.y + gEkrBg0QuakeVec.y));
			EkrDispUP_SetPositionSync(
				-(gEkrBg2QuakeVec.x + gEkrBg0QuakeVec.x), -(gEkrBg2QuakeVec.y + gEkrBg0QuakeVec.y));
		}

		if (GetEkrDragonStateType() != 0) {
#if FE8
			SetBgOffset(BG_3, gEkrBg2QuakeVec.x, gEkrBg2QuakeVec.y);
#else
			SetBgOffset(BG_3, gEkrBg2QuakeVec.x, gEkrBg2QuakeVec.y + 0x10);
#endif
		}

		if (GetEkrDragonStateType() != 0) {
			x1 = (gEkrXPosReal[0] - gEkrBg2QuakeVec.x) - gEkrBgPosition;
			y1 = gEkrYPosReal[0] - gEkrBg2QuakeVec.y;
		} else {
			x1 = (gEkrXPosReal[0] + gEkrBg2QuakeVec.x) - gEkrBgPosition;
			y1 = gEkrYPosReal[0] - gEkrBg2QuakeVec.y;
		}

		x2 = (gEkrXPosReal[1] + gEkrBg2QuakeVec.x) - gEkrBgPosition;
		y2 = gEkrYPosReal[1] - gEkrBg2QuakeVec.y;

		switch (gEkrDistanceType) {
		case EKR_DISTANCE_CLOSE:
			SetEkrFrontAnimPostion(0, x1, y1);
			SetEkrFrontAnimPostion(1, x2, y2);
			break;

		case EKR_DISTANCE_FAR:
		case EKR_DISTANCE_FARFAR:
			if (GetAnimPosition(proc->anim_l) == 0)
				SetEkrFrontAnimPostion(0, x1, y1);
			else
				SetEkrFrontAnimPostion(1, x2, y2);
			break;
		}
	}
}

