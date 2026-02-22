#ifndef _C_PARTICLE_EVENT__COLOR
#define _C_PARTICLE_EVENT__COLOR

#include <globals.h>

class CParticleEvent_Color {
public:
	/* 1001DB00 */ CMinMax<struct_D3DXCOLOR> GetColor(uint* param_1);
	/* 1001DB30 */ void SetColor(CMinMax<struct_D3DXCOLOR>* param_1);
	/* 1001DB50 */ CParticleEvent_Color();
	/* 1001DBC0 */ CParticleEvent_Color(CParticleEvent_Color* param_1);
	/* 1001DD00 */ CParticleEvent_Color* operator=(CParticleEvent_Color* param_1);
	/* 1001DE20 */ ~CParticleEvent_Color();
	/* 1001DE80 */ CParticleEvent_Color* scalar_destructor(uchar param_1);
	/* 1006B220 */ bool ProcessTokenStream(CParticleEmitterToken** param_1, CParticleEmitterToken** param_2);
	/* 1006BC40 */ void DoItToIt(CParticle* param_1);
};

#endif