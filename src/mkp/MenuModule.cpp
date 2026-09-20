#include "MenuModule.h"
#include <dinput.h>

#include "GameSDK.h"
#include "cMagMeshObject.h"

/* 4164E0-4164E3 00003	*/
void MenuModule::OnButtonUp(cMagKernel* param_1) {
}


/* 419BA0-419BA1 00001	*/
void MenuModule::OnActivateLevel() {
}

/* 433FB0-434082 000D2	*/
MenuModule::MenuModule() {
    uiWindow = NULL;
    windowExit = NULL;
    menuOpcje = NULL;
    menuChoiceWindow = NULL;
    isCalibrationEnabled = false;
    unk_1785 = false;
    calibrationXChange = 0.0f;
    calibrationYChange = 0.0f;
    wormButtonTexID = -1;
    birdButtonTexID = -1;
    unk_17d4 = -1;
    unk_17d8 = -1;
    unk_17dc = -1;
    menuMusicSoundID = -1;
    exitShortSoundID = -1;
    hoveredPapatkaTexID = -1;
    hoveredBirdTexID = -1;
    hoveredWormTexID = -1;
    exitSoundID = -1;
    optionsSoundID = -1;
    lastSoundID = -1;
    isExitWindowOpened = false;
    soundsManager = NULL;
    isSubWindowOpened = false;
    isHoveringDisabledButton = false;
    unk_17c5 = false;
    isPlayingSound = false;
    activeCursorIndex = 0;
    lastCursorChangeTime = 0.0f;
    isHoveringEnabledButton = false;
    areSoundsMuted = NULL;
}

/* 4340B0-4340BC 0000C	*/
MenuModule::~MenuModule() {
}

/* 4340C0-4344FB 0043B	*/
void MenuModule::OnActivate() {
    soundsManager = new cMagMeshObject();
    CreateObject(soundsManager);
    uiWindow = new UIWindow(this);
    CreateObject(uiWindow);
    
    uiWindow->FUN004134e0("data\\textures\\menu\\menu_start.png");
    uiWindow->FUN00413510(true);
    uiWindow->FUN00413580(false);
    
    wormButtonTexID = uiWindow->AddTexture("data\\textures\\hud\\b1.png");
    uiWindow->SetScale(wormButtonTexID, 0.725f, 1.344f);
    uiWindow->SetPos(wormButtonTexID, 0.086f, 0.741f, 0);
    uiWindow->Hide(wormButtonTexID);
    
    birdButtonTexID = uiWindow->AddTexture("data\\textures\\hud\\b1.png");
    uiWindow->SetScale(birdButtonTexID, 1.725f, 1.257f);
    uiWindow->SetPos(birdButtonTexID, 0.0937f, 0.225f, 0);
    uiWindow->Hide(birdButtonTexID);

    barnabaButtonTexID = uiWindow->AddTexture("data\\textures\\hud\\b1.png");
    uiWindow->SetScale(barnabaButtonTexID, 1.725f, 3.553f);
    uiWindow->SetPos(barnabaButtonTexID, 0.323f, 0.346f, 0);
    uiWindow->Hide(barnabaButtonTexID);

    tosiaButtonTexID = uiWindow->AddTexture("data\\textures\\hud\\b1.png");
    uiWindow->SetScale(tosiaButtonTexID, 0.984f, 2.85f);
    uiWindow->SetPos(tosiaButtonTexID, 0.555f, 0.535f, 0);
    uiWindow->Hide(tosiaButtonTexID);

    filipButtonTexID = uiWindow->AddTexture("data\\textures\\hud\\b1.png");
    uiWindow->SetScale(filipButtonTexID, 0.984f, 3.701f);
    uiWindow->SetPos(filipButtonTexID, 0.452f, 0.5f, 0);
    uiWindow->Hide(filipButtonTexID);
    
    papatkaButtonTexID = uiWindow->AddTexture("data\\textures\\hud\\b1.png");
    uiWindow->SetScale(papatkaButtonTexID, 1.384f, 3.14f);
    uiWindow->SetPos(papatkaButtonTexID, 0.691f, 0.655f, 0);
    uiWindow->Hide(papatkaButtonTexID);

    hoveredPapatkaTexID = uiWindow->AddTexture("data\\textures\\menu\\papatka_activate.png");
    uiWindow->SetScale(hoveredPapatkaTexID, 1.31f, 0.933f);
    uiWindow->SetPos(hoveredPapatkaTexID, 0.692f, 0.643f, 0);
    uiWindow->Hide(hoveredPapatkaTexID);

    hoveredBirdTexID = uiWindow->AddTexture("data\\textures\\menu\\ptak_activate.png");
    uiWindow->SetScale(hoveredBirdTexID, 0.777f, 1.1);
    uiWindow->SetPos(hoveredBirdTexID, 0.138f, 0.243f, 0);
    uiWindow->Hide(hoveredBirdTexID);

    hoveredWormTexID = uiWindow->AddTexture("data\\textures\\menu\\robaczek_activate.png");
    uiWindow->SetScale(hoveredWormTexID, 0.63f, 1.1);
    uiWindow->SetPos(hoveredWormTexID, 0.1f, 0.746f, 0);
    uiWindow->Hide(hoveredWormTexID);

    menuChoiceWindow = new MenuOknoWyboru_CZ1();
    CreateObject(menuChoiceWindow);
    menuChoiceWindow->SetMenuModule(this);
    LoadSounds();
    LoadSoundsSettings();
}

