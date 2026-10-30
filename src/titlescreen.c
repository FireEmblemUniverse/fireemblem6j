#include "prelude.h"
#include "util.h"
#include "armfunc.h"
#include "gamecontroller.h"
#include "sound.h"
#include "oam.h"
#include "spriteanim.h"
#include "constants/songs.h"

#include "opanim.h"
#include "titlescreen.h"

struct ProcScr CONST_DATA ProcScr_TitleScreen[] =
{
    PROC_MARK(9),
    PROC_ONEND(Title_End),
    PROC_CALL(Title_Init),
    PROC_CALL(Title_InitDisp),
    PROC_CALL(Title_StartBgm),
    PROC_CALL(FadeInBlackSpeed20),
    PROC_YIELD,
    PROC_CALL(Title_ReinitTimer),
    PROC_REPEAT(Title_Idle),
    PROC_YIELD,
    PROC_END,
};

void Title_ReinitTimer(struct ProcTitle * proc)
{
    proc->timer = 0;
}

void Title_Idle(struct ProcTitle * proc)
{
    proc->timer++;

    if (proc->timer >= gTitleDuration)
    {
        SetNextGameAction(GAME_ACTION_1);
        FadeInBlackWithCallBack_Speed10(proc);
        Proc_Break(proc);
        return;
    }

    if (gKeySt->pressed & (KEY_BUTTON_A | KEY_BUTTON_START))
    {
        PlaySe(SONG_6D);
        SetNextGameAction(GAME_ACTION_0);
        FadeInBlackWithCallBack_Speed20(proc);
        Proc_Break(proc);
        return;
    }
}

void Title_End(struct ProcTitle * proc)
{
    EndEachSpriteAnimProc();
}

void func_fe6_0809B378(ProcPtr proc)
{
    if (bool_opanim_03005284)
        Proc_End(proc);
}

void Title_Init(struct ProcTitle * proc)
{
    int i;
    u16 * tm;

    CONST_DATA static u16 bg_config[12] =
    {
        0x0000, 0x6800, 0,
        0x0000, 0x7000, 0,
        0x0000, 0xE000, 3,
        0x8000, 0x7800, 0,
    };

    InitBgs(bg_config);
    DisableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT | BG2_SYNC_BIT | BG3_SYNC_BIT);

    SetDispEnable(0, 0, 0, 1, 1);
    SetTm((void *)BG_VRAM + GetBgTilemapOffset(BG_2), 0x1000, 0);

    Decompress(Img_Title_BG, (void *)BG_VRAM + GetBgChrOffset(BG_0));
    Decompress(Tsa_Title_BG0, (void *)BG_VRAM + GetBgTilemapOffset(BG_0));
    Decompress(Tsa_Title_BG1, (void *)BG_VRAM + GetBgTilemapOffset(BG_1));
    Decompress(Tsa_Title_BG2, (void *)BG_VRAM + GetBgTilemapOffset(BG_2));
    ApplyPalettes(Pal_Title_BG, 0, 8);

    Decompress(Img_Title_BG3, (void *)BG_VRAM + GetBgChrOffset(BG_3));
    ApplyPalette(Pal_Title_BG3, 0xF);

    /* This may be a pure ApplyTsa ? */
    tm = gBg3Tm;
    for (i = 0; i < 0x280; i++)
        *tm++ = OAM2_PAL(0xF) + i;

    EnableBgSync(BG3_SYNC_BIT);
    proc->timer = 0;
}

void Title_InitDisp(struct ProcTitle * proc)
{
    Decompress(Img_Title_Sprites, OBJ_VRAM0);
    ApplyPalettes(Pal_Title_BG, 0x10, 5);

    StartSpriteAnimProc(SpriteAnim_0835F2C8, 0xA3, 0x1B, 0, 3, 0);
    StartSpriteAnimProc(SpriteAnim_0835F2C8, 0x78, 0x55, 0, 0, 0);
    StartSpriteAnimProc(SpriteAnim_0835F2C8, 0x78, 0x78, 0, 1, 0);
    StartSpriteAnimProc(SpriteAnim_0835F2C8, 0x78, 0x98, 0, 2, 0);

    SpawnProc(ProcScr_Title_08692258, proc);
    SpawnProc(ProcScr_Title_08692298, proc);
}

