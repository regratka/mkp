#ifndef _MAG_TERRAIN
#define _MAG_TERRAIN

#include <globals.h>
#include <d3dx8math.h>

#include "pgImage.h"

class MagTerrain {
public:
	/* 1000F820 */ float GetHeightMapSizeX();
	/* 1000F830 */ float GetHeightMapSizeY();
	/* 1000F840 */ void SetHeightMapSize(float param_1, float param_2);
	/* 1000F860 */ MagTerrain(MagTerrain* param_1);
	/* 1000F9D0 */ MagTerrain* operator=(MagTerrain* param_1);
	/* 1000FF10 */ MagTerrain* scalar_destructor(uchar param_1);
	/* 10082010 */ pgImage* loadImage(char* param_1, int param_2, int param_3, FORMAT param_4);
	/* 10083100 */ MagTerrain();
	/* 100831B0 */ ~MagTerrain();
	/* 10083250 */ void Build();
	/* 10083430 */ void Update(uchar param_1);
	/* 10083500 */ void Render();
	/* 10083560 */ void OnRender();
	/* 100836E0 */ bool EnableRendering();
	/* 100836F0 */ void EnableRendering(bool param_1);
	/* 10083700 */ void SetLODRadius(float param_1);
	/* 10083710 */ float GetLODRadius();
	/* 10083720 */ void SetDetailTile(float param_1);
	/* 10083730 */ float GetDetailTile();
	/* 10083740 */ uchar GetMapSize(uint* param_1);
	/* 10083770 */ bool SetHeighMap(char* param_1);
	/* 100837D0 */ void SetDetailMap(char* param_1);
	/* 10083820 */ void SetColorMap(char* param_1);
	/* 10083870 */ uint GetHeigh(uint param_1, uint param_2, uint param_3, uint* param_4);
	/* 100838F0 */ uchar GetNormal(uint* param_1);
	/* 100839A0 */ void ShowWireframe(bool param_1);
	/* 100839B0 */ bool ShowWireframe();
	/* 100839C0 */ void SetMapSize(uint param_1, uint param_2, uint param_3);
	/* 100839E0 */ D3DXMATRIX* GetWorldMatrix(D3DXMATRIX* param_1);
	/* 10083A00 */ void SetGrassMap(char* param_1);
	/* 10083A50 */ int GetColorGrassMap(int param_1, int param_2);
	/* 10083A70 */ bool GetPositionGrassMap(int param_1, int param_2, uchar param_3);
	/* 10083B30 */ int GetNumTris();
	/* 10083B50 */ uint Pick(float param_1, float param_2, float param_3, float param_4, float param_5, float param_6, float* param_7, uint param_8, int param_9);
};

#endif