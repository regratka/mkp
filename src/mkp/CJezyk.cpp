#include "CJezyk.h"

/* 4164E0-4164E3 00003	*/
void CJezyk::OnDestTime(float param_1) {
}

/* 419BA0-419BA1 00001	*/
void CJezyk::OnActivate() {
}

/* 4262D0-4262FA 0002A	*/
void CJezyk::OnLoadChunk(_ED_CHUNK param_1, std::ifstream& param_2) {
	if (param_1.chunkType == 15 && param_1.chunkDataSize == 200) {
		// param_2.read(unk_2658, 200);
	}
}

/* 43D110-43D255 00145	*/
CJezyk::CJezyk() {
}

/* 43D280-43D2BC 0003C	*/
CJezyk::~CJezyk() {
}

/* 43D2C0-43D31A 0005A	*/
void* CJezyk::EXP() {
	return new CJezyk();
}

/* 43D320-43D41E 000FE	*/
void CJezyk::OnActivateLevel() {
}

/* 43D420-43D4D0 000B0	*/
void CJezyk::FUN0043d420() {
}

/* 43D4D0-43D4F4 00024	*/
void CJezyk::OnPlaySoundEnd(int param_1) {
}

/* 43D500-43D5E6 000E6	*/
void CJezyk::FUN0043d500() {
}

/* 43D5F0-43D613 00023	*/
void CJezyk::FUN0043d5f0() {
}

/* 43D620-43D7B2 00192	*/
void CJezyk::FUN0043d620() {
}

/* 419BA0-419BA1 00001	*/
void CJezyk::Idle::OnFrame() {
}

/* 419BA0-419BA1 00001	*/
void CJezyk::Idle::OnExitState() {
}

/* 43DC50-43DC70 00020	*/
void CJezyk::Idle::OnEnterState() {
}

/* 419BA0-419BA1 00001	*/
void CJezyk::WalkNaviPath::OnExitState() {
}

/* 43D7C0-43D894 000D4	*/
void CJezyk::WalkNaviPath::OnEnterState() {
}

/* 43D8A0-43DAB4 00214	*/
void CJezyk::WalkNaviPath::OnFrame() {
}

/* 43DAC0-43DB60 000A0	*/
void CJezyk::WalkNaviPath::OnDestinationPos(D3DXVECTOR3 param_1) {
}

/* 43DB60-43DC26 000C6	*/
void CJezyk::WalkNaviPath::OnCollisionObject(cMagMeshObject* param_1) {
}

/* 43DC30-43DC45 00015	*/
void CJezyk::WalkNaviPath::OnAnimEnd(char* param_1) {
}

