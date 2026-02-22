#ifndef C_MAG_LINE
#define C_MAG_LINE

#include <globals.h>

class cMagLine {
public:
	/* 10006950 */ int GetSize();
	/* 10006960 */ cMagLine* operator=(cMagLine* param_1);
	/* 1002D7D0 */ cMagLine(cMagLine* param_1);
	/* 1002DAA0 */ cMagLine* scalar_destructor(uchar param_1);
	/* 1002DB00 */ cMagLine();
	/* 1002DB60 */ void InitDeviceDx(cMagGameObject* param_1);
	/* 1002DB80 */ cMagLine(float param_1, float param_2, float param_3, ulong param_4, float param_5, float param_6, float param_7, ulong param_8);
	/* 1002DC30 */ ~cMagLine();
	/* 1002DCA0 */ void SetProps(float param_1, float param_2, float param_3, ulong param_4, float param_5, float param_6, float param_7, ulong param_8);
	/* 1002DD00 */ void GetProps(float* param_1, float* param_2, float* param_3, ulong* param_4, float* param_5, float* param_6, float* param_7, ulong* param_8);
	/* 1002DD70 */ uint Render();
};

#endif