#include "prelude.h"
#include "proc.h"
#include "oam.h"
#include "banim.h"
#include "banim_data.h"

void EkrMainMini_ExecCommands(struct EkrMainMiniDesc *desc, struct Anim *anim)
{
	int type;

	if (anim == NULL)
		return;

	type = anim->flags2 & ANIM_BIT2_CMD_MASK;
	if (type == 0)
		return;

	if (type & ANIM_BIT2_COMMAND) {
		while (1) {
			if (anim->cqSize == 0)
				goto L_cmd_loop_end;

			switch (anim->cq[anim->cqSize - 1]) {
			case 0:
				break;

			case BAS_CMD(0x01):
			case BAS_CMD(0x02):
				EkrMainMini_C01_Blocking(anim);
				break;

			case BAS_CMD(0x05):
				if (GetAnimLayer(anim) == 0)
					StartClassReelSpellAnim(anim);

				/* fall through */

			case BAS_CMD(0x03):
			case BAS_CMD(0x04):
				anim->scrCur++;
				break;

			case BAS_CMD(0x0D):
				EkrMainMini_C0D_ExecNextRoundAfterAttack(anim);
				break;

			case BAS_CMD(0x18):
				EkrMainMini_C01_Blocking(anim);
				break;

			case BAS_CMD(0x30):
			case BAS_CMD(0x31):
			case BAS_CMD(0x32):
			default:
				break;
			}
			anim->cqSize--;
		}

		L_cmd_loop_end:
			anim->flags2 &= ~(ANIM_BIT2_COMMAND |
							  ANIM_BIT2_0800 |
							  ANIM_BIT2_0080 |
							  ANIM_BIT2_0040 |
							  ANIM_BIT2_0020 |
							  ANIM_BIT2_0010 |
							  ANIM_BIT2_0008 |
							  ANIM_BIT2_0004 |
							  ANIM_BIT2_0002 |
							  ANIM_BIT2_0001);
	}

	if (type & ANIM_BIT2_FRAME) {
		if (GetAnimLayer(anim) == 0 && desc->img_sheet != anim->imgSheet) {
			SyncBanimImage(anim);
			desc->img_sheet = anim->imgSheet;
		}

		anim->flags2 &= ~(ANIM_BIT2_FRAME |
						  ANIM_BIT2_0800 |
						  ANIM_BIT2_0080 |
						  ANIM_BIT2_0040 |
						  ANIM_BIT2_0020 |
						  ANIM_BIT2_0010 |
						  ANIM_BIT2_0008 |
						  ANIM_BIT2_0004 |
						  ANIM_BIT2_0002 |
						  ANIM_BIT2_0001);
	}

	if (type & ANIM_BIT2_STOP)
		anim->nextRoundId = -1;
}

void EkrMainMini_C01_Blocking(struct Anim * anim)
{
	anim->nextRoundId = -2;

	if (anim->flags3 & ANIM_BIT3_C01_BLOCK_END_INBATTLE) {
		anim->flags3 &= ANIM_BIT3_C01_BLOCK_END_INBATTLE;
		anim->nextRoundId = 0;
		anim->scrCur++;
	}
}

