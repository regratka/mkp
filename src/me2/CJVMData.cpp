#include "CJVMData.h"

#include "CGame.h"
#include "cMagMeshObject.h"
#include "CLevel.h"
#include "CFreeCamera.h"
#include "CCollisionCamera.h"
#include "cMagSprite.h"
#include "cMagBillboard.h"
#include "CParticleEmitter.h"
#include "MagTerrain.h"

/* 100BEB80-100BEB99 00019 	*/
String::String() {
	memset(buffer, 0, sizeof(buffer));
}

/* 100BEBA0-100BEBA7 00007  */
String::~String() {
}

/* 100B9120-100B913A 0001A  */
MagKernelMetaData::MagKernelMetaData() {
	
}

/* 100BECE0-100BED27 00047	*/
CTimerMethod::CTimerMethod() {

}

/* 100BED30-100BED37 00007  */
CTimerMethod::~CTimerMethod() {

}

/* 1009C7D0-1009CA5F 0028F	*/
CJVMData::CJVMData(JNIEnv* param_1) {
	unkn_2f4 = true;
	unkn_2f0 = FALSE;
	jniEnv = param_1;
	jniEnv->GetJavaVM(&javaVM);
	onInitializeMethodID = NULL;
	gameObjectClass = NULL;
	meshObjectClass = NULL;
	cameraClass = NULL;
	freeCameraClass = NULL;
	collisionCameraClass = NULL;
	levelClass = NULL;
	gameClass = NULL;
	matrixClass = NULL;
	vectorClass = NULL;
	patrolPointClass = NULL;
	collisionClass = NULL;
	rectClass = NULL;
	spriteClass = NULL;
	billboardClass = NULL;
	particleClass = NULL;
	lightClass = NULL;
	terrainClass =  NULL;
	currentStateID = NULL;
	fxID = NULL;
	fyID = NULL;
	fzID = NULL;
	patrolPointRadiusFieldID = NULL;
	patrolPointFloatFieldID = NULL;
	patrolPointDataFieldID = NULL;
	collisionTexNameFieldID = NULL;
	collisionColliderFieldID = NULL;
	collisionExcludeFieldID = NULL;
	collisionOrygFieldID = NULL;
	collisionDeltaFieldID = NULL;
	collisionNormalFieldID = NULL;
	collisionVertexFieldID = NULL;
	collisionTexIDFieldID = NULL;
	collisionDistFieldID = NULL;
	rectBottomFieldID = NULL;
	rectLeftFieldID = NULL;
	rectRightFieldID = NULL;
	rectTopFieldID = NULL;
	lightTypeFieldID = NULL;
	memset(lightDiffuseFieldIDs, 0, sizeof(lightDiffuseFieldIDs));
	memset(lightSpecularFieldIDs, 0, sizeof(lightSpecularFieldIDs));
	memset(lightAmbientFieldIDs, 0, sizeof(lightAmbientFieldIDs));
	memset(lightPositionFieldIDs, 0, sizeof(lightPositionFieldIDs));
	memset(lightDirectionFieldIDs, 0, sizeof(lightDirectionFieldIDs));
	lightRangeFieldID = NULL;
	lightFalloffFieldID = NULL;
	lightAttenuation0FieldID = NULL;
	lightAttenuation1FieldID = NULL;
	lightAttenuation2FieldID = NULL;
	lightThetaFieldID = NULL;
	lightPhiFieldID = NULL;
	memset(matrixFieldsIDs, 0, sizeof(matrixFieldsIDs)); 
  	vectorInitMethodID = NULL;
  	vectorInitMethodID2 = NULL;
  	matrixInitMethodID = NULL;
  	patrolPointInitMethodID = NULL;
  	collisionInitMethodID = NULL;
  	rectInitMethodID = NULL;
	unkn_130 = NULL;
	unkn_134 = NULL;
	unkn_138 = NULL;
	onPercentageLoadLevelMethodID = NULL;
	lightInitMethodID = NULL;
	initClassInstance = NULL;
	unkn_1bc = NULL;
	memset(initClassName, 0, sizeof(initClassName));
	LoadInitClassName("game.ini");
	LoadMetadata();
}

/* 1009CA80-1009CC03 00183	*/
CJVMData::~CJVMData() {
	for (int index = 0; index < objects.size(); index++) {
		cMagGameObject* object = objects[index];
		if (object != NULL) {
			delete object;
		}
	}
	objects.clear();
	
	for (int index2 = 0; index2 < magKernelsMetaData.size(); index2++) {
		MagKernelMetaData* metadata = magKernelsMetaData[index2];
		if (metadata != NULL) {
			delete metadata;
		}
	}

	timerMethods.clear();
}

