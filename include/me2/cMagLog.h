#ifndef C_MAG_LOG
#define C_MAG_LOG

#include <globals.h>

#include <d3dx8math.h>


class cMagLog {
public:
	/* 10030390 */ cMagLog();
	/* 100303b0 */ void DeleteLog();
	/* 100303f0 */ void DataLog(char* param_1);
	/* 10030460 */ void CrashLog(char* param_1);
	/* 100304e0 */ void TextureErrorLog(char* param_1);
	/* 10030560 */ void TexturesLog(char* param_1);
	/* 100305e0 */ void FileLog(char* param_1);
	/* 10030660 */ void DummyLog(char* param_1);
	/* 100306e0 */ void DebugLog(char* param_1);
	/* 10030730 */ void DebugLog();
	/* 10030750 */ void ClientServerLog(char* param_1);
	/* 100307d0 */ void ReadSettings(char* param_1);
	/* 1005a5e0 */ void DebugLog(D3DXVECTOR3* param_1);
};

#endif