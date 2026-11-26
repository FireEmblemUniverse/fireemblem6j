#ifndef SAVEMENU_H
#define SAVEMENU_H

#include "prelude.h"

// TODO: MOVE
enum { BGCHR_SAVEMENU_0 = 0,
       BGCHR_SAVEMENU_2_0 = 0, // 8000
       BGCHR_SAVEMENU_TEXT = 1, // c000

       OBCHR_SAVEMENU_1C0 = 0x1C0,
       OBCHR_SAVEMENU_200 = 0x200,
       OBCHR_SAVEMENU_CHAPTER_TITLE_BG = 0x2C0,
       OBCHR_SAVEMENU_CHAPTER_TITLE_TEXT = 0x340, // .. 0x3FF, one per slot

       OBCHR_SAVEMENU_QUILL = 0x1A0,

       OBPAL_SAVEMENU_9 = 9,

       OBPAL_SAVEMENU_FRAME_SELECTED = 1, // blended from OBPAL_SAVEMENU_FRAME
       OBPAL_SAVEMENU_FRAME = 2,
       OBPAL_SAVEMENU_LABEL_SELECTED = 3,
       OBPAL_SAVEMENU_FRAME_UNSELECTED = 4,
       OBPAL_SAVEMENU_PLAY_TIME = 5,
       OBPAL_SAVEMENU_QUILL = 6,
       OBPAL_SAVEMENU_LABEL_UNSELECTED = 8,

       // bg and text palettes alternate per slot, .. 15
       OBPAL_SAVEMENU_CHAPTER_TITLE_BG = 10,
       OBPAL_SAVEMENU_CHAPTER_TITLE_TEXT = 11,
};

enum { L_SAVEMENU_BEGIN = 0,
       L_SAVEMENU_1 = 1,
       L_SAVEMENU_2 = 2,
       L_SAVEMENU_3 = 3,
       L_SAVEMENU_4 = 4,
       L_SAVEMENU_5 = 5,
       L_SAVEMENU_6 = 6,
       L_SAVEMENU_EXTRA_INTRO = 7,
       L_SAVEMENU_EXTRA_EXIT = 8,
       L_SAVEMENU_EXTRA_MENU = 9,
       L_SAVEMENU_XMAP1_MAIN = 10,
       L_SAVEMENU_XMAP1_INTRO = 11,
       L_SAVEMENU_XMAP1_EXIT = 12,
       L_SAVEMENU_13 = 13,
       L_SAVEMENU_14 = 14,
       L_SAVEMENU_15 = 15,
       L_SAVEMENU_16 = 16,
};

enum {
	// prompt index = bit index of the corresponding SAVEMENU_ACTION_*

	SAVEMENU_PROMPT_0 = 0,
	SAVEMENU_PROMPT_1,
	SAVEMENU_PROMPT_2,
	SAVEMENU_PROMPT_3,
	SAVEMENU_PROMPT_4,
	SAVEMENU_PROMPT_5,
	SAVEMENU_PROMPT_6,
};

enum { SAVEMENU_ACTION_RESUME = 1 << 0,
       SAVEMENU_ACTION_CONTINUE = 1 << 1,
       SAVEMENU_ACTION_COPY = 1 << 2,
       SAVEMENU_ACTION_ERASE = 1 << 3,
       SAVEMENU_ACTION_NEW_GAME = 1 << 4,
       SAVEMENU_ACTION_EXTRA = 1 << 5,
       SAVEMENU_ACTION_SAVE = 1 << 6, // save screen
       SAVEMENU_ACTION_EXIT = 1 << 7,
};

enum { SAVEMENU_EXTRA_TRIAL_MAP = 1 << 0,
       SAVEMENU_EXTRA_LINK_ARENA = 1 << 1,
       SAVEMENU_EXTRA_TUTORIAL = 1 << 2,
       SAVEMENU_EXTRA_SOUND_ROOM = 1 << 3,
};

