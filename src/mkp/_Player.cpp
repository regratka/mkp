#include "_Player.h"

/* 40E670-40E683 00013	*/
_Player::_Player() {
}

/* 40E6B0-40E6BC 0000C	*/
_Player::~_Player() {
}

/* 40E6C0-40E71A 0005A	*/
void* _Player::EXP() {
	return new _Player();
}

