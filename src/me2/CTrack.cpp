#include "CTrack.h"

/* 100B8220-100B83DA 001BA	*/
CTrack::CTrack() {
	trackPointCoords = 0;
	dataVector.reserve(1024);
}

/* 100B83E0-100B8502 00122	*/
CTrack::~CTrack() {
}

/* 100B8510-100B87A4 00294	*/
void CTrack::Load(std::ifstream& param_1) {
	uchar trackNameLength;
	param_1.read((char*)&trackNameLength, 1);
	param_1.read(this->objectName, trackNameLength);
	this->objectName[trackNameLength] = '\0';
	param_1.read((char*)&this->trackPointCoords, 4);
	int trackPointsAmount = 0;
	param_1.read((char*)&trackPointsAmount, 4);

	int fullCoordsAmount = (trackPointCoords * 2 + 1) * trackPointsAmount;
	D3DXVECTOR3* pointCoordsBuffer = new D3DXVECTOR3[fullCoordsAmount];
	param_1.read((char*)pointCoordsBuffer, fullCoordsAmount * sizeof(D3DXVECTOR3));
	
	int* coordsTypesBuffer = new int[trackPointsAmount];
	param_1.read((char*)coordsTypesBuffer, trackPointsAmount * sizeof(int));

	for (int trackPointIndex = 0; trackPointIndex < trackPointsAmount; trackPointIndex++) {
		CTrackData trackData;
		trackData.position = pointCoordsBuffer[trackPointIndex];
		trackData.unkn_2c = coordsTypesBuffer[trackPointIndex];
		for (int pointCoordIndex = 0; pointCoordIndex < this->trackPointCoords; pointCoordIndex++) {
			trackData.vector1.push_back(pointCoordsBuffer[(pointCoordIndex+1) * trackPointsAmount + trackPointIndex]); // start pos
			trackData.vector2.push_back(pointCoordsBuffer[(this->trackPointCoords + pointCoordIndex+1) * trackPointsAmount + trackPointIndex]); // end pos
		}
		this->dataVector.push_back(trackData);
		trackData.vector1.clear();
		trackData.vector2.clear();
	}

	delete[] pointCoordsBuffer;
	delete[] coordsTypesBuffer;
}

