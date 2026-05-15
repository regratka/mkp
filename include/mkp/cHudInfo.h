#ifndef C_HUD_INFO
#define C_HUD_INFO

#include <globals.h>
#include "cMagSprite.h"

class cHudInfo {
public:
	/* 427EF0 */ cHudInfo();
	/* 4280E0 */ cMagSprite* scalar_destructor(uchar param_1);
	/* 428180 */ ~cHudInfo();
	/* 428310 */ void OnActivateLevel();
	/* 4283E0 */ void OnFrame();
};

#endif