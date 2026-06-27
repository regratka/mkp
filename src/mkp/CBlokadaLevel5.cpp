#include "CBlokadaLevel5.h"

#include "GameSDK.h"
#include "CPlayerTPP.h"

/* 419BA0-419BA1 00001	*/
void CBlokadaLevel5::OnActivate() {
}

/* 4262D0-4262FA 0002A	*/
void CBlokadaLevel5::OnLoadChunk(_ED_CHUNK param_1, std::ifstream& param_2) {
	if (param_1.chunkType == 15 && param_1.chunkDataSize == 200) {
		param_2.read(unk_2658, 200);
	}
}

/* 4408B0-440978 000C8	*/
void CBlokadaLevel5::Save(std::ostream& param_1) {
	_ED_CHUNK chunk;
	chunk.chunkType = GetObjectID();
	chunk.chunkDataSize = sizeof(CBlokadaLevel5SaveData);
	chunk.chunkEndPos = (int)param_1.tellp() + chunk.chunkDataSize + sizeof(_ED_CHUNK);
	param_1.write((char*) &chunk, sizeof(_ED_CHUNK));

	CBlokadaLevel5SaveData saveData;
	saveData.unk_00 = ((GameSDK*) GetGame())->unk_276c;
	saveData.unk_04 = GetPosition();
	param_1.write((char*) &saveData, sizeof(CBlokadaLevel5SaveData));
}

/* 4415C0-4415E7 00027	*/
CBlokadaLevel5::CBlokadaLevel5() {
	unk_2720 = -1;
	hud = NULL;
}

/* 441610-44161C 0000C	*/
CBlokadaLevel5::~CBlokadaLevel5() {
}

/* 441620-44167A 0005A	*/
void* CBlokadaLevel5::EXP() {
	return new CBlokadaLevel5();
}

/* 441680-4416EE 0006E	*/
void CBlokadaLevel5::OnCollisionObject(cMagMeshObject* param_1) {
	if (strcmpi("CMotorboat", param_1->GetClassNameA()) != 0) {
		return;
	}

	if (hud == NULL) {
		return;
	}

	if (hud->FUN0042d450() >= 29) {
		DisableCallHandler("OnCollisionObject");
		GetGame()->LoadLevel("data\\levels\\Level06\\Level06.lev");
		return;
	}

	hud->FUN0042CC30(true);
}

/* 441860-441887 00027	*/
void CBlokadaLevel5::OnActivateLevel() {
	EnableRendering(false);
	EnableFrustumPhysicsPause(false);
	hud = (CHudGratka*) MagGetObject("HUD");
}

/* 441900-441920 00020	*/
void CBlokadaLevel5::OnPlaySoundEnd(int param_1) {
	if (unk_2720 == param_1 && hud != NULL) {
		hud->FUN0042d850();
	}
}

/* 441920-441994 00074	*/
void CBlokadaLevel5::Load(std::ifstream& param_1, _ED_CHUNK param_2) {
	if (param_2.chunkDataSize != 16) {
		return; 
	}

	CBlokadaLevel5SaveData local_10;
	param_1.read((char*) &local_10, sizeof(CBlokadaLevel5SaveData));
	((GameSDK*) GetGame())->unk_276c = local_10.unk_00;
	SetPosition(local_10.unk_04);

	if (((GameSDK*) GetGame())->unk_276c == 1) {
		EnableCollisionObjects(true);
	} else {
		EnableCollisionObjects(true);
	}
}