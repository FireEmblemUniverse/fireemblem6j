    .include "asm_macros.inc"

    .text

    .global ArmCodeStart
    .type ArmCodeStart, object
ArmCodeStart:

    .syntax unified
    .arm

.LPal: .4byte gPal
.LFadeComponents: .4byte gFadeComponents
.LFadeComponentStep: .4byte gFadeComponentStep

    function ColorFadeTick
ColorFadeTick:
    push {r4-r7}

    @ r7 = start offset of next palette
    @ we start from the end, so palette 0x1F
    mov  r7, 0x20 * 0x1F

.Lpal_loop:
    @ r0 = gFadeComponentStep + pal_idx
    ldr  r0, .LFadeComponentStep
    add  r0, r0, r7, lsr 5

    @ r5 = component step for this palette
    ldsb r5, [r0]

    @ skip if step is 0
    tst  r5, r5
    beq  .Lpal_loop_continue

    ldr  r4, .LFadeComponents

    @ r4 = r4 + 0x30 + r7 * 1.5
    lsr  r0, r7, 1
    add  r0, r0, r0, lsl 1
    add  r0, 0x30
    add  r4, r0

    @ r6 = start offset of next color
    @ starting from the end again
    mov  r6, 0x1E

.Lcolor_loop:
    sub  r4, 3

    @ the clamp compares could be made branchless with some conditional operations
    @ eg: subs r0, 0x20 ; movlo r0, 0 ; cmp r0, 0x20 ; movhs r0, 0x1F

    @ get, update and clamp red component (r0)
    ldrb r0, [r4, 0]
    add  r0, r5
    strb r0, [r4, 0]
    subs r0, 0x20
    bpl  1f
    mov  r0, 0
1:  cmp  r0, 0x20
    blo  1f
    mov  r0, 0x1F
1:

    @ get, update and clamp green component (r1)
    ldrb r1, [r4, 1]
    add  r1, r5
    strb r1, [r4, 1]
    subs r1, 0x20
    bpl  1f
    mov  r1, 0
1:  cmp  r1, 0x20
    blo  1f
    mov  r1, 0x1F
1:

    @ get, update and clamp blue component (r2)
    ldrb r2, [r4, 2]
    add  r2, r5
    strb r2, [r4, 2]
    subs r2, 0x20
    bpl  1f
    mov  r2, 0
1:  cmp  r2, 0x20
    blo  1f
    mov  r2, 0x1F
1:

    @ get combined RGB5 color value
    add  r0, r0, r1, lsl 5
    add  r0, r0, r2, lsl 10

    @ store updated color to pal buffer
    ldr  r1, .LPal
    add  r1, r6
    strh r0, [r1, r7]

    subs r6, 2
    bpl  .Lcolor_loop

.Lpal_loop_continue:
    subs r7, 0x20
    bpl  .Lpal_loop

    @ end
    pop  {r4-r7}
    bx   lr

    endfunction ColorFadeTick

    function ClearOam
ClearOam:
    lsr  r1, 4
    sub  r1, 1

    mov  r2, 0xA0

.Loam_loop:
    str  r2, [r0, 0x00]
    str  r2, [r0, 0x08]
    str  r2, [r0, 0x10]
    str  r2, [r0, 0x18]
    str  r2, [r0, 0x20]
    str  r2, [r0, 0x28]
    str  r2, [r0, 0x30]
    str  r2, [r0, 0x38]
    str  r2, [r0, 0x40]
    str  r2, [r0, 0x48]
    str  r2, [r0, 0x50]
    str  r2, [r0, 0x58]
    str  r2, [r0, 0x60]
    str  r2, [r0, 0x68]
    str  r2, [r0, 0x70]
    str  r2, [r0, 0x78]

    add  r0, 0x80

    subs r1, 1
    bpl  .Loam_loop

    @ end
    bx   lr

    endfunction ClearOam

    function Checksum32
Checksum32:
    push {r4-r7}

    sub  r1, r1, 2
    mov  r2, 0 @ sum
    mov  r3, 0 @ xor

.Lchecksum_loop:
    ldrh r4, [r0]
    add  r2, r2, r4
    eor  r3, r3, r4
    add  r0, r0, 2
    subs r1, r1, 2
    bpl  .Lchecksum_loop

    @ return (sum & 0xFFFF) + (xor << 16)
    mov  r0, 0x10000
    sub  r0, r0, 1
    and  r2, r2, r0
    lsl  r3, r3, 16
    mov  r0, r2
    add  r0, r0, r3

    pop  {r4-r7}
    bx   lr

    endfunction Checksum32

    function TmFillRect
