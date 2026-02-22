#ifndef C_MAG_MESH_MGR
#define C_MAG_MESH_MGR

#include <globals.h>

class cMagMeshMgr {
public:
	/* 10005570 */ cMagMeshMgr(cMagMeshMgr* param_1);
	/* 10005710 */ cMagMeshMgr* operator=(cMagMeshMgr* param_1);
	/* 10005940 */ cMagMeshMgr* scalar_destructor(uchar param_1);
	/* 10044050 */ cMagMeshMgr();
	/* 100441C0 */ ~cMagMeshMgr();
	/* 10044230 */ cStaticMesh* GetMesh(char* param_1);
	/* 100442A0 */ cStaticMesh* LoadMesh(char* param_1, char* param_2, int param_3);
	/* 10044690 */ bool IsMesh(char* param_1, int* param_2);
	/* 10044700 */ void Clear();
};

#endif