#include "CMusicScript.h"

/* 1009B450-1009B470 00020	*/
CMusicScript::CMusicScript(IDirectMusicPerformance8* param_1, IDirectMusicLoader8* param_2, IDirectMusicScript8* param_3) {
	musicPerformance = param_1;
	musicLoader = param_2;
	musicScript = param_3;
}

/* 1009B470-1009B4A6 00036	*/
CMusicScript::~CMusicScript() {
	if (musicLoader != NULL) {
		musicLoader->ReleaseObjectByUnknown(musicScript);
		musicLoader = NULL;
	}

	if (musicScript != NULL) {
		musicScript->Release();
		musicScript = NULL;
	}

	musicPerformance = NULL;
}

/* 1009B4B0-1009B4E7 00037	*/
HRESULT CMusicScript::CallRoutine(char* param_1) {
	wchar_t buffer[260];

	mbtowc(buffer, param_1, 0xffffffff);
	return musicScript->CallRoutine(buffer, NULL);
}

/* 1009B4F0-1009B52F 0003F	*/
HRESULT CMusicScript::SetVariableNumber(char* param_1, long param_2) {
	wchar_t buffer[260];

	mbtowc(buffer, param_1, 0xffffffff);
	return musicScript->SetVariableNumber(buffer, param_2, NULL);
}

/* 1009B530-1009B56F 0003F	*/
HRESULT CMusicScript::GetVariableNumber(char* param_1, long* param_2) {
	wchar_t buffer[260];

	mbtowc(buffer, param_1, 0xffffffff);
	return musicScript->GetVariableNumber(buffer, param_2, NULL);
}