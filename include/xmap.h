#pragma once

#include "prelude.h"

#include "proc.h"
#include "text.h"

#define MAX_TRIAL_CHAPTERS 6

enum videoalloc_xmap {
    BGCHR_XMAP_MINIMAP = 0x100,
    BGPAL_XMAP_MINIMAP = 0x0A, // x2
    BGPAL_XMAP_BACKGROUND = 0x0F,

    OBCHR_XMAP_BANNER = 0x80,
    OBCHR_XMAP_SPRITETEXT = 0x100,

    OBPAL_XMAP_BANNER = 4,
    OBPAL_XMAP_SPRITETEXT = 5, // x2
};

enum proc_label_xmap {
    PL_XMAP_SELECT = 0,
    PL_XMAP_INFO = 1,
    PL_XMAP_END = 3,
};

enum xmap_text {
    XMAP_TEXT_BANNER,
    XMAP_TEXT_CONFIRM,
    XMAP_TEXT_INFO,

    XMAP_INFO_LINES = 5,
    XMAP_TEXT_NUM = XMAP_TEXT_INFO + XMAP_INFO_LINES,

    XMAP_TEXT_CHRS = 0x40,
};

enum xmap_info_state {
    XMAP_INFO_NONE,
    XMAP_INFO_DRAWING,
    XMAP_INFO_CONFIRM,
};

enum xmap_confirm {
    XMAP_CONFIRM_YES,
    XMAP_CONFIRM_NO,
};

enum {
    XMAP_INFO_CHAR_DELAY = 4,
    XMAP_INFO_LINE_DELAY = 8,
    XMAP_DARKEN_FRAMES = 20,
    XMAP_WINDOW_STEPS = 10,

    XMAP_BANNER_BG_SPRITES = 8,
    XMAP_BANNER_TEXT_SPRITES = 7,
    XMAP_LINE_SPRITES = 6,
};

struct ProcXmapBgScroll;

struct ProcXmap
{
    PROC_HEADER;
    /* 29 */ u8 unused_29;
    /* 2A */ u8 selected_idx;
    /* 2B */ u8 num_chapters;
    /* 2C */ u8 minimap_blend;
    /* 2D */ u8 scroll_clock;
    /* 2E */ i8 scroll_dir;
    /* 2F */ STRUCT_PAD(0x2F, 0x30);
    /* 30 */ i32 minimap_x;
    /* 34 */ i32 minimap_y;
    /* 38 */ i8 chapter_list[MAX_TRIAL_CHAPTERS];
    /* 3E */ u8 info_state;
    /* 3F */ u8 confirm_choice;
    /* 40 */ char const * info_str;
    /* 44 */ u8 info_line;
    /* 45 */ u8 info_speed;
    /* 46 */ i8 info_delay;
    /* 47 */ u8 info_x;
    /* 48 */ u8 info_y;
    /* 49 */ STRUCT_PAD(0x49, 0x4C);
    /* 4C */ struct ProcXmapBgScroll * bg_scroll_proc;
};

struct ProcXmapSprites
{
    /* 00 */ PROC_HEADER;

    /* 2C */ struct ProcXmap * trial_menu_proc;
    /* 30 */ u8 unused_30;
};

struct ProcXmapBgScroll
{
    /* 00 */ PROC_HEADER;

    /* 2A */ u16 pos;
    /* 2C */ u8 timer;
};

struct XmapState
{
    /* 00 */ struct Font font;
    /* 18 */ struct Text text[XMAP_TEXT_NUM];
    /* 50 */ u16 sprite_oam2;
};

extern EWRAM_DATA struct Text gXmapTexts[MAX_TRIAL_CHAPTERS];

bool Xmap_DrawInfoText(struct ProcXmap * proc);
void Xmap_OnHBlank(void);
void Xmap_Init(struct ProcXmap * proc);
void Xmap_DrawBanner(struct ProcXmap * proc);
void Xmap_DrawInfoScreen(struct ProcXmap * proc);
void Xmap_SelectLoop(struct ProcXmap * proc);
void Xmap_MinimapScrollOut(struct ProcXmap * proc);
void Xmap_MinimapScrollIn(struct ProcXmap * proc);
void Xmap_DarkenLoop(struct ProcXmap * proc);
void Xmap_InfoTextLoop(struct ProcXmap * proc);
void Xmap_OpenConfirmWindow(struct ProcXmap * proc);
void Xmap_ConfirmLoop(struct ProcXmap * proc);
void Xmap_End(struct ProcXmap * proc);
void Xmap_TextEnd(struct ProcXmap * proc);
void StartXmap(fu8 unused, ProcPtr parent);
void XmapSprites_InitText(struct ProcXmapSprites * proc);
void XmapSprites_Init(struct ProcXmapSprites * proc);
void XmapSprites_Loop(struct ProcXmapSprites * proc);
void StartXmapSprites(struct ProcXmap * proc);
void XmapBgScroll_Init(struct ProcXmapBgScroll * proc);
void XmapBgScroll_Loop(struct ProcXmapBgScroll * proc);
struct ProcXmapBgScroll * StartXmapBgScroll(ProcPtr unused);

extern u8 const Img_XmapObj[];
extern u16 const Pal_XmapObj[];

extern struct ProcScr CONST_DATA ProcScr_Xmap[];
extern struct ProcScr CONST_DATA ProcScr_XmapSprites[];
extern struct ProcScr CONST_DATA ProcScr_XmapBgScroll[];
