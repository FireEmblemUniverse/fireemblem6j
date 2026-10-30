#include "prelude.h"
#include "oam.h"
#include "hardware.h"
#include "util.h"
#include "oam.h"
#include "sprite.h"
#include "bm.h"
#include "bmio.h"
#include "event.h"
#include "sound.h"
#include "talk.h"
#include "mapui.h"
#include "manim.h"
#include "scanline.h"
#include "debugtext.h"
#include "spriteanim.h"
#include "chapterinfo.h"
#include "worldmap.h"
#include "constants/videoalloc.h"
#include "constants/worldmap.h"

void DrawWmArrowCore(u8 id, i16 b, i16 c, int d)
{
    PutSpriteAffine(
        id,
        (b * gSinLut_u32[(d + 0x100) & 0x3FF]) >> 0xF,
        (c * gSinLut_u32[(d) & 0x3FF]) >> 0xF,
        -((gSinLut_u32[(d) & 0x3FF] * b) >> 0xF),
        (gSinLut_u32[(d + 0x100) & 0x3FF] * c) >> 0xF
    );
}

void StartWmEvent(void)
{
    if (ChapterAssets[GetChapterInfo(gPlaySt.chapter)->asset_event_info_wm])
        StartEvent(ChapterAssets[GetChapterInfo(gPlaySt.chapter)->asset_event_info_wm]);
}

void func_fe6_08093114(void)
{
    FadeBgmOut(4);
}

void func_fe6_08093120(void)
{
    FadeBgmOut(1);
}

void SetWmFlag(int index, ProcPtr approc)
{
    struct ProcWmSprite * proc = FindProc(ProcScr_WmSprite);

    if (proc)
        proc->flag_procs[index] = approc;
}

ProcPtr GetWmFlag(int index)
{
    struct ProcWmSprite * proc = FindProc(ProcScr_WmSprite);

    if (proc)
        return proc->flag_procs[index];

    return NULL;
}

void SetWMDot(int index, ProcPtr approc)
{
    struct ProcWmSprite * proc = FindProc(ProcScr_WmSprite);

    if (proc)
        proc->dot_procs[index] = approc;
}

ProcPtr GetWMDot(int index)
{
    struct ProcWmSprite * proc = FindProc(ProcScr_WmSprite);

    if (proc)
        return proc->dot_procs[index];

    return NULL;
}

void SetWmHighlight(int index, ProcPtr approc)
{
    struct ProcWmSprite * proc = FindProc(ProcScr_WmSprite);

    if (proc)
        proc->highlight_procs[index] = approc;
}

ProcPtr GetWmHighlight(int index)
{
    struct ProcWmSprite * proc = FindProc(ProcScr_WmSprite);

    if (proc)
        return proc->highlight_procs[index];

    return NULL;
}

void SetWmMapText(int index, ProcPtr approc)
{
    struct ProcWmSprite * proc = FindProc(ProcScr_WmSprite);

    if (proc)
        proc->text_procs[index] = approc;
}

ProcPtr GetWmMapText(int index)
{
    struct ProcWmSprite * proc = FindProc(ProcScr_WmSprite);

    if (proc)
        return proc->text_procs[index];

    return NULL;
}

