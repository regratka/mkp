#ifndef _C_PARTICLE
#define _C_PARTICLE

#include <globals.h>

class CParticle {
public:
	/* 1001AC90 */ CParticle();
	/* 1001ADA0 */ ~CParticle();
	/* 1001AE00 */ uchar GetPosition(uint* param_1);
	/* 1001AE30 */ void SetPosition(float param_1, float param_2, float param_3);
	/* 1001AE70 */ bool Update(float param_1);
	/* 1001AFE0 */ CParticle(CParticle* param_1);
	/* 1001B1F0 */ CParticle* operator=(CParticle* param_1);
	/* 1001B3F0 */ CParticle* scalar_destructor(uchar param_1);
};

#endif