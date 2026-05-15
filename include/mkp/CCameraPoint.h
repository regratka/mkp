#ifndef _C_CAMERA_POINT
#define _C_CAMERA_POINT

#include <globals.h>

class CCameraPoint {
public:
	/* 40E7D0 */ CCameraPoint();
	/* 40E810 */ uchar scalar_destructor(uchar param_1);
	/* 40E830 */ ~CCameraPoint();
	/* 40E840 */ void OnActivate();
	/* 40EA60 */ uchar OnActivateLevel(uchar param_1);
	/* 40EAA0 */ uchar OnInputMouse(uchar param_1, uchar param_2, uchar param_3, uchar param_4);
	/* 40EC33 */ uchar FUN0040ec33(uchar param_1, uchar param_2, uchar param_3, uchar param_4, uint param_5, uint param_6, uint param_7);
};

#endif