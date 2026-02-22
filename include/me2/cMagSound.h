#ifndef C_MAG_SOUND
#define C_MAG_SOUND

#include <globals.h>

class cMagSound {
public:
	/* 10001F90 */ cMagSound(cMagSound* param_1);
	/* 10002000 */ cMagSound* operator=(cMagSound* param_1);
	/* 10002070 */ cMagSound* scalar_destructor(uchar param_1);
	/* 100885E0 */ cMagSound();
	/* 10088610 */ ~cMagSound();
	/* 10088620 */ long Setup(char* param_1, uchar param_2, uchar param_3);
	/* 10088790 */ void Kill();
	/* 10088830 */ long Play(bool param_1);
	/* 10088880 */ bool IsPlaying();
	/* 100888A0 */ void SetVolume(int param_1);
	/* 100888F0 */ long Stop();
	/* 10088910 */ void Set3DSoundParams(float param_1, float param_2, float param_3, float param_4);
	/* 10088960 */ long SetPosition(float param_1, float param_2, float param_3);
	/* 100889A0 */ long setListenerPos(float param_1, float param_2, float param_3);
};

#endif