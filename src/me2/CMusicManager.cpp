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
HRESULT CMusicManager::CreateSegmentFromFile(CMusicSegment** param_1, char* param_2, BOOL param_3, BOOL param_4) {
	IDirectMusicSegment8* musicSegment = NULL;
	wchar_t buffor[260];
	mbtowc(buffor, param_2, 0xffffffff); // or mbstowcs
	HRESULT result =  musicLoader->LoadObjectFromFile(CLSID_DirectMusicSegment, IID_IDirectMusicSegment8, buffor,(void**) &musicSegment);
	if (result < S_OK) {
		if (result == DMUS_E_LOADER_FAILEDOPEN) {
			return DMUS_E_LOADER_FAILEDOPEN;
		}
		return result;
	}

	*param_1 = new CMusicSegment(musicPerformance, musicLoader, musicSegment);
	if (*param_1 == NULL) {
		return E_OUTOFMEMORY;
	}

	if (param_4) {
		result = musicSegment->SetParam(GUID_StandardMIDIFile, 0xffffffff, 0, 0, NULL);
		if (result < S_OK) {
			return result;
		}
	    
	}
	if (param_3) {
		result = (*param_1)->Download(NULL);
		if (result < S_OK) {
			return result;
		}
	}
	return S_OK;
}

/* 1009AD80-1009AF1E 0019E	*/
HRESULT CMusicManager::CreateSegmentFromResource(CMusicSegment** param_1, char* param_2, char* param_3, BOOL param_4, BOOL param_5) {
	IDirectMusicSegment8* musicSegment = NULL;
	HRSRC hrsrc = FindResource(NULL, param_2, param_3);
	if (hrsrc == NULL) {
		return E_FAIL;
	}

	HGLOBAL hGlobal = LoadResource(NULL, hrsrc);
	if (hGlobal == NULL) {
		return E_FAIL;
	}
	DWORD resourceSize = SizeofResource(NULL, hrsrc);
	
	DMUS_OBJECTDESC dmusObjectDesc;
	ZeroMemory(&dmusObjectDesc, sizeof(DMUS_OBJECTDESC));
	dmusObjectDesc.guidClass = CLSID_DirectMusicSegment;
	dmusObjectDesc.dwSize = sizeof(DMUS_OBJECTDESC);
	dmusObjectDesc.dwValidData = DMUS_OBJ_MEMORY | DMUS_OBJ_CLASS;
	dmusObjectDesc.llMemLength = resourceSize;
	dmusObjectDesc.pbMemData = NULL;
	
	HRESULT result = musicLoader->GetObjectA(&dmusObjectDesc, IID_IDirectMusicSegment8, (void**) &musicSegment);
	if (result < S_OK) {
		if (result == DMUS_E_LOADER_FAILEDOPEN) {
			return DMUS_E_LOADER_FAILEDOPEN;
		}
		return result;
	}

	*param_1 = new CMusicSegment(musicPerformance, musicLoader, musicSegment);
	if (*param_1 == NULL) {
		return E_OUTOFMEMORY;
	}

	if (param_5) {
		result = musicSegment->SetParam(GUID_StandardMIDIFile, 0xffffffff, 0, 0, NULL);
		if (result < S_OK) {
			return result;
		}  
	}

	if (param_4) {
		result = (*param_1)->Download(NULL);
		if (result < S_OK) {
			return result;
		}
	}
	return S_OK;
}

/* 1009AF20-1009AFF7 000D7	*/
HRESULT CMusicManager::CreateScriptFromFile(CMusicScript** param_1, char* param_2) {
	IDirectMusicScript8* musicScript = NULL;
	wchar_t buffor[260];
	mbtowc(buffor, param_2, 0xffffffff); // or mbstowcs
	HRESULT result =  musicLoader->LoadObjectFromFile(CLSID_DirectMusicScript, IID_IDirectMusicScript8, buffor,(void**) &musicScript);
	if (result < S_OK) {
		return result;
	}

	result = musicScript->Init(musicPerformance, NULL);
	if (result < S_OK) {
		return result;
	}
	*param_1 = new CMusicScript(musicPerformance, musicLoader, musicScript);
	if (*param_1 == NULL) {
		return E_OUTOFMEMORY;
	}
	return result;
}

/* 1009B000-1009B047 00047	*/
HRESULT CMusicManager::CreateChordMapFromFile(IDirectMusicChordMap8** param_1, char* param_2) {
	wchar_t buffor[260];
	mbtowc(buffor, param_2, 0xffffffff); // or mbstowcs
	return musicLoader->LoadObjectFromFile(CLSID_DirectMusicChordMap, IID_IDirectMusicChordMap8, buffor, (void**)param_1);
}

/* 1009B050-1009B097 00047	*/
HRESULT CMusicManager::CreateStyleFromFile(IDirectMusicStyle8** param_1, char* param_2) {
	wchar_t buffor[260];
	mbtowc(buffor, param_2, 0xffffffff); // or mbstowcs
	return musicLoader->LoadObjectFromFile(CLSID_DirectMusicStyle, IID_IDirectMusicStyle8, buffor, (void**)param_1);
}

/* 1009B0A0-1009B14A 000AA	*/
HRESULT CMusicManager::GetMotifFromStyle(IDirectMusicSegment8** param_1, char* param_2, char* param_3) {
	IDirectMusicStyle8* style = NULL;
	IDirectMusicSegment* segment = NULL;
	HRESULT result = CreateStyleFromFile(&style, param_2);
	if (result < S_OK) {
		return result;
	}

	if (style == NULL) {
		return S_OK;
	}

	
	wchar_t buffor[260];
	mbtowc(buffor, param_3, 0xffffffff); // or mbstowcs
	result = style->GetMotif(buffor, &segment);
	if (style != NULL) {
		style->Release();
		style = NULL;
	}

	if (result < S_OK) {
		return result;
	}

	segment->QueryInterface(IID_IDirectMusicSegment8, (void**)param_1);
	return S_OK;
}

