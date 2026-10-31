#include "prelude.h"
#include "proc.h"
#include "oam.h"
#include "sprite.h"
#include "util.h"
#include "armfunc.h"
#include "constants/songs.h"
#include "constants/msg.h"

#include "sound.h"

#include "ending.h"
#include "unitlistscreen.h"

#include "msg.h"
#include "helpbox.h"
#include "soundroom.h"

EWRAM_OVERLAY(savemenu) struct SoundRoomText gSoundRoomText = {};
EWRAM_OVERLAY(savemenu) u8 gSoundRoomRecentCgs[2] = {};

CONST_DATA struct SoundRoomInfo gSoundRoomInfo[] = {
	{
		.id = SONG_01,
		.msg_name1 = MSG_SOUNDROM_00_NAME,
		.msg_name2 = MSG_SOUNDROM_00_DESC,
	},
	{
		.id = SONG_02,
		.msg_name1 = MSG_SOUNDROM_01_NAME,
		.msg_name2 = MSG_SOUNDROM_01_DESC,
	},
	{
		.id = SONG_03,
		.msg_name1 = MSG_SOUNDROM_02_NAME,
		.msg_name2 = MSG_SOUNDROM_02_DESC,
	},
	{
		.id = SONG_04,
		.msg_name1 = MSG_SOUNDROM_03_NAME,
		.msg_name2 = MSG_SOUNDROM_03_DESC,
	},
	{
		.id = SONG_05,
		.msg_name1 = MSG_SOUNDROM_04_NAME,
		.msg_name2 = MSG_SOUNDROM_04_DESC,
	},
	{
		.id = SONG_06,
		.msg_name1 = MSG_SOUNDROM_05_NAME,
		.msg_name2 = MSG_SOUNDROM_05_DESC,
	},
	{
		.id = SONG_07,
		.msg_name1 = MSG_SOUNDROM_06_NAME,
		.msg_name2 = MSG_SOUNDROM_06_DESC,
	},
	{
		.id = SONG_08,
		.msg_name1 = MSG_SOUNDROM_07_NAME,
		.msg_name2 = MSG_SOUNDROM_07_DESC,
	},
	{
		.id = SONG_09,
		.msg_name1 = MSG_SOUNDROM_08_NAME,
		.msg_name2 = MSG_SOUNDROM_08_DESC,
	},
	{
		.id = SONG_0A,
		.msg_name1 = MSG_SOUNDROM_09_NAME,
		.msg_name2 = MSG_SOUNDROM_09_DESC,
	},
	{
		.id = SONG_0B,
		.msg_name1 = MSG_SOUNDROM_0A_NAME,
		.msg_name2 = MSG_SOUNDROM_0A_DESC,
	},
	{
		.id = SONG_0C,
		.msg_name1 = MSG_SOUNDROM_0B_NAME,
		.msg_name2 = MSG_SOUNDROM_0B_DESC,
	},
	{
		.id = SONG_0D,
		.msg_name1 = MSG_SOUNDROM_0C_NAME,
		.msg_name2 = MSG_SOUNDROM_0C_DESC,
	},
	{
		.id = SONG_0E,
		.msg_name1 = MSG_SOUNDROM_0D_NAME,
		.msg_name2 = MSG_SOUNDROM_0D_DESC,
	},
	{
		.id = SONG_0F,
		.msg_name1 = MSG_SOUNDROM_0E_NAME,
		.msg_name2 = MSG_SOUNDROM_0E_DESC,
	},
	{
		.id = SONG_10,
		.msg_name1 = MSG_SOUNDROM_0F_NAME,
		.msg_name2 = MSG_SOUNDROM_0F_DESC,
	},
	{
		.id = SONG_11,
		.msg_name1 = MSG_SOUNDROM_10_NAME,
		.msg_name2 = MSG_SOUNDROM_10_DESC,
	},
	{
		.id = SONG_12,
		.msg_name1 = MSG_SOUNDROM_11_NAME,
		.msg_name2 = MSG_SOUNDROM_11_DESC,
	},
	{
		.id = SONG_13,
		.msg_name1 = MSG_SOUNDROM_12_NAME,
		.msg_name2 = MSG_SOUNDROM_12_DESC,
	},
	{
		.id = SONG_14,
		.msg_name1 = MSG_SOUNDROM_13_NAME,
		.msg_name2 = MSG_SOUNDROM_13_DESC,
	},
	{
		.id = SONG_15,
		.msg_name1 = MSG_SOUNDROM_14_NAME,
		.msg_name2 = MSG_SOUNDROM_14_DESC,
	},
	{
		.id = SONG_16,
		.msg_name1 = MSG_SOUNDROM_15_NAME,
		.msg_name2 = MSG_SOUNDROM_15_DESC,
	},
	{
		.id = SONG_17,
		.msg_name1 = MSG_SOUNDROM_16_NAME,
		.msg_name2 = MSG_SOUNDROM_16_DESC,
	},
	{
		.id = SONG_18,
		.msg_name1 = MSG_SOUNDROM_17_NAME,
		.msg_name2 = MSG_SOUNDROM_17_DESC,
	},
	{
		.id = SONG_19,
		.msg_name1 = MSG_SOUNDROM_18_NAME,
		.msg_name2 = MSG_SOUNDROM_18_DESC,
	},
	{
		.id = SONG_1A,
		.msg_name1 = MSG_SOUNDROM_19_NAME,
		.msg_name2 = MSG_SOUNDROM_19_DESC,
	},
	{
		.id = SONG_1B,
		.msg_name1 = MSG_SOUNDROM_1A_NAME,
		.msg_name2 = MSG_SOUNDROM_1A_DESC,
	},
	{
		.id = SONG_1C,
		.msg_name1 = MSG_SOUNDROM_1B_NAME,
		.msg_name2 = MSG_SOUNDROM_1B_DESC,
	},
	{
		.id = SONG_1E,
		.msg_name1 = MSG_SOUNDROM_1C_NAME,
		.msg_name2 = MSG_SOUNDROM_1C_DESC,
	},
	{
		.id = SONG_1F,
		.msg_name1 = MSG_SOUNDROM_1D_NAME,
		.msg_name2 = MSG_SOUNDROM_1D_DESC,
	},
	{
		.id = SONG_20,
		.msg_name1 = MSG_SOUNDROM_1E_NAME,
		.msg_name2 = MSG_SOUNDROM_1E_DESC,
	},
	{
		.id = SONG_21,
		.msg_name1 = MSG_SOUNDROM_1F_NAME,
		.msg_name2 = MSG_SOUNDROM_1F_DESC,
	},
	{
		.id = SONG_22,
		.msg_name1 = MSG_SOUNDROM_20_NAME,
		.msg_name2 = MSG_SOUNDROM_20_DESC,
	},
	{
		.id = SONG_23,
		.msg_name1 = MSG_SOUNDROM_21_NAME,
		.msg_name2 = MSG_SOUNDROM_21_DESC,
	},
	{
		.id = SONG_24,
		.msg_name1 = MSG_SOUNDROM_22_NAME,
		.msg_name2 = MSG_SOUNDROM_22_DESC,
	},
	{
		.id = SONG_25,
		.msg_name1 = MSG_SOUNDROM_23_NAME,
		.msg_name2 = MSG_SOUNDROM_23_DESC,
	},
	{
		.id = SONG_26,
		.msg_name1 = MSG_SOUNDROM_24_NAME,
		.msg_name2 = MSG_SOUNDROM_24_DESC,
	},
	{
		.id = SONG_27,
		.msg_name1 = MSG_SOUNDROM_25_NAME,
		.msg_name2 = MSG_SOUNDROM_25_DESC,
	},
	{
		.id = SONG_28,
		.msg_name1 = MSG_SOUNDROM_26_NAME,
		.msg_name2 = MSG_SOUNDROM_26_DESC,
	},
	{
		.id = SONG_29,
		.msg_name1 = MSG_SOUNDROM_27_NAME,
		.msg_name2 = MSG_SOUNDROM_27_DESC,
	},
	{
		.id = SONG_2A,
		.msg_name1 = MSG_SOUNDROM_28_NAME,
		.msg_name2 = MSG_SOUNDROM_28_DESC,
	},
	{
		.id = SONG_2B,
		.msg_name1 = MSG_SOUNDROM_29_NAME,
		.msg_name2 = MSG_SOUNDROM_29_DESC,
	},
	{
		.id = SONG_2C,
		.msg_name1 = MSG_SOUNDROM_2A_NAME,
		.msg_name2 = MSG_SOUNDROM_2A_DESC,
	},
	{
		.id = SONG_2D,
		.msg_name1 = MSG_SOUNDROM_2B_NAME,
		.msg_name2 = MSG_SOUNDROM_2B_DESC,
	},
	{
		.id = SONG_2E,
		.msg_name1 = MSG_SOUNDROM_2C_NAME,
		.msg_name2 = MSG_SOUNDROM_2C_DESC,
	},
	{
		.id = SONG_31,
		.msg_name1 = MSG_SOUNDROM_2D_NAME,
		.msg_name2 = MSG_SOUNDROM_2D_DESC,
	},
	{
		.id = SONG_32,
		.msg_name1 = MSG_SOUNDROM_2E_NAME,
		.msg_name2 = MSG_SOUNDROM_2E_DESC,
	},
	{
		.id = SONG_33,
		.msg_name1 = MSG_SOUNDROM_2F_NAME,
		.msg_name2 = MSG_SOUNDROM_2F_DESC,
	},
	{
		.id = SONG_34,
		.msg_name1 = MSG_SOUNDROM_30_NAME,
		.msg_name2 = MSG_SOUNDROM_30_DESC,
	},
	{
		.id = SONG_35,
		.msg_name1 = MSG_SOUNDROM_31_NAME,
		.msg_name2 = MSG_SOUNDROM_31_DESC,
	},
	{
		.id = SONG_36,
		.msg_name1 = MSG_SOUNDROM_32_NAME,
		.msg_name2 = MSG_SOUNDROM_32_DESC,
	},
	{
		.id = SONG_37,
		.msg_name1 = MSG_SOUNDROM_33_NAME,
		.msg_name2 = MSG_SOUNDROM_33_DESC,
	},
	{
		.id = SONG_38,
		.msg_name1 = MSG_SOUNDROM_34_NAME,
		.msg_name2 = MSG_SOUNDROM_34_DESC,
	},
	{
		.id = SONG_39,
		.msg_name1 = MSG_SOUNDROM_35_NAME,
		.msg_name2 = MSG_SOUNDROM_35_DESC,
	},
	{
		.id = SONG_3A,
		.msg_name1 = MSG_SOUNDROM_36_NAME,
		.msg_name2 = MSG_SOUNDROM_36_DESC,
	},
	{
		.id = SONG_3B,
		.msg_name1 = MSG_SOUNDROM_37_NAME,
		.msg_name2 = MSG_SOUNDROM_37_DESC,
	},
	{
		.id = SONG_3C,
		.msg_name1 = MSG_SOUNDROM_38_NAME,
		.msg_name2 = MSG_SOUNDROM_38_DESC,
	},
	{
		.id = SONG_3D,
		.msg_name1 = MSG_SOUNDROM_39_NAME,
		.msg_name2 = MSG_SOUNDROM_39_DESC,
	},
	{
		.id = SONG_3E,
		.msg_name1 = MSG_SOUNDROM_3A_NAME,
		.msg_name2 = MSG_SOUNDROM_3A_DESC,
	},
	{
		.id = SONG_3F,
		.msg_name1 = MSG_SOUNDROM_3B_NAME,
		.msg_name2 = MSG_SOUNDROM_3B_DESC,
	},
	{
		.id = SONG_41,
		.msg_name1 = MSG_SOUNDROM_3C_NAME,
		.msg_name2 = MSG_SOUNDROM_3C_DESC,
	},
	{
		.id = SONG_42,
		.msg_name1 = MSG_SOUNDROM_3D_NAME,
		.msg_name2 = MSG_SOUNDROM_3D_DESC,
	},
	{
		.id = SONG_43,
		.msg_name1 = MSG_SOUNDROM_3E_NAME,
		.msg_name2 = MSG_SOUNDROM_3E_DESC,
	},
	{
		.id = SONG_47,
		.msg_name1 = MSG_SOUNDROM_3F_NAME,
		.msg_name2 = MSG_SOUNDROM_3F_DESC,
	},
	{
		.id = SONG_48,
		.msg_name1 = MSG_SOUNDROM_40_NAME,
		.msg_name2 = MSG_SOUNDROM_40_DESC,
	},
	{
		.id = SONG_49,
		.msg_name1 = MSG_SOUNDROM_41_NAME,
		.msg_name2 = MSG_SOUNDROM_41_DESC,
	},
	{
		.id = -1,
	},
};

