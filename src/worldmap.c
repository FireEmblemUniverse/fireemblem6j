#include "prelude.h"
#include "oam.h"
#include "util.h"
#include "sprite.h"
#include "bmio.h"
#include "event.h"
#include "worldmap.h"

u16 CONST_DATA Sprite_0868C2CC[] = {
    1,
    OAM0_SHAPE_8x8, OAM1_SIZE_8x8, 0,
};

u16 CONST_DATA Sprite_0868C2D4[] = {
    1,
    OAM0_SHAPE_16x16 + OAM0_Y(252) + OAM0_AFFINE_ENABLE, OAM1_SIZE_16x16 + OAM1_X(508), 0,
};

u8 CONST_DATA * Pals_0868C2DC[10] = {
    Pal_Wm_082C8874,
    Pal_Wm_082D1BA0,
    Pal_Wm_082AADA4,
    Pal_Wm_082D1964,
    Pal_Wm_082B2380,
    Pal_Wm_082D1964,
    Pal_Wm_082B9E64,
    Pal_Wm_082D1964,
    Pal_Wm_082C1224,
    Pal_Wm_082D1964,
};

EWRAM_OVERLAY(worldmap) u8 gWmImgBuf[0x9600] = {};

u8 * GetCompressedWmPalette(int a, int b)
{
    return Pals_0868C2DC[a * 2 + b];
}

void ApplyCompressedWmPalette(int a, int b)
{
    Decompress(GetCompressedWmPalette(a, b), gBuf);
    ApplyPalettes(gBuf, 0, 0x10);
}

struct ProcScr CONST_DATA ProcScr_WorldMapIntroEvent[] = {
    PROC_SLEEP(1),
    PROC_CALL(StartWmEvent),
    PROC_WHILE(IsEventRunning),
    PROC_END,
};

struct ProcScr CONST_DATA ProcScr_WorldMap[] = {
    PROC_MARK(PROC_MARK_WMSTUFF),
    PROC_CALL(LockBmDisplay),
    PROC_YIELD,
    PROC_CALL(func_fe6_080922D8),
    PROC_START_CHILD_LOCKING(ProcScr_WmRotIntro),
    PROC_REPEAT(func_fe6_080923C4),
    PROC_CALL(StartMidFadeToBlack),
    PROC_REPEAT(WhileFadeExists),
    PROC_CALL(UnlockBmDisplay),
    PROC_CALL(UnlockGame),
    PROC_END,
};

void StartWorldMap(void)
{
    SpawnProc(ProcScr_WorldMap, PROC_TREE_3);
}

void StartWorldMapUnused(void)
{
    SpawnProc(ProcScr_WorldMap, PROC_TREE_3);
}

void func_fe6_080922D8(struct ProcWorldMap * proc)
{
    gDispIo.disp_ct.mode = 4;
    SetDispEnable(0, 0, 1, 0, 1);

    gDispIo.bg0_ct.priority = 0;
    gDispIo.bg1_ct.priority = 1;
    gDispIo.bg2_ct.priority = 2;
    gDispIo.bg3_ct.priority = 3;

    gDispIo.disp_ct.bitmap_frame = 0;

    proc->unk2C = 0;
    proc->unk30 = 0;
    proc->unk34 = 0x3C00;
    proc->unk38 = 0x2800;
    proc->unk44 = 0;
    proc->unk48 = 0x100;
    proc->unk4A = 0x100;
    proc->unk4C = 0;
    proc->unk52 = 0;
    proc->unk4E = 0;
    proc->unk53 = 0;
    proc->unk50 = 0;
    proc->unk54 = 0;

    WmZoomCore(proc->unk2C, proc->unk30, proc->unk34, proc->unk38, proc->unk44, proc->unk48, proc->unk4A);

    ApplyCompressedWmPalette(0, 1);
    Decompress(GetCompressedWmPalette(0, 0), (void *)BG_VRAM);
    ResetWmArrowSt();
}

void func_fe6_080923C4(struct ProcWorldMap * proc) {}

