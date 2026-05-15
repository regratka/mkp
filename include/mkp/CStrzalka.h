#ifndef _C_STRZALKA
#define _C_STRZALKA

#include <globals.h>

class CStrzalka {
public:
	/* 442CA0 */ CStrzalka();
	/* 442CD0 */ CStrzalka* scalar_destructor(uchar param_1);
	/* 442CF0 */ ~CStrzalka();
	/* 442D00 */ void* EXP();
	/* 442D60 */ void OnActivateLevel();
	/* 442DF0 */ void OnFrame();
};

#endif