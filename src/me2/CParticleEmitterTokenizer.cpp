#include "CParticleEmitterTokenizer.h"

BLENDINGMODE const CParticleEmitterTokenizer::m_BlendingModes[11] = {
	{"D3DBLEND_ZERO",1},
	{"D3DBLEND_ONE",2},
	{"D3DBLEND_SRCCOLOR",3},
	{"D3DBLEND_INVSRCCOLOR",4},
	{"D3DBLEND_SRCALPHA",5},
	{"D3DBLEND_INVSRCALPHA",6},
	{"D3DBLEND_DESTALPHA",7},
	{"D3DBLEND_INVDESTALPHA",8},
	{"D3DBLEND_DESTCOLOR",9},
	{"D3DBLEND_INVDESTCOLOR",10},
	{"D3DBLEND_SRCALPHASAT",11}
};

/* 10068A90-10068CC5 00235	*/
bool CParticleEmitterTokenizer::ProcessNumber(CMinMax<float>& param_1, CParticleEmitterToken*& param_2, CParticleEmitterToken*& param_3) {
	if (param_2->unk_d5c != REAL_NUMBER) {
		if (param_2->unk_d5c != KEYWORD_RANDOM) {
			throw "Expecting either Random(...) or a number value.";
		}

		NextToken(param_2, param_3);
		if (param_2->unk_d5c != OPEN_PAREN) {
			throw "Expecting opening paren after Random keyword.";
		}

		NextToken(param_2, param_3);
		if (param_2->unk_d5c != REAL_NUMBER) {
			throw "Expecting first number within Random(...).";
		}
		
		param_1.min = atof(param_2->unk_d4c.c_str());

		NextToken(param_2, param_3);
		if (param_2->unk_d5c != COMMA) {
			throw "Expecting comma within Random(...).";
		}

		NextToken(param_2, param_3);
		if (param_2->unk_d5c != REAL_NUMBER) {
			throw "Expecting second number within Random(...).";
		}

		param_1.max = atof(param_2->unk_d4c.c_str());

		NextToken(param_2, param_3);
		if (param_2->unk_d5c != CLOSE_PAREN) {
			throw "Missing close paren on Random(...).";
		}
		NextToken(param_2, param_3);

	} else {
		float fVar7 = atof(param_2->unk_d4c.c_str());
		param_1.min = fVar7;
		param_1.max = fVar7;
		NextToken(param_2, param_3);
	}
	return true;
}

/* 10068CD0-10068F28 00258	*/
bool CParticleEmitterTokenizer::ProcessVector(CMinMax<D3DXVECTOR3>& param_1, CParticleEmitterToken*& param_2, CParticleEmitterToken*& param_3) {
	if (param_2->unk_d5c != KEYWORD_XYZ) {
		throw "Expecting XYZ(...)!";
	}

	NextToken(param_2, param_3);
	if (param_2->unk_d5c != OPEN_PAREN) {
		throw "Expecting ( after XYZ!";
	}
	
	CMinMax<float> local_30(0.0f,0.0f);
	CMinMax<float> local_28(0.0f,0.0f);
	CMinMax<float> local_20(0.0f,0.0f);

	NextToken(param_2, param_3);
	ProcessNumber(local_30, param_2, param_3);
	if (param_2->unk_d5c != COMMA) {
		throw "Vector components must be seperated by a comma.";
	}

	NextToken(param_2, param_3);
	ProcessNumber(local_28, param_2, param_3);
	if (param_2->unk_d5c != COMMA) {
		throw "Vector components must be seperated by a comma.";
	}

	NextToken(param_2, param_3);
	ProcessNumber(local_20, param_2, param_3);
	if (param_2->unk_d5c != CLOSE_PAREN) {
		throw "Expecting ) to close vector.";
	}

	NextToken(param_2, param_3);

	param_1.min = D3DXVECTOR3(local_30.min, local_28.min, local_20.min);
	param_1.max = D3DXVECTOR3(local_30.max, local_28.max, local_20.max);
	return true;
}

