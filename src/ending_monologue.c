#include "prelude.h"
#include "proc.h"
#include "util.h"
#include "ui.h"
#include "opanim.h"
#include "banim.h"
#include "eventfunctions.h"
#include "scanline.h"
#include "ending_monologue.h"

i8 CONST_DATA Ctrl_EndingMonologueText_TrueEnding[] = {
    0, 1, ENDING_MONOLOGUE_LINE_BLANK,
    2, 3, 4, 5, ENDING_MONOLOGUE_LINE_BLANK,
    6, 7, 8, 9, ENDING_MONOLOGUE_LINE_BLANK, ENDING_MONOLOGUE_LINE_BLANK,
    10,
    ENDING_MONOLOGUE_LINE_END
};

i8 CONST_DATA Ctrl_EndingMonologueText_NormalEnding[] = {
    11, 12, ENDING_MONOLOGUE_LINE_BLANK,
    2, 3, 4, 5, ENDING_MONOLOGUE_LINE_BLANK,
    6, 7, 8, 9, ENDING_MONOLOGUE_LINE_BLANK, ENDING_MONOLOGUE_LINE_BLANK,
    10,
    ENDING_MONOLOGUE_LINE_END
};

i8 CONST_DATA Ctrl_EndingMonologueText_NormalClosing[] = {
    0, 1, 2, 3, ENDING_MONOLOGUE_LINE_BLANK,
    4, 5, 6, 7, 8,
    ENDING_MONOLOGUE_LINE_END
};

i8 CONST_DATA Ctrl_EndingMonologueText_FalseEnding[] = {
    0, 1, ENDING_MONOLOGUE_LINE_BLANK,
    2, 3, ENDING_MONOLOGUE_LINE_BLANK,
    4, 5, 6, 7, ENDING_MONOLOGUE_LINE_BLANK,
    8, 9, 10, 11, 12, ENDING_MONOLOGUE_LINE_BLANK,
    13, 14, ENDING_MONOLOGUE_LINE_BLANK,
    15, ENDING_MONOLOGUE_LINE_NEXT_IMG, ENDING_MONOLOGUE_LINE_BLANK,
    1, 2, 3, ENDING_MONOLOGUE_LINE_BLANK, ENDING_MONOLOGUE_LINE_BLANK,
    4,
    ENDING_MONOLOGUE_LINE_END
};

struct ProcScr CONST_DATA ProcScr_EndingMonologueText[] =
{
    PROC_CALL(EndingMonologueText_Init),
    PROC_REPEAT(EndingMonologueText_Loop),
    PROC_END,
};

void EndingMonologueText_Init(struct ProcEndingMonologueText * proc)
{
    if (gEndingMonologueId == ENDING_MONOLOGUE_TRUE)
    {
        Decompress(Img_EndingMonologueText_FinalChapter, (void *) VRAM + BGCHR_ENDING_MONOLOGUE_TEXT * CHR_SIZE);
        proc->lines = Ctrl_EndingMonologueText_TrueEnding;
        proc->bg_x = -28;
    }
    else if (gEndingMonologueId == ENDING_MONOLOGUE_NORMAL)
    {
        Decompress(Img_EndingMonologueText_FinalChapter, (void *) VRAM + BGCHR_ENDING_MONOLOGUE_TEXT * CHR_SIZE);
        proc->lines = Ctrl_EndingMonologueText_NormalEnding;
        proc->bg_x = -28;
    }
    else if (gEndingMonologueId == ENDING_MONOLOGUE_NORMAL_CLOSING)
    {
        Decompress(Img_EndingMonologueText_NormalClosing, (void *) VRAM + BGCHR_ENDING_MONOLOGUE_TEXT * CHR_SIZE);
        proc->lines = Ctrl_EndingMonologueText_NormalClosing;
        proc->bg_x = -48;
    }
    else if (gEndingMonologueId == ENDING_MONOLOGUE_FALSE)
    {
        Decompress(Img_EndingMonologueText_FalseEnding, (void *) VRAM + BGCHR_ENDING_MONOLOGUE_TEXT * CHR_SIZE);
        proc->lines = Ctrl_EndingMonologueText_FalseEnding;
        proc->bg_x = -24;
    }

    proc->delay_timer = 0;
    proc->bg_y = -144;
    proc->main_timer = 0;
    proc->end_timer = 0;

    EndingMonologue_MoveText(0, proc->lines[0]);
    SetBgOffset(0, proc->bg_x, proc->bg_y);
}

