#include "cMagGameObject.h"
#include "algorithm"

#include "CGame.h"

#include "cMagEngineMgr.h"

#include "CCamera.h"
#include "cMagSprite.h"
#include "cMagMeshObject.h"

#include "CMagFog.h"
#include "cMagBillboard.h"
#include "cMagCamera.h"
#include "CParticleEmitter.h"
#include "MagTerrain.h"
#include "CLensFlare.h"
#include "cMagSun.h"
#include "cMagSkyBox.h"

/* 10024C60-10024F31 002D1	*/
cMagGameObject::cMagGameObject() {

	levelObject = NULL;
	SetObjectName("No name");
	SetClassName("cMagGameObject");
	strcpy(windowTitle, "MagnumEngine ver 2.0");
	removeObject = false;
	nearPlane = 10.0f;
	farPlane = 550000.0f;
	D3DXMatrixIdentity(&projectionMatrix);
	D3DXMatrixIdentity(&viewMatrix);

}

/* 10024F40-10025018 000D8	*/
cMagGameObject::~cMagGameObject() {
	DebugLog("cMagGameObject::~cMagGameObject");
}

/* 10025020-1002504E 0002E	*/
void cMagGameObject::SetWindowTitle(char* param_1) {
	strcpy(windowTitle, param_1);
}

/* 10025050-1002543E 003EE	*/
long cMagGameObject::InitD3D(HWND__* param_1) {
	DeleteLog();
	FileLog("[--- Magnum Engine ver 2.0 ---]");
	FileLog("--- Begin CreateDevice3D ... ");
	direct3D = Direct3DCreate8(D3D_SDK_VERSION);
	if (direct3D == NULL) {
		CrashLog("Direct3DCreate8... (error)");
		return E_FAIL;
	}
	D3DDISPLAYMODE displayMode;
	HRESULT result = direct3D->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &displayMode);
	if (result < NO_ERROR) {
		CrashLog("GetAdapterDisplayMode... (error)");
		return E_FAIL;
	}
	backBufferWidth = 800;
	backBufferHeight = 600;
	ZeroMemory(&presentParameters, sizeof(D3DPRESENT_PARAMETERS));
	presentParameters.BackBufferWidth = 800;
	presentParameters.BackBufferFormat = displayMode.Format;
	presentParameters.BackBufferCount = 1;
	presentParameters.Windowed = TRUE;
	presentParameters.SwapEffect = D3DSWAPEFFECT_DISCARD;
	presentParameters.EnableAutoDepthStencil = TRUE;
	presentParameters.AutoDepthStencilFormat = D3DFMT_D16;
	presentParameters.BackBufferHeight = 600;

	result = direct3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, param_1, 0x20, &presentParameters, &device3D);
	if (result < NO_ERROR) {
		magLog.CrashLog( "InitD3D CreateDevice... (error)");
		return E_FAIL;
	}
	cMagEngineMgr::getInstance()->engine = device3D;
	cMagEngineMgr::getInstance()->gameObject = this;
	cMagEngineMgr::getInstance()->CreateFrustumCull();

	D3DMATERIAL8 material;
	ZeroMemory(&material, sizeof(D3DMATERIAL8));
	material.Specular.r = 0.0f;
	material.Specular.g = 0.0f;
	material.Specular.b = 0.0f;
	material.Diffuse.r = 1.0f;
	material.Diffuse.g = 1.0f;
	material.Diffuse.b = 1.0f;
	material.Ambient.r = 0.25f;
	material.Ambient.g = 0.25f;
	material.Ambient.b = 0.25f;
	cMagEngineMgr::getInstance()->engine->SetMaterial(&material);
	cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_AMBIENT, D3DCOLOR_ARGB(0xff, 0x3f, 0x3f, 0x3f));

	ZeroMemory(&light, sizeof(D3DLIGHT8));
	light.Diffuse.b = 0.25f;
	light.Diffuse.g = 0.25f;
	light.Diffuse.r = 0.25f;
	D3DVECTOR lightDir =  {0.0f, 0.0f, -1.0f};
	light.Direction = lightDir;
	light.Type = D3DLIGHT_DIRECTIONAL;
	D3DVECTOR lightPos = {0.0f, 0.0f, 0.0f};
	light.Position = lightPos;
	light.Range = 10000.0f;

	cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_DITHERENABLE, FALSE);
	cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_SPECULARENABLE, FALSE);
	cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_SHADEMODE, D3DSHADE_GOURAUD);
	cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_LIGHTING, TRUE); 
	cMagEngineMgr::getInstance()->engine->SetLight(0, &light);

	float shaderConstant[4] = {0.0f, 0.0f, 1.0f, 0.0f};
	cMagEngineMgr::getInstance()->engine->SetVertexShaderConstant(1, shaderConstant, 1);
	IDirect3DSurface8* surface;
	cMagEngineMgr::getInstance()->engine->GetBackBuffer(0, D3DBACKBUFFER_TYPE_MONO, &surface);
	surface->GetDesc(&surfaceDesc);
	// cMagEngineMgr::getInstance()->engine->GetDisplayMode(&this->displayMode);
	surface->Release();
	
	grid = new MagGrid();

	grid->InitDeviceObjects(cMagEngineMgr::getInstance()->engine);
	grid->Create(150, 150, 200.0f);
	grid->BuildVertexBuffer();

	FileLog("--- End CreateDevice3D ... OK");
	return S_OK;
}

/* 10025440-10025515 000D5	*/
void cMagGameObject::Cleanup() {
	if (direct3D != NULL) {
		direct3D->Release();
	}
	FileLog("Cleanup... OK");
}

LRESULT CALLBACK ME2WNDPROC(HWND, UINT, WPARAM, LPARAM) {
	return 0;
}

/* 10025550-100258B5 00365	*/
long cMagGameObject::AppInit(HINSTANCE__* param_1, bool param_2) {
	FileLog("--- Begin CreateDevice3D ... ");
	direct3D = Direct3DCreate8(D3D_SDK_VERSION);
	if (direct3D == NULL) {
		CrashLog("Direct3DCreate8... (error)");
		return E_FAIL;
	}

	if (logEnabled) {
		int adapterModeCount = direct3D->GetAdapterModeCount(D3DADAPTER_DEFAULT);
		for (int mode = 0; mode < adapterModeCount; mode++) {
			D3DDISPLAYMODE displayMode;
			direct3D->EnumAdapterModes(D3DADAPTER_DEFAULT, mode, &displayMode);
			uint rgbChannels = 0;
			if (displayMode.Format == D3DFMT_X1R5G5B5) {
				rgbChannels = 0x10;
			} else if (displayMode.Format == D3DFMT_R5G6B5) {
				rgbChannels = 0x10;
			} else if (displayMode.Format == D3DFMT_A1R5G5B5) {
				rgbChannels = 0x10;
			} else if (displayMode.Format == D3DFMT_A4R4G4B4) {
				rgbChannels = 0x10;
			} else if (displayMode.Format == D3DFMT_X4R4G4B4) {
				rgbChannels = 0x10;
			} else if (displayMode.Format == D3DFMT_R8G8B8) {
				rgbChannels = 0x18;
			} else if (displayMode.Format == D3DFMT_X8R8G8B8 || displayMode.Format == D3DFMT_A8R8G8B8 ) {
				rgbChannels = 0x20;
			} 
			char buffer[16];
			sprintf(buffer, "%dx%dx%d _ %dhz", displayMode.Width, displayMode.Height, rgbChannels, displayMode.RefreshRate);
			FileLog(buffer);
		}
	}

	ZeroMemory(&cMagGameObject::PRESENT_PARAMETERS, sizeof(D3DPRESENT_PARAMETERS)); 
	cMagGameObject::PRESENT_PARAMETERS.BackBufferCount = 3;
	cMagGameObject::PRESENT_PARAMETERS.BackBufferWidth = windowWidth;
	cMagGameObject::PRESENT_PARAMETERS.BackBufferHeight = windowHeight;
	cMagGameObject::PRESENT_PARAMETERS.SwapEffect = D3DSWAPEFFECT_DISCARD;
	if (enableFullscreen) {
		cMagGameObject::PRESENT_PARAMETERS.Windowed = FALSE;
		rgbChannels = 0x20;
		cMagGameObject::PRESENT_PARAMETERS.EnableAutoDepthStencil = TRUE;
		cMagGameObject::PRESENT_PARAMETERS.AutoDepthStencilFormat = D3DFMT_D24S8;
		cMagGameObject::PRESENT_PARAMETERS.BackBufferFormat = D3DFMT_X8R8G8B8;
		FileLog("Tryb: %d , FullScreen", 0x20);
	} else {
		cMagGameObject::PRESENT_PARAMETERS.Windowed = TRUE;
		D3DDISPLAYMODE displayMode;
		HRESULT result = direct3D->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &displayMode);
		if (result >= S_OK) {
			return E_FAIL;
		} 

		if (displayMode.Format != D3DFMT_X8R8G8B8 && displayMode.Format != D3DFMT_A8R8G8B8) {
			rgbChannels = 0x10;
			cMagGameObject::PRESENT_PARAMETERS.EnableAutoDepthStencil = TRUE;
			cMagGameObject::PRESENT_PARAMETERS.AutoDepthStencilFormat = D3DFMT_D16;
			cMagGameObject::PRESENT_PARAMETERS.BackBufferFormat = D3DFMT_R5G6B5;
			FileLog("Tryb: %d , okno", 0x10);
		} else {
			rgbChannels = 0x20;
			cMagGameObject::PRESENT_PARAMETERS.EnableAutoDepthStencil = TRUE;
			cMagGameObject::PRESENT_PARAMETERS.AutoDepthStencilFormat = D3DFMT_D24S8;
			cMagGameObject::PRESENT_PARAMETERS.BackBufferFormat = D3DFMT_X8R8G8B8;
			FileLog("Tryb: %d , okno", 0x20);
		}
	}

	D3DCAPS8 caps;
	HRESULT result;
	direct3D->GetDeviceCaps(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, &caps);
	if (caps.MaxPrimitiveCount == 0xfffe0101) {
		char buffer[272];
		sprintf(buffer, "%s   %s", windowTitle, "[HV]");
		SetWindowText(hWnd, buffer);
		FileLog("[HV]");
		result = direct3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, 0x40, &cMagGameObject::PRESENT_PARAMETERS, &device3D);
	} else {
		char buffer[272];
		sprintf(buffer, "%s   %s", windowTitle, "[SV]");
		SetWindowText(hWnd, buffer);
		FileLog("[SV]");
		result = direct3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, 0x20, &cMagGameObject::PRESENT_PARAMETERS, &device3D);
	}

	if (result < S_OK) {
		CrashLog("CreateDevice... (error)");
		return E_FAIL;
	}

	SetCursor(NULL);
	cMagEngineMgr::getInstance()->engine = device3D;
	cMagEngineMgr::getInstance()->gameObject = this;
	cMagEngineMgr::getInstance()->CreateFrustumCull();
	FileLog("--- End CreateDevice3D ...OK");
	return S_OK;
}

