#include "CBlokadaLevel1.h"

#include "GameSDK.h"
#include "CPlayerTPP.h"

/* 419BA0-419BA1 00001	*/
void CBlokadaLevel1::OnActivate() {
}

/* 4262D0-4262FA 0002A	*/
void CBlokadaLevel1::OnLoadChunk(_ED_CHUNK param_1, std::ifstream& param_2) {
	if (param_1.chunkType == 15 && param_1.chunkDataSize == 200) {
		param_2.read(unk_2658, 200);
	}
}

/* 4406C0-4406DD 0001D	*/
CBlokadaLevel1::CBlokadaLevel1() {
	unk_2720 = -1;

}

/* 440700-44070C 0000C	*/
CBlokadaLevel1::~CBlokadaLevel1() {
}

/* 440710-44076A 0005A	*/
void* CBlokadaLevel1::EXP() {
	return new CBlokadaLevel1();
}

/* 440770-4407CF 0005F	*/
void CBlokadaLevel1::OnActivateLevel() {
	enableRendering = false;
	EnableFrustumPhysicsPause(false);
	unk_2720 = LoadSound("data\\sounds\\papatka\\level01_jezowa.wav");
	float val = ((GameSDK*) GetGame())->FUN00401e10();
	SetVolume(unk_2720, val);
	StopSound(unk_2720);
}

/* 4407D0-4408A3 000D3	*/
void CBlokadaLevel1::OnCollisionObject(cMagMeshObject* param_1) {
	if (strcmpi("CPlayerTPP", param_1->GetClassNameA()) != 0) {
		return;
	}
	if (((CPlayerTPP*) GetPlayerObject())->unk_3990 == NULL) {
		return;
	}

	if (((CPlayerTPP*) GetPlayerObject())->unk_3990->FUN0042d450() >= 28) {
		EnableCollisionObjects(false);
		return;
	}

	if (!IsPlaying(unk_2720)) {
		((CPlayerTPP*) GetPlayerObject())->FUN00409260();
		PlaySoundA(unk_2720, false);
		EnableCallHandlerOnPlaySoundEnd(unk_2720, this);
		if (((CPlayerTPP*) GetPlayerObject())->unk_3990 != NULL) {
			((CPlayerTPP*) GetPlayerObject())->unk_3990->FUN0042d810();
		}
		((CPlayerTPP*) GetPlayerObject())->unk_3990->FUN0042CC30(1);
	}
}

/* 4408B0-440978 000C8	*/
void CBlokadaLevel1::Save(std::ostream& param_1) {
	_ED_CHUNK chunk;
	chunk.chunkType = GetObjectID();
	chunk.chunkDataSize = sizeof(CBlokadaLevel1SaveData);
	chunk.chunkEndPos = (int)param_1.tellp() + chunk.chunkDataSize + sizeof(_ED_CHUNK);
	param_1.write((char*) &chunk, sizeof(_ED_CHUNK));

	CBlokadaLevel1SaveData saveData;
	saveData.unk_00 = ((GameSDK*) GetGame())->unk_276c;
	saveData.unk_04 = GetPosition();
	param_1.write((char*) &saveData, sizeof(CBlokadaLevel1SaveData));
}

/* 4414D0-44150A 0003A	*/
void CBlokadaLevel1::OnPlaySoundEnd(int param_1) {
	if (unk_2720 != param_1) {
		return;
	}

	if (((CPlayerTPP*) GetPlayerObject())->unk_3990 != NULL) {
		((CPlayerTPP*) GetPlayerObject())->unk_3990->FUN0042d850();
	}
}

/* 441920-441994 00074	*/
void CBlokadaLevel1::Load(std::ifstream& param_1, _ED_CHUNK param_2) {
	if (param_2.chunkDataSize != 16) {
		return; 
	}

	CBlokadaLevel1SaveData local_10;
	param_1.read((char*) &local_10, sizeof(CBlokadaLevel1SaveData));
	((GameSDK*) GetGame())->unk_276c = local_10.unk_00;
	SetPosition(local_10.unk_04);

	if (((GameSDK*) GetGame())->unk_276c == 1) {
		EnableCollisionObjects(true);
	} else {
		EnableCollisionObjects(true);
	}
}

