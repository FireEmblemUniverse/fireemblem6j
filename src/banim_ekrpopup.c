#include "prelude.h"
#include "proc.h"
#include "item.h"
#include "msg.h"
#include "icon.h"
#include "oam.h"
#include "sound.h"
#include "banim.h"
#include "banim_ekrdragon.h"
#include "constants/icons.h"
#include "constants/songs.h"
#include "constants/msg.h"

EWRAM_OVERLAY(banim) struct ProcEkrPopup *gpProcEkrPopup = NULL;
EWRAM_OVERLAY(banim) int gEkrPopupDone = false;

bool CheckEkrPopupDone(void)
{
    if (gEkrPopupDone == true)
        return true;
    
    return false;
}

void EndEkrPopup(void)
{
    if (gpProcEkrPopup != NULL)
    {
        Proc_End(gpProcEkrPopup);
        gpProcEkrPopup = NULL;
    }
}

void EfxPlaySound5AVol100(void)
{
    EfxPlaySE(SONG_5A, 0x100);
}

void EfxPlaySound5CVol100(void)
{
    EfxPlaySE(SONG_5C, 0x100);
}

#if NONMATCHING
void MakeBattlePopupTileMap(u16 * tm, u16 width)
{
    u32 i;
    u16 * buf = gEkrTsaBuffer;

    tm[0x00] = buf[0x00] + 0x1100;
    tm[0x20] = buf[0x18] + 0x1100;
    tm[0x40] = buf[0x30] + 0x1100;
    tm[0x60] = buf[0x48] + 0x1100;

    for (i = 0; i < width; i++)
    {
        tm[0x01 + i] = buf[0x01 + i] + 0x1100;
        tm[0x21 + i] = buf[0x19 + i] + 0x1100;
        tm[0x41 + i] = buf[0x31 + i] + 0x1100;
        tm[0x61 + i] = buf[0x49 + i] + 0x1100;
    }

    tm[0x01 + i] = buf[0x17] + 0x1100;
    tm[0x21 + i] = buf[0x2F] + 0x1100;
    tm[0x41 + i] = buf[0x47] + 0x1100;
    tm[0x61 + i] = buf[0x5F] + 0x1100;
}
#else
NAKEDFUNC
void MakeBattlePopupTileMap(u16 * tm, u16 width)
{
asm("\
    .syntax unified\n\
    push {r4, r5, r6, r7, lr}\n\
    mov r7, sl\n\
    mov r6, sb\n\
    mov r5, r8\n\
    push {r5, r6, r7}\n\
    sub sp, #4\n\
    mov ip, r0\n\
    lsls r1, r1, #0x10\n\
    lsrs r1, r1, #0x10\n\
    mov sb, r1\n\
    ldr r6, .L0805F278 @ =gEkrTsaBuffer\n\
    ldrh r1, [r6]\n\
    movs r2, #0x88\n\
    lsls r2, r2, #5\n\
    adds r0, r1, r2\n\
    mov r3, ip\n\
    strh r0, [r3]\n\
    mov r1, ip\n\
    adds r1, #0x40\n\
    ldrh r7, [r6, #0x30]\n\
    adds r0, r7, r2\n\
    strh r0, [r1]\n\
    adds r1, #0x40\n\
    adds r0, r6, #0\n\
    adds r0, #0x60\n\
    ldrh r0, [r0]\n\
    adds r0, r0, r2\n\
    strh r0, [r1]\n\
    adds r1, #0x40\n\
    adds r0, r6, #0\n\
    adds r0, #0x90\n\
    ldrh r0, [r0]\n\
    adds r0, r0, r2\n\
    strh r0, [r1]\n\
    movs r0, #0\n\
    mov r8, r0\n\
    cmp r8, sb\n\
    bhs .L0805F22C\n\
    adds r3, #0xc2\n\
    str r3, [sp]\n\
    mov r5, ip\n\
    adds r5, #0x82\n\
    adds r4, r6, #0\n\
    adds r4, #0x62\n\
    subs r3, #0x80\n\
    mov r2, ip\n\
    adds r2, #2\n\
    adds r1, r6, #2\n\
.L0805F1F8:\n\
    ldrh r7, [r1]\n\
    movs r0, #0x88\n\
    lsls r0, r0, #5\n\
    adds r7, r7, r0\n\
    strh r7, [r2]\n\
    ldrh r7, [r1, #0x30]\n\
    adds r7, r7, r0\n\
    strh r7, [r3]\n\
    ldrh r7, [r4]\n\
    adds r7, r7, r0\n\
    strh r7, [r5]\n\
    ldrh r7, [r4, #0x30]\n\
    adds r7, r7, r0\n\
    ldr r0, [sp]\n\
    strh r7, [r0]\n\
    adds r0, #2\n\
    str r0, [sp]\n\
    adds r5, #2\n\
    adds r4, #2\n\
    adds r3, #2\n\
    adds r2, #2\n\
    adds r1, #2\n\
    movs r7, #1\n\
    add r8, r7\n\
    cmp r8, sb\n\
    blo .L0805F1F8\n\
.L0805F22C:\n\
    mov r1, r8\n\
    lsls r0, r1, #1\n\
    mov r2, ip\n\
    adds r1, r0, r2\n\
    ldrh r3, [r6, #0x2e]\n\
    movs r7, #0x88\n\
    lsls r7, r7, #5\n\
    adds r0, r3, r7\n\
    strh r0, [r1, #2]\n\
    adds r2, r1, #0\n\
    adds r2, #0x42\n\
    adds r0, r6, #0\n\
    adds r0, #0x5e\n\
    ldrh r0, [r0]\n\
    adds r3, r7, #0\n\
    adds r0, r0, r3\n\
    strh r0, [r2]\n\
    adds r2, #0x40\n\
    adds r0, r6, #0\n\
    adds r0, #0x8e\n\
    ldrh r0, [r0]\n\
    adds r0, r0, r3\n\
    strh r0, [r2]\n\
    adds r1, #0xc2\n\
    adds r0, r6, #0\n\
    adds r0, #0xbe\n\
    ldrh r0, [r0]\n\
    adds r0, r0, r3\n\
    strh r0, [r1]\n\
    add sp, #4\n\
    pop {r3, r4, r5}\n\
    mov r8, r3\n\
    mov sb, r4\n\
    mov sl, r5\n\
    pop {r4, r5, r6, r7}\n\
    pop {r0}\n\
    bx r0\n\
    .align 2, 0\n\
.L0805F278: .4byte gEkrTsaBuffer\n\
    .syntax divided\n\
");
}
#endif

