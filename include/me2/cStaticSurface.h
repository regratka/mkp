#ifndef C_STATIC_SURFACE
#define C_STATIC_SURFACE

#include <globals.h>
#include <d3dx8math.h>

#include "cStaticMesh.h"

class cStaticSurface {
public:
	/* 10040BE0 */ cStaticSurface* scalar_destructor(uchar param_1);
	/* 10042320 */ cStaticSurface();
	/* 10042430 */ ~cStaticSurface();
	/* 10042500 */ void FUN10042500(D3DXVECTOR3* param_1, cStaticMesh* param_2);
	/* 10042AD0 */ bool FUN10042ad0(float param_1);
	/* 10042BC0 */ bool FUN10042bc0(int param_1);
	/* 10042D10 */ void FUN10042d10();
	/* 10043620 */ void FUN10043620();
	/* 10043960 */ void FUN10043960(bool param_1);
	/* 10043970 */ void FUN10043970();
	/* 10043C80 */ void FUN10043c80();
	/* 10043DE0 */ void FUN10043de0();
};

#endif