CONST_DATA u16 Sprite_0868A988[] = {
	2,
	OAM0_SHAPE_8x8, OAM1_SIZE_8x8, OAM2_CHR(0x380) + OAM2_LAYER(1),
	OAM0_SHAPE_8x8 + OAM0_Y(8), OAM1_SIZE_8x8, OAM2_CHR(0x386) + OAM2_LAYER(1),
};

CONST_DATA struct SoundRoomCgInfo gSoundRoomCgInfo[SOUNDROOM_CG_NUM] = {
	{ EndingCG_Img1, EndingCG_Pal1 },
	{ EndingCG_Img2, EndingCG_Pal2 },
	{ EndingCG_Img3, EndingCG_Pal3 },
	{ EndingCG_Img4, EndingCG_Pal4 },
	{ EndingCG_Img5, EndingCG_Pal5 },
	{ EndingCG_Img6, EndingCG_Pal6 },
	{ EndingCG_Img7, EndingCG_Pal7 },
	{ EndingCG_Img8, EndingCG_Pal8 },
	{ EndingCG_Img9, EndingCG_Pal9 },
	{ EndingCG_Img10, EndingCG_Pal10 },
};

CONST_DATA u16 Sprite_0868A9E8[] = {
	1,
	OAM0_SHAPE_16x16, OAM1_SIZE_16x16, OAM2_CHR(0x100) + OAM2_LAYER(1),
};