/* 1009CC10-1009CCD3 000C3	*/
jobject CJVMData::NewObject(char* param_1) {
	jclass clazz = jniEnv->FindClass(param_1);
	if (clazz == NULL) {
		char buffer[300];
		sprintf(buffer, "Can't find %s class\n", param_1);
		MessageBox(NULL, buffer, "", 0);
		return NULL;
	}
	
	jmethodID methodID = jniEnv->GetMethodID(clazz, "<init>", "()V");
	if (methodID == NULL){
		char buffer[300];
		sprintf(buffer, "Can't find %s method\n", "<init>");
		MessageBox(NULL, buffer, "", 0);
		return NULL;
	}

	return jniEnv->NewObject(clazz, methodID);
}

/* 1009CD00-1009CD69 00069	*/
void CJVMData::LoadMetadata() {
	WIN32_FIND_DATA findData;
	HANDLE handle = FindFirstFile("java\\*.class", &findData);
	if (handle == INVALID_HANDLE_VALUE) {
		exit(0);
	}
	LoadClassMetadata(findData.cFileName);
	while(FindNextFile(handle, &findData)) {
		LoadClassMetadata(findData.cFileName);
	}
}

/* 1009CD70-1009DF6A 011FA	*/
void CJVMData::LoadClassMetadata(char* param_1) {
	char* className = strtok(param_1, ".");
	jclass clazz = jniEnv->FindClass(className);
	if (clazz == NULL) {
		char buffer[300];
		sprintf(buffer, "Can't find %s class\n", param_1);
		MessageBox(NULL, buffer, "", 0);
		exit(1);
	}

	if (strcmp(className, "GameObject") == 0) {
		gameObjectClass  = clazz;
		thisID = jniEnv->GetFieldID(clazz, "ThisID", "I");
		currentStateID = jniEnv->GetFieldID(clazz, "CurrentState", "LState;");
	}

	if (strcmp(className, "MeshObject") == 0) {
		meshObjectClass = clazz;
	}

	if (strcmp(className, "Vector") == 0) {
		fxID = jniEnv->GetFieldID(clazz, "fX", "F");
		fyID = jniEnv->GetFieldID(clazz, "fY", "F");
		fzID = jniEnv->GetFieldID(clazz, "fZ", "F");
		vectorInitMethodID = jniEnv->GetMethodID(clazz, "<init>", "()V");
		vectorInitMethodID2 = jniEnv->GetMethodID(clazz, "<init>", "(FFF)V");
		vectorClass = clazz;
	}

	if (strcmp(className, "Matrix") == 00) {
		for (int index1 = 0; index1 < 4; index1++) {
			for (int index2= 0; index2 < 4; index2++) {
				char matrixFieldBuffer[8];
				sprintf(matrixFieldBuffer, "_%d%d", index1+1, index2+1);
				matrixFieldsIDs[index1 * 4 + index2] = jniEnv->GetFieldID(clazz, matrixFieldBuffer, "F");
			}
		}
		matrixInitMethodID = jniEnv->GetMethodID(clazz, "<init>", "()V");
		matrixClass = clazz;
	}

	if (strcmp(className, "PatrolPoint") == 0) {
		patrolPointPosFieldID = jniEnv->GetFieldID(clazz, "vPos", "LVector;");
		patrolPointRadiusFieldID = jniEnv->GetFieldID(clazz, "fRadius", "F");
		patrolPointFloatFieldID = jniEnv->GetFieldID(clazz, "fFloat", "F");
		patrolPointDataFieldID = jniEnv->GetFieldID(clazz, "sData", "Ljava/lang/String;");
		patrolPointInitMethodID = jniEnv->GetMethodID(clazz, "<init>", "()V");
		patrolPointClass = clazz;
	}
	
	if (strcmp(className, "Collision") == 0) {
		collisionTexNameFieldID = jniEnv->GetFieldID(clazz, "sTexName", "Ljava/lang/String;");
		collisionColliderFieldID = jniEnv->GetFieldID(clazz, "cCollider", "LMeshObject;");
		collisionExcludeFieldID = jniEnv->GetFieldID(clazz, "cExclude", "LMeshObject;");
		collisionOrygFieldID = jniEnv->GetFieldID(clazz, "vOryg", "LVector;");
		collisionDeltaFieldID = jniEnv->GetFieldID(clazz, "vDelta", "LVector;");
		collisionNormalFieldID = jniEnv->GetFieldID(clazz, "vNormal", "LVector;");
		collisionVertexFieldID = jniEnv->GetFieldID(clazz, "vVertex", "[LVector;");
		collisionTexIDFieldID = jniEnv->GetFieldID(clazz, "byTexID", "B");
		collisionDistFieldID = jniEnv->GetFieldID(clazz, "fDist", "F");
		collisionInitMethodID = jniEnv->GetMethodID(clazz, "<init>", "()V");
		collisionClass = clazz;
	}

	if (strcmp(className, "Rect") == 0) {
		rectLeftFieldID = jniEnv->GetFieldID(clazz, "fLeft", "F");
		rectRightFieldID = jniEnv->GetFieldID(clazz, "fRight", "F");
		rectTopFieldID = jniEnv->GetFieldID(clazz, "fTop", "F");
		rectBottomFieldID = jniEnv->GetFieldID(clazz, "fBottom", "F");
		rectInitMethodID = jniEnv->GetMethodID(clazz, "<init>", "()V");
		rectClass = clazz;
	}

	if (strcmp(className, "LIGHT") == 0) {
		lightTypeFieldID = jniEnv->GetFieldID(clazz, "Type", "I");
		lightDiffuseFieldIDs[0] = jniEnv->GetFieldID(clazz, "DiffuseR", "F");
		lightDiffuseFieldIDs[1] = jniEnv->GetFieldID(clazz, "DiffuseG", "F");
		lightDiffuseFieldIDs[2] = jniEnv->GetFieldID(clazz, "DiffuseB", "F");
		lightDiffuseFieldIDs[3] = jniEnv->GetFieldID(clazz, "DiffuseA", "F");
		lightSpecularFieldIDs[0] = jniEnv->GetFieldID(clazz, "SpecularR", "F");
		lightSpecularFieldIDs[1] = jniEnv->GetFieldID(clazz, "SpecularG", "F");
		lightSpecularFieldIDs[2] = jniEnv->GetFieldID(clazz, "SpecularB", "F");
		lightSpecularFieldIDs[3] = jniEnv->GetFieldID(clazz, "SpecularA", "F");
		lightAmbientFieldIDs[0] = jniEnv->GetFieldID(clazz, "AmbientR", "F");
		lightAmbientFieldIDs[1] = jniEnv->GetFieldID(clazz, "AmbientG", "F");
		lightAmbientFieldIDs[2] = jniEnv->GetFieldID(clazz, "AmbientB", "F");
		lightAmbientFieldIDs[3] = jniEnv->GetFieldID(clazz, "AmbientA", "F");
		lightPositionFieldIDs[0] = jniEnv->GetFieldID(clazz, "PositionX", "F");
		lightPositionFieldIDs[1] = jniEnv->GetFieldID(clazz, "PositionY", "F");
		lightPositionFieldIDs[2] = jniEnv->GetFieldID(clazz, "PositionZ", "F");
		lightDirectionFieldIDs[0] = jniEnv->GetFieldID(clazz, "DirectionX", "F");
		lightDirectionFieldIDs[1] = jniEnv->GetFieldID(clazz, "DirectionY", "F");
		lightDirectionFieldIDs[2] = jniEnv->GetFieldID(clazz, "DirectionZ", "F");
		lightRangeFieldID = jniEnv->GetFieldID(clazz, "Range", "F");
		lightFalloffFieldID = jniEnv->GetFieldID(clazz, "Falloff", "F");
		lightAttenuation0FieldID = jniEnv->GetFieldID(clazz, "Attenuation0", "F");
		lightAttenuation1FieldID = jniEnv->GetFieldID(clazz, "Attenuation1", "F");
		lightAttenuation2FieldID = jniEnv->GetFieldID(clazz, "Attenuation2", "F");
		lightThetaFieldID = jniEnv->GetFieldID(clazz, "Theta", "F");
		lightPhiFieldID = jniEnv->GetFieldID(clazz, "Phi", "F");
		lightInitMethodID = jniEnv->GetMethodID(clazz, "<init>", "()V");
		lightClass = clazz;
	}

	if (strcmp(className, "Level") == 0) {
		levelClass = clazz;
	}
	if (strcmp(className, "Camera") == 0) {
		cameraClass = clazz;
	}
	if (strcmp(className, "FreeCamera") == 0) {
		freeCameraClass = clazz;
	}
	if (strcmp(className, "CollisionCamera") == 0) {
		collisionCameraClass = clazz;
	}
	if (strcmp(className, "Game") == 0) {
		gameClass = clazz;
	}
	if (strcmp(className, "Sprite") == 0) {
		spriteClass = clazz;
	}
	if (strcmp(className, "Billboard") == 0) {
		billboardClass = clazz;
	}
	if (strcmp(className, "Particle") == 0) {
		particleClass = clazz;
	}

	if (strcmp(className, this->initClassName) == 0) { // Is the main game class
		onInitializeMethodID = jniEnv->GetMethodID(clazz, "OnInitialize", "()V");
		onPercentageLoadLevelMethodID = jniEnv->GetMethodID(clazz, "OnPercentageLoadLevel", "(FI)V");
	}

	MagKernelMetaData* kernelData = new MagKernelMetaData();
	strcpy(kernelData->className, className);
	kernelData->clazz = clazz;

	kernelData->OnFrameMethodID = jniEnv->GetMethodID(clazz, "OnFrame", "()V");
	if (kernelData->OnFrameMethodID == NULL) {
		jniEnv->ExceptionClear();
	}
	kernelData->OnActivateMethodID = jniEnv->GetMethodID(clazz, "OnActivate", "()V");
	if (kernelData->OnActivateMethodID == NULL) {
		jniEnv->ExceptionClear();
	}
	kernelData->OnActivateLevelMethodID = jniEnv->GetMethodID(clazz, "OnActivateLEvel", "()V");
	if (kernelData->OnActivateLevelMethodID == NULL) {
		jniEnv->ExceptionClear();
	}
	kernelData->OnDestinationDirMethodID = jniEnv->GetMethodID(clazz, "OnDestinationDir", "()V");
	if (kernelData->OnDestinationDirMethodID == NULL) {
		jniEnv->ExceptionClear();
	}
	kernelData->OnDestinationPosMethodID = jniEnv->GetMethodID(clazz, "OnDestinationPos", "(LVector;)V");
	if (kernelData->OnDestinationPosMethodID == NULL) {
		jniEnv->ExceptionClear();
	}
	kernelData->OnChangeMovementMethodID = jniEnv->GetMethodID(clazz, "OnChangeMovement", "(I)V");
	if (kernelData->OnChangeMovementMethodID == NULL) {
		jniEnv->ExceptionClear();
	}
	kernelData->OnInputKeyMethodID = jniEnv->GetMethodID(clazz, "OnInputKey", "([Z)V");
	if (kernelData->OnInputKeyMethodID == NULL) {
		jniEnv->ExceptionClear();
	}
	kernelData->OnCollisionObjectMethodID = jniEnv->GetMethodID(clazz, "OnCollisionObject", "(LMeshObject;)V");
	if (kernelData->OnCollisionObjectMethodID == NULL) {
		jniEnv->ExceptionClear();
	}
	kernelData->OnAnimEndMethodID = jniEnv->GetMethodID(clazz, "OnAnimEnd", "(Ljava/lang/String;)V");
	if (kernelData->OnAnimEndMethodID == NULL) {
		jniEnv->ExceptionClear();
	}
	kernelData->OnInputMouseMethodID = jniEnv->GetMethodID(clazz, "OnInputMouse", "(FFZZ)V");
	if (kernelData->OnInputMouseMethodID == NULL) {
		jniEnv->ExceptionClear();
	}
	kernelData->OnMouseArriveMethodID = jniEnv->GetMethodID(clazz, "OnMouseArrive", "(I)V");
	if (kernelData->OnMouseArriveMethodID == NULL) {
		jniEnv->ExceptionClear();
	}
	kernelData->OnMouseLeaveMethodID = jniEnv->GetMethodID(clazz, "OnMouseLeave", "(I)V");
	if (kernelData->OnMouseLeaveMethodID == NULL) {
		jniEnv->ExceptionClear();
	}
	kernelData->OnMouseEnterMethodID = jniEnv->GetMethodID(clazz, "OnMouseEnter", "(I)V");
	if (kernelData->OnMouseEnterMethodID == NULL) {
		jniEnv->ExceptionClear();
	}
	kernelData->OnAttachMethodID = jniEnv->GetMethodID(clazz, "OnAttach", "(LMeshObject;)V");
	if (kernelData->OnAttachMethodID == NULL) {
		jniEnv->ExceptionClear();
	}
	kernelData->OnDetachMethodID = jniEnv->GetMethodID(clazz, "OnDetach", "(LMeshObject;)V");
	if (kernelData->OnDetachMethodID == NULL) {
		jniEnv->ExceptionClear();
	}
	kernelData->OnPathVergeMethodID = jniEnv->GetMethodID(clazz, "OnPathVerge", "()V");
	if (kernelData->OnPathVergeMethodID == NULL) {
		jniEnv->ExceptionClear();
	}
	kernelData->OnInsideFrustumCullMethodID = jniEnv->GetMethodID(clazz, "OnInsideFrustumCull", "()V");
	if (kernelData->OnInsideFrustumCullMethodID == NULL) {
		jniEnv->ExceptionClear();
	}
	kernelData->OnOutsideFrustumCullMethodID = jniEnv->GetMethodID(clazz, "OnOutsideFrustumCull", "()V");
	if (kernelData->OnOutsideFrustumCullMethodID == NULL) {
		jniEnv->ExceptionClear();
	}
	kernelData->OnParticleSequenceEndMethodID = jniEnv->GetMethodID(clazz, "OnParticleSequenceEnd", "()V");
	if (kernelData->OnParticleSequenceEndMethodID == NULL) {
		jniEnv->ExceptionClear();
	}
	kernelData->OnDestTimeMethodID = jniEnv->GetMethodID(clazz, "OnDestTime", "(F)V");
	if (kernelData->OnDestTimeMethodID == NULL) {
		jniEnv->ExceptionClear();
	}
	kernelData->OnSlideMethodID = jniEnv->GetMethodID(clazz, "OnSlide", "(LMeshObject;)V");
	if (kernelData->OnSlideMethodID == NULL) {
		jniEnv->ExceptionClear();
	}
	kernelData->OnFadeInEndMethodID = jniEnv->GetMethodID(clazz, "OnFadeInEnd", "()V");
	if (kernelData->OnFadeInEndMethodID == NULL) {
		jniEnv->ExceptionClear();
	}
	kernelData->OnFadeOutEndMethodID = jniEnv->GetMethodID(clazz, "OnFadeOutEnd", "()V");
	if (kernelData->OnFadeOutEndMethodID == NULL) {
		jniEnv->ExceptionClear();
	}
	kernelData->OnCrashMethodID = jniEnv->GetMethodID(clazz, "OnCrash", "()V");
	if (kernelData->OnCrashMethodID == NULL) {
		jniEnv->ExceptionClear();
	}
	kernelData->OnActivateViewMethodID = jniEnv->GetMethodID(clazz, "OnActivateView", "()V");
	if (kernelData->OnActivateViewMethodID == NULL) {
		jniEnv->ExceptionClear();
	}
	kernelData->OnDeactivateViewMethodID = jniEnv->GetMethodID(clazz, "OnDeactivateView", "()V");
	if (kernelData->OnDeactivateViewMethodID == NULL) {
		jniEnv->ExceptionClear();
	}
	kernelData->OnAttachChildMethodID = jniEnv->GetMethodID(clazz, "OnAttachChild", "(LMeshObject;)V");
	if (kernelData->OnAttachChildMethodID == NULL) {
		jniEnv->ExceptionClear();
	}
	kernelData->OnDetachChildMethodID = jniEnv->GetMethodID(clazz, "OnDetachChild", "(LMeshObject;)V");
	if (kernelData->OnDetachChildMethodID == NULL) {
		jniEnv->ExceptionClear();
	}
	kernelData->OnCreateMethodID = jniEnv->GetMethodID(clazz, "OnCreate", "()V");
	if (kernelData->OnCreateMethodID == NULL) {
		jniEnv->ExceptionClear();
	}
	kernelData->OnDestroyMethodID = jniEnv->GetMethodID(clazz, "OnDestroy", "OnDestroy");
	if (kernelData->OnDestroyMethodID == NULL) {
		jniEnv->ExceptionClear();
	}

	magKernelsMetaData.push_back(kernelData);
}

