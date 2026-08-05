#include "MenuOknoWyboru_CZ1.h"

#include "GameSDK.h"

/* 435380-435451 000D1	*/
MenuOknoWyboru_CZ1::MenuOknoWyboru_CZ1() {
    uiWindow = NULL;
    menuModule = NULL;
    unk_179c = -1;
    lev1TexID = -1;
    lev2TexID = -1;
    lev3TexID = -1;
    lev4TexID = -1;
    lev5TexID = -1;
    lev6TexID = -1;
    unk_1758 = -1;
    unk_17b8 = -1;
    deactLev1TexID = -1;
    deactLev2TexID = -1;
    deactLev3TexID = -1;
    deactLev4TexID = -1;
    deactLev5TexID = -1;
    deactLev6TexID = -1;
    unk_17d4 = true;
    unk_17d5 = true;
    unk_17d6 = false;
    unk_17d7 = false;
    unk_17d8 = false;
    unk_17d9 = false;
    unk_17da = false;
    unk_1744 = true;
    unk_175c = 1;
    activeCursorIndex = 0;
    lastCursorChangeTime = 0.0f;
    unk_1780 = false;
    unk_1774 = false;
}

/* 435480-43548C 0000C	*/
MenuOknoWyboru_CZ1::~MenuOknoWyboru_CZ1() {
}

