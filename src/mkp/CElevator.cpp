#include "CElevator.h"
#include "GameSDK.h"

/* 41AFD0-41B04D 0007D	*/
CElevator::CElevator() {
	nextDestinationIndex = 0;
	ZeroMemory(&chunkData, sizeof(CElevatorChunkData));
	elevatorSpeedValue = 400.0f;
	shouldUpdateMovement = false;
	unk_275d = false;
	lastUpdateTime = 0.0f;
	elevatorMoveSoundID = 0;
	unk_2768 = false;
	reachedDestPos = false;
	hasPlayer = false;
}

/* 41B070-41B0F1 00081	*/
CElevator::~CElevator() {
	destinationPositions.clear();
}

/* 41B100-41B15A 0005A	*/
void* CElevator::EXP() {
	return new CElevator();
}

/* 41B160-41B314 001B4	*/
void CElevator::OnFrame() {
	if (chunkData.movementUpdateInverval != 0.0f) {
		float DVar5 = GetTickCount() / 1000.0f;
		if (chunkData.movementUpdateInverval < DVar5 - lastUpdateTime) {
			shouldUpdateMovement = true;
			lastUpdateTime = DVar5;
			if (chunkData.shouldPlayMoveSound) {
				PlaySoundA(elevatorMoveSoundID, true);
			}
		}	
	}

	if (shouldUpdateMovement && !destinationPositions.empty()) {
		if (hasPlayer && reachedDestPos) {
			SetSpeedValue(0.0f);
			return;
		}

		if (!destinationPositions.empty()) {
			D3DXVECTOR3 dest(destinationPositions[nextDestinationIndex].x, destinationPositions[nextDestinationIndex].y, destinationPositions[nextDestinationIndex].z);
			SetDestinationPos(dest, 30.0f);
			D3DXVECTOR3 pos = GetPosition();
			SetSpeed(dest - pos);
			SetSpeedValue(elevatorSpeedValue);
		}
	}
}

/* 41B320-41B34C 0002C	*/
void CElevator::OnUpdateMenuSettings() {
	float fVar1 = ((GameSDK*) GetGame())->FUN00401e10();
	SetVolume(elevatorMoveSoundID, fVar1);
}

/* 41B350-41B359 00009	*/
void CElevator::OnActivate() {
	EnableFrustumPhysicsPause(false);
}

/* 41B360-41B3A5 00045	*/
void CElevator::OnDestinationPos(D3DXVECTOR3 param_1) {
	SetSpeedValue(0.0f);
	DisableCallHandler("OnFrame");
	shouldUpdateMovement = false;
	if (chunkData.shouldPlayMoveSound) {
		StopSound(elevatorMoveSoundID);
	}
	reachedDestPos = true;
}

/* 41B3B0-41B4DE 0012E	*/
void CElevator::OnAction() {
	reachedDestPos = false;
	float diff1 = D3DXVec3Length(&(GetPosition() - destinationPositions[0]));
	float diff2 = D3DXVec3Length(&(GetPosition() - destinationPositions[1]));
	if (diff1 > diff2) {
		nextDestinationIndex = 0;
	} else {
		nextDestinationIndex = 1;
	}

	if (chunkData.movementUpdateInverval != 0.0f) {
		lastUpdateTime = GetTickCount() * 0.001f;
	} else {
		shouldUpdateMovement = true;
		if (chunkData.shouldPlayMoveSound) {
			PlaySoundA(elevatorMoveSoundID, true);
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
		hasPlayer = true;
	}
}

/* 41B530-41B55B 0002B	*/
void CElevator::OnDetachChild(cMagMeshObject* param_1) {
	if (strcmpi("cPlayer", param_1->GetClassNameA()) == 0) {
		hasPlayer = false;
	}
}

/* 41B560-41B600 000A0	*/
void CElevator::OnActivateLevel() {
	SetCullMode(1);
	if (chunkData.minSoundRange == 0) {
		chunkData.minSoundRange = 1000;
	}
	if (chunkData.maxSoundRange == 0) {
		chunkData.maxSoundRange = 3100;
	}

	if (chunkData.shouldPlayMoveSound) {
		elevatorMoveSoundID = LoadSound(chunkData.soundFilePath);
		float fVar2 = ((GameSDK*) GetGame())->FUN00401e10();
		SetVolume(elevatorMoveSoundID, fVar2);
		SetDefaultSoundRanges(elevatorMoveSoundID, chunkData.minSoundRange,chunkData.maxSoundRange);
	}
}

/* 41B600-41B622 00022	*/
void CElevator::OnCrash() {
	nextDestinationIndex++;
	if (nextDestinationIndex >= destPositionsCount) {
		nextDestinationIndex = 0;
	}
}

/* 41B630-41B939 00309	*/
void CElevator::OnLoadChunk(_ED_CHUNK param_1, std::ifstream& param_2) {
	if (param_1.chunkType == 0xf && param_1.chunkDataSize == 0xe0) {
		param_2.read((char*)&chunkData, sizeof(CElevatorChunkData));
		if (chunkData.speedValue != 0.0f) {
			elevatorSpeedValue = chunkData.speedValue;
			return;
		}
	} 

	if (param_1.chunkType == 0x20) {
		param_2.read((char*)&destPositionsCount, sizeof(destPositionsCount));
		destPositionsBuffer = new float[3*destPositionsCount];
		param_2.read((char*)destPositionsBuffer, destPositionsCount * sizeof(float) * 3);
		for (int index = 0; index < destPositionsCount; index++) {
			destinationPositions.push_back(D3DXVECTOR3(destPositionsBuffer[3*index], destPositionsBuffer[3*index+1], destPositionsBuffer[3*index+2]));
		}
		delete[] destPositionsBuffer;
		destPositionsBuffer = NULL;
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
	saveData.rotMatrix = matrix;
	saveData.position = pos;
	saveData.unk_4c = unk_2768;
	saveData.reachedDestPos = reachedDestPos;
	saveData.nextDestinationIndex = nextDestinationIndex;
	param_1.write((char*) &saveData, sizeof(CElevatorSaveData));
}

/* 41BA60-41BB1A 000BA	*/
void CElevator::Load(std::ifstream& param_1, _ED_CHUNK param_2) {
	if (param_2.chunkDataSize != sizeof(CElevatorSaveData)) {
		return;
	}

	CElevatorSaveData local_54;
	param_1.read((char*)&local_54, sizeof(CElevatorSaveData));
	SetPosition(local_54.position);
	SetRotateMatrix(local_54.rotMatrix);
	unk_2768 = local_54.unk_4c;
	reachedDestPos = local_54.reachedDestPos;
	if (!local_54.reachedDestPos) {
		nextDestinationIndex = local_54.nextDestinationIndex;
		shouldUpdateMovement = true;
		if (chunkData.shouldPlayMoveSound) {
			PlaySoundA(elevatorMoveSoundID, true);
		}
		EnableCallHandler("OnFrame");
	} 
}

