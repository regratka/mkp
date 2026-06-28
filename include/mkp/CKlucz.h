#ifndef _C_KLUCZ
#define _C_KLUCZ

#include <globals.h>

#include "_PowerUp.h"

struct CKluczSaveData{
	/* 0x00 */ BOOL unk_00;
	/* 0x04 */ BOOL unk_04;
	/* 0x08 */ int unk_08;
};

class CKlucz : public _PowerUp {
public:
	/* 419BA0 */ void OnActivateLevel();
	/* 432B30 */ CKlucz();
	/* 432B70 */ ~CKlucz();
	/* 432B80 */ void* EXP();
	/* 432BE0 */ void OnCollisionObject(cMagMeshObject* param_1);
	/* 432C40 */ void Load(std::ifstream& param_1, _ED_CHUNK param_2);
	/* 432E60 */ void OnActivate();
	/* 432E70 */ void Show();
	/* 432F20 */ void Hide();
	/* 432FD0 */ void Save(std::ostream& param_1);

private:
	/* 0x2658 */ bool unk_2658;
	/* 0x2659 */ bool unk_2659;
};

STATIC_ASSERT(sizeof(CKlucz) == 0x2660);

#endif