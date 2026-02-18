#include "cMp3Player.h"

cMp3Player::cMp3Player() {
    unknown = NULL;
    graphBuilder = NULL;
    mediaControl = NULL;
    mediaEventExt = NULL;
    loaded = false;
    CoInitialize(NULL);
}

cMp3Player::~cMp3Player() {
    Cleanup();
}

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

void cMp3Player::Load(char* path) {
    WCHAR buffer[260];
    MultiByteToWideChar(0, 0, path, -1, buffer, 0x104);
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

void cMp3Player::Play() {
    if (loaded) {
        mediaControl->Run();
    }
}

void cMp3Player::Pause() {
    if (loaded) {
        mediaControl->Pause();
    }
}

void cMp3Player::Stop() {
    if (loaded) {
        mediaControl->Stop();
    }
}

void cMp3Player::SetVolume(float volumeF) {
    float volume = volumeF;
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