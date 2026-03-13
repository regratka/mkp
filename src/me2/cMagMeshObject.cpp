#include "cMagMeshObject.h"

/* 10007A10-10007A17 00007	*/
char* cMagMeshObject::GetFileMeshName() {
	return 0;
}

/* 10007A20-10007A27 00007	*/
bool cMagMeshObject::GetStatusRemoveObject() {
	return 0;
}

/* 10007A30-10007A3D 0000D	*/
void cMagMeshObject::RemoveObject(bool param_1) {
}

/* 10007A40-10007A5A 0001A	*/
uchar cMagMeshObject::GetWorldMat(uint* param_1) {
	return 0;
}

/* 10007A60-10007A6D 0000D	*/
void cMagMeshObject::ShowWireframe(bool param_1) {
}

/* 10007A70-10007A7D 0000D	*/
void cMagMeshObject::EnableFrustum(bool param_1) {
}

/* 10007A80-10007A8D 0000D	*/
void cMagMeshObject::EnableRendering(bool param_1) {
}

/* 10007A90-10007A9D 0000D	*/
void cMagMeshObject::EnablePortalRendering(bool param_1) {
}

/* 10007AA0-10008D37 01297	*/
cMagMeshObject::cMagMeshObject(cMagMeshObject* param_1) {
}

/* 10008D40-1000A7EF 01AAF	*/
cMagMeshObject* cMagMeshObject::operator=(cMagMeshObject* param_1) {
	return 0;
}

/* 10051E50-10052DEC 00F9C	*/
cMagMeshObject::cMagMeshObject() {
}

/* 10052DF0-100530E2 002F2	*/
cMagMeshObject::~cMagMeshObject() {
}

/* 100531E0-100534BB 002DB	*/
int cMagMeshObject::Is3dmFile(char* param_1) {
	return 0;
}

/* 100534C0-10053A27 00567	*/
void cMagMeshObject::LoadMesh(char* param_1) {
}

/* 10053AA0-10053B25 00085	*/
void cMagMeshObject::SetPosition(D3DXVECTOR3 param_1) {
}

/* 10053B30-10053BB5 00085	*/
void cMagMeshObject::SetScale(D3DXVECTOR3 param_1) {
}

/* 10053BC0-10053C01 00041	*/
D3DXVECTOR3 cMagMeshObject::GetPosition() {
	return 0;
}

/* 10053C10-10053C31 00021	*/
uchar cMagMeshObject::GetScale(uint* param_1) {
	return 0;
}

/* 10053C40-10053C5A 0001A	*/
uchar cMagMeshObject::GetRotateMatrix(uint* param_1) {
	return 0;
}

/* 10053C60-10053C78 00018	*/
void cMagMeshObject::SetRotateMatrix(uchar param_1) {
}

/* 10053C80-10053C92 00012	*/
int cMagMeshObject::GetFrameCount() {
	return 0;
}

/* 10053CA0-10053CC8 00028	*/
bool cMagMeshObject::InitAnimSeq(char* param_1, int param_2, int param_3) {
	return 0;
}

/* 10053CD0-10053CD5 00005	*/
bool cMagMeshObject::InitAnimSeq(char* param_1, char* param_2, int param_3, int param_4, int param_5, char* param_6) {
	return 0;
}

/* 10053CE0-10053CF7 00017	*/
void cMagMeshObject::DeleteAnimSeq(char* param_1) {
}

/* 10053D00-10053D10 00010	*/
void cMagMeshObject::DeleteAllAnimSeq() {
}

/* 10053D10-10053D39 00029	*/
void cMagMeshObject::PlayAnimSeq(int param_1, int param_2) {
}

/* 10053D40-10053D5F 0001F	*/
void cMagMeshObject::SetAnimFreq(char* param_1, int param_2) {
}

/* 10053D60-10053D7C 0001C	*/
bool cMagMeshObject::IsPlaying(char* param_1) {
	return 0;
}

/* 10053D80-10053D9B 0001B	*/
void cMagMeshObject::StopAnim(char* param_1) {
}

/* 10053DA0-10053DC3 00023	*/
bool cMagMeshObject::PlayAnim(char* param_1, int param_2) {
	return 0;
}

/* 10053DD0-10053DE7 00017	*/
void cMagMeshObject::EnableAnimKeys(bool param_1) {
}

/* 10053DF0-10053E07 00017	*/
void cMagMeshObject::SetMeshType(int param_1) {
}

/* 10053E10-10053E29 00019	*/
bool cMagMeshObject::PlayAnim(char* param_1) {
	return 0;
}

