#include "savemenu.h"

#include "armfunc.h"
#include "datamove.h"
#include "oam.h"
#include "proc.h"
#include "sprite.h"
#include "spriteanim.h"
#include "ui.h"
#include "helpbox.h"
#include "save_core.h"
#include "save_game.h"

extern u16 const gUnk_0832C39C[]; // sprite anim

struct SaveMenuSpriteEntry {
	/* 00 */ u16 const *sprite;
	/* 04 */ u8 unk_04;
};

extern struct SaveMenuSpriteEntry Sprites_0868A4F8[];
extern struct SaveMenuSpriteEntry Sprites_0868A518[];

extern u16 const *Sprites_0868A550[]; // sprites
extern u16 const *Sprites_0868A55C[]; // sprites

u16 EWRAM_OVERLAY(savemenu) gSaveMenuPalFx[0x20] = {0};

struct Font EWRAM_OVERLAY(savemenu) gSaveMenuFont = {0};
struct Text EWRAM_OVERLAY(savemenu) gSaveMenuText = {0};

u8 EWRAM_OVERLAY(savemenu) gSaveMenuSlotFlags[3] = {0};

void SaveDraw_SavePalette(struct SaveDrawPalProc *proc)
{
	int i;

	proc->progress = 0;

	for (i = 0; i < (int)ARRAY_COUNT(gPal); i++) {
		gSaveMenuPalBackup[i] = gPal[i];
	}
}

void SaveDrawFadeIn_Loop(struct SaveDrawPalProc *proc)
{
#define SCALE 0x10

	int i;
	fu8 coef = proc->progress;

	for (i = 0; i < (int)ARRAY_COUNT(gPal); i++) {
		int b_scaled = (gSaveMenuPalBackup[i] & RGB5_MASK_B) * coef;
		int b_out = (b_scaled / SCALE) & RGB5_MASK_B;

		int g_scaled = (gSaveMenuPalBackup[i] & RGB5_MASK_G) * coef;
		int g_out = (g_scaled / SCALE) & RGB5_MASK_G;

		int r_scaled = (gSaveMenuPalBackup[i] & RGB5_MASK_R) * coef;
		int r_out = (r_scaled / SCALE) & RGB5_MASK_R;

		gPal[i] = b_out | g_out | r_out;
	}

	EnablePalSync();

	proc->progress++;

	if (coef == SCALE) {
		Proc_Break(proc);
	}

#undef SCALE
}

void SaveDrawFadeOut_Loop(struct SaveDrawPalProc *proc)
{
#define SCALE 0x10

	int i;
	fu8 coef = SCALE - proc->progress;

	for (i = 0; i < (int)ARRAY_COUNT(gPal); i++) {
		int b_scaled = (gSaveMenuPalBackup[i] & RGB5_MASK_B) * coef;
		int b_out = (b_scaled / SCALE) & RGB5_MASK_B;

		int g_scaled = (gSaveMenuPalBackup[i] & RGB5_MASK_G) * coef;
		int g_out = (g_scaled / SCALE) & RGB5_MASK_G;

		int r_scaled = (gSaveMenuPalBackup[i] & RGB5_MASK_R) * coef;
		int r_out = (r_scaled / SCALE) & RGB5_MASK_R;

		gPal[i] = b_out | g_out | r_out;
	}

	EnablePalSync();

	proc->progress++;

	if (coef == 0) {
		SetDispEnable(0, 0, 0, 0, 0);
		Proc_Break(proc);
	}

#undef SCALE
}

void SaveDrawFadeOut32_Loop(struct SaveDrawPalProc *proc)
{
#define SCALE 0x20

	int i;
	fu8 coef = SCALE - proc->progress;

	for (i = 0; i < (int)ARRAY_COUNT(gPal); i++) {
		int b_scaled = (gSaveMenuPalBackup[i] & RGB5_MASK_B) * coef;
		int b_out = (b_scaled / SCALE) & RGB5_MASK_B;

		int g_scaled = (gSaveMenuPalBackup[i] & RGB5_MASK_G) * coef;
		int g_out = (g_scaled / SCALE) & RGB5_MASK_G;

		int r_scaled = (gSaveMenuPalBackup[i] & RGB5_MASK_R) * coef;
		int r_out = (r_scaled / SCALE) & RGB5_MASK_R;

		gPal[i] = b_out | g_out | r_out;
	}

	EnablePalSync();

	proc->progress++;

	if (coef == 0) {
		SetDispEnable(0, 0, 0, 0, 0);
		Proc_Break(proc);
	}

#undef SCALE
}

void SaveDrawFadeOut64_Loop(struct SaveDrawPalProc *proc)
{
#define SCALE 0x40

	int i;
	fu8 coef = SCALE - proc->progress;

	for (i = 0; i < (int)ARRAY_COUNT(gPal); i++) {
		int b_scaled = (gSaveMenuPalBackup[i] & RGB5_MASK_B) * coef;
		int b_out = (b_scaled / SCALE) & RGB5_MASK_B;

		int g_scaled = (gSaveMenuPalBackup[i] & RGB5_MASK_G) * coef;
		int g_out = (g_scaled / SCALE) & RGB5_MASK_G;

		int r_scaled = (gSaveMenuPalBackup[i] & RGB5_MASK_R) * coef;
		int r_out = (r_scaled / SCALE) & RGB5_MASK_R;

		gPal[i] = b_out | g_out | r_out;
	}

	EnablePalSync();

	proc->progress++;

	if (coef == 0) {
		SetDispEnable(0, 0, 0, 0, 0);
		Proc_Break(proc);
	}

#undef SCALE
}

struct ProcScr CONST_DATA ProcScr_SaveDrawFadeIn[] = {
	PROC_CALL(SaveDraw_SavePalette),
	PROC_REPEAT(SaveDrawFadeIn_Loop),
	PROC_END,
};

void StartSaveDrawFadeIn(ProcPtr parent)
{
	SpawnProcLocking(ProcScr_SaveDrawFadeIn, parent);
}

