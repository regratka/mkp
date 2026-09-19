#include "MenuModule.h"

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
    unk_1784 = false;
    unk_1785 = false;
    unk_1788 = 0.0f;
    unk_178c = 0.0f;
    unk_17a0 = -1;
    unk_17a4 = -1;
    unk_17d4 = -1;
    unk_17d8 = -1;
    unk_17dc = -1;
    unk_17e4 = -1;
    unk_17e8 = -1;
    unk_17b8 = -1;
    unk_17bc = -1;
    unk_17c0 = -1;
    unk_17cc = -1;
    unk_17d0 = -1;
    unk_1750 = -1;
    unk_17c4 = false;
    unk_17c8 = NULL;
    unk_1740 = false;
    unk_1755 = false;
    unk_17c5 = false;
    unk_1754 = false;
    unk_176c = 0;
    unk_1770 = 0.0f;
    unk_1774 = false;
    unk_1748 = NULL;
}

/* 4340B0-4340BC 0000C	*/
MenuModule::~MenuModule() {
}

/* 4340C0-4344FB 0043B	*/
void MenuModule::OnActivate() {
    unk_17c8 = new cMagMeshObject();
    CreateObject(unk_17c8);
    uiWindow = new UIWindow(this);
    CreateObject(uiWindow);
    
    uiWindow->FUN004134e0("data\\textures\\menu\\menu_start.png");
    uiWindow->FUN00413510(true);
    uiWindow->FUN00413580(false);
    
    unk_17a0 = uiWindow->AddTexture("data\\textures\\hud\\b1.png");
    uiWindow->SetScale(unk_17a0, 0.725f, 1.344f);
    uiWindow->SetPos(unk_17a0, 0.086f, 0.741f, 0);
    uiWindow->Hide(unk_17a0);
    
    unk_17a4 = uiWindow->AddTexture("data\\textures\\hud\\b1.png");
    uiWindow->SetScale(unk_17a4, 1.725f, 1.257f);
    uiWindow->SetPos(unk_17a4, 0.0937f, 0.225f, 0);
    uiWindow->Hide(unk_17a4);

    unk_17a8 = uiWindow->AddTexture("data\\textures\\hud\\b1.png");
    uiWindow->SetScale(unk_17a8, 1.725f, 3.553f);
    uiWindow->SetPos(unk_17a8, 0.323f, 0.346f, 0);
    uiWindow->Hide(unk_17a8);

    unk_17ac = uiWindow->AddTexture("data\\textures\\hud\\b1.png");
    uiWindow->SetScale(unk_17ac, 0.984f, 2.85f);
    uiWindow->SetPos(unk_17ac, 0.555f, 0.535f, 0);
    uiWindow->Hide(unk_17ac);

    unk_17b0 = uiWindow->AddTexture("data\\textures\\hud\\b1.png");
    uiWindow->SetScale(unk_17b0, 0.984f, 3.701f);
    uiWindow->SetPos(unk_17b0, 0.452f, 0.5f, 0);
    uiWindow->Hide(unk_17b0);
    
    unk_17b4 = uiWindow->AddTexture("data\\textures\\hud\\b1.png");
    uiWindow->SetScale(unk_17b4, 1.384f, 3.14f);
    uiWindow->SetPos(unk_17b4, 0.691f, 0.655f, 0);
    uiWindow->Hide(unk_17b4);

    unk_17b8 = uiWindow->AddTexture("data\\textures\\menu\\papatka_activate.png");
    uiWindow->SetScale(unk_17b8, 1.31f, 0.933f);
    uiWindow->SetPos(unk_17b8, 0.692f, 0.643f, 0);
    uiWindow->Hide(unk_17b8);

    unk_17bc = uiWindow->AddTexture("data\\textures\\menu\\ptak_activate.png");
    uiWindow->SetScale(unk_17bc, 0.777f, 1.1);
    uiWindow->SetPos(unk_17bc, 0.138f, 0.243f, 0);
    uiWindow->Hide(unk_17bc);

    unk_17c0 = uiWindow->AddTexture("data\\textures\\menu\\robaczek_activate.png");
    uiWindow->SetScale(unk_17c0, 0.63f, 1.1);
    uiWindow->SetPos(unk_17c0, 0.1f, 0.746f, 0);
    uiWindow->Hide(unk_17c0);

    menuChoiceWindow = new MenuOknoWyboru_CZ1();
    CreateObject(menuChoiceWindow);
    menuChoiceWindow->SetMenuModule(this);
    FUN00435070();
    FUN00434500();
}