/* 10053E30-10053E35 00005	*/
bool cMagMeshObject::InitAnimSeq(char* param_1) {
	return 0;
}

/* 10053E40-10053EDE 0009E	*/
int cMagMeshObject::FrameRate() {
	return 0;
}

/* 10053EF0-10053EFD 0000D	*/
void cMagMeshObject::OnAnimEnd1(char* param_1) {
}

/* 10053F00-10053F2F 0002F	*/
bool cMagMeshObject::OnPlayAnim() {
	return 0;
}

/* 10053F30-10053F47 00017	*/
void cMagMeshObject::SetAnimMorphTime(float param_1) {
}

/* 10053F50-10053F67 00017	*/
void cMagMeshObject::SetStepMorph(float param_1) {
}

/* 10053F70-10053F87 00017	*/
void cMagMeshObject::EnableMorph(bool param_1) {
}

/* 10053F90-10053FA2 00012	*/
void cMagMeshObject::AnimFrameMeter(char* param_1, int param_2) {
}

/* 10053FB0-10054400 00450	*/
void cMagMeshObject::RenderMesh() {
}

/* 10054400-10054501 00101	*/
void cMagMeshObject::DrawLine(float param_1, float param_2, float param_3, float param_4) {
}

/* 10054510-10054560 00050	*/
void cMagMeshObject::InitBoundingBox() {
}

/* 10054560-1005456D 0000D	*/
void cMagMeshObject::ShowBoundingBox(bool param_1) {
}

/* 10054570-1005458D 0001D	*/
void cMagMeshObject::CorrectTranslationBoundingBox(uint param_1, uint param_2, uint param_3) {
}

/* 10054590-100545F8 00068	*/
void cMagMeshObject::CorrectScaleBoundingBox(float param_1, float param_2, float param_3) {
}

/* 10054600-10054C46 00646	*/
bool cMagMeshObject::_TestDistance(float param_1) {
	return 0;
}

/* 10054C50-10054C5D 0000D	*/
bool cMagMeshObject::TestDistance(float param_1) {
	return 0;
}

/* 10054C60-10054C6D 0000D	*/
void cMagMeshObject::EnableTestSector(bool param_1) {
}

/* 10054C70-10054FDB 0036B	*/
void cMagMeshObject::OnUpdate_() {
}

/* 10054FE0-1005561B 0063B	*/
void cMagMeshObject::OnRender() {
}

/* 10055620-1005569D 0007D	*/
void cMagMeshObject::OnRenderShadow() {
}

/* 100556A0-100556D7 00037	*/
void cMagMeshObject::SetShadowType(int param_1) {
}

/* 100556E0-100556E7 00007	*/
ulong cMagMeshObject::GetShadowType() {
	return 0;
}

/* 100556F0-100556F8 00008	*/
cMagGameObject* cMagMeshObject::GetEngine() {
	return 0;
}

/* 10055700-10055C6C 0056C	*/
void cMagMeshObject::SetDirection(float param_1, float param_2, float param_3) {
}

/* 10055C70-10056267 005F7	*/
void cMagMeshObject::SetDirection(D3DXVECTOR3 param_1) {
}

/* 10056270-10056291 00021	*/
D3DXVECTOR3* cMagMeshObject::GetDirection(D3DXVECTOR3* param_1) {
	return 0;
}

/* 100562A0-100562C7 00027	*/
void cMagMeshObject::GetDirection(float* param_1, float* param_2, float* param_3) {
}

/* 100562D0-1005633B 0006B	*/
void cMagMeshObject::SetSpeed(float param_1, float param_2, float param_3) {
}

/* 10056340-100563AA 0006A	*/
uchar cMagMeshObject::GetSpeed(float* param_1) {
	return 0;
}

/* 100563B0-100563BD 0000D	*/
void cMagMeshObject::SetGravityAcceleration(float param_1) {
}

/* 100563C0-100563DD 0001D	*/
float cMagMeshObject::GetGravityAcceleration() {
	return 0;
}

/* 100563E0-10056437 00057	*/
void cMagMeshObject::SetSpeedValue(float param_1) {
}

/* 10056440-10056447 00007	*/
float cMagMeshObject::GetSpeedValue() {
	return 0;
}

/* 10056450-100564A9 00059	*/
void cMagMeshObject::SetSpeedDirection(D3DXVECTOR3 param_1) {
}

/* 100564B0-100564D1 00021	*/
uchar cMagMeshObject::GetSpeedDirection(uint* param_1) {
	return 0;
}

