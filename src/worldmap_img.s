    .section .rodata

    .global gUnk_WmArrow_Buf1
gUnk_WmArrow_Buf1:
    .incbin "fe6-base.gba", 0x2AA380, (0x2AA4CC - 0x2AA380)

    .global gUnk_WmArrow_Buf2
gUnk_WmArrow_Buf2:
    .incbin "fe6-base.gba", 0x2AA4CC, (0x2AA5F0 - 0x2AA4CC)

    .global gUnk_WmArrow_Buf3
gUnk_WmArrow_Buf3:
    .incbin "fe6-base.gba", 0x2AA5F0, (0x2AA650 - 0x2AA5F0)

    .global gUnk_WmArrow_Buf4
gUnk_WmArrow_Buf4:
    .incbin "fe6-base.gba", 0x2AA650, (0x2AA7FC - 0x2AA650)

    .global gUnk_WmArrow_Buf5
gUnk_WmArrow_Buf5:
    .incbin "fe6-base.gba", 0x2AA7FC, (0x2AA844 - 0x2AA7FC)

    .global gUnk_WmArrow_Buf6
gUnk_WmArrow_Buf6:
    .incbin "fe6-base.gba", 0x2AA844, (0x2AA918 - 0x2AA844)

    .global gUnk_WmArrow_Buf7
gUnk_WmArrow_Buf7:
    .incbin "fe6-base.gba", 0x2AA918, (0x2AA968 - 0x2AA918)

    .global Pal_ManimFireDragonMu
Pal_ManimFireDragonMu: @ 082AA968
    .incbin "fe6-base.gba", 0x2AA968, (0x2AA988 - 0x2AA968) @ length: 0020

    .global Pal_ManimDivineDragonMu
Pal_ManimDivineDragonMu: @ 082AA988
    .incbin "fe6-base.gba", 0x2AA988, (0x2AA9A8 - 0x2AA988) @ length: 0020

    .global Img_WmDialogueBox
Img_WmDialogueBox: @ 082AA9A8
    .incbin "data/worldmap/graphics/Img_WmDialogueBox.4bpp.lz"

    .global Pal_WmDialogueBox
Pal_WmDialogueBox: @ 082AAD5C
    .incbin "data/worldmap/graphics/Img_WmDialogueBox.gbapal", 0, 0x20

    .incbin "fe6-base.gba", 0x2AAD7C, (0x2AADA4 - 0x2AAD7C)

    .global Img_WorldMapZoomNW
Img_WorldMapZoomNW:    @ 0x082AADA4
    .incbin "fe6-base.gba", 0x2AADA4, 0x2B2380 - 0x2AADA4

    .global Img_WorldMapZoomNE
Img_WorldMapZoomNE:    @ 0x082B2380
    .incbin "fe6-base.gba", 0x2B2380, 0x2B9E64 - 0x2B2380

    .global Img_WorldMapZoomSW
Img_WorldMapZoomSW:    @ 0x082B9E64
    .incbin "fe6-base.gba", 0x2B9E64, 0x2C1224 - 0x2B9E64

    .global Img_WorldMapZoomSE
Img_WorldMapZoomSE:    @ 0x082C1224
    .incbin "fe6-base.gba", 0x2C1224, 0x2C8874 - 0x2C1224

    .global Img_WorldMap
Img_WorldMap:    @ 0x082C8874
    .incbin "fe6-base.gba", 0x2C8874, 0x2D1964 - 0x2C8874

    .global Pal_WorldMapZoom
Pal_WorldMapZoom:    @ 0x082D1964
    .incbin "fe6-base.gba", 0x2D1964, 0x2D1BA0 - 0x2D1964

    .global Pal_WorldMap
Pal_WorldMap:    @ 0x082D1BA0
    .incbin "fe6-base.gba", 0x2D1BA0, 0x2D1DE4 - 0x2D1BA0

    .global Img_WmHighlight_Nation1
Img_WmHighlight_Nation1:
    .incbin "data/worldmap/graphics/Img_WmHighlight_Nation1.4bpp.lz"

    .global Img_WmHighlight_Nation2
Img_WmHighlight_Nation2:
    .incbin "data/worldmap/graphics/Img_WmHighlight_Nation2.4bpp.lz"

    .global Img_WmHighlight_Nation3
