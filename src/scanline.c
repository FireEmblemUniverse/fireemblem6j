#include "prelude.h"
#include "proc.h"
#include "util.h"
#include "constants/videoalloc.h"
#include "scanline.h"

void InitScanlineEffect(void)
{
	InitScanlineBuf(gManimScanlineBufA);
	InitScanlineBuf(gManimScanlineBufB);

	gManimScanlineBufs[0] = gManimScanlineBufA;
	gManimScanlineBufs[1] = gManimScanlineBufB;
	gManimActiveScanlineBuf = gManimScanlineBufs[0];
}

void OnHBlank_WinHScanlines(void);

void func_fe6_08069C74(void)
{
	SetWinEnable(1, 0, 0);
	SetWin0Box(0, 0, DISPLAY_WIDTH, DISPLAY_HEIGHT);
	SetWin0Layers(0, 0, 0, 0, 0);
	SetWOutLayers(1, 1, 1, 1, 1);
	SetOnHBlankA(OnHBlank_WinHScanlines);
}

void func_fe6_08069DA4(int x, int y, int arg_08)
{
	InitScanlineBuf(gManimScanlineBufs[1]);
	func_fe6_0806A51C(gManimScanlineBufs[1], x, y, arg_08);
	SwapScanlineBufs();
}

void func_fe6_08069DD8(void)
{
	SetOnHBlankA(NULL);
}

void OnHBlank_WinHScanlines(void)
{
	u16 vcount = REG_VCOUNT;

	if (vcount >= DISPLAY_HEIGHT) {
		gManimActiveScanlineBuf = gManimScanlineBufs[0];
		vcount = 0;
	} else
		vcount++;

	REG_WIN0H = gManimActiveScanlineBuf[vcount];
}

void OnHBlank_08069E50(void)
{
	u16 vcount = REG_VCOUNT;

	if (vcount >= DISPLAY_HEIGHT) {
		gManimActiveScanlineBuf = gManimScanlineBufs[0];
		vcount = 0;
	} else
		vcount++;

	REG_WIN0H = gManimActiveScanlineBuf[vcount];
	REG_BG2HOFS = gManimActiveScanlineBuf[DISPLAY_HEIGHT + vcount];
}

void OnHBlank_ManimFrameGradient(void)
{
	u16 vcount = REG_VCOUNT;

	if (vcount >= DISPLAY_HEIGHT) {
		gManimActiveScanlineBuf = gManimScanlineBufs[0];
		vcount = 0;
	} else
		vcount++;

	// TODO: better constants
	((u16 volatile *) PLTT)[0x10 * (BGPAL_MANIM_INFOFRAME + 0) + 1] = gManimActiveScanlineBuf[vcount];
	((u16 volatile *) PLTT)[0x10 * (BGPAL_MANIM_INFOFRAME + 1) + 1] = gManimActiveScanlineBuf[DISPLAY_HEIGHT + vcount];
}

void OnHBlank_08069F58(void)
{
	u16 vcount = REG_VCOUNT;

	if (vcount >= DISPLAY_HEIGHT) {
		gManimActiveScanlineBuf = gManimScanlineBufs[0];
		vcount = 0;
	} else
		vcount++;

	// TODO: better constants
	((u16 volatile *) PLTT)[0x10 * 0x19 + 4] = gManimActiveScanlineBuf[vcount];
	((u16 volatile *) PLTT)[0x10 * 0x1D + 4] = gManimActiveScanlineBuf[vcount];
}

void OnHBlank_08069FD8(void)
{
	u16 vcount = REG_VCOUNT;

	if (vcount >= DISPLAY_HEIGHT) {
		gManimActiveScanlineBuf = gManimScanlineBufs[0];
		vcount = 0;
	} else
		vcount++;

	REG_BLDALPHA = gManimActiveScanlineBuf[vcount];
}

