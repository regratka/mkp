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
	/* 434500 */ void LoadSoundsSettings();
	/* 434560 */ void OnFrame();
	/* 434680 */ void Initialize();
	/* 434880 */ void OnMouseArrive(int param_1);
	/* 4349A0 */ void SetSubWindowOpened(bool param_1);
	/* 4349F0 */ void OnMouseLeave(int param_1);
	/* 434A50 */ void OnInputMouse(float param_1, float param_2, bool param_3, bool param_4);
	/* 434B30 */ void OnUpdateMenuSettings();
	/* 434B40 */ void OnInputKey(uchar* param_1);
	/* 434D30 */ void OnExitYesNo(char* param_1);
	/* 434D80 */ void LoadCursorTextures();
	/* 434F50 */ void ChangeActiveCursor();
	/* 435000 */ void ActivateDefaultCursor();
	/* 435040 */ void ActivateStopCursor();
	/* 435070 */ void LoadSounds();
	/* 4351C0 */ void PlayBackgroundMusic();
	/* 4351E0 */ void StopAllSounds();
	/* 435260 */ void PlayMenuSound(int param_1);
	/* 4352B0 */ void OnPlaySoundEnd(int param_1);

private:
	/* 0x1740 */ bool isSubWindowOpened;
	/* 0x1744 */ BOOL isMusicMuted;
	/* 0x1748 */ BOOL areSoundsMuted;
	/* 0x174c */ int playedSoundID;
	/* 0x1750 */ int lastSoundID;
	/* 0x1754 */ bool isPlayingSound;
	/* 0x1755 */ bool isHoveringDisabledButton;
	/* 0x1758 */ int cursorsTextureIDs[5];
	/* 0x176c */ int activeCursorIndex;
	/* 0x1770 */ float lastCursorChangeTime;
	/* 0x1774 */ bool isHoveringEnabledButton;
	/* 0x1775 */ uchar field_0x1775[0x177c- 0x1775];
	/* 0x177c */ float cursorXPos;
	/* 0x1780 */ float cursorYPos;
	/* 0x1784 */ bool isCalibrationEnabled;
	/* 0x1785 */ bool unk_1785;
	/* 0x1788 */ float calibrationXChange;
	/* 0x178c */ float calibrationYChange;
	/* 0x1790 */ CMenuOpcje* menuOpcje;
	/* 0x1794 */ UIWindow* uiWindow;
	/* 0x1798 */ MenuOknoWyboru_CZ1* menuChoiceWindow;
	/* 0x179c */ CWindowExitYesNo* windowExit;
	/* 0x17a0 */ int wormButtonTexID;
	/* 0x17a4 */ int birdButtonTexID;
	/* 0x17a8 */ int barnabaButtonTexID;
	/* 0x17ac */ int tosiaButtonTexID;
	/* 0x17b0 */ int filipButtonTexID;
	/* 0x17b4 */ int papatkaButtonTexID;
	/* 0x17b8 */ int hoveredPapatkaTexID;
	/* 0x17bc */ int hoveredBirdTexID;
	/* 0x17c0 */ int hoveredWormTexID;
	/* 0x17c4 */ bool isExitWindowOpened;
	/* 0x17c5 */ bool unk_17c5;
	/* 0x17c8 */ cMagMeshObject* soundsManager;
	/* 0x17cc */ int exitSoundID;
	/* 0x17d0 */ int optionsSoundID;
	/* 0x17d4 */ int unk_17d4;
	/* 0x17d8 */ int unk_17d8;
	/* 0x17dc */ int unk_17dc;
	/* 0x17e0 */ int selectLevelSoundID;
	/* 0x17e4 */ int menuMusicSoundID;
	/* 0x17e8 */ int exitShortSoundID;
	/* 0x17ec */ uchar field_0x17ec[0x17f0- 0x17ec];
};

STATIC_ASSERT(sizeof(MenuModule) == 0x17f0);

#endif