#include "CMusicManager.h"

/* 1009AAC0-1009AADF 0001F	*/
CMusicManager::CMusicManager() {
	musicLoader = NULL;
	musicPerformance = NULL;
	initalizedCOMLibrary = CoInitialize(NULL) >= S_OK;
}

/* 1009AAE0-1009AB39 00059	*/
CMusicManager::~CMusicManager() {
	if (musicLoader != NULL) {
		musicLoader->Release();
		musicLoader = NULL;
	}

	if (musicPerformance != NULL) {
		musicPerformance->Stop(NULL, NULL, 0, 0);
		musicPerformance->CloseDown();
		if (musicPerformance != NULL) {
			musicPerformance->Release();
			musicPerformance = NULL;
		}
	}

	if (initalizedCOMLibrary) {
		CoUninitialize();
	}
}

/* 1009AB40-1009ABB3 00073	*/
HRESULT CMusicManager::Initialize(HWND__* param_1, ulong param_2, ulong param_3) {
	HRESULT result = CoCreateInstance(CLSID_DirectMusicLoader, NULL, CLSCTX_INPROC_SERVER|CLSCTX_INPROC_HANDLER, IID_IDirectMusicLoader8, (void**) &musicLoader);
	if (result < S_OK) {
		return result;
	}
 	result = CoCreateInstance(CLSID_DirectMusicPerformance, NULL, CLSCTX_INPROC_SERVER|CLSCTX_INPROC_HANDLER, IID_IDirectMusicPerformance8, (void**) &musicPerformance);
	if (result < S_OK) {
		return result;
	}

	result = musicPerformance->InitAudio(NULL, NULL, param_1, param_3, param_2, DMUS_AUDIOF_ALL, NULL);
	if (result < S_OK) {
		if (result == DSERR_NODRIVER) {
			return DSERR_NODRIVER;
		}
		return result;
	}
	return S_OK;
}

/* 1009ABC0-1009AC15 00055	*/
HRESULT CMusicManager::SetSearchDirectory(char const* param_1) {
	if (musicLoader == NULL) {
		return E_UNEXPECTED;
	}
	wchar_t buffor[260];
	mbtowc(buffor, param_1, 0xffffffff); // or mbstowcs
	return musicLoader->SetSearchDirectory(GUID_DirectMusicAllTypes, buffor, FALSE);
}

/* 1009AC20-1009AC46 00026	*/
IDirectMusicAudioPath* CMusicManager::GetDefaultAudioPath() {
	IDirectMusicAudioPath8* audioPath = NULL;
	if (musicPerformance == NULL) {
		return audioPath;
	}

	musicPerformance->GetDefaultAudioPath(&audioPath);
	return audioPath;
}

/* 1009AC50-1009AC5E 0000E	*/
void CMusicManager::CollectGarbage() {
	if (musicLoader != NULL) {
		musicLoader->CollectGarbage();
	}
}

/* 1009AC60-1009AD7A 0011A	*/
long CMusicManager::CreateSegmentFromFile(CMusicSegment** param_1, char* param_2, int param_3, int param_4) {
	return 0;
}

/* 1009AD80-1009AF1E 0019E	*/
long CMusicManager::CreateSegmentFromResource(CMusicSegment** param_1, char* param_2, char* param_3, int param_4, int param_5) {
	return 0;
}

/* 1009AF20-1009AFF7 000D7	*/
long CMusicManager::CreateScriptFromFile(CMusicScript** param_1, char* param_2) {
	return 0;
}

/* 1009B000-1009B047 00047	*/
long CMusicManager::CreateChordMapFromFile(IDirectMusicChordMap** param_1, char* param_2) {
	return 0;
}

/* 1009B050-1009B097 00047	*/
long CMusicManager::CreateStyleFromFile(IDirectMusicStyle8** param_1, char* param_2) {
	return 0;
}

/* 1009B0A0-1009B14A 000AA	*/
long CMusicManager::GetMotifFromStyle(uchar param_1, char* param_2, char* param_3) {
	return 0;
}

