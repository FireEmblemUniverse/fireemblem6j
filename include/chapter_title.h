#pragma once

#include "prelude.h"

struct ChapterTitleFxSt {
	u16 chr_bg;
	u16 chr_text;
};

extern struct ChapterTitleFxSt EWRAM_DATA gChapterTitleFxSt;

enum chapter_title_indx {
	CHAPTER_TITLE_1,
	CHAPTER_TITLE_2,
	CHAPTER_TITLE_3,
	CHAPTER_TITLE_4,
	CHAPTER_TITLE_5,
	CHAPTER_TITLE_6,
	CHAPTER_TITLE_7,
	CHAPTER_TITLE_8,
	CHAPTER_TITLE_8X,
	CHAPTER_TITLE_9,
	CHAPTER_TITLE_10_A,
	CHAPTER_TITLE_11_A,
	CHAPTER_TITLE_10_B,
	CHAPTER_TITLE_11_B,
	CHAPTER_TITLE_12,
	CHAPTER_TITLE_12X,
	CHAPTER_TITLE_13,
	CHAPTER_TITLE_14,
	CHAPTER_TITLE_14X,
	CHAPTER_TITLE_15,
	CHAPTER_TITLE_16,
	CHAPTER_TITLE_16X,
	CHAPTER_TITLE_17_I,
	CHAPTER_TITLE_18_I,
	CHAPTER_TITLE_19_I,
	CHAPTER_TITLE_20_I,
	CHAPTER_TITLE_20X_I,
	CHAPTER_TITLE_17_S,
	CHAPTER_TITLE_18_S,
	CHAPTER_TITLE_19_S,
	CHAPTER_TITLE_20_S,
	CHAPTER_TITLE_20X_S,
	CHAPTER_TITLE_21,
	CHAPTER_TITLE_21X,
	CHAPTER_TITLE_22,
	CHAPTER_TITLE_23,
	CHAPTER_TITLE_24,
	CHAPTER_TITLE_FINAL,
	CHAPTER_TITLE_NO_DATA,
	CHAPTER_TITLE_TUTORIAL,
	CHAPTER_TITLE_EPILOGUE_FAKE,
	CHAPTER_TITLE_EPILOGUE_NORMAL,
	CHAPTER_TITLE_EPILOGUE_TRUE,
	CHAPTER_TITLE_TRIAL_MAP,
	CHAPTER_TITLE_COUNT,
};

enum {
	CHAPTER_TITLE_PAL_BG1 = 1 << 0,
	CHAPTER_TITLE_PAL_UNSELECTED = 1 << 1,
	CHAPTER_TITLE_PAL_HARD = 1 << 2,
	CHAPTER_TITLE_PAL_BG2 = 1 << 3,
};

enum {
	CHAPTER_TITLE_TEXT_TILES = 0x40,
	CHAPTER_TITLE_BG_TILES = 0x80,
};

void PutChapterTitlePalette(int flags, int pal);
void PutChapterTitleGfx(int chr, int title_id);
void PutChapterTitleBG1(int chr);
void PutChapterTitleBG2(int chr);
void PutChapterTitleTextTSA(u16 * tm, int pal);
void PutChapterTitleBgTSA(u16 * tm, int pal);
void PutChapterTitleBgDefaultTSA(u16 * tm, int pal);
int GetChapterTitleExtra(struct PlaySt const * play_st);

extern u8 const * CONST_DATA gChapterTitleData[];

extern u16 const Pal_ChapterTitleBG1[];
extern u16 const Pal_ChapterTitleText[];
extern u8 const Img_ChapterTitleBG1[];
extern u8 const Img_ChapterTitleBG2[];
extern u8 const Tsa_ChapterTitleFxDefaultBG[];
extern u16 const Pal_ChapterTitleBG2[];

extern u8 const Img_ChapterTitle_Ch1[];
extern u8 const Img_ChapterTitle_Ch2[];
extern u8 const Img_ChapterTitle_Ch3[];
extern u8 const Img_ChapterTitle_Ch4[];
extern u8 const Img_ChapterTitle_Ch5[];
extern u8 const Img_ChapterTitle_Ch6[];
extern u8 const Img_ChapterTitle_Ch7[];
extern u8 const Img_ChapterTitle_Ch8[];
extern u8 const Img_ChapterTitle_Ch8X[];
extern u8 const Img_ChapterTitle_Ch9[];
extern u8 const Img_ChapterTitle_Ch10A[];
extern u8 const Img_ChapterTitle_Ch11A[];
extern u8 const Img_ChapterTitle_Ch10B[];
extern u8 const Img_ChapterTitle_Ch11B[];
extern u8 const Img_ChapterTitle_Ch12[];
extern u8 const Img_ChapterTitle_Ch12X[];
extern u8 const Img_ChapterTitle_Ch13[];
extern u8 const Img_ChapterTitle_Ch14[];
extern u8 const Img_ChapterTitle_Ch14X[];
extern u8 const Img_ChapterTitle_Ch15[];
extern u8 const Img_ChapterTitle_Ch16[];
extern u8 const Img_ChapterTitle_Ch16X[];
extern u8 const Img_ChapterTitle_Ch17I[];
extern u8 const Img_ChapterTitle_Ch18I[];
extern u8 const Img_ChapterTitle_Ch19I[];
extern u8 const Img_ChapterTitle_Ch20I[];
extern u8 const Img_ChapterTitle_Ch20XI[];
extern u8 const Img_ChapterTitle_Ch17S[];
extern u8 const Img_ChapterTitle_Ch18S[];
extern u8 const Img_ChapterTitle_Ch19S[];
extern u8 const Img_ChapterTitle_Ch20S[];
extern u8 const Img_ChapterTitle_Ch20XS[];
extern u8 const Img_ChapterTitle_Ch21[];
extern u8 const Img_ChapterTitle_Ch21X[];
extern u8 const Img_ChapterTitle_Ch22[];
extern u8 const Img_ChapterTitle_Ch23[];
extern u8 const Img_ChapterTitle_Ch24[];
extern u8 const Img_ChapterTitle_Final[];
extern u8 const Img_ChapterTitle_NoData[];
extern u8 const Img_ChapterTitle_Tutorial[];
extern u8 const Img_ChapterTitle_Epilogue[];
extern u8 const Img_ChapterTitle_EpilogueStar[];
extern u8 const Img_ChapterTitle_EpilogueTwoStars[];
extern u8 const Img_ChapterTitle_TrialMap[];
