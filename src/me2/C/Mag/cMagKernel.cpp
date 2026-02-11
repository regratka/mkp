#include "cMagKernel.h"

#include <cstring>

bool cMagKernel::GetStatusRemoveObject() {
    return this->statusRemoveObject;
}

void cMagKernel::RemoveObject(bool removeObject) {
    this->statusRemoveObject = removeObject;
}

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

cMagKernel::~cMagKernel() {}

void cMagKernel::OnFrame() {
    if (this->delegator2 != NULL) {
        this->delegator2->OnFrame();
    }
}

void cMagKernel::OnInputKey(unsigned char* key) {
    if (this->delegator2 != NULL) {
        this->delegator2->OnInputKey(key);
    }
}

void cMagKernel::OnInputMouse(float param_1, float param_2, bool param_3, bool param_4) {
    if (this->delegator2 != NULL) {
        this->delegator2->OnInputMouse(param_1, param_2, param_3, param_4);
    }
}

D3DXVECTOR3 cMagKernel::GetPosition() {
    D3DXVECTOR3 position;
    position.x = 0.0f;
    position.y = 0.0f;
    position.z = 0.0f;
    return position;
}

D3DXMATRIX cMagKernel::GetWorldMat() {
    D3DXMATRIX worldMat;
    return worldMat;
}

D3DXMATRIX cMagKernel::GetTransformMatrix() {
    D3DXMATRIX transformMat;
    D3DXMatrixIdentity(&transformMat);
    return transformMat;
}

char* cMagKernel::GetObjectName() {
    return this->objectName;
}

void cMagKernel::SetObjectName(char* objectName) {
    strcpy(this->objectName, objectName);
}

void cMagKernel::SetObjectID(int objectID) {
    this->objectID = objectID;
}

int cMagKernel::GetObjectID() {
    return this->objectID;
}

char* cMagKernel::GetClassNameA() {
    return this->className;
}

void cMagKernel::InitOnInputHandlerParam(unsigned char* onInputHandlerParam) {
    this->onInputHandlerParam = onInputHandlerParam;
}

void cMagKernel::InitOnInputMouseHandlerParam(float param_mouse_1, float param_mouse_2, 
        bool param_enabled_mouse_handler_1, bool param_enabled_mouse_handler_2) {
    this->mouseParam1 = param_mouse_1;
    this->mouseParam2 = param_mouse_2;
    this->enabledOnInputMouseHandler1 = param_enabled_mouse_handler_1;
    this->enabledOnInputMouseHandler2 = param_enabled_mouse_handler_2;
}

void cMagKernel::OnActivate() {

}

void cMagKernel::OnActivateLevel() {
    if (this->delegator2 != NULL) {
        this->delegator2->OnActivateLevel();
    }
}

void cMagKernel::OnChangeMovement(int param_movement) {
    if (this->delegator2 != NULL) {
        this->delegator2->OnChangeMovement(param_movement);
    }
}

void cMagKernel::OnDestinationPos(D3DXVECTOR3 param_pos) {
    if (this->delegator2 != NULL) {
        this->delegator2->OnDestinationPos(param_pos);
    }
}

void cMagKernel::OnDestinationDir() {
    if (this->delegator2 != NULL) {
        this->delegator2->OnDestinationDir();
    }
}

void cMagKernel::OnInsideFrustumCull() {
}

void cMagKernel::OnOutsideFrustumCull() {
}

void cMagKernel::OnParticleSequenceEnd() {
}

D3DXMATRIX cMagKernel::GetRotMat() {
    return this->rotMat;
}

void cMagKernel::SetRotMat(D3DXMATRIX rotMat) {
    this->rotMat = rotMat;
}

bool cMagKernel::OnProcessStateMachine(void*, int, float) {
    return true;
}

void cMagKernel::SetObjectParam(int objectParam) {
    this->objectParam = objectParam;
}


void cMagKernel::SetClassName(char* className) {
    strcpy(this->className, className);
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

