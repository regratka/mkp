#ifndef _C_LEVEL_MENU_NET
#define _C_LEVEL_MENU_NET

#include <globals.h>

class CLevelMenuNet {
public:
	/* 415B80 */ CLevelMenuNet();
	/* 415BE0 */ CLevelMenuNet* scalar_destructor(uchar param_1);
	/* 415C00 */ ~CLevelMenuNet();
	/* 415C60 */ void* EXP();
	/* 415CC0 */ void OnActivate();
	/* 415D90 */ void OnActivateLevel();
	/* 415DA0 */ void OnInputKey(char* param_1);
};

#endif