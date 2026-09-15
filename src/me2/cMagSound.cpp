#include "cMagSound.h"

/* 100885E0-1008860C 0002C	*/
cMagSound::cMagSound() {
	unk_4 = NULL;
	unk_8 = NULL;
	unk_c = NULL;
	unk_10 = NULL;
	unk_14 = NULL;
	unk_18 = NULL;
}

/* 10088610-10088617 00007	*/
cMagSound::~cMagSound() {
}

/* 10088620-1008878D 0016D	*/
HRESULT cMagSound::Setup(char* param_1, IDirectMusicPerformance8* param_2, IDirectMusicLoader8* param_3) {
	unk_4 = param_2;
	unk_8 = param_3;

	WCHAR local_208[260];
	MultiByteToWideChar(0, 0, param_1, -1, local_208, 260);
	HRESULT res = unk_8->LoadObjectFromFile(CLSID_DirectMusicSegment, IID_IDirectMusicSegment8, 
		local_208, (void**)&unk_c);
	if (res < S_OK) {
		return res;
	}

	res = unk_c->Download(unk_4);
	if (res < S_OK) {
		return res;
	}

	res = unk_c->SetRepeats(0);
	if (res < S_OK) {
		return res;
	}

	res = unk_4->CreateStandardAudioPath(6, 64, TRUE, &unk_10);
	if (res < S_OK) {
		return res;
	}

	res = unk_10->GetObjectInPath(0, DMUS_PATH_BUFFER, 0, GUID_NULL, 0, 
		IID_IDirectSound3DBuffer8, (void**)&unk_14);
	if (res < S_OK) {
		return res;
	}
	unk_10->SetVolume(-9600, 0);
	unk_1c.dwSize = sizeof(DS3DBUFFER);
	unk_14->GetAllParameters(&unk_1c);
	unk_1c.dwMode = 1;
	unk_14->SetAllParameters(&unk_1c, 0);
	
	HRESULT res_2 = unk_10->GetObjectInPath(0,DMUS_PATH_PRIMARY_BUFFER, 0, GUID_NULL, 0,
		IID_IDirectSound3DListener, (void**)&unk_18);
	if (res_2 <  S_OK) {
		return res;
	}

	unk_5c.dwSize = sizeof(DS3DLISTENER);
	unk_18->GetAllParameters(&unk_5c);
	unk_5c.vPosition.x = 0.0f;
	unk_5c.vPosition.y = 0.0f;
	unk_5c.vPosition.z = 0.0f;
	unk_18->SetAllParameters(&unk_5c, 0);
	return S_OK;
}

/* 10088790-1008880C 0007C	*/
void cMagSound::Kill() {
	try {
		if (unk_14 != NULL) {
			unk_14->Release();
		}
		unk_14 = NULL;

		if (unk_18 != NULL) {
			unk_18->Release();
		}
		unk_18 = NULL;

		if (unk_10 != NULL) {
			unk_10->Release();
		}
		unk_10 = NULL;

		if (unk_c != NULL) {
			unk_c->Release();
		}
		unk_c = NULL;
	} catch (...) {
		this->log.DebugLog("Error kill sound");
	}
}

/* 10088830-1008887D 0004D	*/
HRESULT cMagSound::Play(bool param_1) {
	if (param_1) {
		HRESULT res = unk_c->SetRepeats(-1);
		if (res < S_OK) {
			return res;
		}
	}

	HRESULT res = unk_4->PlaySegmentEx(unk_c, NULL, NULL, DMUS_SEGF_DEFAULT, 0, NULL, NULL, unk_10);
	if (res < S_OK) {
		return res;
	}
	return S_OK;
}

/* 10088880-10088896 00016	*/
bool cMagSound::IsPlaying() {
	HRESULT res = unk_4->IsPlaying(unk_c, NULL);
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
	unk_10->SetVolume(volume, 0); 

}

/* 100888F0-1008890E 0001E	*/
HRESULT cMagSound::Stop() {
	HRESULT res = unk_4->Stop(unk_c, NULL, 0, 0);
	if (res < S_OK) {
		return res;
	}
	return S_OK;
}

/* 10088910-1008895F 0004F	*/
void cMagSound::Set3DSoundParams(float param_1, float param_2, float param_3, float param_4) {
	unk_5c.flDopplerFactor = param_1;
	unk_5c.flRolloffFactor = param_2;
	if (unk_18 != NULL) {
		unk_18->SetAllParameters(&unk_5c, 0);
	}
	unk_1c.flMinDistance = param_3;
	unk_1c.flMaxDistance = param_4;
	if (unk_14 != NULL) {
		unk_14->SetAllParameters(&unk_1c, 0);
	}
}

/* 10088960-10088993 00033	*/
HRESULT cMagSound::SetPosition(float param_1, float param_2, float param_3) {
	if (unk_14 == NULL) {
		return E_FAIL;
	}

	HRESULT res = unk_14->SetPosition(param_1, param_2, param_3, 0);
	if (res < S_OK) {
		return res;
	}
	return S_OK;
}

/* 100889A0-100889D3 00033	*/
HRESULT cMagSound::setListenerPos(float param_1, float param_2, float param_3) {
	if (unk_18 == NULL) {
		return E_FAIL;
	}

	HRESULT res = unk_18->SetPosition(param_1, param_2, param_3, 0);
	if (res < S_OK) {
		return res;
	}
	return S_OK;
}

