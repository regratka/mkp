#include "UIButton.h"

/* 411860-411963 00103	*/
UIButton::UIButton() {
    ZeroMemory(unk_1744, sizeof(unk_1744));
    unk_1740 = NULL;
    unk_1854 = -1;
    unk_1864 = -1;
    unk_18aa = true;
    unk_18ac = true;
    unk_1858 = -1;
    unk_18a8 = false;
    unk_18ab = false;
    unk_18a9 = false;
    musicSegment = NULL;
    musicSegment2 = NULL;
    unk_18ad = false;
    unk_185c = false;
    unk_1844 = 0.5f;
    unk_1848 = 0.5f;
    unk_184c = 1.0f;
    unk_1850 = 1.0f;
    unk_1868 = 0.3515625f;
    unk_186c = 0.3515625f;
    unk_1870 = 0.3515625f;
    unk_1874 = 1.0f;
    unk_1878 = 0.5f;
    unk_187c = 0.5f;
    unk_1880 = 0.5f;
    unk_1884 = 1.0f;
    unk_1888 = 0.0f;
    unk_188c = 1.0f;
    unk_1890 = 0.0f;
    unk_1894 = 1.0f;
    unk_1898 = 0.3515625f;
    unk_189c = 0.3515625f;
    unk_18a0 = 0.3515625f;
    unk_18a4 = 1.0f;
}

/* 411990-41199C 0000C	*/
UIButton::~UIButton() {
}

/* 4119A0-411B13 00173	*/
void UIButton::FUN004119a0(char* param_1, char* param_2, cMagSprite* param_3) {
    unk_1740 = param_3;
    unk_1854 = AddTexture(param_1);
    SetScale(unk_1854, unk_184c, unk_1850);
    SetPos(unk_1854, unk_1844, unk_1848, 0);
    EnableCheckMouse(unk_1854, true);
    Show(unk_1854);

    if (param_2 != NULL) {
        FUN00411e40(param_2);
        D3DXVECTOR2 fStack_8 = GetSize(unk_1854);
        fStack_8.x /= 2;
        fStack_8.y /= 2;
        float fVar1 = fStack_8.x / GetWindowWidth();
        float fVar2 = fStack_8.y / GetWindowHeight();
        fVar1 = fVar1 + unk_1844 - fVar1 - 0.04f;
        fVar2 = fVar2 + unk_1848 - fVar2 - 0.02f;

        unk_1864 = SetText(unk_1744, fVar1, fVar2,
            unk_1868, unk_186c, unk_1870, unk_1874);
        ShowText(unk_1864, true);
    }
    EnableCallHandler("OnInputMouse");
}

/* 411B20-411B95 00075	*/
void UIButton::FUN00411b20(char* param_1) {
    unk_185c = true;
    unk_1858 = AddTexture(param_1);
    SetScale(unk_1858, unk_184c, unk_1850);
    SetPos(unk_1858, unk_1844, unk_1848, 0);
    EnableCheckMouse(unk_1858, true);
    Hide(unk_1858);
}

/* 411BA0-411C15 00075	*/
void UIButton::FUN00411ba0(char* param_1) {
    unk_1860 = AddTexture(param_1);
    SetScale(unk_1860, unk_184c, unk_1850);
    SetPos(unk_1860, unk_1844, unk_1848, 0);
    EnableCheckMouse(unk_1860, true);
    Hide(unk_1860);
    unk_18ad = true;
}

/* 411C20-411C4B 0002B	*/
void UIButton::FUN00411c20(float param_1, float param_2, float param_3, float param_4) {
    unk_1898 = param_1;
    unk_189c = param_2;
    unk_18a0 = param_3;
    unk_18a4 = param_4;
}

/* 411C50-411D46 000F6	*/
void UIButton::FUN00411c50(float param_1, float param_2) {
    unk_1844 = param_1;
    unk_1848 = param_2;
    SetScale(unk_1854, unk_184c, unk_1850);
    SetPos(unk_1854, unk_1844, unk_1848, 0);
    D3DXVECTOR2 fStack_8 = GetSize(unk_1854);
    fStack_8.x /= 2;
    fStack_8.y /= 2;
    float fVar1 = fStack_8.x / GetWindowWidth();
    float fVar2 = fStack_8.y / GetWindowHeight();    
    fVar1 = fVar1 + unk_1844 - fVar1 - 0.05f;
    fVar2 = fVar2 + unk_1848 - fVar2 - 0.02f;

    SetTextPosition(unk_1864, fVar1, fVar2);
}

