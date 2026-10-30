#include "prelude.h"
#include "proc.h"
#include "banim.h"
#include "oam.h"
#include "sprite.h"
#include "item.h"
#include "util.h"
#include "talk.h"
#include "armfunc.h"

#include "opinfo.h"

#include "constants/jids.h"

EWRAM_OVERLAY(opinfo) struct EkrMainMiniDesc OpEkrMiniDesc = {};
EWRAM_OVERLAY(opinfo) u16 OpEkrMini_ImgBuf[0x1000] = {};
EWRAM_OVERLAY(opinfo) u16 OpEkrMini_OamBuf[0x2C00] = {};
EWRAM_OVERLAY(opinfo) u16 OpEkrMini_PalBuf[0x50] = {};
EWRAM_OVERLAY(opinfo) u8  OpEkrMini_ScrBuf[0x2A00] = {};

EWRAM_OVERLAY(opinfo) struct EfxopMagicDesc OpEkrMagiDesc = {};
EWRAM_OVERLAY(opinfo) u8 OpEkrMagi_BgImgBuf[0x2000] = {};
EWRAM_OVERLAY(opinfo) u8 OpEkrMagi_BgTsaBuf[0x800] = {};
EWRAM_OVERLAY(opinfo) u8 OpEkrMagi_ObImgBuf[0x1000] = {};

EWRAM_OVERLAY(opinfo) struct EkrTerrainfxDesc OpEkrTerrainDesc = {};
EWRAM_OVERLAY(opinfo) u8 OpEkrTerrain_ImgBuf[0x2000] = {};

EWRAM_OVERLAY(opinfo) struct Text OpClassDemoTexts[6] = {};

EWRAM_OVERLAY(opinfo) struct OpClassDemoCharPos OpClassDemoCharPositions[14] = {};

CONST_DATA i8 OpClassDemo_MagiConfig[35 * 5] = {
	0, 0, 0, 0, 0,
	0, 0, 0, 0, 0,
	0, 0, 0, 0, 0,
	0, 0, 0, 0, 0,
	0, 0, 0, 0, 0,
	3, 0, 0, 0, 0,
	0, 0, 0, 0, 0,
	0, 0, 0, 0, 0,
	0, 0, 0, 0, 0,
	3, 0, 0, 0, 0,
	0, 0, 0, 0, 0,
	1, 0, 0, 0, 0,
	0, 0, 0, 0, 0,
	0, 0, 0, 0, 0,
	0, 0, 0, 0, 0,
	0, 0, 0, 0, 0,
	0, 0, 0, 0, 0,
	0, 0, 0, 0, 0,
	0, 0, 0, 0, 0,
	0, 0, 0, 0, 0,
	0, 0, 0, 0, 0,
	3, 0, 0, 0, 0,
	2, 0, 0, 0, 0,
	0, 0, 0, 0, 0,
	0, 0, 0, 0, 0,
	0, 0, 0, 0, 0,
	1, 0, 0, 0, 0,
	3, 0, 0, 0, 0,
	0, 0, 0, 0, 0,
	0, 0, 0, 0, 0,
	0, 0, 0, 0, 0,
	0, 0, 0, 0, 0,
	0, 0, 0, 0, 0,
	0, 0, 0, 0, 0,
	0, 0, 0, 0, 0,
};

CONST_DATA u8 OpClassDemo_TerrainConfig[35][2] = {
	{ 0x14, 0x14 },
	{ 0x11, 0x00 },
	{ 0x0B, 0x12 },
	{ 0x13, 0x13 },
	{ 0x1B, 0x21 },
	{ 0x0E, 0x0F },
	{ 0x06, 0x06 },
	{ 0x0B, 0x18 },
	{ 0x01, 0x01 },
	{ 0x00, 0x11 },
	{ 0x11, 0x00 },
	{ 0x09, 0x09 },
	{ 0x00, 0x00 },
	{ 0x16, 0x16 },
	{ 0x0C, 0x0C },
	{ 0x09, 0x09 },
	{ 0x13, 0x13 },
	{ 0x0E, 0x0E },
	{ 0x19, 0x19 },
	{ 0x04, 0x04 },
	{ 0x13, 0x13 },
	{ 0x09, 0x09 },
	{ 0x11, 0x00 },
	{ 0x17, 0x17 },
	{ 0x0D, 0x0D },
	{ 0x10, 0x10 },
	{ 0x09, 0x09 },
	{ 0x14, 0x14 },
	{ 0x00, 0x00 },
	{ 0x00, 0x00 },
	{ 0x14, 0x14 },
	{ 0x02, 0x02 },
	{ 0x16, 0x16 },
	{ 0x09, 0x09 },
	{ 0x1A, 0x1A },
};