CONST_DATA u16 Sprite_0868A9F0[] = {
	1,
	OAM0_SHAPE_16x16, OAM1_SIZE_16x16, OAM2_CHR(0x102) + OAM2_LAYER(1),
};

CONST_DATA u16 Sprite_0868A9F8[] = {
	1,
	OAM0_SHAPE_32x16, OAM1_SIZE_32x16, OAM2_CHR(0x104) + OAM2_LAYER(1),
	0x6D08, 0x0833, 0x6D2C, 0x0833,
};

struct ProcScr CONST_DATA ProcScr_SoundRoom[] = {
	PROC_SLEEP(0),
	PROC_CALL(Soundroom_Init),
	PROC_CALL(StartSlowFadeFromBlack),
	PROC_REPEAT(WhileFadeExists),

PROC_LABEL(PL_SOUNDROOM_MAIN),
	PROC_REPEAT(func_fe6_0808BBCC),

PROC_LABEL(PL_SOUNDROOM_SLIDE),
	PROC_REPEAT(func_fe6_0808BCBC),
	PROC_REPEAT(func_fe6_0808BCF0),
	PROC_GOTO(PL_SOUNDROOM_MAIN),

PROC_LABEL(PL_SOUNDROOM_EXIT),
	PROC_CALL(StartSlowFadeToBlack),
	PROC_REPEAT(WhileFadeExists),
	PROC_CALL(func_fe6_0808BD28),
	PROC_END,
};