enum {
	SAVEMENU_DIGIT_SEPARATOR = 10,
	SAVEMENU_QUILL_AFFINE = 3,
};

struct SaveMenuSlotProc;
struct SaveMenuBgProc;
struct SaveMenuCursorProc;
struct SaveMenuWindowProc;

struct SaveMenuProc {
	/* 00 */ PROC_HEADER;
	/* 29 */ u8 anim_clock;
	/* 2A */ u8 menu_index;
	/* 2B */ u8 selected_id;
	/* 2C */ u8 copy_from_id;
	/* 2D */ u8 label; // proc label
	/* 2E */ u8 action;
	/* 2F */ u8 scroll_x;
	/* 30 */ u8 action_mask;
	/* 31 */ u8 action_count;
	/* 32 */ u8 extra_mask;
	/* 33 */ u8 extra_count;
	/* 34 */ u8 extra_index;
	/* 35 */ u8 extra_action;
	/* 36 */ u8 choice;
	/* 37 */ u8 slot_titles[3]; // unsure of length
	/* 3A */ u8 slot_completed[3];
	/* 3D */ u8 difficulty;
	/* 3E */ u8 help_shown;
	/* 3F */ u8 target_id;
	/* 40 */ u16 scale;
	/* 42 */ u16 extra_scroll_x;
	/* 44 */ u32 slot_times[3]; // time value
	/* 50 */ u32 suspend_time;  // time value
	/* 54 */ struct SaveMenuSlotProc *slot_proc;
	/* 58 */ struct SaveMenuBgProc *bg_proc;
	/* 5C */ ProcPtr chapter_sprite; // sprite anim proc
};

struct SaveDrawPalProc {
	/* 00 */ PROC_HEADER;
	/* 29 */ u8 progress;
};

struct SaveMenuSlotProc {
	/* 00 */ PROC_HEADER_EXT(struct SaveMenuProc);
	/* 29 */ STRUCT_PAD(0x29, 0x2A);
	/* 2A */ u16 clock;
	/* 2C */ u16 angle;
	/* 2E */ u16 unused_2E;
	/* 30 */ u16 unused_30;
	/* 32 */ u8 unused_32;
	/* 33 */ u8 action;
	/* 34 */ struct SaveMenuCursorProc *cursor_proc;
	/* 38 */ STRUCT_PAD(0x38, 0x39);
	/* 39 */ u8 unused_39;
	/* 3A */ u8 unused_3A;
	/* 3B */ u8 unused_3B;
	/* 3C */ u8 last_selected_id;
};

struct SaveMenuBgProc {
	/* 00 */ PROC_HEADER;
	/* 29 */ STRUCT_PAD(0x29, 0x2A);
	/* 2A */ u16 clock;
	/* 2C */ u16 angle;
	/* 2E */ STRUCT_PAD(0x2E, 0x30);
	/* 30 */ struct SaveMenuProc *sm_proc;
	/* 34 */ u8 unused_34;
	/* 35 */ u8 unused_35;
	/* 36 */ u8 unused_36;
	/* 37 */ u8 unused_37;
	/* 38 */ u8 unused_38;
	/* 39 */ u8 unused_39;
	/* 3A */ u8 unused_3A;
	/* 3B */ u8 unused_3B;
	/* 3C */ STRUCT_PAD(0x3C, 0x3D);
	/* 3D */ u8 unused_3D;
};

struct SaveMenuCursorProc {
	/* 00 */ PROC_HEADER;
	/* 29 */ STRUCT_PAD(0x29, 0x2A);
	/* 2A */ u16 clock;
	/* 2C */ u8 time;
	/* 2D */ u8 target_x;
	/* 2E */ u8 x;
	/* 2F */ u8 target_y;
	/* 30 */ u8 y;
	/* 31 */ u8 active;
	/* 32 */ u8 static_y;
	/* 33 */ u8 show_static;
	/* 34 */ u8 clear_static;
	/* 35 */ u8 mirror;
};

