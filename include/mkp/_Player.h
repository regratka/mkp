#ifndef __PLAYER
#define __PLAYER

#include <globals.h>
#include "cMagMeshObject.h"

class _Player : public cMagMeshObject {
public:
	/* 40E670 */ _Player();
	/* 40E6B0 */ virtual ~_Player();
	/* 40E6C0 */ void* EXP();
};

STATIC_ASSERT(sizeof(_Player) == 0x2658);

#endif