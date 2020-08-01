
#pragma once

#include "gba/gba.h"
#include "types.h"

#include "proc.h"
#include "text.h"
#include "menu.h"
#include "map-select.h"

extern struct AiDecision gAiDecision;

extern struct Glyph const* CONST_DATA TextGlyphs_Special[];
extern struct Glyph const* CONST_DATA TextGlyphs_System[];
extern struct Glyph const* CONST_DATA TextGlyphs_Talk[];
extern u16 CONST_DATA Pal_SystemText[];
extern u16 CONST_DATA Pal_TalkText[];
extern u16 CONST_DATA Pal_GreenTextColors[];
extern u8 const Img_FactionMiniCard[];
extern u16 const Pal_FactionMiniCard[];
extern u8 const Img_TalkBubble[];
extern u16 const Pal_TalkBubble[];
extern u8 const Img_TalkBubbleOpeningA[];
extern u8 const Img_TalkBubbleOpeningB[];
extern u8 const Img_TalkBubbleOpeningC[];
extern u8 const Img_TalkBubbleOpeningD[];
extern u8 const Img_TalkBubbleOpeningE[];
extern u8 const Tsa_Unk_08101974[];
extern u8 const Tsa_Unk_08101A2C[];
extern u8 const Img_SystemObjects[];
extern u16 const Pal_SystemObjects[];
extern u8 const Img_LimitViewSquares[];
extern u16 const Pal_LimitViewBlue[];
extern u16 const Pal_LimitViewRed[];
extern u16 const Pal_LimitViewGreen[];
extern u8 const Img_PhaseChangeSquares[];
extern u8 const Img_PhaseChangePlayer[];
extern u16 const Pal_PhaseChangePlayer[];
extern u8 const Img_PhaseChangeEnemy[];
extern u16 const Pal_PhaseChangeEnemy[];
extern u8 const Img_PhaseChangeOther[];
extern u16 const Pal_PhaseChangeOther[];
extern u16 const Anim_08102450[];
extern u16 const Anim_GasTrapVertical[];
extern u16 const Anim_GasTrapHorizontal[];
extern u8 const Img_GasTrapVertical[];
extern u8 const Img_GasTrapHorizontal[];
extern u16 const Pal_GasTrap[];
extern u8 const Img_ArrowTrap[];
extern u16 const Pal_ArrowTrap[];
extern u16 const Anim_ArrowTrap[];
extern u8 const Img_FireTrap[];
extern u16 const Pal_FireTrap[];
extern u16 const Anim_FireTrap[];
extern u8 const Img_PikeTrap[];
extern u16 const Anim_PikeTrap[];
extern u16 const Pal_PikeTrap[];
extern u8 const Img_ChapterIntroFog[];
extern u16 const Pal_ChapterIntroFog[];
extern u8 const Img_ChapterIntroMotif[];
extern u16 const Pal_ChapterIntroMotif[];
extern u8 const Tm_ChapterIntroMotif[];
extern u8 const Img_GameOverText[];
extern u16 const Pal_GameOverText[];
extern u16 const Pal_Unk_0830D95C[];
extern u8 const Tsa_Unk_0830D97C[];
extern u8 const Tsa_Unk_081022FC[];
extern u16 const Pal_UnitSprites[];
extern u16 const Pal_UnitSpritesPurple[];
extern u8 const Img_SandstormParticles[];
extern u8 const Img_SnowstormParticles[];
extern u8 const Img_FlamesParticles[];
extern u16 const Pal_FlamesParticles[];
extern u8 const Img_CloudWeather[];
extern u16 const Pal_CloudWeather[];
extern u8 const Img_MovePath[];
extern u16 const Pal_MovePath[];
extern struct ProcScr CONST_DATA ProcScr_Unk_085C8080[];
extern struct FaceInfo CONST_DATA FaceInfoTable[];
extern struct ProcScr CONST_DATA ProcScr_OpeningSequence[];
extern struct ProcScr CONST_DATA ProcScr_Unk_08691480[];
extern struct ProcScr CONST_DATA ProcScr_Unk_0868C304[];
extern struct ProcScr CONST_DATA ProcScr_AiPhase[];
extern struct ProcScr CONST_DATA ProcScr_StatusDecayDisplay[];
extern struct ProcScr CONST_DATA ProcScr_TerrainHealDisplay[];
extern struct ProcScr CONST_DATA ProcScr_PoisonDamageDisplay[];
extern struct ProcScr CONST_DATA ProcScr_BerserkPhase[];
extern struct ProcScr CONST_DATA ProcScr_Unk_0868B010[];
extern struct ProcScr CONST_DATA ProcScr_Unk_0868AE04[];
extern struct ProcScr CONST_DATA ProcScr_Unk_085C83C8[];
extern struct ProcScr CONST_DATA ProcScr_TrapDamageDisplay[];
extern struct ProcScr CONST_DATA ProcScr_Mu[];
extern struct MenuInfo CONST_DATA MenuInfo_085C7474;
extern struct MenuInfo CONST_DATA MenuInfo_085C73E4;
extern struct MenuInfo CONST_DATA MenuInfo_085C742C;
extern struct MenuInfo CONST_DATA MenuInfo_085C7450;
extern struct MenuInfo CONST_DATA MenuInfo_085C7408;
extern struct MenuInfo CONST_DATA MenuInfo_085C7648;
extern struct MenuInfo CONST_DATA MenuInfo_085C73C0;
extern struct MenuInfo CONST_DATA MenuInfo_UnitMenu;
extern struct MenuInfo CONST_DATA MenuInfo_085C74E0;
extern struct MenuInfo CONST_DATA MenuInfo_085C7504;
extern struct MenuInfo CONST_DATA MenuInfo_085C75B8;
extern struct MenuInfo CONST_DATA MenuInfo_085C75DC;
extern struct MenuInfo CONST_DATA MenuInfo_085C7594;
extern struct MenuInfo CONST_DATA MenuInfo_085C754C;
extern struct MenuInfo CONST_DATA MenuInfo_085C7528;
extern struct MenuInfo CONST_DATA MenuInfo_085C7570;
extern struct MenuInfo CONST_DATA MenuInfo_085C74BC;
extern struct MenuInfo CONST_DATA MenuInfo_085C7498;
extern struct MenuInfo CONST_DATA MenuInfo_085C7624;
extern struct MapSelectInfo CONST_DATA MapSelectInfo_085C786C;
extern struct MapSelectInfo CONST_DATA MapSelectInfo_085C784C;
extern struct MapSelectInfo CONST_DATA MapSelectInfo_085C782C;
extern struct MapSelectInfo CONST_DATA MapSelectInfo_085C780C;
extern struct MapSelectInfo CONST_DATA MapSelectInfo_085C77EC;
extern struct MapSelectInfo CONST_DATA MapSelectInfo_085C77CC;
extern struct MapSelectInfo CONST_DATA MapSelectInfo_085C76EC;
extern struct MapSelectInfo CONST_DATA MapSelectInfo_085C778C;
extern struct MapSelectInfo CONST_DATA MapSelectInfo_085C776C;
extern struct MapSelectInfo CONST_DATA MapSelectInfo_Steal;
extern struct MapSelectInfo CONST_DATA MapSelectInfo_085C772C;
extern struct MapSelectInfo CONST_DATA MapSelectInfo_085C770C;
extern struct MapSelectInfo CONST_DATA MapSelectInfo_Repair;
extern struct MapSelectInfo CONST_DATA MapSelectInfo_Heal;
extern struct MapSelectInfo CONST_DATA MapSelectInfo_Restore;
extern struct MapSelectInfo CONST_DATA MapSelectInfo_Barrier;
extern struct MapSelectInfo CONST_DATA MapSelectInfo_AttackStaff;

