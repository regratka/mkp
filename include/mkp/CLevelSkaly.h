#ifndef _C_LEVEL_SKALY
#define _C_LEVEL_SKALY

#include <globals.h>

class CLevelSkaly {
public:
	/* 4139B0 */ CLevelSkaly();
	/* 413A20 */ CLevelSkaly* scalar_destructor(uchar param_1);
	/* 413A40 */ ~CLevelSkaly();
	/* 413AC0 */ void* EXP();
	/* 413B20 */ void OnActivate();
	/* 413CD0 */ void OnActivateLevel();
	/* 413D40 */ void OnFrame();
	/* 413D80 */ void OnInputKey(char* param_1);
};

#endif