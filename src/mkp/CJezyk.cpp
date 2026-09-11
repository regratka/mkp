#include "CJezyk.h"

#include "GameSDK.h"
#include "CPlayerTPP.h"
#include "CSplineCamera.h"

/* 4164E0-4164E3 00003	*/
void CJezyk::OnDestTime(float param_1) {
}

/* 419BA0-419BA1 00001	*/
void CJezyk::OnActivate() {
}

/* 4262D0-4262FA 0002A	*/
void CJezyk::OnLoadChunk(_ED_CHUNK param_1, std::ifstream& param_2) {
	if (param_1.chunkType == 15 && param_1.chunkDataSize == 200) {
		param_2.read(navigationPath, 200);
	}
}

/* 43D110-43D255 00145	*/
CJezyk::CJezyk() {
	ZeroMemory(navigationPath, sizeof(navigationPath));
	visitedNaviPoints = 0;
	allCapturedSoundID = -1;
	patrolObject = NULL;
	nextWalkPoint = NULL;
	destinationPosition = D3DXVECTOR3(0.0f,0.0f,0.0f);
	walkPathPoints.reserve(100);
}

/* 43D280-43D2BC 0003C	*/
CJezyk::~CJezyk() {
}

/* 43D2C0-43D31A 0005A	*/
void* CJezyk::EXP() {
	return new CJezyk();
}

/* 43D320-43D41E 000FE	*/
void CJezyk::OnActivateLevel() {
	EnableFrustumPhysicsPause(false);
	SetGravityAcceleration(200.0f);
	patrolObject = MagGetObject("patrol01");
	StartRunning();
	if (navigationPath[0] != '\0') {
		CreateNavigationPath(navigationPath);
	}
	allCapturedSoundID = LoadSound("data\\sounds\\papatka\\P_jezowa-2.wav");
	GameSDK* sdk = ((GameSDK*) GetGame());
	float fVar3 = sdk->FUN00401e10();
	SetVolume(allCapturedSoundID, fVar3);
	StopSound(allCapturedSoundID);
	SetState(new WalkNaviPath());
}

/* 43D420-43D4D0 000B0	*/
void CJezyk::OnLastCaptured() {
	if (GetPlayerObject() != NULL) {
		((CPlayerTPP*) GetPlayerObject())->FUN00409ff0(true);
	}

	if (((CPlayerTPP*) GetPlayerObject())->unk_3990 != NULL) {
		((CPlayerTPP*) GetPlayerObject())->unk_3990->FUN0042d590(false);
		((CPlayerTPP*) GetPlayerObject())->unk_3990->FUN0042d540(true);
	}

	EnableCallHandlerOnPlaySoundEnd(allCapturedSoundID);
	PlaySoundA(allCapturedSoundID, false);
	CSplineCamera* camera = (CSplineCamera*) MagGetObject("Camera02"); 
	camera->SetHandlerObject(this);
	camera->SetDestTime(-1.0f);
	GetGame()->SetActiveCamera(camera);
	camera->Play(0.0f);
	
}

/* 43D4D0-43D4F4 00024	*/
void CJezyk::OnPlaySoundEnd(int param_1) {
	if (param_1 == allCapturedSoundID) {
		GetGame()->LoadLevel("data\\levels\\Level03\\Level03.lev");
	}
}

/* 43D500-43D5E6 000E6	*/
void CJezyk::SetAsCaptured() {
	EnableRendering(false);
	EnableCollision(false);
	if (((CPlayerTPP*) GetPlayerObject())->unk_3990 != NULL) {
		((CPlayerTPP*) GetPlayerObject())->unk_3990->FUN0042d320();
	}

	int iVar1 = ((CPlayerTPP*) GetPlayerObject())->unk_3990->FUN0042d450();
	if (iVar1 == 8) {
		cMagKernel* pcVar2 = MagGetObject("sound01");
		if (pcVar2 != NULL) {
			pcVar2->OnAction();
		}
		OnLastCaptured();
		return;
	}

	SetState(new Idle());
}

/* 43D5F0-43D613 00023	*/
void CJezyk::StartRunning() {
	InitAnimSeq("Run", 0, 51);
	SetAnimFreq("Run", 35);
}

