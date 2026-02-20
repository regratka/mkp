#ifndef C_MAG_KERNEL
#define C_MAG_KERNEL

#include <globals.h>
#include <d3dx8math.h>
#include <fstream>

#include "cMagLog.h"

class cMagMeshObject {

};

struct MsgObject;
struct StateObject_Str;
struct _ED_CHUNK {

};


class cMagKernel : public cMagLog {
public:
	/* 100011e0 */ virtual bool GetStatusRemoveObject();
	/* 100011f0 */ virtual void RemoveObject(bool param_1);
	/* 10001200 */ cMagKernel(cMagKernel* param_1);
	/* 100111a0 */ cMagKernel();
	/* 10011250 */ virtual ~cMagKernel();
	/* 10011260 */ virtual void OnFrame();
	/* 10011300 */ virtual void OnInputKey(uchar* param_1);
	/* 100113e0 */ virtual void OnInputMouse(float param_1, float param_2, bool param_3, bool param_4);
	/* 100114c0 */ virtual D3DXVECTOR3 GetPosition();
	/* 10011500 */ virtual  D3DXMATRIX GetWorldMat();
	/* 10011520 */ virtual D3DXMATRIX GetTransformMatrix();
	/* 100115c0 */ virtual char* GetObjectName();
	/* 100115d0 */ virtual void SetObjectName(char* param_1);
	/* 10011600 */ virtual void SetObjectID(int param_1);
	/* 10011610 */ virtual int GetObjectID();
	/* 10011620 */ virtual void SetClassName(char* param_1);
	/* 10011650 */ virtual char* GetClassNameA();
	/* 10011660 */ void InitOnInputHandlerParam(uchar* param_1);
	/* 10011670 */ void InitOnInputMouseHandlerParam(float param_1, float param_2, bool param_3, bool param_4);
	/* 100116a0 */ virtual void OnActivate();
	/* 100116e0 */ virtual void OnActivateLevel();
	/* 10011760 */ virtual void OnChangeMovement(int param_1);
	/* 100117f0 */ virtual void OnDestinationPos(D3DXVECTOR3 param_1);
	/* 10011900 */ virtual void OnDestinationDir();
	/* 10011980 */ virtual void OnInsideFrustumCull();
	/* 100119f0 */ virtual void OnOutsideFrustumCull();
	/* 10011a60 */ virtual void OnParticleSequenceEnd();
	/* 10011ad0 */ D3DXMATRIX GetRotMat();
	/* 10011af0 */ void SetRotMat(D3DXMATRIX param_1);
	/* 10011b10 */ virtual bool OnProcessStateMachine(StateObject_Str* param_1, int param_2, MsgObject* param_3);
	/* 10011b20 */ virtual void OnAnimEnd(char* param_1);
	/* 10011bf0 */ virtual void OnMouseArrive(int param_1);
	/* 10011c80 */ virtual void OnMouseLeave(int param_1);
	/* 10011d10 */ virtual void OnMouseEnter(int param_1);
	/* 10011da0 */ virtual void OnCollisionObject(cMagMeshObject* param_1);
	/* 10011e40 */ virtual void OnAttach(cMagMeshObject* param_1);
	/* 10011ee0 */ virtual void OnDetach(cMagMeshObject* param_1);
	/* 10011f80 */ virtual void OnSlideObject(cMagMeshObject* param_1);
	/* 10011fa0 */ virtual void OnBonePositionUpdate(char* param_1, D3DXVECTOR3 param_2, D3DXMATRIX param_3, D3DXMATRIX param_4);
	/* 10012010 */ virtual void OnPathVerge();
	/* 10012090 */ virtual void EnableCallHandler(char* param_1);
	/* 10012140 */ virtual void DisableCallHandler(char* param_1);
	/* 100121f0 */ bool GetStatusOnAttachChild();
	/* 10012200 */ bool GetStatusOnFrame();
	/* 10012210 */ bool GetStatusOnInputKey();
	/* 10012220 */ bool GetStatusOnInputMouse();
	/* 10012230 */ bool GetStatusOnCollisionObject();
	/* 10012240 */ virtual void DisableAllHandlers();
	/* 10012260 */ virtual char* GetFileMeshName();
	/* 10012270 */ virtual void OnDestTime(float param_1);
	/* 10012310 */ virtual void OnSlide(cMagMeshObject* param_1);
	/* 100123b0 */ virtual void OnCrash();
	/* 10012430 */ bool GetStatusOnPhysicsUpdate();
	/* 10012440 */ virtual void SetObjectParam(int param_1);
	/* 10012450 */ virtual int GetObjectParam();
	/* 10012460 */ virtual void Load(std::ifstream&, _ED_CHUNK); 
	/* 10012470 */ virtual void OnAction();
	/* 10012480 */ virtual void OnAction(char* param_1);
	/* 100124a0 */ void CallOnFrame();
	/* 100124c0 */ void CallOnInputKey(uchar* param_1);
	/* 100124f0 */ void CallOnInputMouse(float param_1, float param_2, bool param_3, bool param_4);
	/* 10012540 */ void CallOnAction();
	/* 10012560 */ void CallOnCrash();
	/* 10012580 */ void CallOnSlide(cMagMeshObject* param_1);
	/* 100125b0 */ void CallOnDestTime(float param_1);
	/* 100125e0 */ void CallOnPathVerge();
	/* 10012600 */ void CallOnBonePositionUpdate(char* param_1, D3DXVECTOR3, D3DXMATRIX, D3DXMATRIX);
	/* 100126d0 */ void CallOnSlideObject(cMagMeshObject* param_1);
	/* 10012700 */ void CallOnDetach(cMagMeshObject* param_1);
	/* 10012730 */ void CallOnAttach(cMagMeshObject* param_1);
	/* 10012760 */ void CallOnCollisionObject(cMagMeshObject* param_1);
	/* 10012790 */ void CallOnMouseEnter(int param_1);
	/* 100127c0 */ void CallOnMouseLeave(int param_1);
	/* 100127f0 */ void CallOnMouseArrive(int param_1);
	/* 10012820 */ void CallOnAnimEnd(char* param_1);
	/* 10012850 */ void CallOnDestinationDir();
	/* 10012870 */ void CallOnDestinationPos(D3DXVECTOR3);
	/* 100128c0 */ void CallOnChangeMovement(int param_1);
	/* 100128f0 */ void CallOnActivateLevel();
	/* 10012920 */ void CallOnNavigationPathEnd();

private:
	/* 0x00c */	cMagKernel* delegator1;
    /* 0x010 */	cMagKernel* delegator2;
    /* 0x014 */	int objectParam;
    /* 0x018 */	D3DXMATRIX rotMat;
    /* 0x058 */	char objectName[100];
    /* 0x0bc */	int objectID;
    /* 0x0c0 */	char className[255];
    /* 0x1bf */	bool statusRemoveObject;
    /* 0x1c0 */	cMagLog log;
    /* 0x1c8 */	unsigned char* onInputHandlerParam;
    /* 0x1cc */	float mouseParam1;
    /* 0x1d0 */	float mouseParam2;
    /* 0x1d4 */	bool enabledOnInputMouseHandler1;
    /* 0x1d5 */	bool enabledOnInputMouseHandler2;
    /* 0x1d6 */	bool enableOnFrameHandler;
    /* 0x1d7 */	bool enableOnInputKeyHandler;
    /* 0x1d8 */	bool enabledOnInputMouseHandler3;
    /* 0x1d9 */	bool enabledOnCollisionObjectHandler;
    /* 0x1da */	bool enabledOnAttachChild;
    /* 0x1db */	bool enabledOnPhysicsUpdate;

public:
    static int m_iMaxID;
};

STATIC_ASSERT(sizeof(cMagKernel) == 0x1dc);

#endif