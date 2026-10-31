#include "prelude.h"
#include "proc.h"
#include "hardware.h"
#include "util.h"
#include "datamove.h"
#include "oam.h"
#include "banim.h"
#include "banim_data.h"
#include "banim_ekrdragon.h"

struct ProcScr CONST_DATA ProcScr_EkrBaseKaiten[] = {
	PROC_19,
	PROC_REPEAT(EkrBaseKaiten_Loop),
	PROC_END,
};

const u8 *CONST_DATA Imgs_EkrBaseKaiten1[] = {
	Img_EkrBaseKaiten2, NULL,
	Img_EkrBaseKaiten2, NULL,
	Img_EkrBaseKaiten1, NULL,
	Img_EkrBaseKaiten2, NULL
};

const u8 *CONST_DATA Imgs_EkrBaseKaiten2[] = {
	Img_EkrBaseKaiten3,
	Img_EkrBaseKaiten4,
	Img_EkrBaseKaiten4,
	Img_EkrBaseKaiten4,
	Img_EkrBaseKaiten5,
	Img_EkrBaseKaiten4,
	Img_EkrBaseKaiten4,
	Img_EkrBaseKaiten4
};

CONST_DATA AnimScr *AnimScrs_EkrBaseKaiten1[] = {
	AnimScr_EkrBaseKaiten_085CEDF8, NULL,
	AnimScr_EkrBaseKaiten_085CEE18, NULL,
	AnimScr_EkrBaseKaiten_085CE168, NULL,
	AnimScr_EkrBaseKaiten_085CEE3C, NULL,
};

CONST_DATA AnimScr *AnimScrs_EkrBaseKaiten2[] = {
	AnimScr_EkrBaseKaiten_085CF6CC,
	AnimScr_EkrBaseKaiten_085D0530,
	AnimScr_EkrBaseKaiten_085D0530,
	AnimScr_EkrBaseKaiten_085D0530,
	AnimScr_EkrBaseKaiten_085D0D34,
	AnimScr_EkrBaseKaiten_085D0554,
	AnimScr_EkrBaseKaiten_085D0554,
	AnimScr_EkrBaseKaiten_085D0554
};

CONST_DATA AnimScr *AnimScrs_EkrBaseKaiten3[] = {
	AnimScr_EkrBaseKaiten_085CF6A8,
	AnimScr_EkrBaseKaiten_085D04E8,
	AnimScr_EkrBaseKaiten_085D04E8,
	AnimScr_EkrBaseKaiten_085D04E8,
	AnimScr_EkrBaseKaiten_085D0D10,
	AnimScr_EkrBaseKaiten_085D050C,
	AnimScr_EkrBaseKaiten_085D050C,
	AnimScr_EkrBaseKaiten_085D050C
};

CONST_DATA AnimScr *AnimScrs_EkrBaseKaiten4[] = {
	AnimScr_EkrBaseKaiten_085CEE60, NULL,
	AnimScr_EkrBaseKaiten_085CEE80, NULL,
	AnimScr_EkrBaseKaiten_085CE18C, NULL,
	AnimScr_EkrBaseKaiten_085CEEA4, NULL,
};

CONST_DATA AnimScr *AnimScrs_EkrBaseKaiten5[] = {
	AnimScr_EkrBaseKaiten_085CF714,
	AnimScr_EkrBaseKaiten_085D05C0,
	AnimScr_EkrBaseKaiten_085D05C0,
	AnimScr_EkrBaseKaiten_085D05C0,
	AnimScr_EkrBaseKaiten_085D0D7C,
	AnimScr_EkrBaseKaiten_085D05E4,
	AnimScr_EkrBaseKaiten_085D05E4,
	AnimScr_EkrBaseKaiten_085D05E4
};

CONST_DATA AnimScr *AnimScrs_EkrBaseKaiten6[] = {
	AnimScr_EkrBaseKaiten_085CF6F0,
	AnimScr_EkrBaseKaiten_085D0578,
	AnimScr_EkrBaseKaiten_085D0578,
	AnimScr_EkrBaseKaiten_085D0578,
	AnimScr_EkrBaseKaiten_085D0D58,
	AnimScr_EkrBaseKaiten_085D059C,
	AnimScr_EkrBaseKaiten_085D059C,
	AnimScr_EkrBaseKaiten_085D059C
};