CONST_DATA struct WmArrowConf gWmArrowConf[] = {
    { gUnk_WmArrow_Buf4, 0x014A, 0x00DF, 0x00, 0x0A, 0x0080 },
    { gUnk_WmArrow_Buf4, 0x014A, 0x00DF, 0x00, 0x0A, 0x0080 },
    { gUnk_WmArrow_Buf4, 0x014A, 0x00DF, 0x00, 0x08, 0x0080 },
    { gUnk_WmArrow_Buf4, 0x0154, 0x00CF, 0x01, 0x08, 0x0080 },
    { gUnk_WmArrow_Buf4, 0x013E, 0x00B3, 0x02, 0x08, 0x0080 },
    { gUnk_WmArrow_Buf4, 0x0125, 0x00C2, 0x03, 0x08, 0x0080 },
    { gUnk_WmArrow_Buf4, 0x0114, 0x00BC, 0x04, 0x06, 0x0080 },
    { gUnk_WmArrow_Buf4, 0x0106, 0x00B6, 0x05, 0x08, 0x0080 },
    { gUnk_WmArrow_Buf4, 0x00F4, 0x00B3, 0x06, 0x0A, 0x0080 },
    { gUnk_WmArrow_Buf1, 0x00CD, 0x00AC, 0x00, 0x08, 0x0080 },
    { gUnk_WmArrow_Buf1, 0x0095, 0x007E, 0x01, 0x0A, 0x0080 },
    { gUnk_WmArrow_Buf1, 0x0087, 0x0066, 0x02, 0x0A, 0x0080 },
    { gUnk_WmArrow_Buf1, 0x0079, 0x0056, 0x03, 0x0A, 0x0080 },
    { gUnk_WmArrow_Buf5, 0x0066, 0x009A, 0x00, 0x0A, 0x00C0 },
    { gUnk_WmArrow_Buf3, 0x0040, 0x010C, 0x00, 0x0A, 0x00C0 },
    { gUnk_WmArrow_Buf3, 0x00A0, 0x00F8, 0x01, 0x0A, 0x0080 },
    { gUnk_WmArrow_Buf3, 0x00BC, 0x00E6, 0x02, 0x0A, 0x00C0 },
    { gUnk_WmArrow_Buf2, 0x00CD, 0x00AC, 0x05, 0x0A, 0x0080 },
    { gUnk_WmArrow_Buf2, 0x011E, 0x0091, 0x06, 0x0A, 0x0080 },
    { gUnk_WmArrow_Buf2, 0x0167, 0x0090, 0x07, 0x0A, 0x0080 },
    { gUnk_WmArrow_Buf2, 0x016C, 0x008E, 0x07, 0x0A, 0x0080 },
    { gUnk_WmArrow_Buf6, 0x01A6, 0x0092, 0x03, 0x0A, 0x0080 },
    { gUnk_WmArrow_Buf4, 0x01B3, 0x00C9, 0x07, 0x0A, 0x0080 },
    { gUnk_WmArrow_Buf4, 0x018C, 0x00D0, 0x08, 0x0A, 0x0080 },
    { gUnk_WmArrow_Buf4, 0x017C, 0x00E9, 0x09, 0x0A, 0x0080 },
    { gUnk_WmArrow_Buf4, 0x0187, 0x0107, 0x0A, 0x0A, 0x0080 },
    { gUnk_WmArrow_Buf1, 0x0095, 0x007E, 0x04, 0x0A, 0x0080 },
    { gUnk_WmArrow_Buf1, 0x0073, 0x0088, 0x05, 0x0A, 0x0080 },
    { gUnk_WmArrow_Buf1, 0x003D, 0x00C6, 0x06, 0x0A, 0x00C0 },
    { gUnk_WmArrow_Buf2, 0x00CD, 0x00AC, 0x00, 0x0A, 0x0080 },
    { gUnk_WmArrow_Buf2, 0x0107, 0x0056, 0x01, 0x0A, 0x0080 },
    { gUnk_WmArrow_Buf2, 0x0145, 0x004B, 0x02, 0x0A, 0x00C0 },
    { gUnk_WmArrow_Buf2, 0x019B, 0x004E, 0x03, 0x0A, 0x0080 },
    { gUnk_WmArrow_Buf6, 0x01B4, 0x0063, 0x02, 0x0A, 0x00C0 },
    { gUnk_WmArrow_Buf4, 0x0106, 0x00B6, 0x05, 0x0A, 0x0080 },
    { gUnk_WmArrow_Buf1, 0x0079, 0x0056, 0x03, 0x0A, 0x0080 },
    { gUnk_WmArrow_Buf3, 0x001C, 0x0111, 0x00, 0x0A, 0x0080 },
    { gUnk_WmArrow_Buf3, 0x00BD, 0x00E6, 0x02, 0x0A, 0x0080 },
    { gUnk_WmArrow_Buf2, 0x016C, 0x008E, 0x07, 0x0A, 0x0080 },
    { gUnk_WmArrow_Buf2, 0x019B, 0x004E, 0x03, 0x0A, 0x0080 },
    { gUnk_WmArrow_Buf2, 0x01B4, 0x0071, 0x04, 0x0A, 0x0080 },
    { gUnk_WmArrow_Buf6, 0x01B3, 0x00AA, 0x00, 0x0A, 0x0050 },
    { gUnk_WmArrow_Buf6, 0x01B3, 0x00AA, 0x01, 0x0A, 0x00C0 },
    { gUnk_WmArrow_Buf4, 0x0167, 0x00B4, 0x0C, 0x0A, 0x0080 },
    { gUnk_WmArrow_Buf4, 0x00F4, 0x00B4, 0x0D, 0x0A, 0x00C0 },
    { gUnk_WmArrow_Buf4, 0x0139, 0x00BF, 0x0B, 0x06, 0x0080 },
    { gUnk_WmArrow_Buf7, 0x00F4, 0x00B4, 0x00, 0x0A, 0x0080 },
};

const u16 * GetWmArrowConfigBuf(int index)
{
    struct WmArrowConf * _conf = gWmArrowConf;
    struct WmArrowConf * conf = _conf + index;
    const u16 * buf = conf->buf;

    buf = buf + buf[0] / 2;
    buf = buf + buf[conf->unk_08] / 2;

    return buf;
}

int GetWmArrowCount(const u16 * buf)
{
    return buf[0];
}

int func_fe6_08093288(const u16 * buf, int a)
{
    int x = OAM1_X(buf[a * 3 + 2]);
    struct ProcWmSprite * proc = FindProc(ProcScr_WmSprite);

    if (0x100 & x)
        x |= 0xFFFFFE00;

    if (proc->scaling_down == 0)
        x = Div(x, 2);

    return x;
}

int func_fe6_080932D8(const u16 * buf, int a)
{
    int x = OAM0_Y(buf[a * 3 + 1]);
    struct ProcWmSprite * proc = FindProc(ProcScr_WmSprite);

    if (0x80 & x)
        x |= 0xFFFFFF00;

    if (proc->scaling_down == 0)
        x = Div(x, 2);

    return x;
}

