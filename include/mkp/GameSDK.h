#ifndef _GAME_S_D_K
#define _GAME_S_D_K

#include <globals.h>
#include "CGame.h"

class GameSDK {
public:
	/* 401400 */ GameSDK();
	/* 401780 */ CGame* scalar_destructor(uchar param_1);
	/* 4017A0 */ ~GameSDK();
	/* 401830 */ void Run(HINSTANCE param_1, bool param_2, int param_3, int param_4, int param_5, char* param_6, bool param_7);
	/* 4018F0 */ void FUN004018f0();
	/* 401AC0 */ uchar FUN00401ac0();
	/* 401E40 */ uint FUN00401e40();
	/* 402300 */ uint FUN00402300();
};

#endif