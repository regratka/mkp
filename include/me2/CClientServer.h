#ifndef _C_CLIENT_SERVER
#define _C_CLIENT_SERVER

#include <globals.h>

class CClientServer {
public:
	/* 1008E580 */ CClientServer(CClientServer* param_1);
	/* 1008E5C0 */ CClientServer* operator=(CClientServer* param_1);
	/* 1008E600 */ CClientServer* scalar_destructor(uchar param_1);
	/* 1008E680 */ CClientServer();
	/* 1008E6B0 */ CClientServer(CGame* param_1);
	/* 1008E6E0 */ ~CClientServer();
	/* 1008EED0 */ bool InitServer();
	/* 1008EF30 */ long StartServer();
	/* 1008F150 */ void StopServer();
	/* 1008F3A0 */ long StartClient();
	/* 1008F420 */ long InitDirectPlay();
	/* 1008F4F0 */ long SessionsDlgEnumHosts();
	/* 1008F8D0 */ void SetSessionName(char* param_1);
	/* 1008F900 */ void SetPlayerName(char* param_1);
	/* 1008F930 */ void SetPort(int param_1);
	/* 1008F940 */ void SetIP(char* param_1);
	/* 1008F970 */ void SendPositionToServerPlayer(D3DXVECTOR3 param_1, D3DXVECTOR3 param_2);
	/* 1008F9F0 */ void PositionToAllPlayers(D3DXVECTOR3 param_1, D3DXVECTOR3 param_2);
	/* 1008FA70 */ void SendStateIdle(uint param_1, uint param_2, uint param_3, uint param_4, uint* param_5, uint param_6);
};

#endif