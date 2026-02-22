#ifndef _C_EXTENDED_PARAMETER_LOADER
#define _C_EXTENDED_PARAMETER_LOADER

#include <globals.h>

class CExtendedParameterLoader {
public:
	/* 100BA400 */ void FUN100ba400(CClassPrototype* param_1);
	/* 100BA4A0 */ uchar FUN_100ba4a0(CClassPrototype* param_1, CClassParameter* param_2);
	/* 100BA570 */ void LoadClassPrototype(std_basic_ifstream* param_1);
	/* 100BA790 */ uchar loadJavaMeshExtension(std_basic_ifstream* param_1, cMagMeshObject* param_2);
	/* 100BA960 */ CClassPrototype* FUN_100ba960(cMagMeshObject* param_1);
};

#endif