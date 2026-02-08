#include <d3dx8math.h>

#include "cMagLog.h"
#include "cMagMeshObject.h"

class cMagKernel : public cMagLog {

public:
    cMagKernel();
    virtual void SetObjectName(char* objectName);
    virtual ~cMagKernel();
    virtual D3DXVECTOR3 GetPosition();

    void SetRotMat(D3DXMATRIX rotMat);
    virtual void SetObjectParam(int objectParam);
    virtual void SetObjectID(int objectID);
    virtual void SetClassName(char* className);
    virtual void RemoveObject(bool removeObject);
    virtual void OnSlideObject(cMagMeshObject* meshObject);
    virtual void OnSlide(cMagMeshObject* meshObject);
    void CallOnAction();
    virtual void OnAction();
    virtual void OnAction(char* param_1);
    void CallOnActivateLevel();
    virtual void OnActivateLevel();

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
    char unkn2[0x1d4-0x1c8];
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