#ifndef C_FADE_IN_OUT
#define C_FADE_IN_OUT

#include <globals.h>
#include "cMagSprite.h"

class cFadeInOut : public cMagSprite {
public:
	/* 41C4A0 */ cFadeInOut();
	/* 41C550 */ virtual ~cFadeInOut();
	/* 41C560 */ void FUN0041c560();
	/* 41C5A0 */ void OnActivate();
	/* 41C5E0 */ void FUN0041c5e0(cMagKernel* param_1);
	/* 41C600 */ void OnFrame();
	/* 41C750 */ void FUN0041c750();
	/* 41C7B0 */ void FUN0041c7b0();
	/* 41C830 */ void FUN0041c830(bool param_1);

private:
	/* 0x1740 */ int unk_1740;
	/* 0x1744 */ float unk_1744;
	/* 0x1748 */ uchar field_0x1748[0x174c-0x1748];
	/* 0x174c */ bool unk_174c;
	/* 0x174d */ bool unk_174d;
	/* 0x174e */ bool unk_174e;
	/* 0x174f */ bool unk_174f;
	/* 0x1750 */ cMagKernel* unk_1750;
	/* 0x1754 */ uchar field_0x1754[0x175c-0x1754];
	/* 0x175c */ float unk_175c;
	/* 0x1760 */ float unk_1760;
	/* 0x1764 */ int unk_1764;
	/* 0x1768 */ bool unk_1768;
	/* 0x1769 */ uchar field_0x1769[0x1770-0x1769];
};

STATIC_ASSERT(sizeof(cFadeInOut) == 0x1770);

#endif