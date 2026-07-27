#ifndef PG_VEC2
#define PG_VEC2

#include <globals.h>

class DLLEXPORT pgVec2 {

public:
	enum Axis {
		AxisX,
		AxisY
	};

	/* 1000A9C0-1000A9CA 0000A	*/
	float const & operator[](uint param_1) const {
		return _vec[param_1];
	}

	/* 1000A9C0-1000A9CA 0000A	*/
	float& operator[](uint param_1) {
		return _vec[param_1];
	}

	/* 1000A9D0-1000A9E0 00010	*/
	pgVec2() {
		_vec[0] = 0.0f;
		_vec[1] = 0.0f;
	}

	/* 1000A9E0-1000A9F2 00012	*/
	pgVec2(float param_1, float param_2) {
		_vec[0] = param_1;
		_vec[1] = param_2;
	}

	/* 1000AA00-1000AA11 00011	*/
	pgVec2 operator+() const {
		return pgVec2(*this);
	}

	/* 1000AA20-1000AA38 00018	*/
	pgVec2& pgVec2::operator+=(pgVec2 const& param_1) {
		_vec[0] += param_1._vec[0];
		_vec[1] += param_1._vec[1];
		return *this;
	}

	/* 1000AA40-1000AA55 00015	*/
	pgVec2 pgVec2::operator-() const {
		return pgVec2(-_vec[0], -_vec[1]);
	}

	/* 1000AA60-1000AA78 00018	*/
	pgVec2& pgVec2::operator-=(pgVec2 const & param_1) {
		_vec[0] -= param_1._vec[0];
		_vec[1] -= param_1._vec[1];
		return *this;
	}

	/* 1000AA80-1000AA97 00017	*/
	pgVec2& pgVec2::operator/=(float param_1) {
		_vec[0] /= param_1;
		_vec[1] /= param_1;
		return *this;;
	}

	/* 1000AAA0-1000AABC 0001C	*/
	pgVec2& add(pgVec2 const& param_1, pgVec2 const& param_2) {
		_vec[0] = param_1._vec[0] + param_2._vec[0];
		_vec[1] = param_1._vec[1] + param_2._vec[1];
		return *this;
	}

	/* 1000AAC0-1000AAE4 00024	*/
	pgVec2& addScaled(pgVec2 const& param_1, float param_2, pgVec2 const& param_3) {
		_vec[0] = param_2 * param_3._vec[0] + param_1._vec[0];
		_vec[1] = param_2 * param_3._vec[1] + param_1._vec[1];
		return *this;
	}

	/* 1000AAF0-1000AB52 00062	*/
	bool almostEqual(pgVec2 const& param_1, float param_2) const {
		float fVar1 = _vec[0] - param_1._vec[0];
		float fVar2 = _vec[1] - param_1._vec[1];
		return fVar1 > -param_2 && fVar1 < param_2 && fVar2 > -param_2 && fVar2 < param_2;

	}

	/* 1000AB60-1000AB90 00030	*/
	pgVec2& pgVec2::combine(float param_1, pgVec2 const& param_2, float param_3, pgVec2 const& param_4) {
		_vec[0] = param_3 * param_4._vec[0] + param_1 * param_2._vec[0];
		_vec[1] = param_3 * param_4._vec[1] + param_1 * param_2._vec[1];
		return *this;
	}


	/* 1000AB90-1000ABA3 00013	*/
	pgVec2(pgVec2 const& param_1) {
		_vec[0] = param_1._vec[0];
		_vec[1] = param_1._vec[1];
	}

	/* 1000AB90-1000ABA3 00013	*/
	pgVec2(float* param_1) {
		_vec[0] = param_1[0];
		_vec[1] = param_1[1];
	}

	/* 1000AB90-1000ABA3 00013	*/
	pgVec2& operator=(pgVec2 const & param_1) {
		_vec[0] = param_1[0];
		_vec[1] = param_1[1];
		return *this;
	}

	/* 1000AB90-1000ABA3 00013	*/
	pgVec2& copy(pgVec2 const & param_1) {
		_vec[0] = param_1[0];
		_vec[1] = param_1[1];
		return *this;
	}

	/* 1000ABB0-1000ABCF 0001F	*/
	float pgVec2::sqrDistance(pgVec2 const& param_1) const {
		float fVar1 = _vec[1] - param_1._vec[1];
		float fVar2 = _vec[0] - param_1._vec[0];
		return fVar1 * fVar1 + fVar2 * fVar2;
	}

	/* 1000ABD0-1000ABE3 00013	*/
	float pgVec2::dot(pgVec2 const & param_1) const {
		return param_1._vec[0] * _vec[0] + param_1._vec[1] * _vec[1];
	}

	/* 1000ABF0-1000AC19 00029	*/
	bool pgVec2::equal(pgVec2 const & param_1) const {
		return _vec[0] == param_1._vec[0] && _vec[1] == param_1._vec[1];
	}

	/* 1000AC20-1000AC2F 0000F	*/
	void pgVec2::negate() {
		_vec[0] = -_vec[0];
		_vec[1] = -_vec[1];
	}

	/* 1000AC30-1000AC47 00017	*/
	pgVec2& pgVec2::operator*=(float param_1) {
		_vec[0] *= param_1;
		_vec[1] *= param_1;
		return *this;
	}

	/* 1000AC30-1000AC47 00017	*/
	pgVec2& scale(float param_1) {
		_vec[0] *= param_1;
		_vec[1] *= param_1;
		return *this;
	}

	/* 1000AC50-1000AC6B 0001B	*/
	pgVec2& pgVec2::scale(float param_1, pgVec2 const & param_2) {
		_vec[0] = param_2._vec[0] * param_1;
		_vec[1] = param_2._vec[1] * param_1;
		return *this;
	}

	/* 1000AC70-1000AC88 00018	*/
	pgVec2& pgVec2::scaleBy(pgVec2 const & param_1) {
		_vec[0] = _vec[0] * param_1._vec[0];
		_vec[1] = _vec[1] * param_1._vec[1];
		return *this;
	}

	/* 1000AC90-1000ACA0 00010	*/
	void pgVec2::set(float param_1, float param_2) {
		_vec[0] = param_1;
		_vec[1] = param_2;
	}

	/* 1000ACA0-1000ACB1 00011	*/
	void pgVec2::set(float const * const param_1) {
		_vec[0] = param_1[0];
		_vec[1] = param_1[1];
	}

	/* 1000ACC0-1000ACDC 0001C	*/
	pgVec2& pgVec2::sub(pgVec2 const & param_1, pgVec2 const & param_2) {
		_vec[0] = param_1._vec[0] - param_2._vec[0];
		_vec[1] = param_1._vec[1] - param_2._vec[1];
		return *this;
	}

	/* 100817C0 */ static float cosine(pgVec2 const & param_1, Axis param_2);
	/* 10081810 */ static float cosine(pgVec2 const & param_1, pgVec2 const & param_2);
	/* 10081860 */ float distance(pgVec2 const & param_1)const;
	/* 10081890 */ float length()const;
	/* 100818B0 */ float normalize();

private:
	/* 0x00 */ float _vec[2];
};

STATIC_ASSERT(sizeof(pgVec2) == 0x08);

#endif