#pragma once

#include "prelude.h"

#include "unit.h"

enum
{
    COMMAND_FLAG_BIT_ATTACK = 1,
    COMMAND_FLAG_BIT_RESCUE = 8,
    COMMAND_FLAG_BIT_VISIT = 15,
    COMMAND_FLAG_BIT_SEIZE = 16,
    COMMAND_FLAG_BIT_TRADE = 23,
};

enum
{
    COMMAND_FLAG_ATTACK = 1 << COMMAND_FLAG_BIT_ATTACK,
    COMMAND_FLAG_RESCUE = 1 << COMMAND_FLAG_BIT_RESCUE,
    COMMAND_FLAG_VISIT = 1 << COMMAND_FLAG_BIT_VISIT,
    COMMAND_FLAG_SEIZE = 1 << COMMAND_FLAG_BIT_SEIZE,
    COMMAND_FLAG_TRADE = 1 << COMMAND_FLAG_BIT_TRADE,
};

bool CanActiveUnitUseVisit(void);
bool CanActiveUnitUseSeize(void);
bool CanActiveUnitUseAttack(void);
bool CanActiveUnitUseRescue(void);
bool CanActiveUnitUseTrade(void);
int GetActiveUnitCommandFlags(void);
int GetActiveUnitCommandFlagsAfterMove(void);
int GetActiveUnitCommandFlagsInPlace(void);
void ListAttackPositions(struct Unit * unit);
