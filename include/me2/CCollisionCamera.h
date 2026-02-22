#ifndef _C_COLLISION_CAMERA
#define _C_COLLISION_CAMERA

#include <globals.h>
#include "CCamera.h"
#include "cMagMeshObject.h"

class CCollisionCamera {
public:
	/* 1001A6A0 */ CCollisionCamera(CCollisionCamera* param_1);
	/* 1001A900 */ CCollisionCamera* operator=(CCollisionCamera* param_1);
	/* 1001AB60 */ CCollisionCamera* scalar_destructor(uchar param_1);
	/* 10060BF0 */ CCollisionCamera();
	/* 10060C10 */ CCollisionCamera(cMagMeshObject* param_1, bool param_2);
	/* 10060C70 */ ~CCollisionCamera();
	/* 10060C80 */ void Create(cMagMeshObject* param_1, bool param_2);
	/* 10060DB0 */ void Update(float param_1);
	/* 10060DC0 */ void SetRadius(D3DXVECTOR3 param_1);
	/* 10060DE0 */ void SetAngle(float param_1);
	/* 10060DF0 */ void SetDistance(float param_1);
	/* 10060E00 */ void SetLookAtAngle(float param_1);
	/* 10060E10 */ void OnInputKey(uchar* param_1);
	/* 10060FD0 */ D3DXVECTOR3* GetObservedPosition(D3DXVECTOR3* param_1);
	/* 10061040 */ D3DXVECTOR3* GetOffset(D3DXVECTOR3* param_1);
	/* 10061090 */ uchar GetRadius(uint* param_1);
	/* 100610C0 */ void UpdateView();
	/* 10061110 */ float GetDistenceToObserved();
	/* 10061190 */ void Update2(float param_1);
	/* 100615B0 */ void SetRotSpeedY(float param_1);
	/* 100615C0 */ void Update3(float param_1);
	/* 10061740 */ void ReadSettings(char* param_1);
	/* 100619B0 */ void SetOppositeDirection(bool param_1);
	/* 100619D0 */ bool GetOppositeDirection();
	/* 100619E0 */ D3DXVECTOR3* GetObservedDirection(D3DXVECTOR3* param_1);
	/* 10061A90 */ void Pause(bool param_1);
	/* 10061AC0 */ void AfterPauseDelay(bool param_1);
};

#endif