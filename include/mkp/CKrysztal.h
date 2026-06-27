#ifndef _C_KRYSZTAL
#define _C_KRYSZTAL

#include <globals.h>

#include "_PowerUp.h"

struct CKrysztalSaveData{
	/* 0x00 */ BOOL unk_00;
	/* 0x04 */ BOOL unk_04;
	/* 0x08 */ int unk_08;
};

class CKrysztal : public _PowerUp {
public:
	/* 419BA0 */ void OnActivateLevel();
	/* 432DB0 */ CKrysztal();
	/* 432DF0 */ ~CKrysztal();
	/* 432E00 */ void* EXP();
	/* 432E60 */ void OnActivate();
	/* 432E70 */ void OnActivateInternal();
	/* 432F20 */ void FUN00432f20();
	/* 432F70 */ void OnCollisionObject(cMagMeshObject* param_1);
	/* 432FD0 */ void Save(std::ostream& param_1);
	/* 433090 */ void Load(std::ifstream& param_1, _ED_CHUNK param_2);

private:
	/* 0x2658 */ bool unk_2658;
	/* 0x2659 */ bool unk_2659;
};

STATIC_ASSERT(sizeof(CKrysztal) == 0x2660);

#endif