Img_WmHighlight_Nation3:
    .incbin "data/worldmap/graphics/Img_WmHighlight_Nation3.4bpp.lz"

    .global Img_WmHighlight_Nation4
Img_WmHighlight_Nation4:
    .incbin "data/worldmap/graphics/Img_WmHighlight_Nation4.4bpp.lz"

    .global Img_WmHighlight_Nation5
Img_WmHighlight_Nation5:
    .incbin "data/worldmap/graphics/Img_WmHighlight_Nation5.4bpp.lz"

    .global Img_WmHighlight_Nation6
Img_WmHighlight_Nation6:
    .incbin "data/worldmap/graphics/Img_WmHighlight_Nation6.4bpp.lz"

    .global Img_WmHighlight_Nation7
Img_WmHighlight_Nation7:
    .incbin "data/worldmap/graphics/Img_WmHighlight_Nation7.4bpp.lz"

    .global ApInfo_WmHighlight_Nation1
ApInfo_WmHighlight_Nation1:
    .incbin "fe6-base.gba", 0x2D3224, 0x2D3250 - 0x2D3224

    .global ApInfo_WmHighlight_Nation2
ApInfo_WmHighlight_Nation2:
    .incbin "fe6-base.gba", 0x2D3250, 0x2D3280 - 0x2D3250

    .global ApInfo_WmHighlight_Nation3
ApInfo_WmHighlight_Nation3:
    .incbin "fe6-base.gba", 0x2D3280, 0x2D32AC - 0x2D3280

    .global ApInfo_WmHighlight_Nation4
ApInfo_WmHighlight_Nation4:
    .incbin "fe6-base.gba", 0x2D32AC, 0x2D32F0 - 0x2D32AC

    .global ApInfo_WmHighlight_Nation5
ApInfo_WmHighlight_Nation5:
    .incbin "fe6-base.gba", 0x2D32F0, 0x2D3324 - 0x2D32F0

    .global ApInfo_WmHighlight_Nation7
ApInfo_WmHighlight_Nation7:
    .incbin "fe6-base.gba", 0x2D3324, 0x2D335C - 0x2D3324

    .global ApInfo_WmHighlight_Nation6
ApInfo_WmHighlight_Nation6:
    .incbin "fe6-base.gba", 0x2D335C, 0x2D3398 - 0x2D335C

    .global Pal_WmHightlight
Pal_WmHightlight: @ 082D3398
    .incbin "fe6-base.gba", 0x2D3398, (0x2D33B8 - 0x2D3398) @ length: 0020

    .global Img_WorldMapStuff
Img_WorldMapStuff: @ 082D33B8
    .incbin "data/worldmap/graphics/Img_WorldMapStuff.4bpp.lz"

    .global ApInfo_WmDot
ApInfo_WmDot: @ 082D3674
    .incbin "fe6-base.gba", 0x2D3674, (0x2D36E4 - 0x2D3674) @ length: 0070

    .global Pal_WorldMapStuff
Pal_WorldMapStuff: @ 082D36E4
    .incbin "fe6-base.gba", 0x2D36E4, (0x2D3764 - 0x2D36E4) @ length: 0080

    .global Pal_WmSpriteDisp2
Pal_WmSpriteDisp2: @ 082D3764
    .incbin "fe6-base.gba", 0x2D3764, (0x2D37E4 - 0x2D3764) @ length: 0080

    .global Pal_WmSpriteDisp1
Pal_WmSpriteDisp1: @ 082D37E4
    .incbin "fe6-base.gba", 0x2D37E4, (0x2D3864 - 0x2D37E4) @ length: 0080

    .global Pal_WmMapText
Pal_WmMapText: @ 082D3864
    .incbin "fe6-base.gba", 0x2D3864, (0x2D38A4 - 0x2D3864) @ length: 0040

    .global ApInfo_WmMapTextDisp
ApInfo_WmMapTextDisp: @ 082D38A4
    .incbin "fe6-base.gba", 0x2D38A4, (0x2D3904 - 0x2D38A4)

	.global Img_WmMapTextDisp_082D3904
Img_WmMapTextDisp_082D3904:	@ 0x082D3904
	.incbin "fe6-base.gba", 0x2D3904, 0x2D3C68 - 0x2D3904

	.global Img_WmMapTextDisp_082D3C68
