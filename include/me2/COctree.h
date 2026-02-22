#ifndef _C_OCTREE
#define _C_OCTREE

#include <globals.h>

class COctree {
public:
	/* 10003EF0 */ COctree(COctree* param_1);
	/* 10003F60 */ COctree* operator=(COctree* param_1);
	/* 10003FE0 */ COctree* scalar_destructor(uchar param_1);
	/* 100B6760 */ COctree();
	/* 100B67C0 */ ~COctree();
	/* 100B67D0 */ void Create(D3DXVECTOR3* param_1, int param_2);
	/* 100B6820 */ void Release();
	/* 100B6860 */ void SetData(D3DXVECTOR3* param_1, int param_2);
	/* 100B69C0 */ void CreateNode(D3DXVECTOR3* param_1, int param_2, D3DXVECTOR3 param_3, float param_4);
	/* 100B6FE0 */ void CreateNodeEnd(D3DXVECTOR3* param_1, int param_2, bool* param_3, D3DXVECTOR3 param_4, float param_5, int param_6, COctreeSegment param_7);
	/* 100B7160 */ D3DXVECTOR3* GetNodeCenter(D3DXVECTOR3* param_1, D3DXVECTOR3 param_2, float param_3, COctreeSegment param_4);
	/* 100B73A0 */ void SetNode(D3DXVECTOR3* param_1, int param_2);
	/* 100B7410 */ void CreateVertexBuffer(IDirect3DDevice8* param_1);
	/* 100B7650 */ void Render(COctree* param_1);
	/* 100B7830 */ void RenderOctree(uchar param_1, uchar param_2, uchar param_3, uchar param_4, uchar param_5, uchar param_6, uchar param_7, uchar param_8, uchar param_9, uint param_10, uint param_11);
	/* 100B7C30 */ float abs_f(float param_1);
	/* 100B7C60 */ void triangle(uchar param_1, float* param_2, float* param_3, float* param_4, uchar param_5);
	/* 100B7C70 */ void wire_cube(uchar param_1, float* param_2, float* param_3, uchar param_4);
};

#endif