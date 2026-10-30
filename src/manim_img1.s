    .section .rodata

    .global SpriteAnim_ManimStatGain
SpriteAnim_ManimStatGain: @ 082A75FC
    .incbin "fe6-base.gba", 0x2A75FC, (0x2A79D4 - 0x2A75FC)

    .incbin "fe6-base.gba", 0x2A79D4, (0x2A7CBC - 0x2A79D4)

    .global SpriteAnim_ManimLevelUpText
SpriteAnim_ManimLevelUpText: @ 082A7CBC
    .incbin "fe6-base.gba", 0x2A7CBC, (0x2A8448 - 0x2A7CBC) @ length: 078C

    .global SpriteAnim_ManimTorch
SpriteAnim_ManimTorch: @ 082A8448
    .incbin "fe6-base.gba", 0x2A8448, (0x2A84A4 - 0x2A8448) @ length: 005C

    .global SpriteAnim_ManimUnlock
SpriteAnim_ManimUnlock: @ 082A84A4
    .incbin "fe6-base.gba", 0x2A84A4, (0x2A9190 - 0x2A84A4) @ length: 0CEC

    .global SpriteAnim_ManimPoison
SpriteAnim_ManimPoison: @ 082A9190
    .incbin "fe6-base.gba", 0x2A9190, (0x2A9228 - 0x2A9190) @ length: 0098

    .global SpriteAnim_ManimRubble
SpriteAnim_ManimRubble: @ 082A9228
    .incbin "fe6-base.gba", 0x2A9228, (0x2AA324 - 0x2A9228) @ length: 10FC

    .global SpriteAnim_MuFogBump
SpriteAnim_MuFogBump: @ 082AA324
    .incbin "fe6-base.gba", 0x2AA324, (0x2AA380 - 0x2AA324) @ length: 0644
