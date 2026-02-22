#ifndef _C_CLASS_PROTOTYPE
#define _C_CLASS_PROTOTYPE

#include <globals.h>
#include <fstream>

#include "CClassParameter.h"

class CClassPrototype {
public:
	/* 100B91C0 */ CClassPrototype(std::ifstream* param_1);
	/* 100B9250 */ ~CClassPrototype();
	/* 100B9300 */ CClassParameter* GetParameter(int param_1);
	/* 100B9310 */ char* GetPrototypeName();
	/* 100B9320 */ int GetParametersCount();
	/* 100B9340 */ void FUN_100b9340(std::ifstream* param_1);
};

#endif