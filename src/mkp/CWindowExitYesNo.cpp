#include "CWindowExitYesNo.h"

#include "GameSDK.h"
#include "cMagMeshObject.h"
#include "CPlayerTPP.h"
#include "CMotorboat.h"
#include "MenuModule.h"

/* 4264A0-426530 00090	*/
CWindowExitYesNo::CWindowExitYesNo() {
    menuModule = NULL;
    mainWindow = NULL;
    hitboxesLayer = NULL;
    bodySprite = NULL;
    cursorXPos = 0.0;
    cursorYPos = 0.0;
    unk_176c = false;
    soundsManager = NULL;
    unk_17a0 = false;
    unk_17ac = false;
    unk_1791 = false;
    yesHitboxTexID = -1;
    noHitboxTexID = -1;
    unk_1760 = -1;
    questionSoundID = -1;
    yesSoundID = -1;
    noSoundID = -1;
    activeCursorIndex = 0;
    lastCursorChangeTime = 0.0;
    unk_1790 = false;
}

/* 426550-42655C 0000C	*/
CWindowExitYesNo::~CWindowExitYesNo() {
}

/* 426560-4269DC 0047C	*/
void CWindowExitYesNo::OnActivate() {
    areSoundMuted = ((GameSDK*) GetGame())->unk_2548;
    soundsManager = new cMagMeshObject();
    CreateObject(soundsManager);

    mainWindow = new UIWindow();
    CreateObject(mainWindow);
    mainWindow->SetBackground("data\\textures\\HUD\\menu-exit.png");
    mainWindow->SetBackgroundScale(D3DXVECTOR2(0.7f, 1.0f));
    mainWindow->SetBackgroundPos(D3DXVECTOR2(0.5f, 0.5f));
    mainWindow->SetBackgroundVisible(false);

    bodySprite = new UIWindow();
    CreateObject(bodySprite);
    bodySprite->SetBackground("data\\textures\\HUD\\PapatkaYesNo.png");
    bodySprite->SetBackgroundScale(D3DXVECTOR2(1.0f, 1.0f));
    bodySprite->SetBackgroundPos(D3DXVECTOR2(0.5f, 0.5f));
    bodySprite->SetBackgroundVisible(false);
    
    headYesSprite = new UIWindow();
    CreateObject(headYesSprite);
    headYesSprite->SetBackground("data\\textures\\HUD\\papatka_yes.png");
    headYesSprite->SetBackgroundScale(D3DXVECTOR2(0.8f, 0.6f));
    headYesSprite->SetBackgroundPos(D3DXVECTOR2(0.687f, 0.455f));
    headYesSprite->SetBackgroundVisible(false);
    headYesSprite->unk_176b = true;
    headYesSprite->FUN004135d0(0, 4, 128, 256);

    headNoSprite = new UIWindow();
    CreateObject(headNoSprite);
    headNoSprite->SetBackground("data\\textures\\HUD\\papatka_no.png");
    headNoSprite->SetBackgroundScale(D3DXVECTOR2(0.8f, 0.6f));
    headNoSprite->SetBackgroundPos(D3DXVECTOR2(0.687f, 0.455f));
    headNoSprite->SetBackgroundVisible(false);
    headNoSprite->unk_176b = true;
    headNoSprite->FUN004135d0(0, 4, 128, 256);

    hitboxesLayer = new UIWindow(this);
    CreateObject(hitboxesLayer);
    FUN00426c50();
    yesHitboxTexID = hitboxesLayer->AddTexture("data\\textures\\hud\\b1.png");
    hitboxesLayer->SetScale(yesHitboxTexID, 0.8f, 0.8f);
    hitboxesLayer->SetPos(yesHitboxTexID, 0.432f, 0.613f, 0);
    hitboxesLayer->Hide(yesHitboxTexID);
    hitboxesLayer->EnableCheckMouse(yesHitboxTexID, true);

    noHitboxTexID = hitboxesLayer->AddTexture("data\\textures\\hud\\b1.png");
    hitboxesLayer->SetScale(noHitboxTexID, 0.8f, 0.8f);
    hitboxesLayer->SetPos(noHitboxTexID, 0.57f, 0.61f, 0);
    hitboxesLayer->Hide(noHitboxTexID);
    hitboxesLayer->EnableCheckMouse(noHitboxTexID, true);
    FUN00426fa0();

}