/* 434500-434560 00060	*/
void MenuModule::LoadSoundsSettings() {
    isMusicMuted = ((GameSDK*)GetGame())->unk_254c;
    areSoundsMuted = ((GameSDK*)GetGame())->unk_2548;

    if (!isMusicMuted) {
        soundsManager->PlaySoundA(menuMusicSoundID, true);
    } else {
        soundsManager->StopSound(menuMusicSoundID);
    }

}

/* 434560-434676 00116	*/
void MenuModule::OnFrame() {
    if (windowExit->FUN00426c40()) {
        return;
    } 

    if (isHoveringEnabledButton) {
        ChangeActiveCursor();
    } else if (isHoveringDisabledButton) {
        ActivateStopCursor();
    } else {
        ActivateDefaultCursor();
    }

    tagPOINT local_8;
    GetCursorPos(&local_8);
    ScreenToClient(GetHandleWindow(), &local_8);
    int iVar1 = GetWindowWidth();
    int iVar2 = GetWindowHeight();
    cursorXPos = local_8.x / (float)iVar1;
    cursorYPos = local_8.y / (float)iVar2;
    uiWindow->SetScale(cursorsTextureIDs[activeCursorIndex], 1.0f, 1.0f);
    uiWindow->SetPos(cursorsTextureIDs[activeCursorIndex], 
        cursorXPos +  0.01f, cursorYPos + 0.01f, 0);
    uiWindow->Show(cursorsTextureIDs[activeCursorIndex]);
}

/* 434680-434871 001F1	*/
void MenuModule::Initialize() {
    menuOpcje = new CMenuOpcje();
    CreateObject(menuOpcje);
    menuOpcje->OnActivateLevel();
    menuOpcje->menuModule = this;
    windowExit = new CWindowExitYesNo();
    CreateObject(windowExit);
    uiWindow->FUN00413580(true);
    uiWindow->Show(wormButtonTexID);
    uiWindow->EnableCheckMouse(wormButtonTexID, true);
    uiWindow->Show(birdButtonTexID);
    uiWindow->EnableCheckMouse(birdButtonTexID, true);
    uiWindow->Show(barnabaButtonTexID);
    uiWindow->EnableCheckMouse(barnabaButtonTexID, true);
    uiWindow->Show(tosiaButtonTexID);
    uiWindow->EnableCheckMouse(tosiaButtonTexID, true);
    uiWindow->Show(filipButtonTexID);
    uiWindow->EnableCheckMouse(filipButtonTexID, true);
    uiWindow->Show(papatkaButtonTexID);
    uiWindow->EnableCheckMouse(papatkaButtonTexID, true);
    uiWindow->EnableCheckMouse(hoveredBirdTexID, true);
    uiWindow->EnableCheckMouse(hoveredWormTexID, true);
    LoadCursorTextures();
    EnableCallHandler("OnFrame");
    EnableCallHandler("OnInputMouse");
    EnableCallHandler("OnInputKey");
    LoadSoundsSettings();
}   