CONST_DATA u8 OpClassDemo_JidConfig[35] = {
	JID_ROY,
	JID_CAVALIER,
	JID_PALADIN,
	JID_ARCHER,
	JID_ARMOR,
	JID_CLERIC,
	JID_THIEF,
	JID_MERCENARY,
	JID_FIGHTER,
	JID_TROUBADOUR,
	JID_MYRMIDON,
	JID_MAGE,
	JID_NOMAD_F,
	JID_BRIGAND,
	JID_PIRATE,
	JID_SHAMAN_F,
	JID_BARD,
	JID_DANCER,
	JID_PEGASUSKNIGHT,
	JID_WYVERNRIDER,
	JID_WARRIOR,
	JID_DRUID,
	JID_VALKYRIE,
	JID_HERO,
	JID_FALCONKNIGHT,
	JID_BERSERKER,
	JID_SAGE_F,
	JID_BISHOP,
	JID_SWORDMASTER,
	JID_NOMADTROOPER,
	JID_SNIPER,
	JID_GENERAL,
	JID_WYVERNLORD,
	JID_MANAKETE,
	JID_KING
};

void HBlank_ClassDemoMain(void)
{
	u16 vcount = (REG_VCOUNT + 1);

	if (vcount < 110) {
		REG_BG0CNT = (0xFFFC & REG_BG0CNT) + 2;
		REG_BG2CNT = (0xFFFC & REG_BG2CNT) + 2;
	} else {
		REG_BG0CNT = (0xFFFC & REG_BG0CNT) + 1;
		REG_BG2CNT = (0xFFFC & REG_BG2CNT) + 1;
	}
}

void OpInfo_EfxmagicMiniCallBack(void)
{
	SetBlendConfig(1, 0x10, 0x10, 0);

	SetBlendTargetA(0, 1, 0, 0, 0);
	SetBlendTargetB(0, 0, 1, 1, 1);

	SetWinEnable(1, 0, 0);
	SetWin0Box(0, 0, 240, 160);

	SetWin0Layers(1, 1, 1, 1, 1);
	SetWOutLayers(1, 0, 1, 1, 1);

	gDispIo.win_ct.win0_enable_blend = 1;

#if FE6
	gDispIo.win_ct.wout_enable_blend = 0;
#elif FE8
	gDispIo.win_ct.win1_enable_blend = 0;
#endif

	gDispIo.blend_ct.target2_enable_bd = 1;
}

const char Str_OpInfo_Hp[]  = TEXT("ＨＰ", "HP");
const char Str_OpInfo_Str[] = TEXT("力",   "Str");
const char Str_OpInfo_Skl[] = TEXT("技",   "Skl");
const char Str_OpInfo_Spd[] = TEXT("速さ", "Spd");
const char Str_OpInfo_Def[] = TEXT("守備", "Def");
const char Str_OpInfo_Res[] = TEXT("魔防", "Res");

