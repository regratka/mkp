#ifndef _C_PARTICLE_EVENT__VELOCITY_X
#define _C_PARTICLE_EVENT__VELOCITY_X

#include <globals.h>

class CParticleEvent_VelocityX {
public:
	/* 1001ED20 */ CParticleEvent_VelocityX();
	/* 1001ED60 */ CParticleEvent_VelocityX(CParticleEvent_VelocityX* param_1);
	/* 1001EEA0 */ ~CParticleEvent_VelocityX();
	/* 1001EF00 */ CParticleEvent_VelocityX* scalar_destructor(uchar param_1);
	/* 1006B7C0 */ bool ProcessTokenStream(CParticleEmitterToken** param_1, CParticleEmitterToken** param_2);
	/* 1006C2C0 */ void DoItToIt(CParticle* param_1);
};

#endif