void EkrMainMini_C0D_ExecNextRoundAfterAttack(struct Anim * anim)
{
	register const void *tmp_ptr;
	register struct BanimScrFrame *scr_start asm("r1");
	register int scr_offset asm("r0");
	struct EkrMainMiniDesc *desc = anim->priv;

	if (GetAnimLayer(anim) == 0) {
		const u8 *mode_conf = BanimDefaultModeConfig;
		struct BattleAnim *banim_data = desc->bid + gBanimTable;
		const int *banim_mode = banim_data->modes;

		struct Anim *anim1 = desc->anim1;
		struct Anim *anim2 = desc->anim2;

		const u8 *scr_buf = tmp_ptr = desc->scr_buf;
		int frame_idx = mode_conf[ANIM_ROUND_TAKING_HIT_CLOSE * 4 + 0];

		scr_offset = banim_mode[frame_idx];
		scr_start = (void *)(scr_buf + scr_offset);

		anim1->imgSheet = scr_start->img;
#if !NONMATCHING
		anim1->sprData = tmp_ptr = (tmp_ptr = anim1->sprDataPool) + scr_start->oam_offset;
		anim2->sprData = tmp_ptr = (tmp_ptr = anim2->sprDataPool) + BAS_OAM_REF_MAX_SIZE;
#else
		anim1->sprData = anim1->sprDataPool + scr_start->oam_offset;
		anim2->sprData = anim2->sprDataPool + BAS_OAM_REF_MAX_SIZE;
#endif
		if (desc->img_sheet != anim->imgSheet) {
			NewEkrChienCHR(anim);
			desc->img_sheet = anim->imgSheet;
		}
	}
}

void EkrMainMini_InitAnim(struct EkrMainMiniDesc *desc)
{
	int mode1, mode2;
	int priority1, priority2;
	struct Anim *anim;
	u8 *oam_buf;
	u32 *scr1, *scr2;
	struct BattleAnim *banim, *tmp_banim;
	u8 *scr_buf;
	int *modes;

	banim = gBanimTable;

	mode1     = BanimDefaultModeConfig[desc->round_type * 4 + 0];
	priority1 = BanimDefaultModeConfig[desc->round_type * 4 + 1];
	mode2     = BanimDefaultModeConfig[desc->round_type * 4 + 2];
	priority2 = BanimDefaultModeConfig[desc->round_type * 4 + 3];

	/**
	 * scr
	 */
	LZ77UnCompWram(banim[desc->bid].script, desc->scr_buf);

	tmp_banim = &banim[desc->bid];
	modes = tmp_banim->modes;
	scr_buf = desc->scr_buf;

	scr1 = AnimScr_DefaultAnim;
	if (mode1 != (u8)BANIM_MODE_INVALID)
		scr1 = (void *)(scr_buf + modes[mode1]);

	scr2 = AnimScr_DefaultAnim;
	if (mode2 != (u8)BANIM_MODE_INVALID)
		scr2 = (void *)(scr_buf + modes[mode2]);

	/**
	 * oam
	 */
	if (desc->pos == POS_L) {
		oam_buf = (u8 *)desc->oam_buf;

		LZ77UnCompWram(tmp_banim->oam_l, oam_buf);
		*(u32 *)(oam_buf + BAS_OAM_REF_MAX_SIZE) = 1;
	} else {
		oam_buf = (u8 *)desc->oam_buf;

		LZ77UnCompWram(tmp_banim->oam_r, oam_buf);
		*(u32 *)(oam_buf + BAS_OAM_REF_MAX_SIZE) = 1;
	}

	/**
	 * front anim
	 */
	anim = BasCreate(scr1, priority1);
	anim->sprDataPool = desc->oam_buf;
	anim->xPosition = desc->x;
	anim->yPosition = desc->y;
	anim->oam2 = (desc->oam2_pal * 0x1000) | OAM2_LAYER(2) | desc->oam2_chr;
	anim->flags2 |= (desc->pos << 9) | ANIM_BIT2_0400 | ANIM_BIT2_BACK_FRAME;
	anim->nextRoundId = 0;
	anim->currentRoundType = desc->round_type;
	anim->imgBuf = desc->img_buf;

	desc->anim1 = anim;
	anim->priv = desc;

	/**
	 * back anim
	 */
	anim = BasCreate(scr2, priority2);
	anim->sprDataPool = desc->oam_buf;
	anim->xPosition = desc->x;
	anim->yPosition = desc->y;
	anim->oam2 = (desc->oam2_pal * 0x1000) | OAM2_LAYER(2) | desc->oam2_chr;
	anim->flags2 |= (desc->pos << 9) | ANIM_BIT2_0400 | ANIM_BIT2_FRONT_FRAME;
	anim->nextRoundId = 0;
	anim->currentRoundType = desc->round_type;
	anim->imgBuf = desc->img_buf;

	desc->anim2 = anim;
	anim->priv = desc;

	/**
	 * pal
	 */
	LZ77UnCompWram(banim[desc->bid].pal, desc->pal_buf);
	CpuFastCopy(desc->pal_buf + PAL_OFFSET(desc->faction_pal), gPal + 0x10 * 0x10 + PAL_OFFSET(desc->oam2_pal), 0x20);
	desc->img_sheet = NULL; // ?
	EnablePalSync();
}

