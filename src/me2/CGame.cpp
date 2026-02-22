#include "CGame.h"

/* 10018FB0-10019941 00991	*/
CGame::CGame(CGame* param_1) {
}

/* 10019B10-1001A5D8 00AC8	*/
CGame* CGame::operator=(CGame* param_1) {
	return 0;
}

/* 10091750-10091CA9 00559	*/
CGame::CGame() {
}

/* 10091CD0-10091E99 001C9	*/
CGame::CGame(HINSTANCE__* param_1) {
}

/* 10091EA0-10091FFE 0015E	*/
CGame::~CGame() {
}

/* 10092000-100920B7 000B7	*/
CLevel* CGame::CreateLevelObject(_iobuf* param_1) {
	return 0;
}

/* 100920C0-100920CD 0000D	*/
void CGame::SetLoadLevelBackground(char* param_1) {
}

/* 100920D0-1009212D 0005D	*/
void CGame::SetLoadLevelBackground(int param_1) {
}

/* 10092130-100922A3 00173	*/
void CGame::LoadLevel(char* param_1) {
}

/* 10092440-10092610 001D0	*/
void CGame::LoadBackgroundSettings(char* param_1) {
}

/* 10092610-1009266A 0005A	*/
void CGame::SetProgressBarPos(D3DXVECTOR2 param_1) {
}

/* 10092670-100926CD 0005D	*/
void CGame::SetProgressBarBackgroundPos(D3DXVECTOR2 param_1) {
}

/* 100926D0-100926E0 00010	*/
void CGame::Restore() {
}

/* 100926E0-10092702 00022	*/
void CGame::LoadLevel() {
}

/* 10092710-100927C5 000B5	*/
void CGame::ShowLoadLevelBackground() {
}

/* 100927D0-100927FE 0002E	*/
void CGame::UpdateProgress(float param_1) {
}

/* 10092800-10092859 00059	*/
void CGame::ShowProgressBar(bool param_1) {
}

/* 10092860-10092CBC 0045C	*/
CLevel* CGame::LoadLevel_(char* param_1) {
	return 0;
}

/* 10092CC0-100932E4 00624	*/
void CGame::OnLoadChunk(_ED_CHUNK param_1, _iobuf* param_2) {
}

/* 100932F0-10093657 00367	*/
void CGame::LoadMeshObject(_iobuf* param_1) {
}

/* 10093660-1009395A 002FA	*/
void CGame::LoadBaseMeshObject(_iobuf* param_1) {
}

/* 10093960-10093A89 00129	*/
void CGame::LoadSun(_iobuf* param_1) {
}

/* 10093A90-10093AC8 00038	*/
IDirect3DTexture8* CGame::FindTexture(int param_1) {
	return 0;
}

/* 10093AD0-10093DD5 00305	*/
void CGame::LoadFlare(_iobuf* param_1) {
}

/* 10093DE0-100940E1 00301	*/
void CGame::LoadTerrain(_iobuf* param_1) {
}

/* 100940F0-10094213 00123	*/
void CGame::LoadSky_Old(_iobuf* param_1) {
}

/* 10094220-1009445E 0023E	*/
void CGame::LoadSky(_iobuf* param_1) {
}

/* 10094460-1009465A 001FA	*/
void CGame::LoadLight(_iobuf* param_1, _ED_CHUNK param_2) {
}

/* 10094660-10094760 00100	*/
void CGame::CreateDLLFunctionName(_iobuf* param_1, char* param_2, char* param_3) {
}

/* 10094760-1009488D 0012D	*/
void CGame::ClearLevel() {
}

/* 10094890-100949A6 00116	*/
void CGame::LoadFog(_iobuf* param_1) {
}

/* 100949B0-10094A1D 0006D	*/
void CGame::LoadEDCameraProperties(_iobuf* param_1) {
}

/* 10094A20-10094BFB 001DB	*/
void CGame::LoadBillboard(_iobuf* param_1) {
}

/* 10094C00-10094E38 00238	*/
void CGame::LoadMeshExtension(_ED_CHUNK param_1, _iobuf* param_2) {
}

/* 10094E40-10094E47 00007	*/
CLevel* CGame::GetActiveLevel() {
	return 0;
}

/* 10094E50-10094FB3 00163	*/
void CGame::ActivateLevel() {
}

/* 10094FC0-1009508D 000CD	*/
void CGame::LinkMeshToSectorMesh() {
}

/* 10095090-1009512D 0009D	*/
void CGame::Statistics() {
}

/* 10095130-10095775 00645	*/
void CGame::ClearList() {
}

/* 100957D0-100957D7 00007	*/
MagTerrain* CGame::GetTerrain() {
	return 0;
}

/* 100957E0-10095847 00067	*/
void CGame::AddCollisionObject(cMagMeshObject* param_1) {
}

/* 10095860-10095873 00013	*/
void CGame::RemoveCollisionObject(cMagMeshObject* param_1) {
}

/* 10095880-10095908 00088	*/
bool CGame::Initialize(HINSTANCE__* param_1, bool param_2, int param_3, int param_4, int param_5, char* param_6, char* param_7, bool param_8) {
	return 0;
}

