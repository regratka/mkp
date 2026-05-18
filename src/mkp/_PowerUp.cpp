#include "_PowerUp.h"

/* 4327D0-4327E3 00013	*/
_PowerUp::_PowerUp() {
}

/* 432810-43281C 0000C	*/
_PowerUp::~_PowerUp() {
}

/* 432820-43287A 0005A	*/
void* _PowerUp::EXP() {
	return new _PowerUp();
}

