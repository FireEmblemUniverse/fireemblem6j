#include "prelude.h"
#include "proc.h"
#include "util.h"
#include "icon.h"
#include "hardware.h"
#include "banim.h"
#include "banim_ekrdragon.h"

struct ProcScr CONST_DATA ProcScr_EfxFlashBG[] =
{
    PROC_NAME_DEBUG("efxFlashBG"),
    PROC_MARK(PROC_MARK_PAL_CHG),
    PROC_REPEAT(EfxFlashBg_Loop),
    PROC_REPEAT(EfxFlashRestorePalSync),
    PROC_END,
};

void NewEfxFlashBgWhite(struct Anim * anim, int duartion)
{
    struct ProcEfxFlashing * proc;
    proc = SpawnProc(ProcScr_EfxFlashBG, PROC_TREE_VSYNC);
    proc->anim = anim;
    proc->timer = 0;
    proc->terminator = duartion;
    CpuFastFill16(-1, gEfxPal, PLTT_SIZE);
}

void NewEfxFlashBgRed(struct Anim * anim, int duartion)
{
    struct ProcEfxFlashing * proc;
    proc = SpawnProc(ProcScr_EfxFlashBG, PROC_TREE_VSYNC);
    proc->anim = anim;
    proc->timer = 0;
    proc->terminator = duartion;
    CpuFastFill16(0x001F001F, gEfxPal, PLTT_SIZE);
}

void EfxFlashBg_Loop(struct ProcEfxFlashing * proc)
{
    /**
     * Disable the normal palette sync and use the non-cache buffer
    */
    CpuFastCopy(gEfxPal, (u16 *)PLTT, PLTT_SIZE);
    DisablePalSync();

    if (++proc->timer >= proc->terminator)
        Proc_Break(proc);
}

void EfxFlashRestorePalSync(struct ProcEfxFlashing * proc)
{
    EnablePalSync();
    Proc_Break(proc);
}

struct ProcScr CONST_DATA ProcScr_EfxWhiteIN[] =
{
    PROC_NAME_DEBUG("efxWhiteIN"),
    PROC_REPEAT(EfxWhiteIn_Loop1),
    PROC_REPEAT(EfxWhiteIn_Loop2),
    PROC_REPEAT(EfxBlackInRestorePalSync),
    PROC_END,
};

void NewEfxWhiteIN(struct Anim * anim, int duartion, int duartion2)
{
    struct ProcEfxFlashing * proc;
    proc = SpawnProc(ProcScr_EfxWhiteIN, PROC_TREE_VSYNC);
    proc->anim = anim;
    proc->timer = 0;
    proc->terminator = duartion;
    proc->terminator2 = duartion2;
}

void EfxWhiteIn_Loop1(struct ProcEfxFlashing * proc)
{
    CpuFastCopy(gPal, gEfxPal, PLTT_SIZE);
    EfxPalWhiteInOut(gEfxPal, 0x0, 0x20, 0x10);
    CpuFastCopy(gEfxPal, (u16 *)PLTT, PLTT_SIZE);
    DisablePalSync();

    if (++proc->timer > proc->terminator)
    {
        proc->timer = 0;
        Proc_Break(proc);
    }
}

void EfxWhiteIn_Loop2(struct ProcEfxFlashing * proc)
{
    int ret = Interpolate(INTERPOLATE_LINEAR, 0x10, 0x0, proc->timer, proc->terminator2);
    CpuFastCopy(gPal, gEfxPal, PLTT_SIZE);
    EfxPalWhiteInOut(gEfxPal, 0x0, 0x20, ret);
    CpuFastCopy(gEfxPal, (u16 *)PLTT, PLTT_SIZE);
    DisablePalSync();

    if (++proc->timer > proc->terminator2)
        Proc_Break(proc);
}

void EfxBlackInRestorePalSync(struct ProcEfxFlashing * proc)
{
    EnablePalSync();
    Proc_Break(proc);
}

struct ProcScr CONST_DATA ProcScr_EfxFlashHpBar[] =
{
    PROC_NAME_DEBUG("efxFlashHPBar"),
    PROC_MARK(PROC_MARK_PAL_CHG),
    PROC_REPEAT(EfxFlashHpBar_Pause),
    PROC_REPEAT(EfxFlashHpBar_Loop),
    PROC_REPEAT(EfxFlashHpBar_RestorePal),
    PROC_END,
};