/* 100564E0-100564FD 0001D	*/
void cMagMeshObject::Jump(uint param_1, uint param_2, uint param_3) {
}

/* 10056500-10056521 00021	*/
uchar cMagMeshObject::GetFallSpeed(uint* param_1) {
	return 0;
}

/* 10056530-10056586 00056	*/
void cMagMeshObject::SetDestinationPos(uint param_1, uint param_2, uint param_3, uint param_4) {
}

/* 10056590-100565B2 00022	*/
void cMagMeshObject::ClearDestinationPos() {
}

/* 100565C0-10056622 00062	*/
void cMagMeshObject::SetDestinationDir(uint param_1, uint param_2, uint param_3) {
}

/* 10056630-10056652 00022	*/
void cMagMeshObject::ClearDestinationDir() {
}

/* 10056660-1005666D 0000D	*/
void cMagMeshObject::SetMaxAngSpeed(float param_1) {
}

/* 10056670-10056677 00007	*/
float cMagMeshObject::GetMaxAngSpeed() {
	return 0;
}

/* 10056680-100566CE 0004E	*/
void cMagMeshObject::Rotate(float param_1, float param_2, float param_3) {
}

/* 100566D0-100566ED 0001D	*/
void cMagMeshObject::SetAngSpeed(uint param_1, uint param_2, uint param_3) {
}

/* 100566F0-10056711 00021	*/
uchar cMagMeshObject::GetAngSpeed(uint* param_1) {
	return 0;
}

/* 10056720-10056772 00052	*/
bool cMagMeshObject::RestrictFrameRate(float param_1) {
	return 0;
}

/* 10056780-1005679A 0001A	*/
uchar cMagMeshObject::GetSpace(uint* param_1) {
	return 0;
}

/* 100567A0-1005699F 001FF	*/
void cMagMeshObject::Rotate(uchar param_1, uchar param_2, uchar param_3, uint param_4) {
}

/* 100569A0-100569AD 0000D	*/
void cMagMeshObject::EnableTestDistance(bool param_1) {
}

/* 100569B0-10056B6B 001BB	*/
uchar cMagMeshObject::GetBoneWorldPosition(uint* param_1, char* param_2) {
	return 0;
}

/* 10056B70-10056CF1 00181	*/
bool cMagMeshObject::GetBoneMatrix(char* param_1, uchar param_2) {
	return 0;
}

/* 10056D00-10056D9E 0009E	*/
uchar cMagMeshObject::GetBoneWorldRotateMatrix(uint* param_1) {
	return 0;
}

/* 10056DA0-10056EBB 0011B	*/
void cMagMeshObject::OnUpdateLink() {
}

/* 10056EC0-10057143 00283	*/
void cMagMeshObject::LinkToBone(cMagMeshObject* param_1, char* param_2) {
}

/* 10057150-1005729A 0014A	*/
void cMagMeshObject::UnLinkFromBone(cMagMeshObject* param_1) {
}

/* 100572A0-100572A7 00007	*/
bool cMagMeshObject::GetPhysics() {
	return 0;
}

/* 100572B0-100572B7 00007	*/
bool cMagMeshObject::GetCollision() {
	return 0;
}

/* 100572C0-100572C7 00007	*/
bool cMagMeshObject::GetCollisionScene() {
	return 0;
}

/* 100572D0-100572D7 00007	*/
bool cMagMeshObject::GetCollisionObjects() {
	return 0;
}

/* 100572E0-100572E7 00007	*/
uchar cMagMeshObject::GetCollisionType() {
	return 0;
}

/* 100572F0-10057376 00086	*/
void cMagMeshObject::EnablePhysics(bool param_1) {
}

/* 10057380-10057406 00086	*/
void cMagMeshObject::EnableCollision(bool param_1) {
}

/* 10057410-1005741D 0000D	*/
void cMagMeshObject::EnableCollisionScene(bool param_1) {
}

/* 10057420-1005742D 0000D	*/
void cMagMeshObject::EnableCollisionObjects(bool param_1) {
}

/* 10057430-1005743D 0000D	*/
void cMagMeshObject::SetCollisionType(uchar param_1) {
}

/* 10057440-1005744D 0000D	*/
void cMagMeshObject::SetSlideAngle(float param_1) {
}

/* 10057450-1005746D 0001D	*/
float cMagMeshObject::GetSlideAngle() {
	return 0;
}

/* 10057470-100574DE 0006E	*/
D3DXMATRIX* cMagMeshObject::GetTransformMatrix(D3DXMATRIX* param_1) {
	return 0;
}

