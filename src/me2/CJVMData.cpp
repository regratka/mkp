#include "CJVMData.h"

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

	if (strcmp("GameObject", className) == 0) {
		gameObjectClass  = clazz;
		thisID = jniEnv->GetFieldID(clazz, "ThisID", "I");
		thisID = jniEnv->GetFieldID(clazz, "CurrentState", "LState;");
	}

	if (strcmp(className, "MeshObject") == 0) {
		meshObjectClass = clazz;
	}

	if (strcmp(className, "Vector")) {
		fxID = jniEnv->GetFieldID(clazz, "fX", "F");
		fxID = jniEnv->GetFieldID(clazz, "fY", "F");
		fzID = jniEnv->GetFieldID(clazz, "fZ", "F");
		vectorInitMethodID = jniEnv->GetMethodID(clazz, "<init>", "()V");
		vectorInitMethodID2 = jniEnv->GetMethodID(clazz, "<init>", "(FFF)V");
		vectorClass = clazz;
	}

	if (strcmp("Matrix", className)) {
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

	if (strcmp("PatrolPoint", className)) {
		patrolPointPosFieldID = jniEnv->GetFieldID(clazz, "vPos", "LVector;");
		patrolPointRadiusFieldID = jniEnv->GetFieldID(clazz, "fRadius", "F");
		patrolPointFloatFieldID = jniEnv->GetFieldID(clazz, "fFloat", "F");
		patrolPointDataFieldID = jniEnv->GetFieldID(clazz, "sData", "Ljava/lang/String;");
		patrolPointInitMethodID = jniEnv->GetMethodID(clazz, "<init>", "()V");
		patrolPointClass = clazz;
	}
	
	if (strcmp("Collision", className)) {
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

	if (strcmp("Rect", className)) {
		
	}

	return;
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
	GetPrivateProfileString("Game", "Class", "", this->buffer, sizeof(this->buffer), buffer);
}


/* 1009E9F0-1009EA67 00077	*/
void CJVMData::FUN1009e9f0() {
}

/* 1009EC60-1009EC74 00014	*/
uchar CJVMData::FUN1009ec60(uint param_1) {
	return 0;
}

