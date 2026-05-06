#include "CMemoryManager.h"

#include <stdio.h>

/* 1009A340-1009A369 00029	*/
CMemoryManager::CMemoryManager() {
}

/* 1009A370-1009A3D0 00060	*/
CMemoryManager::~CMemoryManager() {
	Reset();
}

/* 1009A3D0-1009A415 00045	*/
void CMemoryManager::Reset() {
	unkn_14.clear();
	unkn_10 = 0;
	unkn_0c = 0;
}

/* 1009A420-1009A42D 0000D	*/
void CMemoryManager::Begin() {
	totalAvailableMemory = GetFreeMemory();
}

/* 1009A430-1009A5B4 00184	*/
void CMemoryManager::End(char* param_1) {
	ulong freeMemory = GetFreeMemory();
	ulong usedMemory = totalAvailableMemory - freeMemory;
	for (int i = 0; i < unkn_14.size(); i++) {
		if (strcmp(unkn_14[i].name, param_1) == 0) {
			unkn_14[i].memory += usedMemory;
			unkn_14[i].items++;
			return;
		}
	}

	unkn_14.push_back(MemoryData(param_1, "-", usedMemory));
}

/* 1009A5C0-1009A746 00186	*/
void CMemoryManager::End(char* param_1, char* param_2) {
	ulong freeMemory = GetFreeMemory();
	ulong usedMemory = totalAvailableMemory - freeMemory;
	for (int i = 0; i < unkn_14.size(); i++) {
		if (strcmp(unkn_14[i].name, param_1) == 0) {
			unkn_14[i].memory += usedMemory;
			unkn_14[i].items++;
			return;
		}
	}

	MemoryData newData(param_1, param_2, usedMemory);
	unkn_14.push_back(newData);
}

/* 1009A750-1009A979 00229	*/
void CMemoryManager::GenerateReport(char* param_1) {
	std::ofstream stream;
	stream.open(param_1, std::ios::out|std::ios::trunc);
	char buffer[100];

	sprintf(buffer, "\nTotal memory: %d, items: %d", GetTotalMemory(), GetTotalItems());
	for (int i = 0; i < unkn_14.size(); i++) {
		unkn_14[i].Print(stream);
	}

	stream.write(buffer, strlen(buffer));
	stream.close();
}

/* 1009A980-1009A9C5 00045	*/
ulong CMemoryManager::GetTotalMemory() {
	int memory = 0;
	for(int index = 0; index < unkn_14.size(); index++) {
		memory += unkn_14[index].memory;
	}
	return memory;
}

/* 1009A9D0-1009AA15 00045	*/
ulong CMemoryManager::GetTotalItems() {
	int items = 0;
	for(int index = 0; index < unkn_14.size(); index++) {
		items += unkn_14[index].items;
	}
	return items;
}

/* 10096190-100961AE 0001E	*/
ulong CMemoryManager::GetFreeMemory() {
	MEMORYSTATUS status;
	GlobalMemoryStatus(&status);
	return status.dwAvailPageFile;
}

/* 1009AA20-1009AA6D 0004D	*/
void MemoryData::Print(std::ostream& param_1) {
	char buffer[100];
	sprintf(buffer, "\nname: %s[%s], \t\t\t\tcount: %d, \t\tsize: %d", name, unkn_32, 
		items, memory);
	param_1.write(buffer, strlen(buffer));
}