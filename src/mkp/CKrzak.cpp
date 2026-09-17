#include "CKrzak.h"

/* 441A50-441A84 00034	*/
CKrzak::CKrzak() {
	ZeroMemory(&chunkData, sizeof(CKrzakChunkData));
	directionUpdateInterval = 0.01f;
	directionChangeValue = 0.05f;
}

/* 441AB0-441ABC 0000C	*/
CKrzak::~CKrzak() {
}

/* 441AC0-441B1A 0005A	*/
void* CKrzak::EXP() {
	return new CKrzak();
}

/* 441B20-441B51 00031	*/
void CKrzak::OnActivate() {
	lastUpdateTick = GetTickCount() / 1000.0f;
	direction = 0.0f;
}

/* 441B60-441BAC 0004C	*/
void CKrzak::OnActivateLevel() {
	if (chunkData.directionUpdateInterval > 0.0f) {
		directionUpdateInterval = chunkData.directionUpdateInterval;
	}
	if (chunkData.directionChangeValue > 0.0f) {
		directionChangeValue = chunkData.directionChangeValue;
	}

	EnableCallHandler("OnFrame");
}

/* 441BB0-441C77 000C7	*/
void CKrzak::OnFrame() {
	float DVar1 = GetTickCount() / 1000.0f;
	if (directionUpdateInterval >= DVar1 - lastUpdateTick) {
		return;
	}
	lastUpdateTick = DVar1;

	if (!shouldDecreaseDirection) {
		direction += directionChangeValue;
	} 
	if (shouldDecreaseDirection) {
		direction -= directionChangeValue;
	}

	SetDirection(direction, 0.0f, direction);

	if (direction > 3.0f) {
		shouldDecreaseDirection = true;
	} 
	if (direction < -3.0f) {
		shouldDecreaseDirection = false;
	}
}

/* 441C80-441CA4 00024	*/
void CKrzak::OnLoadChunk(_ED_CHUNK param_1, std::ifstream& param_2) {
	if (param_1.chunkType == 0xf && param_1.chunkDataSize == 8) {
		param_2.read((char*)&chunkData, sizeof(CKrzakChunkData));
	}
}

