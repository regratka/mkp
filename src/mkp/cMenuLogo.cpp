#include "cMenuLogo.h"
#include "CGame.h"
#include "mkp_utils.h"

/* 419BA0-419BA1 00001	*/
void cMenuLogo::OnActivateLevel() {
}

/* 419BA0-419BA1 00001	*/
void cMenuLogo::OnFadeInEnd() {
}

/* 433B70-433B8F 0001F	*/
cMenuLogo::cMenuLogo(MenuModule* param_1) {
	menuModule = param_1;
}

/* 433B90-433B9C 0000C	*/
cMenuLogo::~cMenuLogo() {
}

/* 433BA0-433C07 00067	*/
void cMenuLogo::OnActivate() {
	logoEgmontTexID = 0;
	logoGratkaTexID = 0;
	logoEgmontTexID = AddTexture("data\\textures\\menu\\logo01.png");
	SetScaleAsWindow(logoEgmontTexID);
	Hide(logoEgmontTexID);
	logoGratkaTexID = AddTexture("data\\textures\\menu\\logo_gratka.png");
	SetScaleAsWindow(logoGratkaTexID);
	Hide(logoGratkaTexID);
}

/* 433C10-433CCE 000BE	*/
void cMenuLogo::FUN00433c10() {
	Show(logoEgmontTexID);
	timeFromLastFade = 0.0f;
	madefadesOut = 0;
	EnableCallHandler("OnFrame");
	EnableCallHandler("OnInputKey");
	fadeInOut = new cFadeInOut();
	CreateObject(fadeInOut);
	fadeInOut->SetListener(this);
	fadeInOut->StartFadingIn();
}

/* 433CD0-433D7C 000AC	*/
void cMenuLogo::OnFadeOutEnd() {
	madefadesOut++;

	if (madefadesOut > 1) {
		Hide(logoEgmontTexID);
		Hide(logoGratkaTexID);
		DisableCallHandler("OnFrame");
		DisableCallHandler("OnInputKey");
		if (fadeInOut != NULL) {
			fadeInOut->HideFade();
		}
		if (menuModule != NULL) {
			menuModule->FUN00434680();
		}
	} else {
		timeFromLastFade = 0.0f;
		Hide(logoEgmontTexID);
		Show(logoGratkaTexID);
		if (fadeInOut != NULL) {
			fadeInOut->StartFadingIn();
		}
	}
}

/* 433D80-433DC5 00045	*/
void cMenuLogo::OnFrame() {
	timeFromLastFade += GetGame()->GetFrameTime();
	if (timeFromLastFade > 4.0f) {
		timeFromLastFade = 0.0f;
		if (fadeInOut != NULL) {
			fadeInOut->StartFadingOut();
		}
	}
}



/* 433DD0-433E49 00079	*/
void cMenuLogo::OnInputKey(uchar* param_1) {
	if (!FUN00412b00(param_1)) {
		return;
	}

	madefadesOut = 10;
	Hide(logoEgmontTexID);
	Hide(logoGratkaTexID);
	DisableCallHandler("OnFrame");
	DisableCallHandler("OnInputKey");

	if (menuModule != NULL) {
		menuModule->FUN00434680();
	}
	
	if (fadeInOut != NULL) {
		fadeInOut->HideFade();
	}
}

