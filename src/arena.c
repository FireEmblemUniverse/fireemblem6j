
#include "arena.h"

#include "random.h"
#include "item.h"
#include "unit.h"
#include "faction.h"
#include "battle.h"
#include "action.h"
#include "save_stats.h"
#include "save_game.h"

#include "constants/jids.h"
#include "constants/pids.h"
#include "constants/iids.h"

struct ArenaSt EWRAM_DATA gArenaSt = {};
struct Unit EWRAM_DATA gArenaOpponent = {};

#include "data/arena_jids.h"

void ArenaBeginInternal(struct Unit * unit)
{
    int i;

    gArenaSt.player = unit;
    gArenaSt.opponent = &gArenaOpponent;

    gArenaSt.player_jid = unit->jinfo->id;
    gArenaSt.player_weapon_kind = ArenaGetUnitWeaponKind(unit);

    gArenaSt.opponent_jid = ArenaGenOpposingJid(gArenaSt.player_weapon_kind);
    gArenaSt.opponent_weapon_kind = ArenaGetJobWeaponKind(GetJInfo(gArenaSt.opponent_jid));

    gArenaSt.player_is_magic = ArenaIsMagicWeaponKind(gArenaSt.player_weapon_kind);
    gArenaSt.opponent_is_magic = ArenaIsMagicWeaponKind(gArenaSt.opponent_weapon_kind);

    gArenaSt.player_level = unit->level;
    gArenaSt.opponent_level = ArenaGetOpposingLevel(gArenaSt.player_level);

    ArenaGenOpponentUnit();
    ArenaGenBaseWeapons();

    for (i = 0; i < 10; ++i)
        if (!ArenaAdjustOpponentPowerRanking())
            break;

    for (i = 0; i < 5; ++i)
        if (!ArenaAdjustOpponentDamage())
            break;

    gArenaSt.player_power_ranking = ArenaGetPowerRanking(gArenaSt.player, gArenaSt.opponent_is_magic);
    gArenaSt.opponent_power_ranking = ArenaGetPowerRanking(gArenaSt.opponent, gArenaSt.player_is_magic);

    ArenaGenMatchupGoldValue();

    gArenaSt.unk_0B = 1;

    ArenaSetResult(ARENA_RESULT_0);
}

void ArenaBegin(struct Unit * unit)
{
    RandGetSt(gAction.arena_begin_rand_st);
    ArenaBeginInternal(unit);
}

void ArenaResume(struct Unit * unit)
{
    RandSetSt(gAction.arena_begin_rand_st);
    ArenaBeginInternal(unit);
    RandSetSt(gAction.action_rand_st);
}

int ArenaGetUnitWeaponKind(struct Unit * unit)
{
    int i;

    int wexp = 0;
    int kind = -1;

    for (i = 0; i < UNIT_WEAPON_EXP_COUNT; ++i)
    {
        if (i == ITEM_KIND_STAFF)
            continue;

        if (wexp < unit->wexp[i])
        {
            wexp = unit->wexp[i];
            kind = i;
        }
    }

    return kind;
}

int ArenaGetJobWeaponKind(struct JInfo const * jinfo)
{
    int i;

    int wexp = 0;
    int kind = -1;

    for (i = 0; i < UNIT_WEAPON_EXP_COUNT; ++i)
    {
        if (i == ITEM_KIND_STAFF)
            continue;

        if (wexp < jinfo->wexp[i])
        {
            wexp = jinfo->wexp[i];
            kind = i;
        }
    }

    return kind;
}

