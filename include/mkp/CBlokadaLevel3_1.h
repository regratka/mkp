#ifndef _C_BLOKADA_LEVEL3_1
#define _C_BLOKADA_LEVEL3_1

#include <globals.h>

#include "CMagMeshObject.h"

struct CBlokadaLevel3_1SaveData{
	/* 0x00 */ int unk_00;
	/* 0x04 */ D3DXVECTOR3 unk_04;
};

class CBlokadaLevel3_1 : public cMagMeshObject {
public:
	/* 419BA0 */ void OnActivate();
	/* 4262D0 */ void OnLoadChunk(_ED_CHUNK param_1, std::ifstream& param_2);
	/* 4329E0 */ void OnActivateLevel();
	/* 440E10 */ CBlokadaLevel3_1();
	/* 440E50 */ ~CBlokadaLevel3_1();
	/* 440E60 */ void* EXP();
	/* 440EC0 */ void OnCollisionObject(cMagMeshObject* param_1);
	/* 4408B0 */ void Save(std::ostream& param_1);
	/* 4414D0 */ void OnPlaySoundEnd(int param_1);
	/* 441920 */ void Load(std::ifstream& param_1, _ED_CHUNK param_2);

private:
	/* 0x2658 */ char unk_2658[200];
	/* 0x2720 */ int unk_2720;
};

STATIC_ASSERT(sizeof(CBlokadaLevel3_1) == 0x2728);

#endif