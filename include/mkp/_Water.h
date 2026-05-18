#ifndef __WATER
#define __WATER

#include <globals.h>
#include "cMagMeshObject.h"

class _Water : public cMagMeshObject {
public:
	/* 4334A0 */ _Water();
	/* 4334E0 */ ~_Water();
	/* 4334F0 */ void* EXP();
};

STATIC_ASSERT(sizeof(_Water) == 0x2658);

#endif