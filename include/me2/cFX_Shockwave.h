#ifndef C_F_X__SHOCKWAVE
#define C_F_X__SHOCKWAVE

#include <globals.h>

#include "cMagUtility.h"

class __declspec(dllexport) cFX_Shockwave : public cMagUtility {
public:
	/* 10022F90-10022FD4 00044	*/
	cFX_Shockwave() {
		this->texture = NULL;
		this->vertexBuffer = NULL;
		this->engine = NULL;
		this->sections = 0;
		this->radius = 0.0f;
		this->range = 0.0f;
		this->verticesAmount = 0;
		this->isRunning = false;
	}

	/* 10022FE0-10022FE8 00008	*/
	virtual void Begin() {
		this->isRunning = true;
	}

	/* 10022FF0-10022FF8 00008	*/
	virtual void Pause() {
		this->isRunning = false;
	}

	/* 10023000-10023021 00021	*/
	virtual void Stop() {
		Pause();
		this->time = 0.0f;
		this->scale = 0.0001f;
	}

	/* 1000FF70-1000FF77 00007	*/ 
	virtual bool IsRunning() {
		return this->isRunning;
	}

	/* 10023030-100230A5 00075	*/
	void ShockwaveUpdate(float param_1) {
		if (IsRunning()) {
			this->scale += param_1 * this->scaleGrowth;
			this->time += param_1;
			SetAlpha(255.0f - (time / duration) * 255.0f);
			if (time > duration) {
				Stop();
			}
		}
	}

	/* 100230B0-100230B7 00007	*/
	D3DXVECTOR3& Pos() {
		return this->position;
	}

	/* 100230C0-100230C7 00007	*/
	IDirect3DVertexBuffer8* GetVB() {
		return this->vertexBuffer;

	}
	/* 100764E0 */ virtual ~cFX_Shockwave();
	/* 10076550 */ HRESULT RestoreDeviceObjects(char const* param_1, float param_2, float param_3, int param_4, float param_5, float param_6);
	/* 10076860 */ void SetAlpha(int param_1);
	/* 100768C0 */ void InvalidateDeviceObjects();
	/* 10076900 */ void ShockwaveRender();

private:
	/* 0xd4c */ bool isRunning;
	/* 0xd50 */ IDirect3DTexture8* texture;
	/* 0xd54 */ IDirect3DVertexBuffer8* vertexBuffer;
	/* 0xd58 */ IDirect3DDevice8* engine;
	/* 0xd5c */ D3DXVECTOR3 position;
	/* 0xd68 */ int sections;
	/* 0xd6c */ float radius;
	/* 0xd70 */ float duration;
	/* 0xd74 */ float time;
	/* 0xd78 */ float scaleGrowth;
	/* 0xd7c */ float range;
	/* 0xd80 */ float scale;
	/* 0xd84 */ int verticesAmount;
};

STATIC_ASSERT(sizeof(cFX_Shockwave) == 0xd88);

#endif