void ClassDemoMain_ExecEkrMainMini(struct ProcClassDemoMain *proc)
{
	int i, k;

	int use_mag = false;

	char const *msgs[] = {
		Str_OpInfo_Hp,
		Str_OpInfo_Str,
		Str_OpInfo_Skl,
		Str_OpInfo_Spd,
		Str_OpInfo_Def,
		Str_OpInfo_Res
	};

	for (i = ITEM_KIND_STAFF; i <= ITEM_KIND_ELDER; i++) {
		if (GetJInfo(OpClassDemo_JidConfig[proc->index])->wexp[i] != 0) {
			use_mag = true;
			break;
		}
	}

	proc->frame_timer = 0;
	proc->total_timer = 0;
	proc->ctrl_index = 0;
	proc->unk_3E = 1;
	proc->anim_x = 0xFA;

	TmFill(gBg0Tm, 0);
	TmFill(gBg1Tm, 0);
	TmFill(gBg2Tm, 0);

	if (proc->index == 0) {
		proc->ctrl_index = 0;
	} else {
		i = 0;
		k = 0;

		while (1) {
			i++;
			if (gOpClassDemoBanimCtrl[i].duration == 0) {
				k++;
				if (k == proc->index)
					break;
			}
		}
		proc->ctrl_index = i + 1;
	}
	proc->round_type = gOpClassDemoBanimCtrl[proc->ctrl_index].round_type;

	SetDispEnable(0, 0, 0, 0, 0);
	ResetTextFont();
	ResetText();

	gDispIo.bg0_ct.priority = 2;
	gDispIo.bg1_ct.priority = 2;
	gDispIo.bg2_ct.priority = 2;
	gDispIo.bg3_ct.priority = 3;

	SetBgOffset(BG_0, 0, 0);
	SetBgOffset(BG_1, 0, 0);
	SetBgOffset(BG_2, 0, 0);
	SetBgOffset(BG_3, 0, 0);

	Decompress(Img_MonologueBG, (u8 *)BG_VRAM + GetBgChrOffset(BG_3));
	ApplyPalette(Pal_Op_0835AB08, 0xA);
	TmApplyTsa(gBg3Tm, Tsa_Op_0835AB28, 0xA000);
	Decompress(Img_Op_0835A3E8, (u8 *)BG_VRAM + GetBgChrOffset(BG_2));
	ApplyPalette(Pal_Op_0835A5D0, 0x9);
	TmApplyTsa(gBg2Tm, Tsa_Op_0835A5F0, 0x9000);

	EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT | BG2_SYNC_BIT | BG3_SYNC_BIT);

	TmFill(gBg0Tm, 0);

	proc->unit_status[0] = GetJInfo(OpClassDemo_JidConfig[proc->index])->base_hp;
	proc->unit_status[1] = GetJInfo(OpClassDemo_JidConfig[proc->index])->base_pow;
	proc->unit_status[2] = GetJInfo(OpClassDemo_JidConfig[proc->index])->base_skl;
	proc->unit_status[3] = GetJInfo(OpClassDemo_JidConfig[proc->index])->base_spd;
	proc->unit_status[4] = GetJInfo(OpClassDemo_JidConfig[proc->index])->base_def;
	proc->unit_status[5] = GetJInfo(OpClassDemo_JidConfig[proc->index])->base_res;

	for (i = 0; i < 6; i++) {
		InitText(&OpClassDemoTexts[i], 3);
		ClearText(&OpClassDemoTexts[i]);
		Text_SetColor(&OpClassDemoTexts[i], TEXT_COLOR_SYSTEM_GOLD);
		Text_SetCursor(&OpClassDemoTexts[i], 0);

		if (use_mag && i == 1)
			Text_DrawString(&OpClassDemoTexts[1], Str_OpInfo_Mag);
		else
			Text_DrawString(&OpClassDemoTexts[i], msgs[i]);

		PutText(&OpClassDemoTexts[i], gBg0Tm + TM_OFFSET(1, 1 + i * 2));
		PutNumber(gBg0Tm + TM_OFFSET(5, 1 + i * 2), TEXT_COLOR_SYSTEM_WHITE, proc->unit_status[i]);
	}

	proc->procfx = StartClassDemoStatus(proc);

	InitTalk(0x100, 2, 0);
	SetInitTalkTextFont();
	ClearTalkText();
	EndTalk();
	StartTalkMsg(2, 15, OpClassDemo_IntroMsgs[proc->index]);
	SetTalkPrintColor(TEXT_COLOR_SYSTEM_WHITE);
	SetTalkFlag(TALK_FLAG_INSTANTSHIFT);
	SetTalkFlag(TALK_FLAG_NOBUBBLE);
	SetTalkFlag(TALK_FLAG_NOSKIP);
	SetTalkFlag(TALK_FLAG_NOFAST);
	SetTalkFlag(TALK_FLAG_SILENT);
	SetTalkPrintDelay(4);

	OpEkrMiniDesc.x = 0x104;
	OpEkrMiniDesc.y = 0x58;
	OpEkrMiniDesc.bid = OpClassDemo_BIDs[proc->index];
	OpEkrMiniDesc.round_type = ANIM_ROUND_TAKING_HIT_CLOSE;
	OpEkrMiniDesc.faction_pal = BANIMPAL_BLUE;
	OpEkrMiniDesc.pos = POS_R;
	OpEkrMiniDesc.oam2_chr = 0x180;
	OpEkrMiniDesc.oam2_pal = 2;
	OpEkrMiniDesc.img_buf = OpEkrMini_ImgBuf;
	OpEkrMiniDesc.oam_buf = OpEkrMini_OamBuf;
	OpEkrMiniDesc.pal_buf = OpEkrMini_PalBuf;
	OpEkrMiniDesc.scr_buf = OpEkrMini_ScrBuf;
	OpEkrMiniDesc.magicfx_desc = &OpEkrMagiDesc;

	OpEkrMagiDesc.magicFuncIdx = OpClassDemo_MagiConfig[proc->index * 5 + 0];
	OpEkrMagiDesc.xOffsetBg    = OpClassDemo_MagiConfig[proc->index * 5 + 1];
	OpEkrMagiDesc.yOffsetBg    = OpClassDemo_MagiConfig[proc->index * 5 + 2];
	OpEkrMagiDesc.xOffsetObj   = OpClassDemo_MagiConfig[proc->index * 5 + 3];
	OpEkrMagiDesc.yOffsetObj   = OpClassDemo_MagiConfig[proc->index * 5 + 4];
	OpEkrMagiDesc.objChr = 0x280;
	OpEkrMagiDesc.objPalId = 0xF;
	OpEkrMagiDesc.bgPalId = 0xF;
	OpEkrMagiDesc.bgChr = 0x200;
	OpEkrMagiDesc.bgPalId = 0xF;
	OpEkrMagiDesc.bg = BG_1;
	OpEkrMagiDesc.bgTmBuf = gBg1Tm;
	OpEkrMagiDesc.bgImgBuf = OpEkrMagi_BgImgBuf;
	OpEkrMagiDesc.bgTsaBuf = OpEkrMagi_BgTsaBuf;
	OpEkrMagiDesc.objImgBuf = OpEkrMagi_ObImgBuf;
	OpEkrMagiDesc.resetCallback = OpInfo_EfxmagicMiniCallBack;

	NewEkrUnitMainMini(&OpEkrMiniDesc);

	OpEkrTerrainDesc.terrain_l = OpClassDemo_TerrainConfig[proc->index][POS_L];
	OpEkrTerrainDesc.pal_l = 0xA;
	OpEkrTerrainDesc.chr_l = 0x380;
	OpEkrTerrainDesc.terrain_r = OpClassDemo_TerrainConfig[proc->index][POS_R];
	OpEkrTerrainDesc.pal_r = 0xB;
	OpEkrTerrainDesc.chr_r = 0x3C0;
	OpEkrTerrainDesc.distance = EKR_DISTANCE_CLOSE;
	OpEkrTerrainDesc.bg_index = -1;
	OpEkrTerrainDesc.vram_offset = (u32)OBJ_VRAM0;
	OpEkrTerrainDesc.img_buf = OpEkrTerrain_ImgBuf;

	NewEkrTerrainfx(&OpEkrTerrainDesc);
	EkrTerrainfx_SetPosition(&OpEkrTerrainDesc, 0xD0, 0x68, 0x130, 0x68);
	SetOnHBlankA(HBlank_ClassDemoMain);
}

