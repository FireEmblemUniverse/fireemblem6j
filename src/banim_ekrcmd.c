#include "prelude.h"
#include "banim.h"
#include "item.h"
#include "faction.h"
#include "constants/iids.h"
#include "constants/banims.h"

const u16 RoundTypes_NormalPhy[EKR_DISTANCE_MAX] = {
	[EKR_DISTANCE_CLOSE]       = ANIM_ROUND_HIT_CLOSE,
	[EKR_DISTANCE_FAR]         = ANIM_ROUND_NONCRIT_FAR,
	[EKR_DISTANCE_FARFAR]      = ANIM_ROUND_NONCRIT_FAR,
	[EKR_DISTANCE_MONOCOMBAT]  = ANIM_ROUND_HIT_CLOSE,
	[EKR_DISTANCE_PROMOTION]   = ANIM_ROUND_HIT_CLOSE
};

const u16 RoundTypes_MissedPhy[EKR_DISTANCE_MAX] = {
	[EKR_DISTANCE_CLOSE]       = ANIM_ROUND_MISS_CLOSE,
	[EKR_DISTANCE_FAR]         = ANIM_ROUND_NONCRIT_FAR,
	[EKR_DISTANCE_FARFAR]      = ANIM_ROUND_NONCRIT_FAR,
	[EKR_DISTANCE_MONOCOMBAT]  = ANIM_ROUND_MISS_CLOSE,
	[EKR_DISTANCE_PROMOTION]   = ANIM_ROUND_MISS_CLOSE
};

const u16 RoundTypes_CriticalPhy[EKR_DISTANCE_MAX] = {
	[EKR_DISTANCE_CLOSE]       = ANIM_ROUND_CRIT_CLOSE,
	[EKR_DISTANCE_FAR]         = ANIM_ROUND_CRIT_FAR,
	[EKR_DISTANCE_FARFAR]      = ANIM_ROUND_CRIT_FAR,
	[EKR_DISTANCE_MONOCOMBAT]  = ANIM_ROUND_CRIT_CLOSE,
	[EKR_DISTANCE_PROMOTION]   = ANIM_ROUND_CRIT_CLOSE
};

const u16 RoundTypes_TargetMiss[EKR_DISTANCE_MAX] = {
	[EKR_DISTANCE_CLOSE]       = ANIM_ROUND_TAKING_MISS_CLOSE,
	[EKR_DISTANCE_FAR]         = ANIM_ROUND_TAKING_MISS_FAR,
	[EKR_DISTANCE_FARFAR]      = ANIM_ROUND_TAKING_MISS_FAR,
	[EKR_DISTANCE_MONOCOMBAT]  = ANIM_ROUND_TAKING_MISS_CLOSE,
	[EKR_DISTANCE_PROMOTION]   = ANIM_ROUND_TAKING_MISS_CLOSE
};

const u16 RoundTypes_TargetHitted[EKR_DISTANCE_MAX] = {
	[EKR_DISTANCE_CLOSE]       = ANIM_ROUND_TAKING_HIT_CLOSE,
	[EKR_DISTANCE_FAR]         = ANIM_ROUND_TAKING_HIT_FAR,
	[EKR_DISTANCE_FARFAR]      = ANIM_ROUND_TAKING_HIT_FAR,
	[EKR_DISTANCE_MONOCOMBAT]  = ANIM_ROUND_TAKING_HIT_CLOSE,
	[EKR_DISTANCE_PROMOTION]   = ANIM_ROUND_TAKING_HIT_CLOSE
};

const u16 RoundTypes_NormalMag[EKR_DISTANCE_MAX] = {
	[EKR_DISTANCE_CLOSE]       = ANIM_ROUND_NONCRIT_FAR,
	[EKR_DISTANCE_FAR]         = ANIM_ROUND_NONCRIT_FAR,
	[EKR_DISTANCE_FARFAR]      = ANIM_ROUND_NONCRIT_FAR,
	[EKR_DISTANCE_MONOCOMBAT]  = ANIM_ROUND_HIT_CLOSE,
	[EKR_DISTANCE_PROMOTION]   = ANIM_ROUND_HIT_CLOSE
};

