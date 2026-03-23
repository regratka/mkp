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
long CMusicSegment::Play(ulong param_1, uchar param_2) {
	return 0;
}

/* 1009B290-1009B2D4 00044	*/
long CMusicSegment::Download(IDirectMusicAudioPath* param_1) {
	return 0;
}

/* 1009B2E0-1009B324 00044	*/
long CMusicSegment::Unload(uchar param_1) {
	return 0;
}

/* 1009B330-1009B39F 0006F	*/
long CMusicSegment::SetVolume(int param_1, IDirectMusicAudioPath* param_2) {
	return 0;
}

/* 1009B3A0-1009B3C3 00023	*/
int CMusicSegment::IsPlaying() {
	return 0;
}

/* 1009B3D0-1009B3FB 0002B	*/
long CMusicSegment::Stop(ulong param_1) {
	return 0;
}

/* 1009B400-1009B41D 0001D	*/
long CMusicSegment::SetRepeats(ulong param_1) {
	return 0;
}

/* 1009B420-1009B441 00021	*/
long CMusicSegment::GetStyle(IDirectMusicStyle8** param_1, ulong param_2) {
	return 0;
}