TmFillRect:
    push {r4-r7}

    mov  r4, r0
    sub  r6, r2, 0

.Lfill_row_loop:
    sub  r5, r1, 0

.Lfill_tile_loop:
    strh r3, [r4]
    add  r4, r4, 2
    subs r5, r5, 1
    bpl  .Lfill_tile_loop

    @ next tilemap row
    add  r0, r0, 0x40
    mov  r4, r0
    subs r6, r6, 1
    bpl  .Lfill_row_loop

    pop  {r4-r7}
    bx   lr

    endfunction TmFillRect

    function TmCopyRect
TmCopyRect:
    push {r4-r7}

    @ skip unless width > 0 and height > 0
    tst  r2, r2
    beq  .Lcopy_end
    bmi  .Lcopy_end
    tst  r3, r3
    beq  .Lcopy_end
    bmi  .Lcopy_end

    @ r4 = bytes from the end of one row to the start of the next
    mov  r4, 0x40
    sub  r4, r4, r2, lsl 1

    sub  r6, r3, 1

.Lcopy_row_loop:
    sub  r5, r2, 1

.Lcopy_tile_loop:
    ldrh r7, [r0]
    strh r7, [r1]
    add  r0, r0, 2
    add  r1, r1, 2
    subs r5, r5, 1
    bpl  .Lcopy_tile_loop

    add  r0, r0, r4
    add  r1, r1, r4
    subs r6, r6, 1
    bpl  .Lcopy_row_loop

.Lcopy_end:
    pop  {r4-r7}
    bx   lr

    endfunction TmCopyRect

    function TmApplyTsa
TmApplyTsa:
    push {r4-r7}

    @ TSA header: width - 1, height - 1
    ldrb r3, [r1, 0]
    ldrb r4, [r1, 1]
    add  r1, r1, 2

    @ TSA rows are stored bottom to top, so start at the last row
    lsl  r7, r4, 6
    add  r0, r0, r7

    mov  r6, r4

.Ltsa_row_loop:
    mov  r5, r3

.Ltsa_tile_loop:
    ldrh r7, [r1]
    add  r7, r7, r2
    strh r7, [r0]
    add  r0, r0, 2
    add  r1, r1, 2
    subs r5, r5, 1
    bpl  .Ltsa_tile_loop

    @ back to the start of the previous row
    sub  r0, r0, r3, lsl 1
    sub  r0, r0, 0x42
    subs r6, r6, 1
    bpl  .Ltsa_row_loop

    pop  {r4-r7}
    bx   lr

    endfunction TmApplyTsa

    .align 2, 0
.LOamHiPutIt: .4byte gOamHiPutIt

    function PutOamHi
PutOamHi:
    push {r4-r7}
    ldr  r7, .LOamHiPutIt

    @ r7 = address of the put pointer for the target buffer
.Lput_oam:
    ldr  r5, [r7]

    @ r4 = oam entry count; skip if 0 or negative
    ldrh r4, [r2]
    tst  r4, r4
    beq  .Lput_oam_end
    bmi  .Lput_oam_end
    add  r2, r2, 2

    @ advance the put pointer past the entries we are about to write
    add  r6, r5, r4, lsl 3
    str  r6, [r7]

    @ r0 = (y << 16) | (x & 0xFFFF)
    mov  r7, 0x10000
    sub  r7, r7, 1
    and  r0, r0, r7
    and  r1, r1, r7
    orr  r0, r0, r1, lsl 16

.Lput_oam_loop:
    @ oam0: add y to the 8-bit y coordinate, keep the attribute bits
    ldrh r1, [r2, 0]
    orr  r6, r1, r0, lsr 16
    and  r6, r6, 0xFF00
    add  r7, r1, r0, lsr 16
    and  r7, r7, 0xFF
    orr  r6, r6, r7
    strh r6, [r5, 0]

    @ oam1: add x to the 9-bit x coordinate, keep the attribute bits
    ldrh r1, [r2, 2]
    orr  r6, r1, r0
    and  r6, r6, 0xFE00
    add  r7, r1, r0
    lsl  r7, r7, 23
    lsr  r7, r7, 23
    orr  r6, r6, r7
    strh r6, [r5, 2]

    @ oam2: add the base tile and palette
    ldrh r1, [r2, 4]
    add  r6, r1, r3
    strh r6, [r5, 4]

    add  r2, r2, 6
    add  r5, r5, 8
    subs r4, r4, 1
    bne  .Lput_oam_loop

.Lput_oam_end:
    pop  {r4-r7}
    bx   lr

    endfunction PutOamHi

    .align 2, 0