struct ProcScr CONST_DATA ProcScr_WmSprite[] =
{
    PROC_CALL(StartWmSpriteDisp),
    PROC_BLOCK,
};

void StartWmSpriteDisp(struct ProcWmSprite * proc)
{
    int i;
    const struct ProcScr * procscr;

    proc->x_off = 0;
    proc->y_off = 0;
    proc->scaling_down = 0;

    procscr = ProcScr_WmSpriteDisp;

    for (i = 0; i < 4; i++)
        proc->flag_procs[i] = NULL;

    for (i = 0; i < 2; i++)
        proc->dot_procs[i] = NULL;

    for (i = 0; i < 2; i++)
        proc->text_procs[i] = NULL;

    for (i = 0; i < 2; i++)
        proc->highlight_procs[i] = NULL;

    SpawnProc(ProcScr_WmSpriteDisp, proc);
}

struct ProcScr CONST_DATA ProcScr_WmSpriteDisp[] =
{
    PROC_CALL(WmSpriteDisp_Init),
    PROC_REPEAT(WmSpriteDisp_Loop),
};

void WmSpriteDisp_Init(struct Proc * proc)
{
    proc->timer1 = 0;
}

void WmSpriteDisp_Loop(struct Proc * proc)
{
    int pal_off;

    u8 pal_table[] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        1, 1, 1, 1, 1, 1,
        2, 2, 2, 2, 2, 2,
        3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
        2, 2, 2, 2, 2, 2,
        1, 1, 1, 1, 1, 1,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        -1
    };

    proc->timer1++;

    if (pal_table[proc->timer1] == (u8)-1)
        proc->timer1 = 0;

    pal_off = pal_table[proc->timer1] * 0x10;

    ApplyPalette(Pal_WmSpriteDisp1 + pal_off, 0x10);
    ApplyPalette(Pal_WmSpriteDisp2 + pal_off, 0x11);
}

void StartWmSprite(void)
{
    Decompress(Img_WorldMapStuff, OBJ_VRAM0 + 0x6200);
    ApplyPalettes(Pal_WorldMapStuff, 0x10, 4);
    ApplyPalettes(Pal_WmMapText, 0x14, 2);
    ResetWmArrowSt();

    SpawnProc(ProcScr_WmSprite, PROC_TREE_3);
    ResetWmSpriteState();
}

bool WmSpriteExists(void)
{
    return Proc_Exists(ProcScr_WmSprite);
}

void EndWmSprite(void)
{
    Proc_EndEachMarked(PROC_MARK_WMSTUFF);
    EndEachSpriteAnimProc();
    EndPutTalkSpriteText();
    Proc_EndEach(ProcScr_WmSprite);
}

void func_fe6_0809347C(int x, int y)
{
    struct ProcWmSprite * proc = FindProc(ProcScr_WmSprite);

    proc->x_off = x - 0x78;
    proc->y_off = y - 0x50;
    proc->scaling_down = true;
}

void ResetWmSpriteState(void)
{
    struct ProcWmSprite * proc = FindProc(ProcScr_WmSprite);

    proc->x_off = 0;
    proc->y_off = 0;
    proc->scaling_down = false;
}

void DisplayWmArrow(int id, int color)
{
    struct ProcWmSprite * proc = FindProc(ProcScr_WmSprite);
    struct WmArrowConf * conf = gWmArrowConf + id;

    int x = conf->x - proc->x_off;
    int y = conf->y - proc->y_off;

    if (proc->scaling_down == 0)
    {
        x = x >> 1;
        y = y >> 1;

        x -= 2;
        y -= 2;
    }

    StartWmArrow(id, color, x, y, conf->unk_0A, conf->unk_09 << 8);
}

void SetupWmTalkBoxGfx(void)
{
    Decompress(Img_WorldMapStuff, OBJ_VRAM0 + 0x6200);
    ApplyPalettes(Pal_WorldMapStuff, 0x10, 4);
    ApplyPalettes(Pal_SystemObjects, 0x1B, 2);
    Decompress(Img_WmDialogueBox, OBJ_VRAM0 + 0x6800);
    ApplyPalette(Pal_WmDialogueBox, 0x19);
}

struct ProcScr CONST_DATA ProcScr_WmZoomIntro[] =
{
    PROC_MARK(PROC_MARK_WMSTUFF),
    PROC_CALL(WmZoomIntro_Init),
    PROC_REPEAT(WmZoomIntro_Loop),
    PROC_END,
};

void StartWmZoomIntro(ProcPtr parent)
{
    SpawnProcLocking(ProcScr_WmZoomIntro, parent);
}

void WmZoomIntro_Init(struct Proc * proc)
{
    proc->unk44 = 0x200;
    proc->unk48 = 0x80;
    proc->timer1 = 0;
}