struct ProcScr CONST_DATA ProcScr_0868AA80[] = {
	PROC_SLEEP(0),
	PROC_CALL(func_fe6_0808BD6C),
	PROC_REPEAT(func_fe6_0808BD78),
	PROC_REPEAT(func_fe6_0808BDF8),
	PROC_END,
};

struct ProcScr CONST_DATA ProcScr_0868AAA8[] = {
	PROC_SLEEP(0),
	PROC_CALL(func_fe6_0808C084),
	PROC_REPEAT(func_fe6_0808C098),
	PROC_END,
};

void PutSoundRoomCG(int seed)
{
	int i;
	int cg = seed;

	cg %= SOUNDROOM_CG_NUM;

	for (i = 0; i < 3; i++) {
		if (gSoundRoomRecentCgs[i % 2] == cg)
			cg = (cg + 1) % SOUNDROOM_CG_NUM;
	}

	gSoundRoomRecentCgs[1] = gSoundRoomRecentCgs[0];
	gSoundRoomRecentCgs[0] = cg;

	Decompress(gSoundRoomCgInfo[cg].img, (u8 *)BG_VRAM + 0x2800 + GetBgChrOffset(BG_2));
	ApplyPaletteExt(gSoundRoomCgInfo[gSoundRoomRecentCgs[0]].pal, 0xC0, 0x20);
}