void ClassDemoMain_Loop_Intro(struct ProcClassDemoMain *proc)
{
	proc->anim_x = proc->anim_x - 1 - (0x50 - proc->frame_timer) / 14;

	if (proc->anim_x < 180)
		proc->anim_x = 180;

	SetDispEnable(1, 1, 1, 1, 1);
	SetWinEnable(1, 0, 0);
	SetWin0Box(0, 80 - proc->frame_timer, 240, proc->frame_timer + 80);
	SetWin0Layers(1, 1, 1, 1, 1);
	SetWOutLayers(0, 0, 0, 0, 0);

	if (proc->frame_timer == 80) {
		proc->anim_x = 180;
		proc->frame_timer = 0;
		Proc_Break(proc);
		func_fe6_08095D48(proc->procfx);
	} else
		proc->frame_timer += 4;

	EkrMainMini_SetAnimPosition(&OpEkrMiniDesc, proc->anim_x, 88);
	EkrTerrainfx_SetPosition(&OpEkrTerrainDesc, proc->anim_x - 48, 104, proc->anim_x + 48, 104);
	SetOpClassDemoStatusPos(proc->procfx, 0x78);
}

void ClassDemoMain_Loop_Main(struct ProcClassDemoMain *proc)
{
	int ret = false;

	if (proc->total_timer > 0x18F) {
		proc->opinfo->mode = OPINFO_STATE_2;
		goto goto_judge_ret;
	}

	proc->frame_timer++;
	proc->total_timer++;

	if (gOpClassDemoBanimCtrl[proc->ctrl_index].duration == 0)
		goto goto_judge_ret;

	if (proc->frame_timer > gOpClassDemoBanimCtrl[proc->ctrl_index].duration)
		goto goto_ret_0;

	if (gOpClassDemoBanimCtrl[proc->ctrl_index].duration != 0xFF)
		goto goto_judge_ret;

	if (proc->unk_3E != 0)
		if (EkrMainMini_CheckBlocking(&OpEkrMiniDesc) != false)
			goto goto_ret_0;

	if (proc->unk_3E == 0)
		if (EkrMainMini_CheckDone(&OpEkrMiniDesc) != false)
			ret = 1;

goto_judge_ret:

	if (ret == 0)
		return;

goto_ret_0:

	proc->ctrl_index++;

	if (gOpClassDemoBanimCtrl[proc->ctrl_index].duration == 0)
		return;

	if (gOpClassDemoBanimCtrl[proc->ctrl_index].round_type == 0xFF) {
		EkrMainMini_EndBlock(&OpEkrMiniDesc);
		proc->unk_3E = 0;
	} else if (proc->round_type != gOpClassDemoBanimCtrl[proc->ctrl_index].round_type) {
		OpEkrMiniDesc.round_type = gOpClassDemoBanimCtrl[proc->ctrl_index].round_type;
		EkrMainMini_UpdateAnim(&OpEkrMiniDesc);

		if (gOpClassDemoBanimCtrl[proc->ctrl_index].round_type == 4)
			EkrMainMini_EndBlock(&OpEkrMiniDesc);

		proc->unk_3E = 1;
	}

	proc->round_type = gOpClassDemoBanimCtrl[proc->ctrl_index].round_type;
	proc->frame_timer = 0;
}

void ClassDemoMain_Block(struct ProcClassDemoMain *proc) {}

void ClassDemoMain_OnEnd(struct ProcClassDemoMain *proc)
{
	SetOnHBlankA(NULL);
	EndTalk();
	EndActiveClassReelBgColorProc();
	EndEkrTerrainfx(&OpEkrTerrainDesc);
	EndActiveClassReelSpell();
	EndEkrMainMini(&OpEkrMiniDesc);

	if (proc->procfx)
		Proc_Goto(proc->procfx, 4);

	proc->opinfo->anim_proc = NULL;
}

