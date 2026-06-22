#include "CBlokadaLevel3_1.h"
#include "GameSDK.h"
#include "CPlayerTPP.h"

/* 419BA0-419BA1 00001	*/
void CBlokadaLevel3_1::OnActivate() {
}

/* 4262D0-4262FA 0002A	*/
void CBlokadaLevel3_1::OnLoadChunk(_ED_CHUNK param_1, std::ifstream& param_2) {
	if (param_1.chunkType == 15 && param_1.chunkDataSize == 200) {
		param_2.read(unk_2658, 200);
	}
}

/* 4329E0-4329F0 00010	*/
void CBlokadaLevel3_1::OnActivateLevel() {
	enableRendering = false;
	EnableFrustumPhysicsPause(false);
}

/* 440E10-440E2D 0001D	*/
CBlokadaLevel3_1::CBlokadaLevel3_1() {
	unk_2720 = -1;
}

/* 440E50-440E5C 0000C	*/
CBlokadaLevel3_1::~CBlokadaLevel3_1() {
}

/* 440E60-440EBA 0005A	*/
void* CBlokadaLevel3_1::EXP() {
	return new CBlokadaLevel3_1();
}

/* 440EC0-440F49 00089	*/
void CBlokadaLevel3_1::OnCollisionObject(cMagMeshObject* param_1) {
	if (strcmpi("CPlayerTPP", param_1->GetClassNameA()) != 0) {
		return;
	}
	if (((CPlayerTPP*) GetPlayerObject())->unk_3990 == NULL) {
		return;
	}

	if (((CPlayerTPP*) GetPlayerObject())->unk_3990->FUN0042d450() >= 27) {
		DisableCallHandler("OnCollisionObject");
		GetGame()->LoadLevel("data\\levels\\Level04\\level04.lev");
		return;
	}

	((CPlayerTPP*) GetPlayerObject())->unk_3990->FUN0042CC30(true);
}

/* 4408B0-440978 000C8	*/
void CBlokadaLevel3_1::Save(std::ostream& param_1) {
	_ED_CHUNK chunk;
	chunk.chunkType = GetObjectID();
	chunk.chunkDataSize = sizeof(CBlokadaLevel3_1SaveData);
	chunk.chunkEndPos = (int)param_1.tellp() + chunk.chunkDataSize + sizeof(_ED_CHUNK);
	param_1.write((char*) &chunk, sizeof(_ED_CHUNK));

	CBlokadaLevel3_1SaveData saveData;
	saveData.unk_00 = ((GameSDK*) GetGame())->unk_276c;
	saveData.unk_04 = GetPosition();
	param_1.write((char*) &saveData, sizeof(CBlokadaLevel3_1SaveData));
}

/* 4414D0-44150A 0003A	*/
void CBlokadaLevel3_1::OnPlaySoundEnd(int param_1) {
	if (unk_2720 != param_1) {
		return;
	}

	if (((CPlayerTPP*) GetPlayerObject())->unk_3990 != NULL) {
		((CPlayerTPP*) GetPlayerObject())->unk_3990->FUN0042d850();
	}
}

/* 441920-441994 00074	*/
void CBlokadaLevel3_1::Load(std::ifstream& param_1, _ED_CHUNK param_2) {
	if (param_2.chunkDataSize != 16) {
		return; 
	}

	CBlokadaLevel3_1SaveData local_10;
	param_1.read((char*) &local_10, sizeof(CBlokadaLevel3_1SaveData));
	((GameSDK*) GetGame())->unk_276c = local_10.unk_00;
	SetPosition(local_10.unk_04);

	if (((GameSDK*) GetGame())->unk_276c == 1) {
		EnableCollisionObjects(true);
	} else {
		EnableCollisionObjects(true);
	}
}
