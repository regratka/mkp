#include "pgVec2.h"
#include "math.h"
#include "d3dx8math.h"

/* 100817C0-1008180A 0004A	*/
float pgVec2::cosine(pgVec2 const & param_1, Axis param_2) {
	float fVar1;
	switch (param_2) {
		case Axis::AxisY:
			fVar1 = acos(param_1._vec[1]);
			if (param_1._vec[0] > 0.0f) {
				return 2*D3DX_PI -fVar1 ;
			} else {
				return fVar1;
			}
		case Axis::AxisX:
		default:
			fVar1 = acos(param_1._vec[0]);
			if (param_1._vec[1] < 0.0f) {
				return 2*D3DX_PI -fVar1 ;
			} else {
				return fVar1;
			}
	}
}

/* 10081810-1008185B 0004B	*/
float pgVec2::cosine(pgVec2 const & param_1, pgVec2 const & param_2) {
	float fVar1 = cosine(param_1,Axis::AxisX);
	float fVar2 = cosine(param_2,Axis::AxisX);
	fVar2 = fVar2 - fVar1;
	if (fVar2 > D3DX_PI) {
		return fVar2 - 2*D3DX_PI;
	}
	if (fVar2 < -D3DX_PI) {
		return fVar2 + 2*D3DX_PI;
		
	}
	return fVar2;
}

/* 10081860-10081881 00021	*/
float pgVec2::distance(pgVec2 const & param_1)const {
	float fVar1 = _vec[1] - param_1._vec[1];
	float fVar2 = _vec[0] - param_1._vec[0];
	return sqrt(fVar1 * fVar1 + fVar2 * fVar2);
}

/* 10081890-100818A6 00016	*/
float pgVec2::length()const {
	return sqrt(_vec[1] * _vec[1] + _vec[0] * _vec[0]);
}

/* 100818B0-100818F7 00047	*/
float pgVec2::normalize() {
	
	if ( _vec[1] * _vec[1] + _vec[0] * _vec[0] != 1.0) {
		float fVar1 = _vec[1] * _vec[1] + _vec[0] * _vec[0];
		if (fVar1 > 0.00001f) {
			fVar1 = sqrt(fVar1);
			_vec[0] = _vec[0] / fVar1;
			_vec[1] = _vec[1] / fVar1;
			return fVar1;
		}
		return 0.0f;
	}
	return _vec[1] * _vec[1] + _vec[0] * _vec[0];
}

