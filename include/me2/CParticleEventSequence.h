#ifndef _C_PARTICLE_EVENT_SEQUENCE
#define _C_PARTICLE_EVENT_SEQUENCE

#include <globals.h>

class CParticleEventSequence {
public:
	/* 1000FFA0 */ void SetLoops(int param_1);
	/* 1000FFB0 */ void SetLoop(int param_1);
	/* 1001F650 */ CMinMax<float> GetLifetime(uint* param_1);
	/* 1001F680 */ void SetLifetime(uint param_1, uint param_2);
	/* 1001F6A0 */ int GetSrcBlendMode();
	/* 1001F6B0 */ void SetSrcBlendMode(int param_1);
	/* 1001F6C0 */ int GetDestBlendMode();
	/* 1001F6D0 */ void SetDestBlendMode(int param_1);
	/* 1001F6E0 */ CMinMax<float> GetEmitRate(uint* param_1);
	/* 1001F710 */ void SetEmitRate(uint param_1, uint param_2);
	/* 1001F730 */ CMinMax<struct_D3DXVECTOR3> GetEmitRadius(uint* param_1);
	/* 1001F760 */ void SetEmitRadius(CMinMax<struct_D3DXVECTOR3>* param_1);
	/* 1001F780 */ CMinMax<struct_D3DXVECTOR3> GetGravity(uint* param_1);
	/* 1001F7B0 */ void SetGravity(CMinMax<struct_D3DXVECTOR3>* param_1);
	/* 1001F7D0 */ CParticleEventSequence* GetName(CParticleEventSequence* param_1);
	/* 1001F900 */ void SetName(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>* param_1);
	/* 1001FA40 */ int GetNumActiveParticles();
	/* 1001FA60 */ int GetNumParticles();
	/* 1001FA70 */ void SetNumParticles(int param_1);
	/* 1001FA80 */ int GetLoops();
	/* 1001FA90 */ int GetLoop();
	/* 1001FAA0 */ void SetAnimFrames(int param_1);
	/* 1001FAC0 */ int GetAnimFrames();
	/* 1001FAD0 */ void SetFrameWidth(int param_1);
	/* 1001FAE0 */ int GetFrameWidth();
	/* 1001FAF0 */ void SetFrameHeight(int param_1);
	/* 1001FB00 */ int GetFrameHeight();
	/* 1001FB10 */ void SetFramesPerLine(int param_1);
	/* 1001FB20 */ int GetFramesPerLine();
	/* 1001FB30 */ void SetAnimDelay(uint param_1, uint param_2);
	/* 1001FB50 */ void GetAnimDelay();
	/* 1001FB80 */ bool IsEnableAnim();
	/* 1001FB90 */ CMinMax<struct_D3DXVECTOR3> GetSpawnDir(uint* param_1);
	/* 1001FBC0 */ void SetSpawnDir(CMinMax<struct_D3DXVECTOR3>* param_1);
	/* 1001FBE0 */ CParticleEventSequence* GetTextureFilename(CParticleEventSequence* param_1);
	/* 1001FD10 */ uchar GetTexture();
	/* 1001FD20 */ void DeleteAllParticles();
	/* 1001FD60 */ CParticleEventSequence(CParticleEventSequence* param_1);
	/* 10020100 */ CParticleEventSequence* operator=(CParticleEventSequence* param_1);
	/* 10020510 */ CParticleEventSequence* scalar_destructor(uchar param_1);
	/* 1006C5E0 */ CParticleEventSequence();
	/* 1006C7C0 */ ~CParticleEventSequence();
	/* 1006C8B0 */ void Reset();
	/* 1006CA10 */ void SortEvents();
	/* 1006CC60 */ void CreateFadeLists();
	/* 1006CCE0 */ void NailDownRandomTimes();
	/* 1006CD60 */ long RestoreDeviceObjects(IDirect3DDevice8* param_1);
	/* 1006CEE0 */ void SetTexture(char* param_1);
	/* 1006CFC0 */ void Restore();
	/* 1006D130 */ void CreateNewParticle(float param_1, float param_2, float param_3);
	/* 1006D270 */ void RunEvents(CParticle* param_1);
	/* 1006D310 */ void Update(uint param_1, float param_2, float param_3, float param_4, float param_5, float param_6, float param_7, float param_8);
	/* 1006D790 */ void SetPosition(uint param_1, uint param_2, uint param_3);
	/* 1006D7F0 */ void Render();
};

#endif