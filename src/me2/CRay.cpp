#include "CRay.h"

/* 100BC850-100BC867 00017	*/
CRay::CRay() {
	Reset();
}

/* 100BC870-100BC8B9 00049	*/
CRay::CRay(D3DXVECTOR3 const& param_1, D3DXVECTOR3 const& param_2) {
	origin = param_1;
	vector = param_2;
	Reset();
}

/* 100BC8C0-100BC8C7 00007	*/
CRay::~CRay() {
}