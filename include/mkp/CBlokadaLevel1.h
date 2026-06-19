#ifndef _C_BLOKADA_LEVEL1
#define _C_BLOKADA_LEVEL1

#include <globals.h>

#include "cMagMeshObject.h"

class CBlokadaLevel1 : public cMagMeshObject {
public:
	/* 4262D0 */ void OnLoadChunk(_ED_CHUNK param_1, std::ifstream& param_2);
	/* 4406C0 */ CBlokadaLevel1();
	/* 440700 */ ~CBlokadaLevel1();
	/* 440710 */ void* EXP();
	/* 440770 */ void OnActivateLevel();
	/* 4407D0 */ void OnCollisionObject(cMagMeshObject* param_1);
	/* 4408B0 */ void Save(std::ostream& param_1);
	/* 4414D0 */ void OnPlaySoundEnd(int param_1);
	/* 441920 */ void Load(std::ifstream& param_1, _ED_CHUNK param_2);

private:
	/* 0x2658 */ char unk_2658[200];
	/* 0x2720 */ int unk_2720;
};

STATIC_ASSERT(sizeof(CBlokadaLevel1) == 0x2728);

#endif