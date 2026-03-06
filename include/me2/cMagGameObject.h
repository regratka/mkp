#ifndef C_MAG_GAME_OBJECT
#define C_MAG_GAME_OBJECT

#include <globals.h>
#include <Windows.h>
#include <vector>
#include <CMATH>

#include "cMagObjectList.h"
#include "MagGrid.h"

typedef long (*renderCallback) ();

class CGame;
class MagTerrain;
class CLensFlare;
class cMagSun;
class cMagSkyBox;
class cMagFog;
class CCamera;
class CSoundManager;
class CState;
class Mesh;

struct _LIGHT;

class __declspec(dllexport) cMagGameObject : public cMagObjectList {
public:
	/* 10002260-100022A0 00040	*/
	void SetLevelDirectory(char* param_1) {
		strcpy(levelDirectory, param_1);
		char* lastSlash = strrchr(levelDirectory, '\\');
		if (lastSlash != NULL) {
			*lastSlash = '\0';
		}
	}

	/* 100022A0-100022A7 00007	*/
	D3DXMATRIX& GetViewMatrix() {
		return viewMatrix;
	}

	/* 100022B0-100022B7 00007	*/
	D3DXMATRIX& GetProjMatrix() {
		return projectionMatrix;
	}

	/* 100022C0-100022C7 00007	*/
	virtual bool GetStatusRemoveObject() {
		return removeObject;
	}

	/* 100022D0-100022DD 0000D	*/
	virtual void RemoveObject(bool param_1) {
		removeObject = param_1;
	}

	/* 100022E0-100022E7 00007	*/
	float GetClipNear() {
		return nearPlane;
	}

	/* 100022F0-100022F7 00007	*/
	float GetClipFar() {
		return farPlane;
	}

	/* 10002300-1000230D 0000D	*/
	float cMagGameObject::GpgDegToRad(float param_1) {
		return param_1 * (D3DX_PI / 180.0f);
	}