/* 100574E0-100574ED 0000D	*/
void cMagMeshObject::SetSlideObject(cMagMeshObject* param_1) {
}

/* 100574F0-100574F7 00007	*/
cMagMeshObject* cMagMeshObject::GetSlideObject() {
	return 0;
}

/* 10057500-1005755C 0005C	*/
void cMagMeshObject::AttachTo(cMagMeshObject* param_1) {
}

/* 10057560-100575C4 00064	*/
void cMagMeshObject::Detach() {
}

/* 100575D0-100575D7 00007	*/
cMagMeshObject* cMagMeshObject::GetParent() {
	return 0;
}

/* 100575E0-10057601 00021	*/
uchar cMagMeshObject::GetRotate(uint* param_1) {
	return 0;
}

/* 10057610-10057643 00033	*/
void cMagMeshObject::LinkTo(cMagMeshObject* param_1) {
}

/* 10057650-1005768B 0003B	*/
void cMagMeshObject::UnLink() {
}

/* 10057690-10057697 00007	*/
cMagMeshObject* cMagMeshObject::GetLinkParent() {
	return 0;
}

/* 100576A0-100576AD 0000D	*/
void cMagMeshObject::SetCollAction(uchar param_1) {
}

/* 100576B0-100576B7 00007	*/
uchar cMagMeshObject::GetCollAction() {
	return 0;
}

/* 100576C0-10057704 00044	*/
void cMagMeshObject::SetPauseUpdatePhysics(bool param_1) {
}

/* 10057710-10057717 00007	*/
bool cMagMeshObject::GetPauseUpdatePhysics() {
	return 0;
}

/* 10057720-10057808 000E8	*/
uint* cMagMeshObject::CalculateSpeed(uint* param_1) {
	return 0;
}

/* 10057810-1005781D 0000D	*/
void cMagMeshObject::SetWayType(uchar param_1) {
}

/* 10057820-10057827 00007	*/
uchar cMagMeshObject::GetWayType() {
	return 0;
}

/* 10057830-1005783D 0000D	*/
void cMagMeshObject::SetSafeWayMaxYDifference(float param_1) {
}

/* 10057840-10057847 00007	*/
float cMagMeshObject::GetSafeWayMaxYDifference() {
	return 0;
}

/* 10057850-100578FE 000AE	*/
bool cMagMeshObject::InitPathBMP(D3DXVECTOR3 param_1, D3DXVECTOR3 param_2) {
	return 0;
}

/* 10057900-10057927 00027	*/
bool cMagMeshObject::OnPath(D3DXVECTOR3 param_1) {
	return 0;
}

/* 10057930-10057970 00040	*/
void cMagMeshObject::SetPathBMPMinMax(D3DXVECTOR3 param_1, D3DXVECTOR3 param_2) {
}

/* 10057970-10057988 00018	*/
void cMagMeshObject::GetPathBMPMinMax(D3DXVECTOR3* param_1, D3DXVECTOR3* param_2) {
}

/* 10057990-10057A3A 000AA	*/
D3DXVECTOR3* cMagMeshObject::GetPosPathBMP(D3DXVECTOR3* param_1) {
	return 0;
}

/* 10057A40-10057BBC 0017C	*/
void cMagMeshObject::CreatePathBillboard() {
}

/* 10057BC0-10057BEE 0002E	*/
void cMagMeshObject::DisableCollideClass(char* param_1) {
}

/* 10057BF0-10057BF7 00007	*/
char* cMagMeshObject::GetDisabledCollideClass() {
	return 0;
}

/* 10057C00-10057C2E 0002E	*/
void cMagMeshObject::SetOnlyCollidingClass(char* param_1) {
}

/* 10057C30-10057C37 00007	*/
char* cMagMeshObject::GetOnlyCollidingClass() {
	return 0;
}

/* 10057C40-10057EA5 00265	*/
uchar cMagMeshObject::LinearSpeedFromAngSpeed(uint* param_1) {
	return 0;
}

/* 10057EB0-10057EF8 00048	*/
uchar cMagMeshObject::GetPatrolPointAt(int param_1) {
	return 0;
}

/* 10057F00-10057F87 00087	*/
void cMagMeshObject::DeletePatrols() {
}

/* 10057F90-10057FB7 00027	*/
int cMagMeshObject::GetPatrolPointsCount() {
	return 0;
}

/* 10057FC0-10058037 00077	*/
bool cMagMeshObject::LoadVideo(char* param_1) {
	return 0;
}

/* 10058080-1005809A 0001A	*/
void cMagMeshObject::PlayVideo() {
}

