#include "CSplineCamera.h"

/* 10090470-10090703 00293	*/
CSplineCamera::CSplineCamera(CSplineCamera* param_1) {
}

/* 10090710-100909EA 002DA	*/
CSplineCamera* CSplineCamera::operator=(CSplineCamera* param_1) {
	return 0;
}

/* 100909F0-10090A47 00057	*/
bool* CSplineCamera::scalar_destructor(uchar param_1) {
	return 0;
}

/* 100BCC80-100BCD59 000D9	*/
CSplineCamera::CSplineCamera() {
}

/* 100BCD60-100BCE88 00128	*/
CSplineCamera::~CSplineCamera() {
}

/* 100BCE90-100BD0A4 00214	*/
void CSplineCamera::AddFrameKey(D3DXVECTOR3 param_1, float param_2, float param_3, float param_4, D3DXVECTOR3 param_5) {
}

/* 100BD0B0-100BD0FF 0004F	*/
void CSplineCamera::Play(float param_1) {
}

/* 100BD100-100BD108 00008	*/
void CSplineCamera::Stop() {
}

/* 100BD110-100BD1F5 000E5	*/
void CSplineCamera::Play(float param_1, float param_2) {
}

/* 100BD200-100BD20D 0000D	*/
void CSplineCamera::SetTimeAdjust(float param_1) {
}

/* 100BD210-100BD217 00007	*/
float CSplineCamera::GetTimeAdjust() {
	return 0;
}

/* 100BD220-100BD89D 0067D	*/
float* CSplineCamera::Update(float* param_1, float param_2) {
	return 0;
}

/* 100BD8A0-100BD8D8 00038	*/
float CSplineCamera::GetTotalTime() {
	return 0;
}

/* 100BD8E0-100BD962 00082	*/
void CSplineCamera::DeleteFrame(int param_1) {
}

/* 100BD970-100BD9A0 00030	*/
CSplineControlPoint* CSplineCamera::GetFrameKeyAt(int param_1) {
	return 0;
}

/* 100BD9A0-100BD9D8 00038	*/
float CSplineCamera::GetTotalLen() {
	return 0;
}

/* 100BD9E0-100BD9ED 0000D	*/
void CSplineCamera::SetType(uchar param_1) {
}

/* 100BD9F0-100BD9F7 00007	*/
uchar CSplineCamera::GetType() {
	return 0;
}

/* 100BDA00-100BDA19 00019	*/
int CSplineCamera::GetFrameCount() {
	return 0;
}

/* 100BDA20-100BDA2D 0000D	*/
void CSplineCamera::SetFPS(float param_1) {
}

/* 100BDA30-100BDA37 00007	*/
float CSplineCamera::GetFPS() {
	return 0;
}

/* 100BDA40-100BDC1C 001DC	*/
void CSplineCamera::InsertFrameKey(CSplineControlPoint* param_1, int param_2) {
}

/* 100BDC20-100BDC7C 0005C	*/
void CSplineCamera::LookAt(D3DXVECTOR3 param_1) {
}

/* 100BDC80-100BDC99 00019	*/
void CSplineCamera::Roll(float param_1) {
}

/* 100BDCC0-100BDE65 001A5	*/
void CSplineCamera::CopyKeyFrames(CSplineCamera* param_1) {
}

/* 100BDE70-100BE00F 0019F	*/
void CSplineCamera::CopyKeyFrames(std::vector<CSplineControlPoint>* param_1) {
}

/* 100BE010-100BE16C 0015C	*/
void CSplineCamera::OnRender() {
}

/* 100BE170-100BE1FF 0008F	*/
void CSplineCamera::PlayReverse(float param_1) {
}

/* 100BE200-100BE20D 0000D	*/
void CSplineCamera::SetHandlerObject(cMagGameObject* param_1) {
}

/* 100BE210-100BE275 00065	*/
void CSplineCamera::SetDestTime(float param_1) {
}

/* 100BE280-100BE2A2 00022	*/
void CSplineCamera::ClearDestTime() {
}

/* 100BE2B0-100BE322 00072	*/
void CSplineCamera::CallDestTimeHandler(float param_1) {
}

/* 100BE330-100BE337 00007	*/
bool CSplineCamera::IsPlaying() {
	return 0;
}

/* 100BE340-100BE989 00649	*/
float* CSplineCamera::UpdateByLen(float* param_1, float param_2) {
	return 0;
}

/* 100BE990-100BE997 00007	*/
float CSplineCamera::GetCurLen() {
	return 0;
}

/* 100BE9A0-100BE9C2 00022	*/
float CSplineCamera::GetCurTime() {
	return 0;
}

/* 100BE9D0-100BE9DD 0000D	*/
void CSplineCamera::SetLerp(bool param_1) {
}

