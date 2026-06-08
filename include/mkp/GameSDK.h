#ifndef _GAME_S_D_K
#define _GAME_S_D_K

#include <globals.h>

#include "CGame.h"


class GameSDK : public CGame {
public:
	/* 401400 */ GameSDK();
	/* 401780 */ CGame* scalar_destructor(uchar param_1);
	/* 4017A0 */ ~GameSDK();
	/* 401830 */ void Run(HINSTANCE__* param_1, bool param_2, int param_3, int param_4, int param_5, char* param_6, bool param_7);
	/* 4018F0 */ void OnActivateLevel();
	/* 4019B0 */ void OnInputKey(char* param_1);
	/* 401A90 */ void OnFrame();
	/* 401AB0 */ uchar FUN00401ab0(uchar param_1);
	/* 401AC0 */ uchar FUN00401ac0();
	/* 401AF0 */ uchar FUN00401af0(uint param_1);
	/* 401B30 */ void FUN00401b30();
	/* 401B50 */ uchar FUN00401b50(uint param_1, int param_2);
	/* 401B80 */ void FUN00401b80();
	/* 401BA0 */ void FUN00401ba0();
	/* 401C80 */ uchar OnButtonDown(void* param_1);
	/* 401D50 */ void FUN00401d50();
	/* 401D80 */ void FUN00401d80();
	/* 401DB0 */ uchar FUN00401db0();
	/* 401DE0 */ void FUN00401de0();
	/* 401E10 */ float FUN00401e10();
	/* 401E20 */ uchar FUN00401e20(char* param_1);
	/* 401E40 */ uint FUN00401e40();
	/* 4022C0 */ uchar FUN004022c0(char* param_1);
	/* 4022E0 */ uchar FUN004022e0(char* param_1);
	/* 402300 */ uint FUN00402300();
public:
	/* 0x19f0 */ uchar field_0x19f0[0x1d76 - 0x19f0];
	/* 0x1d76 */ char e_input[100];
	/* 0x1dda */ uchar field_0x1dda[0x278c - 0x1dda];

};

#endif