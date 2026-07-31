#include "COknoTajnyKod.h"

#include "GameSDK.h"


/* 419BA0-419BA1 00001	*/
void COknoTajnyKod::OnActivateLevel() {
}

/* 4272F0-42734D 0005D	*/
COknoTajnyKod::COknoTajnyKod(CPlayerTPP* param_1) {
    player = param_1;
    motorboat = NULL;
    uiEdit = NULL;
    uiWindow = NULL;
    unk_1745 = false;
    unk_1788 = 0;
    unk_178c = 0.0f;
    unk_1790 = false;
    uiWindow2 = NULL;
    meshObject = NULL;
    unk_1744 = false;
}

/* 427370-42737C 0000C	*/
COknoTajnyKod::~COknoTajnyKod() {
}

/* 427380-427651 002D1	*/
void COknoTajnyKod::OnActivate() {
    meshObject = new cMagMeshObject();
    CreateObject(meshObject);

    uiWindow = new UIWindow(this);
    CreateObject(uiWindow);
    uiWindow->FUN004134e0("data\\textures\\menu\\tlokod.png");
    uiWindow->FUN00413540(D3DXVECTOR2(0.7f, 1.0f));
    uiWindow->FUN00413560(D3DXVECTOR2(0.5f, 0.55f));
    uiWindow->FUN00413580(false);

    uiEdit = new UIEdit("data\\textures\\menu\\edit.png", this);
    CreateObject(uiEdit);
    uiEdit->FUN004127e0(1.3f, 0.4f);

    uiEdit->FUN00412830(0.5f, 0.5f);
    uiEdit->FUN00412910("");
    uiEdit->FUN00412770(false);

    doorsTextureID = uiWindow->AddTexture("data\\textures\\hud\\drzwi.png");
    uiWindow->SetScale(doorsTextureID ,0.7f, 0.7f);
    uiWindow->SetPos(doorsTextureID, 0.72f, 0.32f, 0);
    uiWindow->Hide(doorsTextureID);
    uiWindow->EnableCheckMouse(doorsTextureID, true);

    doorsATextureID = uiWindow->AddTexture("data\\textures\\hud\\drzwi_a.png");
    uiWindow->SetScale(doorsATextureID ,0.7f, 0.7f);
    uiWindow->SetPos(doorsATextureID, 0.72f, 0.32f, 0);
    uiWindow->Hide(doorsATextureID);
    uiWindow->EnableCheckMouse(doorsATextureID, true);

    uiWindow2 = new UIWindow(this);
    CreateObject(uiWindow2);
    FUN004276f0();
    FUN00427ae0();
}

/* 427660-4276E9 00089	*/
void COknoTajnyKod::FUN00427660() {
    DisableCallHandler("OnFrame");
    DisableCallHandler("OnInputMouse");
    DisableCallHandler("OnInputKey");
    FUN00427910();
    uiEdit->FUN00413060();
    uiWindow->FUN00413580(false);
    uiEdit->FUN00412770(false);
    uiWindow->Hide(doorsTextureID);
    uiWindow->Hide(doorsATextureID);
    unk_1745 = false;
}

/* 4276F0-42785D 0016D	*/
void COknoTajnyKod::FUN004276f0() {
    cursorsTextureID[0] = uiWindow2->AddTexture("data\\textures\\menu\\kursor.png");
    uiWindow2->SetScale(cursorsTextureID[0], 1.0f, 1.0f);
    uiWindow2->SetPos(cursorsTextureID[0], 0.1f, 0.1f, 0);
    uiWindow2->Hide(cursorsTextureID[0]);
    
    cursorsTextureID[1] = uiWindow2->AddTexture("data\\textures\\menu\\kursor1.png");
    uiWindow2->SetScale(cursorsTextureID[1], 1.0f, 1.0f);
    uiWindow2->SetPos(cursorsTextureID[1], 0.1f, 0.1f, 0);
    uiWindow2->Hide(cursorsTextureID[1]);

    cursorsTextureID[2] = uiWindow2->AddTexture("data\\textures\\menu\\kursor2.png");
    uiWindow2->SetScale(cursorsTextureID[2], 1.0f, 1.0f);
    uiWindow2->SetPos(cursorsTextureID[2], 0.1f, 0.1f, 0);
    uiWindow2->Hide(cursorsTextureID[2]);

    cursorsTextureID[3] = uiWindow2->AddTexture("data\\textures\\menu\\kursor3.png");
    uiWindow2->SetScale(cursorsTextureID[3], 1.0f, 1.0f);
    uiWindow2->SetPos(cursorsTextureID[3], 0.1f, 0.1f, 0);
    uiWindow2->Hide(cursorsTextureID[3]);
}


