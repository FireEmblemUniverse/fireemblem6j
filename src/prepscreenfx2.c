#include "prelude.h"
#include "proc.h"
#include "hardware.h"
#include "bm.h"
#include "oam.h"
#include "sound.h"
#include "sprite.h"
#include "text.h"
#include "msg.h"
#include "icon.h"
#include "unit.h"
#include "item.h"
#include "supply.h"
#include "ui.h"
#include "armfunc.h"
#include "prepscreen.h"
#include "constants/msg.h"

#include <string.h>
#include "constants/videoalloc.h"

extern const char String_Prep_08327294[];
extern const char Msg_Prep_Supply[]; // 輸送隊

void func_fe6_0807D834(fu8 kind)
{
	fu8 category_offset = kind * 2;

	int i, j;
	int gap;

	gPrepMenuScrollPos = 0;

	for (i = 0; i < gPrepAllItemsCount; i++)
	{
		fu8 item_kind = GetItemKind(gPrepItemListData[i].item);

		if (item_kind >= PrepItemKindRefTable[category_offset + 0] && item_kind <= PrepItemKindRefTable[category_offset + 1])
		{
			gPrepPageItemTable[gPrepMenuScrollPos] = gPrepItemListData[i];
			gPrepMenuScrollPos++;
		}
	}

	/* this is a variant of shellsort
	 * <https://en.wikipedia.org/wiki/Shellsort> */

	gap = 1;

	while (gap < gPrepMenuScrollPos / 3)
	{
		gap = gap * 3 + 1;
	}

	while (gap > 0)
	{
		for (i = gap; i < gPrepMenuScrollPos; i++)
		{
			for (j = i - gap; j >= 0; j -= gap)
			{
				if (GetItemIid(gPrepPageItemTable[j].item) > GetItemIid(gPrepPageItemTable[j + gap].item))
				{
					/* swap if greater IID */
					struct PrepItemListEnt tmp = gPrepPageItemTable[j];
					gPrepPageItemTable[j] = gPrepPageItemTable[j + gap];
					gPrepPageItemTable[j + gap] = tmp;
				}
				else
				{
					if (GetItemIid(gPrepPageItemTable[j].item) != GetItemIid(gPrepPageItemTable[j + gap].item))
						break;

					if (gPrepPageItemTable[j].item > gPrepPageItemTable[j + gap].item)
					{
						/* swap if greater item value (=> greater uses) */
						struct PrepItemListEnt tmp = gPrepPageItemTable[j];
						gPrepPageItemTable[j] = gPrepPageItemTable[j + gap];
						gPrepPageItemTable[j + gap] = tmp;
					}
				}
			}
		}

		gap = gap / 3;
	}

	/* import in the remaining items */

	j = 0;

	for (i = 0; i < gPrepAllItemsCount; i++)
	{
		fu8 item_kind = GetItemKind(gPrepItemListData[i].item);

		if (item_kind < PrepItemKindRefTable[category_offset + 0] || item_kind > PrepItemKindRefTable[category_offset + 1])
		{
			gPrepPageItemTable[gPrepMenuScrollPos + j] = gPrepItemListData[i];
			j++;
		}
	}

	memcpy(gPrepItemListData, gPrepPageItemTable, sizeof(gPrepItemListData));
}

