#include "cMagCamera.h"


/* 10060620-1006062B 0000B	*/
cMagCamera::~cMagCamera() {
}

/* 10060630-1006068C 0005C	*/
cMagCamera::cMagCamera(float param_1, float param_2, float param_3, float param_4, float param_5, float param_6, float param_7, float param_8, float param_9) {
	SetObjectName("No Name");
	SetClassName("cMagCamera");
}

/* 10060690-100606C5 00035	*/
void cMagCamera::Init(float param_1, float param_2, float param_3, float param_4, float param_5, float param_6, float param_7, float param_8, float param_9) {
	PositionCamera(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9);
}

/* 100606D0-10060782 000B2	*/
void cMagCamera::PositionCamera(float param_1, float param_2, float param_3, float param_4, float param_5, float param_6, float param_7, float param_8, float param_9) {
	G1018c5e8.x = param_1;
	G1018c5e8.y = param_2;
	G1018c5e8.z = param_3;
	G1018c5d8.x = param_4;
	G1018c5d8.y = param_5;
	G1018c5d8.z = param_6;
	G1018c5c8.x = param_7;
	G1018c5c8.y = param_8;
	G1018c5c8.z = param_9;
	position.x = param_1;
	position.y = param_2;
	position.z = param_3;
	view.x = param_4;
	view.y = param_5;
	view.z = param_6;
	unk_d64.x = param_7;
	unk_d64.y = param_8;
	unk_d64.z = param_9;
}

/* 10060790-100608AF 0011F	*/
void cMagCamera::RotateView(float param_1, float param_2, float param_3) {
	D3DXVECTOR3 fVar1 = view - position;

	if (param_1 != 0.0f) {
		float fVar4 = cos(param_1);
		float fVar5 = sin(param_1);
		view.z = fVar1.z * fVar4 + fVar1.y * fVar5 + position.z;
		view.y = fVar1.y * fVar4 + position.y - fVar1.z * fVar5;
	}

	if (param_2 != 0.0f) {
		float fVar4 = cos(param_2);
		float fVar5 = sin(param_2);
		view.z = fVar1.z * fVar4 + fVar1.x * fVar5 + position.z;
		view.x = fVar1.x * fVar4 + position.x - fVar1.z * fVar5;
	}

	if (param_3 != 0.0f) {
		float fVar3 = sin(param_3);
		float fVar4 = cos(param_3);
		view.x = fVar1.y * fVar3 + fVar1.x * fVar4 + position.x;
		view.y = fVar1.y * fVar4 + position.y - fVar1.x * fVar3;
	}


}

/* 100608B0-10060953 000A3	*/
void cMagCamera::MoveCamera(float param_1) {
	D3DXVECTOR3 fVar1 = (view - position);
	fVar1.x *= param_1;
	position.x += fVar1.x;
	fVar1.z *= param_1;
	position.z += fVar1.z;
	fVar1.y *= param_1;
	position.y += fVar1.y;
	view.x += fVar1.x;
	view.z += fVar1.z;
	view.y += fVar1.y;
}

/* 10060960-10060A51 000F1	*/
bool cMagCamera::MoveCameraByMouse(int param_1, int param_2, int param_3, int param_4) {
	int X = param_1 >> 1;
	int Y = param_2 >> 1;
	int iVar2 = param_1 / 2 + param_3;
	int iVar3 = param_2 / 2 + param_4;
	if (iVar2 == X && iVar3 == Y) {
		return false;
	}

	SetCursorPos(X, Y);
	float fVar1 = (X - iVar2) * 0.001f;
	float fVar2 = (Y - iVar3) * 0.002f;

	view.y += fVar2 * 8.0f;
	if (view.y - position.y > 3600.0f) {
		view.y = position.y + 3600.0f;
	}

	if (view.y - position.y < -3600.0f) {
		view.y = position.y - 3600.0f;
	}

	RotateView(0.0f, fVar1, 0.0f);

	return true;
}

