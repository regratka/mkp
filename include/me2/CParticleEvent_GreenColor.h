#ifndef _C_PARTICLE_EVENT__GREEN_COLOR
#define _C_PARTICLE_EVENT__GREEN_COLOR

#include <globals.h>

#include "CParticleEmitterToken.h"
#include "CParticle.h"


class CParticleEvent_GreenColor {
public:
	/* 1001E120 */ CParticleEvent_GreenColor();
	/* 1001E160 */ CParticleEvent_GreenColor(CParticleEvent_GreenColor* param_1);
	/* 1001E2A0 */ ~CParticleEvent_GreenColor();
	/* 1001E300 */ CParticleEvent_GreenColor* scalar_destructor(uchar param_1);
	/* 1006B400 */ bool ProcessTokenStream(CParticleEmitterToken** param_1, CParticleEmitterToken** param_2);
	/* 1006BF10 */ void DoItToIt(CParticle* param_1);
};

#endif