int ArenaGenOpposingJid(int weapon_kind)
{
    int promoteflag;
    int jobnum, i;

    int jobcount = 0;
    u8 const * joblist = NULL;

    switch (weapon_kind)
    {

    case ITEM_KIND_SWORD:
    case ITEM_KIND_LANCE:
    case ITEM_KIND_AXE:
        joblist = JList_MeleeArena;
        break;

    case ITEM_KIND_BOW:
        joblist = JList_RangedArena;
        break;

    case ITEM_KIND_ANIMA:
    case ITEM_KIND_LIGHT:
    case ITEM_KIND_ELDER:
        joblist = JList_MagicArena;
        break;

    }

    promoteflag = UNIT_ATTRIBUTES(gArenaSt.player) & UNIT_ATTR_PROMOTED;

    // Iterating through the list is done by skipping jobs that aren't of the same tier as the player's jinfo
    // Therefore we are working with a logical sub-list that omits the skipped jobs

    // First, we iterate through this logical sub-list once to count the number of jobs it contains.

    for (i = 0; joblist[i] != 0; ++i)
    {
        if ((GetJInfo(joblist[i])->attributes & UNIT_ATTR_PROMOTED) != promoteflag)
            continue; // skip jobs that aren't of the same tier as player

        ++jobcount;
    }

    // We then choose one of the jobs in the sub-list randomly

    jobnum = RandNext(jobcount);

    // Then, since we can't access elements of that sub-list via indexes directly, we need to iterate again
    // This time, we count up to jobnum and when we reach that we have the jinfo we want

    for (i = 0, jobcount = 0; TRUE; ++i)
    {
        if ((GetJInfo(joblist[i])->attributes & UNIT_ATTR_PROMOTED) != promoteflag)
            continue; // skip jobs that aren't of the same tier as player

        if (jobcount == jobnum)
            break; // we reached the jinfo we want

        ++jobcount;
    }

    return joblist[i];
}

bool ArenaIsMagicWeaponKind(int weapon_kind)
{
    switch (weapon_kind)
    {

    case ITEM_KIND_SWORD:
    case ITEM_KIND_LANCE:
    case ITEM_KIND_AXE:
    case ITEM_KIND_BOW:
        return FALSE;

    case ITEM_KIND_ANIMA:
    case ITEM_KIND_LIGHT:
    case ITEM_KIND_ELDER:
        return TRUE;

#if BUGFIX
    default:
        return FALSE;
#endif

    }
}

int ArenaGetOpposingLevel(int level)
{
    enum { LEVEL_VARIANCE = 4 };

    int result = level + RandNext(1 + 2*LEVEL_VARIANCE) - LEVEL_VARIANCE;

    if (result < 1)
        result = 1;

    return result;
}

int ArenaGetPowerRanking(struct Unit * unit, bool opponent_is_magic)
{
    int result = unit->max_hp;

    result += unit->max_hp;
    result += unit->pow*2;
    result += unit->skl*2;
    result += unit->spd*2;
    result += unit->lck;
    result += UNIT_CON_BASE(unit);

    if (opponent_is_magic)
        result += GetUnitResistance(unit)*2;
    else
        result += GetUnitDefense(unit)*2;

    if (UNIT_ATTRIBUTES(unit) & UNIT_ATTR_CRITBONUS)
        result += GetUnitPower(unit);

    return result;
}

void ArenaGenOpponentUnit(void)
{
    struct UnitInfo info;

    int level, i;

    struct Unit * unit = &gArenaOpponent;

    info.pid = PID_ARENA_OPPONENT;
    info.jid = gArenaSt.opponent_jid;
    info.faction_id = 0;
    info.level = gArenaSt.opponent_level;
    info.autolevel = TRUE;
    info.items[0] = 0;
    info.items[1] = 0;
    info.items[2] = 0;
    info.items[3] = 0;
    info.ai[0] = 0;
    info.ai[0] = 0;
    info.ai[1] = 0;
    info.ai[2] = 0;
    info.ai[3] = 0;

    ClearUnit(unit);
    unit->id = FACTION_RED+0;

    UnitInitFromInfo(unit, &info);
    UnitInitStats(unit, unit->pinfo);

    level = unit->level;

    unit->level = ((gPlaySt.flags & PLAY_FLAG_HARD) ? level*18 : level*12) / 10;
    UnitAutolevel(unit);

    unit->level = level;

    if (unit->level < 1)
        unit->level = 1;

    if (unit->level > 20)
        unit->level = 20;

    UnitCheckStatOverflow(unit);
    SetUnitHp(unit, GetUnitMaxHp(unit));
}

