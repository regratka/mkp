#ifndef __WROGOWIE
#define __WROGOWIE

#include <globals.h>
#include "cMagMeshObject.h"

class _Wrogowie : public cMagMeshObject {
public:
	/* 43DD20 */ _Wrogowie();
	/* 43DD60 */ ~_Wrogowie();
	/* 43DD70 */ void* EXP();
};

STATIC_ASSERT(sizeof(_Wrogowie) == 0x2658);

#endif