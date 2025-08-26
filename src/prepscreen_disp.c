#include "prelude.h"
#include "proc.h"
#include "hardware.h"
#include "bm.h"
#include "ui.h"
#include "oam.h"
#include "sprite.h"
#include "unitsprite.h"
#include "unitlistscreen.h"
#include "chapterinfo.h"
#include "prepscreen.h"

void PrepMenuFade_Init(struct ProcPrepFade * proc)
{
    int i;
    u16 * src, * dst;

    proc->timer = 0;

    src = gPal;
    dst = gPrepFadePal;

    for (i = 0x200; i != 0; i--)
    {
        *dst = *src;
        src++;
        dst++;
    }
}

void PrepMenuFadeOut_Loop(struct ProcPrepFade * proc)
{
    #define SCALE 0x10
    int i;
    u8 coef = proc->timer;

    SetDispEnable(1, 1, 1, 1, 1);

    for (i = 0; i < 0x200; i++)
    {
        int b_scaled = (gPrepFadePal[i] & RGB5_MASK_B) * coef;
        int b_out = (b_scaled / SCALE) & RGB5_MASK_B;

        int g_scaled = (gPrepFadePal[i] & RGB5_MASK_G) * coef;
        int g_out = (g_scaled / SCALE) & RGB5_MASK_G;

        int r_scaled = (gPrepFadePal[i] & RGB5_MASK_R) * coef;
        int r_out = (r_scaled / SCALE) & RGB5_MASK_R;

        gPal[i] = b_out | g_out | r_out;
    }

    EnablePalSync();
    proc->timer++;
    if (coef == 0x10)
        Proc_Break(proc);

    #undef SCALE
}

void PrepMenuFadeIn_Loop(struct ProcPrepFade * proc)
{
    #define SCALE 0x10
    int i;
    u8 coef = 0x10 - proc->timer;

    for (i = 0; i < 0x200; i++)
    {
        int b_scaled = (gPrepFadePal[i] & RGB5_MASK_B) * coef;
        int b_out = (b_scaled / SCALE) & RGB5_MASK_B;

        int g_scaled = (gPrepFadePal[i] & RGB5_MASK_G) * coef;
        int g_out = (g_scaled / SCALE) & RGB5_MASK_G;

        int r_scaled = (gPrepFadePal[i] & RGB5_MASK_R) * coef;
        int r_out = (r_scaled / SCALE) & RGB5_MASK_R;

        gPal[i] = b_out | g_out | r_out;
    }

    EnablePalSync();
    proc->timer++;
    if (coef == 0)
    {
        SetDispEnable(0, 0, 0, 0, 0);
        Proc_Break(proc);
    }

    #undef SCALE
}

struct ProcScr CONST_DATA ProcScr_PrepMenuFadeOut[] =
{
    PROC_19,
    PROC_CALL(PrepMenuFade_Init),
    PROC_REPEAT(PrepMenuFadeOut_Loop),
    PROC_END,
};

struct ProcScr CONST_DATA ProcScr_PrepMenuFadeIn[] =
{
    PROC_19,
    PROC_CALL(PrepMenuFade_Init),
    PROC_REPEAT(PrepMenuFadeIn_Loop),
    PROC_END,
};

void StartPrepMenuFadeOut(ProcPtr proc)
{
    SpawnProcLocking(ProcScr_PrepMenuFadeOut, proc);
}

void StartPrepMenuFadeIn(ProcPtr proc)
{
    SpawnProcLocking(ProcScr_PrepMenuFadeIn, proc);
}

void func_fe6_0807B8B0(struct PrepScreenDispProc * proc, int idx)
{
    u8 _idx = idx;

    if (proc->pre != _idx)
        proc->pre = _idx;

    proc->unk_44 = TRUE;
}

void func_fe6_0807B8CC(struct PrepScreenDispProc * proc, fu8 x, fu8 y, int chidx)
{
    proc->cursor_x = x;
    proc->cursor_y = y;
    proc->chidx = chidx;
    proc->disp_x = GetChapterInfo(gPlaySt.chapter)->gmap_dispx;
    proc->disp_y = GetChapterInfo(gPlaySt.chapter)->gmap_dispy;
}

void func_fe6_0807B90C(u8 a, u8 b, int c)
{
    u8 _c = c;
    u8 e = ((b / 8) % 6) * 2;

    if (a == 0)
    {
        i8 __c = c;
        if (__c != 0)
        {
            gBg0Tm[TM_OFFSET(0x14, 4)] = e + 0xF240;
            gBg0Tm[TM_OFFSET(0x15, 4)] = e + 0xF241;
        }
        else
        {
            gBg0Tm[TM_OFFSET(0x14, 4)] = 0;
            gBg0Tm[TM_OFFSET(0x15, 4)] = 0;
        }
    }
    else
    {
        i8 __c = c;
        if (__c != 0)
        {
            u16 oam2 = 0xF240;
            gBg0Tm[TM_OFFSET(0x14, 0x13)] = e + 0xFA40;
            gBg0Tm[TM_OFFSET(0x15, 0x13)] = e + 0xFA41;
        }
        else
        {
            gBg0Tm[TM_OFFSET(0x14, 0x13)] = 0;
            gBg0Tm[TM_OFFSET(0x15, 0x13)] = 0;
        }
    }
    EnableBgSync(BG0_SYNC_BIT);
}