void ArenaGenBaseWeapons(void)
{
    SHOULD_BE_STATIC u8 SHOULD_BE_CONST arenaWeapons[] =
    {
        [ITEM_KIND_SWORD] = IID_IRONSWORD,
        [ITEM_KIND_LANCE] = IID_IRONLANCE,
        [ITEM_KIND_AXE] = IID_IRONAXE,
        [ITEM_KIND_BOW] = IID_IRONBOW,
        [ITEM_KIND_ANIMA] = IID_FIRE,
        [ITEM_KIND_LIGHT] = IID_LIGHTNING,
        [ITEM_KIND_ELDER] = IID_FLUX,
    };

    gArenaSt.player_weapon = CreateItem(arenaWeapons[gArenaSt.player_weapon_kind]);
    gArenaSt.opponent_weapon = CreateItem(arenaWeapons[gArenaSt.opponent_weapon_kind]);

    gArenaSt.range = 1;

    if (gArenaSt.player_weapon_kind == ITEM_KIND_BOW)
        gArenaSt.range = 2;

    if (gArenaSt.opponent_weapon_kind == ITEM_KIND_BOW)
        gArenaSt.range = 2;
}

u16 ArenaGetUpgradedWeapon(u16 item)
{
    SHOULD_BE_STATIC u8 SHOULD_BE_CONST arenaWeaponUpgrades[] =
    {
        IID_IRONSWORD, IID_STEELSWORD, IID_SILVERSWORD, 0,
        IID_IRONLANCE, IID_STEELLANCE, IID_SILVERLANCE, 0,
        IID_IRONAXE, IID_STEELAXE, IID_SILVERAXE, 0,
        IID_IRONBOW, IID_STEELBOW, IID_SILVERBOW, 0,
        IID_FIRE, IID_ELFIRE, IID_FIMBULVETR, 0,
        IID_LIGHTNING, IID_DIVINE, 0,
        IID_FLUX, 0,

        -1, // end
    };

    u8 const * it;

    for (it = arenaWeaponUpgrades; *it != (u8) -1; ++it)
    {
        if (GetItemIid(item) != *it)
            continue;

        if (*++it != 0)
            return CreateItem(*it);

        return item;
    }

#if BUGFIX
    return 0;
#endif
}

bool ArenaAdjustOpponentDamage(void)
{
    bool result = FALSE;

    // Update battle unit stats

    gBattleUnitA.battle_attack = GetUnitPower(gArenaSt.player) + 5;

    if (gArenaSt.opponent_is_magic)
        gBattleUnitA.battle_defense = GetUnitResistance(gArenaSt.player);
    else
        gBattleUnitA.battle_defense = GetUnitDefense(gArenaSt.player);

    gBattleUnitB.battle_attack = GetUnitPower(gArenaSt.opponent) + 5;

    if (gArenaSt.player_is_magic)
        gBattleUnitB.battle_defense = GetUnitResistance(gArenaSt.opponent);
    else
        gBattleUnitB.battle_defense = GetUnitDefense(gArenaSt.opponent);

    if (gBattleUnitA.battle_attack - gBattleUnitB.battle_defense < GetUnitMaxHp(gArenaSt.opponent)/6)
    {
        // Player does too little damage
        // Nerfing opponent defenses

        result = TRUE;

        if (gArenaSt.player_is_magic)
        {
            gArenaSt.opponent->res -= 4;

            if (gArenaSt.opponent->res < 0)
                gArenaSt.opponent->res = 0;
        }
        else
        {
            gArenaSt.opponent->def -= 4;

            if (gArenaSt.opponent->def < 0)
                gArenaSt.opponent->def = 0;
        }

        gArenaSt.opponent->spd += 1;
        gArenaSt.opponent->skl += 1;
    }

    if (gBattleUnitB.battle_attack - gBattleUnitA.battle_defense < GetUnitMaxHp(gArenaSt.player)/6)
    {
        // Opponent does too little damage
        // Buffing opponent offenses

        result = TRUE;

        gArenaSt.opponent->pow += 3;
        gArenaSt.opponent->spd += 2;
        gArenaSt.opponent->skl += 2;

        gArenaSt.opponent_weapon = ArenaGetUpgradedWeapon(gArenaSt.opponent_weapon);
    }

    return result;
}

