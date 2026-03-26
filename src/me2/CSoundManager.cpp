#include "CSoundManager.h"


/* 1009B570-1009B579 00009	*/
CSoundManager::CSoundManager() {
	sound = NULL;
}

/* 1009B580-1009B597 00017	*/
CSoundManager::~CSoundManager() {
	if (sound != NULL) {
		sound->Release();
		sound = NULL;
	}
}

/* 1009B5A0-1009B5FD 0005D	*/
HRESULT CSoundManager::Initialize(HWND param_1, uint param_2, uint param_3, uint param_4, uint param_5) {
	if (sound != NULL) {
		sound->Release();
		sound = NULL;
	}

	HRESULT result = DirectSoundCreate8(NULL, &sound, NULL);
	if (result < S_OK) {
		return result;
	}

	result = sound->SetCooperativeLevel(param_1, param_2);
	if (result < S_OK) {
		return result;
	}

	result = FUN_1009b600(param_3, param_4, param_5);
	if (result < S_OK) {
		return result;
	}
	return S_OK;
}

/* 1009B600-1009B6D6 000D6	*/
HRESULT CSoundManager::FUN_1009b600(uint param_3, uint param_4, uint param_5) {
	if (sound == NULL) {
		return CO_E_NOTINITIALIZED;
	}
	return 0;
}

/* 1009B6E0-1009B905 00225	*/
int CSoundManager::FUN_1009b6e0(uint* param_1, char* param_2, uint param_3, uint param_4, uint param_5, uint param_6, uint param_7, uint param_8) {
	return 0;
}

