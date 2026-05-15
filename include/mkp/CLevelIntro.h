#ifndef _C_LEVEL_INTRO
#define _C_LEVEL_INTRO

#include <globals.h>

class CLevelIntro {
public:
	/* 4157C0 */ CLevelIntro();
	/* 415830 */ CLevelIntro* scalar_destructor(uchar param_1);
	/* 415850 */ ~CLevelIntro();
	/* 4158B0 */ void* EXP();
	/* 415910 */ void OnActivate();
	/* 415A40 */ void OnActivateLevel();
	/* 415A90 */ void OnInputKey(uchar* param_1);
};

#endif