int CountTotalSoundRoomSongs(void)
{
	int ret = 0;
	struct SoundRoomInfo *it = gSoundRoomInfo;

	do {
		if (it->id < 0)
			break;

		it++, ret++;
	} while (1);

	return ret;
}

void Soundroom_Init(struct ProcSoundRoom *proc)
{
	InitBgs(0);
	ResetTextFont();
	ResetText();
	ApplySystemObjectsGraphics();
	InitSystemTextFont();

	SetDispEnable(1, 1, 1, 1, 1);
	gDispIo.bg0_ct.priority = 0;
	gDispIo.bg1_ct.priority = 2;
	gDispIo.bg2_ct.priority = 1;
	gDispIo.bg3_ct.priority = 3;
	SetWinEnable(0, 0, 0);

	SetBlankChr(0);
	TmFill(gBg0Tm, 0);
	TmFill(gBg1Tm, 0);
	TmFill(gBg2Tm, 0);
	TmFill(gBg3Tm, 0);
	EnableBgSync(0xF);

	proc->unk_34 = 0;
	proc->cur_index = 0;

	gSoundRoomRecentCgs[1] |= 0xFF;
	gSoundRoomRecentCgs[0] |= 0xFF;

	proc->unk_29 = 1;
	proc->unk_2c = 0;
	proc->unk_38 = 0;
	proc->unk_39 = 0;
	proc->unk_40 = 0;
	proc->unk_41 = 0;

	func_fe6_0808BE70();
	func_fe6_0808BF00(proc);
	func_fe6_0808BFF0();

	SetBgOffset(BG_0, 0, 0);
	SetBgOffset(BG_1, 0, 0);

	Decompress(Img_EndingPInfoWindow, (void *)(BG_VRAM + GetBgChrOffset(BG_1)));
	ApplyPaletteExt(Pal_EndingPInfoWindow, 0x80, 0x40);
	TmApplyTsa(gBg1Tm, (u8 const *)gUnk_0832C5E8, 0x4000);

	SetBgOffset(BG_2, (u16)0xFF98, (u16)0xFFC0);

	PutSoundRoomCG(GetGameTime());

	PutEndingCreditTm(gBg2Tm, 0x6140, 15, 10);

	Decompress(Img_MonologueBG, (void *)(BG_VRAM + GetBgChrOffset(BG_3)));
	ApplyPaletteExt(gUnk_0832CA9C, 0xE0, 0x20);
	TmApplyTsa(gBg3Tm, Tsa_EndingPInfoBG, 0x7000);

	Decompress(gUnk_0832CAFC, (void *)0x06012000);
	ApplyPaletteExt(gUnk_0832CC90, 0x280, 0x20);
	Decompress(Img_HorizontalSpinningArrow, (void *)0x06017000);
	ApplyPaletteExt(Pal_SpinningArrow, 0x2A0, 0x20);

	proc->unk_2e = 0x100;
	proc->sprite_proc = NewProc_0868AAA8(proc);
}

