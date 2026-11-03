#pragma once

#include "prelude.h"

#include "proc.h"
#include "text.h"

enum
{
    HELPBOX_INFO_NONE,
    HELPBOX_INFO_WEAPON,
    HELPBOX_INFO_STAFF,
};

struct HelpBoxProc
{
    /* 00 */ PROC_HEADER;

    /* 2C */ struct HelpBoxInfo const * info;

    /* 30 */ i16 x_box;
    /* 32 */ i16 y_box;
    /* 34 */ i16 w_box;
    /* 36 */ i16 h_box;
    /* 38 */ i16 x_box_init;
    /* 3A */ i16 y_box_init;
    /* 3C */ i16 x_box_fini;
    /* 3E */ i16 y_box_fini;
    /* 40 */ i16 w_box_init;
    /* 42 */ i16 h_box_init;
    /* 44 */ i16 w_box_fini;
    /* 46 */ i16 h_box_fini;
    /* 48 */ i16 timer;
    /* 4A */ i16 timer_end;

    /* 4C */ u16 msg;
    /* 4E */ u16 item;

    /* 50 */ u16 move_key_bit; // move ctrl proc only

    /* 52 */ u8 plain;

    // NOTE: there's likely more, need to decompile more files
};

struct ProcTypeWriter
{
    /* 00 */ PROC_HEADER;

    /* 2C */ char const * str_it;
    /* 30 */ struct Font * font;
    /* 34 */ struct Text * text[6];
    /* 4C */ STRUCT_PAD(0x4C, 0x5C);
    /* 5C */ i16 line;
    /* 5E */ i16 clock;
    /* 60 */ i16 clock_interval;
    /* 62 */ i16 chars_per_print;
};

struct HelpBoxInfo
{
    /* 00 */ struct HelpBoxInfo const * adjacent_up;
    /* 04 */ struct HelpBoxInfo const * adjacent_down;
    /* 08 */ struct HelpBoxInfo const * adjacent_left;
    /* 0C */ struct HelpBoxInfo const * adjacent_right;
    /* 10 */ u8 x, y;
    /* 12 */ u16 msg;
    /* 14 */ void (* redirect)(struct HelpBoxProc * proc);
    /* 18 */ void (* populate)(struct HelpBoxProc * proc);
};

enum
{
    TALKBOX_CHR_EDGE_H = 0x1B,
    TALKBOX_CHR_EDGE_V = 0x1F,
    TALKBOX_CHR_CORNER = 0x3E,

    TALKBOX_MIN_W = 0x20,
    TALKBOX_MAX_W = 0xC0,
    TALKBOX_MIN_H = 0x10,
    TALKBOX_MAX_H = 0x30,
};

struct HelpBoxSt
{
    /* 00 */ struct Font font;
    /* 18 */ struct Text text[3];
    /* 30 */ u16 oam2_base;
};

struct HelpBoxPrintProc
{
    /* 00 */ PROC_HEADER;

    /* 29 */ u8 pad_29[0x58 - 0x29];
    /* 58 */ i32 item;
    /* 5C */ i32 msg;
    /* 60 */ u8 pad_60[0x64 - 0x60];
    /* 64 */ i16 line; // NOTE: might not be same proc
};

