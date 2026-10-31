#include "prelude.h"
#include "proc.h"
#include "oam.h"
#include "datamove.h"
#include "hardware.h"
#include "unit.h"
#include "battle.h"
#include "banim_sprite.h"
#include "banim.h"
#include "banim_data.h"
#include "constants/banims.h"
#include "constants/jids.h"

EWRAM_OVERLAY(banim) u8 gBanimImgSheetBuf_Left[BAS_IMG_MAX_SIZE * 2] = {};
EWRAM_OVERLAY(banim) u8 gBanimImgSheetBuf_Right[BAS_IMG_MAX_SIZE * 2] = {};
EWRAM_OVERLAY(banim) u16 gBanimPaletteLeft[0x50] = {};
EWRAM_OVERLAY(banim) u16 gBanimPaletteRight[0x50] = {};
EWRAM_OVERLAY(banim) u8 gBanimOamBufs[2 * BAS_OAM_MAX_SIZE] = {};
EWRAM_OVERLAY(banim) u8 gBanimScrs[2 * BAS_SCR_MAX_SIZE] = {};
EWRAM_OVERLAY(banim) u8 gBanimTerrainfxBufObj[0x2000] = {};
EWRAM_OVERLAY(banim) u16 gEfxPal[0x200] = {};
EWRAM_OVERLAY(banim) u16 Buf_EkrGaugeNumImg[0x200] = {};
EWRAM_OVERLAY(banim) u16 gEkrGaugeHpNumImgBuf[0x40] = {};
EWRAM_OVERLAY(banim) u8 gEkrGaugeBuf[0x800] = {};
EWRAM_OVERLAY(banim) struct Font gBanimFont = {};
EWRAM_OVERLAY(banim) struct Text gBanimText[20] = {};
EWRAM_OVERLAY(banim) u16 gEkrGaugeDecoder[18] = {};
EWRAM_OVERLAY(banim) u32 gEkrBattleEndFlag = 0;
EWRAM_OVERLAY(banim) u32 gEkrHpBarCount = 0;
EWRAM_OVERLAY(banim) u32 gEfxSpellAnimExists = 0;
EWRAM_OVERLAY(banim) u32 gUnk_Banim_02017728 = 0;
EWRAM_OVERLAY(banim) u32 gEkrDeadExist = 0;
EWRAM_OVERLAY(banim) u32 gEkrDeadEventExist = 0;
EWRAM_OVERLAY(banim) u32 gEfxQuakeExist = 0;
EWRAM_OVERLAY(banim) u32 gEfxHitQuakeExist = 0;
EWRAM_OVERLAY(banim) u32 gEkrInitPosReal = 0;
EWRAM_OVERLAY(banim) u32 gEfxFarAttackExist = 0;
EWRAM_OVERLAY(banim) u32 gEfxBgSemaphore = 0;
EWRAM_OVERLAY(banim) u32 gEfxHpBarResireFlag = 0;
EWRAM_OVERLAY(banim) u32 gUnk_Banim_0201774C = 0;
EWRAM_OVERLAY(banim) u32 gEfxTeonoState = 0;
EWRAM_OVERLAY(banim) u32 gEfxTerrainLayerLow = 0;
EWRAM_OVERLAY(banim) struct Vec2i gEkrBg2QuakeVec = {};
EWRAM_OVERLAY(banim) i16 gUnk_Banim_0201775C[2] = {};
EWRAM_OVERLAY(banim) i16 gEfxSpecalEffectExist[2] = {};
EWRAM_OVERLAY(banim) struct ProcEfxStatusUnit *gpProcEfxStatusUnits[2] = {};
EWRAM_OVERLAY(banim) struct ProcEfxWeaponIcon *gpProcEfxWeaponIcon = NULL;
EWRAM_OVERLAY(banim) struct ProcEfxSpellCast *gpProcEfxSpellCast = NULL;
EWRAM_OVERLAY(banim) struct ProcEfxHpBarColorChange *gpProcEfxHpBarColorChange = NULL;
EWRAM_OVERLAY(banim) i16 gEkrHitNow[2] = {};
EWRAM_OVERLAY(banim) u8 gSpellAnimBgfx[0x1D00] = {};
EWRAM_OVERLAY(banim) u16 gEkrBarfxBuf[0x300 / 2] = {};
EWRAM_OVERLAY(banim) u16 gEkrTsaBuffer[0x1000 / 2] = {};
EWRAM_OVERLAY(banim) u8 gBuf_Banim[0x2000] = {};
EWRAM_OVERLAY(banim) u16 gPal_Banim[0xA0] = {};
EWRAM_OVERLAY(banim) u16 gTmA_Banim[0xB58 / sizeof(u16)] = {};
EWRAM_OVERLAY(banim) u16 gTmB_Banim[0xB58 / sizeof(u16)] = {};
EWRAM_OVERLAY(banim) i8 gEfxSplitedColorBufA[2][0x30] = {};
EWRAM_OVERLAY(banim) i8 gEfxSplitedColorBufB[2][0x30] = {};
EWRAM_OVERLAY(banim) i16 gEfxSplitedColorBufC[2][0x30] = {};
EWRAM_OVERLAY(banim) int gEkrWindowAppearUnexist = 0;
EWRAM_OVERLAY(banim) int gEkrNameWinAppearExist = 0;
EWRAM_OVERLAY(banim) int gProcEkrBaseAppearExist = 0;
EWRAM_OVERLAY(banim) u32 gUnk_Banim_0201E0F8 = 0;
EWRAM_OVERLAY(banim) struct EkrTerrainfxDesc gEkrTerrainfxDesc = {};
EWRAM_OVERLAY(banim) u32 gBanimDoneFlag[2] = {};
EWRAM_OVERLAY(banim) u32 gEkrBgPosition = 0;
EWRAM_OVERLAY(banim) u32 gUnk_Banim_0201E130[2] = {};
EWRAM_OVERLAY(banim) ProcPtr gpProcEfxAnimeDrv = NULL;
EWRAM_OVERLAY(banim) const void *gpImgSheet[2] = {};

