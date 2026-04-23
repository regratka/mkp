#include "cMagFx.h"

/* 10077490-100777A7 00317	*/
cMagFx::cMagFx() {
	SetClassName("cMagFx");

}

/* 100777B0-100777BB 0000B	*/
cMagFx::~cMagFx() {
}

/* 100777C0-10077845 00085	*/
void cMagFx::SetPosition(D3DXVECTOR3 param_1) {
}

/* 10077850-100778D5 00085	*/
void cMagFx::SetScale(D3DXVECTOR3 param_1) {
}

/* 100778E0-1007793B 0005B	*/
void cMagFx::AddTexture(char* param_1) {
	strcpy(this->shockwaveName, param_1);
	RestoreDeviceObjects(param_1, 10.0f, 5.0f, 32, 30.1f, 1.0f);
}

/* 10077940-10077963 00023	*/
void cMagFx::Restore() {
	RestoreDeviceObjects(shockwaveName, 10.0f, 5.0f, 32, 30.1f, 1.0f);
}

/* 10077970-10077BAC 0023C	*/
void cMagFx::OnRender() {
}

/* 10077BB0-10077EAD 002FD	*/
float cMagFx::DXUtil_Timer(TIMER_COMMAND param_1) {
	return 0;
}