const u16 RoundTypes_CriticalMag[EKR_DISTANCE_MAX] = {
	[EKR_DISTANCE_CLOSE]       = ANIM_ROUND_CRIT_FAR,
	[EKR_DISTANCE_FAR]         = ANIM_ROUND_CRIT_FAR,
	[EKR_DISTANCE_FARFAR]      = ANIM_ROUND_CRIT_FAR,
	[EKR_DISTANCE_MONOCOMBAT]  = ANIM_ROUND_CRIT_CLOSE,
	[EKR_DISTANCE_PROMOTION]   = ANIM_ROUND_CRIT_CLOSE
};

const u16 RoundTypes_Dragon1[EKR_DISTANCE_MAX] = {
	[EKR_DISTANCE_CLOSE]       = ANIM_ROUND_HIT_CLOSE,
	[EKR_DISTANCE_FAR]         = ANIM_ROUND_HIT_CLOSE,
	[EKR_DISTANCE_FARFAR]      = ANIM_ROUND_HIT_CLOSE,
	[EKR_DISTANCE_MONOCOMBAT]  = ANIM_ROUND_INVALID,
	[EKR_DISTANCE_PROMOTION]   = ANIM_ROUND_INVALID
};

const u16 RoundTypes_Dragon2[EKR_DISTANCE_MAX] = {
	[EKR_DISTANCE_CLOSE]       = ANIM_ROUND_NONCRIT_FAR,
	[EKR_DISTANCE_FAR]         = ANIM_ROUND_NONCRIT_FAR,
	[EKR_DISTANCE_FARFAR]      = ANIM_ROUND_NONCRIT_FAR,
	[EKR_DISTANCE_MONOCOMBAT]  = ANIM_ROUND_INVALID,
	[EKR_DISTANCE_PROMOTION]   = ANIM_ROUND_INVALID
};

const u16 RoundTypes_Dragon3[EKR_DISTANCE_MAX] = {
	[EKR_DISTANCE_CLOSE]       = ANIM_ROUND_CRIT_FAR,
	[EKR_DISTANCE_FAR]         = ANIM_ROUND_CRIT_FAR,
	[EKR_DISTANCE_FARFAR]      = ANIM_ROUND_CRIT_FAR,
	[EKR_DISTANCE_MONOCOMBAT]  = ANIM_ROUND_INVALID,
	[EKR_DISTANCE_PROMOTION]   = ANIM_ROUND_INVALID
};

const u8 BanimDefaultModeConfig[ANIM_ROUND_MAX * 4] = {
	/**
	 * 00: front mode
	 * 01: front priority
	 * 02: back mode
	 * 03: back priority
	*/

	/* ANIM_ROUND_HIT_CLOSE */
	BANIM_MODE_NORMAL_ATK, 0x64, BANIM_MODE_NORMAL_ATK_PRIORITY_L, 0x3C,

	/* ANIM_ROUND_CRIT_CLOSE */
	BANIM_MODE_CRIT_ATK, 0x64, BANIM_MODE_CRIT_ATK_PRIORITY_L, 0x3C,

	/* ANIM_ROUND_NONCRIT_FAR */
	BANIM_MODE_RANGED_ATK, 0x64, BANIM_MODE_INVALID, 0x3C,

	/* ANIM_ROUND_CRIT_FAR */
	BANIM_MODE_RANGED_CRIT_ATK, 0x64, BANIM_MODE_INVALID, 0x3C,

	/* ANIM_ROUND_TAKING_MISS_CLOSE */
	BANIM_MODE_CLOSE_DODGE, 0x28, BANIM_MODE_INVALID, 0x28,

	/* ANIM_ROUND_TAKING_MISS_FAR */
	BANIM_MODE_RANGED_DODGE, 0x28, BANIM_MODE_INVALID, 0x28,

	/* ANIM_ROUND_TAKING_HIT_CLOSE */
	BANIM_MODE_STANDING, 0x50, BANIM_MODE_INVALID, 0x28,

	/* ANIM_ROUND_STANDING */
	BANIM_MODE_STANDING2, 0x50, BANIM_MODE_INVALID, 0x28,

	/* ANIM_ROUND_TAKING_HIT_FAR */
	BANIM_MODE_RANGED_STANDING, 0x50, BANIM_MODE_INVALID, 0x28,

	/* ANIM_ROUND_MISS_CLOSE */
	BANIM_MODE_MISSED_ATK, 0x64, BANIM_MODE_INVALID, 0x28,
};

