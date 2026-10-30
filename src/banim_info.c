#include "prelude.h"
#include "banim.h"
#include "banim_ekrdragon.h"

void LoadAnimFrame(struct Anim *anim, int type)
{
	u32 frame, priority;
	const u32 *scr;

	if (GetAnimLayer(anim) == 0) {
		frame    = BanimDefaultModeConfig[4 * type + 0];
		priority = BanimDefaultModeConfig[4 * type + 1];
	} else {
		frame    = BanimDefaultModeConfig[4 * type + 2];
		priority = BanimDefaultModeConfig[4 * type + 3];
	}

	if (frame != 0xFF) {
		if (GetAnimPosition(anim) == POS_L) {
			// use r1 for scr
			scr = gpBanimModesLeft;
			scr = (void *)(gBanimScrs + scr[frame]);
		} else {
			scr = (void *)(gBanimScrs + BAS_SCR_MAX_SIZE + gpBanimModesRight[frame]);
		}
		anim->script = scr;
		anim->scrCur = scr;
	} else {
		anim->script = AnimScr_DefaultAnim;
		anim->scrCur = AnimScr_DefaultAnim;
		anim->flags3 = 0;
	}

	anim->priority = priority;
	anim->oam2 &= ~0xC00;
	anim->oam2 |= 0x800;
	anim->timer = 0;
	anim->flags2 &= ANIM_BIT2_FRONT_FRAME | ANIM_BIT2_POS_RIGHT | ANIM_BIT2_0400;
	anim->currentRoundType = type;
	anim->cqSize = 0;
	anim->sprDataPool = gBanimOamBufs + GetAnimPosition(anim) * BAS_OAM_MAX_SIZE;
	BasSort();
}

int GetAnimLayer(struct Anim *anim)
{
	if (!(anim->flags2 & ANIM_BIT2_FRONT_FRAME))
		return 0;

	return 1;
}

int GetAnimPosition(struct Anim *anim)
{
	if (!(anim->flags2 & ANIM_BIT2_POS_RIGHT))
		return POS_L;

	return POS_R;
}

int CheckRoundMiss(i16 type)
{
	switch(type) {
	case ANIM_ROUND_TAKING_MISS_CLOSE:
	case ANIM_ROUND_TAKING_MISS_FAR:
		return true;

	case ANIM_ROUND_HIT_CLOSE:
	case ANIM_ROUND_CRIT_CLOSE:
	case ANIM_ROUND_NONCRIT_FAR:
	case ANIM_ROUND_CRIT_FAR:
	case ANIM_ROUND_TAKING_HIT_CLOSE:
	case ANIM_ROUND_STANDING:
	case ANIM_ROUND_TAKING_HIT_FAR:
	case ANIM_ROUND_MISS_CLOSE:
	default:
		return false;
	}
}

int CheckRound1(i16 type)
{
	switch(type) {
	case ANIM_ROUND_TAKING_HIT_CLOSE:
	case ANIM_ROUND_STANDING:
	case ANIM_ROUND_TAKING_HIT_FAR:
		return true;

	case ANIM_ROUND_HIT_CLOSE:
	case ANIM_ROUND_CRIT_CLOSE:
	case ANIM_ROUND_NONCRIT_FAR:
	case ANIM_ROUND_CRIT_FAR:
	case ANIM_ROUND_TAKING_MISS_CLOSE:
	case ANIM_ROUND_TAKING_MISS_FAR:
	case ANIM_ROUND_MISS_CLOSE:
	default:
		return false;
	}
}

int CheckRound2(i16 type)
{
	switch(type) {
	case ANIM_ROUND_HIT_CLOSE:
	case ANIM_ROUND_CRIT_CLOSE:
	case ANIM_ROUND_NONCRIT_FAR:
	case ANIM_ROUND_CRIT_FAR:
	case ANIM_ROUND_MISS_CLOSE:
		return true;

	case ANIM_ROUND_TAKING_MISS_CLOSE:
	case ANIM_ROUND_TAKING_MISS_FAR:
	case ANIM_ROUND_TAKING_HIT_CLOSE:
	case ANIM_ROUND_STANDING:
	case ANIM_ROUND_TAKING_HIT_FAR:
	default:
		return false;
	}
}


int CheckRoundCrit(struct Anim *anim)
{
	switch(anim->currentRoundType) {
	case ANIM_ROUND_CRIT_FAR:
		if ((GetAnimPosition(anim) == POS_L) && (GetEkrDragonStateTypeIdunn() != 0))
			return false;

		/* fall through */

	case ANIM_ROUND_CRIT_CLOSE:
		return true;

	case ANIM_ROUND_HIT_CLOSE:
	case ANIM_ROUND_NONCRIT_FAR:
	case ANIM_ROUND_TAKING_MISS_CLOSE:
	case ANIM_ROUND_TAKING_MISS_FAR:
	case ANIM_ROUND_TAKING_HIT_CLOSE:
	case ANIM_ROUND_STANDING:
	case ANIM_ROUND_TAKING_HIT_FAR:
	case ANIM_ROUND_MISS_CLOSE:
	default:
		return false;
	}
}

struct Anim *GetAnimAnotherSide(struct Anim *anim)
{
	return gAnims[(1 ^ GetAnimPosition(anim)) * 2];
}

i16 GetAnimRoundType(struct Anim *anim)
{
	return GetBattleAnimRoundType((anim->nextRoundId - 1) * 2 + GetAnimPosition(anim));
}

i16 GetAnimNextRoundType(struct Anim *anim)
{
	return GetBattleAnimRoundType(anim->nextRoundId * 2 + GetAnimPosition(anim));
}

i16 GetAnimRoundTypeAnotherSide(struct Anim *anim)
{
	return GetBattleAnimRoundType((anim->nextRoundId - 1) * 2 + (1 ^ GetAnimPosition(anim)));
}

i16 GetAnimNextRoundTypeAnotherSide(struct Anim *anim)
{
	return GetBattleAnimRoundType(anim->nextRoundId * 2 + (1 ^ GetAnimPosition(anim)));
}

void SetAnimStateHidden(int pos)
{
	if (pos == POS_L) {
		struct Anim *anim;

		anim = gAnims[0];
		anim->flags |= BAS_BIT_HIDDEN;

		anim = gAnims[1];
		anim->flags |= BAS_BIT_HIDDEN;
		return;
	}

	if (pos == POS_R) {
		struct Anim *anim;

		anim = gAnims[2];
		anim->flags |= BAS_BIT_HIDDEN;

		anim = gAnims[3];
		anim->flags |= BAS_BIT_HIDDEN;
		return;
	}
}

void SetAnimStateUnHidden(int pos)
{
	if (pos == POS_L) {
		struct Anim *anim;

		anim = gAnims[0];
		anim->flags &= ~BAS_BIT_HIDDEN;

		anim = gAnims[1];
		anim->flags &= ~BAS_BIT_HIDDEN;
		return;
	}

	if (pos == POS_R) {
		struct Anim *anim;

		anim = gAnims[2];
		anim->flags &= ~BAS_BIT_HIDDEN;

		anim = gAnims[3];
		anim->flags &= ~BAS_BIT_HIDDEN;
		return;
	}
}