.LOamLoPutIt: .4byte gOamLoPutIt

    function PutOamLo
PutOamLo:
    push {r4-r7}
    ldr  r7, .LOamLoPutIt
    b    .Lput_oam

    endfunction PutOamLo

    @ multiplying a 2bpp row by 4^n shifts it right by n pixels
.LGlyphShiftMul:
    .4byte 1 << 0,  1 << 2,  1 << 4,  1 << 6
    .4byte 1 << 8,  1 << 10, 1 << 12, 1 << 14

.LGlyphShiftMulRef: .4byte .LGlyphShiftMul

    @ r0 = 2bpp to 4bpp conversion lut, r1 = chr, r2 = glyph rows, r3 = pixel offset
    function DrawGlyph
DrawGlyph:
    push {r4-r10}

    mov  r9, 15 @ row counter
    mov  r10, 0x10000
    sub  r10, r10, 1

.Lglyph_row_loop:
    @ r6:r5 = glyph row shifted right by offset pixels
    ldr  r4, .LGlyphShiftMulRef
    ldr  r5, [r4, r3, lsl 2]
    ldr  r4, [r2]
    umull r5, r6, r4, r5

    @ pixels 0-7 into the first tile
    mov  r7, r5
    and  r7, r7, 0xFF
    ldr  r7, [r0, r7, lsl 1]
    lsr  r8, r5, 8
    and  r8, r8, 0xFF
    ldr  r8, [r0, r8, lsl 1]
    and  r7, r7, r10
    orr  r7, r7, r8, lsl 16
    ldr  r4, [r1, 0x00]
    orr  r4, r4, r7
    str  r4, [r1, 0x00]

    @ pixels 8-15 into the second tile
    lsr  r7, r5, 16
    and  r7, r7, 0xFF
    ldr  r7, [r0, r7, lsl 1]
    lsr  r8, r5, 24
    and  r8, r8, 0xFF
    ldr  r8, [r0, r8, lsl 1]
    and  r7, r7, r10
    orr  r7, r7, r8, lsl 16
    ldr  r4, [r1, 0x40]
    orr  r4, r4, r7
    str  r4, [r1, 0x40]

    @ pixels shifted out of the glyph into the third tile
    mov  r7, r6
    and  r7, r7, 0xFF
    ldr  r7, [r0, r7, lsl 1]
    lsr  r8, r6, 8
    and  r8, r8, 0xFF
    ldr  r8, [r0, r8, lsl 1]
    and  r7, r7, r10
    orr  r7, r7, r8, lsl 16
    ldr  r4, [r1, 0x80]
    orr  r4, r4, r7
    str  r4, [r1, 0x80]

    add  r1, r1, 4
    add  r2, r2, 4
    subs r9, r9, 1
    bpl  .Lglyph_row_loop

    pop  {r4-r10}
    bx   lr

    endfunction DrawGlyph

    @ an 8-row variant of DrawGlyph; it reads the destination with the 16-row tile stride
    function DrawGlyph_Unused
DrawGlyph_Unused:
    push {r4-r10}

    mov  r9, 7 @ row counter
    mov  r10, 0x10000
    sub  r10, r10, 1

.Lglyph8_row_loop:
    ldr  r4, .LGlyphShiftMulRef
    ldr  r5, [r4, r3, lsl 2]
    ldr  r4, [r2]
    umull r5, r6, r4, r5

    mov  r7, r5
    and  r7, r7, 0xFF
    ldr  r7, [r0, r7, lsl 1]
    lsr  r8, r5, 8
    and  r8, r8, 0xFF
    ldr  r8, [r0, r8, lsl 1]
    and  r7, r7, r10
    orr  r7, r7, r8, lsl 16
    ldr  r4, [r1, 0x00]
    orr  r4, r4, r7
    str  r4, [r1, 0x00]

    lsr  r7, r5, 16
    and  r7, r7, 0xFF
    ldr  r7, [r0, r7, lsl 1]
    lsr  r8, r5, 24
    and  r8, r8, 0xFF
    ldr  r8, [r0, r8, lsl 1]
    and  r7, r7, r10
    orr  r7, r7, r8, lsl 16
    ldr  r4, [r1, 0x40]
    orr  r4, r4, r7
    str  r4, [r1, 0x20]

    mov  r7, r6
    and  r7, r7, 0xFF
    ldr  r7, [r0, r7, lsl 1]
    lsr  r8, r6, 8
    and  r8, r8, 0xFF
    ldr  r8, [r0, r8, lsl 1]
    and  r7, r7, r10
    orr  r7, r7, r8, lsl 16
    ldr  r4, [r1, 0x80]
    orr  r4, r4, r7
    str  r4, [r1, 0x40]

    add  r1, r1, 4
    add  r2, r2, 4
    subs r9, r9, 1
    bpl  .Lglyph8_row_loop

    pop  {r4-r10}
    bx   lr

    endfunction DrawGlyph_Unused

    .align 2, 0
