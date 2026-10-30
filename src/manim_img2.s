    .section .rodata

    .global Img_ManimMissTag
Img_ManimMissTag: @ 082DB1C0
    .incbin "fe6-base.gba", 0x2DB1C0, (0x2DB2B0 - 0x2DB1C0) @ length: 00F0

    .global Ap_ManimMissTag
Ap_ManimMissTag: @ 082DB2B0
    .incbin "fe6-base.gba", 0x2DB2B0, (0x2DB418 - 0x2DB2B0) @ length: 0168

    .global Img_ManimNoDamageTag
Img_ManimNoDamageTag: @ 082DB418
    .incbin "fe6-base.gba", 0x2DB418, (0x2DB55C - 0x2DB418) @ length: 0144

    .global Ap_ManimNoDamageTag
Ap_ManimNoDamageTag: @ 082DB55C
    .incbin "fe6-base.gba", 0x2DB55C, (0x2DB6E8 - 0x2DB55C) @ length: 018C

    .global Pal_ManimLevelUpStatGainCycling
Pal_ManimLevelUpStatGainCycling: @ 082DB6E8
    .incbin "fe6-base.gba", 0x2DB6E8, (0x2DB8B0 - 0x2DB6E8) @ length: 01C8

    .global Img_ManimLevelUpText
Img_ManimLevelUpText: @ 082DB8B0
    .incbin "fe6-base.gba", 0x2DB8B0, (0x2DBAC4 - 0x2DB8B0) @ length: 0214

    .global Pal_ManimLevelUp
Pal_ManimLevelUp: @ 082DBAC4
    .incbin "fe6-base.gba", 0x2DBAC4, (0x2DBB24 - 0x2DBAC4) @ length: 0060

    .global Img_ManimLevelUpStatGain
Img_ManimLevelUpStatGain: @ 082DBB24
    .incbin "fe6-base.gba", 0x2DBB24, (0x2DBDB0 - 0x2DBB24) @ length: 028C

    .global Img_ManimLevelUpStatGainDigits
Img_ManimLevelUpStatGainDigits: @ 082DBDB0
    .incbin "fe6-base.gba", 0x2DBDB0, (0x2DC5B0 - 0x2DBDB0) @ length: 0800

    .global Tsa_ManimExpBar
Tsa_ManimExpBar: @ 082DC5B0
    .incbin "fe6-base.gba", 0x2DC5B0, (0x2DC618 - 0x2DC5B0) @ length: 0068

    .global Img_ManimInfoWindowDigits
Img_ManimInfoWindowDigits: @ 082DC618
    .incbin "fe6-base.gba", 0x2DC618, (0x2DC6DC - 0x2DC618) @ length: 00C4

    .global Img_ManimInfoFrame
Img_ManimInfoFrame: @ 082DC6DC
    .incbin "fe6-base.gba", 0x2DC6DC, (0x2DC840 - 0x2DC6DC) @ length: 0164

    .global Pal_ManimInfoFrameBlue
Pal_ManimInfoFrameBlue: @ 082DC840
    .incbin "fe6-base.gba", 0x2DC840, (0x2DC860 - 0x2DC840) @ length: 0020

    .global Pal_ManimInfoFrameRed
Pal_ManimInfoFrameRed: @ 082DC860
    .incbin "fe6-base.gba", 0x2DC860, (0x2DC880 - 0x2DC860) @ length: 0020

    .global Pal_ManimInfoFrameGreen
Pal_ManimInfoFrameGreen: @ 082DC880
    .incbin "fe6-base.gba", 0x2DC880, (0x2DC8A0 - 0x2DC880) @ length: 0020

    .global Pal_ManimInfoFramePurple
Pal_ManimInfoFramePurple: @ 082DC8A0
    .incbin "fe6-base.gba", 0x2DC8A0, (0x2DC8C0 - 0x2DC8A0) @ length: 0020

    .global Tsa_ManimInfoFrameSingle
Tsa_ManimInfoFrameSingle: @ 082DC8C0
    .incbin "fe6-base.gba", 0x2DC8C0, (0x2DC8EC - 0x2DC8C0) @ length: 002C

    .global Tsa_ManimInfoFrameLeft
Tsa_ManimInfoFrameLeft: @ 082DC8EC
    .incbin "fe6-base.gba", 0x2DC8EC, (0x2DC918 - 0x2DC8EC) @ length: 002C

    .global Tsa_ManimInfoFrameRight
Tsa_ManimInfoFrameRight: @ 082DC918
    .incbin "fe6-base.gba", 0x2DC918, (0x2DC944 - 0x2DC918) @ length: 002C

    .global Tsa_ShopWindows
