#include "cFadeInOut.h"

#include "CGame.h"

/* 41C4A0-41C52A 0008A	*/
cFadeInOut::cFadeInOut() {
	SetObjectName("cFadeInOut");
	unk_174c = false;
	unk_174d = false;
	unk_174e = false;
	unk_174f = false;
	unk_1750 = NULL;
	unk_1760 = 0.0f;
	unk_175c = 1.0f;
	unk_1764 = 0;
	unk_1768 = false;
}

/* 41C550-41C55C 0000C	*/
cFadeInOut::~cFadeInOut() {
}

/* 41C560-41C596 00036	*/
void cFadeInOut::FUN0041c560() {
	if (!unk_1768) {
		Hide(unk_1740);
	} else {
		Hide(unk_1764);
	}
	DisableCallHandler("OnFrame");
}

/* 41C5A0-41C5DB 0003B	*/
void cFadeInOut::OnActivate() {
	unk_1740 = AddTexture("data\\textures\\BlackFade.png");
	SetScaleAsWindow(unk_1740);
	unk_1764 = AddTexture("data\\textures\\BlackFade.png");
	SetScaleAsWindow(unk_1764);
}

/* 41C5E0-41C5FA 0001A	*/
void cFadeInOut::FUN0041c5e0(cMagKernel* param_1) {
	if (param_1 == NULL) {
		unk_1750 = NULL;
	} else {
		unk_1750 = param_1;
	}
}

/* 41C600-41C743 00143	*/
void cFadeInOut::OnFrame() {
	float fVar1 = GetGame()->GetFrameTime();
	unk_1760 = fVar1 / (1.0f / unk_175c);
	if (unk_1760 > 1.0f) {
		return;
	}

	if (unk_174c) {
		unk_1744 -= unk_1760;
		if (unk_1744 <= 0.0f) {
			unk_174f = true;
			if (unk_1750 != NULL) {
				unk_1750->OnFadeInEnd();
			}

			DisableCallHandler("OnFrame");
			if (!unk_1768) {
				Show(unk_1740);
			} else {
				Show(unk_1764);
			}
		}
	}

	if (unk_174d) {
		unk_1744 += unk_1760;
		if (unk_1744 >= 1.0f) {
			unk_174e = true;
			DisableCallHandler("OnFrame");
			if (unk_1750 != NULL) {
				unk_1750->OnFadeOutEnd();
			}
		}
	}

	if (!unk_1768) {
		SetAlpha(unk_1740, unk_1744);
	} else {
		SetAlpha(unk_1764, unk_1744);
	}
	
}

/* 41C750-41C7AB 0005B	*/
void cFadeInOut::FUN0041c750() {
	unk_174c = true;
	unk_174d = false;
	unk_174e = false;
	unk_174f = false;
	unk_1744 = 1.0f;
	if (!unk_1768) {
		Show(unk_1740);
	} else {
		Show(unk_1764);
	}
	EnableCallHandler("OnFrame");
}

/* 41C7B0-41C826 00076	*/
void cFadeInOut::FUN0041c7b0() {
	unk_174d = true;
	unk_174c = false;
	unk_174e = false;
	unk_174f = false;
	unk_1744 = 0.0f;
	if (!unk_1768) {
		SetAlpha(unk_1740, 0.0f);
		Show(unk_1740);
	} else {
		SetAlpha(unk_1764, 0.0f);
		Show(unk_1764);
	}
	EnableCallHandler("OnFrame");
}

/* 41C830-41C83D 0000D	*/
void cFadeInOut::FUN0041c830(bool param_1) {
	unk_1768 = param_1;
}

