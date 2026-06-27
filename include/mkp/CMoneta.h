#ifndef _C_MONETA
#define _C_MONETA

#include <globals.h>

#include "_PowerUp.h"

struct CMonetaSaveData{
	/* 0x00 */ BOOL unk_00;
	/* 0x04 */ BOOL unk_04;
};

class CMoneta : public _PowerUp {
public:
	/* 419BA0 */ void OnActivateLevel();
	/* 432E60 */ void OnActivate();
	/* 432E70 */ void Show();
	/* 432F20 */ void Hide();
	/* 4331C0 */ CMoneta();
	/* 433200 */ ~CMoneta();
	/* 433210 */ void* EXP();
	/* 433270 */ void OnCollisionObject(cMagMeshObject* param_1);
	/* 4332E0 */ void Save(std::ostream& param_1);
	/* 433390 */ void Load(std::ifstream& param_1, _ED_CHUNK param_2);

private:
	/* 0x2658 */ bool unk_2658;
	/* 0x2659 */ bool unk_2659;
};

STATIC_ASSERT(sizeof(CMoneta) == 0x2660);

#endif