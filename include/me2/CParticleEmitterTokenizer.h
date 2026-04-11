#ifndef _C_PARTICLE_EMITTER_TOKENIZER
#define _C_PARTICLE_EMITTER_TOKENIZER

#include <globals.h>

#include "CMinMax.h"
#include "CParticleEmitterToken.h"

class CParticleEmitterTokenizer : public CParticleEmitterToken {
public:
	/* 1001CE20 */ static void NextToken(CParticleEmitterToken** param_1, CParticleEmitterToken** param_2);
	/* 1001CE50 */ CParticleEmitterTokenizer();
	/* 1001CEA0 */ CParticleEmitterTokenizer(CParticleEmitterTokenizer* param_1);
	/* 1001D0A0 */ CParticleEmitterTokenizer* operator=(CParticleEmitterTokenizer* param_1);
	/* 1001D390 */ ~CParticleEmitterTokenizer();
	/* 1001D460 */ CParticleEmitterTokenizer* scalar_destructor(uchar param_1);
	/* 10068A90 */ static bool ProcessNumber(CMinMax<float>* param_1, CParticleEmitterToken** param_2, CParticleEmitterToken** param_3);
	/* 10068CD0 */ static bool ProcessVector(CMinMax<D3DXVECTOR3>* param_1, CParticleEmitterToken** param_2, CParticleEmitterToken** param_3);
	/* 10068F30 */ static bool ProcessColor(CMinMax<D3DXCOLOR>* param_1, CParticleEmitterToken** param_2, CParticleEmitterToken** param_3);
	/* 10069210 */ static bool ProcessAlphaBlendMode(int* param_1, CParticleEmitterToken** param_2, CParticleEmitterToken** param_3);
	/* 10069390 */ static bool ProcessTime(CMinMax<float>* param_1, bool* param_2, float param_3, float param_4, CParticleEmitterToken** param_5, CParticleEmitterToken** param_6);
	/* 10069510 */ void DetermineTokenType(CParticleEmitterToken* param_1);
	/* 1006A2E0 */ void AddToken();
	/* 1006A390 */ void Tokenize(char* param_1);

private:
	/* 0xd60 */ uchar field_0xd60[0xd70-0xd60];
};

STATIC_ASSERT(sizeof(CParticleEmitterTokenizer) == 0xd70);

#endif