CONST_DATA AnimScr AnimScr_DefaultAnim[] = {
	ANIMSCR_FRAME(1, NULL, BAS_OAM_REF_MAX_SIZE),
	ANIMSCR_BLOCKED
};

CONST_DATA u16 *TsaConfs_BanimTmA[] = {
	TsaConf_BanimTmA_08112380,
	TsaConf_BanimTmA_08112418,
	TsaConf_BanimTmA_081124B0,
	TsaConf_BanimTmA_08112548,
	TsaConf_BanimTmA_081124B0,
	TsaConf_BanimTmA_08112548,
	TsaConf_BanimTmA_081124B0,
	TsaConf_BanimTmA_08112548,
	TsaConf_BanimTmA_08112380,
	TsaConf_BanimTmA_08112418,
};

struct ProcScr CONST_DATA ProcScr_EkrChienCHR[] = {
	PROC_NAME_DEBUG("ekrChienCHR"),
	PROC_REPEAT(EkrChienCHR_Loop),
	PROC_END,
};

void NewEkrChienCHR(struct Anim *anim)
{
	struct ProcEfx *proc;

	proc = SpawnProc(ProcScr_EkrChienCHR, PROC_TREE_3);
	proc->anim = anim;
}

void EkrChienCHR_Loop(struct ProcEfx *proc)
{
	SyncBanimImage(proc->anim);
	Proc_Break(proc);
}

void SyncBanimImage(struct Anim * anim)
{
	void *mmap;

	mmap = OBJ_VRAM0 + OAM2_CHR(anim->oam2) * CHR_SIZE;

	LZ77UnCompWram(anim->imgSheet, anim->imgBuf);
	RegisterDataMove(anim->imgBuf, mmap, 0x2000);
}

void ApplyBanimUniquePalette(u32 *buf, int pos)
{
	u32 i;

	if (gBanimUniquePaletteDisabled[pos] == 0)
		return;

	for (i = 0; i < 8; i++)
		buf[i] = buf[i + 0x20];
}

int GetBanimPalette(int banim_id, int pos)
{
	u32 jid;
	struct BattleUnit *bu;

	if (POS_L == pos)
		bu = gpEkrBattleUnitLeft;
	else
		bu = gpEkrBattleUnitRight;

	jid = bu->unit.jinfo->id;
	switch (jid) {
	case JID_ARCHER:
		return BANIM_0E;
	
	case JID_ARCHER_F:
		return BANIM_0F;
	
	case JID_SNIPER:
		return BANIM_04;
	
	case JID_SNIPER_F:
		return BANIM_05;
	
	default:
		return banim_id;
	}
}

