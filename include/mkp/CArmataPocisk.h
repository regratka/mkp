#ifndef _C_ARMATA_POCISK
#define _C_ARMATA_POCISK

#include <globals.h>

#include "cMagMeshObject.h"

class CArmataPocisk : public cMagMeshObject {
public:
	/* 419BA0 */ void OnActivateLevel();
	/* 43B090 */ CArmataPocisk();
	/* 43B0D0 */ virtual ~CArmataPocisk();
	/* 43B0E0 */ void OnActivate();
	/* 43B1A0 */ void FUN0043b1a0(D3DXVECTOR3 param_1, D3DXVECTOR3 param_2);
	/* 43B1F0 */ void OnCollisionObject(cMagMeshObject* param_1);
};

STATIC_ASSERT(sizeof(CArmataPocisk) == 0x2658);

#endif