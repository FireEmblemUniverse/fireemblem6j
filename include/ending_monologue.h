#pragma once

#include "prelude.h"
#include "proc.h"

enum
{
	BGCHR_ENDING_MONOLOGUE_TEXT = 1,
	BGPAL_ENDING_MONOLOGUE_TEXT = 15,

	// each text line is two rows of 32 tiles
	ENDING_MONOLOGUE_TEXT_ROW_TILES = 0x20,
	ENDING_MONOLOGUE_TEXT_LINE_TILES = 2 * ENDING_MONOLOGUE_TEXT_ROW_TILES,
};

enum
{
	ENDING_MONOLOGUE_TRUE,
	ENDING_MONOLOGUE_NORMAL,
	ENDING_MONOLOGUE_NORMAL_CLOSING,
	ENDING_MONOLOGUE_FALSE,
};

enum
{
	ENDING_MONOLOGUE_LINE_BLANK = -1,
	ENDING_MONOLOGUE_LINE_NEXT_IMG = -2,
	ENDING_MONOLOGUE_LINE_END = -3,
};

enum
{
	ENDING_MONOLOGUE_SCROLL_INTERVAL = 7,
	ENDING_MONOLOGUE_LINE_SPACING = 24,
	ENDING_MONOLOGUE_END_STEPS = 4,
};

struct ProcEndingMonologueText
{
	/* 00 */ PROC_HEADER;
	/* 29 */ STRUCT_PAD(0x29, 0x2C);
	/* 2C */ int bg_y;
	/* 30 */ int delay_timer;
	/* 34 */ int main_timer;
	/* 38 */ int bg_x;
	/* 3C */ i8 const * lines;
	/* 40 */ int end_timer;
};


void EndingMonologueText_Init(struct ProcEndingMonologueText *proc);
void EndingMonologueText_Loop(struct ProcEndingMonologueText *proc);
void EndingMonologue_PutText(ProcPtr parent);

void EndingMonologue_Init(void);
void EndingMonologue_MoveText(int row, int line);
void EndingMonologue_Loop(ProcPtr proc);
void EndingMonologue_End(void);
void EndingMonologue_RemoveBg(void);
void StartTrueEndingMonologue(ProcPtr parent);
void StartNormalEndingMonologue(ProcPtr parent);
void StartNormalEndingClosingMonologue(ProcPtr parent);
void StartFalseEndingMonologue(ProcPtr parent);
bool EndingMonologueExists(void);

extern u8 gEndingMonologueId;
extern u8 gEndingMonologueTextDone;
extern u32 const Img_EndingMonologueText_FinalChapter[];
extern u32 const Img_EndingMonologueText_NormalClosing[];
extern u32 const Img_EndingMonologueText_FalseEnding[];
extern u32 const Img_EndingMonologueText_FalseEnding2[];
extern u16 const Pal_EndingMonologueText[];
extern i8 CONST_DATA Ctrl_EndingMonologueText_TrueEnding[];
extern i8 CONST_DATA Ctrl_EndingMonologueText_NormalEnding[];
extern i8 CONST_DATA Ctrl_EndingMonologueText_NormalClosing[];
extern i8 CONST_DATA Ctrl_EndingMonologueText_FalseEnding[];
extern struct ProcScr CONST_DATA ProcScr_EndingMonologue[];
extern struct ProcScr CONST_DATA ProcScr_EndingMonologueText[];

extern u16 CONST_DATA BgConf_EndingMonologue[]; // bg config
