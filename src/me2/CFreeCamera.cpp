#include "CFreeCamera.h"

#include "cMagEngineMgr.h"

/* 10061C20-10061CD8 000B8	*/
CFreeCamera::CFreeCamera()
{
	EnableCallHandler("OnFrame");
	EnableCallHandler("OnInputKey");
	EnableCallHandler("OnInputMouse");
	unk_df0 = 0.0;
	unk_df8 = 0.0;
	activeWindow = cMagEngineMgr::getInstance()->gameObject->hWnd;
	freeCameraSpeed = 500.0f;
	unk_e10 = true;
	freeCameraAngSpeed = 0.1f;
	ReadSettings("data\\Ustawienia.cfg");
}

/* 10061CE0-10061CEB 0000B	*/
CFreeCamera::~CFreeCamera()
{
}

/* 10061CF0-10061D07 00017	*/
void CFreeCamera::OnInputKey(uchar *param_1)
{
	GetUpdate(TRUE);
	CheckWindowActivation();
}

/* 10061D10-10061E88 00178	*/
void CFreeCamera::OnInputMouse(float param_1, float param_2, bool param_3, bool param_4)
{
	double local_34 = GetUpdate(FALSE);
	if (!CheckWindowActivation())
	{
		return;
	}

	RECT local_10;
	GetWindowRect(activeWindow, &local_10);
	int centerX = (local_10.right - local_10.left) / 2 + local_10.left;
	int centerY = (local_10.bottom - local_10.top) / 2 + local_10.top;
	POINT cursorPoint;
	GetCursorPos(&cursorPoint);
	float fVar5 = (cursorPoint.x - centerX) * freeCameraSpeed;
	float fVar6 = (cursorPoint.y - centerY) * freeCameraSpeed;
	Rotate(D3DXVECTOR3(0.0f, 1.0f, 0.0f), fVar5, false);
	Rotate(GetRight(), fVar6, false);
	SetCursorPos(centerX, centerY);
	float speed = freeCameraSpeed;
	speed *= GetAsyncKeyState(VK_CONTROL) < 0 ? 10 : 1;
	speed *= GetAsyncKeyState(VK_SHIFT) < 0 ? 1.6 : 1.0;
	speed *= local_34;
	D3DXVECTOR3 dirSpeed = speed * GetDirection();
	if (param_3) {
		SetPosition(dirSpeed + GetPosition());
	}

	if (param_4) {
		SetPosition(GetPosition() - dirSpeed);
	}

	CCamera::OnInputMouse(param_1, param_2, param_3, param_4);
}

/* 10061F80-10062042 000C2	*/
double CFreeCamera::GetUpdate(int param_1)
{
	double time = timeGetTime();
	double dVar2 = 0.0;
	if (param_1 == TRUE){
		if (unk_df0 != 0.0)
		{
			dVar2 = time - unk_df0;
		}
		unk_df0 = time;
		return dVar2 * 0.001;
	} 
	
	if (param_1 == FALSE){
		if (unk_df8 != 0.0)
		{
			dVar2 = time - unk_df8;
		}
		unk_df8 = time;
		return dVar2 * 0.001;
	}
	return dVar2;
}

/* 10062050-100620B6 00066	*/
void CFreeCamera::OnActivateView()
{
	GetUpdate(FALSE);
	GetUpdate(TRUE);
	RECT local_10;
	GetWindowRect(activeWindow, &local_10);
	uint diffX = (local_10.right - local_10.left) / 2;
	uint diffY = (local_10.bottom - local_10.top) / 2;
	int centerX = diffX + local_10.left;
	int centerY = diffY + local_10.top;
	SetCursorPos(centerX, centerY);
	CCamera::OnActivateLevel();
}

/* 100620C0-100620CD 0000D	*/
void CFreeCamera::SetSpeedValue(float param_1)
{
	freeCameraSpeed = param_1;
}

/* 100620D0-10062113 00043	*/
bool CFreeCamera::CheckWindowActivation()
{
	if (GetActiveWindow() != activeWindow)
	{
		unk_e10 = false;
	}
	else
	{
		if (!unk_e10)
		{
			OnActivateView();
		}
		unk_e10 = true;
	}
	return unk_e10;
}

/* 10062120-10062234 00114	*/
void CFreeCamera::ReadSettings(char *param_1)
{
	FILE *file = fopen(param_1, "r");

	if (file == NULL)
	{
		return;
	}

	char buffer[100];
	ZeroMemory(buffer, sizeof(buffer));
	while (!feof(file))
	{
		fgets(buffer, 99, file);
		char *name = strtok(buffer, " :,");
		if (stricmp(name, "FreeCameraSpeed") == 0)
		{
			name = strtok(NULL, " :");
			if (name != NULL)
			{
				freeCameraSpeed = atof(name);
			}
		}

		if (stricmp(name, "FreeCameraAngSpeed") == 0)
		{
			name = strtok(NULL, " :");
			if (name != NULL)
			{
				freeCameraAngSpeed = atof(name);
			}
		}

		if (stricmp(name, "FreeCameraFOV") == 0)
		{
			char *val = strtok(NULL, " :");
			if (val != NULL)
			{
				fov = atof(val);
			}
		}
	}
	fclose(file);
}
