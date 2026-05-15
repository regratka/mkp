#ifndef _C_KRZAK
#define _C_KRZAK

#include <globals.h>

class CKrzak {
public:
	/* 441A50 */ CKrzak();
	/* 441A90 */ CKrzak* scalar_destructor(uchar param_1);
	/* 441AB0 */ ~CKrzak();
	/* 441AC0 */ void* EXP();
	/* 441B20 */ void OnActivate();
	/* 441B60 */ void OnActivateLevel();
	/* 441BB0 */ void OnFrame();
	/* 441C80 */ uchar OnLoadChunk(uint param_1, int param_2, uint param_3, void* param_4);
};

#endif