/* 4269E0-426B69 00189	*/
void CWindowExitYesNo::FUN004269e0(MenuModule* param_1) {
    menuModule = param_1;
    areSoundMuted = ((GameSDK*) GetGame())->unk_2548;
    mainWindow->SetBackgroundVisible(true);
    bodySprite->SetBackgroundVisible(true);
    headNoSprite->SetBackgroundVisible(true);
    hitboxesLayer->Show(yesHitboxTexID);
    hitboxesLayer->Show(noHitboxTexID);
    int iVar1 = GetWindowWidth();
    int iVar2 = GetWindowHeight();
    SetCursorPos(iVar1/2, iVar2/2);
    hitboxesLayer->SetPos(unk_1760, 0.1f, 0.1f, 0);
    EnableCallHandler("OnInputMouse");
    EnableCallHandler("OnFrame");
    if (!areSoundMuted) {
        soundsManager->PlaySoundA(questionSoundID, false);
    }
    unk_17a0 = true;
    
    if (strcmpi("menu.lev", GetGame()->GetLevelFileName()) != 0) {
        if (strcmpi("Level05kk.lev", GetGame()->GetLevelFileName()) != 0) {
            if (strcmpi("Level06.lev", GetGame()->GetLevelFileName()) != 0) {
                if (GetPlayerObject() != NULL) {
                    ((CPlayerTPP*) GetPlayerObject())->FUN00409260();
                }
                return;
            }
        }
        if (GetPlayerObject() != NULL) {
            ((CMotorboat*) GetPlayerObject())->FUN0040db40();
        }
    }
}

/* 426B70-426C3F 000CF	*/
void CWindowExitYesNo::FUN00426b70() {
    mainWindow->SetBackgroundVisible(false);
    bodySprite->SetBackgroundVisible(false);
    headYesSprite->FUN004136a0();
    headNoSprite->FUN004136a0();
    headYesSprite->SetBackgroundVisible(false);
    headNoSprite->SetBackgroundVisible(false);
    hitboxesLayer->Hide(yesHitboxTexID);
    hitboxesLayer->Hide(noHitboxTexID);
    DisableCallHandler("OnInputMouse");
    DisableCallHandler("OnFrame");
    hitboxesLayer->Hide(unk_1760);
    unk_17a0 = false;
    int iVar1 = GetWindowWidth();
    int iVar2 = GetWindowHeight();
    SetCursorPos(iVar1/2, iVar2/2);
}

/* 426C40-426C47 00007	*/
bool CWindowExitYesNo::FUN00426c40() {
	return unk_17a0;
}

/* 426C50-426DBD 0016D	*/
void CWindowExitYesNo::FUN00426c50() {
    cursorsTextureIDs[0] = hitboxesLayer->AddTexture("data\\textures\\menu\\kursor.png");
    hitboxesLayer->SetScale(cursorsTextureIDs[0], 1.0f, 1.0f);
    hitboxesLayer->SetPos(cursorsTextureIDs[0], 0.1f, 0.1f, 0);
    hitboxesLayer->Hide(cursorsTextureIDs[0]);

    cursorsTextureIDs[1] = hitboxesLayer->AddTexture("data\\textures\\menu\\kursor1.png");
    hitboxesLayer->SetScale(cursorsTextureIDs[1], 1.0f, 1.0f);
    hitboxesLayer->SetPos(cursorsTextureIDs[1], 0.1f, 0.1f, 0);
    hitboxesLayer->Hide(cursorsTextureIDs[1]);

    cursorsTextureIDs[2] = hitboxesLayer->AddTexture("data\\textures\\menu\\kursor2.png");
    hitboxesLayer->SetScale(cursorsTextureIDs[2], 1.0f, 1.0f);
    hitboxesLayer->SetPos(cursorsTextureIDs[2], 0.1f, 0.1f, 0);
    hitboxesLayer->Hide(cursorsTextureIDs[2]);

    cursorsTextureIDs[3] = hitboxesLayer->AddTexture("data\\textures\\menu\\kursor3.png");
    hitboxesLayer->SetScale(cursorsTextureIDs[3], 1.0f, 1.0f);
    hitboxesLayer->SetPos(cursorsTextureIDs[3], 0.1f, 0.1f, 0);
    hitboxesLayer->Hide(cursorsTextureIDs[3]);
}

/* 426DC0-426E61 000A1	*/
void CWindowExitYesNo::FUN00426dc0() {
    for (int index = 1; index < 4; index++) {
        hitboxesLayer->Hide(cursorsTextureIDs[index]);
    }
    
    hitboxesLayer->Hide(cursorsTextureIDs[0]);
    float fVar1 = timeGetTime() * 0.001f;
    if (fVar1 - lastCursorChangeTime > 0.1f) {
        lastCursorChangeTime = fVar1;
        activeCursorIndex++;
        if (activeCursorIndex > 3) {
            activeCursorIndex = 1;
        }
    }
}