	/* 10024C60 */ cMagGameObject();
	/* 10024F40 */ ~cMagGameObject();
	/* 10025020 */ void SetWindowTitle(char* param_1);
	/* 10025050 */ long InitD3D(HWND__* param_1);
	/* 10025440 */ void Cleanup();
	/* 10025550 */ long AppInit(HINSTANCE__* param_1, bool param_2);
	/* 100258C0 */ void SetDeviceMode(int param_1, int param_2);
	/* 10025AB0 */ bool InitWindow(int param_1, int param_2, int param_3, bool param_4, HINSTANCE__* param_5, WNDPROC param_6, char* param_7);
	/* 10025C70 */ void UpdateMagWindowSize(int param_1, int param_2);
	/* 10025C90 */ void ShowGameCursor(bool param_1);
	/* 10025CB0 */ bool EnableGameCursor();
	/* 10025CC0 */ void RenderGameCursor();
	/* 10025CF0 */ long MsgProc(HWND param_1, uint param_2, uint param_3, long param_4);
	/* 10025F40 */ bool KillWindowDx();
	/* 10025FA0 */ bool HandleMessages();
	/* 10026000 */ bool Run();
	/* 10026090 */ bool CreateWinDx(HINSTANCE__* param_1, bool param_2, int param_3, int param_4, int param_5, char* param_6, bool param_7);
	/* 10026150 */ void ClearInputKey();
	/* 100261A0 */ void OnPreRenderEdytor();
	/* 100261E0 */ void OnPreRender();
	/* 10026300 */ void OnPostRender();
	/* 10026330 */ bool Render();
	/* 100266A0 */ void RenderScene();
	/* 10026790 */ void RestoreScene();
	/* 10026B70 */ void CallHandlerOnUpdate_();
	/* 10026C90 */ void CallOnUpdateMenuSettings();
	/* 10026D10 */ void CallAllHandler(uchar* param_1, float param_2, float param_3, bool param_4, bool param_5);
	/* 10027020 */ void CreateObject(cMagKernel* param_1);
	/* 10027330 */ void CameraLookAt(float param_1, float param_2, float param_3, float param_4, float param_5, float param_6, float param_7, float param_8, float param_9);
	/* 100273C0 */ void Fps();
	/* 10027450 */ void ShowFPS(bool param_1);
	/* 10027470 */ uint TestViewObjest();
	/* 10027630 */ void VectorToScreen();
	/* 100276E0 */ void DrawTexts(uchar param_1, uchar param_2, uchar param_3, uchar param_4, uchar param_5);
	/* 100278A0 */ void DrawObjectName();
	/* 10027A40 */ void GpgFrustum(double param_1, double param_2, double param_3, double param_4, double param_5, double param_6);
	/* 10027AE0 */ void GpgPerspective(double param_1, double param_2, double param_3, double param_4, int param_5);
	/* 10027DC0 */ long ScreenGrab(uchar param_1, char* param_2);
	/* 10027F50 */ long RenderTiled(char* param_1, IDirect3DDevice8* param_2, int param_3, renderCallback param_4);
	/* 10028240 */ void SetLastRender(cMagMeshObject* param_1);
	/* 100282F0 */ void swapObject(int param_1, int param_2);
	/* 10028320 */ void swap(int* param_1, int* param_2);
	/* 10028340 */ void qsort(int* param_1, int param_2, int param_3);
	/* 10028400 */ void SortObject();
	/* 10028D70 */ void QSortMeshObject(int* param_1, int param_2, int param_3);
	/* 10028E30 */ void swapMeshObject(int param_1, int param_2);
	/* 10028E60 */ void ShowObjectName(bool param_1);
	/* 10028E80 */ void SetDataPath(char* param_1);
	/* 10028EA0 */ uchar GetGame();
	/* 10028EB0 */ void SetGame(CGame* param_1);
	/* 10028EC0 */ void SetClipNear(float param_1);
	/* 10028ED0 */ void SetClipFar(float param_1);
	/* 10028EE0 */ int GetWindowHeight();
	/* 10028EF0 */ int GetWindowWidth();
	/* 10028F00 */ uint* GetTextureMgr(uint* param_1);
	/* 10029010 */ void AllFiltersTexture();
	/* 10029040 */ uchar ReplaceTexture(char* param_1, char* param_2);
	/* 10029060 */ void DeleteTexture(char* param_1);
	/* 10029080 */ void ShowGird(bool param_1);
	/* 100290A0 */ IDirect3DDevice8* GetEngine();
	/* 100290B0 */ float GetFOV();
	/* 100290C0 */ void SetFOV(float param_1);
	/* 100290D0 */ void DrawTextA(int param_1, int param_2, char* param_3);
	/* 10029120 */ cMagKernel* GetMeshObject(char* param_1);
	/* 100291D0 */ cMagMeshObject* GetMeshObject(int param_1);
	/* 10029230 */ uint GetObjectsInRadiusFromClass(float param_1, float param_2, float param_3, float param_4, uchar* param_5);
	/* 10029300 */ uint GetObjectsInRadiusFromClass(float param_1, float param_2, float param_3, float param_4, void* param_5, int param_6);
	/* 10029550 */ cMagKernel* MagGetObject(char* param_1);
	/* 100296C0 */ void GetKokoPos(uint param_1, uint param_2, uint param_3);
	/* 100296F0 */ void SetVisibilityRange(float param_1);
	/* 10029710 */ float GetVisibilityRange();
	/* 10029720 */ void SetSurfaceVisibilityRange(float param_1);
	/* 10029740 */ float GetSurfaceVisibilityRange();
	/* 10029750 */ HWND__* GetHandleWindow();
	/* 10029760 */ bool DestroyObject(cMagKernel* param_1);
	/* 10029800 */ bool DeleteMesh(cMagKernel* param_1);
	/* 10029890 */ bool DeleteBillboard(cMagKernel* param_1);
	/* 10029920 */ bool DeleteCamera(cMagKernel* param_1);
	/* 100299B0 */ bool DeleteParticle(cMagKernel* param_1);
	/* 10029A40 */ bool DeleteTerrain(cMagKernel* param_1);
	/* 10029A90 */ bool DeleteLensFlare(cMagKernel* param_1);
	/* 10029AE0 */ bool DeleteSun(cMagKernel* param_1);
	/* 10029B30 */ bool DeleteSky(cMagKernel* param_1);
	/* 10029B80 */ MagTerrain* GetTerrain();
	/* 10029B90 */ CLensFlare* GetLensFlare();
	/* 10029BA0 */ cMagSun* GetSun();
	/* 10029BB0 */ cMagSkyBox* GetSky();
	/* 10029BC0 */ cMagFog* GetFog();
	/* 10029BD0 */ void ClearTextures();
	/* 10029BE0 */ void EnableSkyRendering(bool param_1);
	/* 10029C10 */ void EnableSunRendering(bool param_1);
	/* 10029C40 */ void EnableLensFlareRendering(bool param_1);
	/* 10029C70 */ void EnableFog(bool param_1);
	/* 10029CA0 */ void ExitGame();
	/* 10029CB0 */ float GetDistanceTo(char* param_1, D3DXVECTOR3 param_2);
	/* 10029D60 */ float GetDistanceTo(D3DXVECTOR3 param_1);
	/* 10029DC0 */ void GetDistanceTo(char* param_1, D3DXVECTOR3 param_2, std::vector<float>* param_3);
	/* 1002A000 */ long RenderTiled(char* param_1, IDirect3DDevice8* param_2, int param_3);
	/* 1002A3A0 */ long ScaleRender();
	/* 1002A6D0 */ void AddLight(_LIGHT* param_1);
	/* 1002A6F0 */ void ClearMeshList();
	/* 1002A700 */ void SetActiveCamera(CCamera* param_1);
	/* 1002A730 */ CCamera* GetActiveCamera();
	/* 1002A740 */ void UpdateActiveCamera();
	/* 1002A7E0 */ void RenderActiveCamera();
	/* 1002A810 */ D3DXVECTOR3 RotateVector(D3DXVECTOR3* param_1, D3DXVECTOR3* param_2, float param_4);
	/* 1002A870 */ char* GetLevelDirectory();
	/* 1002A880 */ void SetMagWindowTitle(char* param_1);
	/* 1002A8A0 */ void DXDiags();
	/* 1002AA40 */ bool InitMusicManager();
	/* 1002AB10 */ void DestroyMusicManager();
	/* 1002AB50 */ uchar GetMusicManager();
	/* 1002AB60 */ bool InitSoundManager();
	/* 1002AC10 */ void DestroySoundManager();
	/* 1002AC40 */ CSoundManager* GetSoundManager();
	/* 1002AC50 */ void MememberPlayerObject(cMagMeshObject* param_1);
	/* 1002AC70 */ cMagMeshObject* GetPlayerObject();
	/* 1002AC80 */ void EnableLinkMeshToSector(bool param_1);
	/* 1002ACA0 */ bool EnableLinkMeshToSector();
	/* 1002ACB0 */ void LinkMeshToSector();
	/* 1002ACC0 */ bool InSector(D3DXVECTOR3 param_1, D3DXVECTOR3 param_2, D3DXVECTOR3 param_3);
	/* 1002AD30 */ void SetState(char* param_1);
	/* 1002AE30 */ void SetState(CState* param_1);
	/* 1002AEE0 */ int GetAllFaceCount();
	/* 1002AF20 */ void CreateDxFont();
	/* 1002B280 */ void EnableCallHandlerWindowKey(cMagGameObject* param_1);
	/* 1002B2A0 */ void EnableHandlerOnFrame1(cMagGameObject* param_1);
	/* 1002B2C0 */ void DrawBigSquareShadow();
	/* 1002B570 */ void CreateBigSquareShadow();
	/* 1002B700 */ void EnableBigSquareShadow(bool param_1);
	/* 1002B710 */ long CreateTextureFromFileInZip(IDirect3DDevice8 * param_1, char* param_2, char* param_3, IDirect3DTexture8** param_4);
	/* 1005A5F0 */ void AddLightmapMesh(Mesh* param_1, char* param_2);
	/* 1006CED0 */ ulong GetDXVersion();
	/* 1009CC10 */ uint FUN_1009cc10(char* param_1);
	/* 1009DF70 */ int CreateObject(char* param_1);

private:
	/* 0x2e0 */ cMagGameObject* levelObject;