const u16 EkrBaseKaiten_RefTable[12][8] = {
	{0xA0, 0xB8, 0xE0, 0xF0, 0x01, 0x30, 0x60, 0xFFFF},
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFFFF},
	{0xC0, 0xD8, 0xF0, 0x01, 0x10, 0x28, 0x40, 0xFFFF},
	{0x40, 0x28, 0x10, 0x01, 0xE8, 0xD0, 0xC0, 0xFFFF},
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFFFF},
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFFFF},
	{0x40, 0x40, 0x4C, 0x58, 0x64, 0x70, 0x80, 0xFFFF},
	{0x40, 0x30, 0x20, 0x10, 0xE8, 0xD0, 0xC0, 0xFFFF},
	{0xC0, 0xC8, 0xD0, 0xD8, 0xE0, 0xF0, 0xF8, 0xFFFF},
	{0xC8, 0xC0, 0xB8, 0xB0, 0xA0, 0x90, 0x80, 0xFFFF},
	{0xF0, 0xC0, 0x90, 0x60, 0x30, 0x00, 0xD0, 0xFFFF},
	{0x70, 0x40, 0x10, 0xE0, 0xB0, 0x80, 0x50, 0xFFFF}
};

const u16 *CONST_DATA EkrBaseKaiten_Table1[] = {
	EkrBaseKaiten_RefTable[1], NULL,
	EkrBaseKaiten_RefTable[2], NULL,
	EkrBaseKaiten_RefTable[0], NULL,
	EkrBaseKaiten_RefTable[3], NULL,
};

const u16 *CONST_DATA EkrBaseKaiten_Table2[] = {
	EkrBaseKaiten_RefTable[5],
	EkrBaseKaiten_RefTable[8],
	EkrBaseKaiten_RefTable[8],
	EkrBaseKaiten_RefTable[8],
	EkrBaseKaiten_RefTable[11],
	EkrBaseKaiten_RefTable[9],
	EkrBaseKaiten_RefTable[9],
	EkrBaseKaiten_RefTable[9]
};

const u16 *CONST_DATA EkrBaseKaiten_Table3[] = {
	EkrBaseKaiten_RefTable[4],
	EkrBaseKaiten_RefTable[6],
	EkrBaseKaiten_RefTable[6],
	EkrBaseKaiten_RefTable[6],
	EkrBaseKaiten_RefTable[10],
	EkrBaseKaiten_RefTable[7],
	EkrBaseKaiten_RefTable[7],
	EkrBaseKaiten_RefTable[7]
};

#define AccessArray(array, index, offset) \
	(*(typeof(&*(array)))((void *)(array) + (offset)))