void UpdateHelpBoxDisplay(struct HelpBoxProc * proc, int interpolate_method);
void HelpBox_OnOpen(struct HelpBoxProc * proc);
void HelpBox_OnLoop(struct HelpBoxProc * proc);
void HelpBox_OnClose(struct HelpBoxProc * proc);
void HelpBox_WaitClose(struct HelpBoxProc * proc);
void StartHelpBox(int x, int y, int msg);
void StartItemHelpBox(int x, int y, int item);
void StartHelpBoxExt(struct HelpBoxInfo const * info, int plain);
void StartSimpleHelpBox(int x, int y, int msg);
void CloseHelpBox(void);
void KillHelpBox(void);
// HelpBoxMoveControl_OnInitBox
// HelpBoxMoveControl_OnIdle
// HelpBoxMoveControl_OnEnd
void StartMovingHelpBox(struct HelpBoxInfo const * info, ProcPtr parent);
void StartMovingHelpBoxExt(struct HelpBoxInfo const * info, ProcPtr parent, int x, int y);
void ApplyHelpBoxContentSize(struct HelpBoxProc * proc, int w_inner, int h_inner);
void ApplyHelpBoxPosition(struct HelpBoxProc * proc, int x, int y);
void SetHelpBoxInitPosition(struct HelpBoxProc * proc, int x, int y);
void ResetHelpBoxInitSize(struct HelpBoxProc * proc);
int GetHelpBoxItemInfoKind(int item);
void HelpBoxPopulateAutoItem(struct HelpBoxProc * proc);
int HelpBoxTryRelocateUp(struct HelpBoxProc * proc);
int HelpBoxTryRelocateDown(struct HelpBoxProc * proc);
int HelpBoxTryRelocateLeft(struct HelpBoxProc * proc);
int HelpBoxTryRelocateRight(struct HelpBoxProc * proc);
// HelpBoxLockHelper_Loop
// StartLockingHelpBox
struct HelpBoxInfo const * GetLastHelpBoxInfo(void);
void PutChapterTitlePalettle(int flags, int pal);
void PutChapterTitleGfx(int chr, int chapter);
void PutChapterTitleBG1(int chr);
void PutChapterTitleBG2(int chr);
void PutChapterTitleTextTSA(u16 * tm, int pal);
void PutChapterTitleBgTSA(u16 * tm, int pal);
void PutChapterTitleBgDefaultTSA(u16 * tm, int pal);
int GetChapterTitleExtra(struct PlaySt const * play_st);
void LoadHelpBoxGfx(void * vram, int pal);
// LoadHelpBoxGfxTwoLines
void PutSpriteTalkBox(int x_box, int y_box, int w_box, int h_box);
// DrawHelpBoxWeaponLabels
// DrawHelpBoxWeaponStats
// DrawHelpBoxStaffLabels
void TypeWriter_Loop(struct ProcTypeWriter * proc);
void DemoMonologueDisp_Main(struct ProcTypeWriter * proc);
// HelpBoxPrint_DrawLabels
// HelpBoxPrint_DrawStats
// HelpBoxPrint_StartText
void StartHelpBoxPrint(int item, int msg);
void ClearHelpBoxText(void);
// HelpBoxAlt_OnLoop
// HelpBoxAlt_OnClose
// HelpBoxAlt_WaitClose
// StartHelpBoxAlt
// StartHelpBoxAltExt
// CloseHelpBoxAlt
// HelpBoxAltControl_OnInitBox
// HelpBoxAltControl_WaitA
// EndHelpBoxAltControl
void StartHelpBoxAltControl(struct HelpBoxInfo const * info);
// IsHelpBoxAltControlActive
void ApplyHelpBoxAltContentSize(struct HelpBoxProc * proc, int w_inner, int h_inner);
void ApplyHelpBoxAltPosition(struct HelpBoxProc * proc, int x, int y);
void SetHelpBoxAltInitPosition(struct HelpBoxProc * proc, int x, int y);
void ResetHelpBoxAltInitSize(struct HelpBoxProc * proc);
int GetHelpBoxAltItemInfoKind(int item);
// HelpBoxAltLockHelper_Loop
// StartLockingHelpBoxAlt
bool IsHelpDialogueActive(void);
// LoadHelpDialogueGfx
// ApplyHelpDialogueBoxPosition
// ApplyHelpDialogueBoxContentSize
// HelpDialogue_Init
// HelpDialogue_Idle
// HelpDialogue_Close
// UpdateHelpDialogueBoxDisplay
// HelpDialogueBox_OnLoop
// HelpDialogueBox_OnClose
// HelpDialogueBox_WaitClose
void CloseHelpDialogueBox(void);
void StartHelpDialogue(int x, int y, int msg, ProcPtr parent);
// StartHelpDialogueExt
void GetPagedStringTextBox(char const * str, int * out_w, int * out_h);
// GetStringPageEndPos
void StartHelpDialogueBox(int x, int y, int msg);
void PutSpriteHelpDialogueBox(int x, int y, int w, int h);
// HelpDialoguePrint_Init
// HelpDialoguePrint_Loop
// HelpDialoguePrint_End
// HelpDialogueStartPrint_Init
void StartHelpDialoguePrint(int msg);
void ClearHelpDialogueText(void);

