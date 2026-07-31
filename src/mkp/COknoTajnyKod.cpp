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
    activeCursorIndex = 0;
    lastCursorChangeTime = 0.0f;
    isCursorOnDoorSprite = false;
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

    doorTexID = uiWindow->AddTexture("data\\textures\\hud\\drzwi.png");
    uiWindow->SetScale(doorTexID ,0.7f, 0.7f);
    uiWindow->SetPos(doorTexID, 0.72f, 0.32f, 0);
    uiWindow->Hide(doorTexID);
    uiWindow->EnableCheckMouse(doorTexID, true);

    doorActiveTexID = uiWindow->AddTexture("data\\textures\\hud\\drzwi_a.png");
    uiWindow->SetScale(doorActiveTexID ,0.7f, 0.7f);
    uiWindow->SetPos(doorActiveTexID, 0.72f, 0.32f, 0);
    uiWindow->Hide(doorActiveTexID);
    uiWindow->EnableCheckMouse(doorActiveTexID, true);

    uiWindow2 = new UIWindow(this);
    CreateObject(uiWindow2);
    PrepareCursors();
    PrepareExitSound();
}

/* 427660-4276E9 00089	*/
void COknoTajnyKod::DisableWindow() {
    DisableCallHandler("OnFrame");
    DisableCallHandler("OnInputMouse");
    DisableCallHandler("OnInputKey");
    ActivateDefaultCursor();
    uiEdit->FUN00413060();
    uiWindow->FUN00413580(false);
    uiEdit->FUN00412770(false);
    uiWindow->Hide(doorTexID);
    uiWindow->Hide(doorActiveTexID);
    unk_1745 = false;
}

/* 4276F0-42785D 0016D	*/
void COknoTajnyKod::PrepareCursors() {
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
void COknoTajnyKod::ChangeActiveCursor() {
    for (int index = 1; index < sizeof(cursorsTextureID)/sizeof(int); index++) {
        uiWindow2->Hide(cursorsTextureID[index]);
    }
    uiWindow2->Hide(cursorsTextureID[0]);
    float fVar1 = timeGetTime() * 0.001f;
    if (fVar1 - lastCursorChangeTime > 0.1f) {
        lastCursorChangeTime = fVar1;
        activeCursorIndex++;
        if (activeCursorIndex > 3) {
            activeCursorIndex = 1;
        }
    }
}

/* 427910-42794B 0003B	*/
void COknoTajnyKod::ActivateDefaultCursor() {
    // !!! out of bounds exception !!!
    for (int i = 0; i <= sizeof(cursorsTextureID)/sizeof(int); i++) {
        uiWindow2->Hide(cursorsTextureID[i]);
    }
    activeCursorIndex = 0;
    isCursorOnDoorSprite = false;
}

/* 427950-427A3E 000EE	*/
void COknoTajnyKod::OnFrame() {
    if (isCursorOnDoorSprite) {
        ChangeActiveCursor();
    } else {
        ActivateDefaultCursor();
    }

    POINT local_8;
    GetCursorPos(&local_8);
    ScreenToClient(GetHandleWindow(), &local_8);
    int iVar1 = GetWindowWidth();
    int iVar2 = GetWindowHeight();
    cursorXPos = local_8.x / (float)iVar1;
    cursorYPos = local_8.y / (float)iVar2;
    uiWindow2->SetScale(cursorsTextureID[activeCursorIndex], 1.0f, 1.0f);
    uiWindow2->SetPos(cursorsTextureID[activeCursorIndex], 
        cursorXPos +  0.01f, cursorYPos + 0.01f, 0);
    uiWindow2->Show(cursorsTextureID[activeCursorIndex]);
}

/* 427A40-427A97 00057	*/
void COknoTajnyKod::OnMouseArrive(int param_1) {
    if (doorTexID == param_1) {
        isCursorOnDoorSprite = true;
        meshObject->PlaySoundA(exitSoundID, false);
        uiWindow->Hide(doorTexID);
        uiWindow->Show(doorActiveTexID);
    }
}

/* 427AA0-427ADC 0003C	*/
void COknoTajnyKod::OnMouseLeave(int param_1) {
    if (doorActiveTexID == param_1) {
        isCursorOnDoorSprite = false;
        uiWindow->Hide(doorActiveTexID);
        uiWindow->Show(doorTexID);
    }
}

/* 427AE0-427B34 00054	*/
void COknoTajnyKod::PrepareExitSound() {
    GameSDK* sdk = (GameSDK*) GetGame();
    float fVar2 = sdk->FUN00401e10();
    exitSoundID = meshObject->LoadSound("data\\sounds\\wyjscie.wav");
    meshObject->SetVolume(exitSoundID, fVar2);
    meshObject->StopSound(exitSoundID);
}

/* 427B40-427B7C 0003C	*/
void COknoTajnyKod::OnInputMouse(float param_1, float param_2, bool param_3, bool param_4) {
    if (param_3 && !unk_1744) {
        if (doorActiveTexID == uiWindow->GetMouseActivateSprite()) {
            DisableWindow();
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

    DisableWindow();
}

