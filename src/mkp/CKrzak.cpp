#include "CKrzak.h"

/* 441A50-441A84 00034	*/
CKrzak::CKrzak() {
	ZeroMemory(&unk_2658, sizeof(CKrzakChunkData));
	unk_266c = 0.01f;
	unk_2670 = 0.05f;
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
	unk_2660 = GetTickCount() / 1000.0f;
	unk_2664 = 0.0f;
}

/* 441B60-441BAC 0004C	*/
void CKrzak::OnActivateLevel() {
	if (unk_2658.unk_00 > 0.0f) {
		unk_266c = unk_2658.unk_00;
	}
	if (unk_2658.unk_04 > 0.0f) {
		unk_2670 = unk_2658.unk_04;
	}

	EnableCallHandler("OnFrame");
}

/* 441BB0-441C77 000C7	*/
void CKrzak::OnFrame() {
	float DVar1 = GetTickCount() / 1000.0f;
	if (unk_266c >= DVar1 - unk_2660) {
		return;
	}
	unk_2660 = DVar1;

	if (!unk_2668) {
		unk_2664 += unk_2670;
	} 
	if (unk_2668) {
		unk_2664 -= unk_2670;
	}

	SetDirection(unk_2664, 0.0f, unk_2664);

	if (unk_2664 > 3.0f) {
		unk_2668 = true;
	} 
	if (unk_2664 < -3.0f) {
		unk_2668 = false;
	}
}

/* 441C80-441CA4 00024	*/
void CKrzak::OnLoadChunk(_ED_CHUNK param_1, std::ifstream& param_2) {
	if (param_1.chunkType == 0xf && param_1.chunkDataSize == 8) {
		param_2.read((char*)&unk_2658, sizeof(CKrzakChunkData));
	}
}

