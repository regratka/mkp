#include "CBlokadaLevel4.h"

#include "GameSDK.h"
#include "CPlayerTPP.h"

/* 4164E0-4164E3 00003 */ 
void CBlokadaLevel4::OnInputKey(uchar* param_1) {

}

/* 419BA0-419BA1 00001	*/
void CBlokadaLevel4::OnActivate() {
}

/* 4262D0-4262FA 0002A	*/
void CBlokadaLevel4::OnLoadChunk(_ED_CHUNK param_1, std::ifstream& param_2) {
	if (param_1.chunkType == 15 && param_1.chunkDataSize == 200) {
		param_2.read(unk_2658, 200);
	}
}

/* 441000-441027 00027	*/
CBlokadaLevel4::CBlokadaLevel4() {
	unk_2720 = NULL;
	unk_2730 = -1;
	
}

/* 441050-44105C 0000C	*/
CBlokadaLevel4::~CBlokadaLevel4() {
}

/* 441060-4410BA 0005A	*/
void* CBlokadaLevel4::EXP() {
	return new CBlokadaLevel4();
}

/* 4410C0-44116A 000AA	*/
void CBlokadaLevel4::OnActivateLevel() {
	enableRendering = false;
	EnableFrustumPhysicsPause(false);
	unk_2724 = GetPosition();
	unk_2720 = (cMagMeshObject*) MagGetObject("plane14");
	EnableCallHandler("OnInputKey");
	unk_2730 = LoadSound("data\\sounds\\papatka\\OdszukajKlucz.wav");
	float fVar4 = ((GameSDK*) GetGame())->FUN00401e10();
	SetVolume(unk_2730, fVar4);
	StopSound(unk_2730);
}

/* 441170-4411A8 00038	*/
void CBlokadaLevel4::OnPlaySoundEnd(int param_1) {
	if (param_1 != unk_2730) {
		return;
	}

	if (((CPlayerTPP*) GetPlayerObject())->unk_3990 != NULL) {
		((CPlayerTPP*) GetPlayerObject())->unk_3990->FUN0042d850();
	}
}

/* 4411B0-4412DD 0012D	*/
void CBlokadaLevel4::OnCollisionObject(cMagMeshObject* param_1) {
	if (strcmpi("CPlayerTPP", param_1->GetClassNameA()) != 0) {
		return;
	}
	if (((CPlayerTPP*) GetPlayerObject())->unk_3990 == NULL) {
		return;
	}
	if (((GameSDK*) GetGame())->unk_276c != 0) {
		EnableCollisionObjects(false);
		if (unk_2720 != NULL) {
			unk_2720->SetPosition(D3DXVECTOR3(372.0f, 2332.0f, -477.0f));
		}
		((CPlayerTPP*) GetPlayerObject())->unk_3990->FUN0042d750(false);
		((GameSDK*) GetGame())->unk_276c = -1;
		return;
	}

	if (!IsPlaying(unk_2730)) {
		((CPlayerTPP*) GetPlayerObject())->FUN00409260();
		EnableCallHandlerOnPlaySoundEnd(unk_2730);
		PlaySoundA(unk_2730, false);
		if (((CPlayerTPP*) GetPlayerObject())->unk_3990 != NULL) {
			((CPlayerTPP*) GetPlayerObject())->unk_3990->FUN0042d810();
		}
	}
}

/* 4408B0-440978 000C8	*/
void CBlokadaLevel4::Save(std::ostream& param_1) {
	_ED_CHUNK chunk;
	chunk.chunkType = GetObjectID();
	chunk.chunkDataSize = sizeof(CBlokadaLevel4SaveData);
	chunk.chunkEndPos = (int)param_1.tellp() + chunk.chunkDataSize + sizeof(_ED_CHUNK);
	param_1.write((char*) &chunk, sizeof(_ED_CHUNK));

	CBlokadaLevel4SaveData saveData;
	saveData.unk_00 = ((GameSDK*) GetGame())->unk_276c;
	saveData.unk_04 = GetPosition();
	param_1.write((char*) &saveData, sizeof(CBlokadaLevel4SaveData));
}

/* 441920-441994 00074	*/
void CBlokadaLevel4::Load(std::ifstream& param_1, _ED_CHUNK param_2) {
	if (param_2.chunkDataSize != 16) {
		return; 
	}

	CBlokadaLevel4SaveData local_10;
	param_1.read((char*) &local_10, sizeof(CBlokadaLevel4SaveData));
	((GameSDK*) GetGame())->unk_276c = local_10.unk_00;
	SetPosition(local_10.unk_04);

	if (((GameSDK*) GetGame())->unk_276c == 1) {
		EnableCollisionObjects(true);
	} else {
		EnableCollisionObjects(true);
	}
}