Img_WmMapTextDisp_082D3C68:	@ 0x082D3C68
	.incbin "fe6-base.gba", 0x2D3C68, 0x2D3E78 - 0x2D3C68

	.global Img_WmMapTextDisp_082D3E78
Img_WmMapTextDisp_082D3E78:	@ 0x082D3E78
	.incbin "fe6-base.gba", 0x2D3E78, 0x2D4120 - 0x2D3E78

	.global Img_WmMapTextDisp_082D4120
Img_WmMapTextDisp_082D4120:	@ 0x082D4120
	.incbin "fe6-base.gba", 0x2D4120, 0x2D43A4 - 0x2D4120

	.global Img_WmMapTextDisp_082D43A4
Img_WmMapTextDisp_082D43A4:	@ 0x082D43A4
	.incbin "fe6-base.gba", 0x2D43A4, 0x2D45E0 - 0x2D43A4

	.global Img_WmMapTextDisp_082D45E0
Img_WmMapTextDisp_082D45E0:	@ 0x082D45E0
	.incbin "fe6-base.gba", 0x2D45E0, 0x2D4838 - 0x2D45E0

	.global Img_WmMapTextDisp_082D4838
Img_WmMapTextDisp_082D4838:	@ 0x082D4838
	.incbin "fe6-base.gba", 0x2D4838, 0x2D4B38 - 0x2D4838

	.global Img_WmMapTextDisp_082D4B38
Img_WmMapTextDisp_082D4B38:	@ 0x082D4B38
	.incbin "fe6-base.gba", 0x2D4B38, 0x2D4D3C - 0x2D4B38

	.global Img_WmMapTextDisp_082D4D3C
Img_WmMapTextDisp_082D4D3C:	@ 0x082D4D3C
	.incbin "fe6-base.gba", 0x2D4D3C, 0x2D4F9C - 0x2D4D3C

	.global Img_WmMapTextDisp_082D4F9C
Img_WmMapTextDisp_082D4F9C:	@ 0x082D4F9C
	.incbin "fe6-base.gba", 0x2D4F9C, 0x2D5254 - 0x2D4F9C

	.global Img_WmMapTextDisp_082D5254
Img_WmMapTextDisp_082D5254:	@ 0x082D5254
	.incbin "fe6-base.gba", 0x2D5254, 0x2D5400 - 0x2D5254

	.global Img_WmMapTextDisp_082D5400
Img_WmMapTextDisp_082D5400:	@ 0x082D5400
	.incbin "fe6-base.gba", 0x2D5400, 0x2D55A4 - 0x2D5400

	.global Img_WmMapTextDisp_082D55A4
Img_WmMapTextDisp_082D55A4:	@ 0x082D55A4
	.incbin "fe6-base.gba", 0x2D55A4, 0x2D5778 - 0x2D55A4

	.global Img_WmMapTextDisp_082D5778
Img_WmMapTextDisp_082D5778:	@ 0x082D5778
	.incbin "fe6-base.gba", 0x2D5778, 0x2D5844 - 0x2D5778

	.global Img_WmMapTextDisp_082D5844
Img_WmMapTextDisp_082D5844:	@ 0x082D5844
	.incbin "fe6-base.gba", 0x2D5844, 0x2D5910 - 0x2D5844

    .global Img_DefaultMapText
Img_DefaultMapText: @ 082D5910
    .incbin "fe6-base.gba", 0x2D5910, (0x2D59DC - 0x2D5910)

	.global Img_WmMapTextDisp_082D59DC
Img_WmMapTextDisp_082D59DC:	@ 0x082D59DC
	.incbin "fe6-base.gba", 0x2D59DC, 0x2D5B98 - 0x2D59DC

	.global Img_WmMapTextDisp_082D5B98
Img_WmMapTextDisp_082D5B98:	@ 0x082D5B98
	.incbin "fe6-base.gba", 0x2D5B98, 0x2D5D08 - 0x2D5B98

	.global Img_WmMapTextDisp_082D5D08
Img_WmMapTextDisp_082D5D08:	@ 0x082D5D08
	.incbin "fe6-base.gba", 0x2D5D08, 0x2D5EE0 - 0x2D5D08

	.global Img_WmMapTextDisp_082D5EE0
Img_WmMapTextDisp_082D5EE0:	@ 0x082D5EE0
	.incbin "fe6-base.gba", 0x2D5EE0, 0x2D60F4 - 0x2D5EE0

	.global Img_WmMapTextDisp_082D60F4