/* 100258C0-10025AA6 001E6	*/
void cMagGameObject::SetDeviceMode(int param_1, int param_2) {
	backBufferWidth = param_1;
	backBufferHeight = param_2;
	windowWidth = param_1;
	windowHeight = param_2;
	DebugLog("WindowWidth: %d  WindowHeight: %d", param_1, param_2);

	ZeroMemory(&cMagGameObject::PRESENT_PARAMETERS, sizeof(D3DPRESENT_PARAMETERS));
	device3D->Reset(&cMagGameObject::PRESENT_PARAMETERS);
	cMagGameObject::PRESENT_PARAMETERS.BackBufferCount = 3;
	cMagGameObject::PRESENT_PARAMETERS.BackBufferWidth = windowWidth;
	cMagGameObject::PRESENT_PARAMETERS.BackBufferHeight = windowHeight;
	cMagGameObject::PRESENT_PARAMETERS.SwapEffect = D3DSWAPEFFECT_DISCARD;
	SetWindowPos(hWnd, NULL, 0, 0, windowWidth, windowHeight, 0);

	int channels;
	if (enableFullscreen) {
		cMagGameObject::PRESENT_PARAMETERS.Windowed = FALSE;
		rgbChannels = 0x20;
		channels = 0x20;
		cMagGameObject::PRESENT_PARAMETERS.EnableAutoDepthStencil = TRUE;
		cMagGameObject::PRESENT_PARAMETERS.AutoDepthStencilFormat = D3DFMT_D24S8;
		cMagGameObject::PRESENT_PARAMETERS.BackBufferFormat = D3DFMT_X8R8G8B8;
		FileLog("Tryb: %d , FullScreen", channels);
	} else {
		cMagGameObject::PRESENT_PARAMETERS.Windowed = TRUE;
		D3DDISPLAYMODE displayMode;
		HRESULT result = direct3D->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &displayMode);
		if (result < 0) {
			return;
		}
		if (displayMode.Format == D3DFMT_X8R8G8B8 || displayMode.Format == D3DFMT_A8R8G8B8) {
			rgbChannels = 0x20;
			channels = 0x20;
			cMagGameObject::PRESENT_PARAMETERS.EnableAutoDepthStencil = TRUE;
			cMagGameObject::PRESENT_PARAMETERS.AutoDepthStencilFormat = D3DFMT_D24S8;
			cMagGameObject::PRESENT_PARAMETERS.BackBufferFormat = D3DFMT_X8R8G8B8;
			FileLog("Tryb: %d , okno", channels);
		} else {
			rgbChannels = 0x10;
			channels = 0x10;
			cMagGameObject::PRESENT_PARAMETERS.EnableAutoDepthStencil = TRUE;
			cMagGameObject::PRESENT_PARAMETERS.AutoDepthStencilFormat = D3DFMT_D16;
			cMagGameObject::PRESENT_PARAMETERS.BackBufferFormat = D3DFMT_R5G6B5;
			FileLog("Tryb: %d , okno", channels);
		}
	}
	ShowWindow(hWnd, 5);
	UpdateWindow(hWnd);
	SetForegroundWindow(hWnd);
	SetCapture(hWnd);
	SetFocus(hWnd);
	for(std::vector<cMagKernel*>::iterator it = spriteObjects.begin(); it != spriteObjects.end(); it++) {
		((cMagSprite*)(*it))->Restore();
	}
}


/* 10025AB0-10025C6F 001BF	*/
bool cMagGameObject::InitWindow(int param_1, int param_2, int param_3, bool param_4, HINSTANCE__* param_5, WNDPROC param_6, char* param_7) {
	DeleteLog();
	FileLog("[-----------------------------]");
	FileLog("[--- Magnum Engine ver 2.0 ---]");
	FileLog("[-----------------------------]");
	windowWidth = param_1;
	windowHeight = param_2;
	rgbChannels = param_3;
	enableFullscreen = param_4;
	strcpy(windowTitle, param_7);

	WNDCLASSEX classEx = {sizeof(WNDCLASSEX), CS_CLASSDC, ME2WNDPROC, 0, 0, GetModuleHandle(NULL), 
		NULL, NULL, NULL, NULL, "Magnum", NULL};
	classEx.hbrBackground = (HBRUSH) GetStockObject(BLACK_BRUSH);
	HINSTANCE dllHandle = GetModuleHandle("ME2.dll");
	classEx.hIcon = LoadIcon(dllHandle, MAKEINTRESOURCE(109));
	RegisterClassEx(&classEx);

	hWnd = CreateWindowEx(WS_EX_LEFT, "Magnum", param_7, WS_VISIBLE|WS_CAPTION|WS_SYSMENU, 0,0, windowWidth, windowHeight, 
		GetDesktopWindow(), NULL, classEx.hInstance, NULL);
	
	if (hWnd == NULL) {
		CrashLog("InitWindow... (error)");
		KillWindowDx();
		return false;
	}
	ShowWindow(hWnd, 5);
	UpdateWindow(hWnd);
	SetForegroundWindow(hWnd);
	SetCapture(hWnd);
	SetFocus(hWnd);
	SetCursor(NULL);
	FileLog("--- End InitWindow... OK");

	return true;
}

/* 10025C70-10025C87 00017	*/
void cMagGameObject::UpdateMagWindowSize(int param_1, int param_2) {
	windowWidth = param_1;
	windowHeight = param_2;
}

/* 10025C90-10025CA4 00014	*/
void cMagGameObject::ShowGameCursor(bool param_1) {
	cMagEngineMgr::getInstance()->gameObject->showCursor = param_1;
}

/* 10025CB0-10025CBE 0000E	*/
bool cMagGameObject::EnableGameCursor() {
	return cMagEngineMgr::getInstance()->gameObject->showCursor;
}

/* 10025CC0-10025CE6 00026	*/
void cMagGameObject::RenderGameCursor() {
	if (cMagEngineMgr::getInstance()->gameObject->showCursor) {
		cMagEngineMgr::getInstance()->engine->ShowCursor(TRUE);
	} else {
		cMagEngineMgr::getInstance()->engine->ShowCursor(FALSE);
	}
}

/* 10025CF0-10025E29 00139	*/
long cMagGameObject::MsgProc(HWND param_1, uint param_2, uint param_3, long param_4) {
	switch(param_2) {
		case WM_DESTROY:
		case WM_CLOSE:
			PostQuitMessage(0); // case 0
			return 0;
		case WM_SETCURSOR:
			SetCursor(NULL); // case 1
			break;
		case WM_KEYDOWN: {
			cMagGameObject* obj = cMagEngineMgr::getInstance()->gameObject->callHandlerWindowKey; // case 2
			if (obj != NULL) {
				obj->OnInputKey(param_3, true);
			}
			break;
		}
		case WM_KEYUP: {
			cMagGameObject* obj = cMagEngineMgr::getInstance()->gameObject->callHandlerWindowKey; // case 2
			if (obj != NULL) {
				obj->OnInputKey(param_3, false);
			}
			break;
		}
		case WM_CHAR: {
			cMagGameObject* obj = cMagEngineMgr::getInstance()->gameObject->callHandlerWindowKey; // case 2
			if (obj != NULL) {
				obj->OnInputChar(param_3);
			}
			break;
		}
		case WM_MOUSEMOVE:
			POINT mousePos;
			GetCursorPos(&mousePos);
			ScreenToClient(hWnd, &mousePos);
			cMagEngineMgr::getInstance()->engine->SetCursorPosition(mousePos.x, mousePos.y, 0);
			RenderGameCursor();
			break;
		case WM_MOVE:
		case WM_SIZE:
		case WM_ACTIVATE:
		case WM_SETFOCUS:
		case WM_KILLFOCUS:
		case WM_ENABLE:
		case WM_SETREDRAW:
		default:
			break; // case 3
	}
	return DefWindowProc(param_1, param_2, param_3, param_4);
}

/* 10025F40-10025FA0 00060	*/
bool cMagGameObject::KillWindowDx() {
	if (hdc != NULL) {
		if (ReleaseDC(hWnd, hdc) == 0) {
			hdc = NULL;
		}
	}

	if (hWnd != NULL) {
		if (!DestroyWindow(hWnd)) {
			hWnd = NULL;
		}
	}
	
	if (!UnregisterClass("Magnum", hInstance)) {
		hInstance = NULL;
	}
	return true;
}

/* 10025FA0-10025FF7 00057	*/
bool cMagGameObject::HandleMessages() {
	while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
		if (msg.message == WM_QUIT) {
			return false;
		}
	}
	return true;
}

/* 10026000-10026083 00083	*/
bool cMagGameObject::Run() {
	while (true) {
		if (gameInstance != NULL) {
			gameInstance->FrameTime();
		}
		GetGame()->LoadLevel();
		if (!HandleMessages()) {
			break;
		}
		RenderScene();
		cMagGameObject* gameObject = cMagEngineMgr::getInstance()->gameObject;
		if (!gameObject->input.Update()) {
			break;
		}
	}

	if (gameInstance != NULL) {
		gameInstance->Clean();
	}
	cMagEngineMgr::getInstance()->gameObject->input.Kill();
	KillWindowDx();
	DestroySoundManager();
	Cleanup();
	return false;
}

/* 10026090-10026149 000B9	*/
bool cMagGameObject::CreateWinDx(HINSTANCE__* param_1, bool param_2, int param_3, int param_4, int param_5, char* param_6, bool param_7) {
	backBufferWidth = param_4;
	backBufferHeight = param_5;
	bool success = InitWindow(param_4, param_5, param_3, param_2, param_1, NULL, param_6);
	if (!success) {
		magLog.CrashLog("InitWindow ... (error)");
		return false;
	}

	if (AppInit(param_1, param_7) < 0) {
		magLog.CrashLog("InitD3D ... (error)");
		return false;
	}

	cMagGameObject* gameObject = cMagEngineMgr::getInstance()->gameObject;
	if (!gameObject->input.Init(hWnd, param_1)) {
		magLog.CrashLog("InitInput ... (error) ");
		return false;
	}
	InitSoundManager();
	CreateBigSquareShadow();
	EnableBigSquareShadow(true);
	CreateDxFont();
	return true;
}

