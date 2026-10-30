#include "prelude.h"
#include "proc.h"
#include "unit.h"
#include "item.h"
#include "hardware.h"
#include "oam.h"
#include "datamove.h"
#include "util.h"
#include "banim.h"
#include "banim_ekrdragon.h"

#include "constants/jids.h"
#include "constants/iids.h"
#include "constants/songs.h"

EWRAM_OVERLAY(banim) int gEkrTriangleInvalid = 0;

bool CheckEkrTriangleInvalid(void)
{
	if (gEkrTriangleInvalid == true)
		return true;

	return false;
}

void DebugEkrTriangleMsg(void) {}

struct ProcScr CONST_DATA ProcScr_EkrTriangle[] = {
	PROC_19,
	PROC_REPEAT(EkrTriangle_Loop),
	PROC_END,
};

void NewEkrTriangle(struct Anim * anim)
{
	struct ProcEfx *proc;

	proc = SpawnProc(ProcScr_EkrTriangle, PROC_TREE_3);
	proc->anim = anim;
	gEkrTriangleInvalid = false;
}

void EkrTriangle_Loop(struct ProcEfx *proc)
{
	int jid, jid1, jid2, wpn_type;
	int etype2;
	int ewtype1;
	int ewtype2;
	int etype1;
	struct Unit *unit;
	u16 wpn;

	etype1 = 0;
	etype2 = 0;
	ewtype1 = 0;
	ewtype2 = 0;

	jid = (GetAnimPosition(proc->anim) == POS_L)
		? gpEkrBattleUnitLeft->unit.jinfo->id
		: gpEkrBattleUnitRight->unit.jinfo->id;

	switch (jid) {
	case JID_GENERAL_F:
	case JID_GENERAL:
	case JID_ARMOR_F:
	case JID_ARMOR:

		unit = gpEkrTriangleUnits[POS_L];
		jid1 = unit->jinfo->id;

		if (jid1 == JID_ARMOR)
			etype1 = EKR_TRI_JTYPE_DEFAULT;
		if (jid1 == JID_ARMOR_F)
			etype1 = EKR_TRI_JTYPE_DEFAULT;
		if (jid1 == JID_GENERAL)
			etype1 = EKR_TRI_JTYPE_PROMOTED;
		if (jid1 == JID_GENERAL_F)
			etype1 = EKR_TRI_JTYPE_PROMOTED;

		wpn = GetUnitEquippedWeapon(unit);
		if (wpn == 0)
			wpn_type = ITEM_KIND_LANCE;
		else
			wpn_type = GetItemKind(wpn);

		switch (wpn_type) {
		case ITEM_KIND_LANCE:
			ewtype1 = EKR_TRI_WTYPE_DEFAULT;
			break;

		case ITEM_KIND_AXE:
			ewtype1 = (GetItemIid(wpn) == IID_HANDAXE)
					? EKR_TRI_WTYPE_ALTERNATIVE2
					: EKR_TRI_WTYPE_ALTERNATIVE;
			break;

		default:
			break;
		}

		unit = gpEkrTriangleUnits[POS_R];
		jid2 = unit->jinfo->id;

		if (jid2 == JID_ARMOR)
			etype2 = EKR_TRI_JTYPE_DEFAULT;
		if (jid2 == JID_ARMOR_F)
			etype2 = EKR_TRI_JTYPE_DEFAULT;
		if (jid2 == JID_GENERAL)
			etype2 = EKR_TRI_JTYPE_PROMOTED;
		if (jid2 == JID_GENERAL_F)
			etype2 = EKR_TRI_JTYPE_PROMOTED;

		wpn = GetUnitEquippedWeapon(unit);
		if (wpn == 0)
			wpn_type = ITEM_KIND_LANCE;
		else
			wpn_type = GetItemKind(wpn);

		switch (wpn_type) {
		case ITEM_KIND_LANCE:
			ewtype2 = EKR_TRI_WTYPE_DEFAULT;
			break;

		case ITEM_KIND_AXE:
			ewtype2 = (GetItemIid(wpn) == IID_HANDAXE)
					? EKR_TRI_WTYPE_ALTERNATIVE2
					: EKR_TRI_WTYPE_ALTERNATIVE;
			break;

		default:
			break;
		}

		NewEkrTriArmorKnight(proc->anim, etype1, etype2, ewtype1, ewtype2);

		if (GetItemIid(gpEkrBattleUnitRight->weapon_before) == IID_HANDAXE)
			gEkrTriangleInvalid = false;
		else
			gEkrTriangleInvalid = true;

		break;

	case JID_PEGASUSKNIGHT:
	case JID_FALCONKNIGHT:
	default:
		unit = gpEkrTriangleUnits[POS_L];
		jid1 = unit->jinfo->id;

		if (jid1 == JID_PEGASUSKNIGHT)
			etype1 = EKR_TRI_JTYPE_DEFAULT;
		if (jid1 == JID_FALCONKNIGHT)
			etype1 = EKR_TRI_JTYPE_PROMOTED;

		wpn = GetUnitEquippedWeapon(unit);
		if (wpn == 0)
			wpn_type = ITEM_KIND_LANCE;
		else
			wpn_type = GetItemKind(wpn);

		switch (wpn_type) {
		case ITEM_KIND_LANCE:
			ewtype1 = EKR_TRI_WTYPE_DEFAULT;
			break;

		case ITEM_KIND_SWORD:
			ewtype1 = EKR_TRI_WTYPE_ALTERNATIVE;
			break;

		default:
			break;
		}

		unit = gpEkrTriangleUnits[POS_R];
		jid2 = unit->jinfo->id;

		if (jid2 == JID_PEGASUSKNIGHT)
			etype2 = EKR_TRI_JTYPE_DEFAULT;
		if (jid2 == JID_FALCONKNIGHT)
			etype2 = EKR_TRI_JTYPE_PROMOTED;

		wpn = GetUnitEquippedWeapon(unit);
		if (wpn == 0)
			wpn_type = ITEM_KIND_LANCE;
		else
			wpn_type = GetItemKind(wpn);

		switch (wpn_type) {
		case ITEM_KIND_LANCE:
			ewtype2 = EKR_TRI_WTYPE_DEFAULT;
			break;

		case ITEM_KIND_SWORD:
			ewtype2 = EKR_TRI_WTYPE_ALTERNATIVE;
			break;

		default:
			break;
		}

		NewEkrTriPegasusKnight(proc->anim, etype1, etype2, ewtype1, ewtype2);

		if (jid == JID_PEGASUSKNIGHT)
			gEkrTriangleInvalid = false;
		else
			gEkrTriangleInvalid = true;

		break;
	}

	Proc_Break(proc);
}

