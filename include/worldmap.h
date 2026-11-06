#pragma once

#include "prelude.h"
#include "proc.h"
#include "spriteanim.h"

enum
{
    WM_VIEW_FULL,
    WM_VIEW_ZOOM_NW,
    WM_VIEW_ZOOM_NE,
    WM_VIEW_ZOOM_SW,
    WM_VIEW_ZOOM_SE,
};

enum
{
    WM_GFX_IMG,
    WM_GFX_PAL,
};

enum
{
    WM_ZOOM_FRAMES = 0x20,
    WM_ZOOM_FLICKER_FRAMES = 8,
};

#define BG_WM_BITMAP_FRAME1 (void *)(BG_VRAM + 0xA000)

struct ProcWorldMap {
    PROC_HEADER;

    /* 2C */ int scroll_x;
    /* 30 */ int scroll_y;
    /* 34 */ int pivot_x;
    /* 38 */ int pivot_y;

    /* 3C */ int camera_x, camera_y;

    /* 44 */ int angle;
    /* 48 */ i16 scale_x, scale_y;
    /* 4C */ u16 unused_4C, unused_4E, unused_50;
    /* 52 */ u8 unused_52, unused_53, unused_54;
};

enum
{
    WM_ARROW_MAX = 3,
};

enum
{
    WM_ARROW_DOT_SEGMENT_START = 0,
    WM_ARROW_DOT_MOVING = 1,
    WM_ARROW_DOT_ARRIVED = 99,
};

#define OBCHR_WM_ARROW_HEAD 0x310
#define OBCHR_WM_ARROW_DOT 0x323

struct WmArrowSt {
    /* 00 */ u8 busy;
    /* 01 */ u8 eid;    /* user defined */;
    /* 02 */ u8 sprite_index;  /* gWmArrowSt index */
    /* 03 */ u8 dot_count;
    /* 04 */ u8 amount;
    /* 05 */ u8 color;

    /* 08 */ int spacing;
    /* 0C */ int speed;
    /* 10 */ int length;
    /* 14 */ int sqrt_array[12];
    /* 44 */ int arctan_array[12];
    /* 74 */ int point_x[12];
    /* A4 */ int point_y[12];
    /* D4 */ int x_base;
    /* D8 */ int y_base;

    /* DC */ u8 dot_segment[20];
    /* F0 */ u8 dot_state[20];

    /* 104 */ int x_array[20];
    /* 154 */ int y_array[20];
    /* 1A4 */ int dot_vx[20];
    /* 1F4 */ int dot_vy[20];
    /* 244 */ int dot_speed[20];
    /* 294 */ int dot_angle[20];
    /* 2E4 */ int dot_distance[20];
};

extern struct WmArrowSt gWmArrowSt[WM_ARROW_MAX];

u8 const * GetWmGfx(int view, int kind);
void ApplyWmPalette(int view, int kind);
void StartWorldMap(void);
// StartWorldMapUnused
void WorldMap_Init(struct ProcWorldMap * proc);
void WorldMap_Loop(struct ProcWorldMap * proc);

struct ProcWmArrow {
    PROC_HEADER;

    STRUCT_PAD(0x29, 0x58);

    /* 58 */ struct WmArrowSt * conf;
};

void StartWmArrow(int id, int color, int x, int y, int speed, int spacing);
void EndWmArrow(void);
bool WmArrowExists(void);
void WmArrow_End(struct ProcWmArrow * proc);
void WmArrow_Init(struct ProcWmArrow * proc);
void PutWmArrowSpriteExt(struct WmArrowSt * conf, int idx);
void WmArrow_Loop(struct ProcWmArrow * proc);
void ResetWmArrowSt(void);
struct WmArrowSt * GetFreeWmArrowSt(void);

struct ProcWmWait {
    PROC_HEADER;

    /* 2C */ int duration;

    STRUCT_PAD(0x30, 0x66);

    /* 66 */ i16 timer;
};

void StartWmWait(int duration);
void WmWait_Loop(struct ProcWmWait * proc);
bool WmWaitExists(void);

struct ProcWmZoom {
    PROC_HEADER;

    /* 2C */ int ix, iy;

    STRUCT_PAD(0x34, 0x4C);

    /* 4C */ struct ProcWorldMap * wmproc;

    STRUCT_PAD(0x50, 0x66);

    /* 66 */ i16 state, timer;
};

