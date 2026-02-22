#ifndef C_BLOB
#define C_BLOB

#include <globals.h>

class cMagMeshObject;

class cBlob {
public:
	/* 100188D0 */ cBlob(cBlob* param_1);
	/* 10018A30 */ cBlob* operator=(cBlob* param_1);
	/* 10030930 */ cBlob();
	/* 10030BD0 */ ~cBlob();
	/* 10030BE0 */ void InitBlob(char* param_1, cMagMeshObject* param_2);
	/* 10030C90 */ void SetPosition(uint param_1, uint param_2, uint param_3);
	/* 10030D20 */ uchar GetPosition(uint* param_1);
	/* 10030D50 */ void SetScale(uint param_1, uint param_2, uint param_3);
	/* 10030DE0 */ uchar GetScale(uint* param_1);
	/* 10030E10 */ void SetBlobAlpha(int param_1);
	/* 10030E30 */ void EnableRendering(bool param_1);
	/* 10030E40 */ void Render();
	/* 10030FD0 */ void Align(float param_1, float param_2, float param_3);
	/* 100312F0 */ int SelectFile3DM(int param_1, float param_2, float param_3, float param_4, float param_5, float param_6, float param_7, float* param_8);
	/* 10031460 */ void CreatePickRayInWorldSpace(uint param_1, uint param_2);
	/* 100315C0 */ void OnRender();
	/* 10031610 */ float GetDistance();
};

#endif