struct ProcScr CONST_DATA ProcScr_SaveDrawFadeOut[] = {
	PROC_CALL(SaveDraw_SavePalette),
	PROC_REPEAT(SaveDrawFadeOut_Loop),
	PROC_END,
};

void StartSaveDrawFadeOut(ProcPtr parent)
{
	SpawnProcLocking(ProcScr_SaveDrawFadeOut, parent);
}

struct ProcScr CONST_DATA ProcScr_SaveDrawFadeOut32[] = {
	PROC_CALL(SaveDraw_SavePalette),
	PROC_REPEAT(SaveDrawFadeOut32_Loop),
	PROC_END,
};

void StartSaveDrawFadeOut32(ProcPtr parent)
{
	SpawnProcLocking(ProcScr_SaveDrawFadeOut32, parent);
}

struct ProcScr CONST_DATA ProcScr_SaveDrawFadeOut64[] = {
	PROC_CALL(SaveDraw_SavePalette),
	PROC_REPEAT(SaveDrawFadeOut64_Loop),
	PROC_END,
};

void StartSaveDrawFadeOut64(ProcPtr parent)
{
	SpawnProcLocking(ProcScr_SaveDrawFadeOut64, parent);
}

void CopyPaletteBlock(u16 const *src, u16 *dst, int count)
{
	int i;

	for (i = 0; i < count * 0x10; i++)
		dst[i] = src[i];
}

void SaveMenu_AnimateHighlight(u32 point)
{
	int i;

	point = point % 0x40;

	if ((point & 0x20) != 0)
		point = 0x20 - (point % 0x20);

	for (i = 1; i < 0x10; i++) {
		if (i < 8 || i > 10) {
			int r, g, b;
			u16 r_out, g_out, b_out;

			u16 source = gPal[OBPAL_OFFSET(OBPAL_SAVEMENU_2) + i];
			int blend = gSaveMenuPalFx[0x10 + i];

			b = (RGB5_MASK_B & source) * (0x20 - point);
			b += (RGB5_MASK_B & blend) * (point);
			b_out = RGB5_MASK_B & (b >> 5);

			g = (RGB5_MASK_G & source) * (0x20 - point);
			g += (RGB5_MASK_G & blend) * (point);
			g_out = RGB5_MASK_G & (g >> 5);

			r = (RGB5_MASK_R & source) * (0x20 - point);
			r += (RGB5_MASK_R & blend) * (point);
			r_out = RGB5_MASK_R & (r >> 5);

			gPal[OBPAL_OFFSET(OBPAL_SAVEMENU_1) + i] =
				b_out | g_out | r_out;
		}
	}

	EnablePalSync();
}