void NewEfxFlashHpBar(struct Anim * anim, int duartion, int duartion2)
{
    struct ProcEfxFlashing * proc;
    u16 _duartion = duartion;
    u16 _duartion2 = duartion2;

    proc = SpawnProc(ProcScr_EfxFlashHpBar, PROC_TREE_4);
    proc->anim = anim;
    proc->timer = 0;
    proc->terminator = _duartion;
    proc->terminator2 = _duartion2;

    /* ? */
    if (_duartion == 0)
        Proc_Break(proc);
}

void EfxFlashHpBar_Pause(struct ProcEfxFlashing * proc)
{
    if (++proc->timer >= proc->terminator)
        Proc_Break(proc);
}

void EfxFlashHpBar_Loop(struct ProcEfxFlashing * proc)
{
    if (GetAnimPosition(proc->anim) == POS_L)
    {
        CpuCopy16(gPalEfxHpBarGreen, gPal + OBPAL_OFFSET(OBPAL_EFXHPBAR_L), 0x20);
    }
    else
    {
        CpuCopy16(gPalEfxHpBarGreen, gPal + OBPAL_OFFSET(OBPAL_EFXHPBAR_R), 0x20);
    }

    EnablePalSync();

    if (++proc->timer >= proc->terminator2)
        Proc_Break(proc);
}

void EfxFlashHpBar_RestorePal(struct ProcEfxFlashing * proc)
{
    if (GetAnimPosition(proc->anim) == POS_L)
    {
        CpuCopy16(
            gPalEfxHpBarPurple + PAL_OFFSET(gBanimFactionPal[POS_L]),
            gPal + OBPAL_OFFSET(OBPAL_EFXHPBAR_L),
            0x20);
    }
    else
    {
        CpuCopy16(
            gPalEfxHpBarPurple + PAL_OFFSET(gBanimFactionPal[POS_R]),
            gPal + OBPAL_OFFSET(OBPAL_EFXHPBAR_R),
            0x20);
    }

    EnablePalSync();
    Proc_Break(proc);
}

struct ProcScr CONST_DATA ProcScr_EfxHpBarColorChange[] =
{
    PROC_NAME_DEBUG("efxHPBarColorChange"),
    PROC_MARK(PROC_MARK_PAL_CHG),
    PROC_REPEAT(EfxHpBarColorChange_Loop),
    PROC_END,
};

void NewEfxHpBarColorChange(struct Anim * anim)
{
    static const u16 frame_conf[] = {
        0x01, 0x02,
        0x02, 0x02,
        0x03, 0x02,
        0x04, 0x02,
        0x05, 0x0A,
        0x04, 0x02,
        0x03, 0x02,
        0x02, 0x02,
        0x01, 0x02,
        0x00, 0x0A,
        -2
    };

    struct ProcEfxHpBarColorChange * proc;
    gpProcEfxHpBarColorChange = proc = SpawnProc(ProcScr_EfxHpBarColorChange, PROC_TREE_3);
    proc->anim = anim;
    proc->timer = 0;
    proc->frame = 0;
    proc->frame_conf = frame_conf;
    proc->frame_state = 0;
    proc->disabled = false;

    EfxSplitColor(
        gPalEfxHpBarPurple + gBanimFactionPal[POS_L] * 0x10,
        gEfxSplitedColorBufA[0],
        0x10);

    EfxSplitColor(
        Pal_081134C4 + gBanimFactionPal[POS_L] * 0x10,
        gEfxSplitedColorBufB[0],
        0x10);

    func_fe6_0805B88C(
        gEfxSplitedColorBufA[0],
        gEfxSplitedColorBufB[0],
        gEfxSplitedColorBufC[0],
        0x10, 5);

    EfxSplitColor(
        gPalEfxHpBarPurple + gBanimFactionPal[POS_R] * 0x10,
        gEfxSplitedColorBufA[1],
        0x10);

    EfxSplitColor(
        Pal_081134C4 + gBanimFactionPal[POS_R] * 0x10,
        gEfxSplitedColorBufB[1],
        0x10);

    func_fe6_0805B88C(
        gEfxSplitedColorBufA[1],
        gEfxSplitedColorBufB[1],
        gEfxSplitedColorBufC[1],
        0x10, 5);
}

