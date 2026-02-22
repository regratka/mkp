#ifndef _C_PARTICLE_EVENT__EVENT_TIMER
#define _C_PARTICLE_EVENT__EVENT_TIMER

#include <globals.h>

class CParticleEvent_EventTimer {
public:
	/* 1001F3E0 */ bool FadeAllowed();
	/* 1001F3F0 */ void SetEventTimer(CMinMax<float>* param_1);
	/* 1001F410 */ CParticleEvent_EventTimer();
	/* 1001F450 */ CParticleEvent_EventTimer(CParticleEvent_EventTimer* param_1);
	/* 1001F590 */ ~CParticleEvent_EventTimer();
	/* 1001F5F0 */ CParticleEvent_EventTimer* scalar_destructor(uchar param_1);
	/* 1006BA90 */ bool ProcessTokenStream(CParticleEmitterToken** param_1, CParticleEmitterToken** param_2);
	/* 1006C500 */ void DoItToIt(CParticle* param_1);
};

#endif