extern struct ProcScr CONST_DATA ProcScr_HelpBox[];
extern struct ProcScr CONST_DATA ProcScr_HelpBoxMoveControl[];

extern u8 const * CONST_DATA gChapterTitleData[]; // array img ref

extern struct ProcScr CONST_DATA ProcScr_TypeWriter[];
extern struct ProcScr CONST_DATA ProcScr_DemoMonologueDisp[];
extern struct ProcScr CONST_DATA ProcScr_HelpBoxPrint[];
extern struct ProcScr CONST_DATA ProcScr_HelpBoxAlt[];
extern struct ProcScr CONST_DATA ProcScr_HelpBoxAltControl[];
extern struct ProcScr CONST_DATA ProcScr_HelpBoxAltLockHelper[];
extern struct ProcScr CONST_DATA ProcScr_HelpDialogue[];
extern struct ProcScr CONST_DATA ProcScr_HelpDialogueBox[];
extern struct ProcScr CONST_DATA ProcScr_HelpDialoguePrint[];
extern struct ProcScr CONST_DATA ProcScr_HelpDialogueStartPrint[];

// TODO: move to helpboxinfo
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677798;
extern struct HelpBoxInfo CONST_DATA HelpInfo_086777B4;
extern struct HelpBoxInfo CONST_DATA HelpInfo_086777D0;
extern struct HelpBoxInfo CONST_DATA HelpInfo_086777EC;
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677808;
extern struct HelpBoxInfo CONST_DATA HelpInfo_StatScreenPersonalInfo_Pow;
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677840;
extern struct HelpBoxInfo CONST_DATA HelpInfo_0867785C;
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677878;
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677894;
extern struct HelpBoxInfo CONST_DATA HelpInfo_086778B0;
extern struct HelpBoxInfo CONST_DATA HelpInfo_086778CC;
extern struct HelpBoxInfo CONST_DATA HelpInfo_086778E8;
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677904;
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677920;
extern struct HelpBoxInfo CONST_DATA HelpInfo_0867793C;
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677958;
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677974;
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677990;
extern struct HelpBoxInfo CONST_DATA HelpInfo_086779AC;
extern struct HelpBoxInfo CONST_DATA HelpInfo_086779C8;
extern struct HelpBoxInfo CONST_DATA HelpInfo_086779E4;
extern struct HelpBoxInfo CONST_DATA HelpInfo_StatScreenItems_ItemA;
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677A1C;
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677A38;
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677A54;
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677A70;
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677A8C;
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677AA8;
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677AC4;
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677AE0;
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677AFC;
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677B18;
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677B34;
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677B50;
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677B6C;
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677B88;
extern struct HelpBoxInfo CONST_DATA HelpInfo_StatScreenWeaponExp_WExpA;
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677BC0;
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677BDC;
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677BF8;
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677C14;
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677C30;
extern struct HelpBoxInfo CONST_DATA HelpInfo_BpShort_Hp;
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677C68;
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677C84;
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677CA0;
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677CBC;
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677CD8;
extern struct HelpBoxInfo CONST_DATA HelpInfo_BpLarge_Hp;
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677D10;
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677D2C;
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677D48;
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677D64;
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677D80;
extern struct HelpBoxInfo CONST_DATA HelpInfo_08677D9C;
