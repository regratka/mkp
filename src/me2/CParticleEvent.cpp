#include "CParticleEvent.h"

/* 1000F000-1000F001 00001	*/
void CParticleEvent::InvalidateDeviceObjects() {
}

/* 10012BA0-10012BA3 00003	*/
void CParticleEvent::RestoreDeviceObjects(uchar param_1) {
}

/* 1001D4C0-1001D4E6 00026	*/
CParticleEvent::CParticleEvent() {
}

/* 1001D4F0-1001D54B 0005B	*/
CParticleEvent::~CParticleEvent() {
}

/* 1001D550-1001D572 00022	*/
CMinMax<float>* CParticleEvent::GetTimeRange() {
	return 0;
}

/* 1001D580-1001D597 00017	*/
void CParticleEvent::SetTimeRange(uint param_1, uint param_2) {
}

/* 1001D5A0-1001D5A7 00007	*/
float CParticleEvent::GetActualTime() {
	return 0;
}

/* 1001D5B0-1001D5BD 0000D	*/
void CParticleEvent::SetActualTime(float param_1) {
}

/* 1001D5C0-1001D5C7 00007	*/
bool CParticleEvent::IsFade() {
	return 0;
}

/* 1001D5D0-1001D5DD 0000D	*/
void CParticleEvent::SetFade(bool param_1) {
}

/* 1001D5E0-1001D6F7 00117	*/
CParticleEvent::CParticleEvent(CParticleEvent* param_1) {
}

/* 1001D700-1001D805 00105	*/
CParticleEvent* CParticleEvent::operator=(CParticleEvent* param_1) {
	return 0;
}

/* 1001D810-1001D867 00057	*/
CParticleEvent* CParticleEvent::scalar_destructor(uchar param_1) {
	return 0;
}

/* 1006AFB0-1006B02E 0007E	*/
void CParticleEvent::ProcessPropEqualsValue(CMinMax<float>* param_1, CParticleEmitterToken** param_2, CParticleEmitterToken** param_3) {
}

/* 1006B030-1006B0AE 0007E	*/
void CParticleEvent::ProcessPropEqualsValue(CMinMax<D3DXVECTOR3>* param_1, CParticleEmitterToken** param_2, CParticleEmitterToken** param_3) {
}

/* 1006B0B0-1006B12E 0007E	*/
void CParticleEvent::ProcessPropEqualsValue(CMinMax<D3DXCOLOR>* param_1, CParticleEmitterToken** param_2, CParticleEmitterToken** param_3) {
}

