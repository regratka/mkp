#ifndef _C_HUD_GRATKA
#define _C_HUD_GRATKA

#include <globals.h>

class CHudGratka {
public:
	/* 42C480 */ CHudGratka();
	/* 42C570 */ CHudGratka* scalar_destructor(uchar param_1);
	/* 42C590 */ ~CHudGratka();
	/* 42C5A0 */ void OnActivate();
	/* 42CCF0 */ void OnActivateLevel();
	/* 42CE00 */ void OnFrame();
	/* 42CE80 */ uchar FUN0042ce80(int param_1);
	/* 42CF40 */ uchar FUN0042cf40(int param_1);
	/* 42D000 */ uchar FUN0042d000();
	/* 42D030 */ uchar FUN0042d030();
	/* 42D360 */ uchar FUN0042d360(int param_1);
	/* 42D460 */ uchar FUN0042d460(int param_1);
	/* 42D6E0 */ uchar FUN0042d6e0();
	/* 42D780 */ int FUN0042d780(char* param_1);
};

#endif