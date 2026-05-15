#ifndef _C_OKNO_TAJNY_KOD
#define _C_OKNO_TAJNY_KOD

#include <globals.h>
#include "cMagSprite.h"

class COknoTajnyKod {
public:
	/* 4272F0 */ COknoTajnyKod();
	/* 427350 */ cMagSprite* scalar_destructor(uchar param_1);
	/* 427370 */ ~COknoTajnyKod();
	/* 427380 */ void OnActivate();
	/* 427950 */ void OnFrame();
	/* 427A40 */ uchar OnMouseArrive(int param_1);
	/* 427AA0 */ uchar OnMouseLeave(int param_1);
	/* 427B40 */ uchar OnInputMouse(uint param_1, uint param_2, char param_3);
	/* 427B80 */ uchar OnInputKey(int param_1);
};

#endif