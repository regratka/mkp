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
	unk_2720 = 0;
	unk_2724 = -1;
	patrolObject = NULL;
	unk_2748 = NULL;
	unk_272c = D3DXVECTOR3(0.0f,0.0f,0.0f);
	unk_2738.reserve(100);
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
	FUN0043d5f0();
	if (navigationPath[0] != '\0') {
		CreateNavigationPath(navigationPath);
	}
	unk_2724 = LoadSound("data\\sounds\\papatka\\P_jezowa-2.wav");
	GameSDK* sdk = ((GameSDK*) GetGame());
	float fVar3 = sdk->FUN00401e10();
	SetVolume(unk_2724, fVar3);
	StopSound(unk_2724);
	SetState(new WalkNaviPath());
}

/* 43D420-43D4D0 000B0	*/
void CJezyk::FUN0043d420() {
	if (GetPlayerObject() != NULL) {
		((CPlayerTPP*) GetPlayerObject())->FUN00409ff0(true);
	}

	if (((CPlayerTPP*) GetPlayerObject())->unk_3990 != NULL) {
		((CPlayerTPP*) GetPlayerObject())->unk_3990->FUN0042d590(false);
		((CPlayerTPP*) GetPlayerObject())->unk_3990->FUN0042d540(true);
	}

	EnableCallHandlerOnPlaySoundEnd(unk_2724);
	PlaySoundA(unk_2724, false);
	CSplineCamera* camera = (CSplineCamera*) MagGetObject("Camera02"); 
	camera->SetHandlerObject(this);
	camera->SetDestTime(-1.0f);
	GetGame()->SetActiveCamera(camera);
	camera->Play(0.0f);
	
}

/* 43D4D0-43D4F4 00024	*/
void CJezyk::OnPlaySoundEnd(int param_1) {
	if (param_1 == unk_2724) {
		GetGame()->LoadLevel("data\\levels\\Level03\\Level03.lev");
	}
}

/* 43D500-43D5E6 000E6	*/
void CJezyk::FUN0043d500() {
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
		FUN0043d420();
		return;
	}

	SetState(new Idle());
}

/* 43D5F0-43D613 00023	*/
void CJezyk::FUN0043d5f0() {
	InitAnimSeq("Run", 0, 51);
	SetAnimFreq("Run", 35);
}

/* 43D620-43D7B2 00192	*/
void CJezyk::FUN0043d620() {
	unk_2738.clear();
	D3DXVECTOR3 puVar3 = GetPosition();
	GetObjectsInRadiusFromClass(5000000.0f, puVar3, "AIControlPoint", *((std::vector<cMagKernel*>*) &unk_2738));

	for (int index = 0; index < unk_2738.size(); index++) {

	}
	
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
	jezyk->unk_2720 = 0;
	jezyk->FUN0043d620();
	jezyk->BuildNaviPoints(jezyk->GetPosition(), jezyk->unk_272c);

}

/* 43D8A0-43DAB4 00214	*/
void CJezyk::WalkNaviPath::OnFrame() {
	int iVar3 = jezyk->GetNaviPointsCount();
	if (iVar3 <= 0) {
		return;
	}

	D3DXVECTOR3 pDVar4 = jezyk->GetNaviPointAt(jezyk->unk_2720);
	pDVar4.y = jezyk->GetPosition().y;
	jezyk->SetDestinationPos(pDVar4, 150.0f);
	D3DXVECTOR3 auStack_54 = pDVar4 - jezyk->GetPosition();
	D3DXVec3Normalize(&auStack_54, &auStack_54);
	jezyk->SetDestinationDir(auStack_54, 2);
	float dist = D3DXVec3Length(&(jezyk->GetPlayerObject()->GetPosition() - jezyk->GetPosition()));
	if (dist < 200.0f) {
		jezyk->unk_2720 = 0;
		jezyk->unk_2720 = 0;
		jezyk->patrolObject->GetPosition();
		jezyk->BuildNaviPoints(jezyk->GetPosition(), jezyk->patrolObject->GetPosition());
	}
}

/* 43DAC0-43DB60 000A0	*/
void CJezyk::WalkNaviPath::OnDestinationPos(D3DXVECTOR3 param_1) {
	jezyk->unk_2720++;
	if (jezyk->unk_2720 < jezyk->GetNaviPointsCount()) {
		return;
	}
	jezyk->unk_2720 = 0;
	jezyk->FUN0043d620();
	jezyk->BuildNaviPoints(jezyk->GetPosition(), jezyk->unk_272c);
}

/* 43DB60-43DC26 000C6	*/
void CJezyk::WalkNaviPath::OnCollisionObject(cMagMeshObject* param_1) {
	if (strncmp("CJezyk", param_1->GetClassNameA(), 6) == 0) {
		jezyk->unk_2720 = 0;
		jezyk->FUN0043d620();
		jezyk->BuildNaviPoints(jezyk->GetPosition(), jezyk->unk_272c);
	}

	if (strncmp("CDomekJeza", param_1->GetClassNameA(), 10) == 0) {
		jezyk->FUN0043d500();
	}
}

/* 43DC30-43DC45 00015	*/
void CJezyk::WalkNaviPath::OnAnimEnd(char* param_1) {
	strcmpi(param_1, "Reakcja01");
}

