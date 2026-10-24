#ifndef _C_PHYSICS_RIGID_BODY
#define _C_PHYSICS_RIGID_BODY

#include <globals.h>

#include "cMagMeshObject.h"

class CPhysicsRigidBody {
public:
	/* 100B42F0 */ CPhysicsRigidBody(cMagMeshObject* param_1);
	/* 100B4460 */ CPhysicsRigidBody* scalar_destructor(uchar param_1);
	/* 100B4480 */ ~CPhysicsRigidBody();
	/* 100B44F0 */ void FUN100b44f0(float param_1);
};

#endif