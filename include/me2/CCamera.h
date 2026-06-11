#ifndef _C_CAMERA
#define _C_CAMERA

#include <globals.h>
#include <d3dx8math.h>

#include "cMagGameObject.h"

class DLLEXPORT CCamera : public cMagGameObject {
public:
	/* 1005F530 */ CCamera();
	/* 1005F6B0 */ virtual ~CCamera();
	/* 1005F6C0 */ void SetFOV(float param_1);
	/* 1005F6D0 */ float GetFOV();
	/* 1005F6E0 */ void SetPosition(D3DXVECTOR3 param_1);
	/* 1005F710 */ virtual D3DXVECTOR3 GetPosition();
	/* 1005F740 */ void SetNearPlane(float param_1);
	/* 1005F750 */ void SetFarPlane(float param_1);
	/* 1005F760 */ float GetNearPlane();
	/* 1005F770 */ void SetAspect(float param_1);
	/* 1005F780 */ float GetAspect();
	/* 1005F790 */ float GetFarPlane();
	/* 1005F7A0 */ void SetDirection(D3DXVECTOR3 param_1);
	/* 1005FC60 */ D3DXVECTOR3 GetDirection();
	/* 1005FC90 */ D3DXVECTOR3 GetRight();
	/* 1005FCC0 */ D3DXVECTOR3 GetUp();
	/* 1005FCF0 */ void UpdateAspectByWindowSize(bool param_1);
	/* 1005FD00 */ void OnRender();
	/* 1005FDA0 */ void UpdateWindowSize(int param_1, int param_2);
	/* 1005FDC0 */ int GetID();
	/* 1005FED0 */ virtual void OnDeactivateView();
	/* 1005FDD0 */ virtual void OnActivateView();
	/* 1005FE20 */ void Rotate(D3DXVECTOR3 param_1, float param_2, bool param_3);
	/* 1005FF10 */ void SetFreeRotationMatrix(bool param_1);
	/* 1005FF20 */ bool GetFreeRotationMatrix();
	/* 1005FF30 */ void SetUp(D3DXVECTOR3 param_1);
	/* 10060210 */ void SetRight(D3DXVECTOR3 param_1);

protected:
	/* 0xd10 */ bool isFreeRotationMatrix;
	/* 0xd14 */ float fov;
	/* 0xd18 */ float nearPlane;
	/* 0xd1c */ float farPlane;
	/* 0xd20 */ float aspectRatio;
	/* 0xd24 */ D3DXMATRIX cameraVectors;
	/* 0xd64 */ D3DXMATRIX viewMatrix;
	/* 0xda4 */ D3DXMATRIX projectionMatrix;
	/* 0xde4 */ bool updateAspectByWindowSize;
	/* 0xde8 */ int cameraID;

private:
	/* 1018C5C4 */ static int m_iIDCounter;
};

STATIC_ASSERT(sizeof(CCamera) == 0xdec);

#endif