/* 100580A0-100581BD 0011D	*/
bool cMagMeshObject::LoadMp3Sound(char* param_1) {
	return 0;
}

/* 100581E0-10058201 00021	*/
void cMagMeshObject::SetMp3Volume(float param_1) {
}

/* 10058210-1005822A 0001A	*/
void cMagMeshObject::PlayMp3Sound() {
}

/* 10058230-1005824A 0001A	*/
void cMagMeshObject::StopMp3Sound() {
}

/* 10058250-10058276 00026	*/
bool cMagMeshObject::IsPlayingMp3Sound() {
	return 0;
}

/* 10058280-1005829C 0001C	*/
bool cMagMeshObject::IsEndMp3Sound() {
	return 0;
}

/* 100582A0-100582BA 0001A	*/
void cMagMeshObject::RewindMp3Sound() {
}

/* 100582C0-100586CC 0040C	*/
int cMagMeshObject::LoadSound(char* param_1) {
	return 0;
}

/* 100586D0-10058772 000A2	*/
void cMagMeshObject::PlaySoundA(int param_1, bool param_2) {
}

/* 10058780-10058794 00014	*/
void cMagMeshObject::EnableCallHandlerOnPlaySoundEnd(int param_1) {
}

/* 100587A0-100587BE 0001E	*/
void cMagMeshObject::EnableCallHandlerOnPlaySoundEnd(int param_1, cMagKernel* param_2) {
}

/* 100587C0-10058850 00090	*/
void cMagMeshObject::StopSound(int param_1) {
}

/* 10058850-100588C1 00071	*/
bool cMagMeshObject::IsPlaying(int param_1) {
	return 0;
}

/* 100588D0-1005899E 000CE	*/
void cMagMeshObject::SetVolume(int param_1, float param_2) {
}

/* 100589A0-10058A10 00070	*/
void cMagMeshObject::SetFrequency(int param_1, int param_2) {
}

/* 10058A10-10058A7D 0006D	*/
void cMagMeshObject::ResetFrequency(int param_1) {
}

/* 10058A80-10058B47 000C7	*/
void cMagMeshObject::ClearSound() {
}

/* 10058B50-10058BEA 0009A	*/
void cMagMeshObject::SetDefaultSoundRanges(int param_1, float param_2, float param_3) {
}

/* 10058BF0-10058D8F 0019F	*/
void cMagMeshObject::TestSoundRanges() {
}

/* 10058D90-10058E86 000F6	*/
void cMagMeshObject::MatrixToEuler(float param_1) {
}

/* 10058E90-10058E9C 0000C	*/
void cMagMeshObject::RepairEuler(bool param_1) {
}

/* 10058EA0-10058EA7 00007	*/
bool cMagMeshObject::EnableRendering() {
	return 0;
}

/* 10058EB0-10058F2D 0007D	*/
void cMagMeshObject::OnAttachChild(cMagMeshObject* param_1) {
}

/* 10058F30-10058FB5 00085	*/
void cMagMeshObject::OnDetachChild(cMagMeshObject* param_1) {
}

/* 10058FC0-10059002 00042	*/
void cMagMeshObject::SetDestRotation(uint param_1, uint param_2, uint param_3) {
}

/* 10059010-10059032 00022	*/
void cMagMeshObject::ClearDestRotation() {
}

/* 10059040-1005905D 0001D	*/
void cMagMeshObject::SetRotationAngSpeed(uint param_1, uint param_2, uint param_3) {
}

/* 10059060-10059280 00220	*/
void cMagMeshObject::SetMotionDirection(float param_1) {
}

/* 10059280-100592A1 00021	*/
uchar cMagMeshObject::GetRotationAngSpeed(uint* param_1) {
	return 0;
}

/* 100592B0-100592CD 0001D	*/
void cMagMeshObject::SetMotionRotationAngSpeed(uint param_1, uint param_2, uint param_3) {
}

/* 100592D0-100592F1 00021	*/
uchar cMagMeshObject::GetMotionRotationAngSpeed(uint* param_1) {
	return 0;
}

/* 10059300-10059328 00028	*/
void cMagMeshObject::PauseMovableTreeCollision(bool param_1) {
}

/* 10059330-10059346 00016	*/
long cMagMeshObject::SetStaticMeshAlpha(int param_1) {
	return 0;
}

/* 10059350-1005936E 0001E	*/
bool cMagMeshObject::SetMultiple(float param_1) {
	return 0;
}

/* 10059370-100593CC 0005C	*/
long cMagMeshObject::SetAlpha(int param_1) {
	return 0;
}

