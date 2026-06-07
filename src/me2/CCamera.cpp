#include "CCamera.h"

#include "cMagEngineMgr.h"
#include "CJVMData.h"


/* 1005F530-1005F6A6 00176	*/
CCamera::CCamera() {
	updateAspectByWindowSize = true;
	fov = 70.0f;
	nearPlane = 10.0f;
	farPlane = 500000.0f;
	D3DXMatrixIdentity(&cameraVectors);
	D3DXMatrixIdentity(&viewMatrix);
	D3DXMatrixIdentity(&projectionMatrix);
	cameraID = CCamera::m_iIDCounter;
	CCamera::m_iIDCounter++;
	isFreeRotationMatrix = false;
}

/* 1005F6B0-1005F6BB 0000B	*/
CCamera::~CCamera() {
}

/* 1005F6C0-1005F6CD 0000D	*/
void CCamera::SetFOV(float param_1) {
	fov = param_1;
}

/* 1005F6D0-1005F6D7 00007	*/
float CCamera::GetFOV() {
	return fov;
}

/* 1005F6E0-1005F701 00021	*/
void CCamera::SetPosition(D3DXVECTOR3 param_1) {
	cameraVectors(3,0) = param_1.x;
	cameraVectors(3,1) = param_1.y;
	cameraVectors(3,2) = param_1.z;

}

/* 1005F710-1005F731 00021	*/
D3DXVECTOR3 CCamera::GetPosition() {
	return D3DXVECTOR3(cameraVectors(3,0), cameraVectors(3,1), cameraVectors(3,2));
}

/* 1005F740-1005F74D 0000D	*/
void CCamera::SetNearPlane(float param_1) {
	nearPlane = param_1;
}

/* 1005F750-1005F75D 0000D	*/
void CCamera::SetFarPlane(float param_1) {
	farPlane = param_1;
}

/* 1005F760-1005F767 00007	*/
float CCamera::GetNearPlane() {
	return nearPlane;
}

/* 1005F770-1005F77D 0000D	*/
void CCamera::SetAspect(float param_1) {
	aspectRatio = param_1;
}

/* 1005F780-1005F787 00007	*/
float CCamera::GetAspect() {
	return aspectRatio;
}

/* 1005F790-1005F797 00007	*/
float CCamera::GetFarPlane() {
	return farPlane;
}

/* 1005F7A0-1005FC54 004B4	*/
void CCamera::SetDirection(D3DXVECTOR3 param_1) {
	D3DXVec3Normalize(&param_1, &param_1);

	if (!isFreeRotationMatrix) {
		cameraVectors(2,1) = param_1.y;
		cameraVectors(2,0) = param_1.x;
		cameraVectors(2,2) = param_1.z;
		D3DXVECTOR3 Dstack_70;

		D3DXVECTOR3 Dstack_64(0.0f, 1.0f, 0.0f);
		if (param_1 == Dstack_64 || param_1 == D3DXVECTOR3(0.0f, -1.0f, 0.0f)) {
			Dstack_70 = GetRight();
		} else {
			Dstack_70 =  param_1 - D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			D3DXVec3Normalize(&Dstack_70, &Dstack_70);
		}
		D3DXVECTOR3 Dstack_58 = *D3DXVec3Cross(&Dstack_64, &param_1, &Dstack_70);
		D3DXVec3Normalize(&Dstack_64, &Dstack_64);
		cameraVectors(0,0) = Dstack_70.x;
		cameraVectors(0,1) = Dstack_70.y;
		cameraVectors(0,2) = Dstack_70.z;
		cameraVectors(1,0) = Dstack_64.x;
		cameraVectors(1,1) = Dstack_64.y;
		cameraVectors(1,2) = Dstack_64.z;
		return;
	}
	
	if (param_1 == GetDirection()) {
		return;
	}

	if (param_1 == -1 * GetDirection()) {
		D3DXVECTOR3 Dstack_64 = -1 * GetRight();
		cameraVectors(2, 0) = param_1.x;
		cameraVectors(2, 1) = param_1.y;
		cameraVectors(2, 2) = param_1.z;
		cameraVectors(0, 0) = Dstack_64.x; 
		cameraVectors(0, 1) = Dstack_64.y; 
		cameraVectors(0, 2) = Dstack_64.z;
		return;
	}

	D3DXVECTOR3 Dstack_70 = GetPosition();
	SetPosition(D3DXVECTOR3(0.0f,0.0f,0.0f));
	D3DXVECTOR3 Dstack_64;
	D3DXVec3Cross(&Dstack_64, &GetDirection(), &param_1);
	D3DXVec3Normalize(&Dstack_64, &Dstack_64);
	if (Dstack_64 == D3DXVECTOR3(0,0,0)) {
		return;
	}

	float val = acos(D3DXVec3Dot(&param_1, &GetDirection()));
	D3DXMATRIX Dstack_40;
	Dstack_40 = *D3DXMatrixRotationAxis(&Dstack_40, &Dstack_64, val);
	D3DXMatrixMultiply(&cameraVectors, &cameraVectors, &Dstack_40);
	SetPosition(Dstack_70);
}