/* 434880-434992 00112	*/
void MenuModule::OnMouseArrive(int param_1) {
    if (isSubWindowOpened) {
        return;
    }

    if (wormButtonTexID == param_1) {
        uiWindow->Show(hoveredWormTexID);
        lastSoundID = exitSoundID;
        if (areSoundsMuted == NULL) {
            PlayMenuSound(exitSoundID);
        }
        isHoveringEnabledButton = true;
    }

    if (birdButtonTexID == param_1) {
        uiWindow->Show(hoveredBirdTexID);
        if (areSoundsMuted == NULL) {
            PlayMenuSound(optionsSoundID);
        }
        isHoveringEnabledButton = true;
        lastSoundID = optionsSoundID;
    }

    if (barnabaButtonTexID == param_1) {
        isHoveringDisabledButton = true;
    }

    if (tosiaButtonTexID == param_1) {
        isHoveringDisabledButton = true;
    }
    
    if (filipButtonTexID == param_1) {
        isHoveringDisabledButton = true;
    }

    if (papatkaButtonTexID == param_1) {
        uiWindow->Show(hoveredPapatkaTexID);
        if (areSoundsMuted == NULL) {
            PlayMenuSound(selectLevelSoundID);
        }
        isHoveringEnabledButton = true;
        lastSoundID = selectLevelSoundID;
    }
}

/* 4349A0-4349EA 0004A	*/
void MenuModule::SetSubWindowOpened(bool param_1) {
    isSubWindowOpened = param_1;
    if (!isSubWindowOpened) {
        uiWindow->Hide(hoveredPapatkaTexID);
        uiWindow->Hide(hoveredBirdTexID);
        uiWindow->Hide(hoveredWormTexID);
    }
}

/* 4349F0-434A4C 0005C	*/
void MenuModule::OnMouseLeave(int param_1) {
    if (!isSubWindowOpened) {
        isHoveringEnabledButton = false;
        isHoveringDisabledButton = false;
        lastSoundID = -1;
        uiWindow->Hide(hoveredPapatkaTexID);
        uiWindow->Hide(hoveredWormTexID);
        uiWindow->Hide(hoveredBirdTexID);
    }
}

/* 434A50-434B2E 000DE	*/
void MenuModule::OnInputMouse(float param_1, float param_2, bool param_3, bool param_4) {
    if (isSubWindowOpened) {
        return;
    }

    if (param_3 && !unk_17c5) {
        if (wormButtonTexID == uiWindow->GetMouseActivateSprite()) {
            ActivateDefaultCursor();
            StopAllSounds();
            if (windowExit != NULL) {
                windowExit->FUN004269e0(this);
            }
            isExitWindowOpened = true;
            SetSubWindowOpened(true);
        }
        if (birdButtonTexID == uiWindow->GetMouseActivateSprite()) {
            ActivateDefaultCursor();
            SetSubWindowOpened(true);
            if (menuOpcje != NULL) {
                menuOpcje->FUN00438010(this);
            }
        }

        if (papatkaButtonTexID == uiWindow->GetMouseActivateSprite()) {
            SetSubWindowOpened(true);
            if (menuChoiceWindow != NULL) {
                menuChoiceWindow->OpenWindow();
            }
            ActivateDefaultCursor();
        }
    }
    unk_17c5 = param_3;
}

/* 434B30-434B35 00005	*/
void MenuModule::OnUpdateMenuSettings() {
    LoadSoundsSettings();
}

