#include "MagAnimMeshMgr.h"

/* 10044900-10044961 00061	*/
MagAnimMeshMgr::MagAnimMeshMgr(): MagSingleton<MagAnimMeshMgr>(this) {}

/* 100449A0-10044AA9 00109	*/
MagAnimMeshMgr::~MagAnimMeshMgr() {
	for (int index = 0; index < data.size(); index++){
		if (data[index].unkn_600 == 0) {
			
		}
	}

}