struct ProcScr CONST_DATA ProcScr_Title_08692258[] = {
    PROC_CALL(func_fe6_0809B53C),
    PROC_REPEAT(func_fe6_0809B54C),

    // PROC_END ?
};

struct ProcScr CONST_DATA ProcScr_Title_08692268[] = {
    PROC_CALL(func_fe6_0809B69C),
    PROC_REPEAT(func_fe6_0809B6A4),
    PROC_END,
};

void func_fe6_0809B53C(struct ProcTitleDisp * proc)
{
    proc->timer1 = 0;
    proc->timer2 = 0;
}

void func_fe6_0809B54C(struct ProcTitleDisp * proc)
{

    if ((proc->timer1++) > 3)
    {
        proc->timer1 = 0;
        proc->timer2 = (proc->timer2 + 1) & 0xF;
        ApplyPaletteExt(
            Pal_Title_0835F388 + proc->timer2,
            0x11 * 0x20 + 0x10,
            2);
    }
}

/* Unused ? */
void func_fe6_0809B590(struct ProcTitleDisp * proc)
{
    SetDispEnable(1, 0, 0, 1, 1);
    SetBlendTargetA(1, 0, 0, 0, 0);
    SetBlendTargetB(0, 0, 0, 1, 0);
    SetBlendAlpha(0, 0x10);
    proc->timer1 = 0;
}

/* Unused ? */
void func_fe6_0809B608(struct ProcTitleDisp * proc)
{
    int ret;

    proc->timer1++;

    ret = Interpolate(INTERPOLATE_RCUBIC, 0, 0x10, proc->timer1, gUnk_08692120);
    SetBlendAlpha(ret, 0x10 - ret);

    SetBgOffset(BG_0, 0, Interpolate(INTERPOLATE_RCUBIC, -0x10, 0, proc->timer1, gUnk_08692120));

    if (proc->timer1 >= gUnk_08692120)
    {
        Proc_Break(proc);
        proc->timer1 = 0;
    }
}

void func_fe6_0809B69C(struct ProcTitleDisp * proc)
{
    proc->timer1 = 0;
}

void func_fe6_0809B6A4(struct ProcTitleDisp * proc)
{
    if (proc->timer1++ >= gUnk_0869212C)
        Proc_Break(proc);
}

struct ProcScr CONST_DATA ProcScr_Title_08692280[] =
{
    PROC_CALL(func_fe6_0809B6CC),
    PROC_REPEAT(func_fe6_0809B6F4),
    PROC_END,
};

void func_fe6_0809B6CC(struct ProcTitleDisp * proc)
{
    SetDispEnable(1, 0, 1, 1, 1);
    proc->timer1 = 0;
}

void func_fe6_0809B6F4(struct ProcTitleDisp * proc)
{
    proc->timer1++;

    SetBgOffset(
        BG_2,
        Interpolate(INTERPOLATE_RSQUARE, 0xF0, 0, proc->timer1, gUnk_0869211C),
        Interpolate(INTERPOLATE_RSQUARE, 0x69, 0, proc->timer1, gUnk_0869211C));

    if (proc->timer1 >= gUnk_0869211C)
        Proc_Break(proc);
}

struct ProcScr CONST_DATA ProcScr_Title_08692298[] =
{
    PROC_CALL(func_fe6_0809B75C),
    PROC_REPEAT(func_fe6_0809B7D4),
    PROC_END,
};

void func_fe6_0809B75C(struct ProcTitleDisp * proc)
{
    SetDispEnable(1, 1, 1, 1, 1);
    SetBlendTargetA(0, 1, 0, 0, 0);
    SetBlendTargetB(0, 0, 1, 1, 0);
    SetBlendAlpha(0, 0x10);
    proc->timer1 = 0;
}

