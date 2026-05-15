#ifndef _C_MOTORBOAT
#define _C_MOTORBOAT

#include <globals.h>

#include "cMagMeshObject.h"

class CMotorboat {
public:
	/* 40D390 */ CMotorboat();
	/* 40D440 */ CMotorboat* scalar_destructor(uchar param_1);
	/* 40D460 */ ~CMotorboat();
	/* 40D470 */ void* EXP();
	/* 40D4D0 */ void Load();
	/* 40D6A0 */ void Save();
	/* 40DA30 */ uchar OnPlaySoundEnd(int param_1);
	/* 40DA90 */ uchar OnExitYesNo(char* param_1);
	/* 40DAF0 */ uchar FUN0040daf0();
	/* 40DC10 */ uchar OnInputKey(int param_1);
	/* 40DE40 */ cMagMeshObject* FUN0040de40(char* param_1, uint* param_2);
	/* 40DF10 */ void FUN0040df10();
	/* 40DFB0 */ void OnFrame();
	/* 40E000 */ uchar OnLoadChunk(uint param_1, int param_2, uint param_3, void* param_4);
	/* 40E030 */ void OnFadeOutEnd();
	/* 40E080 */ uchar OnCrash(cMagMeshObject* param_1);
	/* 40E160 */ uchar FUN0040e160();
	/* 40E220 */ uchar FUN0040e220(int param_1);
};

#endif