/* 1005FC60-1005FC81 00021	*/
D3DXVECTOR3 CCamera::GetDirection() {
	return D3DXVECTOR3(cameraVectors(2,0), cameraVectors(2,1), cameraVectors(2,2));
}

/* 1005FC90-1005FCB1 00021	*/
D3DXVECTOR3 CCamera::GetRight() {
	return D3DXVECTOR3(cameraVectors(0,0), cameraVectors(0,1), cameraVectors(0,2));
}

/* 1005FCC0-1005FCE1 00021	*/
D3DXVECTOR3 CCamera::GetUp() {
	return D3DXVECTOR3(cameraVectors(1,0), cameraVectors(1,1), cameraVectors(1,2));
}

/* 1005FCF0-1005FCFD 0000D	*/
void CCamera::UpdateAspectByWindowSize(bool param_1) {
	updateAspectByWindowSize = param_1;
}

/* 1005FD00-1005FD9A 0009A	*/
void CCamera::OnRender() {
	if (updateAspectByWindowSize) {
		aspectRatio = (float)cMagEngineMgr::getInstance()->gameObject->windowWidth / cMagEngineMgr::getInstance()->gameObject->windowHeight;
	}

	float farPlaneL = farPlane;
	float nearPlaneL = nearPlane;
	float aspectRatioL = aspectRatio;

	D3DXMatrixPerspectiveFovLH(&projectionMatrix, GpgDegToRad(GetFOV()), aspectRatioL, nearPlaneL, farPlaneL);
	cMagEngineMgr::getInstance()->engine->SetTransform(D3DTS_PROJECTION, &projectionMatrix);
	D3DXMatrixInverse(&viewMatrix, NULL, &cameraVectors);
	cMagEngineMgr::getInstance()->engine->SetTransform(D3DTS_VIEW, &viewMatrix);
}

/* 1005FDA0-1005FDBB 0001B	*/
void CCamera::UpdateWindowSize(int param_1, int param_2) {
	if (updateAspectByWindowSize) {
		aspectRatio = (float)param_1 / param_2;
	}
}

/* 1005FDC0-1005FDC7 00007	*/
int CCamera::GetID() {
	return cameraID;
}

/* 1005FDD0-1005FE14 00044	*/
void CCamera::OnActivateView() {
	if (cMagEngineMgr::getInstance()->gameObject == NULL) {
		return;
	}
	CJVMData* jvmData = cMagEngineMgr::getInstance()->gameObject->jvmData;
	if (jvmData == NULL) {
		return;
	}	

	if (javaMetaData == NULL) {
		return;
	}

	if (javaMetaData->OnActivateViewMethodID != NULL) {
		jvmData->jniEnv->CallVoidMethod(javaGlobalRef, javaMetaData->OnActivateViewMethodID);
	}
	jvmData->TraceExceptions();
}

/* 1005FE20-1005FECB 000AB	*/
void CCamera::Rotate(D3DXVECTOR3 param_1, float param_2, bool param_3) {
	D3DXVECTOR3 local_4c = GetPosition();
	if (param_3) {
		SetPosition(D3DXVECTOR3(0.0f,0.0f,0.0f));
	}
	D3DXMATRIX Dstack_40;
	D3DXMatrixRotationAxis(&Dstack_40, &param_1, GpgDegToRad(param_2));
	D3DXMatrixMultiply(&cameraVectors, &cameraVectors, &Dstack_40);
	SetPosition(local_4c);
}

