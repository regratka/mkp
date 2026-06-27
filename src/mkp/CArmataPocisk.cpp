#include "CArmataPocisk.h"

/* 419BA0-419BA1 00001	*/
void CArmataPocisk::OnActivateLevel() {
}


/* 43B090-43B0A3 00013	*/
CArmataPocisk::CArmataPocisk() {
}

/* 43B0D0-43B0DC 0000C	*/
CArmataPocisk::~CArmataPocisk() {
}

/* 43B0E0-43B1A0 000C0	*/
void CArmataPocisk::OnActivate() {
	LoadMesh("data\\Meshes\\Wyspa\\Morela.3dm");
	SetScale(D3DXVECTOR3(0.8f, 0.8f, 0.8f));
	SetClassName("CArmataPocisk");
	SetObjectName("ArmataPocisk");
	EnableCollisionScene(false);
	SetGravityAcceleration(15.0f);
	SetCollisionType(2);
	SetCollAction(0);
	EnableCollision(true);
	EnablePhysics(true);
	EnableCollisionObjects(true);
	EnableFrustumPhysicsPause(false);
}

/* 43B1A0-43B1F0 00050	*/
void CArmataPocisk::FUN0043b1a0(D3DXVECTOR3 param_1, D3DXVECTOR3 param_2) {
	EnableRendering(true);
	SetPosition(param_2);
	SetDirection(param_1);
}

/* 43B1F0-43B1FA 0000A	*/
void CArmataPocisk::OnCollisionObject(cMagMeshObject* param_1) {
	EnableRendering(false);
}

