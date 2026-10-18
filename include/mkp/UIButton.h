#ifndef _U_I_BUTTON
#define _U_I_BUTTON

#include <globals.h>

#include "cMagSprite.h"

class UIButton : public cMagSprite {

public:
	/* 411860 */ UIButton();
	/* 411990 */ virtual ~UIButton();
	/* 4119A0 */ void SetTexture(char* param_1, char* param_2, cMagSprite* param_3);
	/* 411B20 */ void SetHoverTexture(char* param_1);
	/* 411BA0 */ void SetPressTexture(char* param_1);
	/* 411C20 */ void SetDisabledTextColor(float param_1, float param_2, float param_3, float param_4);
	/* 411C50 */ void SetButtonPosition(float param_1, float param_2);
	/* 411D50 */ void SetButtonScale(float param_1, float param_2);
	/* 411E40 */ void SetButtonText(char* param_1);
	/* 411E90 */ void SetButtonAlpha(float param_1);
	/* 411EB0 */ void EnableButton(bool param_1);
	/* 411F30 */ void SetButtonVisibility(bool param_1);
	/* 411FB0 */ void PlayHoverSound();
	/* 411FD0 */ void PlayPressSound();
	/* 411FF0 */ void OnMouseArrive(int param_1);
	/* 412090 */ void OnMouseLeave(int param_1);
	/* 412160 */ void OnInputMouse(float param_1, float param_2, bool param_3, bool param_4);
	/* 419BA0 */ void OnActivate();
	/* 419BA0 */ void OnActivateLevel();

private:
	/* 0x1740 */ cMagSprite* parent;
	/* 0x1744 */ char buttonText[255];
	/* 0x1844 */ float bgPosX;
	/* 0x1848 */ float bgPosY;
	/* 0x184c */ float bgScaleX;
	/* 0x1850 */ float bgScaleY;
	/* 0x1854 */ int bgTexID;
	/* 0x1858 */ int hoverBgTexID;
	/* 0x185c */ bool hasHoverTexture;
	/* 0x1860 */ int pressBgTexID;
	/* 0x1864 */ int textTexID;
	/* 0x1868 */ D3DXCOLOR defaultTextColor;
	/* 0x1878 */ D3DXCOLOR pressedTextColor;
	/* 0x1888 */ D3DXCOLOR hoveredTextColor;
	/* 0x1898 */ D3DXCOLOR disabledTextColor;
	/* 0x18a8 */ bool unk_18a8;
	/* 0x18a9 */ bool isPressed;
	/* 0x18aa */ bool unk_18aa;
	/* 0x18ab */ bool isHovered;
	/* 0x18ac */ bool isEnabled;
	/* 0x18ad */ bool hasPressTexture;
	/* 0x18b0 */ CMusicSegment* musicSegment;
	/* 0x18b4 */ CMusicSegment* musicSegment2;
};

STATIC_ASSERT(sizeof(UIButton) == 0x18b8);

#endif