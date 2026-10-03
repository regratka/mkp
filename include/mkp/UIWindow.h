#ifndef _U_I_WINDOW
#define _U_I_WINDOW

#include <globals.h>

#include "cMagSprite.h"

class UIWindow : public cMagSprite {
public:
	/* 4133E0 */ UIWindow();
	/* 413470 */ UIWindow(cMagSprite* param_1);
	/* 4134D0 */ virtual ~UIWindow();
	/* 4134E0 */ void FUN004134e0(char* param_1);
	/* 413510 */ void FUN00413510(bool param_1);
	/* 413540 */ void FUN00413540(D3DXVECTOR2 param_1);
	/* 413560 */ void FUN00413560(D3DXVECTOR2 param_1);
	/* 413580 */ void FUN00413580(bool param_1);
	/* 4135B0 */ void FUN004135b0(float param_1);
	/* 4135D0 */ void FUN004135d0(int param_1, int param_2, int param_3, int param_4);
	/* 413650 */ void FUN00413650(float param_1, int param_2, int param_3, bool param_4);
	/* 4136A0 */ void FUN004136a0();
	/* 4136E0 */ void FUN004136e0(int param_1);
	/* 413720 */ void OnFrame();
	/* 413740 */ void FUN00413740();
	/* 413820 */ void FUN00413820();
	/* 4138C0 */ void OnMouseArrive(int param_1);
	/* 4138E0 */ void OnMouseLeave(int param_1);

private:
	/* 0x1740 */ cMagSprite* unk_1740;
	/* 0x1744 */ int unk_1744;
	/* 0x1748 */ float unk_1748;
	/* 0x174c */ float unk_174c;
	/* 0x1750 */ int unk_1750;
	/* 0x1754 */ int unk_1754;
	/* 0x1758 */ int unk_1758;
	/* 0x175c */ int unk_175c;
	/* 0x1760 */ int unk_1760;
	/* 0x1764 */ int unk_1764;
	/* 0x1768 */ bool unk_1768;
	/* 0x1769 */ bool unk_1769;
	/* 0x176a */ bool unk_176a;
	/* 0x176b */ bool unk_176b;
	/* 0x176c */ uchar field_0x176c[0x1770-0x176c];
};

STATIC_ASSERT(sizeof(UIWindow) == 0x1770);

#endif