struct ProcScr CONST_DATA ProcScr_WmArrow[] = {
    PROC_MARK(PROC_MARK_WMSTUFF),
    PROC_ONEND(WmArrow_End),
    PROC_SLEEP(1),
    PROC_CALL(WmArrow_Init),
    PROC_REPEAT(WmArrow_Loop),
    PROC_END,
};

void StartWmArrow(int id, int color, int x, int y, int e, int f)
{
    struct ProcWmArrow * proc;

    proc = SpawnProc(ProcScr_WmArrow, PROC_TREE_3);
    proc->conf = GetFreeWmArrowSt();

    if (proc->conf == NULL)
    {
        Proc_End(proc);
        return;
    }

    proc->conf->busy = true;
    proc->conf->eid = id;
    proc->conf->color = color;
    proc->conf->x_base = x;
    proc->conf->y_base = y;
    proc->conf->unk_0C = e;
    proc->conf->unk_08 = f;
}

void EndWmArrow(void)
{
    Proc_EndEach(ProcScr_WmArrow);
}

bool WmArrowExists(void)
{
    if (FindProc(ProcScr_WmArrow) != NULL)
        return true;

    return false;
}

void WmArrow_End(struct ProcWmArrow * proc)
{
    proc->conf->busy = false;
}

void WmArrow_Init(struct ProcWmArrow * proc)
{
    int i;
    struct WmArrowSt * conf = proc->conf;
    int unk = GetWmArrowCount(GetWmArrowConfigBuf(conf->eid));

    conf->amount = unk;
    conf->sqrt_array[0] = 0;

    for (i = 0; i < conf->amount; i++)
    {
        conf->unk_74[i] = (func_fe6_08093288(GetWmArrowConfigBuf(conf->eid), i) + conf->x_base) * 0x100;
        conf->unk_A4[i] = (func_fe6_080932D8(GetWmArrowConfigBuf(conf->eid), i) + conf->y_base) * 0x100;
    }

    for (i = 1; i < conf->amount; i++)
    {
        int arctan;

        int x_diff = conf->unk_74[i] - conf->unk_74[i - 1];
        int y_diff = conf->unk_A4[i] - conf->unk_A4[i - 1];

        int sqrt = Sqrt(x_diff * x_diff + y_diff * y_diff);
        conf->sqrt_array[i] = conf->sqrt_array[i - 1] + sqrt;
        conf->arctan_array[i] = (arctan = ArcTan2(x_diff, y_diff)) / 0x3F;
    }

    conf->unk_10 = conf->sqrt_array[conf->amount - 1];
    conf->unk_03 = conf->unk_10 / conf->unk_08 + 1;

    for (i = 0; i < conf->unk_03; i++)
    {
        conf->unk_244[i] = (conf->unk_0C * i) / (conf->unk_03 - 1);
        conf->unk_DC[i] = 0;
        conf->unk_2E4[i] = 0;
        conf->unk_F0[i] = 0;
    }
}

void PutWmArrowSpriteExt(struct WmArrowSt * conf, int idx)
{
    int chr = OAM2_CHR(conf->unk_294[idx] + 0x20);
    int r2 = chr >> 6;
    int r3 = (chr >> 8) << 8;
    int oam2 = (r2 & 3) * 2;

    if (idx == (conf->unk_03 - 1))
    {
        int pal;

        DrawWmArrowCore(conf->sprite_index, 0x100, 0x100, r3);

        pal = OAM2_PAL(conf->color);
        pal = pal + 0x310;
        oam2 = oam2 + pal;

        PutSpriteExt(
            0xC,
            OAM1_X(conf->x_array[idx] >> 8) | (conf->sprite_index << 9),
            OAM0_Y(conf->y_array[idx] >> 8) | 0x100,
            Sprite_0868C2D4,
            oam2);
    }
    else
    {
        oam2 = OAM2_PAL(conf->color) + 0x323;

        PutSpriteExt(
            0xC,
            OAM1_X(conf->x_array[idx] >> 8),
            OAM0_Y(conf->y_array[idx] >> 8),
            Sprite_0868C2CC,
            oam2);
    }
}

