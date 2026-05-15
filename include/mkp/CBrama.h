#ifndef _C_BRAMA
#define _C_BRAMA

#include <globals.h>

class CBrama {
public:
	/* 41A860 */ CBrama();
	/* 41A8B0 */ uchar scalar_destructor(uchar param_1);
	/* 41A8D0 */ ~CBrama();
	/* 41A8E0 */ void* EXP();
	/* 41A940 */ void OnActivate();
	/* 41A970 */ void OnActivateLevel();
	/* 41AAD0 */ void OnCrash();
	/* 41AB00 */ uint OnProcessStateMachine(uint param_1, int param_2, int* param_3);
	/* 41AEF0 */ uchar OnLoadChunk(uint param_1, int param_2, uint param_3, void* param_4);
};

#endif