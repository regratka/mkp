#ifndef __ACTION
#define __ACTION

#include <globals.h>
#include "cMagMeshObject.h"

class _Action : public cMagMeshObject {
public:
	/* 416820 */ _Action();
	/* 416860 */ virtual ~_Action();
	/* 416870 */ void* EXP();
};

STATIC_ASSERT(sizeof(_Action) == 0x2658);

#endif