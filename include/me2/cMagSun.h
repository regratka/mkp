#ifndef C_MAG_SUN
#define C_MAG_SUN

#include <globals.h>

#include <d3dx8math.h>
#include "cMagUtility.h"
#include "cMagMeshObject.h"

class DLLEXPORT cMagSun : public cMagUtility {
public:
	/* 10012910 */ void DeleteTexture();

	/* 10021C20-10021C37 00017	*/ 
	void SetScale(D3DXVECTOR2 param_1) {
		scale = param_1;
	}

	/* 10021C40-10021C68 00028	*/
	D3DXVECTOR2 cMagSun::GetScale() {
		D3DXVECTOR2 fVar1;
		fVar1.x = scale.x;
		fVar1.y = scale.y;
		return fVar1;
	}

	/* 1005A5E0 */ void InitDeviceDx(cMagGameObject* param_1);
	/* 10072620 */ void SetAnimTextureFPS(int param_1);
	/* 10072630 */ void SetAnimTextureFrameCount(int param_1);
	/* 100731B0 */ cMagSun();
	/* 10073340 */ virtual ~cMagSun();
	/* 10073410 */ void RestoreSun();
	/* 10073460 */ IDirect3DTexture8* AddTexture(char const * param_1);
	/* 100734A0 */ D3DXVECTOR3 GetPosition();
	/* 100734C0 */ void Render(D3DXMATRIX param_1);
	/* 100739E0 */ void DeleteQuad();
	/* 10073A00 */ void OnRender();
	/* 10073A60 */ void EnableRendering(bool param_1);
	/* 10073A70 */ bool IsEnabled();
	/* 10073A80 */ void AddAnimTexture(char* param_1);
	/* 10073C50 */ void RenderAnimTexture();
	/* 10073D30 */ void EnableAnimTexture(bool param_1);
	/* 10073D40 */ float deg2rad(float param_1);
	/* 10073D50 */ void SetAngleXZ(float param_1);
	/* 10073D60 */ void SetAngleYZ(float param_1);
	/* 10073D70 */ void SetDistance(float param_1);
	/* 10073D80 */ void Update();

private:
	/* 0xd4c */ bool isRenderingEnabled;
	/* 0xd4d */ bool isAnimTextureEnabled;
	/* 0xd50 */ int animTextureFPS;
	/* 0xd54 */ int animTextureFrameCount;
	/* 0xd58 */ float lastTextureChangeTime;
	/* 0xd5c */ float currentAnimTextureIndex;
	/* 0xd60 */ std::vector<IDirect3DTexture8*> animTextures;
	/* 0xd70 */ IDirect3DTexture8* texture;
	/* 0xd74 */ D3DXVECTOR2 scale;
	/* 0xd7c */ float yaw;
	/* 0xd80 */ float pitch;
	/* 0xd84 */ float roll;
	/* 0xd88 */ IDirect3DVertexBuffer8* buffer;
	/* 0xd90 */ cMagMeshObject meshObject;
	/* 0x33e8 */ D3DXVECTOR3 cameraPosition;
	/* 0x33f4 */ D3DXMATRIX unk_33f4;
	/* 0x3434 */ float oldAngleXZ;
	/* 0x3438 */ float oldAngleYZ;
	/* 0x343c */ float angleXZ;
	/* 0x3440 */ float angleYZ;
	/* 0x3444 */ float distance;
};

STATIC_ASSERT(sizeof(cMagSun) == 0x3448);

#endif