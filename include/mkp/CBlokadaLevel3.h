#ifndef _C_BLOKADA_LEVEL3
#define _C_BLOKADA_LEVEL3

#include <globals.h>
#include "cMagMeshObject.h"

struct CBlokadaLevel3SaveData{
	/* 0x00 */ int unk_00;
	/* 0x04 */ D3DXVECTOR3 unk_04;
};

class CBlokadaLevel3 : public cMagMeshObject {
public:
	/* 419BA0 */ void OnActivate();
	/* 4262D0 */ void OnLoadChunk(_ED_CHUNK param_1, std::ifstream& param_2);
	/* 4408B0 */ void Save(std::ostream& param_1);
	/* 440A30 */ CBlokadaLevel3();
	/* 440A80 */ ~CBlokadaLevel3();
	/* 440A90 */ void* EXP();
	/* 440AF0 */ void OnActivateLevel();
	/* 440B70 */ void OnCollisionObject(cMagMeshObject* param_1);
	/* 440CA0 */ void OnPlaySoundEnd(int param_1);
	/* 440CE0 */ void Load(std::ifstream& param_1, _ED_CHUNK param_2);

private:
	/* 0x2658 */ char unk_2658[200];
	/* 0x2720 */ cMagMeshObject* unk_2720;
	/* 0x2724 */ int unk_2724;
};

STATIC_ASSERT(sizeof(CBlokadaLevel3) == 0x2728);

#endif