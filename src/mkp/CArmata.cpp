#include "CArmata.h"

#include "GameSDK.h"
#include "CPlayerTPP.h"

/* 4262D0-4262FA 0002A	*/
void CArmata::OnLoadChunk(_ED_CHUNK param_1, std::ifstream& param_2) {
	if (param_1.chunkType == 15 && param_1.chunkDataSize == 200) {
		param_2.read(unk_2658, 200);
	}
}

/* 439F40-43A003 000C3	*/
CArmata::CArmata() {
	hud = NULL;
	unk_272c = -1;
	unk_2730 = false;
	camera = NULL;
	unk_2720 = false;
	unk_2a2c = 0;
	unk_2a30 = 0;
	unk_2a34 = 0;
	unk_2a3c = NULL;
	unk_2a50 = 0;
	unk_2a54 = true;
	soundID = 0;
	unk_2a28 = 400.0f;
}

/* 43A030-43A0AD 0007D	*/
CArmata::~CArmata() {
}

/* 43A0B0-43A10A 0005A	*/
void* CArmata::EXP() {
	return new CArmata();
}

/* 43A110-43A14F 0003F	*/
void CArmata::OnActivate() {
	soundID = LoadSound("data\\sounds\\Armata.wav");
	float volume = ((GameSDK*) GetGame())->FUN00401e10();
	SetVolume(soundID, volume);
}

/* 43A150-43A1B0 00060	*/
void CArmata::OnActivateLevel() {
	unk_2a3c = (cMagMeshObject*) MagGetObject(unk_2658);
	hud = (CHudGratka*) MagGetObject("HUD");
	unk_272c = kbSettings.FUN00410260(((GameSDK*) GetGame())->e_input);
	FUN0043a900();
	EnableCallHandler("OnInputKey");
}

/* 43A1B0-43A271 000C1	*/
void CArmata::FUN0043a1b0(float param_1) {
	if (!EnableRendering()) {
		return;
	}
	if (param_1 < unk_2a28) {
		if (hud != NULL) {
			hud->FUN0042db90(true, GetPosition());
		}
		unk_2728 = false;
		return;
	}

	if (!unk_2728) {
		unk_2728 = true;
		if (hud != NULL) {
			hud->FUN0042db90(false, GetPosition());
		}
	}
	
}

/* 43A280-43A7D9 00559	*/
void CArmata::OnInputKey(uchar* param_1) {
	if (!unk_2720) {
		float distance = GetDistanceTo(this, GetPlayerObject()->GetPosition());
		FUN0043a1b0(distance);
		if (param_1[unk_272c] != 0 && !unk_2730 && distance < unk_2a28) {
			FUN0043a7e0();
		}
	} else if (param_1[unk_272c] != 0 && !unk_2730) {
		FUN0043a890();
	}
	unk_2730 = param_1[unk_272c] != 0;

	if (!unk_2720) {
		return;
	}

	D3DXVECTOR3 direction = GetDirection();
	if (param_1[57]) {
		unk_2a54 = false;
		if (hud != NULL) {
			hud->FUN0042e030();
		}
	} else {
		if (!unk_2a54) {
			unk_2a54 = true;
			FUN0043ab90(hud->FUN0042e0a0());
		}
		if (hud != NULL) {
			hud->FUN0042e0b0();
		}
	}

	if (param_1[203]) {
		if (unk_2a34 >= -12.0f) {
			unk_2a34 -= 0.1f;
			if (unk_2a3c != NULL) {
				unk_2a3c->SetFreeDestinationDir(true);
				unk_2a3c->SetFreeRotationMatrix(true);
				unk_2a3c->SetDestinationDir(unk_2a3c->RotateVector(&unk_2a3c->GetUp(), &unk_2a3c->GetDirection(), -0.3f), 2);
			}
			SetRight(unk_2a3c->GetRight());
			SetFreeDestinationDir(true);
			SetFreeRotationMatrix(true);
			SetDestinationDir(RotateVector(&GetUp(), &GetDirection(), -0.3f), 2);
		}
	} else if (param_1[205]) {
		if (unk_2a34 <= 12.0f) {
			unk_2a34 += 0.1f;
			if (unk_2a3c != NULL) {
				unk_2a3c->SetFreeDestinationDir(true);
				unk_2a3c->SetFreeRotationMatrix(true);
				unk_2a3c->SetDestinationDir(unk_2a3c->RotateVector(&unk_2a3c->GetUp(), &unk_2a3c->GetDirection(), 0.3f), 2);
			}
			SetRight(unk_2a3c->GetRight());
			SetFreeDestinationDir(true);
			SetFreeRotationMatrix(true);
			SetDestinationDir(RotateVector(&GetUp(), &GetDirection(), 0.3f), 2);
		}
	} else if (param_1[200]) {
		if (unk_2a30 <= 8.0f) {
			unk_2a2c = 0.3f;
			unk_2a30 += 0.1f;
			SetFreeDestinationDir(true);
			SetFreeRotationMatrix(true);
			if (unk_2a2c < 0.0f) {
				SetDestinationDir(RotateVector(&GetRight(), &GetDirection(), -1 * unk_2a2c), 2);
			} 
			else {
				SetDestinationDir(RotateVector(&GetRight(), &GetDirection(), unk_2a2c), 2);
			}
		}
	} else if (param_1[208]) {
		if (unk_2a30 >= -8.0f) {
			unk_2a30 -= 0.1f;
			unk_2a2c = -0.3f;
			SetFreeDestinationDir(true);
			SetFreeRotationMatrix(true);
			if (unk_2a2c >= 0.0f) {
				SetDestinationDir(RotateVector(&GetRight(), &GetDirection(), -1 * unk_2a2c), 2);
			} else {
				SetDestinationDir(RotateVector(&GetRight(), &GetDirection(), unk_2a2c), 2);
			}
		}
	} else {
		SetFreeDestinationDir(true);
		SetFreeRotationMatrix(true);	
	}
}

