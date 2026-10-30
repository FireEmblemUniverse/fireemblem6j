#include "prelude.h"
#include "proc.h"
#include "oam.h"
#include "datamove.h"
#include "hardware.h"
#include "sprite.h"
#include "banim_sprite.h"
#include "banim.h"
#include "banim_ekrbattle.h"

void SpellFx_Begin(void)
{
    gEfxSpellAnimExists = true;
}

void SpellFx_Finish(void)
{
    gEfxSpellAnimExists = false;
}

void SpellFx_ClearBG1Position(void)
{
    SetBgOffset(BG_1, 0, 0);
}

void SpellFx_ClearBG1(void)
{
    CpuFastFill16(0, gBg1Tm, 0x800);
    EnableBgSync(BG1_SYNC_BIT);
}

void SpellFx_SetSomeColorEffect(void)
{
    SetBlendConfig(1, 0x10, 0x10, 0);
    SetBlendTargetA(0, 1, 0, 0, 0);
    SetBlendTargetB(0, 0, 1, 1, 1);
    SetWinEnable(1, 0, 0);
    SetWin0Box(0, 0, 0xF0, 0xA0);
    SetWin0Layers(1, 1, 1, 1, 1);
    SetWOutLayers(1, 0, 1, 1, 1);

    gDispIo.win_ct.win0_enable_blend = true;
    gDispIo.win_ct.wout_enable_blend = false;
    gDispIo.blend_ct.target2_enable_bd = true;
}

void SpellFx_ClearColorEffects(void)
{
    SetBlendNone();
}

void StartBattleAnimHitEffectsDefault(struct Anim * anim, int type)
{
    StartBattleAnimHitEffects(anim, type, 3, 4);
}

void StartBattleAnimHitEffectsAlt(struct Anim * anim, int type)
{
    StartBattleAnimHitEffects(anim, type, 5, 5);
}

void StartBattleAnimHitEffects(struct Anim * anim, int type, int quake_normal, int quake_crit)
{
    struct Anim * anim_other_f, * anim_other_b, * anim_this_f, * anim_this_b;
    int val1, val2;
    i16 roundt1, roundt2;

    if (GetAnimPosition(anim) == POS_L)
    {
        anim_other_f = MAIN_ANIM_FRONT(POS_R);
        anim_other_b = MAIN_ANIM_BACK(POS_R);
        anim_this_f  = MAIN_ANIM_FRONT(POS_L);
        anim_this_b  = MAIN_ANIM_BACK(POS_L);
    }
    else
    {
        anim_other_f = MAIN_ANIM_FRONT(POS_L);
        anim_other_b = MAIN_ANIM_BACK(POS_L);
        anim_this_f  = MAIN_ANIM_FRONT(POS_R);
        anim_this_b  = MAIN_ANIM_BACK(POS_R);
    }

    switch (type) {
    case EKR_HITTED:
        roundt1 = GetRoundFlagByAnim(anim_other_f);
        roundt2 = GetRoundFlagByAnim(anim_this_f);

        if (roundt1 & ANIM_ROUND_POISON)
        {
            if (GetUnitEfxDebuff(anim_other_f) == UNIT_STATUS_NONE)
                SetUnitEfxDebuff(anim_other_f, UNIT_STATUS_POISON);
        }

        if (roundt2 & ANIM_ROUND_POISON)
        {
            if (GetUnitEfxDebuff(anim_this_f) == UNIT_STATUS_NONE)
                SetUnitEfxDebuff(anim_this_f, UNIT_STATUS_POISON);
        }

        if (roundt1 & ANIM_ROUND_DEVIL || roundt2 & ANIM_ROUND_DEVIL)
        {
            struct Anim *tmp;
            tmp = anim_this_f;
            anim_this_f = anim_other_f;
            anim_other_f = tmp;
            anim_this_b = anim_other_b;
        }

        val1 = gEfxHpLutOff[GetAnimPosition(anim_this_f)];
        val2 = gEfxHpLutOff[GetAnimPosition(anim_this_f)];
        val2++;
    
        val1 = GetEfxHp(val1 * 2 + GetAnimPosition(anim_this_f));
        val2 = GetEfxHp(val2 * 2 + GetAnimPosition(anim_this_f));

        if (val1 != val2)
        {
            NewEfxHpBar(anim_this_f);

            if (CheckRoundCrit(anim_other_f) == true)
                NewEfxHitQuake(anim_this_f, anim_other_f, quake_crit);
            else
                NewEfxHitQuake(anim_this_f, anim_other_f, quake_normal);
            
            NewEfxFlashHpBar(anim_this_f, 0, 5);
            NewEfxFlashUnit(anim_this_f, 0, 8, 0);
        }
        else
        {
            NewEfxNoDamage(anim_this_f, anim_this_b, 0);
        }
        break;

    case EKR_MISS:
        NewEfxAvoid(anim_this_f);
        break;
    }
}

