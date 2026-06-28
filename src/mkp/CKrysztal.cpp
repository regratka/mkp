#include "CKrysztal.h"

#include "GameSDK.h"
#include "CPlayerTPP.h"

/* 419BA0-419BA1 00001	*/
void CKrysztal::OnActivateLevel() {
}

/* 432DB0-432DD0 00020	*/
CKrysztal::CKrysztal() {
	unk_2658 = false;
	unk_2659 = false;
}

/* 432DF0-432DFB 0000B	*/
CKrysztal::~CKrysztal() {
}

/* 432E00-432E5A 0005A	*/
void*  CKrysztal::EXP() {
	return new CKrysztal();
}

/* 432E60-432E65 00005	*/
void CKrysztal::OnActivate() {
	Show();
}

/* 432E70-432F12 000A2	*/
void CKrysztal::Show() {
	EnableCollisionObjects(true);
	SetCollisionType(2);
	SetCollAction(0);
	EnableRendering(true);
	EnableCollision(true);
	SetGravityAcceleration(0.0f);
	SetFreeRotationMatrix(true);
	SetAngSpeed(D3DXVECTOR3(0.0f, 100.0f, 0.0f));
	EnableCallHandler("OnCollisionObject");
	unk_2658 = false;
	unk_2659 = true;
}

/* 432F20-432F65 00045	*/
void CKrysztal::Hide() {
	EnableCollisionObjects(false);
	SetCollAction(0);
	EnableRendering(false);
	SetFreeRotationMatrix(false);
	DisableCallHandler("OnCollisionObject");
	unk_2658 = true;
	unk_2659 = false;
}

/* 432F70-432FC3 00053	*/
void CKrysztal::OnCollisionObject(cMagMeshObject* param_1) {
	if (strcmpi("CPlayerTPP", param_1->GetClassNameA()) != 0) {
		return;
	}

	((GameSDK*) GetGame())->unk_276c = 1;
	Hide();
	((CPlayerTPP*) GetPlayerObject())->unk_3990->FUN0042d730(true);
}

/* 432FD0-43308D 000BD	*/
void CKrysztal::Save(std::ostream& param_1) {
	_ED_CHUNK chunk;
	chunk.chunkType = GetObjectID();
	chunk.chunkDataSize = sizeof(CKrysztalSaveData);
	chunk.chunkEndPos = (int)param_1.tellp() + chunk.chunkDataSize + sizeof(_ED_CHUNK);
	param_1.write((char*) &chunk, sizeof(_ED_CHUNK));

	CKrysztalSaveData saveData;
	saveData.unk_04 = unk_2659;
	saveData.unk_00 = unk_2658;
	saveData.unk_08 = ((GameSDK*) GetGame())->unk_276c;
	param_1.write((char*) &saveData, sizeof(CKrysztalSaveData));
}

/* 433090-433102 00072	*/
void CKrysztal::Load(std::ifstream& param_1, _ED_CHUNK param_2) {
	if (param_2.chunkDataSize != sizeof(CKrysztalSaveData)) {
		return;
	}
	CKrysztalSaveData saveData;
	param_1.read((char*) &saveData, sizeof(CKrysztalSaveData));
	unk_2658 = saveData.unk_00;
	unk_2659 = saveData.unk_04;

	((GameSDK*) GetGame())->unk_276c = saveData.unk_08;

	if (unk_2659) {
		Show();
	}

	if (unk_2658) {
		Hide();
	}
}