#ifndef _C_HUD_GRATKA
#define _C_HUD_GRATKA

#include <globals.h>

#include <d3dx8math.h>

class CHudGratka {
public:
	/* 42C480 */ CHudGratka();
	/* 42C570 */ CHudGratka* scalar_destructor(uchar param_1);
	/* 42C590 */ ~CHudGratka();
	/* 42C5A0 */ void OnActivate();
	/* 42CC30 */ void FUN0042CC30(bool param_1);
	/* 42CCF0 */ void OnActivateLevel();
	/* 42CE00 */ void OnFrame();
	/* 42CE80 */ uchar FUN0042ce80(int param_1);
	/* 42CF40 */ uchar FUN0042cf40(int param_1);
	/* 42D000 */ uchar FUN0042d000();
	/* 42D030 */ uchar FUN0042d030();
	/* 42D360 */ uchar FUN0042d360(int param_1);
	/* 42D450 */ int FUN0042d450();
	/* 42D460 */ uchar FUN0042d460(int param_1);
	/* 42D6E0 */ uchar FUN0042d6e0();
	/* 42D780 */ int FUN0042d780(char* param_1);
	/* 42D810 */ void FUN0042d810();
	/* 42D850 */ void FUN0042d850();
	/* 42DB90 */ void FUN0042db90(bool param_1, D3DXVECTOR3 param_2);
	/* 42DD10 */ void FUN0042dd10();
	/* 42DD60 */ void FUN0042dd60(bool param_1);
	/* 42DFB0 */ void FUN0042dfb0(bool param_1);
	/* 42E030 */ void FUN0042e030();
	/* 42E0A0 */ float FUN0042e0a0();
	/* 42E0B0 */ void FUN0042e0b0();
};

#endif