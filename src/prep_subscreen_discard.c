#include "prelude.h"
#include "bm.h"
#include "hardware.h"
#include "proc.h"
#include "oam.h"
#include "sprite.h"
#include "ui.h"
#include "util.h"
#include "bmfx.h"
#include "face.h"
#include "msg.h"
#include "unit.h"
#include "item.h"
#include "text.h"
#include "icon.h"
#include "armfunc.h"
#include "helpbox.h"
#include "prepscreen.h"
#include "sound.h"

#include "constants/songs.h"
#include "constants/msg.h"
#include "constants/videoalloc_global.h"

void PrepDiscardUpdateInfoWindow(struct ProcPrepDiscardScreen *proc)
{
	UpdateEquipInfoWindow(proc->sel_slot);
}

void func_fe6_0808166C(struct Text *text, bool disp)
{
	if (disp == true) {
		PutUiWindowFrame(17, 4, 12, 7, 0);
		PrepPutText(&text[0], gBg0Tm + TM_OFFSET(0x13, 5), TEXT_COLOR_SYSTEM_WHITE, 0, TEXT("本当に", "Are you sure"));
		PrepPutText(&text[1], gBg0Tm + TM_OFFSET(0x16, 5), TEXT_COLOR_SYSTEM_WHITE, 0, TEXT("すてますか", "Discard?"));
		PrepPutText(&text[2], gBg0Tm + TM_OFFSET(0x14, 8), TEXT_COLOR_SYSTEM_WHITE, 0, TEXT("はい", "Yes"));
		PrepPutText(&text[3], gBg0Tm + TM_OFFSET(0x18, 8), TEXT_COLOR_SYSTEM_WHITE, 0, TEXT("いいえ", "None"));
	} else {
		TmFillRect(gBg0Tm + TM_OFFSET(18, 5), 13, 5, 0);
		TmFillRect(gBg1Tm + TM_OFFSET(17, 4), 12, 6, 0);
	}

	EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT);
}

void PrepDiscard_Init(struct ProcPrepDiscardScreen *proc)
{
	u8 i;
	int x;

	ResetTextFont();
	ClearIcons();

	gDispIo.bg0_ct.priority = 0;
	gDispIo.bg1_ct.priority = 1;
	gDispIo.bg2_ct.priority = 0;
	gDispIo.bg3_ct.priority = 3;

	TmFill(gBg0Tm, 0);
	TmFill(gBg1Tm, 0);
	TmFill(gBg2Tm, 0);

	ApplySystemObjectsGraphics();
	InitIcons();
	ApplyIconPalettes(BGPAL_ICONS);

	InitText(&gPrepTexts3[0], 6);

	for (i = 0; i < 8; i++)
		InitTextDb(&gPrepTexts1[0][i], 7);

	for (i = 0; i < 4; i++)
		InitText(&gPrepTexts1[1][i], 7);

	proc->units[POS_L] = proc->proc_parent->unit1;
	proc->units[POS_R] = proc->proc_parent->unit2;

	StartEquipInfoWindow(proc, proc->units[POS_L], 0x10, 0xB);

	proc->unk_2F = 0;
	proc->sel_slot = 0;
	proc->sel_yes = 0;
	proc->unk_31 = 0;
	proc->unk_45 = 0;
	proc->unk_50 = 0;
	proc->sub_sel = 0;
	proc->unk_52 = 0;
	proc->in_helpbox = false;
	proc->unk_2D = 0;

	SetBgOffset(BG_0, 0, 0);
	SetBgOffset(BG_1, 0, 0);
	SetBgOffset(BG_2, 0, 0);

	UnpackUiWindowFrameGraphics();
	PutUiWindowFrame(0x10, 0xB, 0xE, 8, 0);
	PrepDiscardUpdateInfoWindow(proc);
	PutUiWindowFrame(1, 8, 0xE, 0xC, 0);

	StartFace(0, GetUnitFid(proc->units[POS_L]), 0x40, -4, FACE_DISP_KIND(FACE_96x80_FLIPPED));
	func_fe6_0807D6C0(0, proc->units[POS_L]);
	PutUiEntryHover(
		proc->unk_2F * 14 + 2,
		proc->sel_slot * 2 + 9,
		12);

	PrepPutText(
		&gPrepTexts3[0], gBg0Tm, TEXT_COLOR_SYSTEM_WHITE,
		(0x30 - GetStringTextLen(DecodeMsg(proc->units[POS_L]->pinfo->msg_name))) / 2,
		DecodeMsg(proc->units[POS_L]->pinfo->msg_name));

	Decompress(Img_Prep_083198CC, OBJ_VRAM0 + OBCHR_PREPMENU_390 * CHR_SIZE);
	ApplyPalettes(Pal_SpinningArrow, 0x10 + OBPAL_PREPMENU_2, 3);
	Decompress(Img_Prep_0831AB1C, OBJ_VRAM0 + OBCHR_PREPMENU_080 * CHR_SIZE);
	ApplyPalette(Pal_Sio_0831AABC, 0x10 + OBPAL_PREPMENU_8);
	EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT | BG2_SYNC_BIT);

	NewPrepDiscardHand(proc);
	LoadHelpBoxGfx(NULL, -1);
	NewSallyCir2(proc, -1);
	Proc_Goto(proc, 0);
}

