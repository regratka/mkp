#ifndef _C_CLIENT_SERVER_PLAYER
#define _C_CLIENT_SERVER_PLAYER

#include <globals.h>

class CClientServerPlayer {
public:
	/* 1008FC80 */ CClientServerPlayer();
	/* 1008FCC0 */ ~CClientServerPlayer();
	/* 1008FE40 */ void SetStateIdle(D3DXVECTOR3 param_1, D3DXVECTOR3 param_2);
	/* 1008FEF0 */ uchar SetPosition(D3DXVECTOR3 param_1, D3DXVECTOR3 param_2);
};

#endif