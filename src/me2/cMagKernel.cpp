#include <cstring>

#include "cMagKernel.h"

cMagKernel::cMagKernel(): cMagLog(), log() {
    delegator1 = NULL;
    delegator2 = NULL;
    SetObjectName("cMagKernel");
    strcpy(this->className, "Class Name: ???");
    this->objectID = cMagKernel::m_iMaxID;
    cMagKernel::m_iMaxID++;
    this->enabledOnCollisionObjectHandler = true;
    this->enabledOnAttachChild = true;
    this->statusRemoveObject = false;
    this->enabledOnPhysicsUpdate = false;
    this->enableOnFrameHandler = false;
    this->enableOnInputKeyHandler = false;
    this->enabledOnInputMouseHandler3 = false;
    this->objectParam = 0;
}

void cMagKernel::SetObjectName(char* objectName) {
    strcpy(this->objectName, objectName);
}

cMagKernel::~cMagKernel() {}

D3DXVECTOR3 cMagKernel::GetPosition() {
    D3DXVECTOR3 position;
    position.x = 0.0f;
    position.y = 0.0f;
    position.z = 0.0f;
    return position;
}

void cMagKernel::SetRotMat(D3DXMATRIX rotMat) {
    this->rotMat = rotMat;
}

void cMagKernel::SetObjectParam(int objectParam) {
    this->objectParam = objectParam;
}

void cMagKernel::SetObjectID(int objectID) {
    this->objectID = objectID;
}

void cMagKernel::SetClassName(char* className) {
    strcpy(this->className, className);
}

void cMagKernel::RemoveObject(bool removeObject) {
    this->statusRemoveObject = removeObject;
}

void cMagKernel::OnSlideObject(cMagMeshObject* meshObject) {
    if (this->delegator2 != NULL) {
        this->delegator2->OnSlideObject(meshObject);
    }
}

void cMagKernel::OnSlide(cMagMeshObject* meshObject) {
    if (this->delegator2 != NULL) {
        this->delegator2->OnSlide(meshObject);
    }
}

void cMagKernel::CallOnAction() {
    if (this->delegator1 != NULL) {
        this->delegator1->OnAction();
    } else {
        OnAction();
    }
}

void cMagKernel::OnAction() {
    if (this->delegator2 != NULL) {
        this->delegator2->OnAction();
    }
}

void cMagKernel::OnAction(char* param_1) {
    if (this->delegator2 != NULL) {
        this->delegator2->OnAction(param_1);
    }
}

void cMagKernel::CallOnActivateLevel() {
    if (this->delegator1 != NULL) {
        this->delegator1->OnActivateLevel();
    } else {
        OnActivateLevel();
    }
}

void cMagKernel::OnActivateLevel() {
    if (this->delegator2 != NULL) {
        this->delegator2->OnActivateLevel();
    }
}