void WmArrow_Loop(struct ProcWmArrow * proc)
{
    int i;
    int r6;
    struct WmArrowSt * conf = proc->conf;

    for (i = 0; i < conf->unk_03; i++)
    {
        switch (conf->unk_F0[i]) {
        case 0:
            r6 = conf->unk_DC[i];

            conf->x_array[i] = conf->unk_74[r6];
            conf->y_array[i] = conf->unk_A4[r6];
            conf->unk_294[i] = conf->arctan_array[r6 + 1];
            conf->unk_1A4[i] = conf->unk_244[i] * gSinLut_u32[(conf->unk_294[i] + 0x100) & 0x3FF] / 0x8000;
            conf->unk_1F4[i] = conf->unk_244[i] * gSinLut_u32[(conf->unk_294[i]) & 0x3FF] / 0x8000;
            conf->unk_F0[i] = 1;

            /* Fall through */

        case 1:
            PutWmArrowSpriteExt(conf, i);

            r6 = conf->unk_DC[i];

            conf->x_array[i] += conf->unk_1A4[i];
            conf->y_array[i] += conf->unk_1F4[i];
            conf->unk_2E4[i] += conf->unk_244[i];

            if (conf->unk_2E4[i] >= (conf->unk_10 * i / (conf->unk_03 - 1)))
            {
                conf->unk_F0[i] = 99;
            }
            else if (conf->unk_2E4[i] >= conf->sqrt_array[r6 + 1])
            {
                conf->unk_DC[i]++;
                conf->unk_F0[i] = 0;
            }
            break;

        case 99:
            PutWmArrowSpriteExt(conf, i);                            
            break;

        default:
            break;
        }
    }
}

void ResetWmArrowSt(void)
{
    int i;

    for (i = 0; i < 3; i++)
    {
        gWmArrowSt[i].busy = false;
        gWmArrowSt[i].sprite_index = i;
    }
}

struct WmArrowSt * GetFreeWmArrowSt(void)
{
    int i;

    for (i = 0; i < 3; i++)
    {
        struct WmArrowSt * st = &gWmArrowSt[i];

        if (st->busy == false)
            return st;
    }
    return NULL;
}

struct ProcScr CONST_DATA ProcScr_0868C3AC[] = {
    PROC_MARK(PROC_MARK_WMSTUFF),
    PROC_REPEAT(func_fe6_0809289C),
    PROC_END,
};

void func_fe6_0809287C(int duration)
{
    struct Proc_0868C3AC * proc;

    proc = SpawnProc(ProcScr_0868C3AC, PROC_TREE_3);
    proc->duration = duration;
    proc->timer = 0;
}

void func_fe6_0809289C(struct Proc_0868C3AC * proc)
{
    proc->timer++;

    if (proc->timer == proc->duration)
        Proc_Break(proc);
}

bool func_fe6_080928C0(void)
{
    if (FindProc(ProcScr_0868C3AC) != NULL)
        return true;

    return false;
}

struct ProcScr CONST_DATA ProcScr_WmZoomTo[] = {
    PROC_MARK(PROC_MARK_WMSTUFF),
    PROC_SLEEP(1),
    PROC_CALL(WmZoomTo_Init),
    PROC_REPEAT(WmZoomTo_Loop),
    PROC_END,
};

void StartWmZoomTo(int x, int y, ProcPtr parent)
{
    struct ProcWmZoom * proc;

    proc = SpawnProc(ProcScr_WmZoomTo, parent);

    proc->wmproc = FindProc(ProcScr_WorldMap);

    proc->ix = x * 0x100;
    proc->iy = y * 0x100;
}

void WmZoomTo_Init(struct ProcWmZoom * proc)
{
    proc->unk_66 = 0;
    proc->unk_68 = 0;
}