void NewEkrBaseKaiten(int identifier)
{
	int mode;
	struct Anim *anim;
	struct ProcEkrBaseKaiten *proc;
	u32 scale;
	const u8 *img;

	SetBlendConfig(0, 10, 6, 0);
	SetBlendTargetA(0, 0, 0, 0, 0);
	SetBlendTargetB(0, 0, 1, 1, 0);
	gDispIo.blend_ct.target2_enable_bd = 1;

	if (gEkrBmLocation[POS_L] == gEkrBmLocation[2]) {
		if (gEkrBmLocation[POS_R] >= gEkrBmLocation[3])
			mode = 6;
		else
			mode = 2;
	} else if (gEkrBmLocation[POS_R] == gEkrBmLocation[3]) {
		if (gEkrBmLocation[POS_L] < gEkrBmLocation[2])
			mode = 0;
		else
			mode = 4;
	} else if (gEkrBmLocation[POS_L] < gEkrBmLocation[2]) {
		if (gEkrBmLocation[POS_R] >= gEkrBmLocation[3])
			mode = 7;
		else
			mode = 1;
	} else {
		if (gEkrBmLocation[POS_R] >= gEkrBmLocation[3])
			mode = 5; 
		else
			mode = 3;
	}

	switch (gEkrDistanceType) {
	case EKR_DISTANCE_CLOSE:
	case EKR_DISTANCE_PROMOTION:
		img = Imgs_EkrBaseKaiten1[mode];
		break;

	case EKR_DISTANCE_FAR:
	case EKR_DISTANCE_FARFAR:
	case EKR_DISTANCE_MONOCOMBAT:
	default:
		img = Imgs_EkrBaseKaiten2[mode];
		break;
	}

	scale = mode << 2;
	LZ77UnCompVram(img, OBJ_VRAM0);
	CpuFastSet(Pal_EkrBaseKaiten, gPal + 0x140, 1);
	EnablePalSync();

	switch (gEkrDistanceType) {
	case EKR_DISTANCE_CLOSE:
	case EKR_DISTANCE_PROMOTION:
		proc = SpawnProc(ProcScr_EkrBaseKaiten, PROC_TREE_3);
		proc->type = identifier;
		proc->unk29 = 0;
		proc->timer = 0;
		proc->terminator = 0xB;
		proc->x1 = (gEkrBmLocation[POS_L] + gEkrBmLocation[2]) * 8 + 8;
		proc->y1 = (gEkrBmLocation[POS_R] + gEkrBmLocation[3]) * 8 + 8;
		proc->x2 = 0x78;
		proc->y2 = 0x68;

		if (proc->type == 0)
			anim = BasCreate(AccessArray(AnimScrs_EkrBaseKaiten1, mode, scale), 0x64);
		else
			anim = BasCreate(AccessArray(AnimScrs_EkrBaseKaiten4, mode, scale), 0x64);

		proc->anim = anim;
		anim->oam2 = 0x4800;
		anim->oam01 |= 0x400;

		if (proc->type == 0) {
			anim->xPosition = proc->x1;
			anim->yPosition = proc->y1;
		} else {
			anim->xPosition = proc->x2;
			anim->yPosition = proc->y2;
		}

		proc->unk60 = AccessArray(EkrBaseKaiten_Table1, mode, scale);
		proc->unk3E = 0;
		proc->unk36 = 0;
		break;

	case EKR_DISTANCE_FAR:
	case EKR_DISTANCE_FARFAR:
		proc = SpawnProc(ProcScr_EkrBaseKaiten, PROC_TREE_3);
		proc->type = identifier;
		proc->unk29 = 0;
		proc->timer = 0;
		proc->terminator = 0xB;
		proc->x1 = gEkrBmLocation[POS_L] * 0x10 + 8;
		proc->y1 = gEkrBmLocation[POS_R] * 0x10 + 8;
		proc->x2 = 0x48;
		proc->y2 = 0x68;

		if (gEkrInitPosReal == POS_R)
			proc->x2 -= BanimLeftDefaultPos[gEkrDistanceType];

		if (proc->type == 0)
			anim = BasCreate(AccessArray(AnimScrs_EkrBaseKaiten2, mode, scale), 0x64);
		else
			anim = BasCreate(AccessArray(AnimScrs_EkrBaseKaiten5, mode, scale), 0x64);

		proc->anim = anim;
		anim->oam2 = 0x4800;
		anim->oam01 |= 0x400;

		if (proc->type == 0) {
			anim->xPosition = proc->x1;
			anim->yPosition = proc->y1;
		} else {
			anim->xPosition = proc->x2;
			anim->yPosition = proc->y2;
		}

		proc->unk60 = AccessArray(EkrBaseKaiten_Table2, mode, scale);
		proc->unk3E = 0;
		proc->unk36 = 0;

		proc = SpawnProc(ProcScr_EkrBaseKaiten, PROC_TREE_3);
		proc->type = identifier;
		proc->unk29 = 1;
		proc->timer = 0;
		proc->terminator = 0xB;
		proc->x1 = gEkrBmLocation[2] * 0x10 + 8;
		proc->y1 = gEkrBmLocation[3] * 0x10 + 8;
		proc->x2 = 0xA8;
		proc->y2 = 0x68;

		if (gEkrInitPosReal == POS_L)
			proc->x2 = BanimLeftDefaultPos[gEkrDistanceType] + 0xA8;

		if (proc->type == 0)
			anim = BasCreate(AccessArray(AnimScrs_EkrBaseKaiten3, mode, scale), 0x64);
		else
			anim = BasCreate(AccessArray(AnimScrs_EkrBaseKaiten6, mode, scale), 0x64);

		proc->anim = anim;
		anim->oam2 = 0x4800;
		anim->oam01 |= 0x400;

		if (proc->type == 0) {
			anim->xPosition = proc->x1;
			anim->yPosition = proc->y1;
		} else {
			anim->xPosition = proc->x2;
			anim->yPosition = proc->y2;
		}

		proc->unk60 = AccessArray(EkrBaseKaiten_Table3, mode, scale);
		proc->unk3E = 0;
		proc->unk36 = 0;
		break;

	case EKR_DISTANCE_MONOCOMBAT:
		proc = SpawnProc(ProcScr_EkrBaseKaiten, PROC_TREE_3);
		proc->type = identifier;
		proc->unk29 = 0;
		proc->timer = 0;
		proc->terminator = 0xB;
		proc->x1 = gEkrBmLocation[2] * 0x10 + 8;
		proc->y1 = gEkrBmLocation[3] * 0x10 + 8;
		proc->x2 = 0x78;
		proc->y2 = 0x68;

		if (proc->type == 0)
			anim = BasCreate(AccessArray(AnimScrs_EkrBaseKaiten3, mode, scale), 0x64);
		else
			anim = BasCreate(AccessArray(AnimScrs_EkrBaseKaiten6, mode, scale), 0x64);

		proc->anim = anim;
		anim->oam2 = 0x4800;
		anim->oam01 |= 0x400;

		if (proc->type == 0) {
			anim->xPosition = proc->x1;
			anim->yPosition = proc->y1;
		} else {
			anim->xPosition = proc->x2;
			anim->yPosition = proc->y2;
		}

		proc->unk60 = AccessArray(EkrBaseKaiten_Table3, mode, scale);
		proc->unk3E = 0;
		proc->unk36 = 0;
		break;

	default:
		break;
	}
}

