#ifndef _C_SOUND_LEKTOR
#define _C_SOUND_LEKTOR

#include <globals.h>

#include "cMagMeshObject.h"

class CSoundLektor {
public:
	/* 41A310 */ CSoundLektor();
	/* 41A350 */ CSoundLektor* scalar_destructor(uchar param_1);
	/* 41A370 */ ~CSoundLektor();
	/* 41A380 */ void* EXP();
	/* 41A3E0 */ uchar OnActivateLevel(cMagMeshObject* param_1);
	/* 41A480 */ void OnFrame();
	/* 41A4D0 */ uchar OnCollisionObject(int* param_1);
	/* 41A630 */ uchar OnPlaySoundEnd(int param_1);
};

#endif