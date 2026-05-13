#ifndef _GAME_S_D_K
#define _GAME_S_D_K

#include <globals.h>
#include "CGame.h"

class GameSDK {
public:
	/* 401400 */ GameSDK();
	/* 401780 */ CGame* scalar_destructor(uchar param_1);
	/* 4017A0 */ ~GameSDK();
	/* 401830 */ void Run(HINSTANCE__* param_1, bool param_2, int param_3, int param_4, int param_5, char* param_6, bool param_7);
	/* 4018F0 */ void FUN004018f0();
	/* 401A90 */ void FUN00401a90();
	/* 401AC0 */ uchar FUN00401ac0();
	/* 401AF0 */ uchar FUN00401af0(uint param_1);
	/* 401B30 */ void FUN00401b30();
	/* 401B80 */ void FUN00401b80();
	/* 401C80 */ uchar FUN00401c80(void* param_1);
	/* 401D50 */ void FUN00401d50();
	/* 401DE0 */ void FUN00401de0();
	/* 401E20 */ uchar FUN00401e20(char* param_1);
	/* 401E40 */ uint FUN00401e40();
	/* 402300 */ uint FUN00402300();
};

#endif