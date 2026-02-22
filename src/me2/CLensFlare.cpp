#include "CLensFlare.h"

/* 10022600-10022622 00022	*/
CMinMax<float> CLensFlare::GetIntensity(uint* param_1) {
	return CMinMax<float>();
}

/* 10022630-10022648 00018	*/
void CLensFlare::SetIntensity(CMinMax<float>* param_1) {
}

/* 10022650-10022657 00007	*/
float CLensFlare::GetIntensityBorder() {
	return 0;
}

/* 10022660-1002266D 0000D	*/
void CLensFlare::SetIntensityBorder(float param_1) {
}

/* 10022670-10022691 00021	*/
uchar CLensFlare::GetPosition(uint* param_1) {
	return 0;
}

/* 100226A0-100229AE 0030E	*/
CLensFlare::CLensFlare(CLensFlare* param_1) {
}

/* 100229B0-10022C99 002E9	*/
CLensFlare* CLensFlare::operator=(CLensFlare* param_1) {
	return 0;
}

/* 10022CA0-10022CF7 00057	*/
CLensFlare* CLensFlare::scalar_destructor(uchar param_1) {
	return 0;
}

/* 10074110-10074133 00023	*/
void CLensFlare::InitDeviceDx(cMagGameObject* param_1) {
}

/* 10074230-100742FE 000CE	*/
CLensFlare::CLensFlare() {
}

/* 10074300-100743BE 000BE	*/
CLensFlare::~CLensFlare() {
}

/* 100743C0-100743E6 00026	*/
long CLensFlare::RestoreDeviceObjects(IDirect3DDevice8* param_1) {
	return 0;
}

/* 100743F0-10074455 00065	*/
long CLensFlare::RecreateVB() {
	return 0;
}

/* 10074460-10074484 00024	*/
void CLensFlare::InvalidateDeviceObjects() {
}

/* 10074490-100746B9 00229	*/
void CLensFlare::CalcLightSourceScreenCoords(uchar param_1, uchar param_2, uchar param_3, uchar param_4, uchar param_5, uchar param_6, uchar param_7, uchar param_8, uchar param_9, uint param_10, uint param_11) {
}

/* 100746C0-100747D2 00112	*/
void CLensFlare::Render() {
}

/* 100747E0-10075756 00F76	*/
void CLensFlare::Render(int param_1, int param_2, int param_3, int param_4, bool param_5) {
}

/* 10075760-100757DA 0007A	*/
void CLensFlare::DeleteTextures() {
}

/* 100757E0-10075903 00123	*/
void CLensFlare::DeleteSpots() {
}

/* 10075910-10075AF0 001E0	*/
uchar CLensFlare::AddTexture(char* param_1) {
	return 0;
}

/* 10075AF0-10075C96 001A6	*/
void CLensFlare::AddSpot(int param_1, CLensFlareSpot* param_2) {
}

/* 10075CA0-10075E0D 0016D	*/
void CLensFlare::DeleteSpots(int param_1) {
}

/* 10075E10-10075E2D 0001D	*/
void CLensFlare::SetPosition(D3DXVECTOR3 param_1) {
}

/* 10075E30-10075EED 000BD	*/
void CLensFlare::OnRender() {
}

/* 10075EF0-10075EFD 0000D	*/
void CLensFlare::EnableRendering(bool param_1) {
}

/* 10075F00-10075F07 00007	*/
bool CLensFlare::IsEnabled() {
	return 0;
}

/* 10075F10-10076028 00118	*/
bool CLensFlare::TestVisibility() {
	return 0;
}

