#ifndef C_MAG_SPRITE
#define C_MAG_SPRITE

#include <globals.h>
#include <d3dx8math.h>
// #include <vector>

#include "cMagUtility.h"
#include "CDirectXFont.h"
#include "KTeksturyVideoDirectX.h"

struct Rect { 
	/* 0x00  */ float unk_00;
	/* 0x04  */ float unk_04;
	/* 0x08  */ float unk_08;
	/* 0x0c  */ float unk_0c;
};
struct D3DTLVERTEXS;

class DLLEXPORT cMagSprite : public cMagUtility {

private:
	struct SubSpriteData {
		/* 0x00  */ int texID;
		/* 0x04  */ bool shouldShowText;
		/* 0x05  */ bool shouldHideRender;
		/* 0x06  */ bool unk_06;
		/* 0x07  */ uchar field_0x07[0x10-0x7];
		/* 0x10  */ IDirect3DTexture8* texture;
		/* 0x14  */ D3DXVECTOR2 unk_14;
		// /* 0x18  */ float unk_18;
		/* 0x1c  */ float unk_1c;
		/* 0x20  */ float unk_20;
		/* 0x24  */ float unk_24;
		/* 0x28  */ float unk_28;
		/* 0x2c  */ float unk_2c;
		/* 0x30  */ float unk_30;
		/* 0x34  */ bool unk_34;
		/* 0x38  */ D3DXVECTOR2 unk_38;
		/* 0x40  */ D3DXVECTOR2 unk_40;
		/* 0x48  */ D3DXVECTOR2 unk_48;
		/* 0x50  */ float unk_50;
		/* 0x54  */ float unk_54;
		/* 0x58  */ float unk_58;
		/* 0x5c  */ D3DXVECTOR2 unk_5c;
		/* 0x64  */ RECT unk_64;
		/* 0x74  */ float unk_74;
		/* 0x78  */ uchar field_0x78[0x7c - 0x78];
		/* 0x7c  */ char texturePath[255];
		/* 0x17b */ bool shouldCheckMouse;
		/* 0x17c */ bool unk_17c;
		/* 0x17d */ char text[255];
		/* 0x27c */ D3DXVECTOR2 textPosition;
		/* 0x284 */ D3DXCOLOR textColor;
	};

