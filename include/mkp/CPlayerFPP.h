#ifndef _C_PLAYER_F_P_P
#define _C_PLAYER_F_P_P

#include <globals.h>

class CPlayerFPP {
public:
	/* 404E00 */ CPlayerFPP();
	/* 404FB0 */ CPlayerFPP* scalar_destructor(uchar param_1);
	/* 404FD0 */ ~CPlayerFPP();
	/* 4051D0 */ void* EXP();
	/* 405230 */ void OnActivateLevel();
	/* 4054F0 */ uchar OnAnimEnd(char* param_1);
	/* 405510 */ uint OnProcessStateMachine(uint param_1, int param_2, int* param_3);
	/* 405800 */ uchar OnInputKey(int param_1);
	/* 4059A0 */ void OnFrame();
	/* 405BA0 */ uchar FUN00405ba0(float param_1, char param_2);
	/* 405D20 */ uchar FUN00405d20();
	/* 405D80 */ uchar FUN00405d80(uint param_1, int param_2);
	/* 405F50 */ float FUN00405f50();
	/* 405FA0 */ uchar OnChangeMovement(uint param_1);
	/* 405FB0 */ uchar FUN00405fb0(int param_1);
	/* 406080 */ void OnActivate();
	/* 4062F0 */ uchar FUN004062f0();
	/* 4063A0 */ uchar FUN004063a0();
	/* 406570 */ uchar OnInputMouse(uint param_1, uint param_2, char param_3);
	/* 4065C0 */ uchar FUN004065c0();
	/* 4067B0 */ void OnDestTime();
	/* 4067C0 */ void OnFadeOutEnd();
	/* 406810 */ void OnFadeInEnd();
	/* 406860 */ uchar FUN00406860();
	/* 406BB0 */ uchar FUN00406bb0(char* param_1);
	/* 406F40 */ uchar OnLoadChunk(uint param_1, int param_2, uint param_3, void* param_4);
};

#endif