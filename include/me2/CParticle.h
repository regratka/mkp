#ifndef _C_PARTICLE
#define _C_PARTICLE

#include <globals.h>
#include "cMagUtility.h"

class DLLEXPORT CParticle : public cMagUtility {
public:

	/* 1001AC90-1001AD9B 0010B	*/
	CParticle::CParticle() {
		unk_d50 = 1.0f;
		unk_d54 = 100.0f;
		unk_d58 = 0.0f;
		unk_d60 = 0.0f;
		unk_d64 = 0.0f;
		unk_d5c = 1.0f;
		unk_d68 = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		unk_d78 = D3DXVECTOR4(0.0f, 0.0f, 0.0f, 0.0f);
		unk_d94 = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		unk_da0 = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		position = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		unk_dac = 0.0f;
		unk_db0 = 0.0f;
		unk_db4 = 0.0f;
		unk_db8 = 30;
		unk_dbc = 0.0f;
	}

	/* 1001ADA0-1001ADFB 0005B	*/
	CParticle::~CParticle() {
		DebugLog("destruktor CParticle");
	}

	/* 1001AE00-1001AE21 00021	*/
	D3DXVECTOR3 CParticle::GetPosition() {
		return position;
	}

	/* 1001AE30-1001AE63 00033	*/
	void CParticle::SetPosition(D3DXVECTOR3 param_1) {
		position += param_1;
	}

	/* 1001AE70-1001AFDA 0016A	*/
	bool CParticle::Update(float param_1) {
		unk_d60 += param_1;
		unk_d64 += param_1;
		
		if (unk_d60 >= unk_d5c) {
			return false;
		}

		position += param_1 * unk_d94;
		unk_d68 += param_1 * unk_d78;
		unk_d94 += param_1 * unk_da0;
		unk_d54 += param_1 * unk_d58;
		return true;
	}

private:
	/* 0xd4c */ float unk_d4c;
	/* 0xd50 */ float unk_d50;
	/* 0xd54 */ float unk_d54;
	/* 0xd58 */ float unk_d58;
	/* 0xd5c */ float unk_d5c;
	/* 0xd60 */ float unk_d60;
	/* 0xd64 */ float unk_d64;
	/* 0xd68 */ D3DXVECTOR4 unk_d68;
	/* 0xd78 */ D3DXVECTOR4 unk_d78;
	/* 0xd88 */ D3DXVECTOR3 position;
	/* 0xd94 */ D3DXVECTOR3 unk_d94;
	/* 0xda0 */ D3DXVECTOR3 unk_da0;
	/* 0xdac */ float unk_dac;
	/* 0xdb0 */ float unk_db0;
	/* 0xdb4 */ float unk_db4;
	/* 0xdb8 */ int unk_db8;
	/* 0xdbc */ float unk_dbc;
};

STATIC_ASSERT(sizeof(CParticle) == 0xdc0);

#endif