Img_WmMapTextDisp_082D60F4:	@ 0x082D60F4
	.incbin "fe6-base.gba", 0x2D60F4, 0x2D6274 - 0x2D60F4

	.global Img_WmMapTextDisp_082D6274
Img_WmMapTextDisp_082D6274:	@ 0x082D6274
	.incbin "fe6-base.gba", 0x2D6274, 0x2D6408 - 0x2D6274

	.global Img_WmMapTextDisp_082D6408
Img_WmMapTextDisp_082D6408:	@ 0x082D6408
	.incbin "fe6-base.gba", 0x2D6408, 0x2D65A8 - 0x2D6408

	.global Img_WmMapTextDisp_082D65A8
Img_WmMapTextDisp_082D65A8:	@ 0x082D65A8
	.incbin "fe6-base.gba", 0x2D65A8, 0x2D6768 - 0x2D65A8

	.global Img_WmMapTextDisp_082D6768
Img_WmMapTextDisp_082D6768:	@ 0x082D6768
	.incbin "fe6-base.gba", 0x2D6768, 0x2D6930 - 0x2D6768

	.global Img_WmMapTextDisp_082D6930
Img_WmMapTextDisp_082D6930:	@ 0x082D6930
	.incbin "fe6-base.gba", 0x2D6930, 0x2D6AF4 - 0x2D6930

	.global Img_WmMapTextDisp_082D6AF4
Img_WmMapTextDisp_082D6AF4:	@ 0x082D6AF4
	.incbin "fe6-base.gba", 0x2D6AF4, 0x2D6CA8 - 0x2D6AF4

	.global Img_WmMapTextDisp_082D6CA8
Img_WmMapTextDisp_082D6CA8:	@ 0x082D6CA8
	.incbin "fe6-base.gba", 0x2D6CA8, 0x2D6E44 - 0x2D6CA8

	.global Img_WmMapTextDisp_082D6E44
Img_WmMapTextDisp_082D6E44:	@ 0x082D6E44
	.incbin "fe6-base.gba", 0x2D6E44, 0x2D7018 - 0x2D6E44

	.global Img_WmMapTextDisp_082D7018
Img_WmMapTextDisp_082D7018:	@ 0x082D7018
	.incbin "fe6-base.gba", 0x2D7018, 0x2D720C - 0x2D7018

	.global Img_WmMapTextDisp_082D720C
Img_WmMapTextDisp_082D720C:	@ 0x082D720C
	.incbin "fe6-base.gba", 0x2D720C, 0x2D73D0 - 0x2D720C

	.global Img_WmMapTextDisp_082D73D0
Img_WmMapTextDisp_082D73D0:	@ 0x082D73D0
	.incbin "fe6-base.gba", 0x2D73D0, 0x2D75D8 - 0x2D73D0

	.global Img_WmMapTextDisp_082D75D8
Img_WmMapTextDisp_082D75D8:	@ 0x082D75D8
	.incbin "fe6-base.gba", 0x2D75D8, 0x2D7774 - 0x2D75D8

	.global Img_WmMapTextDisp_082D7774
Img_WmMapTextDisp_082D7774:	@ 0x082D7774
	.incbin "fe6-base.gba", 0x2D7774, 0x2D7934 - 0x2D7774

	.global Img_WmMapTextDisp_082D7934
Img_WmMapTextDisp_082D7934:	@ 0x082D7934
	.incbin "fe6-base.gba", 0x2D7934, 0x2D7B20 - 0x2D7934

	.global Img_WmMapTextDisp_082D7B20
Img_WmMapTextDisp_082D7B20:	@ 0x082D7B20
	.incbin "fe6-base.gba", 0x2D7B20, 0x2D7D24 - 0x2D7B20

	.global Img_WmMapTextDisp_082D7D24
Img_WmMapTextDisp_082D7D24:	@ 0x082D7D24
	.incbin "fe6-base.gba", 0x2D7D24, 0x2D7F2C - 0x2D7D24

	.global Img_WmMapTextDisp_082D7F2C
Img_WmMapTextDisp_082D7F2C:	@ 0x082D7F2C
	.incbin "fe6-base.gba", 0x2D7F2C, 0x2D80B0 - 0x2D7F2C
