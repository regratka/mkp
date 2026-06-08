#ifndef _C_ARMATA
#define _C_ARMATA

#include <globals.h>
#include <vector>

#include "cMagMeshObject.h"
#include "cKbSettings.h"
#include "CArmataPocisk.h"
#include "CHudGratka.h"
#include "CCamera.h"

class CArmata : public cMagMeshObject {
public:
	/* 4262D0 */ void OnLoadChunk(_ED_CHUNK param_1, FILE* param_2);
	/* 439F40 */ CArmata();
	/* 43A030 */ virtual ~CArmata();
	/* 43A0B0 */ void* EXP();
	/* 43A110 */ void OnActivate();
	/* 43A150 */ void OnActivateLevel();
	/* 43A1B0 */ void FUN0043a1b0(float param_1);
	/* 43A280 */ void OnInputKey(uchar* param_1);
	/* 43A7E0 */ void FUN0043a7e0();
	/* 43A890 */ void FUN0043a890();
	/* 43A900 */ void FUN0043a900();
	/* 43AB90 */ void FUN0043ab90(float param_1);

private:
	/* 0x2658 */ char unk_2658[200];
	/* 0x2720 */ bool unk_2720;
	/* 0x2724 */ CHudGratka* hud;
	/* 0x2728 */ bool unk_2728;
	/* 0x272c */ int unk_272c;
	/* 0x2730 */ bool unk_2730;
	/* 0x2731 */ uchar field_0x2731[0x2734-0x2731];
	/* 0x2734 */ cKbSettings kbSettings;
	/* 0x2a28 */ float unk_2a28;
	/* 0x2a2c */ int unk_2a2c;
	/* 0x2a30 */ int unk_2a30;
	/* 0x2a34 */ int unk_2a34;
	/* 0x2a38 */ CCamera* camera; /* TODO unknown CCamera subclass */
	/* 0x2a3c */ cMagKernel* unk_2a3c;
	/* 0x2a40 */ std::vector<CArmataPocisk*> bullets;
	/* 0x2a50 */ int unk_2a50;
	/* 0x2a54 */ bool unk_2a54;
	/* 0x2a58 */ int soundID;
};

STATIC_ASSERT(sizeof(CArmata) == 0x2a60);

#endif