struct ProcScr CONST_DATA ProcScr_EkrTriPegasusKnight[] = {
	PROC_19,
	PROC_REPEAT(EkrTriPegasusKnight_Loop),
	PROC_END,
};

ProcPtr NewEkrTriPegasusKnight(struct Anim *anim, u32 ekr1, u32 ekr2, u32 banim1, u32 ewtype2)
{
	struct ProcEkrTriClass *proc;
	proc = SpawnProc(ProcScr_EkrTriPegasusKnight, PROC_TREE_3);

	proc->anim = anim;
	proc->timer = 0;

	proc->etype1 = ekr1;
	proc->etype2 = ekr2;
	proc->ewtype1 = banim1;
	proc->ewtype2 = ewtype2;
	return proc;
}

void EkrTriPegasusKnight_Loop(struct ProcEkrTriClass *proc)
{
	struct Anim *anim1 = GetAnimAnotherSide(proc->anim);

	if (++proc->timer == 0xA)
		NewEkrTriPegasusKnightOBJ(proc->anim, POS_L, proc->etype1, proc->ewtype1);

	if (proc->timer == 0x1C)
		NewEfxFlashBgWhite(anim1, 0x6);

	if (proc->timer == 0x22) {
		NewEkrTriPegasusKnightBG(anim1, POS_L, proc->etype1, proc->ewtype1);
		NewEkrTriPegasusKnightOBJ(proc->anim, POS_R, proc->etype2, proc->ewtype2);
		PlaySFX(SONG_268, 0x100, proc->anim->xPosition, 0x1);
	}

	if (proc->timer == 0x33)
		NewEfxFlashBgWhite(anim1, 0x6);

	if (proc->timer == 0x39) {
		NewEkrTriPegasusKnightBG(anim1, POS_R, proc->etype2, proc->ewtype2);
		PlaySFX(SONG_268, 0x100, proc->anim->xPosition, 0x1);
	}

	if (proc->timer == 0x43) {
		gEkrTriangleInvalid = true;
		Proc_Break(proc);
	}
}

struct ProcScr CONST_DATA ProcScr_EkrTriPegasusKnightBG[] = {
	PROC_19,
	PROC_REPEAT(EfxTriPegasusKnightBG_Loop),
	PROC_END,
};

