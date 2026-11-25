#include "prelude.h"
#include "hardware.h"
#include "util.h"
#include "map.h"
#include "random.h"
#include "banim.h"

CONST_DATA short PosArray_EfxApocalypseBGCtrl[0x140] = {
	0,   0,   0,
	1,   1,   1,
	2,   2,
	3,   3,   3,
	4,   4,
	5,   5,   5,
	6,   6,   6,
	7,   7,   7,
	8,   8,   8,
	9,   9,   9,
	10,  10,  10,
	11,  11,  11, 11,
	12,  12,  12, 12,
	13,  13,  13, 13, 13,
	14,  14,  14, 14, 14, 14,
	15,  15,  15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
	14,  14,  14, 14, 14, 14,
	13,  13,  13, 13, 13,
	12,  12,  12, 12,
	11,  11,  11, 11,
	10,  10,  10,
	9,   9,   9,
	8,   8,   8,
	7,   7,   7,
	6,   6,   6,
	5,   5,   5,
	4,   4,
	3,   3,   3,
	2,   2,
	1,   1,   1,
	0,   0,   0,
	-1,  -1,
	-2,  -2,  -2,
	-3,  -3,
	-4,  -4,  -4,
	-5,  -5,
	-6,  -6,  -6,
	-7,  -7,  -7,
	-8,  -8,  -8,
	-9,  -9,  -9,
	-10, -10, -10,
	-11, -11, -11,
	-12, -12, -12, -12,
	-13, -13, -13, -13,
	-14, -14, -14, -14, -14,
	-15, -15, -15, -15, -15, -15,
	-16, -16, -16, -16, -16, -16, -16, -16, -16, -16, -16, -16, -16, -16, -16, -16, -16, -16, -16, -16, -16, -16, -16, -16, -16, -16, -16, -16, -16,
	-15, -15, -15, -15, -15, -15,
	-14, -14, -14, -14, -14,
	-13, -13, -13, -13,
	-12, -12, -12, -12,
	-11, -11, -11,
	-10, -10, -10,
	-9,  -9,  -9,
	-8,  -8,  -8,
	-7,  -7,  -7,
	-6,  -6,  -6,
	-5,  -5,
	-4,  -4,  -4,
	-3,  -3,
	-2,  -2,  -2,
	-1,  -1,
	0, 0, 0,
	1, 1, 1,
	2, 2,
	3, 3, 3,
	4, 4,
	5, 5, 5,
	6, 6, 6,
	7, 7, 7,
	8, 8, 8,
	9, 9, 9,
	10, 10, 10,
	11, 11, 11, 11,
	12, 12, 12, 12,
	13, 13, 13, 13, 13,
	14, 14, 14, 14, 14, 14,
	15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
};

void ModifyBGRectTileRefs(u16 *tm, u16 width, u16 height, int pal, int chr)
{
	int i, j;
	u16 tileref, len;
	u16 *_tm = tm;

	for (i = height; i != 0; i--) {
		for (j = width; j != 0; j--) {
			tileref = *_tm;

			if (pal != -1)
				tileref = TILEREF(tileref & 0xFFF, pal);
			if (chr != -1)
				tileref += chr;

			*_tm = tileref;
			_tm++;
		}

		tileref = 0x20 - width;
		_tm += tileref;
	}
}

void FillBGRect(u16 *tm, u16 width, u16 height, int pal, int chr)
{
	int i, j;
	u16 *_tm = tm;
	for (i = height; i != 0; i--)
	{
		u16 len = 0x20 - width;

		for (j = width; j != 0; j--)
			*(_tm++) = TILEREF(chr, pal);

		_tm += len;
	}
}

void func_fe6_0805B0D4(u16 *tm, u16 width, u16 height, int pal, int chr)
{
	int i, j;
	u16 val;
	u16 *_tm = tm;

	for (i = height; i != 0; i--)
	{
		for (j = width; j != 0; j--)
		{
			val = *_tm;
			if (pal != -1) val = TILEREF(val, pal);
			if (chr != -1) val += chr;

			*_tm = val;
			_tm++;
		}

		val = 0x20 - width;
		_tm += val;
	}
}

