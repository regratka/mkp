#ifndef _C_CUT_SCENE
#define _C_CUT_SCENE

#include <globals.h>

class CCutScene {
public:
	/* 41CA50 */ CCutScene();
	/* 41CC40 */ CCutScene* scalar_destructor(uchar param_1);
	/* 41CC60 */ ~CCutScene();
	/* 41CCA0 */ void* EXP();
	/* 41CD00 */ void OnActivateLevel();
	/* 41D020 */ uchar OnCollisionObject(int* param_1);
	/* 41D0B0 */ void FUN0041d0b0();
	/* 41D280 */ void OnDestTime();
	/* 41D4E0 */ uchar OnFadeOutEnd();
	/* 41D700 */ void OnFadeInEnd();
	/* 41D720 */ void OnAction();
	/* 41D730 */ void OnAction(char* param_1);
	/* 41D760 */ uchar OnLoadChunk(uint param_1, int param_2, uint param_3, void* param_4);
	/* 41D790 */ uchar Save(int* param_1);
	/* 41D850 */ uchar Load(void* param_1, uint param_2, int param_3);
};

#endif