void StartBattleAnimResireHitEffects(struct Anim * anim, int type)
{
    int val1, val2, off;
    struct Anim * anim_other_f, * anim_this_f, * anim_this_b;

    if (GetAnimPosition(anim) == POS_L)
    {
        anim_other_f = MAIN_ANIM_FRONT(POS_R);
        anim_this_f =  MAIN_ANIM_FRONT(POS_L);
        anim_this_b =  MAIN_ANIM_BACK(POS_L);
    }
    else
    {
        anim_other_f = MAIN_ANIM_FRONT(POS_L);
        anim_this_f =  MAIN_ANIM_FRONT(POS_R);
        anim_this_b =  MAIN_ANIM_BACK(POS_R);
    }

    val1 = gEfxHpLutOff[GetAnimPosition(anim_this_f)];
    val2 = gEfxHpLutOff[GetAnimPosition(anim_this_f)];
    val2++;

    {
        val1 = GetEfxHp(val1 * 2 + GetAnimPosition(anim_this_f));
        val2 = GetEfxHp(val2 * 2 + GetAnimPosition(anim_this_f));
    }

    switch (type) {
    case EKR_HITTED:
        if (val1 != val2)
        {
            NewEfxHpBarResire(anim_this_f);

            if (CheckRoundCrit(anim_other_f) == 1)
                NewEfxHitQuake(anim_this_f, anim_other_f, 4);
            else
                NewEfxHitQuake(anim_this_f, anim_other_f, 3);
            
            NewEfxFlashHpBar(anim_this_f, 0, 5);
            NewEfxFlashUnit(anim_this_f, 0, 8, 0);
        }
        else
        {
            gEfxHpBarResireFlag = 2;
            NewEfxNoDamage(anim_this_f, anim_this_b, 1);
        }
        break;

    case EKR_MISS:
        NewEfxAvoid(anim_this_f);
        break;
    }
}

void StartBattleAnimStatusChgHitEffects(struct Anim * anim, int type)
{
    struct Anim * anim_this;

    if (GetAnimPosition(anim) == POS_L)
        anim_this = MAIN_ANIM_FRONT(POS_L);
    else
        anim_this = MAIN_ANIM_FRONT(POS_R);

    switch (type) {
    case EKR_HITTED:
        NewEfxStatusCHG(anim_this);
        break;
    
    case EKR_MISS:
        NewEfxAvoid(anim_this);
        break;
    }
}

struct Anim * EfxCreateFrontAnim(struct Anim * anim, const AnimScr * scr1, const AnimScr * scr2, const AnimScr * scr3, const AnimScr * scr4)
{
    struct Anim * main_anim;

    if (gEkrDistanceType == EKR_DISTANCE_CLOSE)
    {
        if (GetAnimPosition(anim) == POS_L)
        {
            main_anim = BasCreate(scr1, 0x78);
            main_anim->oam2 = OAM2_PAL(0x2) + OAM2_LAYER(0x2) + OAM2_CHR(VRAMOFF_BANIM_SPELL_OBJ / 0x20);
            main_anim->xPosition = anim->xPosition;
            main_anim->yPosition = anim->yPosition;
            return main_anim;
        }
        else
        {
            main_anim = BasCreate(scr2, 0x78);
            main_anim->oam2 = OAM2_PAL(0x2) + OAM2_LAYER(0x2) + OAM2_CHR(VRAMOFF_BANIM_SPELL_OBJ / 0x20);
            main_anim->xPosition = anim->xPosition;
            main_anim->yPosition = anim->yPosition;
            return main_anim;
        }
    }
    else
    {
        if (GetAnimPosition(anim) != POS_L)
        {
            main_anim = BasCreate(scr4, 0x78);
            main_anim->oam2 = OAM2_PAL(0x2) + OAM2_LAYER(0x2) + OAM2_CHR(VRAMOFF_BANIM_SPELL_OBJ / 0x20);
            main_anim->xPosition = anim->xPosition;
            main_anim->yPosition = anim->yPosition;
            return main_anim;
        }
        else
        {
            main_anim = BasCreate(scr3, 0x78);
            main_anim->oam2 = OAM2_PAL(0x2) + OAM2_LAYER(0x2) + OAM2_CHR(VRAMOFF_BANIM_SPELL_OBJ / 0x20);
            main_anim->xPosition = anim->xPosition;
            main_anim->yPosition = anim->yPosition;
            return main_anim;
        }
    }
}

