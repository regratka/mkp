#include "COknoTajnyKod.h"

#include "GameSDK.h"


/* 419BA0-419BA1 00001	*/
void COknoTajnyKod::OnActivateLevel() {
}

/* 4272F0-42734D 0005D	*/
COknoTajnyKod::COknoTajnyKod(CPlayerTPP* param_1) {
}

/* 427370-42737C 0000C	*/
COknoTajnyKod::~COknoTajnyKod() {
}

/* 427380-427651 002D1	*/
void COknoTajnyKod::OnActivate() {
}

/* 427660-4276E9 00089	*/
void COknoTajnyKod::FUN00427660() {
    DisableCallHandler("OnFrame");
    DisableCallHandler("OnInputMouse");
    DisableCallHandler("OnInputKey");
    FUN00427910();
}

/* 4276F0-42785D 0016D	*/
void COknoTajnyKod::FUN004276f0() {
}

/* 427860-427901 000A1	*/
void COknoTajnyKod::FUN00427860() {
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
        uiEdit->FUN00412a20(false);
        player->FUN00409910((char*)player);
    }

    if (motorboat != NULL) {
        uiEdit->FUN00412a20(false);
        motorboat->FUN0040e550((char*)motorboat);  
    }

    FUN00427660();
}

