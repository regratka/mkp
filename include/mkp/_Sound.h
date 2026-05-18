#ifndef __SOUND
#define __SOUND

#include <globals.h>
#include "cMagMeshObject.h"

class _Sound : public cMagMeshObject {
public:
	/* 4195D0 */ _Sound();
	/* 419610 */ ~_Sound();
	/* 419620 */ void* EXP();
};

STATIC_ASSERT(sizeof(_Sound) == 0x2658);

#endif