	/* 0x2e4 */ uchar f_2e4[0x2f4-0x2e4];

	/* 0x2f4 */ char levelDirectory[300];
	/* 0x420 */ char windowTitle[254];

	/* 0x51e */ uchar f_51e[0x53c-0x51e];

	/* 0x53c */ MSG msg;

	/* 0x558 */ uchar f_558[0x62c-0x558];
	
	/* 0x62c */ HINSTANCE hInstance;
	/* 0x630 */ HWND hWnd;
	/* 0x634 */ HDC hdc;
	/* 0x638 */ int windowWidth;
	/* 0x63c */ int windowHeight;
	/* 0x640 */ int rgbChannels;
	/* 0x644 */ bool enableFullscreen;

	/* 0x645 */ uchar f_645[0x784-0x645];

	/* 0x784 */ D3DDISPLAYMODE displayMode;

	/* 0x794 */ uchar f_794[0x7a4-0x794];

	/* 0x7a4 */ D3DPRESENT_PARAMETERS presentParameters;
	/* 0x7d8 */ IDirect3D8* direct3D;
	/* 0x7dc */ IDirect3DDevice8* device3D;

	/* 0x7e0 */ uchar f_7e0[0x8a0-0x7e0];

	/* 0x8a0 */ D3DLIGHT8 light;

	/* 0x908 */ uchar f_908[0x9dc-0x908];

	/* 0x9dc */ bool showCursor;

	/* 0x9dd */ uchar f_9dd[0x9e0-0x9dd];

	/* 0x9e0 */ D3DXMATRIX projectionMatrix;
	/* 0xa20 */ D3DXMATRIX viewMatrix;

	/* 0xa60 */ uchar f_a60[0xb00-0xa60];

	/* 0xb00 */ bool removeObject;

	/* 0xb01 */ uchar f_b01[0xb08-0xb01];

	/* 0xb08 */ MagGrid* grid;

	/* 0xb0c */ uchar f_b0c[0xb24-0xb0c];

	/* 0xb24 */ uint backBufferHeight;
	/* 0xb28 */ uint backBufferWidth;

	/* 0xb2c */ uchar f_b2c[0xbf8-0xb2c];

	/* 0xbf8 */ float nearPlane;
	/* 0xbfc */ float farPlane;

	/* 0xc00 */ uchar f_c00[0xcf8-0xc00];
	/* 0xcf8 */ cMagGameObject* f_cf8;
	/* 0xcfc */ uchar f_cfc[0xd10-0xcfc];

private:
	static D3DPRESENT_PARAMETERS PRESENT_PARAMETERS;
};

STATIC_ASSERT(sizeof(cMagGameObject) == 0xd10);

#endif