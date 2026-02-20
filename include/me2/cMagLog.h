#ifndef C_MAG_LOG
#define C_MAG_LOG

#include <globals.h>

#include <d3dx8math.h>

class cMagLog {
public:
	/* 10030390 */ cMagLog();
	/* 100303B0 */ void DeleteLog();
	/* 100303F0 */ void DataLog(char const * p_format, ...);
	/* 10030460 */ void CrashLog(char const * p_format, ...);
	/* 100304E0 */ void TextureErrorLog(char const * p_format, ...);
	/* 10030560 */ void TexturesLog(char const * formp_formatat, ...);
	/* 100305e0 */ void FileLog(char const * p_format, ...);
	/* 10030660 */ void DummyLog(char const * p_format, ...);
	/* 100306E0 */ void DebugLog(char const * format, ...);
	/* 10030730 */ void DebugLog(D3DXMATRIX matrix);
	/* 10030750 */ void ClientServerLog(char const * format, ...);
	/* 100307D0 */ void ReadSettings(char* param_1);
	/* 1005A5E0 */ void DebugLog(D3DXVECTOR3* param_1);

private:
	/* 0x00 */ bool logEnabled;
	/* 0x04 */ char* logFilename;
};

STATIC_ASSERT(sizeof(cMagLog) == 0x8);

#endif