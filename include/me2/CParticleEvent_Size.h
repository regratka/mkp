#ifndef _C_PARTICLE_EVENT__SIZE
#define _C_PARTICLE_EVENT__SIZE

#include <globals.h>

#include "CParticleEmitterToken.h"
#include "CParticle.h"

class CParticleEvent_Size {
public:
	/* 1001D8C0 */ CParticleEvent_Size();
	/* 1001D900 */ CParticleEvent_Size(CParticleEvent_Size* param_1);
	/* 1001DA40 */ ~CParticleEvent_Size();
	/* 1001DAA0 */ CParticleEvent_Size* scalar_destructor(uchar param_1);
	/* 1006B130 */ bool ProcessTokenStream(CParticleEmitterToken** param_1, CParticleEmitterToken** param_2);
	/* 1006BB80 */ void DoItToIt(CParticle* param_1);
};

#endif