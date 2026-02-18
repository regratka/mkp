#ifndef C_MAG_KERNEL
#define C_MAG_KERNEL

#include <globals.h>
#include <d3dx8math.h>

#include "cMagLog.h"
#include "cMagMeshObject.h"

class cMagKernel : public cMagLog {

public:
    virtual bool GetStatusRemoveObject();
    virtual void RemoveObject(bool removeObject);

    virtual ~cMagKernel();
    cMagKernel();
    
    virtual void OnFrame();
    virtual void OnInputKey(unsigned char* key);
    virtual void OnInputMouse(float param_1, float param_2, bool param_3, bool param_4);
    virtual D3DXVECTOR3 GetPosition();
    virtual D3DXMATRIX GetWorldMat();
    virtual D3DXMATRIX GetTransformMatrix();
    virtual char* GetObjectName();
    virtual void SetObjectName(char* objectName);
    virtual void SetObjectID(int objectID);
    virtual int GetObjectID();
    virtual char* GetClassNameA();
    void InitOnInputHandlerParam(unsigned char* onInputHandlerParam);
    void InitOnInputMouseHandlerParam(float param_mouse_1, float param_mouse_2,bool param_enabled_mouse_handler_1,bool param_enabled_mouse_handler_2);
    virtual void OnActivate();
    virtual void OnActivateLevel();
    virtual void OnChangeMovement(int param_movement);
    virtual void OnDestinationPos(D3DXVECTOR3 param_pos);
    virtual void OnDestinationDir();
    virtual void OnInsideFrustumCull();
    virtual void OnOutsideFrustumCull();
    virtual void OnParticleSequenceEnd();
    D3DXMATRIX GetRotMat();
    void SetRotMat(D3DXMATRIX rotMat);
    virtual bool OnProcessStateMachine(void*, int, float);

    virtual void SetObjectParam(int objectParam);
    virtual void SetClassName(char* className);
    virtual void OnSlideObject(cMagMeshObject* meshObject);
    virtual void OnSlide(cMagMeshObject* meshObject);
    void CallOnAction();
    virtual void OnAction();
    virtual void OnAction(char* param_1);
    void CallOnActivateLevel();

private:
    cMagKernel* delegator1;
    cMagKernel* delegator2;
    int objectParam;
    D3DXMATRIX rotMat;
    char objectName[100];
    int objectID;
    char className[255];
    bool statusRemoveObject;
    cMagLog log;
    unsigned char* onInputHandlerParam;
    float mouseParam1;
    float mouseParam2;
    bool enabledOnInputMouseHandler1;
    bool enabledOnInputMouseHandler2;
    bool enableOnFrameHandler;
    bool enableOnInputKeyHandler;
    bool enabledOnInputMouseHandler3;
    bool enabledOnCollisionObjectHandler;
    bool enabledOnAttachChild;
    bool enabledOnPhysicsUpdate;

public:
    static int m_iMaxID;
};

STATIC_ASSERT(sizeof(cMagKernel) == 0x1dc);

int cMagKernel::m_iMaxID = 0;

#endif