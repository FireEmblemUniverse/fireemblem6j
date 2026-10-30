#include "prelude.h"
#include "proc.h"
#include "util.h"
#include "ui.h"
#include "opanim.h"
#include "banim.h"
#include "eventfunctions.h"
#include "scanline.h"
#include "ending_monologue.h"

i8 CONST_DATA Ctrl_EndingMonologueText1[] = {
    0, 1, -1,
    2, 3, 4, 5, -1,
    6, 7, 8, 9, -1, -1,
    10,
    -3
};

i8 CONST_DATA Ctrl_EndingMonologueText2[] = {
    11, 12, -1,
    2, 3, 4, 5, -1,
    6, 7, 8, 9, -1, -1,
    10,
    -3
};

i8 CONST_DATA Ctrl_EndingMonologueText3[] = {
    0, 1, 2, 3, -1,
    4, 5, 6, 7, 8,
    -3
};

i8 CONST_DATA Ctrl_EndingMonologueText4[] = {
    0, 1, -1,
    2, 3, -1,
    4, 5, 6, 7, -1,
    8, 9, 10, 11, 12, -1,
    13, 14, -1,
    15, -2, -1,
    1, 2, 3, -1, -1,
    4,
    -3
};

struct ProcScr CONST_DATA ProcScr_EndingMonologueText[] =
{
    PROC_CALL(EndingMonologueText_Init),
    PROC_REPEAT(EndingMonologueText_Loop),
    PROC_END,
};

void EndingMonologueText_Init(struct ProcEndingMonologueText * proc)
{
    if (gEndingMonologueState == 0)
    {
        Decompress(Img_EndingMonologueText_b, (void *) VRAM + 1 * CHR_SIZE);
        proc->ctrl_y = Ctrl_EndingMonologueText1;
        proc->bg_x = -28;
    }
    else if (gEndingMonologueState == 1)
    {
        Decompress(Img_EndingMonologueText_b, (void *) VRAM + 1 * CHR_SIZE);
        proc->ctrl_y = Ctrl_EndingMonologueText2;
        proc->bg_x = -28;
    }
    else if (gEndingMonologueState == 2)
    {
        Decompress(Img_EndingMonologueText_a, (void *) VRAM + 1 * CHR_SIZE);
        proc->ctrl_y = Ctrl_EndingMonologueText3;
        proc->bg_x = -48;
    }
    else if (gEndingMonologueState == 3)
    {
        Decompress(Img_EndingMonologueText_c, (void *) VRAM + 1 * CHR_SIZE);
        proc->ctrl_y = Ctrl_EndingMonologueText4;
        proc->bg_x = -24;
    }

    proc->delay_timer = 0;
    proc->bg_y = -144;
    proc->main_timer = 0;
    proc->paulse_timer = 0;

    EndingMonologue_MoveText(0, proc->ctrl_y[0]);
    SetBgOffset(0, proc->bg_x, proc->bg_y);
}

void EndingMonologueText_Loop(struct ProcEndingMonologueText * proc)
{
    proc->delay_timer++;

    if (proc->delay_timer < 7)
        return;

    proc->delay_timer = 0;

    proc->bg_y++;
    SetBgOffset(0, proc->bg_x, proc->bg_y);

    proc->main_timer++;

    if ((proc->main_timer % 24) != 0)
        return;

    if (proc->paulse_timer != 0)
    {
        EndingMonologue_MoveText(proc->main_timer / 8, -3);
    }
    else
    {
        if (proc->ctrl_y[proc->main_timer / 24] == -2 && proc->ctrl_y == Ctrl_EndingMonologueText4)
        {
            Decompress(Img_EndingMonologueText_d, (void *) VRAM + 1 * CHR_SIZE);
        }

        EndingMonologue_MoveText(proc->main_timer / 8, proc->ctrl_y[proc->main_timer / 24]);
    }

    if (proc->paulse_timer != 0 || proc->ctrl_y[proc->main_timer / 24] == -3)
    {
        proc->paulse_timer++;

        if (proc->paulse_timer == 4)
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
    ApplyPalette(Pal_EndingMonologueText, 15);

    OpAnim_SetWin0Layers(1, 0, 1, 0, 1);

    InitScanlineEffect();
    SetOnHBlankA(OnHBlank_08069FD8);
    Scanline_SetupMonologue();

    gEndingMonologueTextDone = false;

    EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT | BG2_SYNC_BIT | BG3_SYNC_BIT);
}

void EndingMonologue_MoveText(int x, int y)
{
    int iy, ix;

    if (y == -2)
        y = 0;

    for (iy = -1; iy < 3; iy++)
    {
        u16 * tm = gBg0Tm + TM_OFFSET(0, (x + iy) & 0x1F);

        if (iy == -1 || iy == 2)
        {
            for (ix = 0; ix < 0x20; ix++)
                *tm++ = 0;
        }
        else if (y == -1 || y == -3)
        {
            for (ix = 0; ix < 0x20; ix++)
                *tm++ = 0;
        }
        else
        {
            // TODO: constants
            int base = TILEREF(y * 0x40 + iy * 0x20 + 1, 15);

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

void func_fe6_0806E73C(void)
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

void StartEndingMonologue0(ProcPtr parent)
{
    gEndingMonologueState = 0;
    SpawnProc(ProcScr_EndingMonologue, parent);
}

void StartEndingMonologue1(ProcPtr parent)
{
    gEndingMonologueState = 1;
    SpawnProc(ProcScr_EndingMonologue, parent);
}

void StartEndingMonologue2(ProcPtr parent)
{
    gEndingMonologueState = 2;
    SpawnProc(ProcScr_EndingMonologue, parent);
}

void StartEndingMonologue3(ProcPtr parent)
{
    gEndingMonologueState = 3;
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