void DrawBattlePopup(struct ProcEkrPopup * proc, int type, u32 item)
{
    const char * str;
    int x1, x2, x3, x_cursor, x_bg1, width_box;
    struct Text * text;
    struct Anim * anim;

    LZ77UnCompVram(Img_EkrPopup, (void *)BG_VRAM + 0x2000);
    LZ77UnCompWram(Tsa_EkrPopup, (void *)gEkrTsaBuffer);
    InitTextFont(&gBanimFont, (void *)BG_VRAM + 0x20C0, 0x106, 1);
    SetTextDrawNoClear();
    CpuFastCopy(Pal_EkrPopup, gPal + BGPAL_OFFSET(1), 0x20);

    if (type == 0)
    {
        str = DecodeMsg(MSG_POPUP_WexpLvup1);
        x1 = GetStringTextLen(str);
        x2 = x1 + 0x10;

        str = DecodeMsg(MSG_POPUP_WexpLvup2);
        x3 = GetStringTextLen(str) + x2;
    }
    else
    {
        x1 = 0;
        str = GetItemName(item);
        x2 = GetStringTextLen(str) + 0x10;

        str = DecodeMsg(MSG_POPUP_WeaponBroken);
        x3 = GetStringTextLen(str) + x2;
    }

    width_box = (x3 + 7) >> 3;

    MakeBattlePopupTileMap(gBg1Tm, width_box);

    text = gBanimText;
    InitText(text, width_box);

    x_cursor = (width_box * 8 - x3) >> 1;
    Text_SetCursor(text, x_cursor);

    LZ77UnCompVram(Img_EkrUnkPopup, (void *)BG_VRAM + 0x20C0);

    if (type == 0)
    {
        str = DecodeMsg(MSG_POPUP_WexpLvup1);
        Text_SetColor(text, TEXT_COLOR_SYSTEM_WHITE);
        Text_DrawString(text, str);

        Text_Skip(text, 0x10);

        str = DecodeMsg(MSG_POPUP_WexpLvup2);
        Text_SetColor(text, TEXT_COLOR_SYSTEM_WHITE);
        Text_DrawString(text, str);
    }
    else
    {
        Text_Skip(text, 0x10);

        str = GetItemName(item);
        Text_SetColor(text, TEXT_COLOR_SYSTEM_GRAY);
        Text_DrawString(text, str);

        str = DecodeMsg(MSG_POPUP_WeaponBroken);
        Text_SetColor(text, TEXT_COLOR_SYSTEM_WHITE);
        Text_DrawString(text, str);
    }

    x_bg1 = (0xF0 - (width_box + 2) * 8) / 2;
    SetBgOffset(BG_1, -x_bg1, -0x30);
    EnableBgSync(BG1_SYNC_BIT);
    InitIcons();

    if (type == 0)
    {
        ApplyIconPalette(1, 0x12);
        PutIconObjImg(GetItemKind(item) + ICON_ITEM_KIND_BASE, 0x40);
    }
    else
    {
        ApplyIconPalette(0, 0x12);
        PutIconObjImg(GetItemIcon(item), 0x40);
    }

    anim = BasCreate(AnimScr_EkrPopup, 0x96);
    proc->anim = anim;
    anim->oam2 = OAM2_PAL(0x2) + OAM2_LAYER(0x1) + OAM2_CHR(0x0800 / 0x20);;

    anim->xPosition = 8 + x_bg1 + x_cursor + x1;
    anim->yPosition = 0x38;

    EnablePalSync();
    SetBlendNone();
}