/* 434500-434560 00060	*/
void MenuModule::FUN00434500() {
    unk_1744 = ((GameSDK*)GetGame())->unk_254c;
    unk_1748 = ((GameSDK*)GetGame())->unk_2548;

    if (unk_1744 == NULL) {
        unk_17c8->PlaySoundA(unk_17e4, true);
    } else {
        unk_17c8->StopSound(unk_17e4);
    }

}

/* 434560-434676 00116	*/
void MenuModule::OnFrame() {
    if (windowExit->FUN00426c40()) {
        return;
    } 

    if (unk_1774) {
        FUN00434f50();
    } else if (unk_1755) {
        FUN00435040();
    } else {
        FUN00435000();
    }

    tagPOINT local_8;
    GetCursorPos(&local_8);
    ScreenToClient(GetHandleWindow(), &local_8);
    int iVar1 = GetWindowWidth();
    int iVar2 = GetWindowHeight();
    unk_177c = local_8.x / (float)iVar1;
    unk_1780 = local_8.y / (float)iVar2;
    uiWindow->SetScale(unk_1758[unk_176c], 1.0f, 1.0f);
    uiWindow->SetPos(unk_1758[unk_176c], 
        unk_177c +  0.01f, unk_1780 + 0.01f, 0);
    uiWindow->Show(unk_1758[unk_176c]);
}

/* 434680-434871 001F1	*/
void MenuModule::FUN00434680() {
    menuOpcje = new CMenuOpcje();
    CreateObject(menuOpcje);
    menuOpcje->OnActivateLevel();
    menuOpcje->menuModule = this;
    windowExit = new CWindowExitYesNo();
    CreateObject(windowExit);
    uiWindow->FUN00413580(true);
    uiWindow->Show(unk_17a0);
    uiWindow->EnableCheckMouse(unk_17a0, true);
    uiWindow->Show(unk_17a4);
    uiWindow->EnableCheckMouse(unk_17a4, true);
    uiWindow->Show(unk_17a8);
    uiWindow->EnableCheckMouse(unk_17a8, true);
    uiWindow->Show(unk_17ac);
    uiWindow->EnableCheckMouse(unk_17ac, true);
    uiWindow->Show(unk_17b0);
    uiWindow->EnableCheckMouse(unk_17b0, true);
    uiWindow->Show(unk_17b4);
    uiWindow->EnableCheckMouse(unk_17b4, true);
    uiWindow->EnableCheckMouse(unk_17bc, true);
    uiWindow->EnableCheckMouse(unk_17c0, true);
    FUN00434d80();
    EnableCallHandler("OnFrame");
    EnableCallHandler("OnInputMouse");
    EnableCallHandler("OnInputKey");
    FUN00434500();
}   

/* 434880-434992 00112	*/
void MenuModule::OnMouseArrive(int param_1) {

    if (unk_1740) {
        return;
    }

    if (unk_17a0 == param_1) {
        uiWindow->Show(unk_17c0);
        unk_1750 = unk_17cc;
        if (unk_1748 == NULL) {
            FUN00435260(unk_17cc);
        }
        unk_1774 = true;
    }

    if (unk_17a4 == param_1) {
        uiWindow->Show(unk_17bc);
        if (unk_1748 == NULL) {
            FUN00435260(unk_17d0);
        }
        unk_1774 = true;
        unk_1750 = unk_17d0;
    }

    if (unk_17a8 == param_1) {
        unk_1755 = true;
    }

    if (unk_17ac == param_1) {
        unk_1755 = true;
    }
    
    if (unk_17b0 == param_1) {
        unk_1755 = true;
    }

    if (unk_17b4 == param_1) {
        uiWindow->Show(unk_17b8);
        if (unk_1748 == NULL) {
            FUN00435260(unk_17e0);
        }
        unk_1774 = true;
        unk_1750 = unk_17e0;
    }
}

