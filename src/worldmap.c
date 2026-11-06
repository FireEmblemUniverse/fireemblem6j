#include "prelude.h"
#include "oam.h"
#include "util.h"
#include "sprite.h"
#include "bmio.h"
#include "event.h"
#include "worldmap.h"

u16 CONST_DATA Sprite_WmArrowDot[] = {
    1,
    OAM0_SHAPE_8x8, OAM1_SIZE_8x8, 0,
};

u16 CONST_DATA Sprite_WmArrowHead[] = {
    1,
    OAM0_SHAPE_16x16 + OAM0_Y(252) + OAM0_AFFINE_ENABLE, OAM1_SIZE_16x16 + OAM1_X(508), 0,
};

u8 const * CONST_DATA WorldMapGfxTable[10] = {
    Img_WorldMap,
    Pal_WorldMap,
    Img_WorldMapZoomNW,
    Pal_WorldMapZoom,
    Img_WorldMapZoomNE,
    Pal_WorldMapZoom,
    Img_WorldMapZoomSW,
    Pal_WorldMapZoom,
    Img_WorldMapZoomSE,
    Pal_WorldMapZoom,
};

EWRAM_OVERLAY(worldmap) u8 gWmImgBuf[DISPLAY_WIDTH * DISPLAY_HEIGHT] = {};

u8 const * GetWmGfx(int view, int kind)
{
    return WorldMapGfxTable[view * 2 + kind];
}

void ApplyWmPalette(int view, int kind)
{
    Decompress(GetWmGfx(view, kind), gBuf);
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
    PROC_CALL(WorldMap_Init),
    PROC_START_CHILD_LOCKING(ProcScr_WmRotIntro),
    PROC_REPEAT(WorldMap_Loop),
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

void WorldMap_Init(struct ProcWorldMap * proc)
{
    gDispIo.disp_ct.mode = 4;
    SetDispEnable(0, 0, 1, 0, 1);

    gDispIo.bg0_ct.priority = 0;
    gDispIo.bg1_ct.priority = 1;
    gDispIo.bg2_ct.priority = 2;
    gDispIo.bg3_ct.priority = 3;

    gDispIo.disp_ct.bitmap_frame = 0;

    proc->scroll_x = 0;
    proc->scroll_y = 0;
    proc->pivot_x = 0x3C00;
    proc->pivot_y = 0x2800;
    proc->angle = 0;
    proc->scale_x = 0x100;
    proc->scale_y = 0x100;
    proc->unused_4C = 0;
    proc->unused_52 = 0;
    proc->unused_4E = 0;
    proc->unused_53 = 0;
    proc->unused_50 = 0;
    proc->unused_54 = 0;

    WmZoomCore(proc->scroll_x, proc->scroll_y, proc->pivot_x, proc->pivot_y, proc->angle, proc->scale_x, proc->scale_y);

    ApplyWmPalette(WM_VIEW_FULL, WM_GFX_PAL);
    Decompress(GetWmGfx(WM_VIEW_FULL, WM_GFX_IMG), (void *)BG_VRAM);
    ResetWmArrowSt();
}

void WorldMap_Loop(struct ProcWorldMap * proc) {}

struct ProcScr CONST_DATA ProcScr_WmArrow[] = {
    PROC_MARK(PROC_MARK_WMSTUFF),
    PROC_ONEND(WmArrow_End),
    PROC_SLEEP(1),
    PROC_CALL(WmArrow_Init),
    PROC_REPEAT(WmArrow_Loop),
    PROC_END,
};

void StartWmArrow(int id, int color, int x, int y, int speed, int spacing)
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
    proc->conf->speed = speed;
    proc->conf->spacing = spacing;
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
        conf->point_x[i] = (func_fe6_08093288(GetWmArrowConfigBuf(conf->eid), i) + conf->x_base) * 0x100;
        conf->point_y[i] = (func_fe6_080932D8(GetWmArrowConfigBuf(conf->eid), i) + conf->y_base) * 0x100;
    }

    for (i = 1; i < conf->amount; i++)
    {
        int arctan;

        int x_diff = conf->point_x[i] - conf->point_x[i - 1];
        int y_diff = conf->point_y[i] - conf->point_y[i - 1];

        int sqrt = Sqrt(x_diff * x_diff + y_diff * y_diff);
        conf->sqrt_array[i] = conf->sqrt_array[i - 1] + sqrt;
        conf->arctan_array[i] = (arctan = ArcTan2(x_diff, y_diff)) / 0x3F;
    }

    conf->length = conf->sqrt_array[conf->amount - 1];
    conf->dot_count = conf->length / conf->spacing + 1;

    for (i = 0; i < conf->dot_count; i++)
    {
        conf->dot_speed[i] = (conf->speed * i) / (conf->dot_count - 1);
        conf->dot_segment[i] = 0;
        conf->dot_distance[i] = 0;
        conf->dot_state[i] = WM_ARROW_DOT_SEGMENT_START;
    }
}

