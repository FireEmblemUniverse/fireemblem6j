#include "prelude.h"
#include "proc.h"
#include "chapterinfo.h"
#include "spellassoc.h"
#include "gamedata.h"
#include "banim.h"
#include "banim_ekrbattle.h"
#include "banim_ekrdragon.h"
#include "constants/iids.h"
#include "constants/pids.h"
#include "constants/jids.h"
#include "constants/terrains.h"

EWRAM_DATA i16 gBanimExpPrevious[2] = {};
EWRAM_DATA i16 gBanimExpGain[2] = {};
EWRAM_DATA i16 gBanimTerrain[2] = {};
EWRAM_DATA i16 gBanimCon[2] = {};
EWRAM_DATA i16 gBanimWtaBonus[2] = {};
EWRAM_DATA i16 gBanimEffectiveness[2] = {};
EWRAM_DATA i16 gBanimUniquePaletteDisabled[2] = {};

static inline i16 GetBanimBattleActorPosition(int faction1, int faction2)
{
	int pos = POS_L;

	if (GetBanimLinkArenaFlag() != true) {
		if (BANIMPAL_BLUE == (i16)faction1)
			pos = POS_R;
		else if (BANIMPAL_GREEN == (i16)faction1)
			pos = POS_R;
		else if (BANIMPAL_RED == (i16)faction1 && BANIMPAL_RED == faction2)
			pos = POS_R;
	}
	return pos;
}