void func_fe6_0808BBCC(struct ProcSoundRoom *proc)
{
	if (gKeySt->repeated & KEY_DPAD_LEFT) {
		Proc_Goto(proc, PL_SOUNDROOM_SLIDE);
		PlaySe(SONG_67);

		if ((int)proc->cur_index > 0)
			proc->cur_index--;
		else
			proc->cur_index = CountTotalSoundRoomSongs() - 1;

		proc->unk_38 = 1;
	} else {
		if (gKeySt->repeated & KEY_DPAD_RIGHT) {
			Proc_Goto(proc, PL_SOUNDROOM_SLIDE);
			PlaySe(SONG_67);

			if (proc->cur_index + 1 == CountTotalSoundRoomSongs())
				proc->cur_index = 0;
			else
				proc->cur_index++;

			proc->unk_39 = 1;
		} else if (proc->unk_40 == 0) {

			if (gKeySt->pressed & KEY_BUTTON_B) {
				FadeBgmOut(-1);
				proc->unk_29 = 1;
			} else if (gKeySt->pressed & KEY_BUTTON_A) {
				NewProc_0868AA80(proc);
				proc->unk_40 = 1;
			} else if (gKeySt->pressed & KEY_BUTTON_START) {
				Proc_Goto(proc, PL_SOUNDROOM_EXIT);

				if (IsBgmPlaying())
					FadeBgmOut(-1);
			}
		}
	}
}

void func_fe6_0808BCBC(struct ProcSoundRoom *proc)
{
	proc->unk_2c++;
	proc->unk_2e = (6 - proc->unk_2c) * 0x100 / 6;

	if (proc->unk_2c == 6) {
		func_fe6_0808BF00(proc);
		Proc_Break(proc);
	}
}

void func_fe6_0808BCF0(struct ProcSoundRoom *proc)
{
	proc->unk_2c--;
	proc->unk_2e = (6 - proc->unk_2c) * 0x100 / 6;

	if (proc->unk_2c == 0) {
		Proc_Break(proc);
		proc->unk_38 = 0;
		proc->unk_39 = 0;
	}
}

void func_fe6_0808BD28(struct ProcSoundRoom *proc)
{
	SetDispEnable(0, 0, 0, 0, 0);
	Proc_End(proc->sprite_proc);
}

ProcPtr SaveMenu_ExecSoundroom(ProcPtr parent)
{
	return SpawnProcLocking(ProcScr_SoundRoom, parent);
}

void func_fe6_0808BD6C(struct ProcSoundRoomConfirm *proc)
{
	proc->unk_2c = 0;
	proc->cur_index = proc->proc_parent->cur_index;
}

void func_fe6_0808BD78(struct ProcSoundRoomConfirm *proc)
{
	proc->unk_2c++;

	gDispIo.blend_ct.effect = BLEND_EFFECT_BRIGHTEN;
	gDispIo.blend_coef_a = 0;
	gDispIo.blend_coef_b = 0;
	gDispIo.blend_y = proc->unk_2c / 3;
	SetBlendTargetA(0, 0, 1, 0, 0);

	if (proc->unk_2c == 0x30) {
		StartBgm(gSoundRoomInfo[proc->cur_index].id, NULL);
		PutSoundRoomCG(GetGameTime());
		Proc_Break(proc);
	}
}

