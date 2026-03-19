#ifndef _C_LENS_FLARE_SPOT
#define _C_LENS_FLARE_SPOT

#include <globals.h>

#include "cMagUtility.h"

#include "d3d8.h"
#include "d3dx8math.h"

class CLensFlareSpot : public cMagUtility {
public:
	/* 100222A0 */ void SetTexture(IDirect3DTexture8* param_1);
	/* 100222B0 */ uchar GetTexture();
	/* 100222C0 */ float GetSize();
	/* 100222D0 */ void SetSize(float param_1);
	/* 100222E0 */ float GetLinePos();
	/* 100222F0 */ void SetLinePos(float param_1);
	/* 10022300 */ D3DXCOLOR* GetColor(D3DXCOLOR* param_1);
	/* 10022330 */ void SetColor(D3DXCOLOR* param_1);
	/* 10022360 */ CLensFlareSpot(CLensFlareSpot* param_1);
	/* 10022490 */ CLensFlareSpot* operator=(CLensFlareSpot* param_1);
	/* 100225A0 */ CLensFlareSpot* scalar_destructor(uchar param_1);
	/* 10074140 */ CLensFlareSpot();
	/* 100741C0 */ CLensFlareSpot(IDirect3DTexture8* param_1, float param_2, float param_3, D3DXCOLOR param_4);
	/* 10074220 */ ~CLensFlareSpot();
};

#endif