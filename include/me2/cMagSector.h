#ifndef C_MAG_SECTOR
#define C_MAG_SECTOR

#include <globals.h>

class cMagSector {
public:
	/* 10024950 */ cMagSector(cMagSector* param_1);
	/* 100249F0 */ cMagSector* operator=(cMagSector* param_1);
	/* 10024A80 */ cMagSector* scalar_destructor(uchar param_1);
	/* 10045B20 */ cMagSector();
	/* 10045BC0 */ ~cMagSector();
	/* 10045BD0 */ void OnRender();
	/* 10045D10 */ cMagMeshObject* GetParentSector();
	/* 10045D20 */ void GetBoundingBoxSector(uchar param_1, uchar param_2, uchar param_3);
	/* 10045E40 */ bool EnableSectorRendering();
	/* 10045E60 */ void DisableRenderingOtherSector();
	/* 10045EF0 */ bool TestSectorName(char* param_1);
	/* 10046090 */ void EnableRenderingChildSector(bool param_1);
	/* 10046240 */ void SetSector(cMagMeshObject* param_1);
};

#endif