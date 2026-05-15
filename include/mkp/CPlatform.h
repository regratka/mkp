#ifndef _C_PLATFORM
#define _C_PLATFORM

#include <globals.h>

class CPlatform {
public:
	/* 41BCA0 */ CPlatform();
	/* 41BD10 */ CPlatform* scalar_destructor(uchar param_1);
	/* 41BD30 */ ~CPlatform();
	/* 41BDC0 */ void* EXP();
	/* 41BE20 */ void OnLoadChunk(int param_1, int* param_2);
	/* 41C130 */ void OnFrame();
	/* 41C220 */ void OnActivate();
	/* 41C240 */ void OnDestinationPos();
	/* 41C270 */ void OnActivateLevel();
	/* 41C380 */ void OnAction();
	/* 41C3C0 */ void OnCrash();
};

#endif