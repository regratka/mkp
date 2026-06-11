#ifndef C_KB_SETTINGS
#define C_KB_SETTINGS

#include <globals.h>

class cKbSettings {
public:
	/* 40FFC0 */ cKbSettings();
	/* 410230 */ uint* scalar_destructor(uchar param_1);
	/* 410250 */ ~cKbSettings();
	/* 410260 */ int FUN00410260(char* param_1);
private:
	/* 0x00 */ uchar field_00[0x2f2];
};

#endif