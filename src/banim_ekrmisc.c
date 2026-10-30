#include "prelude.h"
#include "hardware.h"
#include "msg.h"
#include "item.h"
#include "eventinfo.h"
#include "banim.h"
#include "banim_data.h"

void EfxClearScreenFx(void)
{
	gDispIo.disp_ct.mode = 0;
	SetDispEnable(1, 1, 1, 1, 1);
	gDispIo.disp_ct.obj_mapping = 0;

	SetBgOffset(BG_0, 0, 0);
	SetBgOffset(BG_1, 0, 0);
	SetBgOffset(BG_2, 0, 0);

	SetBgChrOffset(BG_0, 0);
	SetBgChrOffset(BG_1, 0);
	SetBgChrOffset(BG_2, 0);
	SetBgChrOffset(BG_3, 0x8000);

	SetBgTilemapOffset(BG_0, 0x6000);
	SetBgTilemapOffset(BG_1, 0x6800);
	SetBgTilemapOffset(BG_2, 0x7000);
	SetBgTilemapOffset(BG_3, 0x7800);

	gDispIo.bg0_ct.priority = 0;
	gDispIo.bg1_ct.priority = 1;
	gDispIo.bg2_ct.priority = 2;
	gDispIo.bg3_ct.priority = 3;

	CpuFastFill16(0, gBg0Tm, 0x800);
	CpuFastFill16(0, gBg1Tm, 0x800);
	CpuFastFill16(0, gBg2Tm, 0x800);

	if (GetBattleAnimArenaFlag() == false)
		EkrDispUp_PutTerrainfx();
	else
		CpuFastFill16(0, gBg2Tm, 0x800);

	EfxPrepareScreenFx();
	EnablePalSync();

	EnableBgSync(BG0_SYNC_BIT);
	EnableBgSync(BG1_SYNC_BIT);
	EnableBgSync(BG2_SYNC_BIT);
	SetBlendNone();
}

void EkrDispUp_PutTerrainfx(void)
{
	struct EkrTerrainfxDesc *desc = &gEkrTerrainfxDesc;
	const struct BattleAnimTerrain *terrain1 = &gBanimTerrainTable[gBanimFloorfx[0]];
	const struct BattleAnimTerrain *terrain2 = &gBanimTerrainTable[gBanimFloorfx[1]];

	switch (gEkrDistanceType) {
	case EKR_DISTANCE_CLOSE:
	case EKR_DISTANCE_PROMOTION:
		gpBanimTerrainfxBufs[0] = &gBanimTerrainfxBufObj[0];
		gpBanimTerrainfxBufs[1] = &gBanimTerrainfxBufObj[0x1000];
		break;

	case EKR_DISTANCE_FAR:
	case EKR_DISTANCE_FARFAR:
	case EKR_DISTANCE_MONOCOMBAT:
		gpBanimTerrainfxBufs[0] = &gBanimTerrainfxBufObj[0x800];
		gpBanimTerrainfxBufs[1] = &gBanimTerrainfxBufObj[0x1800];
		break;

	}

	switch (gPlaySt.weather) {
		// dummy, both cases do the same thing
	case WEATHER_SNOW:
		gpBanimTerrainPalBufs[0] = terrain1->palette;
		gpBanimTerrainPalBufs[1] = terrain2->palette;
		break;

	default:
		gpBanimTerrainPalBufs[0] = terrain1->palette;
		gpBanimTerrainPalBufs[1] = terrain2->palette;
		break;
	}

	gpBanimTerrainTsaBufs[0] = TsaConfs_BanimTmA[gEkrDistanceType * 2];
	gpBanimTerrainTsaBufs[1] = TsaConfs_BanimTmA[gEkrDistanceType * 2 + 1];

	desc->terrain_l = gBanimFloorfx[0];
	desc->pal_l = 4;
	desc->chr_l = 640;
	desc->terrain_r = gBanimFloorfx[1];
	desc->pal_r = 5;
	desc->chr_r = 640;
	desc->distance = gEkrDistanceType;
	desc->bg_index = BG_2;
	desc->vram_offset = 0;
	desc->img_buf = &gBanimTerrainfxBufObj[0];
	desc->unk_10 = gEkrSnowWeather;
	NewEkrTerrainfx(desc);
}

