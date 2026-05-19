#ifndef _C_J_V_M_DATA
#define _C_J_V_M_DATA

#include <globals.h>
#include <jni.h>

#include "cMagGameObject.h"

class DLLEXPORT String {
public:
	/* 100BEB80 */ String();
	/* 100BEBA0 */ virtual ~String();

public:
	/* 0x04 */ char buffer[300];
};

class MagKernelMetaData {

public:
	/* 100B9120 */ MagKernelMetaData();

public:
	/* 0x00 */ cMagLog log;
	/* 0x08 */ jclass clazz;
	/* 0x0c */ jmethodID OnFrameMethodID;
	/* 0x10 */ jmethodID azz;
	/* 0x14 */ jmethodID OnInputKeyMethodID;
	/* 0x18 */ jmethodID OnActivateMethodID;
	/* 0x1c */ jmethodID OnActivateLevelMethodID;
	/* 0x20 */ jmethodID OnCollisionObjectMethodID;
	/* 0x24 */ jmethodID OnDestinationDirMethodID;
	/* 0x28 */ jmethodID OnDestinationPosMethodID;
	/* 0x2c */ jmethodID OnChangeMovementMethodID;
	/* 0x30 */ jmethodID OnAnimEndMethodID;
	/* 0x34 */ jmethodID OnInputMouseMethodID;
	/* 0x38 */ jmethodID OnMouseArriveMethodID;
	/* 0x3c */ jmethodID OnMouseLeaveMethodID;

	/* 0x40 */ jmethodID OnMouseEnterMethodID;
	/* 0x44 */ jmethodID OnAttachMethodID;
	/* 0x48 */ jmethodID OnDetachMethodID;
	/* 0x4c */ jmethodID OnPathVergeMethodID;

	/* 0x50 */ jmethodID OnInsideFrustumCullMethodID;
	/* 0x54 */ jmethodID OnOutsideFrustumCullMethodID;
	/* 0x58 */ jmethodID OnParticleSequenceEndMethodID;
	/* 0x5c */ jmethodID OnDestTimeMethodID;

	/* 0x60 */ jmethodID OnSlideMethodID;
	/* 0x64 */ jmethodID OnFadeOutEndMethodID;
	/* 0x68 */ jmethodID OnFadeInEndMethodID;
	/* 0x6c */ jmethodID OnCrashMethodID;

	/* 0x70 */ jmethodID OnDeactivateViewMethodID;
	/* 0x74 */ jmethodID OnActivateViewMethodID;
	/* 0x78 */ jmethodID OnDetachChildMethodID;
	/* 0x7c */ jmethodID OnAttachChildMethodID;

	/* 0x80 */ jmethodID OnCreateMethodID;
	/* 0x84 */ jmethodID OnDestroyMethodID;
	/* 0x88 */ char className[100];
};

STATIC_ASSERT(sizeof(MagKernelMetaData) == 0xec);

class CTimerMethod {
public:
	/* 100BECE0 */ CTimerMethod();
	/* 100BED30 */ virtual ~CTimerMethod();

public:
	/* 0x04 */ char methodName[100];
	/* 0x68 */ char field_0x68[100];
	/* 0xcc */ jmethodID methodID;
	/* 0xd0 */ jobject globalRef;
	/* 0xd4 */ cMagGameObject* gameObject;
	/* 0xd8 */ void* field_0xd8;
	/* 0xdc */ float field_0xdc;
	/* 0xe0 */ int repetitions;
};

STATIC_ASSERT(sizeof(CTimerMethod) == 0xe4);

