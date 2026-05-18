#include "_Action.h"

/* 416820-416833 00013	*/
_Action::_Action() {
}

/* 416860-41686C 0000C	*/
_Action::~_Action() {
}

/* 416870-4168CA 0005A	*/
void* _Action::EXP() {
	return new _Action();
}

