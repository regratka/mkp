#ifndef _C_PATH
#define _C_PATH

#include <globals.h>

class CPath {
public:
	/* 1000A850 */ uint* scalar_destructor(uchar param_1);
	/* 100BBD50 */ CPath();
	/* 100BBD80 */ ~CPath();
	/* 100BBDA0 */ uint InitInner(char* param_1, int param_2, int param_3);
	/* 100BBF60 */ uint InnerOnPath2(int param_1, uchar param_2, uint param_3, uint param_4);
	/* 100BBFC0 */ bool InnerOnPath(float param_1, uint param_2, uchar param_3, uint param_4);
	/* 100BC000 */ uchar Init(cMagMeshObject* param_1, char* param_2, D3DXVECTOR3 param_3, D3DXVECTOR3 param_4);
	/* 100BC0D0 */ bool OnPath(D3DXVECTOR3 param_1);
	/* 100BC180 */ void SetBMPMinMax(D3DXVECTOR3 param_1, D3DXVECTOR3 param_2);
	/* 100BC200 */ void GetBMPMinMax(D3DXVECTOR3* param_1, D3DXVECTOR3* param_2);
};

#endif