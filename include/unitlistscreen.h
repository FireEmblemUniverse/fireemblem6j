#ifndef UNITLISTSCREEN_H
#define UNITLISTSCREEN_H

#include "prelude.h"

enum
{
    UNITLIST_PAGE_SOLOANIM = 0,
    UNITLIST_PAGE_1 = 1,
    UNITLIST_PAGE_2 = 2,
    UNITLIST_PAGE_3 = 3,
    UNITLIST_PAGE_4 = 4,
    UNITLIST_PAGE_WEXP = 5,
    UNITLIST_PAGE_SUPPORT = 6,
};

enum
{
    UNITLIST_MODE_FIELD = 0,
    UNITLIST_MODE_PREPMENU = 1,
    // no 2?
    UNITLIST_MODE_SOLOANIM = 3,
    UNITLIST_MODE_4 = 4,
};

enum
{
    UNITLIST_STATE_ROWS = 0,
    UNITLIST_STATE_SCROLL_DOWN = 1,
    UNITLIST_STATE_SCROLL_UP = 2,
    UNITLIST_STATE_HEADER = 3,
    UNITLIST_STATE_STATSCREEN = 4,
};

enum
{
    UNITLIST_SORTKEY_0,
    UNITLIST_SORTKEY_1,
    UNITLIST_SORTKEY_2,
    UNITLIST_SORTKEY_3,
    UNITLIST_SORTKEY_4,
    UNITLIST_SORTKEY_5,
    UNITLIST_SORTKEY_6,
    UNITLIST_SORTKEY_7,
    UNITLIST_SORTKEY_8,
    UNITLIST_SORTKEY_9,
    UNITLIST_SORTKEY_10,
    UNITLIST_SORTKEY_11,
    UNITLIST_SORTKEY_12,
    UNITLIST_SORTKEY_13,
    UNITLIST_SORTKEY_14,
    UNITLIST_SORTKEY_15,
    UNITLIST_SORTKEY_16,
    UNITLIST_SORTKEY_17,
    UNITLIST_SORTKEY_18,
    UNITLIST_SORTKEY_19,
    UNITLIST_SORTKEY_20,
    UNITLIST_SORTKEY_21,
    UNITLIST_SORTKEY_22,
    UNITLIST_SORTKEY_23,
    UNITLIST_SORTKEY_24,
    UNITLIST_SORTKEY_25,
    UNITLIST_SORTKEY_26,
    UNITLIST_SORTKEY_27,
    UNITLIST_SORTKEY_28,
    UNITLIST_SORTKEY_29,
    UNITLIST_SORTKEY_30,
    UNITLIST_SORTKEY_31,
    UNITLIST_SORTKEY_32,
};

// TODO
struct UnitListScreenProc;

struct UnitListScreenSpritesProc;

struct UnitListScreenProc
{
    /* 00 */ PROC_HEADER;
    /* 29 */ u8 state;
    /* 2A */ u8 has_sorted;
    /* 2B */ u8 help_open;
    /* 2C */ u8 cursor_row;
    /* 2D */ u8 cursor_column;
    /* 2E */ u8 max_page;
    /* 2F */ u8 page;
    /* 30 */ u8 cursor_unit;
    /* 31 */ u8 scroll_speed;
    /* 32 */ u8 sort_key;
    /* 33 */ u8 target_sort_order; // idk which is which actually
    /* 34 */ u8 sort_order;
    /* 35 */ u8 sort_column;
    /* 36 */ u8 page_target;
    /* 37 */ u8 page_from;
    /* 38 */ u8 page_slide;
    /* 39 */ u8 mode;
    /* 3A */ u8 max_deploy;
    /* 3B */ u8 deploy_count;
    /* 3C */ u8 is_link_arena;
    /* 3D */ STRUCT_PAD(0x3D, 0x3E);
    /* 3E */ u16 page_slide_clock;
    /* 40 */ u16 scroll_y;
    /* 42 */ STRUCT_PAD(0x42, 0x44);
    /* 44 */ struct UnitListScreenSpritesProc * sprites_proc;
    /* 48 */ ProcPtr bg_proc;
};

void UnitList_PutUnitRow(struct UnitListScreenProc * proc, fu8 unit_num, u16 * tm, fu8 page, bool put_name);

struct UnitListScreenSpritesProc
{
    /* 00 */ PROC_HEADER;
    /* 2C */ struct UnitListScreenProc * main_proc;
    /* 30 */ u8 page_arrow_clock;
    /* 34 */ ProcPtr scroll_bar;
    /* 38 */ u16 last_scroll_y;
    /* 3A */ u8 is_scrolling;
    /* 3B */ u8 sort_arrow_clock;
    /* 3C */ u8 blink_clock;
};

void UnitList_Setup(struct UnitListScreenProc * proc);

struct SortedUnitEnt
{
    /* 00 */ struct Unit * unit;
    /* 04 */ i16 battle_attack;
    /* 06 */ i16 battle_hit;
    /* 08 */ i16 battle_avoid;
    /* 0A */ u8 support_talk_count;
};

extern struct SortedUnitEnt gSortedUnitsBuf[];
extern struct SortedUnitEnt * gSortedUnits[];

