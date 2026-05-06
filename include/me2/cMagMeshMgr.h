#ifndef C_MAG_MESH_MGR
#define C_MAG_MESH_MGR

#include <globals.h>
#include <vector>

#include "MagSingleton.h"

#include "cMagLog.h"
#include "cStaticMesh.h"
#include "CMemoryManager.h"

struct MeshData {
	/* 0x00 */ int unkn_00;
	/* 0x04 */ char filename[300];
	/* 0x130 */ char filepath[300];
	/* 0x25c */ cStaticMesh* mesh;
};

STATIC_ASSERT(sizeof(MeshData)==0x260);

class __declspec(dllexport) cMagMeshMgr : public MagSingleton<cMagMeshMgr> {
public:
	/* 10044050 */ cMagMeshMgr();
	/* 100441C0 */ virtual ~cMagMeshMgr();
	/* 10044230 */ cStaticMesh* GetMesh(char* param_1);
	/* 100442A0 */ cStaticMesh* LoadMesh(char* param_1, char* param_2, int param_3);
	/* 10044690 */ bool IsMesh(char* param_1, int& param_2);
	/* 10044700 */ void Clear();
	/* 100393E0 */ char* cMagMeshMgr::CreateNiceString(char* param_1);

private:
	/* 0x04 */ int unkn_04;
	/* 0x08 */ std::vector<MeshData> data;
	/* 0x18 */ int unkn_18;
	/* 0x1c */ cMagLog log;
	/* 0x24 */ CMemoryManager memoryManager;
};

STATIC_ASSERT(sizeof(cMagMeshMgr)==0x4c);


#endif