void SpellFx_WriteBgMapUncomp(struct Anim * anim, const u16 * src1, const u16 * src2)
{
    const u16 * buf;

    if (gEkrDistanceType == EKR_DISTANCE_CLOSE)
        buf = src1;
    else
        buf = src2;

    if (GetAnimPosition(anim) == POS_L)
        EfxTmCpyBgHFlip(buf, gBg1Tm, 30, 20, OBPAL_EFX_SPELL_BG, 0x100);
    else
        EfxTmCpyBG(buf, gBg1Tm, 30, 20, OBPAL_EFX_SPELL_BG, 0x100);

    EnableBgSync(BG1_SYNC_BIT);
}

void SpellFx_WriteBgMap(struct Anim * anim, const u16 * src1, const u16 * src2)
{
    u16 * buf;

    if (gEkrDistanceType == EKR_DISTANCE_CLOSE)
        LZ77UnCompWram(src1, gEkrTsaBuffer);
    else
        LZ77UnCompWram(src2, gEkrTsaBuffer);

    buf = gEkrTsaBuffer;
    if (GetAnimPosition(anim) == POS_L)
        EfxTmCpyBgHFlip(buf, gBg1Tm, 30, 20, OBPAL_EFX_SPELL_BG, 0x100);
    else
        EfxTmCpyBG(buf, gBg1Tm, 30, 20, OBPAL_EFX_SPELL_BG, 0x100);

    EnableBgSync(BG1_SYNC_BIT);
}


void SpellFx_WriteBgMapExt(struct Anim * anim, const u16 * src, int width, int height)
{
    LZ77UnCompWram(src, gEkrTsaBuffer);

    if (GetAnimPosition(anim) == POS_L)
        EfxTmCpyBgHFlip(gEkrTsaBuffer, gBg1Tm, width, height, OBPAL_EFX_SPELL_BG, 0x100);
    else
        EfxTmCpyBG(gEkrTsaBuffer, gBg1Tm, width, height, OBPAL_EFX_SPELL_BG, 0x100);

    EnableBgSync(BG1_SYNC_BIT);
}

void SpellFx_RegisterObjGfx(const void * img, u32 size)
{
    u16 * dst = OBJ_VRAM0 + VRAMOFF_BANIM_SPELL_OBJ;
    LZ77UnCompWram(img, gBuf_Banim);
    RegisterDataMove(gBuf_Banim, dst, size);
}

void SpellFx_RegisterObjPal(const u16 * pal, u32 size)
{
    CpuFastCopy(pal, gPal + OBPAL_OFFSET(OBPAL_EFX_SPELL_OBJ), size);
    EnablePalSync();
}

void SpellFx_RegisterBgGfx(const void * img, u32 size)
{
    u16 *dst = (void *)BG_VRAM + VRAMOFF_BANIM_SPELL_BG;
    LZ77UnCompWram(img, gSpellAnimBgfx);
    RegisterDataMove(gSpellAnimBgfx, dst, size);
}

void SpellFx_RegisterBgPal(const u16 * pal, u32 size)
{
    CpuFastCopy(pal, gPal + BGPAL_OFFSET(BGPAL_EFX_SPELL_BG), size);
    EnablePalSync();
}

void func_fe6_08047B10(const u16 * src, u16 * dst, u32 cur, u32 len_src, u32 len_dst)
{
    u32 i;
    for (i = 0; i < len_dst; i++, cur++)
    {
        if (cur >= len_src)
            cur = 0;

        dst[i] = src[cur];
    }
}

void func_fe6_08047B3C(const u16 * src, u16 * dst, u32 cur, u32 len_src, u32 len_dst)
{
    u32 i;
    for (i = 0; i < len_dst; i++, cur++)
    {
        if (cur >= len_src)
            cur = 0;

        dst[i + 0x10] = src[cur];
    }

    EnablePalSync();
}

