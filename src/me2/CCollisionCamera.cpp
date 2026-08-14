#include "CCollisionCamera.h"

#include "cMagEngineMgr.h"

/* 10012910-10012911 00001	*/
void CCollisionCamera::OnFrame() {
}


/* 10060BF0-10060C02 00012	*/
CCollisionCamera::CCollisionCamera() {
}

/* 10060C10-10060C65 00055	*/
CCollisionCamera::CCollisionCamera(cMagMeshObject* param_1, bool param_2) {
	Create(param_1, param_2);
}

/* 10060C70-10060C7B 0000B	*/
CCollisionCamera::~CCollisionCamera() {
}

/* 10060C80-10060DAA 0012A	*/
void CCollisionCamera::Create(cMagMeshObject* param_1, bool param_2) {
	if (param_2) {
		cMagEngineMgr::getInstance()->gameObject->collision->FUN100A6BD0(this);
	}
	SetObjectName("No name");
	SetClassName("cMagCamera");
	observedObject = param_1;
	distance = 400.0f;
	angle = 31.0f;
	lookAtAngle = -15.0f;
	lastMeasureTime = 0;
	direction = param_1->GetDirection();
	dirDelay1 = 0.5f;
	dirDelay2 = 0.5f;
	xzPosDelay = 0.3f;
	yPosDelay = 0.5f;
	maxMultipleDist = 3.0f;
	addObservedY = 50.0f;
	ReadSettings("data\\Ustawienia.cfg");
	isAfterPauseDelay = true;
	unk_df0 = D3DXVECTOR3(0,0,0);
	paused = false;
	isOppositeDirection = false;
	rotSpeedY = 0.0f;
	distanceToObserved = 0;
}

/* 10060DB0-10060DBD 0000D	*/
void CCollisionCamera::Update(float param_1) {
	Update2(param_1);
}

/* 10060DC0-10060DDD 0001D	*/
void CCollisionCamera::SetRadius(D3DXVECTOR3 param_1) {
	radius = param_1;
}

/* 10060DE0-10060DED 0000D	*/
void CCollisionCamera::SetAngle(float param_1) {
	angle = param_1;
}

/* 10060DF0-10060DFD 0000D	*/
void CCollisionCamera::SetDistance(float param_1) {
	distance = param_1;
}

/* 10060E00-10060E0D 0000D	*/
void CCollisionCamera::SetLookAtAngle(float param_1) {
	lookAtAngle = param_1;
}

/* 10060E10-10060FC9 001B9	*/
void CCollisionCamera::OnInputKey(uchar* param_1) {
	cMagGameObject* gameObject = cMagEngineMgr::getInstance()->gameObject;
	ulong nanoTime = timeGetTime();
	ulong timeDiff = (nanoTime - lastMeasureTime);
	float fStack_d8 = timeDiff * 0.001;
	if (lastMeasureTime == 0) {
		fStack_d8 = 0.0f;
	}

	if (param_1[2] != 0) {
		float newDistance;
		if (param_1[42] == 0) {
			newDistance = distance - fStack_d8 * 20.0f;
		} else {
			newDistance = fStack_d8 * 20.0f + distance;
		}
		distance = newDistance;
	}

	if (param_1[3] != 0) {
		float newAngle;
		if (param_1[42] == 0) {
			newAngle = angle - fStack_d8 * 10.0f;
		} else {
			newAngle = fStack_d8 * 10.0f + angle;
		}
		angle = newAngle;
	}

	if (param_1[4] != 0) {
		float newLookAtAngle;
		if (param_1[42] == 0) {
			newLookAtAngle = fStack_d8 * 10.0f + lookAtAngle;
		} else {
			newLookAtAngle = lookAtAngle - fStack_d8 * 10.0f;
		}
		lookAtAngle = newLookAtAngle;
	}

	if (param_1[5] != 0) {
		float newFov;
		if (param_1[42] == 0) {
			newFov = GetFOV() - fStack_d8 * 5.0f;
			SetFOV(newFov);
			CrashLog("f : %f", newFov);
		} else {
			newFov = fStack_d8 * 5.0f + GetFOV();
			SetFOV(newFov);
			CrashLog("f : %f", newFov);
		}
	}
	lastMeasureTime = nanoTime;
	char buffer[200];
	sprintf(buffer, "Distance: %f, Angle: %f, View Angle %f, FOV: %f ",
		distance, angle, lookAtAngle, gameObject->GetFOV());
	gameObject->DrawTextA(30, 25, buffer);
}

