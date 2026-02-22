#ifndef _C_PARTICLE_EVENT
#define _C_PARTICLE_EVENT

#include <globals.h>
#include <d3dx8math.h>

#include "CParticleEmitterToken.h"
#include "CParticle.h"
#include "CParticleEvent.h"
#include "CMinMax.h"

class CParticleEvent {
public:
	/* 1000F000 */ void InvalidateDeviceObjects();
	/* 10012BA0 */ void RestoreDeviceObjects(uchar param_1);
	/* 1001D4C0 */ CParticleEvent();
	/* 1001D4F0 */ ~CParticleEvent();
	/* 1001D550 */ CMinMax<float>* GetTimeRange();
	/* 1001D580 */ void SetTimeRange(uint param_1, uint param_2);
	/* 1001D5A0 */ float GetActualTime();
	/* 1001D5B0 */ void SetActualTime(float param_1);
	/* 1001D5C0 */ bool IsFade();
	/* 1001D5D0 */ void SetFade(bool param_1);
	/* 1001D5E0 */ CParticleEvent(CParticleEvent* param_1);
	/* 1001D700 */ CParticleEvent* operator=(CParticleEvent* param_1);
	/* 1001D810 */ CParticleEvent* scalar_destructor(uchar param_1);
	/* 1006AFB0 */ static void ProcessPropEqualsValue(CMinMax<float>* param_1, CParticleEmitterToken** param_2, CParticleEmitterToken** param_3);
	/* 1006B030 */ static void ProcessPropEqualsValue(CMinMax<D3DXVECTOR3>* param_1, CParticleEmitterToken** param_2, CParticleEmitterToken** param_3);
	/* 1006B0B0 */ static void ProcessPropEqualsValue(CMinMax<D3DXCOLOR>* param_1, CParticleEmitterToken** param_2, CParticleEmitterToken** param_3);
};

#endif