void EndingMonologueText_Loop(struct ProcEndingMonologueText * proc)
{
    proc->delay_timer++;

    if (proc->delay_timer < ENDING_MONOLOGUE_SCROLL_INTERVAL)
        return;

    proc->delay_timer = 0;

    proc->bg_y++;
    SetBgOffset(0, proc->bg_x, proc->bg_y);

    proc->main_timer++;

    if ((proc->main_timer % ENDING_MONOLOGUE_LINE_SPACING) != 0)
        return;

    if (proc->end_timer != 0)
    {
        EndingMonologue_MoveText(proc->main_timer / 8, ENDING_MONOLOGUE_LINE_END);
    }
    else
    {
        if (proc->lines[proc->main_timer / ENDING_MONOLOGUE_LINE_SPACING] == ENDING_MONOLOGUE_LINE_NEXT_IMG && proc->lines == Ctrl_EndingMonologueText_FalseEnding)
        {
            Decompress(Img_EndingMonologueText_FalseEnding2, (void *) VRAM + BGCHR_ENDING_MONOLOGUE_TEXT * CHR_SIZE);
        }

        EndingMonologue_MoveText(proc->main_timer / 8, proc->lines[proc->main_timer / ENDING_MONOLOGUE_LINE_SPACING]);
    }

    if (proc->end_timer != 0 || proc->lines[proc->main_timer / ENDING_MONOLOGUE_LINE_SPACING] == ENDING_MONOLOGUE_LINE_END)
    {
        proc->end_timer++;

        if (proc->end_timer == ENDING_MONOLOGUE_END_STEPS)
            gEndingMonologueTextDone = true;
    }
}

void EndingMonologue_PutText(ProcPtr parent)
{
    SpawnProc(ProcScr_EndingMonologueText, parent);
}

u16 CONST_DATA BgConf_EndingMonologue[] = {
    // tile offset  map offset  screen size
    0x0000,         0xE000,     0,          // BG 0
    0x0000,         0xE800,     0,          // BG 1
    0x8000,         0xF000,     1,          // BG 2
    0x0000,         0xF800,     0,          // BG 3
};

void EndingMonologue_Init(void)
{
    int i;

    InitBgs(BgConf_EndingMonologue);
    DisableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT | BG2_SYNC_BIT | BG3_SYNC_BIT);

    gDispIo.disp_ct.mode = DISPCNT_BG_MODE_REGULAR;
    SetDispEnable(1, 0, 1, 0, 0);
    SetWinEnable(0, 0, 0);

    SetBlendAlpha(0x10, 0x10);
    SetBlendTargetA(1, 0, 0, 0, 0);
    SetBlendTargetB(0, 0, 1, 0, 0);

    UnpackUiWindowFrameGraphics();

    TmFill(gBg0Tm, 0);
    TmFill(gBg1Tm, 0);
    SetBgOffset(2, 0, 0);

    Decompress(Img_EndingMonologue, (void *) VRAM + GetBgChrOffset(2));
    Decompress(Tsa_EndingMonologue, gBg2Tm);
    Decompress(Zpal_EndingMonologue, gBuf);

    for (i = 0; i < 8; i++)
    {
        EfxPalBlackInOut((u16 *) gBuf, i, 1, 2);
    }

    ApplyPalettes(gBuf, 0, 0x10);
    gPal[0] = 0;
    ApplyPalette(Pal_EndingMonologueText, BGPAL_ENDING_MONOLOGUE_TEXT);

    OpAnim_SetWin0Layers(1, 0, 1, 0, 1);

    InitScanlineEffect();
    SetOnHBlankA(OnHBlank_08069FD8);
    Scanline_SetupMonologue();

    gEndingMonologueTextDone = false;

    EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT | BG2_SYNC_BIT | BG3_SYNC_BIT);
}

