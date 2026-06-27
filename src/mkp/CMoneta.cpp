#include "CMoneta.h"

#include "CPlayerTPP.h"
#include "CMotorboat.h"

/* 419BA0-419BA1 00001	*/
void CMoneta::OnActivateLevel() {
}

/* 432E60-432E65 00005	*/
void CMoneta::OnActivate() {
	Show();
}

/* 432E70-432F12 000A2	*/
void CMoneta::Show() {
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
void CMoneta::Hide() {
	EnableCollisionObjects(false);
	SetCollAction(0);
	EnableRendering(false);
	SetFreeRotationMatrix(false);
	DisableCallHandler("OnCollisionObject");
	unk_2658 = true;
	unk_2659 = false;
}

/* 4331C0-4331E0 00020	*/
CMoneta::CMoneta() {
	unk_2658 = false;
	unk_2659 = false;
}

/* 433200-43320B 0000B	*/
CMoneta::~CMoneta() {
}

/* 433210-43326A 0005A	*/
void* CMoneta::EXP() {
	return new CMoneta();
}

/* 433270-4332D1 00061	*/
void CMoneta::OnCollisionObject(cMagMeshObject* param_1) {
	if (strcmpi("CPlayerTPP", param_1->GetClassNameA()) == 0) {
		((CPlayerTPP*) param_1)->FUN0040A150();
		Hide();
	}

	if (strcmpi("CMotorboat", param_1->GetClassNameA()) == 0) {
		((CMotorboat*) param_1)->FUN0040daf0();
		Hide();
	}
}

/* 4332E0-43338B 000AB	*/
void CMoneta::Save(std::ostream& param_1) {
	_ED_CHUNK chunk;
	chunk.chunkType = GetObjectID();
	chunk.chunkDataSize = sizeof(CMonetaSaveData);
	chunk.chunkEndPos = (int)param_1.tellp() + chunk.chunkDataSize + sizeof(_ED_CHUNK);
	param_1.write((char*) &chunk, sizeof(_ED_CHUNK));

	CMonetaSaveData saveData;
	saveData.unk_04 = unk_2659;
	saveData.unk_00 = unk_2658;
	param_1.write((char*) &saveData, sizeof(CMonetaSaveData));
}

/* 433390-4333EA 0005A	*/
void CMoneta::Load(std::ifstream& param_1, _ED_CHUNK param_2) {
	if (param_2.chunkDataSize != sizeof(CMonetaSaveData)) {
		return;
	}
	CMonetaSaveData saveData;
	param_1.read((char*) &saveData, sizeof(CMonetaSaveData));
	unk_2658 = saveData.unk_00;
	unk_2659 = saveData.unk_04;
	if (unk_2659) {
		Show();
	}

	if (unk_2658) {
		Hide();
	}
}