/* 434B40-434D2F 001EF	*/
void MenuModule::OnInputKey(uchar* param_1) {
    if (isSubWindowOpened || !isCalibrationEnabled) {
        return;
    }

    int iVar3 = uiWindow->GetMouseActivateSprite();
    float fVar1 = uiWindow->GetScale(iVar3).x;
    float fVar2 = uiWindow->GetScale(iVar3).y;
    if (param_1[DIK_LEFT] != '\0') {
        calibrationXChange += 1e-05f;
        uiWindow->SetScale(iVar3, fVar1 - calibrationXChange, fVar2);
    }
    if (param_1[DIK_RIGHT] != '\0') {
        calibrationXChange += 1e-05f;
        uiWindow->SetScale(iVar3, fVar1 + calibrationXChange,fVar2);
    }
    if (param_1[DIK_UP] != '\0') {
        calibrationYChange += 1e-05f;
        uiWindow->SetScale(iVar3, fVar1, fVar2 - calibrationYChange);
    }
    if (param_1[DIK_DOWN] != '\0') {
        calibrationYChange += 1e-05f;
        uiWindow->SetScale(iVar3, fVar1, fVar2 + calibrationYChange);
    }

    if (param_1[DIK_S] != '\0') {
        DebugLog("-----");
        DebugLog("scale: <%f , %f>", fVar1, fVar2);

        DebugLog("pos: <%f , %f>", uiWindow->GetPos(iVar3).x / GetWindowWidth(), uiWindow->GetPos(iVar3).y / GetWindowHeight());
        isCalibrationEnabled = false;
    }
}

/* 434D30-434D7F 0004F	*/
void MenuModule::OnExitYesNo(char* param_1) {
    if (strcmpi("Yes", param_1) == 0) {
        GetGame()->ExitGame();
    }
    if (strcmpi("No", param_1) == 0) {
        isExitWindowOpened = false;
        SetSubWindowOpened(false);
    }
}

/* 434D80-434F41 001C1	*/
void MenuModule::LoadCursorTextures() {
    cursorsTextureIDs[0] = uiWindow->AddTexture("data\\textures\\menu\\kursor.png");
    uiWindow->SetScale(cursorsTextureIDs[0], 1.0f, 1.0f);
    uiWindow->SetPos(cursorsTextureIDs[0], 0.1f, 0.1f, 0);
    uiWindow->Hide(cursorsTextureIDs[0]);

    cursorsTextureIDs[1] = uiWindow->AddTexture("data\\textures\\menu\\kursor1.png");
    uiWindow->SetScale(cursorsTextureIDs[1], 1.0f, 1.0f);
    uiWindow->SetPos(cursorsTextureIDs[1], 0.1f, 0.1f, 0);
    uiWindow->Hide(cursorsTextureIDs[1]);

    cursorsTextureIDs[2] = uiWindow->AddTexture("data\\textures\\menu\\kursor2.png");
    uiWindow->SetScale(cursorsTextureIDs[2], 1.0f, 1.0f);
    uiWindow->SetPos(cursorsTextureIDs[2], 0.1f, 0.1f, 0);
    uiWindow->Hide(cursorsTextureIDs[2]);

    cursorsTextureIDs[3] = uiWindow->AddTexture("data\\textures\\menu\\kursor3.png");
    uiWindow->SetScale(cursorsTextureIDs[3], 1.0f, 1.0f);
    uiWindow->SetPos(cursorsTextureIDs[3], 0.1f, 0.1f, 0);
    uiWindow->Hide(cursorsTextureIDs[3]);

    cursorsTextureIDs[4] = uiWindow->AddTexture("data\\textures\\menu\\kursor_stop.png");
    uiWindow->SetScale(cursorsTextureIDs[4], 1.0f, 1.0f);
    uiWindow->SetPos(cursorsTextureIDs[4], 0.1f, 0.1f, 0);
    uiWindow->Hide(cursorsTextureIDs[4]);
}