void func_fe6_0809B7D4(struct ProcTitleDisp * proc)
{
    int ret;

    proc->timer1++;

    SetBgOffset(
        BG_1,
        0,
        Interpolate(INTERPOLATE_RSQUARE, 8, 0, proc->timer1, gUnk_08692124));

    ret = Interpolate(INTERPOLATE_RSQUARE, 0, 8, proc->timer1, gUnk_08692124);
    SetBlendAlpha(ret, 0x10 - ret);

    if (proc->timer1 >= gUnk_08692124)
        Proc_Break(proc);
}

struct ProcScr CONST_DATA ProcScr_Title_086922B0[] =
{
    PROC_CALL(func_fe6_0809B864),
    PROC_REPEAT(func_fe6_0809B898),
    PROC_END,
};

void func_fe6_0809B864(struct ProcTitleDisp * proc)
{
    SetBlendAlpha(0, 0x10);
    proc->timer1 = 0;
}

void func_fe6_0809B898(struct ProcTitleDisp * proc)
{
    SetBlendAlpha(
        Interpolate(INTERPOLATE_LINEAR, 0, 0x10, proc->timer1, 0x18),
        0x10);

    if (proc->timer1++ >= 0x18)
        Proc_Break(proc);
}

struct ProcScr CONST_DATA ProcScr_Title_086922C8[] =
{
    PROC_START_CHILD(ProcScr_Title_086922B0),
    PROC_CALL(func_fe6_0809B8FC),
    PROC_REPEAT(func_fe6_0809B96C),
    PROC_REPEAT(func_fe6_0809B99C),
    PROC_END,
};

void func_fe6_0809B8FC(struct ProcTitleDisp * proc)
{
    Decompress(Img_Title_08364438, OBJ_VRAM0 + 0x4000);
    ApplyObPalette(Pal_Title_08364A94, 0);
    SetDispEnable(1, 0, 0, 1, 1);
    SetBlendTargetA(0, 0, 0, 0, 1);
    SetBlendTargetB(1, 1, 1, 1, 0);
    proc->timer1 = 0;
}

void func_fe6_0809B96C(struct ProcTitleDisp * proc)
{
    func_fe6_0809B99C(proc);

    if (proc->timer1 == gUnk_08692128)
        Proc_Break(proc);
    else
        proc->timer1++;
}

u16 CONST_DATA Sprite_086922F0[] =
{
    1,
    OAM0_SHAPE_8x8 + OAM0_Y(2), OAM1_SIZE_8x8 + OAM1_X(2), OAM2_CHR(0xC),
};

u16 CONST_DATA Sprite_086922F8[] =
{
    1,
    OAM0_SHAPE_32x32 + OAM0_Y(246), OAM1_SIZE_32x32 + OAM1_X(501), OAM2_CHR(0x8),
};

u16 CONST_DATA Sprite_08692300[] =
{
    1,
    OAM0_SHAPE_64x64 + OAM0_Y(220) + OAM0_AFFINE_ENABLE + OAM0_DOUBLESIZE, OAM1_SIZE_64x64 + OAM1_X(472), 0,
};

void func_fe6_0809B99C(struct ProcTitleDisp * proc)
{
    int x = Interpolate(INTERPOLATE_RSQUARE, 0x96, 0, proc->timer1, gUnk_08692128);
    int y = Interpolate(INTERPOLATE_RSQUARE, 0x64, 0, proc->timer1, gUnk_08692128);
    int scale = Interpolate(INTERPOLATE_RSQUARE, 0x80, 0x200, proc->timer1, gUnk_08692128);

    PutOamHi(
        OAM1_X(x + 0x23C),
        OAM0_Y(y + 0x120),
        Sprite_08692300,
        0x200
    );

    PutOamHi(
        OAM1_X((x * 3) / 8 + 0x23C),
        OAM0_Y(y / 2 + 0x120),
        Sprite_086922F8,
        0x200
    );

    PutOamHi(
        OAM1_X(x / 8 + 0x23C),
        OAM0_Y(y / 6 + 0x120),
        Sprite_086922F0,
        0x200
    );

    SetObjAffineAuto(0, 0, scale, scale);
}

void Title_StartBgm(struct ProcTitle * proc)
{
    StartBgmExt(SONG_01, 0, NULL);
}

void func_fe6_0809BB00(void)
{
    PlaySe(SONG_92);
}
