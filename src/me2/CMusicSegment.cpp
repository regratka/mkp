#include "CMusicSegment.h"

/* 1009B150-1009B1BF 0006F	*/
CMusicSegment::CMusicSegment(IDirectMusicPerformance8* param_1, IDirectMusicLoader8* param_2, IDirectMusicSegment8* param_3) {
	directMusicPerformance = param_1;
	directMusicLoader = param_2;
	directMusicSegment = param_3;

	directMusicAudioPath = NULL;
	downloaded = FALSE;

	IUnknown* audioPathConfig = NULL;
	HRESULT result = directMusicSegment->GetAudioPathConfig(&audioPathConfig);
	if (result < S_OK) {
		return;
	}

	directMusicPerformance->CreateAudioPath(audioPathConfig, TRUE, &directMusicAudioPath);
	if (audioPathConfig != NULL) {
		audioPathConfig->Release();
	}
}

/* 1009B1C0-1009B229 00069	*/
CMusicSegment::~CMusicSegment() {
	if (directMusicSegment != NULL) {
		if (directMusicLoader != NULL) {
			directMusicLoader->ReleaseObjectByUnknown(directMusicSegment);
		}

		if (downloaded) {
			if (directMusicAudioPath != NULL) {
				directMusicSegment->Unload(directMusicAudioPath);
			} else {
				directMusicSegment->Unload(directMusicPerformance);
			}
		}

		if (directMusicAudioPath != NULL) {
			directMusicAudioPath->Release();
			directMusicAudioPath = NULL;
		}
		
		if (directMusicSegment != NULL) {
			directMusicSegment->Release();
			directMusicSegment = NULL;
		}
	}
	directMusicPerformance = NULL;
}

/* 1009B230-1009B289 00059	*/
HRESULT CMusicSegment::Play(ulong param_1, IDirectMusicAudioPath8* param_2) {
	if (directMusicSegment == NULL || directMusicPerformance == NULL) { 
		return CO_E_NOTINITIALIZED;
	}

	if (!downloaded) {
		return E_FAIL;
	}

	if (param_2 == NULL && directMusicAudioPath != NULL) {
		param_2 = directMusicAudioPath;
	}

	return directMusicPerformance->PlaySegmentEx(directMusicSegment, NULL, NULL, param_1, 0, NULL, NULL, param_2);
}

/* 1009B290-1009B2D4 00044	*/
HRESULT CMusicSegment::Download(IDirectMusicAudioPath8* param_1) {
	if (directMusicSegment == NULL) { 
		return CO_E_NOTINITIALIZED;
	}
	if (param_1 == NULL) {
		param_1 = directMusicAudioPath;
	}
	HRESULT result = param_1 == NULL 
		? directMusicSegment->Download(directMusicPerformance) 
		: directMusicSegment->Download(param_1);

	if (result >= S_OK) {
		downloaded = TRUE;
	}
	return result;
}

/* 1009B2E0-1009B324 00044	*/
HRESULT CMusicSegment::Unload(IDirectMusicAudioPath8* param_1) {
	if (directMusicSegment == NULL) { 
		return CO_E_NOTINITIALIZED;
	}
	if (param_1 == NULL) {
		param_1 = directMusicAudioPath;
	}
	HRESULT result = param_1 == NULL 
		? directMusicSegment->Unload(directMusicPerformance) 
		: directMusicSegment->Unload(param_1);
		
	if (result >= S_OK) {
		downloaded = FALSE;
	}
	return result;
}

/* 1009B330-1009B39F 0006F	*/
HRESULT CMusicSegment::SetVolume(int param_1, IDirectMusicAudioPath8* param_2) {
	if (directMusicSegment == NULL || directMusicPerformance == NULL) { 
		return CO_E_NOTINITIALIZED;
	}

	if (!downloaded) {
		return E_FAIL;
	}

	if (param_2 == NULL && directMusicAudioPath != NULL) {
		param_2 = directMusicAudioPath;
	}

	int volume;
	if (param_1 <= 0) {
		volume = -9600;
	} else {
		volume = (param_1-100) * 25.0;
	}
	if (param_2 != NULL) {
		return param_2->SetVolume(volume, 0);
	}
	return volume;
}

/* 1009B3A0-1009B3C3 00023	*/
int CMusicSegment::IsPlaying() {
	if (directMusicSegment != NULL && directMusicPerformance != NULL) {
		return directMusicPerformance->IsPlaying(directMusicSegment, NULL) == S_OK;
	}
	return CO_E_NOTINITIALIZED;
}

/* 1009B3D0-1009B3FB 0002B	*/
HRESULT CMusicSegment::Stop(ulong param_1) {
	if (directMusicSegment != NULL && directMusicPerformance != NULL) {
		return directMusicPerformance->Stop(directMusicSegment, NULL, 0, param_1);
	}
	return CO_E_NOTINITIALIZED;
}

/* 1009B400-1009B41D 0001D	*/
HRESULT CMusicSegment::SetRepeats(ulong param_1) {
	if (directMusicSegment == NULL) {
		return CO_E_NOTINITIALIZED;
	}
	
	return directMusicSegment->SetRepeats(param_1);
}


/* 1009B420-1009B441 00021	*/
HRESULT CMusicSegment::GetStyle(IDirectMusicStyle8** param_1, ulong param_2) {
	return directMusicSegment->GetParam(GUID_IDirectMusicStyle, 0xffffffff, param_2, 0, NULL, param_1);
}