void PrepDiscard_Loop(struct ProcPrepDiscardScreen *proc)
{
	u8 prev_slot = proc->sel_slot;

	if (proc->in_helpbox && (gKeySt->pressed & (KEY_BUTTON_B | KEY_BUTTON_R))) {
		CloseHelpBox();
		proc->in_helpbox = false;
		return;
	}

	switch (proc->sub_sel) {
	case 0:
		if ((gKeySt->pressed & KEY_BUTTON_R) && proc->in_helpbox == false) {
			proc->in_helpbox = true;
			StartItemHelpBox(0x10, proc->sel_slot * 16 + 0x48, proc->units[POS_L]->items[proc->sel_slot]);
		} else if ((gKeySt->repeated & KEY_DPAD_UP) && GetUnitItemCount(proc->units[POS_L]) > 1) {
			RemoveUiEntryHover(proc->unk_2F * 14 + 2, proc->sel_slot * 2 + 9, 12);

			if (proc->sel_slot != 0) {
				PlaySe(SONG_66);
				proc->sel_slot--;
				PrepDiscardUpdateInfoWindow(proc);
			} else if (gKeySt->pressed & KEY_DPAD_UP) {
				PlaySe(SONG_66);
				proc->sel_slot = GetUnitItemCount(proc->units[POS_L]) - 1;
				PrepDiscardUpdateInfoWindow(proc);
			}

			PutUiEntryHover(proc->unk_2F * 14 + 2, proc->sel_slot * 2 + 9, 12);
		} else if ((gKeySt->repeated & KEY_DPAD_DOWN) && GetUnitItemCount(proc->units[POS_L]) > 1) {
			u8 last = GetUnitItemCount(proc->units[proc->unk_2F]) - 1;

			RemoveUiEntryHover(proc->unk_2F * 14 + 2, proc->sel_slot * 2 + 9, 12);

			if (proc->sel_slot < last && proc->sel_slot < ITEMSLOT_INV_COUNT - 1) {
				PlaySe(SONG_66);
				proc->sel_slot++;
				PrepDiscardUpdateInfoWindow(proc);
			} else if (gKeySt->pressed & KEY_DPAD_DOWN) {
				PlaySe(SONG_66);
				proc->sel_slot = 0;
				PrepDiscardUpdateInfoWindow(proc);
			}

			PutUiEntryHover(proc->unk_2F * 14 + 2, proc->sel_slot * 2 + 9, 12);
		} else if (gKeySt->pressed & KEY_BUTTON_A) {
			if (proc->in_helpbox == false) {
				if (GetItemAttributes(proc->units[POS_L]->items[proc->sel_slot]) & ITEM_ATTR_IMPORTANT) {
					StartPrepErrorHelpbox(0x10, proc->sel_slot * 16 + 0x48, MSG_C33, proc);
				} else {
					PlaySe(SONG_6A);
					func_fe6_0808166C(gPrepTexts1[1], true);
					RemoveUiEntryHover(proc->unk_2F * 14 + 2, proc->sel_slot * 2 + 9, 12);
					proc->sel_yes = 1;
					proc->sub_sel = 1;
				}
			}
		} else if (gKeySt->pressed & KEY_BUTTON_B) {
			PlaySe(SONG_6B);
			NewSallyCir2(proc, 1);
			Proc_Goto(proc, 1);
		}
		break;

	case 1:
		if ((gKeySt->repeated & KEY_DPAD_RIGHT) && proc->sel_yes == 0) {
			PlaySe(SONG_66);
			proc->sel_yes = 1;
		} else if ((gKeySt->repeated & KEY_DPAD_LEFT) && proc->sel_yes == 1) {
			PlaySe(SONG_66);
			proc->sel_yes = 0;
		} else {
			if (gKeySt->pressed & KEY_BUTTON_A) {
				PlaySe(SONG_6A);

				if (proc->sel_yes == 0) {
					UnitRemoveItem(proc->units[POS_L], proc->sel_slot);
					UnitRemoveInvalidItems(proc->units[POS_L]);
					func_fe6_0807D6C0(0, proc->units[POS_L]);

					if (GetUnitItemCount(proc->units[POS_L]) == 0) {
						NewSallyCir2(proc, 1);
						Proc_Goto(proc, 1);
						break;
					}

					if (proc->sel_slot >= GetUnitItemCount(proc->units[POS_L])) {
						RemoveUiEntryHover(proc->unk_2F * 14 + 2, proc->sel_slot * 2 + 9, 12);
						proc->sel_slot--;
						PutUiEntryHover(proc->unk_2F * 14 + 2, proc->sel_slot * 2 + 9, 12);
					}

					PrepDiscardUpdateInfoWindow(proc);
					func_fe6_0808166C(gPrepTexts1[1], false);
					proc->sub_sel = 0;
				} else {
					func_fe6_0808166C(gPrepTexts1[1], false);
					proc->sub_sel = 0;
				}
			}

			if (gKeySt->pressed & KEY_BUTTON_B) {
				PlaySe(SONG_6B);
				func_fe6_0808166C(gPrepTexts1[1], false);
				proc->sub_sel = 0;
			}

			if (proc->sub_sel == 0)
				PutUiEntryHover(proc->unk_2F * 14 + 2, proc->sel_slot * 2 + 9, 12);
		}
		break;
	}

	if (proc->in_helpbox && prev_slot != proc->sel_slot) {
		StartItemHelpBox(0x10, proc->sel_slot * 16 + 0x48, proc->units[POS_L]->items[proc->sel_slot]);
	}
}