const u8 BanimDefaultStandingTypes[5] = {
	[EKR_DISTANCE_CLOSE]      = ANIM_ROUND_TAKING_HIT_CLOSE,
	[EKR_DISTANCE_FAR]        = ANIM_ROUND_TAKING_HIT_FAR,
	[EKR_DISTANCE_FARFAR]     = ANIM_ROUND_TAKING_HIT_FAR,
	[EKR_DISTANCE_MONOCOMBAT] = ANIM_ROUND_TAKING_HIT_CLOSE,
	[EKR_DISTANCE_PROMOTION]  = ANIM_ROUND_TAKING_HIT_CLOSE
};

const u8 BanimTypesPosLeft[5] = {
	[EKR_DISTANCE_CLOSE]      = 0x5C,
	[EKR_DISTANCE_FAR]        = 0x44,
	[EKR_DISTANCE_FARFAR]     = 0x44,
	[EKR_DISTANCE_MONOCOMBAT] = 0x78,
	[EKR_DISTANCE_PROMOTION]  = 0x5C
};

const u8 BanimTypesPosRight[5] = {
	[EKR_DISTANCE_CLOSE]      = 0x94,
	[EKR_DISTANCE_FAR]        = 0xAC,
	[EKR_DISTANCE_FARFAR]     = 0xAC,
	[EKR_DISTANCE_MONOCOMBAT] = 0x78,
	[EKR_DISTANCE_PROMOTION]  = 0x94
};

const u16 BanimLeftDefaultPos[5] = {
	[EKR_DISTANCE_CLOSE]      = 0x00,
	[EKR_DISTANCE_FAR]        = 0x20,
	[EKR_DISTANCE_FARFAR]     = 0xF0,
	[EKR_DISTANCE_MONOCOMBAT] = 0x00,
	[EKR_DISTANCE_PROMOTION]  = 0x00
};

const u16 Tsa_EkrTerrainfx_081122DA[] = {
	0x000, 0x000, 0x000, 0x000, 0x000,
	0x000, 0x000, 0x000, 0x000, 0x000,
	0x000, 0x000, 0x000, 0x000, 0x000,
	0x000, 0x000, 0x000, 0x000, 0x000,
	0x000, 0x000, 0x000, 0x000, 0x000,
	0x000, 0x000, 0x000, 0x000, 0x000,
	0x000, 0x000, 0x000, 0x000, 0x000,
	0x000, 0x000, 0x000, 0x000, 0x000,
	0x000, 0x000, 0x000, 0x000, 0x000,
	0x000, 0x000, 0x000, 0x000, 0x000,
	0x000, 0x000, 0x000, 0x000, 0x000,
	0x000, 0x000, 0x000, 0x000, 0x000,
	0x000, 0x000, 0x000, 0x000, 0x000,
	0x000, 0x000, 0x000, 0x000, 0x000,
	0x000, 0x000, 0x000, 0x000, 0x000,
};

