#include "cMp3Player.h"

/* 10088E30-10088E55 00025	*/
cMp3Player::cMp3Player() {
	unknown = NULL;
    graphBuilder = NULL;
    mediaControl = NULL;
    mediaEventExt = NULL;
    loaded = false;
    CoInitialize(NULL);
}

/* 10088E60-10088E6B 0000B	*/
cMp3Player::~cMp3Player() {
	Cleanup();
}

/* 10088E70-10088EC6 00056	*/
void cMp3Player::Cleanup() {
    if (mediaControl != NULL) {
        mediaControl->Stop();
    }
    if (unknown != NULL) {
        unknown->Release();
        unknown = NULL;
    }
    if (graphBuilder != NULL) {
        graphBuilder->Release();
        graphBuilder = NULL;
    }
    if (mediaControl != NULL) {
        mediaControl->Release();
        mediaControl = NULL;
    }
    if (mediaEventExt != NULL) {
        mediaEventExt->Release();
        mediaEventExt = NULL;
    }
}

/* 10088ED0-10088F56 00086	*/
void cMp3Player::Load(char* p_mp3Path) {
	WCHAR buffer[260];
    MultiByteToWideChar(0, 0, p_mp3Path, -1, buffer, 0x104);
    HRESULT res = CoCreateInstance(CLSID_FilterGraph, NULL, 1, IID_IGraphBuilder, (void**)&graphBuilder);
    if (res >= S_OK) {
        graphBuilder->QueryInterface(IID_IMediaControl, (void**)&mediaControl);
        graphBuilder->QueryInterface(IID_IMediaEventEx, (void**)&mediaEventExt);
        res = graphBuilder->RenderFile(buffer, NULL);
        if (res >= S_OK) {
            loaded = true;
        }
    }
}

/* 10088F60-10088F71 00011	*/
void cMp3Player::Play() {
	if (loaded) {
		mediaControl->Run();
    }
}

/* 10088F80-10088F91 00011	*/
void cMp3Player::Pause() {
    if (loaded) {
        mediaControl->Pause();
    }
}

/* 10088FA0-10088FB1 00011	*/
void cMp3Player::Stop() {
    if (loaded) {
        mediaControl->Stop();
    }
}

/* 10088FC0-1008904C 0008C	*/
void cMp3Player::SetVolume(float p_volume) {
    float volume = p_volume;
    if (volume < 0.0f) {
        volume = 0.0f;
    } else if (volume > 1.0f) {
        volume = 1.0f;
    }

    if (loaded) {
        IBasicAudio* audio;
        HRESULT res = mediaControl->QueryInterface(IID_IBasicAudio, (void**)&audio);
        if (res >= S_OK) {
            audio->put_Volume((volume - 1.0f) * 500.0f);
            audio->Release();
        }
    }
}

/* 10089050-10089091 00041	*/
void cMp3Player::Rewind() {
    if (loaded) {
        Stop();
        IMediaPosition* position;
        HRESULT res = mediaControl->QueryInterface(IID_IMediaPosition, (void**)&position);
        if (res >= S_OK) {
            position->put_CurrentPosition(0.0);
            position->Release();
        }
    }
}

/* 100890A0-100890F8 00058	*/
bool cMp3Player::boCompleted() {
    IMediaEvent* mediaEvent;
    long evCode;
    HRESULT res = mediaControl->QueryInterface(IID_IMediaEvent, (void**)&mediaEvent);
    if (res < S_OK) {
        return false;
    }

    res = mediaEvent->WaitForCompletion(0, &evCode);
    mediaEvent->Release();
    if (res < S_OK) {
        return false;
    }
    return evCode == EC_COMPLETE;
}