void EfxPrepareScreenFx(void)
{
	const char *str;

	ApplyPalette(Pal_Text, 2);
	ApplyPalette(Pal_Text, 3);
	InitTextFont(&gBanimFont, (u8 *)BG_VRAM + BGCHR_BANIM_PNAME_L * CHR_SIZE, BGCHR_BANIM_PNAME_L, BGPAL_EFX_2);
	SetTextDrawNoClear();
	LZ77UnCompVram(Img_081125E0, (u8 *)BG_VRAM + BGCHR_BANIM_080 * CHR_SIZE);

	/* left unit name */
	if (gBanimValid[POS_L] == false)
		str = gNopStr;
	else
		str = DecodeMsg(gpEkrBattleUnitLeft->unit.pinfo->msg_name);

	InitText(&gBanimText[0], 6);
	Text_SetCursor(&gBanimText[0], GetStringTextCenteredPos(0x30, str));
	LZ77UnCompVram(Img_EfxLeftNameBox, (u8 *)BG_VRAM + BGCHR_BANIM_PNAME_L * CHR_SIZE);
	Text_DrawString(&gBanimText[0], str);

	/* left unit item */
	if (gBanimValid[POS_L] == false)
		str = gNopStr;
	else
		str = GetItemName(gpEkrBattleUnitLeft->weapon_before);

	InitText(&gBanimText[2], 7);
	Text_SetCursor(&gBanimText[2], GetStringTextCenteredPos(0x38, str));
	LZ77UnCompVram(Img_EfxLeftItemBox, (u8 *)BG_VRAM + BGCHR_BANIM_INAME_L * CHR_SIZE);
	Text_DrawString(&gBanimText[2], str);

	/* right unit name */
	if (gBanimValid[POS_R] == false)
		str = gNopStr;
	else
		str = DecodeMsg(gpEkrBattleUnitRight->unit.pinfo->msg_name);

	InitText(&gBanimText[3], 6);
	Text_SetCursor(&gBanimText[3], GetStringTextCenteredPos(0x30, str));
	LZ77UnCompVram(Img_EfxRightNameBox, (u8 *)BG_VRAM + BGCHR_BANIM_PNAME_R * CHR_SIZE);
	Text_DrawString(&gBanimText[3], str);

	/* right unit item */
	if (gBanimValid[POS_R] == false)
		str = gNopStr;
	else
		str = GetItemName(gpEkrBattleUnitRight->weapon_before);

	InitText(&gBanimText[1], 7);
	Text_SetCursor(&gBanimText[1], GetStringTextCenteredPos(0x38, str));
	LZ77UnCompVram(Img_EfxRightItemBox, (u8 *)BG_VRAM + BGCHR_BANIM_INAME_R * CHR_SIZE);
	Text_DrawString(&gBanimText[1], str);

	TmFill(gBg0Tm, BGCHR_BANIM_PNAME_L - 1);
	EfxTmCpyBG(Tsa_08112C84, gBg0Tm + 0x1E, 2, 20, -1, -1);
	FillBGSafelyRect(gBg0Tm + 0x1F, 1, 20, 2, 128);
	FillBGSafelyRect(gBg0Tm + 0x1E, 1, 20, 3, 128);
	EnableBgSync(BG0_SYNC_BIT);

	CpuFastCopy(&Pal_08112CD4[gBanimFactionPal[POS_L] * 0x10], PAL_BG(BGPAL_EFX_2), 0x20);
	CpuFastCopy(&Pal_08112CD4[gBanimFactionPal[POS_R] * 0x10], PAL_BG(BGPAL_EFX_3), 0x20);
	EnablePalSync();

	gEkrBg0QuakeVec.x = 0;
	gEkrBg0QuakeVec.y = 0;
	SetBgOffset(BG_0, 0, 0);
}

int GetBanimInitPosReal(void)
{
	int quote1, quote2;

	switch (gEkrDistanceType) {
	case EKR_DISTANCE_FAR:
		return gEkrInitialHitSide;

	case EKR_DISTANCE_CLOSE:
	case EKR_DISTANCE_MONOCOMBAT:
	case EKR_DISTANCE_PROMOTION:
		return POS_R;

	case EKR_DISTANCE_FARFAR:
	default:
		break;
	}

	quote2 = false;
	quote1 = false;

	if (gEkrDebugModeMaybe == 0) {
		quote1 = CheckBattleTalk(gEkrPids[POS_L], gEkrPids[POS_R]);
		quote2 = CheckBattleTalk(gEkrPids[POS_R], gEkrPids[POS_L]);
	}

	if (quote1 == true)
		return POS_L;
	else if (quote2 == true)
		return POS_R;
	else
		return gEkrInitialHitSide;
}

void EkrEfxStatusClear(void)
{
	gEkrHpBarCount = 0;
	gEfxSpellAnimExists = 0;
	gUnk_Banim_02017728 = 0;
	gEkrDeadEventExist = 0;
	gEfxQuakeExist = 0;
	gEfxHitQuakeExist = 0;
	gEfxFarAttackExist = 0;
	gEfxBgSemaphore = 0;
	gEfxHpBarResireFlag = 0;
	gUnk_Banim_0201774C = 0;
	gEfxTeonoState = 0;
	gEfxTerrainLayerLow = 0;
	SetEkrBg2QuakeVec(0, 0);
	gUnk_Banim_0201775C[0] = 0;
	gUnk_Banim_0201775C[1] = 0;
	gEfxSpecalEffectExist[0] = 0;
	gEfxSpecalEffectExist[1] = 0;
	gEkrHitNow[0] = 0;
	gEkrHitNow[1] = 0;
	gpProcEfxStatusUnits[0] = NULL;
	gpProcEfxStatusUnits[1] = NULL;
	gpProcEfxSpellCast = NULL;
	gpProcEfxHpBarColorChange = NULL;

	LZ77UnCompVram(gUnk_08113D70, OBJ_VRAM0 + 0x2000);
	gEfxMagicChk_N = 0;
}