void ParseBattleHitToBanimCmd(void)
{
	u32 i;
	u16 hpoff_l; // r7
	u16 hpoff_r; // r8
	u16 round_info[2]; // sp00
	struct BattleHit *hit; // sp04
	struct BattleUnit *bul_sp08;
	struct BattleUnit *bur_sp0C;
	i32 round; // sp10
	i32 is_target; // sp14
	i32 distance_sp18;
	i32 distance_sp1C;
	i32 is_dark_breath; // sp20

	hit = gBattleHits;
	gpEkrTriangleUnits[POS_L] = gpEkrTriangleUnits[POS_R] = NULL;

	if (gEkrDistanceType == EKR_DISTANCE_PROMOTION) {
		gAnimRoundData[POS_L] = ANIM_ROUND_TAKING_MISS_CLOSE;
		gAnimRoundData[POS_R] = ANIM_ROUND_TAKING_MISS_CLOSE;

		gAnimRoundData[2 + POS_L] = 0xFFFF;
		gAnimRoundData[2 + POS_R] = 0xFFFF;
		return;
	}

	if (gBattleSt.flags & BATTLE_FLAG_REFRESH) {
		gAnimRoundData[POS_L] = ANIM_ROUND_TAKING_HIT_CLOSE;
		gAnimRoundData[POS_R] = 0;

		gAnimRoundData[2 + POS_L] = 0xFFFF;
		gAnimRoundData[2 + POS_R] = 0xFFFF;
		return;
	}

	distance_sp18 = (u16)gEkrDistanceType;
	distance_sp1C = distance_sp18;

	is_dark_breath = false;

	bul_sp08 = gpEkrBattleUnitLeft;
	bur_sp0C = gpEkrBattleUnitRight;

	if (GetItemIid(bul_sp08->weapon_before) == IID_RUNESWORD  && distance_sp18 == ANIM_ROUND_HIT_CLOSE)
		distance_sp18 = EKR_DISTANCE_FAR;
	if (GetItemIid(bur_sp0C->weapon_before) == IID_RUNESWORD  && distance_sp1C == ANIM_ROUND_HIT_CLOSE)
		distance_sp1C = EKR_DISTANCE_FAR;

	if (GetItemIid(bul_sp08->weapon_before) == IID_HANDAXE    && distance_sp18 == ANIM_ROUND_HIT_CLOSE)
		distance_sp18 = EKR_DISTANCE_FAR;
	if (GetItemIid(bur_sp0C->weapon_before) == IID_HANDAXE    && distance_sp1C == ANIM_ROUND_HIT_CLOSE)
		distance_sp1C = EKR_DISTANCE_FAR;

	if (GetItemIid(bul_sp08->weapon_before) == IID_TOMAHAWK   && distance_sp18 == ANIM_ROUND_HIT_CLOSE)
		distance_sp18 = EKR_DISTANCE_FAR;
	if (GetItemIid(bur_sp0C->weapon_before) == IID_TOMAHAWK   && distance_sp1C == ANIM_ROUND_HIT_CLOSE)
		distance_sp1C = EKR_DISTANCE_FAR;

	if (GetItemIid(bul_sp08->weapon_before) == IID_FIRESTONE  && distance_sp18 == ANIM_ROUND_HIT_CLOSE)
		distance_sp18 = EKR_DISTANCE_FAR;

	if (GetItemIid(bul_sp08->weapon_before) == IID_DARKBREATH)
		is_dark_breath = true;

	for (i = 0; i < 20; i++)
		gAnimRoundData[i] = 0xFFFF;

	for (i = 0; i < 20; i++)
		gEfxHpLut[2 + i] = 0xFFFF;

	gEfxHpLut[0] = gEkrGaugeHp[0];
	gEfxHpLut[1] = gEkrGaugeHp[1];

	round = 0;
	hpoff_l = hpoff_r = 0;

	for (; (hit->info & BATTLE_HIT_INFO_END) == 0; hit++, round++) {
		i32 cur_is_dark_breath; // r3
		i16 act_distance; // r4
		u16 *act_round; // r5
		struct Unit *actor_unit; // r6
		u16 *tar_round; // r9
		i16 tar_distance; // sl

		if (hit->info & BATTLE_HIT_INFO_ACTORB)
			is_target = true;
		else
			is_target = false;

		if (gBanimPosIsTarget[POS_L] == is_target) {
			act_round = &round_info[POS_L];
			tar_round = &round_info[POS_R];
			act_distance = distance_sp18;
			tar_distance = distance_sp1C;
			actor_unit = &bul_sp08->unit;
			cur_is_dark_breath = is_dark_breath;

			if (round == 0)
				gEkrInitialHitSide = POS_L;
		} else {
			act_round = &round_info[POS_R];
			tar_round = &round_info[POS_L];
			act_distance = distance_sp1C;
			tar_distance = distance_sp18;
			actor_unit = &bur_sp0C->unit;
			cur_is_dark_breath = 0;

			if (round == 0)
				gEkrInitialHitSide = POS_R;
		}

		if (hit->attributes & BATTLE_HIT_ATTR_TRIANGLE_ATTACK) {
			gpEkrTriangleUnits[0] = gBattleSt.extra_unit_a;
			gpEkrTriangleUnits[1] = gBattleSt.extra_unit_b;
		}

		/* Check for attacker */
		if (hit->attributes & BATTLE_HIT_ATTR_CRIT) {
			if (!UnitKnowsMagic(actor_unit))
				*act_round = RoundTypes_CriticalPhy[act_distance];
			else
				*act_round = RoundTypes_CriticalMag[act_distance];
		} else if (cur_is_dark_breath == 0) {
			if (!UnitKnowsMagic(actor_unit))
				*act_round = RoundTypes_NormalPhy[act_distance];
			else
				*act_round = RoundTypes_NormalMag[act_distance];
		} else {
			// Idunn!
			switch (BanimSpawnRandB(2)) {
			case 0:
				*act_round = RoundTypes_Dragon1[act_distance];
				break;

			case 1:
				*act_round = RoundTypes_Dragon2[act_distance];
				break;

			case 2:
				*act_round = RoundTypes_Dragon3[act_distance];
				break;

			default:
				break;
			}
		}

		/* Check for defender */
		if (hit->attributes & BATTLE_HIT_ATTR_MISS)
		{
			/**
			 * Make sure to ignore critical anim?
			 */
			if (!UnitKnowsMagic(actor_unit))
				*act_round = RoundTypes_MissedPhy[act_distance];
			else
				*act_round = RoundTypes_NormalMag[act_distance];

			*tar_round = RoundTypes_TargetMiss[tar_distance];
		}
		else
		{
			*tar_round = RoundTypes_TargetHitted[tar_distance];
		}

		gAnimRoundData[ANIM_REF_OFFSET(round, POS_L)] = round_info[POS_L];
		tar_round = round_info;
		gAnimRoundData[ANIM_REF_OFFSET(round, POS_R)] = tar_round[round_info - tar_round + POS_R];

		if ((hit->attributes & BATTLE_HIT_ATTR_MISS) == 0) {
			i16 new_hp;
			if (hit->attributes & BATTLE_HIT_ATTR_DEVIL) {
				/* devil */
				if (gBanimPosIsTarget[POS_L] == is_target) {
					new_hp = GetEfxHp(ANIM_REF_OFFSET(hpoff_l, POS_L)) - hit->damage;

					if (new_hp < 0)
						new_hp = 0;

					hpoff_l++;
					gEfxHpLut[ANIM_REF_OFFSET(hpoff_l, POS_L)] = new_hp;
					gAnimRoundData[ANIM_REF_OFFSET(round, POS_L)] |= ANIM_ROUND_DEVIL;
				} else {
					new_hp = GetEfxHp(ANIM_REF_OFFSET(hpoff_r, POS_R)) - hit->damage;

					if (new_hp < 0)
						new_hp = 0;

					hpoff_r++;
					gEfxHpLut[ANIM_REF_OFFSET(hpoff_r, POS_R)] = new_hp;
					gAnimRoundData[ANIM_REF_OFFSET(round, POS_R)] |= ANIM_ROUND_DEVIL;
				}
			} else if (hit->attributes & BATTLE_HIT_ATTR_HPSTEAL) {
				/* nosferatu */
				if (gBanimPosIsTarget[POS_L] == is_target) {

					/* target */
					new_hp = GetEfxHp(ANIM_REF_OFFSET(hpoff_r, POS_R)) - hit->damage;
					if (new_hp < 0)
						new_hp = 0;

					hpoff_r++;
					gEfxHpLut[ANIM_REF_OFFSET(hpoff_r, POS_R)] = new_hp;

					/* actor */
					new_hp = GetEfxHp(ANIM_REF_OFFSET(hpoff_l, POS_L)) + hit->damage;
					if (new_hp > gBanimMaxHP[POS_L])
						new_hp = gBanimMaxHP[POS_L];

					hpoff_l++;
					gEfxHpLut[ANIM_REF_OFFSET(hpoff_l, POS_L)] = new_hp;
				} else {
					/* target */
					new_hp = GetEfxHp(ANIM_REF_OFFSET(hpoff_l, POS_L)) - hit->damage;
					if (new_hp < 0)
						new_hp = 0;

					hpoff_l++;
					gEfxHpLut[ANIM_REF_OFFSET(hpoff_l, POS_L)] = new_hp;

					/* actor */
					new_hp = GetEfxHp(ANIM_REF_OFFSET(hpoff_r, POS_R)) + hit->damage;
					if (new_hp > gBanimMaxHP[POS_R])
						new_hp = gBanimMaxHP[POS_R];

					hpoff_r++;
					gEfxHpLut[ANIM_REF_OFFSET(hpoff_r, POS_R)] = new_hp;
				}
			} else {
				/* normal */
				if (gBanimPosIsTarget[POS_L] == is_target) {
					new_hp = GetEfxHp(ANIM_REF_OFFSET(hpoff_r, POS_R)) - hit->damage;

					if (new_hp < 0)
						new_hp = 0;

					hpoff_r++;
					gEfxHpLut[ANIM_REF_OFFSET(hpoff_r, POS_R)] = new_hp;

					if (hit->attributes & BATTLE_HIT_ATTR_POISON)
						gAnimRoundData[ANIM_REF_OFFSET(round, POS_R)] |= ANIM_ROUND_POISON;

				} else {
					new_hp = GetEfxHp(ANIM_REF_OFFSET(hpoff_l, POS_L)) - hit->damage;

					if (new_hp < 0)
						new_hp = 0;

					hpoff_l++;
					gEfxHpLut[ANIM_REF_OFFSET(hpoff_l, POS_L)] = new_hp;

					if (hit->attributes & BATTLE_HIT_ATTR_POISON)
						gAnimRoundData[ANIM_REF_OFFSET(round, POS_L)] |= ANIM_ROUND_POISON;
				}
			}
		}
	}
}

