#ifndef C_MAG_LIGHT
#define C_MAG_LIGHT

#include <globals.h>
#include <vector>

#include "d3d8.h"

#include "MagSingleton.h"

struct Light {
	int unkn_00;
	D3DLIGHT8 light;
};

class __declspec(dllexport) cMagLight : public MagSingleton<cMagLight> {
public:
	/* 1008D800 */ cMagLight();
	/* 1008D860 */ virtual ~cMagLight();
	/* 1008D8C0 */ bool GetDynamicLight(int param_1, D3DLIGHT8& param_2);
	/* 1008D920 */ int AddDynamicLight(D3DLIGHT8 param_1);
	/* 1008DB90 */ void ClearDynamicLights();
private:
	/* 0x04 */ std::vector<Light> lights;
};

#endif