void EndEfxHPBarColorChange(void)
{
    Proc_End(gpProcEfxHpBarColorChange);
}

void DisableEfxHpBarColorChange(void)
{
    gpProcEfxHpBarColorChange->disabled = true;
}

void EnableEfxHpBarColorChange(void)
{
    gpProcEfxHpBarColorChange->disabled = false;
}

void EfxHpBarColorChange_Loop(struct ProcEfxHpBarColorChange * proc)
{
    int ret;

    if (proc->disabled == true)
        return;

    ret = EfxAdvanceFrameLut(&proc->timer, (i16 *)&proc->frame, proc->frame_conf);
    if (ret >= 0)
        proc->frame_state = ret;

    EfxDecodeSplitedPalette(
        gPal + OBPAL_OFFSET(OBPAL_EFXHPBAR_L),
        gEfxSplitedColorBufA[0],
        gEfxSplitedColorBufB[0],
        gEfxSplitedColorBufC[0],
        0x10,
        proc->frame_state,
        5
    );

    EfxDecodeSplitedPalette(
        gPal + OBPAL_OFFSET(OBPAL_EFXHPBAR_R),
        gEfxSplitedColorBufA[1],
        gEfxSplitedColorBufB[1],
        gEfxSplitedColorBufC[1],
        0x10,
        proc->frame_state,
        5
    );

    EnablePalSync();
}

struct ProcScr CONST_DATA ProcScr_EfxFlashUnit[] =
{
    PROC_NAME_DEBUG("efxFlashUnit"),
    PROC_MARK(PROC_MARK_PAL_CHG),
    PROC_REPEAT(EfxFlashUnit_Loop),
    PROC_REPEAT(EfxFlashUnit_RestorePal),
    PROC_END,
};

void NewEfxFlashUnit(struct BaSprite * anim, u16 dura1, u16 dura2, int flag)
{
    struct ProcEfxFlashing * proc = SpawnProc(ProcScr_EfxFlashUnit, PROC_TREE_4);
    proc->anim = anim;
    proc->timer = 0;
    proc->terminator = dura1;
    proc->terminator2 = dura2;
    proc->flag = flag;
}

void EfxFlashUnit_Loop(struct ProcEfxFlashing * proc)
{
    u32 ret = GetEkrDragonStateType();

    if (++proc->timer < proc->terminator)
        return;

    if (GetAnimPosition(proc->anim) == POS_L)
    {
        CpuFastCopy(Pal_BanimUnitFlashing, gPal + OBPAL_OFFSET(OBPAL_EFX_UNIT_L), 0x20);

        if (proc->flag == 0)
        {
            if (ret & EDRAGON_TYPE_MANAKETE_L)
                EfxBodyFlashingForDragon(POS_L);

            if (ret & EDRAGON_TYPE_IDUNN_L)
                EfxBodyFlashingForDragon(POS_L);
        }
    }
    else
    {
        CpuFastCopy(Pal_BanimUnitFlashing, gPal + OBPAL_OFFSET(OBPAL_EFX_UNIT_R), 0x20);

        if (proc->flag == 0)
        {
            if (ret & EDRAGON_TYPE_MANAKETE_R)
                EfxBodyFlashingForDragon(POS_R);

            if (ret & EDRAGON_TYPE_IDUNN_R)
                EfxBodyFlashingForDragon(POS_R);
        }
    }

    EnablePalSync();

    if (proc->timer >= proc->terminator2)
        Proc_Break(proc);
}

