#ifndef _C_WINDOW_EXIT_YES_NO
#define _C_WINDOW_EXIT_YES_NO

#include <globals.h>
#include "UIWindow.h"

class MenuModule;

class CWindowExitYesNo : public cMagSprite {
public:
	/* 4264A0 */ CWindowExitYesNo();
	/* 426550 */ virtual ~CWindowExitYesNo();
	/* 426560 */ void OnActivate();
	/* 4269E0 */ void FUN004269e0(MenuModule* param_1);
	/* 426B70 */ void FUN00426b70();
	/* 426C40 */ bool FUN00426c40();
	/* 426C50 */ void FUN00426c50();
	/* 426DC0 */ void FUN00426dc0();
	/* 426E70 */ void FUN00426e70();
	/* 426EB0 */ void OnFrame();
	/* 426FA0 */ void FUN00426fa0();
	/* 427030 */ void OnMouseArrive(int param_1);
	/* 427130 */ void OnMouseLeave(int param_1);
	/* 427190 */ void OnInputMouse(float param_1, float param_2, bool param_3, bool param_4);

private:
	/* 0x1740 */ MenuModule* menuModule;
	/* 0x1744 */ UIWindow* hitboxesLayer;
	/* 0x1748 */ UIWindow* mainWindow;
	/* 0x174c */ UIWindow* bodySprite;
	/* 0x1750 */ UIWindow* headYesSprite;
	/* 0x1754 */ UIWindow* headNoSprite;
	/* 0x1758 */ int yesHitboxTexID;
	/* 0x175c */ int noHitboxTexID;
	/* 0x1760 */ int unk_1760;
	/* 0x1764 */ float cursorXPos;
	/* 0x1768 */ float cursorYPos;
	/* 0x176c */ bool unk_176c;
	/* 0x1770 */ int cursorsTextureID[5];
	/* 0x1784 */ int unk_1784; // probably disabled cursor
	/* 0x1788 */ int activeCursorIndex;
	/* 0x178c */ float lastCursorChangeTime;
	/* 0x1790 */ bool unk_1790;
	/* 0x1791 */ bool unk_1791;
	/* 0x1794 */ int questionSoundID;
	/* 0x1798 */ int yesSoundID;
	/* 0x179c */ int noSoundID;
	/* 0x17a0 */ bool unk_17a0;
	/* 0x17a4 */ cMagMeshObject* soundsManager;
	/* 0x17a8 */ BOOL areSoundMuted;
	/* 0x17ac */ bool unk_17ac;

};

STATIC_ASSERT(sizeof(CWindowExitYesNo) == 0x17b0);

#endif