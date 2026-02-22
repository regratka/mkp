#ifndef _C_PARTICLE_EVENT__RED_COLOR
#define _C_PARTICLE_EVENT__RED_COLOR

#include <globals.h>

class CParticleEvent_RedColor {
public:
	/* 1001DEE0 */ CParticleEvent_RedColor();
	/* 1001DF20 */ CParticleEvent_RedColor(CParticleEvent_RedColor* param_1);
	/* 1001E060 */ ~CParticleEvent_RedColor();
	/* 1001E0C0 */ CParticleEvent_RedColor* scalar_destructor(uchar param_1);
	/* 1006B310 */ bool ProcessTokenStream(CParticleEmitterToken** param_1, CParticleEmitterToken** param_2);
	/* 1006BE50 */ void DoItToIt(CParticle* param_1);
};

#endif