void SaveMenuOnHBlank(void);
void SaveMenu_StartExit(struct SaveMenuProc *proc);
fu8 GetSaveMenuSelectIndex(fu8 byte, int num);
fu8 GetSaveMenuBitIndex(fu8 byte);
void SaveMenu_UpdateHelpBox(struct SaveMenuProc *proc);
void SaveMenu_InitSong(struct SaveMenuProc *proc);
void SaveMenu_InitDisplay(struct SaveMenuProc *proc);
void SaveMenu_PutScreen(struct SaveMenuProc *proc);
void SaveMenu_InitSlotList(struct SaveMenuProc *proc);
void SaveMenu_GotoLabel(struct SaveMenuProc *proc);
void SaveMenu_Main_Loop(struct SaveMenuProc *proc);
void SaveMenu_HandleAction(struct SaveMenuProc *proc);
void SaveMenu_SlotSelect_Loop(struct SaveMenuProc *proc);
void SaveMenu_ConfirmAction(struct SaveMenuProc *proc);
void SaveMenu_ExitAnim_Init(struct SaveMenuProc *proc);
void SaveMenu_ExitAnim_Loop(struct SaveMenuProc *proc);
void SaveMenu_SlotScrollIn_Loop(struct SaveMenuProc *proc);
void SaveMenu_SlotScrollOut_Loop(struct SaveMenuProc *proc);
void SaveMenu_ExtraMenuScrollIn(struct SaveMenuProc *proc);
void SaveMenu_ExtraMenuScrollOut(struct SaveMenuProc *proc);
void SaveMenu_XMap1ScrollIn(struct SaveMenuProc *proc);
void SaveMenu_XMap1ScrollOut(struct SaveMenuProc *proc);
void SaveMenu_ExtraMenu_Loop(struct SaveMenuProc *proc);
bool SaveMenu_MoveXmapSlot(struct SaveMenuProc *proc, int direction);
void SaveMenu_Xmap1_Loop(struct SaveMenuProc *proc);
void SaveMenu_StartWindowAnim(struct SaveMenuProc *proc);
void SaveMenu_Finish(struct SaveMenuProc *proc);
void SaveMenu_StartXmapSoundRoom(struct SaveMenuProc *proc);
void SaveMenu_GotoExtraScreen(struct SaveMenuProc *proc);
void StartMainMenu(ProcPtr parent);
void StartSaveMenu(ProcPtr parent);

void SaveDraw_SavePalette(struct SaveDrawPalProc *proc);
void SaveDrawFadeIn_Loop(struct SaveDrawPalProc *proc);
void SaveDrawFadeOut_Loop(struct SaveDrawPalProc *proc);
void SaveDrawFadeOut32_Loop(struct SaveDrawPalProc *proc);
void SaveDrawFadeOut64_Loop(struct SaveDrawPalProc *proc);
void StartSaveDrawFadeIn(ProcPtr parent);
void StartSaveDrawFadeOut(ProcPtr parent);
void StartSaveDrawFadeOut32(ProcPtr parent);
void StartSaveDrawFadeOut64(ProcPtr parent);
void CopyPaletteBlock(u16 const *src, u16 *dst, int count);
void SaveMenu_AnimateHighlight(u32 point);

void SaveMenu_PutSaveTime(ProcPtr proc);
void SaveMenu_SetBgAffine(fu8 bg,
			  i32 scr_x,
			  i32 scr_y,
			  i32 tex_x,
			  i32 tex_y,
			  fi16 angle,
			  fi16 scale);
void SaveMenuSlot_Init(struct SaveMenuSlotProc *proc);
void SaveMenu_SetIconPalette(bool animate, fu16 clock);
void SaveMenu_PutAction(
	ProcPtr proc, int x, int y, fu8 id, fu8 pal_a, fu8 pal_b);
void SaveMenu_PutExtraAction(
	ProcPtr proc, int x, int y, fu8 id, fu8 pal_a, fu8 pal_b);
