#ifndef _K_TEKSTURY_VIDEO_DIRECT_X
#define _K_TEKSTURY_VIDEO_DIRECT_X

#include <globals.h>
#include <d3dx8.h>


class CMediaType;
class IMediaSample;
class cMagSprite;


class KTeksturyVideoDirectX  {
public:
	/* 10066DF0 */ KTeksturyVideoDirectX();
	/* 10066F20 */ KTeksturyVideoDirectX* scalar_destructor(uchar param_1);
	/* 10066F80 */ ~KTeksturyVideoDirectX();
	/* 100670D0 */ long CheckMediaType(CMediaType* param_1);
	/* 10067130 */ long SetMediaType(CMediaType* param_1);
	/* 100671E0 */ long DoRenderSample(IMediaSample* param_1);
	/* 100672D0 */ long UtworzZPlikuAVI(IDirect3DDevice8* param_1, char* param_2);
	/* 10067580 */ void SprawdzPetle(cMagSprite* param_1);

public:
	/* 0x15c */ uchar field_0x15c[0x160-0x0];
	/* 0x160 */ int unk_160;
	/* 0x164 */ int unk_164;
	/* 0x168 */ int unk_168;
	/* 0x16c */ int unk_16c;
	/* 0x170 */ uchar field_0x170[0x188-0x170];
	/* 0x188 */ IDirect3DTexture8* texture;
	/* 0x18c */ IDirect3DDevice8* device;
	/* 0x190 */ uchar field_0x190[0x198-0x190];
};

#endif