#ifndef C_FADE_IN_OUT
#define C_FADE_IN_OUT

#include <globals.h>
#include "cMagSprite.h"

class cFadeInOut : public cMagSprite {
public:
	/* 41C4A0 */ cFadeInOut();
	/* 41C530 */ cMagSprite* scalar_destructor(uchar param_1);
	/* 41C550 */ ~cFadeInOut();
	/* 41C560 */ void FUN0041c560();
	/* 41C5A0 */ void OnActivate();
	/* 41C5E0 */ void FUN0041c5e0(cMagKernel* param_1);
	/* 41C600 */ void OnFrame();
	/* 41C750 */ void FUN0041c750();
	/* 41C7B0 */ void FUN0041c7b0();
	/* 41C830 */ void FUN0041c830(bool param_1);

private:
	/* 0x1740 */ uchar field_0x1740[0x1770-0x1740];
};

STATIC_ASSERT(sizeof(cFadeInOut) == 0x1770);

#endif