#ifndef C_MAG_FOG
#define C_MAG_FOG

#include <globals.h>

#include "d3d8.h"

class cMagFog {
public:
	/* 10022D00 */ cMagFog(cMagFog* param_1);
	/* 10022E20 */ cMagFog* operator=(cMagFog* param_1);
	/* 10022F30 */ cMagFog* scalar_destructor(uchar param_1);
	/* 10072470 */ cMagFog();
	/* 10072500 */ virtual ~cMagFog();
	/* 10072560 */ void TypeFog(ulong param_1);
	/* 10072570 */ void InitFog();
	/* 10072610 */ void SetFogRangeNear(float param_1);
	/* 10072640 */ void SetColorFog(uchar param_1, uchar param_2, uchar param_3);
	/* 10072680 */ void EnableFog();
	/* 100726B0 */ void DisableFog();
	/* 100726E0 */ void SetColorFog(ulong param_1);
	/* 100726F0 */ D3DCOLOR GetColorFog();
	/* 10072700 */ void Enable(bool param_1);
};

#endif