ProcPtr StartClassAnimDisplay(struct ProcOpInfo *parent, u8 index)
{
	struct ProcClassDemoMain *proc;

	proc = SpawnProc(ProcScr_ClassDemoMain, parent);
	proc->index = index;
	proc->opinfo = parent;
	proc->procfx = NULL;

	return proc;
}

void ClassDemoStatus_Init(struct ProcClassDemoStatus *proc)
{
	int i, j;

	proc->gauge = proc->proc_parent;
	proc->timer = 0;
	proc->unk_42 = 0;
	proc->unk_43 = 250;

	for (i = 0; i < 14; i++) {
		OpClassDemoCharPositions[i].x = 0;
		OpClassDemoCharPositions[i].y = 0;

		if (gClassDemoNames[proc->gauge->index][i] == '\0') {
			proc->ch_pos[i] = 0xFF;
			break;
		}

		for (j = 0; gClassDisplayFont1[j].sprite != NULL; j++) {
			if (gClassDisplayFont1[j].ch == gClassDemoNames[proc->gauge->index][i]) {
				proc->ch_pos[i] = j;
				proc->unk_42 += gClassDisplayFont1[j].width - gClassDisplayFont1[j].x_start;
				break;
			}
		}
	}

	Decompress(Img_ClassDemoFont, OBJ_VRAM0);
	ApplyPalettes(Pal_ClassDemoFont, 0x14, 2);
}

const char Str_OpInfo_Mag[] = TEXT("魔力", "Mag");

void ClassDemoStatus_Loop(struct ProcClassDemoStatus *proc)
{
	u8 unused[] = { 2, 2, 3, 3, 3, 3, 2, 2, 2, 3, 3, 4 };
	int i, x;

	for (i = 0; i < 6; i++) {
		u8 status = proc->gauge->unit_status[i];

		for (x = 0; x < status / 4; x++)
			PutSpriteExt(13, 0x30 + x * 8, 0x10 + i * 0x10, Sprites_OpInfo_0869006C[3], OAM2_PAL(5));

		if (status % 4)
			PutSpriteExt(13, 0x30 + x * 8, 0x10 + i * 0x10, Sprites_OpInfo_0869006C[status % 4 - 1], OAM2_PAL(5));
	}

	x = (0x78 - proc->unk_42) / 2 + proc->unk_43;

	for (i = 0; i < 14 && proc->ch_pos[i] != 0xFF; i++) {
		PutSpriteExt(4, x - gClassDisplayFont1[proc->ch_pos[i]].x_start, 8 - gClassDisplayFont1[proc->ch_pos[i]].c,
			gClassDisplayFont1[proc->ch_pos[i]].sprite, OAM2_PAL(5));
		PutSpriteExt(4, x - gClassDisplayFont1[proc->ch_pos[i]].x_start - 2, 6 - gClassDisplayFont1[proc->ch_pos[i]].c,
			gClassDisplayFont1[proc->ch_pos[i]].sprite, OAM2_PAL(4));

		x += gClassDisplayFont1[proc->ch_pos[i]].width - gClassDisplayFont1[proc->ch_pos[i]].x_start;
	}

	if (proc->timer < 0xFF)
		proc->timer++;
}

void func_fe6_08095D28(void)
{
}

ProcPtr StartClassDemoStatus(ProcPtr parent)
{
	return SpawnProc(ProcScr_ClassDemoStatus, parent);
}

void SetOpClassDemoStatusPos(struct ProcClassDemoStatus *proc, int pos)
{
	proc->unk_43 = pos;
}

void func_fe6_08095D48(ProcPtr unused)
{
	OpClassDemoCharPositions[0].x = 0x80;
	OpClassDemoCharPositions[0].y = 2;
}

void func_fe6_08095D58(void)
{
}

u16 CONST_DATA Sprite_ClassDemoFont_0[] = {
	1,
	OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(0xD6) + OAM2_LAYER(3),
};

u16 CONST_DATA Sprite_ClassDemoFont_1[] = {
	1,
	OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(0xD7) + OAM2_LAYER(3),
};

u16 CONST_DATA Sprite_ClassDemoFont_2[] = {
	1,
	OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(0xD8) + OAM2_LAYER(3),
};

u16 CONST_DATA Sprite_ClassDemoFont_3[] = {
	1,
	OAM0_SHAPE_16x16, OAM1_SIZE_16x16, OAM2_CHR(0x10D) + OAM2_LAYER(3),
};

u16 CONST_DATA Sprite_ClassDemoFont_4[] = {
	1,
	OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(0xD9) + OAM2_LAYER(3),
};

