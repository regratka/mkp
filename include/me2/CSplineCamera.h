#ifndef _C_SPLINE_CAMERA
#define _C_SPLINE_CAMERA

#include <globals.h>

class CSplineCamera {
public:
	/* 10090470 */ CSplineCamera(CSplineCamera* param_1);
	/* 10090710 */ CSplineCamera* operator=(CSplineCamera* param_1);
	/* 100909F0 */ bool* scalar_destructor(uchar param_1);
	/* 100BCC80 */ CSplineCamera();
	/* 100BCD60 */ ~CSplineCamera();
	/* 100BCE90 */ void AddFrameKey(D3DXVECTOR3 param_1, float param_2, float param_3, float param_4, D3DXVECTOR3 param_5);
	/* 100BD0B0 */ void Play(float param_1);
	/* 100BD100 */ void Stop();
	/* 100BD110 */ void Play(float param_1, float param_2);
	/* 100BD200 */ void SetTimeAdjust(float param_1);
	/* 100BD210 */ float GetTimeAdjust();
	/* 100BD220 */ float* Update(float* param_1, float param_2);
	/* 100BD8A0 */ float GetTotalTime();
	/* 100BD8E0 */ void DeleteFrame(int param_1);
	/* 100BD970 */ CSplineControlPoint* GetFrameKeyAt(int param_1);
	/* 100BD9A0 */ float GetTotalLen();
	/* 100BD9E0 */ void SetType(uchar param_1);
	/* 100BD9F0 */ uchar GetType();
	/* 100BDA00 */ int GetFrameCount();
	/* 100BDA20 */ void SetFPS(float param_1);
	/* 100BDA30 */ float GetFPS();
	/* 100BDA40 */ void InsertFrameKey(CSplineControlPoint* param_1, int param_2);
	/* 100BDC20 */ void LookAt(D3DXVECTOR3 param_1);
	/* 100BDC80 */ void Roll(float param_1);
	/* 100BDCC0 */ void CopyKeyFrames(CSplineCamera* param_1);
	/* 100BDE70 */ void CopyKeyFrames(std::vector<CSplineControlPoint>* param_1);
	/* 100BE010 */ void OnRender();
	/* 100BE170 */ void PlayReverse(float param_1);
	/* 100BE200 */ void SetHandlerObject(cMagGameObject* param_1);
	/* 100BE210 */ void SetDestTime(float param_1);
	/* 100BE280 */ void ClearDestTime();
	/* 100BE2B0 */ void CallDestTimeHandler(float param_1);
	/* 100BE330 */ bool IsPlaying();
	/* 100BE340 */ float* UpdateByLen(float* param_1, float param_2);
	/* 100BE990 */ float GetCurLen();
	/* 100BE9A0 */ float GetCurTime();
	/* 100BE9D0 */ void SetLerp(bool param_1);
};

#endif