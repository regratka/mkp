#ifndef C_MAG_SOUND
#define C_MAG_SOUND

#include <globals.h>
#include <Dmusici.h>

#include "cMagLog.h" 

class DLLEXPORT cMagSound {
public:
	/* 100885E0 */ cMagSound();
	/* 10088610 */ virtual ~cMagSound();
	/* 10088620 */ HRESULT Setup(char* param_1, IDirectMusicPerformance8* param_2, IDirectMusicLoader8* param_3);
	/* 10088790 */ void Kill();
	/* 10088830 */ HRESULT Play(bool param_1);
	/* 10088880 */ bool IsPlaying();
	/* 100888A0 */ void SetVolume(int param_1);
	/* 100888F0 */ HRESULT Stop();
	/* 10088910 */ void Set3DSoundParams(float param_1, float param_2, float param_3, float param_4);
	/* 10088960 */ HRESULT SetPosition(float param_1, float param_2, float param_3);
	/* 100889A0 */ HRESULT setListenerPos(float param_1, float param_2, float param_3);

private:
	/* 0x4 */ IDirectMusicPerformance8* unk_4;
	/* 0x8 */ IDirectMusicLoader8* unk_8;
	/* 0xc */ IDirectMusicSegment8* unk_c;
	/* 0x10 */ IDirectMusicAudioPath* unk_10;
	/* 0x14 */ IDirectSound3DBuffer* unk_14;
	/* 0x18 */ IDirectSound3DListener* unk_18;
	/* 0x1c */ DS3DBUFFER unk_1c;
	/* 0x5c */ DS3DLISTENER unk_5c;
	/* 0x9c */ cMagLog log;
};

STATIC_ASSERT(sizeof(cMagSound) == 0xa4);

#endif