/* https://decomp.me/scratch/8UsuW */
#if NONMATCHING
void UpdateBanimFrame(void)
{
	int bid, bid_pal, chara_pal;
	struct BattleAnim *banim;
	struct BattleAnim *tmp_banim0;
	struct BattleAnim *tmp_banim;

	banim = gBanimTable;
	++banim, --banim;

	gpImgSheet[POS_R] = NULL;
	gpImgSheet[POS_L] = NULL;

	if (gBanimValid[POS_L] == true) {
		bid = gBanimIdx[POS_L];
		bid_pal = gBanimFactionPal[POS_L];
		chara_pal = gBanimUniquePal[POS_L];

		tmp_banim = &gBanimTable[bid];
		LZ77UnCompWram(tmp_banim->script, &gBanimScrs[POS_L * BAS_SCR_MAX_SIZE]);
		gpBanimModesLeft = tmp_banim->modes;

		tmp_banim0 = &gBanimTable[GetBanimPalette(bid, POS_L)];
		LZ77UnCompWram(tmp_banim0->pal, gBanimPaletteLeft);

		if (chara_pal != -1) {
			struct BattleAnimCharaPal *capal = &gBanimCharaPalTable[chara_pal];

			LZ77UnCompWram(capal->pal, gBanimPaletteLeft);
			ApplyBanimUniquePalette((u32 *)gBanimPaletteLeft, POS_L);
		}

		gpEfxUnitPaletteBackup[POS_L] = gBanimPaletteLeft + PAL_OFFSET(bid_pal);
		CpuFastCopy(gBanimPaletteLeft + PAL_OFFSET(bid_pal), PAL_OBJ(OBPAL_EFX_UNIT_L), 0x20);
		CpuFastCopy(gpBanimTriAtkPalettes[POS_L], PAL_OBJ(OBPAL_EFX_UNIT_BAK_L), 0x20);

		EnablePalSync();

		if (bid != BANIM_74)
			LZ77UnCompWram(tmp_banim->oam_l, gBanimOamBufs);
		else
			LZ77UnCompWram(tmp_banim->oam_r, gBanimOamBufs);

		*(u32 *)(gBanimOamBufs + BAS_OAM_REF_MAX_SIZE) = 1;
	}

	if (gBanimValid[POS_R] == true) {
		bid = gBanimIdx[POS_R];
		bid_pal = gBanimFactionPal[POS_R];
		chara_pal = gBanimUniquePal[POS_R];

		LZ77UnCompWram(banim[bid].script, &gBanimScrs[POS_R * BAS_SCR_MAX_SIZE]);
		gpBanimModesRight = banim[bid].modes;
		LZ77UnCompWram(banim[GetBanimPalette(bid, POS_R)].pal, gBanimPaletteRight);
		
		if (chara_pal != -1) {
			struct BattleAnimCharaPal *capal = &gBanimCharaPalTable[chara_pal];

			LZ77UnCompWram(capal->pal, gBanimPaletteRight);
			ApplyBanimUniquePalette((u32 *)gBanimPaletteRight, POS_R);
		}

		gpEfxUnitPaletteBackup[POS_R] = gBanimPaletteRight + PAL_OFFSET(bid_pal);
		CpuFastCopy(gBanimPaletteRight + PAL_OFFSET(bid_pal), PAL_OBJ(OBPAL_EFX_UNIT_R), 0x20);
		CpuFastCopy(gpBanimTriAtkPalettes[POS_R], PAL_OBJ(OBPAL_EFX_UNIT_BAK_R), 0x20);

		EnablePalSync();

		LZ77UnCompWram(banim[bid].oam_r, &gBanimOamBufs[0x5800]);

		*(u32 *)(gBanimOamBufs + 0x5800 + BAS_OAM_REF_MAX_SIZE) = 1;
	}

	/* triangle*/
	if (gpEkrTriangleUnits[0] != NULL) {
		bid = GetBattleAnimationId(gpEkrTriangleUnits[0]->jinfo->banim_info, 0);
		gpBanimTriAtkPalettes[0] = banim[bid].pal;

		chara_pal = (i16)GetBanimUniquePal(gpEkrTriangleUnits[0]);
		if (chara_pal != -1) {
			struct BattleAnimCharaPal *capal = &gBanimCharaPalTable[chara_pal];

			gpBanimTriAtkPalettes[0] = (void *)capal->pal;
		}

		bid = GetBattleAnimationId(gpEkrTriangleUnits[1]->jinfo->banim_info, 0);
		gpBanimTriAtkPalettes[1] = banim[bid].pal;

		chara_pal = (i16)GetBanimUniquePal(gpEkrTriangleUnits[1]);
		if (chara_pal != -1) {
			struct BattleAnimCharaPal *capal = &gBanimCharaPalTable[chara_pal];

			gpBanimTriAtkPalettes[1] = (void *)capal->pal;
		}
	}
}
#else
NAKEDFUNC
void UpdateBanimFrame(void)
{
asm("\
	.syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	ldr r0, .L0804B0F8 @ =gBanimTable\n\
	mov sl, r0\n\
	ldr r1, .L0804B0FC @ =gpImgSheet\n\
	movs r0, #0\n\
	str r0, [r1, #4]\n\
	str r0, [r1]\n\
	ldr r0, .L0804B100 @ =gBanimValid\n\
	ldrh r1, [r0]\n\
	cmp r1, #1\n\
	bne .L0804B140\n\
	ldr r0, .L0804B104 @ =gBanimIdx\n\
	movs r2, #0\n\
	ldrsh r7, [r0, r2]\n\
	ldr r0, .L0804B108 @ =gBanimFactionPal\n\
	movs r2, #0\n\
	ldrsh r1, [r0, r2]\n\
	mov r8, r1\n\
	ldr r0, .L0804B10C @ =gBanimUniquePal\n\
	movs r1, #0\n\
	ldrsh r4, [r0, r1]\n\
	lsls r0, r7, #5\n\
	ldr r2, .L0804B0F8 @ =gBanimTable\n\
	adds r6, r0, r2\n\
	ldr r0, [r6, #0x10]\n\
	ldr r1, .L0804B110 @ =gBanimScrs\n\
	bl LZ77UnCompWram\n\
	ldr r1, .L0804B114 @ =gpBanimModesLeft\n\
	ldr r0, [r6, #0xc]\n\
	str r0, [r1]\n\
	adds r0, r7, #0\n\
	movs r1, #0\n\
	bl GetBanimPalette\n\
	lsls r0, r0, #5\n\
	ldr r1, .L0804B0F8 @ =gBanimTable\n\
	adds r0, r0, r1\n\
	ldr r0, [r0, #0x1c]\n\
	ldr r5, .L0804B118 @ =gBanimPaletteLeft\n\
	adds r1, r5, #0\n\
	bl LZ77UnCompWram\n\
	movs r0, #1\n\
	rsbs r0, r0, #0\n\
	cmp r4, r0\n\
	beq .L0804B0C4\n\
	lsls r0, r4, #4\n\
	ldr r2, .L0804B11C @ =gBanimCharaPalTable\n\
	adds r0, r0, r2\n\
	ldr r0, [r0, #0xc]\n\
	adds r1, r5, #0\n\
	bl LZ77UnCompWram\n\
	adds r0, r5, #0\n\
	movs r1, #0\n\
	bl ApplyBanimUniquePalette\n\
.L0804B0C4:\n\
	ldr r1, .L0804B120 @ =gpEfxUnitPaletteBackup\n\
	mov r2, r8\n\
	lsls r0, r2, #5\n\
	adds r0, r0, r5\n\
	str r0, [r1]\n\
	ldr r4, .L0804B124 @ =gPal+0x2E0\n\
	adds r1, r4, #0\n\
	movs r2, #8\n\
	bl CpuFastSet\n\
	ldr r0, .L0804B128 @ =gpBanimTriAtkPalettes\n\
	ldr r0, [r0]\n\
	adds r4, #0x20\n\
	adds r1, r4, #0\n\
	movs r2, #8\n\
	bl CpuFastSet\n\
	bl EnablePalSync\n\
	cmp r7, #0x74\n\
	beq .L0804B130\n\
	ldr r0, [r6, #0x18]\n\
	ldr r1, .L0804B12C @ =gBanimOamBufs\n\
	bl LZ77UnCompWram\n\
	b .L0804B138\n\
	.align 2, 0\n\
.L0804B0F8: .4byte gBanimTable\n\
.L0804B0FC: .4byte gpImgSheet\n\
.L0804B100: .4byte gBanimValid\n\
.L0804B104: .4byte gBanimIdx\n\
.L0804B108: .4byte gBanimFactionPal\n\
.L0804B10C: .4byte gBanimUniquePal\n\
.L0804B110: .4byte gBanimScrs\n\
.L0804B114: .4byte gpBanimModesLeft\n\
.L0804B118: .4byte gBanimPaletteLeft\n\
.L0804B11C: .4byte gBanimCharaPalTable\n\
.L0804B120: .4byte gpEfxUnitPaletteBackup\n\
.L0804B124: .4byte gPal+0x2E0\n\
.L0804B128: .4byte gpBanimTriAtkPalettes\n\
.L0804B12C: .4byte gBanimOamBufs\n\
.L0804B130:\n\
	ldr r0, [r6, #0x14]\n\
	ldr r1, .L0804B254 @ =gBanimOamBufs\n\
	bl LZ77UnCompWram\n\
.L0804B138:\n\
	ldr r4, .L0804B258 @ =gBanimOamBufs + 0x57F0\n\
	movs r0, #1\n\
	str r0, [r4]\n\
	ldr r0, .L0804B25C @ =gBanimValid\n\
.L0804B140:\n\
	movs r2, #2\n\
	ldrsh r1, [r0, r2]\n\
	mov sb, r1\n\
	cmp r1, #1\n\
	bne .L0804B1DE\n\
	ldr r0, .L0804B260 @ =gBanimIdx\n\
	movs r1, #2\n\
	ldrsh r7, [r0, r1]\n\
	ldr r0, .L0804B264 @ =gBanimFactionPal\n\
	movs r1, #2\n\
	ldrsh r2, [r0, r1]\n\
	mov r8, r2\n\
	ldr r0, .L0804B268 @ =gBanimUniquePal\n\
	movs r2, #2\n\
	ldrsh r4, [r0, r2]\n\
	lsls r0, r7, #5\n\
	mov r1, sl\n\
	adds r6, r0, r1\n\
	ldr r0, [r6, #0x10]\n\
	ldr r1, .L0804B26C @ =gBanimScrs + 0x2A00\n\
	bl LZ77UnCompWram\n\
	ldr r1, .L0804B270 @ =gpBanimModesRight\n\
	ldr r0, [r6, #0xc]\n\
	str r0, [r1]\n\
	adds r0, r7, #0\n\
	movs r1, #1\n\
	bl GetBanimPalette\n\
	lsls r0, r0, #5\n\
	add r0, sl\n\
	ldr r0, [r0, #0x1c]\n\
	ldr r5, .L0804B274 @ =gBanimPaletteRight\n\
	adds r1, r5, #0\n\
	bl LZ77UnCompWram\n\
	movs r0, #1\n\
	rsbs r0, r0, #0\n\
	cmp r4, r0\n\
	beq .L0804B1A6\n\
	lsls r0, r4, #4\n\
	ldr r2, .L0804B278 @ =gBanimCharaPalTable\n\
	adds r0, r0, r2\n\
	ldr r0, [r0, #0xc]\n\
	adds r1, r5, #0\n\
	bl LZ77UnCompWram\n\
	adds r0, r5, #0\n\
	movs r1, #1\n\
	bl ApplyBanimUniquePalette\n\
.L0804B1A6:\n\
	ldr r1, .L0804B27C @ =gpEfxUnitPaletteBackup\n\
	mov r2, r8\n\
	lsls r0, r2, #5\n\
	adds r0, r0, r5\n\
	str r0, [r1, #4]\n\
	ldr r4, .L0804B280 @ =gPal+0x320\n\
	adds r1, r4, #0\n\
	movs r2, #8\n\
	bl CpuFastSet\n\
	ldr r0, .L0804B284 @ =gpBanimTriAtkPalettes\n\
	ldr r0, [r0, #4]\n\
	adds r4, #0x20\n\
	adds r1, r4, #0\n\
	movs r2, #8\n\
	bl CpuFastSet\n\
	bl EnablePalSync\n\
	ldr r0, [r6, #0x14]\n\
	ldr r4, .L0804B288 @ =gBanimOamBufs + 0x5800\n\
	adds r1, r4, #0\n\
	bl LZ77UnCompWram\n\
	ldr r0, .L0804B28C @ =0x000057F0\n\
	adds r4, r4, r0\n\
	mov r1, sb\n\
	str r1, [r4]\n\
.L0804B1DE:\n\
	ldr r6, .L0804B290 @ =gpEkrTriangleUnits\n\
	ldr r0, [r6]\n\
	cmp r0, #0\n\
	beq .L0804B246\n\
	ldr r0, [r0, #4]\n\
	ldr r0, [r0, #0x30]\n\
	movs r1, #0\n\
	bl GetBattleAnimationId\n\
	lsls r0, r0, #0x10\n\
	ldr r5, .L0804B284 @ =gpBanimTriAtkPalettes\n\
	lsrs r0, r0, #0xb\n\
	add r0, sl\n\
	ldr r0, [r0, #0x1c]\n\
	str r0, [r5]\n\
	ldr r0, [r6]\n\
	bl GetBanimUniquePal\n\
	lsls r0, r0, #0x10\n\
	asrs r4, r0, #0x10\n\
	movs r7, #1\n\
	rsbs r7, r7, #0\n\
	cmp r4, r7\n\
	beq .L0804B218\n\
	lsls r0, r4, #4\n\
	ldr r2, .L0804B278 @ =gBanimCharaPalTable\n\
	adds r0, r0, r2\n\
	ldr r0, [r0, #0xc]\n\
	str r0, [r5]\n\
.L0804B218:\n\
	ldr r0, [r6, #4]\n\
	ldr r0, [r0, #4]\n\
	ldr r0, [r0, #0x30]\n\
	movs r1, #0\n\
	bl GetBattleAnimationId\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0xb\n\
	add r0, sl\n\
	ldr r0, [r0, #0x1c]\n\
	str r0, [r5, #4]\n\
	ldr r0, [r6, #4]\n\
	bl GetBanimUniquePal\n\
	lsls r0, r0, #0x10\n\
	asrs r4, r0, #0x10\n\
	cmp r4, r7\n\
	beq .L0804B246\n\
	lsls r0, r4, #4\n\
	ldr r1, .L0804B278 @ =gBanimCharaPalTable\n\
	adds r0, r0, r1\n\
	ldr r0, [r0, #0xc]\n\
	str r0, [r5, #4]\n\
.L0804B246:\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
.L0804B254: .4byte gBanimOamBufs\n\
.L0804B258: .4byte gBanimOamBufs + 0x57F0\n\
.L0804B25C: .4byte gBanimValid\n\
.L0804B260: .4byte gBanimIdx\n\
.L0804B264: .4byte gBanimFactionPal\n\
.L0804B268: .4byte gBanimUniquePal\n\
.L0804B26C: .4byte gBanimScrs + 0x2A00\n\
.L0804B270: .4byte gpBanimModesRight\n\
.L0804B274: .4byte gBanimPaletteRight\n\
.L0804B278: .4byte gBanimCharaPalTable\n\
.L0804B27C: .4byte gpEfxUnitPaletteBackup\n\
.L0804B280: .4byte gPal+0x320\n\
.L0804B284: .4byte gpBanimTriAtkPalettes\n\
.L0804B288: .4byte gBanimOamBufs + 0x5800\n\
.L0804B28C: .4byte 0x000057F0\n\
.L0804B290: .4byte gpEkrTriangleUnits\n\
	.syntax divided\n\
");
}
#endif

void InitMainAnims(void)
{
	struct Anim *anim1, *anim2;

	switch (gEkrDistanceType) {
	case EKR_DISTANCE_CLOSE:
	case EKR_DISTANCE_MONOCOMBAT:
	case EKR_DISTANCE_PROMOTION:
		InitBattleAnimFrame(ANIM_ROUND_TAKING_HIT_CLOSE, ANIM_ROUND_TAKING_HIT_CLOSE);
		break;

	case EKR_DISTANCE_FAR:
		InitBattleAnimFrame(ANIM_ROUND_TAKING_HIT_FAR, ANIM_ROUND_TAKING_HIT_FAR);
		break;

	case EKR_DISTANCE_FARFAR:
		InitBattleAnimFrame(ANIM_ROUND_TAKING_HIT_FAR, ANIM_ROUND_TAKING_HIT_FAR);

		if (GetBanimInitPosReal() == POS_L) {
			anim1 = gAnims[2];
			anim1->xPosition = 0x180;

			anim2 = gAnims[3];
			anim2->xPosition = 0x180;
		} else {
			anim1 = gAnims[0];
			anim1->xPosition = 0x180;

			anim2 = gAnims[1];
			anim2->xPosition = 0x180;
		}
		break;

	default:
		break;
	}

	gEfxHpLutOff[0] = 0;
	gEfxHpLutOff[1] = 0;
}

void InitBattleAnimFrame(int round_type_left, int round_type_right)
{
	gAnims[0] = NULL;
	gAnims[1] = NULL;
	gAnims[2] = NULL;
	gAnims[3] = NULL;

	if (gBanimValid[POS_L] == true)
		InitLeftAnim(round_type_left);

	if (gBanimValid[POS_R] == true)
		InitRightAnim(round_type_right);

	/* Hide the left anim on init promotion */
	if (gEkrDistanceType == EKR_DISTANCE_PROMOTION) {
		gAnims[0]->flags |= BAS_BIT_HIDDEN;
		gAnims[1]->flags |= BAS_BIT_HIDDEN;
	}
}
