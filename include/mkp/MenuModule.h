#ifndef _MENU_MODULE
#define _MENU_MODULE

#include <globals.h>

#include "cMagSprite.h"
#include "CMenuOpcje.h"
#include "UIWindow.h"
#include "MenuOknoWyboru_CZ1.h"
#include "CWindowExitYesNo.h"

class MenuModule : public cMagSprite {
public:
	/* 4164E0 */ void OnButtonUp(cMagKernel* param_1);
	/* 419BA0 */ void OnActivateLevel();
	/* 433FB0 */ MenuModule();
	/* 4340B0 */ virtual ~MenuModule();
	/* 4340C0 */ void OnActivate();
	/* 434500 */ void FUN00434500();
	/* 434560 */ void OnFrame();
	/* 434680 */ void FUN00434680();
	/* 434880 */ void OnMouseArrive(int param_1);
	/* 4349A0 */ void FUN004349a0(bool param_1);
	/* 4349F0 */ void OnMouseLeave(int param_1);
	/* 434A50 */ void OnInputMouse(float param_1, float param_2, bool param_3, bool param_4);
	/* 434B30 */ void OnUpdateMenuSettings();
	/* 434B40 */ void OnInputKey(uchar* param_1);
	/* 434D30 */ void OnExitYesNo(char* param_1);
	/* 434D80 */ void FUN00434d80();
	/* 434F50 */ void FUN00434f50();
	/* 435000 */ void FUN00435000();
	/* 435040 */ void FUN00435040();
	/* 435070 */ void FUN00435070();
	/* 4351C0 */ void FUN004351c0();
	/* 4351E0 */ void FUN004351e0();
	/* 435260 */ void FUN00435260(int param_1);
	/* 4352B0 */ void OnPlaySoundEnd(int param_1);

private:
	/* 0x1740 */ bool unk_1740;
	/* 0x1744 */ void* unk_1744;
	/* 0x1748 */ void* unk_1748;
	/* 0x174c */ int unk_174c;
	/* 0x1750 */ int unk_1750;
	/* 0x1754 */ bool unk_1754;
	/* 0x1755 */ bool unk_1755;
	/* 0x1758 */ int unk_1758[4];
	/* 0x1768 */ int unk_1768;
	/* 0x176c */ int unk_176c;
	/* 0x1770 */ float unk_1770;
	/* 0x1774 */ bool unk_1774;
	/* 0x1775 */ uchar field_0x1775[0x177c- 0x1775];
	/* 0x177c */ float unk_177c;
	/* 0x1780 */ float unk_1780;
	/* 0x1784 */ bool unk_1784;
	/* 0x1785 */ bool unk_1785;
	/* 0x1788 */ float unk_1788;
	/* 0x178c */ float unk_178c;
	/* 0x1790 */ CMenuOpcje* menuOpcje;
	/* 0x1794 */ UIWindow* uiWindow;
	/* 0x1798 */ MenuOknoWyboru_CZ1* menuChoiceWindow;
	/* 0x179c */ CWindowExitYesNo* windowExit;
	/* 0x17a0 */ int unk_17a0;
	/* 0x17a4 */ int unk_17a4;
	/* 0x17a8 */ int unk_17a8;
	/* 0x17ac */ int unk_17ac;
	/* 0x17b0 */ int unk_17b0;
	/* 0x17b4 */ int unk_17b4;
	/* 0x17b8 */ int unk_17b8;
	/* 0x17bc */ int unk_17bc;
	/* 0x17c0 */ int unk_17c0;
	/* 0x17c4 */ bool unk_17c4;
	/* 0x17c5 */ bool unk_17c5;
	/* 0x17c8 */ cMagMeshObject* unk_17c8;
	/* 0x17cc */ int unk_17cc;
	/* 0x17d0 */ int unk_17d0;
	/* 0x17d4 */ int unk_17d4;
	/* 0x17d8 */ int unk_17d8;
	/* 0x17dc */ int unk_17dc;
	/* 0x17e0 */ int unk_17e0;
	/* 0x17e4 */ int unk_17e4;
	/* 0x17e8 */ int unk_17e8;
	/* 0x17ec */ uchar field_0x17ec[0x17f0- 0x17ec];
};

STATIC_ASSERT(sizeof(MenuModule) == 0x17f0);

#endif