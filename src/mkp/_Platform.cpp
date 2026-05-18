#include "_Platform.h"

/* 41A700-41A713 00013	*/
_Platform::_Platform() {
}

/* 41A740-41A74C 0000C	*/
_Platform::~_Platform() {
}

/* 41A750-41A7AA 0005A	*/
void* _Platform::EXP() {
	return new _Platform();
}

