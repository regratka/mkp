#ifndef _C_PARTICLE_EVENT__VELOCITY
#define _C_PARTICLE_EVENT__VELOCITY

#include <globals.h>
#include <d3dx8math.h>

#include "CParticleEmitterToken.h"
#include "CParticle.h"
#include "CMinMax.h"

class CParticleEvent_Velocity {
public:
	/* 1001E920 */ CMinMax<D3DXVECTOR3> GetVelocity(uint* param_1);
	/* 1001E950 */ void SetVelocity(CMinMax<D3DXVECTOR3>* param_1);
	/* 1001E970 */ CParticleEvent_Velocity();
	/* 1001E9D0 */ CParticleEvent_Velocity(CParticleEvent_Velocity* param_1);
	/* 1001EB10 */ CParticleEvent_Velocity* operator=(CParticleEvent_Velocity* param_1);
	/* 1001EC30 */ ~CParticleEvent_Velocity();
	/* 1001EC90 */ CParticleEvent_Velocity* scalar_destructor(uchar param_1);
	/* 1006B6D0 */ bool ProcessTokenStream(CParticleEmitterToken** param_1, CParticleEmitterToken** param_2);
	/* 1006C150 */ void DoItToIt(CParticle* param_1);
};

#endif