CONST_DATA u16 gEfxTmyPalRefs[] = {
	0xB000, 0xC000, 0xD000, 0xE000, 0xF000,
	0xB000, 0xC000, 0xD000, 0xE000, 0xF000,
};

#if NONMATCHING
void EfxTmModifyPal(u16 * tm, u16 width, u16 height)
{
	int i, j;
	u16 tileref;
	u16 * _tm = tm;
	u32 _tileref;
	
	for (i = height; i != 0; i--)
	{
		u16 len = 0x20 - width;

		for (j = width; j != 0; j--)
		{
			tileref = _tileref = *_tm;
			tileref = (tileref & 0xFFF) + gEfxTmyPalRefs[(u16)(((_tileref >> 0xC) & 0xF) - 6)];
			*_tm = tileref;
			_tm++;
		}

		len = 0x20 - width;
		_tm += len;
	}
}
#else
NAKEDFUNC
void EfxTmModifyPal(u16 * tm, u16 width, u16 height)
{
asm("\
	.syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sb\n\
	mov r6, r8\n\
	push {r6, r7}\n\
	lsls r1, r1, #0x10\n\
	lsrs r1, r1, #0x10\n\
	mov ip, r1\n\
	lsls r2, r2, #0x10\n\
	adds r3, r0, #0\n\
	lsrs r2, r2, #0x10\n\
	cmp r2, #0\n\
	beq .L0805B198\n\
	movs r0, #0x20\n\
	subs r0, r0, r1\n\
	lsls r0, r0, #0x10\n\
	mov r8, r0\n\
	ldr r0, .L0805B1A4 @ =gEfxTmyPalRefs\n\
	mov sb, r0\n\
.L0805B160:\n\
	mov r4, ip\n\
	subs r2, #1\n\
	cmp r4, #0\n\
	beq .L0805B18E\n\
	ldr r7, .L0805B1A8 @ =0x00000FFF\n\
	mov r6, sb\n\
	movs r5, #0xf\n\
.L0805B16E:\n\
	ldrh r0, [r3]\n\
	adds r1, r0, #0\n\
	lsrs r0, r0, #0xc\n\
	ands r0, r5\n\
	subs r0, #6\n\
	lsls r0, r0, #0x10\n\
	ands r1, r7\n\
	lsrs r0, r0, #0xf\n\
	adds r0, r0, r6\n\
	ldrh r0, [r0]\n\
	adds r1, r0, r1\n\
	strh r1, [r3]\n\
	adds r3, #2\n\
	subs r4, #1\n\
	cmp r4, #0\n\
	bne .L0805B16E\n\
.L0805B18E:\n\
	mov r1, r8\n\
	lsrs r0, r1, #0xf\n\
	adds r3, r3, r0\n\
	cmp r2, #0\n\
	bne .L0805B160\n\
.L0805B198:\n\
	pop {r3, r4}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
.L0805B1A4: .4byte gEfxTmyPalRefs\n\
.L0805B1A8: .4byte 0x00000FFF\n\
	.syntax divided\n\
");
}
#endif

void EfxTmCpyBG(const void *ptr1, void *ptr2, u16 width, u16 height, int pal, int chr)
{
	EfxTmCpyExt(ptr1, -1, ptr2, 32, width, height, pal, chr);
}

void EfxTmCpyBgHFlip(const u16 *tsa, u16 *tm, u16 width, u16 height, int pal, int chr)
{
	EfxTmCpyExtHFlip(tsa, -1, tm, 32, width, height, pal, chr);
}

void EfxTmCpyExt(const u16 *src, i16 src_width, u16 *dst, i16 dst_width, u16 width, u16 hight, int pal, int chr)
{
	int i, j;

	for (i = hight; i != 0; i--) {
		u16 len1 = 0;
		u16 len2 = 0;

		for (j = width; j != 0; j--) {
			u16 val = *src;
			if (pal != -1)
				val = val + (pal << 0xC);

			if (chr != -1)
				val = val + chr;

			*dst = val;

			src++;
			dst++;
		}

		if (src_width != -1) {
			len1 = src_width - width;
			src = src + len1;
		}

		if (dst_width != -1) {
			len2 = dst_width - width;
			dst = dst + len2;
		}
	}
}

void EfxTmCpyExtHFlip(const u16 *src, i16 src_width, u16 *dst, i16 dst_width, u16 width, u16 hight, int pal, int chr)
{
	int i, j;

	dst += width - 1;

	for (i = hight; i != 0; i--) {
		u16 len1 = 0;
		u16 len2 = 0;

		for (j = width; j != 0; j--) {
			u16 val = *src;
			if (pal != -1)
				val = val + (pal << 0xC);

			if (chr != -1)
				val = val + chr;

			*dst = val ^ TILE_HFLIP;

			src++;
			dst--;
		}

		if (src_width != -1) {
			len1 = src_width - width;
			src = src + len1;
		}

		if (dst_width != -1) {
			len2 = width + dst_width;
			dst = dst + len2;
		}
	}
}

void func_fe6_0805B380(u16 *tm, int arg1, int arg2)
{
	int r1, i, flag = 0;

	if (arg2 != 0) {
		for (i = 0; i <= 40; i = r1) {
			if (arg2 <= i) {
				if (flag == 0) {
					flag = 1;
					*tm++ = 0xE;
				} else
					*tm++ = 0xFF;

				r1 = i + 4;
			} else if (arg2 == (i + 1)) {
				flag = 1;
				if (arg1 <= i) {
					*tm++ = 0xD;
					r1 = i + 4;
				} else {
					r1 = i + 4;

					if (arg1 == (i + 1))
						*tm++ = 0xC;
				}
			} else if (arg2 == (i + 2)) {
				flag = 1;
				if (arg1 <= i) {
					*tm++ = 0xB;
					r1 = i + 4;
				} else if (arg1 == (i + 1)) {
					*tm++ = 0xA;
					r1 = i + 4;
				} else {
					r1 = i + 4;

					if (arg1 == (i + 2))
						*tm++ = 0x9;
				}
			} else if (arg2 == (i + 3)) {
				flag = 1;
				if (arg1 <= i) {
					*tm++ = 0x8;
					r1 = i + 4;
				} else if (arg1 == (i + 1)) {
					*tm++ = 0x7;
					r1 = i + 4;
				} else if (arg1 == (i + 2)) {
					*tm++ = 0x6;
					r1 = i + 4;
				} else {
					r1 = i + 4;

					if (arg1 == (i + 3))
						*tm++ = 0x5;
				}
			} else if (r1 = i + 4, arg2 >= r1) {
				if (arg1 <= i)
					*tm++ = 0x4;
				else if (arg1 == (i + 1))
					*tm++ = 0x3;
				else if (arg1 == (i + 2))
					*tm++ = 0x2;
				else if (arg1 == (i + 3))
					*tm++ = 0x1;
				else if (arg1 >= r1)
					*tm++ = 0x0;
			}
		}
	}
}

void EkrModifyBarfx(u16 *tm, int arg)
{
	int i;

	static const u16 conf1[] = {
		0, 1, 2, 3, 4, 5, 6,
	};

	static const u16 conf2[] = {
		8, 9, 10, 11, 12, 13, 14, 15, 16
	};

	static const u16 conf3[] = {
		18, 19, 20, 21, 22, 23
	};

	if (arg > 5)
		*tm = 6;
	else
		*tm = conf1[arg];

	tm = tm + 1;

	for (i = 0; i <= 0x57; i += 8) {
		if (arg >= i + 0xE)
			*tm = 0x10;
		else if (arg >= i + 0x6)
			*tm = conf2[arg - (i + 0x6)];
		else
			*tm = 0x7;

		tm = tm + 1;
	}

	if (arg > 0x62)
		*tm = 0x17;
	else if (arg > 0x5D)
		*tm = conf3[arg - 0x5E];
	else
		*tm = 0x11;
}

bool func_fe6_0805B4D8(u16 *pal_start, u16 *pal_end, u16 *dst, u16 amount, u16 start, u16 end)
{
	int i;

	for (i = 0; i < amount; i++) {
		int r1 = *pal_start & 0x001F;
		int g1 = *pal_start & 0x03E0;
		int b1 = *pal_start & 0x7C00;

		int r2 = *pal_end & 0x001F;
		int g2 = *pal_end & 0x03E0;
		int b2 = *pal_end & 0x7C00;

		u16 r = Interpolate(0, r1, r2, (i16)start, (i16)end);
		u16 g = Interpolate(0, g1, g2, (i16)start, (i16)end);
		u16 b = Interpolate(0, b1, b2, (i16)start, (i16)end);

		*dst = (b & 0x7C00) | (g & 0x03E0) | (r & 0x001F);

		pal_start++;
		pal_end++;
		dst++;
	}

	if (start == end)
		return true;

	return false;
}

void EfxPalBlackInOut(u16 *pal_buf, int line, int length, int ref)
{
	int i, j, _ref = Div(ref * 0x20, 0x10);

	for (i = line; i < (line + length); i++)
	{
		u16 * pal = pal_buf + i * 0x10;
		for (j = 0; j < 0x10; j++)
		{
			int r = RGB_GET_RED(pal[j]);
			int g = RGB_GET_GREEN(pal[j]);
			int b = RGB_GET_BLUE(pal[j]);

			r = r - ((r * _ref) >> 5);
			g = g - ((g * _ref) >> 5);
			b = b - ((b * _ref) >> 5);

			pal[j] = _RGB(r, g, b);
		}
	}
}

void EfxPalWhiteInOut(u16 *pal_buf, int line, int length, int ref)
{
	int i, j, _ref = Div(ref * 0x20, 0x10);

	for (i = line; i < (line + length); i++) {
		u16 * pal = pal_buf + i * 0x10;

		for (j = 0; j < 0x10; j++) {
			int r = RGB_GET_RED(pal[j]);
			int g = RGB_GET_GREEN(pal[j]);
			int b = RGB_GET_BLUE(pal[j]);

			r = r + (((0x1F - r) * _ref) >> 5);
			g = g + (((0x1F - g) * _ref) >> 5);
			b = b + (((0x1F - b) * _ref) >> 5);

			pal[j] = _RGB(r, g, b);
		}
	}
}

void EfxPalFlashingInOut(u16 *pal_buf, int line, int length, int r0, int g0, int b0)
{
	int i, j;

	int _r = Div(r0 * 0x20, 0x10);
	int _g = Div(g0 * 0x20, 0x10);
	int _b = Div(b0 * 0x20, 0x10);

	for (i = line; i < (line + length); i++) {
		u16 *pal = pal_buf + i * 0x10;

		for (j = 0; j < 0x10; j++) {
			int r = RGB_R(pal[j]);
			int g = RGB_G(pal[j]);
			int b = RGB_B(pal[j]);

			r = r + (((0x1F - r) * _r) >> 5);
			g = g + (((0x1F - g) * _g) >> 5);
			b = b + (((0x1F - b) * _b) >> 5);

			pal[j] = _RGB(r, g, b);
		}
	}
}

void EfxPalModifyPetrifyEffect(u16 *pal_buf, int line, int length)
{
	int i, j;

	for (i = line; i < (line + length); i++) {
		for (j = 0; j < 0x10; j++) {
			int r, g, b, c;
			u16 * pal = pal_buf + i * 0x10 + j;

			r = RGB_R(pal[0]);
			g = RGB_G(pal[0]);
			b = RGB_B(pal[0]);

			c = r * 3 + g * 6 + b;

			c = Div(c, 10);

			pal[0] = _RGB(c, c, c);
		}
	}
}

void EfxSplitColor(u16 *pal, u8 *dst, u32 length)
{
	u32 i, r, g, b;
	u16 color;

	for (i = 0; i < length; i++) {
		color = *pal++;

		r = RGB_R(color);
		g = RGB_G(color);
		b = RGB_B(color);

		*dst++ = r;
		*dst++ = g;
		*dst++ = b;
	}
}

void EfxSplitColorPetrify(u16 *src, u8 *dst, u32 length)
{
	int r, g, b, _c;
	u16 color;
	u32 i;

	for (i = 0; i < length; i++) {
		color = *src++;

		r = RGB_R(color);
		g = RGB_G(color);
		b = RGB_B(color);

		_c = Div(r * 3 + g * 6 + b, 10);

		*dst++ = _c;
		*dst++ = _c;
		*dst++ = _c;
	}
}

void func_fe6_0805B88C(i8 *src1, i8 *src2, i16 *pal, u32 length, int ref)
{
	u32 i;
	s16 c1, c2, c;

	for (i = 0; i < length; i++) {
		c1 = *src2;
		c2 = *src1;
		src1++, src2++;
		c = (c1 - c2) * 0x100;
		*pal++ = Div(c, ref);

		c1 = *src2;
		c2 = *src1;
		src1++, src2++;
		c = (c1 - c2) * 0x100;
		*pal++ = Div(c, ref);

		c1 = *src2;
		c2 = *src1;
		src1++, src2++;
		c = (c1 - c2) * 0x100;
		*pal++ = Div(c, ref);
	}
}

void EfxDecodeSplitedPalette(u16 *dst, i8 *src1, i8 *src2, s16 *src3, u32 length, int ref, int unk)
{
	u32 i;
	int r, g, b;

	for (i = 0; i < length; i++) {
		if (ref != unk) {
			r = *src3++;
			g = *src3++;
			b = *src3++;

			r = (r * ref) >> 8;
			g = (g * ref) >> 8;
			b = (b * ref) >> 8;

			r = r + *src1++;
			g = g + *src1++;
			b = b + *src1++;
		} else {
			r = *src2++;
			g = *src2++;
			b = *src2++;
		}
		*dst++ = _RGB(r, g, b);
	}
}


void EfxChapterMapFadeOUT(int speed)
{
	ApplyChapterMapPalettes();
	EfxPalBlackInOut(gPal, 6, 10, speed);
	EnablePalSync();
}

int BanimSpawnRandB(int a)
{
	return DivRem(RandNextB(), a + 1);
}

struct ProcScr CONST_DATA ProcScr_EkrSubAnimeEmulator[] = {
	PROC_19,
	PROC_REPEAT(EkrsubAnimeEmulator_Loop),
	PROC_END,
};

ProcPtr NewEkrsubAnimeEmulator(int x, int y, u32 *anim_scr, int type,
	int oam2Base, int oamBase, ProcPtr parent)
{
	struct ProcEkrSubAnimeEmulator *proc =
		SpawnProc(ProcScr_EkrSubAnimeEmulator, parent);

	proc->timer = 0;
	proc->scr_offset = 0;
	proc->act_type = type;
	proc->valid = 0;
	proc->x1 = x;
	proc->y1 = y;
	proc->x2 = 0;
	proc->y2 = 0;
	proc->scr = anim_scr;
	proc->sprite_data = NULL;
	proc->oam2 = oam2Base;
	proc->oam = oamBase;
	return proc;
}

void EkrsubAnimeEmulator_Loop(struct ProcEkrSubAnimeEmulator *proc)
{
	struct Anim local_anim;
	const AnimScr *scr = proc->scr;

	if (proc->timer == 0) {
		u32 inst = scr[proc->scr_offset];

		if (BAS_INS_KIND_STOP == ANINS_GET_TYPE(inst)) {
			switch (proc->act_type) {
			case EKR_SUBANIMEMU_ACT_ONE_TURN:
				Proc_Break(proc);
				return;
				break;

			case EKR_SUBANIMEMU_ACT_LOOP:
				proc->timer = 1;
				proc->scr_offset = 0;
				break;

			case EKR_SUBANIMEMU_ACT_END:
				proc->timer = 1;
				proc->scr_offset--;
				break;

			default:
				break;
			}
		} else if (BAS_INS_KIND_WAIT == ANINS_GET_TYPE(inst)) {
			proc->timer = inst;
			proc->scr_offset++;
		} else {
			proc->sprite_data = ANINS_FORCESPRITE_GET_ADDRESS(inst);
			proc->timer = ANINS_FORCESPRITE_GET_DELAY(inst);
			proc->scr_offset++;
		}
	}

	proc->timer--;

	if (proc->valid == 0 && proc->sprite_data != NULL) {
		local_anim.sprData = proc->sprite_data;
		local_anim.oam2 = proc->oam2;
		local_anim.oam01 = proc->oam;
		local_anim.xPosition = proc->x1 + proc->x2;
		local_anim.yPosition = proc->y1 + proc->y2;
		local_anim.flags2 = 0;
		BasPutOam(&local_anim);
	}
}

const s16 gAnimSpriteRotScalePosX[][4] = {
	{ 0x08, 0x10, 0x20, 0x40 },
	{ 0x10, 0x20, 0x20, 0x40 },
	{ 0x08, 0x08, 0x10, 0x20 },
	{ -1, -1, -1, -1 },
};

const s16 gAnimSpriteRotScalePosY[][4] = {
	{ 0x08, 0x10, 0x20, 0x40 },
	{ 0x08, 0x08, 0x10, 0x20 },
	{ 0x10, 0x20, 0x20, 0x40 },
	{ -1, -1, -1, -1 },
};

int GetAnimSpriteRotScaleX(u32 header)
{
	u32 size = header >> 30;
	u32 shape = header & 0xC000;

	return gAnimSpriteRotScalePosX[shape >> 14][size];
}

int GetAnimSpriteRotScaleY(u32 header)
{
	u32 size = header >> 30;
	u32 shape = header & 0xC000;

	return gAnimSpriteRotScalePosY[shape >> 14][size];
}

void BanimUpdateSpriteRotScale(void *src, struct BaSpriteData *out, s16 x, s16 y, int unused)
{
	struct ObjAffineSetSrc affin_src;
	struct BaSpriteData *anim_sprite, *it;
	struct BaSpriteData *scr = src;

	affin_src.rotation = 0;
	affin_src.x_scale = x;
	affin_src.y_scale = y;

	out[0].header = 0xFFFF0004;
	ObjAffineSet(&affin_src, &out[0].as.affine, 1, 2);

	anim_sprite = &out[1];
	out[1].header = 0xFFFF0004;
	ObjAffineSet(&affin_src, &out[1].as.affine, 1, 2);
	anim_sprite->as.affine.pa = -anim_sprite->as.affine.pa;
	anim_sprite->as.affine.pb = -anim_sprite->as.affine.pb;

	anim_sprite = &out[2];
	anim_sprite->header = 0xFFFF0004;
	ObjAffineSet(&affin_src, &out[2].as.affine, 1, 2);
	anim_sprite->as.affine.pc = -anim_sprite->as.affine.pc;
	anim_sprite->as.affine.pd = -anim_sprite->as.affine.pd;

	anim_sprite = &out[3];
	anim_sprite->header = 0xFFFF0004;
	ObjAffineSet(&affin_src, &out[3].as.affine, 1, 2);
	anim_sprite->as.affine.pa = -anim_sprite->as.affine.pa;
	anim_sprite->as.affine.pb = -anim_sprite->as.affine.pb;
	anim_sprite->as.affine.pc = -anim_sprite->as.affine.pc;
	anim_sprite->as.affine.pd = -anim_sprite->as.affine.pd;

	out = out + 4;

	for (; scr->header != 1; out++, scr++) {
		s16 r8, r5;
		int val1, val2, val, _val, header;
	
		r8 = x;
		r5 = y;

		header = scr->header;
		val = ((int)(-(header & 0x10000000)) >> 0x1F) & 0x2000000;

		if (header & 0x20000000)
			val = val + 0x4000000;

		out->header = (header &~ 0x3E000000) + 0x100 + val;
		out->as.object.oam2 = scr->as.object.oam2;

		val1 = GetAnimSpriteRotScaleX(header);
		val1 = val1 << 0x10;
		val1 = val1 >> 0x11;
		_val = val1 << 8;
		_val = val1 - Div(_val, r8);
		val1 = scr->as.object.x - _val;
		_val = scr->as.object.x << 8;
		_val = Div(_val, r8);
		_val = scr->as.object.x - _val;
		val1 = val1 - _val;
		out->as.object.x = val1;

		val1 = GetAnimSpriteRotScaleY(scr->header);
		val1 = val1 << 0x10;
		val1 = val1 >> 0x11;
		_val = val1 << 8;
		_val = val1 - Div(_val, r5);
		val1 = scr->as.object.y - _val;
		_val = scr->as.object.y << 8;
		_val = Div(_val, r5);
		_val = scr->as.object.y - _val;
		val1 = val1 - _val;
		out->as.object.y = val1;
	}
	out->header = scr->header;
	out->as.object.oam2 = scr->as.object.oam2;
	out->as.object.x = scr->as.object.x;
	out->as.object.y = scr->as.object.y;
}
