#ifndef _C_SIMPLE_LINE
#define _C_SIMPLE_LINE

#include <globals.h>

class CSimpleLine {
public:
	/* 1000CA00 */ long Invalidate();
	/* 1000CA40 */ CSimpleLine(CSimpleLine* param_1);
	/* 1000CC40 */ CSimpleLine* operator=(CSimpleLine* param_1);
	/* 1000CE60 */ CSimpleLine* scalar_destructor(uchar param_1);
	/* 1002EBB0 */ CSimpleLine();
	/* 1002ECB0 */ ~CSimpleLine();
	/* 1002ED30 */ void OnRender();
	/* 1002ED40 */ void SetParams(uint param_1, uint param_2, uint param_3, uint param_4, uint param_5, uint param_6, uint param_7);
	/* 1002ED90 */ long Create(int param_1, int param_2, float param_3);
	/* 1002EDC0 */ long InitDeviceObjects(IDirect3DDevice8* param_1);
	/* 1002EDE0 */ long BuildVertexBuffer(float* param_1, int param_2);
	/* 1002EF40 */ long Render();
	/* 1002F220 */ void CreateSphere(D3DXVECTOR3 param_1, int param_2, int param_3, int param_4);
	/* 1002F5E0 */ void CreateCircle(short* param_1, float* param_2, float param_3, float param_4, float param_5, uint param_6, float param_7);
	/* 1002F770 */ void SetPosition(uint param_1, uint param_2, uint param_3);
	/* 1002F7D0 */ void DrawTriangle(MagnumMesh* param_1, int param_2);
	/* 1002FAE0 */ void Line(D3DXVECTOR3 param_1, D3DXVECTOR3 param_2, char* param_3);
	/* 1002FB50 */ void EnableRendering(bool param_1);
	/* 1002FB60 */ void SetTexture(char* param_1);
	/* 1002FB80 */ void Arrow(D3DXVECTOR3 param_1, D3DXVECTOR3 param_2, D3DXVECTOR3 param_3, char* param_4);
	/* 1002FE20 */ void BuildArrowVertexBuffer(float* param_1, int param_2);
	/* 1002FFA0 */ long BuildVertexBuffer(vector<struct_D3DXVECTOR3,class_std::allocator<struct_D3DXVECTOR3>_>* param_1);
	/* 10030120 */ void SetPrimitiveType(D3DPRIMITIVETYPE param_1);
	/* 10030130 */ void SetPointSize(float param_1);
	/* 10030140 */ long BuildPointsVertexBuffer(std::vector<D3DXVECTOR3>* param_1);
	/* 100302B0 */ void PolyLine(vector<struct_D3DXVECTOR3,class_std::allocator<struct_D3DXVECTOR3>_>* param_1, char* param_2);
	/* 100302E0 */ void SetPosition();
	/* 10030350 */ void EnableZBuffer(bool param_1);
};

#endif