#ifndef C_MAG_KERNEL
#define C_MAG_KERNEL

#include <globals.h>
#include <d3dx8math.h>
#include <fstream>

#include "cMagLog.h"

class cMagMeshObject;

struct MsgObject;
struct StateObject_Str;
struct _ED_CHUNK {
	uint _1;
	uint _2;
	uint _3;
};


class __declspec(dllexport) cMagKernel : public cMagLog {
public:

	/* 100111a0 */ cMagKernel();
 
	/* 10012310 */ virtual void OnSlide(cMagMeshObject* param_1); /* vtbl 0x00 */
	/* 10012440 */ virtual void SetObjectParam(int param_1); /* vtbl 0x04 */
	/* 10012450 */ virtual int GetObjectParam(); /* vtbl 0x08 */
	/* 10012010 */ virtual void OnPathVerge(); /* vtbl 0x0c */
	/* 10011f80 */ virtual void OnSlideObject(cMagMeshObject* param_1); /* vtbl 0x10 */
	/* 10011ee0 */ virtual void OnDetach(cMagMeshObject* param_1); /* vtbl 0x14 */
	/* 10011e40 */ virtual void OnAttach(cMagMeshObject* param_1); /* vtbl 0x18 */
	/* 10011da0 */ virtual void OnCollisionObject(cMagMeshObject* param_1); /* vtbl 01c */
	/* 10011900 */ virtual void OnDestinationDir(); /* vtbl 0x20 */
	/* 100117f0 */ virtual void OnDestinationPos(D3DXVECTOR3 param_1); /* vtbl 024 */
	/* 10011760 */ virtual void OnChangeMovement(int param_1); /* vtbl 0x28 */

	virtual void OnLoadChunk(_ED_CHUNK, std::ifstream&); /* vtbl 0x2c */

	/* 100116a0 */ virtual void OnActivate(); /* vtbl 0x30 */
	/* 100116e0 */ virtual void OnActivateLevel(); /* vtbl 0x34 */
	
	virtual void vtbl_0x38(); /* vtbl 0x38 */
	virtual void OnPreRender(); /* vtbl 0x3c */

	/* 10011980 */ virtual void OnInsideFrustumCull(); /* vtbl 0x40 */
	/* 100119f0 */ virtual void OnOutsideFrustumCull(); /* vtbl 0x44 */
	/* 10011a60 */ virtual void OnParticleSequenceEnd(); /* vtbl 0x48 */
	
	virtual void vtbl_0x4c(); /* vtbl 0x4c*/
	virtual void vtbl_0x50(); /* vtbl 0x50*/

	/* 10011b10 */ virtual bool OnProcessStateMachine(StateObject_Str* param_1, int param_2, MsgObject* param_3); /* vtbl 0x54 */
	/* 10011b20 */ virtual void OnAnimEnd(char* param_1); /* vtbl 0x58 */

	virtual void OnAnimFrameMeter(); /* vtbl 0x5c*/
	virtual void vtbl_0x60(); /* vtbl 0x60*/
	virtual void vtbl_0x64(); /* vtbl 0x64*/
	virtual void vtbl_0x68(); /* vtbl 0x68*/
	virtual void vtbl_0x6c(); /* vtbl 0x6c*/
	virtual void vtbl_0x70(); /* vtbl 0x70*/
	virtual void vtbl_0x74(); /* vtbl 0x74*/
	virtual void vtbl_0x78(); /* vtbl 0x78*/
	virtual ulong GetShadowType(); /* vtbl 0x7c*/

	/* 10011250 */ virtual ~cMagKernel(); /* vtbl 0x80 */
	/* 10011260 */ virtual void OnFrame(); /* vtbl 0x84 */

	virtual void vtb_0x88(); /* vtbl 0x88 */
	/* 10011300 */ virtual void OnInputKey(uchar* param_1); /* vtbl 0x90 */
	virtual void OnInputKey(int, bool);  /* vtbl 0x8c */
	virtual void OnInputChar(char); /* vtbl 0x94 */

