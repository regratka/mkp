#ifndef _C_RAY
#define _C_RAY

#include <globals.h>

class CRay {
public:
	/* 1000B470 */ uchar Vector();
	/* 10010900 */ float Length();
	/* 10010940 */ D3DXVECTOR3* End(D3DXVECTOR3* param_1, float param_2);
	/* 100109C0 */ D3DXVECTOR3* Closest(D3DXVECTOR3* param_1, D3DXVECTOR3* param_2);
	/* 10010A50 */ void SetVector(D3DXVECTOR3* param_1);
	/* 10010A80 */ void SetOrigin(uchar param_1);
	/* 10010AB0 */ uchar Origin();
	/* 10010AC0 */ float D();
	/* 10010B20 */ uchar Normal();
	/* 10010B60 */ bool Intersect(CRay* param_1, float* param_2);
	/* 10010CB0 */ float Distance(D3DXVECTOR3* param_1);
	/* 10010E60 */ D3DXVECTOR3* End(D3DXVECTOR3* param_1);
	/* 10010E90 */ void Reset();
	/* 10010EA0 */ CRay(CRay* param_1);
	/* 10010F20 */ CRay* operator=(CRay* param_1);
	/* 10010FA0 */ CRay* scalar_destructor(uchar param_1);
	/* 100BC850 */ CRay();
	/* 100BC870 */ CRay(D3DXVECTOR3* param_1, D3DXVECTOR3* param_2);
	/* 100BC8C0 */ ~CRay();
};

#endif