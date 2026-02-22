#ifndef _C_PARTICLE_EVENT__BLUE_COLOR
#define _C_PARTICLE_EVENT__BLUE_COLOR

#include <globals.h>

#include "CParticleEmitterToken.h"
#include "CParticle.h"
#include "CMinMax.h"

class CParticleEvent_BlueColor {
public:
	/* 1001E360 */ CParticleEvent_BlueColor();
	/* 1001E3A0 */ CParticleEvent_BlueColor(CParticleEvent_BlueColor* param_1);
	/* 1001E600 */ ~CParticleEvent_BlueColor();
	/* 1001E660 */ CParticleEvent_BlueColor* scalar_destructor(uchar param_1);
	/* 1006B4F0 */ bool ProcessTokenStream(CParticleEmitterToken** param_1, CParticleEmitterToken** param_2);
	/* 1006BFD0 */ void DoItToIt(CParticle* param_1);
};

#endif