/* 435490-435B51 006C1	*/
void MenuOknoWyboru_CZ1::OnActivate() {
    unk_1740 = ((GameSDK *)GetGame())->unk_2548;

    uiWindow = new UIWindow(this);
    CreateObject(uiWindow);
    uiWindow->FUN004134e0("data\\textures\\menu\\ramka.png");
    uiWindow->FUN00413540(D3DXVECTOR2(1.0f, 0.8f));
    uiWindow->FUN00413560(D3DXVECTOR2(0.552f, 0.466f));
    uiWindow->FUN00413580(false);

    doorTexID = uiWindow->AddTexture("data\\textures\\hud\\drzwi.png");
    uiWindow->SetScale(doorTexID, 0.7f, 0.7f);
    uiWindow->SetPos(doorTexID, 0.823f, 0.163f, 0);
    uiWindow->Hide(doorTexID);
    uiWindow->EnableCheckMouse(doorTexID, true);

    doorActiveTexID = uiWindow->AddTexture("data\\textures\\hud\\drzwi_a.png");
    uiWindow->SetScale(doorActiveTexID, 0.7f, 0.7f);
    uiWindow->SetPos(doorActiveTexID, 0.823f, 0.163f, 0);
    uiWindow->Hide(doorActiveTexID);
    uiWindow->EnableCheckMouse(doorActiveTexID, true);

    lev1TexID = uiWindow->AddTexture("data\\textures\\menu\\l1.png");
    uiWindow->SetScale(lev1TexID, 0.9f, 0.9f);
    uiWindow->SetPos(lev1TexID, 0.4f, 0.34f, 0);
    uiWindow->Hide(lev1TexID);
    uiWindow->EnableCheckMouse(lev1TexID, true);

    deactLev1TexID = uiWindow->AddTexture("data\\textures\\menu\\l1_deact.png");
    uiWindow->SetScale(deactLev1TexID, 0.9f, 0.9f);
    uiWindow->SetPos(deactLev1TexID, 0.4f, 0.34f, 0);
    uiWindow->Hide(deactLev1TexID);
    uiWindow->EnableCheckMouse(deactLev1TexID, true);

    lev2TexID = uiWindow->AddTexture("data\\textures\\menu\\l2.png");
    uiWindow->SetScale(lev2TexID, 0.9f, 0.9f);
    uiWindow->SetPos(lev2TexID, 0.56f, 0.34f, 0);
    uiWindow->Hide(lev2TexID);
    uiWindow->EnableCheckMouse(lev2TexID, true);

    deactLev2TexID = uiWindow->AddTexture("data\\textures\\menu\\l2_deact.png");
    uiWindow->SetScale(deactLev2TexID, 0.9f, 0.9f);
    uiWindow->SetPos(deactLev2TexID, 0.56f, 0.34f, 0);
    uiWindow->Hide(deactLev2TexID);
    uiWindow->EnableCheckMouse(deactLev2TexID, true);

    lev3TexID = uiWindow->AddTexture("data\\textures\\menu\\l3.png");
    uiWindow->SetScale(lev3TexID, 0.9f, 0.9f);
    uiWindow->SetPos(lev3TexID, 0.72f, 0.34f, 0);
    uiWindow->Hide(lev3TexID);
    uiWindow->EnableCheckMouse(lev3TexID, true);

    deactLev3TexID = uiWindow->AddTexture("data\\textures\\menu\\l3_deact.png");
    uiWindow->SetScale(deactLev3TexID, 0.9f, 0.9f);
    uiWindow->SetPos(deactLev3TexID, 0.72f, 0.34f, 0);
    uiWindow->Hide(deactLev3TexID);
    uiWindow->EnableCheckMouse(deactLev3TexID, true);

    lev4TexID = uiWindow->AddTexture("data\\textures\\menu\\l4.png");
    uiWindow->SetScale(lev4TexID, 0.9f, 0.9f);
    uiWindow->SetPos(lev4TexID, 0.4f, 0.55f, 0);
    uiWindow->Hide(lev4TexID);
    uiWindow->EnableCheckMouse(lev4TexID, true);

    deactLev4TexID = uiWindow->AddTexture("data\\textures\\menu\\l4_deact.png");
    uiWindow->SetScale(deactLev4TexID, 0.9f, 0.9f);
    uiWindow->SetPos(deactLev4TexID, 0.4f, 0.55f, 0);
    uiWindow->Hide(deactLev4TexID);
    uiWindow->EnableCheckMouse(deactLev4TexID, true);

    lev5TexID = uiWindow->AddTexture("data\\textures\\menu\\l5.png");
    uiWindow->SetScale(lev5TexID, 0.9f, 0.9f);
    uiWindow->SetPos(lev5TexID, 0.56f, 0.55f, 0);
    uiWindow->Hide(lev5TexID);
    uiWindow->EnableCheckMouse(lev5TexID, true);

    deactLev5TexID = uiWindow->AddTexture("data\\textures\\menu\\l5_deact.png");
    uiWindow->SetScale(deactLev5TexID, 0.9f, 0.9f);
    uiWindow->SetPos(deactLev5TexID, 0.56f, 0.55f, 0);
    uiWindow->Hide(deactLev5TexID);
    uiWindow->EnableCheckMouse(deactLev5TexID, true);

    lev6TexID = uiWindow->AddTexture("data\\textures\\menu\\l6.png");
    uiWindow->SetScale(lev6TexID, 0.9f, 0.9f);
    uiWindow->SetPos(lev6TexID, 0.72f, 0.55f, 0);
    uiWindow->Hide(lev6TexID);
    uiWindow->EnableCheckMouse(lev6TexID, true);

    deactLev6TexID = uiWindow->AddTexture("data\\textures\\menu\\l6_deact.png");
    uiWindow->SetScale(deactLev6TexID, 0.9f, 0.9f);
    uiWindow->SetPos(deactLev6TexID, 0.72f, 0.55f, 0);
    uiWindow->Hide(deactLev6TexID);
    uiWindow->EnableCheckMouse(deactLev6TexID, true);

    FUN004368c0();
}



/* 435B60-435B6D 0000D	*/
void MenuOknoWyboru_CZ1::FUN00435b60(MenuModule *param_1) {
    menuModule = param_1;
}