u16 CONST_DATA Sprite_ClassDemoFont_5[] = {
	2,
	OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(0x106) + OAM2_LAYER(3),
	OAM0_SHAPE_8x8 + OAM0_Y(16), OAM1_SIZE_8x8, OAM2_CHR(0x146) + OAM2_LAYER(3),
};

u16 CONST_DATA Sprite_ClassDemoFont_6[] = {
	2,
	OAM0_SHAPE_16x16, OAM1_SIZE_16x16, OAM2_CHR(0x107) + OAM2_LAYER(3),
	OAM0_SHAPE_16x8 + OAM0_Y(16), OAM1_SIZE_16x8, OAM2_CHR(0x147) + OAM2_LAYER(3),
};

u16 CONST_DATA Sprite_ClassDemoFont_7[] = {
	1,
	OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(0xDA) + OAM2_LAYER(3),
};

u16 CONST_DATA Sprite_ClassDemoFont_8[] = {
	1,
	OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(0xDB) + OAM2_LAYER(3),
};

u16 CONST_DATA Sprite_ClassDemoFont_9[] = {
	2,
	OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(0x109) + OAM2_LAYER(3),
	OAM0_SHAPE_8x8 + OAM0_Y(16), OAM1_SIZE_8x8, OAM2_CHR(0x149) + OAM2_LAYER(3),
};

u16 CONST_DATA Sprite_ClassDemoFont_10[] = {
	1,
	OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(0xDC) + OAM2_LAYER(3),
};

u16 CONST_DATA Sprite_ClassDemoFont_11[] = {
	1,
	OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(0xDD) + OAM2_LAYER(3),
};

u16 CONST_DATA Sprite_ClassDemoFont_12[] = {
	1,
	OAM0_SHAPE_16x16, OAM1_SIZE_16x16, OAM2_CHR(0x10F) + OAM2_LAYER(3),
};

u16 CONST_DATA Sprite_ClassDemoFont_13[] = {
	1,
	OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(0xDE) + OAM2_LAYER(3),
};

u16 CONST_DATA Sprite_ClassDemoFont_14[] = {
	1,
	OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(0xDF) + OAM2_LAYER(3),
};

u16 CONST_DATA Sprite_ClassDemoFont_15[] = {
	2,
	OAM0_SHAPE_16x16, OAM1_SIZE_16x16, OAM2_CHR(0x10A) + OAM2_LAYER(3),
	OAM0_SHAPE_16x8 + OAM0_Y(16), OAM1_SIZE_16x8, OAM2_CHR(0x14A) + OAM2_LAYER(3),
};

u16 CONST_DATA Sprite_ClassDemoFont_16[] = {
	1,
	OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(0x111) + OAM2_LAYER(3),
};

u16 CONST_DATA Sprite_ClassDemoFont_17[] = {
	1,
	OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(0x112) + OAM2_LAYER(3),
};

u16 CONST_DATA Sprite_ClassDemoFont_18[] = {
	1,
	OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(0x113) + OAM2_LAYER(3),
};

u16 CONST_DATA Sprite_ClassDemoFont_19[] = {
	1,
	OAM0_SHAPE_16x16, OAM1_SIZE_16x16, OAM2_CHR(0x114) + OAM2_LAYER(3),
};

u16 CONST_DATA Sprite_ClassDemoFont_20[] = {
	1,
	OAM0_SHAPE_16x16, OAM1_SIZE_16x16, OAM2_CHR(0x116) + OAM2_LAYER(3),
};

u16 CONST_DATA Sprite_ClassDemoFont_21[] = {
	2,
	OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(0x10C) + OAM2_LAYER(3),
	OAM0_SHAPE_8x8 + OAM0_Y(16), OAM1_SIZE_8x8, OAM2_CHR(0x14C) + OAM2_LAYER(3),
};

u16 CONST_DATA Sprite_ClassDemoFont_22[] = {
	1,
	OAM0_SHAPE_16x16, OAM1_SIZE_16x16, OAM2_CHR(0x90) + OAM2_LAYER(3),
};

u16 CONST_DATA Sprite_ClassDemoFont_23[] = {
	1,
	OAM0_SHAPE_16x16, OAM1_SIZE_16x16, OAM2_CHR(0x92) + OAM2_LAYER(3),
};

u16 CONST_DATA Sprite_ClassDemoFont_24[] = {
	1,
	OAM0_SHAPE_16x16, OAM1_SIZE_16x16, OAM2_CHR(0x94) + OAM2_LAYER(3),
};

u16 CONST_DATA Sprite_ClassDemoFont_25[] = {
	1,
	OAM0_SHAPE_16x16, OAM1_SIZE_16x16, OAM2_CHR(0x96) + OAM2_LAYER(3),
};

u16 CONST_DATA Sprite_ClassDemoFont_26[] = {
	2,
	OAM0_SHAPE_16x16, OAM1_SIZE_16x16, OAM2_CHR(0x100) + OAM2_LAYER(3),
	OAM0_SHAPE_16x8 + OAM0_Y(16), OAM1_SIZE_16x8, OAM2_CHR(0x140) + OAM2_LAYER(3),
};