/* 43A7E0-43A88F 000AF	*/
void CArmata::FUN0043a7e0() {
	unk_2720 = true;
	((GameSDK*) GetGame())->FUN00401e20("Armata");
	if (hud != NULL) { 
		hud->FUN0042db90(false, GetPosition());
		hud->FUN0042dfb0(true);
	}
	CPlayerTPP* player = (CPlayerTPP*) GetPlayerObject();
	camera = player->FUN00408840();
	camera->observedObject = this;
	
	GetGame()->SetActiveCamera(camera);
	((CPlayerTPP*) GetPlayerObject())->FUN00409ff0(true);
	return;
}

/* 43A890-43A8FD 0006D	*/
void CArmata::FUN0043a890() {
	unk_2720 = false;
	unk_2a54 = true;
	if (hud != NULL) {
		hud->FUN0042dd60(true);
		hud->FUN0042dfb0(false);
	}
	camera->observedObject = (CPlayerTPP*) GetPlayerObject();
	GetGame()->SetActiveCamera(camera);
	((CPlayerTPP*) GetPlayerObject())->FUN00409ff0(false);
}

/* 43A900-43AB90 00290	*/
void CArmata::FUN0043a900() {
	CArmataPocisk* pocisk1 = new CArmataPocisk();
	CreateObject(pocisk1);
	bullets.push_back(pocisk1);
	CArmataPocisk* pocisk2 = new CArmataPocisk();
	CreateObject(pocisk2);
	bullets.push_back(pocisk2);
	CArmataPocisk* pocisk3 = new CArmataPocisk();
	CreateObject(pocisk3);
	bullets.push_back(pocisk3);
}

/* 43AB90-43ADC4 00234	*/
void CArmata::FUN0043ab90(float param_1) {
	if (unk_2a50 > 2) {
		unk_2a50 = 0;
	}

	if (param_1 != 0.0f) {
		if (param_1 > 0.0f && param_1 < 10.0f) {
			bullets[unk_2a50]->SetGravityAcceleration(10.0f);
			bullets[unk_2a50]->SetSpeedValue(1500.0f);
		}
		if (param_1 > 10.0f && param_1 < 20.0f) {
			bullets[unk_2a50]->SetGravityAcceleration(12.0f);
			bullets[unk_2a50]->SetSpeedValue(2500.0f);
		}
		if (param_1 > 20.0f && param_1 < 40.0f) {
			bullets[unk_2a50]->SetGravityAcceleration(13.0f);
			bullets[unk_2a50]->SetSpeedValue(3500.0f);
		}
		if (param_1 > 40.0f && param_1 < 60.0f) {
			bullets[unk_2a50]->SetGravityAcceleration(15.0f);
			bullets[unk_2a50]->SetSpeedValue(5500.0f);
		}
		if (param_1 > 60.0f) {
			bullets[unk_2a50]->SetGravityAcceleration(15.0f);
			bullets[unk_2a50]->SetSpeedValue(5800.0f);
		}
	}
	PlaySoundA(soundID, false);
	bullets[unk_2a50]->FUN0043b1a0(GetDirection(), GetPosition());
	unk_2a50++;
}