/* 10026150-10026195 00045	*/
void cMagGameObject::ClearInputKey() {
}

/* 100261A0-100261D6 00036	*/
void cMagGameObject::OnPreRenderEdytor() {
	cMagEngineMgr::getInstance()->engine->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_ARGB(0xff, 0x7f, 0x7f, 0x7f), 1.0f, 0);
	cMagEngineMgr::getInstance()->engine->BeginScene();
}

/* 100261E0-100262F9 00119	*/
void cMagGameObject::OnPreRender() {
	CGame* game = GetGame();
	if (game == NULL) {
		cMagEngineMgr::getInstance()->engine->Clear(0, NULL, D3DCLEAR_TARGET|D3DCLEAR_ZBUFFER, D3DCOLOR_ARGB(0xff, 0x7f, 0x7f, 0x7f), 1.0f, 0);
		cMagEngineMgr::getInstance()->engine->BeginScene();
		return; 
	} 

	// if (!enabledFog && rgbChannels == 0x20) {
	// 	cMagEngineMgr::getInstance()->engine->Clear(0, NULL, D3DCLEAR_TARGET|D3DCLEAR_ZBUFFER|D3DCLEAR_STENCIL, D3DCOLOR_ARGB(0xff, 0x0f, 0x0f, 0x0f), 1.0f, 0);
	// 	cMagEngineMgr::getInstance()->engine->BeginScene();
	// 	return;
	// }

	// if (!enabledFog && rgbChannels != 0x20) {
	// 	cMagEngineMgr::getInstance()->engine->Clear(0, NULL, D3DCLEAR_TARGET|D3DCLEAR_ZBUFFER, D3DCOLOR_ARGB(0xff, 0x0f, 0x0f, 0x0f), 1.0f, 0);
	// 	cMagEngineMgr::getInstance()->engine->BeginScene();	
	// 	return;
	// }


	// if(rgbChannels == 0x20) {
	// 		D3DCOLOR fogColor = GetFog()->GetColorFog();
	// 		cMagEngineMgr::getInstance()->engine->Clear(0, NULL, D3DCLEAR_TARGET|D3DCLEAR_ZBUFFER|D3DCLEAR_STENCIL, fogColor, 1.0f, 0);
	// 		cMagEngineMgr::getInstance()->engine->BeginScene();
	// 		return;
	// 	} else {
	// 		cMagEngineMgr::getInstance()->engine->Clear(0, NULL, D3DCLEAR_TARGET|D3DCLEAR_ZBUFFER, GetFog()->GetColorFog(), 1.0f, 0);
	// 		cMagEngineMgr::getInstance()->engine->BeginScene();
	// 		return;
	// 	}

	// if (!enabledFog) {
	// 	if (rgbChannels == 0x20) {
	// 		cMagEngineMgr::getInstance()->engine->Clear(0, NULL, D3DCLEAR_TARGET|D3DCLEAR_ZBUFFER|D3DCLEAR_STENCIL, D3DCOLOR_ARGB(0xff, 0x0f, 0x0f, 0x0f), 1.0f, 0);
	// 		cMagEngineMgr::getInstance()->engine->BeginScene();
	// 	} else {
	// 		cMagEngineMgr::getInstance()->engine->Clear(0, NULL, D3DCLEAR_TARGET|D3DCLEAR_ZBUFFER, D3DCOLOR_ARGB(0xff, 0x0f, 0x0f, 0x0f), 1.0f, 0);
	// 		cMagEngineMgr::getInstance()->engine->BeginScene();
	// 	}

	// } else {
	// 	if (rgbChannels == 0x20) {
	// 		D3DCOLOR fogColor = GetFog()->GetColorFog();
	// 		cMagEngineMgr::getInstance()->engine->Clear(0, NULL, D3DCLEAR_TARGET|D3DCLEAR_ZBUFFER|D3DCLEAR_STENCIL, fogColor, 1.0f, 0);
	// 		cMagEngineMgr::getInstance()->engine->BeginScene();
			
	// 	} else {
	// 	cMagEngineMgr::getInstance()->engine->Clear(0, NULL, D3DCLEAR_TARGET|D3DCLEAR_ZBUFFER, GetFog()->GetColorFog(), 1.0f, 0);
	// 	cMagEngineMgr::getInstance()->engine->BeginScene();
	// 	}
	// }
 	

	if (enabledFog && rgbChannels == 0x20) {
		D3DCOLOR fogColor = GetFog()->GetColorFog();
		cMagEngineMgr::getInstance()->engine->Clear(0, NULL, D3DCLEAR_TARGET|D3DCLEAR_ZBUFFER|D3DCLEAR_STENCIL, fogColor, 1.0f, 0);
		cMagEngineMgr::getInstance()->engine->BeginScene();
		return;
	} 
	
	if (enabledFog && rgbChannels != 0x20) {
		cMagEngineMgr::getInstance()->engine->Clear(0, NULL, D3DCLEAR_TARGET|D3DCLEAR_ZBUFFER, GetFog()->GetColorFog(), 1.0f, 0);
		cMagEngineMgr::getInstance()->engine->BeginScene();
		return;
	} 
	
	if (rgbChannels == 0x20) {
		cMagEngineMgr::getInstance()->engine->Clear(0, NULL, D3DCLEAR_TARGET|D3DCLEAR_ZBUFFER|D3DCLEAR_STENCIL, D3DCOLOR_ARGB(0xff, 0x0f, 0x0f, 0x0f), 1.0f, 0);
		cMagEngineMgr::getInstance()->engine->BeginScene();
		return;
	} 

	cMagEngineMgr::getInstance()->engine->Clear(0, NULL, D3DCLEAR_TARGET|D3DCLEAR_ZBUFFER, D3DCOLOR_ARGB(0xff, 0x0f, 0x0f, 0x0f), 1.0f, 0);
	cMagEngineMgr::getInstance()->engine->BeginScene();
	return;

}

/* 10026300-1002632E 0002E	*/
void cMagGameObject::OnPostRender() {
	RenderGameCursor();
	cMagEngineMgr::getInstance()->engine->EndScene();
	cMagEngineMgr::getInstance()->engine->Present(NULL, NULL, NULL, NULL);
}

/* 10026330-1002669D 0036D	*/
bool cMagGameObject::Render() {
	D3DMATRIX worldMatrix;
	cMagEngineMgr::getInstance()->engine->GetTransform(D3DTS_WORLD, &worldMatrix);
	SortObject();

	if (showGrid) {
		grid->Render();
	}

	if (enabledFog) {
		cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_FOGENABLE, FALSE);
	}
	RenderSkyBox();
	if (enabledFog) {
		cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_FOGENABLE, TRUE);		
	}

	if (enabledFog) {
		cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_FOGENABLE, FALSE);
	}
	RenderSun();
	if (enabledFog) {
		cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_FOGENABLE, TRUE);
	}

	cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_ZENABLE, TRUE);
	RenderTerrain();

	cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_LIGHTING, TRUE);
	renderedMeshObjects = 0;
	renderedObjects = 0;
	RenderObjectList();

	cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_LIGHTING, FALSE);
	RenderShadowsList();

	if (enableBigSquareShadow && rgbChannels == 0x20) {
		DrawBigSquareShadow();
	}

	RenderNoShadowObjects();

	MagTextureMgr::getInstance()->BeginFilterTexture();
	MagTextureMgr::getInstance()->BeginFilterVertexColorTexture();
	MagTextureMgr::getInstance()->BeginAlphaTexture();
	RenderAlphaMeshObjectsList();
	RenderAlphaList();
	RenderWaterList();
	
	if (enabledFog) {
		cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_FOGENABLE, FALSE);
	}
	RenderFxList();
	if (enabledFog) {
		cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_FOGENABLE, TRUE);
	}

	if (enabledFog) {
		cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_FOGENABLE, FALSE);
	}
	RenderParticleList();
	if (enabledFog) {
		cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_FOGENABLE, TRUE);
	}

	cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_ALPHATESTENABLE, TRUE);
	cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_ALPHAREF, 2);
	cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATEREQUAL);
	cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_LIGHTING, FALSE);

	MagTextureMgr::getInstance()->BeginFilterTexture();
	MagTextureMgr::getInstance()->BeginAlphaTexture();
	MagTextureMgr::getInstance()->BeginFilterVertexColorTexture();

	cMagEngineMgr::getInstance()->engine->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_SELECTARG1);
	cMagEngineMgr::getInstance()->engine->SetTextureStageState(0, D3DTSS_TEXTURETRANSFORMFLAGS, D3DTTFF_DISABLE);
	cMagEngineMgr::getInstance()->engine->SetTextureStageState(0, D3DTSS_ADDRESSU, D3DTADDRESS_CLAMP);
	cMagEngineMgr::getInstance()->engine->SetTextureStageState(0, D3DTSS_ADDRESSV, D3DTADDRESS_CLAMP);

	renderedBillboards = 0;
	RenderBillboardList();

	MagTextureMgr::getInstance()->EndAlphaTexture();
	cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_ZWRITEENABLE, TRUE);
	RenderFog();
	RenderLensFlare();
	RenderBlobList();
	RenderSpriteList();

	cMagEngineMgr::getInstance()->engine->SetTransform(D3DTS_WORLD, &worldMatrix);
	return true;
}

/* 100266A0-10026785 000E5	*/
void cMagGameObject::RenderScene() {
	HRESULT result = cMagEngineMgr::getInstance()->engine->TestCooperativeLevel();

	if (result < S_OK) {
		unkn_cf4 = true;
		if (result == D3DERR_DEVICELOST) {
			return;
		}
 		if (result == D3DERR_DEVICENOTRESET) {
			if (dxFont != NULL) {
				if (dxFont->OnLostDevice() != S_OK) {
					dxFont->OnResetDevice();
				}
			}

			HRESULT result = cMagEngineMgr::getInstance()->engine->Reset(&cMagGameObject::PRESENT_PARAMETERS);
			if (result < S_OK) {
				return;
			}
			RestoreScene();
		}
	} else {
		unkn_cf4 = false;
	}

	RenderActiveCamera();
	UpdateActiveCamera();
	CallHandlerOnUpdate_();
	OnPreRender();
	Render();
	OnPostRender();
	if (collision != NULL) {
		collision->FUN_100a5af0();
	}
	
	cMagGameObject* gameObject = cMagEngineMgr::getInstance()->gameObject;
	CallAllHandler(&gameObject->input.unkn_1c, gameObject->input.unkn_11c, gameObject->input.unkn_120, gameObject->input.unkn_128, gameObject->input.unkn_129);
}

