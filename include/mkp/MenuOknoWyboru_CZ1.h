#ifndef _MENU_OKNO_WYBORU__C_Z1
#define _MENU_OKNO_WYBORU__C_Z1

#include <globals.h>

#include "cMagSprite.h"
#include "MenuModule.h"
#include "UIWindow.h"

class MenuOknoWyboru_CZ1 : public cMagSprite
{
public:
	/* 435380 */ MenuOknoWyboru_CZ1();
	/* 435480 */ virtual ~MenuOknoWyboru_CZ1();
	/* 435490 */ void OnActivate();
	/* 435B60 */ void SetMenuModule(MenuModule *param_1);
	/* 435B80 */ void OnFrame();
	/* 435C90 */ void OpenWindow();
	/* 435D40 */ void CloseWindow();
	/* 435E60 */ void OnMouseArrive(int param_1);
	/* 435FA0 */ void OnMouseLeave(int param_1);
	/* 435FF0 */ void OnInputMouse(float param_1, float param_2, bool param_3, bool param_4);
	/* 436160 */ void OnActivateLevel();
	/* 436330 */ void ChangeActiveCursor();
	/* 4363E0 */ void ActivateDefaultCursor();
	/* 436420 */ void ActivateStopCursor();
	/* 436450 */ void ShowUnlockedLevels();
	/* 4368C0 */ void LoadUnlockedLevels();

private:
	/* 0x1740 */ void *unk_1740;
	/* 0x1744 */ bool unk_1744;
	/* 0x1748 */ MenuModule *menuModule;
	/* 0x174c */ UIWindow *uiWindow;
	/* 0x1750 */ int doorTexID;
	/* 0x1754 */ int doorActiveTexID;
	/* 0x1758 */ int unk_1758;
	/* 0x175c */ int unlockedLevels;
	/* 0x1760 */ int cursorsTextureIDs[5];
	/* 0x1774 */ bool isHoveringLockedLevel;
	/* 0x1778 */ int activeCursorIndex;
	/* 0x177c */ float lastCursorChangeTime;
	/* 0x1780 */ bool isHoveringUnlockedLevel;
	/* 0x1781 */ uchar unk_1781[7];
	/* 0x1788 */ float cursorXPos;
	/* 0x178c */ float cursorYPos;
	/* 0x1790 */ uchar unk_1790[12];
	/* 0x179c */ int unk_179c;
	/* 0x17a0 */ int lev1TexID;
	/* 0x17a4 */ int lev2TexID;
	/* 0x17a8 */ int lev3TexID;
	/* 0x17ac */ int lev4TexID;
	/* 0x17b0 */ int lev5TexID;
	/* 0x17b4 */ int lev6TexID;
	/* 0x17b8 */ int unk_17b8;
	/* 0x17bc */ int deactLev1TexID;
	/* 0x17c0 */ int deactLev2TexID;
	/* 0x17c4 */ int deactLev3TexID;
	/* 0x17c8 */ int deactLev4TexID;
	/* 0x17cc */ int deactLev5TexID;
	/* 0x17d0 */ int deactLev6TexID;
	/* 0x17d4 */ bool isIntroUnlocked;
	/* 0x17d5 */ bool isLevel1Unlocked;
	/* 0x17d6 */ bool isLevel2Unlocked;
	/* 0x17d7 */ bool isLevel3Unlocked;
	/* 0x17d8 */ bool isLevel4Unlocked;
	/* 0x17d9 */ bool isLevel5Unlocked;
	/* 0x17da */ bool isLevel6Unlocked;
	/* 0x17db */ uchar unk_17db[5];
};

STATIC_ASSERT(sizeof(MenuOknoWyboru_CZ1) == 0x17e0);

#endif