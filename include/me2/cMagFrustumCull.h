#ifndef C_MAG_FRUSTUM_CULL
#define C_MAG_FRUSTUM_CULL

#include <globals.h>

#include "d3dx8math.h"

enum CULLSTATE {

};

struct CULLINFO {

};

struct StructUnk184 {
	/* 0x00 */ uchar f_00[0x14-0x00];
	/* 0x14 */ D3DXMATRIX unk_14;
	/* 0x54 */ D3DXVECTOR3 unk_54[8];
	/* 0xb4 */ D3DXVECTOR3 unk_b4[8];
	/* 0x114 */ uchar f_114[0x120-0x114];
	/* 0x120 */ D3DXPLANE unk_120[6];
	/* 0x180 */ CULLSTATE cullState;
};

STATIC_ASSERT(sizeof(StructUnk184) == 0x184);

class cMagFrustumCull {
public:
	/* 10003A00 */ cMagFrustumCull(cMagFrustumCull* param_1);
	/* 10003B50 */ cMagFrustumCull* operator=(cMagFrustumCull* param_1);
	/* 10003E30 */ cMagFrustumCull* scalar_destructor(uchar param_1);
	/* 10089A80 */ cMagFrustumCull();
	/* 10089B60 */ virtual ~cMagFrustumCull();
	/* 10089C50 */ HRESULT ComputeBoundingBox(D3DXVECTOR3 param_1, D3DXVECTOR3 param_2);
	/* 10089F90 */ void UpdateBB(D3DXVECTOR3 param_1, D3DXVECTOR3 param_2, D3DXMATRIX& param_3);
	/* 1008A1A0 */ void DrawBoundingBox(D3DXMATRIX param_1, D3DXMATRIX param_2);
	/* 1008A210 */ void CreateBox();
	/* 1008A760 */ void CullObjects();
	/* 1008A790 */ CULLSTATE CullObject(CULLINFO* param_1, uchar param_2, D3DXPLANE* param_3);
	/* 1008B560 */ int EdgeIntersectsFace(uchar param_1, uchar param_2, D3DXPLANE* param_3);
	/* 1008B7E0 */ void UpdateCullInfo(CULLINFO* param_1, uchar param_2, uchar param_3);
	/* 1008BA40 */ void UpdateCull(D3DXMATRIX* param_1, D3DXMATRIX* param_2);
	/* 1008BA60 */ long UpdatePlaneVBs();
	/* 1008BE00 */ uchar GetCenterBox(uint* param_1);
	/* 1008BE30 */ void AddLine(uchar param_1, uchar param_2, uchar param_3, uint param_4, uint param_5, uint param_6);
	/* 1008C060 */ void InitLine();
	/* 1008C120 */ void RenderLines();

public:
	/* 0x04 */ StructUnk184* structUnk184; 
	/* 0x08 */ uchar f_04[0x158-0x08]; 


};

STATIC_ASSERT(sizeof(cMagFrustumCull) == 0x158);

#endif