#ifndef _C_DOMEK_JEZA
#define _C_DOMEK_JEZA

#include <globals.h>

#include "cMagMeshObject.h"

class CDomekJeza : public cMagMeshObject {
public:
	/* 40EF90 */ void OnActivateLevel();
	/* 419BA0 */ void OnActivate();
	/* 43CFB0 */ CDomekJeza();
	/* 43CFF0 */ virtual ~CDomekJeza();
	/* 43D000 */ void* EXP();
};

#endif