void EkrMainMini_UpdateAnim(struct EkrMainMiniDesc *desc)
{
	int mode1, mode2;
	struct Anim *anim;
	u8 *oam_buf;
	u32 *scr1, *scr2;
	struct BattleAnim *banim, *tmp_banim;
	u8 *scr_buf;
	int *modes;

	banim = gBanimTable;

	mode1 = BanimDefaultModeConfig[desc->round_type * 4 + 0];
	mode2 = BanimDefaultModeConfig[desc->round_type * 4 + 2];

	/**
	 * scr
	 */
	LZ77UnCompWram(banim[desc->bid].script, desc->scr_buf);

	tmp_banim = &banim[desc->bid];
	modes = tmp_banim->modes;
	scr_buf = desc->scr_buf;

	scr1 = AnimScr_DefaultAnim;
	if (mode1 != (u8)BANIM_MODE_INVALID)
		scr1 = (void *)(scr_buf + modes[mode1]);

	scr2 = AnimScr_DefaultAnim;
	if (mode2 != (u8)BANIM_MODE_INVALID)
		scr2 = (void *)(scr_buf + modes[mode2]);

	/**
	 * oam
	 */
	if (desc->pos == POS_L) {
		oam_buf = (u8 *)desc->oam_buf;

		LZ77UnCompWram(tmp_banim->oam_l, oam_buf);
		*(u32 *)(oam_buf + BAS_OAM_REF_MAX_SIZE) = 1;
	} else {
		oam_buf = (u8 *)desc->oam_buf;

		LZ77UnCompWram(tmp_banim->oam_r, oam_buf);
		*(u32 *)(oam_buf + BAS_OAM_REF_MAX_SIZE) = 1;
	}

	/**
	 * front anim
	 */
	anim = desc->anim1;
	anim->script = scr1;
	anim->scrCur = scr1;
	anim->sprDataPool = desc->oam_buf;
	anim->xPosition = desc->x;
	anim->yPosition = desc->y;
	anim->oam2 = (desc->oam2_pal * 0x1000) | OAM2_LAYER(2) | desc->oam2_chr;
	anim->flags2 &= ANIM_BIT2_FRONT_FRAME | ANIM_BIT2_POS_RIGHT | ANIM_BIT2_0400;
	anim->flags3 = 0;
	anim->timer = 0;
	anim->nextRoundId = 0;
	anim->currentRoundType = desc->round_type;
	anim->imgBuf = desc->img_buf;

	anim->cqSize = 0;
	desc->anim1 = anim;

	/**
	 * back anim
	 */
	anim = desc->anim2;
	anim->script = scr2;
	anim->scrCur = scr2;
	anim->sprDataPool = desc->oam_buf;
	anim->xPosition = desc->x;
	anim->yPosition = desc->y;
	anim->oam2 = (desc->oam2_pal * 0x1000) | OAM2_LAYER(2) | desc->oam2_chr;
	anim->flags2 &= ANIM_BIT2_FRONT_FRAME | ANIM_BIT2_POS_RIGHT | ANIM_BIT2_0400;
	anim->flags3 = 0;
	anim->timer = 0;
	anim->nextRoundId = 0;
	anim->currentRoundType = desc->round_type;
	anim->imgBuf = desc->img_buf;

	anim->cqSize = 0;
	desc->anim2 = anim;

	/**
	 * pal
	 */
	LZ77UnCompWram(banim[desc->bid].pal, desc->pal_buf);
	CpuFastCopy(desc->pal_buf + PAL_OFFSET(desc->faction_pal), gPal + 0x10 * 0x10 + PAL_OFFSET(desc->oam2_pal), 0x20);
	EnablePalSync();
}