void OnHBlank_0806A040(void)
{
	u16 vcount = REG_VCOUNT;

	if (vcount >= DISPLAY_HEIGHT) {
		gManimActiveScanlineBuf = gManimScanlineBufs[0];
		vcount = 0;
	} else
		vcount++;

	REG_BG0VOFS = gManimActiveScanlineBuf[vcount];
	REG_BG0HOFS = gManimActiveScanlineBuf[vcount];
	REG_BG1VOFS = gManimActiveScanlineBuf[DISPLAY_HEIGHT + vcount];
}

void StartManimFrameGradientScanlineEffect(fu16 y_top, fu16 y_bottom, fu16 color_2, fu16 color_3)
{
	#define RGB_HALVED(color, component_mask) \
		((((component_mask) & (color)) >> 1) & (component_mask))

	PrepareGradientScanlineBuf(gManimScanlineBufs[1], y_top, y_bottom, color_2,
		RGB_HALVED(color_2, 0x1F) | RGB_HALVED(color_2, 0x1F << 5) | RGB_HALVED(color_2, 0x1F << 10));
	PrepareGradientScanlineBuf(gManimScanlineBufs[1] + DISPLAY_HEIGHT, y_top, y_bottom, color_3,
		RGB_HALVED(color_3, 0x1F) | RGB_HALVED(color_3, 0x1F << 5) | RGB_HALVED(color_3, 0x1F << 10));
	SwapScanlineBufs();

	SetOnHBlankA(OnHBlank_ManimFrameGradient);

	#undef RGB_HALVED
}

void func_fe6_0806A218(fu16 y_top, fu16 y_bottom, fu16 color_a, fu16 color_b)
{
	PrepareGradientScanlineBuf(gManimScanlineBufs[1], y_top, y_bottom, color_a, color_b);
	SwapScanlineBufs();

	SetOnHBlankA(OnHBlank_08069F58);
}

void func_fe6_0806A270(int x, int y, int a, int b, u8 const *unk)
{
	int var_10;

	InitScanlineBuf(gManimScanlineBufs[1]);

	while (*unk != 0xFF && y >= 0) {
		var_10 = Div(*unk * a, b);
		unk++;

		if (var_10 > 0) {
			SetScanlineBufWinR(gManimScanlineBufs[1], x + var_10 - 1, y);
			SetScanlineBufWinL(gManimScanlineBufs[1], x - var_10, y);
		}

		y--;
	}

	if (var_10 > 0) {
		while (y >= 0) {
			SetScanlineBufWinR(gManimScanlineBufs[1], x + var_10 - 1, y);
			SetScanlineBufWinL(gManimScanlineBufs[1], x - var_10, y);
			y--;
		}
	}
}

void PrepareSineWaveScanlineBuf(u16 *buf, fi16 phase, fi16 amplitude, fi16 frequence)
{
	int i;

	for (i = 0; i < DISPLAY_HEIGHT; i++)
		*buf++ = (SIN_Q12(i * frequence + phase) * amplitude) >> 12;
}

void PrepareSineWaveScanlineBufExt(u16 *buf, fi16 phase, fi16 amplitude, fi16 frequence, int y_start, int y_end)
{
	int i;

	for (i = y_start; i < y_end; i++)
		*buf++ = (SIN_Q12(i * frequence + phase) * amplitude) >> 12;
}

void SwapScanlineBufs(void)
{
	u16 *tmp = gManimScanlineBufs[0];

	gManimScanlineBufs[0] = gManimScanlineBufs[1];
	gManimScanlineBufs[1] = tmp;
}

void InitScanlineBuf(u16 *buf)
{
	int i;
	u16 *it = buf;

	for (i = 0; i < DISPLAY_HEIGHT; i++)
	{
		// TODO: WINH macro?
		*it++ = DISPLAY_WIDTH | (DISPLAY_WIDTH << 8);
	}
}

void SetScanlineBufWinL(u16 *buf, int x, int y)
{
	if (x < 0)
		x = 0;

	if (x > DISPLAY_WIDTH - 1)
		x = DISPLAY_WIDTH - 1;

	if (y < 0 || y > DISPLAY_HEIGHT - 1)
		return;

	// TODO: better? (WINH left)
	((u8 *) (buf + y))[1] = x;
}

