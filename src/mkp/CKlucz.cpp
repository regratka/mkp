#include "CKlucz.h"

#include "GameSDK.h"
#include "CPlayerTPP.h"

/* 419BA0-419BA1 00001	*/
void CKlucz::OnActivateLevel() {
}

/* 432B30-432B50 00020	*/
CKlucz::CKlucz() {
	unk_2658 = false;
	unk_2659 = false;
}

/* 432B70-432B7B 0000B	*/
CKlucz::~CKlucz() {
}

/* 432B80-432BDA 0005A	*/
void* CKlucz::EXP() {
	return new CKlucz();
}

/* 432BE0-432C33 00053	*/
void CKlucz::OnCollisionObject(cMagMeshObject* param_1) {
	if (strcmpi("CPlayerTPP", param_1->GetClassNameA()) != 0) {
		return;
	}

	((GameSDK*) GetGame())->unk_276c = 1;
	Hide();
	((CPlayerTPP*) GetPlayerObject())->unk_3990->FUN0042d730(true);
}

/* 432C40-432CFB 000BB	*/
void CKlucz::Load(std::ifstream& param_1, _ED_CHUNK param_2) {
	if (param_2.chunkDataSize != sizeof(CKluczSaveData)) {
		return;
	}
	CKluczSaveData saveData;
	param_1.read((char*) &saveData, sizeof(CKluczSaveData));
	unk_2658 = saveData.unk_00;
	unk_2659 = saveData.unk_04;

	((GameSDK*) GetGame())->unk_276c = saveData.unk_08;

	if (((GameSDK*) GetGame())->unk_276c == 1) {
		((CPlayerTPP*) GetPlayerObject())->unk_3990->FUN0042d750(true);
	} else if (((GameSDK*) GetGame())->unk_276c == 0 
			|| ((GameSDK*) GetGame())->unk_276c == -1) {
		((CPlayerTPP*) GetPlayerObject())->unk_3990->FUN0042d750(false);
	}

	if (unk_2659) {
		Show();
	}

	if (unk_2658) {
		Hide();
	}
}

/* 432E60-432E65 00005	*/
void CKlucz::OnActivate() {
	Show();
}

/* 432E70-432F12 000A2	*/
void CKlucz::Show() {
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
void CKlucz::Hide() {
	EnableCollisionObjects(false);
	SetCollAction(0);
	EnableRendering(false);
	SetFreeRotationMatrix(false);
	DisableCallHandler("OnCollisionObject");
	unk_2658 = true;
	unk_2659 = false;
}

/* 432FD0-43308D 000BD	*/
void CKlucz::Save(std::ostream& param_1) {
	_ED_CHUNK chunk;
	chunk.chunkType = GetObjectID();
	chunk.chunkDataSize = sizeof(CKluczSaveData);
	chunk.chunkEndPos = (int)param_1.tellp() + chunk.chunkDataSize + sizeof(_ED_CHUNK);
	param_1.write((char*) &chunk, sizeof(_ED_CHUNK));

	CKluczSaveData saveData;
	saveData.unk_04 = unk_2659;
	saveData.unk_00 = unk_2658;
	saveData.unk_08 = ((GameSDK*) GetGame())->unk_276c;
	param_1.write((char*) &saveData, sizeof(CKluczSaveData));
}