.LMsgHuffmanTableRoot: .4byte gMsgHuffmanTableRoot
.LMsgHuffmanTable: .4byte gMsgHuffmanTable

    @ r0 = huffman-encoded src, r1 = dst
    function DecodeString
DecodeString:
    push {r4-r7}

    sub  r3, r3, r3 @ bits left in r2
    ldr  r5, .LMsgHuffmanTable
    ldr  r7, .LMsgHuffmanTableRoot
    ldr  r7, [r7]

.Ldecode_char_loop:
    mov  r4, r7

.Ldecode_bit_loop:
    @ fetch the next byte when out of bits
    subs r3, r3, 1
    bpl  1f
    ldrb r2, [r0]
    add  r0, r0, 1
    mov  r3, 7
1:
    @ follow the right child on a 1 bit, the left child on a 0 bit
    tst  r2, 1
    beq  1f
    ldrh r6, [r4, 2]
    b    2f
1:  ldrh r6, [r4, 0]
2:  add  r4, r5, r6, lsl 2
    lsr  r2, r2, 1

    @ non-negative nodes are branches
    ldr  r6, [r4]
    tst  r6, r6
    bpl  .Ldecode_bit_loop

    @ leaf: emit one or two characters
    tst  r6, 0xFF00
    beq  1f
    strb r6, [r1, 0]
    lsr  r6, r6, 8
    strb r6, [r1, 1]
    add  r1, r1, 2
    b    .Ldecode_char_loop

1:  strb r6, [r1]
    tst  r6, 0xFF
    beq  .Ldecode_end
    add  r1, r1, 1
    b    .Ldecode_char_loop

.Ldecode_end:
    pop  {r4-r7}
    bx   lr

    endfunction DecodeString

    @ MapFloodSquareEnt.connect values
    .set FLOOD_LEFT,  0
    .set FLOOD_RIGHT, 1
    .set FLOOD_DOWN,  2
    .set FLOOD_UP,    3
    .set FLOOD_END,   4

    .align 2, 0
.LWorkingMovTable: .4byte gWorkingMovTable
.LMapFloodSt: .4byte gMapFloodSt
.LWorkingMap: .4byte gWorkingMap
.LMapTerrain: .4byte gMapTerrain
.LMapUnit: .4byte gMapUnit

    @ r0 = connect, r1 = dx, r2 = dy
    function MapFloodCoreStep
MapFloodCoreStep:
    push {r4-r10}

    @ r1, r2 = target x, y from the current square r5, r6
    ldr  r3, .LMapFloodSt
    ldr  r4, [r3, 0x00] @ active_queue
    ldrb r5, [r4, 0x00] @ x
    add  r1, r1, r5
    ldrb r6, [r4, 0x01] @ y
    add  r2, r2, r6

    @ r10 = gWorkingMovTable[gMapTerrain[y][x]]
    ldr  r7, .LMapTerrain
    ldr  r7, [r7]
    ldr  r7, [r7, r2, lsl 2]
    ldrb r7, [r7, r1]
    ldr  r8, .LWorkingMovTable
    ldrb r10, [r8, r7]

    @ r10 += cost to reach the current square
    ldr  r7, .LWorkingMap
    ldr  r7, [r7]
    ldr  r9, [r7, r6, lsl 2]
    ldrb r9, [r9, r5]
    add  r10, r10, r9

    @ skip if the target was already reached at least as cheaply
    ldr  r9, [r7, r2, lsl 2]
    ldrb r9, [r9, r1]
    cmp  r10, r9
    bhs  .Lstep_end

    @ with a unit, skip squares held by another faction
    ldrb r4, [r3, 0x08] @ has_unit
    tst  r4, r4
    beq  .Lstep_check_move
    ldr  r7, .LMapUnit
    ldr  r7, [r7]
    ldr  r7, [r7, r2, lsl 2]
    ldrb r7, [r7, r1]
    tst  r7, r7
    beq  .Lstep_check_move
    ldrb r4, [r3, 0x0A] @ uid
    eor  r4, r4, r7
    ands r4, r4, 0x80
    bne  .Lstep_end