	STATIC_ASSERT(sizeof(SubSpriteData) == 0x294);

public:
	/* 1000A9B0 */ void PlayMovie(bool param_1);
	/* 1000FF70 */ bool GetStatusRemoveObject();
	/* 1000FF80 */ void RemoveObject(bool param_1);
	/* 10012910 */ void DeleteAllSprites();
	/* 10030740 */ void SetMouseRegion(int param_1, int param_2, int param_3);
	/* 1005A5E0 */ void InitDeviceDx(cMagGameObject* param_1);
	/* 1005A5F0 */ void SetCursorPosition(int param_1, int param_2);
	/* 10062870 */ cMagSprite();
	/* 10062C40 */ virtual ~cMagSprite();
	/* 10062DA0 */ void SetTextColor(int param_1, float param_2, float param_3, float param_4, float param_5);
	/* 10062DA0 */ void ShowText(int param_1, float param_2, float param_3, float param_4, float param_5);
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
	/* 100644D0 */ void SetRotate(int param_1, float param_2, D3DXVECTOR2 param_3);
	/* 10064640 */ void SetPos(int param_1, float param_2, float param_3, int param_4);
	/* 100647A0 */ D3DXVECTOR2 GetPos(int param_1);
	/* 10064850 */ D3DXVECTOR2 GetSize(int param_1);
	/* 100648E0 */ void SetScale(int param_1, float param_2, float param_3);
	/* 10064A70 */ D3DXVECTOR2 GetScale(int param_1);
	/* 10064B00 */ void Show(int param_1);
	/* 10064B70 */ void Hide(int param_1);
	/* 10064BE0 */ void HideRender(int param_1, bool param_2);
	/* 10064C50 */ void RenderSprites();
	/* 10064EC0 */ void SetAlpha(int param_1, float param_2);
	/* 10064F30 */ void EnableCheckMouse(int param_1, bool param_2);
	/* 10064FA0 */ void CheckMouseRegion();
	/* 10065130 */ void SetScaleAsWindow(int param_1);
	/* 100651F0 */ int GetMouseActivateSprite();
	/* 10065250 */ void TexFromDigit(int param_1, int param_2, int param_3, int param_4, Rect& param_5);
	/* 100652D0 */ void CutFrame(int param_1, int param_2, int param_3, int param_4, Rect& param_5);
	/* 100653E0 */ void SetTextureRect(int param_1, Rect param_2);
	/* 10065490 */ _D3DMATRIX* BuildMatrix(_D3DMATRIX* param_1, D3DXVECTOR2* param_2, D3DXVECTOR2* param_3, float param_4);
	/* 10065710 */ void TransformVertices(D3DTLVERTEXS* const param_1, D3DXVECTOR2* param_2, D3DXVECTOR2* param_3, float param_4);
	/* 100657D0 */ void Blit(IDirect3DDevice8* param_1, IDirect3DTexture8* param_2, tagPOINT* param_3, D3DXVECTOR2* param_4, D3DXVECTOR2* param_5, float param_6, ulong param_7);
	/* 10065930 */ void BlitX(IDirect3DDevice8* param_1, IDirect3DTexture8* param_2, tagPOINT* param_3, ulong param_4, float param_5, float param_6);
	/* 10065930 */ void InitSpriteAnim(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6);
	/* 10065940 */ void CreateSurfaceFromFile(IDirect3DDevice8* param_1, IDirect3DSurface8** param_2, char* const param_3, ulong param_4);
	/* 10065950 */ void CreateTextureFromSurface(IDirect3DDevice8* param_1, IDirect3DSurface8* param_2, tagRECT* param_3, IDirect3DTexture8** param_4);
	/* 10065990 */ void LoadSprite(char* param_1);
	/* 10065A00 */ void RenderTestSprite();
	/* 10065A40 */ long LoadMovie(char* param_1);
	/* 10065A90 */ long UtworzBuforDuszkow();
	/* 10065BD0 */ long CreatePlane(char* param_1);
	/* 10065D10 */ void RenderPlane();
	/* 10066020 */ void RysujDuszkiEx(float param_1, float param_2, float param_3, float param_4, float param_5, float param_6);
	/* 10066140 */ void SetScaleMovie(float param_1, float param_2);
	/* 10066160 */ void SetRotateMovie(float param_1);

private:
	/* 0xd4c  */ bool shouldRemoveObject;
	/* 0xd4d  */ bool unk_d4d;
	/* 0xd50  */ int srcBlend;
	/* 0xd54  */ int destBlend;
	/* 0xd58  */ bool shouldRenderSprites;
	/* 0xd59  */ bool unk_d59;
	/* 0xd5a  */ bool unk_d5a;
	/* 0xd5c  */ std::vector<SubSpriteData> subSprites;
	/* 0xd6c  */ D3DXVECTOR3 unk_d6c;
	/* 0xd78  */ D3DXVECTOR3 unk_d78;
	/* 0xd84  */ D3DXVECTOR3 scale;
	/* 0xd90  */ uchar field_0xd90[0xdd0 - 0xd90];
	/* 0xdd0  */ float unk_dd0;
	/* 0xdd4  */ float unk_dd4;
	/* 0xdd8  */ IDirect3DTexture8* testTexture;
	/* 0xddc  */ uchar field_0xddc[0xde0 - 0xddc];
	/* 0xdd8  */ CDirectXFont directXFont;
	/* 0x13fc */ char typefaceName[200];
	/* 0x14c4 */ long unk_14c4;
	/* 0x14c8 */ KTeksturyVideoDirectX teksturyVideo;
	/* 0x1660 */ IDirect3DVertexBuffer8* vertexBuffer;
	/* 0x1664 */ D3DXMATRIX unk_1664;
	/* 0x16a4 */ D3DXMATRIX unk_16a4;
	/* 0x16e4 */ D3DXMATRIX unk_16e4;
	/* 0x1724 */ bool unk_1724;
	/* 0x1725 */ bool shouldPlayMovie;
	/* 0x1728 */ float movieScaleX;
	/* 0x172c */ float movieScaleY;
	/* 0x1730 */ float unk_1730;
	/* 0x1734 */ float rotationMovie;
	/* 0x1738 */ bool unk_1738;
	/* 0x173c  */ IDirect3DTexture8* texture;
};

STATIC_ASSERT(sizeof(cMagSprite) == 0x1740);

#endif