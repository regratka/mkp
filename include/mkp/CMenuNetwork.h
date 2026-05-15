#ifndef _C_MENU_NETWORK
#define _C_MENU_NETWORK

#include <globals.h>

#include "cMagSprite.h"

class CMenuNetwork {
public:
	/* 42E3F0 */ CMenuNetwork();
	/* 42E4A0 */ cMagSprite* scalar_destructor(uchar param_1);
	/* 42E4C0 */ ~CMenuNetwork();
	/* 42E4D0 */ void OnActivate();
	/* 42E8D0 */ void OnActivateLevel();
	/* 42EB50 */ void OnFrame();
	/* 42ECB0 */ uchar OnButtonDown(cMagSprite* param_1);
};

#endif