void EkrBaseKaiten_Loop(struct ProcEkrBaseKaiten *proc)
{
	struct Anim *anim = proc->anim;

	if (proc->timer >= proc->terminator) {
		BasRemove(anim);
		Proc_Break(proc);
		return;
	}

	if (proc->type == 0) {
		anim->xPosition =
			Interpolate(0, proc->x1, proc->x2, proc->timer, proc->terminator);
		anim->yPosition =
			Interpolate(0, proc->y1, proc->y2, proc->timer, proc->terminator);
	} else {
		anim->xPosition =
			Interpolate(0, proc->x2, proc->x1, proc->timer, proc->terminator);
		anim->yPosition =
			Interpolate(0, proc->y2, proc->y1, proc->timer, proc->terminator);
	}

	if (proc->timer <= proc->terminator)
		proc->timer++;
}

struct ProcScr CONST_DATA ProcScr_EkrUnitKakudai[] = {
	PROC_19,
	PROC_REPEAT(EkrUnitKakudai_PrepareAnimScript),
	PROC_REPEAT(EkrUnitKakudai_Main),
	PROC_REPEAT(EkrUnitKakudai_End),
	PROC_END,
};

void NewEkrUnitKakudai(int identifier)
{
	struct ProcEkrUnitKakudai *proc;

	proc = SpawnProc(ProcScr_EkrUnitKakudai, PROC_TREE_3);
	proc->type = identifier;
	proc->valid_r = 0;
	proc->valid_l = 0;

	switch (gEkrDistanceType) {
	case EKR_DISTANCE_CLOSE:
	case EKR_DISTANCE_FAR:
	case EKR_DISTANCE_FARFAR:
	case EKR_DISTANCE_MONOCOMBAT:
		if (gBanimValid[POS_L] == 1 && GetDragonPosition() != POS_L)
			proc->valid_l = 1;

		if (gBanimValid[POS_R] == 1 && GetDragonPosition() != POS_R)
			proc->valid_r = 1;
		return;

	case EKR_DISTANCE_PROMOTION:
		if (identifier == 0) {
			proc->valid_l = 0;
			proc->valid_r = 1;
		} else {
			proc->valid_l = 1;
			proc->valid_r = 0;
		}
		break;

	default:
		break;
	}
}