CONST_DATA u16 *TsaArray_EkrTriPegagusBG[] = {
	Tsa_EkrTriPegagusBG1,
	Tsa_EkrTriPegagusBG2,
	Tsa_EkrTriPegagusBG3,
	Tsa_EkrTriPegagusBG4,
	Tsa_EkrTriPegagusBG5,
	Tsa_EkrTriPegagusBG6,
};

void NewEkrTriPegasusKnightBG(struct Anim *anim, u32 pos, u32 etype, u32 ewtype)
{
	const u16 *pal;
	const u16 *img;
	struct ProcEfxBG *proc;

	static const s16 frame_l[0x7] = {
		0x03, 0x02,
		0x04, 0x02,
		0x05, 0x01,
		-1
	};

	static const s16 frame_r[0x7] = {
		0x00, 0x02,
		0x01, 0x02,
		0x02, 0x01,
		-1
	};

	proc = SpawnProc(ProcScr_EkrTriPegasusKnightBG, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->frame = 0;

	if (pos == POS_L) {
		pal = gpBanimTriAtkPalettes[POS_L];
		proc->frame_config = frame_l;
	} else {
		pal = gpBanimTriAtkPalettes[POS_R];
		proc->frame_config = frame_r;
	}

	proc->tsal = TsaArray_EkrTriPegagusBG;
	proc->tsar = TsaArray_EkrTriPegagusBG;

	LZ77UnCompWram(pal, gSpellAnimBgfx);
	SpellFx_RegisterBgPal((u16 *)gSpellAnimBgfx, 0x20);

	img = Img_TriPegasusKnightBG;
	if (etype != EKR_TRI_JTYPE_DEFAULT) {
		img = Img_TriFalconKnightSwordBG;

		if (ewtype == EKR_TRI_WTYPE_DEFAULT)
			img = Img_TriFalconKnightLanceBG;
	}

	SpellFx_RegisterBgGfx(img, 0x2000);
}

void EfxTriPegasusKnightBG_Loop(struct ProcEfxBG *proc)
{
	int ret = EfxAdvanceFrameLut(&proc->timer, (s16 *)&proc->frame, proc->frame_config);

	if (ret >= 0) {
		u16 **buf1 = proc->tsal;
		u16 **buf2 = proc->tsar;

		SpellFx_WriteBgMap(proc->anim, buf1[ret], buf2[ret]);
		return;
	}

	if (ret == -1) {
		SpellFx_ClearBG1();
		Proc_Break(proc);
	}
}

struct ProcScr CONST_DATA ProcScr_EkrTriPegasusKnightOBJ[] = {
	PROC_19,
	PROC_REPEAT(EkrTriPegasusKnightOBJ_Loop),
	PROC_END,
};

void NewEkrTriPegasusKnightOBJ(struct Anim *anim, u32 pos, u32 etype, u32 ewtype)
{
	struct ProcEfxOBJ *proc;
	const u16 *pal;
	AnimScr *scr;
	const u16 *img;

	proc = SpawnProc(ProcScr_EkrTriPegasusKnightOBJ, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;

	if (pos == POS_L) {
		proc->terminator = 0x12;
		pal = gpBanimTriAtkPalettes[POS_L];
		scr = AnimScr_TriAtkLeft;
	} else {
		proc->terminator = 0x11;
		pal = gpBanimTriAtkPalettes[POS_R];
		scr = AnimScr_TriAtkRight;
	}

	proc->anim2 = EfxCreateFrontAnim(anim, scr, scr, scr, scr);
	LZ77UnCompWram(pal, gBuf_Banim);
	SpellFx_RegisterObjPal((u16 *)gBuf_Banim, 0x20);

	img = Img_TriPegasusKnightOBJ;
	if (etype != EKR_TRI_JTYPE_DEFAULT) {
		img = Img_TriFalconKnightSwordOBJ;

		if (ewtype == EKR_TRI_WTYPE_DEFAULT)
			img = Img_TriFalconKnightLanceOBJ;
	}

	SpellFx_RegisterObjGfx(img, 0x1000);
}

void EkrTriPegasusKnightOBJ_Loop(struct ProcEfxOBJ *proc)
{
	if (++proc->timer > proc->terminator) {
		BasRemove(proc->anim2);
		Proc_Break(proc);
	}
}

struct ProcScr CONST_DATA ProcScr_EkrTriArmorKnight[] = {
	PROC_19,
	PROC_REPEAT(EkrTriArmorKnight_Loop),
	PROC_END,
};

ProcPtr NewEkrTriArmorKnight(struct Anim *anim, u32 ekr1, u32 ekr2, u32 banim1, u32 ewtype2)
{
	struct ProcEkrTriClass *proc;

	proc = SpawnProc(ProcScr_EkrTriArmorKnight, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;

	proc->etype1 = ekr1;
	proc->etype2 = ekr2;
	proc->ewtype1 = banim1;
	proc->ewtype2 = ewtype2;
	return proc;
}

void EkrTriArmorKnight_Loop(struct ProcEkrTriClass * proc)
{
	if (++proc->timer == 0x1) {
		NewEkrTriArmorKnightOBJ(proc->anim, proc->etype1, proc->etype2, proc->ewtype1, proc->ewtype2);
		PlaySFX(SONG_E2, 0x100, proc->anim->xPosition, 0x1);
	}

	if (proc->timer == 0x30) {
		NewEkrTriArmorKnightOBJ2(proc->anim, 0, proc->etype1, proc->ewtype1);
		PlaySFX(SONG_E2, 0x100, proc->anim->xPosition, 0x1);
	}

	if (proc->timer == 0x3C) {
		NewEfxFlashBgWhite(proc->anim, 0x4);
		NewEfxTriangleQUAKE(proc->anim, 0xA);
	}

	if (proc->timer == 0x4F) {
		NewEkrTriArmorKnightOBJ2(proc->anim, 1, proc->etype2, proc->ewtype2);
		PlaySFX(SONG_E2, 0x100, proc->anim->xPosition, 0x1);
	}

	if (proc->timer == 0x5B)
		gEkrTriangleInvalid = true;

	if (proc->timer == 0x60) {
		NewEfxFlashBgWhite(proc->anim, 0x4);
		NewEfxTriangleQUAKE(proc->anim, 0xA);
	}

	if (proc->timer == 0x78)
		Proc_Break(proc);
}

struct ProcScr CONST_DATA ProcScr_EkrTriArmorKnightOBJ[] = {
	PROC_19,
	PROC_REPEAT(EkrTriArmorKnightOBJ_Loop),
	PROC_END,
};

void NewEkrTriArmorKnightOBJ(struct Anim *anim, u32 etype1, u32 etype2, u32 ewtype1, u32 ewtype2)
{
	struct ProcEfxOBJ * proc;
	struct Anim *anim2, *anim3;
	const u16 *pal;
	u32 *scr;
	const u16 *img;

	proc = SpawnProc(ProcScr_EkrTriArmorKnightOBJ, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->terminator = 0x14;

	pal = gpBanimTriAtkPalettes[0];
	if (etype1 == EKR_TRI_JTYPE_DEFAULT) {
		scr = AnimScr_TriKnightOBJ;
		img = Img_TriKnightOBJ;
	} else {
		switch (ewtype1) {
		case EKR_TRI_WTYPE_DEFAULT:
			scr = AnimScr_TriGenerialLanceOBJ;
			img = Img_TriGenerialLanceOBJ;
			break;

		case EKR_TRI_WTYPE_ALTERNATIVE:
			scr = AnimScr_TriGenerialAxeOBJ;
			img = Img_TriGenerialAxeOBJ;
			break;

		case EKR_TRI_WTYPE_ALTERNATIVE2:
		default:
			scr = AnimScr_TriGenerialHandAxeOBJ;
			img = Img_TriGenerialHandAxeOBJ;
			break;
		}
	}

	anim2 = EfxCreateFrontAnim(anim, scr, scr, scr, scr);
	proc->anim2 = anim2;
	anim2->oam2 = OAM2_PAL(0x8) + OAM2_LAYER(0x2) + OAM2_CHR(0x0800 / 0x20);

	LZ77UnCompWram(pal, gBuf_Banim);
	CpuFastCopy(gBuf_Banim, PAL_OBJ(0x8), 0x20);
	LZ77UnCompWram(img, gBuf_Banim);

	pal = gpBanimTriAtkPalettes[1];
	if (etype2 == EKR_TRI_JTYPE_DEFAULT) {
		scr = AnimScr_TriKnightOBJ;
		img = Img_TriKnightOBJ;
	} else {
		switch (ewtype2) {
		case EKR_TRI_WTYPE_DEFAULT:
			scr = AnimScr_TriGenerialLanceOBJ;
			img = Img_TriGenerialLanceOBJ;
			break;

		case EKR_TRI_WTYPE_ALTERNATIVE:
			scr = AnimScr_TriGenerialAxeOBJ;
			img = Img_TriGenerialAxeOBJ;
			break;

		case EKR_TRI_WTYPE_ALTERNATIVE2:
		default:
			scr = AnimScr_TriGenerialHandAxeOBJ;
			img = Img_TriGenerialHandAxeOBJ;
			break;
		}
	}

	anim2 = EfxCreateFrontAnim(anim, scr, scr, scr, scr);
	proc->anim3 = anim2;
	anim2->oam2 = OAM2_PAL(0xA) + OAM2_LAYER(0x2) + OAM2_CHR(0x1000 / 0x20);

	LZ77UnCompWram(pal, &gBuf_Banim[0x800]);
	CpuFastCopy(&gBuf_Banim[0x800], PAL_OBJ(0xA), 0x20);
	LZ77UnCompWram(img, &gBuf_Banim[0x800]);

	{
		u16 * dst = OBJ_VRAM0 + 0x800;

		RegisterDataMove(gBuf_Banim, dst, 0x1000);
	}

	EnablePalSync();

	proc->anim2->xPosition = proc->anim->xPosition + 0x20;
	proc->anim3->xPosition = proc->anim->xPosition - 0x20;
}

void EkrTriArmorKnightOBJ_Loop(struct ProcEfxOBJ * proc)
{
	int ret = Interpolate(INTERPOLATE_LINEAR, 0x20, 0x0, proc->timer, proc->terminator);

	proc->anim2->xPosition = proc->anim->xPosition + ret;
	proc->anim3->xPosition = proc->anim->xPosition - ret;

	if (++proc->timer > proc->terminator) {
		BasRemove(proc->anim2);
		BasRemove(proc->anim3);
		Proc_Break(proc);
	}
}

struct ProcScr CONST_DATA ProcScr_EkrTriArmorKnightOBJ2[] = {
	PROC_19,
	PROC_REPEAT(EkrTriArmorKnightOBJ2_Loop1),
	PROC_REPEAT(EkrTriArmorKnightOBJ2_Loop2),
	PROC_END,
};

void NewEkrTriArmorKnightOBJ2(struct Anim *anim, u32 pos, u32 etype, u32 ewtype)
{
	struct ProcEfxOBJ *proc;
	struct Anim * anim2, *_anim;
	const u16 *pal;
	AnimScr *scr;
	const u16 * buf;
	int off;

	proc = SpawnProc(ProcScr_EkrTriArmorKnightOBJ2, PROC_TREE_3);
	proc->anim = anim;
	proc->timer = 0;
	proc->terminator = 0x5;
	proc->unk29 = pos;
	proc->unk2A = etype;

	if (pos == 0)
		pal = gpBanimTriAtkPalettes[POS_L];
	else
		pal = gpBanimTriAtkPalettes[POS_R];

	if (etype == EKR_TRI_JTYPE_DEFAULT) {
		scr = AnimScr_TriKnightAtkOBJ;
		buf = Img_TriKnightAtkOBJ;
	} else {
		switch (ewtype) {
		case EKR_TRI_WTYPE_DEFAULT:
			scr = AnimScr_TriGenerialLanceAtkOBJ;
			buf = Img_TriGenerialLanceAtkOBJ;
			break;

		case EKR_TRI_WTYPE_ALTERNATIVE:
			scr = AnimScr_TriGenerialAxeAtkOBJ;
			buf = Img_TriGenerialAxeAtkOBJ;
			break;

		case EKR_TRI_WTYPE_ALTERNATIVE2:
		default:
			scr = AnimScr_TriGenerialHandAxeAtkOBJ;
			buf = Img_TriGenerialHandAxeAtkOBJ;
			break;
		}
	}

	anim2 = EfxCreateFrontAnim(anim, scr, scr, scr, scr);
	proc->anim2 = anim2;

	if (pos == 0) {
		anim2->yPosition += 0xA;
		proc->anim2->priority = 0x78;
		BasSort();

		_anim = proc->anim;
		proc->unk32 = _anim->xPosition + 0x10;
		proc->unk34 = _anim->xPosition - 0x10;
		proc->anim2->xPosition = proc->unk32;
	} else {
		anim2->yPosition += 0x2;
		proc->anim2->priority = 0x14;
		BasSort();

		_anim = proc->anim;
		proc->unk32 = _anim->xPosition - 0x0C;
		proc->unk34 = _anim->xPosition - 0x10;
		proc->anim2->xPosition = proc->unk32;
	}

	LZ77UnCompWram(pal, gBuf_Banim);
	SpellFx_RegisterObjPal((u16 *)gBuf_Banim, 0x20);
	SpellFx_RegisterObjGfx(buf, 0x1000);
}

void EkrTriArmorKnightOBJ2_Loop1(struct ProcEfxOBJ *proc)
{
	int ret = Interpolate(INTERPOLATE_SQUARE,
		*(i16 *)&proc->unk32,
		*(i16 *)&proc->unk34,
		proc->timer, proc->terminator);

	proc->anim2->xPosition = ret;

	if (++proc->timer > proc->terminator) {
		proc->timer = 0;
		proc->terminator = 0x14;
		Proc_Break(proc);
	}
}

void EkrTriArmorKnightOBJ2_Loop2(struct ProcEfxOBJ *proc)
{
	if (++proc->timer > proc->terminator) {
		BasRemove(proc->anim2);
		Proc_Break(proc);
	}
}

struct ProcScr CONST_DATA ProcScr_EfxTriangleQUAKE[] = {
	PROC_19,
	PROC_REPEAT(EfxTriangleQUAKE_Loop),
	PROC_END,
};

void NewEfxTriangleQUAKE(struct Anim *anim, int duration)
{
	struct ProcEfx2 *proc;

	gEfxBgSemaphore++;

	proc = SpawnProc(ProcScr_EfxTriangleQUAKE, PROC_TREE_3);
	proc->anim = anim;
	proc->procfx = NewEfxQuakePure(0, 0);
	proc->timer = 0;
	proc->terminator = duration;
}

void EfxTriangleQUAKE_Loop(struct ProcEfx2 *proc)
{
	s16 ix1, iy1;
	s16 ix2, iy2;

	SetBgOffset(BG_2, gEkrBg2QuakeVec.x, gEkrBg2QuakeVec.y);
	SetBgOffset(BG_0,
		gEkrBg2QuakeVec.x + gEkrBg0QuakeVec.x,
		gEkrBg2QuakeVec.y + gEkrBg0QuakeVec.y);

	EkrGauge_Setxy323A(
		-(gEkrBg2QuakeVec.x + gEkrBg0QuakeVec.x),
		-(gEkrBg2QuakeVec.y + gEkrBg0QuakeVec.y));

	EkrDispUP_SetPositionSync(
		-(gEkrBg2QuakeVec.x + gEkrBg0QuakeVec.x),
		-(gEkrBg2QuakeVec.y + gEkrBg0QuakeVec.y));

	if (GetEkrDragonStateType() != 0)
		SetBgOffset(BG_3, gEkrBg2QuakeVec.x, gEkrBg2QuakeVec.y + 0x10);

	ix1 = (gEkrXPosReal[0] + gEkrBg2QuakeVec.x) - gEkrBgPosition;
	iy1 = gEkrYPosReal[0] - gEkrBg2QuakeVec.y;
	ix2 = (gEkrXPosReal[1] + gEkrBg2QuakeVec.x) - gEkrBgPosition;
	iy2 = gEkrYPosReal[1] - gEkrBg2QuakeVec.y;

	SetEkrFrontAnimPostion(0, ix1, iy1);
	SetEkrFrontAnimPostion(1, ix2, iy2);

	if (++proc->timer > proc->terminator) {
		gEfxBgSemaphore = gEfxBgSemaphore - 1;
		SetBgOffset(BG_2, 0, 0);
		SetBgOffset(BG_0, gEkrBg0QuakeVec.x, gEkrBg0QuakeVec.y);
		EkrGauge_Setxy323A(-gEkrBg0QuakeVec.x, -gEkrBg0QuakeVec.y);
		EkrDispUP_SetPositionSync(-gEkrBg0QuakeVec.x, -gEkrBg0QuakeVec.y);

		if (GetEkrDragonStateType() != 0)
			SetBgOffset(BG_3, 0, 0x10);

		ix1 = gEkrXPosReal[0] - gEkrBgPosition;
		iy1 = gEkrYPosReal[0];
		ix2 = gEkrXPosReal[1] - gEkrBgPosition;
		iy2 = gEkrYPosReal[1];

		SetEkrFrontAnimPostion(0, ix1, iy1);
		SetEkrFrontAnimPostion(1, ix2, iy2);

		Proc_End(proc->procfx);
		Proc_Break(proc);
	}
}
