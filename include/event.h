
#pragma once

#include "common.h"
#include "proc.h"

struct PopupInfo
{
    /* 00 */ u8 cmd;
    /* 04 */ int arg;
};

enum
{
    POPUP_CMD_END,
    POPUP_CMD_SPACE,
    POPUP_CMD_ITEM_NAME,
    POPUP_CMD_UNIT_NAME,
    POPUP_CMD_MSG,
    POPUP_CMD_STR,
    POPUP_CMD_COLOR,
    POPUP_CMD_ICON_ITEM,
    POPUP_CMD_ICON_IKIND,
    POPUP_CMD_NUMBER,
    POPUP_CMD_SONG,
};

enum
{
    BACKGROUND_0,
    BACKGROUND_1,
    BACKGROUND_2,
    BACKGROUND_3,
    BACKGROUND_4,
    BACKGROUND_5,
    BACKGROUND_6,
    BACKGROUND_7,
    BACKGROUND_8,
    BACKGROUND_9,
    BACKGROUND_10,
    BACKGROUND_11,
    BACKGROUND_12,
    BACKGROUND_13,
    BACKGROUND_14,
    BACKGROUND_15,
    BACKGROUND_16,
    BACKGROUND_17,
    BACKGROUND_18,
    BACKGROUND_19,
    BACKGROUND_20,
};

void SetPopupUnit(struct Unit* unit);
void SetPopupItem(u16 item);
void SetPopupNumber(int number);
ProcPtr StartPopup(struct PopupInfo const* info, int duration, int winKind, ProcPtr parent);
ProcPtr StartPopupExt(struct PopupInfo const* info, int duration, int winKind, int iconChr, int iconPal, ProcPtr parent);
void EndPopup(void);
void DisableEventSkip(void);
ProcPtr StartEvent(u32 const* script);
ProcPtr StartEventLocking(u32 const* script, ProcPtr parent);
void DisplayBackground(int background);
void DisplayBackgroundNoClear(int background);
void TryMoveUnit(struct Unit* unit, int x, int y, s8 moveClosest);
bool TryMoveUnitDisplayed(ProcPtr proc, struct Unit* unit, int x, int y);
int GetNextAvailableBlueUnitId(int start);
bool UnitInfoRequiresNoMovement(struct UnitInfo const* info);
int EventGotoLabel(ProcPtr proc, int label);
int EventEndBattleMap(ProcPtr proc);
void ClearTalk(void);
void sub_8011F4C(void);
void sub_8011F64(void);
bool IsEventRunning(void);
bool IsEventProcRunning(void);
void KillTalkAndEvent(void);
void SetFightEventFaceConfig(void);
ProcPtr StartTalkEvent(int msgid);
ProcPtr StartTalkSupportEvent(int msgid);
void StartPopup_08012040(u16 item, ProcPtr parent);
void StartPopup_08012070(u16 item, ProcPtr parent);
void StartPopup_080120A0(u16 item, ProcPtr parent);
void StartPopup_080120D0(int amount, ProcPtr parent);
void StartPopup_08012120(u16 item, ProcPtr parent);
void StartPopup_08012178(u16 item, ProcPtr parent);
void StartSupportLevelGaindPopup(ProcPtr parent);
void StartGiveItem(struct Unit* unit, u16 iid, ProcPtr parent);
void StartGiveItemEvent(u16 iid);
void StartGiveItemToEvent(u16 pid, u16 iid);
void StartGiveMoneyEvent(int amount);
void StartMapChangeEvent(u8 id);
void StartChestItemEvent(u16 iid, u8 id);
void StartChestMoneyEvent(int amount, u8 id);
void SetEventTalkSkipped(void);
int GetPlayerDeployCount(void);
void InitPlayerDeployUnits(void);
void InitPlayerDeployUnitPositions(void);

#define POPUP_END { POPUP_CMD_END, 0 }
#define POPUP_SPACE(len) { POPUP_CMD_SPACE, (len) }
#define POPUP_ITEM_NAME { POPUP_CMD_ITEM_NAME, 0 }
#define POPUP_UNIT_NAME { POPUP_CMD_UNIT_NAME, 0 }
#define POPUP_MSG(msg) { POPUP_CMD_MSG, (msg) }
#define POPUP_STR(str) { POPUP_CMD_STR, (int) (char const*) (str) }
#define POPUP_COLOR(color) { POPUP_CMD_COLOR, (color) }
#define POPUP_ICON_ITEM { POPUP_CMD_ICON_ITEM, 0 }
#define POPUP_ICON_IKIND { POPUP_CMD_ICON_IKIND, 0 }
#define POPUP_NUMBER { POPUP_CMD_NUMBER, 0 }
#define POPUP_SONG(song) { POPUP_CMD_SONG, (song) }