/* 10026790-10026B70 003E0	*/
void cMagGameObject::RestoreScene() {
	if (dxFont != NULL) {
		dxFont->Release();
		if (GetWindowWidth() == 320 && GetWindowHeight() == 240) {
			LOGFONT logFont = {
				14, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, EASTEUROPE_CHARSET, 
				OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 
				DEFAULT_PITCH | FF_DONTCARE, "Comic Sans MS"
			};
			IDirect3DDevice8* engine = cMagEngineMgr::getInstance()->engine;
			createFontResult = D3DXCreateFontIndirect(engine, &logFont, &dxFont);
			if (createFontResult < D3D_OK) {
				CrashLog("Nie mo�na utworzy� czcionki");
			}
		}

		if (GetWindowWidth() == 640 && GetWindowHeight() == 480) {
			LOGFONT logFont = {
				18, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, EASTEUROPE_CHARSET, 
				OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 
				DEFAULT_PITCH | FF_DONTCARE, "Comic Sans MS"
			};

			IDirect3DDevice8* engine = cMagEngineMgr::getInstance()->engine;
			createFontResult = D3DXCreateFontIndirect(engine, &logFont, &dxFont);
			if (createFontResult < D3D_OK) {
				CrashLog("Nie mo�na utworzy� czcionki");
			}
		}

		if (GetWindowWidth() == 800 && GetWindowHeight() == 600) {
			LOGFONT logFont = {
				22, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, EASTEUROPE_CHARSET, 
				OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 
				DEFAULT_PITCH | FF_DONTCARE, "Comic Sans MS"
			};
			IDirect3DDevice8* engine = cMagEngineMgr::getInstance()->engine;
			createFontResult = D3DXCreateFontIndirect(engine, &logFont, &dxFont);
			if (createFontResult < D3D_OK) {
				CrashLog("Nie mo�na utworzy� czcionki");
			}
		}

		if (GetWindowWidth() == 1024 && GetWindowHeight() == 768) {
			LOGFONT logFont = {
				28, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, EASTEUROPE_CHARSET, 
				OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 
				DEFAULT_PITCH | FF_DONTCARE, "Comic Sans MS"
			};

			IDirect3DDevice8* engine = cMagEngineMgr::getInstance()->engine;
			createFontResult = D3DXCreateFontIndirect(engine, &logFont, &dxFont);
			if (createFontResult < D3D_OK) {
				CrashLog("Nie mo�na utworzy� czcionki");
			}
		}
	}

	if (enabledFog) {
		if (GetFog() != NULL) {
			GetFog()->InitFog();
		}
	}

	try {
		for (int index = 0; index < cMagEngineMgr::getInstance()->gameObject->spriteObjects.size(); index++) {
			((cMagSprite*)(spriteObjects[index]))->Restore();
		}
	} catch(...) {
		CrashLog("[CRACH] Restore sprite error");
	}

	SetCapture(GetHandleWindow());
	SetCursor(NULL);
}

/* 10026B70-10026C82 00112	*/
void cMagGameObject::CallHandlerOnUpdate_() {
	for (std::vector<cMagKernel*>::iterator mit = meshObjects.begin(); 
			mit != meshObjects.end(); mit++) {
		(*mit)->OnUpdate_();
	}
	for (std::vector<cMagKernel*>::iterator bit = billboardObjects.begin(); 
			bit != billboardObjects.end(); bit++) {
		(*bit)->OnUpdate_();
	}
	for (std::vector<cMagKernel*>::iterator cit = cameraObjects.begin(); 
			cit != cameraObjects.end(); cit++) {
		(*cit)->OnUpdate_();
	}
	for (std::vector<cMagKernel*>::iterator sit = spriteObjects.begin(); 
			sit != spriteObjects.end(); sit++) {
		(*sit)->OnUpdate_();
	}
	for (std::vector<cMagKernel*>::iterator nit = noShadowObjects.begin(); 
			nit != noShadowObjects.end(); nit++) {
		(*nit)->OnUpdate_();
	}
	for (std::vector<cMagKernel*>::iterator wit = waterObjects.begin(); 
			wit != waterObjects.end(); wit++) {
		(*wit)->OnUpdate_();
	}
	for (std::vector<cMagKernel*>::iterator ait = alphaMeshObjects.begin(); 
			ait != alphaMeshObjects.end(); ait++) {
		(*ait)->OnUpdate_();
	}
}

/* 10026C90-10026D0B 0007B	*/
void cMagGameObject::CallOnUpdateMenuSettings() {
	for (std::vector<cMagKernel*>::iterator mit = cMagEngineMgr::getInstance()->gameObject->meshObjects.begin(); 
			mit != cMagEngineMgr::getInstance()->gameObject->meshObjects.end(); mit++) {
		(*mit)->OnUpdateMenuSettings();
	}

	for (std::vector<cMagKernel*>::iterator sit = spriteObjects.begin(); 
			sit != spriteObjects.end(); sit++) {
		(*sit)->OnUpdateMenuSettings();
	}

	if (gameInstance != NULL && gameInstance->activeLevel != NULL) {
		gameInstance->activeLevel->OnUpdateMenuSettings();
	}
}

/* 10026D10-1002701F 0030F	*/
void cMagGameObject::CallAllHandler(uchar* param_1, float param_2, float param_3, bool param_4, bool param_5) {
	if (cMagEngineMgr::getInstance()->gameObject->callHandlerOnFrame1 != NULL) {
		cMagEngineMgr::getInstance()->gameObject->callHandlerOnFrame1->OnFrame1();
	}
	if (terrainObject != NULL) {
		if (terrainObject->GetStatusOnFrame()) {
			terrainObject->OnFrame();
		}
	}
	if (GetStatusOnFrame()) {
		OnFrame();
	}
	if (GetStatusOnInputKey()) {
		OnInputKey(param_1);
	}
	if (GetStatusOnInputMouse()) {
		OnInputMouse(param_2, param_3, param_4, param_5);
	}
	if (gameInstance != NULL && gameInstance->activeLevel != NULL) {
		if (gameInstance->activeLevel->GetStatusOnFrame()) {
			gameInstance->activeLevel->OnFrame();
		}
	}
	if (gameInstance != NULL && gameInstance->activeLevel != NULL) {
		if (gameInstance->activeLevel->GetStatusOnInputKey()) {
			gameInstance->activeLevel->OnInputKey(param_1);
		}
	}

	for (std::vector<cMagKernel*>::iterator mit = meshObjects.begin(); 
				mit != meshObjects.end(); mit++) {
		if ((*mit)->GetStatusOnFrame()) {
			(*mit)->CallOnFrame();
		}
		if ((*mit)->GetStatusOnInputKey()) {
			(*mit)->CallOnInputKey(param_1);
		}
		if ((*mit)->GetStatusOnInputMouse()) {
			(*mit)->CallOnInputMouse(param_2, param_3, param_4, param_5);
		}
	}

	for (std::vector<cMagKernel*>::iterator cit = cameraObjects.begin(); 
				cit != cameraObjects.end(); cit++) {
		if ((*cit)->GetStatusOnFrame()) {
			(*cit)->OnFrame();
		}
		if ((*cit)->GetStatusOnInputKey()) {
			(*cit)->OnInputKey(param_1);
		}
		if ((*cit)->GetStatusOnInputMouse()) {
			(*cit)->OnInputMouse(param_2, param_3, param_4, param_5);
		}
	}

	for (std::vector<cMagKernel*>::iterator sit = spriteObjects.begin(); 
				sit != spriteObjects.end(); sit++) {
		if ((*sit)->GetStatusOnFrame()) {
			(*sit)->CallOnFrame();
		}
		if ((*sit)->GetStatusOnInputKey()) {
			(*sit)->CallOnInputKey(param_1);
		}
		if ((*sit)->GetStatusOnInputMouse()) {
			(*sit)->CallOnInputMouse(param_2, param_3, param_4, param_5);
		}
	}

	for (std::vector<cMagKernel*>::iterator bit = billboardObjects.begin(); 
				bit != billboardObjects.end(); bit++) {
		if ((*bit)->GetStatusOnFrame()) {
			(*bit)->OnFrame();
		}
		if ((*bit)->GetStatusOnInputKey()) {
			(*bit)->OnInputKey(param_1);
		}
		if ((*bit)->GetStatusOnInputMouse()) {
			(*bit)->OnInputMouse(param_2, param_3, param_4, param_5);
		}
	}

	for (std::vector<cMagKernel*>::iterator pit = particleObjects.begin(); 
				pit != particleObjects.end(); pit++) {
		if ((*pit)->GetStatusOnFrame()) {
			(*pit)->OnFrame();
		}
		if ((*pit)->GetStatusOnInputKey()) {
			(*pit)->OnInputKey(param_1);
		}
		if ((*pit)->GetStatusOnInputMouse()) {
			(*pit)->OnInputMouse(param_2, param_3, param_4, param_5);
		}
	}
}

/* 10027020-1002732C 0030C	*/
void cMagGameObject::CreateObject(cMagKernel* param_1) {
	cMagKernel* object;
	object->OnActivate();
	FileLog("CreateObject: %s", object->GetObjectName());
	if (stricmp(object->GetClassNameA(), "cMagParticleSystem") == 0) {
		cMagEngineMgr::getInstance()->gameObject->AddParticleObject(object);
		object->vtbl_0x50();
		return;
	} 
	 if (stricmp(object->GetClassNameA(), "cMagFx") != 0) {
		if (stricmp(object->GetClassNameA(), "cGlow") != 0) {
			if (stricmp(object->GetClassNameA(), "CSplineCamera") == 0) {
				cMagEngineMgr::getInstance()->gameObject->splineCameras.push_back(param_1);
				object->vtbl_0x50();
			} else if (stricmp(object->GetClassNameA(), "cMagBillboard") == 0) {
				cMagEngineMgr::getInstance()->gameObject->AddBillboardObject(object);
				object->vtbl_0x50();
			} else if (stricmp(object->GetClassNameA(), "cMagCamera") == 0) {
				cMagEngineMgr::getInstance()->gameObject->AddCameraObject(object);
				object->vtbl_0x50();
			} else if(stricmp(object->GetClassNameA(), "cMagSkyBox") == 0) {
				cMagEngineMgr::getInstance()->gameObject->AddSkyBoxObject(object);
			} else if (stricmp(object->GetClassNameA(), "cMagSun") == 0) {
				cMagEngineMgr::getInstance()->gameObject->AddSunObject(object);
			} else if (stricmp(object->GetClassNameA(), "CLensFlare") == 0) {
				lensFlare = object;
			} else if (stricmp(object->GetClassNameA(), "MagTerrain") == 0) {
				cMagEngineMgr::getInstance()->gameObject->AddTerrainObject(object);
			} else if(stricmp(object->GetClassNameA(), "cMagSprite") == 0) {
				cMagEngineMgr::getInstance()->gameObject->AddSpriteObject(object);
				object->vtbl_0x50();
			} else if(stricmp(object->GetClassNameA(), "cMagFog") == 0) {
				cMagEngineMgr::getInstance()->gameObject->AddFogObject(object);
			} else if(stricmp(object->GetClassNameA(), "cWater") == 0) {
				cMagEngineMgr::getInstance()->gameObject->AddWaterObject(object);
				object->vtbl_0x50();
			} else if (stricmp(object->GetClassNameA(), "cBlob") == 0) {
				cMagEngineMgr::getInstance()->gameObject->AddBlobObject(object);
				object->vtbl_0x50();
			}
		} else {
			cMagEngineMgr::getInstance()->gameObject->AddObject(object);
			object->OnPreRender();
			object->vtbl_0x50();
		}
	} else {
		cMagEngineMgr::getInstance()->gameObject->AddFxObject(object);
		object->vtbl_0x50();
	}
}