void func_fe6_0807D9E4(struct Text *text, u8 x, struct Unit *unit, u16 off, int unused)
{
	u16 i;

	TmFill(gBg2Tm, 0);

	if (gPrepMenuScrollPos == 0) {
		ClearText(text);
		Text_SetCursor(text, 0);
		Text_SetColor(text, TEXT_COLOR_SYSTEM_GRAY);
		Text_DrawString(text, String_Prep_08327294);
		PutText(text, gBg2Tm + TM_OFFSET(x * 14 + 4, 0));
	}

	for (i = off; i < (off + 7) && i < gPrepMenuScrollPos; i++) {
		bool usable;

		ClearText(&text[i & 7]);
		Text_SetCursor(&text[i & 7], 0);
		PutIcon(
			gBg2Tm + TM_OFFSET(x * 14 + 2, (i * 2) & 0x1F),
			GetItemIcon(gPrepItemListData[i].item),
			OAM2_PAL(OBPAL_PREPMENU_4));
		PrepSubItem_InsertIcon(GetItemIcon(gPrepItemListData[i].item));

		if (!unit || IsItemDisplayUsable(unit, gPrepItemListData[i].item))
			usable = true;
		else
			usable = false;

		Text_SetColor(&text[i & 7], usable ? TEXT_COLOR_SYSTEM_WHITE : TEXT_COLOR_SYSTEM_GRAY);
		Text_DrawString(&text[i & 7], GetItemName(gPrepItemListData[i].item));
		PutText(&text[i & 7], gBg2Tm + TM_OFFSET(x * 14 + 4, (i * 2) & 0x1F));
		PutNumberOrBlank(
			gBg2Tm + TM_OFFSET(x * 14 + 0xD, (i * 2) & 0x1F),
			usable ? TEXT_COLOR_SYSTEM_BLUE : TEXT_COLOR_SYSTEM_GRAY,
			GetItemUses(gPrepItemListData[i].item));
	}

	EnableBgSync(BG2_SYNC_BIT);
}

void func_fe6_0807DB80(struct Text *texts, u8 x, u16 y, struct Unit *unit, int unused)
{
	i8 tmp;
	struct Text *text;
	u8 _y = y & 0xF;

	TmFillRect(gBg2Tm + TM_OFFSET(x * 14, _y * 2), 0x10, 1, 0);
	ClearText(&texts[y & 0x7]);
	PutIcon(
		gBg2Tm + TM_OFFSET(x * 14 + 2, _y * 2),
		GetItemIcon(gPrepItemListData[y].item),
		0x4000);
	PrepSubItem_InsertIcon(GetItemIcon(gPrepItemListData[y].item));

	if (unit == NULL || IsItemDisplayUsable(unit, gPrepItemListData[y].item) != false)
		tmp = 1;
	else
		tmp = 0;

	text = &texts[y & 0x7];

	Text_SetColor(text, (tmp == 0) ? TEXT_COLOR_SYSTEM_GRAY : TEXT_COLOR_SYSTEM_WHITE);
	Text_SetCursor(text, 0);
	Text_DrawString(text, GetItemName(gPrepItemListData[y].item));
	PutText(text, gBg2Tm + TM_OFFSET(x * 14 + 4, _y * 2));
	PutNumberOrBlank(
		gBg2Tm + TM_OFFSET(x * 14 + 13, _y * 2),
		(tmp != 0) ? TEXT_COLOR_SYSTEM_BLUE : TEXT_COLOR_SYSTEM_GRAY,
		GetItemUses(gPrepItemListData[y].item));

	EnableBgSync(BG2_SYNC_BIT);
}

void PrepAllItems_PutPName(struct Text *text, u8 pid, u8 x, u8 y)
{
	TmFillRect(gBg0Tm + TM_OFFSET(0xF, 0), 0xF, 1, 0);

	if (gPrepMenuScrollPos == 0)
		TmFillRect(gBg0Tm + TM_OFFSET(20, 0), 9, 1, 0);
	else if (pid == 0) {
		ClearText(text);
		Text_SetColor(text, TEXT_COLOR_SYSTEM_WHITE);
		Text_SetCursor(text, (0x28 - GetStringTextLen(Msg_Prep_Supply)) / 2);
		Text_DrawString(text, Msg_Prep_Supply);
		PutText(text, gBg0Tm + TM_OFFSET(x, y));
	} else {
		struct Unit *unit = GetUnitByPid(pid);

		ClearText(text);
		Text_SetColor(text, TEXT_COLOR_SYSTEM_WHITE);
		Text_SetCursor(text, (0x28 - GetStringTextLen(DecodeMsg(unit->pinfo->msg_name))) / 2);
		Text_DrawString(text, DecodeMsg(unit->pinfo->msg_name));
		PutText(text, gBg0Tm + TM_OFFSET(x, y));
	}

	EnableBgSync(BG0_SYNC_BIT);
}