	/* 100113e0 */ virtual void OnInputMouse(float param_1, float param_2, bool param_3, bool param_4); /* vtbl 0x98 */
	/* 100114c0 */ virtual D3DXVECTOR3 GetPosition(); /* vtbl 0x9c */
	/* 10011500 */ virtual D3DXMATRIX GetWorldMat(); /* vtbl 0xa0 */
	/* 10011520 */ virtual D3DXMATRIX GetTransformMatrix(); /* vtbl 0xa4 */
	/* 100115c0 */ virtual char* GetObjectName(); /* vtbl 0xa8 */
	/* 100115d0 */ virtual void SetObjectName(char* param_1); /* vtbl 0xac */
	/* 10011600 */ virtual void SetObjectID(int param_1); /* vtbl 0xb0 */
	/* 10011610 */ virtual int GetObjectID(); /* vtbl 0xb4 */
	/* 10011620 */ virtual void SetClassName(char* param_1); /* vtbl 0xb8 */
	/* 10011650 */ virtual char* GetClassNameA(); /* vtbl 0xbc */
	/* 10012260 */ virtual char* GetFileMeshName(); /* vtbl 0xc0 */

	/* 100011e0-100011e7 00007	vtbl 0xc4 */
	virtual bool GetStatusRemoveObject() {
		return this->statusRemoveObject;
	}
	
	/* 100011f0 vtbl 0xc8 */ 
	virtual void RemoveObject(bool p_removeObject) {
		this->statusRemoveObject = p_removeObject;
	}

	virtual void vtb_0xcc(); /* vtbl 0xcc */

	/* 10011bf0 */ virtual void OnMouseArrive(int param_1); /* vtbl 0xd0 */

	virtual void vtb_0xd4(); /* vtbl 0xd4 */

	/* 10011c80 */ virtual void OnMouseLeave(int param_1); /* vtbl 0xd8 */
	/* 10011d10 */ virtual void OnMouseEnter(int param_1); /* vtbl 0xdc */

	virtual void vtb_0xe0(); /* vtbl 0xe0 */
	virtual void vtb_0xe4(); /* vtbl 0xe4 */
	virtual void vtb_0xe8(); /* vtbl 0xe8 */

	virtual void OnRender(); /* vtbl 0xec */
	
	virtual void vtb_0xf0(); /* vtbl 0xf0 */

	virtual void OnUpdate_(); /* vtbl 0xf4 */
	/* 10011fa0 */ virtual void OnBonePositionUpdate(char* param_1, D3DXVECTOR3 param_2, D3DXMATRIX param_3, D3DXMATRIX param_4); /* vtbl 0xf8 */
	/* 10012090 */ virtual void EnableCallHandler(char* param_1); /* vtbl 0xfc */
	/* 10012140 */ virtual void DisableCallHandler(char* param_1); /* vtbl 0x100 */

	/* 10012240 */ virtual void DisableAllHandlers(); /* vtbl 0x104 */
	/* 10012470 */ virtual void OnAction(); /* vtbl 0108 */
	/* 10012480 */ virtual void OnAction(char* param_1); /* vtbl 0x10c */

	virtual void vtb_0x110(); /* vtbl 0x110 */

	/* 10012460 */ virtual void Load(std::ifstream&, _ED_CHUNK);  /* vtbl 0x114 */

	virtual void vtb_0x118(); /* vtbl 0x118 */
	virtual void vtb_0x11c(); /* vtbl 0x11c */

	/* 10012270 */ virtual void OnDestTime(float param_1); /* vtbl 0x120 */

	virtual void vtb_0x124(); /* vtbl 0x124 */
	virtual void vtb_0x128(); /* vtbl 0x128 */

	/* 100123b0 */ virtual void OnCrash(); /* vtbl 0x12c */

	virtual void vtb_0x130(); /* vtbl 0x130 */

	virtual void OnNavigationPathEnd(); /* vtbl 0x134 */
	virtual void OnUpdateMenuSettings(); /* vtbl 0x138 */
	virtual void GetBoundingBox(D3DXVECTOR3&, D3DXVECTOR3&, int);  /* vtbl 0x13c */

	/* 10011660 */ void InitOnInputHandlerParam(uchar* param_1);
	/* 10011670 */ void InitOnInputMouseHandlerParam(float param_1, float param_2, bool param_3, bool param_4);
	/* 10011ad0 */ D3DXMATRIX GetRotMat();
	/* 10011af0 */ void SetRotMat(D3DXMATRIX param_1);
	/* 100121f0 */ bool GetStatusOnAttachChild();
	/* 10012200 */ bool GetStatusOnFrame();
	/* 10012210 */ bool GetStatusOnInputKey();
	/* 10012220 */ bool GetStatusOnInputMouse();
	/* 10012230 */ bool GetStatusOnCollisionObject();
	/* 10012430 */ bool GetStatusOnPhysicsUpdate();
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
protected:
    /* 0x1c0 */	cMagLog magLog;
private:
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