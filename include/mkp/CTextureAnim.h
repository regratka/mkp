#ifndef _C_TEXTURE_ANIM
#define _C_TEXTURE_ANIM

#include <globals.h>

class CTextureAnim {
public:
	/* 443030 */ CTextureAnim();
	/* 443050 */ CTextureAnim* scalar_destructor(uchar param_1);
	/* 443070 */ ~CTextureAnim();
	/* 443080 */ void* EXP();
	/* 4430E0 */ void OnActivateLevel();
	/* 443450 */ uchar OnLoadChunk(uint param_1, int param_2, uint param_3, void* param_4);
};

#endif