.Lstep_check_move:
    ldrb r4, [r3, 0x09] @ move
    cmp  r10, r4
    bhi  .Lstep_end

    @ queue the target square
    ldr  r4, [r3, 0x04] @ waiting_queue
    strb r1, [r4, 0x00]
    strb r2, [r4, 0x01]
    strb r0, [r4, 0x02]
    strb r10, [r4, 0x03]
    add  r4, r4, 4
    str  r4, [r3, 0x04]

    ldr  r7, .LWorkingMap
    ldr  r7, [r7]
    ldr  r7, [r7, r2, lsl 2]
    strb r10, [r7, r1]

.Lstep_end:
    pop  {r4-r10}
    bx   lr

    endfunction MapFloodCoreStep

    .macro flood_step connect, dx, dy
    mov  r0, \connect
    mov  r1, \dx
    mov  r2, \dy
    bl   MapFloodCoreStep
    .endm

    .align 2, 0
.LMapFloodSquareBufB: .4byte gMapFloodSquareBufB
.LMapFloodSquareBufA: .4byte gMapFloodSquareBufA

    @ unreferenced copy of the jump table in MapFloodCore
.LFloodJumpTableCopy:
    b    .Lflood_moved_left
    b    .Lflood_moved_right
    b    .Lflood_moved_down
    b    .Lflood_moved_up
    b    .Lflood_queue_end
    b    .Lflood_start
    .4byte .LFloodJumpTableCopy

    function MapFloodCore
MapFloodCore:
    push {r4-r6, lr}

    mov  r4, 0
    ldr  r5, .LMapFloodSt

.Lflood_pass_loop:
    @ swap the active and waiting queues each pass
    eors r4, r4, 1
    beq  1f
    ldr  r0, .LMapFloodSquareBufB
    str  r0, [r5, 0x00]
    ldr  r0, .LMapFloodSquareBufA
    str  r0, [r5, 0x04]
    b    2f
1:  ldr  r0, .LMapFloodSquareBufA
    str  r0, [r5, 0x00]
    ldr  r0, .LMapFloodSquareBufB
    str  r0, [r5, 0x04]
2:
    @ done once a pass starts with an empty queue
    ldr  r6, [r5, 0x00]
    ldrb r6, [r6, 0x02]
    cmp  r6, FLOOD_END
    beq  .Lflood_end

.Lflood_square_loop:
    @ jump to the case for this square's connect value
    ldr  r6, [r5, 0x00]
    ldrb r6, [r6, 0x02]
    mov  r0, pc
    add  r0, r0, 8
    add  r0, r0, r6, lsl 2
    bx   r0
    b    .Lflood_moved_left
    b    .Lflood_moved_right
    b    .Lflood_moved_down
    b    .Lflood_moved_up
    b    .Lflood_queue_end

    @ the starting square: expand in every direction
.Lflood_start:
    flood_step FLOOD_UP,     0, -1
    flood_step FLOOD_DOWN,   0, +1
    flood_step FLOOD_LEFT,  -1,  0
    flood_step FLOOD_RIGHT, +1,  0
    b    .Lflood_next_square

    @ don't expand back toward the square we came from
.Lflood_moved_up:
    flood_step FLOOD_UP,     0, -1
    flood_step FLOOD_LEFT,  -1,  0
    flood_step FLOOD_RIGHT, +1,  0
    b    .Lflood_next_square

.Lflood_moved_down:
    flood_step FLOOD_DOWN,   0, +1
    flood_step FLOOD_LEFT,  -1,  0
    flood_step FLOOD_RIGHT, +1,  0
    b    .Lflood_next_square

.Lflood_moved_left:
    flood_step FLOOD_UP,     0, -1
    flood_step FLOOD_DOWN,   0, +1
    flood_step FLOOD_LEFT,  -1,  0
    b    .Lflood_next_square

.Lflood_moved_right:
    flood_step FLOOD_UP,     0, -1
    flood_step FLOOD_DOWN,   0, +1
    flood_step FLOOD_RIGHT, +1,  0

.Lflood_next_square:
    @ terminate the waiting queue and advance the active one
    ldr  r6, [r5, 0x04]
    mov  r0, FLOOD_END
    strb r0, [r6, 0x02]
    ldr  r6, [r5, 0x00]
    add  r6, r6, 4
    str  r6, [r5, 0x00]
    b    .Lflood_square_loop

.Lflood_queue_end:
    b    .Lflood_pass_loop

.Lflood_end:
    pop  {r4-r6, lr}
    bx   lr

    endfunction MapFloodCore

    .global ArmCodeEnd
    .type ArmCodeEnd, object
ArmCodeEnd:
