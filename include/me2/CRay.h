#ifndef _C_RAY
#define _C_RAY

#include <globals.h>
#include <d3dx8math.h>

class DLLEXPORT CRay {
public:
	/* 1000B470-1000B474 00004	*/
	D3DXVECTOR3 const& Vector() const {
		return vector;
	}

	/* 10010900-10010933 00033	*/
	float Length() const {
		if (!computedLength) {
			D3DXVECTOR3* fVar1 = const_cast<D3DXVECTOR3*>(&vector);
			*const_cast<float*>(&length) = D3DXVec3Length(fVar1);
			*const_cast<bool*>(&computedLength) = true;
		}
		return length;
	}

	/* 10010940-100109B3 00073	*/
	D3DXVECTOR3 End(float param_1) {
		return param_1 * Normal() + origin;
	}

	/* 100109C0-10010A42 00082	*/
	D3DXVECTOR3 Closest(D3DXVECTOR3 const& param_1) {
		float fVar2 = Distance(param_1);
		return param_1 - fVar2 * Normal();
	}

	/* 10010A50-10010A7A 0002A	*/
	void SetVector(D3DXVECTOR3 const& param_1) {
		vector = param_1;
		Reset();
	}

	/* 10010A80-10010AAA 0002A	*/
	void SetOrigin(D3DXVECTOR3 const& param_1) {
		origin = param_1;
		Reset();
	}

	/* 10010AB0-10010AB4 00004	*/
	D3DXVECTOR3 const& Origin()const {
		return origin;
	}

	/* 10010AC0-10010B1A 0005A	*/
	float CRay::D()const {
		if (!computedD) {
			*const_cast<float*>(&DValue) = -D3DXVec3Dot(&Origin(), &Normal());
			*const_cast<bool*>(&computedD) = true;
		}
		return DValue;
	}

	/* 10010B20-10010B59 00039	*/
	D3DXVECTOR3& Normal() const {
		if (!computedNormalizedVector) {
			*const_cast<D3DXVECTOR3*>(&normalizeVector) = vector;
			D3DXVec3Normalize(const_cast<D3DXVECTOR3*>(&normalizeVector), &normalizeVector);
			*const_cast<bool*>(&computedNormalizedVector) = true;
		}

		return (D3DXVECTOR3&) normalizeVector;
	}

	/* 10010B60-10010CA2 00142	*/
	bool CRay::Intersect(CRay& param_1, float& param_2) const {
		param_2 = 0.0f;
		float fVar1 = D3DXVec3Dot(&Normal(), &param_1.Normal());
		if (fVar1 == 0.0f) {
			return false;
		}
		float fVar2 = D3DXVec3Dot(&Normal(), &param_1.Origin());
		param_2 = -((D() + fVar2) / fVar1);
		return true;
	}

	/* 10010CB0-10010E57 001A7	*/
	float Distance(D3DXVECTOR3 const& param_1) const {
		D3DXVECTOR3 local_40 = Normal() * -1.0f;
		float fStack_44;
		bool t = Intersect(CRay(param_1, local_40), fStack_44);
		return fStack_44;
	}

	/* 10010E60-10010E81 00021	*/
	D3DXVECTOR3 End() const {
		return origin + vector;
	}

protected:
	/* 10010E90-10010E9F 0000F	*/
	void Reset() {
		computedD = false;
		unk_29 = false;
		computedNormalizedVector = false;
		computedLength = false;
	}

public:
	/* 100BC850 */ CRay();
	/* 100BC870 */ CRay(D3DXVECTOR3 const& param_1, D3DXVECTOR3 const& param_2);
	/* 100BC8C0 */ virtual ~CRay();

public:
	/* 0x04 */ D3DXVECTOR3 origin; 
	/* 0x10 */ D3DXVECTOR3 vector; 
	/* 0x1c */ D3DXVECTOR3 normalizeVector; 
	/* 0x28 */ bool computedNormalizedVector; 
	/* 0x29 */ bool unk_29; 
	/* 0x2a */ bool computedD; 
	/* 0x2b */ bool computedLength; 
	/* 0x2c */ float DValue; 
	/* 0x30 */ float length; 
};

#endif