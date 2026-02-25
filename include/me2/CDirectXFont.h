#ifndef _C_DIRECT_X_FONT
#define _C_DIRECT_X_FONT

#include <globals.h>
#include <d3dx8.h>

struct FONTVERTEX {
	float x;
	float y;
	float z;
	float rhw;
	ulong color;
	float u;
	float v;
};

class __declspec(dllexport) CDirectXFont {
	
public:
	/* 10066270 */ CDirectXFont();
	/* 10066290 */ virtual ~CDirectXFont();
	/* 100662A0 */ HRESULT CreateFontA(IDirect3DDevice8* param_1, char* param_2, long param_3);
	/* 10066690 */ void DrawDebug(float param_1, float param_2);
	/* 10066840 */ void DrawTextA(float param_1, float param_2, char* param_3, ulong param_4);
	/* 10066960 */ IDirect3DVertexBuffer8* CreateStaticText(float param_1, float param_2, char* param_3, ulong param_4);
	/* 10066A30 */ void DrawStaticText(IDirect3DVertexBuffer8* param_1, long param_2, long param_3);
	/* 10066AD0 */ void DestroyStaticText(IDirect3DVertexBuffer8* param_1);
	/* 10066AF0 */ void DestroyFont();
	/* 10066B70 */ void FillCharacter(char param_1, FONTVERTEX** param_2, float param_3, float* param_4, float* param_5, ulong param_6);
	/* 10066D30 */ void FillVertex(FONTVERTEX* param_1, float param_2, float param_3, float param_4, float param_5, ulong param_6);

private:
	/* 0x004 */	int bitmapWidth;
	/* 0x008 */ float charactersPositionInfo[0x180];
	/* 0x608 */ IDirect3DTexture8* directTexture;
	/* 0x60c */ IDirect3DVertexBuffer8* directVertexBuffer;
	/* 0x610 */ IDirect3DDevice8* directDevice;
	/* 0X614 */ ulong blockToken1; 
	/* 0X618 */ ulong blockToken2; 
};

// STATIC_ASSERT(sizeof(CDirectXFont) == 0x61c);

#endif