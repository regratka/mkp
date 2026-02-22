#include "pgImage.h"

/* 1000B460-1000B46D 0000D	*/
bool pgImage::isCompressed() {
	return 0;
}

/* 1000B480-1000B485 00005	*/
_D3DFORMAT pgImage::getD3DFormat(FORMAT param_1) {
	return _D3DFORMAT();
}

/* 1000B490-1000B4BF 0002F	*/
pgImage::pgImage(pgImage* param_1) {
}

/* 1000B4C0-1000B4EF 0002F	*/
pgImage* pgImage::operator=(pgImage* param_1) {
	return 0;
}

/* 1000B4F0-1000B4F8 00008	*/
pgImage::~pgImage() {
}

/* 10081BF0-10081C03 00013	*/
pgImage::pgImage() {
}

/* 10081C10-10081CDB 000CB	*/
pgImage::pgImage(int param_1, int param_2, FORMAT param_3, pgString* param_4, uchar* param_5, bool param_6) {
}

/* 10081CE0-10081CED 0000D	*/
int pgImage::getPixelSize() {
	return 0;
}

/* 10081CF0-10081D26 00036	*/
int pgImage::getPixelSize(FORMAT param_1) {
	return 0;
}

/* 10081D60-10081D81 00021	*/
pgString* pgImage::getFormatString(pgString* param_1, int param_2) {
	return 0;
}

/* 10081D90-10081F3D 001AD	*/
pgString* pgImage::getFormatString(pgString* param_1, FORMAT param_2) {
	return 0;
}

/* 10081F80-10081FB2 00032	*/
bool pgImage::isCompressed(FORMAT param_1) {
	return 0;
}

/* 10081FC0-1008200B 0004B	*/
bool pgImage::hasAlpha(FORMAT param_1) {
	return 0;
}

