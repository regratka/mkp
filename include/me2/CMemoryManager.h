#ifndef _C_MEMORY_MANAGER
#define _C_MEMORY_MANAGER

#include <globals.h>

class CMemoryManager {
public:
	/* 100051A0 */ CMemoryManager(CMemoryManager* param_1);
	/* 10005260 */ CMemoryManager* operator=(CMemoryManager* param_1);
	/* 10005510 */ CMemoryManager* scalar_destructor(uchar param_1);
	/* 1009A340 */ CMemoryManager();
	/* 1009A370 */ ~CMemoryManager();
	/* 1009A3D0 */ void Reset();
	/* 1009A420 */ void Begin();
	/* 1009A430 */ void End(char* param_1);
	/* 1009A5C0 */ void End(char* param_1, char* param_2);
	/* 1009A750 */ void GenerateReport(char* param_1);
	/* 1009A980 */ ulong GetTotalMemory();
	/* 1009A9D0 */ ulong GetTotalItems();

private: 
	/* 0x00 */ uchar field_0000[0x28-0x0];
};

#endif