#include "cMagMeshMgr.h"

#include <stdio.h>

#include "cMagEngineMgr.h"

/* 10044050-100441B3 00163	*/
cMagMeshMgr::cMagMeshMgr(): MagSingleton<cMagMeshMgr>(this) {
	unkn_18 = 0;
	data.clear();
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
	char datapath[300];
	ZeroMemory(datapath, sizeof(datapath));
	char filepathBuffer[300];
	ZeroMemory(filepathBuffer, sizeof(filepathBuffer));

	sprintf(filepathBuffer, "%s", param_1);
	cMagEngineMgr::getInstance()->GetDataPath(filepathBuffer, datapath);

	char substituteMeshFilepath[300];
	strcpy(substituteMeshFilepath, "data\\Interface\\wykrzyknik.3DM");
	char substituteMeshDataPath[300];
	cMagEngineMgr::getInstance()->GetDataPath(substituteMeshFilepath, substituteMeshDataPath);

	log.FileLog("--MagMeshMgr-- create mesh: %s ", filepathBuffer);
	MeshData meshData;
	meshData.mesh = new cStaticMesh();
	bool loaded = meshData.mesh->Load(filepathBuffer);
	if (!loaded) {
		log.CrashLog("--MagMeshMgr-- Can`t create mesh!!!!!: %s", filepathBuffer);
		if (meshData.mesh != NULL) {
			delete meshData.mesh;
		}
		return NULL;
	}

	if (param_3 == 0) {
		meshData.unkn_00 = unkn_18;
		strcpy(meshData.filepath, param_1);
		strcpy(meshData.filename, param_2);
		data.push_back(meshData);
	}
	return meshData.mesh;
}

/* 10044690-100446FB 0006B	*/
bool cMagMeshMgr::IsMesh(char* param_1, int& param_2) {
	int elements = data.size();
	if(elements == 0){
		return false;
	}

	for (int index = 0; index < elements; index++) {
		if (stricmp(data[index].filename, param_1) == 0) {
			param_2 = index;
			return true;
		}
	}
	return false;
}

/* 10044700-1004479F 0009F	*/
void cMagMeshMgr::Clear() {
	int elements = data.size();
	for (int index = 0; index < elements; index++) {
		if (data[index].mesh != NULL) {
			delete data[index].mesh;
			data[index].mesh = NULL;
		}
	}
	data.clear();
}

char* cMagMeshMgr::CreateNiceString(char* param_1) {
	return 0;
}

