
// I can't get the sjis tilde to generate matching strings so I'm using '\x81\x60' instead

char const String_ItemRange_1ToMag[] = "�P\x81\x60����";
char const String_ItemRange_1[]      = "�@�@�@�P";
char const String_ItemRange_1To2[]   = "�@�P\x81\x60�Q";
char const String_ItemRange_1To3[]   = "�@�P\x81\x60�R";
char const String_ItemRange_2[]      = "�@�@�@�Q\0";
char const String_ItemRange_2To3[]   = "�@�Q\x81\x60�R";
char const String_ItemRange_3To10[]  = "�R\x81\x60�P�O";
char const String_ItemRange_3To15[]  = "�R\x81\x60�P�T";
char const String_ItemRange_All[]    = "�@�@�S��";
char const String_ItemRange_None[]   = "�@�@�[�[";
