#include "UIButton.h"

/* 411860-411963 00103	*/
UIButton::UIButton() {
    ZeroMemory(buttonText, sizeof(buttonText));
    parent = NULL;
    bgTexID = -1;
    textTexID = -1;
    unk_18aa = true;
    isEnabled = true;
    hoverBgTexID = -1;
    unk_18a8 = false;
    isHovered = false;
    isPressed = false;
    musicSegment = NULL;
    musicSegment2 = NULL;
    hasPressTexture = false;
    hasHoverTexture = false;
    bgPosX = 0.5f;
    bgPosY = 0.5f;
    bgScaleX = 1.0f;
    bgScaleY = 1.0f;
    defaultTextColor.r = 0.3515625f;
    defaultTextColor.g = 0.3515625f;
    defaultTextColor.b = 0.3515625f;
    defaultTextColor.a = 1.0f;
    pressedTextColor.r = 0.5f;
    pressedTextColor.g = 0.5f;
    pressedTextColor.b = 0.5f;
    pressedTextColor.a = 1.0f;
    hoveredTextColor.r = 0.0f;
    hoveredTextColor.g = 1.0f;
    hoveredTextColor.b = 0.0f;
    hoveredTextColor.a = 1.0f;
    disabledTextColor.r = 0.3515625f;
    disabledTextColor.g = 0.3515625f;
    disabledTextColor.b = 0.3515625f;
    disabledTextColor.a = 1.0f;
}

/* 411990-41199C 0000C	*/
UIButton::~UIButton() {
}

/* 4119A0-411B13 00173	*/
void UIButton::SetTexture(char* param_1, char* param_2, cMagSprite* param_3) {
    parent = param_3;
    bgTexID = AddTexture(param_1);
    SetScale(bgTexID, bgScaleX, bgScaleY);
    SetPos(bgTexID, bgPosX, bgPosY, 0);
    EnableCheckMouse(bgTexID, true);
    Show(bgTexID);

    if (param_2 != NULL) {
        SetButtonText(param_2);
        D3DXVECTOR2 fStack_8 = GetSize(bgTexID);
        fStack_8.x /= 2;
        fStack_8.y /= 2;
        float fVar1 = fStack_8.x / GetWindowWidth();
        float fVar2 = fStack_8.y / GetWindowHeight();
        fVar1 = fVar1 + bgPosX - fVar1 - 0.04f;
        fVar2 = fVar2 + bgPosY - fVar2 - 0.02f;

        textTexID = SetText(buttonText, fVar1, fVar2,
            defaultTextColor.r, defaultTextColor.g, defaultTextColor.b, defaultTextColor.a);
        ShowText(textTexID, true);
    }
    EnableCallHandler("OnInputMouse");
}

/* 411B20-411B95 00075	*/
void UIButton::SetHoverTexture(char* param_1) {
    hasHoverTexture = true;
    hoverBgTexID = AddTexture(param_1);
    SetScale(hoverBgTexID, bgScaleX, bgScaleY);
    SetPos(hoverBgTexID, bgPosX, bgPosY, 0);
    EnableCheckMouse(hoverBgTexID, true);
    Hide(hoverBgTexID);
}

/* 411BA0-411C15 00075	*/
void UIButton::SetPressTexture(char* param_1) {
    pressBgTexID = AddTexture(param_1);
    SetScale(pressBgTexID, bgScaleX, bgScaleY);
    SetPos(pressBgTexID, bgPosX, bgPosY, 0);
    EnableCheckMouse(pressBgTexID, true);
    Hide(pressBgTexID);
    hasPressTexture = true;
}

/* 411C20-411C4B 0002B	*/
void UIButton::SetDisabledTextColor(float param_1, float param_2, float param_3, float param_4) {
    disabledTextColor.r = param_1;
    disabledTextColor.g = param_2;
    disabledTextColor.b = param_3;
    disabledTextColor.a = param_4;
}

/* 411C50-411D46 000F6	*/
void UIButton::SetButtonPosition(float param_1, float param_2) {
    bgPosX = param_1;
    bgPosY = param_2;
    SetScale(bgTexID, bgScaleX, bgScaleY);
    SetPos(bgTexID, bgPosX, bgPosY, 0);
    D3DXVECTOR2 fStack_8 = GetSize(bgTexID);
    fStack_8.x /= 2;
    fStack_8.y /= 2;
    float fVar1 = fStack_8.x / GetWindowWidth();
    float fVar2 = fStack_8.y / GetWindowHeight();    
    fVar1 = fVar1 + bgPosX - fVar1 - 0.05f;
    fVar2 = fVar2 + bgPosY - fVar2 - 0.02f;

    SetTextPosition(textTexID, fVar1, fVar2);
}

