#include "CBalon.h"

/* 419BA0-419BA1 00001	*/
void CBalon::OnActivate() {
}

/* 419BA0-419BA1 00001	*/
void CBalon::OnActivateLevel() {
}

/* 4400B0-440139 00089	*/
CBalon::CBalon() {
	pointsLoadBuffer = NULL;
	visitedPoints = 0;
	routePoints.clear();
}

/* 440160-44019C 0003C	*/
CBalon::~CBalon() {
}

/* 4401A0-4401FA 0005A	*/
void* CBalon::EXP() {
	return new CBalon();
}

/* 440200-44021F 0001F	*/
void CBalon::OnAction() {
	EnableCallHandler("OnFrame");
	SetSpeedValue(200.0f);
}

/* 440220-4402F6 000D6	*/
void CBalon::OnFrame() {
	if (routePointsAmount <= 0) {
		return;
	}

	D3DXVECTOR3 destPos(routePoints[visitedPoints].x, routePoints[visitedPoints].y, routePoints[visitedPoints].z);
	destPos.y = GetPosition().y;
	SetDestinationPos(destPos, 200.0f);
	D3DXVECTOR3 auStack18 = GetPosition();
	D3DXVECTOR3 local_28 = destPos - auStack18;
	D3DXVec3Normalize(&local_28, &local_28);
	SetDestinationDir(local_28, 2);
}

/* 440300-440343 00043	*/
void CBalon::OnDestinationPos(D3DXVECTOR3 param_1) {
	visitedPoints++;
	if (visitedPoints >= routePointsAmount) {
		visitedPoints = 0;
		DisableCallHandler("OnFrame");
		SetSpeedValue(0.0f);
	}
}

/* 440350-44060A 002BA	*/
void CBalon::OnLoadChunk(_ED_CHUNK param_1, std::ifstream& param_2) {
	if (param_1.chunkType != 32) {
		return;
	}
	param_2.read((char*) &routePointsAmount, 4);
	pointsLoadBuffer = new float[routePointsAmount*3];
	
	param_2.read((char*) pointsLoadBuffer, routePointsAmount*sizeof(D3DXVECTOR3));
	for (int index = 0; index < routePointsAmount; index++) {
		routePoints.push_back(D3DXVECTOR3(pointsLoadBuffer[index*3],pointsLoadBuffer[index*3+1], pointsLoadBuffer[index*3+2]));
	}

	delete[] pointsLoadBuffer;
	pointsLoadBuffer = NULL;
}

