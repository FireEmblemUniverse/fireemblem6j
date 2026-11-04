#pragma once

#include "prelude.h"
#include "proc.h"
#include "text.h"

struct SoundRoomInfo {
	int id;
	int msg_name;
	int msg_desc;
};
extern CONST_DATA struct SoundRoomInfo gSoundRoomInfo[];

enum { SOUNDROOM_CG_NUM = 10 };

enum {
	BGPAL_SOUNDROOM_FRAME = 4,
	BGPAL_SOUNDROOM_BG = 7,

	OBPAL_SOUNDROOM_BUTTONS = 4,
	OBPAL_SOUNDROOM_ARROW = 5,
	OBPAL_SOUNDROOM_TEXT = 0xA,

	OBCHR_SOUNDROOM_BUTTONS = 0x100,
	OBCHR_SOUNDROOM_ARROW = 0x380,
};

enum {
	SOUNDROOM_SLIDE_FRAMES = 6,
	SOUNDROOM_FLASH_FRAMES = 0x30,
	SOUNDROOM_ARROW_FRAMES = 6,
};

enum {
	SOUNDROOM_TEXT_NAME,
	SOUNDROOM_TEXT_DESC,
	SOUNDROOM_TEXT_PLAY,
	SOUNDROOM_TEXT_STOP,
	SOUNDROOM_TEXT_EXIT,
	SOUNDROOM_TEXT_NUM,
};

enum {
	SOUNDROOM_TEXT_CHRS = 0x40,
	SOUNDROOM_TEXT_WIDTH = 0xB0,
};

struct SoundRoomCgInfo {
	const u8  *img;
	const u16 *pal;
};
extern CONST_DATA struct SoundRoomCgInfo gSoundRoomCgInfo[SOUNDROOM_CG_NUM];

struct SoundRoomText {
	struct Font font;
	struct Text texts[SOUNDROOM_TEXT_NUM];
	u16 oam2[2];
};
extern EWRAM_OVERLAY(savemenu) struct SoundRoomText gSoundRoomText;

enum {
	PL_SOUNDROOM_MAIN = 0,
	PL_SOUNDROOM_SLIDE = 2,
	PL_SOUNDROOM_EXIT = 3,
};

struct ProcSoundRoom {
	PROC_HEADER;

	/* 29 */ u8 unused_29;

	STRUCT_PAD(0x2A, 0x2C);

	/* 2C */ u16 slide_clock;
	/* 2E */ u16 name_scale;
	/* 30 */ u32 cur_index;
	/* 34 */ u32 unused_34;
	/* 38 */ u8 sliding_left;
	/* 39 */ u8 sliding_right;

	STRUCT_PAD(0x3A, 0x3C);

	/* 3C */ ProcPtr sprite_proc;
	/* 40 */ u8 play_active;
	/* 41 */ u8 hide_desc;
};

struct ProcSoundRoomPlay {
	PROC_HEADER_EXT(struct ProcSoundRoom);

	STRUCT_PAD(0x29, 0x2C);

	/* 2C */ u16 clock;

	STRUCT_PAD(0x2E, 0x30);

	/* 30 */ u32 cur_index;
};

struct ProcSoundRoomSprite {
	PROC_HEADER_EXT(struct ProcSoundRoom);

	STRUCT_PAD(0x29, 0x2C);

	/* 2C */ struct ProcSoundRoom *parent;
	/* 30 */ u8 arrow_anim_l;
	/* 31 */ u8 arrow_anim_r;
};

void SoundRoom_Init(struct ProcSoundRoom *proc);
void SoundRoom_Loop(struct ProcSoundRoom *proc);
void SoundRoom_SlideOut(struct ProcSoundRoom *proc);
void SoundRoom_SlideIn(struct ProcSoundRoom *proc);
void SoundRoom_End(struct ProcSoundRoom *proc);
void SoundRoomPlay_Init(struct ProcSoundRoomPlay *proc);
void SoundRoomPlay_FlashIn(struct ProcSoundRoomPlay *proc);
void SoundRoomPlay_FlashOut(struct ProcSoundRoomPlay *proc);
void SoundRoomSprite_Init(struct ProcSoundRoomSprite *proc);
void SoundRoomSprite_Loop(struct ProcSoundRoomSprite *proc);

int CountTotalSoundRoomSongs(void);

ProcPtr SaveMenu_ExecSoundroom(ProcPtr parent);
void PutSoundRoomCG(int seed);
void InitSoundRoomText(void);
void PutSoundRoomSongText(struct ProcSoundRoom *proc);
void PutSoundRoomButtonLabels(void);
ProcPtr StartSoundRoomPlay(struct ProcSoundRoom *proc);
ProcPtr StartSoundRoomSprite(struct ProcSoundRoom *proc);

extern CONST_DATA u16 Sprite_SoundRoomArrow[];
extern CONST_DATA u16 Sprite_SoundRoomButtonA[];
extern CONST_DATA u16 Sprite_SoundRoomButtonB[];
extern CONST_DATA u16 Sprite_SoundRoomButtonStart[];
extern char const *CONST_DATA SoundRoomMainThemeStrings[];
extern struct ProcScr CONST_DATA ProcScr_SoundRoom[];
extern struct ProcScr CONST_DATA ProcScr_SoundRoomPlay[];
extern struct ProcScr CONST_DATA ProcScr_SoundRoomSprite[];

extern u8 const Tsa_SoundRoomFrame[];
extern u16 const Pal_SoundRoomBG[];
extern u8 const Img_SoundRoomButtons[];
extern u16 const Pal_SoundRoomButtons[];

extern char const String_SoundRoomMainThemeName[];
extern char const String_SoundRoomMainThemeDesc[];
extern char const String_SoundRoomPlay[];
extern char const String_SoundRoomStop[];
extern char const String_SoundRoomExit[];
