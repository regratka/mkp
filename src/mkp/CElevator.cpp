#include "CElevator.h"
#include "GameSDK.h"

/* 41AFD0-41B04D 0007D	*/
CElevator::CElevator() {
	unk_2750 = 0;
	ZeroMemory(&chunkData, sizeof(CElevatorChunkData));
	unk_2758 = 400.0f;
	unk_275c = false;
	unk_275d = false;
	unk_2760 = 0.0f;
	unk_2764 = 0;
	unk_2768 = false;
	unk_2769 = false;
	unk_274c = false;
}

/* 41B070-41B0F1 00081	*/
CElevator::~CElevator() {
	unk_273c.clear();
}

/* 41B100-41B15A 0005A	*/
void* CElevator::EXP() {
	return new CElevator();
}

/* 41B160-41B314 001B4	*/
void CElevator::OnFrame() {
	if (chunkData.unk_04 != 0.0f) {
		float DVar5 = GetTickCount() / 1000.0f;
		if (chunkData.unk_04 < DVar5 - unk_2760 ) {
			unk_275c = true;
			unk_2760 = DVar5;
			if (chunkData.unk_0c != 0) {
				PlaySoundA(unk_2764, true);
			}
		}	
	}

	if (unk_275c && !unk_273c.empty()) {
		if (unk_274c && unk_2769) {
			SetSpeedValue(0.0f);
			return;
		}

		if (!unk_273c.empty()) {
			D3DXVECTOR3 dest(unk_273c[unk_2750].x, unk_273c[unk_2750].y, unk_273c[unk_2750].z);
			SetDestinationPos(dest, 30.0f);
			D3DXVECTOR3 pos = GetPosition();
			SetSpeed(dest - pos);
			SetSpeedValue(unk_2758);
		}
	}
}

/* 41B320-41B34C 0002C	*/
void CElevator::OnUpdateMenuSettings() {
	float fVar1 = ((GameSDK*) GetGame())->FUN00401e10();
	SetVolume(unk_2764, fVar1);
}

/* 41B350-41B359 00009	*/
void CElevator::OnActivate() {
	EnableFrustumPhysicsPause(false);
}

/* 41B360-41B3A5 00045	*/
void CElevator::OnDestinationPos(D3DXVECTOR3 param_1) {
	SetSpeedValue(0.0f);
	DisableCallHandler("OnFrame");
	unk_275c = false;
	if (chunkData.unk_0c != 0) {
		StopSound(unk_2764);
	}
	unk_2769 = true;
}

/* 41B3B0-41B4DE 0012E	*/
void CElevator::OnAction() {
	unk_2769 = false;
	float diff1 = D3DXVec3Length(&(GetPosition() - unk_273c[0]));
	float diff2 = D3DXVec3Length(&(GetPosition() - unk_273c[1]));
	if (diff1 > diff2) {
		unk_2750 = 0;
	} else {
		unk_2750 = 1;
	}

	if (chunkData.unk_04 != 0.0f) {
		unk_2760 = GetTickCount() * 0.001f;
	} else {
		unk_275c = true;
		if (chunkData.unk_0c != 0) {
			PlaySoundA(unk_2764, true);
		}
	}

	EnableCallHandler("OnFrame");
}

/* 41B4E0-41B4FD 0001D	*/
void CElevator::OnCollisionObject(cMagMeshObject* param_1) {
	strcmpi("cPlayer", param_1->GetClassNameA());
}

/* 41B500-41B52C 0002C	*/
void CElevator::OnAttachChild(cMagMeshObject* param_1) {
	if (strcmpi("cPlayer", param_1->GetClassNameA()) == 0) {
		unk_274c = true;
	}
}

/* 41B530-41B55B 0002B	*/
void CElevator::OnDetachChild(cMagMeshObject* param_1) {
	if (strcmpi("cPlayer", param_1->GetClassNameA()) == 0) {
		unk_274c = false;
	}
}

/* 41B560-41B600 000A0	*/
void CElevator::OnActivateLevel() {
	SetCullMode(1);
	if (chunkData.unk_10 == 0) {
		chunkData.unk_10 = 1000;
	}
	if (chunkData.unk_14 == 0) {
		chunkData.unk_14 = 3100;
	}

	if (chunkData.unk_0c != 0) {
		unk_2764 = LoadSound(chunkData.unk_18);
		float fVar2 = ((GameSDK*) GetGame())->FUN00401e10();
		SetVolume(unk_2764, fVar2);
		SetDefaultSoundRanges(unk_2764, chunkData.unk_10,chunkData.unk_14);
	}
}

/* 41B600-41B622 00022	*/
void CElevator::OnCrash() {
	unk_2750++;
	if (unk_2750 >= unk_2754) {
		unk_2750 = 0;
	}
}

/* 41B630-41B939 00309	*/
void CElevator::OnLoadChunk(_ED_CHUNK param_1, std::ifstream& param_2) {
	if (param_1.chunkType == 0xf && param_1.chunkDataSize == 0xe0) {
		param_2.read((char*)&chunkData, sizeof(CElevatorChunkData));
		if (chunkData.unk_00 != 0.0f) {
			unk_2758 = chunkData.unk_00;
			return;
		}
	} 

	if (param_1.chunkType == 0x20) {
		param_2.read((char*)&unk_2754, sizeof(unk_2754));
		unk_2738 = new float[3*unk_2754];
		param_2.read((char*)unk_2738, unk_2754 * sizeof(float) * 3);
		for (int index = 0; index < unk_2754; index++) {
			unk_273c.push_back(D3DXVECTOR3(unk_2738[3*index], unk_2738[3*index+1], unk_2738[3*index+2]));
		}
		delete[] unk_2738;
		unk_2738 = NULL;
	}


}

/* 41B940-41BA5A 0011A	*/
void CElevator::Save(std::ostream& param_1) {
	_ED_CHUNK chunk;
	chunk.chunkType = GetObjectID();
	chunk.chunkDataSize = sizeof(CElevatorSaveData);
	chunk.chunkEndPos = (int)param_1.tellp() + chunk.chunkDataSize + sizeof(_ED_CHUNK);
	param_1.write((char*) &chunk, sizeof(_ED_CHUNK));
	CElevatorSaveData saveData;
	D3DXMATRIX matrix = GetRotateMatrix();
	D3DXVECTOR3 pos = GetPosition();
	saveData.unk_00 = matrix;
	saveData.unk_40 = pos;
	saveData.unk_4c = unk_2768;
	saveData.unk_4d = unk_2769;
	saveData.unk_50 = unk_2750;
	param_1.write((char*) &saveData, sizeof(CElevatorSaveData));
}

/* 41BA60-41BB1A 000BA	*/
void CElevator::Load(std::ifstream& param_1, _ED_CHUNK param_2) {
	if (param_2.chunkDataSize != sizeof(CElevatorSaveData)) {
		return;
	}

	CElevatorSaveData local_54;
	param_1.read((char*)&local_54, sizeof(CElevatorSaveData));
	SetPosition(local_54.unk_40);
	SetRotateMatrix(local_54.unk_00);
	unk_2768 = local_54.unk_4c;
	unk_2769 = local_54.unk_4d;
	if (!local_54.unk_4d) {
		unk_2750 = local_54.unk_50;
		unk_275c = true;
		if (chunkData.unk_0c != 0) {
			PlaySoundA(unk_2764, true);
		}
		EnableCallHandler("OnFrame");
	} 
}

