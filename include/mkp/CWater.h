#ifndef _C_WATER
#define _C_WATER

#include <globals.h>

class CWater {
public:
	/* 433600 */ CWater();
	/* 433620 */ CWater* scalar_destructor(uchar param_1);
	/* 433640 */ ~CWater();
	/* 433650 */ void* EXP();
	/* 4336B0 */ void OnActivateLevel();
	/* 433A70 */ uchar OnLoadChunk(uint param_1, int param_2, uint param_3, void* param_4);
};

#endif