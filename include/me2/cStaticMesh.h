#ifndef C_STATIC_MESH
#define C_STATIC_MESH

#include <globals.h>

class cStaticMesh {
public:
	/* 100043E0 */ cStaticMesh(cStaticMesh* param_1);
	/* 10004820 */ cStaticMesh* operator=(cStaticMesh* param_1);
	/* 10004BA0 */ cStaticMesh* scalar_destructor(uchar param_1);
	/* 1003D720 */ cStaticMesh();
	/* 1003DA70 */ virtual ~cStaticMesh();
	/* 1003DCF0 */ bool Load(char* param_1);
	/* 1003DF70 */ bool LoadOld(char* param_1);
	/* 1003EB30 */ bool LoadNew(char* param_1);
	/* 1003F7C0 */ void LoadDummy();
	/* 1003FB80 */ void LoadLightmap(char* param_1);
	/* 10040520 */ int GetSurfaceCount();
	/* 10040530 */ int GetVertexCount();
	/* 10040540 */ int GetFacesCount();
	/* 10040550 */ bool Create();
	/* 10040C40 */ void ComputeBoundingBox(uchar param_1, uchar param_2);
	/* 10040C80 */ void Update(uchar param_1);
	/* 10041000 */ void Render(uchar param_1, uchar param_2, uchar param_3, uchar param_4, uchar param_5, uchar param_6, uchar param_7, uchar param_8, uchar param_9, uint param_10);
	/* 10041070 */ int TestDistance(float param_1, float param_2, float param_3, float param_4, float param_5, float param_6);
	/* 10041710 */ void CreateColTypeTexIni(char* param_1);
	/* 10041980 */ void LoadColTypeTexIni(char* param_1);
	/* 10041D00 */ bool SetAlpha(int param_1);
	/* 10041D60 */ bool SetMultiple(float param_1);
	/* 10041DC0 */ void SetAnimTextureLightMap(uchar param_1);

private:
	/* 0x04 */ uchar f_04[0x480-0x04];
};

STATIC_ASSERT(sizeof(cStaticMesh)==0x480);

#endif