#ifndef _C_BALON
#define _C_BALON

#include <globals.h>

class CBalon {
public:
	/* 4400B0 */ CBalon();
	/* 440140 */ uchar scalar_destructor(uchar param_1);
	/* 440160 */ ~CBalon();
	/* 4401A0 */ void* EXP();
	/* 440200 */ void OnAction();
	/* 440220 */ void OnFrame();
	/* 440300 */ void OnDestinationPos();
	/* 440350 */ uchar OnLoadChunk(int param_1, uint param_2, uint param_3, void* param_4);
};

#endif