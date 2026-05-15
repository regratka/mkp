#ifndef _C_TEST_ANIM
#define _C_TEST_ANIM

#include <globals.h>

class CTestAnim {
public:
	/* 441EE0 */ CTestAnim();
	/* 441F90 */ CTestAnim* scalar_destructor(uchar param_1);
	/* 441FB0 */ ~CTestAnim();
	/* 441FF0 */ void* EXP();
	/* 442050 */ void OnActivateLevel();
	/* 442270 */ void OnAction();
	/* 442280 */ void OnFrame();
	/* 442360 */ void OnDestinationPos();
	/* 442390 */ uchar OnLoadChunk(int param_1, int param_2, uint param_3, void* param_4);
};

#endif