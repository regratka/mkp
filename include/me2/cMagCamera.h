#ifndef C_MAG_CAMERA
#define C_MAG_CAMERA

#include <globals.h>

#include "cMagUtility.h"

class DLLEXPORT cMagCamera : public cMagUtility {
public:

	/* 10012910-10012911 00001	*/
	void OnRender() {
	}

	/* 10021350-1002136D 0001D	*/
	void SetPosition(D3DXVECTOR3 param_1) {
		position = param_1;
	}

	/* 10021370-1002138D 0001D	*/
	void cMagCamera::SetView(D3DXVECTOR3 param_1) {
		view = param_1;
	}

	/* 10021390-100213B1 00021	*/
	D3DXVECTOR3 cMagCamera::GePosition() {
		return position;
	}

	/* 100213C0-100213E1 00021	*/
	D3DXVECTOR3 cMagCamera::GetView() {
		return view;
	}

	/* 10060620 */ virtual ~cMagCamera();
	/* 10060630 */ cMagCamera(float param_1 = 0.0f, float param_2 = 0.0f, float param_3 = 0.0f, float param_4 = 0.0f, float param_5 = 0.0f, float param_6 = -1.0f, float param_7 = 0.0f, float param_8 = 1.0f, float param_9 = 0.0f);
	/* 10060690 */ void Init(float param_1, float param_2, float param_3, float param_4, float param_5, float param_6, float param_7, float param_8, float param_9);
	/* 100606D0 */ void PositionCamera(float param_1, float param_2, float param_3, float param_4, float param_5, float param_6, float param_7, float param_8, float param_9);
	/* 10060790 */ void RotateView(float param_1, float param_2, float param_3);
	/* 100608B0 */ void MoveCamera(float param_1);
	/* 10060960 */ bool MoveCameraByMouse(int param_1, int param_2, int param_3, int param_4);

private:
	/* 0xd4c */ D3DXVECTOR3 position;
	/* 0xd58 */ D3DXVECTOR3 view;
	/* 0xd64 */ D3DXVECTOR3 unk_d64;
};

D3DXVECTOR3 G1018c5c8;
D3DXVECTOR3 G1018c5d8;
D3DXVECTOR3 G1018c5e8;

STATIC_ASSERT(sizeof(cMagCamera) == 0xd70);

#endif