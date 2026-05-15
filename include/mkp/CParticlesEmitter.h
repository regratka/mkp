#ifndef _C_PARTICLES_EMITTER
#define _C_PARTICLES_EMITTER

#include <globals.h>

class CParticlesEmitter {
public:
	/* 431D60 */ CParticlesEmitter();
	/* 431DA0 */ void* scalar_destructor(uchar param_1);
	/* 431DC0 */ ~CParticlesEmitter();
	/* 431DD0 */ void* EXP();
	/* 431E30 */ void OnActivate();
	/* 431EB0 */ void OnActivateLevel();
	/* 432010 */ void OnAction();
	/* 4320D0 */ void OnFrame();
	/* 4321D0 */ void OnOutsideFrustumCull();
	/* 4321E0 */ void OnInsideFrustumCull();
	/* 432400 */ uchar OnLoadChunk(uint param_1, int param_2, uint param_3, void* param_4);
	/* 432430 */ uchar Save(int* param_1);
	/* 432500 */ uchar Load(void* param_1, uint param_2, int param_3, int param_4);
};

#endif