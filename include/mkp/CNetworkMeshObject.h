#ifndef _C_NETWORK_MESH_OBJECT
#define _C_NETWORK_MESH_OBJECT

#include <globals.h>

class CNetworkMeshObject {
public:
	/* 431100 */ CNetworkMeshObject();
	/* 431150 */ uchar scalar_destructor(uchar param_1);
	/* 431170 */ ~CNetworkMeshObject();
	/* 431180 */ void OnActivate();
	/* 431320 */ void OnActivateLevel();
	/* 4314A0 */ void OnFrame();
	/* 4317E0 */ void OnOutsideFrustumCull();
	/* 4317F0 */ void OnInsideFrustumCull();
	/* 431960 */ void OnDestinationPos();
};

#endif