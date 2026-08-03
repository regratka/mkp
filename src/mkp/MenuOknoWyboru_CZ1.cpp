#include "MenuOknoWyboru_CZ1.h"
#include "GameSDK.h"

/* 435380-435451 000D1	*/
MenuOknoWyboru_CZ1::MenuOknoWyboru_CZ1() {
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
    unk_1744 = true;
    unk_175c = 1;
    uiWindow = (UIWindow *)0x0;
    menuModule = (MenuModule *)0x0;
    unk_17d6 = false;
    unk_17d7 = false;
    unk_17d8 = false;
    unk_17d9 = false;
    unk_17da = false;
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
}

/* 435C90-435D38 000A8	*/
void MenuOknoWyboru_CZ1::FUN00435c90() {
}

/* 435D40-435E60 00120	*/
void MenuOknoWyboru_CZ1::FUN00435d40() {
}

/* 435E60-435F9E 0013E	*/
void MenuOknoWyboru_CZ1::OnMouseArrive(int param_1)
{
}

/* 435FA0-435FE3 00043	*/
void MenuOknoWyboru_CZ1::OnMouseLeave(int param_1)
{
}

/* 435FF0-436158 00168	*/
void MenuOknoWyboru_CZ1::OnInputMouse(float param_1, float param_2, bool param_3, bool param_4)
{
}

/* 436160-436321 001C1	*/
void MenuOknoWyboru_CZ1::OnActivateLevel()
{
}

/* 436330-4363D1 000A1	*/
void MenuOknoWyboru_CZ1::FUN00436330()
{
}

/* 4363E0-43641B 0003B	*/
void MenuOknoWyboru_CZ1::FUN004363e0()
{
}

/* 436420-436447 00027	*/
void MenuOknoWyboru_CZ1::FUN00436420()
{
}

/* 436450-4368BC 0046C	*/
void MenuOknoWyboru_CZ1::FUN00436450()
{
}

/* 4368C0-436C14 00354	*/
void MenuOknoWyboru_CZ1::FUN004368c0()
{
}