/* https://decomp.me/scratch/W8G6F */
#if NONMATCHING
void PrepUnit_DrawSMSAndObjs(struct PrepScreenDispProc * proc)
{
    u8 i;
    int r6, r8;
    u32 x, y;
    i16 ydiff_mod, ydiff_quo;
    u16 uydiff_mod, uydiff_quo;
    int ydiff = proc->proc_parent->yDiff_cur;

#if NONMATCHING
    ydiff_mod = proc->proc_parent->yDiff_cur % 16;
    ydiff_quo = proc->proc_parent->yDiff_cur / 16;
#else
    int tmp1 = proc->proc_parent->yDiff_cur;
    int tmp2 = -tmp1;
    if ((-tmp1) < 0)
        tmp2 = -tmp1 + 0xF;

    uydiff_mod = ydiff_mod = -tmp1 - ((tmp2 >> 4) << 4);
    uydiff_quo = ydiff_quo = (u8)(proc->proc_parent->yDiff_cur / 16);
#endif

    if (proc->unk_40 != proc->proc_parent->yDiff_cur)
    {
        SetWinEnable(1, 1, 0);
        SetWin1Layers(1, 1, 0, 1, 1);
        SetWin0Layers(1, 1, 1, 1, 1);
        SetWin0Box(0, 0x28, 0xF0, 0x98);
        SetWin1Box(0, 0, 0xF0, 0x28);
        SetWOutLayers(1, 1, 0, 1, 0);
        proc->unk_29 = TRUE;
    }
    else if (proc->unk_29 == TRUE)
    {
        SetWinEnable(1, 0, 0);
        SetWin1Layers(1, 1, 1, 1, 1);
        SetWin0Layers(1, 1, 1, 1, 1);
        SetWin0Box(0, 0x28, 0xF0, 0x98);
        SetWOutLayers(1, 1, 0, 1, 1);
        proc->unk_29 = FALSE;
    }

    x = proc->proc_parent->unk_31;
    if (x != 0xFF)
    {
        u32 y = x;
        u16 yd;
        
        y = y >> 1;
        yd = (u32)ydiff_quo;

        y = y - yd;
        if (y <= 6)
        {
            PutFrozenUiHand(
                (x & 1) * 0x40 + 0x70,
                y * 0x10 + (i16)ydiff_quo + 0x28
            );
        }
    }

    i = 0;
    r6 = (u32)ydiff_quo * 2;
    r8 = (i16)ydiff_mod + 0x28;

    for (; i < 0xE; i++)
    {
        int list_idx, x, y;

        list_idx = r6 + i;
        if (list_idx >= proc->proc_parent->unk_2D)
            continue;

        y = (i >> 1) * 0x10 + r8;
        if (y <= 0x27)
            continue;

        PutUnitSprite(
            3,
            (i & 1) * 0x40 + 0x70,
            y,
            GetUnitFromPrepList(list_idx));
    }

    if (ydiff_quo == 0)
        return;

    for (; i < 0x10; i++)
    {
        int list_idx = r6 + i;
        int y = ydiff_quo + 0x28;

        if (list_idx >= proc->proc_parent->unk_2D)
            continue;

        PutUnitSprite(
            3,
            (i & 1) * 0x40 + 0x70,
            ((i >> 1) * 0x10 + y) & 0xFF,
            GetUnitFromPrepList(list_idx)
        );
    }
}
#else