/* 411D50-411E3C 000EC	*/
void UIButton::FUN00411d50(float param_1, float param_2) {
    unk_184c = param_1;
    unk_1850 = param_2;
    SetScale(unk_1854, unk_184c, unk_1850);
    SetPos(unk_1854, unk_1844, unk_1848, 0);
    D3DXVECTOR2 fStack_8 = GetSize(unk_1854);
    fStack_8.x /= 2;
    fStack_8.y /= 2;
    float fVar1 = fStack_8.x / GetWindowWidth();
    float fVar2 = fStack_8.y / GetWindowHeight();    
    fVar1 = fVar1 + unk_1844 - fVar1 - 0.05f;
    fVar2 = fVar2 + unk_1848 - fVar2 - 0.02f;

    SetTextPosition(unk_1864, fVar1, fVar2);
}

/* 411E40-411E90 00050	*/
void UIButton::FUN00411e40(char* param_1) {
    ZeroMemory(unk_1744, sizeof(unk_1744));
    strcpy(unk_1744, param_1);
    SetText(unk_1864, unk_1744);
}

/* 411E90-411EA5 00015	*/
void UIButton::FUN00411e90(float param_1) {
    SetAlpha(unk_1854, param_1);
}

/* 411EB0-411F26 00076	*/
void UIButton::FUN00411eb0(bool param_1) {
    unk_18ac = param_1;
    if (!param_1) {
        SetTextColor(unk_1864, unk_1898, unk_189c, unk_18a0, unk_18a4);
        unk_18ab = false;
    } else {
        SetTextColor(unk_1864, unk_1868, unk_186c, unk_1870, unk_1874);
    }
}

/* 411F30-411FA2 00072	*/
void UIButton::FUN00411f30(bool param_1) {
    if (!param_1) {
        FUN00411eb0(false);
        ShowText(unk_1864, false);
        Hide(unk_1854);
        Hide(unk_1858);
    } else {
        FUN00411eb0(true);
        ShowText(unk_1864, true);
        Show(unk_1854);
    }
}

/* 411FB0-411FC8 00018	*/
void UIButton::FUN00411fb0() {
    if (musicSegment != NULL) {
        musicSegment->Play();
    }
}

/* 411FD0-411FE8 00018	*/
void UIButton::FUN00411fd0() {
    if (musicSegment2 != NULL) {
        musicSegment2->Play();
    }
}

/* 411FF0-412087 00097	*/
void UIButton::OnMouseArrive(int param_1) {
    if (!unk_18ac || param_1 != unk_1854) {
        return;
    }
    SetTextColor(unk_1864, unk_1888, unk_188c, unk_1890, unk_1894);
    unk_18ab = true;
    FUN00411fb0();
    if (unk_1740 != NULL) {
        unk_1740->OnMouseArrive(this);
    }

    if (unk_185c) {
        Hide(unk_1854);
        Show(unk_1858);
    }

}

/* 412090-412152 000C2	*/
void UIButton::OnMouseLeave(int param_1) {
    if (!unk_18ac) {
        return;
    }

    if (param_1 == unk_1854) {
        SetTextColor(unk_1864, unk_1868, unk_186c, unk_1870, unk_1874);
        unk_18ab = false;
        if (unk_1740 != NULL) {
            unk_1740->OnMouseLeave(this);
        }

        if (!unk_185c) {
            return;
        }

        Show(unk_1854);
        Hide(unk_1858);
    }

    if (unk_185c && param_1 == unk_1858) {
        Show(unk_1854);
        Hide(unk_1858);
    }
}

/* 412160-4122CD 0016D	*/
void UIButton::OnInputMouse(float param_1, float param_2, bool param_3, bool param_4) {
    if (!unk_18ac) {
        return;
    }

    if (param_3) {
        if (!unk_18a9 && unk_18ab) {
            if (unk_18ad) {
                Show(unk_1860);
            }
            SetTextColor(unk_1864, unk_1878, unk_187c, unk_1880, unk_1884);
            unk_18a9 = true;
            unk_18aa = false;
            FUN00411fd0();
            if (unk_1740) {
                unk_1740->OnButtonDown(this);
            }
        }
       return; 
    } 

    if (!unk_18a9) {
        return;
    }
    
    if (unk_18ab) {
        if (unk_18ad) {
            Hide(unk_1860);
        }
        SetTextColor(unk_1864, unk_1888, unk_188c, unk_1890, unk_1894);
        if (unk_1740) {
            unk_1740->OnButtonUp(this);
        }
    } else {
        SetTextColor(unk_1864, unk_1868, unk_186c, unk_1870, unk_1874);
    }

    unk_18a9 = false;
    unk_18aa = true;
    if (unk_18ad) {
        Hide(unk_1860);
    }
    
}

/* 419BA0-419BA1 00001	*/
void UIButton::OnActivate() {
}

/* 419BA0-419BA1 00001	*/
void UIButton::OnActivateLevel() {
}

