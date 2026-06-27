#include "CBlokadaLevel3.h"

#include "GameSDK.h"
#include "CPlayerTPP.h"
#include "CHudGratka.h"

/* 419BA0-419BA1 00001	*/
void CBlokadaLevel3::OnActivate() {
}

/* 4262D0-4262FA 0002A	*/
void CBlokadaLevel3::OnLoadChunk(_ED_CHUNK param_1, std::ifstream& param_2) {
	if (param_1.chunkType == 15 && param_1.chunkDataSize == 200) {
		param_2.read(unk_2658, 200);
	}
}

/* 4408B0-440978 000C8	*/
void CBlokadaLevel3::Save(std::ostream& param_1) {
	_ED_CHUNK chunk;
	chunk.chunkType = GetObjectID();
	chunk.chunkDataSize = sizeof(CBlokadaLevel3SaveData);
	chunk.chunkEndPos = (int)param_1.tellp() + chunk.chunkDataSize + sizeof(_ED_CHUNK);
	param_1.write((char*) &chunk, sizeof(_ED_CHUNK));

	CBlokadaLevel3SaveData saveData;
	saveData.unk_00 = ((GameSDK*) GetGame())->unk_276c;
	saveData.unk_04 = GetPosition();
	param_1.write((char*) &saveData, sizeof(CBlokadaLevel3SaveData));
}

/* 440A30-440A57 00027	*/
CBlokadaLevel3::CBlokadaLevel3() {
	unk_2720 = NULL;
	unk_2724 = -1;
}

/* 440A80-440A8C 0000C	*/
CBlokadaLevel3::~CBlokadaLevel3() {
}

/* 440A90-440AEA 0005A	*/
void* CBlokadaLevel3::EXP() {
	return new CBlokadaLevel3();
}

/* 440AF0-440B62 00072	*/
void CBlokadaLevel3::OnActivateLevel() {
	EnableRendering(false);
	EnableFrustumPhysicsPause(false);
	unk_2720 = (cMagMeshObject*) MagGetObject("cube03");
	unk_2724 = LoadSound("data\\sounds\\papatka\\OdszukajKlucz.wav");
	float val = ((GameSDK*) GetGame())->FUN00401e10();
	SetVolume(unk_2724, val);
	StopSound(unk_2724);
}

/* 440B70-440C9D 0012D	*/
void CBlokadaLevel3::OnCollisionObject(cMagMeshObject* param_1) {
	if (strcmpi("CPlayerTPP", param_1->GetClassNameA()) != 0) {
		return;
	}
	if (((CPlayerTPP*) GetPlayerObject())->unk_3990 == NULL) {
		return;
	}

	if (((GameSDK*) GetGame())->unk_276c != 0) {
		EnableCollisionObjects(false);
		if (unk_2720 != NULL) {
			unk_2720->SetPosition(D3DXVECTOR3(-494.0f, 1104.0f, -875.0f));
		}
		((CPlayerTPP*) GetPlayerObject())->unk_3990->FUN0042d750(false);
		((GameSDK*) GetGame())->unk_276c = -1;
		return;
	}

	if (!IsPlaying(unk_2724)) {
		((CPlayerTPP*) GetPlayerObject())->FUN00409260();
		EnableCallHandlerOnPlaySoundEnd(unk_2724);
		PlaySoundA(unk_2724, false);
		if (((CPlayerTPP*) GetPlayerObject())->unk_3990 != NULL) {
			((CPlayerTPP*) GetPlayerObject())->unk_3990->FUN0042d810();
		}
	}
}

/* 440CA0-440CD8 00038	*/
void CBlokadaLevel3::OnPlaySoundEnd(int param_1) {
	if (param_1 != unk_2724) {
		return;
	}

	if (((CPlayerTPP*) GetPlayerObject())->unk_3990 != NULL) {
		((CPlayerTPP*) GetPlayerObject())->unk_3990->FUN0042d850();
	}
}

/* 440CE0-440D58 00078	*/
void CBlokadaLevel3::Load(std::ifstream& param_1, _ED_CHUNK param_2) {
	if (param_2.chunkDataSize != 16) {
		return; 
	}

	CBlokadaLevel3SaveData local_10;
	param_1.read((char*) &local_10, sizeof(CBlokadaLevel3SaveData));
	((GameSDK*) GetGame())->unk_276c = local_10.unk_00;
	SetPosition(local_10.unk_04);

	if (((GameSDK*) GetGame())->unk_276c == 1) {
		EnableCollisionObjects(true);
	} else {
		EnableCollisionObjects(true);
	}
	GetGame();
}