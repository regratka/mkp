#ifndef _C_ALPHA_OBJECT
#define _C_ALPHA_OBJECT

#include <globals.h>

#include "cMagMeshObject.h"
#include "cStaticSurface.h"

class CAlphaObject : public cMagGameObject {
public:
	/* 1003D180 */ CAlphaObject(cStaticSurface* param_1, cMagMeshObject* param_2);
	/* 1003D1B0 */ virtual ~CAlphaObject();
	/* 1003D1C0 */ void OnRender();

private:
	/* 0xd10 */ cStaticSurface* unkn_d10;
	/* 0xd14 */ cMagMeshObject* unkn_d14;
};

STATIC_ASSERT(sizeof(CAlphaObject) == 0xd18);

#endif