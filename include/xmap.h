#pragma once

#include "prelude.h"

#include "proc.h"
#include "text.h"

#define MAX_TRIAL_CHAPTERS 6

enum proc_label_xmap {
    PL_XMAP_0,
    PL_XMAP_1,
    PL_XMAP_2,
    PL_XMAP_3
};

struct ProcXmapVSync;

struct ProcXmap
{
    PROC_HEADER;
    /* 29 */ u8 unk_29;
    /* 2A */ u8 selected_idx;
    /* 2B */ u8 num_chapters;
    /* 2C */ u8 unk_2C;
    /* 2D */ u8 unk_2D;
    /* 2E */ i8 unk_2E;
    /* 2F */ STRUCT_PAD(0x2F, 0x30);
    /* 30 */ i32 unk_30;
    /* 34 */ i32 unk_34;
    /* 38 */ i8 chapter_list[MAX_TRIAL_CHAPTERS];
    /* 3E */ u8 unk_3E;
    /* 3F */ u8 unk_3F;
    /* 40 */ char const * unk_40;
    /* 44 */ u8 unk_44;
    /* 45 */ u8 unk_45;
    /* 46 */ i8 unk_46;
    /* 47 */ u8 unk_47;
    /* 48 */ u8 unk_48;
    /* 49 */ STRUCT_PAD(0x49, 0x4C);
    /* 4C */ struct ProcXmapVSync * vsync_proc;
};

struct ProcXmapSprites
{
    /* 00 */ PROC_HEADER;

    /* 2C */ struct ProcXmap * trial_menu_proc;
    /* 30 */ u8 unk_30;
};

struct ProcXmapVSync
{
    /* 00 */ PROC_HEADER;

    /* 2A */ u16 unk_2A;
    /* 2C */ u8 unk_2C;
};

struct XmapState
{
    /* 00 */ struct Font font;
    /* 18 */ struct Text text[7];
    /* 50 */ u16 unk_50;
};

extern EWRAM_DATA struct Text gXmapTexts[MAX_TRIAL_CHAPTERS];

void Xmap_Init(struct ProcXmap *proc);
void func_fe6_0808AEFC(struct ProcXmap * proc);
// func_fe6_0808AF4C
void func_fe6_0808B028(struct ProcXmap *proc);
void func_fe6_0808B194(struct ProcXmap *proc);
void func_fe6_0808B2BC(struct ProcXmap *proc);
void func_fe6_0808B378(struct ProcXmap *proc);
void func_fe6_0808B3B8(struct ProcXmap *proc);
void func_fe6_0808B40C(struct ProcXmap *proc);
void func_fe6_0808B430(struct ProcXmap *proc);
void Xmap_End(struct ProcXmap *proc);
void Xmap_TextEnd(struct ProcXmap *proc);
// StartXmap
// func_fe6_0808B598
// func_fe6_0808B628
// func_fe6_0808B640
void func_fe6_0808B7A0(struct ProcXmap * proc);
// func_fe6_0808B7B4
// func_fe6_0808B854
struct ProcXmapVSync * func_fe6_0808B928(ProcPtr unused);

extern struct ProcScr CONST_DATA ProcScr_Xmap[];
extern struct ProcScr CONST_DATA ProcScr_XmapSprites[];
extern struct ProcScr CONST_DATA ProcScr_XmapVSync[];
