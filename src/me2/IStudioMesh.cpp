#include "IStudioMesh.h"

/* 10006C70-10006EC6 00256	*/
IStudioMesh::IStudioMesh(IStudioMesh* param_1) {
}

/* 10006ED0-100072E0 00410	*/
IStudioMesh* IStudioMesh::operator=(IStudioMesh* param_1) {
	return 0;
}

/* 100072E0-10007337 00057	*/
IStudioMesh* IStudioMesh::scalar_destructor(uchar param_1) {
	return 0;
}

/* 1005CF90-1005D0D3 00143	*/
IStudioMesh::IStudioMesh() {
}

/* 1005D0E0-1005D207 00127	*/
IStudioMesh::~IStudioMesh() {
}

/* 1005D210-1005D2B6 000A6	*/
bool IStudioMesh::LoadMesh(char* param_1, cMagMeshObject* param_2) {
	return 0;
}

/* 1005D2E0-1005D373 00093	*/
void IStudioMesh::LoadColTypeTexIni(char* param_1) {
}

/* 1005D380-1005D664 002E4	*/
void IStudioMesh::CreateColTypeTexIni(char* param_1) {
}

/* 1005D670-1005D67D 0000D	*/
void IStudioMesh::EnableAnimTexture(bool param_1) {
}

/* 1005D680-1005D697 00017	*/
void IStudioMesh::SetShadowType(int param_1) {
}

/* 1005D6A0-1005D6F1 00051	*/
void IStudioMesh::RenderMesh(D3DXMATRIX param_1) {
}

/* 1005D700-1005D70D 0000D	*/
void IStudioMesh::EnableRenderShadow(bool param_1) {
}

/* 1005D710-1005D717 00007	*/
bool IStudioMesh::EnableRenderShadow() {
	return 0;
}

/* 1005D720-1005D7C5 000A5	*/
void IStudioMesh::OnRenderShadow(D3DXMATRIX param_1) {
}

/* 1005D7D0-1005D848 00078	*/
void IStudioMesh::SetCullMode(int param_1) {
}

/* 1005D850-1005D8DD 0008D	*/
void IStudioMesh::SetAlpha(int param_1) {
}

/* 1005D8E0-1005D92B 0004B	*/
uint* IStudioMesh::GetHelperPosition(uint* param_1, uchar* param_2) {
	return 0;
}

/* 1005D930-1005D94E 0001E	*/
void IStudioMesh::UpdateMorfing() {
}

/* 1005D950-1005DA0A 000BA	*/
bool IStudioMesh::PlayMorfing() {
	return 0;
}

/* 1005DA10-1005DA1D 0000D	*/
void IStudioMesh::EnableMorph1(bool param_1) {
}

/* 1005DA20-1005DA41 00021	*/
void IStudioMesh::SetMorphData(int param_1, int param_2, float param_3) {
}

/* 1005DA50-1005DA5D 0000D	*/
void IStudioMesh::SetStepMorph(float param_1) {
}

/* 1005DA60-1005DA77 00017	*/
void IStudioMesh::SetStep(float param_1) {
}

/* 1005DA80-1005DA97 00017	*/
void IStudioMesh::EnableMorph(bool param_1) {
}

/* 1005DAA0-1005E05D 005BD	*/
void IStudioMesh::UpdateAnimation(D3DXMATRIX param_1) {
}

/* 1005E060-1005E410 003B0	*/
bool IStudioMesh::InitAnimSeq(char* param_1, int param_2, int param_3) {
	return 0;
}

/* 1005E410-1005E485 00075	*/
void IStudioMesh::SetAnimFreq(char* param_1, float param_2) {
}

/* 1005E490-1005E5F2 00162	*/
void IStudioMesh::PlayAnim(char* param_1) {
}

/* 1005E600-1005E763 00163	*/
void IStudioMesh::PlayAnim(char* param_1, int param_2) {
}

/* 1005E770-1005E872 00102	*/
void IStudioMesh::StopAnim(char* param_1) {
}

/* 1005E880-1005E8FA 0007A	*/
bool IStudioMesh::IsPlaying(char* param_1) {
	return 0;
}

/* 1005E900-1005E98A 0008A	*/
void IStudioMesh::DeleteAnimSeq(char* param_1) {
}

/* 1005E990-1005E9ED 0005D	*/
void IStudioMesh::DeleteAllAnimSeq() {
}

/* 1005E9F0-1005EA07 00017	*/
void IStudioMesh::EnableLight(bool param_1) {
}

/* 1005EA10-1005EA36 00026	*/
void IStudioMesh::SetMaterialDiffuse(float param_1, float param_2, float param_3, float param_4) {
}

/* 1005EA40-1005EA66 00026	*/
void IStudioMesh::SetMaterialAmbient(float param_1, float param_2, float param_3, float param_4) {
}

/* 1005EA70-1005EA96 00026	*/
void IStudioMesh::SetLightDiffuse(float param_1, float param_2, float param_3, float param_4) {
}

/* 1005EAA0-1005EAC6 00026	*/
void IStudioMesh::SetLightAmbient(float param_1, float param_2, float param_3, float param_4) {
}

/* 1005EAD0-1005EAE2 00012	*/
int IStudioMesh::GetFrameCount() {
	return 0;
}

/* 1005EAF0-1005EB02 00012	*/
int IStudioMesh::GetFaceCount() {
	return 0;
}

/* 1005EB10-1005EB2D 0001D	*/
void IStudioMesh::SetLightPosition(D3DXVECTOR3 param_1) {
}

/* 1005EB30-1005EE5E 0032E	*/
void IStudioMesh::ComputeBoundingBox(D3DXVECTOR3& param_1, D3DXVECTOR3& param_2) {
}

/* 1005EE60-1005EEC3 00063	*/
bool IStudioMesh::GetBoneMatrix(char* param_1, D3DXMATRIX& param_2, D3DXMATRIX& param_3) {
	return 0;
}

/* 1005EED0-1005EEE4 00014	*/
void IStudioMesh::EnableAnimKeys(bool param_1) {
}

/* 1005EEF0-1005EF07 00017	*/
void IStudioMesh::SetMeshType(int param_1) {
}

/* 1005EF10-1005EF3C 0002C	*/
void IStudioMesh::GetPerfCounter(_LARGE_INTEGER* param_1) {
}

