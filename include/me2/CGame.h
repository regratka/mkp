#ifndef _C_GAME
#define _C_GAME

#include <fstream>
#include <globals.h>

#include "cMagGameObject.h"
#include "CLevel.h"
#include "CLevelsManager.h"
#include "CMemoryManager.h"
#include "CExtendedParameterLoader.h"
#include "cMagSprite.h"
#include "CClientServerPlayer.h"
#include "CCPUTicker.h"

class CState;
class CClientServer;
class cMagGameObject;

struct JNIEnv_;


struct CGameTextureData {
	/* 0x00  */ char textureName[255];
	/* 0x100 */ int textureId;
	/* 0x104 */ int directTexture;
};

class DLLEXPORT CGame : public cMagGameObject {
public:
	/* 10091750 */ CGame();
	/* 10091CD0 */ CGame(HINSTANCE__* param_1);
	/* 10091EA0 */ ~CGame();
	/* 10092000 */ CLevel* CreateLevelObject(_iobuf* param_1);
	/* 100920C0 */ void SetLoadLevelBackground(char* param_1);
	/* 100920D0 */ void SetLoadLevelBackground(BOOL param_1);
	/* 10092130 */ void LoadLevel(char* param_1);
	/* 10092440 */ void LoadBackgroundSettings(char* param_1);
	/* 10092610 */ void SetProgressBarPos(D3DXVECTOR2 param_1);
	/* 10092670 */ void SetProgressBarBackgroundPos(D3DXVECTOR2 param_1);
	/* 100926D0 */ void Restore();
	/* 100926E0 */ void LoadLevel();
	/* 10092710 */ void ShowLoadLevelBackground();
	/* 100927D0 */ void UpdateProgress(float param_1);
	/* 10092800 */ void ShowProgressBar(bool param_1);
	/* 10092860 */ CLevel* LoadLevel_(char* param_1);
	/* 10092CC0 */ void OnLoadChunk(_ED_CHUNK param_1, FILE* param_2);
	/* 100932F0 */ void LoadMeshObject(_iobuf* param_1);
	/* 10093660 */ void LoadBaseMeshObject(_iobuf* param_1);
	/* 10093960 */ void LoadSun(_iobuf* param_1);
	/* 10093A90 */ IDirect3DTexture8* FindTexture(int param_1);
	/* 10093AD0 */ void LoadFlare(_iobuf* param_1);
	/* 10093DE0 */ void LoadTerrain(_iobuf* param_1);
	/* 100940F0 */ void LoadSky_Old(_iobuf* param_1);
	/* 10094220 */ void LoadSky(_iobuf* param_1);
	/* 10094460 */ void LoadLight(_iobuf* param_1, _ED_CHUNK param_2);
	/* 10094660 */ void CreateDLLFunctionName(_iobuf* param_1, char* param_2, char* param_3);
	/* 10094760 */ void ClearLevel();
	/* 10094890 */ void LoadFog(_iobuf* param_1);
	/* 100949B0 */ void LoadEDCameraProperties(_iobuf* param_1);
	/* 10094A20 */ void LoadBillboard(_iobuf* param_1);
	/* 10094C00 */ void LoadMeshExtension(_ED_CHUNK param_1, _iobuf* param_2);
	/* 10094E40 */ CLevel* GetActiveLevel();
	/* 10094E50 */ void ActivateLevel();
	/* 10094FC0 */ void LinkMeshToSectorMesh();
	/* 10095090 */ void Statistics();
	/* 10095130 */ void ClearList();
	/* 100957D0 */ MagTerrain* GetTerrain();
	/* 100957E0 */ void AddCollisionObject(cMagMeshObject* param_1);
	/* 10095860 */ void RemoveCollisionObject(cMagMeshObject* param_1);
	/* 10095880 */ bool Initialize(HINSTANCE__* param_1, bool param_2, int param_3, int param_4, int param_5, char* param_6, char* param_7, bool param_8);
	/* 10095910 */ void StartServer();
	/* 10095A10 */ void StartClient();
	/* 10095B10 */ void LoadPhysicsCollision(_ED_CHUNK param_1, _iobuf* param_2, int param_3);
	/* 10095D80 */ char* GetLevelDirectory();
	/* 10095D90 */ char* GetLevelFileName();
	/* 10095E40 */ void LoadPathProperties(_ED_CHUNK param_1, _iobuf* param_2);
	/* 10095FD0 */ void LoadPatrolPoint(cMagMeshObject* param_1, _ED_CHUNK param_2, _iobuf* param_3);
	/* 10096190 */ ulong GetFreeMemory();
	/* 100961B0 */ void LoadPortalExt(_ED_CHUNK param_1);
	/* 10096510 */ void ConvertPortals();
	/* 100966F0 */ void LoadLevelStatistics();
	/* 10096710 */ void OnPercentageLoadLevel(float param_1, int param_2);
	/* 10096750 */ void UpdateStatistics();
	/* 100967A0 */ void LoadSplineCamera();
	/* 10096A10 */ void InitializeJVM(HINSTANCE__* param_1, bool param_2, int param_3, int param_4, int param_5, char* param_6, JNIEnv_* param_7);
	/* 10096B90 */ void LoadJavaMeshExtension(_ED_CHUNK param_1, cMagMeshObject* param_2);
	/* 10096BC0 */ void Clean();
	/* 10096C00 */ void FrameTime();
	/* 10096C60 */ float GetFrameTime();
	/* 10096C70 */ void LoadTextureProperties(_ED_CHUNK param_1);
	/* 100970A0 */ void LoadRenderOptions(_ED_CHUNK param_1);
	/* 100972F0 */ void LoadSectorsList(_iobuf* param_1);
	/* 100974F0 */ void LoadParent(_ED_CHUNK param_1);
	/* 100975E0 */ void LinkObjects();
	/* 100976B0 */ void LoadTrack();
	/* 10097720 */ void PausePhysics(bool param_1);
	/* 10097840 */ void _PausePhysics(bool param_1);
	/* 10097860 */ CState* CreateState(char* param_1);
	/* 100978A0 */ void ReadSettingsClientServer(char* param_1);
	/* 10097AB0 */ void SetServerName(char* param_1);
	/* 10097AE0 */ void SetPlayerName(char* param_1);
	/* 10097B10 */ void SetIP(char* param_1);
	/* 10097B40 */ void SetPort(char* param_1);
	/* 10097B60 */ void MULTIPLAY_CreateClientPalayer();
	/* 10097C70 */ void MULTIPLAY_SetPosition(D3DXVECTOR3 param_1, D3DXVECTOR3 param_2);
	/* 10097CC0 */ void MULTIPLAY_CreateServerPalayer();
	/* 10097DD0 */ void MULTIPLAY_SetServerPosition(D3DXVECTOR3 param_1, D3DXVECTOR3 param_2);
	/* 10097E20 */ void MULTIPLAY_SetServerStateIdle(D3DXVECTOR3 param_1, D3DXVECTOR3 param_2);
	/* 10097E70 */ void MULTIPLAY_SetClientStateIdle(D3DXVECTOR3 param_1, D3DXVECTOR3 param_2);
	/* 10097EC0 */ CClientServer* GetClientServer();
	/* 100C97D0 */ cMagGameObject* JLoadMesh(char* param_1);

public:
	/* 0xd10  */ CExtendedParameterLoader* parameterLoader;
	/* 0xd14  */ uchar f_d14[0xd24-0xd14];
	/* 0xd24  */ char* loadLevelBackground;
	/* 0xd28  */ D3DXVECTOR2 progressBarPos;
	/* 0xd30  */ D3DXVECTOR2 backgroundPos;
	/* 0xd38  */ BOOL loadedProgressBar;
	/* 0xd3c  */ BOOL loadedProgressBackground;
	/* 0xd40  */ int unkn_d40;
	/* 0xd44  */ int unkn_d44;
	/* 0xd48  */ uchar f_d48[0xe30-0xd48];
	/* 0xe30  */ CCPUTicker ticker;
	/* 0x1168 */ cMagSprite* magSprite;
	/* 0x116c */ MagTerrain* terrain;
	/* 0x1170 */ cMagKernel* unkn_1170;
	/* 0x1174 */ D3DXVECTOR3 cameraProperty1;
	/* 0x1180 */ CLevel* activeLevel;
	/* 0x1184 */ CLevelsManager* levelsManager;
	/* 0x1188 */ std::vector<CGameTextureData*> texturesData;
	/* 0x1198 */ cMagLog log;
	/* 0x11a0 */ char unkn_11a0[256];
	/* 0x12a0 */ char levelDirectory[256];
	/* 0x13a0 */ char levelPath[256];
	/* 0x14a0 */ std::ifstream fileStream;
	/* 0x1530 */ int loadedObjects;
	/* 0x1534 */ int memoryUsage;
	/* 0x1538 */ uchar unkn_1538[40];
	/* 0x1560 */ char exeFilename[300];
	/* 0x168c */ float lastTickCount;
	/* 0x1690 */ float m_frameTime;
	/* 0x1694 */ CMemoryManager memoryManager;
	/* 0x16bc */ CClientServer* clientServer;
	/* 0x16c0 */ bool isClient;
	/* 0x16c1 */ bool isServer;
	/* 0x16c4 */ int serverPort;
	/* 0x16c8 */ char playerName[256];
	/* 0x17c8 */ uchar f_17c8[0x17cc-0x17c8];
	/* 0x17cc */ char serverIP[256];
	/* 0x18cc */ uchar f_18cc[0x18d0-0x18cc];
	/* 0x18d0 */ char serverSessionName[256];
	/* 0x19d0 */ uchar f_19d0[0x19d4-0x19d0];
	/* 0x19d4 */ CClientServerPlayer* clientPlayer; 
	/* 0x19d8 */ CClientServerPlayer* serverPlayer; 
	/* 0x19dc */ uchar f_19dc[0x19f0-0x19dc];
private:
	static UINT_PTR TIMER_PTR;
	static bool CLEANED_CALL_METHODS;
};

STATIC_ASSERT(sizeof(CGame) == 0x19f0);

#endif