void WmZoomIntro_Loop(struct Proc * proc)
{
    int val1 = Interpolate(INTERPOLATE_RCUBIC, 0x8000, 0,     proc->timer1, 35);
    int val2 = Interpolate(INTERPOLATE_RCUBIC, 0x400,  0x100, proc->timer1++, 35);

    WmZoomCore(0, 0, 0x7800, 0x5000, val1, val2, val2);

    if (proc->timer1 == 0x28)
        Proc_Break(proc);
}

struct ProcScr CONST_DATA ProcScr_WmRotIntro[] =
{
    PROC_MARK(PROC_MARK_WMSTUFF),
    PROC_ONEND(WmRotIntro_End),
    PROC_CALL(WmRotIntro_Init),
    PROC_REPEAT(WmRotIntro_Loop),
    PROC_END,
};

void WmRotIntro_Init(struct Proc * proc)
{
    proc->timer1 = 0;
    InitScanlineEffect();
    func_fe6_08069C74();

    SetBlendTargetA(1, 1, 1, 1, 1);
    SetBlendBackdropA(1);

    SetWinEnable(1, 0, 0);

    gDispIo.win_ct.win0_enable_blend = 1;
    gDispIo.win_ct.wout_enable_blend = 0;

    SetWin0Layers(1, 1, 1, 1, 1);
    SetWOutLayers(1, 1, 1, 1, 1);

    gDispIo.win_ct.win0_enable_blend = 1;
    gDispIo.win_ct.wout_enable_blend = 0;

    SetBlendBrighten(proc->timer1);
}

void WmRotIntro_Loop(struct Proc * proc)
{
    func_fe6_08069DA4(0x78, 0x50, Interpolate(INTERPOLATE_RCUBIC, 1, 200, proc->timer1, 45));
    SetBlendBrighten(Interpolate(INTERPOLATE_LINEAR, 0x10, 0, proc->timer1, 40));

    if (++proc->timer1 == 40)
        Proc_Break(proc);
}

void WmRotIntro_End(struct Proc * proc)
{
    SetBlendNone();
    SetOnHBlankA(NULL);
    SetWinEnable(0, 0, 0);
}

void StartWmHighlight(int nation, int id)
{
    struct ProcWmHighLight * proc = SpawnProc(ProcScr_WroldMapRmBorder, PROC_TREE_3);

    proc->nation = nation;
    proc->id = id;

    SetWmHighlight(id, proc);
}

struct WmHighlightConfig CONST_DATA Config_WmHighlight[7] =
{
    [WM_HIGHLIGHT_NATION_0] = {
        .img = Img_WmHighlight_Nation1,
        .sprite = ApInfo_WmHighlight_Nation1,
        .x = 0x3E,
        .y = 0x1D,
    },

    [WM_HIGHLIGHT_NATION_1] = {
        .img = Img_WmHighlight_Nation2,
        .sprite = ApInfo_WmHighlight_Nation2,
        .x = 0xC9,
        .y = 0x33,
    },

    [WM_HIGHLIGHT_NATION_2] = {
        .img = Img_WmHighlight_Nation3,
        .sprite = ApInfo_WmHighlight_Nation3,
        .x = 0x40,
        .y = 0x69,
    },

    [WM_HIGHLIGHT_NATION_3] = {
        .img = Img_WmHighlight_Nation4,
        .sprite = ApInfo_WmHighlight_Nation4,
        .x = 0xA0,
        .y = 0x50,
    },

    [WM_HIGHLIGHT_NATION_4] = {
        .img = Img_WmHighlight_Nation5,
        .sprite = ApInfo_WmHighlight_Nation5,
        .x = 0xE5,
        .y = 0x4B,
    },

    [WM_HIGHLIGHT_NATION_5] = {
        .img = Img_WmHighlight_Nation6,
        .sprite = ApInfo_WmHighlight_Nation6,
        .x = 0xB3,
        .y = 0x00,
    },

    [WM_HIGHLIGHT_NATION_6] = {
        .img = Img_WmHighlight_Nation7,
        .sprite = ApInfo_WmHighlight_Nation7,
        .x = 0x62,
        .y = 0x26,
    },
};

struct ProcScr CONST_DATA ProcScr_WroldMapRmBorder[] =
{
    PROC_MARK(PROC_MARK_WMSTUFF),
    PROC_ONEND(WmHighlight_End),
    PROC_YIELD,
    PROC_CALL(WmHighlight_Init),
    PROC_REPEAT(WmHighlight_Loop),
    PROC_END,
};

void WmHighlight_Init(struct ProcWmHighLight * proc)
{
    struct SpriteAnim * sprite_anim;

    Decompress(
        Config_WmHighlight[proc->nation].img,
        proc->id == 0
            ? OBJ_VRAM0 + 0x4000
            : OBJ_VRAM0 + 0x5100);

    ApplyObPalette(Pal_WmHightlight, 0xA);

    sprite_anim = StartSpriteAnim(Config_WmHighlight[proc->nation].sprite, 0xD);

    proc->sprite_anim = sprite_anim;
    sprite_anim->oam2 = proc->id == 0 ? 0xA200 : 0xA288;

    SetBlendConfig(BLEND_EFFECT_NONE, 0, 0x10, 0);
    SetBlendTargetA(0, 0, 0, 0, 1);
    SetBlendTargetB(0, 0, 1, 0, 0);
    SetBlendBackdropB(1);

    proc->ctrl = false;
    proc->unk_44 = 0xC0;
}