u16 CONST_DATA Sprite_ClassDemoFont_27[] = {
	2,
	OAM0_SHAPE_16x16, OAM1_SIZE_16x16, OAM2_CHR(0x102) + OAM2_LAYER(3),
	OAM0_SHAPE_16x8 + OAM0_Y(16), OAM1_SIZE_16x8, OAM2_CHR(0x142) + OAM2_LAYER(3),
};

u16 CONST_DATA Sprite_ClassDemoFont_28[] = {
	1,
	OAM0_SHAPE_16x16, OAM1_SIZE_16x16, OAM2_CHR(0x118) + OAM2_LAYER(3),
};

u16 CONST_DATA Sprite_ClassDemoFont_29[] = {
	1,
	OAM0_SHAPE_16x16, OAM1_SIZE_16x16, OAM2_CHR(0x98) + OAM2_LAYER(3),
};

u16 CONST_DATA Sprite_ClassDemoFont_30[] = {
	1,
	OAM0_SHAPE_16x16, OAM1_SIZE_16x16, OAM2_CHR(0x9A) + OAM2_LAYER(3),
};

u16 CONST_DATA Sprite_ClassDemoFont_31[] = {
	2,
	OAM0_SHAPE_16x16, OAM1_SIZE_16x16, OAM2_CHR(0x104) + OAM2_LAYER(3),
	OAM0_SHAPE_16x8 + OAM0_Y(16), OAM1_SIZE_16x8, OAM2_CHR(0x144) + OAM2_LAYER(3),
};

u16 CONST_DATA Sprite_ClassDemoFont_32[] = {
	1,
	OAM0_SHAPE_16x16, OAM1_SIZE_16x16, OAM2_CHR(0x9C) + OAM2_LAYER(3),
};

u16 CONST_DATA Sprite_ClassDemoFont_33[] = {
	1,
	OAM0_SHAPE_16x16, OAM1_SIZE_16x16, OAM2_CHR(0x9E) + OAM2_LAYER(3),
};

u16 CONST_DATA Sprite_ClassDemoFont_34[] = {
	1,
	OAM0_SHAPE_16x16, OAM1_SIZE_16x16, OAM2_CHR(0xD0) + OAM2_LAYER(3),
};

u16 CONST_DATA Sprite_ClassDemoFont_35[] = {
	1,
	OAM0_SHAPE_16x16, OAM1_SIZE_16x16, OAM2_CHR(0xD2) + OAM2_LAYER(3),
};

u16 CONST_DATA Sprite_ClassDemoFont_36[] = {
	1,
	OAM0_SHAPE_16x16, OAM1_SIZE_16x16, OAM2_CHR(0xD4) + OAM2_LAYER(3),
};

CONST_DATA struct ClassDisplayFont gClassDisplayFont1[] = {
	{ Sprite_ClassDemoFont_0,  'a', 0, 8,  0 },
	{ Sprite_ClassDemoFont_1,  'b', 0, 8,  0 },
	{ Sprite_ClassDemoFont_2,  'c', 0, 7,  0 },
	{ Sprite_ClassDemoFont_3,  'd', 0, 8,  0 },
	{ Sprite_ClassDemoFont_4,  'e', 0, 7,  0 },
	{ Sprite_ClassDemoFont_5,  'f', 1, 7,  0 },
	{ Sprite_ClassDemoFont_6,  'g', 1, 10, 0 },
	{ Sprite_ClassDemoFont_7,  'h', 0, 8,  0 },
	{ Sprite_ClassDemoFont_8,  'i', 0, 7,  0 },
	{ Sprite_ClassDemoFont_9,  'j', 1, 8,  0 },
	{ Sprite_ClassDemoFont_10, 'k', 0, 8, 0  },
	{ Sprite_ClassDemoFont_11, 'l', 0, 6, 0  },
	{ Sprite_ClassDemoFont_12, 'm', 0, 14, 0 },
	{ Sprite_ClassDemoFont_13, 'n', 0, 8, 0  },
	{ Sprite_ClassDemoFont_14, 'o', 0, 8, 0  },
	{ Sprite_ClassDemoFont_15, 'p', 2, 12, 0 },
	{ Sprite_ClassDemoFont_16, 'r', 0, 6, 0  },
	{ Sprite_ClassDemoFont_17, 's', 0, 6, 0  },
	{ Sprite_ClassDemoFont_18, 't', 0, 7, 0  },
	{ Sprite_ClassDemoFont_19, 'u', 0, 9, 0  },
	{ Sprite_ClassDemoFont_20, 'w', 0, 12, 0 },
	{ Sprite_ClassDemoFont_21, 'y', 0, 8, 0  },
	{ Sprite_ClassDemoFont_22, 'A', 1, 15, 0 },
	{ Sprite_ClassDemoFont_23, 'B', 1, 14, 0 },
	{ Sprite_ClassDemoFont_24, 'D', 1, 15, 0 },
	{ Sprite_ClassDemoFont_25, 'F', 1, 15, 0 },
	{ Sprite_ClassDemoFont_26, 'G', 1, 13, 0 },
	{ Sprite_ClassDemoFont_27, 'H', 0, 15, 6 },
	{ Sprite_ClassDemoFont_28, 'K', 1, 15, 0 },
	{ Sprite_ClassDemoFont_29, 'L', 0, 12, 0 },
	{ Sprite_ClassDemoFont_30, 'M', 0, 15, 0 },
	{ Sprite_ClassDemoFont_31, 'N', 0, 14, 6 },
	{ Sprite_ClassDemoFont_32, 'P', 2, 12, 0 },
	{ Sprite_ClassDemoFont_33, 'S', 2, 12, 0 },
	{ Sprite_ClassDemoFont_34, 'T', 1, 14, 0 },
	{ Sprite_ClassDemoFont_35, 'V', 1, 15, 0 },
	{ Sprite_ClassDemoFont_36, 'W', 0, 16, 0 },
	{ NULL, 0, 0, 0, 0 },
};