/* 411D50-411E3C 000EC	*/
void UIButton::SetButtonScale(float param_1, float param_2) {
    bgScaleX = param_1;
    bgScaleY = param_2;
    SetScale(bgTexID, bgScaleX, bgScaleY);
    SetPos(bgTexID, bgPosX, bgPosY, 0);
    D3DXVECTOR2 fStack_8 = GetSize(bgTexID);
    fStack_8.x /= 2;
    fStack_8.y /= 2;
    float fVar1 = fStack_8.x / GetWindowWidth();
    float fVar2 = fStack_8.y / GetWindowHeight();    
    fVar1 = fVar1 + bgPosX - fVar1 - 0.05f;
    fVar2 = fVar2 + bgPosY - fVar2 - 0.02f;

    SetTextPosition(textTexID, fVar1, fVar2);
}

/* 411E40-411E90 00050	*/
void UIButton::SetButtonText(char* param_1) {
    ZeroMemory(buttonText, sizeof(buttonText));
    strcpy(buttonText, param_1);
    SetText(textTexID, buttonText);
}

/* 411E90-411EA5 00015	*/
void UIButton::SetButtonAlpha(float param_1) {
    SetAlpha(bgTexID, param_1);
}

/* 411EB0-411F26 00076	*/
void UIButton::EnableButton(bool param_1) {
    isEnabled = param_1;
    if (!param_1) {
        SetTextColor(textTexID, disabledTextColor.r, disabledTextColor.g, disabledTextColor.b, disabledTextColor.a);
        isHovered = false;
    } else {
        SetTextColor(textTexID, defaultTextColor.r, defaultTextColor.g, defaultTextColor.b, defaultTextColor.a);
    }
}

/* 411F30-411FA2 00072	*/
void UIButton::SetButtonVisibility(bool param_1) {
    if (!param_1) {
        EnableButton(false);
        ShowText(textTexID, false);
        Hide(bgTexID);
        Hide(hoverBgTexID);
    } else {
        EnableButton(true);
        ShowText(textTexID, true);
        Show(bgTexID);
    }
}

/* 411FB0-411FC8 00018	*/
void UIButton::PlayHoverSound() {
    if (musicSegment != NULL) {
        musicSegment->Play();
    }
}

/* 411FD0-411FE8 00018	*/
void UIButton::PlayPressSound() {
    if (musicSegment2 != NULL) {
        musicSegment2->Play();
    }
}

/* 411FF0-412087 00097	*/
void UIButton::OnMouseArrive(int param_1) {
    if (!isEnabled || param_1 != bgTexID) {
        return;
    }
    SetTextColor(textTexID, hoveredTextColor.r, hoveredTextColor.g, hoveredTextColor.b, hoveredTextColor.a);
    isHovered = true;
    PlayHoverSound();
    if (parent != NULL) {
        parent->OnMouseArrive(this);
    }

    if (hasHoverTexture) {
        Hide(bgTexID);
        Show(hoverBgTexID);
    }

}

/* 412090-412152 000C2	*/
void UIButton::OnMouseLeave(int param_1) {
    if (!isEnabled) {
        return;
    }

    if (param_1 == bgTexID) {
        SetTextColor(textTexID, defaultTextColor.r, defaultTextColor.g, defaultTextColor.b, defaultTextColor.a);
        isHovered = false;
        if (parent != NULL) {
            parent->OnMouseLeave(this);
        }

        if (!hasHoverTexture) {
            return;
        }

        Show(bgTexID);
        Hide(hoverBgTexID);
    }

    if (hasHoverTexture && param_1 == hoverBgTexID) {
        Show(bgTexID);
        Hide(hoverBgTexID);
    }
}

/* 412160-4122CD 0016D	*/
void UIButton::OnInputMouse(float param_1, float param_2, bool param_3, bool param_4) {
    if (!isEnabled) {
        return;
    }

    if (param_3) {
        if (!isPressed && isHovered) {
            if (hasPressTexture) {
                Show(pressBgTexID);
            }
            SetTextColor(textTexID, pressedTextColor.r, pressedTextColor.g, pressedTextColor.b, pressedTextColor.a);
            isPressed = true;
            unk_18aa = false;
            PlayPressSound();
            if (parent) {
                parent->OnButtonDown(this);
            }
        }
       return; 
    } 

    if (!isPressed) {
        return;
    }
    
    if (isHovered) {
        if (hasPressTexture) {
            Hide(pressBgTexID);
        }
        SetTextColor(textTexID, hoveredTextColor.r, hoveredTextColor.g, hoveredTextColor.b, hoveredTextColor.a);
        if (parent) {
            parent->OnButtonUp(this);
        }
    } else {
        SetTextColor(textTexID, defaultTextColor.r, defaultTextColor.g, defaultTextColor.b, defaultTextColor.a);
    }

    isPressed = false;
    unk_18aa = true;
    if (hasPressTexture) {
        Hide(pressBgTexID);
    }
    
}

/* 419BA0-419BA1 00001	*/
void UIButton::OnActivate() {
}

/* 419BA0-419BA1 00001	*/
void UIButton::OnActivateLevel() {
}