u16 CONST_DATA Sprite_SaveMenuSlotFrame[] = {
	4,
	OAM0_SHAPE_32x32,
	OAM1_SIZE_32x32,
	OAM2_CHR(0x80) + OAM2_LAYER(1),
	OAM0_SHAPE_32x32,
	OAM1_SIZE_32x32 + OAM1_X(32),
	OAM2_CHR(0x81) + OAM2_LAYER(1),
	OAM0_SHAPE_32x32,
	OAM1_SIZE_32x32 + OAM1_X(64),
	OAM2_CHR(0x81) + OAM2_LAYER(1),
	OAM0_SHAPE_32x32,
	OAM1_SIZE_32x32 + OAM1_X(96),
	OAM2_CHR(0x82) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_SaveMenuSideTabs[] = {
	3,
	OAM0_SHAPE_32x32,
	OAM1_SIZE_32x32,
	OAM2_CHR(0x80) + OAM2_LAYER(1),
	OAM0_SHAPE_32x32,
	OAM1_SIZE_32x32 + OAM1_X(32),
	OAM2_CHR(0x81) + OAM2_LAYER(1),
	OAM0_SHAPE_32x32,
	OAM1_SIZE_32x32 + OAM1_X(64),
	OAM2_CHR(0x82) + OAM2_LAYER(1),
};

// unused?
u16 CONST_DATA Sprite_SaveMenuSlotFrameAlt[] = {
	6,
	OAM0_SHAPE_32x16,
	OAM1_SIZE_32x16,
	OAM2_CHR(0x80) + OAM2_LAYER(1),
	OAM0_SHAPE_32x16,
	OAM1_SIZE_32x16 + OAM1_X(32),
	OAM2_CHR(0x82) + OAM2_LAYER(1),
	OAM0_SHAPE_32x16 + OAM0_Y(16),
	OAM1_SIZE_32x16,
	OAM2_CHR(0xA0) + OAM2_LAYER(1),
	OAM0_SHAPE_32x16 + OAM0_Y(16),
	OAM1_SIZE_32x16 + OAM1_X(32),
	OAM2_CHR(0xA2) + OAM2_LAYER(1),
	OAM0_SHAPE_32x16 + OAM0_Y(32),
	OAM1_SIZE_32x16,
	OAM2_CHR(0xC0) + OAM2_LAYER(1),
	OAM0_SHAPE_32x16 + OAM0_Y(32),
	OAM1_SIZE_32x16 + OAM1_X(32),
	OAM2_CHR(0xC2) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_SaveMenuHand[] = {
	1,
	OAM0_SHAPE_32x32,
	OAM1_SIZE_32x32,
	OAM2_CHR(0x11C),
};

u16 CONST_DATA Sprite_SaveMenuHover[] = {
	1,
	OAM0_SHAPE_32x32 + OAM0_AFFINE_ENABLE,
	OAM1_SIZE_32x32 + OAM1_AFFINE_ID(3),
	OAM2_CHR(0x158) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_SaveMenuTimeFrame[] = {
	3,
	OAM0_SHAPE_32x32,
	OAM1_SIZE_32x32,
	OAM2_CHR(0x100) + OAM2_LAYER(1),
	OAM0_SHAPE_16x32,
	OAM1_SIZE_16x32 + OAM1_X(32),
	OAM2_CHR(0x101) + OAM2_LAYER(1),
	OAM0_SHAPE_32x32,
	OAM1_SIZE_32x32 + OAM1_X(48),
	OAM2_CHR(0x102) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_0868A174[] = {
	1,
	OAM0_SHAPE_8x8,
	OAM1_SIZE_8x8,
	OAM2_CHR(0x9E) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_0868A17C[] = {
	1,
	OAM0_SHAPE_8x8,
	OAM1_SIZE_8x8,
	OAM2_CHR(0x9F) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_0868A184[] = {
	1,
	OAM0_SHAPE_8x8,
	OAM1_SIZE_8x8,
	OAM2_CHR(0xBE) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_0868A18C[] = {
	1,
	OAM0_SHAPE_8x8,
	OAM1_SIZE_8x8,
	OAM2_CHR(0xBF) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_0868A194[] = {
	1,
	OAM0_SHAPE_8x8,
	OAM1_SIZE_8x8,
	OAM2_CHR(0xDE) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_0868A19C[] = {
	1,
	OAM0_SHAPE_8x8,
	OAM1_SIZE_8x8,
	OAM2_CHR(0xDF) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_0868A1A4[] = {
	1,
	OAM0_SHAPE_8x8,
	OAM1_SIZE_8x8,
	OAM2_CHR(0xFE) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_0868A1AC[] = {
	1,
	OAM0_SHAPE_8x8,
	OAM1_SIZE_8x8,
	OAM2_CHR(0xFF) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_0868A1B4[] = {
	1,
	OAM0_SHAPE_8x8,
	OAM1_SIZE_8x8,
	OAM2_CHR(0x188) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_0868A1BC[] = {
	1,
	OAM0_SHAPE_8x8,
	OAM1_SIZE_8x8,
	OAM2_CHR(0x189) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_0868A1C4[] = {
	1,
	OAM0_SHAPE_8x8,
	OAM1_SIZE_8x8,
	OAM2_CHR(0x18A) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_0868A1CC[] = {
	1,
	OAM0_SHAPE_8x16,
	OAM1_SIZE_8x16,
	OAM2_CHR(0x146) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_0868A1D4[] = {
	1,
	OAM0_SHAPE_8x16,
	OAM1_SIZE_8x16,
	OAM2_CHR(0x147) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_0868A1DC[] = {
	1,
	OAM0_SHAPE_8x16,
	OAM1_SIZE_8x16,
	OAM2_CHR(0x148) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_0868A1E4[] = {
	1,
	OAM0_SHAPE_8x16,
	OAM1_SIZE_8x16,
	OAM2_CHR(0x149) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_0868A1EC[] = {
	1,
	OAM0_SHAPE_8x16,
	OAM1_SIZE_8x16,
	OAM2_CHR(0x14A) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_0868A1F4[] = {
	1,
	OAM0_SHAPE_8x16,
	OAM1_SIZE_8x16,
	OAM2_CHR(0x14B) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_0868A1FC[] = {
	1,
	OAM0_SHAPE_8x16,
	OAM1_SIZE_8x16,
	OAM2_CHR(0x14C) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_0868A204[] = {
	1,
	OAM0_SHAPE_8x16,
	OAM1_SIZE_8x16,
	OAM2_CHR(0x14D) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_0868A20C[] = {
	1,
	OAM0_SHAPE_8x16,
	OAM1_SIZE_8x16,
	OAM2_CHR(0x14E) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_0868A214[] = {
	1,
	OAM0_SHAPE_8x16,
	OAM1_SIZE_8x16,
	OAM2_CHR(0x14F) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_0868A21C[] = {
	1,
	OAM0_SHAPE_8x16,
	OAM1_SIZE_8x16,
	OAM2_CHR(0x150) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_SaveMenuTimeColon[] = {
	2,
	OAM0_SHAPE_32x8,
	OAM1_SIZE_32x8,
	OAM2_CHR(0x180) + OAM2_LAYER(1),
	OAM0_SHAPE_32x8,
	OAM1_SIZE_32x8 + OAM1_X(32),
	OAM2_CHR(0x184) + OAM2_LAYER(1),
};

u16 const *CONST_DATA gSaveMenuTimeDigits[] = {
	Sprite_0868A174,
	Sprite_0868A17C,
	Sprite_0868A184,
	Sprite_0868A18C,
	Sprite_0868A194,
	Sprite_0868A19C,
	Sprite_0868A1A4,
	Sprite_0868A1AC,
	Sprite_0868A1B4,
	Sprite_0868A1BC,
	Sprite_0868A1C4,
};

u16 const *CONST_DATA gSaveMenuHourDigits[] = {
	Sprite_0868A1CC,
	Sprite_0868A1D4,
	Sprite_0868A1DC,
	Sprite_0868A1E4,
	Sprite_0868A1EC,
	Sprite_0868A1F4,
	Sprite_0868A1FC,
	Sprite_0868A204,
	Sprite_0868A20C,
	Sprite_0868A214,
	Sprite_0868A21C,
};

void SaveMenu_PutSaveTime(ProcPtr proc)
{
	struct SaveMenuProc *sm_proc = ((struct Proc *)proc)->proc_parent;

	fu8 y, x;
	u16 hours, minutes, seconds;

	y = (0x20 - (sm_proc->scroll_x * 0x20 / 220));
	y = y + 144;
	x = 144;

	if (sm_proc->action == 1) {
		FormatTime(sm_proc->suspend_time, &hours, &minutes, &seconds);
	} else {
		FormatTime(sm_proc->slot_times[sm_proc->selected_id],
			   &hours,
			   &minutes,
			   &seconds);
	}

	PutSpriteExt(
		13, x + 0x10, y - 14, Sprite_SaveMenuTimeFrame, OAM2_PAL(2));
	PutSpriteExt(
		13, x + 0x14, y - 14, Sprite_SaveMenuTimeColon, OAM2_PAL(5));

	if (hours >= 100) {
		PutSpriteExt(13,
			     x + 0x12,
			     y - 8,
			     gSaveMenuHourDigits[hours / 100],
			     OAM2_PAL(5));
		hours = hours -
			(hours / 100 *
			 100); // sure, 'hours % 100' would have been fine too
	}

	if (hours >= 10) {
		PutSpriteExt(13,
			     x + 0x1A,
			     y - 8,
			     gSaveMenuHourDigits[hours / 10],
			     OAM2_PAL(5));
	}

	PutSpriteExt(13,
		     x + 0x22,
		     y - 8,
		     gSaveMenuHourDigits[hours % 10],
		     OAM2_PAL(5));

	PutSpriteExt(13, x + 0x2A, y - 7, gSaveMenuHourDigits[10], OAM2_PAL(5));

	PutSpriteExt(13,
		     x + 0x32,
		     y - 8,
		     gSaveMenuHourDigits[minutes / 10],
		     OAM2_PAL(5));
	PutSpriteExt(13,
		     x + 0x3A,
		     y - 8,
		     gSaveMenuHourDigits[minutes % 10],
		     OAM2_PAL(5));

	PutSpriteExt(13, x + 0x42, y + 1, gSaveMenuTimeDigits[10], OAM2_PAL(5));

	PutSpriteExt(13,
		     x + 0x4A,
		     y,
		     gSaveMenuTimeDigits[seconds / 10],
		     OAM2_PAL(5));
	PutSpriteExt(13,
		     x + 0x52,
		     y,
		     gSaveMenuTimeDigits[seconds % 10],
		     OAM2_PAL(5));
}

void SaveMenu_SetBgAffine(fu8 bg,
			  i32 scr_x,
			  i32 scr_y,
			  i32 tex_x,
			  i32 tex_y,
			  fi16 angle,
			  fi16 scale)
{
	struct BgAffineSetSrc affine_src;

	affine_src.tex_x = tex_x;
	affine_src.tex_y = tex_y;
	affine_src.scr_x = scr_x >> 8;
	affine_src.scr_y = scr_y >> 8;
	affine_src.sx = 0x10000 / scale;
	affine_src.sy = 0x10000 / scale;
	affine_src.alpha = angle << 6;

	// TODO: put proper affine structs inside gDispIo instead of using
	// bg[23]pa directly
	BgAffineSet(&affine_src,
		    (bg == 2) ? (void *)&gDispIo.bg2pa : (void *)&gDispIo.bg3pa,
		    1);
}

void SaveMenuSlot_Init(struct SaveMenuSlotProc *proc)
{
	fu8 i;

	proc->angle = 0;
	proc->unk_2E = 0x100;

	proc->unk_3A = 0;
	proc->unk_3B = 40;

	PutChapterTitleBG1(0xAC << 4);

	for (i = 0; i < 3; i++) {
		// TODO: make sense of these constants

		if (proc->proc_parent->slot_titles[i] != 0xFF) {
			PutChapterTitleGfx(
				((u32)(0x16800 + 0x800 * i) & 0x1FFFF) >> 5,
				proc->proc_parent->slot_titles[i]);
		} else {
			PutChapterTitleGfx(
				((u32)(0x16800 + 0x800 * i) & 0x1FFFF) >> 5,
				-1);
		}
	}

	proc->unk_30 = 0;
	proc->unk_32 = 0;

	SetObjAffine(0, 0x100, 0, 0, 0x100);
	SetObjAffine(1, 0x100, 0, 0, 0x100);
	SetObjAffine(2, 0x100, 0, 0, 0x100);

	proc->clock = 0;

	proc->cursor_proc = StartSaveMenuCursor(proc);
	proc->unk_39 = 0;

	if (proc->proc_parent->target_id == 0xFF) {
		proc->proc_parent->chapter_sprite = NULL;
	} else {
		proc->proc_parent->chapter_sprite = StartSpriteAnimProc(
			gUnk_0832C39C,
			320,
			0x30 + proc->proc_parent->target_id * 0x20,
			0x1A0,
			0,
			4);
	}

	proc->last_selected_id = proc->proc_parent->selected_id;
}

void SaveMenu_SetIconPalette(bool arg_0, fu16 arg_1)
{
	if (arg_0) {
		gPal[OBPAL_OFFSET(6) + 8] =
			gPal[OBPAL_OFFSET(9) + (arg_1 / 4) % 0x10];
	} else {
		gPal[OBPAL_OFFSET(6) + 8] = gPal[OBPAL_OFFSET(9) + 13];
	}

	EnablePalSync();
}

void SaveMenu_PutAction(
	ProcPtr proc, int x, int y, fu8 arg_3, fu8 pal_a, fu8 pal_b)
{
	PutSpriteExt(
		4, OAM1_X(x), y, Sprite_SaveMenuSlotFrame, OAM2_PAL(pal_a));

	PutSpriteExt(4,
		     OAM1_X(x + 8 + Sprites_0868A518[arg_3].unk_04),
		     y + 8,
		     Sprites_0868A518[arg_3].sprite,
		     OAM2_PAL(pal_b));
}

void SaveMenu_PutExtraAction(
	ProcPtr proc, int x, int y, fu8 arg_3, fu8 pal_a, fu8 pal_b)
{
	PutSpriteExt(
		4, OAM1_X(x), y, Sprite_SaveMenuSlotFrame, OAM2_PAL(pal_a));

	PutSpriteExt(4,
		     OAM1_X(x + 8 + Sprites_0868A4F8[arg_3].unk_04),
		     y + 8,
		     Sprites_0868A4F8[arg_3].sprite,
		     OAM2_PAL(pal_b));
}

void SaveMenuSlot_UpdateCursor(struct SaveMenuSlotProc *proc)
{
	if (proc->last_selected_id != proc->proc_parent->selected_id) {
		SaveMenu_UpdateSlotPal(proc->proc_parent->selected_id);
		proc->last_selected_id = proc->proc_parent->selected_id;
	}

	gPal[OBPAL_OFFSET(1) + 10] = gSaveMenuPalFx[(proc->clock / 4) % 0x10];
	EnablePalSync();

	if (proc->proc_parent->target_id != 0xFF &&
	    proc->proc_parent->scale != 0x100) {
		if (proc->proc_parent->scale < 0x10) {
			proc->proc_parent->target_id = 0xFF;
		} else {
			// angle = scale???
			SetObjAffineAuto(3,
					 proc->proc_parent->scale,
					 proc->proc_parent->scale,
					 proc->proc_parent->scale);
		}

		proc->proc_parent->scale -= 0x10;
	}

	SaveMenu_AnimateHighlight(proc->clock);
	proc->clock++;
}

void SaveMenuSlot_PutSuspendIcon(struct SaveMenuSlotProc *proc)
{
	fu8 id;
	fu16 y;

	y = (0x100 + (0xD0 + proc->proc_parent->scroll_x * 48 / 220)) & 0x1FF;

	PutSpriteExt(4, 0x38, y, Sprite_SaveMenuSlotFrame, OAM2_PAL(2));

	if (proc->proc_parent->extra_scroll_x != 0) {
		id = GetSaveMenuBitIndex(proc->proc_parent->extra_action);

		PutSpriteExt(4,
			     0x40 + Sprites_0868A518[id].unk_04,
			     (y + 8) & 0x1FF,
			     Sprites_0868A4F8[id].sprite,
			     OAM2_PAL(3));
	} else {
		id = GetSaveMenuBitIndex(proc->proc_parent->action);

		PutSpriteExt(4,
			     0x40 + Sprites_0868A518[id].unk_04,
			     (y + 8) & 0x1FF,
			     Sprites_0868A518[id].sprite,
			     OAM2_PAL(3));
	}
}

void SaveMenuSlot_Loop(struct SaveMenuSlotProc *proc)
{
	// TODO: clean up

	fu8 i;
	fu8 id;
	int r5;
	fu8 r4;

	if (proc->proc_parent->action < 0x80) {
		if (proc->proc_parent->action == 0x20) {
			proc->action = proc->proc_parent->extra_action;
		} else {
			proc->action = proc->proc_parent->action;
		}
	}

	r5 = proc->proc_parent->scroll_x + proc->proc_parent->extra_scroll_x;

	if (r5 < 0xDC) {
		r4 = (6 - proc->proc_parent->action_count) * 8;

		for (i = 0; i < proc->proc_parent->action_count; i++) {
			id = GetSaveMenuSelectIndex(
				proc->proc_parent->action_mask, i);
			id = GetSaveMenuBitIndex(id);

			if (i == proc->proc_parent->menu_index) {
				SaveMenu_PutAction(
					proc, 0x38 - r5, r4 + i * 24, id, 1, 3);
			} else {
				SaveMenu_PutAction(
					proc, 0x38 - r5, r4 + i * 24, id, 4, 8);
			}
		}

		if (proc->proc_parent->label == 1) {
			SaveMenuCursor_MoveTo(
				0,
				0x24,
				r4 + proc->proc_parent->menu_index * 24,
				proc);
		}
	}

	if (proc->proc_parent->extra_scroll_x > 0 &&
	    proc->proc_parent->extra_scroll_x < 0x1B8) {
		r4 = (6 - proc->proc_parent->extra_count) * 8;

		for (i = 0; i < proc->proc_parent->extra_count; i++) {
			id = GetSaveMenuSelectIndex(
				proc->proc_parent->extra_mask, i);
			id = GetSaveMenuBitIndex(id);

			if (i == proc->proc_parent->extra_index) {
				SaveMenu_PutExtraAction(
					proc,
					0x114 - proc->proc_parent
							->extra_scroll_x,
					r4 + i * 26,
					id,
					1,
					3);
			} else {
				SaveMenu_PutExtraAction(
					proc,
					0x114 - proc->proc_parent
							->extra_scroll_x,
					r4 + i * 26,
					id,
					4,
					8);
			}
		}

		if (proc->proc_parent->label == 9) {
			SaveMenuCursor_MoveTo(
				0,
				0x24,
				r4 + proc->proc_parent->extra_index * 26,
				proc);
		}
	}

	if (proc->proc_parent->scroll_x != 0) {
		SaveMenu_PutSaveTime(proc);
		SaveMenuSlot_PutSuspendIcon(proc);

		for (i = 0; i < 3; i++) {
			u32 r2 = (proc->proc_parent->label == 5 &&
				  proc->proc_parent->selected_id == i) ?
					 0x100 :
					 0;

			PutSpriteExt(4,
				     OAM1_X(0xF4 - proc->proc_parent->scroll_x),
				     0x20 + r2 + i * 0x20,
				     Sprites_0868A55C[i],
				     OAM2_PAL(10 + i * 2));
			PutSpriteExt(4,
				     OAM1_X(0xF4 - proc->proc_parent->scroll_x),
				     0x20 + r2 + i * 0x20 + 8,
				     Sprites_0868A550[i],
				     OAM2_PAL(11 + i * 2));
		}

		if (proc->proc_parent->target_id != 0xFF) {
			if (proc->proc_parent->scale != 0x100) {
				if (proc->proc_parent->chapter_sprite != NULL) {
					EndSpriteAnimProc(
						proc->proc_parent
							->chapter_sprite);
					proc->proc_parent->chapter_sprite =
						NULL;
				}

				if (proc->proc_parent->action == 1) {
					PutSpriteExt(
						4,
						0xC2,
						0x1E + proc->proc_parent->target_id *
								0x20,
						Sprite_SaveMenuHover,
						0);
				} else {
					PutSpriteExt(
						4,
						0xC2,
						0x1E + proc->proc_parent->target_id *
								0x20,
						Sprite_SaveMenuHover,
						OAM2_PAL(6));
				}
			} else {
				if (proc->proc_parent->action == 1) {
					SetSpriteAnimProcParameters(
						proc->proc_parent
							->chapter_sprite,
						0x1AC - proc->proc_parent
								->scroll_x,
						0x34 + proc->proc_parent->target_id *
								0x20,
						0x1A0);
				} else {
					SetSpriteAnimProcParameters(
						proc->proc_parent
							->chapter_sprite,
						0x140,
						0x34 + proc->proc_parent->target_id *
								0x20,
						0x1A0);

					PutSpriteExt(
						4,
						0x19E - proc->proc_parent
								->scroll_x,
						0x1E + proc->proc_parent->target_id *
								0x20,
						Sprite_SaveMenuHover,
						OAM2_PAL(6));
				}
			}
		}
	}

	if (proc->proc_parent->label == 4 || proc->proc_parent->label == 5) {
		if (proc->proc_parent->choice != 0) {
			int tmp;
			PutSpriteExt(
				4, 0x28, 0x80, Sprite_SaveMenuSideTabs, 0x2000);

			tmp = proc->proc_parent->choice - 1;
			PutUiHand(0x34 + (tmp - tmp / 2 * 2) * 0x28, 0x88);

			SaveMenuCursor_MoveTo(
				1,
				12,
				0x20 + proc->proc_parent->selected_id * 0x20,
				proc);
		} else {
			if (proc->proc_parent->selected_id != 0xFF) {
				SaveMenuCursor_MoveTo(
					1,
					12,
					0x20 + proc->proc_parent->selected_id *
							0x20,
					proc);
			}
		}

		if (proc->proc_parent->copy_from_id != 0xFF) {
			SaveMenuCursor_PutStatic(
				1,
				0x20 + proc->proc_parent->copy_from_id * 0x20,
				proc);
		}
	}

	SaveMenuSlot_UpdateCursor(proc);
}

struct ProcScr CONST_DATA ProcScr_SaveMenuSlot[] = {
	PROC_19,
	PROC_CALL(SaveMenuSlot_Init),
	PROC_REPEAT(SaveMenuSlot_Loop),
	PROC_END,
};

struct SaveMenuSlotProc *StartSaveMenuSlot(struct SaveMenuProc *parent)
{
	return SpawnProc(ProcScr_SaveMenuSlot, parent);
}

void SaveMenuBg_Init(struct SaveMenuBgProc *proc)
{
	proc->unk_39 = 0;
	proc->clock = 0;
	proc->unk_35 = 0;
	proc->unk_36 = 0;
	proc->unk_37 = 0;
	proc->unk_38 = 0;
	proc->unk_3A = 0;
	proc->unk_3B = 0;
	proc->unk_3D = 0;
	proc->unk_34 = 0;
}

void SaveMenuBg_Loop(struct SaveMenuBgProc *proc)
{
	SHOULD_BE_STATIC u8 SHOULD_BE_CONST ALIGNED(4) unk_08336C74[8] = {
		0,
		1,
		2,
		3,
		3,
		2,
		1,
		0,
	};

	proc->clock++;
	proc->angle++;

	SaveMenu_SetBgAffine(
		2, 0x7800, 0x14000, 0x4C00, 0x4C00, proc->angle, 0x180);

	gDispIo.bg2pb *= 2;
	gDispIo.bg2pd *= 2;

// TODO: this is bad, esp. for MODERN
#define SET_REG(type, reg, src) *((type *)&REG_##reg) = *((type *)&(src))

	SET_REG(u32,
		BG2PA,
		gDispIo.bg2pa); // set both with a single 32-bit copy
	SET_REG(u32,
		BG2PC,
		gDispIo.bg2pc); // set both with a single 32-bit copy
	SET_REG(u32, BG2X, gDispIo.bg2x);
	SET_REG(u32, BG2Y, gDispIo.bg2y);

#undef SET_REG
}

struct ProcScr CONST_DATA ProcScr_SaveMenuBg[] = {
	PROC_19,
	PROC_CALL(SaveMenuBg_Init),
	PROC_REPEAT(SaveMenuBg_Loop),
	PROC_END,
};

struct SaveMenuBgProc *StartSaveMenuBg(struct SaveMenuProc *parent)
{
	struct SaveMenuBgProc *proc;

	proc = SpawnProc(ProcScr_SaveMenuBg, PROC_TREE_VSYNC);
	proc->sm_proc = parent;

	return proc;
}

void SaveMenuCursor_Init(struct SaveMenuCursorProc *proc)
{
	proc->active = 0;
	proc->clock = 0;
	proc->target_x = 0;
	proc->x = 0;
	proc->target_y = 0;
	proc->y = 0;
	proc->static_y = 0;
	proc->show_static = 0;
	proc->mirror = 0;
	proc->time = 0;
}

void SaveMenuCursor_Loop(struct SaveMenuCursorProc *proc)
{
	SHOULD_BE_STATIC u8 SHOULD_BE_CONST ALIGNED(4) unk_08336C74[8] = {
		0,
		1,
		2,
		3,
		3,
		2,
		1,
		0,
	};

	proc->clock++;

	if (proc->time < 4)
		proc->time++;

	if (proc->active != 0) {
		fu8 r8 = proc->target_y;
		fu8 r5 = proc->target_x;
		fu8 r6;

		if (proc->time < 4) {
			r8 = (r8 + proc->y) / 2;
			r5 = (r5 + proc->x) / 2;
		}

		if (proc->mirror == 0) {
			r6 = 0x86 + r5;
		} else {
			r6 = 0xB8 + r5;
		}

		proc->y = proc->target_y;
		proc->x = proc->target_x;

		if (proc->mirror == 0) {
			PutSpriteExt(4,
				     r5,
				     unk_08336C74[(proc->clock / 8) & 7] + r8,
				     Sprite_SaveMenuHand,
				     OAM2_PAL(1));
			PutSpriteExt(4,
				     r6 | OAM1_HFLIP,
				     unk_08336C74[(proc->clock / 8) & 7] + r8,
				     Sprite_SaveMenuHand,
				     OAM2_PAL(1));
		} else {
			PutSpriteExt(4,
				     r5,
				     unk_08336C74[(proc->clock / 8) & 7] + r8,
				     Sprite_SaveMenuHand,
				     OAM2_PAL(2));
		}

		proc->time = 0;
	} else {
		if (proc->time == 4)
			proc->active = 0;
	}

	if (proc->show_static != 0) {
		PutSpriteExt(4,
			     12,
			     proc->static_y,
			     Sprite_SaveMenuHand,
			     OAM2_PAL(2));
	}

	if (proc->clear_static != 0)
		proc->show_static = 0;

	proc->active = 0;
	proc->clear_static = 1;
}

void SaveMenuCursor_MoveTo(int a, int b, fu8 c, struct SaveMenuSlotProc *proc)
{
	struct SaveMenuCursorProc *self = proc->cursor_proc;

	self->target_y = c;
	self->target_x = b;
	self->active = 1;
	self->mirror = a;
}

void SaveMenuCursor_PutStatic(int a, fu8 b, struct SaveMenuSlotProc *proc)
{
	struct SaveMenuCursorProc *self = proc->cursor_proc;

	self->static_y = b;
	self->show_static = 1;
	self->mirror = a;
	self->clear_static = 0;
}

struct ProcScr CONST_DATA ProcScr_SaveMenuCursor[] = {
	PROC_19,
	PROC_CALL(SaveMenuCursor_Init),
	PROC_REPEAT(SaveMenuCursor_Loop),
	PROC_END,
};

struct SaveMenuCursorProc *StartSaveMenuCursor(ProcPtr parent)
{
	return SpawnProc(ProcScr_SaveMenuCursor, parent);
}

void SaveMenu_InitText(void)
{
	InitTextFont(&gSaveMenuFont, (void *)VRAM + 0x601 * 0x20, 1, 0);
	InitText(&gSaveMenuText, 10);
}

void SaveMenu_PutPrompt(char const *string, bool display)
{
	if (display) {
		SetTextFont(&gSaveMenuFont);
		ClearText(&gSaveMenuText);
		Text_SetCursor(&gSaveMenuText, 0);
		Text_SetColor(&gSaveMenuText, 0);
		Text_DrawString(&gSaveMenuText, string);
		PutText(&gSaveMenuText, gBg1Tm + TM_OFFSET(7, 17));
	} else {
		TmFillRect(gBg1Tm + TM_OFFSET(7, 17), 10, 1, 0);
	}

	EnableBgSync(BG1_SYNC_BIT);
}

char const *CONST_DATA SaveMenuPromptTextTable[] = {
	[SAVEMENU_PROMPT_0] = JTEXT(""),
	[SAVEMENU_PROMPT_1] = JTEXT("はじめる　やめる"),
	[SAVEMENU_PROMPT_2] = JTEXT("うつす　　やめる"),
	[SAVEMENU_PROMPT_3] = JTEXT("消す　　　やめる"),
	[SAVEMENU_PROMPT_4] = JTEXT("はじめる　やめる"),
	[SAVEMENU_PROMPT_5] = JTEXT("はじめる　やめる"),
	[SAVEMENU_PROMPT_6] = JTEXT("記録　　　やめる"),
};

void SaveMenu_UpdatePrompt(struct SaveMenuProc *proc, bool display)
{
	SaveMenu_PutPrompt(
		SaveMenuPromptTextTable[GetSaveMenuBitIndex(proc->action)],
		display);

	if (!display)
		proc->choice = 0;
}

void SaveMenu_ClearVram(void)
{
	CpuFastFill(0, (void *)VRAM + 0x8000, 0x40 * 0x20);
	CpuFastFill(0, (void *)VRAM + 0xC000, 0x40 * 0x20);
}

void SaveMenu_UpdateAvailableActions(struct SaveMenuProc *proc)
{
	int i, save_count = 0;

	proc->action_count = 0;
	proc->action_mask = 0;
	proc->extra_mask = 0;
	proc->extra_count = 0;

	if (proc->scale == 0x100) {
		proc->action_mask |= 1;
		proc->action_count++;
	}

	for (i = 0; i < 3; i++) {
		if (proc->slot_titles[i] != 0xFF)
			save_count++;
	}

	if (save_count > 0) {
		proc->action_mask |= 2;
		proc->action_count++;

		if (save_count < 3) {
			proc->action_mask |= 4;
			proc->action_count++;
		}

		proc->action_mask |= 8;
		proc->action_count++;
	}

	if (save_count < 3) {
		proc->action_mask |= 16;
		proc->action_count++;
	}

	if (func_fe6_08084714()) {
		proc->extra_mask |= 4;
		proc->extra_count++;
	}

	if (IsMultiArenaAvailable()) {
		proc->extra_mask |= 2;
		proc->extra_count++;
	}

	if (IsNotFirstPlaythrough_2()) {
		proc->extra_mask |= 8;
		proc->extra_count++;
	}

	if (CheckHasCompletedSave()) {
		proc->extra_mask |= 1;
		proc->extra_count++;
	}

	if (proc->extra_mask != 0) {
		proc->action_mask |= 32;
		proc->action_count++;
	}
}

fu8 SaveMenu_GetNextSaveIndex(fu8 save_id, bool valid, fi8 direction)
{
	fu8 i;

	if (direction > 0) {
		for (i = 0; i < 3; i++) {
			if (IsSaveValid(save_id) == valid)
				return save_id;

			if (save_id == 2)
				save_id = 0;
			else
				save_id++;
		}
	} else {
		for (i = 0; i < 3; i++) {
			if (IsSaveValid(save_id) == valid)
				return save_id;

			if (save_id == 0)
				save_id = 2;
			else
				save_id--;
		}
	}

	return UINT8_MAX;
}

bool SaveMenu_MoveSlot(struct SaveMenuProc *proc, fi8 direction)
{
	int valid = FALSE;
	fu8 prev_selected_id = proc->selected_id;

	switch (proc->action) {
	case SAVEMENU_ACTION_RESUME:
		return FALSE;

	case SAVEMENU_ACTION_CONTINUE:
		valid = TRUE;
		break;

	case SAVEMENU_ACTION_COPY:
		if (proc->copy_from_id == 0xFF)
			valid = TRUE;
		else
			valid = FALSE;
		break;

	case SAVEMENU_ACTION_ERASE:
		valid = TRUE;
		break;

	case SAVEMENU_ACTION_NEW_GAME:
		valid = FALSE;
		break;
	}

	if (direction > 0) {
		if (proc->selected_id == 2)
			proc->selected_id = 0;
		else
			proc->selected_id++;
	} else {
		if (proc->selected_id == 0)
			proc->selected_id = 2;
		else
			proc->selected_id--;
	}

	if (proc->action == SAVEMENU_ACTION_SAVE)
		return TRUE;

	proc->selected_id =
		SaveMenu_GetNextSaveIndex(proc->selected_id, valid, direction);

	if (prev_selected_id == proc->selected_id)
		return FALSE;

	return TRUE;
}

bool SaveMenu_IsActionAvailable(struct SaveMenuProc *proc)
{
	if ((proc->action & proc->action_mask) != 0)
		return TRUE;

	return FALSE;
}

struct SaveMenuWindowProc {
	/* 00 */ PROC_HEADER;
	/* 29 */ u8 clock;
	/* 2A */ i8 anim_direction;
	/* 2B */ u8 anim_speed;
};

void SaveMenu_WindowAnim_Loop(struct SaveMenuWindowProc *proc)
{
	// this function makes the following assumption
	STATIC_ASSERT(DISPLAY_WIDTH / 3 == DISPLAY_HEIGHT / 2);

	proc->clock += proc->anim_speed;

	SetWinEnable(0, 1, 0);

	if (proc->anim_direction > 0) {
		SetWin1Box(proc->clock * 3,
			   proc->clock * 2,
			   DISPLAY_WIDTH - proc->clock * 3,
			   DISPLAY_HEIGHT - proc->clock * 2);
	} else {
		SetWin1Box((DISPLAY_WIDTH / 2) - proc->clock * 3,
			   (DISPLAY_HEIGHT / 2) - proc->clock * 2,
			   (DISPLAY_WIDTH / 2) + proc->clock * 3,
			   (DISPLAY_HEIGHT / 2) + proc->clock * 2);
	}

	SetWin1Layers(1, 1, 1, 1, 1);
	SetWOutLayers(0, 0, 0, 0, 0);

	if (proc->clock >= (DISPLAY_WIDTH / 6))
		Proc_Break(proc);
}

struct ProcScr CONST_DATA ProcScr_SaveMenuWindowAnim[] = {
	PROC_19,
	PROC_SLEEP(1),
	PROC_REPEAT(SaveMenu_WindowAnim_Loop),
	PROC_END,
};

void StartSaveMenuWindowAnim(ProcPtr parent, fi8 anim_direction, fu8 anim_speed)
{
	struct SaveMenuWindowProc *proc;

	proc = SpawnProcLocking(ProcScr_SaveMenuWindowAnim, parent);

	proc->anim_direction = anim_direction;
	proc->anim_speed = anim_speed;
	proc->clock = 0;
}

void SaveMenu_CopyBg2(ProcPtr proc)
{
	RegisterDataMove(gBg2Tm, (void *)VRAM + 0x7000, sizeof(gBg2Tm));
}

struct ProcScr CONST_DATA ProcScr_SaveMenuBg2Copy[] = {
	PROC_19,
	PROC_SLEEP(1),
	PROC_REPEAT(SaveMenu_CopyBg2),
	PROC_END,
};

ProcPtr StartSaveMenuBg2Copy(ProcPtr parent)
{
	return SpawnProc(ProcScr_SaveMenuBg2Copy, parent);
}

void SaveMenu_LoadSlotInfo(fu8 save_id, struct SaveMenuProc *proc)
{
	struct PlaySt play_st;

	if (save_id < 3) {
		if (IsSaveValid(save_id)) {
			ReadGameSavePlaySt(save_id, &play_st);

			proc->slot_titles[save_id] =
				GetChapterTitleExtra(&play_st);
			proc->slot_times[save_id] = play_st.time_saved;

			if ((play_st.flags & PLAY_FLAG_COMPLETE) != 0)
				proc->slot_completed[save_id] = 1;
			else
				proc->slot_completed[save_id] = 0;

			gSaveMenuSlotFlags[save_id] = play_st.flags;
		} else {
			proc->slot_titles[save_id] = 0xFF;
			proc->slot_completed[save_id] = 0;
			proc->slot_times[save_id] = 0;
			gSaveMenuSlotFlags[save_id] = 0;
		}
	} else if (proc->scale == 0x100) {
		if (IsValidSuspendSave(SAVE_SUSPEND)) {
			ReadSuspendSavePlaySt(SAVE_SUSPEND, &play_st);
			proc->target_id = play_st.save_id;
			proc->suspend_time = play_st.time_saved;
		} else {
			proc->scale = 0xF0;
		}
	}
}

void SaveMenu_UpdateSlotPal(fu8 save_id)
{
	int i;

	for (i = 0; i < 3; i++) {
		fu8 flags =
			(gSaveMenuSlotFlags[i] & PLAY_FLAG_HARD) != 0 ? 4 : 0;

		if (i != save_id)
			flags |= 2;

		PutChapterTitlePalettle(flags | 1, 0x1A + i * 2);
		PutChapterTitlePalettle(flags | 0, 0x1B + i * 2);
	}

	EnablePalSync();
}

fu8 SaveMenu_GetActionIndex(fu8 end_mask, struct SaveMenuProc *proc)
{
	int mask, count = 0;

	for (mask = 1; mask < end_mask; mask <<= 1) {
		if ((proc->action_mask & mask) != 0)
			count++;
	}

	return count;
}
