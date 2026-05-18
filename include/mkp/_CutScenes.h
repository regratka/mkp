#ifndef __CUT_SCENES
#define __CUT_SCENES

#include <globals.h>
#include "cMagMeshObject.h"

class _CutScenes : public cMagMeshObject {
public:
	/* 41C8F0 */ _CutScenes();
	/* 41C930 */ virtual ~_CutScenes();
	/* 41C940 */ void* EXP();
};

STATIC_ASSERT(sizeof(_CutScenes) == 0x2658);

#endif