void WmHighlight_Loop(struct ProcWmHighLight * proc)
{
    int sin;

    DisplaySpriteAnim(
        proc->sprite_anim,
        Config_WmHighlight[proc->nation].x,
        Config_WmHighlight[proc->nation].y | 0x400
    );

    sin = ((SIN_Q12(proc->unk_44) * 3) >> 0xB) + 8;
    proc->unk_44 += 3;

    SetBlendConfig(BLEND_EFFECT_NONE, sin, 0x10 - sin, 0);

    if (proc->ctrl != 0 && sin == 2)
    {
        SetBlendConfig(BLEND_EFFECT_NONE, 0, 0x10, 0);
        Proc_End(proc);
    }
}

void WmHighlight_End(struct ProcWmHighLight * proc)
{
    EndSpriteAnim(proc->sprite_anim);
    SetWmHighlight(proc->id, NULL);
}

void RemoveWmHighlight(int index)
{
    struct ProcWmHighLight * proc = GetWmHighlight(index);

    if (proc)
        Proc_End(proc);
}

void RemoveAllWmHighlight(void)
{
    int i;

    for (i = 0; i < 2; i++)
        RemoveWmHighlight(i);
}

void WmHighlightFadeOut(int index)
{
    struct ProcWmHighLight * proc = GetWmHighlight(index);

    if (proc)
        proc->ctrl = true;
}

bool WmHighlightExists(int index)
{
    if (GetWmHighlight(index) != NULL)
        return true;

    return false;
}

bool WmHighlightAllSideExists(void)
{
    if (GetWmHighlight(0) != NULL)
        return true;

    if (GetWmHighlight(1) != NULL)
        return true;

    return false;
}

void StartWmDot(int x, int y, int palid, int id)
{
    ProcPtr proc = GetWMDot(id);
    struct Vec2i vec = { x, y };

    ModifyWmSpritePosition(&vec);

    if (proc)
        SetSpriteAnimProcParameters(proc, vec.x, vec.y, 0x310);
    else
        SetWMDot(id, StartSpriteAnimProc(ApInfo_WmDot, vec.x, vec.y, OAM2_PAL(palid) | 0x310, 1, 0xA));
}

void EndWMDot(int id)
{
    ProcPtr proc = GetWMDot(id);

    if (proc)
        EndSpriteAnimProc(proc);

    SetWMDot(id, NULL);
}

void StartWmFlag(int x, int y, int palid, int id)
{
    ProcPtr proc = GetWmFlag(id);
    struct Vec2i vec = { x, y };

    ModifyWmSpritePosition(&vec);

    if (proc)
        SetSpriteAnimProcParameters(proc, vec.x, vec.y, OAM2_PAL(palid) | 0x310);
    else
        SetWmFlag(id, StartSpriteAnimProc(ApInfo_WmDot, vec.x, vec.y, OAM2_PAL(palid) | 0x310, 0, 0x7));
}

void EndWmFlag(int id)
{
    ProcPtr proc = GetWmFlag(id);

    if (proc)
        EndSpriteAnimProc(proc);

    SetWmFlag(id, NULL);
}