/* 1009DF70-1009E862 008F2	*/
cMagGameObject* CJVMData::CreateObject(char* param_1) {
	jobject object = NewObject(param_1);
	if (object == NULL) {
		return NULL;
	}

	if (jniEnv->IsInstanceOf(object, meshObjectClass) == 1) {
		cMagMeshObject* meshObject = new cMagMeshObject();
		meshObject->javaGlobalRef = jniEnv->NewGlobalRef(object);
		meshObject->javaMetaData = FindClassMetaData(param_1);
		jniEnv->SetIntField(object, thisID, (jint)meshObject);
		objects.push_back(meshObject);
		if (meshObject->javaMetaData->OnCreateMethodID != NULL) {
			jniEnv->CallVoidMethod(meshObject->javaGlobalRef, meshObject->javaMetaData->OnCreateMethodID);
		}
		return meshObject;
	}

	
	if (jniEnv->IsInstanceOf(object, levelClass) == 1) {
		CLevel* levelObject = new CLevel();
		levelObject->javaGlobalRef = jniEnv->NewGlobalRef(object);
		levelObject->javaMetaData = FindClassMetaData(param_1);
		jniEnv->SetIntField(object, thisID, (jint)levelObject);
		objects.push_back(levelObject);
		if (levelObject->javaMetaData->OnCreateMethodID != NULL) {
			jniEnv->CallVoidMethod(levelObject->javaGlobalRef, levelObject->javaMetaData->OnCreateMethodID);
		}
		return levelObject;
	}

	if (jniEnv->IsInstanceOf(object, freeCameraClass) == 1) {
		CFreeCamera* cameraObject = new CFreeCamera();
		cameraObject->javaGlobalRef = jniEnv->NewGlobalRef(object);
		cameraObject->javaMetaData = FindClassMetaData(param_1);
		jniEnv->SetIntField(object, thisID, (jint)cameraObject);
		objects.push_back(cameraObject);
		if (cameraObject->javaMetaData->OnCreateMethodID != NULL) {
			jniEnv->CallVoidMethod(cameraObject->javaGlobalRef, cameraObject->javaMetaData->OnCreateMethodID);
		}
		return cameraObject;
	}

	if (jniEnv->IsInstanceOf(object, collisionCameraClass) == 1) {
		CCollisionCamera* cameraObject = new CCollisionCamera();
		cameraObject->javaGlobalRef = jniEnv->NewGlobalRef(object);
		cameraObject->javaMetaData = FindClassMetaData(param_1);
		jniEnv->SetIntField(object, thisID, (jint)cameraObject);
		objects.push_back(cameraObject);
		if (cameraObject->javaMetaData->OnCreateMethodID != NULL) {
			jniEnv->CallVoidMethod(cameraObject->javaGlobalRef, cameraObject->javaMetaData->OnCreateMethodID);
		}
		return cameraObject;
	}

	if (jniEnv->IsInstanceOf(object, cameraClass) == 1) {
		CCamera* cameraObject = new CCamera();
		cameraObject->javaGlobalRef = jniEnv->NewGlobalRef(object);
		cameraObject->javaMetaData = FindClassMetaData(param_1);
		jniEnv->SetIntField(object, thisID, (jint)cameraObject);
		objects.push_back(cameraObject);
		if (cameraObject->javaMetaData->OnCreateMethodID != NULL) {
			jniEnv->CallVoidMethod(cameraObject->javaGlobalRef, cameraObject->javaMetaData->OnCreateMethodID);
		}
		return cameraObject;
	}

	if (jniEnv->IsInstanceOf(object, spriteClass) == 1) {
		cMagSprite* spriteObject = new cMagSprite();
		spriteObject->javaGlobalRef = jniEnv->NewGlobalRef(object);
		spriteObject->javaMetaData = FindClassMetaData(param_1);
		jniEnv->SetIntField(object, thisID, (jint)spriteObject);
		objects.push_back(spriteObject);
		if (spriteObject->javaMetaData->OnCreateMethodID != NULL) {
			jniEnv->CallVoidMethod(spriteObject->javaGlobalRef, spriteObject->javaMetaData->OnCreateMethodID);
		}
		return spriteObject;
	}

	if (jniEnv->IsInstanceOf(object, billboardClass) == 1) {
		cMagBillboard* billboardObject = new cMagBillboard();
		billboardObject->javaGlobalRef = jniEnv->NewGlobalRef(object);
		billboardObject->javaMetaData = FindClassMetaData(param_1);
		jniEnv->SetIntField(object, thisID, (jint)billboardObject);
		objects.push_back(billboardObject);
		if (billboardObject->javaMetaData->OnCreateMethodID != NULL) {
			jniEnv->CallVoidMethod(billboardObject->javaGlobalRef, billboardObject->javaMetaData->OnCreateMethodID);
		}
		return billboardObject;
	}

	if (jniEnv->IsInstanceOf(object, particleClass) == 1) {
		CParticleEmitter* particleObject = new CParticleEmitter();
		particleObject->javaGlobalRef = jniEnv->NewGlobalRef(object);
		particleObject->javaMetaData = FindClassMetaData(param_1);
		jniEnv->SetIntField(object, thisID, (jint)particleObject);
		objects.push_back(particleObject);
		if (particleObject->javaMetaData->OnCreateMethodID != NULL) {
			jniEnv->CallVoidMethod(particleObject->javaGlobalRef, particleObject->javaMetaData->OnCreateMethodID);
		}
		return particleObject;
	}

	if (jniEnv->IsInstanceOf(object, terrainClass) == 1) {
		MagTerrain* terrainObject = new MagTerrain();
		terrainObject->javaGlobalRef = jniEnv->NewGlobalRef(object);
		terrainObject->javaMetaData = FindClassMetaData(param_1);
		jniEnv->SetIntField(object, thisID, (jint)terrainObject);
		objects.push_back(terrainObject);
		if (terrainObject->javaMetaData->OnCreateMethodID != NULL) {
			jniEnv->CallVoidMethod(terrainObject->javaGlobalRef, terrainObject->javaMetaData->OnCreateMethodID);
		}
		return terrainObject;
	}

	return NULL;
}

