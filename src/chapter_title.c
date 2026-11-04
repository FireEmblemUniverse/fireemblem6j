#include "prelude.h"
#include "util.h"
#include "armfunc.h"
#include "hardware.h"
#include "eventfunctions.h"
#include "chapterinfo.h"
#include "constants/chapters.h"

#include "chapter_title.h"

struct ChapterTitleFxSt EWRAM_DATA gChapterTitleFxSt = { 0 };

// enum: CHAPTER_TITLE
u16 const *CONST_DATA gChapterTitleData[] = {
	Img_ChapterTitle_0830D9C0,
	Img_ChapterTitle_0830DDBC,
	Img_ChapterTitle_0830E1DC,
	Img_ChapterTitle_0830E640,
	Img_ChapterTitle_0830EA4C,
	Img_ChapterTitle_0830EDC8,
	Img_ChapterTitle_0830F250,
	Img_ChapterTitle_0830F6C4,
	Img_ChapterTitle_0830F9B8,
	Img_ChapterTitle_0830FE60,
	Img_ChapterTitle_083102CC,
	Img_ChapterTitle_083107A8,
	Img_ChapterTitle_08310BBC,
	Img_ChapterTitle_08311094,
	Img_ChapterTitle_083114AC,
	Img_ChapterTitle_08311890,
	Img_ChapterTitle_08311D54,
	Img_ChapterTitle_08312158,
	Img_ChapterTitle_083124FC,
	Img_ChapterTitle_083129A0,
	Img_ChapterTitle_08312D20,
	Img_ChapterTitle_08313104,
	Img_ChapterTitle_083135C0,
	Img_ChapterTitle_0831394C,
	Img_ChapterTitle_08313D38,
	Img_ChapterTitle_083140C8,
	Img_ChapterTitle_083144E4,
	Img_ChapterTitle_083149C8,
	Img_ChapterTitle_08314E14,
	Img_ChapterTitle_083151E8,
	Img_ChapterTitle_0831569C,
	Img_ChapterTitle_08315AC0,
	Img_ChapterTitle_08315F88,
	Img_ChapterTitle_08316354,
	Img_ChapterTitle_083167EC,
	Img_ChapterTitle_08316C00,
	Img_ChapterTitle_08317014,
	Img_ChapterTitle_08317484,
	Img_ChapterTitle_08317858,
	Img_ChapterTitle_08317AA4,
	Img_ChapterTitle_08317D94,
	Img_ChapterTitle_08318040,
	Img_ChapterTitle_0831833C,
	Img_ChapterTitle_08318658,
};

void PutChapterTitlePalettle(int flags, int pal)
{
    u16 const * pal_src;

    if (flags & 8)
    {
        ApplyPalette(Pal_Unk_0830D5E4, pal);
        return;
    }

    pal_src = (flags & 1) != 0
        ? Pal_Unk_08309474
        : Pal_Unk_083094F4;

    if (flags & 2)
        pal_src = pal_src + 0x10;

    if (flags & 4)
        pal_src = pal_src + 0x20;

    ApplyPalette(pal_src, pal);
}

void PutChapterTitleGfx(int chr, int title_id)
{
    // TODO: is this really chapter?
    if (title_id < 0 || title_id >= CHAPTER_COUNT)
        title_id = CHAPTER_21X;

    gChapterTitleFxSt.chr_text = chr & 0x3FF;
    Decompress(gChapterTitleData[title_id], ((void *) VRAM) + chr * CHR_SIZE);
}

void PutChapterTitleBG1(int chr)
{
    gChapterTitleFxSt.chr_bg = chr & 0x3FF;
    Decompress(Img_ChapterTitleBG1, ((void *) VRAM) + chr * CHR_SIZE);
}

void PutChapterTitleBG2(int chr)
{
    gChapterTitleFxSt.chr_bg = chr & 0x3FF;
    Decompress(Img_ChapterTitleBG2, ((void *) VRAM) + chr * CHR_SIZE);
}

void PutChapterTitleTextTSA(u16 * tm, int pal)
{
    int i, tile = TILEREF(gChapterTitleFxSt.chr_text, pal);

    for (i = 0; i < 0x40; i++)
        *tm++ = tile++;
}

void PutChapterTitleBgTSA(u16 * tm, int pal)
{
    int i, tile = TILEREF(gChapterTitleFxSt.chr_bg, pal);

    for (i = 0; i < 0x80; i++)
        *tm++ = tile++;
}

void PutChapterTitleBgDefaultTSA(u16 * tm, int pal)
{
    TmApplyTsa(tm, Tsa_ChapterTitleFxDefaultBG, TILEREF(gChapterTitleFxSt.chr_bg, pal));
}

int GetChapterTitleExtra(struct PlaySt const * play_st)
{
    if (play_st == NULL)
        return 0x26;

    switch (play_st->chapter)
    {

    case -1:
    case 0x28 ... 0x2C:
        return 0x2B;

    default:
        if ((play_st->flags & PLAY_FLAG_COMPLETE) != 0)
        {
            switch (play_st->ending_id)
            {
                case TRUE_ENDING:
                    return 0x2A;

                case NORMAL_ENDING:
                    return 0x29;

                case FAKE_ENDING:
                    return 0x28;
            }
        }

        return GetChapterInfo(play_st->chapter)->title_id;
    }
}
