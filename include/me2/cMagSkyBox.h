#ifndef C_MAG_SKY_BOX
#define C_MAG_SKY_BOX

#include <globals.h>
#include <d3dx8math.h>
#include "cMagMeshObject.h"

class cMagSkyBox : public cMagMeshObject{
public:
	/* 100216C0 */ cMagSkyBox(cMagSkyBox* param_1);
	/* 100218D0 */ cMagSkyBox* operator=(cMagSkyBox* param_1);
	/* 10021BC0 */ cMagSkyBox* scalar_destructor(uchar param_1);
	/* 100727F0 */ cMagSkyBox();
	/* 100728E0 */ ~cMagSkyBox();
	/* 10072960 */ void CreateSkyBox(char* param_1);
	/* 10072AD0 */ void SetPosY(float param_1);
	/* 10072AE0 */ void SetScale(D3DXVECTOR3 param_1);
	/* 10072B40 */ void Render(uchar param_1);
	/* 10072D80 */ void DayDown(float param_1);
	/* 10072E30 */ void DayUp(float param_1);
	/* 10072E90 */ void OnRender();
	/* 10072EC0 */ void GetBBox(uchar param_1, uchar param_2);
	/* 10072F30 */ void AddTexture(char* param_1);
};

#endif