struct ProcScr CONST_DATA ProcScr_EkrPopup[] =
{
    PROC_NAME_DEBUG("ekrPopup"),
    PROC_REPEAT(EkrPopup_BeginningPause),
    PROC_REPEAT(EkrPopup_DrawRankUp1),
    PROC_REPEAT(EkrPopup_WaitRankUp1),
    PROC_REPEAT(EkrPopup_DrawRankUp2),
    PROC_REPEAT(EkrPopup_WaitRankUp2),
    PROC_REPEAT(EkrPopup_DrawWeaponBroken1),
    PROC_REPEAT(EkrPopup_WaitWeaponBroken1),
    PROC_REPEAT(EkrPopup_DrawWeaponBroken2),
    PROC_REPEAT(EkrPopup_WaitWeaponBroken2),
    PROC_REPEAT(EkrPopup_EndingPause),
    PROC_REPEAT(EkrPopup_Blocked),
    PROC_END,
};

void NewEkrPopup(void)
{
    struct ProcEkrPopup * proc;

    gpProcEkrPopup = proc = SpawnProc(ProcScr_EkrPopup, PROC_TREE_3);
    gEkrPopupDone = false;

    proc->timer = 0;
    proc->ldebuf = 0;
    proc->lbuff = 0;
    proc->rdebuf = 0;
    proc->rbuff = 0;

    /* No popup in dragon */
    if (CheckEkrDragonWorking() != false)
        return;

    /* No popup in promotion... */
    if (gEkrDistanceType == EKR_DISTANCE_PROMOTION)
        return;

    if (gBanimFactionPal[POS_L] == BANIMPAL_BLUE)
    {
        if (HasBattleUnitGainedWeaponLevel(gpEkrBattleUnitLeft) == true)
            proc->lbuff = gpEkrBattleUnitLeft->weapon_before;

        if (DidBattleUnitBreakWeapon(gpEkrBattleUnitLeft) == true)
            proc->ldebuf = gpEkrBattleUnitLeft->weapon_before;
    }

    if (gBanimFactionPal[POS_R] == BANIMPAL_BLUE)
    {
        if (HasBattleUnitGainedWeaponLevel(gpEkrBattleUnitRight) == true)
            proc->rbuff = gpEkrBattleUnitRight->weapon_before;

        if (DidBattleUnitBreakWeapon(gpEkrBattleUnitRight) == true)
            proc->rdebuf = gpEkrBattleUnitRight->weapon_before;
    }

    if (proc->lbuff + proc->ldebuf + proc->rbuff + proc->rdebuf == 0)
    {
        gEkrPopupDone = true;
        EndEkrPopup();
    }
    else
    {
        SetBgmVolume(0x80);
    }
}

