#ifndef _C_SOUND_MANAGER
#define _C_SOUND_MANAGER

#include <globals.h>

#include <windows.h>

class CSoundManager {
public:
	/* 1009B570 */ CSoundManager();
	/* 1009B580 */ ~CSoundManager();
	/* 1009B5A0 */ HRESULT Initialize(HWND__* param_1, uint param_2, uint param_3, uint param_4, uint param_5);
	/* 1009B600 */ HRESULT FUN_1009b600();
	/* 1009B6E0 */ int FUN_1009b6e0(uint* param_1, char* param_2, uint param_3, uint param_4, uint param_5, uint param_6, uint param_7, uint param_8);

private: 
	/* 0x00 */ int* unkn_00;
};

STATIC_ASSERT(sizeof(CSoundManager) == 0x4);

#endif