extern s8 CONST_DATA TerrainHealAmountTable[];
extern Bool CONST_DATA TerrainHealsStatusTable[];
extern char const* CONST_DATA TerrainNameStringTable[];

extern u8 CONST_DATA JList_BowEffectiveness[];
extern u8 CONST_DATA JList_HeroCrestPromotes[];
extern u8 CONST_DATA JList_KnightCrestPromotes[];
extern u8 CONST_DATA JList_OrionBoltPromotes[];
extern u8 CONST_DATA JList_ElysianWhipPromotes[];
extern u8 CONST_DATA JList_GuidingRingPromotes[];

extern s8 CONST_DATA MoveTable_Unk_0860C912[];

extern struct ChapterInfo CONST_DATA ChapterInfoTable[];
extern struct TrialLoadInfo* CONST_DATA gTrialLoadInfo;

extern void const* CONST_DATA ChapterAssets[];

extern u8 const Img_Background_082D80B0[];
extern u8 const Tsa_Background_082DAC8C[];
extern u16 const Pal_Background_082DB140[];
extern u8 const Img_Background_082E28F8[];
extern u8 const Tsa_Background_082E35DC[];
extern u16 const Pal_Background_082E3A90[];
extern u8 const Img_Background_082E3B10[];
extern u8 const Tsa_Background_082E3EC0[];
extern u16 const Pal_Background_082E4374[];
extern u8 const Img_Background_082E4650[];
extern u8 const Tsa_Background_082E6EB4[];
extern u16 const Pal_Background_082E7368[];
extern u8 const Img_Background_082E73E8[];
extern u8 const Tsa_Background_082EADF0[];
extern u16 const Pal_Background_082EB2A4[];
extern u8 const Img_Background_082EB324[];
extern u8 const Tsa_Background_082EDB7C[];
extern u16 const Pal_Background_082EE030[];
extern u8 const Img_Background_082EE0B0[];
extern u8 const Tsa_Background_082EF97C[];
extern u16 const Pal_Background_082EFE30[];
extern u16 const Pal_Background_082EFEB0[];
extern u8 const Img_Background_082EFF30[];
extern u8 const Tsa_Background_082F1490[];
extern u16 const Pal_Background_082F1944[];
extern u8 const Img_Background_082F19C4[];
extern u8 const Tsa_Background_082F3494[];
extern u16 const Pal_Background_082F3948[];
extern u8 const Img_Background_082F39C8[];
extern u8 const Tsa_Background_082F62E0[];
extern u16 const Pal_Background_082F6794[];
extern u16 const Pal_Background_082F6814[];
extern u8 const Img_Background_082F6894[];
extern u8 const Tsa_Background_082F85E8[];
extern u16 const Pal_Background_082F8A9C[];
extern u8 const Img_Background_082F8B1C[];
extern u8 const Tsa_Background_082FBE6C[];
extern u16 const Pal_Background_082FC320[];
extern u8 const Img_Background_082FC3A0[];
extern u8 const Tsa_Background_082FECE0[];
extern u16 const Pal_Background_082FF194[];
extern u8 const Img_Background_082FF214[];
extern u8 const Tsa_Background_08301244[];
extern u16 const Pal_Background_083016F8[];
extern u16 const Pal_Background_08301778[];
extern u16 const Pal_Background_083017F8[];
extern u8 const Img_Background_08301878[];
extern u8 const Tsa_Background_0830491C[];
extern u16 const Pal_Background_08304DD0[];
extern u8 const Img_Background_08304E50[];
extern u8 const Tsa_Background_08306F24[];
extern u16 const Pal_Background_083073D8[];
