#ifndef __PLATFORM
#define __PLATFORM

#include <globals.h>
#include "cMagMeshObject.h"

class _Platform : public cMagMeshObject {
public:
	/* 41A700 */ _Platform();
	/* 41A740 */ virtual ~_Platform();
	/* 41A750 */ void* EXP();
};

STATIC_ASSERT(sizeof(_Platform) == 0x2658);

#endif