bool _SetupBanim(void)
{
	int zero;
	struct BattleUnit * bu1, * bu2;
	struct Unit * unit_bu2;
	const struct PInfo * pinfo1, * pinfo2;
	struct Unit * unit_bu1;
	int usrdefined_enable;
	const struct BanimInfoEnt * animdef1;
	const struct BanimInfoEnt * animdef2;
	i16 valid_l, valid_r;

	int char_cnt = 1;

	/* Judge arena */
	if (!(gBattleSt.flags & BATTLE_FLAG_ARENA))
		SetBanimArenaFlag(false);
	else
		SetBanimArenaFlag(true);

	/* Judge link-arena */
	if (!(gBmSt.flags & BM_FLAG_LINKARENA))
		SetBanimLinkArenaFlag(false);
	else
		SetBanimLinkArenaFlag(true);

	/* Judge promotion */
	if (gBattleSt.flags & BATTLE_FLAG_PROMOTE)
		gEkrDistanceType = EKR_DISTANCE_PROMOTION;
	else
		gEkrDistanceType = EKR_DISTANCE_CLOSE;

	if (gEkrDistanceType == EKR_DISTANCE_PROMOTION) {
		bu1 = gpEkrBattleUnitLeft = &gBattleUnitA;
		bu2 = gpEkrBattleUnitRight = &gBattleUnitB;

		gBanimPosIsTarget[POS_L] = gBanimPosIsTarget[POS_R] = false;
		gBanimValid[POS_R] = gBanimValid[POS_L] = true;
	} else {
		u8 fac1 = -0x40 & gBattleUnitA.unit.id;
		u16 fac_pal1 = GetBanimFactionPalette(fac1);
		u8 fac2 = -0x40 & gBattleUnitB.unit.id;
		u16 fac_pal2 = GetBanimFactionPalette(fac2);

		if (gBattleSt.flags & BATTLE_FLAG_REFRESH)
			char_cnt = 2;
		else if (gBattleUnitA.weapon_before == 0)
			char_cnt = 2;
		else
			char_cnt = GetSpellAssocCharCount(GetItemIid(gBattleUnitA.weapon_before));

		gBanimValid[POS_L] = gBanimValid[POS_R] = true;

		if (GetBanimBattleActorPosition(fac_pal1, fac_pal2) == POS_R) {
			bu1 = gpEkrBattleUnitLeft  = &gBattleUnitB;
			bu2 = gpEkrBattleUnitRight = &gBattleUnitA;

			gBanimPosIsTarget[POS_L] = true;
			gBanimPosIsTarget[POS_R] = false;

			if (char_cnt == 1)
				gBanimValid[POS_L] = false;
		} else {
			bu1 = gpEkrBattleUnitLeft  = &gBattleUnitA;
			bu2 = gpEkrBattleUnitRight = &gBattleUnitB;

			gBanimPosIsTarget[POS_L] = false;
			gBanimPosIsTarget[POS_R] = true;

			if (char_cnt == 1)
				gBanimValid[POS_R] = false;
		}
	}

	unit_bu1 = &bu1->unit;
	unit_bu2 = &bu2->unit;

	pinfo1 = unit_bu1->pinfo;
	pinfo2 = unit_bu2->pinfo;

	animdef2 = NULL;
	animdef1 = NULL;

	valid_l = gBanimValid[POS_L];
	valid_r = gBanimValid[POS_R];

	if (valid_l) animdef1 = unit_bu1->jinfo->banim_info;
	if (valid_r) animdef2 = unit_bu2->jinfo->banim_info;

	if (valid_l) {
		gEkrBmLocation[0] = (16 * unit_bu1->x - gBmSt.camera.x) >> 4;
		gEkrBmLocation[1] = (16 * unit_bu1->y - gBmSt.camera.y) >> 4;
	}

	if (valid_r) {
		gEkrBmLocation[2] = (16 * unit_bu2->x - gBmSt.camera.x) >> 4;
		gEkrBmLocation[3] = (16 * unit_bu2->y - gBmSt.camera.y) >> 4;
	}

	if (gEkrDistanceType != EKR_DISTANCE_PROMOTION) {
		if (GetItemAttributes(gBattleUnitA.weapon_before) & ITEM_ATTR_UNCOUNTERABLE)
			gEkrDistanceType = EKR_DISTANCE_FARFAR;
		else {
			gEkrDistanceType = EKR_DISTANCE_MONOCOMBAT;

			if (valid_l + valid_r == 2) {
				i16 x_distance, y_distance;
				x_distance = ABS(gEkrBmLocation[POS_L] - gEkrBmLocation[2]);
				y_distance = ABS(gEkrBmLocation[1] - gEkrBmLocation[3]);

				if (x_distance + y_distance <= 1)
					gEkrDistanceType = EKR_DISTANCE_CLOSE;
				else if (x_distance + y_distance <= 3)
					gEkrDistanceType = EKR_DISTANCE_FAR;
				else
					gEkrDistanceType = EKR_DISTANCE_FARFAR;
			}
		}
	}

	if (gEkrDistanceType == EKR_DISTANCE_PROMOTION) {
		gBanimIdx[POS_L] = gBanimIdx_bak[POS_L] = GetBattleAnimationId(animdef1, bu1->weapon);
		gBanimIdx[POS_R] = gBanimIdx_bak[POS_R] = GetBattleAnimationId(animdef2, bu2->weapon);
	} else {
		if (valid_l) gBanimIdx[POS_L] = gBanimIdx_bak[POS_L] = GetBattleAnimationId(animdef1, bu1->weapon_before);
		if (valid_r) gBanimIdx[POS_R] = gBanimIdx_bak[POS_R] = GetBattleAnimationId(animdef2, bu2->weapon_before);
	}

	if (valid_l)
		gBanimUniquePal[POS_L] = GetBanimUniquePal(unit_bu1);
	if (valid_r)
		gBanimUniquePal[POS_R] = GetBanimUniquePal(unit_bu2);

	if (valid_l) gpBanimTriAtkPalettes[POS_L] = GetBanimTriangleAttackPalette(gBanimIdx[POS_L], bu1->weapon_before);
	if (valid_r) gpBanimTriAtkPalettes[POS_R] = GetBanimTriangleAttackPalette(gBanimIdx[POS_R], bu2->weapon_before);

	gBanimTerrain[POS_L] = bu1->terrain;
	gBanimTerrain[POS_R] = bu2->terrain;

	gBanimFloorfx[POS_L] = gBanimFloorfx[POS_R] = -1;

	if (valid_l)
		gBanimFloorfx[POS_L] = GetBanimTerrainGround(bu1->terrain, GetChapterInfo(gPlaySt.chapter)->banim_terrain_id);
	if (valid_r)
		gBanimFloorfx[POS_R] = GetBanimTerrainGround(bu2->terrain, GetChapterInfo(gPlaySt.chapter)->banim_terrain_id);

	if (gBmSt.flags & BM_FLAG_LINKARENA) {
		gBanimTerrain[POS_R] = gBanimTerrain[POS_L] = TERRAIN_ARENA_30;

		if (valid_l)
			gBanimFloorfx[POS_L] = GetBanimTerrainGround(gBanimTerrain[POS_L], GetChapterInfo(gPlaySt.chapter)->banim_terrain_id);
		if (valid_r)
			gBanimFloorfx[POS_R] = GetBanimTerrainGround(gBanimTerrain[POS_R], GetChapterInfo(gPlaySt.chapter)->banim_terrain_id);
	}

	switch (gEkrDistanceType) {
	case EKR_DISTANCE_CLOSE:
	case EKR_DISTANCE_FAR:
	case EKR_DISTANCE_FARFAR:
	case EKR_DISTANCE_MONOCOMBAT:
		break;

	case EKR_DISTANCE_PROMOTION:
		gBanimFloorfx[POS_L] = gBanimFloorfx[POS_R];
		break;
	}

	switch (gPlaySt.weather) {
	case WEATHER_SNOW:
	case WEATHER_SNOWSTORM:
		gEkrSnowWeather = true;
		break;

	default:
		gEkrSnowWeather = false;
		break;
	}

	if (valid_l) gBanimCon[POS_L] = unit_bu1->jinfo->base_con;
	if (valid_r) gBanimCon[POS_R] = unit_bu2->jinfo->base_con;

	if (valid_l) {
		gEkrGaugeHp[POS_L] = bu1->previous_hp;
		gBanimMaxHP[POS_L] = unit_bu1->max_hp;
	}
	if (valid_r) {
		gEkrGaugeHp[POS_R] = bu2->previous_hp;
		gBanimMaxHP[POS_R] = unit_bu2->max_hp;
	}

	ParseBattleHitToBanimCmd();

	if (gEkrDistanceType == EKR_DISTANCE_PROMOTION) {
		gEkrSpellAnimIndex[POS_R] = 1;
		gEkrSpellAnimIndex[POS_L] = 1;
	} else {
		if (valid_l) gEkrSpellAnimIndex[POS_L] = GetSpellAnimId(unit_bu1->jinfo->id, bu1->weapon_before);
		if (valid_r) gEkrSpellAnimIndex[POS_R] = GetSpellAnimId(unit_bu2->jinfo->id, bu2->weapon_before);

		if (gBattleSt.flags & BATTLE_FLAG_REFRESH) {
			if (unit_bu2->jinfo->id == JID_BARD)
				gEkrSpellAnimIndex[POS_R] = 0xE; // todo: spell anim index
			if (unit_bu2->jinfo->id == JID_DANCER)
				gEkrSpellAnimIndex[POS_R] = 0xF; // todo: spell anim index
		}
	}

	if (valid_l)
		UnsetMapStaffAnim(&gEkrSpellAnimIndex[POS_L], 0, bu1->weapon_before);
	if (valid_r)
		UnsetMapStaffAnim(&gEkrSpellAnimIndex[POS_R], 1, bu2->weapon_before);

	*GetEkrDragonWeapon(POS_L) = 0;
	*GetEkrDragonWeapon(POS_R) = 0;

	switch (gEkrDistanceType) {
	case EKR_DISTANCE_CLOSE:
	case EKR_DISTANCE_FAR:
	case EKR_DISTANCE_FARFAR:
		if (valid_l && GetItemIid(bu1->weapon_before) == IID_FIRESTONE)
			*GetEkrDragonWeapon(POS_L) = IID_FIRESTONE;
		if (valid_r && GetItemIid(bu2->weapon_before) == IID_FIRESTONE)
			*GetEkrDragonWeapon(POS_R) = IID_FIRESTONE;

		if (valid_l && GetItemIid(bu1->weapon_before) == IID_DIVINESTONE)
			*GetEkrDragonWeapon(POS_L) = IID_DIVINESTONE;
		if (valid_r && GetItemIid(bu2->weapon_before) == IID_DIVINESTONE)
			*GetEkrDragonWeapon(POS_R) = IID_DIVINESTONE;

		if (valid_l && GetItemIid(bu1->weapon_before) == IID_DARKBREATH)
			*GetEkrDragonWeapon(POS_L) = IID_DARKBREATH;
		if (valid_r && GetItemIid(bu2->weapon_before) == IID_DARKBREATH)
			*GetEkrDragonWeapon(POS_R) = IID_DARKBREATH;

		break;

	case EKR_DISTANCE_MONOCOMBAT:
	case EKR_DISTANCE_PROMOTION:
		break;

	default:
		break;
	}

	if (valid_l) {
		u8 i1 = -0x40 & unit_bu1->id;

		gBanimFactionPal[POS_L] = GetBanimFactionPalette(i1);
	}

	if (valid_r) {
		u8 i2 = -0x40 & unit_bu2->id;

		gBanimFactionPal[POS_R] = GetBanimFactionPalette(i2);
	}

	/* pid */
	gEkrPids[POS_R] = 0;
	gEkrPids[POS_L] = 0;

	if (valid_l) gEkrPids[POS_L] = pinfo1->id;
	if (valid_r) gEkrPids[POS_R] = pinfo2->id;

	/* hit */
	if (valid_l) gEkrGaugeHit[POS_L] = bu1->battle_effective_hit;
	if (valid_r) gEkrGaugeHit[POS_R] = bu2->battle_effective_hit;

	if (gEkrGaugeHit[POS_L] == 0xFF) gEkrGaugeHit[POS_L] = -1;
	if (gEkrGaugeHit[POS_R] == 0xFF) gEkrGaugeHit[POS_R] = -1;

	/* dmg */
	if (valid_l) {
		gEkrGaugeDmg[POS_L] = bu1->battle_attack - bu2->battle_defense;
		if (gEkrGaugeDmg[POS_L] < 0)
			gEkrGaugeDmg[POS_L] = 0;

		if (bu1->battle_attack == 0xFF)
			gEkrGaugeDmg[POS_L] = -1;
	}

	if (valid_r) {
		gEkrGaugeDmg[POS_R] = bu2->battle_attack - bu1->battle_defense;
		if (gEkrGaugeDmg[POS_R] < 0)
			gEkrGaugeDmg[POS_R] = 0;

		if (bu2->battle_attack == 0xFF)
			gEkrGaugeDmg[POS_R] = -1;
	}

	/* crit */
	if (valid_l) gEkrGaugeCrt[POS_L] = bu1->battle_effective_crit;
	if (valid_r) gEkrGaugeCrt[POS_R] = bu2->battle_effective_crit;

	if (gEkrGaugeCrt[POS_L] == 0xFF) gEkrGaugeCrt[POS_L] = -1;
	if (gEkrGaugeCrt[POS_R] == 0xFF) gEkrGaugeCrt[POS_R] = -1;

	if (gEkrDistanceType == EKR_DISTANCE_PROMOTION) {
		gEkrGaugeHit[POS_R] = -1;
		gEkrGaugeDmg[POS_R] = -1;
		gEkrGaugeCrt[POS_R] = -1;
	}

	/* exp */
	if (valid_l) gBanimExpPrevious[POS_L] = (i8)(bu1->previous_exp); // needed explicit casts
	if (valid_r) gBanimExpPrevious[POS_R] = (i8)(bu2->previous_exp); // needed explicit casts

	if (valid_l) gBanimExpGain[POS_L] = bu1->exp_gain;
	if (valid_r) gBanimExpGain[POS_R] = bu2->exp_gain;

	/* WTA */
	gBanimWtaBonus[POS_R] = 0;
	gBanimWtaBonus[POS_L] = 0;

	if (valid_l) gBanimWtaBonus[POS_L] = bu1->advantage_bonus_hit;
	if (valid_r) gBanimWtaBonus[POS_R] = bu2->advantage_bonus_hit;

	gBanimEffectiveness[POS_L] = gBanimEffectiveness[POS_R] = false;

	if (valid_l) gBanimEffectiveness[POS_L] = IsItemEffectiveAgainst(bu1->weapon, unit_bu2);
	if (valid_r) gBanimEffectiveness[POS_R] = IsItemEffectiveAgainst(bu2->weapon, unit_bu1);

	/* Force display ballista anim */
	gBanimBallistaImages[POS_L] = gBanimBallistaImages[POS_R] =  0;;

	if (valid_l) {
		switch (GetItemIid(bu1->weapon_before)) {
		case IID_BALLISTA:
		case IID_LONGBALLISTA:
		case IID_KILLERBALLISTA:
			switch (UNIT_JID(unit_bu1)) {
			case JID_ARCHER_F:
				gBanimBallistaImages[POS_L] = Img_BanimArcherFBallistaIntro;
				break;

			case JID_SNIPER:
				gBanimBallistaImages[POS_L] = Img_BanimArcherMBallistaIntro;
				break;

			case JID_SNIPER_F:
				gBanimBallistaImages[POS_L] = Img_BanimSnipperFBallistaIntro;
				break;

			case JID_ARCHER:
			default:
				break;
			}
			break;


		default:
			break;
		}
	}

	if (valid_r) {
		switch (GetItemIid(bu2->weapon_before)) {
		case IID_BALLISTA:
		case IID_LONGBALLISTA:
		case IID_KILLERBALLISTA:
			switch (UNIT_JID(unit_bu2)) {
			case JID_ARCHER_F:
				gBanimBallistaImages[POS_R] = Img_BanimArcherFBallistaIntro;
				break;

			case JID_SNIPER:
				gBanimBallistaImages[POS_R] = Img_BanimArcherMBallistaIntro;
				break;

			case JID_SNIPER_F:
				gBanimBallistaImages[POS_R] = Img_BanimSnipperFBallistaIntro;
				break;

			case JID_ARCHER:
			default:
				break;
			}
			break;

		default:
			break;
		}
	}

	/* Unique palette EN */
	if (GetBanimLinkArenaFlag() == true || gPlaySt.config_unique_pal)
		gBanimUniquePaletteDisabled[POS_L] = gBanimUniquePaletteDisabled[POS_R] = 1;
	else
		gBanimUniquePaletteDisabled[POS_L] = gBanimUniquePaletteDisabled[POS_R] = zero = 0;

	++zero; --zero; // :/

	/* BG */
	gBanimBG = 0;
	if (GetBattleAnimType() == PLAY_ANIMCONF_ON_UNIQUE_BG)
	{
		if (gBanimValid[POS_L] != false)
			gBanimBG = GetBanimBackgroundIndex(gBanimTerrain[POS_L], GetChapterInfo(gPlaySt.chapter)->banim_terrain_id);
		else
			gBanimBG = GetBanimBackgroundIndex(gBanimTerrain[POS_R], GetChapterInfo(gPlaySt.chapter)->banim_terrain_id);
	}

	usrdefined_enable = false;
	if (GetBattleAnimType() == PLAY_ANIMCONF_ON)
		usrdefined_enable = true;
	if (GetBattleAnimType() == PLAY_ANIMCONF_ON_UNIQUE_BG)
		usrdefined_enable = true;
	if (GetBattleAnimType() == PLAY_ANIMCONF_OFF) {
		/**
		 * Banim can also display regardless used-configuration
		 * in the following case:
		 *
		 * 1. promotion
		 * 2. arena
		 * 2. hardcoded specific person...
		 */
		if (gEkrDistanceType == EKR_DISTANCE_PROMOTION)
			usrdefined_enable = true;

		if (GetBattleAnimArenaFlag() == true)
			usrdefined_enable = true;

		if (UNIT_PID(unit_bu1) == PID_ZEPHIEL && gBanimFactionPal[POS_L] != BANIMPAL_BLUE)
			usrdefined_enable = true;

		if (UNIT_PID(unit_bu2) == PID_ZEPHIEL && gBanimFactionPal[POS_R] != BANIMPAL_BLUE)
			usrdefined_enable = true;
	}

	if (UNIT_PID(unit_bu1) == PID_MERLINUS) return false;
	if (UNIT_PID(unit_bu2) == PID_MERLINUS) return false;

	if (char_cnt != 1 && UNIT_PID(unit_bu1) == PID_IDUNN_DRAGON)
		return true;

	if (usrdefined_enable == false)
		return false;

	if (gBanimValid[POS_L] == true) {
		if (unit_bu1->status == UNIT_STATUS_BERSERK)
			return false;

		if (gBanimIdx[POS_L] == -1)
			return false;

		if (gEkrSpellAnimIndex[POS_L] == -2)
			return false;

		if (gBanimFloorfx[POS_L] == -1)
			return false;

		if (gBanimTerrain[POS_L] == TERRAIN_WALL_BREAKABLE)
			return false;
	}

	if (gBanimValid[POS_R] == true) {
		if (unit_bu2->status == UNIT_STATUS_BERSERK)
			return false;

		if (gBanimIdx[POS_R] == -1)
			return false;

		if (gEkrSpellAnimIndex[POS_R] == -2)
			return false;

		if (gBanimFloorfx[POS_R] == -1)
			return false;

		if (gBanimTerrain[POS_R] == TERRAIN_WALL_BREAKABLE)
			return false;
	}

	return true;
}

