#ifndef C_MAG_LIGHT
#define C_MAG_LIGHT

#include <globals.h>

#include "d3d8.h"

class cMagLight {
public:
	/* 10007340 */ cMagLight(cMagLight* param_1);
	/* 10007410 */ cMagLight* operator=(cMagLight* param_1);
	/* 10007640 */ cMagLight* scalar_destructor(uchar param_1);
	/* 1008D800 */ cMagLight();
	/* 1008D860 */ ~cMagLight();
	/* 1008D8C0 */ bool GetDynamicLight(int param_1, uchar param_2);
	/* 1008D920 */ int AddDynamicLight(D3DLIGHT8 param_1);
	/* 1008DB90 */ void ClearDynamicLights();
};

#endif