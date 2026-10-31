#include "prelude.h"
#include "proc.h"
#include "util.h"
#include "armfunc.h"
#include "scanline.h"
#include "sound.h"
#include "constants/songs.h"

#include "monologue.h"

struct ProcScr CONST_DATA ProcScr_Monologue[] =
{
    PROC_ONEND(Monologue_End),
    PROC_CALL(Monologue_Init),
    PROC_CALL(FadeInBlackSpeed08),
    PROC_YIELD,

    PROC_SLEEP(60),
    PROC_START_CHILD(ProcScr_MonologueDisp),
    PROC_REPEAT(Monologue_Loop),

    PROC_CALL_ARG(_FadeBgmOut, 4),
    PROC_CALL(FadeInBlackWithCallBack_Speed08),
    PROC_SLEEP(0),
    PROC_END,
};

void StartIntroMonologue(ProcPtr proc)
{
    SpawnProcLocking(ProcScr_Monologue, proc);
}

void Monologue_End(struct Proc * proc)
{
    SetOnHBlankA(NULL);
}

void Monologue_Init(struct Proc * proc)
{
    CONST_DATA static u16 bg_config[12] =
    {
        0x0000, 0xD000, 2,
        0x0000, 0xD800, 0,
        0x0000, 0xE000, 0,
        0x8000, 0xE800, 0,
    };

    InitBgs(bg_config);
    Clear4bppFirstTm();
    ResetText();

    SetDispEnable(1, 0, 0, 1, 0);
    SetBlendAlpha(0x10, 0x10);
    SetBlendTargetA(1, 0, 0, 0, 0);
    SetBlendTargetB(0, 0, 0, 1, 0);

    InitScanlineEffect();
    SetOnHBlankA(OnHBlank_08069FD8);
    Scanline_SetupMonologue();

    Decompress(Img_MonologueBG, (void *)BG_VRAM + GetBgChrOffset(BG_3));
    TmApplyTsa((void *)gBuf, Tsa_MonologueBG, 0x4000);
    VramCopy(gBuf, gBg3Tm, 0x800);
    ApplyBgPalettes(Pal_MonologueBG, 4, 4);

    BrightenPalette(4);
    BrightenPalette(5);
    BrightenPalette(6);
    BrightenPalette(7);

    TmFill(gBg0Tm, 0);
    TmFill(gBg1Tm, 0);

    ApplyBgPalette(Pal_MonologueText, 3);
    Decompress(Img_MonologueText, (void *)BG_VRAM + 0x20 + GetBgChrOffset(BG_0));

    MonologueSetTm(gBg0Tm + TM_OFFSET(2, 0), 0x3001);
    MonologueSetTm(gBg0Tm + TM_OFFSET(2, 3), 0x3041);
    MonologueSetTm(gBg0Tm + TM_OFFSET(2, 6), 0x3081);
    MonologueSetTm(gBg0Tm + TM_OFFSET(2, 10), 0x30C1);
    MonologueSetTm(gBg0Tm + TM_OFFSET(2, 13), 0x3101);
    MonologueSetTm(gBg0Tm + TM_OFFSET(2, 16), 0x3141);
    MonologueSetTm(gBg0Tm + TM_OFFSET(2, 19), 0x3181);
    MonologueSetTm(gBg0Tm + TM_OFFSET(2, 22), 0x31C1);
    MonologueSetTm(gBg0Tm + TM_OFFSET(2, 25), 0x3201);
    MonologueSetTm(gBg0Tm + TM_OFFSET(2, 29), 0x3241);

    EnableBgSync(BG0_SYNC_BIT);
    EnableBgSync(BG1_SYNC_BIT);

    SetBgOffset(BG_0, 0, -0xA0);

    /**
     * Although the config has not avaliable during new game.
     * But I still think it better to use PlaySe.
     */
    m4aSongNumStart(SONG_47);
}

void MonologueSetTm(u16 * tm, int tm_ref)
{
    int i;

    for (i = 0; i < 0x20; i++)
    {
        int val = tm_ref + i;

        *tm = val;
        *(tm + 0x20) = val + 0x20;
    
        tm++;
    }
}

void Monologue_Loop(struct Proc * proc)
{
    if (proc->timer1 == 0x390)
    {
        MonologueSetTm(gBg1Tm + TM_OFFSET(2, 0), 0x3281);
        MonologueSetTm(gBg1Tm + TM_OFFSET(2, 3), 0x32C1);
        MonologueSetTm(gBg1Tm + TM_OFFSET(2, 6), 0x3301);
        MonologueSetTm(gBg1Tm + TM_OFFSET(2, 14), 0x3341);

        EnableBgSync(BG0_SYNC_BIT);
        EnableBgSync(BG1_SYNC_BIT);
    }

    if (gKeySt->pressed & KEY_BUTTON_START)
        Proc_Break(proc);

    if (proc->timer1++ > 0x6C7)
        Proc_Break(proc);
}

struct ProcScr CONST_DATA ProcScr_MonologueDisp[] =
{
    PROC_CALL(MonologueDisp_Init),
    PROC_REPEAT(MonologueDisp_Loop),

#if BUGFIX
    PROC_END
#endif
};

void MonologueDisp_Init(struct Proc * proc)
{
    proc->timer1 = 0;
    proc->timer2 = 0;
}

void MonologueDisp_Loop(struct Proc * proc)
{
    if (proc->timer1++ > 2)
    {
        proc->timer1 = 0;
        proc->timer2++;
    }

    SetBgOffset(BG_0, 0, proc->timer2 - 0x90);
}