void EkrMainMini_ChangeAnim(struct EkrMainMiniDesc *desc, int bid)
{
	desc->bid = bid;
	EkrMainMini_UpdateAnim(desc);
}

void EkrMainMini_SetAnimPosition(struct EkrMainMiniDesc *desc, u16 x, u16 y)
{
	struct Anim * anim;

	desc->x = x;
	desc->y = y;

	anim = desc->anim1;
	anim->xPosition = desc->x;
	anim->yPosition = desc->y;

	anim = desc->anim2;
	anim->xPosition = desc->x;
	anim->yPosition = desc->y;
}

void EkrMainMini_SetAnimLayer(struct EkrMainMiniDesc *desc, u16 layer)
{
	struct Anim * anim;

	anim = desc->anim1;
	anim->oam2 = layer << 10;

	anim = desc->anim2;
	anim->oam2 = layer << 10;
}

bool EkrMainMini_CheckBlocking(struct EkrMainMiniDesc *desc)
{
	struct Anim * anim1 = desc->anim1;
	struct Anim * anim2 = desc->anim2;

	if (anim1->nextRoundId == (u16)-2)
		return true;

	if (anim2->nextRoundId == (u16)-2)
		return true;

	return false;
}

void EkrMainMini_EndBlock(struct EkrMainMiniDesc *desc)
{
	struct Anim * anim;

	anim = desc->anim1;
	anim->flags3 |= ANIM_BIT3_C01_BLOCK_END_INBATTLE;

	anim = desc->anim2;
	anim->flags3 |= ANIM_BIT3_C01_BLOCK_END_INBATTLE;
}

bool EkrMainMini_CheckDone(struct EkrMainMiniDesc *desc)
{
	struct Anim * anim = desc->anim1;

	if (anim->nextRoundId != (u16)-1)
		return false;

	return true;
}

struct ProcScr CONST_DATA ProcScr_EfxAnimeDrv[] = {
	PROC_NAME_DEBUG("ekrAnimeDrvProc"),
	PROC_REPEAT(EkrAnimeDrv_Loop),
	PROC_END,
};

void NewEfxAnimeDrvProc(void)
{
	ProcPtr *pproc = &gpProcEfxAnimeDrv;

	*pproc = SpawnProc(ProcScr_EfxAnimeDrv, PROC_TREE_4);
	BasInit();
}

void EndEfxAnimeDrvProc(void)
{
	Proc_End(gpProcEfxAnimeDrv);
}

void EkrAnimeDrv_Loop(void)
{
	BasUpdateAll();
}

struct ProcScr CONST_DATA ProcScr_EkrUnitMainMini[] = {
	PROC_NAME_DEBUG("ekrUnitMainMini"),
	PROC_REPEAT(EkrMainMini_Loop),
	PROC_END,
};

void NewEkrUnitMainMini(struct EkrMainMiniDesc *desc)
{
	struct ProcEkrUnitMainMini * proc = SpawnProc(ProcScr_EkrUnitMainMini, PROC_TREE_4);

	EkrMainMini_InitAnim(desc);

	proc->desc = desc;
	desc->proc = proc;
	desc->valid = true;
}

void EndEkrMainMini(struct EkrMainMiniDesc *desc)
{
	BasRemove(desc->anim1);
	BasRemove(desc->anim2);

	desc->anim1 = 0;
	desc->anim2 = 0;

	Proc_End(desc->proc);
}

void EkrMainMini_Loop(struct ProcEkrUnitMainMini * proc)
{
	struct EkrMainMiniDesc *desc = proc->desc;

	EkrMainMini_ExecCommands(desc, desc->anim1);
	EkrMainMini_ExecCommands(desc, desc->anim2);
}