void func_fe6_0808BDF8(struct ProcSoundRoomConfirm *proc)
{
	proc->unk_2c--;

	gDispIo.blend_ct.effect = BLEND_EFFECT_BRIGHTEN;
	gDispIo.blend_coef_a = 0;
	gDispIo.blend_coef_b = 0;
	gDispIo.blend_y = proc->unk_2c / 3;
	SetBlendTargetA(0, 0, 1, 0, 0);

	if (proc->unk_2c == 0) {
		Proc_Break(proc);
		proc->proc_parent->unk_40 = 0;
	}
}

ProcPtr NewProc_0868AA80(struct ProcSoundRoom *proc)
{
	return SpawnProc(ProcScr_0868AA80, proc);
}

void func_fe6_0808BE70(void)
{
	int i;
	u32 vram = (u32)OBJ_VRAM1;

	InitSpriteTextFont(&gSoundRoomText.font, (u8 *)vram, 5);
	ApplyPalettes(Pal_Text, 0x1A, 2);
	gPal[0x1A * 0x10] = 0;
	EnablePalSync();

	SetTextFont(&gSoundRoomText.font);
	InitSpriteText(&gSoundRoomText.texts[0]);
	InitSpriteText(&gSoundRoomText.texts[1]);

	for (i = 0; i < 3; i++)
		InitSpriteText(&gSoundRoomText.texts[i + 2]);

	SetTextFont(NULL);

	gSoundRoomText.oam2[0] = 0xa000 + (((vram & 0x1ffff) >> 5) & 0x3ff);
}

void func_fe6_0808BF00(struct ProcSoundRoom *proc)
{
	int width;
	int height;
	u32 cur_index = proc->cur_index;

	SetTextFont(&gSoundRoomText.font);
	SetTextFontGlyphs(TEXT_GLYPHS_TALK);

	func_fe6_08071C00(DecodeMsg(gSoundRoomInfo[cur_index].msg_name1), &width, &height);

	SpriteText_DrawBackgroundExt(&gSoundRoomText.texts[0], 0);
	Text_SetCursor(&gSoundRoomText.texts[0], (0xb0 - width) / 2);
	Text_SetColor(&gSoundRoomText.texts[0], 0);
	Text_DrawString(&gSoundRoomText.texts[0], DecodeMsg(gSoundRoomInfo[cur_index].msg_name1));

	SpriteText_DrawBackgroundExt(&gSoundRoomText.texts[1], 0);

	if (cur_index == 0) {
		proc->unk_41 = 1;
	} else {
		proc->unk_41 = 0;

		func_fe6_08071C00(DecodeMsg(gSoundRoomInfo[cur_index].msg_name2), &width, &height);
		Text_SetCursor(&gSoundRoomText.texts[1], 0xa8 - width);
		Text_SetColor(&gSoundRoomText.texts[1], 0);
		Text_DrawString(&gSoundRoomText.texts[1], DecodeMsg(gSoundRoomInfo[cur_index].msg_name2));
	}

	SetTextFont(NULL);
}

void func_fe6_0808BFF0(void)
{
	SetTextFont(&gSoundRoomText.font);
	SetTextFontGlyphs(0);

	SpriteText_DrawBackgroundExt(&gSoundRoomText.texts[2], 0);
	Text_SetCursor(&gSoundRoomText.texts[2], 0);
	Text_SetColor(&gSoundRoomText.texts[2], 0);
	Text_DrawString(&gSoundRoomText.texts[2], String_Xmap_08336D3C);

	SpriteText_DrawBackgroundExt(&gSoundRoomText.texts[3], 0);
	Text_SetCursor(&gSoundRoomText.texts[3], 0);
	Text_SetColor(&gSoundRoomText.texts[3], 0);
	Text_DrawString(&gSoundRoomText.texts[3], String_Xmap_08336D48);

	SpriteText_DrawBackgroundExt(&gSoundRoomText.texts[4], 0);
	Text_SetCursor(&gSoundRoomText.texts[4], 0);
	Text_SetColor(&gSoundRoomText.texts[4], 0);
	Text_DrawString(&gSoundRoomText.texts[4], String_Xmap_08336D54);

	SetTextFont(NULL);
}

