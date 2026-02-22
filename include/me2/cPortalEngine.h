#ifndef C_PORTAL_ENGINE
#define C_PORTAL_ENGINE

#include <globals.h>
#include <d3dx8math.h>

#include "Mesh.h"

class cPortalEngine {
public:
	/* 1000ECE0 */ cPortalEngine(cPortalEngine* param_1);
	/* 1000F010 */ cPortalEngine* operator=(cPortalEngine* param_1);
	/* 1000F4B0 */ cPortalEngine* scalar_destructor(uchar param_1);
	/* 10077F60 */ cPortalEngine();
	/* 10078160 */ ~cPortalEngine();
	/* 10078360 */ void CreatePlanePortal(Mesh* param_1, D3DXMATRIX param_2);
	/* 100784F0 */ void AssignFacesToTexturesSektor();
	/* 10078FB0 */ void CreateTextures();
	/* 100791D0 */ void RenderAllViewSectors(int param_1);
	/* 10079370 */ void RenderSector(int param_1);
	/* 10079780 */ void Render();
	/* 100797A0 */ void CreateSector(int param_1, float param_2, float param_3, float param_4, float param_5, float param_6, float param_7);
	/* 10079A70 */ void AddPortal(float param_1, float param_2, float param_3, float param_4, float param_5, float param_6);
	/* 10079E20 */ int GetNumberSector();
	/* 10079EF0 */ uint SectorIsRendering(float param_1, float param_2, float param_3);
	/* 10079F30 */ uint GetIndexSector(float param_1, float param_2, float param_3);
	/* 10079FC0 */ void AssignPortalToSector();
};

#endif