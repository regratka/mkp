#ifndef PG_VEC2
#define PG_VEC2

#include <globals.h>

class pgVec2 {
public:
	/* 1000A9C0 */ float* operator[](uint param_1);
	/* 1000A9D0 */ pgVec2();
	/* 1000A9E0 */ pgVec2(float param_1, float param_2);
	/* 1000AA00 */ pgVec2 operator+(uint* param_1);
	/* 1000AA20 */ pgVec2* operator+=(pgVec2* param_1);
	/* 1000AA40 */ pgVec2 operator-(float* param_1);
	/* 1000AA60 */ pgVec2* operator-=(pgVec2* param_1);
	/* 1000AA80 */ pgVec2* operator/=(float param_1);
	/* 1000AAA0 */ pgVec2* add(pgVec2* param_1, pgVec2* param_2);
	/* 1000AAC0 */ pgVec2* addScaled(pgVec2* param_1, float param_2, pgVec2* param_3);
	/* 1000AAF0 */ bool almostEqual(pgVec2* param_1, float param_2);
	/* 1000AB60 */ pgVec2* combine(float param_1, pgVec2* param_2, float param_3, pgVec2* param_4);
	/* 1000AB90 */ pgVec2(pgVec2* param_1);
	/* 1000ABB0 */ float sqrDistance(pgVec2* param_1);
	/* 1000ABD0 */ float dot(pgVec2* param_1);
	/* 1000ABF0 */ bool equal(pgVec2* param_1);
	/* 1000AC20 */ void negate();
	/* 1000AC30 */ pgVec2* operator*=(float param_1);
	/* 1000AC50 */ pgVec2* scale(float param_1, pgVec2* param_2);
	/* 1000AC70 */ pgVec2* scaleBy(pgVec2* param_1);
	/* 1000AC90 */ void set(float param_1, float param_2);
	/* 1000ACA0 */ void set(float* param_1);
	/* 1000ACC0 */ pgVec2* sub(pgVec2* param_1, pgVec2* param_2);
	/* 100817C0 */ static float cosine(pgVec2* param_1, Axis param_2);
	/* 10081810 */ static float cosine(pgVec2* param_1, pgVec2* param_2);
	/* 10081860 */ float distance(pgVec2* param_1);
	/* 10081890 */ float length();
	/* 100818B0 */ float normalize();
};

#endif