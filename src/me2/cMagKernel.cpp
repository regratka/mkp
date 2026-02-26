#include "cMagKernel.h"

/* 100111a0-10011244 000a4	*/
cMagKernel::cMagKernel() : cMagLog(), log() {
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

/* 10011250-10011257 00007	*/
cMagKernel::~cMagKernel() {
}

/* 10011260-100112dd 0007d	*/
void cMagKernel::OnFrame() {
    if (this->delegator2 != NULL) {
        this->delegator2->OnFrame();
    }
}

/* 10011300-100113e0 000e0	*/
void cMagKernel::OnInputKey(uchar* p_key) {
    if (this->delegator2 != NULL) {
        this->delegator2->OnInputKey(p_key);
    }
}

/* 100113e0-100114b5 000d5	*/
void cMagKernel::OnInputMouse(float param_1, float param_2, bool param_3, bool param_4) {
    if (this->delegator2 != NULL) {
        this->delegator2->OnInputMouse(param_1, param_2, param_3, param_4);
    }
}

/* 100114c0-100114fb 0003b	*/
D3DXVECTOR3 cMagKernel::GetPosition() {
    D3DXVECTOR3 position;
    position.x = 0.0f;
    position.y = 0.0f;
    position.z = 0.0f;
    return position;
}

/* 10011500-1001151e 0001e	*/
D3DXMATRIX cMagKernel::GetWorldMat() {
    D3DXMATRIX worldMat;
    return worldMat;
}

/* 10011520-100115be 0009e	*/
D3DXMATRIX cMagKernel::GetTransformMatrix() {
    D3DXMATRIX transformMat;
    D3DXMatrixIdentity(&transformMat);
    return transformMat;
}

/* 100115c0-100115c4 00004	*/
char* cMagKernel::GetObjectName() {
    return this->objectName;
}

/* 100115d0-100115fb 0002b	*/
void cMagKernel::SetObjectName(char* p_objectName) {
    strcpy(this->objectName, p_objectName);
}

/* 10011600-1001160d 0000d	*/
void cMagKernel::SetObjectID(int p_objectID) {
    this->objectID = p_objectID;
}

/* 10011610-10011617 00007	*/
int cMagKernel::GetObjectID() {
    return this->objectID;
}

/* 10011620-1001164e 0002e	*/
void cMagKernel::SetClassName(char* p_className) {
    strcpy(this->className, p_className);
}

/* 10011650-10011657 00007	*/
char* cMagKernel::GetClassNameA() {
    return this->className;
}

/* 10011660-1001166d 0000d	*/
void cMagKernel::InitOnInputHandlerParam(uchar* param_1) {
    this->onInputHandlerParam = param_1;
}

/* 10011670-1001169b 0002b	*/
void cMagKernel::InitOnInputMouseHandlerParam(float param_1, float param_2, bool param_3, bool param_4) {
    this->mouseParam1 = param_1;
    this->mouseParam2 = param_2;
    this->enabledOnInputMouseHandler1 = param_3;
    this->enabledOnInputMouseHandler2 = param_4;
}

/* 100116a0-100116e0 00040	*/
void cMagKernel::OnActivate() {
}

/* 100116e0-10011756 00076	*/
void cMagKernel::OnActivateLevel() {
    if (this->delegator2 != NULL) {
        this->delegator2->OnActivateLevel();
    }
}

/* 10011760-100117e1 00081	*/
void cMagKernel::OnChangeMovement(int param_1) {
    if (this->delegator2 != NULL) {
        this->delegator2->OnChangeMovement(param_1);
    }
}

/* 100117f0-100118ff 0010f	*/
void cMagKernel::OnDestinationPos(D3DXVECTOR3 param_1) {
    if (this->delegator2 != NULL) {
        this->delegator2->OnDestinationPos(param_1);
    }
}

/* 10011900-10011976 00076	*/
void cMagKernel::OnDestinationDir() {
    if (this->delegator2 != NULL) {
        this->delegator2->OnDestinationDir();
    }
}

/* 10011980-100119e5 00065	*/
void cMagKernel::OnInsideFrustumCull() {
}

/* 100119f0-10011a55 00065	*/
void cMagKernel::OnOutsideFrustumCull() {
}

/* 10011a60-10011ac5 00065	*/
void cMagKernel::OnParticleSequenceEnd() {
}

/* 10011ad0-10011ae7 00017	*/
D3DXMATRIX cMagKernel::GetRotMat() {
	return this->rotMat;
}

/* 10011af0-10011b05 00015	*/
void cMagKernel::SetRotMat(D3DXMATRIX param_1) {
	this->rotMat = param_1;
}

/* 10011b10-10011b15 00005	*/
bool cMagKernel::OnProcessStateMachine(StateObject_Str* param_1, int param_2, MsgObject* param_3) {
	return true;
}

/* 10011b20-10011bea 000ca	*/
void cMagKernel::OnAnimEnd(char* param_1) {
}

/* 10011bf0-10011c74 00084	*/
void cMagKernel::OnMouseArrive(int param_1) {
}

/* 10011c80-10011d04 00084	*/
void cMagKernel::OnMouseLeave(int param_1) {
}

/* 10011d10-10011d94 00084	*/
void cMagKernel::OnMouseEnter(int param_1) {
}

/* 10011da0-10011e40 000a0	*/
void cMagKernel::OnCollisionObject(cMagMeshObject* param_1) {
}

/* 10011e40-10011ee0 000a0	*/
void cMagKernel::OnAttach(cMagMeshObject* param_1) {
}

/* 10011ee0-10011f80 000a0	*/
void cMagKernel::OnDetach(cMagMeshObject* param_1) {
}

/* 10011f80-10011f94 00014	*/
void cMagKernel::OnSlideObject(cMagMeshObject* param_1) {
    if (this->delegator2 != NULL) {
        this->delegator2->OnSlideObject(param_1);
    }
}

/* 10011fa0-10012008 00068	*/
void cMagKernel::OnBonePositionUpdate(char* param_1, D3DXVECTOR3 param_2, D3DXMATRIX param_3, D3DXMATRIX param_4) {
}

/* 10012010-10012086 00076	*/
void cMagKernel::OnPathVerge() {
}

/* 10012090-1001213f 000af	*/
void cMagKernel::EnableCallHandler(char* param_1) {
}

/* 10012140-100121e1 000a1	*/
void cMagKernel::DisableCallHandler(char* param_1) {
}

/* 100121f0-100121f7 00007	*/
bool cMagKernel::GetStatusOnAttachChild() {
	return enabledOnAttachChild;
}

/* 10012200-10012207 00007	*/
bool cMagKernel::GetStatusOnFrame() {
	return enableOnFrameHandler;
}

/* 10012210-10012217 00007	*/
bool cMagKernel::GetStatusOnInputKey() {
	return enableOnInputKeyHandler;
}

/* 10012220-10012227 00007	*/
bool cMagKernel::GetStatusOnInputMouse() {
	return enabledOnInputMouseHandler3;
}

/* 10012230-10012237 00007	*/
bool cMagKernel::GetStatusOnCollisionObject() {
	return enabledOnCollisionObjectHandler;
}

/* 10012240-1001225b 0001b	*/
void cMagKernel::DisableAllHandlers() {
    enableOnFrameHandler = false;
    enableOnInputKeyHandler = false;
    enabledOnInputMouseHandler3 = false;
    enabledOnCollisionObjectHandler = false;
}

/* 10012260-10012266 00006	*/
char* cMagKernel::GetFileMeshName() {
	return "No name";
}

/* 10012270-10012303 00093	*/
void cMagKernel::OnDestTime(float param_1) {
}

/* 10012310-100123af 0009f	*/
void cMagKernel::OnSlide(cMagMeshObject* param_1) {
    if (this->delegator2 != NULL) {
        this->delegator2->OnSlide(param_1);
    }
}

/* 100123b0-10012429 00079	*/
void cMagKernel::OnCrash() {
}

/* 10012430-10012437 00007	*/
bool cMagKernel::GetStatusOnPhysicsUpdate() {
	return enabledOnPhysicsUpdate;
}

/* 10012440-1001244a 0000a	*/
void cMagKernel::SetObjectParam(int param_1) {
	this->objectParam = param_1;
}

/* 10012450-10012454 00004	*/
int cMagKernel::GetObjectParam() {
	return objectParam;
}

/* 10012460-10012463 00003	*/
void cMagKernel::Load(std::ifstream& stream, _ED_CHUNK chunk) {

}

/* 10012470-10012480 00010	*/
void cMagKernel::OnAction() {
    if (this->delegator2 != NULL) {
        this->delegator2->OnAction();
    }
}

/* 10012480-10012497 00017	*/
void cMagKernel::OnAction(char* param_1) {
    if (this->delegator2 != NULL) {
        this->delegator2->OnAction(param_1);
    }
}

/* 100124a0-100124b9 00019	*/
void cMagKernel::CallOnFrame() {
}

/* 100124c0-100124e9 00029	*/
void cMagKernel::CallOnInputKey(uchar* param_1) {
}

/* 100124f0-10012537 00047	*/
void cMagKernel::CallOnInputMouse(float param_1, float param_2, bool param_3, bool param_4) {
}

/* 10012540-10012559 00019	*/
void cMagKernel::CallOnAction() {
    if (this->delegator1 != NULL) {
        this->delegator1->OnAction();
    } else {
        OnAction();
    }
}

/* 10012560-10012579 00019	*/
void cMagKernel::CallOnCrash() {
}

/* 10012580-100125a1 00021	*/
void cMagKernel::CallOnSlide(cMagMeshObject* param_1) {
}

/* 100125b0-100125d9 00029	*/
void cMagKernel::CallOnDestTime(float param_1) {
}

/* 100125e0-100125f3 00013	*/
void cMagKernel::CallOnPathVerge() {
}

/* 10012600-100126c9 000c9	*/
void cMagKernel::CallOnBonePositionUpdate(char* param_1, D3DXVECTOR3 param_2, D3DXMATRIX param_3, D3DXMATRIX param_4) {
}

/* 100126d0-100126f3 00023	*/
void cMagKernel::CallOnSlideObject(cMagMeshObject* param_1) {
}

/* 10012700-10012723 00023	*/
void cMagKernel::CallOnDetach(cMagMeshObject* param_1) {
}

/* 10012730-10012753 00023	*/
void cMagKernel::CallOnAttach(cMagMeshObject* param_1) {
}

/* 10012760-10012783 00023	*/
void cMagKernel::CallOnCollisionObject(cMagMeshObject* param_1) {
}

/* 10012790-100127b9 00029	*/
void cMagKernel::CallOnMouseEnter(int param_1) {
}

/* 100127c0-100127e9 00029	*/
void cMagKernel::CallOnMouseLeave(int param_1) {
}

/* 100127f0-10012819 00029	*/
void cMagKernel::CallOnMouseArrive(int param_1) {
}

/* 10012820-10012843 00023	*/
void cMagKernel::CallOnAnimEnd(char* param_1) {
}

/* 10012850-10012863 00013	*/
void cMagKernel::CallOnDestinationDir() {
}

/* 10012870-100128be 0004e	*/
void cMagKernel::CallOnDestinationPos(D3DXVECTOR3 param_1) {
}

/* 100128c0-100128e3 00023	*/
void cMagKernel::CallOnChangeMovement(int param_1) {
}

/* 100128f0-10012903 00013	*/
void cMagKernel::CallOnActivateLevel() {
    if (this->delegator1 != NULL) {
        this->delegator1->OnActivateLevel();
    } else {
        OnActivateLevel();
    }
}

/* 10012920-10012939 00019	*/
void cMagKernel::CallOnNavigationPathEnd() {
    if (delegator1 != NULL) {
        delegator1->OnNavigationPathEnd();
        return;
    }
    OnNavigationPathEnd();
}