extern struct Text gUnitListSortKeyText;
extern u8 gUnitRearrangeBuf[];
extern u8 gUnitListCount;
extern u32 gUnitListItemIcons[];

extern u8 CONST_DATA gUnitListPageSlideInSpeedLut[];

extern u16 const * CONST_DATA gUnitListBoxSpriteLut[3];

struct UnitListScreenField
{
    /* 00 */ u8 sort_key;
    /* 01 */ STRUCT_PAD(0x01, 0x04);
    /* 04 */ char const * label_string;
    /* 08 */ u8 x_column;
    /* 09 */ STRUCT_PAD(0x09, 0x0C);
    /* 0C */ u32 msg_help;
};

extern struct UnitListScreenField UnitListPageFields[][9];

extern u16 CONST_DATA Sprite_08678750[]; // sprite
extern u16 const * CONST_DATA gUnitListPageTitleSpriteLut[]; // sprites
extern u16 CONST_DATA Sprite_08678758[]; // sprite
extern u16 CONST_DATA Sprite_08678760[]; // sprite

extern u16 gPrepUiPal[0x3A];

extern u8 const Img_Prep_083198CC[]; // img
extern u16 const Pal_SpinningArrow[]; // pal
extern u32 const Img_UnitList_Title[]; // img
extern u16 const Pal_UnitList_Title[]; // pal
extern u8 const Tsa_UnitList_083210A0[]; // tsa
extern u32 const Img_HorizontalSpinningArrow[]; // tm
extern u16 const Pal_MonologueBG[]; // pal

extern struct Text gUnitListNameTexts[];
extern struct Text gUnitListFieldTexts[][3];
extern struct Text gUnitListNameLabelText;
extern struct Text gUnitListFieldLabelText;
extern struct Text gUnitListSortKeyText;

extern struct ProcScr CONST_DATA ProcScr_UnitListScreenSprites[];
extern struct ProcScr CONST_DATA ProcScr_UnitListScreen_PrepMenu[];

enum
{
    BGPAL_UNITLIST_10 = 10, // ..13
    BGPAL_UNITLIST_15 = 15,
};

enum
{
    OBCHR_UNITLIST_240 = 0x240,
    OBCHR_UNITLIST_390 = 0x390,
};

enum
{
    OBPAL_UNITLIST_1 = 1, // ..4
    OBPAL_UNITLIST_9 = 9,
};

extern u16 gUnitListRowsTmBuf[0x20][0x20]; // tm
extern u16 gUnitListHeaderTmBuf[2][0x20]; // tm

extern u8 CONST_DATA gUnitListPageSlideOutSpeedLut[];

void UnitList_ApplyUnitOrder(void);
void UnitList_PutBoxSprites(fu8 x, fu8 y, fu8 width);
void UnitList_PutSortKeyLabel(fu8 sort_key);
void UnitList_TrackItemIcon(int icon);
void UnitList_ClearOffscreenItemIcons(fu16 scroll_y);
void UnitList_PutPageArrow(fu8 is_right, fu8 clock, fi8 visible);
void UnitList_MoveCursorToLastUnit(struct UnitListScreenProc * proc, fi8 from_prep_menu);
void UnitList_SetupWindows(bool use_win1);
void UnitList_StartStatScreen(struct UnitListScreenProc * proc);
void UnitList_ResetFromStatScreen(struct UnitListScreenProc * proc);
void UnitList_ResetDispFromStatScreen(struct UnitListScreenProc * proc);
void UnitListScreenSprites_Init(struct UnitListScreenSpritesProc * proc);
void UnitListScreenSprites_Main(struct UnitListScreenSpritesProc * proc);
void UnitListScreenSprites_Dummy(struct UnitListScreenSpritesProc * proc);
void UnitList_CollectFactionUnits(struct UnitListScreenProc * proc);
void UnitList_CollectBlueUnits(struct UnitListScreenProc * proc);
void UnitList_Setup(struct UnitListScreenProc * proc);
void UnitList_Init(struct UnitListScreenProc * proc);
void UnitList_ToggleDeploy(struct UnitListScreenProc * proc);
void CycleUnitSoloAnim(struct Unit * unit, int step);
void UnitList_Loop(struct UnitListScreenProc * proc);
void UnitList_OnEnd(struct UnitListScreenProc * proc);
void UnitList_StartPageChange(struct UnitListScreenProc * proc);
void UnitList_PageSlideOut_Loop(struct UnitListScreenProc * proc);
void UnitList_PageSlideIn_Loop(struct UnitListScreenProc * proc);
void StartUnitListScreen(void);
void StartUnitListScreenForPrepMenu(ProcPtr parent);
void StartUnitListScreenForSoloAnim(ProcPtr parent);
void StartUnitListScreenUnk(ProcPtr parent);
void UnitList_PutFieldLabels(u16 * tm, fu8 page);
void UnitList_PutPageHeader(fu8 max_page, fu8 page, bool put_labels);
void UnitList_PutUnitRow(struct UnitListScreenProc * proc, fu8 unit_num, u16 * tm, fu8 page, bool put_name);
int GetUnitSoloAnimFlags(struct Unit * unit);
bool SortUnitList(fu8 key, fu8 order);

extern int gPrepCursorUnitPid;

#endif // UNITLISTSCREEN_H
