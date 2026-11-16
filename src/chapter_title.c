#include "prelude.h"
#include "util.h"
#include "armfunc.h"
#include "hardware.h"
#include "eventfunctions.h"
#include "chapterinfo.h"
#include "constants/chapters.h"

#include "chapter_title.h"

struct ChapterTitleFxSt EWRAM_DATA gChapterTitleFxSt = { 0 };

u8 const * CONST_DATA gChapterTitleData[] = {
	Img_ChapterTitle_Ch1,
	Img_ChapterTitle_Ch2,
	Img_ChapterTitle_Ch3,
	Img_ChapterTitle_Ch4,
	Img_ChapterTitle_Ch5,
	Img_ChapterTitle_Ch6,
	Img_ChapterTitle_Ch7,
	Img_ChapterTitle_Ch8,
	Img_ChapterTitle_Ch8X,
	Img_ChapterTitle_Ch9,
	Img_ChapterTitle_Ch10A,
	Img_ChapterTitle_Ch11A,
	Img_ChapterTitle_Ch10B,
	Img_ChapterTitle_Ch11B,
	Img_ChapterTitle_Ch12,
	Img_ChapterTitle_Ch12X,
	Img_ChapterTitle_Ch13,
	Img_ChapterTitle_Ch14,
	Img_ChapterTitle_Ch14X,
	Img_ChapterTitle_Ch15,
	Img_ChapterTitle_Ch16,
	Img_ChapterTitle_Ch16X,
	Img_ChapterTitle_Ch17I,
	Img_ChapterTitle_Ch18I,
	Img_ChapterTitle_Ch19I,
	Img_ChapterTitle_Ch20I,
	Img_ChapterTitle_Ch20XI,
	Img_ChapterTitle_Ch17S,
	Img_ChapterTitle_Ch18S,
	Img_ChapterTitle_Ch19S,
	Img_ChapterTitle_Ch20S,
	Img_ChapterTitle_Ch20XS,
	Img_ChapterTitle_Ch21,
	Img_ChapterTitle_Ch21X,
	Img_ChapterTitle_Ch22,
	Img_ChapterTitle_Ch23,
	Img_ChapterTitle_Ch24,
	Img_ChapterTitle_Final,
	Img_ChapterTitle_NoData,
	Img_ChapterTitle_Tutorial,
	Img_ChapterTitle_Epilogue,
	Img_ChapterTitle_EpilogueStar,
	Img_ChapterTitle_EpilogueTwoStars,
	Img_ChapterTitle_TrialMap,
};

void PutChapterTitlePalette(int flags, int pal)
{
    u16 const * pal_src;

    if (flags & CHAPTER_TITLE_PAL_BG2)
    {
        ApplyPalette(Pal_ChapterTitleBG2, pal);
        return;
    }

    pal_src = (flags & CHAPTER_TITLE_PAL_BG1) != 0
        ? Pal_ChapterTitleBG1
        : Pal_ChapterTitleText;

    if (flags & CHAPTER_TITLE_PAL_UNSELECTED)
        pal_src = pal_src + 0x10;

    if (flags & CHAPTER_TITLE_PAL_HARD)
        pal_src = pal_src + 0x20;

    ApplyPalette(pal_src, pal);
}

void PutChapterTitleGfx(int chr, int title_id)
{
    // TODO: is this really chapter?
    // Not the title count either: CHAPTER_COUNT is CHAPTER_TITLE_COUNT + 1, so id 44 reads past gChapterTitleData.
    if (title_id < 0 || title_id >= CHAPTER_COUNT)
        title_id = CHAPTER_TITLE_NO_DATA;

    gChapterTitleFxSt.chr_text = TILE_CHR_SAFE(chr);
    Decompress(gChapterTitleData[title_id], ((void *) VRAM) + chr * CHR_SIZE);
}

void PutChapterTitleBG1(int chr)
{
    gChapterTitleFxSt.chr_bg = TILE_CHR_SAFE(chr);
    Decompress(Img_ChapterTitleBG1, ((void *) VRAM) + chr * CHR_SIZE);
}

void PutChapterTitleBG2(int chr)
{
    gChapterTitleFxSt.chr_bg = TILE_CHR_SAFE(chr);
    Decompress(Img_ChapterTitleBG2, ((void *) VRAM) + chr * CHR_SIZE);
}

void PutChapterTitleTextTSA(u16 * tm, int pal)
{
    int i, tile = TILEREF(gChapterTitleFxSt.chr_text, pal);

    for (i = 0; i < CHAPTER_TITLE_TEXT_TILES; i++)
        *tm++ = tile++;
}

void PutChapterTitleBgTSA(u16 * tm, int pal)
{
    int i, tile = TILEREF(gChapterTitleFxSt.chr_bg, pal);

    for (i = 0; i < CHAPTER_TITLE_BG_TILES; i++)
        *tm++ = tile++;
}

void PutChapterTitleBgDefaultTSA(u16 * tm, int pal)
{
    TmApplyTsa(tm, Tsa_ChapterTitleFxDefaultBG, TILEREF(gChapterTitleFxSt.chr_bg, pal));
}

int GetChapterTitleExtra(struct PlaySt const * play_st)
{
    if (play_st == NULL)
        return CHAPTER_TITLE_NO_DATA;

    switch (play_st->chapter)
    {

    case -1:
    case CHAPTER_TRIAL_A ... CHAPTER_TRIAL_E:
        return CHAPTER_TITLE_TRIAL_MAP;

    default:
        if ((play_st->flags & PLAY_FLAG_COMPLETE) != 0)
        {
            switch (play_st->ending_id)
            {
                case TRUE_ENDING:
                    return CHAPTER_TITLE_EPILOGUE_TRUE;

                case NORMAL_ENDING:
                    return CHAPTER_TITLE_EPILOGUE_NORMAL;

                case FAKE_ENDING:
                    return CHAPTER_TITLE_EPILOGUE_FAKE;
            }
        }

        return GetChapterInfo(play_st->chapter)->title_id;
    }
}
