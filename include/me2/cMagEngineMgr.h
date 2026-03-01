#ifndef C_MAG_ENGINE_MGR
#define C_MAG_ENGINE_MGR

#include <globals.h>

#include "cMagGameObject.h"
#include "cMagFrustumCull.h"

class cMagEngineMgr {
public:
    static cMagEngineMgr* getInstance() {
		return instance;
	}

	/* 10003E90 */ void SetEngine(IDirect3DDevice8* param_1);
	/* 10003EA0 */ void SetGameObject(cMagGameObject* param_1);
	/* 10003EB0 */ void ClearGameObject();
	/* 10003EC0 */ void operator=(cMagEngineMgr* param_1);
	/* 1000B500 */ cMagGameObject* GetGameObject();
	/* 1000B510 */ IDirect3DDevice8* GetEngine();
	/* 1000B530 */ cMagFrustumCull* GetFrustumCull();
	/* 10088320 */ cMagEngineMgr();
	/* 10088340 */ ~cMagEngineMgr();
	/* 100883A0 */ void SetDataPath(char* param_1);
	/* 100883B0 */ void GetDataPath(char* param_1, char* param_2);
	/* 100883F0 */ void CreateFrustumCull();

public:
	/* 0x00 */ cMagGameObject* gameObject;
	/* 0x04 */ IDirect3DDevice8* engine;
	/* 0x08 */ char* dataPath;
	/* 0x0c */ cMagFrustumCull* frustumCull;


private:
	static cMagEngineMgr* instance;
};

STATIC_ASSERT(sizeof(cMagEngineMgr) == 0x10);


cMagEngineMgr* cMagEngineMgr::instance = NULL;

#endif