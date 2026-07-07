#ifndef C_GLOW
#define C_GLOW

#include <globals.h>

#include "cMagMeshObject.h"

struct GLOWVERTEX{
	D3DXVECTOR3 pos;
	D3DCOLOR color;
};

class DLLEXPORT cGlow : public cMagMeshObject {
public:
	/* 10076E10 */ cGlow();
	/* 10076EF0 */ virtual ~cGlow();
	/* 10076F60 */ void Create(char* param_1);
	/* 10076FF0 */ void OnRender();
	/* 10077180 */ void RenderGlow();
	/* 10077370 */ void SetScale(D3DXVECTOR3 param_1);
	/* 10077390 */ void SetPosition(D3DXVECTOR3 param_1);
	/* 100773B0 */ void SetSize(float param_1);
	/* 100773C0 */ void EnableRendering(bool param_1);
	/* 100773D0 */ bool EnableRendering();

private:
	/* 0x2658 */ IDirect3DVertexBuffer8* vertexBuffer;
	/* 0x265c */ IDirect3DTexture8* texture;
	/* 0x2660 */ D3DXMATRIX unk_2660;
	/* 0x26a0 */ D3DXMATRIX positionMatrix;
	/* 0x26e0 */ D3DXMATRIX scaleMatrix;
	/* 0x2720 */ D3DXVECTOR3 scale;
	/* 0x272c */ D3DXVECTOR3 position;
	/* 0x2738 */ float size;
	/* 0x273c */ bool enableRendering;

};

STATIC_ASSERT(sizeof(cGlow) == 0x2740);

#endif