CONST_DATA struct WmMapTextConfig Config_WmMapText[] = {
    [WM_MAPTEXT_LOC_00] = { 0, Img_WmMapTextDisp_082D3904, Img_WmMapTextDisp_082D3E78 },
    [WM_MAPTEXT_LOC_01] = { 0, Img_WmMapTextDisp_082D3904, Img_WmMapTextDisp_082D43A4 },
    [WM_MAPTEXT_LOC_02] = { 0, Img_WmMapTextDisp_082D4838, Img_WmMapTextDisp_082D4D3C },
    [WM_MAPTEXT_LOC_03] = { 0, Img_WmMapTextDisp_082D5254, Img_DefaultMapText },
    [WM_MAPTEXT_LOC_04] = { 0, Img_WmMapTextDisp_082D3C68, Img_DefaultMapText },
    [WM_MAPTEXT_LOC_05] = { 0, Img_WmMapTextDisp_082D4120, Img_DefaultMapText },
    [WM_MAPTEXT_LOC_06] = { 0, Img_WmMapTextDisp_082D45E0, Img_DefaultMapText },
    [WM_MAPTEXT_LOC_07] = { 0, Img_WmMapTextDisp_082D4B38, Img_DefaultMapText },
    [WM_MAPTEXT_LOC_08] = { 0, Img_WmMapTextDisp_082D4F9C, Img_DefaultMapText },
    [WM_MAPTEXT_LOC_09] = { 0, Img_WmMapTextDisp_082D5400, Img_DefaultMapText },
    [WM_MAPTEXT_LOC_0A] = { 0, Img_WmMapTextDisp_082D55A4, Img_DefaultMapText },
    [WM_MAPTEXT_LOC_0B] = { 0, Img_WmMapTextDisp_082D5778, Img_WmMapTextDisp_082D5844 },
    [WM_MAPTEXT_LOC_0C] = { 0, Img_DefaultMapText, Img_DefaultMapText },
    [WM_MAPTEXT_LOC_0D] = { 45, Img_WmMapTextDisp_082D59DC, Img_DefaultMapText },
    [WM_MAPTEXT_LOC_0E] = { 33, Img_WmMapTextDisp_082D5B98, Img_DefaultMapText },
    [WM_MAPTEXT_LOC_0F] = { 46, Img_WmMapTextDisp_082D5D08, Img_DefaultMapText },
    [WM_MAPTEXT_LOC_10] = { 64, Img_WmMapTextDisp_082D5EE0, Img_DefaultMapText },
    [WM_MAPTEXT_LOC_11] = { 32, Img_WmMapTextDisp_082D60F4, Img_DefaultMapText },
    [WM_MAPTEXT_LOC_12] = { 35, Img_WmMapTextDisp_082D6274, Img_DefaultMapText },
    [WM_MAPTEXT_LOC_13] = { 37, Img_WmMapTextDisp_082D6408, Img_DefaultMapText },
    [WM_MAPTEXT_LOC_14] = { 39, Img_WmMapTextDisp_082D65A8, Img_DefaultMapText },
    [WM_MAPTEXT_LOC_15] = { 42, Img_WmMapTextDisp_082D6768, Img_DefaultMapText },
    [WM_MAPTEXT_LOC_16] = { 38, Img_WmMapTextDisp_082D6930, Img_DefaultMapText },
    [WM_MAPTEXT_LOC_17] = { 40, Img_WmMapTextDisp_082D6AF4, Img_DefaultMapText },
    [WM_MAPTEXT_LOC_18] = { 35, Img_WmMapTextDisp_082D6CA8, Img_DefaultMapText },
    [WM_MAPTEXT_LOC_19] = { 44, Img_WmMapTextDisp_082D6E44, Img_DefaultMapText },
    [WM_MAPTEXT_LOC_1A] = { 52, Img_WmMapTextDisp_082D7018, Img_DefaultMapText },
    [WM_MAPTEXT_LOC_1B] = { 37, Img_WmMapTextDisp_082D720C, Img_DefaultMapText },
    [WM_MAPTEXT_LOC_1C] = { 52, Img_WmMapTextDisp_082D73D0, Img_DefaultMapText },
    [WM_MAPTEXT_LOC_1D] = { 38, Img_WmMapTextDisp_082D75D8, Img_DefaultMapText },
    [WM_MAPTEXT_LOC_1E] = { 36, Img_WmMapTextDisp_082D7774, Img_DefaultMapText },
    [WM_MAPTEXT_LOC_1F] = { 44, Img_WmMapTextDisp_082D7934, Img_DefaultMapText },
    [WM_MAPTEXT_LOC_20] = { 51, Img_WmMapTextDisp_082D7B20, Img_DefaultMapText },
    [WM_MAPTEXT_LOC_21] = { 58, Img_WmMapTextDisp_082D7D24, Img_DefaultMapText },
    [WM_MAPTEXT_LOC_22] = { 35, Img_WmMapTextDisp_082D7F2C, Img_DefaultMapText },
};

struct ProcScr CONST_DATA ProcScr_WmMapTextDisp[] =
{
    PROC_MARK(PROC_MARK_WMSTUFF),
    PROC_ONEND(WmMapTextDisp_End),
    PROC_CALL(WmMapTextDisp_Init),
    PROC_YIELD,
    PROC_CALL(WmMapTextDisp_DrawGfx),
    PROC_REPEAT(WmMapTextDisp_Loop1),
    PROC_REPEAT(WmMapTextDisp_Loop2),
    PROC_REPEAT(WmMapTextDisp_Loop3),
    PROC_END,
};

void StartWmMapText(int x, int y, int nation, int d, int e, int id)
{
    struct ProcWmMapText * proc;
    struct Vec2i vec = { x, y };

    ModifyWmSpritePosition(&vec);

    proc = SpawnProc(ProcScr_WmMapTextDisp, PROC_TREE_3);
    proc->x = vec.x;
    proc->y = vec.y;
    proc->nation = nation;
    proc->type_a = d;
    proc->type_b = e;
    proc->id = id;

    SetWmMapText(id, proc);
}

void RemoveWmMapText(int id)
{
    struct ProcWmMapText * proc = GetWmMapText(id);

    if (proc)
        Proc_End(proc);
}

void EndWmMapText(int id)
{
    struct ProcWmMapText * proc = GetWmMapText(id);

    if (proc)
        proc->end_ctrl = true;
}

void PutWmMapTextGfx(const void * img_src, u8 * vram_dst)
{
    u8 * buf = gBuf;

    Decompress(img_src, buf);

    func_fe6_08015298(buf,         vram_dst,         8, 4);
    func_fe6_08015298(buf + 0x400, vram_dst + 0x100, 4, 4);
    func_fe6_08015298(buf + 0x600, vram_dst + 0x180, 1, 4);
}

