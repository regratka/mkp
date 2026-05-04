#include "cMagLight.h"

/* 1008D800-1008D859 00059	*/
cMagLight::cMagLight(): MagSingleton<cMagLight>(this) {
	lights.clear();
}

/* 1008D860-1008D8BE 0005E	*/
cMagLight::~cMagLight() {
	lights.clear();
}

/* 1008D8C0-1008D912 00052	*/
bool cMagLight::GetDynamicLight(int param_1, D3DLIGHT8& param_2) {
	if (lights.empty()) {
		return false;
	}
	if (param_1 <= 0) {
		param_1 = 1;
	}
	param_2 = lights[param_1-1].light;

	return true;;
}

/* 1008D920-1008DB84 00264	*/
int cMagLight::AddDynamicLight(D3DLIGHT8 param_1) {
	Light light;
	light.light = param_1;
	int lastID = 0;
	if (!lights.empty()) {
		lastID = lights[lights.size()-1].unkn_00;
		if (lastID == -1) {
			lastID = 0;
		}
	}
	
	light.unkn_00 = lastID+1; 
	lights.push_back(light);
	return light.unkn_00;
}

/* 1008DB90-1008DBD6 00046	*/
void cMagLight::ClearDynamicLights() {
	lights.clear();
}