/* 434F50-434FF1 000A1	*/
void MenuModule::ChangeActiveCursor() {
    for (int index = 1; index < 4; index++) {
        uiWindow->Hide(cursorsTextureIDs[index]);
    }
    
    uiWindow->Hide(cursorsTextureIDs[0]);
    float fVar1 = timeGetTime() * 0.001f;
    if (fVar1 - lastCursorChangeTime > 0.1f) {
        lastCursorChangeTime = fVar1;
        activeCursorIndex++;
        if (activeCursorIndex > 3) {
            activeCursorIndex = 1;
        }
    }
}

/* 435000-43503B 0003B	*/
void MenuModule::ActivateDefaultCursor() {
    for (int i = 0; i < sizeof(cursorsTextureIDs)/sizeof(int); i++) {
        uiWindow->Hide(cursorsTextureIDs[i]);
    }
    activeCursorIndex = 0;
    isHoveringEnabledButton = false;
}

/* 435040-435067 00027	*/
void MenuModule::ActivateStopCursor() {
    ActivateDefaultCursor();
    activeCursorIndex = 4;
    uiWindow->Show(cursorsTextureIDs[activeCursorIndex]);
}

/* 435070-4351B8 00148	*/
void MenuModule::LoadSounds() {
    float fVar2 = ((GameSDK*) GetGame())->FUN00401e10();

    exitSoundID = soundsManager->LoadSound("data\\sounds\\menu\\wyjscie.wav");
    soundsManager->SetVolume(exitSoundID, fVar2);

    optionsSoundID = soundsManager->LoadSound("data\\sounds\\menu\\opcje.wav");
    soundsManager->SetVolume(optionsSoundID, fVar2);

    unk_17d4 = soundsManager->LoadSound("data\\sounds\\menu\\niedostepny.wav");
    soundsManager->SetVolume(optionsSoundID, fVar2);

    unk_17d8 = soundsManager->LoadSound("data\\sounds\\menu\\niedostepny.wav");
    soundsManager->SetVolume(optionsSoundID, fVar2);

    unk_17dc = soundsManager->LoadSound("data\\sounds\\menu\\niedostepny.wav");
    soundsManager->SetVolume(optionsSoundID, fVar2);

    selectLevelSoundID = soundsManager->LoadSound("data\\sounds\\menu\\wybierzpoziom.wav");
    soundsManager->SetVolume(selectLevelSoundID, fVar2);

    menuMusicSoundID = soundsManager->LoadSound("data\\sounds\\menu\\menu.wav");
    soundsManager->SetVolume(menuMusicSoundID, fVar2 * 0.8f);

    exitShortSoundID = soundsManager->LoadSound("data\\sounds\\wyjscie.wav");
    soundsManager->SetVolume(exitShortSoundID, fVar2);

    soundsManager->StopSound(exitShortSoundID);
}

/* 4351C0-4351D7 00017	*/
void MenuModule::PlayBackgroundMusic() {
    if (areSoundsMuted == NULL) {
        PlayMenuSound(exitShortSoundID);
    } 
}

/* 4351E0-435256 00076	*/
void MenuModule::StopAllSounds() {
    soundsManager->StopSound(exitSoundID);
    soundsManager->StopSound(optionsSoundID);
    soundsManager->StopSound(unk_17d4);
    soundsManager->StopSound(unk_17d8);
    soundsManager->StopSound(unk_17dc);
    soundsManager->StopSound(selectLevelSoundID);
    soundsManager->StopSound(exitShortSoundID);
}

/* 435260-4352AF 0004F	*/
void MenuModule::PlayMenuSound(int param_1) {
    if (isPlayingSound) {
        return;
    }

    isPlayingSound = true;
    playedSoundID = param_1;
    if (areSoundsMuted == NULL) {
        soundsManager->PlaySoundA(param_1, false);
    }
    soundsManager->EnableCallHandlerOnPlaySoundEnd(playedSoundID, this);
}

/* 4352B0-4352C8 00018	*/
void MenuModule::OnPlaySoundEnd(int param_1) {
    if (playedSoundID == param_1) {
        isPlayingSound = false;
    }
}