/* 43D620-43D7B2 00192	*/
bool CJezyk::FindNextControlPoint() {
	float local_1c = 1e11;
	AIControlPoint* this_00 = NULL;
	walkPathPoints.clear();
	GetObjectsInRadiusFromClass(5000000.0f, GetPosition(), "AIControlPoint", *((std::vector<cMagKernel*>*) &walkPathPoints));
	
	for (int index = 0; index < walkPathPoints.size(); index++) {
		if (walkPathPoints[index]->FUN0043cee0()) {
			float fVar9 = GetDistanceTo(this, walkPathPoints[index]->GetPosition());
			if (fVar9 < local_1c) {
				local_1c = fVar9;
				destinationPosition = walkPathPoints[index]->GetPosition();
				this_00 = walkPathPoints[index];
			}
		}
	}

	walkPathPoints.clear();
	if (this_00 != NULL) {
		this_00->FUN0043cef0(false);
		if (nextWalkPoint != NULL) {
			nextWalkPoint->FUN0043cef0(true);
		} 
		nextWalkPoint = this_00;
		return true;
	}
	return false;
}

/* 419BA0-419BA1 00001	*/
void CJezyk::Idle::OnFrame() {
}

/* 419BA0-419BA1 00001	*/
void CJezyk::Idle::OnExitState() {
}

/* 43DC50-43DC70 00020	*/
void CJezyk::Idle::OnEnterState() {
	jezyk = (CJezyk*) delegator2;
	jezyk->SetSpeedValue(0.0f);
	unk_1e0 = 0;
}

/* 419BA0-419BA1 00001	*/
void CJezyk::WalkNaviPath::OnExitState() {
}

/* 43D7C0-43D894 000D4	*/
void CJezyk::WalkNaviPath::OnEnterState() {
	jezyk = (CJezyk*) delegator2;
	unk_1e0.x = 0;
	unk_1e0.y = 0;
	unk_1e0.z = 0;
	jezyk->PlayAnim("Run");
	jezyk->SetSpeedValue(350.0f);
	jezyk->EnableCallHandler("OnFrame");
	jezyk->SetMaxAngSpeed(500.0f);
	jezyk->visitedNaviPoints = 0;
	jezyk->FindNextControlPoint();
	jezyk->BuildNaviPoints(jezyk->GetPosition(), jezyk->destinationPosition);

}

/* 43D8A0-43DAB4 00214	*/
void CJezyk::WalkNaviPath::OnFrame() {
	int iVar3 = jezyk->GetNaviPointsCount();
	if (iVar3 <= 0) {
		return;
	}

	D3DXVECTOR3 auStack_54 = D3DXVECTOR3(jezyk->GetNaviPointAt(jezyk->visitedNaviPoints).x,jezyk->GetNaviPointAt(jezyk->visitedNaviPoints).y, jezyk->GetNaviPointAt(jezyk->visitedNaviPoints).z);
	auStack_54.y = jezyk->GetPosition().y;
	jezyk->SetDestinationPos(auStack_54, 150.0f);
	D3DXVECTOR3 Dstack_3c = jezyk->GetPosition();
	D3DXVECTOR3 DStack_48 = auStack_54 - Dstack_3c;
	D3DXVec3Normalize(&DStack_48, &DStack_48);
	jezyk->SetDestinationDir(DStack_48, 2);
	D3DXVECTOR3 Dstack_48 = jezyk->GetPlayerObject()->GetPosition() ;
	D3DXVECTOR3 Dstack_40 = jezyk->GetPosition();
	D3DXVECTOR3 diff = Dstack_48 - Dstack_40;
	float dist = D3DXVec3Length(&diff);
	if (dist < 200.0f) {
		jezyk->visitedNaviPoints = 0;
		jezyk->visitedNaviPoints = 0;
		D3DXVECTOR3 pcVar1 = jezyk->patrolObject->GetPosition();
		jezyk->BuildNaviPoints(jezyk->GetPosition(), pcVar1);
	}
}

/* 43DAC0-43DB60 000A0	*/
void CJezyk::WalkNaviPath::OnDestinationPos(D3DXVECTOR3 param_1) {
	jezyk->visitedNaviPoints++;
	if (jezyk->visitedNaviPoints < jezyk->GetNaviPointsCount()) {
		return;
	}
	jezyk->visitedNaviPoints = 0;
	jezyk->FindNextControlPoint();
	jezyk->BuildNaviPoints(jezyk->GetPosition(), jezyk->destinationPosition);
}

/* 43DB60-43DC26 000C6	*/
void CJezyk::WalkNaviPath::OnCollisionObject(cMagMeshObject* param_1) {
	if (strncmp("CJezyk", param_1->GetClassNameA(), 6) == 0) {
		jezyk->visitedNaviPoints = 0;
		jezyk->FindNextControlPoint();
		jezyk->BuildNaviPoints(jezyk->GetPosition(), jezyk->destinationPosition);
	}

	if (strncmp("CDomekJeza", param_1->GetClassNameA(), 10) == 0) {
		jezyk->SetAsCaptured();
	}
}

/* 43DC30-43DC45 00015	*/
void CJezyk::WalkNaviPath::OnAnimEnd(char* param_1) {
	strcmpi(param_1, "Reakcja01");
}