void EkrPopup_BeginningPause(struct ProcEkrPopup * proc)
{
    if (++proc->timer > 16)
        Proc_Break(proc);
}

void EkrPopup_DrawRankUp1(struct ProcEkrPopup * proc)
{
    u32 item = proc->lbuff;

    if (item != 0)
    {
        DrawBattlePopup(proc, 0, item);
        EfxPlaySound5AVol100();

        proc->timer = 0;
        proc->terminator = 0x60;
    }
    Proc_Break(proc);
}

void EkrPopup_WaitRankUp1(struct ProcEkrPopup * proc)
{
    if (proc->lbuff == 0)
    {
        Proc_Break(proc);
        return;
    }
    
    if (++proc->timer > proc->terminator)
    {
        BasRemove(proc->anim);
        SpellFx_ClearBG1();
        Proc_Break(proc);
    }
}

void EkrPopup_DrawRankUp2(struct ProcEkrPopup * proc)
{
    u32 wtype = proc->rbuff;

    if (wtype != 0)
    {
        DrawBattlePopup(proc, 0, wtype);
        EfxPlaySound5AVol100();

        proc->timer = 0;
        proc->terminator = 0x60;
    }

    Proc_Break(proc);
}

void EkrPopup_WaitRankUp2(struct ProcEkrPopup * proc)
{
    if (proc->rbuff == 0)
    {
        Proc_Break(proc);
        return;
    }
    
    if (++proc->timer > proc->terminator)
    {
        BasRemove(proc->anim);
        SpellFx_ClearBG1();
        Proc_Break(proc);
    }
}

void EkrPopup_DrawWeaponBroken1(struct ProcEkrPopup * proc)
{
    u32 item = proc->ldebuf;
    if (item != 0)
    {
        DrawBattlePopup(proc, 1, item);
        EfxPlaySound5CVol100();

        proc->timer = 0;
        proc->terminator = 0x6C;
    }

    Proc_Break(proc);
}

void EkrPopup_WaitWeaponBroken1(struct ProcEkrPopup *proc)
{
    if (proc->ldebuf == 0)
    {
        Proc_Break(proc);
        return;
    }

    if (++proc->timer > proc->terminator)
    {
        BasRemove(proc->anim);
        SpellFx_ClearBG1();
        Proc_Break(proc);
    }
}

void EkrPopup_DrawWeaponBroken2(struct ProcEkrPopup * proc)
{
    u32 item = proc->rdebuf;
    if (item != 0)
    {
        DrawBattlePopup(proc, 1, item);
        EfxPlaySound5CVol100();

        proc->timer = 0;
        proc->terminator = 0x6C;
    }

    Proc_Break(proc);
}

void EkrPopup_WaitWeaponBroken2(struct ProcEkrPopup * proc)
{
    if (proc->rdebuf == 0)
    {
        Proc_Break(proc);
        return;
    }

    if (++proc->timer > proc->terminator)
    {
        proc->timer = 0;
        BasRemove(proc->anim);
        SpellFx_ClearBG1();
        Proc_Break(proc);
    }
}

void EkrPopup_EndingPause(struct ProcEkrPopup * proc)
{
    if (++proc->timer > 0x10)
    {
        gEkrPopupDone = true;
        SetBgmVolume(0x100);
        Proc_Break(proc);
    }
}

void EkrPopup_Blocked(struct ProcEkrPopup * proc) {}
