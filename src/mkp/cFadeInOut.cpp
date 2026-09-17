#include "cFadeInOut.h"

#include "CGame.h"

/* 41C4A0-41C52A 0008A	*/
cFadeInOut::cFadeInOut() {
	SetObjectName("cFadeInOut");
	isFadingIn = false;
	isFadingOut = false;
	isFadingOutFinished = false;
	isFadingInFinished = false;
	fadeFinishListener = NULL;
	fadeChange = 0.0f;
	fadingSpeed = 1.0f;
	secondaryFadeTexID = 0;
	useSecondaryTexture = false;
}

/* 41C550-41C55C 0000C	*/
cFadeInOut::~cFadeInOut() {
}

/* 41C560-41C596 00036	*/
void cFadeInOut::HideFade() {
	if (!useSecondaryTexture) {
		Hide(primaryFadeTexID);
	} else {
		Hide(secondaryFadeTexID);
	}
	DisableCallHandler("OnFrame");
}

/* 41C5A0-41C5DB 0003B	*/
void cFadeInOut::OnActivate() {
	primaryFadeTexID = AddTexture("data\\textures\\BlackFade.png");
	SetScaleAsWindow(primaryFadeTexID);
	secondaryFadeTexID = AddTexture("data\\textures\\BlackFade.png");
	SetScaleAsWindow(secondaryFadeTexID);
}

/* 41C5E0-41C5FA 0001A	*/
void cFadeInOut::SetListener(cMagKernel* param_1) {
	if (param_1 == NULL) {
		fadeFinishListener = NULL;
	} else {
		fadeFinishListener = param_1;
	}
}

/* 41C600-41C743 00143	*/
void cFadeInOut::OnFrame() {
	float fVar1 = GetGame()->GetFrameTime();
	fadeChange = fVar1 / (1.0f / fadingSpeed);
	if (fadeChange > 1.0f) {
		return;
	}

	if (isFadingIn) {
		fadeValue -= fadeChange;
		if (fadeValue <= 0.0f) {
			isFadingInFinished = true;
			if (fadeFinishListener != NULL) {
				fadeFinishListener->OnFadeInEnd();
			}

			DisableCallHandler("OnFrame");
			if (!useSecondaryTexture) {
				Show(primaryFadeTexID);
			} else {
				Show(secondaryFadeTexID);
			}
		}
	}

	if (isFadingOut) {
		fadeValue += fadeChange;
		if (fadeValue >= 1.0f) {
			isFadingOutFinished = true;
			DisableCallHandler("OnFrame");
			if (fadeFinishListener != NULL) {
				fadeFinishListener->OnFadeOutEnd();
			}
		}
	}

	if (!useSecondaryTexture) {
		SetAlpha(primaryFadeTexID, fadeValue);
	} else {
		SetAlpha(secondaryFadeTexID, fadeValue);
	}
	
}

/* 41C750-41C7AB 0005B	*/
void cFadeInOut::StartFadingIn() {
	isFadingIn = true;
	isFadingOut = false;
	isFadingOutFinished = false;
	isFadingInFinished = false;
	fadeValue = 1.0f;
	if (!useSecondaryTexture) {
		Show(primaryFadeTexID);
	} else {
		Show(secondaryFadeTexID);
	}
	EnableCallHandler("OnFrame");
}

/* 41C7B0-41C826 00076	*/
void cFadeInOut::StartFadingOut() {
	isFadingOut = true;
	isFadingIn = false;
	isFadingOutFinished = false;
	isFadingInFinished = false;
	fadeValue = 0.0f;
	if (!useSecondaryTexture) {
		SetAlpha(primaryFadeTexID, 0.0f);
		Show(primaryFadeTexID);
	} else {
		SetAlpha(secondaryFadeTexID, 0.0f);
		Show(secondaryFadeTexID);
	}
	EnableCallHandler("OnFrame");
}

/* 41C830-41C83D 0000D	*/
void cFadeInOut::MustUseSecondaryTexture(bool param_1) {
	useSecondaryTexture = param_1;
}

