#include "cMagUtility.h"

/* 10006450-10006525 000D5	*/
cMagUtility::cMagUtility(cMagUtility* param_1) {
}

/* 10006530-100065F9 000C9	*/
cMagUtility* cMagUtility::operator=(cMagUtility* param_1) {
	return 0;
}

/* 1002D170-1002D1EE 0007E	*/
cMagUtility::cMagUtility() {
}

/* 1002D1F0-1002D1FB 0000B	*/
cMagUtility::~cMagUtility() {
}

/* 1002D200-1002D20D 0000D	*/
void cMagUtility::InitDeviceDx(cMagGameObject* param_1) {
}

/* 1002D210-1002D253 00043	*/
void cMagUtility::D3DUtil_InitMaterial(_D3DMATERIAL8* param_1, float param_2, float param_3, float param_4, float param_5) {
}

/* 1002D260-1002D2D2 00072	*/
void cMagUtility::D3DUtil_InitLight(uchar param_1, _D3DLIGHTTYPE param_2, float param_3, float param_4, float param_5) {
}

/* 1002D2E0-1002D661 00381	*/
long cMagUtility::CreateQuad(IDirect3DVertexBuffer8** param_1, D3DPOOL param_2, float param_3, ulong param_4, IDirect3DDevice8* param_5, float param_6, float param_7, bool param_8) {
	return 0;
}

/* 1002DE90-1002DF8F 000FF	*/
int cMagUtility::LoadBitmapToSurface(char* param_1, IDirect3DSurface8** param_2, uchar param_3) {
	return 0;
}

/* 1002DF90-1002E070 000E0	*/
long cMagUtility::LoadAlphabet(char* param_1, int param_2, int param_3) {
	return 0;
}

/* 1002E070-1002E09B 0002B	*/
long cMagUtility::UnloadAlphabet() {
	return 0;
}

/* 1002E0A0-1002E270 001D0	*/
void cMagUtility::PrintChar(int param_1, int param_2, char param_3, int param_4, ulong param_5, ulong* param_6, int param_7) {
}

/* 1002E270-1002E2EF 0007F	*/
void cMagUtility::PrintString(int param_1, int param_2, char* param_3, int param_4, ulong param_5, ulong* param_6, int param_7) {
}

/* 1002E2F0-1002E4FA 0020A	*/
long cMagUtility::CopySurfaceToSurface(tagRECT* param_1, IDirect3DSurface8* param_2, tagPOINT* param_3, IDirect3DSurface8* param_4, int param_5, ulong param_6) {
	return 0;
}