/* 10095910-10095A07 000F7	*/
void CGame::StartServer() {
}

/* 10095A10-10095B07 000F7	*/
void CGame::StartClient() {
}

/* 10095B10-10095D71 00261	*/
void CGame::LoadPhysicsCollision(_ED_CHUNK param_1, _iobuf* param_2, int param_3) {
}

/* 10095D80-10095D87 00007	*/
char* CGame::GetLevelDirectory() {
	return 0;
}

/* 10095D90-10095E3E 000AE	*/
char* CGame::GetLevelFileName() {
	return 0;
}

/* 10095E40-10095FCA 0018A	*/
void CGame::LoadPathProperties(_ED_CHUNK param_1, _iobuf* param_2) {
}

/* 10095FD0-10096186 001B6	*/
void CGame::LoadPatrolPoint(cMagMeshObject* param_1, _ED_CHUNK param_2, _iobuf* param_3) {
}

/* 10096190-100961AE 0001E	*/
ulong CGame::GetFreeMemory() {
	return 0;
}

/* 100961B0-10096508 00358	*/
void CGame::LoadPortalExt(_ED_CHUNK param_1) {
}

/* 10096510-100966EC 001DC	*/
void CGame::ConvertPortals() {
}

/* 100966F0-10096705 00015	*/
void CGame::LoadLevelStatistics() {
}

/* 10096710-1009674C 0003C	*/
void CGame::OnPercentageLoadLevel(float param_1, int param_2) {
}

/* 10096750-1009679D 0004D	*/
void CGame::UpdateStatistics() {
}

/* 100967A0-10096A10 00270	*/
void CGame::LoadSplineCamera() {
}

/* 10096A10-10096B8C 0017C	*/
void CGame::InitializeJVM(HINSTANCE__* param_1, bool param_2, int param_3, int param_4, int param_5, char* param_6, JNIEnv_* param_7) {
}

/* 10096B90-10096BB7 00027	*/
void CGame::LoadJavaMeshExtension(_ED_CHUNK param_1, cMagMeshObject* param_2) {
}

/* 10096BC0-10096BF2 00032	*/
void CGame::Clean() {
}

/* 10096C00-10096C56 00056	*/
void CGame::FrameTime() {
}

/* 10096C60-10096C67 00007	*/
float CGame::GetFrameTime() {
	return 0;
}

/* 10096C70-1009709F 0042F	*/
void CGame::LoadTextureProperties(_ED_CHUNK param_1) {
}

/* 100970A0-100972E8 00248	*/
void CGame::LoadRenderOptions(_ED_CHUNK param_1) {
}

/* 100972F0-100974E1 001F1	*/
void CGame::LoadSectorsList(_iobuf* param_1) {
}

/* 100974F0-100975DF 000EF	*/
void CGame::LoadParent(_ED_CHUNK param_1) {
}

/* 100975E0-100976A5 000C5	*/
void CGame::LinkObjects() {
}

/* 100976B0-1009771D 0006D	*/
void CGame::LoadTrack() {
}

/* 10097720-10097762 00042	*/
void CGame::PausePhysics(bool param_1) {
}

/* 10097840-10097857 00017	*/
void CGame::_PausePhysics(bool param_1) {
}

/* 10097860-10097895 00035	*/
CState* CGame::CreateState(char* param_1) {
	return 0;
}

/* 100978A0-10097AAF 0020F	*/
void CGame::ReadSettingsClientServer(char* param_1) {
}

/* 10097AB0-10097ADE 0002E	*/
void CGame::SetServerName(char* param_1) {
}

/* 10097AE0-10097B0E 0002E	*/
void CGame::SetPlayerName(char* param_1) {
}

/* 10097B10-10097B3E 0002E	*/
void CGame::SetIP(char* param_1) {
}

/* 10097B40-10097B5A 0001A	*/
void CGame::SetPort(char* param_1) {
}

/* 10097B60-10097C66 00106	*/
void CGame::MULTIPLAY_CreateClientPalayer() {
}

/* 10097C70-10097CB4 00044	*/
void CGame::MULTIPLAY_SetPosition(D3DXVECTOR3 param_1, D3DXVECTOR3 param_2) {
}

/* 10097CC0-10097DC6 00106	*/
void CGame::MULTIPLAY_CreateServerPalayer() {
}

/* 10097DD0-10097E14 00044	*/
void CGame::MULTIPLAY_SetServerPosition(D3DXVECTOR3 param_1, D3DXVECTOR3 param_2) {
}

/* 10097E20-10097E64 00044	*/
void CGame::MULTIPLAY_SetServerStateIdle(D3DXVECTOR3 param_1, D3DXVECTOR3 param_2) {
}

/* 10097E70-10097EB4 00044	*/
void CGame::MULTIPLAY_SetClientStateIdle(D3DXVECTOR3 param_1, D3DXVECTOR3 param_2) {
}

/* 10097EC0-10097EC7 00007	*/
CClientServer* CGame::GetClientServer() {
	return 0;
}

/* 100C97D0-100C97D5 00005	*/
cMagGameObject* CGame::JLoadMesh(char* param_1) {
	return 0;
}