void SetScanlineBufWinR(u16 *buf, int x, int y)
{
	if (x < 0)
		x = 0;

	if (x > DISPLAY_WIDTH - 1)
		x = DISPLAY_WIDTH - 1;

	if (y < 0 || y > DISPLAY_HEIGHT - 1)
		return;

	// TODO: better? (WINH right)
	((u8 *) (buf + y))[0] = x;
}

void func_fe6_0806A51C(u16 *buf, int x, int y, int arg_0C)
{
	int var_10, i;

	var_10 = arg_0C;

	for (i = 0; var_10 >= i; i++) {
		SetScanlineBufWinR(buf, x + var_10, y + i);
		SetScanlineBufWinR(buf, x + var_10, y - i);
		SetScanlineBufWinR(buf, x + i, y + var_10);
		SetScanlineBufWinR(buf, x + i, y - var_10);

		SetScanlineBufWinL(buf, x - var_10, y + i);
		SetScanlineBufWinL(buf, x - var_10, y - i);
		SetScanlineBufWinL(buf, x - i, y + var_10);
		SetScanlineBufWinL(buf, x - i, y - var_10);

		arg_0C -= (i << 1) - 1;

		if (arg_0C < 0) {
			arg_0C = arg_0C + ((var_10 - 1) << 1);
			var_10 = var_10 - 1;
		}
	}
}

void PrepareGradientScanlineBuf(u16 *buf, fu16 y_top, fu16 y_bottom, fu16 color_a, fu16 color_b)
{
	int i, scanline, r, g, b, scanlines;

	scanlines = y_bottom - y_top;
	scanline = 0;

	for (i = 0; i < DISPLAY_HEIGHT; i++) {
		if (i < y_top) {
			*buf++ = color_a;
			continue;
		}

		if (i > y_bottom) {
			*buf++ = color_b;
			continue;
		}

		// TODO: RGB color mask constants

		r = Interpolate(INTERPOLATE_LINEAR, color_a & 0x001F, color_b & 0x001F, scanline, scanlines);
		g = Interpolate(INTERPOLATE_LINEAR, color_a & 0x03E0, color_b & 0x03E0, scanline, scanlines);
		b = Interpolate(INTERPOLATE_LINEAR, color_a & 0x7C00, color_b & 0x7C00, scanline, scanlines);

		*buf++ = (r & 0x001F) | (g & 0x03E0) | (b & 0x7C00);

		scanline++;
	}
}





struct ProcScr CONST_DATA ProcScr_ManimShiftingSineWaveScanlineBuf[] = {
	PROC_CALL(ManimShiftingSineWaveScanlineBuf_Init),
	PROC_REPEAT(ManimShiftingSineWaveScanlineBuf_Loop),
	PROC_END,
};

void ManimShiftingSineWaveScanlineBuf_Init(struct ManimShiftingSineWaveScanlineBufProc *proc)
{
	proc->phase = 0;
}

void ManimShiftingSineWaveScanlineBuf_Loop(struct ManimShiftingSineWaveScanlineBufProc *proc)
{
	PrepareSineWaveScanlineBuf(gManimScanlineBufs[1] + DISPLAY_HEIGHT, proc->phase++, 0x10, 8);
	SwapScanlineBufs();
}

void Scanline_SetupMonologue(void)
{
	int i;

	for (i = 0; i < DISPLAY_HEIGHT; i++)
		gManimScanlineBufs[0][i] = 0x1000;

	for (i = 8; i < DISPLAY_HEIGHT - 8; i++)
		gManimScanlineBufs[0][i] = 0x10;

	for (i = 0; i <= 32; i++) {
		// ugly
		*(gManimScanlineBufs[0] + (i + 8)) = ((0x10 - (i >> 1)) << 8) | (i >> 1);
		*(gManimScanlineBufs[0] - (i - DISPLAY_HEIGHT + 8)) = ((0x10 - (i >> 1)) << 8) | (i >> 1);
	}
}

u16 *func_fe6_0806A87C(int buf_id, int scanline)
{
	return gManimScanlineBufs[buf_id] + scanline;
}