/* 1005FED0-1005FF10 00040	*/
void CCamera::OnDeactivateView() {
	cMagGameObject* gameObject = cMagEngineMgr::getInstance()->gameObject;
	if (gameObject->jvmData == NULL) {
		return;
	}	
	
	if (javaMetaData == NULL) {
		return;
	}
	
	CJVMData* jvmData = gameObject->jvmData;
	if (javaMetaData->OnDeactivateViewMethodID != NULL) {
		jvmData->jniEnv->CallVoidMethod(javaGlobalRef, javaMetaData->OnDeactivateViewMethodID);
	}
	jvmData->TraceExceptions();
}

/* 1005FF10-1005FF1D 0000D	*/
void CCamera::SetFreeRotationMatrix(bool param_1) {
	isFreeRotationMatrix = param_1;
}

/* 1005FF20-1005FF27 00007	*/
bool CCamera::GetFreeRotationMatrix() {
	return isFreeRotationMatrix;
}

/* 1005FF30-10060204 002D4	*/
void CCamera::SetUp(D3DXVECTOR3 param_1) {
	D3DXVec3Normalize(&param_1, &param_1);
	if (param_1 == GetUp()) {
		return;
	}

	if (param_1 == -1 * GetUp()) {
		D3DXVECTOR3 Dstack_58 = -1 * GetRight();
		cameraVectors(1, 0) = param_1.x;
		cameraVectors(1, 1) = param_1.y;
		cameraVectors(1, 2) = param_1.z;
		cameraVectors(0, 0) = Dstack_58.x; 
		cameraVectors(0, 1) = Dstack_58.y; 
		cameraVectors(0, 2) = Dstack_58.z;

		return;
	}
	
	D3DXVECTOR3 Dstack_58 = GetPosition();
	SetPosition(D3DXVECTOR3(0,0,0));

	D3DXVECTOR3 Dstack_70;
	D3DXVec3Cross(&Dstack_70, &GetUp(), &param_1);
	D3DXVec3Normalize(&Dstack_70, &Dstack_70);
	if (Dstack_70 == D3DXVECTOR3(0,0,0)) {
		return;
	}

	float val = acos(D3DXVec3Dot(&param_1, &GetUp()));
	D3DXMATRIX Dstack_40;
	Dstack_40 = *D3DXMatrixRotationAxis(&Dstack_40, &Dstack_70, val);
	D3DXMatrixMultiply(&cameraVectors, &cameraVectors, &Dstack_40);
	SetPosition(Dstack_58);

}

/* 10060210-10060474 00264	*/
void CCamera::SetRight(D3DXVECTOR3 param_1) {
	D3DXVec3Normalize(&param_1, &param_1);
	if (param_1 == GetRight()) {
		return;
	}

	if (param_1 == -1 * GetRight()) {
		D3DXVECTOR3 Dstack_58 = -GetDirection();
		cameraVectors(0, 0) = param_1.x;
		cameraVectors(0, 1) = param_1.y;
		cameraVectors(0, 2) = param_1.z;
		cameraVectors(2, 0) = Dstack_58.x; 
		cameraVectors(2, 1) = Dstack_58.y; 
		cameraVectors(2, 2) = Dstack_58.z;
		return;
	}
	
	D3DXVECTOR3 Dstack_58 = GetPosition();
	SetPosition(D3DXVECTOR3(0,0,0));

	D3DXVECTOR3 Dstack_70;
	D3DXVec3Cross(&Dstack_70, &GetRight(), &param_1);
	D3DXVec3Normalize(&Dstack_70, &Dstack_70);
	if (Dstack_70 == D3DXVECTOR3(0,0,0)) {
		return;
	}

	float val = acos(D3DXVec3Dot(&param_1, &GetRight()));
	D3DXMATRIX Dstack_40;
	Dstack_40 = *D3DXMatrixRotationAxis(&Dstack_40, &Dstack_70, val);
	D3DXMatrixMultiply(&cameraVectors, &cameraVectors, &Dstack_40);
	SetPosition(Dstack_58);
}