void WmZoomTo_Loop(struct ProcWmZoom * proc)
{
    int ret;
    struct ProcWorldMap * wmproc = proc->wmproc;

    wmproc->camera_x = proc->ix;
    wmproc->camera_y = proc->iy;

    switch (proc->unk_66) {
    case 0:
        func_fe6_08092A9C(wmproc->camera_x, wmproc->camera_y);
        proc->unk_66++;
        proc->unk_68 = 0;
        break;

    case 1:
        ret = Interpolate(INTERPOLATE_RCUBIC, 0x100, 0x200, proc->unk_68, 0x20);

        wmproc->unk4A = ret;
        wmproc->unk48 = ret;

        wmproc->unk34 = wmproc->camera_x + 0xFFFF8800;
        wmproc->unk38 = wmproc->camera_y + 0xFFFFB000;

        proc->unk_68++;
        if (proc->unk_68 == 0x21)
        {
            proc->unk_66++;
            proc->unk_68 = 0;
        }
        break;

    case 2:
        if (1 & proc->unk_68)
        {
            ApplyCompressedWmPalette(1, 1);

            wmproc->unk2C = 0;
            wmproc->unk30 = 0;

            wmproc->unk34 = 0x7800;
            wmproc->unk38 = 0x5000;

            wmproc->unk44 = 0;

            wmproc->unk48 = 0x100;
            wmproc->unk4A = 0x100;

            gDispIo.disp_ct.bitmap_frame = true;
        }
        else
        {
            ApplyCompressedWmPalette(0, 1);

            wmproc->unk2C = 0;
            wmproc->unk30 = 0;

            wmproc->unk34 = wmproc->camera_x + 0xFFFF8800;
            wmproc->unk38 = wmproc->camera_y + 0xFFFFB000;

            wmproc->unk44 = 0;

            wmproc->unk48 = 0x200;
            wmproc->unk4A = 0x200;

            gDispIo.disp_ct.bitmap_frame = false;
        }

        proc->unk_68++;
        if (proc->unk_68 == 8)
            Proc_Break(proc);

        break;
    }

    WmZoomCore(wmproc->unk2C, wmproc->unk30, wmproc->unk34, wmproc->unk38, wmproc->unk44, wmproc->unk48, wmproc->unk4A);
}

void func_fe6_08092A9C(int x, int y)
{
    i16 x2, i, w1, x3, x4, h2, h1, y1, y3, y4, x1;
    u8 *dst, *src;

    x = (x >> 8) - 0x78;
    y = (y >> 8) - 0x50;

    w1 = 0xF0 - x;
    x1 = 0xF0 - w1;
    h1 = 0xA0 - y;
    h2 = 0xA0 - h1;
    x2 = w1 + x - 0xF0;
    y1 = h2;
    x3 = 0xF0 - w1;
    y3 = h1 + y - 0xA0;
    x4 = x2;
    y4 = y3;

    Decompress(GetCompressedWmPalette(1, 0), gWmImgBuf);

    for (i = 0; i < h1; i++)
    {
        dst = (u8 *)0x0600A000 + i * 0xF0;
        src = gWmImgBuf + ((y1 + i) * 0xF0 + x1);
        CpuCopy32(src, dst, w1);
    }

    Decompress(GetCompressedWmPalette(2, 0), gWmImgBuf);

    for (i = 0; i < h1; i++)
    {
        dst = (u8 *)0x0600A000 + i * 0xF0 + w1;
        src = gWmImgBuf + ((y1 + i) * 0xF0 + x2);
        CpuCopy32(src, dst, x1);
    }

    Decompress(GetCompressedWmPalette(3, 0), gWmImgBuf);

    for (i = 0; i < h2; i++)
    {
        dst = (u8 *)0x0600A000 + (h1 + i) * 0xF0;
        src = gWmImgBuf + ((y3 + i) * 0xF0 + x3);
        CpuCopy32(src, dst, w1);
    }

    Decompress(GetCompressedWmPalette(4, 0), gWmImgBuf);

    for (i = 0; i < h2; i++)
    {
        dst = (u8 *)0x0600A000 + (h1 + i) * 0xF0 + w1;
        src = gWmImgBuf + ((y4 + i) * 0xF0 + x4);
        CpuCopy32(src, dst, x1);
    }
}

struct ProcScr CONST_DATA ProcScr_WmZoomBack[] = {
    PROC_MARK(PROC_MARK_WMSTUFF),
    PROC_SLEEP(1),
    PROC_CALL(WmZoomBack_Init),
    PROC_REPEAT(WmZoomBack_Loop),
    PROC_END,
};

void StartWmZoomBack(ProcPtr parent)
{
    struct ProcWmZoom * proc;

    proc = SpawnProc(ProcScr_WmZoomBack, parent);
    proc->wmproc = FindProc(ProcScr_WorldMap);
}

