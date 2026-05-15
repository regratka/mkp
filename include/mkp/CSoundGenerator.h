#ifndef _C_SOUND_GENERATOR
#define _C_SOUND_GENERATOR

#include <globals.h>

class CSoundGenerator {
public:
	/* 419820 */ void OnFrame();
	/* 419EF0 */ CSoundGenerator();
	/* 419F50 */ CSoundGenerator* scalar_destructor(uchar param_1);
	/* 419F70 */ ~CSoundGenerator();
	/* 419F80 */ void* EXP();
	/* 419FE0 */ void OnAction();
	/* 41A0B0 */ void OnActivateLevel();
	/* 41A200 */ void OnUpdateMenuSettings();
	/* 41A230 */ uchar OnLoadChunk(uint param_1, int param_2, uint param_3, void* param_4);
};

#endif