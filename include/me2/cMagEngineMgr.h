#ifndef C_MAG_ENGINE_MGR
#define C_MAG_ENGINE_MGR

#include <globals.h>

class cMagEngineMgr {
public:
	/* 10003E90 */ void SetEngine(IDirect3DDevice8* param_1);
	/* 10003EA0 */ void SetGameObject(cMagGameObject* param_1);
	/* 10003EB0 */ void ClearGameObject();
	/* 10003EC0 */ void operator=(cMagEngineMgr* param_1);
	/* 1000B500 */ cMagGameObject* GetGameObject();
	/* 1000B510 */ uchar GetEngine();
	/* 1000B530 */ cMagFrustumCull* GetFrustumCull();
	/* 10088320 */ cMagEngineMgr();
	/* 10088340 */ ~cMagEngineMgr();
	/* 100883A0 */ void SetDataPath(char* param_1);
	/* 100883B0 */ void GetDataPath(char* param_1, char* param_2);
	/* 100883F0 */ void CreateFrustumCull();
};

#endif