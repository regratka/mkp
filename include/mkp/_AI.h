#ifndef __A_I
#define __A_I

#include <globals.h>
#include "cMagMeshObject.h"

class _AI : public cMagMeshObject {
public:
	/* 43CCC0 */ _AI();
	/* 43CD00 */ virtual ~_AI();
	/* 43CD10 */ void* EXP();
};

STATIC_ASSERT(sizeof(_AI) == 0x2658);

#endif