/* 1009E870-1009E8DC 0006C*/ 
D3DXVECTOR3 CJVMData::GetObjectPosition(jobject param_1) {
	D3DXVECTOR3 position;
	position.x = jniEnv->GetFloatField(param_1, fxID);
	position.y = jniEnv->GetFloatField(param_1, fyID);
	position.z = jniEnv->GetFloatField(param_1, fzID);
	return position;
}

/* 1009E8E0-1009E958 00078	*/
MagKernelMetaData* CJVMData::FindClassMetaData(char* param_1) {
	for (int index = 0; index < magKernelsMetaData.size(); index++) {
		if (strcmp(magKernelsMetaData[index]->className, param_1) == 0) {
			return magKernelsMetaData[index];
		}
	}
	return NULL;
}

/* 1009E960-1009E978 00018	*/
jint CJVMData::GetObjectID(jobject param_1) {
	return jniEnv->GetIntField(param_1, thisID);
}

/* 1009E980-1009E9E8 00068	*/
void CJVMData::LoadInitClassName(char* param_1) {
	char buffer[299];
	GetCurrentDirectory(sizeof(buffer), buffer);
	sprintf(buffer, "%s\\%s", buffer, param_1);
	GetPrivateProfileString("Game", "Class", "", initClassName, sizeof(initClassName), buffer);
}


