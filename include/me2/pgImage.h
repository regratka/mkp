#ifndef PG_IMAGE
#define PG_IMAGE

#include <globals.h>
#include "d3d8.h"

#include "pgString.h"

struct FORMAT {

};

class pgImage {
public:
	/* 1000B460 */ bool isCompressed();
	/* 1000B480 */ static _D3DFORMAT getD3DFormat(FORMAT param_1);
	/* 1000B490 */ pgImage(pgImage* param_1);
	/* 1000B4C0 */ pgImage* operator=(pgImage* param_1);
	/* 1000B4F0 */ ~pgImage();
	/* 10081BF0 */ pgImage();
	/* 10081C10 */ pgImage(int param_1, int param_2, FORMAT param_3, pgString* param_4, uchar* param_5, bool param_6);
	/* 10081CE0 */ int getPixelSize();
	/* 10081CF0 */ static int getPixelSize(FORMAT param_1);
	/* 10081D60 */ static pgString* getFormatString(pgString* param_1, int param_2);
	/* 10081D90 */ static pgString* getFormatString(pgString* param_1, FORMAT param_2);
	/* 10081F80 */ static bool isCompressed(FORMAT param_1);
	/* 10081FC0 */ static bool hasAlpha(FORMAT param_1);
};

#endif