/* 100593D0-1005940B 0003B	*/
void cMagMeshObject::SetAlpha(ulong param_1, ulong param_2) {
}

/* 10059410-10059456 00046	*/
long cMagMeshObject::SetColor(float param_1, float param_2, float param_3, float param_4) {
	return 0;
}

/* 10059460-1005947D 0001D	*/
void cMagMeshObject::SetCullMode(int param_1) {
}

/* 10059480-10059493 00013	*/
void cMagMeshObject::SetAlphaGreatereQual(ulong param_1) {
}

/* 100594A0-1005971E 0027E	*/
void cMagMeshObject::AddWaterTexture(char* param_1) {
}

/* 10059720-1005972D 0000D	*/
void cMagMeshObject::SetFps(float param_1) {
}

/* 10059730-1005973D 0000D	*/
void cMagMeshObject::SetFpsMove(float param_1) {
}

/* 10059740-1005974D 0000D	*/
void cMagMeshObject::SetVelocityAnimMove(float param_1) {
}

/* 10059750-10059767 00017	*/
void cMagMeshObject::EnableWaterEffect(bool param_1) {
}

/* 10059770-10059778 00008	*/
void cMagMeshObject::PlayWaterAnim() {
}

/* 10059780-10059788 00008	*/
void cMagMeshObject::StopWaterAnim() {
}

/* 10059790-100597AE 0001E	*/
void cMagMeshObject::SetScaleTile(float param_1) {
}

/* 100597B0-100597BD 0000D	*/
void cMagMeshObject::EnableRiverEffect(bool param_1) {
}

/* 100597C0-100597CD 0000D	*/
void cMagMeshObject::SetMoveWater(bool param_1) {
}

/* 100597D0-100597D7 00007	*/
bool cMagMeshObject::GetFreeDestinationDir() {
	return 0;
}

/* 100597E0-100597ED 0000D	*/
void cMagMeshObject::SetFreeDestinationDir(bool param_1) {
}

/* 100597F0-1005981F 0002F	*/
void cMagMeshObject::EnableDynamicLight(bool param_1) {
}

/* 10059820-10059B90 00370	*/
void cMagMeshObject::SetUp(float param_1) {
}

/* 10059B90-10059BB1 00021	*/
uchar cMagMeshObject::GetUp(uint* param_1) {
	return 0;
}

/* 10059BC0-10059F4D 0038D	*/
void cMagMeshObject::SetRight(float param_1) {
}

/* 10059F50-10059F71 00021	*/
uchar cMagMeshObject::GetRight(uint* param_1) {
	return 0;
}

/* 10059F80-10059F8D 0000D	*/
void cMagMeshObject::SetFreeRotationMatrix(bool param_1) {
}

/* 10059F90-10059F97 00007	*/
bool cMagMeshObject::GetFreeRotationMatrix() {
	return 0;
}

/* 10059FA0-10059FBB 0001B	*/
void cMagMeshObject::SetOutsideViewPhysicsActivityRange(float param_1) {
}

/* 10059FC0-10059FC7 00007	*/
float cMagMeshObject::GetOutsideViewPhysicsActivityRange() {
	return 0;
}

/* 10059FD0-1005A053 00083	*/
bool cMagMeshObject::PhysicsActivityRange() {
	return 0;
}

/* 1005A060-1005A06D 0000D	*/
void cMagMeshObject::EnableFrustumPhysicsPause(bool param_1) {
}

/* 1005A070-1005A077 00007	*/
bool cMagMeshObject::EnableFrustumPhysicsPause() {
	return 0;
}

/* 1005A080-1005A0A5 00025	*/
void cMagMeshObject::SetFrustumPhysicsPause(bool param_1) {
}

/* 1005A0B0-1005A0B5 00005	*/
bool cMagMeshObject::GetFrustumPhysicsPause() {
	return 0;
}

/* 1005A0C0-1005A0CD 0000D	*/
void cMagMeshObject::EnableDynamicPointLight(bool param_1) {
}

/* 1005A0D0-1005A0FC 0002C	*/
void cMagMeshObject::AddDynamicLight(D3DLIGHT8 param_1) {
}

/* 1005A100-1005A11F 0001F	*/
void cMagMeshObject::DisableDynamicLight() {
}

/* 1005A120-1005A12D 0000D	*/
void cMagMeshObject::SetLightingObject(bool param_1) {
}

/* 1005A130-1005A147 00017	*/
void cMagMeshObject::SetAmbient(float param_1, float param_2, float param_3) {
}

/* 1005A150-1005A164 00014	*/
bool cMagMeshObject::JumpEnabled() {
	return 0;
}