void func_fe6_08047B6C(const u16 * src, u16 * dst, u32 a, u32 b, u32 c)
{
    u32 i;
    for (i = 0; i < c; i++, a++) {
        
        if (a >= b)
            a = 0;

        dst[i + 0x120] = src[a];
    }

    EnablePalSync();
}

i16 EfxAdvanceFrameLut(i16 *ptime, i16 *pcount, const i16 lut[])
{
    register u16 uframe asm("r4");
    u16 count;
    u16 time;
    int iframe;
    u16 tmp, time2, count2;
    register u32 r6 asm("r6");

    time = *ptime;
    r6 = time;
    if (r6 == 0)
    {
        count = *pcount;
        uframe = lut[count * 2];
        iframe = lut[count * 2];
    
        if (-1 == iframe)
            return -1;
        
        if (-4 == iframe)
            return -4;
        
        if (-2 == iframe)
        {
            *pcount = r6;
            uframe = lut[0];
        }
        else if (-3 == iframe)
        {
            *pcount = count - 1;
            tmp = *pcount;
            uframe = lut[tmp * 2];
        }
    
        count2 = *pcount;
        time2 = lut[count2 * 2 + 1];
        ++*(i16 *)pcount;
        *ptime = time2 - 1;
        return uframe;
    }
    else
    {
        --*ptime;
        return -5;
    }
}

void PutEfxTerrainToLowerLayer(void)
{
    gEfxTerrainLayerLow = true;
}

int EfxGetCamMovDuration(void)
{
    if (gEkrDistanceType == EKR_DISTANCE_FARFAR)
        return 0x18;
    else if (gEkrDistanceType == EKR_DISTANCE_FAR)
        return 0x10;
    else
        return 0x0;
}

void EfxTmFillA(u32 val)
{
    u16 * dst = gTmA_Banim;
    CpuFill32(val, dst, sizeof(gTmA_Banim));
}

void EfxTmFillB(u32 val)
{
    u16 * dst = gTmB_Banim;
    CpuFill32(val, dst, sizeof(gTmB_Banim));
}

void SetEkrFrontAnimPostion(int pos, i16 x, i16 y)
{
    struct Anim * anim;
    u16 ux = x;
    u16 uy = y;

    if (POS_L == pos)
    {
        anim = gAnims[0];
        anim->xPosition = ux;
        anim->yPosition = uy;

        anim = gAnims[1];
        anim->xPosition = ux;
        anim->yPosition = uy;
    }
    else
    {
        anim = gAnims[2];
        anim->xPosition = ux;
        anim->yPosition = uy;

        anim = gAnims[3];
        anim->xPosition = ux;
        anim->yPosition = uy;
    }
}

bool SetupBanim(void)
{
    return _SetupBanim();
}

void BeginAnimsOnBattleAnimations(void)
{
    int ret;

    if (GetBattleAnimArenaFlag() == true)
    {
        BeginAnimsOnBattle_Arena();
        return;
    }

    NewEkrBattleDeamon();
    BasInit();
    ret = GetBanimInitPosReal();
    gEkrInitPosReal = ret;
    NewEkrBattleStarting();

    gAnims[0] = NULL;
    gAnims[1] = NULL;
    gAnims[2] = NULL;
    gAnims[3] = NULL;

    SetMainFunc(OnMainBas);
    SetOnHBlankA(NULL);
}

void EkrMainEndExec(void)
{
    if (GetBattleAnimArenaFlag() == true)
    {
        ExecBattleAnimArenaExit();
        return;
    }

    NewEkrbattleending();
    SetMainFunc(OnMainBas);
}

void OnMainBas(void)
{
    RefreshKeySt(gKeySt);
    ClearSprites();

    Proc_Run(gProcTreeRootArray[1]);

    if (GetGameLock() == 0)
        Proc_Run(gProcTreeRootArray[2]);

    Proc_Run(gProcTreeRootArray[3]);
    Proc_Run(gProcTreeRootArray[5]);

    PutSpriteLayerOam(0);

    Proc_Run(gProcTreeRootArray[4]);

    BasUpdateAll();
    BattleAIS_ExecCommands();

    PutSpriteLayerOam(13);

    gBmSt.main_loop_ended = TRUE;
    gBmSt.main_loop_end_scanline = REG_VCOUNT;

    VBlankIntrWait();
}
