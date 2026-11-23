#ifndef _C_PARTICLE_EMITTER_TOKENIZER
#define _C_PARTICLE_EMITTER_TOKENIZER

#include <globals.h>

#include "CMinMax.h"
#include "CParticleEmitterToken.h"

class DLLEXPORT CParticleEmitterTokenizer : public CParticleEmitterToken {
public:
	/* 1001CE20-1001CE4D 0002D	*/
	static void NextToken(CParticleEmitterToken*& param_1, CParticleEmitterToken*& param_2) {
		if (param_1 == param_2) {
			throw "Unexpected end-of-file.";
		}
		param_1++;
	}

	/* 10068A90 */ static bool ProcessNumber(CMinMax<float>& param_1, CParticleEmitterToken*& param_2, CParticleEmitterToken*& param_3);
	/* 10068CD0 */ static bool ProcessVector(CMinMax<D3DXVECTOR3>& param_1, CParticleEmitterToken*& param_2, CParticleEmitterToken*& param_3);
	/* 10068F30 */ static bool ProcessColor(CMinMax<D3DXCOLOR>& param_1, CParticleEmitterToken*& param_2, CParticleEmitterToken*& param_3);
	/* 10069210 */ static bool ProcessAlphaBlendMode(int& param_1, CParticleEmitterToken*& param_2, CParticleEmitterToken*& param_3);
	/* 10069390 */ static bool ProcessTime(CMinMax<float>& param_1, bool& param_2, float param_3, float param_4, CParticleEmitterToken*& param_5, CParticleEmitterToken*& param_6);
private:
	/* 10069510 */ void DetermineTokenType(CParticleEmitterToken& param_1);
	/* 1006A2E0 */ void AddToken(CParticleEmitterToken param_1);
public:
	/* 1006A390 */ void Tokenize(const char* param_1);

private:
	/* 0xd60 */ std::vector<CParticleEmitterToken> unk_d60;
};

STATIC_ASSERT(sizeof(CParticleEmitterTokenizer) == 0xd70);

#endif