void PrepAllItems_PutTotalNum(u8 x, u8 y)
{
	u8 total_num = GetTotalSupplyItemCount();

	TmFillRect(gBg0Tm + TM_OFFSET(x - 3, y), 6, 1, 0);
	PrepPutText(&gPrepTexts3[1], gBg0Tm + TM_OFFSET(0x12, 0), TEXT_COLOR_SYSTEM_WHITE, 4, Msg_Prep_Supply);

	PutNumber(gBg0Tm + TM_OFFSET(x, y), TEXT_COLOR_SYSTEM_BLUE, total_num);
	PutNumber(gBg0Tm + TM_OFFSET(x + 4, y), TEXT_COLOR_SYSTEM_BLUE, 100);
	PutSpecialChar(gBg0Tm + TM_OFFSET(x + 1, y), TEXT_COLOR_SYSTEM_BLUE, TEXT_SPECIAL_SLASH);

	EnableBgSync(BG0_SYNC_BIT);
}

void PrepAllItems_Update(void)
{
	u16 *supply_items = GetSupplyItems();
	u16 i, j = 0;

	for (i = 0; i < gPrepAllItemsCount; i++) {
		if (gPrepItemListData[i].pid == 0) {
			supply_items[j] = gPrepItemListData[i].item;
			j++;
		}
	}

	for (; j < SUPPLY_ITEM_COUNT; j++)
		supply_items[j] = 0;

	PrepAllItems_PutTotalNum(0x18, 0);
}

void func_fe6_0807DEC8(struct PrepSubItemProc *proc, u16 item)
{
	register u8 i;
	register u8 kind;

	kind = GetItemKind(item);

	for (i = 0; i < 9; i++) {
		if ((kind == PrepItemKindRefTable[i * 2 + 0]) || (kind == PrepItemKindRefTable[i * 2 + 1]))
			break;
	}

	if (proc->convoy_page != i) {
		proc->convoy_page = i;
		proc->menu_scroll_bar_disp_idx = proc->unk_32[proc->convoy_page] * 0x10;
		func_fe6_0807D834(proc->convoy_page);
		func_fe6_080823A0(proc->unk_3B + proc->convoy_page, &proc->menu_scroll_bar_disp_idx);
		func_fe6_0807D9E4(&gPrepTexts1[1][0], 1, proc->units[0], proc->menu_scroll_bar_disp_idx / 0x10, 1);
		func_fe6_0807D358(proc);
	}
}

bool PrepAllItems_SwapItems(struct Unit *unit, u8 u_slot, u16 c_slot)
{
	struct PrepItemListEnt tmp;
	
	tmp = gPrepItemListData[c_slot];
	gPrepItemListData[c_slot].item = unit->items[u_slot];
	unit->items[u_slot] = tmp.item;

	UnitRemoveInvalidItems(unit);

	if (gPrepItemListData[c_slot].item == 0) {
		u16 i;

		for (i = c_slot; i < gPrepAllItemsCount; i++) {
			gPrepItemListData[i] = gPrepItemListData[i + 1];

			if (gPrepItemListData[i].pid == 0)
				gPrepItemListData[i].slot--;
		}

		gPrepMenuScrollPos--;
		gPrepAllItemsCount--;
		PrepAllItems_Update();
		return true;
	}

	PrepAllItems_Update();
	return false;
}

void func_fe6_0807DFEC(u8 a, int timer, int obj_off)
{
	u8 tmp = timer;
	const u16 *src = Pal_Prep_0831B068;

	gPal[PAL_COLOR_OFFSET(0x12, 0xD)] = src[(tmp >> 2) & 0xF];

	EnablePalSync();

	PutSprite(4, a * 12 + 0x7C, 0x18, Sprites_08679330[a], 0x2000 + obj_off / 0x20);
	PutSprite(4, a * 12 + 0x7C, 0x18, Sprite_08679326,	 0x2000 + obj_off / 0x20);
}
