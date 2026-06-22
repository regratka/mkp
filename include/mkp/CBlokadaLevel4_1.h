#ifndef _C_BLOKADA_LEVEL4_1
#define _C_BLOKADA_LEVEL4_1

#include <globals.h>

#include "cMagMeshObject.h"

struct CBlokadaLevel4_1SaveData{
	/* 0x00 */ int unk_00;
	/* 0x04 */ D3DXVECTOR3 unk_04;
};


class CBlokadaLevel4_1 : public cMagMeshObject {
public:
	/* 419BA0 */ void OnActivate();
	/* 4262D0 */ void OnLoadChunk(_ED_CHUNK param_1, std::ifstream& param_2);
	/* 4329E0 */ void OnActivateLevel();
	/* 4408B0 */ void Save(std::ostream& param_1);
	/* 441390 */ CBlokadaLevel4_1();
	/* 4413D0 */ ~CBlokadaLevel4_1();
	/* 4413E0 */ void* EXP();
	/* 441440 */ void OnCollisionObject(cMagMeshObject* param_1);
	/* 4414D0 */ void OnPlaySoundEnd(int param_1);
	/* 441920 */ void Load(std::ifstream& param_1, _ED_CHUNK param_2);

private:
	/* 0x2658 */ char unk_2658[200];
	/* 0x2720 */ int unk_2720;
};

STATIC_ASSERT(sizeof(CBlokadaLevel4_1) == 0x2728);

#endif