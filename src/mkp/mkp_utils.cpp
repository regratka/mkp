#include "mkp_utils.h"

bool __stdcall FUN00412b00(uchar* param_1) {
	for (int i = 0; i < 256; i++) {
		if ((param_1[i] & 0x80) != 0) {
			return true;
		}
	}
	return false;
}