#ifndef _COLLISION
#define _COLLISION

#include <globals.h>

#include <d3dx8math.h>

class cMagMeshObject;

class Collision {
public:
	/* 10011000 */ uchar operator=(uchar param_1);
	/* 100A9CA0 */ Collision();
	/* 100A9CB0 */ Collision(D3DXVECTOR3 param_1, D3DXVECTOR3 param_2);
	/* 100A9CF0 */ Collision(D3DXVECTOR3 param_1, D3DXVECTOR3 param_2, cMagMeshObject* param_3);
	/* 100A9D40 */ char* GetTextureName();
	/* 100A9DA0 */ void Init();
};

#endif