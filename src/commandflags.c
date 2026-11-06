#include "prelude.h"

#include "hardware.h"
#include "item.h"
#include "map.h"
#include "mapwork.h"
#include "targetlist.h"
#include "mapselect.h"
#include "faction.h"
#include "action.h"
#include "eventinfo.h"

#include "commandflags.h"

#include "constants/terrains.h"

bool CanActiveUnitUseVisit(void)
{
    int ix, iy;

    if (gActiveUnit->flags & UNIT_FLAG_HAD_ACTION)
        return FALSE;

    for (iy = gMapSize.y-1; iy >= 0; --iy)
    {
        for (ix = gMapSize.x-1; ix >= 0; --ix)
        {
            if (gMapMovement[iy][ix] > MAP_MOVEMENT_MAX)
                continue;

            if (gMapTerrain[iy][ix] != TERRAIN_VILLAGE && gMapTerrain[iy][ix] != TERRAIN_HOUSE)
                continue;

            if (GetAvailableTileEventCommand(ix, iy) == TILE_COMMAND_VISIT)
                return TRUE;
        }
    }

    return FALSE;
}

bool CanActiveUnitUseSeize(void)
{
    int ix, iy;

    if (gActiveUnit->flags & UNIT_FLAG_HAD_ACTION)
        return FALSE;

    if (!(UNIT_ATTRIBUTES(gActiveUnit) & UNIT_ATTR_LORD))
        return FALSE;

    for (iy = gMapSize.y-1; iy >= 0; --iy)
    {
        for (ix = gMapSize.x-1; ix >= 0; --ix)
        {
            if (gMapMovement[iy][ix] > MAP_MOVEMENT_MAX)
                continue;

            if (GetAvailableTileEventCommand(ix, iy) == TILE_COMMAND_SEIZE)
                return TRUE;
        }
    }

    return FALSE;
}

bool CanActiveUnitUseAttack(void)
{
    BeginTargetList(0, 0);

    BuildUnitCompleteAttackRange(gActiveUnit);

    gSubjectUnit = gActiveUnit;
    ForEachUnitInRange(TryEnlistAttackUnitTarget);

    return CountTargets() != 0 ? TRUE : FALSE;
}

bool CanActiveUnitUseRescue(void)
{
    ListRescueTargets(gActiveUnit);

    return CountTargets() != 0 ? TRUE : FALSE;
}

bool CanActiveUnitUseTrade(void)
{
    ListTradeTargets(gActiveUnit);

    return CountTargets() != 0 ? TRUE : FALSE;
}

int GetActiveUnitCommandFlags(void)
{
    int result = 0;

    GetGameTime();

    result |= CanActiveUnitUseVisit() << COMMAND_FLAG_BIT_VISIT;
    result |= CanActiveUnitUseSeize() << COMMAND_FLAG_BIT_SEIZE;
    result |= CanActiveUnitUseAttack() << COMMAND_FLAG_BIT_ATTACK;
    result |= CanActiveUnitUseRescue() << COMMAND_FLAG_BIT_RESCUE;
    result |= CanActiveUnitUseTrade() << COMMAND_FLAG_BIT_TRADE;

    return result;
}

int GetActiveUnitCommandFlagsAfterMove(void)
{
    MapFlood_UpTo(gActiveUnit, UNIT_MOV(gActiveUnit) - gAction.move_count);
    return GetActiveUnitCommandFlags();
}

int GetActiveUnitCommandFlagsInPlace(void)
{
    MapFill(gMapMovement, MAP_MOVEMENT_UNREACHABLE);
    gMapMovement[gActiveUnit->y][gActiveUnit->x] = 0;

    return GetActiveUnitCommandFlags();
}

void ListAttackPositions(struct Unit * unit)
{
    int ix, iy;

    int reach = GetUnitWeaponReach(unit, -1);

    MapFill(gMapOther, 0);

    FOR_UNITS_FACTION(FACTION_RED, enemy,
    {
        BuildUnitStandingRangeForReach(enemy, reach);

        gAction.x_target = enemy->x;
        gAction.y_target = enemy->y;
    })

    BeginTargetList(0, 0);

    for (iy = gMapSize.y-1; iy >= 0; --iy)
    {
        for (ix = gMapSize.x-1; ix >= 0; --ix)
        {
            if (gMapMovement[iy][ix] > MAP_MOVEMENT_MAX)
                continue;

            if (gMapUnit[iy][ix] != 0)
                continue;

            if (gMapOther[iy][ix] == 0)
                continue;

            EnlistTarget(ix, iy, 1, 1);
        }
    }
}
