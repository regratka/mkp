#include "CCamera.h"

/* 1000BE30-1000BEDC 000AC	*/
CCamera::CCamera(CCamera* param_1) {
}

/* 1000BEE0-1000BF86 000A6	*/
CCamera* CCamera::operator=(CCamera* param_1) {
	return 0;
}

/* 1000BF90-1000BFE7 00057	*/
CCamera* CCamera::scalar_destructor(uchar param_1) {
	return 0;
}

/* 1005F530-1005F6A6 00176	*/
CCamera::CCamera() {
}

/* 1005F6B0-1005F6BB 0000B	*/
CCamera::~CCamera() {
}

/* 1005F6C0-1005F6CD 0000D	*/
void CCamera::SetFOV(float param_1) {
}

/* 1005F6D0-1005F6D7 00007	*/
float CCamera::GetFOV() {
	return 0;
}

/* 1005F6E0-1005F701 00021	*/
void CCamera::SetPosition(D3DXVECTOR3 param_1) {
}

/* 1005F710-1005F731 00021	*/
D3DXVECTOR3 CCamera::GetPosition() {
	return 0;
}

/* 1005F740-1005F74D 0000D	*/
void CCamera::SetNearPlane(float param_1) {
}

/* 1005F750-1005F75D 0000D	*/
void CCamera::SetFarPlane(float param_1) {
}

/* 1005F760-1005F767 00007	*/
float CCamera::GetNearPlane() {
	return 0;
}

/* 1005F770-1005F77D 0000D	*/
void CCamera::SetAspect(float param_1) {
}

/* 1005F780-1005F787 00007	*/
float CCamera::GetAspect() {
	return 0;
}

/* 1005F790-1005F797 00007	*/
float CCamera::GetFarPlane() {
	return 0;
}

/* 1005F7A0-1005FC54 004B4	*/
void CCamera::SetDirection(D3DXVECTOR3 param_1) {
}

/* 1005FC60-1005FC81 00021	*/
D3DXVECTOR3* CCamera::GetDirection(D3DXVECTOR3* param_1) {
	return 0;
}

/* 1005FC90-1005FCB1 00021	*/
D3DXVECTOR3* CCamera::GetRight(D3DXVECTOR3* param_1) {
	return 0;
}

/* 1005FCC0-1005FCE1 00021	*/
D3DXVECTOR3* CCamera::GetUp(D3DXVECTOR3* param_1) {
	return 0;
}

/* 1005FCF0-1005FCFD 0000D	*/
void CCamera::UpdateAspectByWindowSize(bool param_1) {
}

/* 1005FD00-1005FD9A 0009A	*/
void CCamera::OnRender() {
}

/* 1005FDA0-1005FDBB 0001B	*/
void CCamera::UpdateWindowSize(int param_1, int param_2) {
}

/* 1005FDC0-1005FDC7 00007	*/
int CCamera::GetID() {
	return 0;
}

/* 1005FDD0-1005FE14 00044	*/
void CCamera::OnActivateView() {
}

/* 1005FE20-1005FECB 000AB	*/
void CCamera::Rotate(D3DXVECTOR3 param_1, float param_2, bool param_3) {
}

/* 1005FED0-1005FF10 00040	*/
void CCamera::OnDeactivateView() {
}

/* 1005FF10-1005FF1D 0000D	*/
void CCamera::SetFreeRotationMatrix(bool param_1) {
}

/* 1005FF20-1005FF27 00007	*/
bool CCamera::GetFreeRotationMatrix() {
	return 0;
}

/* 1005FF30-10060204 002D4	*/
void CCamera::SetUp(D3DXVECTOR3 param_1) {
}

/* 10060210-10060474 00264	*/
void CCamera::SetRight(D3DXVECTOR3 param_1) {
}

