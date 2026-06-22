#ifndef _C_BLOKADA_LEVEL6
#define _C_BLOKADA_LEVEL6

#include <globals.h>

#include "cMagMeshObject.h"
#include "CHudGratka.h"

struct CBlokadaLevel6SaveData{
	/* 0x00 */ int unk_00;
	/* 0x04 */ D3DXVECTOR3 unk_04;
};


class CBlokadaLevel6 : public cMagMeshObject {
public:
	/* 419BA0 */ void OnActivate();
	/* 4262D0 */ void OnLoadChunk(_ED_CHUNK param_1, std::ifstream& param_2);
	/* 4408B0 */ void Save(std::ostream& param_1);
	/* 4417A0 */ CBlokadaLevel6();
	/* 4417F0 */ ~CBlokadaLevel6();
	/* 441800 */ void* EXP();
	/* 441860 */ void OnActivateLevel();
	/* 441890 */ void OnCollisionObject(cMagMeshObject* param_1);
	/* 441900 */ void OnPlaySoundEnd(int param_1);
	/* 441920 */ void Load(std::ifstream& param_1, _ED_CHUNK param_2);

private:
	/* 0x2658 */ char unk_2658[200];
	/* 0x2720 */ int unk_2720;
	/* 0x2724 */ CHudGratka* hud;
};

STATIC_ASSERT(sizeof(CBlokadaLevel6) == 0x2728);

#endif