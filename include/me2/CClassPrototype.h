#ifndef _C_CLASS_PROTOTYPE
#define _C_CLASS_PROTOTYPE

#include <globals.h>

class CClassPrototype {
public:
	/* 100B91C0 */ CClassPrototype(std_basic_ifstream* param_1);
	/* 100B9250 */ void ~CClassPrototype(CClassPrototype* param_1);
	/* 100B9300 */ CClassParameter* GetParameter(int param_1);
	/* 100B9310 */ char* GetPrototypeName();
	/* 100B9320 */ int GetParametersCount();
	/* 100B9340 */ void FUN_100b9340(std_basic_ifstream* param_1);
};

#endif