/* 1005A170-1005A1D3 00063	*/
uint cMagMeshObject::ClassifyPoint(float param_1, float param_2, float param_3, float param_4, float param_5, float param_6, float param_7, float param_8, float param_9) {
	return 0;
}

/* 1005A1E0-1005A216 00036	*/
float cMagMeshObject::GetMagnitude(float param_1, float param_2, float param_3) {
	return 0;
}

/* 1005A220-1005A289 00069	*/
uint* cMagMeshObject::GetHelperPosition(uint* param_1, uchar* param_2) {
	return 0;
}

/* 1005A290-1005A3F5 00165	*/
void cMagMeshObject::SetPhysicsType(uchar param_1) {
}

/* 1005A410-1005A417 00007	*/
uchar cMagMeshObject::GetPhysicsType() {
	return 0;
}

/* 1005A420-1005A489 00069	*/
uint cMagMeshObject::TraceScene(uint param_1, uint param_2, uint param_3, uint param_4, uint param_5, uint param_6, uint param_7, uint param_8, uint param_9) {
	return 0;
}

/* 1005A490-1005A49D 0000D	*/
void cMagMeshObject::EnablePushing(bool param_1) {
}

/* 1005A4A0-1005A4A7 00007	*/
bool cMagMeshObject::EnablePushing() {
	return 0;
}

/* 1005A4B0-1005A5BA 0010A	*/
void cMagMeshObject::SetRotationMatrix(D3DXMATRIX param_1) {
}

/* 1005A5C0-1005A5CD 0000D	*/
void cMagMeshObject::EnableNBFacesCollision(bool param_1) {
}

/* 1005A5D0-1005A5D7 00007	*/
bool cMagMeshObject::EnableNBFacesCollision() {
	return 0;
}

/* 1005A600-1005A60D 0000D	*/
void cMagMeshObject::ActivateLightMap(int param_1) {
}

/* 1005A610-1005A641 00031	*/
void cMagMeshObject::SetEllipsoid(uint param_1, uint param_2, uint param_3) {
}

/* 1005A650-1005A67A 0002A	*/
uchar cMagMeshObject::GetEllipsoid(uint* param_1) {
	return 0;
}

/* 1005A680-1005A6AD 0002D	*/
bool cMagMeshObject::TraceObjects(uchar param_1) {
	return 0;
}

/* 1005A6B0-1005A6DD 0002D	*/
bool cMagMeshObject::TraceScene(uchar param_1) {
	return 0;
}

/* 1005A6E0-1005A749 00069	*/
void cMagMeshObject::CreateMagQuad() {
}

/* 1005A750-1005A76D 0001D	*/
void cMagMeshObject::SetTextureMagQuad(char* param_1) {
}

/* 1005A770-1005A886 00116	*/
void cMagMeshObject::RenderMagQuad() {
}

/* 1005A890-1005A9DE 0014E	*/
void cMagMeshObject::SetAlphaMagQuad(float param_1) {
}

/* 1005A9E0-1005A9F2 00012	*/
float cMagMeshObject::GetPhysicsFrameTime() {
	return 0;
}

/* 1005AA00-1005AA41 00041	*/
void cMagMeshObject::GetBoundingBox(uchar param_1, uchar param_2, int param_3) {
}

/* 1005AA50-1005AA5D 0000D	*/
void cMagMeshObject::EnableAnimTexture(bool param_1) {
}

/* 1005AA60-1005AA6D 0000D	*/
int cMagMeshObject::AddTexture(char* param_1) {
	return 0;
}

/* 1005AA70-1005AAD4 00064	*/
bool cMagMeshObject::SetTexture(int param_1) {
	return 0;
}

/* 1005AAE0-1005AB46 00066	*/
int cMagMeshObject::AddAnimTexture(char* param_1) {
	return 0;
}

/* 1005AB50-1005AB5D 0000D	*/
void cMagMeshObject::SetAnimTextureFPS(int param_1) {
}

/* 1005AB60-1005AB6D 0000D	*/
void cMagMeshObject::SetAnimTextureFrameCount(int param_1) {
}

/* 1005AB70-1005AC50 000E0	*/
void cMagMeshObject::RenderAnimTexture() {
}

/* 1005AC50-1005AC5D 0000D	*/
void cMagMeshObject::EnableAnimTextureMove(bool param_1) {
}

/* 1005AC60-1005AC77 00017	*/
void cMagMeshObject::EnableAttachDynObj(bool param_1) {
}

/* 1005AC80-1005AC94 00014	*/
bool cMagMeshObject::EnableAttachDynObj() {
	return 0;
}

