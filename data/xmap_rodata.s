	.section .rodata

	.global String_SoundRoomMainThemeName
String_SoundRoomMainThemeName: @ 08336D08
	.incbin "fe6-base.gba", 0x336D08, (0x336D2C - 0x336D08) @ length: 0024

	.global String_SoundRoomMainThemeDesc
String_SoundRoomMainThemeDesc: @ 08336D2C
	.incbin "fe6-base.gba", 0x336D2C, (0x336D3C - 0x336D2C) @ length: 0010

	.global String_SoundRoomPlay
String_SoundRoomPlay: @ 08336D3C
	.incbin "fe6-base.gba", 0x336D3C, (0x336D48 - 0x336D3C) @ length: 000C

	.global String_SoundRoomStop
String_SoundRoomStop: @ 08336D48
	.incbin "fe6-base.gba", 0x336D48, (0x336D54 - 0x336D48) @ length: 000C

	.global String_SoundRoomExit
String_SoundRoomExit: @ 08336D54
	.incbin "fe6-base.gba", 0x336D54, (0x336D5C - 0x336D54) @ length: 0008