/* 1009E9F0-1009EA67 00077	*/
void CJVMData::CreateInitClass(CGame* param_1) {
	initClassInstance = NewObject(initClassName);
	if (jniEnv->IsInstanceOf(initClassInstance, gameClass) == 1) {
		param_1->javaMetaData = FindClassMetaData(initClassName);
		param_1->javaGlobalRef = jniEnv->NewGlobalRef(initClassInstance);
		jniEnv->CallVoidMethod(initClassInstance, onInitializeMethodID);
	}
}

/* 1009EA70-1009EB17 000A7	*/
void CJVMData::DestroyObject(cMagGameObject* param_1) {
	if (param_1->javaGlobalRef != NULL) {
		if (param_1->javaMetaData->OnDestroyMethodID != NULL) {
			jniEnv->CallVoidMethod(param_1->javaGlobalRef, param_1->javaMetaData->OnDestroyMethodID);
		}
		jniEnv->DeleteGlobalRef(param_1->javaGlobalRef);
	}
	
	if (param_1->unkn_GlobalRef != NULL) {
		jniEnv->DeleteGlobalRef(param_1->unkn_GlobalRef);
	}

	for (std::vector<cMagGameObject*>::iterator it = objects.begin(); 
			it != objects.end(); it++) {
		if (param_1 == *it) {
			objects.erase(it);
			break;
		}
	}
}