void SaveMenuSlot_UpdateCursor(struct SaveMenuSlotProc *proc);
void SaveMenuSlot_PutSuspendIcon(struct SaveMenuSlotProc *proc);
void SaveMenuSlot_Loop(struct SaveMenuSlotProc *proc);
struct SaveMenuSlotProc *StartSaveMenuSlot(struct SaveMenuProc *parent);
void SaveMenuBg_Init(struct SaveMenuBgProc *proc);
void SaveMenuBg_Loop(struct SaveMenuBgProc *proc);
struct SaveMenuBgProc *StartSaveMenuBg(struct SaveMenuProc *parent);
void SaveMenuCursor_Init(struct SaveMenuCursorProc *proc);
void SaveMenuCursor_Loop(struct SaveMenuCursorProc *proc);
void SaveMenuCursor_MoveTo(int a, int b, fu8 c, struct SaveMenuSlotProc *proc);
void SaveMenuCursor_PutStatic(int a, fu8 b, struct SaveMenuSlotProc *proc);
struct SaveMenuCursorProc *StartSaveMenuCursor(ProcPtr parent);

void SaveMenu_InitText(void);
void SaveMenu_PutPrompt(char const *string, bool display);
void SaveMenu_UpdatePrompt(struct SaveMenuProc *proc, bool display);
void SaveMenu_ClearVram(void);
void SaveMenu_UpdateAvailableActions(struct SaveMenuProc *proc);
fu8 SaveMenu_GetNextSaveIndex(fu8 save_id, bool valid, fi8 direction);
bool SaveMenu_MoveSlot(struct SaveMenuProc *proc, fi8 direction);
bool SaveMenu_IsActionAvailable(struct SaveMenuProc *proc);

void SaveMenu_WindowAnim_Loop(struct SaveMenuWindowProc *proc);
void StartSaveMenuWindowAnim(ProcPtr parent,
			     fi8 anim_direction,
			     fu8 anim_speed);
void SaveMenu_CopyBg2(ProcPtr proc);
ProcPtr StartSaveMenuBg2Copy(ProcPtr parent);

void SaveMenu_LoadSlotInfo(fu8 save_id, struct SaveMenuProc *proc);
void SaveMenu_UpdateSlotPal(fu8 save_id);
fu8 SaveMenu_GetActionIndex(fu8 end_mask, struct SaveMenuProc *proc);

extern struct ProcScr CONST_DATA ProcScr_SaveMenu[];
extern struct ProcScr CONST_DATA ProcScr_SaveDrawFadeIn[];
extern struct ProcScr CONST_DATA ProcScr_SaveDrawFadeOut[];
extern struct ProcScr CONST_DATA ProcScr_SaveDrawFadeOut32[];
extern struct ProcScr CONST_DATA ProcScr_SaveDrawFadeOut64[];
extern struct ProcScr CONST_DATA ProcScr_SaveMenuSlot[];
extern struct ProcScr CONST_DATA ProcScr_SaveMenuBg[];
extern struct ProcScr CONST_DATA ProcScr_SaveMenuCursor[];
extern struct ProcScr CONST_DATA ProcScr_SaveMenuWindowAnim[];
extern struct ProcScr CONST_DATA ProcScr_SaveMenuBg2Copy[];

extern u16 gSaveMenuUnk00;
extern u16 gSaveMenuPalBackup[0x200];

extern u16 gSaveMenuPalFx[0x20];

struct SaveMenuSpriteEntry {
	/* 00 */ u16 const *sprite;
	/* 04 */ u8 x_offset;
};

extern struct SaveMenuSpriteEntry CONST_DATA Sprites_SaveMenuActionLabels[];
extern struct SaveMenuSpriteEntry CONST_DATA Sprites_SaveMenuExtraLabels[];
extern u16 const *CONST_DATA Sprites_SaveMenuSlotTitleText[];
extern u16 const *CONST_DATA Sprites_SaveMenuSlotTitleBg[];

extern u16 const SpriteAnim_SaveMenuQuill[];

#endif // SAVEMENU_H
