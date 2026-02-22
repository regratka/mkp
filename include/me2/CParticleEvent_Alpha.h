#ifndef _C_PARTICLE_EVENT__ALPHA
#define _C_PARTICLE_EVENT__ALPHA

#include <globals.h>

#include "CParticleEmitterToken.h"
#include "CParticle.h"
#include "CMinMax.h"

class CParticleEvent_Alpha {
public:
	/* 1001D8B0 */ bool FadeAllowed();
	/* 1001E4E0 */ CParticleEvent_Alpha* operator=(CParticleEvent_Alpha* param_1);
	/* 1001E6C0 */ void SetAlpha(uint param_1, uint param_2);
	/* 1001E6E0 */ CParticleEvent_Alpha();
	/* 1001E720 */ CParticleEvent_Alpha(CParticleEvent_Alpha* param_1);
	/* 1001E860 */ ~CParticleEvent_Alpha();
	/* 1001E8C0 */ CParticleEvent_Alpha* scalar_destructor(uchar param_1);
	/* 1001ECF0 */ CMinMax<float> GetAlpha();
	/* 1006B5E0 */ bool ProcessTokenStream(CParticleEmitterToken** param_1, CParticleEmitterToken** param_2);
	/* 1006C090 */ void DoItToIt(CParticle* param_1);
};

#endif