void PutWmArrowSpriteExt(struct WmArrowSt * conf, int idx)
{
    int chr = OAM2_CHR(conf->dot_angle[idx] + 0x20);
    int r2 = chr >> 6;
    int r3 = (chr >> 8) << 8;
    int oam2 = (r2 & 3) * 2;

    if (idx == (conf->dot_count - 1))
    {
        int pal;

        DrawWmArrowCore(conf->sprite_index, 0x100, 0x100, r3);

        pal = OAM2_PAL(conf->color);
        pal = pal + OBCHR_WM_ARROW_HEAD;
        oam2 = oam2 + pal;

        PutSpriteExt(
            0xC,
            OAM1_X(conf->x_array[idx] >> 8) | (conf->sprite_index << 9),
            OAM0_Y(conf->y_array[idx] >> 8) | OAM0_AFFINE_ENABLE,
            Sprite_WmArrowHead,
            oam2);
    }
    else
    {
        oam2 = OAM2_PAL(conf->color) + OBCHR_WM_ARROW_DOT;

        PutSpriteExt(
            0xC,
            OAM1_X(conf->x_array[idx] >> 8),
            OAM0_Y(conf->y_array[idx] >> 8),
            Sprite_WmArrowDot,
            oam2);
    }
}

void WmArrow_Loop(struct ProcWmArrow * proc)
{
    int i;
    int r6;
    struct WmArrowSt * conf = proc->conf;

    for (i = 0; i < conf->dot_count; i++)
    {
        switch (conf->dot_state[i]) {
        case WM_ARROW_DOT_SEGMENT_START:
            r6 = conf->dot_segment[i];

            conf->x_array[i] = conf->point_x[r6];
            conf->y_array[i] = conf->point_y[r6];
            conf->dot_angle[i] = conf->arctan_array[r6 + 1];
            conf->dot_vx[i] = conf->dot_speed[i] * gSinLut_u32[(conf->dot_angle[i] + 0x100) & 0x3FF] / 0x8000;
            conf->dot_vy[i] = conf->dot_speed[i] * gSinLut_u32[(conf->dot_angle[i]) & 0x3FF] / 0x8000;
            conf->dot_state[i] = WM_ARROW_DOT_MOVING;

            /* Fall through */

        case WM_ARROW_DOT_MOVING:
            PutWmArrowSpriteExt(conf, i);

            r6 = conf->dot_segment[i];

            conf->x_array[i] += conf->dot_vx[i];
            conf->y_array[i] += conf->dot_vy[i];
            conf->dot_distance[i] += conf->dot_speed[i];

            if (conf->dot_distance[i] >= (conf->length * i / (conf->dot_count - 1)))
            {
                conf->dot_state[i] = WM_ARROW_DOT_ARRIVED;
            }
            else if (conf->dot_distance[i] >= conf->sqrt_array[r6 + 1])
            {
                conf->dot_segment[i]++;
                conf->dot_state[i] = WM_ARROW_DOT_SEGMENT_START;
            }
            break;

        case WM_ARROW_DOT_ARRIVED:
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

    for (i = 0; i < WM_ARROW_MAX; i++)
    {
        gWmArrowSt[i].busy = false;
        gWmArrowSt[i].sprite_index = i;
    }
}

struct WmArrowSt * GetFreeWmArrowSt(void)
{
    int i;

    for (i = 0; i < WM_ARROW_MAX; i++)
    {
        struct WmArrowSt * st = &gWmArrowSt[i];

        if (st->busy == false)
            return st;
    }
    return NULL;
}

struct ProcScr CONST_DATA ProcScr_WmWait[] = {
    PROC_MARK(PROC_MARK_WMSTUFF),
    PROC_REPEAT(WmWait_Loop),
    PROC_END,
};

void StartWmWait(int duration)
{
    struct ProcWmWait * proc;

    proc = SpawnProc(ProcScr_WmWait, PROC_TREE_3);
    proc->duration = duration;
    proc->timer = 0;
}

void WmWait_Loop(struct ProcWmWait * proc)
{
    proc->timer++;

    if (proc->timer == proc->duration)
        Proc_Break(proc);
}

bool WmWaitExists(void)
{
    if (FindProc(ProcScr_WmWait) != NULL)
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
    proc->state = 0;
    proc->timer = 0;
}

void WmZoomTo_Loop(struct ProcWmZoom * proc)
{
    int ret;
    struct ProcWorldMap * wmproc = proc->wmproc;

    wmproc->camera_x = proc->ix;
    wmproc->camera_y = proc->iy;

    switch (proc->state) {
    case 0:
        DrawWmZoomedView(wmproc->camera_x, wmproc->camera_y);
        proc->state++;
        proc->timer = 0;
        break;

    case 1:
        ret = Interpolate(INTERPOLATE_RCUBIC, 0x100, 0x200, proc->timer, WM_ZOOM_FRAMES);

        wmproc->scale_y = ret;
        wmproc->scale_x = ret;

        wmproc->pivot_x = wmproc->camera_x - 0x7800;
        wmproc->pivot_y = wmproc->camera_y - 0x5000;

        proc->timer++;
        if (proc->timer == WM_ZOOM_FRAMES + 1)
        {
            proc->state++;
            proc->timer = 0;
        }
        break;

    case 2:
        if (1 & proc->timer)
        {
            ApplyWmPalette(WM_VIEW_ZOOM_NW, WM_GFX_PAL);

            wmproc->scroll_x = 0;
            wmproc->scroll_y = 0;

            wmproc->pivot_x = 0x7800;
            wmproc->pivot_y = 0x5000;

            wmproc->angle = 0;

            wmproc->scale_x = 0x100;
            wmproc->scale_y = 0x100;

            gDispIo.disp_ct.bitmap_frame = true;
        }
        else
        {
            ApplyWmPalette(WM_VIEW_FULL, WM_GFX_PAL);

            wmproc->scroll_x = 0;
            wmproc->scroll_y = 0;

            wmproc->pivot_x = wmproc->camera_x - 0x7800;
            wmproc->pivot_y = wmproc->camera_y - 0x5000;

            wmproc->angle = 0;

            wmproc->scale_x = 0x200;
            wmproc->scale_y = 0x200;

            gDispIo.disp_ct.bitmap_frame = false;
        }

        proc->timer++;
        if (proc->timer == WM_ZOOM_FLICKER_FRAMES)
            Proc_Break(proc);

        break;
    }

    WmZoomCore(wmproc->scroll_x, wmproc->scroll_y, wmproc->pivot_x, wmproc->pivot_y, wmproc->angle, wmproc->scale_x, wmproc->scale_y);
}

void DrawWmZoomedView(int x, int y)
{
    i16 x2, i, w1, x3, x4, h2, h1, y1, y3, y4, x1;
    u8 *dst, *src;

    x = (x >> 8) - DISPLAY_WIDTH / 2;
    y = (y >> 8) - DISPLAY_HEIGHT / 2;

    w1 = DISPLAY_WIDTH - x;
    x1 = DISPLAY_WIDTH - w1;
    h1 = DISPLAY_HEIGHT - y;
    h2 = DISPLAY_HEIGHT - h1;
    x2 = w1 + x - DISPLAY_WIDTH;
    y1 = h2;
    x3 = DISPLAY_WIDTH - w1;
    y3 = h1 + y - DISPLAY_HEIGHT;
    x4 = x2;
    y4 = y3;

    Decompress(GetWmGfx(WM_VIEW_ZOOM_NW, WM_GFX_IMG), gWmImgBuf);

    for (i = 0; i < h1; i++)
    {
        dst = (u8 *)BG_WM_BITMAP_FRAME1 + i * DISPLAY_WIDTH;
        src = gWmImgBuf + ((y1 + i) * DISPLAY_WIDTH + x1);
        CpuCopy32(src, dst, w1);
    }

    Decompress(GetWmGfx(WM_VIEW_ZOOM_NE, WM_GFX_IMG), gWmImgBuf);

    for (i = 0; i < h1; i++)
    {
        dst = (u8 *)BG_WM_BITMAP_FRAME1 + i * DISPLAY_WIDTH + w1;
        src = gWmImgBuf + ((y1 + i) * DISPLAY_WIDTH + x2);
        CpuCopy32(src, dst, x1);
    }

    Decompress(GetWmGfx(WM_VIEW_ZOOM_SW, WM_GFX_IMG), gWmImgBuf);

    for (i = 0; i < h2; i++)
    {
        dst = (u8 *)BG_WM_BITMAP_FRAME1 + (h1 + i) * DISPLAY_WIDTH;
        src = gWmImgBuf + ((y3 + i) * DISPLAY_WIDTH + x3);
        CpuCopy32(src, dst, w1);
    }

    Decompress(GetWmGfx(WM_VIEW_ZOOM_SE, WM_GFX_IMG), gWmImgBuf);

    for (i = 0; i < h2; i++)
    {
        dst = (u8 *)BG_WM_BITMAP_FRAME1 + (h1 + i) * DISPLAY_WIDTH + w1;
        src = gWmImgBuf + ((y4 + i) * DISPLAY_WIDTH + x4);
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
    proc->state = 0;
    proc->timer = 0;
}

void WmZoomBack_Loop(struct ProcWmZoom * proc)
{
    int ret;
    struct ProcWorldMap * wmproc = proc->wmproc;

    switch (proc->state) {
    case 0:
        if (1 & proc->timer)
        {
            ApplyWmPalette(WM_VIEW_ZOOM_NW, WM_GFX_PAL);

            wmproc->scroll_x = 0;
            wmproc->scroll_y = 0;

            wmproc->pivot_x = 0x7800;
            wmproc->pivot_y = 0x5000;

            wmproc->angle = 0;

            wmproc->scale_x = 0x100;
            wmproc->scale_y = 0x100;

            gDispIo.disp_ct.bitmap_frame = true;
        }
        else
        {
            ApplyWmPalette(WM_VIEW_FULL, WM_GFX_PAL);

            wmproc->scroll_x = 0;
            wmproc->scroll_y = 0;

            wmproc->pivot_x = wmproc->camera_x - 0x7800;
            wmproc->pivot_y = wmproc->camera_y - 0x5000;

            wmproc->angle = 0;

            wmproc->scale_x = 0x200;
            wmproc->scale_y = 0x200;

            gDispIo.disp_ct.bitmap_frame = false;
        }

        proc->timer++;
        if (proc->timer == WM_ZOOM_FLICKER_FRAMES - 1)
        {
            proc->state++;
            proc->timer = 0;
        }
        break;

    case 1:
        ret = Interpolate(INTERPOLATE_RCUBIC, 0x200, 0x100, proc->timer, WM_ZOOM_FRAMES);

        wmproc->scale_y = ret;
        wmproc->scale_x = ret;

        wmproc->pivot_x = wmproc->camera_x - 0x7800;
        wmproc->pivot_y = wmproc->camera_y - 0x5000;

        proc->timer++;
        if (proc->timer == WM_ZOOM_FRAMES + 1)
            Proc_Break(proc);

        break;

    default:
        break;
    }

    WmZoomCore(wmproc->scroll_x, wmproc->scroll_y, wmproc->pivot_x, wmproc->pivot_y, wmproc->angle, wmproc->scale_x, wmproc->scale_y);
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

void WmZoomCore(int scroll_x, int scroll_y, int pivot_x, int pivot_y, int angle, i16 scale_x, i16 scale_y)
{
    int r5 = Div(angle, 0x20);
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

    scroll_x = scroll_x / 0x100;
    scroll_y = scroll_y / 0x100;
    pivot_x = pivot_x / 0x100;
    pivot_y = pivot_y / 0x100;

    gDispIo.bg2pa = ((0x10000 / scale_x * r5) / 0x100) >> 7;
    gDispIo.bg2pb = ((0x10000 / scale_x * r7) / 0x100) >> 7;

    gDispIo.bg2pc = -(((0x10000 / scale_y * r7) / 0x100) >> 7);
    gDispIo.bg2pd = ((0x10000 / scale_y * r5) / 0x100) >> 7;

    gDispIo.bg2x = ((i16)gDispIo.bg2pa) * (scroll_x - pivot_x) + ((i16)gDispIo.bg2pb) * (scroll_y - pivot_y) + pivot_x * 0x100;
    gDispIo.bg2y = ((i16)gDispIo.bg2pc) * (scroll_x - pivot_x) + ((i16)gDispIo.bg2pd) * (scroll_y - pivot_y) + pivot_y * 0x100;
}