void StartWmZoomTo(int x, int y, ProcPtr parent);
void WmZoomTo_Init(struct ProcWmZoom * proc);
void WmZoomTo_Loop(struct ProcWmZoom * proc);
extern EWRAM_OVERLAY(worldmap) u8 gWmImgBuf[DISPLAY_WIDTH * DISPLAY_HEIGHT];

void DrawWmZoomedView(int x, int y);
void StartWmZoomBack(ProcPtr parent);
void WmZoomBack_Init(struct ProcWmZoom * proc);
void WmZoomBack_Loop(struct ProcWmZoom * proc);
bool WmZoomExists(void);
void EndWmZoom(void);

void WmZoomCore(int scroll_x, int scroll_y, int pivot_x, int pivot_y, int angle, i16 scale_x, i16 scale_y);
void DrawWmArrowCore(u8 a, i16 b, i16 c, int d);
void StartWmEvent(void);
// func_fe6_08093114
void func_fe6_08093120(void);

struct ProcWmSprite {
    PROC_HEADER;

    /* 2A */ u16 x_off, y_off;
    /* 2E */ u8 scaling_down;

    /* 30 */ ProcPtr flag_procs[4];
    /* 40 */ ProcPtr dot_procs[2];
    /* 48 */ ProcPtr highlight_procs[2];
    /* 50 */ ProcPtr text_procs[2];
};

struct WmArrowConf {
    const u16 * buf;
    i16 x, y;
    u8 unk_08, unk_09;
    u16 unk_0A;
};

extern CONST_DATA struct WmArrowConf gWmArrowConf[];

void SetWmFlag(int index, ProcPtr approc);
ProcPtr GetWmFlag(int index);
void SetWMDot(int index, ProcPtr approc);
ProcPtr GetWMDot(int index);
void SetWmHighlight(int index, ProcPtr approc);
ProcPtr GetWmHighlight(int index);
void SetWmMapText(int index, ProcPtr approc);
ProcPtr GetWmMapText(int index);
const u16 * GetWmArrowConfigBuf(int a);
int GetWmArrowCount(const u16 * buf);
int func_fe6_08093288(const u16 * buf, int a);
int func_fe6_080932D8(const u16 * buf, int a);
void StartWmSpriteDisp(struct ProcWmSprite * proc);
void WmSpriteDisp_Init(struct Proc * proc);
void WmSpriteDisp_Loop(struct Proc * proc);
void StartWmSprite(void);
bool WmSpriteExists(void);
void EndWmSprite(void);
void func_fe6_0809347C(int x, int y);
void ResetWmSpriteState(void);
void DisplayWmArrow(int id, int color);
void SetupWmTalkBoxGfx(void);

void StartWmZoomIntro(ProcPtr parent);
void WmZoomIntro_Init(struct Proc * proc);
void WmZoomIntro_Loop(struct Proc * proc);
void WmRotIntro_Init(struct Proc * proc);
void WmRotIntro_Loop(struct Proc * proc);
void WmRotIntro_End(struct Proc * proc);

struct WmHighlightConfig {
    const void * img;
    const u16 * sprite;
    u8 x, y;
};

extern CONST_DATA struct WmHighlightConfig Config_WmHighlight[];

struct ProcWmHighLight {
    PROC_HEADER;

    STRUCT_PAD(0x29, 0x44);

    /* 44 */ u16 unk_44;

    STRUCT_PAD(0x46, 0x50);

    /* 50 */ struct SpriteAnim * sprite_anim;
    /* 54 */ int ctrl;

    STRUCT_PAD(0x58, 0x64);

    /* 64 */ i16 nation, id;
};

void StartWmHighlight(int nation, int id);
void WmHighlight_Init(struct ProcWmHighLight * proc);
void WmHighlight_Loop(struct ProcWmHighLight * proc);
void WmHighlight_End(struct ProcWmHighLight * proc);
void RemoveWmHighlight(int index);
void RemoveAllWmHighlight(void);
void WmHighlightFadeOut(int id);
i8 WmHighlightExists(int id);
i8 WmHighlightAllSideExists(void);
void StartWmDot(int x, int y, int palid, int id);
void EndWMDot(int id);
void StartWmFlag(int x, int y, int palid, int id);
void EndWmFlag(int id);

struct WmMapTextConfig {
    int x;
    const void * img1;
    const void * img2;
};

extern CONST_DATA struct WmMapTextConfig Config_WmMapText[];

struct WmMapTextSpriteConfig {
    u16 * sprite;
    i16 x1, y1;
    i16 x2, y2;
};

extern CONST_DATA struct WmMapTextSpriteConfig SpriteConf_WmMapTextDisp[];

struct ProcWmMapText {
    PROC_HEADER;