bool CheckBattleHasHit(void)
{
	const struct BattleHit *hit = &gBattleHits[0];

	if (hit->info & BATTLE_HIT_INFO_FINISHES)
		return true;
	else
		return false;
}

int GetBanimUniquePal(struct Unit * unit)
{
	int idx = !!(UNIT_ATTRIBUTES(unit) & UNIT_ATTR_PROMOTED);

	return unit->pinfo->banim_pal[idx] - 1;
}

const u16 *GetBanimTriangleAttackPalette(i16 bid, u16 item)
{
	switch (bid) {
	case BANIM_67:
		switch (GetItemIid(item)) {
		case IID_BALLISTA:
			return Pal_08113FB8;

		case IID_LONGBALLISTA:
			return Pal_08113F98;

		case IID_KILLERBALLISTA:
			return Pal_08113FD8;

		default:
			return NULL;
		}
		break;

	default:
		return NULL;
	}
}

int GetBanimFactionPalette(u32 faction)
{
	u8 _faction = faction;

	switch (_faction) {
	case FACTION_RED:
		return BANIMPAL_RED;

	case FACTION_GREEN:
		return BANIMPAL_GREEN;

	case FACTION_PURPLE:
		return BANIMPAL_PURPLE;

	case FACTION_BLUE:
		return BANIMPAL_BLUE;
	}

	return BANIMPAL_BLUE;
}

void EkrPrepareBanimfx(struct Anim * anim, i16 index)
{
	gBanimIdx[GetAnimPosition(anim)] = index;
	UpdateBanimFrame();
	LoadAnimFrame(anim, ANIM_ROUND_TAKING_HIT_CLOSE);
}

i16 GetBattleAnimRoundType(int index)
{
	i16 * buf = (i16 *)gAnimRoundData;

	if (buf[index] == -1)
		return -1;
	else
		return buf[index] & (0xFFF);
}

i16 func_fe6_0804A57C(int index)
{
	i16 * buf = (i16 *)gAnimRoundData;

	if (buf[index] == -1)
		return 0;
	else
		return buf[index] & (~0xFFF);
}

i16 GetEfxHp(int index)
{
	return gEfxHpLut[index] & 0xFFF;
}

i16 func_fe6_0804A5C0(int index)
{
	i16 * buf = (i16 *)gEfxHpLut;

	return buf[index] & (~0xFFF);
}