/* 1009EB20-1009EB5D 0003D */ 
jobject CJVMData::NewVectorObject(D3DXVECTOR3 param_1) {
	return jniEnv->NewObject(vectorClass, vectorInitMethodID2, param_1.x, param_1.y, param_1.z);
}

/* 1009EB60-1009EC3F 000DF*/ 
String CJVMData::GetString(jstring param_1) {
	String string;
	const char* utfChars = jniEnv->GetStringUTFChars(param_1, NULL);
	strcpy(string.buffer, utfChars);
	jniEnv->ReleaseStringUTFChars(param_1, utfChars);
	return string;
}

/* 1009EC60-1009EC74 00014	*/
jstring CJVMData::CreateJString(char* param_1) {
	return jniEnv->NewStringUTF(param_1);
}

/* 1009EC80-1009EEA0 00220	*/
void CJVMData::CreateTimerMethod(cMagGameObject* param_1, char* param_2, float param_3, int param_4) {
	if (param_4 == 0 || param_3 == 0.0f) {
		return;
	}

	for (int index = 0; index < timerMethods.size(); index++) {
		if (param_1 == timerMethods[index].gameObject && strcmp(param_2, timerMethods[index].methodName) == 0) {
			timerMethods[index].field_0xdc = param_3;
			timerMethods[index].repetitions = param_4;
			return;
		}
	}

	jmethodID methodID = jniEnv->GetMethodID(param_1->javaMetaData->clazz, param_2, "()V");
	if (methodID == NULL) {
		jniEnv->ExceptionClear();
		return;
	}

	CTimerMethod timerMethod;
	strcpy(timerMethod.methodName, param_2);
	timerMethod.field_0xdc = param_3;
	timerMethod.gameObject = param_1;
	timerMethod.globalRef = param_1->javaGlobalRef;
	timerMethod.repetitions = param_4;
	timerMethod.methodID = methodID;
	timerMethods.push_back(timerMethod);
}