/* 10027330-100273BA 0008A	*/
void cMagGameObject::CameraLookAt(float param_1, float param_2, float param_3, float param_4, float param_5, float param_6, float param_7, float param_8, float param_9) {
	eye.x = param_1;
	eye.y = param_2;
	eye.z = param_3;
	
	at.x = param_4;
	at.y = param_5;
	at.z = param_6;

	up.x = param_7;
	up.y = param_8;
	up.z = param_9;

	D3DXMatrixLookAtLH(&viewMatrix, &eye, &at, &up);
	cMagEngineMgr::getInstance()->engine->SetTransform(D3DTS_VIEW, &viewMatrix);
}

/* 100273C0-1002744E 0008E	*/
void cMagGameObject::Fps() {
	static float FRAMES_PER_SECOND = 0;
	static float LAST_MEASURE_TIME = 0;
	static uint FRAME_COUNT = 0;
	
	uint time = timeGetTime();
	float timeDiff = time * 0.001f - LAST_MEASURE_TIME;
	FRAME_COUNT++;
	if (timeDiff > 1.0f) {
		uint counts = FRAME_COUNT;
		FRAME_COUNT = 0;
		FRAMES_PER_SECOND = counts / timeDiff;
		LAST_MEASURE_TIME = time * 0.001f;
	}
	
	
	char buffer[80];
	sprintf(buffer, "%s %7.02f", "fps", FRAMES_PER_SECOND);
}

/* 10027450-10027464 00014	*/
void cMagGameObject::ShowFPS(bool param_1) {
	cMagEngineMgr::getInstance()->gameObject->showFPS = param_1;
}

/* 10027470-1002762B 001BB	*/
bool cMagGameObject::TestViewObjest(D3DXVECTOR3 param_1, D3DXMATRIX param_2) {
	D3DVIEWPORT8 viewport;
	cMagEngineMgr::getInstance()->engine->GetViewport(&viewport);
	magLog.DebugLog("Viewport: <fClipWidth2:%f fClipHeight2:%f>", 800.0, 600.0);

	D3DXMATRIX localMatrix = param_2;
	D3DXMATRIX result;
	D3DXMATRIX view;
	cMagEngineMgr::getInstance()->engine->GetTransform(D3DTS_VIEW, &view);
	D3DXMATRIX projection;
	cMagEngineMgr::getInstance()->engine->GetTransform(D3DTS_PROJECTION, &projection);

	D3DXMatrixMultiply(&result, &localMatrix, &view);
	D3DXMatrixMultiply(&result, &result, &projection);
	float var_1 = 1.0f / (result(0,3) * param_1.x + result(1,3) * param_1.y + result(2,3) * param_1.z  + result(3,3));
	float screenXPos = ((result(0,0) * param_1.x + result(1,0) * param_1.y + result(2,0) * param_1.z + result(3,0)) * var_1 + 1.0f) * 400.0f;
	float screenYPos = (1.0f - var_1 * (result(0,1) * param_1.x + result(1,1) * param_1.y + result(2,1) * param_1.z + result(3,1))) * 300.0f;

	if (screenXPos >= 0.0f && screenXPos <= 800.0f && screenYPos >= 0.0f && screenYPos <= 600.0f) {
		return true;
	} 
	return false;
}

/* 10027630-100276D8 000A8	*/
void cMagGameObject::VectorToScreen(D3DXVECTOR3 param_1, D3DXMATRIX param_2, float& param_3, float& param_4) {
	D3DVIEWPORT8 viewport;
	cMagEngineMgr::getInstance()->engine->GetViewport(&viewport);
	viewport.MinZ = 1.0f;
	viewport.MaxZ = 1.0f;
	D3DXMATRIX projection;
	cMagEngineMgr::getInstance()->engine->GetTransform(D3DTS_PROJECTION, &projection);
	D3DXMATRIX view;
	cMagEngineMgr::getInstance()->engine->GetTransform(D3DTS_VIEW, &view);
	
	D3DXVECTOR3 result;
	D3DXVec3Project(&result, &param_1, &viewport, &projection, &view, &param_2);
	param_3 = result.x;
	param_4 = result.y;
}

/* 100276E0-100278A0 001C0	*/
void cMagGameObject::DrawTexts(char const* param_1, float param_2, float param_3, float param_4, D3DXMATRIX param_5) {
	float width = windowWidth;
	float height = windowHeight;
	D3DXMATRIX localMatrix = param_5;
	float halfWidth = width * 0.5f;
	float halfHeight = height * 0.5f;
	D3DXMATRIX view;
	cMagEngineMgr::getInstance()->engine->GetTransform(D3DTS_VIEW, &view);
	D3DXMATRIX projection;
	cMagEngineMgr::getInstance()->engine->GetTransform(D3DTS_PROJECTION, &projection);
	D3DXMATRIX result;
	D3DXMatrixMultiply(&result, &localMatrix, &view);
	D3DXMatrixMultiply(&result, &result, &projection);
	float normalizedX = param_2 - halfWidth;
	float normalizedY = param_3 - halfHeight;
	float var_1 = 1.0f / (result(0,3) * normalizedX + result(1,3) * normalizedY + result(2,3) * param_4  + result(3,3));
	float screenXPos = ((result(0,0) * normalizedX + result(1,0) * normalizedY + result(2,0) * param_4 + result(3,0)) 
		* var_1 + 1.0f) * halfWidth;
	float screenYPos = (1.0f - var_1 * (result(0,1) * normalizedX + result(1,1) * normalizedY + result(2,1) * param_4 + result(3,1))) * halfHeight;

	char buffer[80];
	if (screenXPos >= 0.0f && screenXPos <= width && screenYPos >= 0.0f && screenYPos <= height) {
		strcpy(buffer, param_1);
	} 
}

/* 100278A0-10027A3F 0019F	*/
void cMagGameObject::DrawObjectName() {
	for(std::vector<cMagKernel*>::iterator mit = meshObjects.begin(); mit != meshObjects.end(); mit++) {
		cMagMeshObject* mesh = (cMagMeshObject*) *mit;
		if (mesh != NULL && !mesh->unk_113e){
			D3DXVECTOR3 position = mesh->GetPosition();
			char* objectName = mesh->GetObjectName();
			if (objectName == NULL) {
				continue;
			}

			char buffer[100];
			sprintf(buffer, "%s  pos:<%4.f,%4.f,%4.f>", objectName, position.x, position.y, position.z);

			D3DXMATRIX matrix;
			D3DXMatrixIdentity(&matrix);
			
			float f1 = 0;
			float f2 = 0;
			VectorToScreen(position, matrix, f1, f2);
		}

	}

}

/* 10027A40-10027ADB 0009B	*/
void cMagGameObject::GpgFrustum(double param_1, double param_2, double param_3, double param_4, double param_5, double param_6) {
	float sum_5_5 = param_5 + param_5;
	float sub_2_1 = param_2 - param_1;
	float val_1 = sum_5_5 / sub_2_1;

	float sub_4_3 = param_4 - param_3;
	float val_2 = sum_5_5 / sub_4_3;

	float sum_1_2 = param_1 + param_2;
	float val_3 = sum_1_2 / sub_2_1;

	float sum_3_4 = param_3 + param_4;
	float val_4 = sum_3_4 / sub_4_3;

	float sub_6_5 = param_6 - param_5;
	float val_5 = -param_6 / sub_6_5;

	D3DXMatrixPerspectiveOffCenterRH(&projectionMatrix, val_1, val_2, val_3, val_4, val_5, -1.0f);
}

