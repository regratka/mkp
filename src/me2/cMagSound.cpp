#include "cMagSound.h"

/* 100885E0-1008860C 0002C	*/
cMagSound::cMagSound() {
	musicPerformance = NULL;
	musicLoader = NULL;
	musicSegment = NULL;
	musicAudioPath = NULL;
	sound3DBuffer = NULL;
	sound3DListener = NULL;
}

/* 10088610-10088617 00007	*/
cMagSound::~cMagSound() {
}

/* 10088620-1008878D 0016D	*/
HRESULT cMagSound::Setup(char* param_1, IDirectMusicPerformance8* param_2, IDirectMusicLoader8* param_3) {
	musicPerformance = param_2;
	musicLoader = param_3;

	WCHAR local_208[260];
	MultiByteToWideChar(CP_ACP, 0, param_1, -1, local_208, 260);
	HRESULT res = musicLoader->LoadObjectFromFile(CLSID_DirectMusicSegment, IID_IDirectMusicSegment8, 
		local_208, (void**)&musicSegment);
	if (res < S_OK) {
		return res;
	}

	res = musicSegment->Download(musicPerformance);
	if (res < S_OK) {
		return res;
	}

	res = musicSegment->SetRepeats(0);
	if (res < S_OK) {
		return res;
	}

	res = musicPerformance->CreateStandardAudioPath(DMUS_APATH_DYNAMIC_3D, 64, TRUE, &musicAudioPath);
	if (res < S_OK) {
		return res;
	}

	res = musicAudioPath->GetObjectInPath(0, DMUS_PATH_BUFFER, 0, GUID_NULL, 0, 
		IID_IDirectSound3DBuffer8, (void**)&sound3DBuffer);
	if (res < S_OK) {
		return res;
	}
	musicAudioPath->SetVolume(-9600, 0);
	bufferParams.dwSize = sizeof(DS3DBUFFER);
	sound3DBuffer->GetAllParameters(&bufferParams);
	bufferParams.dwMode = DS3DMODE_HEADRELATIVE;
	sound3DBuffer->SetAllParameters(&bufferParams, DS3D_IMMEDIATE);
	
	HRESULT res_2 = musicAudioPath->GetObjectInPath(0,DMUS_PATH_PRIMARY_BUFFER, 0, GUID_NULL, 0,
		IID_IDirectSound3DListener, (void**)&sound3DListener);
	if (res_2 <  S_OK) {
		return res;
	}

	listenerParams.dwSize = sizeof(DS3DLISTENER);
	sound3DListener->GetAllParameters(&listenerParams);
	listenerParams.vPosition.x = 0.0f;
	listenerParams.vPosition.y = 0.0f;
	listenerParams.vPosition.z = 0.0f;
	sound3DListener->SetAllParameters(&listenerParams, DS3D_IMMEDIATE);
	return S_OK;
}

/* 10088790-1008880C 0007C	*/
void cMagSound::Kill() {
	try {
		if (sound3DBuffer != NULL) {
			sound3DBuffer->Release();
		}
		sound3DBuffer = NULL;

		if (sound3DListener != NULL) {
			sound3DListener->Release();
		}
		sound3DListener = NULL;

		if (musicAudioPath != NULL) {
			musicAudioPath->Release();
		}
		musicAudioPath = NULL;

		if (musicSegment != NULL) {
			musicSegment->Release();
		}
		musicSegment = NULL;
	} catch (...) {
		// TODO 
		// catch block returns offset to next code block instead of address 
		// as in target exe. I assume it is because the offset is replaced 
		// during the linking phase
		this->log.DebugLog("Error kill sound");
	}

	
}

/* 10088830-1008887D 0004D	*/
HRESULT cMagSound::Play(bool param_1) {
	if (param_1) {
		HRESULT res = musicSegment->SetRepeats(DMUS_SEG_REPEAT_INFINITE);
		if (res < S_OK) {
			return res;
		}
	}

	HRESULT res = musicPerformance->PlaySegmentEx(musicSegment, NULL, NULL, DMUS_SEGF_DEFAULT, 0, NULL, NULL, musicAudioPath);
	if (res < S_OK) {
		return res;
	}
	return S_OK;
}

/* 10088880-10088896 00016	*/
bool cMagSound::IsPlaying() {
	HRESULT res = musicPerformance->IsPlaying(musicSegment, NULL);
	bool playing = res == S_OK;
	return playing;
}

/* 100888A0-100888E6 00046	*/
void cMagSound::SetVolume(int param_1) {
	long volume;
	if (param_1 <= 0) {
		volume = -9600;
	} else {
		volume = (param_1 - 100) * 25.0;
	}
	musicAudioPath->SetVolume(volume, 0); 

}

/* 100888F0-1008890E 0001E	*/
HRESULT cMagSound::Stop() {
	HRESULT res = musicPerformance->Stop(musicSegment, NULL, 0, 0);
	if (res < S_OK) {
		return res;
	}
	return S_OK;
}

/* 10088910-1008895F 0004F	*/
void cMagSound::Set3DSoundParams(float param_1, float param_2, float param_3, float param_4) {
	listenerParams.flDopplerFactor = param_1;
	listenerParams.flRolloffFactor = param_2;
	if (sound3DListener != NULL) {
		sound3DListener->SetAllParameters(&listenerParams, DS3D_IMMEDIATE);
	}
	bufferParams.flMinDistance = param_3;
	bufferParams.flMaxDistance = param_4;
	if (sound3DBuffer != NULL) {
		sound3DBuffer->SetAllParameters(&bufferParams, DS3D_IMMEDIATE);
	}
}

/* 10088960-10088993 00033	*/
HRESULT cMagSound::SetPosition(float param_1, float param_2, float param_3) {
	if (sound3DBuffer == NULL) {
		return E_FAIL;
	}

	HRESULT res = sound3DBuffer->SetPosition(param_1, param_2, param_3, DS3D_IMMEDIATE);
	if (res < S_OK) {
		return res;
	}
	return S_OK;
}

/* 100889A0-100889D3 00033	*/
HRESULT cMagSound::setListenerPos(float param_1, float param_2, float param_3) {
	if (sound3DListener == NULL) {
		return E_FAIL;
	}

	HRESULT res = sound3DListener->SetPosition(param_1, param_2, param_3, DS3D_IMMEDIATE);
	if (res < S_OK) {
		return res;
	}
	return S_OK;
}