void func_fe6_0808C084(struct ProcSoundRoomSprite *proc)
{
	proc->parent = proc->proc_parent;
	proc->arrow_anim_l = 0;
	proc->arrow_anim_r = 0;
}

void func_fe6_0808C098(struct ProcSoundRoomSprite *proc)
{
	int i, j, y;

	PutSprite(11, 0x14, 0x4D, Sprite_0868A9E8, OAM2_PAL(4));
	PutSprite(11, 0x14, 0x61, Sprite_0868A9F0, OAM2_PAL(4));
	PutSprite(11, 0x14, 0x75, Sprite_0868A9F8, OAM2_PAL(4));

	PutSpriteExt(11, 0x1A, 0x1A, Sprite_0868A988, OAM2_PAL(5) + (proc->arrow_anim_l >> 3) % 6);
	PutSpriteExt(11, OAM1_HFLIP + 0xCE, 0x1A, Sprite_0868A988, OAM2_PAL(5) + (proc->arrow_anim_r >> 3) % 6);

	if (proc->parent->unk_2e > 0x30) {
		SetObjAffine(0,
			Div(+COS_Q12(0) * 16, 0x100),
			Div(-SIN_Q12(0) * 16, proc->parent->unk_2e),
			Div(+SIN_Q12(0) * 16, 0x100),
			Div(+COS_Q12(0) * 16, proc->parent->unk_2e));

		if (proc->parent->unk_41 != 0) {
			y = 0x18;
		} else {
			y = 0x10;

			for (i = 0; i < 5; i++)
				PutSpriteExt(4, 0x20 + i * 0x20, OAM0_AFFINE_ENABLE + 0x10 + y, Sprite_32x16, gSoundRoomText.oam2[0] + 0x40 + i * 4 + OAM2_PAL(1));

			PutSpriteExt(4, 0x20 + i * 0x20, OAM0_AFFINE_ENABLE + 0x10 + y, Sprite_16x16, gSoundRoomText.oam2[0] + 0x40 + i * 4 + OAM2_PAL(1));
		}

		for (i = 0; i < 5; i++)
			PutSpriteExt(4, 0x20 + i * 0x20, OAM0_AFFINE_ENABLE + y, Sprite_32x16, gSoundRoomText.oam2[0] + i * 4 + OAM2_PAL(1));

		PutSpriteExt(4, 0x20 + i * 0x20, OAM0_AFFINE_ENABLE + y, Sprite_16x16, gSoundRoomText.oam2[0] + i * 4 + OAM2_PAL(1));
	}

	for (y = 0; y < 3; y++) {
		for (j = 0; j < 2; j++)
			PutSpriteExt(4, 0x28 + (y >> 1) * 0x10 + j * 0x20, 0x4C + y * 20, Sprite_32x16, gSoundRoomText.oam2[0] + 0x80 + j * 4 + y * 0x40);
	}

	proc->arrow_anim_l++;
	proc->arrow_anim_r++;

	if (proc->parent->unk_38)
		proc->arrow_anim_l++;

	if (proc->parent->unk_39)
		proc->arrow_anim_r++;

	if ((proc->arrow_anim_l >> 3) > 5)
		proc->arrow_anim_l -= 0x30;

	if ((proc->arrow_anim_r >> 3) > 5)
		proc->arrow_anim_r -= 0x30;
}

ProcPtr NewProc_0868AAA8(struct ProcSoundRoom *proc)
{
	return SpawnProc(ProcScr_0868AAA8, proc);
}
