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
	/* 1009CD00 */ void FUN1009cd00();
	/* 1009CD70 */ void FUN1009cd70(char* param_1);
	/* 1009DF70 */ cMagGameObject* CreateObject(char* param_1);
	/* 1009E960 */ uchar FUN1009e960(uint param_1);
	/* 1009E980 */ void FUN1009e980(char* param_1);
	/* 1009E9F0 */ void FUN1009e9f0();
	/* 1009EC60 */ uchar FUN1009ec60(uint param_1);

private:
	/* 0x0c */ JNIEnv* jniEnv;
	/* 0x10 */ JavaVM* javaVM;
	/* 0x14 */ jfieldID thisID;
	/* 0x18 */ jfieldID currentStateID;
	/* 0x1c */ jfieldID fxID;
	/* 0x20 */ jfieldID fyID;
	/* 0x24 */ jfieldID fzID;
	/* 0x28 */ jfieldID matrixFieldsIDs[16];
	/* 0x68 */ jfieldID patrolPointPosFieldID;
	/* 0x6c */ jfieldID patrolPointRadiusFieldID;
	/* 0x70 */ jfieldID patrolPointFloatFieldID;
	/* 0x74 */ jfieldID patrolPointDataFieldID;
	/* 0x78 */ jfieldID collisionTexNameFieldID;
	/* 0x7c */ jfieldID collisionColliderFieldID;
	/* 0x80 */ jfieldID collisionExcludeFieldID;
	/* 0x84 */ jfieldID collisionOrygFieldID;
	/* 0x88 */ jfieldID collisionDeltaFieldID;
	/* 0x8c */ jfieldID collisionNormalFieldID;
	/* 0x90 */ jfieldID collisionVertexFieldID;
	/* 0x94 */ jfieldID collisionTexIDFieldID;
	/* 0x98 */ jfieldID collisionDistFieldID;
	/* 0x9c */ jfieldID rectLeftFieldID;
	/* 0xa0 */ jfieldID rectRightFieldID;
	/* 0xa4 */ jfieldID rectTopFieldID;
	/* 0xa8 */ jfieldID rectBottomFieldID;
	/* 0xac */ jfieldID lightTypeFieldID;
	/* 0xb0 */ jfieldID lightDiffuseRFieldID;
	/* 0xb4 */ jfieldID lightDiffuseGFieldID;
	/* 0xb8 */ jfieldID lightDiffuseBFieldID;
	/* 0xbc */ jfieldID lightDiffuseAFieldID;
	/* 0xc0 */ jfieldID lightSpecularRFieldID;
	/* 0xc4 */ jfieldID lightSpecularGFieldID;
	/* 0xc8 */ jfieldID lightSpecularBFieldID;
	/* 0xcc */ jfieldID lightSpecularAFieldID;
	/* 0xd0 */ jfieldID lightAmbientRFieldID;
	/* 0xd4 */ jfieldID lightAmbientGFieldID;
	/* 0xd8 */ jfieldID lightAmbientBFieldID;
	/* 0xdc */ jfieldID lightAmbientAFieldID;
	/* 0xe0 */ jfieldID lightPositionXFieldID;
	/* 0xe4 */ jfieldID lightPositionYFieldID;
	/* 0xe8 */ jfieldID lightPositionZFieldID;
	/* 0xec */ jfieldID lightDirectionXFieldID;
	/* 0xf0 */ jfieldID lightDirectionYFieldID;
	/* 0xf4 */ jfieldID lightDirectionZFieldID;
	/* 0xf8 */ jfieldID lightRangeFieldID;
	/* 0xfc */ jfieldID lightFalloffFieldID;
	/* 0x100 */ jfieldID lightAttentuation0FieldID;
	/* 0x104 */ jfieldID lightAttentuation1FieldID;
	/* 0x108 */ jfieldID lightAttentuation2FieldID;
	/* 0x10c */ jfieldID lightThetaFieldID;
	/* 0x110 */ jfieldID lightPhiFieldID;
	/* 0x114 */ jmethodID onInitializeMethodID;
	/* 0x118 */ jmethodID vectorInitMethodID;
	/* 0x11c */ jmethodID vectorInitMethodID2;
	/* 0x120 */ jmethodID matrixInitMethodID;
	/* 0x124 */ jmethodID patrolPointInitMethodID;
	/* 0x128 */ jmethodID collisionInitMethodID;
	/* 0x12c */ jmethodID rectInitMethodID;
	/* 0x130 */ uchar field_130[0x13c-0x130];
	/* 0x13c */ jmethodID onPercentageLoadLevelMethodID;
	/* 0x140 */ jmethodID lightInitMethodID;
	/* 0x144 */ uchar field_144[0x174-0x144];
	/* 0x174 */ jclass gameObjectClass;
	/* 0x178 */ jclass meshObjectClass;
	/* 0x17c */ jclass cameraClass;
	/* 0x180 */ jclass freeCameraClass;
	/* 0x184 */ jclass collisionCameraClass;
	/* 0x188 */ jclass levelClass;
	/* 0x18c */ jclass gameClass;
	/* 0x190 */ jclass vectorClass;
	/* 0x194 */ jclass matrixClass;
	/* 0x198 */ jclass patrolPointClass;
	/* 0x19c */ jclass collisionClass;
	/* 0x1a0 */ jclass rectClass;
	/* 0x1a4 */ jclass spriteClass;
	/* 0x1a8 */ jclass billboardClass;
	/* 0x1ac */ jclass particleClass;
	/* 0x1b0 */ jclass lightClass;
	/* 0x1b4 */ uchar field_1b4[0x1c0-0x1b4];
	/* 0x1c0 */ char buffer[300];
	/* 0x2ec */ uchar field_2ec[0x4ec-0x2ec];

};

STATIC_ASSERT(sizeof(CJVMData) == 0x4ec);

#endif