/* 1005ACA0-1005ACB7 00017	*/
void cMagMeshObject::EnableLastParentSpeed(bool param_1) {
}

/* 1005ACC0-1005ACD4 00014	*/
bool cMagMeshObject::EnableLastParentSpeed() {
	return 0;
}

/* 1005ACE0-1005ACED 0000D	*/
void cMagMeshObject::SetAcceleration(float param_1) {
}

/* 1005ACF0-1005ACF7 00007	*/
float cMagMeshObject::GetAcceleration() {
	return 0;
}

/* 1005AD00-1005ADED 000ED	*/
bool cMagMeshObject::SectorRendering() {
	return 0;
}

/* 1005ADF0-1005ADFD 0000D	*/
void cMagMeshObject::DisableTestMeshInSector(bool param_1) {
}

/* 1005AE00-1005AE45 00045	*/
void cMagMeshObject::PauseObject(bool param_1) {
}

/* 1005AE50-1005AE5D 0000D	*/
void cMagMeshObject::EnableAnimTextureLightMap(bool param_1) {
}

/* 1005AE60-1005B027 001C7	*/
void cMagMeshObject::AddAnimTextureLightMap(char* param_1) {
}

/* 1005B030-1005B03D 0000D	*/
void cMagMeshObject::SetAnimTextureLightMapFPS(int param_1) {
}

/* 1005B040-1005B10B 000CB	*/
void cMagMeshObject::AnimateLightMap() {
}

/* 1005B110-1005B11D 0000D	*/
void cMagMeshObject::EnableZBuffeWrite(bool param_1) {
}

/* 1005B120-1005B127 00007	*/
bool cMagMeshObject::EnableZBuffeWrite() {
	return 0;
}

/* 1005B130-1005B155 00025	*/
int cMagMeshObject::GetFaceCount() {
	return 0;
}

/* 1005B160-1005B16D 0000D	*/
void cMagMeshObject::EnableForceTransform(bool param_1) {
}

/* 1005B170-1005B188 00018	*/
void cMagMeshObject::SetForceTransformMatrix(uchar param_1) {
}

/* 1005B190-1005B1BB 0002B	*/
void cMagMeshObject::SetLightPosition(D3DXVECTOR3 param_1) {
}

/* 1005B1C0-1005B1D7 00017	*/
void cMagMeshObject::EnableLight(bool param_1) {
}

/* 1005B1E0-1005B206 00026	*/
void cMagMeshObject::SetMaterialDiffuse(float param_1, float param_2, float param_3, float param_4) {
}

/* 1005B210-1005B236 00026	*/
void cMagMeshObject::SetMaterialAmbient(float param_1, float param_2, float param_3, float param_4) {
}

/* 1005B240-1005B266 00026	*/
void cMagMeshObject::SetLightDiffuse(float param_1, float param_2, float param_3, float param_4) {
}

/* 1005B270-1005B296 00026	*/
void cMagMeshObject::SetLightAmbient(float param_1, float param_2, float param_3, float param_4) {
}

/* 1005B2A0-1005B2B7 00017	*/
void cMagMeshObject::EnableRenderShadow(bool param_1) {
}

/* 1005B2C0-1005B2D2 00012	*/
bool cMagMeshObject::EnableRenderShadow() {
	return 0;
}

/* 1005B2E0-1005B59A 002BA	*/
void cMagMeshObject::CreateBumpAndEnviromentTexture() {
}

/* 1005B5A0-1005B9A8 00408	*/
void cMagMeshObject::LoadLod(char* param_1) {
}

/* 1005B9B0-1005BB33 00183	*/
bool cMagMeshObject::_TestDistanceLOD(float param_1) {
	return 0;
}

/* 1005BB40-1005BF7E 0043E	*/
bool cMagMeshObject::CreateNavigationPath(char* param_1) {
	return 0;
}

/* 1005C280-1005C5B2 00332	*/
uint cMagMeshObject::BuildNaviPoints(uint param_1, uint param_2, uint param_3, uint param_4, uint param_5, uint param_6) {
	return 0;
}

/* 1005C610-1005C636 00026	*/
int cMagMeshObject::GetNaviPointsCount() {
	return 0;
}

/* 1005C640-1005C705 000C5	*/
uchar cMagMeshObject::GetNaviPointAt(uint* param_1, uint param_2) {
	return 0;
}

/* 1005C710-1005C7B5 000A5	*/
uchar cMagMeshObject::GotoRandomLocation(uint* param_1) {
	return 0;
}

