#ifndef C_MAG_FRUSTUM_CULL
#define C_MAG_FRUSTUM_CULL

#include <globals.h>

class cMagFrustumCull {
public:
	/* 10003A00 */ cMagFrustumCull(cMagFrustumCull* param_1);
	/* 10003B50 */ cMagFrustumCull* operator=(cMagFrustumCull* param_1);
	/* 10003E30 */ cMagFrustumCull* scalar_destructor(uchar param_1);
	/* 10089A80 */ cMagFrustumCull();
	/* 10089B60 */ ~cMagFrustumCull();
	/* 10089C50 */ uint ComputeBoundingBox(float param_1, float param_2, float param_3, float param_4, float param_5, float param_6);
	/* 10089F90 */ void UpdateBB(float param_1, float param_2, float param_3, uint* param_4, float param_5, float param_6);
	/* 1008A1A0 */ void DrawBoundingBox(uchar param_1, uchar param_2, uchar param_3, uchar param_4, uchar param_5, uchar param_6, uchar param_7, uchar param_8, uchar param_9, uchar param_10);
	/* 1008A210 */ void CreateBox();
	/* 1008A760 */ void CullObjects();
	/* 1008A790 */ CULLSTATE CullObject(CULLINFO* param_1, uchar param_2, D3DXPLANE* param_3);
	/* 1008B560 */ int EdgeIntersectsFace(uchar param_1, uchar param_2, D3DXPLANE* param_3);
	/* 1008B7E0 */ void UpdateCullInfo(CULLINFO* param_1, uchar param_2, uchar param_3);
	/* 1008BA40 */ void UpdateCull(uchar param_1, uchar param_2);
	/* 1008BA60 */ long UpdatePlaneVBs();
	/* 1008BE00 */ uchar GetCenterBox(uint* param_1);
	/* 1008BE30 */ void AddLine(uchar param_1, uchar param_2, uchar param_3, uint param_4, uint param_5, uint param_6);
	/* 1008C060 */ void InitLine();
	/* 1008C120 */ void RenderLines();
};

#endif