void EkrUnitKakudai_PrepareAnimScript(struct ProcEkrUnitKakudai *proc)
{
    void *vram;
    int std_type = BanimDefaultStandingTypes[gEkrDistanceType];
	int front_mode = BanimDefaultModeConfig[std_type * 4];

	UpdateBanimFrame();

	if (proc->type == 0)
		if (gBattleSt.flags & BATTLE_FLAG_REFRESH)
			EfxPalModifyPetrifyEffect(gPal, 0x17, 1);

	if (gBanimValid[POS_L] == 1) {
		struct BanimScrFrame *scr = (void *)(gBanimScrs + gpBanimModesLeft[front_mode]);
        const void *src = scr->img;

		proc->pOaml = (void *)(gBanimOamBufs + scr->oam_offset);
		LZ77UnCompWram(src, gBanimImgSheetBuf_Left);
	}

	if (gBanimValid[POS_R] == 1) {
		struct BanimScrFrame *scr = (void *)(gBanimScrs + BAS_SCR_MAX_SIZE + gpBanimModesRight[front_mode]);
		const void *src = scr->img;

		proc->pOamr = (void *)(gBanimOamBufs + BAS_OAM_MAX_SIZE + scr->oam_offset);
		LZ77UnCompWram(src, gBanimImgSheetBuf_Right);
	}

	if (gBanimBallistaImages[POS_L] != NULL)
		LZ77UnCompWram(gBanimBallistaImages[POS_L], gBanimImgSheetBuf_Left + BAS_IMG_MAX_SIZE);

	if (gBanimBallistaImages[POS_R] != NULL)
		LZ77UnCompWram(gBanimBallistaImages[POS_R], gBanimImgSheetBuf_Right + BAS_IMG_MAX_SIZE);

    vram = OBJ_VRAM1;
	RegisterDataMove(gBanimImgSheetBuf_Left, vram, 0x4000);

	proc->timer = 0;
	proc->terminator = 0xB;

	proc->x1 = gEkrBmLocation[0] * 0x10 + 8;
	proc->y1 = gEkrBmLocation[1] * 0x10 + 8;
	proc->x2 = gEkrBmLocation[2] * 0x10 + 8;
	proc->y2 = gEkrBmLocation[3] * 0x10 + 8;

	proc->left_pos = BanimTypesPosLeft[gEkrDistanceType];
	proc->right_pos = BanimTypesPosRight[gEkrDistanceType];

	if (gEkrInitPosReal == POS_L)
		proc->right_pos += BanimLeftDefaultPos[gEkrDistanceType];
	else
		proc->left_pos -= BanimLeftDefaultPos[gEkrDistanceType];

	Proc_Break(proc);
}

void EkrUnitKakudai_Main(struct ProcEkrUnitKakudai *proc)
{
	u16 ret, x, y;
	struct BaSpriteData bas_data[0x40];
	struct Anim local_anim;
	struct Anim *anim = &local_anim;

	if (proc->timer >= proc->terminator) {
		Proc_Break(proc);
		return;
	}

	proc->timer++;

	if (proc->type == 0)
		ret = Interpolate(0, 0x250, 0x100, proc->timer, proc->terminator);
	else
		ret = Interpolate(0, 0x100, 0x250, proc->timer, proc->terminator);

	if (proc->valid_l == true) {
		BanimUpdateSpriteRotScale(proc->pOaml, bas_data, ret, ret, 0);

		if (proc->type == 0) {
			x = Interpolate(0, proc->x1, proc->left_pos, proc->timer, proc->terminator);
			y = Interpolate(0, proc->y1, 0x58, proc->timer, proc->terminator);
		} else {
			x = Interpolate(0, proc->left_pos, proc->x1, proc->timer, proc->terminator);
			y = Interpolate(0, 0x58, proc->y1, proc->timer, proc->terminator);
		}

		anim->sprData = bas_data;
		anim->xPosition = x;
		anim->yPosition = y;
		anim->flags2 = ANIM_BIT2_0400;
		anim->oam2 = OAM2_CHR(VRAMOFF_OBJ_4000 / CHR_SIZE) + OAM2_PAL(OBPAL_EFX_UNIT_L) + OAM2_LAYER(0);
		anim->oam01 = 0;
		BasPutOam(anim);
	}

	if (proc->valid_r == true) {
		BanimUpdateSpriteRotScale(proc->pOamr, bas_data, ret, ret, 1);

		if (proc->type == 0) {
			x = Interpolate(0, proc->x2, proc->right_pos, proc->timer, proc->terminator);
			y = Interpolate(0, proc->y2, 0x58, proc->timer, proc->terminator);
		} else {
			x = Interpolate(0, proc->right_pos, proc->x2, proc->timer, proc->terminator);
			y = Interpolate(0, 0x58, proc->y2, proc->timer, proc->terminator);
		}

		anim->sprData = bas_data;
		anim->xPosition = x;
		anim->yPosition = y;
		anim->flags2 = 0x400;
		anim->oam2 = 0x9300;
		anim->oam01 = 0;
		BasPutOam(anim);
	}
}

void EkrUnitKakudai_End(struct ProcEkrUnitKakudai *proc)
{
	Proc_Break(proc);
}

struct ProcScr CONST_DATA ProcScr_EkrWindowAppear[] = {
	PROC_19,
	PROC_REPEAT(EkrWindowAppear_Main),
	PROC_END,
};

