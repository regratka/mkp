#include "CJVMData.h"

MagKernelMetaData::MagKernelMetaData() {
	
}

/* 1009C7D0-1009CA5F 0028F	*/
CJVMData::CJVMData(JNIEnv* param_1) {
	jniEnv = param_1;
	jniEnv->GetJavaVM(&javaVM);

	FUN1009e980("game.ini");
	FUN1009cd00();
}

/* 1009CA80-1009CC03 00183	*/
CJVMData::~CJVMData() {
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
void CJVMData::FUN1009cd00() {
	WIN32_FIND_DATA findData;
	HANDLE handle = FindFirstFile("java\\*.class", &findData);
	if (handle == INVALID_HANDLE_VALUE) {
		exit(0);
	}
	FUN1009cd70(findData.cFileName);
	while(FindNextFile(handle, &findData)) {
		FUN1009cd70(findData.cFileName);
	}
}

/* 1009CD70-1009DF6A 011FA	*/
void CJVMData::FUN1009cd70(char* param_1) {
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
		thisID = jniEnv->GetFieldID(clazz, "CurrentState", "LState;");
	}

	if (strcmp(className, "MeshObject") == 0) {
		meshObjectClass = clazz;
	}

	if (strcmp(className, "Vector") == 0) {
		fxID = jniEnv->GetFieldID(clazz, "fX", "F");
		fxID = jniEnv->GetFieldID(clazz, "fY", "F");
		fzID = jniEnv->GetFieldID(clazz, "fZ", "F");
		vectorInitMethodID = jniEnv->GetMethodID(clazz, "<init>", "()V");
		vectorInitMethodID2 = jniEnv->GetMethodID(clazz, "<init>", "(FFF)V");
		vectorClass = clazz;
	}

	if (strcmp(className, "Matrix") == 00) {
		for (int index1; index1 < 4; index1++) {
			for (int index2; index2 < 4; index2++) {
				char matrixFieldBuffer[8];
				sprintf(matrixFieldBuffer, "_%d%d", index1, index2);
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
		lightDiffuseRFieldID = jniEnv->GetFieldID(clazz, "DiffuseR", "F");
		lightDiffuseGFieldID = jniEnv->GetFieldID(clazz, "DiffuseG", "F");
		lightDiffuseBFieldID = jniEnv->GetFieldID(clazz, "DiffuseB", "F");
		lightDiffuseAFieldID = jniEnv->GetFieldID(clazz, "DiffuseA", "F");
		lightSpecularRFieldID = jniEnv->GetFieldID(clazz, "SpecularR", "F");
		lightSpecularGFieldID = jniEnv->GetFieldID(clazz, "SpecularG", "F");
		lightSpecularBFieldID = jniEnv->GetFieldID(clazz, "SpecularB", "F");
		lightSpecularAFieldID = jniEnv->GetFieldID(clazz, "SpecularA", "F");
		lightAmbientRFieldID = jniEnv->GetFieldID(clazz, "AmbientR", "F");
		lightAmbientGFieldID = jniEnv->GetFieldID(clazz, "AmbientG", "F");
		lightAmbientBFieldID = jniEnv->GetFieldID(clazz, "AmbientB", "F");
		lightAmbientAFieldID = jniEnv->GetFieldID(clazz, "AmbientA", "F");
		lightPositionXFieldID = jniEnv->GetFieldID(clazz, "PositionX", "F");
		lightPositionYFieldID = jniEnv->GetFieldID(clazz, "PositionY", "F");
		lightPositionZFieldID = jniEnv->GetFieldID(clazz, "PositionZ", "F");
		lightDirectionXFieldID = jniEnv->GetFieldID(clazz, "DirectionX", "F");
		lightDirectionYFieldID = jniEnv->GetFieldID(clazz, "DirectionY", "F");
		lightDirectionZFieldID = jniEnv->GetFieldID(clazz, "DirectionZ", "F");
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
	return 0;
}

/* 1009E960-1009E978 00018	*/
uchar CJVMData::FUN1009e960(uint param_1) {
	return 0;
}

/* 1009E980-1009E9E8 00068	*/
void CJVMData::FUN1009e980(char* param_1) {

	char buffer[299];
	GetCurrentDirectory(sizeof(buffer), buffer);
	sprintf(buffer, "%s\\%s", buffer, param_1);
	GetPrivateProfileString("Game", "Class", "", initClassName, sizeof(initClassName), buffer);
}


/* 1009E9F0-1009EA67 00077	*/
void CJVMData::FUN1009e9f0() {
}

/* 1009EC60-1009EC74 00014	*/
uchar CJVMData::FUN1009ec60(uint param_1) {
	return 0;
}

