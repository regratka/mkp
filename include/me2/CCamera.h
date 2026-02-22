#ifndef _C_CAMERA
#define _C_CAMERA

#include <globals.h>

class CCamera {
public:
	/* 1000BE30 */ CCamera(CCamera* param_1);
	/* 1000BEE0 */ CCamera* operator=(CCamera* param_1);
	/* 1000BF90 */ CCamera* scalar_destructor(uchar param_1);
	/* 1005F530 */ CCamera();
	/* 1005F6B0 */ ~CCamera();
	/* 1005F6C0 */ void SetFOV(float param_1);
	/* 1005F6D0 */ float GetFOV();
	/* 1005F6E0 */ void SetPosition(D3DXVECTOR3 param_1);
	/* 1005F710 */ D3DXVECTOR3* GetPosition(D3DXVECTOR3* param_1);
	/* 1005F740 */ void SetNearPlane(float param_1);
	/* 1005F750 */ void SetFarPlane(float param_1);
	/* 1005F760 */ float GetNearPlane();
	/* 1005F770 */ void SetAspect(float param_1);
	/* 1005F780 */ float GetAspect();
	/* 1005F790 */ float GetFarPlane();
	/* 1005F7A0 */ void SetDirection(D3DXVECTOR3 param_1);
	/* 1005FC60 */ D3DXVECTOR3* GetDirection(D3DXVECTOR3* param_1);
	/* 1005FC90 */ D3DXVECTOR3* GetRight(D3DXVECTOR3* param_1);
	/* 1005FCC0 */ D3DXVECTOR3* GetUp(D3DXVECTOR3* param_1);
	/* 1005FCF0 */ void UpdateAspectByWindowSize(bool param_1);
	/* 1005FD00 */ void OnRender();
	/* 1005FDA0 */ void UpdateWindowSize(int param_1, int param_2);
	/* 1005FDC0 */ int GetID();
	/* 1005FDD0 */ void OnActivateView();
	/* 1005FE20 */ void Rotate(D3DXVECTOR3 param_1, float param_2, bool param_3);
	/* 1005FED0 */ void OnDeactivateView();
	/* 1005FF10 */ void SetFreeRotationMatrix(bool param_1);
	/* 1005FF20 */ bool GetFreeRotationMatrix();
	/* 1005FF30 */ void SetUp(D3DXVECTOR3 param_1);
	/* 10060210 */ void SetRight(D3DXVECTOR3 param_1);
};

#endif