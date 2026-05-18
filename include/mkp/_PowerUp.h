#ifndef __POWER_UP
#define __POWER_UP

#include <globals.h>
#include "cMagMeshObject.h"

class _PowerUp : public cMagMeshObject {
public:
	/* 4327D0 */ _PowerUp();
	/* 432810 */ virtual ~_PowerUp();
	/* 432820 */ void* EXP();
};

STATIC_ASSERT(sizeof(_PowerUp) == 0x2658);

#endif