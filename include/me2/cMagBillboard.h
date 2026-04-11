#ifndef C_MAG_BILLBOARD
#define C_MAG_BILLBOARD

#include <globals.h>

#include "cMagUtility.h"

class cMagBillboard : public cMagUtility {
public:
	/* 1000FF70 */ bool GetStatusRemoveObject();
	/* 1000FF80 */ void RemoveObject(bool param_1);
	/* 1000FF90 */ void SetRotationYaw(float param_1);
	/* 1000FFC0 */ void SetPosition(uint param_1, uint param_2, uint param_3);
	/* 1000FFE0 */ float GetRotationYaw();
	/* 1000FFF0 */ float GetRotationPitch();
	/* 10010000 */ float GetRotationRoll();
	/* 10010010 */ uchar GetPosition(uint* param_1);
	/* 10010040 */ float GetZPosition();
	/* 10010050 */ float GetXPosition();
	/* 10010060 */ void SetZPosition(float param_1);
	/* 10010070 */ void SetXPosition(float param_1);
	/* 10010080 */ void SetBlendAlpha(bool param_1);
	/* 100100A0 */ uchar GetWorldMat(uint* param_1);
	/* 100100C0 */ void EnableFrustum(bool param_1);
	/* 100100D0 */ cMagBillboard(cMagBillboard* param_1);
	/* 10010470 */ cMagBillboard* operator=(cMagBillboard* param_1);
	/* 100108A0 */ cMagBillboard* scalar_destructor(uchar param_1);
	/* 10067AD0 */ cMagBillboard();
	/* 10067C30 */ ~cMagBillboard();
	/* 10067D40 */ void SetTexture(char* param_1);
	/* 10067D60 */ void Render();
	/* 10067EF0 */ bool AddFrame(char* param_1, float param_2);
	/* 100681B0 */ int GetCurFrame();
	/* 10068230 */ void EnableRendering(bool param_1);
	/* 10068240 */ void OnUpdate_();
	/* 10068610 */ void OnRender();
	/* 10068770 */ void EnableAnim(bool param_1);
	/* 10068790 */ void Enable3Axis(bool param_1);
	/* 100687A0 */ void SetUpMode(bool param_1);
	/* 100687B0 */ void SetAlpha(ulong param_1, ulong param_2);
	/* 10068850 */ void CalculateVectorMinMax();
	/* 10068940 */ void GetBoundingBox(uchar param_1, uchar param_2, int param_3);
	/* 10068990 */ uchar GetTransformMatrix(uint* param_1);
	/* 100689B0 */ bool EnableZBuffeWrite();
	/* 100689C0 */ void EnableZBuffeWrite(bool param_1);
	/* 100689D0 */ void SetHandlerObject(cMagGameObject* param_1);

private:
	/* 0xd4c */ uchar field_0xd4c[0x1008 - 0xd4c];
};

STATIC_ASSERT(sizeof(cMagBillboard) == 0x1008);

#endif