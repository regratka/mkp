#ifndef PG_STRING
#define PG_STRING

#include <globals.h>

class pgString {
public:
	/* 1000B420 */ pgString();
	/* 1000B430 */ int getLength();
	/* 1000B440 */ char* operator_char_const*();
	/* 1000B450 */ char operator[](int param_1);
	/* 100821E0 */ pgString(pgString* param_1);
	/* 10082200 */ pgString(char* param_1);
	/* 10082260 */ ~pgString();
	/* 10082270 */ pgString* set(char* param_1, ...);
	/* 10082310 */ pgString* cat(char* param_1);
	/* 100823F0 */ int length();
	/* 10082410 */ bool consistsJustOf(pgString* param_1);
	/* 10082490 */ int getIndex(char param_1, bool param_2);
	/* 100824D0 */ int getIndex(int param_1, char param_2, bool param_3);
	/* 10082550 */ int getIndexNot(char param_1, bool param_2);
	/* 10082590 */ int getIndexNot(int param_1, char param_2, bool param_3);
	/* 10082610 */ int getIndex(pgString* param_1, bool param_2);
	/* 10082650 */ int getIndex(int param_1, pgString* param_2, bool param_3);
	/* 10082740 */ int getCNum(char param_1);
	/* 10082790 */ pgString* getSubString(pgString param_1, int param_2, int param_3);
	/* 10082850 */ pgString* toLower();
	/* 10082890 */ pgString* toUpper();
	/* 100828D0 */ static char toLower(char param_1);
	/* 10082900 */ static char toUpper(char param_1);
	/* 10082930 */ pgString* cutC(char param_1, bool param_2);
	/* 10082A30 */ pgString* cut(char param_1);
	/* 10082A60 */ pgString* cutS(pgString* param_1, bool param_2);
	/* 10082B80 */ pgString* cut(pgString* param_1);
	/* 10082BB0 */ int find(pgString* param_1);
	/* 10082BF0 */ bool operator<(pgString* param_1);
	/* 10082C60 */ bool operator>(pgString* param_1);
	/* 10082CD0 */ bool operator==(pgString* param_1);
	/* 10082D40 */ bool operator==(char* param_1);
	/* 10082DB0 */ bool operator!=(pgString* param_1);
	/* 10082E20 */ bool operator!=(char* param_1);
	/* 10082E90 */ pgString* operator=(pgString* param_1);
	/* 10082F00 */ pgString* operator+=(pgString* param_1);
	/* 10082F20 */ void setBuffer(char* param_1);
	/* 10110CD3 */ static int _islower(int param_1);
};

#endif