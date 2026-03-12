#ifndef C_MAG_SPRITE
#define C_MAG_SPRITE

#include <globals.h>

#include <d3dx8math.h>

#include "cMagUtility.h"

struct Rect;
struct D3DTLVERTEXS;

class cMagSprite : public cMagUtility {
public:
	/* 1000A9B0 */ void PlayMovie(bool param_1);
	/* 10062870 */ cMagSprite();
	/* 10062BE0 */ cMagSprite* scalar_destructor(uchar param_1);
	/* 10062C40 */ virtual~cMagSprite();
	/* 10062DA0 */ void SetTextColor(int param_1, float param_2, float param_3, float param_4, float param_5);
	/* 10062E50 */ void ShowText(int param_1, bool param_2);
	/* 10062ED0 */ void SetText(int param_1, char* param_2);
	/* 10062F90 */ void SetText(int param_1, char* param_2, float param_3, float param_4, float param_5, float param_6, float param_7, float param_8);
	/* 10063110 */ void SetTextPosition(int param_1, float param_2, float param_3);
	/* 10063200 */ char* GetText(int param_1);
	/* 10063280 */ void ClearTextBuffer();
	/* 10063340 */ int SetText(char* param_1, float param_2, float param_3, float param_4, float param_5, float param_6, float param_7);
	/* 100636C0 */ void CreateFontA(char* param_1, long param_2);
	/* 10063720 */ void Restore();
	/* 100637E0 */ void SetAlpha1(ulong param_1, ulong param_2);
	/* 10063800 */ void LoadSprites(char* param_1);
	/* 100638B0 */ void SetScale(float param_1, float param_2, float param_3);
	/* 100638E0 */ void EnableSpriteRendering(bool param_1);
	/* 100638F0 */ void OnRender();
	/* 10063AA0 */ void SetScale(tagRECT param_1);
	/* 10063AB0 */ int AddTexture(char* param_1);
	/* 10063FC0 */ void Top(int param_1);
	/* 10064240 */ void Bottom(int param_1);
	/* 100644D0 */ void SetRotate(int param_1, uint param_2, float param_3, float param_4);
	/* 10064640 */ void SetPos(int param_1, float param_2, float param_3, int param_4);
	/* 100647A0 */ D3DXVECTOR2 GetPos(float* param_1, int param_2);
	/* 10064850 */ D3DXVECTOR2 GetSize(uint* param_1, int param_2);
	/* 100648E0 */ void SetScale(int param_1, float param_2, float param_3);
	/* 10064A70 */ D3DXVECTOR2 GetScale(uint* param_1, int param_2);
	/* 10064B00 */ void Show(int param_1);
	/* 10064B70 */ void Hide(int param_1);
	/* 10064BE0 */ void HideRender(int param_1, bool param_2);
	/* 10064C50 */ void RenderSprites();
	/* 10064EC0 */ void SetAlpha(int param_1, float param_2);
	/* 10064F30 */ void EnableCheckMouse(int param_1, bool param_2);
	/* 10064FA0 */ void CheckMouseRegion();
	/* 10065130 */ void SetScaleAsWindow(int param_1);
	/* 100651F0 */ int GetMouseActivateSprite();
	/* 10065250 */ void TexFromDigit(int param_1, int param_2, int param_3, int param_4, Rect* param_5);
	/* 100652D0 */ void CutFrame(int param_1, int param_2, int param_3, int param_4, Rect* param_5);
	/* 100653E0 */ void SetTextureRect(int param_1);
	/* 10065490 */ _D3DMATRIX* BuildMatrix(_D3DMATRIX* param_1, D3DXVECTOR2* param_2, D3DXVECTOR2* param_3, float param_4);
	/* 10065710 */ void TransformVertices(D3DTLVERTEXS* param_1, D3DXVECTOR2* param_2, D3DXVECTOR2* param_3, float param_4);
	/* 100657D0 */ void Blit(uchar param_1, uchar param_2, tagPOINT* param_3, D3DXVECTOR2* param_4, D3DXVECTOR2* param_5, float param_6, ulong param_7);
	/* 10065930 */ void BlitX(uchar param_1, uchar param_2, tagPOINT* param_3, ulong param_4, float param_5, float param_6);
	/* 10065940 */ void CreateSurfaceFromFile(uchar param_1, IDirect3DSurface8** param_2, char* param_3, ulong param_4);
	/* 10065950 */ void CreateTextureFromSurface(uchar param_1, IDirect3DSurface8* param_2, tagRECT* param_3, uchar param_4);
	/* 10065990 */ void LoadSprite(char* param_1);
	/* 10065A00 */ void RenderTestSprite();
	/* 10065A40 */ long LoadMovie(char* param_1);
	/* 10065A90 */ long UtworzBuforDuszkow();
	/* 10065BD0 */ long CreatePlane(char* param_1);
	/* 10065D10 */ void RenderPlane();
	/* 10066020 */ void RysujDuszkiEx(float param_1, float param_2, float param_3, float param_4, float param_5, float param_6);
	/* 10066140 */ void SetScaleMovie(float param_1, float param_2);
	/* 10066160 */ void SetRotateMovie(float param_1);
};

#endif