/* 10027AE0-10027DBE 002DE	*/
void cMagGameObject::GpgPerspective(double param_1, double param_2, double param_3, double param_4, int param_5) {
	float fov_rad_2 = GpgDegToRad(param_1) / 2;
	float fov_aspect = param_3 / (cos(fov_rad_2) / sin(fov_rad_2));

	if (param_5 == -1) {
		GpgFrustum(-fov_aspect*param_2, fov_aspect*param_2, -fov_aspect, fov_aspect, param_3, param_4);
	} else if (param_5 == 0) {
		GpgFrustum(-fov_aspect*param_2, -fov_aspect*param_2/3, fov_aspect/3, fov_aspect * param_2, param_3, param_4);
	} else if (param_5 == 1) {
		GpgFrustum(-fov_aspect*param_2 / 3, fov_aspect*param_2/3, fov_aspect/3, fov_aspect, param_3, param_4);
	} else if (param_5 == 2) {
		GpgFrustum(fov_aspect*param_2 / 3, fov_aspect*param_2, fov_aspect/3, fov_aspect, param_3, param_4);
	} else if (param_5 == 3) {
		GpgFrustum(-fov_aspect*param_2, -fov_aspect*param_2/3, -fov_aspect/3, fov_aspect/3, param_3, param_4);
	} else if (param_5 == 4) {
    	GpgFrustum(-fov_aspect*param_2/3, fov_aspect*param_2/3, -fov_aspect/3,  fov_aspect/3, param_3, param_4);
	} else if (param_5 == 5) {
		GpgFrustum(fov_aspect*param_2/3, fov_aspect*param_2, -fov_aspect/3, fov_aspect/3, param_3, param_4);
	} else if (param_5 == 6) {
		GpgFrustum(-fov_aspect*param_2, -fov_aspect*param_2/3, -fov_aspect, -fov_aspect/3, param_3, param_4);
	} else if (param_5 == 7) {
		GpgFrustum(-fov_aspect*param_2/3, fov_aspect*param_2/3, -fov_aspect, -fov_aspect/3, param_3, param_4);
	} else if (param_5 == 8) {
		GpgFrustum(fov_aspect*param_2/3, fov_aspect*param_2, -fov_aspect, fov_aspect/3, param_3, param_4);
	}

	// switch(param_5) {
	// 	case -1:
	// 		GpgFrustum(-fov_aspect*param_2, fov_aspect*param_2, -fov_aspect, fov_aspect, param_3, param_4);
	// 		break;
	// 	case 0:
	// 		GpgFrustum(-fov_aspect*param_2, -fov_aspect*param_2/3, fov_aspect/3, fov_aspect * param_2, param_3, param_4);
	// 		break;
	// 	case 1:
	// 		GpgFrustum(-fov_aspect*param_2 / 3, fov_aspect*param_2/3, fov_aspect/3, fov_aspect, param_3, param_4);
	// 		break;
	// 	case 2:
	// 		GpgFrustum(fov_aspect*param_2 / 3, fov_aspect*param_2, fov_aspect/3, fov_aspect, param_3, param_4);
	// 		break;
	// 	case 3:
	// 		GpgFrustum(-fov_aspect*param_2, -fov_aspect*param_2/3, -fov_aspect/3, fov_aspect/3, param_3, param_4);
	// 		break;
	// 	case 4:
	// 		GpgFrustum(-fov_aspect*param_2/3, fov_aspect*param_2/3, -fov_aspect/3,  fov_aspect/3, param_3, param_4);
	// 		break;
	// 	case 5:
	// 		GpgFrustum(fov_aspect*param_2/3, fov_aspect*param_2, -fov_aspect/3, fov_aspect/3, param_3, param_4);
	// 		break;
	// 	case 6:
	// 		GpgFrustum(-fov_aspect*param_2, -fov_aspect*param_2/3, -fov_aspect, -fov_aspect/3, param_3, param_4);
	// 		break;
	// 	case 7:
	// 		GpgFrustum(-fov_aspect*param_2/3, fov_aspect*param_2/3, -fov_aspect, -fov_aspect/3, param_3, param_4);
	// 		break;
	// 	case 8:
	// 		GpgFrustum(fov_aspect*param_2/3, fov_aspect*param_2, -fov_aspect, fov_aspect/3, param_3, param_4);
	// 		break;
	// }
}


/* 10027DC0-10027F46 00186	*/
long cMagGameObject::ScreenGrab(IDirect3DDevice8* param_1, char* param_2) {
	SYSTEMTIME systemTime;
	GetLocalTime(&systemTime);

	char buffer[256];
	sprintf(buffer, "data\\screenshots\\screenshot%d%d%d%d.bmp", systemTime.wDay, systemTime.wHour, systemTime.wMinute, systemTime.wSecond);
	IDirect3DSurface8* surface;
	HRESULT result = param_1->GetBackBuffer(0, D3DBACKBUFFER_TYPE_MONO, &surface);
	if (result < D3D_OK) {
		return D3D_OK;
	}
	D3DSURFACE_DESC surface_Desc;
	result = surface->GetDesc(&surface_Desc);
	if (result < D3D_OK) {
		return D3D_OK;
	}
	IDirect3DSurface8* imageSurface;
	result = param_1->CreateImageSurface(GetWindowWidth(), GetWindowHeight(), surface_Desc.Format, &imageSurface);
	if (result < D3D_OK) {
		surface->Release();
		return D3D_OK;
	}

	RECT destRect; 
	destRect.left = 0;
	destRect.right = GetWindowWidth();
	destRect.top = 0;
	destRect.bottom = GetWindowHeight();

	result = D3DXLoadSurfaceFromSurface(imageSurface, NULL, &destRect, surface, NULL, NULL, 2, 0);
	surface->Release();
	if (result < D3D_OK) {
		imageSurface->Release();
		return D3D_OK;
	}
	
	result = D3DXSaveSurfaceToFile(buffer, D3DXIFF_BMP, imageSurface, NULL, NULL);
	if (result < D3D_OK) {
		imageSurface->Release();
		return D3D_OK;
	}

	imageSurface->Release();
	return result;
}

/* 10027F50-10028234 002E4	*/
HRESULT cMagGameObject::RenderTiled(char const* param_1, IDirect3DDevice8* param_2, int param_3, renderCallback param_4) {
	IDirect3DSurface8* surface;
	createFontResult = param_2->GetBackBuffer(0, D3DBACKBUFFER_TYPE_MONO, &surface);
	if (createFontResult < D3D_OK) {
		return createFontResult;
	}

	D3DSURFACE_DESC surface_Desc;
	createFontResult = surface->GetDesc(&surface_Desc);
	surface->Release();
	if (createFontResult < D3D_OK) {
		return createFontResult;
	}

	DebugLog("--------------titled 1------------");
	IDirect3DSurface8* imageSurface;
	uint width = surface_Desc.Width * param_3;
	uint height = surface_Desc.Height * param_3;
	createFontResult = param_2->CreateImageSurface(width, height, surface_Desc.Format, &imageSurface);
	if (createFontResult < D3D_OK) {
		return createFontResult;
	}

	DebugLog("--------------titled 2------------");
	D3DXMATRIX projectionMatrix;
	param_2->GetTransform(D3DTS_PROJECTION, &projectionMatrix);
	D3DXMATRIX matrix = projectionMatrix;
	DebugLog("--------------titled 2-1------------");
	matrix(0,0) = param_3 * matrix(0,0);
	matrix(1,1) = param_3 * matrix(1,1);



	for (int index1 = 0; index1 < param_3; index1++) {
		float maxPos = param_3 - 1;
		matrix(2,0) = maxPos - (12*index1); 
		for (int index2 = 0; index2 < param_3; index2++) {
			matrix(2,1) = - (maxPos - (index2 + index2));
			param_2->SetTransform(D3DTS_PROJECTION, &matrix);
			RenderScene();

			DebugLog("--------------titled 2-2------------");
			createFontResult = param_2->GetBackBuffer(0, D3DBACKBUFFER_TYPE_MONO, &surface);
			if (createFontResult < D3D_OK) {
				imageSurface->Release();
				return createFontResult;
			}
			DebugLog("--------------titled 3------------");

			RECT destRect; 
			destRect.left = index1 * surface_Desc.Width;
			destRect.right = destRect.left + surface_Desc.Width;
			destRect.top = index2 * surface_Desc.Height;
			destRect.bottom = destRect.top + surface_Desc.Height;

			createFontResult = D3DXLoadSurfaceFromSurface(imageSurface, NULL, &destRect, surface, NULL, NULL, 1, 0);
			surface->Release();
			if (createFontResult < D3D_OK) {
				imageSurface->Release();
				return createFontResult;
			}
			param_2->Present(NULL, NULL, NULL, NULL);
		}
	}

	DebugLog("--------------titled 4------------");
	param_2->SetTransform(D3DTS_PROJECTION, &projectionMatrix);
	createFontResult = D3DXSaveSurfaceToFile(param_1, D3DXIFF_BMP, imageSurface, NULL, NULL);
	imageSurface->Release();
	DebugLog("--------------titled 5------------");

	return createFontResult;
}

/* 10028240-100282ED 000AD	*/
void cMagGameObject::SetLastRender(cMagMeshObject* param_1) {
	int size = cMagEngineMgr::getInstance()->gameObject->meshObjects.size();
	for (int index = 0; index < size; index++) {
		char* param_name = param_1->GetObjectName();
		cMagKernel* object = cMagEngineMgr::getInstance()->gameObject->meshObjects[index];
		if (stricmp(param_name, object->GetObjectName()) == 0) {
			cMagGameObject* gameObject = cMagEngineMgr::getInstance()->gameObject;
			int size2 = gameObject->meshObjects.size();
			cMagKernel* temp = gameObject->meshObjects[size2-1];
			gameObject->meshObjects[size2-1] = gameObject->meshObjects[index];
			gameObject = cMagEngineMgr::getInstance()->gameObject;
			gameObject->meshObjects[index] = temp;
		}
	}
}

/* 100282F0-10028319 00029	*/
void cMagGameObject::swapObject(int param_1, int param_2) {
	cMagKernel* first = objects[param_1];
	objects[param_1] = objects[param_2];
	objects[param_2] = first;
}

/* 10028320-10028335 00015	*/
void cMagGameObject::swap(int& param_1, int& param_2) {
	int temp = param_1;
	param_1 = param_2;
	param_2 = temp;
}

/* 10028340-100283FE 000BE	*/
void cMagGameObject::qsort(int* param_1, int param_2, int param_3) {
	while (param_2 < param_3) {
		int pivotIndex = param_2;
		for (int j = param_2 + 1; j <= param_3; j++) {
			if (param_1[param_2] < param_1[j]) {
				pivotIndex++;
				swap(param_1[pivotIndex], param_1[j]);
				swapObject(pivotIndex, j);
			}
		}
		swap(param_1[param_2], param_1[pivotIndex]);
		swapObject(param_2, pivotIndex);
		qsort(param_1, param_2, pivotIndex-1);
		param_2 = pivotIndex+1;
	}
}

/* 10028400-10028D63 00963	*/
void cMagGameObject::SortObject() {

}

/* 10028D70-10028E2E 000BE	*/
void cMagGameObject::QSortMeshObject(int* param_1, int param_2, int param_3) {
	while (param_2 < param_3) {
		int pivotIndex = param_2;
		for (int j = param_2 + 1; j <= param_3; j++) {
			if (param_1[param_2] < param_1[j]) {
				pivotIndex++;
				swap(param_1[pivotIndex], param_1[j]);
				swapMeshObject(pivotIndex, j);
			}
		}
		swap(param_1[param_2], param_1[pivotIndex]);
		swapMeshObject(param_2, pivotIndex);
		QSortMeshObject(param_1, param_2, pivotIndex-1);
		param_2 = pivotIndex+1;
	}
}

/* 10028E30-10028E59 00029	*/
void cMagGameObject::swapMeshObject(int param_1, int param_2) {
	cMagKernel* first = meshObjects[param_1];
	meshObjects[param_1] = meshObjects[param_2];
	meshObjects[param_2] = first;
}

/* 10028E60-10028E74 00014	*/
void cMagGameObject::ShowObjectName(bool param_1) {
	cMagEngineMgr::getInstance()->gameObject->showObjectName = param_1;
}

/* 10028E80-10028E99 00019	*/
void cMagGameObject::SetDataPath(char* param_1) {
	dataPath = param_1;
	cMagEngineMgr::getInstance()->SetDataPath(param_1);
}

