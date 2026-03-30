#ifndef _C_J_V_M_DATA
#define _C_J_V_M_DATA

#include <globals.h>
#include <jni.h>

#include "cMagGameObject.h"

class CJVMData : public cMagLog {
public:
	/* 1009C7D0 */ CJVMData(JNIEnv* param_1);
	/* 1009CA80 */ virtual ~CJVMData();
	/* 1009CC10 */ jobject NewObject(char* param_1);
	/* 1009CD00 */ void FUN_1009cd00();
	/* 1009CD70 */ void FUN_1009cd70(char* param_1);
	/* 1009DF70 */ cMagGameObject* CreateObject(char* param_1);
	/* 1009E960 */ uchar FUN_1009e960(uint param_1);
	/* 1009E980 */ void FUN_1009e980(char* param_1);
	/* 1009E9F0 */ void FUN_1009e9f0();
	/* 1009EC60 */ uchar FUN_1009ec60(uint param_1);

private:
	/* 0x0c */ JNIEnv* jniEnv;
	/* 0x10 */ JavaVM* javaVM;
	/* 0x14 */ uchar field_14[0x1c0-0x14];
	/* 0x1c0 */ char buffer[300];
	/* 0x2ec */ uchar field_2ec[0x4ec-0x2ec];

};

STATIC_ASSERT(sizeof(CJVMData) == 0x4ec);

#endif