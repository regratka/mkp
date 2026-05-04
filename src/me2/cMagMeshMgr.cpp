#include "cMagMeshMgr.h"

/* 10044050-100441B3 00163	*/
cMagMeshMgr::cMagMeshMgr(): MagSingleton<cMagMeshMgr>(this) {
	data.clear();
	unkn_18 = 0;
	unkn_04 = 0;

	data.reserve(256);
}

/* 100441C0-10044225 00065	*/
cMagMeshMgr::~cMagMeshMgr() {
}

/* 10044230-10044292 00062	*/
cStaticMesh* cMagMeshMgr::GetMesh(char* param_1) {
	char* niceString = CreateNiceString(param_1);
	if (!IsMesh(niceString, unkn_18)) {
		return LoadMesh(param_1, niceString, 0);
	} else {
		log.FileLog("--MagMeshMgr-- find mesh: %s ", niceString);
		return data[unkn_18].mesh;
	}
}

/* 100442A0-10044688 003E8	*/
cStaticMesh* cMagMeshMgr::LoadMesh(char* param_1, char* param_2, int param_3) {
	return 0;
}

/* 10044690-100446FB 0006B	*/
bool cMagMeshMgr::IsMesh(char* param_1, int& param_2) {
	for (int index = 0; index < data.size(); index++) {
		if (stricmp(data[index].filename, param_1) == 0) {
			param_2 = index;
			return true;
		}
	}
	return false;
}

/* 10044700-1004479F 0009F	*/
void cMagMeshMgr::Clear() {
	
	data.clear();
}

char* cMagMeshMgr::CreateNiceString(char* param_1) {
	return 0;
}