void WmMapTextDisp_Init(struct ProcWmMapText * proc)
{
    proc->timer = 0;
    proc->end_ctrl = false;
}

void WmMapTextDisp_DrawGfx(struct ProcWmMapText * proc)
{
    proc->sprite_anim = StartSpriteAnim(ApInfo_WmMapTextDisp, 0xB);
    proc->sprite_anim->oam2 = ((proc->id == 0) ? 0x200 : 0x288) | ((proc->type_b == 0) ? 0x5000 : 0x4000);

    if (Config_WmMapText[proc->nation].img2 == Img_DefaultMapText)
        SetSpriteAnimId(proc->sprite_anim, 1);
    else
        SetSpriteAnimId(proc->sprite_anim, 2);

    PutWmMapTextGfx(Config_WmMapText[proc->nation].img1, proc->id == 0 ? (OBJ_VRAM0 + 0x4000) : (OBJ_VRAM0 + 0x5100));
    PutWmMapTextGfx(Config_WmMapText[proc->nation].img2, proc->id == 0 ? (OBJ_VRAM0 + 0x4200) : (OBJ_VRAM0 + 0x5300));

    SetBlendConfig(BLEND_EFFECT_NONE, 0, 0x10, 0);
    SetBlendTargetA(0, 0, 0, 0, 1);
    SetBlendTargetB(0, 0, 1, 0, 0);
    SetBlendBackdropB(1);
}

void WmMapTextDisp_Loop1(struct ProcWmMapText * proc)
{
    DrawWmMapTextCore(proc->sprite_anim, proc->x, proc->y | 0x400, proc->nation, proc->type_a, proc->type_b);

    proc->timer++;
    SetBlendConfig(BLEND_EFFECT_NONE, proc->timer, 0x10 - proc->timer, 0);

    if (proc->timer >= 0x10)
        Proc_Break(proc);
}

void WmMapTextDisp_Loop2(struct ProcWmMapText * proc)
{
    DrawWmMapTextCore(proc->sprite_anim, proc->x, proc->y, proc->nation, proc->type_a, proc->type_b);

    if (proc->end_ctrl)
        Proc_Break(proc);
}

void WmMapTextDisp_Loop3(struct ProcWmMapText * proc)
{
    DrawWmMapTextCore(proc->sprite_anim, proc->x, proc->y | 0x400, proc->nation, proc->type_a, proc->type_b);

    proc->timer--;
    SetBlendConfig(BLEND_EFFECT_NONE, proc->timer, 0x10 - proc->timer, 0);

    if (proc->timer == 0)
        Proc_Break(proc);
}

void WmMapTextDisp_End(struct ProcWmMapText * proc)
{
    SetWmMapText(proc->id, NULL);
    EndSpriteAnim(proc->sprite_anim);
}

u16 CONST_DATA Sprite_0868C920[] =
{
    1,
    OAM0_SHAPE_8x8 + OAM0_Y(248), OAM1_SIZE_8x8 + OAM1_X(507) + OAM1_HFLIP, 0,
};

u16 CONST_DATA Sprite_0868C928[] =
{
    1,
    OAM0_SHAPE_8x8 + OAM0_Y(248), OAM1_SIZE_8x8 + OAM1_X(510), 0,
};

u16 CONST_DATA Sprite_0868C930[] =
{
    1,
    OAM0_SHAPE_8x8, OAM1_SIZE_8x8 + OAM1_X(510), 0,
};

u16 CONST_DATA Sprite_0868C938[] =
{
    1,
    OAM0_SHAPE_8x8, OAM1_SIZE_8x8 + OAM1_X(507) + OAM1_HFLIP, 0,
};

CONST_DATA struct WmMapTextSpriteConfig SpriteConf_WmMapTextDisp[] = {
    [0] = { Sprite_0868C920, -4, -8, 2, 2 },
    [1] = { Sprite_0868C928, 4, -8, -2, 2 },
    [2] = { Sprite_0868C930, -4, 8, 1, 0 },
    [3] = { Sprite_0868C938, 4, 8, -1, 0 },
};

void DrawWmMapTextCore(struct SpriteAnim * sprit_anim, int oam1_x, int oam0_y, int d, int e, int f)
{
    int oam1 = oam1_x & 0xFFFFFE00;
    int oam0 = oam0_y & 0xFFFFFF00;

    switch (e) {
    case 0:
        oam1_x = oam1_x - 2;
        break;

    case 2:
        oam1_x = oam1_x - 3;
        break;

    case 1:
    case 3:
        oam1_x = oam1_x + 2;
        break;
    }

    f *= 2;

    while (--f != -1)
    {
        PutSpriteExt(
            0xB,
            oam1 + OAM1_X(oam1_x),
            oam0 + OAM0_Y(oam0_y),
            SpriteConf_WmMapTextDisp[e].sprite,
            0x4320);

        oam1_x += SpriteConf_WmMapTextDisp[e].x1;
        oam0_y += SpriteConf_WmMapTextDisp[e].y1;
    }

    switch (e) {
    case 2:
        oam1_x = oam1_x + 2;

        /* Fall through */

    case 0:
        oam1_x = oam1_x - Config_WmMapText[d].x;
        break;

    case 1:
        break;

    case 3:
        oam1_x = oam1_x - 2;
        break;
    }

    DisplaySpriteAnim(
        sprit_anim,
        oam1 + OAM1_X(oam1_x + SpriteConf_WmMapTextDisp[e].x2),
        oam0 + OAM0_Y(oam0_y + SpriteConf_WmMapTextDisp[e].y2));
}

