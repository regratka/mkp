#ifndef C_MAG_FOG
#define C_MAG_FOG

#include <globals.h>

#include "cMagUtility.h"

class DLLEXPORT cMagFog : public cMagUtility {
public:
	/* 1005A5E0 */ void InitDeviceObjects(cMagGameObject* param_1);
	/* 10072470 */ cMagFog();
	/* 10072500 */ virtual ~cMagFog();
	/* 10072560 */ void TypeFog(ulong param_1);
	/* 10072570 */ void InitFog();
	/* 10072610 */ void SetFogRangeNear(float param_1);
	/* 10072620 */ void SetFogRangeFar(float param_1);
	/* 10072630 */ void SetFogDensity(float param_1);
	/* 10072640 */ void SetColorFog(uchar param_1, uchar param_2, uchar param_3);
	/* 10072680 */ void EnableFog();
	/* 100726B0 */ void DisableFog();
	/* 100726E0 */ void SetColorFog(D3DCOLOR param_1);
	/* 100726F0 */ D3DCOLOR GetColorFog();
	/* 10072700 */ void Enable(bool param_1);

private:
	/* 0xd4c */ float fogRangeNear;
	/* 0xd50 */ float fogRangeFar;
	/* 0xd54 */ float fogDensity;
	/* 0xd58 */ D3DCOLOR colorFog;
	/* 0xd5c */ D3DFOGMODE typeFog;
};

STATIC_ASSERT(sizeof(cMagFog) == 0xd60);

#endif