void WmZoomBack_Init(struct ProcWmZoom * proc)
{
    proc->unk_66 = 0;
    proc->unk_68 = 0;
}

void WmZoomBack_Loop(struct ProcWmZoom * proc)
{
    int ret;
    struct ProcWorldMap * wmproc = proc->wmproc;

    switch (proc->unk_66) {
    case 0:
        if (1 & proc->unk_68)
        {
            ApplyCompressedWmPalette(1, 1);

            wmproc->unk2C = 0;
            wmproc->unk30 = 0;

            wmproc->unk34 = 0x7800;
            wmproc->unk38 = 0x5000;

            wmproc->unk44 = 0;

            wmproc->unk48 = 0x100;
            wmproc->unk4A = 0x100;

            gDispIo.disp_ct.bitmap_frame = true;
        }
        else
        {
            ApplyCompressedWmPalette(0, 1);

            wmproc->unk2C = 0;
            wmproc->unk30 = 0;

            wmproc->unk34 = wmproc->camera_x + 0xFFFF8800;
            wmproc->unk38 = wmproc->camera_y + 0xFFFFB000;

            wmproc->unk44 = 0;

            wmproc->unk48 = 0x200;
            wmproc->unk4A = 0x200;

            gDispIo.disp_ct.bitmap_frame = false;
        }

        proc->unk_68++;
        if (proc->unk_68 == 7)
        {
            proc->unk_66++;
            proc->unk_68 = 0;
        }
        break;

    case 1:
        ret = Interpolate(INTERPOLATE_RCUBIC, 0x200, 0x100, proc->unk_68, 0x20);

        wmproc->unk4A = ret;
        wmproc->unk48 = ret;

        wmproc->unk34 = wmproc->camera_x + 0xFFFF8800;
        wmproc->unk38 = wmproc->camera_y + 0xFFFFB000;

        proc->unk_68++;
        if (proc->unk_68 == 0x21)
            Proc_Break(proc);

        break;

    default:
        break;
    }

    WmZoomCore(wmproc->unk2C, wmproc->unk30, wmproc->unk34, wmproc->unk38, wmproc->unk44, wmproc->unk48, wmproc->unk4A);
}

bool WmZoomExists(void)
{
    if (FindProc(ProcScr_WmZoomTo) != NULL)
        return true;

    if (FindProc(ProcScr_WmZoomBack) != NULL)
        return true;

    return false;
}

void EndWmZoom(void)
{
    Proc_EndEach(ProcScr_WmZoomTo);
    Proc_EndEach(ProcScr_WmZoomBack);
}

void WmZoomCore(int a, int b, int c, int d, int e, i16 f, i16 g)
{
    int r5 = Div(e, 0x20);
    int r4 = Div(r5, 2);
    int r7;

    if (1 & r5)
        r7 = (gSinLut_u32[r4 & 0x3FF] + gSinLut_u32[(r4 + 1) & 0x3FF]) >> 1;
    else
        r7 =  gSinLut_u32[r4 & 0x3FF];

    if (1 & r5)
        r5 = (gSinLut_u32[(r4 + 0x100) & 0x3FF] + gSinLut_u32[(r4 + 0x101) & 0x3FF]) >> 1;
    else
        r5 =  gSinLut_u32[(r4 + 0x100) & 0x3FF];

    a = a / 0x100;
    b = b / 0x100;
    c = c / 0x100;
    d = d / 0x100;

    gDispIo.bg2pa = ((0x10000 / f * r5) / 0x100) >> 7;
    gDispIo.bg2pb = ((0x10000 / f * r7) / 0x100) >> 7;

    gDispIo.bg2pc = -(((0x10000 /g * r7) / 0x100) >> 7);
    gDispIo.bg2pd = ((0x10000 / g * r5) / 0x100) >> 7;

    gDispIo.bg2x = ((i16)gDispIo.bg2pa) * (a - c) + ((i16)gDispIo.bg2pb) * (b - d) + c * 0x100;
    gDispIo.bg2y = ((i16)gDispIo.bg2pc) * (a - c) + ((i16)gDispIo.bg2pd) * (b - d) + d * 0x100;
}
