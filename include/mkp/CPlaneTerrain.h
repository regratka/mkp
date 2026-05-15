#ifndef _C_PLANE_TERRAIN
#define _C_PLANE_TERRAIN

#include <globals.h>

class CPlaneTerrain {
public:
	/* 40EEB0 */ CPlaneTerrain();
	/* 40EED0 */ uchar scalar_destructor(uchar param_1);
	/* 40EEF0 */ ~CPlaneTerrain();
	/* 40EF00 */ void OnActivate();
};

#endif