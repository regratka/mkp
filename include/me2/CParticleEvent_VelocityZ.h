#ifndef _C_PARTICLE_EVENT__VELOCITY_Z
#define _C_PARTICLE_EVENT__VELOCITY_Z

#include <globals.h>

#include "CParticleEmitterToken.h"
#include "CParticle.h"

class CParticleEvent_VelocityZ {
public:
	/* 1001F1A0 */ CParticleEvent_VelocityZ();
	/* 1001F1E0 */ CParticleEvent_VelocityZ(CParticleEvent_VelocityZ* param_1);
	/* 1001F320 */ ~CParticleEvent_VelocityZ();
	/* 1001F380 */ CParticleEvent_VelocityZ* scalar_destructor(uchar param_1);
	/* 1006B9A0 */ bool ProcessTokenStream(CParticleEmitterToken** param_1, CParticleEmitterToken** param_2);
	/* 1006C440 */ void DoItToIt(CParticle* param_1);
};

#endif