i8 const * CONST_DATA gClassDemoNames[] = {
	"Lord",
	"Socialknight",
	"Paladin",
	"Archer",
	"Armorknight",
	"Priest",
	"Thief",
	"Mercenary",
	"Fighter",
	"Torubadour",
	"Myrmidon",
	"Mage",
	"Nomad",
	"Bandit",
	"Pirate",
	"Shaman",
	"Bard",
	"Dancer",
	"Pegasusknight",
	"Dragonknight",
	"Warrior",
	"Druid",
	"Valkyuria",
	"Hero",
	"Falconknight",
	"Berserker",
	"Sage",
	"Bishop",
	"Swordmaster",
	"Nomadictrooper",
	"Sniper",
	"General",
	"Dragonmaster",
	"Mamkute",
	"King"
};

u16 CONST_DATA Sprite_08690DD0[] = {
	1,
	OAM0_SHAPE_32x32, OAM1_SIZE_32x32, OAM2_LAYER(3),
};

u16 CONST_DATA Sprite_08690DD8[] = {
	1,
	OAM0_SHAPE_32x32, OAM1_SIZE_32x32, OAM2_CHR(0x4) + OAM2_LAYER(3),
};

u16 CONST_DATA Sprite_08690DE0[] = {
	1,
	OAM0_SHAPE_32x32, OAM1_SIZE_32x32, OAM2_CHR(0x8) + OAM2_LAYER(3),
};

u16 CONST_DATA Sprite_08690DE8[] = {
	1,
	OAM0_SHAPE_32x32, OAM1_SIZE_32x32, OAM2_CHR(0xC) + OAM2_LAYER(3),
};

u16 CONST_DATA Sprite_08690DF0[] = {
	1,
	OAM0_SHAPE_32x32, OAM1_SIZE_32x32, OAM2_CHR(0x10) + OAM2_LAYER(3),
};

u16 CONST_DATA Sprite_08690DF8[] = {
	1,
	OAM0_SHAPE_32x32, OAM1_SIZE_32x32, OAM2_CHR(0x14) + OAM2_LAYER(3),
};

u16 CONST_DATA Sprite_08690E00[] = {
	1,
	OAM0_SHAPE_32x32, OAM1_SIZE_32x32, OAM2_CHR(0x18) + OAM2_LAYER(3),
};

u16 CONST_DATA Sprite_08690E08[] = {
	1,
	OAM0_SHAPE_32x32, OAM1_SIZE_32x32, OAM2_CHR(0x1C) + OAM2_LAYER(3),
};

u16 CONST_DATA Sprite_08690E10[] = {
	1,
	OAM0_SHAPE_32x32, OAM1_SIZE_32x32, OAM2_CHR(0x80) + OAM2_LAYER(3),
};

u16 CONST_DATA Sprite_08690E18[] = {
	1,
	OAM0_SHAPE_32x32, OAM1_SIZE_32x32, OAM2_CHR(0x84) + OAM2_LAYER(3),
};

u16 CONST_DATA Sprite_08690E20[] = {
	1,
	OAM0_SHAPE_32x32, OAM1_SIZE_32x32, OAM2_CHR(0x88) + OAM2_LAYER(3),
};

u16 CONST_DATA Sprite_08690E28[] = {
	1,
	OAM0_SHAPE_32x32, OAM1_SIZE_32x32, OAM2_CHR(0x8C) + OAM2_LAYER(3),
};

CONST_DATA u16 * CONST_DATA Sprites_ClassDemo_Unused[] = {
	Sprite_08690DD0, Sprite_08690DD8, Sprite_08690DE0, Sprite_08690DE8,
	Sprite_08690DF0, Sprite_08690DF8, Sprite_08690E00, Sprite_08690E08,
	Sprite_08690E10, Sprite_08690E18, Sprite_08690E20, Sprite_08690E28,
};
