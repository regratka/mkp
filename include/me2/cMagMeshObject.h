#ifndef C_MAG_MESH_OBJECT
#define C_MAG_MESH_OBJECT

#include <globals.h>

#include "cMagUtility.h"
#include "IStudioMesh.h"
#include "cStaticMesh.h"
#include "CPath.h"
#include "cVideoPlayer.h"
#include "cMp3Player.h"
#include "ColObject.h"
#include "cMagFrustumCull.h"
#include "cMagBillboard.h"
#include "cMagSector.h"
#include "cBlob.h"
#include "CCPUTicker.h"

struct LINEVERTEX {
	D3DXVECTOR3 pos;
	D3DCOLOR color;
};

struct WATERTEXTURE {
	/* 0x00 */ void* unk_00;
	/* 0x04 */ IDirect3DTexture8* texture;
	/* 0x08 */ char textureName[256];
};

class DLLEXPORT cMagMeshObject : public cMagUtility {
public:
	struct PatrolPoint {
		/* 0x00 */ uchar f_00[0x18];
	};

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
	/* 10055620 */ virtual void OnRenderShadow();
	/* 100556A0 */ void SetShadowType(int param_1);
	/* 100556E0 */ virtual int GetShadowType();
	/* 100556F0 */ cMagGameObject* GetEngine();
	/* 10055700 */ void SetDirection(float param_1, float param_2, float param_3);
	/* 10055C70 */ void SetDirection(D3DXVECTOR3 param_1);
	/* 10056270 */ D3DXVECTOR3 GetDirection();
	/* 100562A0 */ void GetDirection(float& param_1, float& param_2, float& param_3);
	/* 100562D0 */ void SetSpeed(D3DXVECTOR3 param_1);
	/* 10056340 */ D3DXVECTOR3 GetSpeed();
	/* 100563B0 */ void SetGravityAcceleration(float param_1);
	/* 100563C0 */ float GetGravityAcceleration();
	/* 100563E0 */ void SetSpeedValue(float param_1);
	/* 10056440 */ float GetSpeedValue();
	/* 10056450 */ void SetSpeedDirection(D3DXVECTOR3 param_1);
	/* 100564B0 */ D3DXVECTOR3 GetSpeedDirection();
	/* 100564E0 */ void Jump(D3DXVECTOR3 param_1);
	/* 10056500 */ D3DXVECTOR3 GetFallSpeed();
	/* 10056530 */ void SetDestinationPos(D3DXVECTOR3 param_1, float param_2);
	/* 10056590 */ void ClearDestinationPos();
	/* 100565C0 */ void SetDestinationDir(D3DXVECTOR3 param_1, int param_2);
	/* 10056630 */ void ClearDestinationDir();
	/* 10056660 */ void SetMaxAngSpeed(float param_1);
	/* 10056670 */ float GetMaxAngSpeed();
	/* 10056680 */ void Rotate(float param_1, float param_2, float param_3);
	/* 100566D0 */ void SetAngSpeed(D3DXVECTOR3 param_1);
	/* 100566F0 */ D3DXVECTOR3 GetAngSpeed();
	/* 10056720 */ bool RestrictFrameRate(float param_1);
	/* 10056780 */ D3DXMATRIX GetSpace();
	/* 100567A0 */ void Rotate(D3DXVECTOR3 param_1, float param_2);
	/* 100569A0 */ void EnableTestDistance(bool param_1);
	/* 100569B0 */ D3DXVECTOR3 GetBoneWorldPosition(char* param_1);
	/* 10056B70 */ bool GetBoneMatrix(char* param_1, D3DXMATRIX& param_2);
	/* 10056D00 */ D3DXMATRIX GetBoneWorldRotateMatrix(char* param_1);
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
	/* 10057470 */ virtual D3DXMATRIX GetTransformMatrix();
	/* 10057470 */ D3DXMATRIX GetVolatileWorldMat();
	/* 100574E0 */ void SetSlideObject(cMagMeshObject* param_1);
	/* 100574F0 */ cMagMeshObject* GetSlideObject();
	/* 10057500 */ void AttachTo(cMagMeshObject* param_1);
	/* 10057560 */ void Detach();
	/* 100575D0 */ cMagMeshObject* GetParent();
	/* 100575E0 */ D3DXVECTOR3 GetRotate();
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
	/* 10057970 */ void GetPathBMPMinMax(D3DXVECTOR3& param_1, D3DXVECTOR3& param_2);
	/* 10057990 */ D3DXVECTOR3 GetPosPathBMP();
	/* 10057A40 */ void CreatePathBillboard();
	/* 10057BC0 */ void DisableCollideClass(char* param_1);
	/* 10057BF0 */ char* GetDisabledCollideClass();
	/* 10057C00 */ void SetOnlyCollidingClass(char* param_1);
	/* 10057C30 */ char* GetOnlyCollidingClass();
	/* 10057C40 */ uchar LinearSpeedFromAngSpeed(uint* param_1);
	/* 10057EB0 */ cMagMeshObject::PatrolPoint const * GetPatrolPointAt(int param_1);
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
	/* 10058D90 */ void MatrixToEuler(D3DXMATRIX param_1, float& param_2, float& param_3, float& param_4);
	/* 10058E90 */ void RepairEuler(bool param_1);
	/* 10058EA0 */ bool EnableRendering();
	/* 10058F30 */ virtual void OnDetachChild(cMagMeshObject* param_1);
	/* 10058EB0 */ virtual void OnAttachChild(cMagMeshObject* param_1);
	/* 10058FC0 */ void SetDestRotation(D3DXVECTOR3 param_1);
	/* 10059010 */ void ClearDestRotation();
	/* 10059040 */ void SetRotationAngSpeed(D3DXVECTOR3 param_1);
	/* 10059060 */ void SetMotionDirection(float param_1);
	/* 10059280 */ D3DXVECTOR3 GetRotationAngSpeed();
	/* 100592B0 */ void SetMotionRotationAngSpeed(D3DXVECTOR3 param_1);
	/* 100592D0 */ D3DXVECTOR3 GetMotionRotationAngSpeed();
	/* 10059300 */ void PauseMovableTreeCollision(bool param_1);
	/* 10059330 */ HRESULT SetStaticMeshAlpha(int param_1);
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
	/* 1005A170 */ int ClassifyPoint(D3DXVECTOR3 param_1, D3DXVECTOR3 param_2, D3DXVECTOR3 param_3);
	/* 1005A1E0 */ float GetMagnitude(D3DXVECTOR3 param_1);
	/* 1005A220 */ D3DXVECTOR3 GetHelperPosition(char* param_1);
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
	/* 1005AA00 */ void GetBoundingBox(D3DXVECTOR3& param_1, D3DXVECTOR3& param_2, int param_3);
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
	/* 1005B170 */ void SetForceTransformMatrix(D3DXMATRIX param_1);
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
	/* 1005C280 */ bool BuildNaviPoints(D3DXVECTOR3 param_1, D3DXVECTOR3 param_2);
	/* 1005C610 */ int GetNaviPointsCount();
	/* 1005C640 */ uchar GetNaviPointAt(uint* param_1, uint param_2);
	/* 1005C710 */ uchar GotoRandomLocation(uint* param_1);
	/* 100393E0 */ char* CreateNiceString(char* param_1);

public:
	/* 0xd4c */ cBlob* blob;
	/* 0xd50 */ bool enableNBFacesCollision;
	/* 0xd51 */ bool enablePushing;
	/* 0xd52 */ bool enableFrustumPhysicsPause;
	/* 0xd54 */ float outsideViewPhysicsActivityRangePow;
	/* 0xd58 */ float outsideViewPhysicsActivityRange;
	/* 0xd5c */ int unk_d5c;
	/* 0xd60 */ char fileMeshName[255];
	/* 0xe60 */ std::vector<PatrolPoint> patrolPoints;
	/* 0xe70 */ CPath path;
	/* 0xebc */ D3DXVECTOR3 speedDirection;
	/* 0xec8 */ bool pauseUpdatePhysics;
	/* 0xec9 */ uchar collAction;
	/* 0xeca */ bool unk_eca;
	/* 0xecb */ uchar f_ecb[0xed0 - 0xecb];
	/* 0xed0 */ bool enableTestSector;
	/* 0xed1 */ bool unk_ed1;
	/* 0xed2 */ bool unk_ed2;
	/* 0xed3 */ bool statusRemoveObject;
	/* 0xed4 */ float unk_ed4;
	/* 0xed8 */ uchar unk_ed8[1016];
	/* 0x12d0 */ bool enableTestDistance;
	/* 0x12d1 */ bool unk_12d1;
	/* 0x12d2 */ bool unk_12d2;
	/* 0x12d4 */ int unk_12d4;
	/* 0x12d8 */ std::vector<void*> unk_12d8;
	/* 0x12e8 */ cMagMeshObject* linkParent;
	/* 0x12ec */ D3DXVECTOR3 unk_12ec;
	/* 0x12f8 */ bool unk_12f8;
	/* 0x12f9 */ bool unk_12f9;
	/* 0x12fc */ int unk_12fc;
	/* 0x1300 */ int unk_1300;
	/* 0x1304 */ uchar f_1304[0x1305 - 0x1304];
	/* 0x1305 */ bool showWireframe;
	/* 0x1308 */ LINEVERTEX* lineVertex;
	/* 0x130c */ IDirect3DTexture8** lineTexture;
	/* 0x1310 */ CULLSTATE cullState;
	/* 0x1314 */ int unk_1314;
	/* 0x1318 */ bool showBoundingBox;
	/* 0x131c */ float framesSinceLastMeasure;
	/* 0x1320 */ bool unk_1320;
	/* 0x1324 */ D3DXVECTOR3 boundary1;
	/* 0x1330 */ D3DXVECTOR3 boundary2;
	/* 0x133c */ bool enableFrustum;
	/* 0x133d */ bool unk_133d;
	/* 0x133e */ bool unk_133e;
	/* 0x133f */ bool unk_133f;
	/* 0x1340 */ int unk_1340;
	/* 0x1344 */ int unk_1344;
	/* 0x1348 */ D3DXMATRIX unk_1348;
	/* 0x1388 */ D3DXMATRIX translationMatrix;
	/* 0x13c8 */ D3DXMATRIX scaleMatrix;
	/* 0x1408 */ D3DXMATRIX computationMatrix;
	/* 0x1448 */ D3DXMATRIX unk_1448;
	/* 0x1488 */ D3DXMATRIX unk_1488;
	/* 0x14c8 */ D3DXMATRIX unk_14c8;
	/* 0x1508 */ D3DXMATRIX unk_1508;
	/* 0x1548 */ D3DXMATRIX unk_1548;
	/* 0x1588 */ D3DXMATRIX unk_1588;
	/* 0x15c8 */ D3DXMATRIX unk_15c8;
	/* 0x1608 */ D3DXMATRIX unk_1608;
	/* 0x1648 */ D3DXMATRIX unk_1648;
	/* 0x1688 */ D3DXVECTOR3 translationBoundingBox;
	/* 0x1694 */ D3DXVECTOR3 scaleBoundingBox;
	/* 0x16a0 */ bool enableRendering;
	/* 0x16a1 */ bool enablePortalRendering;
	/* 0x16a2 */ bool unk_16a2;
	/* 0x16a4 */ float safeWayMaxYDifference;
	/* 0x16a8 */ uchar wayType;
	/* 0x16a9 */ char onlyCollidingClass[100];
	/* 0x170d */ char disabledCollideClass[100];
	/* 0x1771 */ uchar f_1771[0x1774 - 0x1771];
	/* 0x1774 */ cMagBillboard* billboard;
	/* 0x1778 */ cVideoPlayer* videoPlayer;
	/* 0x177c */ bool unk_177c;
	/* 0x1780 */ cMp3Player* mp3Player;
	/* 0x1784 */ bool unk_1784;
	/* 0x1788 */ std::vector<void*> unk_1788;
	/* 0x1798 */ bool unk_1798;
	/* 0x179c */ int unk_179c;
	/* 0x17a0 */ bool enableCallHandlerOnPlaySoundEnd;
	/* 0x17a4 */ cMagKernel* handlerOnPlaySoundEnd;
	/* 0x17a8 */ D3DXVECTOR3 positionVector;
	/* 0x17b4 */ D3DXVECTOR3 scaleVector;
	/* 0x17c0 */ D3DXVECTOR3 unk_17c0;
	/* 0x17cc */ D3DXVECTOR3 unk_17cc;
	/* 0x17d8 */ D3DXVECTOR3 rotateVector;
	/* 0x17e4 */ int unk_17e4;
	/* 0x17e8 */ char filePath[300];
	/* 0x1914 */ int unk_1914;
	/* 0x1918 */ float unk_1918;
	/* 0x191c */ int unk_191c;
	/* 0x1920 */ int unk_1920;
	/* 0x1924 */ int unk_1924;
	/* 0x1928 */ float lastMeasureTime;
	/* 0x192c */ float frameRate;
	/* 0x1930 */ D3DXMATRIX worldMat;
	/* 0x1970 */ D3DXMATRIX space;
	/* 0x19b0 */ D3DXVECTOR3 angSpeed;
	/* 0x19bc */ float maxAngSpeed;
	/* 0x19c0 */ D3DXVECTOR3* destinationDir;
	/* 0x19c4 */ D3DXVECTOR3* destinationPos;
	/* 0x19c8 */ float unkn_19c8;
	/* 0x19cc */ D3DXVECTOR3 fallSpeed;
	/* 0x19d8 */ float speedValue;
	/* 0x19dc */ float gravityAcceleration;
	/* 0x19e0 */ D3DXVECTOR3 speedVector;
	/* 0x19ec */ uchar f_19ec[0x19f8 - 0x19ec];
	/* 0x19f8 */ D3DXVECTOR3 directionVector;
	/* 0x1a04 */ D3DXMATRIX rotateMatrix;
	/* 0x1a44 */ D3DXMATRIX rotateXMatrix;
	/* 0x1a84 */ D3DXMATRIX rotateYMatrix;
	/* 0x1ac4 */ D3DXMATRIX rotateZMatrix;
	/* 0x1b04 */ bool physics;
	/* 0x1b05 */ bool collision;
	/* 0x1b06 */ bool collisionScene;
	/* 0x1b07 */ bool collisionObjects;
	/* 0x1b08 */ uchar collisionType;
	/* 0x1b0c */ float slideAngle;
	/* 0x1b10 */ D3DXMATRIX unk_1b10;
	/* 0x1b50 */ cMagMeshObject* parent;
	/* 0x1b54 */ cMagMeshObject* slideObject;
	/* 0x1b58 */ bool unk_1b58;
	/* 0x1b59 */ uchar f_1b59[0x1b60 - 0x1b59];
	/* 0x1b60 */ CCPUTicker cpuTicker;
	/* 0x1e98 */ int unk_1e98;
	/* 0x1e9c */ IStudioMesh* studioMesh;
	/* 0x1ea0 */ cStaticMesh* staticMesh;
	/* 0x1ea4 */ bool unk_1ea4;
	/* 0x1ea8 */ ulong unk_1ea8;
	/* 0x1eac */ bool unk_1eac;
	/* 0x1eb0 */ float unk_1eb0;
	/* 0x1eb4 */ float unk_1eb4;
	/* 0x1eb8 */ float unk_1eb8;
	/* 0x1ebc */ float unk_1ebc;
	/* 0x1ec0 */ int cullMode;
	/* 0x1ec4 */ ulong unk_1ec4;
	/* 0x1ec8 */ ulong unk_1ec8;
	/* 0x1ecc */ std::vector<WATERTEXTURE> waterTextures;
	/* 0x1edc */ bool playWaterAnim;
	/* 0x1edd */ bool enableWaterEffect;
	/* 0x1ede */ bool unk_1ede;
	/* 0x1ee0 */ float scaleTile;
	/* 0x1ee4 */ bool unk_1ee4;
	/* 0x1ee8 */ ulong unk_1ee8;
	/* 0x1eec */ ulong unk_1eec;
	/* 0x1ef0 */ float fps;
	/* 0x1ef4 */ uchar f_1ef4[0x1ef5 - 0x1ef4];
	/* 0x1ef5 */ bool enableRiverEffect;
	/* 0x1ef6 */ bool moveWater;
	/* 0x1ef8 */ float fpsMove;
	/* 0x1efc */ float velocityAnimMove;
	/* 0x1f00 */ D3DXVECTOR3* destRotation;
	/* 0x1f04 */ D3DXVECTOR3 rotationAngSpeed;
	/* 0x1f10 */ D3DXVECTOR3 motionRotationAngSpeed;
	/* 0x1f1c */ D3DXMATRIX unk_1f1c;
	/* 0x1f5c */ bool unk_1f5c;
	/* 0x1f5d */ bool enableDynamicPointLight;
	/* 0x1f5e */ bool unk_1f5e;
	/* 0x1f60 */ int dynamicLightID;
	/* 0x1f64 */ char unk_1f64[104];
	/* 0x1fcc */ bool lightingObject;
	/* 0x1fd0 */ D3DXVECTOR3 unk_1fd0;
	/* 0x1fdc */ ColObject* colObject;
	/* 0x1fe0 */ bool freeRotationMatrix;
	/* 0x1fe1 */ bool freeDestinationDir;
	/* 0x1fe4 */ int unk_1fe4;
	/* 0x1fe8 */ uchar physicsType;
	/* 0x1fe9 */ uchar f_1fe9[0x1ff0 - 0x1fe9];
	/* 0x1ff0 */ int unk_1ff0;
	/* 0x1ff4 */ int unk_1ff4;
	/* 0x1ff8 */ bool unk_1ff8;
	/* 0x1ff9 */ uchar f_1ff9[0x2000 - 0x1ff9];
	/* 0x2000 */ std::vector<IDirect3DTexture8*> animTextureLightMaps;
	/* 0x2010 */ int animTextureLightMapFPS;
	/* 0x2014 */ bool enableAnimTextureLightMap;
	/* 0x2018 */ float unk_2018;
	/* 0x201c */ char unk_201c[300];
	/* 0x2148 */ int lightMap;
	/* 0x214c */ IDirect3DTexture8* magQuadTexture;
	/* 0x2150 */ IDirect3DVertexBuffer8* magQuadBuffer;
	/* 0x2154 */ bool unk_2154;
	/* 0x2155 */ bool enableAnimTexture;
	/* 0x2156 */ bool enableAnimTextureMove;
	/* 0x2158 */ IDirect3DTexture8* animTexture;
	/* 0x215c */ int animTextureFPS;
	/* 0x2160 */ int animTextureFrameCount;
	/* 0x2164 */ std::vector<IDirect3DTexture8*> animTextures;
	/* 0x2174 */ float acceleration;
	/* 0x2178 */ bool unk_2178;
	/* 0x2179 */ char unk_2179[255];
	/* 0x2278 */ cMagSector* sector;
	/* 0x227c */ bool unk_227c;
	/* 0x2280 */ float unk_2280;
	/* 0x2284 */ void* unk_2284;
	/* 0x2288 */ bool unk_2288;
	/* 0x2289 */ bool unk_2289;
	/* 0x228a */ bool disableTestMeshInSector;
	/* 0x228b */ bool unk_228b;
	/* 0x228c */ bool enableZBufferWrite;
	/* 0x228d */ bool enableForceTransform;
	/* 0x2290 */ D3DXMATRIX forceTransformMatrix;
	/* 0x22d0 */ bool unk_22d0;
	/* 0x22d4 */ int shadowType;
	/* 0x22d8 */ uchar f_22d8[0x2614 - 0x22d8];
	/* 0x2614 */ std::vector<void*> unk_2614;
	/* 0x2624 */ D3DXVECTOR3 unk_2624;
	/* 0x2630 */ bool unk_2630;
	/* 0x2634 */ std::vector<void*> unk_2634;
	/* 0x2644 */ int unk_2644;
	/* 0x2648 */ std::vector<void*> unk_2648;

public:
	/* 1018C598 */ static bool m_bRepairEuler;
};

STATIC_ASSERT(sizeof(cMagMeshObject) == 0x2658);

#endif