struct ProcScr CONST_DATA ProcScr_PrepDiscardItemScreen[] = {
	PROC_19,
	PROC_SLEEP(1),
	PROC_CALL(PrepDiscard_Init),
PROC_LABEL(0),
	PROC_REPEAT(PrepDiscard_Loop),
PROC_LABEL(1),
	PROC_CALL(PrepDiscard_End),
	PROC_END,
};

void PrepDiscard_End(struct ProcPrepDiscardScreen *proc)
{
	EndFaceById(0);

	TmFill(gBg0Tm, 0);
	TmFill(gBg1Tm, 0);
	TmFill(gBg2Tm, 0);

	EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT | BG2_SYNC_BIT);

	ResetTextFont();
	ClearIcons();
	InitBmBgLayers();
}

void StartPrepDiscardItemScreen(ProcPtr parent)
{
	SpawnProcLocking(ProcScr_PrepDiscardItemScreen, parent);
}

struct ProcScr CONST_DATA ProcScr_PrepDiscardHand[] = {
	PROC_19,
	PROC_CALL(PrepDiscardHand_Init),
	PROC_REPEAT(PrepDiscardHand_Loop),
	PROC_END,
};

void PrepDiscardHand_Init(struct ProcPrepDiscardHand *proc)
{
	proc->timer = 0;
}

void PrepDiscardHand_Loop(struct ProcPrepDiscardHand *proc)
{
	dummy_0807CFB8(1, 4, proc->timer);

	PutSpriteExt(0xB, OAM1_HFLIP, 0, Sprite_086792B6, OAM2_CHR(OBCHR_PREPMENU_390));

	if (proc->proc_parent->sub_sel == true) {
		PutUiHand(proc->proc_parent->sel_yes * 0x20 + 0x9C, 0x40);
		PutFrozenUiHand(0x10, proc->proc_parent->sel_slot * 0x10 + 0x48);
	} else {
		PutUiHand(0x10, proc->proc_parent->sel_slot * 0x10 + 0x48);
	}

	proc->timer++;
}

ProcPtr NewPrepDiscardHand(ProcPtr parent)
{
	return SpawnProc(ProcScr_PrepDiscardHand, parent);
}
