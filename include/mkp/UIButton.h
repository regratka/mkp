#ifndef _U_I_BUTTON
#define _U_I_BUTTON

#include <globals.h>

#include "cMagSprite.h"

class UIButton : public cMagSprite {

public:
	/* 411860 */ UIButton();
	/* 411990 */ virtual ~UIButton();
	/* 4119A0 */ void FUN004119a0(char* param_1, char* param_2, cMagSprite* param_3);
	/* 411B20 */ void FUN00411b20(char* param_1);
	/* 411BA0 */ void FUN00411ba0(char* param_1);
	/* 411C20 */ void FUN00411c20(float param_1, float param_2, float param_3, float param_4);
	/* 411C50 */ void FUN00411c50(float param_1, float param_2);
	/* 411D50 */ void FUN00411d50(float param_1, float param_2);
	/* 411E40 */ void FUN00411e40(char* param_1);
	/* 411E90 */ void FUN00411e90(float param_1);
	/* 411EB0 */ void FUN00411eb0(bool param_1);
	/* 411F30 */ void FUN00411f30(bool param_1);
	/* 411FB0 */ void FUN00411fb0();
	/* 411FD0 */ void FUN00411fd0();
	/* 411FF0 */ void OnMouseArrive(int param_1);
	/* 412090 */ void OnMouseLeave(int param_1);
	/* 412160 */ void OnInputMouse(float param_1, float param_2, bool param_3, bool param_4);
	/* 419BA0 */ void OnActivate();
	/* 419BA0 */ void OnActivateLevel();

private:
	/* 0x1740 */ cMagSprite* unk_1740;
	/* 0x1744 */ char unk_1744[255];
	/* 0x1844 */ float unk_1844;
	/* 0x1848 */ float unk_1848;
	/* 0x184c */ float unk_184c;
	/* 0x1850 */ float unk_1850;
	/* 0x1854 */ int unk_1854;
	/* 0x1858 */ int unk_1858;
	/* 0x185c */ bool unk_185c;
	/* 0x1860 */ int unk_1860;
	/* 0x1864 */ int unk_1864;
	/* 0x1868 */ float unk_1868;
	/* 0x186c */ float unk_186c;
	/* 0x1870 */ float unk_1870;
	/* 0x1874 */ float unk_1874;
	/* 0x1878 */ float unk_1878;
	/* 0x187c */ float unk_187c;
	/* 0x1880 */ float unk_1880;
	/* 0x1884 */ float unk_1884;
	/* 0x1888 */ float unk_1888;
	/* 0x188c */ float unk_188c;
	/* 0x1890 */ float unk_1890;
	/* 0x1894 */ float unk_1894;
	/* 0x1898 */ float unk_1898;
	/* 0x189c */ float unk_189c;
	/* 0x18a0 */ float unk_18a0;
	/* 0x18a4 */ float unk_18a4;
	/* 0x18a8 */ bool unk_18a8;
	/* 0x18a9 */ bool unk_18a9;
	/* 0x18aa */ bool unk_18aa;
	/* 0x18ab */ bool unk_18ab;
	/* 0x18ac */ bool unk_18ac;
	/* 0x18ad */ bool unk_18ad;
	/* 0x18b0 */ CMusicSegment* musicSegment;
	/* 0x18b4 */ CMusicSegment* musicSegment2;
};

STATIC_ASSERT(sizeof(UIButton) == 0x18b8);

#endif