void EndingMonologue_MoveText(int row, int line)
{
    int iy, ix;

    if (line == ENDING_MONOLOGUE_LINE_NEXT_IMG)
        line = 0;

    for (iy = -1; iy < 3; iy++)
    {
        u16 * tm = gBg0Tm + TM_OFFSET(0, (row + iy) & 0x1F);

        if (iy == -1 || iy == 2)
        {
            for (ix = 0; ix < 0x20; ix++)
                *tm++ = 0;
        }
        else if (line == ENDING_MONOLOGUE_LINE_BLANK || line == ENDING_MONOLOGUE_LINE_END)
        {
            for (ix = 0; ix < 0x20; ix++)
                *tm++ = 0;
        }
        else
        {
            int base = TILEREF(
                line * ENDING_MONOLOGUE_TEXT_LINE_TILES + iy * ENDING_MONOLOGUE_TEXT_ROW_TILES + BGCHR_ENDING_MONOLOGUE_TEXT,
                BGPAL_ENDING_MONOLOGUE_TEXT);

            for (ix = 0; ix < 0x20; ix++)
                *tm++ = base + ix;
        }
    }

    EnableBgSync(BG0_SYNC_BIT);
}

void EndingMonologue_Loop(ProcPtr proc)
{
    if (gEndingMonologueTextDone != 0)
        Proc_Break(proc);
}

void EndingMonologue_End(void)
{
    SetOnHBlankA(NULL);
}

void EndingMonologue_RemoveBg(void)
{
    InitBgs(NULL);

    SetDispEnable(1, 1, 1, 1, 1);

    CpuFastFill(0, (void *) VRAM + GetBgChrOffset(3), CHR_SIZE);
    CpuFastFill(0, (void *) VRAM + 0x6000, 0x2000); // TODO: constants
}

struct ProcScr CONST_DATA ProcScr_EndingMonologue[] =
{
    PROC_SLEEP(15),
    PROC_CALL(EndingMonologue_Init),
    PROC_CALL(FadeInBlackSpeed08),
    PROC_SLEEP(1),
    PROC_CALL(EndingMonologue_PutText),
    PROC_REPEAT(EndingMonologue_Loop),
    PROC_SLEEP(300),
PROC_LABEL(99),
    PROC_CALL(FadeInBlackWithCallBack_Speed08),
    PROC_SLEEP(1),
    PROC_CALL(EndingMonologue_End),
    PROC_END,
};

void StartTrueEndingMonologue(ProcPtr parent)
{
    gEndingMonologueId = ENDING_MONOLOGUE_TRUE;
    SpawnProc(ProcScr_EndingMonologue, parent);
}

void StartNormalEndingMonologue(ProcPtr parent)
{
    gEndingMonologueId = ENDING_MONOLOGUE_NORMAL;
    SpawnProc(ProcScr_EndingMonologue, parent);
}

void StartNormalEndingClosingMonologue(ProcPtr parent)
{
    gEndingMonologueId = ENDING_MONOLOGUE_NORMAL_CLOSING;
    SpawnProc(ProcScr_EndingMonologue, parent);
}

void StartFalseEndingMonologue(ProcPtr parent)
{
    gEndingMonologueId = ENDING_MONOLOGUE_FALSE;
    SpawnProc(ProcScr_EndingMonologue, parent);
}

bool EndingMonologueExists(void)
{
    if (Proc_Exists(ProcScr_EndingMonologue))
        return TRUE;

    Proc_EndEach(ProcScr_EndingMonologueText);
    RemoveEndingMonologueBG();

    return FALSE;
}