void EfxFlashUnit_RestorePal(struct ProcEfxFlashing * proc)
{
    u32 ret = GetEkrDragonStateType();

    if (GetAnimPosition(proc->anim) == POS_L)
    {
        CpuFastCopy(gpEfxUnitPaletteBackup[POS_L], gPal + OBPAL_OFFSET(OBPAL_EFX_UNIT_L), 0x20);

        if (proc->flag == 0)
        {
            if (ret & EDRAGON_TYPE_MANAKETE_L)
                RestoreBodyFlashingPalForManakete(POS_L);

            if (ret & EDRAGON_TYPE_IDUNN_L)
                RestoreBodyFlashingPalForIdunn(POS_L);
        }
    }
    else
    {
        CpuFastCopy(gpEfxUnitPaletteBackup[POS_R], gPal + OBPAL_OFFSET(OBPAL_EFX_UNIT_R), 0x20);

        if (proc->flag == 0)
        {
            if (ret & EDRAGON_TYPE_MANAKETE_R)
                RestoreBodyFlashingPalForManakete(POS_R);

            if (ret & EDRAGON_TYPE_IDUNN_R)
                RestoreBodyFlashingPalForIdunn(POS_R);
        }
    }
    EnablePalSync();
    Proc_Break(proc);
}

struct ProcScr CONST_DATA ProcScr_EfxStatusUnit[] =
{
    PROC_NAME_DEBUG("efxStatusUnit"),
    PROC_MARK(PROC_MARK_PAL_CHG),
    PROC_ONEND(EfxStatusUnit_End),
    PROC_REPEAT(EfxStatusUnit_Loop),
    PROC_END,
};

void NewEfxStatusUnit(struct Anim * anim)
{
    struct Unit * unit;
    struct ProcEfxStatusUnit * proc;

    static const u16 frame_config[] = {
        0x00, 0x14,
        0x04, 0x06,
        0x08, 0x05,
        0x0C, 0x06,
        0x10, 0x14,
        0x0C, 0x06,
        0x08, 0x05,
        0x04, 0x06,
        -2
    };

    if (GetAnimPosition(anim) == POS_L)
        unit = &gpEkrBattleUnitLeft->unit;
    else
        unit = &gpEkrBattleUnitRight->unit;

    proc = SpawnProc(ProcScr_EfxStatusUnit, PROC_TREE_3);

    proc->invalid = 0;
    proc->anim = anim;
    proc->timer = 0;
    proc->frame = 0;
    proc->frame_lut = frame_config;
    proc->debuff = unit->status;

    if (gEkrDebugModeMaybe == 1)
        proc->debuff = UNIT_STATUS_NONE;

    proc->debuf_bak = 0;
    proc->blue = 0;
    proc->green = 0;
    proc->red = 0;
    gpProcEfxStatusUnits[GetAnimPosition(anim)] = proc;

    if (GetAnimPosition(anim) == POS_L)
    {
        EfxSplitColor(gpEfxUnitPaletteBackup[POS_L], &gFadeComponents[0], 0x10);
        EfxSplitColorPetrify(gpEfxUnitPaletteBackup[POS_L], &gFadeComponents[0x30], 0x10);
        func_fe6_0805B88C(&gFadeComponents[0], &gFadeComponents[0x30], (void *)&gFadeComponents[0x180], 0x10, 0x10);
    }
    else
    {
        EfxSplitColor(gpEfxUnitPaletteBackup[POS_R], &gFadeComponents[0x60], 0x10);
        EfxSplitColorPetrify(gpEfxUnitPaletteBackup[POS_R], &gFadeComponents[0x90], 0x10);
        func_fe6_0805B88C(&gFadeComponents[0x60], &gFadeComponents[0x90], (void *)&gFadeComponents[0x300], 0x10, 0x10);
    }
}

void EndEfxStatusUnits(struct Anim * anim)
{
    if (gpProcEfxStatusUnits[GetAnimPosition(anim)])
    {
        Proc_End(gpProcEfxStatusUnits[GetAnimPosition(anim)]);
        gpProcEfxStatusUnits[GetAnimPosition(anim)] = NULL;
    }
}

void DisableEfxStatusUnits(struct Anim * anim)
{
    struct ProcEfxStatusUnit ** procs = gpProcEfxStatusUnits;
    procs[GetAnimPosition(anim)]->invalid = true;
}

void EnableEfxStatusUnits(struct Anim * anim)
{
    struct ProcEfxStatusUnit **procs = gpProcEfxStatusUnits;
    procs[GetAnimPosition(anim)]->invalid = false;
}

