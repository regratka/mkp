#ifndef __PARTICLES
#define __PARTICLES

#include <globals.h>
#include "cMagMeshObject.h"

class _Particles : public cMagMeshObject {
public:
	/* 431C00 */ _Particles();
	/* 431C40 */ virtual ~_Particles();
	/* 431C50 */ void* EXP();
};

STATIC_ASSERT(sizeof(_Particles) == 0x2658);

#endif