    /* 2C */ int x, y;

    STRUCT_PAD(0x34, 0x44);

    /* 44 */ i16 timer;

    STRUCT_PAD(0x46, 0x50);

    /* 50 */ struct SpriteAnim * sprite_anim;
    /* 54 */ int end_ctrl;

    STRUCT_PAD(0x58, 0x64);

    /* 64 */ i16 nation, type_a, type_b;
    /* 6A */ i16 id;
};

void StartWmMapText(int x_a, int y_a, int unk, int x_b, int y_b, int id);
void RemoveWmMapText(int id);
void EndWmMapText(int id);
void PutWmMapTextGfx(const void * img_src, u8 * vram_dst);
void WmMapTextDisp_Init(struct ProcWmMapText * proc);
void WmMapTextDisp_DrawGfx(struct ProcWmMapText * proc);
void WmMapTextDisp_Loop1(struct ProcWmMapText * proc);
void WmMapTextDisp_Loop2(struct ProcWmMapText * proc);
void WmMapTextDisp_Loop3(struct ProcWmMapText * proc);
void WmMapTextDisp_End(struct ProcWmMapText * proc);
void DrawWmMapTextCore(struct SpriteAnim * sprit_anim, int oam0, int oam1, int nation, int e, int f);
void ModifyWmSpritePosition(struct Vec2i * vec);
void PlayWmIntroBGM(void);

struct ProcTalkAdvance {
    PROC_HEADER;

    STRUCT_PAD(0x29, 0x4C);

    void * dst;
    int unk50;
    int lines, _fill;

    STRUCT_PAD(0x5C, 0x64);

    i16 timer;
};

void StartTalkAdvance(int chr, int lines, int _fill, ProcPtr parent);
void TalkAdvance_Init(struct ProcTalkAdvance * proc);
void TalkAdvance_Loop(struct ProcTalkAdvance * proc);

struct ProcWmDebug {
    PROC_HEADER;

    STRUCT_PAD(0x29, 0x2C);

    /* 2C */ int number;

    STRUCT_PAD(0x30, 0x34);

    /* 34 */ u8 state;
    /* 35 */ u8 chapter;
};

void StartWmDebug(void);
void WmDebug_ResetState(struct ProcWmDebug * proc);
void WmDebug_Init(struct ProcWmDebug * proc);
void WmDebug_Loop(struct ProcWmDebug * proc);

extern u16 CONST_DATA Sprite_WmArrowDot[];
extern u16 CONST_DATA Sprite_WmArrowHead[];
extern u8 const * CONST_DATA WorldMapGfxTable[10];

extern u8 const Img_WorldMap[];
extern u8 const Pal_WorldMap[];
extern u8 const Img_WorldMapZoomNW[];
extern u8 const Img_WorldMapZoomNE[];
extern u8 const Img_WorldMapZoomSW[];
extern u8 const Img_WorldMapZoomSE[];
extern u8 const Pal_WorldMapZoom[];
extern CONST_DATA struct ProcScr ProcScr_WorldMapIntroEvent[];
extern CONST_DATA struct ProcScr ProcScr_WorldMap[];
extern CONST_DATA struct ProcScr ProcScr_WmArrow[];
extern CONST_DATA struct ProcScr ProcScr_WmWait[];
extern CONST_DATA struct ProcScr ProcScr_WmZoomTo[];
extern CONST_DATA struct ProcScr ProcScr_WmZoomBack[];
extern CONST_DATA struct ProcScr ProcScr_WmSprite[];
extern CONST_DATA struct ProcScr ProcScr_WmSpriteDisp[];
extern CONST_DATA struct ProcScr ProcScr_WmZoomIntro[];
extern CONST_DATA struct ProcScr ProcScr_WmRotIntro[];
extern CONST_DATA struct ProcScr ProcScr_WorldMapRmBorder[];
extern CONST_DATA struct ProcScr ProcScr_WmMapTextDisp[];
extern CONST_DATA struct ProcScr ProcScr_TalkAdvance[];
extern CONST_DATA struct ProcScr ProcScr_WmDebug[];

extern u16 const gUnk_WmArrow_Buf1[];
extern u16 const gUnk_WmArrow_Buf2[];
extern u16 const gUnk_WmArrow_Buf3[];
extern u16 const gUnk_WmArrow_Buf4[];
extern u16 const gUnk_WmArrow_Buf5[];
extern u16 const gUnk_WmArrow_Buf6[];
extern u16 const gUnk_WmArrow_Buf7[];

extern const int WmArrowConf[];