/* 10060FD0-1006103E 0006E	*/
D3DXVECTOR3 CCollisionCamera::GetObservedPosition() {
	if (!paused) {
		observedPosition = observedObject->GetPosition();
		observedPosition.y = observedPosition.y + addObservedY;
	}
	return observedPosition;
}

/* 10061040-10061086 00046	*/
D3DXVECTOR3 CCollisionCamera::GetOffset() {
	return GetPosition() - GetObservedPosition();
}

/* 10061090-100610B1 00021	*/
D3DXVECTOR3 CCollisionCamera::GetRadius() {
	return radius;
}

/* 100610C0-10061104 00044	*/
void CCollisionCamera::UpdateView() {
	D3DXMATRIX mat = cameraVectors;
	D3DXMatrixInverse(&mat, NULL, &cameraVectors);
	cMagEngineMgr::getInstance()->engine->SetTransform(D3DTS_VIEW, &mat);
}

/* 10061110-10061182 00072	*/
float CCollisionCamera::GetDistenceToObserved() {
	if (observedObject == NULL) {
		return 0.0f;
	}
	
	D3DXVECTOR3 local_18 = observedObject->GetPosition();
	D3DXVECTOR3 stack_c = GetPosition();
	distanceToObserved = D3DXVec3Length(&(local_18 - stack_c));
	return distanceToObserved;
}

/* 10061190-100615AA 0041a	*/
void CCollisionCamera::Update2(float param_1) {
	if (firstUpdateAfterPause) {
		param_1 = 0.0f;
	}

	D3DXVECTOR3 local_98 = GetObservedPosition();
	D3DXVECTOR3 local_c0 = direction;
	D3DXVECTOR3 local_a4 = GetPosition();
	SetUp(observedObject->GetUp());
	SetDirection(GetObservedDirection());
	D3DXMATRIX Dstack_80;
	D3DXMatrixRotationAxis(&Dstack_80, &GetRight(), GpgDegToRad(angle));
	SetPosition(D3DXVECTOR3(0,0,0));
	D3DXMatrixMultiply(&cameraVectors, &cameraVectors, &Dstack_80);
	D3DXVECTOR3 Dstack_b4(cameraVectors(2,0), cameraVectors(2,1), cameraVectors(2,2));
	if (param_1 != 0.0f && !firstUpdateAfterPause) {
		float fVar7 = dirDelay1 / param_1;
		if (fVar7 < 1.0f) {
			fVar7 = 1.0f;
		}
		Dstack_b4.x = (Dstack_b4.x - local_c0.x) / fVar7 + local_c0.x; 
		Dstack_b4.y = (Dstack_b4.y - local_c0.y) / fVar7 + local_c0.y; 
		Dstack_b4.z = (Dstack_b4.z - local_c0.z) / fVar7 + local_c0.z; 
		SetDirection(Dstack_b4);
	}
	D3DXVec3Normalize(&Dstack_b4, &Dstack_b4);
	direction = GetDirection();
	D3DXMATRIX DStack_40;
	D3DXMatrixRotationAxis(&DStack_40, &GetRight(), GpgDegToRad(lookAtAngle));
	D3DXMatrixMultiply(&cameraVectors, &cameraVectors, &DStack_40);
	D3DXVECTOR3 DStack_cc(local_98 + -distance * Dstack_b4);
	if (param_1 != 0.0f && !firstUpdateAfterPause) {
		float fStack_a8 = xzPosDelay / param_1;
		float fVar7 = yPosDelay / param_1;
		if (fStack_a8 < 1.0f) {
			fStack_a8 = 1.0f;
		}
		if (fVar7 < 1.0f) {
			fVar7 = 1.0f;
		}
		DStack_cc.x = (DStack_cc.x - local_a4.x) / fStack_a8 + local_a4.x; 
		DStack_cc.y = (DStack_cc.y - local_a4.y) / fVar7 + local_a4.y; 
		DStack_cc.z = (DStack_cc.z - local_a4.z) / fStack_a8 + local_a4.z; 
	}
	D3DXVECTOR3 diff = DStack_cc - GetObservedPosition();
	float fVar2 = D3DXVec3Length(&diff);
	if (fVar2 > maxMultipleDist * distance) {
		local_c0.z = maxMultipleDist * distance / fVar2;
		DStack_cc = GetObservedPosition() + diff * local_c0.z;
	}
	SetPosition(DStack_cc);
	firstUpdateAfterPause = false;
	dirDelay1 = dirDelay2;
}

