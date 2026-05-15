#ifndef C_FADE_IN_OUT
#define C_FADE_IN_OUT

#include <globals.h>
#include "cMagSprite.h"

class cFadeInOut {
public:
	/* 41C4A0 */ cFadeInOut();
	/* 41C530 */ cMagSprite* scalar_destructor(uchar param_1);
	/* 41C550 */ ~cFadeInOut();
	/* 41C5A0 */ void OnActivate();
	/* 41C600 */ void OnFrame();
};

#endif