/* 4349A0-4349EA 0004A	*/
void MenuModule::FUN004349a0(bool param_1) {
    unk_1740 = param_1;
    if (!unk_1740) {
        uiWindow->Hide(unk_17b8);
        uiWindow->Hide(unk_17bc);
        uiWindow->Hide(unk_17c0);
    }
}

/* 4349F0-434A4C 0005C	*/
void MenuModule::OnMouseLeave(int param_1) {
    if (!unk_1740) {
        unk_1774 = false;
        unk_1755 = false;
        unk_1750 = -1;
        uiWindow->Hide(unk_17b8);
        uiWindow->Hide(unk_17c0);
        uiWindow->Hide(unk_17bc);
    }
}

/* 434A50-434B2E 000DE	*/
void MenuModule::OnInputMouse(float param_1, float param_2, bool param_3, bool param_4) {
    if (unk_1740) {
        return;
    }

    if (param_3 && !unk_17c5) {
        if (unk_17a0 == uiWindow->GetMouseActivateSprite()) {
            FUN00435000();
            FUN004351e0();
            if (windowExit != NULL) {
                windowExit->FUN004269e0(this);
            }
            unk_17c4 = true;
            FUN004349a0(true);
        }
        if (unk_17a4 == uiWindow->GetMouseActivateSprite()) {
            FUN00435000();
            FUN004349a0(true);
            if (menuOpcje != NULL) {
                menuOpcje->FUN00438010(this);
            }
        }

        if (unk_17b4 == uiWindow->GetMouseActivateSprite()) {
            FUN004349a0(true);
            if (menuChoiceWindow != NULL) {
                menuChoiceWindow->OpenWindow();
            }
            FUN00435000();
        }
    }
    unk_17c5 = param_3;
}

/* 434B30-434B35 00005	*/
void MenuModule::OnUpdateMenuSettings() {
    FUN00434500();
}

/* 434B40-434D2F 001EF	*/
void MenuModule::OnInputKey(uchar* param_1) {
    if (unk_1740 || !unk_1784) {
        return;
    }

    int iVar3 = uiWindow->GetMouseActivateSprite();
    D3DXVECTOR2 DStack_10(uiWindow->GetScale(iVar3).x, uiWindow->GetScale(iVar3).y);

    if (param_1[203] != '\0') {
        unk_1788 += 1e-05;
        uiWindow->SetScale(iVar3, DStack_10.x - unk_1788, DStack_10.y);
    }
    if (param_1[205] != '\0') {
        unk_1788 += 1e-05;
        uiWindow->SetScale(iVar3, DStack_10.x + unk_1788, DStack_10.y);
    }
    if (param_1[200] != '\0') {
        unk_178c += 1e-05;
        uiWindow->SetScale(iVar3, DStack_10.x, DStack_10.y - unk_178c);
    }
    if (param_1[208] != '\0') {
        unk_1788 += 1e-05;
        uiWindow->SetScale(iVar3, DStack_10.x, DStack_10.y + unk_178c);
    }

    if (param_1[31] != '\0') {
        DebugLog("-----");
        DebugLog("scale: <%f , %f>", DStack_10.x, DStack_10.y);
        DStack_10.x = uiWindow->GetPos(iVar3).x;


    }
}

/* 434D30-434D7F 0004F	*/
void MenuModule::OnExitYesNo(char* param_1) {
}

/* 434D80-434F41 001C1	*/
void MenuModule::FUN00434d80() {
}

/* 434F50-434FF1 000A1	*/
void MenuModule::FUN00434f50() {
}

/* 435000-43503B 0003B	*/
void MenuModule::FUN00435000() {
}

/* 435040-435067 00027	*/
void MenuModule::FUN00435040() {
}

/* 435070-4351B8 00148	*/
void MenuModule::FUN00435070() {
}

/* 4351C0-4351D7 00017	*/
void MenuModule::FUN004351c0() {
}

/* 4351E0-435256 00076	*/
void MenuModule::FUN004351e0() {
}

/* 435260-4352AF 0004F	*/
void MenuModule::FUN00435260(int param_1) {
}

/* 4352B0-4352C8 00018	*/
void MenuModule::OnPlaySoundEnd(int param_1) {
}

