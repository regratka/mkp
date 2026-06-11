#ifndef _COLLISION_MANAGER
#define _COLLISION_MANAGER

#include <globals.h>

#include <d3dx8math.h>

#include "Collision.h"

class CCollisionCamera;

class collision {
public:
	/* 100A07A0 */ ~collision();
	/* 100A5AF0 */ void FUN_100a5af0();
	/* 100A6300 */ bool FUN100A6300(D3DXVECTOR3 param_1, D3DXVECTOR3 param_2, D3DXVECTOR3* const param_3, float* param_4, D3DXVECTOR3* param_5);
	/* 100A6BD0 */ void FUN100A6BD0(CCollisionCamera* param_1);
	/* 100A80A0 */ bool FUN100A80A0(Collision* param_1);
	/* 100A80D0 */ bool FUN100A80D0(Collision* param_1);
	/* 100A83A0 */ void FUN_100a83a0();
	/* 100A8810 */ collision();
	/* 100A8D00 */ uchar LoadSettings(char* param_1);
};

#endif