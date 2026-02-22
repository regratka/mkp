#ifndef _C_PARTICLE_EVENT__VELOCITY_Y
#define _C_PARTICLE_EVENT__VELOCITY_Y

#include <globals.h>

#include "CParticleEmitterToken.h"
#include "CParticle.h"

class CParticleEvent_VelocityY {
public:
	/* 1001EF60 */ CParticleEvent_VelocityY();
	/* 1001EFA0 */ CParticleEvent_VelocityY(CParticleEvent_VelocityY* param_1);
	/* 1001F0E0 */ ~CParticleEvent_VelocityY();
	/* 1001F140 */ CParticleEvent_VelocityY* scalar_destructor(uchar param_1);
	/* 1006B8B0 */ bool ProcessTokenStream(CParticleEmitterToken** param_1, CParticleEmitterToken** param_2);
	/* 1006C380 */ void DoItToIt(CParticle* param_1);
};

#endif