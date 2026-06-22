#ifndef _C_BLOKADA_LEVEL4
#define _C_BLOKADA_LEVEL4

#include <globals.h>

#include "cMagMeshObject.h"

struct CBlokadaLevel4SaveData{
	/* 0x00 */ int unk_00;
	/* 0x04 */ D3DXVECTOR3 unk_04;
};

class CBlokadaLevel4 : public cMagMeshObject {
public:
	/* 4164E0 */ void OnInputKey(uchar* param_1);
	/* 419BA0 */ void OnActivate();
	/* 4262D0 */ void OnLoadChunk(_ED_CHUNK param_1, std::ifstream& param_2);
	/* 441000 */ CBlokadaLevel4();
	/* 441050 */ ~CBlokadaLevel4();
	/* 441060 */ void* EXP();
	/* 4410C0 */ void OnActivateLevel();
	/* 441170 */ void OnPlaySoundEnd(int param_1);
	/* 4411B0 */ void OnCollisionObject(cMagMeshObject* param_1);
	/* 4408B0 */ void Save(std::ostream& param_1);
	/* 441920 */ void Load(std::ifstream& param_1, _ED_CHUNK param_2);
private:
	/* 0x2658 */ char unk_2658[200];
	/* 0x2720 */ cMagMeshObject* unk_2720;
	/* 0x2724 */ D3DXVECTOR3 unk_2724;
	/* 0x2730 */ int unk_2730;
};

#endif