/* https://decomp.me/scratch/eHa2J */
#if NONMATCHING
u16 GetBattleAnimationId(const struct BanimInfoEnt * animdef, u16 item)
{
	int i, found;
	u16 itype;
	int ret = 0;

	if (animdef == NULL || GetItemKind(item) == ITEM_KIND_ITEM)
		return -1;

	if (item == 0)
		itype = ITEM_KIND_ITEM;
	else
		itype = GetItemKind(item);


	for (i = 0, found = false; i < 2; i++) {
		const struct BanimInfoEnt *it;

		for (it = animdef; it->wtype != 0; it++) {
			if (i == 0 && it->wtype >= 0x100) {
				/* round 0: skip wtype judgement */
				continue;
			}

			if (i == 1 && it->wtype < 0x100) {
				/* round 1: skip specific weapon judgement */
				continue;
			}

			if (it->wtype == GetItemIid(item) || (it->wtype - 0x100) == itype) {
				ret = it->index;
				found = true;
				break;
			}
		}

		if (found == true)
			break;
	}

	return (ret - 1);
}
#else

NAKEDFUNC
u16 GetBattleAnimationId(const struct BanimInfoEnt * animdef, u16 item)
{
asm("\
	.syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #4\n\
	mov sl, r0\n\
	lsls r1, r1, #0x10\n\
	lsrs r1, r1, #0x10\n\
	mov r8, r1\n\
	movs r0, #0\n\
	mov sb, r0\n\
	mov r2, sl\n\
	cmp r2, #0\n\
	beq .L08049BD4\n\
	mov r0, r8\n\
	bl GetItemKind\n\
	cmp r0, #9\n\
	bne .L08049BDC\n\
.L08049BD4:\n\
	ldr r0, .L08049BD8 @ =0x0000FFFF\n\
	b .L08049C4A\n\
	.align 2, 0\n\
.L08049BD8: .4byte 0x0000FFFF\n\
.L08049BDC:\n\
	mov r3, r8\n\
	cmp r3, #0\n\
	bne .L08049BE6\n\
	movs r1, #9\n\
	b .L08049BF0\n\
.L08049BE6:\n\
	mov r0, r8\n\
	bl GetItemKind\n\
	lsls r0, r0, #0x10\n\
	lsrs r1, r0, #0x10\n\
.L08049BF0:\n\
	movs r6, #0\n\
	movs r7, #0\n\
.L08049BF4:\n\
	mov r5, sl\n\
	b .L08049C32\n\
.L08049BF8:\n\
	cmp r6, #0\n\
	bne .L08049C00\n\
	cmp r0, #0xff\n\
	bhi .L08049C30\n\
.L08049C00:\n\
	cmp r6, #1\n\
	bne .L08049C0A\n\
	ldrh r0, [r5]\n\
	cmp r0, #0xff\n\
	bls .L08049C30\n\
.L08049C0A:\n\
	ldrh r4, [r5]\n\
	mov r0, r8\n\
	str r1, [sp]\n\
	bl GetItemIid\n\
	ldr r1, [sp]\n\
	cmp r4, r0\n\
	beq .L08049C24\n\
	ldrh r2, [r5]\n\
	ldr r3, .L08049C2C @ =0xFFFFFF00\n\
	adds r0, r2, r3\n\
	cmp r0, r1\n\
	bne .L08049C30\n\
.L08049C24:\n\
	ldrh r5, [r5, #2]\n\
	mov sb, r5\n\
	movs r7, #1\n\
	b .L08049C38\n\
	.align 2, 0\n\
.L08049C2C: .4byte 0xFFFFFF00\n\
.L08049C30:\n\
	adds r5, #4\n\
.L08049C32:\n\
	ldrh r0, [r5]\n\
	cmp r0, #0\n\
	bne .L08049BF8\n\
.L08049C38:\n\
	cmp r7, #1\n\
	beq .L08049C42\n\
	adds r6, #1\n\
	cmp r6, #1\n\
	ble .L08049BF4\n\
.L08049C42:\n\
	mov r0, sb\n\
	subs r0, #1\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
.L08049C4A:\n\
	add sp, #4\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
	.syntax divided\n\
");
}
#endif

int GetBanimTerrainGround(u16 terrain, u16 tileset)
{
	int ret;

	// todo: tileset index
	switch (tileset) {
	case BANIM_TERRAIN_SET_1:
		ret = Terrain_BanimUnk_0860CC42[terrain];
		break;

	case BANIM_TERRAIN_SET_2:
		ret = Terrain_BanimUnk_0860CC75[terrain];
		break;

	case BANIM_TERRAIN_SET_3:
		ret = Terrain_BanimUnk_0860CCA8[terrain];
		break;

	case BANIM_TERRAIN_SET_4:
		ret = Terrain_BanimUnk_0860CCDB[terrain];
		break;

	case BANIM_TERRAIN_SET_5:
		ret = Terrain_BanimUnk_0860CD0E[terrain];
		break;

	case BANIM_TERRAIN_SET_6:
		ret = Terrain_BanimUnk_0860CD41[terrain];
		break;

	case BANIM_TERRAIN_SET_7:
		ret = Terrain_BanimUnk_0860CD74[terrain];
		break;

	case BANIM_TERRAIN_SET_8:
		ret = Terrain_BanimUnk_0860CDA7[terrain];
		break;

	case BANIM_TERRAIN_SET_9:
		ret = Terrain_BanimUnk_0860CDDA[terrain];
		break;

	case BANIM_TERRAIN_SET_0:
	default:
		ret = Terrain_BanimUnk_0860CC0F[terrain];
		break;
	}

	return ret - 1;
}

int GetBanimBackgroundIndex(u16 terrain, u16 tileset)
{
	int ret;

	// todo: tileset index
	switch (tileset) {
	case 0x01:
		return Terrain_BanimUnk_0860CE40[terrain];

	case 0x02:
		return Terrain_BanimUnk_0860CE73[terrain];

	case 0x03:
		return Terrain_BanimUnk_0860CEA6[terrain];

	case 0x04:
		return Terrain_BanimUnk_0860CED9[terrain];

	case 0x05:
		return Terrain_BanimUnk_0860CF0C[terrain];

	case 0x06:
		return Terrain_BanimUnk_0860CF3F[terrain];

	case 0x07:
		return Terrain_BanimUnk_0860CF72[terrain];

	case 0x08:
		return Terrain_BanimUnk_0860CFA5[terrain];

	case 0x09:
		return Terrain_BanimUnk_0860CFD8[terrain];

	case 0:
	default:
		return Terrain_BanimUnk_0860CE0D[terrain];
	}
}

static inline const struct SpellAssoc *_GetSpellAssoc(u16 item)
{
	u16 iid = GetItemIid(item);
	const struct SpellAssoc *it;

	for (it = gSpellAssoc; it->item != 0xFFFF; it++)
		if (it->item == iid)
			break;

	return it;
}

i16 GetSpellAnimId(u16 jid, u16 weapon)
{
	u16 ret;
	const struct SpellAssoc *spell_assoc = _GetSpellAssoc(weapon);

	ret = spell_assoc->efx;
	if (spell_assoc->efx == EFXMAGIC_JAVELIN) {
		switch (jid) {
		case JID_CAVALIER:
		case JID_CAVALIER_F:
			ret = EFXMAGIC_JAVELIN_CAVALIER;
			break;

		case JID_SOLDIER:
			ret = EFXMAGIC_JAVELIN_SOILDER;
			break;

		case JID_PALADIN:
		case JID_PALADIN_F:
			ret = EFXMAGIC_JAVELIN_PALADIN;
			break;

		case JID_PEGASUSKNIGHT:
			ret = EFXMAGIC_JAVELIN_PEGASUSKNIGHT;
			break;

		case JID_FALCONKNIGHT:
			ret = EFXMAGIC_JAVELIN_FALCON;
			break;

		case JID_WYVERNRIDER:
		case JID_WYVERNRIDER_F:
			ret = EFXMAGIC_JAVELIN_WYVERNRIDER;
			break;

		case JID_WYVERNLORD:
		case JID_WYVERNLORD_F:
			ret = EFXMAGIC_JAVELIN_WYVERNLORD;
			break;

		case JID_GENERAL:
		case JID_GENERAL_F:
			ret = EFXMAGIC_JAVELIN_GENERAL;
			break;

		default:
			break;
		}
	}
	return ret;
}

void UnsetMapStaffAnim(i16 *out, u16 pos, u16 weapon)
{
	u16 iid = GetItemIid(weapon);

	if (*out == -1)
		*out = 0;

	if (gEkrInitialHitSide == pos)
		return;

	switch (iid) {
	case IID_WARPSTAFF:
	case IID_RESCUESTAFF:
	case IID_TORCHSTAFF:
	case IID_WATCHSTAFF:
	case IID_UNLOCKSTAFF:
		*out = 0;
	}
}