void SetUnitEfxDebuff(struct Anim * anim, int debuff)
{
    struct ProcEfxStatusUnit ** procs = gpProcEfxStatusUnits;
    procs[GetAnimPosition(anim)]->debuff = debuff;

    if (debuff == UNIT_STATUS_NONE)
        EfxStatusUnitFlashing(anim, 0, 0, 0);
}

u32 GetUnitEfxDebuff(struct Anim * anim)
{
    struct ProcEfxStatusUnit **procs = gpProcEfxStatusUnits;
    return procs[GetAnimPosition(anim)]->debuff;
}

void EfxStatusUnitFlashing(struct Anim * anim, int r, int g, int b)
{
    u32 ret = GetEkrDragonStateType();

    if (GetAnimPosition(anim) == POS_L)
    {
        CpuFastCopy(gpEfxUnitPaletteBackup[POS_L], gPal + OBPAL_OFFSET(OBPAL_EFX_UNIT_L), 0x20);
        EfxPalFlashingInOut(gPal, OBPAL_EFX_UNIT_L + 0x10, 1, r, g, b);

        if (EDRAGON_TYPE_MANAKETE_L & ret)
            RestoreBodyFlashingPalForManakete(POS_L);

        if (EDRAGON_TYPE_IDUNN_L & ret)
            RestoreBodyFlashingPalForIdunn(POS_L);

        if ((EDRAGON_TYPE_IDUNN_L | EDRAGON_TYPE_MANAKETE_L) & ret)
            EfxPalFlashingInOut(gPal, BGPAL_EFXDRAGON_L, 1, r, g, b);
    }
    else
    {
        CpuFastCopy(gpEfxUnitPaletteBackup[POS_R], gPal + OBPAL_OFFSET(OBPAL_EFX_UNIT_R), 0x20);
        EfxPalFlashingInOut(gPal, OBPAL_EFX_UNIT_R + 0x10, 1, r, g, b);

        if (EDRAGON_TYPE_MANAKETE_R & ret)
            RestoreBodyFlashingPalForManakete(POS_R);

        if (EDRAGON_TYPE_IDUNN_R & ret)
            RestoreBodyFlashingPalForIdunn(POS_R);

        if ((EDRAGON_TYPE_IDUNN_R | EDRAGON_TYPE_MANAKETE_R) & ret)
            EfxPalFlashingInOut(gPal, BGPAL_EFXDRAGON_R, 1, r, g, b);
    }
}

void EfxStatusUnit_Loop(struct ProcEfxStatusUnit * proc)
{
    int ret;

    if (GetUnitEfxDebuff(proc->anim) == UNIT_STATUS_NONE || proc->invalid == true)
        return;

    if (proc->debuff != proc->debuf_bak)
    {
        proc->timer = 0;
        proc->frame = 0;
        proc->debuf_bak = proc->debuff;
    }

    ret = EfxAdvanceFrameLut((void *)&proc->timer, (void *)&proc->frame, proc->frame_lut);
    if (ret >= 0) {
        switch (proc->debuff) {
        case UNIT_STATUS_POISON:
            proc->red = ret;
            proc->green = 0;
            proc->blue = ret;
            break;

        case UNIT_STATUS_SLEEP:
            proc->red = 0;
            proc->green = 0;
            proc->blue = ret;
            break;

        case UNIT_STATUS_BERSERK:
            proc->red = ret;
            proc->green = 0;
            proc->blue = 0;
            break;

        case UNIT_STATUS_SILENCED:
        default:
            proc->red = ret;
            proc->green = ret;
            proc->blue = ret;
            break;
        }
    }


    switch (proc->debuff) {
    case UNIT_STATUS_POISON:
    case UNIT_STATUS_SLEEP:
    case UNIT_STATUS_BERSERK:
        EfxStatusUnitFlashing(proc->anim, proc->red, proc->green, proc->blue);
        break;

    case UNIT_STATUS_SILENCED:
        if (GetAnimPosition(proc->anim) == POS_L)
            EfxDecodeSplitedPalette(
                gPal + OBPAL_OFFSET(OBPAL_EFX_UNIT_L),
                gFadeComponents,
                &gFadeComponents[0x30],
                (i16 *)&gFadeComponents[0x180],
                16, proc->red, 16);
        else
            EfxDecodeSplitedPalette(
                gPal + OBPAL_OFFSET(OBPAL_EFX_UNIT_R),
                &gFadeComponents[0x60],
                &gFadeComponents[0x90],
                (i16 *)&gFadeComponents[0x300],
                16, proc->red, 16);
        break;

    default:
        break;
    }

    EnablePalSync();
}