void ModifyWmSpritePosition(struct Vec2i * vec)
{
    struct ProcWmSprite * proc = FindProc(ProcScr_WmSprite);

    vec->x -= proc->x_off;
    vec->y -= proc->y_off;

    if (proc->scaling_down == 0)
    {
        vec->x = vec->x >> 1;
        vec->y = vec->y >> 1;
    }
}

void PlayWmIntroBGM(void)
{
    StartBgm(GetChapterInfo(gPlaySt.chapter)->song_intro_bgm, NULL);
}

struct ProcScr CONST_DATA ProcScr_TalkAdvance[] =
{
    PROC_CALL(TalkAdvance_Init),
    PROC_REPEAT(TalkAdvance_Loop),
    PROC_END,
};

void StartTalkAdvance(int chr, int lines, int _fill, ProcPtr parent)
{
    struct ProcTalkAdvance * proc;

    proc = SpawnProcLocking(ProcScr_TalkAdvance, parent);

    proc->dst = OBJ_VRAM0 + OAM2_CHR(chr) * CHR_SIZE;
    proc->lines = lines;
    proc->_fill = _fill;
}

void TalkAdvance_Init(struct ProcTalkAdvance * proc)
{
    proc->timer = 0;
}

void TalkAdvance_Loop(struct ProcTalkAdvance * proc)
{
    int ix, iy;
    u32 * dst = proc->dst;

    for (ix = 0; ix < proc->lines * 8; ix += 8)
    {
        for (iy = 0; iy <= 0x300; iy += 0x100)
        {
            (dst + ix + iy)[0] = (dst + ix + iy)[1];
            (dst + ix + iy)[1] = (dst + ix + iy)[2];
            (dst + ix + iy)[2] = (dst + ix + iy)[3];
            (dst + ix + iy)[3] = (dst + ix + iy)[4];
            (dst + ix + iy)[4] = (dst + ix + iy)[5];
            (dst + ix + iy)[5] = (dst + ix + iy)[6];
            (dst + ix + iy)[6] = (dst + ix + iy)[7];

            if (iy < 0x300)
                (dst + ix + iy)[7] = (dst + ix + iy)[0x100]; // next line
            else
                (dst + ix + iy)[7] = proc->_fill;
        }
    }

    proc->timer++;
    if (proc->timer > 15)
        Proc_Break(proc);
}

struct ProcScr CONST_DATA ProcScr_WmDebug[] =
{
    PROC_CALL(LockGame),
    PROC_YIELD,
    PROC_CALL(WmDebug_Init),
    PROC_REPEAT(WmDebug_Loop),
    PROC_CALL(UnlockGame),
    PROC_END,
};

void StartWmDebug(void)
{
    EndMapUi();
    SpawnProc(ProcScr_WmDebug, PROC_TREE_3);
}

void WmDebug_ResetState(struct ProcWmDebug * proc)
{
    proc->state = 1;
}

void WmDebug_Init(struct ProcWmDebug * proc)
{
    proc->number = 0;
    proc->chapter = gPlaySt.chapter;
    WmDebug_ResetState(proc);
}

void WmDebug_Loop(struct ProcWmDebug * proc)
{
    int repeated, _button_l;
    int number = proc->number;

    if (IsEventRunning())
        return;

    if (proc->state == 0)
    {
        DebugInitObj(-1, 0x9);
        WmDebug_ResetState(proc);
    }

    DebugPutObjNumber(0x70, 0x64, number, 4);

    if (gKeySt->pressed & KEY_BUTTON_SELECT)
    {
        Proc_Break(proc);
        return;
    }

    repeated = gKeySt->repeated;

    if (repeated & KEY_DPAD_UP)
        number++;

    if (repeated & KEY_DPAD_DOWN)
        number--;

    if (repeated & KEY_DPAD_RIGHT)
        number += 10;

    if (repeated & KEY_DPAD_LEFT)
        number -= 10;

    if (repeated & KEY_BUTTON_R)
        number += 100;

    _button_l = KEY_BUTTON_L;
    _button_l &= repeated;
    if (_button_l)
        number -= 100;

    if (number < 0)
        number = 0;

    if (number > 38)
        number = 38;

    if (number != proc->number)
    {
        DebugInitObj(-1, 9);
        proc->number = number;
        return;
    }

    if (gKeySt->pressed & KEY_BUTTON_A)
    {
        proc->state = 0;
        gPlaySt.chapter = proc->chapter;
        SpawnProc(ProcScr_WorldMapIntroEvent, PROC_TREE_3);
    }
}
