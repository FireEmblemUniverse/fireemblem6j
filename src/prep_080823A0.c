#include "prelude.h"
#include "proc.h"
#include "prepscreen.h"

void SetPrepMenuScrollBarBaseInfo(struct MenuScrollBarProc *proc, int a, int b, int c, int d, int e, int f)
{
	proc->xBase = a;
	proc->yBase = b;
	proc->numSegments = c;

	proc->currentSegment = d;
	proc->numTotalRows = e;
	proc->numVisibleRows = f;
}

void SetPrepMenuScrollBarOam2Info(struct MenuScrollBarProc *proc, int a, u8 b)
{
	if (a < 0)
		a = a + 0x1F;

	proc->oam2Chr = a >> 5;
	proc->oam2Pal = b << 12;
}

void PrepPutText(struct Text *th, u16 *tm, int color, int x, const char *str)
{
    ClearText(th);
    Text_SetColor(th, color);
    Text_SetCursor(th, x);
    Text_DrawString(th, str);
    PutText(th, tm);
}

void func_fe6_080823A0(u8 * a, u16 * b)
{
	if (gPrepMenuScrollPos == 0) {
		*a = 0;
		*b = 0;
		return;
	}

	if (gPrepMenuScrollPos < 8) {
		if (*a >= gPrepMenuScrollPos)
			*a = gPrepMenuScrollPos - 1;

		*b = 0;
	} else {
		int unk = (*b >> 4) + 7;

		if (unk < gPrepMenuScrollPos) {
			if (*a != 6)
				return;

			*a = 5;
			return;
		}

		if (unk <= gPrepMenuScrollPos)
			return;

		*b = (gPrepMenuScrollPos - 7) * 16;
	}
}