void EfxStatusUnit_End(struct ProcEfxStatusUnit *proc)
{
    u32 ret = GetEkrDragonStateType();

    if (GetAnimPosition(proc->anim) == POS_L)
    {
        CpuFastCopy(gpEfxUnitPaletteBackup[POS_L], gPal + OBPAL_OFFSET(OBPAL_EFX_UNIT_L), 0x20);

        if (EDRAGON_TYPE_MANAKETE_L & ret)
            RestoreBodyFlashingPalForManakete(POS_L);

        if (EDRAGON_TYPE_IDUNN_L & ret)
            RestoreBodyFlashingPalForIdunn(POS_L);
    }
    else
    {
        CpuFastCopy(gpEfxUnitPaletteBackup[POS_R], gPal + OBPAL_OFFSET(OBPAL_EFX_UNIT_R), 0x20);

        if (EDRAGON_TYPE_MANAKETE_R & ret)
            RestoreBodyFlashingPalForManakete(POS_R);

        if (EDRAGON_TYPE_IDUNN_R & ret)
            RestoreBodyFlashingPalForIdunn(POS_R);
    }
    EnablePalSync();
}

struct ProcScr CONST_DATA ProcScr_EfxWeaponIcon[] =
{
    PROC_NAME_DEBUG("efxWeaponIcon"),
    PROC_MARK(PROC_MARK_PAL_CHG),
    PROC_ONEND(EfxWeaponIcon_End),
    PROC_REPEAT(EfxWeaponIcon_Loop),
    PROC_END,
};

void NewEfxWeaponIcon(i16 eff1, i16 eff2)
{
    struct ProcEfxWeaponIcon * proc;

    static const u16 frame_conf[] = {
        0x00, 0x1,
        0x04, 0x2,
        0x07, 0x1,
        0x0A, 0x1,
        0x0D, 0x1,
        0x10, 0x2,
        0x0D, 0x3,
        0x0A, 0x3,
        0x07, 0x4,
        0x04, 0x5,
        0x00, 0x9,
        -2
    };

    proc = SpawnProc(ProcScr_EfxWeaponIcon, PROC_TREE_3);

    proc->timer = 0;
    proc->frame = 0;
    proc->frame_lut = frame_conf;
    proc->frame_state = 0;
    proc->invalid = false;
    proc->eff1 = eff1;
    proc->eff2 = eff2;

    gpProcEfxWeaponIcon = proc;
}

void EndProcEfxWeaponIcon(void)
{
    if (gpProcEfxWeaponIcon != NULL)
    {
        Proc_End(gpProcEfxWeaponIcon);
        gpProcEfxWeaponIcon = NULL;
    }
}

void DisableEfxWeaponIcon(void)
{
#if BUGFIX
    if (!gpProcEfxWeaponIcon)
        return;
#endif

    gpProcEfxWeaponIcon->invalid = true;
}

void EnableEfxWeaponIcon(void)
{
#if BUGFIX
    if (!gpProcEfxWeaponIcon)
        return;
#endif

    gpProcEfxWeaponIcon->invalid = false;
}

void EfxWeaponIcon_Loop(struct ProcEfxWeaponIcon * proc)
{
    int ret;

    if (true == proc->invalid)
        return;
    
    InitIcons();
    ret = EfxAdvanceFrameLut(&proc->timer, (i16 *)&proc->frame, proc->frame_lut);
    if (ret >= 0)
        proc->frame_state = ret;

    if (proc->eff1 != 0)
    {
        ApplyIconPalette(0, OBPAL_EFX_ITEM_L + 0x10);
        EfxPalWhiteInOut(gPal, OBPAL_EFX_ITEM_L + 0x10, 0x1, proc->frame_state);
    }

    if (proc->eff2 != 0)
    {
        ApplyIconPalette(0, OBPAL_EFX_ITEM_R + 0x10);
        EfxPalWhiteInOut(gPal, OBPAL_EFX_ITEM_R + 0x10, 0x1, proc->frame_state);
    }

    EnablePalSync();
}

