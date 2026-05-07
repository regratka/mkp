#ifndef C_MAG_MESH_OBJECT
#define C_MAG_MESH_OBJECT

#include <globals.h>

#include "cMagUtility.h"
#include "IStudioMesh.h"
#include "cStaticMesh.h"

class __declspec(dllexport) cMagMeshObject : public cMagUtility {
public:
	/* 10007A10-10007A17 00007	*/ 
	char* GetFileMeshName() {
		return fileMeshName;
	}

	/* 10007A20-10007A27 00007	*/
	bool GetStatusRemoveObject() {
		return statusRemoveObject;
	}

	/* 10007A30-10007A3D 0000D	*/
	void cMagMeshObject::RemoveObject(bool param_1) {
		statusRemoveObject = param_1;
	}
	
	/* 10007A40-10007A5A 0001A	*/
	D3DXMATRIX cMagMeshObject::GetWorldMat() {
		return worldMat;
	}

	/* 10007A60-10007A6D 0000D	*/
	void cMagMeshObject::ShowWireframe(bool param_1) {
		showWireframe = param_1;
	}

	/* 10007A70-10007A7D 0000D	*/
	void cMagMeshObject::EnableFrustum(bool param_1) {
		enableFrustum = param_1;
	}

	/* 10007A80-10007A8D 0000D	*/
	void EnableRendering(bool param_1) {
		enableRendering = param_1;
	}
	
	/* 10007A90-10007A9D 0000D	*/
	void cMagMeshObject::EnablePortalRendering(bool param_1) {
		enablePortalRendering = param_1;
	}