void NewEkrWindowAppear(int identifier, int duration)
{
	int iy;
	struct ProcEkrIntroWindow *proc;

	proc = SpawnProc(ProcScr_EkrWindowAppear, PROC_TREE_3);
	proc->type = identifier;
	proc->timer = 0;
	proc->terminator = duration;
	proc->ymax = 0x39;

	if (identifier == 0)
		iy = 0x39;
	else
		iy = 0x00;

	EkrGauge_Clr323A(gEkrBg0QuakeVec.x, gEkrBg0QuakeVec.y + iy);
	gEkrWindowAppearUnexist = true;
	EkrGauge_ClrInitFlag();
}

bool CheckEkrWindowAppearUnexist(void)
{
	if (gEkrWindowAppearUnexist == false)
		return true;

	return false;
}

void EkrWindowAppear_Main(struct ProcEkrIntroWindow *proc)
{
	int iy;

	if (proc->timer >= proc->terminator) {
		gEkrWindowAppearUnexist = false;
		EkrGauge_SetInitFlag();
		Proc_Break(proc);
		return;
	}

	proc->timer++;
	if (proc->type == 0)
		iy = Interpolate(1, proc->ymax, 0, proc->timer, proc->terminator);
	else
		iy = Interpolate(4, 0, proc->ymax, proc->timer, proc->terminator);

	EkrGauge_Clr323A(gEkrBg0QuakeVec.x, gEkrBg0QuakeVec.y + iy);
}

struct ProcScr CONST_DATA ProcScr_EkrNamewinAppear[] = {
	PROC_19,
	PROC_REPEAT(EkrNamewinAppear_Delay),
	PROC_REPEAT(EkrNamewinAppear_Main),
	PROC_END,
};

void NewEkrNamewinAppear(int identifier, int duration, int delay)
{
	int iy;
	struct ProcEkrIntroWindow *proc;

	proc = SpawnProc(ProcScr_EkrNamewinAppear, PROC_TREE_3);

	proc->type = identifier;
	proc->timer = 0;
	proc->terminator = duration;
	proc->ymax = delay;
	proc->ymax_name = -49;

	if (identifier == 0)
		EkrDispUP_SetPositionUnsync(0, proc->ymax_name);
	else
		EkrDispUP_SetPositionUnsync(0, 0);

	gEkrNameWinAppearExist = true;
	UnsyncEkrDispUP();
}

bool CheckEkrNamewinAppearUnexist(void)
{
	if (gEkrNameWinAppearExist == false)
		return true;

	return false;
}

void EkrNamewinAppear_Delay(struct ProcEkrIntroWindow *proc)
{
	if (proc->timer == proc->ymax) {
		proc->timer = 0;
		Proc_Break(proc);
		return;
	}

	proc->timer++;
}

void EkrNamewinAppear_Main(struct ProcEkrIntroWindow *proc)
{
	int iy;

	if (proc->timer >= proc->terminator) {
		gEkrNameWinAppearExist = false;
		SyncEkrDispUP();

		if (proc->type == 2)
			EndEkrDispUP();

		Proc_Break(proc);
		return;
	}
	proc->timer++;

	if (proc->type == 0)
		iy = Interpolate(1, proc->ymax_name, 0, proc->timer, proc->terminator);
	else
		iy = Interpolate(4, 0, proc->ymax_name, proc->timer, proc->terminator);

	EkrDispUP_SetPositionUnsync(0, iy);
}

struct ProcScr CONST_DATA ProcScr_EkrBaseAppear[] = {
	PROC_19,
	PROC_REPEAT(EkrBaseAppear_Loop),
	PROC_END,
};

void NewEkrBaseAppear(int identifier, int duration)
{
	int iy;

	struct ProcEkrIntroWindow *proc;

	proc = SpawnProc(ProcScr_EkrBaseAppear, PROC_TREE_3);
	proc->type = identifier;
	proc->timer = 0;
	proc->terminator = duration;

	if (identifier == 0)
		SetBgOffset(BG_2, 0, -0x58);
	else
		SetBgOffset(BG_2, 0, 0);

	gProcEkrBaseAppearExist = true;
}

bool CheckEkrBaseAppearUnexist(void)
{
	if (gProcEkrBaseAppearExist == false)
		return true;

	return false;
}

void EkrBaseAppear_Loop(struct ProcEkrIntroWindow *proc)
{
	int iy;

	if (proc->timer >= proc->terminator) {
		gProcEkrBaseAppearExist = false;
		Proc_Break(proc);
		return;
	}

	proc->timer++;
	if (proc->type == 0)
		iy = Interpolate(1, -0x50, 0, proc->timer, proc->terminator);
	else
		iy = Interpolate(4, 0, -0x50, proc->timer, proc->terminator);

	SetBgOffset(BG_2, 0, iy);
}