Tsa_ShopWindows: @ 082DC944
    .incbin "fe6-base.gba", 0x2DC944, (0x2DCA2C - 0x2DC944) @ length: 00E8

    .global Img_ShopGoldBox
Img_ShopGoldBox: @ 082DCA2C
    .incbin "fe6-base.gba", 0x2DCA2C, (0x2DCAE4 - 0x2DCA2C) @ length: 00B8

    .global Img_ManimRubble
Img_ManimRubble: @ 082DCAE4
    .incbin "data/mapanim/Img_ManimRubble.4bpp.lz"

    .global Pal_ManimRubble
Pal_ManimRubble: @ 082DCD70
    .incbin "data/mapanim/Img_ManimRubble.gbapal", 0, 0x20

    .global Img_MuFogBump
Img_MuFogBump: @ 082DCD90
    @ pal: OBPAL_SYSTEM_OBJECTS+1
    .incbin "data/mapanim/Img_MuFogBump.4bpp.lz"

    .global Img_ManimPoison
Img_ManimPoison: @ 082DCEF4
    .incbin "data/mapanim/Img_ManimPoison.4bpp.lz"

    .global Pal_ManimPoison
Pal_ManimPoison: @ 082DD248
    .incbin "data/mapanim/Img_ManimPoison.gbapal", 0, 0x20

    .global Img_ManimWarp
Img_ManimWarp: @ 082DD268
    .incbin "data/mapanim/Img_ManimWarp.4bpp.lz"

    .global Pal_ManimWarp
Pal_ManimWarp: @ 082DD4C8
    .incbin "fe6-base.gba", 0x2DD4C8, (0x2DD4E8 - 0x2DD4C8) @ length: 0020

    .global TsaRef_ManimWarp
TsaRef_ManimWarp: @ 082DD4E8
    .incbin "fe6-base.gba", 0x2DD4E8, (0x2DD7E8 - 0x2DD4E8) @ length: 0300

    .global Img_ManimStar
Img_ManimStar: @ 082DD7E8
    .incbin "data/mapanim/Img_ManimStar.4bpp.lz"

    .global Pal_ManimStar
Pal_ManimStar: @ 082DD808
    .incbin "fe6-base.gba", 0x2DD808, (0x2DD848 - 0x2DD808) @ length: 0040

    .global Img_ManimAntitoxin
Img_ManimAntitoxin: @ 082DD848
    .incbin "fe6-base.gba", 0x2DD848, (0x2DE354 - 0x2DD848) @ length: 0B0C

    .global Tsa_ManimAntitoxin
Tsa_ManimAntitoxin: @ 082DE354
    .incbin "fe6-base.gba", 0x2DE354, (0x2DE954 - 0x2DE354) @ length: 0600

    .global Pal_ManimPureWater
Pal_ManimPureWater: @ 082DE954
    .incbin "fe6-base.gba", 0x2DE954, (0x2DE974 - 0x2DE954) @ length: 0020

    .global Pal_ManimAntitoxin
Pal_ManimAntitoxin: @ 082DE974
    .incbin "fe6-base.gba", 0x2DE974, (0x2DE994 - 0x2DE974) @ length: 0020

    .global Img_ManimHeal
Img_ManimHeal: @ 082DE994
    .incbin "fe6-base.gba", 0x2DE994, (0x2DEB08 - 0x2DE994) @ length: 0174

    .global Img_ManimMend
Img_ManimMend: @ 082DEB08
    .incbin "fe6-base.gba", 0x2DEB08, (0x2DED00 - 0x2DEB08) @ length: 01F8

    .global Img_ManimRecover
Img_ManimRecover: @ 082DED00
    .incbin "fe6-base.gba", 0x2DED00, (0x2DEFBC - 0x2DED00) @ length: 02BC

    .global Pal_ManimHeal
Pal_ManimHeal: @ 082DEFBC
    .incbin "fe6-base.gba", 0x2DEFBC, (0x2DEFFC - 0x2DEFBC) @ length: 0040

    .global Img_ManimFortify
Img_ManimFortify: @ 082DEFFC
    .incbin "fe6-base.gba", 0x2DEFFC, (0x2DF3D8 - 0x2DEFFC) @ length: 03DC

    .global Img_ManimTorch
Img_ManimTorch: @ 082DF3D8
    .incbin "fe6-base.gba", 0x2DF3D8, (0x2DF690 - 0x2DF3D8) @ length: 02B8

    .global Pal_ManimTorch
