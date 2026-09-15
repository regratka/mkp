#include "cMagAudio.h"

/* 1000B510-1000B514 00004	*/
IDirectMusicPerformance8* cMagAudio::getPerformance() {
	return musicPerformance;
}

/* 1000B520-1000B524 00004	*/
IDirectMusicLoader8* cMagAudio::getLoader() {
	return musicLoader;
}

/* 100884A0-100884BD 0001D	*/
cMagAudio::cMagAudio() {
	musicPerformance = NULL;
	musicLoader = NULL;
}

/* 100884C0-100884C7 00007	*/
cMagAudio::~cMagAudio() {
}

/* 100884D0-1008853C 0006C	*/
HRESULT cMagAudio::Setup() {
	HRESULT res = CoInitialize(NULL);
	if (res < S_OK) {
		return res;
	}

	res = CoCreateInstance(CLSID_DirectMusicLoader, NULL, CLSCTX_INPROC_SERVER|CLSCTX_INPROC_HANDLER,
		IID_IDirectMusicLoader8, (void**)&musicLoader);
	if (res < S_OK) {
		return res;
	}

	res = CoCreateInstance(CLSID_DirectMusicPerformance, NULL, CLSCTX_INPROC_SERVER|CLSCTX_INPROC_HANDLER,
		IID_IDirectMusicPerformance8, (void**)&musicPerformance);
	if (res < S_OK) {
		return res;
	}

	res = musicPerformance->InitAudio(NULL, NULL, NULL, DMUS_APATH_DYNAMIC_STEREO, 64, DMUS_AUDIOF_ALL, NULL);
	if (res < S_OK) {
		return res;
	}

	return S_OK;
}

/* 10088540-100885BD 0007D	*/
void cMagAudio::Kill() {
	try {
		
		if (musicPerformance != NULL) {
			musicPerformance->Stop(NULL, NULL, 0, 0);
		}

		if (musicLoader != NULL) {
			musicLoader->Release();
		}
		musicLoader = NULL;

		if (musicPerformance != NULL) {
			musicPerformance->CloseDown();
		}
		
		if (musicPerformance != NULL) {
			musicPerformance->Release();
		}
		musicPerformance = NULL;
	} catch (...) {
		// TODO 
		// catch block returns offset to next code block instead of address 
		// as in target exe. I assume it is because the offset is replaced 
		// during the linking phase
		this->log.DebugLog("Error kill sound");
	}
}