/* 100615B0-100615BD 0000D	*/
void CCollisionCamera::SetRotSpeedY(float param_1) {
	rotSpeedY = param_1;
}

/* 100615C0-10061709 00149	*/
void CCollisionCamera::Update3(float param_1) {
	if (firstUpdateAfterPause) {
		param_1 = 0.0f;
	}

	D3DXVECTOR3 local_c = direction;
	SetUp(observedObject->GetUp());
	SetDirection(GetObservedDirection());
	D3DXVECTOR3 local_18(cameraVectors(2,0), cameraVectors(2,1), cameraVectors(2,2));
	if (param_1 != 0.0f && !firstUpdateAfterPause) {
		float fVar1 = dirDelay1 / param_1;
		if (fVar1 < 1.0f) {
			fVar1 = 1.0f;
		}
		local_18.x = (local_18.x - local_c.x) / fVar1 + local_c.x;
		local_18.y = (local_18.y - local_c.y) / fVar1 + local_c.y;
		local_18.z = (local_18.z - local_c.z) / fVar1 + local_c.z;
		SetDirection(local_18);
	}
	direction = GetDirection();
	firstUpdateAfterPause = false;
	dirDelay1 = dirDelay2;
}

/* 10061740-100619A8 00268	*/
void CCollisionCamera::ReadSettings(char* param_1) {
	FILE *file = fopen(param_1, "r");

	if (file == NULL) {
		return;
	}

	char buffer[100];
	ZeroMemory(buffer, sizeof(buffer));
	while (!feof(file)) {
		fgets(buffer, 99, file);
		char *name = strtok(buffer, " :,");
		if (stricmp(name, "DirDelay") == 0) {
			name = strtok(NULL, " :");
			if (name != NULL) {
				float delay = atof(name);
				dirDelay1 = delay;
				dirDelay2 = delay;
			}
		}

		if (stricmp(name, "XZPosDelay") == 0) {
			name = strtok(NULL, " :");
			if (name != NULL) {
				xzPosDelay = atof(name);
			}
		}

		if (stricmp(name, "YPosDelay") == 0) {
			name = strtok(NULL, " :");
			if (name != NULL) {
				yPosDelay = atof(name);
			}
		}

		if (stricmp(name, "MaxMultipleDist") == 0) {
			name = strtok(NULL, " :");
			if (name != NULL) {
				maxMultipleDist = atof(name);
			}
		}

		if (stricmp(name, "AddObservedY") == 0) {
			name = strtok(NULL, " :");
			if (name != NULL) {
				addObservedY = atof(name);
			}
		}

		if (stricmp(name, "Distance") == 0) {
			name = strtok(NULL, " :");
			if (name != NULL) {
				distance = atof(name);
			}
		}

		if (stricmp(name, "Angle") == 0) {
			name = strtok(NULL, " :");
			if (name != NULL) {
				angle = atof(name);
			}
		}

		if (stricmp(name, "LookAtAngle") == 0) {
			name = strtok(NULL, " :");
			if (name != NULL) {
				lookAtAngle = atof(name);
			}
		}

		if (stricmp(name, "FOV") == 0) {
			name = strtok(NULL, " :");
			if (name != NULL) {
				float fov = atof(name);
				cMagEngineMgr::getInstance()->gameObject->SetFOV(fov);
			}
		}
	}
	fclose(file);
}

/* 100619B0-100619C7 00017	*/
void CCollisionCamera::SetOppositeDirection(bool param_1) {
	dirDelay1 = 0.001f;
	isOppositeDirection = param_1;
}

/* 100619D0-100619D7 00007	*/
bool CCollisionCamera::GetOppositeDirection() {
	return isOppositeDirection;
}

/* 100619E0-10061A89 000A9	*/
D3DXVECTOR3 CCollisionCamera::GetObservedDirection() {
	if (!paused) {
		if (isOppositeDirection) {
			observedDirection = -observedObject->GetDirection();
		} else {
			observedDirection = observedObject->GetDirection();
		}
	}
	return observedDirection;
}

/* 10061A90-10061AB2 00022	*/
void CCollisionCamera::Pause(bool param_1) {
	paused = param_1;
	if (!param_1 && !isAfterPauseDelay) {
		firstUpdateAfterPause = true;
	}
}

/* 10061AC0-10061ACD 0000D	*/
void CCollisionCamera::AfterPauseDelay(bool param_1) {
	isAfterPauseDelay = param_1;
}

