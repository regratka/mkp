#ifndef _C_OKNO_TAJNY_KOD
#define _C_OKNO_TAJNY_KOD

#include <globals.h>

#include "cMagSprite.h"
#include "CPlayerTPP.h"
#include "CMotorboat.h"
#include "UIWindow.h"
#include "UIEdit.h"

class COknoTajnyKod : public cMagSprite {
public:
	/* 419BA0 */ void OnActivateLevel();
	/* 4272F0 */ COknoTajnyKod(CPlayerTPP* param_1);
	/* 427370 */ virtual ~COknoTajnyKod();
	/* 427380 */ virtual void OnActivate();
	/* 427660 */ void FUN00427660();
	/* 4276F0 */ void FUN004276f0();
	/* 427860 */ void FUN00427860();
	/* 427910 */ void FUN00427910();
	/* 427950 */ virtual void OnFrame();
	/* 427A40 */ virtual void OnMouseArrive(int param_1);
	/* 427AA0 */ virtual void OnMouseLeave(int param_1);
	/* 427AE0 */ void FUN00427ae0();
	/* 427B40 */ virtual void OnInputMouse(float param_1, float param_2, bool param_3, bool param_4);
	/* 427B80 */ virtual void OnInputKey(uchar* param_1);

private:
	/* 0x1740 */ cMagMeshObject* meshObject;
	/* 0x1744 */ bool unk_1744;
	/* 0x1745 */ bool unk_1745;
	/* 0x1748 */ int doorsTextureID;
	/* 0x174c */ int doorsATextureID;
	/* 0x1750 */ uchar field_0x1750[0x1754-0x1750];
	/* 0x1754 */ float unk_1754;
	/* 0x1758 */ float unk_1758;
	/* 0x175c */ uchar field_0x175c[0x1760-0x175c];
	/* 0x1760 */ int soundID;
	/* 0x1764 */ CPlayerTPP* player;
	/* 0x1768 */ CMotorboat* motorboat;
	/* 0x176c */ UIWindow* uiWindow;
	/* 0x1770 */ UIEdit* uiEdit;
	/* 0x1774 */ UIWindow* uiWindow2;
	/* 0x1778 */ int cursorsTextureID[4];
	/* 0x1788 */ int unk_1788;
	/* 0x178c */ float unk_178c;
	/* 0x1790 */ bool unk_1790;
	/* 0x1794 */ uchar field_0x1794[0x1798-0x1794];
};

STATIC_ASSERT(sizeof(COknoTajnyKod) == 0x1798);

#endif