#ifndef _C_PHYSICS_MOTORBOAT
#define _C_PHYSICS_MOTORBOAT

#include <globals.h>

class CPhysicsMotorboat {
public:
	/* 1004EA10 */ CPhysicsMotorboat(CPhysicsMotorboat* param_1);
	/* 1004EAF0 */ CPhysicsMotorboat* operator=(CPhysicsMotorboat* param_1);
	/* 1004EBD0 */ CPhysicsMotorboat* scalar_destructor(uchar param_1);
	/* 100B3210 */ CPhysicsMotorboat();
	/* 100B3280 */ ~CPhysicsMotorboat();
	/* 100B3290 */ void UpdateMove(float param_1);
	/* 100B3720 */ void Update4Wheels(ColObject* param_1, int param_2, float param_3);
	/* 100B3790 */ void Init();
	/* 100B3810 */ void SetEngineMesh(cMagMeshObject* param_1);
	/* 100B3840 */ void SetDriverMesh(cMagMeshObject* param_1);
	/* 100B3870 */ void UpdatePosition();
	/* 100B3930 */ void UpdateEngineRotation(float param_1);
	/* 100B3A40 */ void RotateEngine(float param_1, float param_2, double param_3);
	/* 100B3AE0 */ void RotateBoat(float param_1);
	/* 100B3ED0 */ float AngSpeedFromVelocity(float param_1, float param_2);
	/* 100B3F10 */ uchar UpdateSpeed();
	/* 100B40B0 */ float Breake(float param_1, float param_2);
	/* 100B40E0 */ void Crash(float param_1, float param_2);
	/* 100B4180 */ void SetWaterMesh(char* param_1);
	/* 100B41B0 */ void SetCrashMinSpeed(float param_1);
	/* 100B41C0 */ void SetPosition(D3DXVECTOR3 param_1);
	/* 100B4210 */ void SetRotationMatrix(D3DXMATRIX param_1);
};

#endif