/* 435B80-435C81 00101	*/
void MenuOknoWyboru_CZ1::OnFrame() {
    if (unk_1780) {
        FUN00436330();
    } else if (unk_1774) {
        FUN00436420();
    } else {
        FUN004363e0();
    }

    POINT local_8;
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

/* 435C90-435D38 000A8	*/
void MenuOknoWyboru_CZ1::FUN00435c90() {
    uiWindow->FUN00413580(true);
    uiWindow->Show(doorTexID);
    uiWindow->Show(lev1TexID);
    uiWindow->Show(lev2TexID);
    uiWindow->Show(lev3TexID);
    uiWindow->Show(lev4TexID);
    uiWindow->Show(lev5TexID);
    uiWindow->Show(lev6TexID);
    FUN00436450();
    EnableCallHandler("OnInputMouse");
    EnableCallHandler("OnFrame");
}

/* 435D40-435E60 00120	*/
void MenuOknoWyboru_CZ1::FUN00435d40() {
    FUN004363e0();
    uiWindow->FUN00413580(false);
    uiWindow->Hide(doorTexID);
    uiWindow->Hide(doorActiveTexID);
    uiWindow->Hide(lev1TexID);
    uiWindow->Hide(lev2TexID);
    uiWindow->Hide(lev3TexID);
    uiWindow->Hide(lev4TexID);
    uiWindow->Hide(lev5TexID);
    uiWindow->Hide(lev6TexID);
    uiWindow->Hide(deactLev1TexID);
    uiWindow->Hide(deactLev2TexID);
    uiWindow->Hide(deactLev3TexID);
    uiWindow->Hide(deactLev4TexID);
    uiWindow->Hide(deactLev5TexID);
    uiWindow->Hide(deactLev6TexID);
    DisableCallHandler("OnInputMouse");
    DisableCallHandler("OnFrame");
    if (menuModule != NULL) {
        menuModule->FUN004349a0(false);
    }
}

/* 435E60-435F9E 0013E	*/
void MenuOknoWyboru_CZ1::OnMouseArrive(int param_1) {
    unk_1780 = true;
    if (unk_17b8 == param_1 || deactLev1TexID == param_1 || deactLev2TexID == param_1 || deactLev3TexID == param_1
            || deactLev4TexID == param_1 || deactLev5TexID == param_1 || deactLev6TexID == param_1 ) {
        unk_1780 = false;
        unk_1774 = true;
    }

    if (lev1TexID == param_1 && !unk_17d5) {
        unk_1780 = false;
        unk_1774 = true;
    }
    if (lev2TexID == param_1 && !unk_17d6) {
        unk_1780 = false;
        unk_1774 = true;
    }
    if (lev3TexID == param_1 && !unk_17d7) {
        unk_1780 = false;
        unk_1774 = true;
    }
    if (lev4TexID == param_1 && !unk_17d8) {
        unk_1780 = false;
        unk_1774 = true;
    }
    if (lev5TexID == param_1 && !unk_17d9) {
        unk_1780 = false;
        unk_1774 = true;
    }
    if (lev6TexID == param_1 && !unk_17da) {
        unk_1780 = false;
        unk_1774 = true;
    }

    if (doorTexID == param_1) {
        uiWindow->Hide(doorTexID);
        uiWindow->Show(doorActiveTexID);
        if (menuModule != NULL) {
            menuModule->FUN004351c0();
        }
    }
}

/* 435FA0-435FE3 00043	*/
void MenuOknoWyboru_CZ1::OnMouseLeave(int param_1) {
    unk_1780 = false;
    unk_1774 = false;
    if (doorActiveTexID == param_1) {
        uiWindow->Hide(doorActiveTexID);
        uiWindow->Show(doorTexID);
    }
}

/* 435FF0-436158 00168	*/
void MenuOknoWyboru_CZ1::OnInputMouse(float param_1, float param_2, bool param_3, bool param_4) {
    if (param_3 && !unk_1744) {
        if (doorActiveTexID == uiWindow->GetMouseActivateSprite()) {
            FUN00435d40();
        }
        if (lev1TexID == uiWindow->GetMouseActivateSprite()) {
            if (unk_17d5) {
                GetGame()->LoadLevel("data\\levels\\Intro\\intro04.lev");
            }
        }
        if (lev2TexID == uiWindow->GetMouseActivateSprite()) {
            if (unk_17d6) {
                GetGame()->LoadLevel("data\\levels\\Level02\\Level02a.lev");
            }
        }
        if (lev3TexID == uiWindow->GetMouseActivateSprite() && unk_17d7) {
            if (unk_17d7) {
                GetGame()->LoadLevel("data\\levels\\Level03\\Level03.lev");
            }
        }
        if (lev4TexID == uiWindow->GetMouseActivateSprite()) {
            if (unk_17d8) {
                GetGame()->LoadLevel("data\\levels\\Level04\\level04.lev");
            }
        }
        if (lev5TexID == uiWindow->GetMouseActivateSprite()) {
            if (unk_17d9) {
                GetGame()->LoadLevel("data\\levels\\Level05\\Level05kk.lev");
            }
        }
        if (lev6TexID == uiWindow->GetMouseActivateSprite()) {
            if (unk_17da) {
                GetGame()->LoadLevel("data\\levels\\Level06\\Level06.lev");
            }
        } 
    }
    unk_1744 = param_3;
}

/* 436160-436321 001C1	*/
void MenuOknoWyboru_CZ1::OnActivateLevel() {
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

/* 436330-4363D1 000A1	*/
void MenuOknoWyboru_CZ1::FUN00436330() {
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

/* 4363E0-43641B 0003B	*/
void MenuOknoWyboru_CZ1::FUN004363e0() {
    for (int i = 0; i < sizeof(cursorsTextureIDs)/sizeof(int); i++) {
        uiWindow->Hide(cursorsTextureIDs[i]);
    }
    activeCursorIndex = 0;
    unk_1780 = false;
}

/* 436420-436447 00027	*/
void MenuOknoWyboru_CZ1::FUN00436420() {
    FUN004363e0();
    activeCursorIndex = 4;
    uiWindow->Show(cursorsTextureIDs[activeCursorIndex]);
}

/* 436450-4368BC 0046C	*/
void MenuOknoWyboru_CZ1::FUN00436450() {
    uiWindow->Hide(lev1TexID);
    uiWindow->Hide(lev2TexID);
    uiWindow->Hide(lev3TexID);
    uiWindow->Hide(lev4TexID);
    uiWindow->Hide(lev5TexID);
    uiWindow->Hide(lev6TexID);
    uiWindow->Hide(deactLev1TexID);
    uiWindow->Hide(deactLev2TexID);
    uiWindow->Hide(deactLev3TexID);
    uiWindow->Hide(deactLev4TexID);
    uiWindow->Hide(deactLev5TexID);
    uiWindow->Hide(deactLev6TexID);

    if (unk_175c == 1 || unk_175c == 0) {
        uiWindow->Show(lev1TexID);
        uiWindow->Hide(deactLev1TexID);
        uiWindow->Show(deactLev2TexID);
        uiWindow->Show(deactLev3TexID);
        uiWindow->Show(deactLev4TexID);
        uiWindow->Show(deactLev5TexID);
        uiWindow->Show(deactLev6TexID);
    }
    if (unk_175c == 2) {
        uiWindow->Show(lev1TexID);
        uiWindow->Show(lev2TexID);
        uiWindow->Hide(deactLev1TexID);
        uiWindow->Hide(deactLev2TexID);
        uiWindow->Show(deactLev3TexID);
        uiWindow->Show(deactLev4TexID);
        uiWindow->Show(deactLev5TexID);
        uiWindow->Show(deactLev6TexID);
    }
    if (unk_175c == 3) {
        uiWindow->Show(lev1TexID);
        uiWindow->Show(lev2TexID);
        uiWindow->Show(lev3TexID);
        uiWindow->Hide(deactLev1TexID);
        uiWindow->Hide(deactLev2TexID);
        uiWindow->Hide(deactLev3TexID);
        uiWindow->Show(deactLev4TexID);
        uiWindow->Show(deactLev5TexID);
        uiWindow->Show(deactLev6TexID);
    }
    if (unk_175c == 4) {
        uiWindow->Show(lev1TexID);
        uiWindow->Show(lev2TexID);
        uiWindow->Show(lev3TexID);
        uiWindow->Show(lev4TexID);
        uiWindow->Hide(deactLev1TexID);
        uiWindow->Hide(deactLev2TexID);
        uiWindow->Hide(deactLev3TexID);
        uiWindow->Hide(deactLev4TexID);
        uiWindow->Show(deactLev5TexID);
        uiWindow->Show(deactLev6TexID);
    }
    if (unk_175c == 5) {
        uiWindow->Show(lev1TexID);
        uiWindow->Show(lev2TexID);
        uiWindow->Show(lev3TexID);
        uiWindow->Show(lev4TexID);
        uiWindow->Show(lev5TexID);
        uiWindow->Hide(deactLev1TexID);
        uiWindow->Hide(deactLev2TexID);
        uiWindow->Hide(deactLev3TexID);
        uiWindow->Hide(deactLev4TexID);
        uiWindow->Hide(deactLev5TexID);
        uiWindow->Show(deactLev6TexID);
    }
    if (unk_175c == 6) {
        uiWindow->Show(lev1TexID);
        uiWindow->Show(lev2TexID);
        uiWindow->Show(lev3TexID);
        uiWindow->Show(lev4TexID);
        uiWindow->Show(lev5TexID);
        uiWindow->Show(lev6TexID);
        uiWindow->Hide(deactLev1TexID);
        uiWindow->Hide(deactLev2TexID);
        uiWindow->Hide(deactLev3TexID);
        uiWindow->Hide(deactLev4TexID);
        uiWindow->Hide(deactLev5TexID);
        uiWindow->Hide(deactLev6TexID);
    }
}

/* 4368C0-436C14 00354	*/
void MenuOknoWyboru_CZ1::FUN004368c0() {
    int local_a4 = 1; 
    std::ifstream stream;
    stream.open("data\\save\\nl.sav", std::ios::binary);
    if (stream.fail()) {
        return;
    }
    stream.read((char*) &local_a4, sizeof(int));
    stream.close();

    unk_175c = local_a4;
    unk_17d4 = false;
    unk_17d5 = false;
    unk_17d6 = false;
    unk_17d7 = false;
    unk_17d8 = false;
    unk_17d9 = false;
    unk_17da = false;

    if (unk_175c == 1) {
        unk_17d4 = true;
        unk_17d5 = true;
        unk_17d6 = false;
        unk_17d7 = false;
        unk_17d8 = false;
        unk_17d9 = false;
        unk_17da = false;
    }  
    
    if (unk_175c == 2) {
        unk_17d4 = true;
        unk_17d5 = true;
        unk_17d6 = true;
        unk_17d7 = false;
        unk_17d8 = false;
        unk_17d9 = false;
        unk_17da = false;
    }  
    
    if (unk_175c == 3) {
        unk_17d4 = true;
        unk_17d5 = true;
        unk_17d6 = true;
        unk_17d7 = true;
        unk_17d8 = false;
        unk_17d9 = false;
        unk_17da = false;
    }  
    
    if (unk_175c == 4) {
        unk_17d4 = true;
        unk_17d5 = true;
        unk_17d6 = true;
        unk_17d7 = true;
        unk_17d8 = true;
        unk_17d9 = false;
        unk_17da = false;
    }

    if (unk_175c == 5) {
        unk_17d4 = true;
        unk_17d5 = true;
        unk_17d6 = true;
        unk_17d7 = true;
        unk_17d8 = true;
        unk_17d9 = true;
        unk_17da = false;
    } 

    if (unk_175c == 6) {
        unk_17d4 = true;
        unk_17d5 = true;
        unk_17d6 = true;
        unk_17d7 = true;
        unk_17d8 = true;
        unk_17d9 = true;
        unk_17da = true;
    }

}