/* 426E70-426EAB 0003B	*/
void CWindowExitYesNo::FUN00426e70() {
    for (int i = 0; i < sizeof(cursorsTextureIDs)/sizeof(int); i++) {
        hitboxesLayer->Hide(cursorsTextureIDs[i]);
    }
    activeCursorIndex = 0;
    unk_1790 = false;
}

/* 426EB0-426F9E 000EE	*/
void CWindowExitYesNo::OnFrame() {
    if (unk_1790) {
        FUN00426dc0();
    } else {
        FUN00426e70();
    }

    tagPOINT local_8;
    GetCursorPos(&local_8);
    ScreenToClient(GetHandleWindow(), &local_8);
    int iVar1 = GetWindowWidth();
    int iVar2 = GetWindowHeight();
    cursorXPos = local_8.x / (float)iVar1;
    cursorYPos = local_8.y / (float)iVar2;
    hitboxesLayer->SetScale(cursorsTextureIDs[activeCursorIndex], 1.0f, 1.0f);
    hitboxesLayer->SetPos(cursorsTextureIDs[activeCursorIndex], 
        cursorXPos +  0.01f, cursorYPos + 0.01f, 0);
    hitboxesLayer->Show(cursorsTextureIDs[activeCursorIndex]);
}

/* 426FA0-427025 00085	*/
void CWindowExitYesNo::FUN00426fa0() {
    float fVar2 = ((GameSDK*) GetGame())->FUN00401e10();

    questionSoundID = soundsManager->LoadSound("data\\sounds\\papatka\\papatka-czy chcesz wyjsc.wav");
    soundsManager->SetVolume(questionSoundID, fVar2);

    yesSoundID = soundsManager->LoadSound("data\\sounds\\papatka\\papatka-tak.wav");
    soundsManager->SetVolume(yesSoundID, fVar2);

    noSoundID = soundsManager->LoadSound("data\\sounds\\papatka\\papatka-nie.wav");
    soundsManager->SetVolume(noSoundID, fVar2);

}

/* 427030-427122 000F2	*/
void CWindowExitYesNo::OnMouseArrive(int param_1) {
    unk_1790 = true;
    if (yesHitboxTexID == param_1) {
        headNoSprite->SetBackgroundVisible(false);
        headYesSprite->SetBackgroundVisible(true);
        if (headYesSprite != NULL) {
            headYesSprite->FUN00413650(0.1, 1, 3, true);
        }
        soundsManager->StopSound(questionSoundID);
        if (!areSoundMuted) {
            soundsManager->PlaySoundA(yesSoundID, false);
        }
    }

    if (noHitboxTexID == param_1) {
        headNoSprite->SetBackgroundVisible(true);
        headYesSprite->SetBackgroundVisible(false);
        if (headNoSprite != NULL) {
            headNoSprite->FUN00413650(0.1, 1, 3, true);
        }
        soundsManager->StopSound(questionSoundID);
        if (!areSoundMuted) {
            soundsManager->PlaySoundA(noSoundID, false);
        }
    }    
}

/* 427130-42718A 0005A	*/
void CWindowExitYesNo::OnMouseLeave(int param_1) {
    unk_1790 = false;
    if (yesHitboxTexID == param_1) {
        headYesSprite->SetBackgroundVisible(false);
        headNoSprite->SetBackgroundVisible(true);
        headNoSprite->FUN004136e0(1);
    }

    if (noHitboxTexID == param_1) {
        headNoSprite->FUN004136e0(1);
    }
}

/* 427190-42723E 000AE	*/
void CWindowExitYesNo::OnInputMouse(float param_1, float param_2, bool param_3, bool param_4) {
    if (param_3 && !unk_17ac) {
        if (yesHitboxTexID == hitboxesLayer->GetMouseActivateSprite()) {
            FUN00426b70();
            FUN00426e70();
            if (menuModule != NULL) {
                menuModule->OnExitYesNo("Yes");
            }
        }
        if (noHitboxTexID == hitboxesLayer->GetMouseActivateSprite()) {
            FUN00426b70();
            FUN00426e70();
            if (menuModule != NULL) {
                OutputDebugString("menu NONO");
                menuModule->OnExitYesNo("Yes");
            }
        }
    }
    unk_17ac = param_3;
}

