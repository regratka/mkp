#include "cMagFrustumCull.h"

/* 10003A00-10003B4C 0014C	*/
cMagFrustumCull::cMagFrustumCull(cMagFrustumCull* param_1) {
}

/* 10003B50-10003E2D 002DD	*/
cMagFrustumCull* cMagFrustumCull::operator=(cMagFrustumCull* param_1) {
	return 0;
}

/* 10003E30-10003E87 00057	*/
cMagFrustumCull* cMagFrustumCull::scalar_destructor(uchar param_1) {
	return 0;
}

/* 10089A80-10089B56 000D6	*/
cMagFrustumCull::cMagFrustumCull() {
}

/* 10089B60-10089C48 000E8	*/
cMagFrustumCull::~cMagFrustumCull() {
}

/* 10089C50-10089F84 00334	*/
HRESULT cMagFrustumCull::ComputeBoundingBox(D3DXVECTOR3 param_1, D3DXVECTOR3 param_2) {
	return 0;
}

/* 10089F90-1008A198 00208	*/
void cMagFrustumCull::UpdateBB(D3DXVECTOR3 param_1, D3DXVECTOR3 param_2, D3DXMATRIX& param_3) {
}

/* 1008A1A0-1008A202 00062	*/
void cMagFrustumCull::DrawBoundingBox(D3DXMATRIX param_1, D3DXMATRIX param_2) {
}

/* 1008A210-1008A756 00546	*/
void cMagFrustumCull::CreateBox() {
}

/* 1008A760-1008A789 00029	*/
void cMagFrustumCull::CullObjects() {
}

/* 1008A790-1008B55F 00DCF	*/
CULLSTATE cMagFrustumCull::CullObject(CULLINFO* param_1, uchar param_2, D3DXPLANE* param_3) {
	return CULLSTATE();
}

/* 1008B560-1008B7D6 00276	*/
int cMagFrustumCull::EdgeIntersectsFace(uchar param_1, uchar param_2, D3DXPLANE* param_3) {
	return 0;
}

/* 1008B7E0-1008BA39 00259	*/
void cMagFrustumCull::UpdateCullInfo(CULLINFO* param_1, uchar param_2, uchar param_3) {
}

/* 1008BA40-1008BA56 00016	*/
void cMagFrustumCull::UpdateCull(D3DXMATRIX* param_1, D3DXMATRIX* param_2) {
}

/* 1008BA60-1008BDE6 00386	*/
long cMagFrustumCull::UpdatePlaneVBs() {
	return 0;
}

/* 1008BE00-1008BE25 00025	*/
uchar cMagFrustumCull::GetCenterBox(uint* param_1) {
	return 0;
}

/* 1008BE30-1008C054 00224	*/
void cMagFrustumCull::AddLine(uchar param_1, uchar param_2, uchar param_3, uint param_4, uint param_5, uint param_6) {
}

/* 1008C060-1008C119 000B9	*/
void cMagFrustumCull::InitLine() {
}

/* 1008C120-1008C2C7 001A7	*/
void cMagFrustumCull::RenderLines() {
}