NAKEDFUNC
void PrepUnit_DrawSMSAndObjs(struct PrepScreenDispProc * proc)
{
asm("\
	.syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #8\n\
	mov sl, r0\n\
	ldr r0, [r0, #0x14]\n\
	adds r0, #0x44\n\
	ldrh r2, [r0]\n\
	rsbs r1, r2, #0\n\
	adds r0, r1, #0\n\
	cmp r1, #0\n\
	bge .L0807B9EA\n\
	adds r0, #0xf\n\
.L0807B9EA:\n\
	asrs r0, r0, #4\n\
	lsls r0, r0, #4\n\
	subs r0, r1, r0\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	str r0, [sp]\n\
	lsrs r0, r2, #4\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	str r0, [sp, #4]\n\
	mov r0, sl\n\
	adds r0, #0x40\n\
	ldrh r0, [r0]\n\
	cmp r0, r2\n\
	beq .L0807BAAC\n\
	ldr r0, .L0807BAA8 @ =gDispIo\n\
	mov ip, r0\n\
	@ SetWinEnable\n\
	movs r0, #0x20\n\
	mov r1, ip\n\
	ldrb r1, [r1, #1]\n\
	orrs r0, r1\n\
	movs r1, #0x40\n\
	orrs r0, r1\n\
	movs r1, #0x7f\n\
	ands r0, r1\n\
	mov r2, ip\n\
	strb r0, [r2, #1]\n\
	@ SetWin1Layers\n\
	mov r1, ip\n\
	adds r1, #0x35\n\
	movs r2, #1\n\
	ldrb r0, [r1]\n\
	orrs r0, r2\n\
	movs r6, #2\n\
	orrs r0, r6\n\
	movs r3, #5\n\
	rsbs r3, r3, #0\n\
	mov sb, r3\n\
	ands r0, r3\n\
	movs r5, #8\n\
	orrs r0, r5\n\
	movs r4, #0x10\n\
	orrs r0, r4\n\
	strb r0, [r1]\n\
	@ SetWin0Layers\n\
	mov r3, ip\n\
	adds r3, #0x34\n\
	ldrb r0, [r3]\n\
	orrs r0, r2\n\
	orrs r0, r6\n\
	movs r1, #4\n\
	orrs r0, r1\n\
	orrs r0, r5\n\
	orrs r0, r4\n\
	strb r0, [r3]\n\
	@ SetWin0Box\n\
	mov r0, ip\n\
	adds r0, #0x2d\n\
	movs r3, #0\n\
	strb r3, [r0]\n\
	adds r0, #4\n\
	movs r1, #0x28\n\
	mov r8, r1\n\
	mov r1, r8\n\
	strb r1, [r0]\n\
	subs r0, #5\n\
	movs r4, #0xf0\n\
	strb r4, [r0]\n\
	mov r1, ip\n\
	adds r1, #0x30\n\
	movs r0, #0x98\n\
	strb r0, [r1]\n\
	@ SetWin1Box\n\
	mov r0, ip\n\
	adds r0, #0x2f\n\
	strb r3, [r0]\n\
	adds r0, #4\n\
	strb r3, [r0]\n\
	subs r0, #5\n\
	strb r4, [r0]\n\
	adds r0, #4\n\
	mov r3, r8\n\
	strb r3, [r0]\n\
	@ SetWOutLayers\n\
	adds r1, #6\n\
	ldrb r0, [r1]\n\
	orrs r2, r0\n\
	orrs r2, r6\n\
	mov r3, sb\n\
	ands r2, r3\n\
	orrs r2, r5\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r2, r0\n\
	strb r2, [r1]\n\
	mov r1, sl\n\
	adds r1, #0x29\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
	b .L0807BB2A\n\
	.align 2, 0\n\
.L0807BAA8: .4byte gDispIo\n\
.L0807BAAC:\n\
	mov r7, sl\n\
	adds r7, #0x29\n\
	ldrb r0, [r7]\n\
	cmp r0, #1\n\
	bne .L0807BB2A\n\
	ldr r1, .L0807BBFC @ =gDispIo\n\
	mov r8, r1\n\
	@ SetWinEnable\n\
	movs r0, #0x20\n\
	ldrb r2, [r1, #1]\n\
	orrs r0, r2\n\
	movs r1, #0x41\n\
	rsbs r1, r1, #0\n\
	ands r0, r1\n\
	movs r1, #0x7f\n\
	ands r0, r1\n\
	mov r3, r8\n\
	strb r0, [r3, #1]\n\
	@ SetWin1Layers\n\
	mov r2, r8\n\
	adds r2, #0x35\n\
	movs r1, #1\n\
	ldrb r0, [r2]\n\
	orrs r0, r1\n\
	movs r6, #2\n\
	orrs r0, r6\n\
	movs r3, #4\n\
	orrs r0, r3\n\
	movs r5, #8\n\
	orrs r0, r5\n\
	movs r4, #0x10\n\
	orrs r0, r4\n\
	strb r0, [r2]\n\
	@ SetWin0Layers\n\
	subs r2, #1\n\
	ldrb r0, [r2]\n\
	orrs r0, r1\n\
	orrs r0, r6\n\
	orrs r0, r3\n\
	orrs r0, r5\n\
	orrs r0, r4\n\
	strb r0, [r2]\n\
	@ SetWin0Box\n\
	mov r0, r8\n\
	adds r0, #0x2d\n\
	movs r3, #0\n\
	strb r3, [r0]\n\
	subs r2, #3\n\
	movs r0, #0x28\n\
	strb r0, [r2]\n\
	subs r2, #5\n\
	movs r0, #0xf0\n\
	strb r0, [r2]\n\
	adds r2, #4\n\
	movs r0, #0x98\n\
	strb r0, [r2]\n\
	@ SetWOutLayers\n\
	adds r2, #6\n\
	ldrb r0, [r2]\n\
	orrs r1, r0\n\
	orrs r1, r6\n\
	movs r0, #5\n\
	rsbs r0, r0, #0\n\
	ands r1, r0\n\
	orrs r1, r5\n\
	orrs r1, r4\n\
	strb r1, [r2]\n\
	strb r3, [r7]\n\
.L0807BB2A:\n\
	mov r1, sl\n\
	ldr r0, [r1, #0x14]\n\
	adds r1, r0, #0\n\
	adds r1, #0x31\n\
	ldrb r0, [r1]\n\
	ldr r2, [sp]\n\
	lsls r7, r2, #0x10\n\
	cmp r0, #0xff\n\
	beq .L0807BB5C\n\
	adds r2, r0, #0\n\
	lsrs r0, r2, #1\n\
	ldr r3, [sp, #4]\n\
	subs r1, r0, r3\n\
	cmp r1, #6\n\
	bhi .L0807BB5C\n\
	movs r0, #1\n\
	ands r2, r0\n\
	lsls r0, r2, #6\n\
	adds r0, #0x70\n\
	lsls r1, r1, #4\n\
	asrs r2, r7, #0x10\n\
	adds r1, r1, r2\n\
	adds r1, #0x28\n\
	bl PutFrozenUiHand\n\
.L0807BB5C:\n\
	movs r5, #0\n\
	ldr r0, [sp, #4]\n\
	lsls r6, r0, #1\n\
	asrs r0, r7, #0x10\n\
	adds r0, #0x28\n\
	mov r8, r0\n\
.L0807BB68:\n\
	adds r3, r6, r5\n\
	mov r1, sl\n\
	ldr r0, [r1, #0x14]\n\
	adds r0, #0x2d\n\
	ldrb r0, [r0]\n\
	cmp r3, r0\n\
	bge .L0807BB9A\n\
	lsrs r0, r5, #1\n\
	lsls r0, r0, #4\n\
	mov r2, r8\n\
	adds r4, r0, r2\n\
	cmp r4, #0x27\n\
	ble .L0807BB9A\n\
	movs r1, #1\n\
	ands r1, r5\n\
	lsls r1, r1, #6\n\
	adds r1, #0x70\n\
	ldr r2, .L0807BC00 @ =gPrepUnitList\n\
	lsls r0, r3, #2\n\
	adds r0, r0, r2\n\
	ldr r3, [r0]\n\
	movs r0, #3\n\
	adds r2, r4, #0\n\
	bl PutUnitSprite\n\
.L0807BB9A:\n\
	adds r0, r5, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r5, r0, #0x18\n\
	cmp r5, #0xd\n\
	bls .L0807BB68\n\
	asrs r0, r7, #0x10\n\
	cmp r0, #0\n\
	beq .L0807BBEA\n\
	cmp r5, #0xf\n\
	bhi .L0807BBEA\n\
	adds r7, r0, #0\n\
	adds r7, #0x28\n\
.L0807BBB2:\n\
	adds r4, r6, r5\n\
	mov r3, sl\n\
	ldr r0, [r3, #0x14]\n\
	adds r0, #0x2d\n\
	ldrb r0, [r0]\n\
	cmp r4, r0\n\
	bge .L0807BBE0\n\
	movs r1, #1\n\
	ands r1, r5\n\
	lsls r1, r1, #6\n\
	adds r1, #0x70\n\
	lsrs r2, r5, #1\n\
	lsls r2, r2, #4\n\
	adds r2, r2, r7\n\
	movs r0, #0xff\n\
	ands r2, r0\n\
	ldr r3, .L0807BC00 @ =gPrepUnitList\n\
	lsls r0, r4, #2\n\
	adds r0, r0, r3\n\
	ldr r3, [r0]\n\
	movs r0, #3\n\
	bl PutUnitSprite\n\
.L0807BBE0:\n\
	adds r0, r5, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r5, r0, #0x18\n\
	cmp r5, #0xf\n\
	bls .L0807BBB2\n\
.L0807BBEA:\n\
	add sp, #8\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
.L0807BBFC: .4byte gDispIo\n\
.L0807BC00: .4byte gPrepUnitList\n\
	.syntax divided\n\
");
}

#endif

u16 CONST_DATA Sprite_08679048[] =
{
    1,
    OAM0_SHAPE_32x16, OAM1_SIZE_32x16, OAM2_CHR(0x380) + OAM2_LAYER(1) + OAM2_PAL(7),
};

u16 CONST_DATA Sprite_08679050[] =
{
    2,
    OAM0_SHAPE_32x16, OAM1_SIZE_32x16, OAM2_CHR(0x3C0) + OAM2_LAYER(1) + OAM2_PAL(7),
    OAM0_SHAPE_32x16, OAM1_SIZE_32x16 + OAM1_X(32), OAM2_CHR(0x3C4) + OAM2_LAYER(1) + OAM2_PAL(7),
};

u16 CONST_DATA Sprite_0867905E[] =
{
    2,
    OAM0_SHAPE_32x8, OAM1_SIZE_32x8 + OAM1_VFLIP, OAM2_CHR(0x398) + OAM2_LAYER(1) + OAM2_PAL(6),
    OAM0_SHAPE_32x16, OAM1_SIZE_32x16 + OAM1_X(32) + OAM1_VFLIP, OAM2_CHR(0x39C) + OAM2_LAYER(1) + OAM2_PAL(6),
};

u16 CONST_DATA Sprite_0867906C[] =
{
    2,
    OAM0_SHAPE_32x8, OAM1_SIZE_32x8 + OAM1_X(32) + OAM1_HFLIP, OAM2_CHR(0x398) + OAM2_LAYER(1) + OAM2_PAL(6),
    OAM0_SHAPE_32x16, OAM1_SIZE_32x16 + OAM1_HFLIP, OAM2_CHR(0x39C) + OAM2_LAYER(1) + OAM2_PAL(6),
};

u16 CONST_DATA Sprite_0867907A[] =
{
    1,
    OAM0_SHAPE_32x16, OAM1_SIZE_32x16, OAM2_CHR(0x398) + OAM2_LAYER(1) + OAM2_PAL(6),
};

u16 CONST_DATA Sprite_08679082[] =
{
    1,
    OAM0_SHAPE_32x16, OAM1_SIZE_32x16, OAM2_CHR(0x39C) + OAM2_LAYER(1) + OAM2_PAL(6),
};

u16 CONST_DATA Sprite_0867908A[] =
{
    2,
    OAM0_SHAPE_32x16, OAM1_SIZE_32x16, OAM2_CHR(0x3C8) + OAM2_LAYER(1) + OAM2_PAL(8),
    OAM0_SHAPE_8x16, OAM1_SIZE_8x16 + OAM1_X(32), OAM2_CHR(0x3CC) + OAM2_LAYER(1) + OAM2_PAL(8),
};

u16 CONST_DATA Sprite_08679098[] =
{
    1,
    OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(0x3D7) + OAM2_LAYER(1) + OAM2_PAL(8),
};

u16 CONST_DATA Sprite_086790A0[] =
{
    4,
    OAM0_SHAPE_16x16, OAM1_SIZE_16x16, OAM2_CHR(0x3DC) + OAM2_LAYER(1) + OAM2_PAL(8),
    OAM0_SHAPE_16x16, OAM1_SIZE_16x16 + OAM1_X(16), OAM2_CHR(0x3DD) + OAM2_LAYER(1) + OAM2_PAL(8),
    OAM0_SHAPE_16x16, OAM1_SIZE_16x16 + OAM1_X(32), OAM2_CHR(0x3DD) + OAM2_LAYER(1) + OAM2_PAL(8),
    OAM0_SHAPE_16x16, OAM1_SIZE_16x16 + OAM1_X(48), OAM2_CHR(0x3DE) + OAM2_LAYER(1) + OAM2_PAL(8),
};

u16 CONST_DATA Sprite_086790BA[] =
{
    5,
    OAM0_SHAPE_16x16, OAM1_SIZE_16x16, OAM2_CHR(0x3DC) + OAM2_LAYER(1) + OAM2_PAL(8),
    OAM0_SHAPE_16x16, OAM1_SIZE_16x16 + OAM1_X(16), OAM2_CHR(0x3DD) + OAM2_LAYER(1) + OAM2_PAL(8),
    OAM0_SHAPE_16x16, OAM1_SIZE_16x16 + OAM1_X(32), OAM2_CHR(0x3DD) + OAM2_LAYER(1) + OAM2_PAL(8),
    OAM0_SHAPE_8x16, OAM1_SIZE_8x16 + OAM1_X(48), OAM2_CHR(0x3DD) + OAM2_LAYER(1) + OAM2_PAL(8),
    OAM0_SHAPE_16x16, OAM1_SIZE_16x16 + OAM1_X(54), OAM2_CHR(0x3DE) + OAM2_LAYER(1) + OAM2_PAL(8),
};

u16 CONST_DATA Sprite_086790DA[] =
{
    1,
    OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(0x3CD) + OAM2_LAYER(1) + OAM2_PAL(8),
};

u16 CONST_DATA Sprite_086790E2[] =
{
    1,
    OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(0x3CE) + OAM2_LAYER(1) + OAM2_PAL(8),
};

u16 CONST_DATA Sprite_086790EA[] =
{
    1,
    OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(0x3CF) + OAM2_LAYER(1) + OAM2_PAL(8),
};

u16 CONST_DATA Sprite_086790F2[] =
{
    1,
    OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(0x3D0) + OAM2_LAYER(1) + OAM2_PAL(8),
};

u16 CONST_DATA Sprite_086790FA[] =
{
    1,
    OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(0x3D1) + OAM2_LAYER(1) + OAM2_PAL(8),
};

u16 CONST_DATA Sprite_08679102[] =
{
    1,
    OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(0x3D2) + OAM2_LAYER(1) + OAM2_PAL(8),
};

u16 CONST_DATA Sprite_0867910A[] =
{
    1,
    OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(0x3D3) + OAM2_LAYER(1) + OAM2_PAL(8),
};

u16 CONST_DATA Sprite_08679112[] =
{
    1,
    OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(0x3D4) + OAM2_LAYER(1) + OAM2_PAL(8),
};

u16 CONST_DATA Sprite_0867911A[] =
{
    1,
    OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(0x3D5) + OAM2_LAYER(1) + OAM2_PAL(8),
};

u16 CONST_DATA Sprite_08679122[] =
{
    1,
    OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(0x3D6) + OAM2_LAYER(1) + OAM2_PAL(8),
};

u16 CONST_DATA Sprite_0867912A[] =
{
    1,
    OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(0x3D8) + OAM2_LAYER(1) + OAM2_PAL(8),
};

u16 CONST_DATA Sprite_08679132[] =
{
    1,
    OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(0x3D9) + OAM2_LAYER(1) + OAM2_PAL(8),
};

u16 CONST_DATA * Sprites_0867913C[12] =
{
    Sprite_086790DA,
    Sprite_086790E2,
    Sprite_086790EA,
    Sprite_086790F2,
    Sprite_086790FA,
    Sprite_08679102,
    Sprite_0867910A,
    Sprite_08679112,
    Sprite_0867911A,
    Sprite_08679122,
    Sprite_0867912A,
    Sprite_08679132,
};

void PrepMenu_DrawGmapSprites(struct PrepScreenDispProc * proc)
{
    u8 order[6] = { 8, 5, 4, 3, 4, 5 };
    u32 unk33;
    int i, xpos, ypos = 0x28;

    if (proc->cursor_y < 0x20)
        ypos = 0x74;

    if ((proc->proc_parent->link_arena_flag & PREPMENU_FLAG_MULTIARENA) == 0 && proc->chidx != 0)
    {
        u8 chidx;
        if ((1 & proc->chidx) != 0)
        {
            xpos = 0xA4;

            PutSpriteExt(4, 0xA6, ypos + 2, Sprite_086790BA, 0);
            PutSpriteExt(4, 0xDC, ypos + 0, Sprites_0867913C[10], 0);
        }
        else
        {
            xpos = 0xA8;

            PutSpriteExt(4, 0xAA, ypos + 2, Sprite_086790A0, 0);
            PutSpriteExt(4, 0xE0, ypos + 0, Sprite_08679098, 0);
        }

        PutSpriteExt(4, xpos, ypos, Sprite_0867908A, 0);

        chidx = proc->chidx / 2;
        if (chidx < 10)
            PutSpriteExt(4, xpos + 0x28, ypos, Sprites_0867913C[11], 0);
        else
            PutSpriteExt(4, xpos + 0x28, ypos, Sprites_0867913C[chidx / 10], 0);

            PutSpriteExt(4, xpos + 0x30, ypos, Sprites_0867913C[(proc->chidx / 2) % 10], 0);
    }

    if ((0xF & proc->unk_33) == 0)
    {
        proc->unk_33 += 0x10;
        if (proc->unk_33 >= 0x60)
            proc->unk_33 = 0;

        proc->unk_33 = (proc->unk_33 & 0xF0) + order[proc->unk_33 >> 4];
    }

    unk33 = proc->unk_33 - 1;
    proc->unk_33 = unk33;

    if (proc->cursor_x < 0x20)
    {
        PutSpriteExt(4, proc->cursor_x + 0x68, proc->cursor_y + 0x26, Sprite_08679048, ((unk33 << 0x18) >> 0x1C) * 4);
        PutSpriteExt(4, proc->cursor_x + 0x1088, proc->cursor_y + 0x1E, Sprite_0867907A, 0);
        PutSpriteExt(4, proc->cursor_x + 0x1068, proc->cursor_y + 0x1E, Sprite_08679082, 0);
        PutSpriteExt(4, proc->cursor_x + 0x68, proc->cursor_y + 0x16, Sprite_08679050, 0);
    }
    else
    {
        PutSpriteExt(4, proc->cursor_x + 0x62, proc->cursor_y + 0x26, Sprite_08679048, ((unk33 << 0x18) >> 0x1C) * 4);
        PutSpriteExt(4, proc->cursor_x + 0x42, proc->cursor_y + 0x1E, Sprite_0867907A, 0);
        PutSpriteExt(4, proc->cursor_x + 0x62, proc->cursor_y + 0x1E, Sprite_08679082, 0);
        PutSpriteExt(4, proc->cursor_x + 0x42, proc->cursor_y + 0x16, Sprite_08679050, 0);
    }

    for (i = 0; i < 10; i++)
    {
        gPal[0x165 + i] = gPal[((proc->unk_3E / 2 + i) & 0xF) + 0x190];
    }
    EnablePalSync();
}

u16 CONST_DATA Sprite_0867916C[] =
{
    2,
    OAM0_SHAPE_32x8, OAM1_SIZE_32x8, OAM2_CHR(0x2C0) + OAM2_LAYER(2),
    OAM0_SHAPE_32x8, OAM1_SIZE_32x8 + OAM1_X(32), OAM2_CHR(0x2C3) + OAM2_LAYER(2),
};

u16 CONST_DATA Sprite_0867917A[] =
{
    1,
    OAM0_SHAPE_32x32 + OAM0_BLEND, OAM1_SIZE_32x32, OAM2_CHR(0x240) + OAM2_LAYER(3),
};

u16 CONST_DATA Sprite_08679182[] =
{
    5,
    OAM0_SHAPE_32x16 + OAM0_BLEND, OAM1_SIZE_32x16, OAM2_CHR(0x24E) + OAM2_LAYER(3),
    OAM0_SHAPE_32x16 + OAM0_BLEND, OAM1_SIZE_32x16 + OAM1_X(32), OAM2_CHR(0x252) + OAM2_LAYER(3),
    OAM0_SHAPE_32x16 + OAM0_BLEND, OAM1_SIZE_32x16 + OAM1_X(64), OAM2_CHR(0x256) + OAM2_LAYER(3),
    OAM0_SHAPE_32x16 + OAM0_BLEND, OAM1_SIZE_32x16 + OAM1_X(96), OAM2_CHR(0x25A) + OAM2_LAYER(3),
    OAM0_SHAPE_16x16 + OAM0_BLEND, OAM1_SIZE_16x16 + OAM1_X(128), OAM2_CHR(0x25E) + OAM2_LAYER(3),
};

u16 CONST_DATA Sprite_086791A2[] =
{
    2,
    OAM0_SHAPE_32x32 + OAM0_AFFINE_ENABLE, OAM1_SIZE_32x32, OAM2_CHR(0x246) + OAM2_LAYER(1),
    OAM0_SHAPE_32x32 + OAM0_AFFINE_ENABLE, OAM1_SIZE_32x32 + OAM1_X(32), OAM2_CHR(0x24A) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_086791B0[] =
{
    2,
    OAM0_SHAPE_32x16 + OAM0_BLEND, OAM1_SIZE_32x16, OAM2_CHR(0x28E) + OAM2_LAYER(3),
    OAM0_SHAPE_32x16 + OAM0_BLEND, OAM1_SIZE_32x16 + OAM1_X(40), OAM2_CHR(0x292) + OAM2_LAYER(3),
};

u16 CONST_DATA Sprite_086791BE[] =
{
    2,
    OAM0_SHAPE_32x16, OAM1_SIZE_32x16, OAM2_CHR(0x29B) + OAM2_LAYER(1),
    OAM0_SHAPE_8x16, OAM1_SIZE_8x16 + OAM1_X(32), OAM2_CHR(0x29F) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_086791CC[] =
{
    1,
    OAM0_SHAPE_32x32 + OAM0_BLEND, OAM1_SIZE_32x32, OAM2_CHR(0x80) + OAM2_LAYER(3),
};

u16 CONST_DATA Sprite_086791D4[] =
{
    3,
    OAM0_SHAPE_32x16 + OAM0_BLEND, OAM1_SIZE_32x16 + OAM1_X(32), OAM2_CHR(0x94) + OAM2_LAYER(3),
    OAM0_SHAPE_32x16 + OAM0_BLEND, OAM1_SIZE_32x16 + OAM1_X(72), OAM2_CHR(0x98) + OAM2_LAYER(3),
    OAM0_SHAPE_16x16 + OAM0_BLEND, OAM1_SIZE_16x16 + OAM1_X(104), OAM2_CHR(0x9C) + OAM2_LAYER(3),
};

u16 CONST_DATA Sprite_086791E8[] =
{
    4,
    OAM0_SHAPE_32x16 + OAM0_BLEND, OAM1_SIZE_32x16 + OAM1_X(8), OAM2_CHR(0x94) + OAM2_LAYER(3),
    OAM0_SHAPE_32x16 + OAM0_BLEND, OAM1_SIZE_32x16 + OAM1_X(48), OAM2_CHR(0xC4) + OAM2_LAYER(3),
    OAM0_SHAPE_32x16 + OAM0_BLEND, OAM1_SIZE_32x16 + OAM1_X(80), OAM2_CHR(0xC8) + OAM2_LAYER(3),
    OAM0_SHAPE_16x16 + OAM0_BLEND, OAM1_SIZE_16x16 + OAM1_X(112), OAM2_CHR(0xCC) + OAM2_LAYER(3),
};

u16 CONST_DATA Sprite_08679202[] =
{
    4,
    OAM0_SHAPE_32x16 + OAM0_BLEND, OAM1_SIZE_32x16, OAM2_CHR(0x84) + OAM2_LAYER(3),
    OAM0_SHAPE_32x16 + OAM0_BLEND, OAM1_SIZE_32x16 + OAM1_X(32), OAM2_CHR(0x88) + OAM2_LAYER(3),
    OAM0_SHAPE_32x16 + OAM0_BLEND, OAM1_SIZE_32x16 + OAM1_X(64), OAM2_CHR(0x8C) + OAM2_LAYER(3),
    OAM0_SHAPE_32x16 + OAM0_BLEND, OAM1_SIZE_32x16 + OAM1_X(96), OAM2_CHR(0x90) + OAM2_LAYER(3),
};

u16 CONST_DATA Sprite_0867921C[] =
{
    2,
    OAM0_SHAPE_32x16 + OAM0_BLEND, OAM1_SIZE_32x16 + OAM1_X(48), OAM2_CHR(0x94) + OAM2_LAYER(3),
    OAM0_SHAPE_32x16 + OAM0_BLEND, OAM1_SIZE_32x16 + OAM1_X(88), OAM2_CHR(0xCE) + OAM2_LAYER(3),
};

/* maybe unused? */
u16 CONST_DATA * Sprites_0867922C[] =
{
    Sprite_086791D4,
    Sprite_086791E8,
    Sprite_08679202,
    Sprite_0867921C,
};

void func_fe6_0807BE88(struct PrepScreenDispProc * proc)
{
    struct PrepMenuProc * parent = proc->proc_parent;

    switch (parent->unk_29) {
    case 0:
        if (parent->submenu_level == 0)
            PutUiHand(0xC, parent->disp_idx[0] * 0x10 + 0x28);
        else if (parent->submenu_level == 1)
            PutUiHand(0xC, parent->disp_idx[parent->submenu_level] * 0x10 + 0x48);
        break;

    case 1:
        if (parent->a_button_actions & 2 && parent->disp_idx[0] == 0)
            PutUiHand(0x6C, 0x8);
        else
        {
            PutUiHand(
                (proc->proc_parent->list_num_cur & 1) * 0x40 + 0x70,
                proc->proc_parent->hand_y_pos * 0x10 + 0x28);

            PutSpriteExt(
                0xD,
                (proc->proc_parent->list_num_cur & 1) * 0x40 + 0x70,
                proc->proc_parent->hand_y_pos * 0x10 + 0x30,
                Sprite_0867916C,
                0x3000);

            gPal[0x13E] = gUnk_02016874.unk_00[(proc->unk_3E / 4) & 0xF];
            EnablePalSync();
        }
        break;

    default:
        break;
    }
}

void func_fe6_0807BF70(struct PrepScreenDispProc * proc)
{
    struct PrepMenuProc * parent = proc->proc_parent;

    if ((parent->a_button_actions & 1) && (parent->cur_counter != 0))
    {
        if (proc->unk_3C <= 0xFF)
            proc->unk_3C += 0x20;
    }
    else
    {
        if (proc->unk_3C != 0)
            proc->unk_3C -= 0x20;
    }

    if (proc->unk_3C > 0x10)
    {
        gPal[0x13D] = *(Pal_0831AAFC + (proc->unk_3E / 8) % 0x10);
        EnablePalSync();

        if ((proc->unk_2A % 10) <= 4)
        {
            SetObjAffineAuto(0, 0, 0x100, proc->unk_3C);
            PutSprite(4, 0x68, 0x1FE, Sprite_086791A2, 0x3000);
        }

        if (proc->unk_2A != 0)
            proc->unk_2A++;
    }
}

void func_fe6_0807C090(struct PrepScreenDispProc * proc)
{
    int i, x;

    SetBlendConfig(0, 0xE, 0x8, 0);
    SetBlendTargetA(0, 0, 0, 0, 1);
    SetBlendTargetB(0, 0, 0, 1, 0);

    for (i = 0; i < 8; i++)
        PutSprite(0xD, 0x20 * i, 4, Sprite_0867917A, 0x2000);

    if (proc->unk_30 != 0)
    {
        proc->unk_3A = (proc->unk_30 * 320 - (proc->unk_30 * 0x10) * proc->unk_30) / 10;

        if (proc->unk_30 < 10)
            proc->unk_30++;
        else
            proc->unk_30 = 0;
    }

    if (proc->proc_parent->unk_2B == 0)
        x = proc->unk_3A - 0xA0;
    else
        x = -proc->unk_3A;

    if (proc->proc_parent->submenu_level == 1)
    {
        if (proc->unk_44 == 0)
        {
            if (proc->unk_46 < 0x100)
                proc->unk_46 += 0x20;
        }
        else
        {
            if (proc->unk_46 >= 0x40)
                proc->unk_46 -= 0x40;
            else
            {
                proc->unk_44 = 0;
                proc->unk_46 = 0;
                func_fe6_08082D54(proc->proc_parent->unk_60, proc->pre);
                proc->unk_48 = 0x60;
            }
        }

        if (proc->proc_parent->submenu_level == 1)
        {
            goto L0;
        }
    }

    PutSprite(0xD, OAM1_X(x + 8), 8, Sprite_08679182, 0x2000);

    if (proc->unk_31 == 0)
    {
        if (proc->proc_parent->link_arena_flag & 1)
            goto L2;

        func_fe6_0807BF70(proc);
    }
    else
    {
        PutSprite(0xD, OAM1_X(0x140 + x), 8, Sprite_086791B0, 0x2000);
    }
    goto L1;

L0:
    func_fe6_08082DA4(proc->proc_parent->unk_60, OAM1_X(0x200 - proc->unk_48), 7, proc->unk_46);
    func_fe6_08082DA4(proc->proc_parent->unk_60, OAM1_X(0x100 - proc->unk_48), 7, proc->unk_46);
    proc->unk_48++;

L1:
    if ((proc->proc_parent->link_arena_flag & 1) == 0)
        return;

L2:
    if (proc->proc_parent->submenu_level != 0)
        return;

    PutSpriteExt(4, OAM1_X((x >> 1) + 0xBC), 8, Sprite_086791BE, 0x4000);
}

void PrepScreenDisp_Init(struct PrepScreenDispProc * proc)
{
    proc->unk_2A = 0;
    proc->unk_3E = 0;
    proc->unk_29 = 0;
    proc->unk_40 = proc->proc_parent->yDiff_cur;

    ForceSyncUnitSpriteSheet();

    proc->unk_2B = proc->proc_parent->disp_idx[proc->proc_parent->submenu_level];
    proc->unk_2C = proc->proc_parent->submenu_level;
    proc->unk_3A = 0xA0;
    proc->unk_2D = proc->proc_parent->unk_29;
    proc->unk_2E = proc->proc_parent->in_unit_sel_screen;
    proc->unk_2F = proc->proc_parent->unk_2B;
    proc->unk_30 = 0;
    proc->unk_32 = 0;
    proc->unk_33 = 0;

    proc->unk_31 = GetPrepScreenMenuCurrentItemIndex(proc->proc_parent);
    proc->unk_44 = 0;
    proc->pre = proc->proc_parent->disp_idx[1];
    proc->unk_48 = 0x60;

    if (((struct PrepMenuProcBug *)(proc->proc_parent))->_bug_34 == 0x100) // ?
    {
        proc->unk_46 = ((struct PrepMenuProcBug *)(proc->proc_parent))->_bug_34;
        func_fe6_08082D54(proc->proc_parent->unk_60, 5);
    }
    else
    {
        proc->unk_46 = 0;
        func_fe6_08082D54(proc->proc_parent->unk_60, GetPrepScreenMenuDispItemIndex(proc->pre, 1) - 5);
    }
}

void PrepScreenDisp_Loop(struct PrepScreenDispProc * proc)
{
    if (proc->proc_parent->in_unit_sel_screen != proc->unk_2E)
        proc->unk_2E = proc->proc_parent->in_unit_sel_screen;

    if (proc->proc_parent->unk_2B != proc->unk_2F)
    {
        proc->unk_31 = GetPrepScreenMenuCurrentItemIndex(proc->proc_parent);
        proc->unk_2F = proc->proc_parent->unk_2B;
        proc->unk_30 = 1;
    }

    SyncUnitSpriteSheet();

    if (proc->proc_parent->in_unit_sel_screen == FALSE)
    {
        PrepMenu_DrawGmapSprites(proc);
    }
    else
    {
        SetBgOffset(2, -0x80, (proc->proc_parent->yDiff_cur - 0x28) & 0xFF);
        PrepUnit_DrawSMSAndObjs(proc);

        if (proc->proc_parent->yDiff_cur != 0)
            func_fe6_0807B90C(0, proc->unk_32, 1);
        else
            func_fe6_0807B90C(0, proc->unk_32, 0);

        if (((proc->proc_parent->yDiff_cur / 0x10 + 7) * 2) < proc->proc_parent->unk_2D)
            func_fe6_0807B90C(1, proc->unk_32, 1);
        else
            func_fe6_0807B90C(1, proc->unk_32, 0);
    }

    func_fe6_0807BE88(proc);
    func_fe6_0807C090(proc);

    if ((++proc->unk_32 / 8) > 5)
        proc->unk_32 = 0;

    proc->unk_40 = proc->proc_parent->yDiff_cur;

    if (proc->unk_2C != proc->proc_parent->submenu_level)
    {
        proc->unk_2C = proc->proc_parent->submenu_level;
    }
    else if (proc->unk_2B != proc->proc_parent->disp_idx[proc->proc_parent->submenu_level])
    {
        if (proc->proc_parent->submenu_level == 0)
        {
            RemoveUiEntryHover(1, proc->unk_2B * 2 + 5, 10);
            PutUiEntryHover(1, proc->proc_parent->disp_idx[proc->proc_parent->submenu_level] * 2 + 5, 10);
        }
        else
        {
            RemoveUiEntryHover(1, proc->unk_2B * 2 + 9, 10);
            PutUiEntryHover(1, proc->proc_parent->disp_idx[proc->proc_parent->submenu_level] * 2 + 9, 10);
        }
        EnableBgSync(BG1_SYNC_BIT);
    }

    proc->unk_2B = proc->proc_parent->disp_idx[proc->proc_parent->submenu_level];
    proc->unk_3E++;
}

void PrepScreenDisp_End(struct PrepScreenDispProc * proc)
{
    return;
}

void PrepScreenDisp_Block(struct PrepScreenDispProc * proc)
{
    return;
}

struct ProcScr CONST_DATA ProcScr_PrepScreenDisp[] = {
    PROC_19,
PROC_LABEL(0),
    PROC_SLEEP(1),
    PROC_CALL(PrepScreenDisp_Init),
PROC_LABEL(1),
    PROC_REPEAT(PrepScreenDisp_Loop),
    PROC_GOTO(5),
PROC_LABEL(2),
    PROC_REPEAT(PrepScreenDisp_Block),
PROC_LABEL(5),
    PROC_CALL(PrepScreenDisp_End),
    PROC_END,
};

ProcPtr StartPrepScreenDisp(ProcPtr parent)
{
    struct PrepScreenDispProc * proc;
    proc = SpawnProc(ProcScr_PrepScreenDisp, parent);
    proc->unk_3C = 0;
}
