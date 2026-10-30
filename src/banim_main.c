#include "prelude.h"
#include "oam.h"
#include "banim.h"
#include "banim_data.h"

void BattleAIS_ExecCommands(void)
{
	int type;
	u32 i;
	struct Anim *anim, *anim1, *anim2;

	for (i = 0; i < 4; i++) {
		anim = gAnims[i];
		if (!anim)
			continue;

		type = anim->flags2 & ANIM_BIT2_CMD_MASK;
		if (type == 0)	
			continue;

		if (type & ANIM_BIT2_COMMAND) {
			while (1) {
				if (anim->cqSize == 0)
					goto L_cmd_loop_end;

				switch (anim->cq[anim->cqSize - 1]) {
				case 0:
					break;

				case BAS_CMD(0x01):
					if (gAnimC01Blocking == 1)
						anim->scrCur = anim->script;
					else if (!(anim->flags3 & ANIM_BIT3_C01_BLOCK_END_PREBATTLE))
						anim->scrCur++;
					else if (anim->flags3 & ANIM_BIT3_C01_BLOCK_END_INBATTLE) {
						if (CheckEkrHitDone() == true) {
							anim->flags3 &= ~(ANIM_BIT3_C02_BLOCK_END | ANIM_BIT3_C01_BLOCK_END_PREBATTLE | ANIM_BIT3_C01_BLOCK_END_INBATTLE);
							anim->scrCur++;
						}
					}
					break;

				/**
				 * C02: blocking
				 */
				case BAS_CMD(0x02):
					if (anim->flags3 & ANIM_BIT3_C02_BLOCK_END) {
						anim->flags3 &= ~ANIM_BIT3_C02_BLOCK_END;
						anim->scrCur++;
					}
					break;

				/**
				 * C03: EfxSpecalEffect
				 */
				case BAS_CMD(0x03):
					if (!(anim->flags3 & ANIM_BIT3_BLOCKING)) {
						anim->flags3 |= ANIM_BIT3_BLOCKING;

						if (GetAnimLayer(anim) == 0)
							NewEfxSpecalEffect(anim);
					}

					if (anim->flags3 & ANIM_BIT3_BLOCKEND) {
						anim->flags3 &= ~ANIM_BIT3_BLOCKING;
						anim->flags3 &= ~ANIM_BIT3_BLOCKEND;
						anim->scrCur++;
					}
					break;

				/**
				 * C04: Start normal hitted effect if not MISS
				 */
				case BAS_CMD(0x04):
					if (!(anim->flags3 & ANIM_BIT3_BLOCKING)) {
						anim->flags3 |= ANIM_BIT3_BLOCKING;
						anim->flags3 |= ANIM_BIT3_BLOCKEND;
					}

					if (anim->flags3 & ANIM_BIT3_BLOCKEND) {
						anim->flags3 &= ~ANIM_BIT3_BLOCKING;
						anim->flags3 &= ~ANIM_BIT3_BLOCKEND;
						anim->scrCur++;
						anim->flags3 |= ANIM_BIT3_C02_BLOCK_END | ANIM_BIT3_C01_BLOCK_END_INBATTLE;

						anim1 = GetAnimAnotherSide(anim);
						type = GetAnimRoundTypeAnotherSide(anim);

						if (CheckRoundMiss(type) == true && anim1) {
							anim1->flags3 |= ANIM_BIT3_C02_BLOCK_END | ANIM_BIT3_C01_BLOCK_END_INBATTLE;

							if (GetAnimLayer(anim) == 0)
								StartBattleAnimHitEffectsDefault(anim1, CheckRoundMiss(type));
						}
					}
					break;

				/**
				 * C05: efx magic
				 */
				case BAS_CMD(0x05):
					if (!(anim->flags3 & ANIM_BIT3_BLOCKING)) {
						anim->flags3 |= ANIM_BIT3_BLOCKING;
						anim->flags3 |= ANIM_BIT3_BLOCKEND;
					}

					if (anim->flags3 & ANIM_BIT3_BLOCKEND) {
						anim->flags3 &= ~ANIM_BIT3_BLOCKING;
						anim->flags3 &= ~ANIM_BIT3_BLOCKEND;
						anim->scrCur++;
						anim->flags3 |= ANIM_BIT3_C02_BLOCK_END | ANIM_BIT3_C01_BLOCK_END_INBATTLE;

						if (GetAnimLayer(anim) == 0)
							StartSpellAnimation(anim);
					}
					break;

				/**
				 * C06
				 * Attacker anim trigger opponent's next round anim.
				 * 
				 * Usually, atttacker anim is written in:
				 * C06
				 * C0D
				 * in end.
				 */
				case BAS_CMD(0x06):
					anim1 = GetAnimAnotherSide(anim);
					if (anim1) {
						type = GetAnimNextRoundTypeAnotherSide(anim1);
						if (type != ANIM_ROUND_INVALID)
							anim1->flags3 |= ANIM_BIT3_NEXT_ROUND_START;
					}
					break;

				/**
				 * C08
				 * Critical hit
				 */
				case BAS_CMD(0x08):
				case BAS_CMD(0x09):
				case BAS_CMD(0x0A):
				case BAS_CMD(0x0B):
				case BAS_CMD(0x0C):
					if (GetAnimLayer(anim) == 0) {
						anim1 = GetAnimAnotherSide(anim);
						type = GetAnimRoundTypeAnotherSide(anim);

						if (CheckRoundMiss(type) == false) {
							if (GetEfxHpChangeType(anim1) != EFX_HPT_NOT_CHANGE)
								NewEfxCriricalEffect(anim1);
						}

						if (anim1) {
							anim1->flags3 |= ANIM_BIT3_C02_BLOCK_END | ANIM_BIT3_C01_BLOCK_END_INBATTLE;
							type = GetAnimRoundTypeAnotherSide(anim);
							StartBattleAnimHitEffectsDefault(anim1, CheckRoundMiss(type));
						}
					}
					break;

				/**
				 * C0D
				 * Attack start its own next round anim.
				 */
				case BAS_CMD(0x0D):
					type = GetAnimNextRoundType(anim);
					anim1 = gAnims[GetAnimPosition(anim) * 2];
					anim2 = gAnims[GetAnimPosition(anim) * 2 + 1];

					switch (anim->currentRoundType) {
					case ANIM_ROUND_HIT_CLOSE:
					case ANIM_ROUND_CRIT_CLOSE:
					case ANIM_ROUND_NONCRIT_FAR:
					case ANIM_ROUND_CRIT_FAR:
					case ANIM_ROUND_MISS_CLOSE:
						if (type != -1) {
							int frame_idx, scr_offset;
							struct BanimScrFrame *scr_start;

							anim1->nextRoundId++;
							anim2->nextRoundId++;
							LoadAnimFrame(anim1, type);
							LoadAnimFrame(anim2, type);
							anim1->flags3 |= ANIM_BIT3_C01_BLOCK_END_PREBATTLE;
							anim2->flags3 |= ANIM_BIT3_C01_BLOCK_END_PREBATTLE;

							type = BanimDefaultStandingTypes[gEkrDistanceType];
							frame_idx = BanimDefaultModeConfig[type * 4 + 0];

							if (GetAnimPosition(anim) == POS_L)
								scr_offset = gpBanimModesLeft[frame_idx];
							else
								scr_offset = gpBanimModesRight[frame_idx];

							/* We need to make sure that the first script is the frame? */
							scr_start = (void *)(scr_offset + gBanimScrs + GetAnimPosition(anim) * BAS_SCR_MAX_SIZE);

							anim1->imgSheet = scr_start->img;
#if !NONMATCHING
							{
								register const void *tmp_ptr asm("r4");
								register int tmp_val asm("r1");

								anim1->sprData = tmp_ptr = (tmp_ptr = anim1->sprDataPool) + (tmp_val = scr_start->oam_offset);
								anim2->sprData = tmp_ptr = anim2->sprDataPool + BAS_OAM_REF_MAX_SIZE;
							}
#else
							anim1->sprData = anim1->sprDataPool + scr_start->oam_offset;
							anim2->sprData = anim2->sprDataPool + BAS_OAM_REF_MAX_SIZE;
#endif

							if (gBanimBallistaImages[GetAnimPosition(anim)] == NULL) {
								if (gpImgSheet[GetAnimPosition(anim1)] != anim1->imgSheet) {
									NewEkrChienCHR(anim1);
									gpImgSheet[GetAnimPosition(anim1)] = anim1->imgSheet;
								}
							}
							goto L_cmd_loop_end;
						}
						/* fall through */

					case ANIM_ROUND_TAKING_MISS_CLOSE:
					case ANIM_ROUND_TAKING_MISS_FAR:
						type = BanimDefaultStandingTypes[gEkrDistanceType];
						/* fall through */

					case ANIM_ROUND_TAKING_HIT_CLOSE:
					case ANIM_ROUND_STANDING:
					case ANIM_ROUND_TAKING_HIT_FAR:
						LoadAnimFrame(anim1, type);
						LoadAnimFrame(anim2, type);
						goto L_cmd_loop_end;
						break;
					}
					break;

				/**
				 * C13
				 * efxTeonoOBJ?
				 */
				case BAS_CMD(0x13):
					if (!(anim->flags3 & ANIM_BIT3_BLOCKING))
						anim->flags3 |= ANIM_BIT3_BLOCKING;
					else if (gEfxTeonoState == 1) {
						gEfxTeonoState = 0;
						anim->flags3 &= ~ANIM_BIT3_BLOCKING;
						anim->scrCur++;
					}
					break;

				/**
				 * C14
				 * Heavy vibration of screen
				 */
				case BAS_CMD(0x14):
					if (GetAnimLayer(anim) == 0)
						NewEfxQuake(3);
					break;

				/**
				 * C15
				 * Slight vibration of screen
				 */
				case BAS_CMD(0x15):
					if (GetAnimLayer(anim) == 0)
						NewEfxQuake(0);
					break;

				/**
				 * C18
				 * Start of dodge toward the foreground
				 */
				case BAS_CMD(0x18):
					if (anim->flags3 & ANIM_BIT3_C02_BLOCK_END) {
						anim->flags3 &= ~ANIM_BIT3_C02_BLOCK_END;
						anim->scrCur++;
						anim->oam2 = (0xF3FF & anim->oam2) | OAM2_LAYER(0x1);
						anim->priority = 0x8C;
						BasSort();
					}
					break;

				/**
				 * C1A
				 * Normal hit effect
				 */
				case BAS_CMD(0x1A):
					if (GetAnimLayer(anim) == 0) {
						anim1 = GetAnimAnotherSide(anim);
						if (anim1) {
							anim1->flags3 |= ANIM_BIT3_C02_BLOCK_END | ANIM_BIT3_C01_BLOCK_END_INBATTLE;
							type = GetAnimRoundTypeAnotherSide(anim);
							StartBattleAnimHitEffectsDefault(anim1, CheckRoundMiss(type));
						}

						if (GetEfxHpChangeType(anim1) != EFX_HPT_NOT_CHANGE)
							NewEfxNormalEffect(anim);
					}
					break;

				case BAS_CMD(0x26):
					if (GetAnimLayer(anim) == 0)
						NewEfxYushaSpinShield(anim, 0x0);
					break;

				case BAS_CMD(0x27):
					if (GetAnimLayer(anim) == 0)
						NewEfxYushaSpinShield(anim, 0x1);
					break;

				case BAS_CMD(0x2C):
					if (GetAnimLayer(anim) == 0)
						NewEfxHurtmutEff00(anim);
					break;

				case BAS_CMD(0x2D):
					GetAnimLayer(anim);
					break;

				/**
				 * C2E
				 * Sage's normal magic
				 */
				case BAS_CMD(0x2E):
					if (GetAnimLayer(anim) == 0)
						NewEfxMagfcast(anim, 0);
					break;

				/**
				 * C2F
				 * Sage's critical magic
				 */
				case BAS_CMD(0x2F):
					if (GetAnimLayer(anim) == 0)
						NewEfxMagfcast(anim, 1);
					break;

				/**
				 * C30
				 * Dirt kicking (as from dashing forward) animation
				 */
				case BAS_CMD(0x30):
					if (GetAnimLayer(anim) == 0)
						NewEfxSunakemuri(anim, 0);
					break;

				/**
				 * C31
				 * Dirt wave (as from horse kicking forward from ground) animation
				 */
				case BAS_CMD(0x31):
					if (GetAnimLayer(anim) == 0)
						NewEfxSunakemuri(anim, 1);
					break;

				/**
				 * C32
				 * Medium sized dirt wave moving backward animation
				 */
				case BAS_CMD(0x32):
					if (GetAnimLayer(anim) == 0)
						NewEfxSunakemuri(anim, 2);
					break;

				case BAS_CMD(0x39):
					if (!(anim->flags3 & ANIM_BIT3_BLOCKING)) {
						anim->flags3 |= ANIM_BIT3_BLOCKING;
						if (GetAnimLayer(anim) == 0)
							NewEfxKingPika(anim);
					} else {
						if (anim->flags3 & ANIM_BIT3_BLOCKEND) {
							anim->flags3 &= ~ANIM_BIT3_BLOCKING;
							anim->flags3 &= ~ANIM_BIT3_BLOCKEND;
							anim->scrCur++;
						}
					}
					break;

				/**
				 * C3A
				 * Idunn anim
				 */
				case BAS_CMD(0x3A):
					anim->xPosition += 0x20;

					if (GetAnimLayer(anim) == 0)
						gEkrXPosReal[GetAnimPosition(anim)] += 0x20;
					break;

				/**
				 * C3B
				 * Idunn anim
				 */
				case BAS_CMD(0x3B):
					anim->xPosition -= 0x20;

					if (GetAnimLayer(anim) == 0)
						gEkrXPosReal[GetAnimPosition(anim)] -= 0x20;
					break;

				case BAS_CMD(0x44):
					if (GetAnimLayer(anim) == 0)
						NewEfxSongFE6(anim);
					break;

				case BAS_CMD(0x45):
					if (GetAnimLayer(anim) == 0)
						NewEfxDanceOBJ(anim);
					break;

				case 25:
				case 27:
				case 28:
				case 29:
				case 30:
				case 31:
				case 32:
				case 33:
				case 34:
				case 35:
				case 36:
				case 37:
				case 40:
				case 41:
				case 42:
				case 43:
				case 51:
				case 52:
				case 53:
				case 54:
				case 55:
				case 56:
				case 60:
				case 61:
				case 62:
				case 63:
				case 64:
				case 65:
				case 66:
				case 67:
				case 70:
					EfxPlaySEwithCmdCtrl(anim, anim->cq[anim->cqSize - 1]);
					break;

				case BAS_CMD(0x47):
					NewEfxMantBatabata(anim);
					break;

				case BAS_CMD(0x48):
				case BAS_CMD(0x49):
				case BAS_CMD(0x4A):
					EfxPlaySEwithCmdCtrl(anim, anim->cq[anim->cqSize - 1]);
					break;

				default:
					break;
				}

				anim->cqSize--;
			}

		L_cmd_loop_end:
			anim->flags2 &= ~(ANIM_BIT2_COMMAND |
							  ANIM_BIT2_0800 |
							  ANIM_BIT2_0080 |
							  ANIM_BIT2_0040 |
							  ANIM_BIT2_0020 |
							  ANIM_BIT2_0010 |
							  ANIM_BIT2_0008 |
							  ANIM_BIT2_0004 |
							  ANIM_BIT2_0002 |
							  ANIM_BIT2_0001);
		}

		if (type & ANIM_BIT2_FRAME) {
			if (GetAnimLayer(anim) == 0) {
				if (gBanimBallistaImages[GetAnimPosition(anim)] == NULL)
					if (!(anim->flags3 & ANIM_BIT3_4000))
						if (gpImgSheet[GetAnimPosition(anim)] != anim->imgSheet) {
							SyncBanimImage(anim);
							gpImgSheet[GetAnimPosition(anim)] = anim->imgSheet;
						}
			}

			anim->flags2 &= ~(ANIM_BIT2_FRAME |
							  ANIM_BIT2_0800 |
							  ANIM_BIT2_0080 |
							  ANIM_BIT2_0040 |
							  ANIM_BIT2_0020 |
							  ANIM_BIT2_0010 |
							  ANIM_BIT2_0008 |
							  ANIM_BIT2_0004 |
							  ANIM_BIT2_0002 |
							  ANIM_BIT2_0001);
		}

		if ((type & ANIM_BIT2_STOP) || (gAnimC01Blocking == true)) {
			if (anim->flags3 & ANIM_BIT3_NEXT_ROUND_START) {
				type = GetAnimNextRoundType(anim);
				if (type != ANIM_ROUND_INVALID) {
					anim1 = gAnims[GetAnimPosition(anim) * 2];
					LoadAnimFrame(anim1, type);
					anim1->flags3 &= ~ANIM_BIT3_NEXT_ROUND_START;
					anim1->flags3 |= ANIM_BIT3_C01_BLOCK_END_PREBATTLE;

					anim2 = gAnims[GetAnimPosition(anim) * 2 + 1];
					LoadAnimFrame(anim2, type);
					anim2->flags3 &= ~ANIM_BIT3_NEXT_ROUND_START;
					anim2->flags3 |= ANIM_BIT3_C01_BLOCK_END_PREBATTLE;

					anim1->nextRoundId++;
					anim2->nextRoundId++;
				} else {
					anim1 = gAnims[GetAnimPosition(anim) * 2 + 0];
					anim1->flags3 &= ~ANIM_BIT3_NEXT_ROUND_START;

					anim2 = gAnims[GetAnimPosition(anim) * 2 + 1];
					anim2->flags3 &= ~ANIM_BIT3_NEXT_ROUND_START;
				}
			} else if (anim->flags3 & ANIM_BIT3_NEW_ROUND_START) {
				type = GetAnimNextRoundType(anim);
				if (type != ANIM_ROUND_INVALID) {
					anim1 = gAnims[GetAnimPosition(anim) * 2];
					LoadAnimFrame(anim1, type);
					anim1->flags3 &= ~ANIM_BIT3_NEW_ROUND_START;
					anim1->flags3 |= ANIM_BIT3_C01_BLOCK_END_PREBATTLE;

					anim2 = gAnims[GetAnimPosition(anim) * 2 + 1];
					LoadAnimFrame(anim2, type);
					anim2->flags3 &= ~ANIM_BIT3_NEW_ROUND_START;
					anim2->flags3 |= ANIM_BIT3_C01_BLOCK_END_PREBATTLE;

					anim1->nextRoundId++;
					anim2->nextRoundId++;
				}
			} else if (GetAnimLayer(anim) == 0) {
				type = GetBattleAnimRoundType(anim->nextRoundId * 2 + GetAnimPosition(anim));
				if (type == ANIM_ROUND_INVALID)
					gBanimDoneFlag[GetAnimPosition(anim)] = 1;
			}
		}
	}
}
