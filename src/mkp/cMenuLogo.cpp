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
	unk_1750 = 0.0f;
	unk_174c = 0;
	EnableCallHandler("OnFrame");
	EnableCallHandler("OnInputKey");
	fadeInOut = new cFadeInOut();
	CreateObject(fadeInOut);
	fadeInOut->FUN0041c5e0(this);
	fadeInOut->FUN0041c750();
}

/* 433CD0-433D7C 000AC	*/
void cMenuLogo::OnFadeOutEnd() {
	unk_174c++;

	if (unk_174c > 1) {
		Hide(logoEgmontTexID);
		Hide(logoGratkaTexID);
		DisableCallHandler("OnFrame");
		DisableCallHandler("OnInputKey");
		if (fadeInOut != NULL) {
			fadeInOut->FUN0041c560();
		}
		if (menuModule != NULL) {
			menuModule->FUN00434680();
		}
	} else {
		unk_1750 = 0.0f;
		Hide(logoEgmontTexID);
		Show(logoGratkaTexID);
		if (fadeInOut != NULL) {
			fadeInOut->FUN0041c750();
		}
	}
}

/* 433D80-433DC5 00045	*/
void cMenuLogo::OnFrame() {
	unk_1750 += GetGame()->GetFrameTime();
	if (unk_1750 > 4.0f) {
		unk_1750 = 0.0f;
		if (fadeInOut != NULL) {
			fadeInOut->FUN0041c7b0();
		}
	}
}



/* 433DD0-433E49 00079	*/
void cMenuLogo::OnInputKey(uchar* param_1) {
	if (!FUN00412b00(param_1)) {
		return;
	}

	unk_174c = 10;
	Hide(logoEgmontTexID);
	Hide(logoGratkaTexID);
	DisableCallHandler("OnFrame");
	DisableCallHandler("OnInputKey");

	if (menuModule != NULL) {
		menuModule->FUN00434680();
	}
	
	if (fadeInOut != NULL) {
		fadeInOut->FUN0041c560();
	}
}

