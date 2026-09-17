#ifndef C_FADE_IN_OUT
#define C_FADE_IN_OUT

#include <globals.h>
#include "cMagSprite.h"

class cFadeInOut : public cMagSprite {
public:
	/* 41C4A0 */ cFadeInOut();
	/* 41C550 */ virtual ~cFadeInOut();
	/* 41C560 */ void HideFade();
	/* 41C5A0 */ void OnActivate();
	/* 41C5E0 */ void SetListener(cMagKernel* param_1);
	/* 41C600 */ void OnFrame();
	/* 41C750 */ void StartFadingIn();
	/* 41C7B0 */ void StartFadingOut();
	/* 41C830 */ void MustUseSecondaryTexture(bool param_1);

private:
	/* 0x1740 */ int primaryFadeTexID;
	/* 0x1744 */ float fadeValue;
	/* 0x1748 */ uchar field_0x1748[0x174c-0x1748];
	/* 0x174c */ bool isFadingIn;
	/* 0x174d */ bool isFadingOut;
	/* 0x174e */ bool isFadingOutFinished;
	/* 0x174f */ bool isFadingInFinished;
	/* 0x1750 */ cMagKernel* fadeFinishListener;
	/* 0x1754 */ uchar field_0x1754[0x175c-0x1754];
	/* 0x175c */ float fadingSpeed;
	/* 0x1760 */ float fadeChange;
	/* 0x1764 */ int secondaryFadeTexID;
	/* 0x1768 */ bool useSecondaryTexture;
	/* 0x1769 */ uchar field_0x1769[0x1770-0x1769];
};

STATIC_ASSERT(sizeof(cFadeInOut) == 0x1770);

#endif