/* 1009EEA0-1009F032 00192 */ 
void CJVMData::DisableCallMethod(cMagGameObject* param_1, char* param_2) {
	for (int index = 0; index < timerMethods.size(); index++) {
		if (param_1 == timerMethods[index].gameObject && strcmp(param_2, timerMethods[index].methodName) == 0) {
			timerMethods.erase(timerMethods.begin()+index);
			break;
		}
	}
}

/* 1009F040-1009F274 00234 */ 
void CJVMData::DeleteCallMethods(std::vector<CTimerMethod> param_1) {
	for (int index = 0; index < param_1.size(); index++) {
		for (int index2 = 0; index2 < timerMethods.size(); index2++) {
			if (param_1[index].gameObject == timerMethods[index2].gameObject
				&& strcmp(param_1[index].methodName, timerMethods[index2].methodName) == 0) {
				timerMethods.erase(timerMethods.begin()+index2);
				break;
			}
		}
	}
}

/* 1009F280-1009F35F 00DF */ 
void CJVMData::CleanCallMethods() {
	timerMethods.clear();
}

/* 1009F360-1009F3BD 0005D */ 
void CJVMData::FUN1009f360(float* param_1, jobject param_2) {
	float fieldValues[4][4];
	for (int x; x < 4; x++) {
		for (int y; y < 4; y++) {
			fieldValues[x][y] = jniEnv->GetFloatField(param_2, matrixFieldsIDs[x*4+y]);
		}
	}
	memcpy(param_1, fieldValues, sizeof(fieldValues));
}

/* 1009FF60-100A0074 00114 */ 
void CJVMData::TraceExceptions() {
	jthrowable exception = jniEnv->ExceptionOccurred();
	if (exception == NULL) {
		return;
	}

	jniEnv->ExceptionDescribe();

	jclass exceptionClass = jniEnv->GetObjectClass(exception);
	if (exceptionClass == NULL) {
		jniEnv->ExceptionClear();
		DebugLog("CJVMData::TraceExceptions: GetObjectClass failed");
		return;
	}
	
	jmethodID toStringMethodID = jniEnv->GetMethodID(exceptionClass, "toString", "()Ljava/lang/String;");
	if (toStringMethodID == NULL) {
		DebugLog("CJVMData::TraceExceptions: GetMethodID failed");
		jniEnv->ExceptionClear();
		return;
	}

	jstring exceptionString = (jstring)jniEnv->CallObjectMethod(exception, toStringMethodID);
	const char* exceptionChars = jniEnv->GetStringUTFChars(exceptionString, NULL);
	char buffer[500];
	strcpy(buffer, exceptionChars);
	DebugLog(buffer);
	jniEnv->ReleaseStringUTFChars(exceptionString, exceptionChars);
	jniEnv->ExceptionClear();
}

