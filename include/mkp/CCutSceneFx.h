#ifndef _C_CUT_SCENE_FX
#define _C_CUT_SCENE_FX

#include <globals.h>

class CCutSceneFx {
public:
	/* 41D980 */ CCutSceneFx();
	/* 41DA20 */ CCutSceneFx* scalar_destructor(uchar param_1);
	/* 41DA40 */ ~CCutSceneFx();
	/* 41DA80 */ void* EXP();
	/* 41DAE0 */ uchar OnLoadChunk(uint param_1, int param_2, uint param_3, void* param_4);
};

#endif