/* 427860-427901 000A1	*/
void COknoTajnyKod::FUN00427860() {
    for (int index = 1; index < sizeof(cursorsTextureID)/sizeof(int); index++) {
        uiWindow2->Hide(cursorsTextureID[index]);
    }
    uiWindow2->Hide(cursorsTextureID[0]);
    float fVar1 = timeGetTime() * 0.001f;
    if (fVar1 - unk_178c > 0.1f) {
        unk_178c = fVar1;
        unk_1788++;
        if (unk_1788 > 3) {
            unk_1788 = 1;
        }
    }

}

/* 427910-42794B 0003B	*/
void COknoTajnyKod::FUN00427910() {
    // !!! out of bounds exception !!!
    for (int i = 0; i <= sizeof(cursorsTextureID)/sizeof(int); i++) {
        uiWindow2->Hide(cursorsTextureID[i]);
    
    }
    unk_1788 = 0;
    unk_1790 = false;
}

/* 427950-427A3E 000EE	*/
void COknoTajnyKod::OnFrame() {
    if (unk_1790) {
        FUN00427860();
    } else {
        FUN00427910();
    }

    POINT local_8;
    GetCursorPos(&local_8);
    ScreenToClient(GetHandleWindow(), &local_8);
    int iVar1 = GetWindowWidth();
    int iVar2 = GetWindowHeight();
    unk_1754 = local_8.x / (float)iVar1;
    unk_1758 = local_8.y / (float)iVar2;
    uiWindow2->SetScale(cursorsTextureID[unk_1788], 1.0f, 1.0f);
    uiWindow2->SetPos(cursorsTextureID[unk_1788], 
        unk_1754 +  0.01f, unk_1758 + 0.01f, 0);
    uiWindow2->Show(cursorsTextureID[unk_1788]);
}

/* 427A40-427A97 00057	*/
void COknoTajnyKod::OnMouseArrive(int param_1) {
    if (doorsTextureID == param_1) {
        unk_1790 = true;
        meshObject->PlaySoundA(soundID, false);
        uiWindow->Hide(doorsTextureID);
        uiWindow->Show(doorsATextureID);
    }
}

/* 427AA0-427ADC 0003C	*/
void COknoTajnyKod::OnMouseLeave(int param_1) {
    if (doorsATextureID == param_1) {
        unk_1790 = false;
        uiWindow->Hide(doorsATextureID);
        uiWindow->Show(doorsTextureID);
    }
}

/* 427AE0-427B34 00054	*/
void COknoTajnyKod::FUN00427ae0() {
    GameSDK* sdk = (GameSDK*) GetGame();
    float fVar2 = sdk->FUN00401e10();
    soundID = meshObject->LoadSound("data\\sounds\\wyjscie.wav");
    meshObject->SetVolume(soundID, fVar2);
    meshObject->StopSound(soundID);
}

/* 427B40-427B7C 0003C	*/
void COknoTajnyKod::OnInputMouse(float param_1, float param_2, bool param_3, bool param_4) {
    if (param_3 && !unk_1744) {
        if (doorsATextureID == uiWindow->GetMouseActivateSprite()) {
            FUN00427660();
        }
    }
    unk_1744 = param_3;
}

/* 427B80-427BDF 0005F	*/
void COknoTajnyKod::OnInputKey(uchar* param_1) {
    if (param_1[0x1c] == '\0') {
        return;
    }

    if (player != NULL) {
        player->FUN00409910(uiEdit->FUN00412a20(false));
    }

    if (motorboat != NULL) {
        motorboat->FUN0040e550(uiEdit->FUN00412a20(false));  
    }

    FUN00427660();
}

