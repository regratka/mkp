#ifndef _C_COLLISION_CAMERA
#define _C_COLLISION_CAMERA

#include <globals.h>
#include "CCamera.h"
#include "cMagMeshObject.h"

class DLLEXPORT CCollisionCamera : public CCamera {
public:
	/* 10060BF0 */ CCollisionCamera();
	/* 10060C10 */ CCollisionCamera(cMagMeshObject* param_1, bool param_2);
	/* 10060C70 */ virtual ~CCollisionCamera();
	/* 10060C80 */ void Create(cMagMeshObject* param_1, bool param_2);
	/* 10060DB0 */ void Update(float param_1);
	/* 10060DC0 */ void SetRadius(D3DXVECTOR3 param_1);
	/* 10060DE0 */ void SetAngle(float param_1);
	/* 10060DF0 */ void SetDistance(float param_1);
	/* 10060E00 */ void SetLookAtAngle(float param_1);
	/* 10060E10 */ void OnInputKey(uchar* param_1);
	/* 10060FD0 */ D3DXVECTOR3 GetObservedPosition();
	/* 10061040 */ D3DXVECTOR3 GetOffset();
	/* 10061090 */ D3DXVECTOR3 GetRadius();
	/* 100610C0 */ void UpdateView();
	/* 10061110 */ float GetDistenceToObserved();
	/* 10061190 */ void Update2(float param_1);
	/* 100615B0 */ void SetRotSpeedY(float param_1);
	/* 100615C0 */ void Update3(float param_1);
	/* 10061740 */ void ReadSettings(char* param_1);
	/* 100619B0 */ void SetOppositeDirection(bool param_1);
	/* 100619D0 */ bool GetOppositeDirection();
	/* 100619E0 */ D3DXVECTOR3 GetObservedDirection();
	/* 10061A90 */ void Pause(bool param_1);
	/* 10061AC0 */ void AfterPauseDelay(bool param_1);

public:
	/* 0xdec */ float rotSpeedY;
	/* 0xdf0 */ D3DXVECTOR3 unk_df0;
	/* 0xdfc */ cMagMeshObject* observedObject;
	/* 0xe24 */ D3DXVECTOR3 unk_e00;
	/* 0xe24 */ D3DXVECTOR3 unk_e0c;
	/* 0xe24 */ D3DXVECTOR3 unk_e18;
	/* 0xe24 */ D3DXVECTOR3 radius;
	/* 0xe30 */ D3DXVECTOR3 direction;
	/* 0xe3c */ D3DXVECTOR3 observedPosition;
	/* 0xe48 */ D3DXVECTOR3 observedDirection;
	/* 0xe54 */ int lastMeasureTime;
	/* 0xe58 */ float lookAtAngle;
	/* 0xe5c */ float angle;
	/* 0xe60 */ float distance;
	/* 0xe64 */ float dirDelay1;
	/* 0xe68 */ float dirDelay2;
	/* 0xe6c */ float xzPosDelay;
	/* 0xe70 */ float yPosDelay;
	/* 0xe74 */ float maxMultipleDist;
	/* 0xe78 */ float addObservedY;
	/* 0xe7c */ float distanceToObserved;
	/* 0xe80 */ bool paused;
	/* 0xe81 */ bool isAfterPauseDelay;
	/* 0xe82 */ bool firstUpdateAfterPause;
	/* 0xe83 */ bool isOppositeDirection;
};

STATIC_ASSERT(sizeof(CCollisionCamera) == 0xe84);

#endif