/* 10028EA0-10028EAE 0000E	*/
CGame* cMagGameObject::GetGame() {
	return cMagEngineMgr::getInstance()->gameObject->gameInstance;
}

/* 10028EB0-10028EBD 0000D	*/
void cMagGameObject::SetGame(CGame* param_1) {
	gameInstance = param_1;
}

/* 10028EC0-10028ECD 0000D	*/
void cMagGameObject::SetClipNear(float param_1) {
	nearPlane = param_1;
}

/* 10028ED0-10028EDD 0000D	*/
void cMagGameObject::SetClipFar(float param_1) {
	farPlane = param_1;
}

/* 10028EE0-10028EEE 0000E	*/
int cMagGameObject::GetWindowHeight() {
	return cMagEngineMgr::getInstance()->gameObject->windowHeight;
}

/* 10028EF0-10028EFE 0000E  */
int cMagGameObject::GetWindowWidth() {
	return cMagEngineMgr::getInstance()->gameObject->windowWidth;
}

/* 10028F00-10029006 00106	*/
MagTextureMgr cMagGameObject::GetTextureMgr() {
	return *MagTextureMgr::getInstance();
}

/* 10029010-10029031 00021	*/
void cMagGameObject::AllFiltersTexture() {
	MagTextureMgr::getInstance()->BeginFilterTexture();
	MagTextureMgr::getInstance()->BeginAlphaTexture();
	MagTextureMgr::getInstance()->BeginFilterVertexColorTexture();
}

/* 10029040-10029058 00018	*/
IDirect3DTexture8* cMagGameObject::ReplaceTexture(char* param_1, char* param_2) {
	return MagTextureMgr::getInstance()->ReplaceTexture(param_1, param_2);
}

/* 10029060-10029073 00013	*/
void cMagGameObject::DeleteTexture(char* param_1) {
	MagTextureMgr::getInstance()->DeleteTexture(param_1);
}

/* 10029080-10029094 00014	*/
void cMagGameObject::ShowGird(bool param_1) {
	cMagEngineMgr::getInstance()->gameObject->showGrid = param_1;
}

/* 100290A0-100290A9 00009	*/
IDirect3DDevice8* cMagGameObject::GetEngine() {
	return cMagEngineMgr::getInstance()->engine;
}

/* 100290B0-100290B7 00007	*/
float cMagGameObject::GetFOV() {
	return fov;
}

/* 100290C0-100290CD 0000D	*/
void cMagGameObject::SetFOV(float param_1) {
	fov = param_1;
}

/* 100290D0-10029119 00049	*/
void cMagGameObject::DrawTextA(int param_1, int param_2, char* param_3) {
	unkn_c08 = param_1;
	unkn_c04 = param_2;
	strcpy(cMagEngineMgr::getInstance()->gameObject->textToDraw, param_3);
}

/* 10029120-100291CE 000AE	*/
cMagKernel* cMagGameObject::GetMeshObject(char* param_1) {
	char buffer[256];
	for (int index = 0; index < cMagEngineMgr::getInstance()->gameObject->meshObjects.size(); index++) {
		cMagGameObject* gameObject = cMagEngineMgr::getInstance()->gameObject;
		cMagKernel* object = gameObject->meshObjects[index];
		strcpy(buffer, object->GetFileMeshName());
		if (stricmp(buffer, param_1) == 0) {
			return cMagEngineMgr::getInstance()->gameObject->meshObjects[index];
		}
	}
	return NULL;
}

/* 100291D0-10029228 00058	*/
cMagMeshObject* cMagGameObject::GetMeshObject(int param_1) {
	for (int index = 0; index < cMagEngineMgr::getInstance()->gameObject->meshObjects.size(); index++) {
		cMagKernel* object = cMagEngineMgr::getInstance()->gameObject->meshObjects[index];
		if (object->GetObjectID() == param_1) {
			return (cMagMeshObject*) cMagEngineMgr::getInstance()->gameObject->meshObjects[index];
		}
	}
	return NULL;
}

/* 10029230-100292FE 000CE	*/
cMagKernel* cMagGameObject::GetObjectsInRadiusFromClass(float param_1, D3DXVECTOR3 param_2, char* param_3) {
	D3DXVECTOR3 vector;
	for (int index = 0; index < cMagEngineMgr::getInstance()->gameObject->meshObjects.size(); index++) {
		char* className = cMagEngineMgr::getInstance()->gameObject->meshObjects[index]->GetClassNameA();
		if (stricmp(className, param_3) == 0) {
			cMagKernel* object = cMagEngineMgr::getInstance()->gameObject->meshObjects[index];
			vector = object->GetPosition()-param_2;
			float length = D3DXVec3Length(&vector);
			if (length <= param_1) {
				return cMagEngineMgr::getInstance()->gameObject->meshObjects[index];
			}
			
		}
	}
	return NULL;
}

/* 10029300-10029550 00250	*/
bool cMagGameObject::GetObjectsInRadiusFromClass(float param_1, D3DXVECTOR3 param_2, char* param_3, std::vector<cMagKernel*>& param_4) {
	D3DXVECTOR3 vector;
	for (int index = 0; index < cMagEngineMgr::getInstance()->gameObject->meshObjects.size(); index++) {
		char* className = cMagEngineMgr::getInstance()->gameObject->meshObjects[index]->GetClassNameA();
		if (stricmp(className, param_3) == 0) {
			cMagKernel* object = cMagEngineMgr::getInstance()->gameObject->meshObjects[index];
			vector = object->GetPosition()-param_2;
			float length = D3DXVec3Length(&vector);
			if (length <= param_1) {
				param_4.push_back(cMagEngineMgr::getInstance()->gameObject->meshObjects[index]);
			}
		}
	}
	return true;
}

/* 10029550-100296B1 00161	*/
cMagKernel* cMagGameObject::MagGetObject(char* param_1) {
	for (int index = 0; index < cMagEngineMgr::getInstance()->gameObject->meshObjects.size(); index++) {
		char* objectName = cMagEngineMgr::getInstance()->gameObject->meshObjects[index]->GetObjectName();
		if (stricmp(objectName, param_1) == 0) {
			return cMagEngineMgr::getInstance()->gameObject->meshObjects[index];
		}
	}

	for (index = 0; index < cMagEngineMgr::getInstance()->gameObject->particleObjects.size(); index++) {
		char* objectName = cMagEngineMgr::getInstance()->gameObject->particleObjects[index]->GetObjectName();
		if (stricmp(objectName, param_1) == 0) {
			return cMagEngineMgr::getInstance()->gameObject->particleObjects[index];
		}
	}

	for (index = 0; index < cMagEngineMgr::getInstance()->gameObject->spriteObjects.size(); index++) {
		char* objectName = cMagEngineMgr::getInstance()->gameObject->spriteObjects[index]->GetObjectName();
		if (stricmp(objectName, param_1) == 0) {
			return cMagEngineMgr::getInstance()->gameObject->spriteObjects[index];
		}
	}

	for (index = 0; index < cMagEngineMgr::getInstance()->gameObject->splineCameras.size(); index++) {
		char* objectName = cMagEngineMgr::getInstance()->gameObject->splineCameras[index]->GetObjectName();
		if (stricmp(objectName, param_1) == 0) {
			return cMagEngineMgr::getInstance()->gameObject->splineCameras[index];
		}
	}

	return NULL;
}

/* 100296C0-100296E4 00024	*/
void cMagGameObject::GetKokoPos(D3DXVECTOR3 param_1) {
	cMagEngineMgr::getInstance()->gameObject->kokoPos = param_1;
}

/* 100296F0-10029704 00014	*/
void cMagGameObject::SetVisibilityRange(float param_1) {
	cMagEngineMgr::getInstance()->gameObject->visibilityRange = param_1;

}

/* 10029710-1002971E 0000E	*/
float cMagGameObject::GetVisibilityRange() {
	return cMagEngineMgr::getInstance()->gameObject->visibilityRange;
}

/* 10029720-10029734 00014	*/
void cMagGameObject::SetSurfaceVisibilityRange(float param_1) {
	cMagEngineMgr::getInstance()->gameObject->surfaceVisibilityRange = param_1;
}

/* 10029740-1002974E 0000E	*/
float cMagGameObject::GetSurfaceVisibilityRange() {
	return cMagEngineMgr::getInstance()->gameObject->surfaceVisibilityRange;
}

/* 10029750-1002975E 0000E	*/
HWND__* cMagGameObject::GetHandleWindow() {
	return cMagEngineMgr::getInstance()->gameObject->hWnd;
}

/* 10029760-100297FD 0009D	*/
bool cMagGameObject::DestroyObject(cMagKernel* param_1) {
	if (DeleteMesh(param_1)) {
		return true;
	}
	if (DeleteBillboard(param_1)) {
		return true;
	}
	if (DeleteCamera(param_1)) {
		return true;
	}
	if (DeleteParticle(param_1)) {
		return true;
	}
	if (DeleteTerrain(param_1)) {
		return true;
	}
	if (DeleteLensFlare(param_1)) {
		return true;
	}
	if (DeleteSun(param_1)) {
		return true;
	}
	if (DeleteSky(param_1)) {
		return true;
	}
	return false;
}

/* 10029800-10029889 00089	*/
bool cMagGameObject::DeleteMesh(cMagKernel* param_1) {
	cMagGameObject* mesh = dynamic_cast<cMagGameObject*>(param_1);
	if (mesh == NULL) {
		return false;
	}
	
	for (std::vector<cMagKernel*>::iterator it = meshObjects.begin(); 
			it != meshObjects.end(); it++) {
		if (*it == param_1) {
			meshObjects.erase(it);
			delete mesh;
			return true;
		}
	}
	return false;
}

/* 10029890-10029919 00089	*/
bool cMagGameObject::DeleteBillboard(cMagKernel* param_1) {
	cMagBillboard* billboard = dynamic_cast<cMagBillboard*>(param_1);
	if (billboard == NULL) {
		return false;
	}
	
	for (std::vector<cMagKernel*>::iterator it = billboardObjects.begin(); 
			it != billboardObjects.end(); it++) {
		if (*it == param_1) {
			billboardObjects.erase(it);
			delete billboard;
			return true;
		}
	}
	return false;
}

/* 10029920-100299A9 00089	*/
bool cMagGameObject::DeleteCamera(cMagKernel* param_1) {
	cMagCamera* camera = dynamic_cast<cMagCamera*>(param_1);
	if (camera == NULL) {
		return false;
	}
	
	for (std::vector<cMagKernel*>::iterator it = cameraObjects.begin(); 
			it != cameraObjects.end(); it++) {
		if (*it == param_1) {
			cameraObjects.erase(it);
			delete camera;
			return true;
		}
	}
	return false;
}