/* 10068F30-1006920E 002DE	*/
bool CParticleEmitterTokenizer::ProcessColor(CMinMax<D3DXCOLOR>& param_1, CParticleEmitterToken*& param_2, CParticleEmitterToken*& param_3) {
	if (param_2->unk_d5c != KEYWORD_COLOR) {
		throw "Expecting RGBA(...)!";
	}

	NextToken(param_2, param_3);
	if (param_2->unk_d5c != OPEN_PAREN) {
		throw "Expecting ( after RGBA!";
	}

	CMinMax<float> local_3c(0,0);
	CMinMax<float> local_34(0,0);
	CMinMax<float> local_2c(0,0);
	CMinMax<float> local_24(0,0);


	NextToken(param_2, param_3);
	ProcessNumber(local_3c, param_2, param_3);
	if (param_2->unk_d5c != COMMA) {
		throw "Color components must be seperated by a comma.";
	}

	NextToken(param_2, param_3);
	ProcessNumber(local_34, param_2, param_3);
	if (param_2->unk_d5c != COMMA) {
		throw "Color components must be seperated by a comma.";
	}

	NextToken(param_2, param_3);
	ProcessNumber(local_2c, param_2, param_3);
	if (param_2->unk_d5c != COMMA) {
		throw "Color components must be seperated by a comma.";
	}

	NextToken(param_2, param_3);
	ProcessNumber(local_24, param_2, param_3);
	if (param_2->unk_d5c != CLOSE_PAREN) {
		throw "Expecting ) to close vector.";
	}

	NextToken(param_2, param_3);

	param_1.min = D3DXCOLOR(local_3c.min, local_34.min, local_2c.min, local_24.min);
	param_1.max = D3DXCOLOR(local_3c.max, local_34.max, local_2c.max, local_24.max);

	return true;
}

/* 10069210-10069388 00178	*/
bool CParticleEmitterTokenizer::ProcessAlphaBlendMode(int& param_1, CParticleEmitterToken*& param_2, CParticleEmitterToken*& param_3) {
	if (param_2->unk_d5c != ALPHA_BLEND_MODE) {
		throw "Expecting alpha blend mode (D3DBLEND_ZERO, D3DBLEND_ONE, etc.).";
	}

	for (int index = 0; index < 11; index++) {
		if (param_2->unk_d4c.find(m_BlendingModes[index].modeName) == std::string::npos) {
			continue;
		}
		if (param_2->unk_d4c.length() == strlen(m_BlendingModes[index].modeName)) {
			param_1 = m_BlendingModes[index].blendMode;
			NextToken(param_2, param_3);
			return true;
		}
	}

	throw "Invalid alpha blending mode!";
}

/* 10069390-10069509 00179	*/
bool CParticleEmitterTokenizer::ProcessTime(CMinMax<float>& param_1, bool& param_2, float param_3, float param_4, CParticleEmitterToken*& param_5, CParticleEmitterToken*& param_6) {
	if (param_5->unk_d5c == KEYWORD_FADE) {
		NextToken(param_5, param_6);
		
		if (param_5->unk_d5c != KEYWORD_SO) {
			throw "Expecting \"so\" after \"fade\".";
		}
		param_2 = true;
		
		NextToken(param_5, param_6);
	} else {
		param_2 = false;
	}

	switch (param_5->unk_d5c) {
		case KEYWORD_AT:
			NextToken(param_5, param_6);
			ProcessNumber(param_1, param_5, param_6);
			break;
		case KEYWORD_INITIAL:
			if (param_2) {
				throw "Cannot use \"fade so\" modifier on \"initial\" times.";
			}
			param_1.min = param_3;
			param_1.max = param_3;
			NextToken(param_5, param_6);
			break;
		case KEYWORD_FINAL:
			param_1.min = param_4;
			param_1.max = param_4;
			NextToken(param_5, param_6);
			break;
		default:
			throw "Expected time specifier: \"[fade so] at\", \"initial\", or \"[fade so] final\"";
	}

	return true;
}

/* 10069510-1006A2DB 00DCB	*/
void CParticleEmitterTokenizer::DetermineTokenType(CParticleEmitterToken& param_1) {
	param_1.unk_d5c = UNDEFINED;
}

/* 1006A2E0-1006A38D 000AD	*/
void CParticleEmitterTokenizer::AddToken(CParticleEmitterToken param_1) {
	if (!param_1.unk_d4c.empty()) {
		DetermineTokenType(param_1);
		unk_d60.push_back(param_1);
	}
}

/* 1006A390-1006A8B8 00528	*/
void CParticleEmitterTokenizer::Tokenize(const char* param_1) {
	std::string local_d84;
	CParticleEmitterToken local_d6c;
	if (param_1[0] == '\0') {
		AddToken(local_d6c);
		return;
	}


}

