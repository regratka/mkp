#include "cMagVertex.h"

/* 1002D670-1002D6C2 00052	*/
cMagVertex::cMagVertex() {
	unk_d64 = D3DCOLOR_RGBA(0xff,0xff,0xff,0xff);
	pos = D3DXVECTOR3(0,0,0);
	unk_d58 = D3DXVECTOR3(0,0,0);
	unk_d68 = 0;
	v = 0.0f;
	u = 0.0f;
}

/* 1002D6D0-1002D748 00078	*/
cMagVertex::cMagVertex(float param_1, float param_2, float param_3, float param_4, float param_5, float param_6, ulong param_7, ulong param_8, float param_9, float param_10) {
	pos.x = param_1;
	pos.y = param_2;
	pos.z = param_3;
	unk_d58.x = param_4;
	unk_d58.y = param_5;
	unk_d58.z = param_6;
	unk_d64 = param_7;
	unk_d68 = param_8;
	u = param_9;
	v = param_10;
}

/* 1002D750-1002D75B 0000B	*/
cMagVertex::~cMagVertex() {
}

/* 1002D760-1002D7C7 00067	*/
void cMagVertex::Set(float param_1, float param_2, float param_3, float param_4, float param_5, float param_6, ulong param_7, ulong param_8, float param_9, float param_10) {
	pos.x = param_1;
	pos.y = param_2;
	pos.z = param_3;
	unk_d58.x = param_4;
	unk_d58.y = param_5;
	unk_d58.z = param_6;
	unk_d64 = param_7;
	unk_d68 = param_8;
	u = param_9;
	v = param_10;
}

