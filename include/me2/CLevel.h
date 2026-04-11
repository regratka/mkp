#ifndef _C_LEVEL
#define _C_LEVEL

#include <globals.h>

#include "cMagUtility.h"

class CLevel : public cMagUtility {
public:
	/* 10023B60 */ CLevel(CLevel* param_1);
	/* 10023CA0 */ CLevel* operator=(CLevel* param_1);
	/* 10023DD0 */ CLevel* scalar_destructor(uchar param_1);
	/* 100BAFA0 */ CLevel();
	/* 100BAFD0 */ ~CLevel();
	/* 100BAFE0 */ void Init(cMagGameObject* param_1);
	/* 100BB0A0 */ D3DXVECTOR3* GetEDCameraPosition(D3DXVECTOR3* param_1);
	/* 100BB0D0 */ D3DXVECTOR3* GetEDCameraView(D3DXVECTOR3* param_1);
	/* 100BB100 */ void SetEDCameraPosition(D3DXVECTOR3 param_1);
	/* 100BB120 */ void SetEDCameraView(D3DXVECTOR3 param_1);
	/* 100BB1E0 */ void SetFilePath(char* param_1);
	/* 100BB210 */ char* GetFilePath();
private: 
	/* 0xd4c */ uchar field_d4c[0xd50 - 0xd4c];
	/* 0xd50 */ D3DXVECTOR3 edCameraPositon;
	/* 0xd5c */ D3DXVECTOR3 edCameraView;
	/* 0xd68 */ char filepath[300];
};

STATIC_ASSERT(sizeof(CLevel) == 0xe94);

#endif