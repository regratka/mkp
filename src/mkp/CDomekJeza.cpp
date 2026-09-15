#include "CDomekJeza.h"

/* 40EF90-40EFA4 00014	*/
void CDomekJeza::OnActivateLevel() {
	EnableFrustumPhysicsPause(false);
	EnableRendering(false);
}

/* 419BA0-419BA1 00001	*/
void CDomekJeza::OnActivate() {
}

/* 43CFB0-43CFC3 00013	*/
CDomekJeza::CDomekJeza() {
}

/* 43CFF0-43CFFC 0000C	*/
CDomekJeza::~CDomekJeza() {
}

/* 43D000-43D05A 0005A	*/
void* CDomekJeza::EXP() {
	return new CDomekJeza();
}