void EfxWeaponIcon_End(struct ProcEfxWeaponIcon * proc)
{
    InitIcons();

    if (proc->eff1 != 0)
        ApplyIconPalette(0, OBPAL_EFX_ITEM_L + 0x10);
    
    if (proc->eff2 != 0)
        ApplyIconPalette(0, OBPAL_EFX_ITEM_R + 0x10);
    
    EnablePalSync();
}

struct ProcScr CONST_DATA ProcScr_EfxSpellCast[] =
{
    PROC_NAME_DEBUG("efxSpellCast"),
    PROC_MARK(PROC_MARK_PAL_CHG),
    PROC_REPEAT(EfxSpellCast_FlashIN),
    PROC_REPEAT(EfxSpellCast_Pause),
    PROC_REPEAT(EfxSpellCast_FlashOUT),
    PROC_END,
};

void NewEfxSpellCast(void)
{
    struct ProcEfxSpellCast * proc;
    u32 conf = GetEkrDragonStateType();

    if (conf != 0)
        return;

    proc = SpawnProc(ProcScr_EfxSpellCast, PROC_TREE_4);
    proc->done = 0;
    proc->timer = 0;
    proc->terminator = 4;

    if (NULL == gpProcEfxSpellCast)
        CpuFastCopy(gPal + BGPAL_OFFSET(BGPAL_EFXDRAGON_L), gPal_Banim, 0x140);
    else
        Proc_End(gpProcEfxSpellCast);

    gpProcEfxSpellCast = proc;
}

void EndEfxSpellCastAsync(void)
{
    if (NULL == gpProcEfxSpellCast)
        return;
    
    gpProcEfxSpellCast->done = true;
}

void EndEfxSpellCastSync(void)
{
    ProcPtr proc = gpProcEfxSpellCast;

    if (NULL == proc)
        return;
    
    gpProcEfxSpellCast = NULL;

#if BUGFIX
    Proc_End(proc);
#else
    /* .... */
    Proc_End(NULL);
#endif
}

void EfxSpellCast_FlashIN(struct ProcEfxSpellCast * proc)
{
    int val = Interpolate(INTERPOLATE_LINEAR, 0, 0x8, proc->timer, proc->terminator);
    
    CpuFastCopy(gPal_Banim, gPal + BGPAL_OFFSET(BGPAL_EFXDRAGON_L), 0x140);
    EfxPalBlackInOut(gPal, BGPAL_EFXDRAGON_L, 0xA, val);
    EnablePalSync();

    if (++proc->timer == (proc->terminator + 1))
        Proc_Break(proc);
}

void EfxSpellCast_Pause(struct ProcEfxSpellCast * proc)
{
    CpuFastCopy(gPal_Banim, gPal + BGPAL_OFFSET(BGPAL_EFXDRAGON_L), 0x140);
    EfxPalBlackInOut(gPal, BGPAL_EFXDRAGON_L, 0xA, 0x8);

    if (true == proc->done)
    {
        proc->timer = 0;
        Proc_Break(proc);
    }
}

void EfxSpellCast_FlashOUT(struct ProcEfxSpellCast * proc)
{
    int val = Interpolate(INTERPOLATE_LINEAR, 0x8, 0, proc->timer, proc->terminator);

    CpuFastCopy(gPal_Banim, gPal + BGPAL_OFFSET(BGPAL_EFXDRAGON_L), 0x140);
    EfxPalBlackInOut(gPal, BGPAL_EFXDRAGON_L, 0xA, val);
    EnablePalSync();

    if (++proc->timer == (proc->terminator + 1))
    {
        gpProcEfxSpellCast = NULL;
        CpuFastCopy(gPal_Banim, gPal + BGPAL_OFFSET(BGPAL_EFXDRAGON_L), 0x140);
        EnablePalSync();
        Proc_Break(proc);
    }
}
