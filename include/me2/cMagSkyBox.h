#ifndef C_MAG_SKY_BOX
#define C_MAG_SKY_BOX

#include <globals.h>
#include <d3dx8math.h>
#include "cMagMeshObject.h"

class DLLEXPORT cMagSkyBox : public cMagMeshObject {
public:
	/* 10012910 */ void RestoreSkyBox();
	/* 10058EA0 */ bool IsEnabled();
	/* 1005A5E0 */ void InitDeviceObjects(cMagGameObject* param_1);
	/* 100727F0 */ cMagSkyBox();
	/* 100728E0 */ virtual ~cMagSkyBox();
	/* 10072960 */ void CreateSkyBox(char* param_1);
	/* 10072AD0 */ void SetPosY(float param_1);
	/* 10072AE0 */ void SetScale(D3DXVECTOR3 param_1);
	/* 10072B40 */ void Render(D3DXMATRIX& param_1);
	/* 10072D80 */ void DayDown(float param_1);
	/* 10072E30 */ void DayUp(float param_1);
	/* 10072E90 */ void OnRender();
	/* 10072EC0 */ void GetBBox(D3DXVECTOR3& param_1, D3DXVECTOR3& param_2);
	/* 10072F30 */ void AddTexture(char* param_1);

private:
	/* 0x2658 */ cStaticMesh* mesh;
	/* 0x265c */ char meshPath[255];
	/* 0x275c */ float posY;
	/* 0x2760 */ int unk_2760;
	/* 0x2764 */ std::vector<IDirect3DTexture8*> textures;
	/* 0x2774 */ uint texturesAmount;
	/* 0x2778 */ bool shouldUseDayCycle;
	/* 0x277c */ float unk_277c;
	/* 0x2780 */ float unk_2780;
	/* 0x2784 */ int unk_2784;
	/* 0x2788 */ int unk_2788;
	/* 0x278c */ int unk_278c;
	/* 0x2790 */ int unk_2790;
	/* 0x2794 */ bool unk_2794;
	/* 0x2795 */ bool unk_2795;
	/* 0x2798 */ float scaleX;
	/* 0x279c */ float scaleY;
	/* 0x27a0 */ float scaleZ;
	/* 0x27a4 */ int unk_27a4;
	/* 0x27a8 */ CCPUTicker cpuTicker;
	/* 0x2ae0 */ int ticksToChangeDay;
	/* 0x2ae4 */ int currentDayTextureIndex;
	/* 0x2ae8 */ int nextDayTextureIndex;
	/* 0x2aec */ bool shouldGoDayDown;
	/* 0x2aed */ bool unk_2aed;
	/* 0x2af0 */ double lastTickTime;
};

STATIC_ASSERT(sizeof(cMagSkyBox) == 0x2af8);

#endif