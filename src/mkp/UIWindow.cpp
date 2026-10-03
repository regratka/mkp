#include "UIWindow.h"

#include "CGame.h"

/* 4133E0-41344A 0006A	*/
UIWindow::UIWindow() {
    unk_1744 = 0;
    unk_1748 = 0;
    unk_174c = 0.0f;
    unk_1750 = 0;
    unk_1754 = 0;
    unk_1758 = 0;
    unk_175c = 0;
    unk_1760 = 0;
    unk_1764 = 0;
    unk_1768 = false;
    unk_1740 = NULL;
    unk_176a = false;
    unk_176b = false;
    unk_1769 = true;
}


/* 413470-4134CD 0005D	*/
UIWindow::UIWindow(cMagSprite* param_1) {
    unk_1744 = 0;
    unk_1748 = 0;
    unk_174c = 0.0f;
    unk_1750 = 0;
    unk_1754 = 0;
    unk_1758 = 0;
    unk_175c = 0;
    unk_1760 = 0;
    unk_1764 = 0;
    unk_1768 = false;
    unk_1740 = param_1;
}

/* 4134D0-4134DC 0000C	*/
UIWindow::~UIWindow() {
}

/* 4134E0-413510 00030	*/
void UIWindow::FUN004134e0(char* param_1) { // SetBackground
    unk_1744 = AddTexture(param_1);
    SetScaleAsWindow(unk_1744);
    Show(unk_1744);
}

/* 413510-413531 00021	*/
void UIWindow::FUN00413510(bool param_1) {
    subSprites[unk_1744].unk_34 = param_1;
}

/* 413540-41355A 0001A	*/
void UIWindow::FUN00413540(D3DXVECTOR2 param_1) {
    SetScale(unk_1744, param_1.x, param_1.y);
}

/* 413560-41357C 0001C	*/
void UIWindow::FUN00413560(D3DXVECTOR2 param_1) {
    SetPos(unk_1744, param_1.x, param_1.y, 0);
}

/* 413580-4135A8 00028	*/
void UIWindow::FUN00413580(bool param_1) {
    if (param_1) {
        Show(unk_1744);
    } else {
        Hide(unk_1744);
    }
}

/* 4135B0-4135C5 00015	*/
void UIWindow::FUN004135b0(float param_1) {
    SetAlpha(unk_1744, param_1);
}

/* 4135D0-413641 00071	*/
void UIWindow::FUN004135d0(int param_1, int param_2, int param_3, int param_4) {
    unk_1754 = param_2;
    unk_1758 = param_3;
    unk_175c = param_4;
    Rect local_10;
    TexFromDigit(param_1, param_2, param_3, param_4, local_10);
    SetTextureRect(unk_1744, local_10);
}

/* 413650-413698 00048	*/
void UIWindow::FUN00413650(float param_1, int param_2, int param_3, bool param_4) {
    unk_1768 = param_4;
    unk_1760 = param_2;
    unk_1764 = param_3;
    unk_174c = param_1;
    unk_1750 = param_2;
    unk_1748 = 0;
    EnableCallHandler("OnFrame");
}

/* 4136A0-4136D5 00035	*/
void UIWindow::FUN004136a0() {
    DisableCallHandler("OnFrame");
    FUN004135d0(unk_1764, unk_1754, unk_1758, unk_175c);
}

/* 4136E0-413715 00035	*/
void UIWindow::FUN004136e0(int param_1) {
    DisableCallHandler("OnFrame");
    FUN004135d0(param_1, unk_1754, unk_1758, unk_175c);
}

/* 413720-413734 00014	*/
void UIWindow::OnFrame() {
    if (!unk_176b) {
        FUN00413820();
    } else {
        FUN00413740();
    }
}

/* 413740-413819 000D9	*/
void UIWindow::FUN00413740() {
    unk_1748 += GetGame()->GetFrameTime();
    if (unk_174c >= unk_1748) {
        return;
    }

    unk_1748 = 0;
    if (unk_1769 && unk_1750 > unk_1764) {
        unk_1750 = unk_1764;
        unk_1769 = false;
        unk_176a = true;
    }

    if (unk_176a && unk_1750 < unk_1760) {
      unk_1750 = unk_1760;
      unk_1769 = true;
      unk_176a = false;
    }

    FUN004135d0(unk_1750,unk_1754,unk_1758,unk_175c);

    if (unk_1769) {
      unk_1750++;
    }

    if (unk_176a) {
      unk_1750--;
    }
}

/* 413820-4138B6 00096	*/
void UIWindow::FUN00413820() {
    unk_1748 += GetGame()->GetFrameTime();
    if (unk_174c >= unk_1748) {
        return;
    }

    unk_1748 = 0.0f;
    if (unk_1750 > unk_1764) {
        unk_1750 = unk_1760;
        if (!unk_1768) {
            DisableCallHandler("OnFrame");
            return;
        }
    }

    FUN004135d0(unk_1750, unk_1754, unk_1758, unk_175c);
    unk_1750++;
}

/* 4138C0-4138DA 0001A	*/
void UIWindow::OnMouseArrive(int param_1) {
    if (unk_1740 != NULL) {
        unk_1740->OnMouseArrive(param_1);
    }
}

/* 4138E0-4138FA 0001A	*/
void UIWindow::OnMouseLeave(int param_1) {
    if (unk_1740 != NULL) {
        unk_1740->OnMouseLeave(param_1);
    }
}