	/* 10051E50 */ cMagMeshObject();
	/* 10052DF0 */ virtual ~cMagMeshObject();
	/* 100531E0 */ int Is3dmFile(char* param_1);
	/* 100534C0 */ void LoadMesh(char* param_1);
	/* 10053AA0 */ void SetPosition(D3DXVECTOR3 param_1);
	/* 10053B30 */ void SetScale(D3DXVECTOR3 param_1);
	/* 10053BC0 */ D3DXVECTOR3 GetPosition();
	/* 10053C10 */ D3DXVECTOR3 GetScale();
	/* 10053C40 */ D3DXMATRIX GetRotateMatrix();
	/* 10053C60 */ void SetRotateMatrix(D3DXMATRIX param_1);
	/* 10053C80 */ int GetFrameCount();
	/* 10053CA0 */ bool InitAnimSeq(char* param_1, int param_2, int param_3);
	/* 10053CD0 */ bool InitAnimSeq(char* param_1, char* param_2, int param_3, int param_4, int param_5, char* param_6);
	/* 10053CE0 */ void DeleteAnimSeq(char* param_1);
	/* 10053D00 */ void DeleteAllAnimSeq();
	/* 10053D10 */ void PlayAnimSeq(int param_1, int param_2);
	/* 10053D40 */ void SetAnimFreq(char* param_1, int param_2);
	/* 10053D60 */ bool IsPlaying(char* param_1);
	/* 10053D80 */ void StopAnim(char* param_1);
	/* 10053DA0 */ bool PlayAnim(char* param_1, int param_2);
	/* 10053DD0 */ void EnableAnimKeys(bool param_1);
	/* 10053DF0 */ void SetMeshType(int param_1);
	/* 10053E10 */ bool PlayAnim(char* param_1);
	/* 10053E30 */ bool InitAnimSeq(char* param_1);
	/* 10053E30 */ bool PlayAnim1(char* param_1);
	/* 10053E30 */ bool PlayAnimBack(char* param_1);
	/* 10053E40 */ int FrameRate();
	/* 10053EF0 */ void OnAnimEnd1(char* param_1);
	/* 10053F00 */ bool OnPlayAnim();
	/* 10053F30 */ void SetAnimMorphTime(float param_1);
	/* 10053F50 */ void SetStepMorph(float param_1);
	/* 10053F70 */ void EnableMorph(bool param_1);
	/* 10053F90 */ void AnimFrameMeter(char* param_1, int param_2);
	/* 10053FB0 */ void RenderMesh();
	/* 10054400 */ void DrawLine(float param_1, float param_2, float param_3, float param_4);
	/* 10054510 */ void InitBoundingBox();
	/* 10054560 */ void ShowBoundingBox(bool param_1);
	/* 10054570 */ void CorrectTranslationBoundingBox(D3DXVECTOR3 param_1);
	/* 10054590 */ void CorrectScaleBoundingBox(D3DXVECTOR3 param_1);
	/* 10054600 */ bool _TestDistance(float param_1);
	/* 10054C50 */ bool TestDistance(float param_1);
	/* 10054C60 */ void EnableTestSector(bool param_1);
	/* 10054C70 */ void OnUpdate_();
	/* 10054FE0 */ void OnRender();
	/* 10055620 */ void OnRenderShadow();
	/* 100556A0 */ void SetShadowType(int param_1);
	/* 100556E0 */ ulong GetShadowType();
	/* 100556F0 */ cMagGameObject* GetEngine();
	/* 10055700 */ void SetDirection(float param_1, float param_2, float param_3);
	/* 10055C70 */ void SetDirection(D3DXVECTOR3 param_1);
	/* 10056270 */ D3DXVECTOR3* GetDirection(D3DXVECTOR3* param_1);
	/* 100562A0 */ void GetDirection(float* param_1, float* param_2, float* param_3);
	/* 100562D0 */ void SetSpeed(float param_1, float param_2, float param_3);
	/* 10056340 */ uchar GetSpeed(float* param_1);
	/* 100563B0 */ void SetGravityAcceleration(float param_1);
	/* 100563C0 */ float GetGravityAcceleration();
	/* 100563E0 */ void SetSpeedValue(float param_1);
	/* 10056440 */ float GetSpeedValue();
	/* 10056450 */ void SetSpeedDirection(D3DXVECTOR3 param_1);
	/* 100564B0 */ uchar GetSpeedDirection(uint* param_1);
	/* 100564E0 */ void Jump(uint param_1, uint param_2, uint param_3);
	/* 10056500 */ uchar GetFallSpeed(uint* param_1);
	/* 10056530 */ void SetDestinationPos(uint param_1, uint param_2, uint param_3, uint param_4);
	/* 10056590 */ void ClearDestinationPos();
	/* 100565C0 */ void SetDestinationDir(uint param_1, uint param_2, uint param_3);
	/* 10056630 */ void ClearDestinationDir();
	/* 10056660 */ void SetMaxAngSpeed(float param_1);
	/* 10056670 */ float GetMaxAngSpeed();
	/* 10056680 */ void Rotate(float param_1, float param_2, float param_3);
	/* 100566D0 */ void SetAngSpeed(uint param_1, uint param_2, uint param_3);
	/* 100566F0 */ uchar GetAngSpeed(uint* param_1);
	/* 10056720 */ bool RestrictFrameRate(float param_1);
	/* 10056780 */ uchar GetSpace(uint* param_1);
	/* 100567A0 */ void Rotate(uchar param_1, uchar param_2, uchar param_3, uint param_4);
	/* 100569A0 */ void EnableTestDistance(bool param_1);
	/* 100569B0 */ uchar GetBoneWorldPosition(uint* param_1, char* param_2);
	/* 10056B70 */ bool GetBoneMatrix(char* param_1, uchar param_2);
	/* 10056D00 */ uchar GetBoneWorldRotateMatrix(uint* param_1);
	/* 10056DA0 */ void OnUpdateLink();
	/* 10056EC0 */ void LinkToBone(cMagMeshObject* param_1, char* param_2);
	/* 10057150 */ void UnLinkFromBone(cMagMeshObject* param_1);
	/* 100572A0 */ bool GetPhysics();
	/* 100572B0 */ bool GetCollision();
	/* 100572C0 */ bool GetCollisionScene();
	/* 100572D0 */ bool GetCollisionObjects();
	/* 100572E0 */ uchar GetCollisionType();
	/* 100572F0 */ void EnablePhysics(bool param_1);
	/* 10057380 */ void EnableCollision(bool param_1);
	/* 10057410 */ void EnableCollisionScene(bool param_1);
	/* 10057420 */ void EnableCollisionObjects(bool param_1);
	/* 10057430 */ void SetCollisionType(uchar param_1);
	/* 10057440 */ void SetSlideAngle(float param_1);
	/* 10057450 */ float GetSlideAngle();
	/* 10057470 */ D3DXMATRIX* GetTransformMatrix(D3DXMATRIX* param_1);
	/* 100574E0 */ void SetSlideObject(cMagMeshObject* param_1);
	/* 100574F0 */ cMagMeshObject* GetSlideObject();
	/* 10057500 */ void AttachTo(cMagMeshObject* param_1);
	/* 10057560 */ void Detach();
	/* 100575D0 */ cMagMeshObject* GetParent();
	/* 100575E0 */ uchar GetRotate(uint* param_1);
	/* 10057610 */ void LinkTo(cMagMeshObject* param_1);
	/* 10057650 */ void UnLink();
	/* 10057690 */ cMagMeshObject* GetLinkParent();
	/* 100576A0 */ void SetCollAction(uchar param_1);
	/* 100576B0 */ uchar GetCollAction();
	/* 100576C0 */ void SetPauseUpdatePhysics(bool param_1);
	/* 10057710 */ bool GetPauseUpdatePhysics();
	/* 10057720 */ uint* CalculateSpeed(uint* param_1);
	/* 10057810 */ void SetWayType(uchar param_1);
	/* 10057820 */ uchar GetWayType();
	/* 10057830 */ void SetSafeWayMaxYDifference(float param_1);
	/* 10057840 */ float GetSafeWayMaxYDifference();
	/* 10057850 */ bool InitPathBMP(D3DXVECTOR3 param_1, D3DXVECTOR3 param_2);
	/* 10057900 */ bool OnPath(D3DXVECTOR3 param_1);
	/* 10057930 */ void SetPathBMPMinMax(D3DXVECTOR3 param_1, D3DXVECTOR3 param_2);
	/* 10057970 */ void GetPathBMPMinMax(D3DXVECTOR3* param_1, D3DXVECTOR3* param_2);
	/* 10057990 */ D3DXVECTOR3* GetPosPathBMP(D3DXVECTOR3* param_1);
	/* 10057A40 */ void CreatePathBillboard();
	/* 10057BC0 */ void DisableCollideClass(char* param_1);
	/* 10057BF0 */ char* GetDisabledCollideClass();
	/* 10057C00 */ void SetOnlyCollidingClass(char* param_1);
	/* 10057C30 */ char* GetOnlyCollidingClass();
	/* 10057C40 */ uchar LinearSpeedFromAngSpeed(uint* param_1);
	/* 10057EB0 */ uchar GetPatrolPointAt(int param_1);
	/* 10057F00 */ void DeletePatrols();
	/* 10057F90 */ int GetPatrolPointsCount();
	/* 10057FC0 */ bool LoadVideo(char* param_1);
	/* 10058080 */ void PlayVideo();
	/* 100580A0 */ bool LoadMp3Sound(char* param_1);
	/* 100581E0 */ void SetMp3Volume(float param_1);
	/* 10058210 */ void PlayMp3Sound();
	/* 10058230 */ void StopMp3Sound();
	/* 10058250 */ bool IsPlayingMp3Sound();
	/* 10058280 */ bool IsEndMp3Sound();
	/* 100582A0 */ void RewindMp3Sound();
	/* 100582C0 */ int LoadSound(char* param_1);
	/* 100586D0 */ void PlaySoundA(int param_1, bool param_2);
	/* 10058780 */ void EnableCallHandlerOnPlaySoundEnd(int param_1);
	/* 100587A0 */ void EnableCallHandlerOnPlaySoundEnd(int param_1, cMagKernel* param_2);
	/* 100587C0 */ void StopSound(int param_1);
	/* 10058850 */ bool IsPlaying(int param_1);
	/* 100588D0 */ void SetVolume(int param_1, float param_2);
	/* 100589A0 */ void SetFrequency(int param_1, int param_2);
	/* 10058A10 */ void ResetFrequency(int param_1);
	/* 10058A80 */ void ClearSound();
	/* 10058B50 */ void SetDefaultSoundRanges(int param_1, float param_2, float param_3);
	/* 10058BF0 */ void TestSoundRanges();
	/* 10058D90 */ void MatrixToEuler(float param_1);
	/* 10058E90 */ void RepairEuler(bool param_1);
	/* 10058EA0 */ bool EnableRendering();
	/* 10058EB0 */ void OnAttachChild(cMagMeshObject* param_1);
	/* 10058F30 */ void OnDetachChild(cMagMeshObject* param_1);
	/* 10058FC0 */ void SetDestRotation(uint param_1, uint param_2, uint param_3);
	/* 10059010 */ void ClearDestRotation();
	/* 10059040 */ void SetRotationAngSpeed(uint param_1, uint param_2, uint param_3);
	/* 10059060 */ void SetMotionDirection(float param_1);
	/* 10059280 */ uchar GetRotationAngSpeed(uint* param_1);
	/* 100592B0 */ void SetMotionRotationAngSpeed(uint param_1, uint param_2, uint param_3);
	/* 100592D0 */ uchar GetMotionRotationAngSpeed(uint* param_1);
	/* 10059300 */ void PauseMovableTreeCollision(bool param_1);
	/* 10059330 */ long SetStaticMeshAlpha(int param_1);
	/* 10059350 */ bool SetMultiple(float param_1);
	/* 10059370 */ long SetAlpha(int param_1);
	/* 100593D0 */ void SetAlpha(ulong param_1, ulong param_2);
	/* 10059410 */ long SetColor(float param_1, float param_2, float param_3, float param_4);
	/* 10059460 */ void SetCullMode(int param_1);
	/* 10059480 */ void SetAlphaGreatereQual(ulong param_1);
	/* 100594A0 */ void AddWaterTexture(char* param_1);
	/* 10059720 */ void SetFps(float param_1);
	/* 10059730 */ void SetFpsMove(float param_1);
	/* 10059740 */ void SetVelocityAnimMove(float param_1);
	/* 10059750 */ void EnableWaterEffect(bool param_1);
	/* 10059770 */ void PlayWaterAnim();
	/* 10059780 */ void StopWaterAnim();
	/* 10059790 */ void SetScaleTile(float param_1);
	/* 100597B0 */ void EnableRiverEffect(bool param_1);
	/* 100597C0 */ void SetMoveWater(bool param_1);
	/* 100597D0 */ bool GetFreeDestinationDir();
	/* 100597E0 */ void SetFreeDestinationDir(bool param_1);
	/* 100597F0 */ void EnableDynamicLight(bool param_1);
	/* 10059820 */ void SetUp(float param_1);
	/* 10059B90 */ uchar GetUp(uint* param_1);
	/* 10059BC0 */ void SetRight(float param_1);
	/* 10059F50 */ uchar GetRight(uint* param_1);
	/* 10059F80 */ void SetFreeRotationMatrix(bool param_1);
	/* 10059F90 */ bool GetFreeRotationMatrix();
	/* 10059FA0 */ void SetOutsideViewPhysicsActivityRange(float param_1);
	/* 10059FC0 */ float GetOutsideViewPhysicsActivityRange();
	/* 10059FD0 */ bool PhysicsActivityRange();
	/* 1005A060 */ void EnableFrustumPhysicsPause(bool param_1);
	/* 1005A070 */ bool EnableFrustumPhysicsPause();
	/* 1005A080 */ void SetFrustumPhysicsPause(bool param_1);
	/* 1005A0B0 */ bool GetFrustumPhysicsPause();
	/* 1005A0C0 */ void EnableDynamicPointLight(bool param_1);
	/* 1005A0D0 */ void AddDynamicLight(D3DLIGHT8 param_1);
	/* 1005A100 */ void DisableDynamicLight();
	/* 1005A120 */ void SetLightingObject(bool param_1);
	/* 1005A130 */ void SetAmbient(float param_1, float param_2, float param_3);
	/* 1005A150 */ bool JumpEnabled();
	/* 1005A170 */ uint ClassifyPoint(float param_1, float param_2, float param_3, float param_4, float param_5, float param_6, float param_7, float param_8, float param_9);
	/* 1005A1E0 */ float GetMagnitude(float param_1, float param_2, float param_3);
	/* 1005A220 */ uint* GetHelperPosition(uint* param_1, uchar* param_2);
	/* 1005A290 */ void SetPhysicsType(uchar param_1);
	/* 1005A410 */ uchar GetPhysicsType();
	/* 1005A420 */ uint TraceScene(uint param_1, uint param_2, uint param_3, uint param_4, uint param_5, uint param_6, uint param_7, uint param_8, uint param_9);
	/* 1005A490 */ void EnablePushing(bool param_1);
	/* 1005A4A0 */ bool EnablePushing();
	/* 1005A4B0 */ void SetRotationMatrix(D3DXMATRIX param_1);
	/* 1005A5C0 */ void EnableNBFacesCollision(bool param_1);
	/* 1005A5D0 */ bool EnableNBFacesCollision();
	/* 1005A600 */ void ActivateLightMap(int param_1);
	/* 1005A610 */ void SetEllipsoid(uint param_1, uint param_2, uint param_3);
	/* 1005A650 */ uchar GetEllipsoid(uint* param_1);
	/* 1005A680 */ bool TraceObjects(uchar param_1);
	/* 1005A6B0 */ bool TraceScene(uchar param_1);
	/* 1005A6E0 */ void CreateMagQuad();
	/* 1005A750 */ void SetTextureMagQuad(char* param_1);
	/* 1005A770 */ void RenderMagQuad();
	/* 1005A890 */ void SetAlphaMagQuad(float param_1);
	/* 1005A9E0 */ float GetPhysicsFrameTime();
	/* 1005AA00 */ void GetBoundingBox(uchar param_1, uchar param_2, int param_3);
	/* 1005AA50 */ void EnableAnimTexture(bool param_1);
	/* 1005AA60 */ int AddTexture(char* param_1);
	/* 1005AA70 */ bool SetTexture(int param_1);
	/* 1005AAE0 */ int AddAnimTexture(char* param_1);
	/* 1005AB50 */ void SetAnimTextureFPS(int param_1);
	/* 1005AB60 */ void SetAnimTextureFrameCount(int param_1);
	/* 1005AB70 */ void RenderAnimTexture();
	/* 1005AC50 */ void EnableAnimTextureMove(bool param_1);
	/* 1005AC60 */ void EnableAttachDynObj(bool param_1);
	/* 1005AC80 */ bool EnableAttachDynObj();
	/* 1005ACA0 */ void EnableLastParentSpeed(bool param_1);
	/* 1005ACC0 */ bool EnableLastParentSpeed();
	/* 1005ACE0 */ void SetAcceleration(float param_1);
	/* 1005ACF0 */ float GetAcceleration();
	/* 1005AD00 */ bool SectorRendering();
	/* 1005ADF0 */ void DisableTestMeshInSector(bool param_1);
	/* 1005AE00 */ void PauseObject(bool param_1);
	/* 1005AE50 */ void EnableAnimTextureLightMap(bool param_1);
	/* 1005AE60 */ void AddAnimTextureLightMap(char* param_1);
	/* 1005B030 */ void SetAnimTextureLightMapFPS(int param_1);
	/* 1005B040 */ void AnimateLightMap();
	/* 1005B110 */ void EnableZBuffeWrite(bool param_1);
	/* 1005B120 */ bool EnableZBuffeWrite();
	/* 1005B130 */ int GetFaceCount();
	/* 1005B160 */ void EnableForceTransform(bool param_1);
	/* 1005B170 */ void SetForceTransformMatrix(uchar param_1);
	/* 1005B190 */ void SetLightPosition(D3DXVECTOR3 param_1);
	/* 1005B1C0 */ void EnableLight(bool param_1);
	/* 1005B1E0 */ void SetMaterialDiffuse(float param_1, float param_2, float param_3, float param_4);
	/* 1005B210 */ void SetMaterialAmbient(float param_1, float param_2, float param_3, float param_4);
	/* 1005B240 */ void SetLightDiffuse(float param_1, float param_2, float param_3, float param_4);
	/* 1005B270 */ void SetLightAmbient(float param_1, float param_2, float param_3, float param_4);
	/* 1005B2A0 */ void EnableRenderShadow(bool param_1);
	/* 1005B2C0 */ bool EnableRenderShadow();
	/* 1005B2E0 */ void CreateBumpAndEnviromentTexture();
	/* 1005B5A0 */ void LoadLod(char* param_1);
	/* 1005B9B0 */ bool _TestDistanceLOD(float param_1);
	/* 1005BB40 */ bool CreateNavigationPath(char* param_1);
	/* 1005C280 */ uint BuildNaviPoints(uint param_1, uint param_2, uint param_3, uint param_4, uint param_5, uint param_6);
	/* 1005C610 */ int GetNaviPointsCount();
	/* 1005C640 */ uchar GetNaviPointAt(uint* param_1, uint param_2);
	/* 1005C710 */ uchar GotoRandomLocation(uint* param_1);

public:
	/* 0xd4c */ uchar f_d4c[0xd60 - 0xd4c];
	/* 0xd60 */ char fileMeshName[255];
	/* 0xe5f */ uchar f_e5f[0xed1 - 0xe5f];
	/* 0xed1 */ bool unk_ed1;
	/* 0xed2 */ bool unk_ed2;
	/* 0xed3 */ bool statusRemoveObject;
	/* 0xed4 */ uchar f_ed4[0x1305 - 0xed4];
	/* 0x1305 */ bool showWireframe;
	/* 0x1306 */ uchar f_1306[0x1318 - 0x1306];
	/* 0x1318 */ bool showBoundingBox;
	/* 0x1319 */ uchar f_1319[0x1324 - 0x1319];
	/* 0x1324 */ D3DXVECTOR3 unkn_1324;
	/* 0x1330 */ D3DXVECTOR3 unkn_1330;
	/* 0x133c */ bool enableFrustum;
	/* 0x133d */ bool unk_113d;
	/* 0x133e */ bool unk_113e;
	/* 0x133f */ uchar f_133f[0x1388 - 0x133f];
	/* 0x1388 */ D3DXMATRIX translationMatrix;
	/* 0x13c8 */ D3DXMATRIX scaleMatrix;
	/* 0x1408 */ D3DXMATRIX computationMatrix;
	/* 0x1448 */ D3DXMATRIX unkn_1448;
	/* 0x1488 */ uchar f_1488[0x1688 - 0x1488];
	/* 0x1688 */ D3DXVECTOR3 translationBoundingBox;
	/* 0x1694 */ D3DXVECTOR3 scaleBoundingBox;
	/* 0x16a0 */ bool enableRendering;
	/* 0x16a1 */ bool enablePortalRendering;
	/* 0x16a2 */ uchar f_16a2[0x17a8 - 0x16a2];
	/* 0x17a8 */ D3DXVECTOR3 unkn_17a8;
	/* 0x17b4 */ D3DXVECTOR3 unkn_17b4;
	/* 0x17c0 */ uchar f_17c0[0x1930 - 0x17c0];
	/* 0x1930 */ D3DXMATRIX worldMat;
	/* 0x1970 */ uchar f_1970[0x1a04 - 0x1970];
	/* 0x1a04 */ D3DXMATRIX rotateMatrix;
	/* 0x1a44 */ uchar f_1a44[0x1e9c - 0x1a44];
	/* 0x1e9c */ IStudioMesh* studioMesh;
	/* 0x1ea0 */ cStaticMesh* staticMesh;
	/* 0x1ea4 */ uchar f_1ea4[0x2658 - 0x1ea4];
};

STATIC_ASSERT(sizeof(cMagMeshObject) == 0x2658);

#endif