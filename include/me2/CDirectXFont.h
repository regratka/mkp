#ifndef _C_DIRECT_X_FONT
#define _C_DIRECT_X_FONT

#include <globals.h>
#include <d3d8.h>

struct FONTVERTEX {

};

class CDirectXFont {
public:
	/* 1000A870 */ CDirectXFont(CDirectXFont* param_1);
	/* 1000A8E0 */ CDirectXFont* operator=(CDirectXFont* param_1);
	/* 1000A950 */ CDirectXFont* scalar_destructor(uchar param_1);
	/* 10066270 */ CDirectXFont();
	/* 10066290 */ ~CDirectXFont();
	/* 100662A0 */ long CreateFontA(IDirect3DDevice8* param_1, char* param_2, long param_3);
	/* 10066690 */ void DrawDebug(float param_1, float param_2);
	/* 10066840 */ void DrawTextA(float param_1, float param_2, char* param_3, ulong param_4);
	/* 10066960 */ IDirect3DVertexBuffer8* CreateStaticText(float param_1, float param_2, IDirect3DVertexBuffer8* param_3, ulong param_4);
	/* 10066A30 */ void DrawStaticText(uchar param_1, long param_2, long param_3);
	/* 10066AD0 */ void DestroyStaticText(IDirect3DVertexBuffer8* param_1);
	/* 10066AF0 */ void DestroyFont();
	/* 10066B70 */ void FillCharacter(char param_1, FONTVERTEX** param_2, float param_3, float* param_4, float* param_5, ulong param_6);
	/* 10066D30 */ void FillVertex(FONTVERTEX* param_1, float param_2, float param_3, float param_4, float param_5, ulong param_6);
};

#endif