#ifndef C_MAG_KERNEL
#define C_MAG_KERNEL

#include <globals.h>

class cMagKernel {
public:
	/* 100011e0 */ bool GetStatusRemoveObject();
	/* 100011f0 */ void RemoveObject(bool param_1);
	/* 10001200 */ cMagKernel(cMagKernel* param_1);
	/* 10001460 */ cMagKernel* scalar_destructor(u8 param_1);
	/* 100111a0 */ cMagKernel();
	/* 10011250 */ ~cMagKernel();
	/* 10011260 */ void OnFrame();
	/* 10011300 */ void OnInputKey(uchar* param_1);
	/* 100113e0 */ void OnInputMouse(f32 param_1, f32 param_2, bool param_3, bool param_4);
	/* 100114c0 */ D3DXVECTOR3* GetPosition(D3DXVECTOR3* param_1);
	/* 10011500 */ D3DXMATRIX* GetWorldMat(D3DXMATRIX* param_1);
	/* 10011520 */ D3DXMATRIX* GetTransformMatrix(D3DXMATRIX* param_1);
	/* 100115c0 */ char* GetObjectName();
	/* 100115d0 */ void SetObjectName(char* param_1);
	/* 10011600 */ void SetObjectID(i32 param_1);
	/* 10011610 */ i32 GetObjectID();
	/* 10011620 */ void SetClassName(char* param_1);
	/* 10011650 */ char* GetClassNameA();
	/* 10011660 */ void InitOnInputHandlerParam(uchar* param_1);
	/* 10011670 */ void InitOnInputMouseHandlerParam(f32 param_1, f32 param_2, bool param_3, bool param_4);
	/* 100116a0 */ void OnActivate();
	/* 100116e0 */ void OnActivateLevel();
	/* 10011760 */ void OnChangeMovement(i32 param_1);
	/* 100117f0 */ void OnDestinationPos(D3DXVECTOR3 param_1);
	/* 10011900 */ void OnDestinationDir();
	/* 10011980 */ void OnInsideFrustumCull();
	/* 100119f0 */ void OnOutsideFrustumCull();
	/* 10011a60 */ void OnParticleSequenceEnd();
	/* 10011ad0 */ D3DXMATRIX* GetRotMat(D3DXMATRIX* param_1);
	/* 10011af0 */ void SetRotMat(D3DXMATRIX param_1);
	/* 10011b10 */ bool OnProcessStateMachine(StateObject_Str* param_1, i32 param_2, MsgObject* param_3);
	/* 10011b20 */ void OnAnimEnd(char* param_1);
	/* 10011bf0 */ void OnMouseArrive(i32 param_1);
	/* 10011c80 */ void OnMouseLeave(i32 param_1);
	/* 10011d10 */ void OnMouseEnter(i32 param_1);
	/* 10011da0 */ void OnCollisionObject(cMagMeshObject* param_1);
	/* 10011e40 */ void OnAttach(cMagMeshObject* param_1);
	/* 10011ee0 */ void OnDetach(cMagMeshObject* param_1);
	/* 10011f80 */ void OnSlideObject(cMagMeshObject* param_1);
	/* 10011fa0 */ void OnBonePositionUpdate(char* param_1, D3DXVECTOR3 param_2, D3DXMATRIX param_3, D3DXMATRIX param_4);
	/* 10012010 */ void OnPathVerge();
	/* 10012090 */ void EnableCallHandler(char* param_1);
	/* 10012140 */ void DisableCallHandler(char* param_1);
	/* 100121f0 */ bool GetStatusOnAttachChild();
	/* 10012200 */ bool GetStatusOnFrame();
	/* 10012210 */ bool GetStatusOnInputKey();
	/* 10012220 */ bool GetStatusOnInputMouse();
	/* 10012230 */ bool GetStatusOnCollisionObject();
	/* 10012240 */ void DisableAllHandlers();
	/* 10012260 */ char* GetFileMeshName();
	/* 10012270 */ void OnDestTime(f32 param_1);
	/* 10012310 */ void OnSlide(cMagMeshObject* param_1);
	/* 100123b0 */ void OnCrash();
	/* 10012430 */ bool GetStatusOnPhysicsUpdate();
	/* 10012440 */ void SetObjectParam(i32 param_1);
	/* 10012450 */ i32 GetObjectParam();
	/* 10012460 */ void Load();
	/* 10012470 */ void OnAction();
	/* 10012480 */ void OnAction(char* param_1);
	/* 100124a0 */ void CallOnFrame();
	/* 100124c0 */ void CallOnInputKey(uchar* param_1);
	/* 100124f0 */ void CallOnInputMouse(f32 param_1, f32 param_2, bool param_3, bool param_4);
	/* 10012540 */ void CallOnAction();
	/* 10012560 */ void CallOnCrash();
	/* 10012580 */ void CallOnSlide(cMagMeshObject* param_1);
	/* 100125b0 */ void CallOnDestTime(f32 param_1);
	/* 100125e0 */ void CallOnPathVerge();
	/* 10012600 */ void CallOnBonePositionUpdate(u32 param_1, u32 param_2, u32 param_3, u32 param_4, u8 param_5, u8 param_6, u8 param_7, u8 param_8, u8 param_9, u8 param_10);
	/* 100126d0 */ void CallOnSlideObject(cMagMeshObject* param_1);
	/* 10012700 */ void CallOnDetach(cMagMeshObject* param_1);
	/* 10012730 */ void CallOnAttach(cMagMeshObject* param_1);
	/* 10012760 */ void CallOnCollisionObject(cMagMeshObject* param_1);
	/* 10012790 */ void CallOnMouseEnter(i32 param_1);
	/* 100127c0 */ void CallOnMouseLeave(i32 param_1);
	/* 100127f0 */ void CallOnMouseArrive(i32 param_1);
	/* 10012820 */ void CallOnAnimEnd(char* param_1);
	/* 10012850 */ void CallOnDestinationDir();
	/* 10012870 */ void CallOnDestinationPos(u32 param_1, u32 param_2, u32 param_3);
	/* 100128c0 */ void CallOnChangeMovement(i32 param_1);
	/* 100128f0 */ void CallOnActivateLevel();
	/* 10012920 */ void CallOnNavigationPathEnd();
};

#endif