class CJVMData : public cMagLog {
public:
	/* 1009C7D0 */ CJVMData(JNIEnv* param_1);
	/* 1009CA80 */ virtual ~CJVMData();
	/* 1009CC10 */ jobject NewObject(char* param_1);
	/* 1009CD00 */ void LoadMetadata();
	/* 1009CD70 */ void LoadClassMetadata(char* param_1);
	/* 1009DF70 */ cMagGameObject* CreateObject(char* param_1);
	/* 1009E870 */ D3DXVECTOR3 GetObjectPosition(jobject param_1);
	/* 1009E8E0 */ MagKernelMetaData* FindClassMetaData(char* param_1);
	/* 1009E960 */ jint GetObjectID(jobject param_1);
	/* 1009E980 */ void LoadInitClassName(char* param_1);
	/* 1009E9F0 */ void CreateInitClass(CGame* param_1);
	/* 1009EA70 */ void DestroyObject(cMagGameObject* param_1);
	/* 1009EB20 */ jobject NewVectorObject(D3DXVECTOR3 param_1);
	/* 1009EB60 */ String GetString(jstring param_1);
	/* 1009EC60 */ jstring CreateJString(char* param_1);
	/* 1009EC80 */ void CreateTimerMethod(cMagGameObject* param_1, char* param_2, float param_3, int param_4);
	/* 1009EEA0 */ void DisableCallMethod(cMagGameObject* param_1, char* param_2);
	/* 1009F040 */ void DeleteCallMethods(std::vector<CTimerMethod> param_1);
	/* 1009F280 */ void CleanCallMethods();
	/* 1009F360 */ void FUN1009f360(float* param_1, jobject param_2);
	/* 1009FF60 */ void TraceExceptions();

	void CallVoidMethod(jobject ref, jmethodID methodId) {
		jniEnv->CallVoidMethod(ref, methodId);
	}
	
public: // HACK
	/* 0x0c */ JNIEnv* jniEnv;
private:
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
	/* 0xa0 */ jfieldID rectTopFieldID;
	/* 0xa4 */ jfieldID rectRightFieldID;
	/* 0xa8 */ jfieldID rectBottomFieldID;
	/* 0xac */ jfieldID lightTypeFieldID;
	/* 0xb0 */ jfieldID lightDiffuseFieldIDs[4];
	/* 0xc0 */ jfieldID lightSpecularFieldIDs[4];
	/* 0xd0 */ jfieldID lightAmbientFieldIDs[4];
	/* 0xe0 */ jfieldID lightPositionFieldIDs[3];
	/* 0xec */ jfieldID lightDirectionFieldIDs[3];
	/* 0xf8 */ jfieldID lightRangeFieldID;
	/* 0xfc */ jfieldID lightFalloffFieldID;
	/* 0x100 */ jfieldID lightAttenuation0FieldID;
	/* 0x104 */ jfieldID lightAttenuation1FieldID;
	/* 0x108 */ jfieldID lightAttenuation2FieldID;
	/* 0x10c */ jfieldID lightThetaFieldID;
	/* 0x110 */ jfieldID lightPhiFieldID;
	/* 0x114 */ jmethodID onInitializeMethodID;
	/* 0x118 */ jmethodID vectorInitMethodID;
	/* 0x11c */ jmethodID vectorInitMethodID2;
	/* 0x120 */ jmethodID matrixInitMethodID;
	/* 0x124 */ jmethodID patrolPointInitMethodID;
	/* 0x128 */ jmethodID collisionInitMethodID;
	/* 0x12c */ jmethodID rectInitMethodID;
	/* 0x130 */ void* unkn_130;
	/* 0x134 */ void* unkn_134;
	/* 0x138 */ void* unkn_138;
	/* 0x13c */ jmethodID onPercentageLoadLevelMethodID;
	/* 0x140 */ jmethodID lightInitMethodID;
	/* 0x144 */ std::vector<cMagGameObject*> objects;
	/* 0x154 */ std::vector<MagKernelMetaData*> magKernelsMetaData;
	/* 0x164 */ std::vector<CTimerMethod> timerMethods;
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
	/* 0x1b4 */ jclass terrainClass;
	/* 0x1b8 */ jobject initClassInstance;
	/* 0x1bc */ void* unkn_1bc;
	/* 0x1c0 */ char initClassName[300];
	/* 0x2ec */ uchar field_2ec[0x2f0-0x2ec];
	/* 0x2f0 */ uint unkn_2f0;
	/* 0x2f4 */ bool unkn_2f4;
	/* 0x2f5 */ uchar field_2f5[0x4ec-0x2f5];

};

STATIC_ASSERT(sizeof(CJVMData) == 0x4ec);

#endif