bool ArenaAdjustOpponentPowerRanking(void)
{
    int max, diff;

    gArenaSt.player_power_ranking = ArenaGetPowerRanking(gArenaSt.player, gArenaSt.opponent_is_magic);
    gArenaSt.opponent_power_ranking = ArenaGetPowerRanking(gArenaSt.opponent, gArenaSt.player_is_magic);

    max = gArenaSt.player_power_ranking > gArenaSt.opponent_power_ranking
        ? gArenaSt.player_power_ranking : gArenaSt.opponent_power_ranking;

    diff = ABS(gArenaSt.player_power_ranking - gArenaSt.opponent_power_ranking);

    if (diff*100/max <= 20)
        return FALSE;

    if (gArenaSt.player_power_ranking < gArenaSt.opponent_power_ranking)
    {
        if (gArenaSt.opponent->max_hp != 0)
        {
            gArenaSt.opponent->max_hp -= 1;
            gArenaSt.opponent->hp -= 1;
        }

        if (gArenaSt.opponent->pow != 0)
            gArenaSt.opponent->pow -= 1;

        if (gArenaSt.opponent->skl != 0)
            gArenaSt.opponent->skl -= 1;

        if (gArenaSt.opponent->spd != 0)
            gArenaSt.opponent->spd -= 1;

        if (gArenaSt.opponent->def != 0)
            gArenaSt.opponent->def -= 1;

        if (gArenaSt.opponent->res != 0)
            gArenaSt.opponent->res -= 1;

        if (gArenaSt.opponent->lck != 0)
            gArenaSt.opponent->lck -= 1;

        return TRUE;
    }
    else
    {
        if (gArenaSt.opponent->max_hp < 80)
        {
            gArenaSt.opponent->max_hp += 2;
            gArenaSt.opponent->hp += 2;
        }

        if (gArenaSt.opponent->pow < 30)
            gArenaSt.opponent->pow += 1;

        if (gArenaSt.opponent->skl < 30)
            gArenaSt.opponent->skl += 1;

        if (gArenaSt.opponent->spd < 30)
            gArenaSt.opponent->spd += 1;

        if (gArenaSt.opponent->def < 30)
            gArenaSt.opponent->def += 1;

        if (gArenaSt.opponent->res < 30)
            gArenaSt.opponent->res += 1;

        if (gArenaSt.opponent->lck < 30)
            gArenaSt.opponent->lck += 1;

        return TRUE;
    }
}

void ArenaGenMatchupGoldValue(void)
{
    int value = gArenaSt.opponent_power_ranking - gArenaSt.player_power_ranking;

    value = 800 + 10*(value/2);

    if (value < 1)
        value = 1;

    gArenaSt.matchup_gold_value = value;
}

int ArenaGetMatchupGoldValue(void)
{
    return gArenaSt.matchup_gold_value;
}

int ArenaGetResult(void)
{
    return gArenaSt.result;
}

void ArenaSetResult(int result)
{
    gArenaSt.result = result;
}

void ArenaContinueBattle(void)
{
    int just_resumed = gBmSt.just_resumed;

    gAction.extra = gBattleUnitB.unit.hp;

    gAction.suspend_point = SUSPEND_POINT_DURING_ARENA;
    WriteSuspendSave(SAVE_SUSPEND);

    BattleUnwind();

    if (gBattleUnitB.unit.hp == 0)
        BattleApplyExpGains();

    UpdateUnitDuringBattle(gArenaSt.player, &gBattleUnitA);

    if (!just_resumed || gBattleUnitB.unit.hp == 0)
        PidStatsUpdateFromBattleOutcome();
}

bool ArenaIsUnitAllowed(struct Unit * unit)
{
    if (unit->status == UNIT_STATUS_SILENCED)
        return FALSE;

    if (ArenaGetUnitWeaponKind(unit) < 0)
        return FALSE;

    return TRUE;
}