Pal_ManimTorch: @ 082DF690
    .incbin "fe6-base.gba", 0x2DF690, (0x2DF6B0 - 0x2DF690) @ length: 0020

    .global Img_ManimUnlockObj
Img_ManimUnlockObj: @ 082DF6B0
    .incbin "fe6-base.gba", 0x2DF6B0, (0x2DF704 - 0x2DF6B0) @ length: 0054

    .global Pal_ManimUnlockObj
Pal_ManimUnlockObj: @ 082DF704
    .incbin "fe6-base.gba", 0x2DF704, (0x2DF724 - 0x2DF704) @ length: 0020

    .global Img_ManimUnlockBg
Img_ManimUnlockBg: @ 082DF724
    .incbin "fe6-base.gba", 0x2DF724, (0x2DF824 - 0x2DF724) @ length: 0100

    .global Pal_ManimUnlockBg
Pal_ManimUnlockBg: @ 082DF824
    .incbin "fe6-base.gba", 0x2DF824, (0x2DF844 - 0x2DF824) @ length: 0020

    .global Tsa_ManimUnlockBg
Tsa_ManimUnlockBg: @ 082DF844
    .incbin "fe6-base.gba", 0x2DF844, (0x2DF868 - 0x2DF844) @ length: 0024

    .global Tsa_ManimRestore
Tsa_ManimRestore: @ 082DF868
    .incbin "fe6-base.gba", 0x2DF868, (0x2DFAD4 - 0x2DF868) @ length: 026C

    .global Img_ManimHammerne
Img_ManimHammerne: @ 082DFAD4
    .incbin "fe6-base.gba", 0x2DFAD4, (0x2E07A8 - 0x2DFAD4) @ length: 0CD4

    .global Tsa_ManimHammerne
Tsa_ManimHammerne: @ 082E07A8
    .incbin "fe6-base.gba", 0x2E07A8, (0x2E0A14 - 0x2E07A8) @ length: 026C

    .global SpriteAnim_ManimSleep
SpriteAnim_ManimSleep: @ 082E0A14
    .incbin "fe6-base.gba", 0x2E0A14, (0x2E0E14 - 0x2E0A14) @ length: 0400

    .global Img_ManimBerserk
Img_ManimBerserk: @ 082E0E14
    .incbin "fe6-base.gba", 0x2E0E14, (0x2E10EC - 0x2E0E14) @ length: 02D8

    .global Pal_ManimBerserk
Pal_ManimBerserk: @ 082E10EC
    .incbin "fe6-base.gba", 0x2E10EC, (0x2E110C - 0x2E10EC) @ length: 0020

    .global SpriteAnim_ManimBerserk
SpriteAnim_ManimBerserk: @ 082E110C
    .incbin "fe6-base.gba", 0x2E110C, (0x2E11DC - 0x2E110C) @ length: 00D0

    .global Img_ManimSilenceObj
Img_ManimSilenceObj: @ 082E11DC
    .incbin "fe6-base.gba", 0x2E11DC, (0x2E161C - 0x2E11DC) @ length: 0440

    .global Img_ManimSilenceBg
Img_ManimSilenceBg: @ 082E161C
    .incbin "fe6-base.gba", 0x2E161C, (0x2E172C - 0x2E161C) @ length: 0110

    .global Pal_ManimSilence
Pal_ManimSilence: @ 082E172C
    .incbin "fe6-base.gba", 0x2E172C, (0x2E174C - 0x2E172C) @ length: 0020

    .global SpriteAnim_ManimSilence
SpriteAnim_ManimSilence: @ 082E174C
    .incbin "fe6-base.gba", 0x2E174C, (0x2E1884 - 0x2E174C) @ length: 0138

    .global Img_ManimBarrier
Img_ManimBarrier: @ 082E1884
    .incbin "fe6-base.gba", 0x2E1884, (0x2E2440 - 0x2E1884) @ length: 0BBC

    .global Tsa_ManimBarrier
Tsa_ManimBarrier: @ 082E2440
    .incbin "fe6-base.gba", 0x2E2440, (0x2E25D4 - 0x2E2440) @ length: 0194

    .global Img_ManimHpBar
Img_ManimHpBar: @ 082E25D4
    .incbin "fe6-base.gba", 0x2E25D4, (0x2E278C - 0x2E25D4) @ length: 01B8

    .global Pal_ManimWindowHpBar
Pal_ManimWindowHpBar: @ 082E278C
    .incbin "fe6-base.gba", 0x2E278C, (0x2E28F8 - 0x2E278C) @ length: 016C