/* 100299B0-10029A39 00089	*/
bool cMagGameObject::DeleteParticle(cMagKernel* param_1) {
	CParticleEmitter* particle = dynamic_cast<CParticleEmitter*>(param_1);
	if (particle == NULL) {
		return false;
	}
	
	for (std::vector<cMagKernel*>::iterator it = particleObjects.begin(); 
			it != particleObjects.end(); it++) {
		if (*it == param_1) {
			particleObjects.erase(it);
			delete particle;
			return true;
		}
	}
	return false;
}

/* 10029A40-10029A84 00044	*/
bool cMagGameObject::DeleteTerrain(cMagKernel* param_1) {
	MagTerrain* terrain = dynamic_cast<MagTerrain*>(param_1);
	if (terrain == NULL) {
		return false;
	}

	delete terrain;
	terrainObject = NULL;
	return true;
}

/* 10029A90-10029AD4 00044	*/
bool cMagGameObject::DeleteLensFlare(cMagKernel* param_1) {
	CLensFlare* lensFlare = dynamic_cast<CLensFlare*>(param_1);
	if (lensFlare == NULL) {
		return false;
	}

	delete lensFlare;
	this->lensFlare = NULL;
	return true;
}

/* 10029AE0-10029B24 00044	*/
bool cMagGameObject::DeleteSun(cMagKernel* param_1) {
	cMagSun* sun = dynamic_cast<cMagSun*>(param_1);
	if (sun == NULL) {
		return false;
	}

	delete sun;
	sunObject = NULL;
	return true;
}

/* 10029B30-10029B74 00044	*/
bool cMagGameObject::DeleteSky(cMagKernel* param_1) {
	cMagSkyBox* sky = dynamic_cast<cMagSkyBox*>(param_1);
	if (sky == NULL) {
		return false;
	}

	delete sky;
	skyBoxObject = NULL;
	return true;
}

/* 10029B80-10029B8E 0000E	*/
MagTerrain* cMagGameObject::GetTerrain() {
	return 0;
}

/* 10029B90-10029B9E 0000E	*/
CLensFlare* cMagGameObject::GetLensFlare() {
	return 0;
}

/* 10029BA0-10029BAE 0000E	*/
cMagSun* cMagGameObject::GetSun() {
	return 0;
}

/* 10029BB0-10029BBE 0000E	*/
cMagSkyBox* cMagGameObject::GetSky() {
	return 0;
}

/* 10029BC0-10029BCE 0000E	*/
cMagFog* cMagGameObject::GetFog() {
	return 0;
}

/* 10029BD0-10029BDB 0000B	*/
void cMagGameObject::ClearTextures() {
}

/* 10029BE0-10029C01 00021	*/
void cMagGameObject::EnableSkyRendering(bool param_1) {
}

/* 10029C10-10029C33 00023	*/
void cMagGameObject::EnableSunRendering(bool param_1) {
}

/* 10029C40-10029C6C 0002C	*/
void cMagGameObject::EnableLensFlareRendering(bool param_1) {
}

/* 10029C70-10029C95 00025	*/
void cMagGameObject::EnableFog(bool param_1) {
}

/* 10029CA0-10029CA9 00009	*/
void cMagGameObject::ExitGame() {
	PostQuitMessage(0);
}

/* 10029CB0-10029D60 000B0	*/
float cMagGameObject::GetDistanceTo(char* param_1, D3DXVECTOR3 param_2) {
	return 0;
}

/* 10029D60-10029DB6 00056	*/
float cMagGameObject::GetDistanceTo(D3DXVECTOR3 param_1) {
	return 0;
}

/* 10029DC0-10029FF2 00232	*/
void cMagGameObject::GetDistanceTo(char* param_1, D3DXVECTOR3 param_2, std::vector<float>* param_3) {
}

/* 1002A000-1002A393 00393	*/
long cMagGameObject::RenderTiled(char* param_1, IDirect3DDevice8* param_2, int param_3) {
	return 0;
}

/* 1002A3A0-1002A6C5 00325	*/
long cMagGameObject::ScaleRender() {
	return 0;
}

/* 1002A6D0-1002A6E4 00014	*/
void cMagGameObject::AddLight(_LIGHT* param_1) {
	DebugLog("--------- Dodaje swiatlo -------------");
}

/* 1002A6F0-1002A6FB 0000B	*/
void cMagGameObject::ClearMeshList() {
}

/* 1002A700-1002A72F 0002F	*/
void cMagGameObject::SetActiveCamera(CCamera* param_1) {
	if (activeCamera != NULL) {
		activeCamera->OnDeactivateView();
	}
	activeCamera = param_1;
	if (param_1 != NULL) {
		param_1->OnActivateView();
	}
}

/* 1002A730-1002A73E 0000E	*/
CCamera* cMagGameObject::GetActiveCamera() {
	return cMagEngineMgr::getInstance()->gameObject->activeCamera;
}

/* 1002A740-1002A7DB 0009B	*/
void cMagGameObject::UpdateActiveCamera() {
}

/* 1002A7E0-1002A802 00022	*/
void cMagGameObject::RenderActiveCamera() {
	if (activeCamera != NULL) {
		activeCamera->OnRender();
		activeCamera->vtbl_0x4c();
	}
}

/* 1002A810-1002A86D 0005D	*/
D3DXVECTOR3 cMagGameObject::RotateVector(D3DXVECTOR3* param_1, D3DXVECTOR3* param_2, float param_4) {
	return 0;
}

/* 1002A870-1002A87D 0000D	*/
char* cMagGameObject::GetLevelDirectory() {
	return cMagEngineMgr::getInstance()->gameObject->levelDirectory;
}

/* 1002A880-1002A89B 0001B	*/
void cMagGameObject::SetMagWindowTitle(char* param_1) {
	cMagGameObject* gameObject = cMagEngineMgr::getInstance()->gameObject;
	SetWindowText(gameObject->GetHandleWindow(), param_1);
}

/* 1002A8A0-1002AA3E 0019E	*/
void cMagGameObject::DXDiags() {
}

/* 1002AA40-1002AB0E 000CE	*/
bool cMagGameObject::InitMusicManager() {
	return 0;
}

/* 1002AB10-1002AB46 00036	*/
void cMagGameObject::DestroyMusicManager() {
}

/* 1002AB50-1002AB5E 0000E	*/
uchar cMagGameObject::GetMusicManager() {
	return 0;
}

/* 1002AB60-1002AC0C 000AC	*/
bool cMagGameObject::InitSoundManager() {
	return 0;
}

/* 1002AC10-1002AC3B 0002B	*/
void cMagGameObject::DestroySoundManager() {
}

/* 1002AC40-1002AC4E 0000E	*/
CSoundManager* cMagGameObject::GetSoundManager() {
	return 0;
}

/* 1002AC50-1002AC64 00014	*/
void cMagGameObject::MememberPlayerObject(cMagMeshObject* param_1) {
	cMagEngineMgr::getInstance()->gameObject->playerObject = param_1;
}

/* 1002AC70-1002AC7E 0000E	*/
cMagMeshObject* cMagGameObject::GetPlayerObject() {
	return cMagEngineMgr::getInstance()->gameObject->playerObject;
}

/* 1002AC80-1002AC94 00014	*/
void cMagGameObject::EnableLinkMeshToSector(bool param_1) {
	cMagEngineMgr::getInstance()->gameObject->enableLinkMeshToSector = param_1;
}

/* 1002ACA0-1002ACAE 0000E	*/
bool cMagGameObject::EnableLinkMeshToSector() {
	return cMagEngineMgr::getInstance()->gameObject->enableLinkMeshToSector;
}

/* 1002ACB0-1002ACB5 00005	*/
void cMagGameObject::LinkMeshToSector() {
	EnableLinkMeshToSector();
}

/* 1002ACC0-1002AD24 00064	*/
bool cMagGameObject::InSector(D3DXVECTOR3 param_1, D3DXVECTOR3 param_2, D3DXVECTOR3 param_3) {
	return 0;
}

/* 1002AD30-1002AE29 000F9	*/
void cMagGameObject::SetState(char* param_1) {
}

/* 1002AE30-1002AEE0 000B0	*/
void cMagGameObject::SetState(CState* param_1) {
}

/* 1002AEE0-1002AF1E 0003E	*/
int cMagGameObject::GetAllFaceCount() {
	int faceCount = 0;
	for (int index = 0; index < cMagEngineMgr::getInstance()->gameObject->meshObjects.size(); index++) {
		cMagMeshObject* meshObject = (cMagMeshObject*) cMagEngineMgr::getInstance()->gameObject->meshObjects[index];
		if (meshObject != NULL) {
			faceCount += meshObject->GetFaceCount();
		}
	}
	return faceCount;
}

/* 1002AF20-1002B27C 0035C	*/
void cMagGameObject::CreateDxFont() {
}

/* 1002B280-1002B294 00014	*/
void cMagGameObject::EnableCallHandlerWindowKey(cMagGameObject* param_1) {
	cMagEngineMgr::getInstance()->gameObject->callHandlerWindowKey = param_1;
}

/* 1002B2A0-1002B2B4 00014	*/
void cMagGameObject::EnableHandlerOnFrame1(cMagGameObject* param_1) {
	cMagEngineMgr::getInstance()->gameObject->callHandlerOnFrame1 = param_1;
}

/* 1002B2C0-1002B568 002A8	*/
void cMagGameObject::DrawBigSquareShadow() {
}

/* 1002B570-1002B6FB 0018B	*/
void cMagGameObject::CreateBigSquareShadow() {
}

/* 1002B700-1002B70D 0000D	*/
void cMagGameObject::EnableBigSquareShadow(bool param_1) {
	enableBigSquareShadow = param_1;
}

/* 1002B710-1002B803 000F3	*/
long cMagGameObject::CreateTextureFromFileInZip(IDirect3DDevice8 * param_1, char* param_2, char* param_3, IDirect3DTexture8** param_4) {
	return 0;
}

/* 1005A5F0-1005A5F3 00003	*/
void cMagGameObject::AddLightmapMesh(Mesh* param_1, char* param_2) {
}

/* 1006CED0-1006CED3 00003	*/
ulong cMagGameObject::GetDXVersion() {
	return 0;
}

/* 1009CC10-1009CCD3 000C3	*/
uint cMagGameObject::FUN_1009cc10(char* param_1) {
	return 0;
}

/* 1009DF70-1009E862 008F2	*/
int cMagGameObject::CreateObject(char* param_1) {
	return 0;
}

