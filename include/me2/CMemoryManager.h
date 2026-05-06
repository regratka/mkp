#ifndef _C_MEMORY_MANAGER
#define _C_MEMORY_MANAGER

#include <globals.h>
#include <vector>
#include <fstream>

#include "cMagLog.h"

class MemoryData {
public:
	MemoryData(char* param_1, char* param_2, int param_3) {
		strcpy(name, param_1);
		strcpy(unkn_32, param_2);
		memory = param_3;
		items = 1;
	}

	~MemoryData(){

	}
	/* 1009AA20 */ void Print(std::ostream& param_1);

public:
	/* 0x00 */ char name[50];
	/* 0x32 */ char unkn_32[200];
	/* 0xfc */ int memory;
	/* 0x100 */ int items;
};

STATIC_ASSERT(sizeof(MemoryData) == 0x104);

class __declspec(dllexport) CMemoryManager {
public:
	/* 1009A340 */ CMemoryManager();
	/* 1009A370 */ virtual ~CMemoryManager();
	/* 1009A3D0 */ void Reset();
	/* 1009A420 */ void Begin();
	/* 1009A430 */ void End(char* param_1);
	/* 1009A5C0 */ void End(char* param_1, char* param_2);
	/* 1009A750 */ void GenerateReport(char* param_1);
	/* 1009A980 */ ulong GetTotalMemory();
	/* 1009A9D0 */ ulong GetTotalItems();
	/* 10096190 */ ulong GetFreeMemory();

private: 
	/* 0x04 */ cMagLog log;
	/* 0x0c */ uint unkn_0c;
	/* 0x10 */ uint unkn_10;
	/* 0x14 */ std::vector<MemoryData> unkn_14;
	/* 0x24 */ ulong totalAvailableMemory;
};

STATIC_ASSERT(sizeof(CMemoryManager) == 0x28);

#endif