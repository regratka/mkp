#ifndef _C_PARTICLE_EMITTER
#define _C_PARTICLE_EMITTER

#include <globals.h>
#include <d3dx8math.h>
#include <string>

#include "CParticleEmitterTokenizer.h"
#include "CParticleEventSequence.h"
#include "CParticleEvent.h"
#include "CParticle.h"
#include "CMinMax.h"

struct TIMER_COMMAND {
	
};

class CParticleEmitter : public CParticleEmitterTokenizer {
public:
	/* 10020570 */ void Pause();
	/* 10020580 */ void Stop();
	/* 100205E0 */ bool IsRunning();
	/* 100205F0 */ void DeleteAllParticles();
	/* 10020650 */ CMinMax<D3DXVECTOR3> GetPosRange(uint* param_1);
	/* 10020680 */ void SetPosRange(CMinMax<D3DXVECTOR3>* param_1);
	/* 100206A0 */ int GetVBSize();
	/* 100206B0 */ void SetVBSize(int param_1);
	/* 100206C0 */ void Reset();
	/* 100206F0 */ int GetNumActiveParticles();
	/* 10020730 */ void EnableRender(bool param_1);
	/* 10020740 */ CParticleEmitter(CParticleEmitter* param_1);
	/* 10020C90 */ CParticleEmitter* operator=(CParticleEmitter* param_1);
	/* 100212F0 */ CParticleEmitter* scalar_destructor(uchar param_1);
	/* 100687D0 */ bool TestDistance(float param_1);
	/* 1006EEE0 */ CParticleEmitter();
	/* 1006F590 */ void Init();
	/* 1006F6E0 */ ~CParticleEmitter();
	/* 1006F880 */ CParticleEvent* EventFactory(uint param_1);
	/* 1006FDD0 */ bool ProcessEventSequenceBlock(CParticleEventSequence* param_1, CParticleEmitterToken** param_2, CParticleEmitterToken** param_3);
	/* 10070F10 */ bool ProcessParticleSystemBlock(CParticleEmitterToken** param_1, CParticleEmitterToken** param_2);
	/* 10071320 */ bool Compile(char* param_1);
	/* 10071700 */ long RestoreDeviceObjects(IDirect3DDevice8* param_1);
	/* 10071750 */ void InvalidateDeviceObjects();
	/* 100717A0 */ void Update(float param_1, float param_2);
	/* 10071850 */ void SetDirection(uint param_1, uint param_2, uint param_3);
	/* 10071870 */ long Render();
	/* 10071930 */ void Restore();
	/* 10071960 */ void OnUpdate_();
	/* 100719D0 */ void EnableZBuffeWrite(bool param_1);
	/* 100719E0 */ bool EnableZBuffeWrite();
	/* 100719F0 */ void OnRender();
	/* 10071AA0 */ void Hide();
	/* 10071AC0 */ void Show();
	/* 10071AE0 */ void Start();
	/* 10071B00 */ void SetLoop(int param_1);
	/* 10071B40 */ int GetLoop();
	/* 10071B50 */ void Pause(bool param_1);
	/* 10071B80 */ void SetPosition(uint param_1, uint param_2, uint param_3);
	/* 10071BA0 */ uchar GetPosition(uint* param_1);
	/* 10071BD0 */ bool LoadFileIntoString(char* param_1, std::string* param_2);
	/* 10071E00 */ void InitAnimFrames(char* param_1);
	/* 10071EB0 */ float DXUtil_Timer(TIMER_COMMAND param_1);

private:
	/* 0xd70 */ uchar field_0xd70[0x11f8-0xd70];
};

STATIC_ASSERT(sizeof(CParticleEmitter) == 0x11f8)

#endif