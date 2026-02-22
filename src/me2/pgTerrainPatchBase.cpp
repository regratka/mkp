#include "pgTerrainPatchBase.h"

/* 1000ACE0-1000ACE5 00005	*/
int pgTerrainPatchBase::render(uchar param_1) {
	return 0;
}

/* 1000ACF0-1000ACFD 0000D	*/
void pgTerrainPatchBase::setRendered(bool param_1) {
}

/* 1000AD00-1000AD07 00007	*/
bool pgTerrainPatchBase::getRendered() {
	return 0;
}

/* 1000AD10-1000AD1A 0000A	*/
void pgTerrainPatchBase::setVisFlags(int param_1) {
}

/* 1000AD20-1000AD24 00004	*/
int pgTerrainPatchBase::getVisFlags() {
	return 0;
}

/* 1000AD30-1000AD3A 0000A	*/
void pgTerrainPatchBase::setMaster(pgTerrain* param_1) {
}

/* 1000AD40-1000AD47 00007	*/
float pgTerrainPatchBase::getCurrentError() {
	return 0;
}

/* 1000AD50-1000AD57 00007	*/
int pgTerrainPatchBase::getCurrentTessellation() {
	return 0;
}

/* 1000AD60-1000AD67 00007	*/
int pgTerrainPatchBase::getNewTessellation() {
	return 0;
}

/* 1000AD70-1000AD77 00007	*/
int pgTerrainPatchBase::getRealTessellation() {
	return 0;
}

/* 1000AD80-1000AD87 00007	*/
int pgTerrainPatchBase::getNumIndices() {
	return 0;
}

/* 1000AD90-1000AD97 00007	*/
int pgTerrainPatchBase::getNumVertices() {
	return 0;
}

/* 1000ADA0-1000ADA7 00007	*/
PATCHVERTEX* pgTerrainPatchBase::getVertices() {
	return 0;
}

/* 1000ADB0-1000ADB4 00004	*/
bool pgTerrainPatchBase::isVisible() {
	return 0;
}

/* 1000ADC0-1000ADC4 00004	*/
bool pgTerrainPatchBase::isActive() {
	return 0;
}

/* 1000ADD0-1000ADE4 00014	*/
float pgTerrainPatchBase::getProjectedError(int param_1) {
	return 0;
}

/* 1000ADF0-1000ADFD 0000D	*/
void pgTerrainPatchBase::setTessellation(int param_1) {
}

/* 1000AE00-1000AE07 00007	*/
pgTerrainPatchBase* pgTerrainPatchBase::getNextActive() {
	return 0;
}

/* 1000AE10-1000AE14 00004	*/
int pgTerrainPatchBase::getGridPosX() {
	return 0;
}

/* 1000AE20-1000AE24 00004	*/
int pgTerrainPatchBase::getGridPosY() {
	return 0;
}

/* 1000AE30-1000AE3D 0000D	*/
void pgTerrainPatchBase::setFlagActive(bool param_1) {
}

/* 1000AE40-1000AE47 00007	*/
bool pgTerrainPatchBase::getFlagActive() {
	return 0;
}

/* 1000AE50-1000AE71 00021	*/
void pgTerrainPatchBase::setPosition(pgVec3* param_1) {
}

/* 1000AE80-1000AE8C 0000C	*/
int pgTerrainPatchBase::getAddLayerFlag(int param_1) {
	return 0;
}

/* 1000AE90-1000AE97 00007	*/
pgTerrainPatchBase* pgTerrainPatchBase::getLeft() {
	return 0;
}

/* 1000AEA0-1000AEA7 00007	*/
pgTerrainPatchBase* pgTerrainPatchBase::getRight() {
	return 0;
}

/* 1000AEB0-1000AEB7 00007	*/
pgTerrainPatchBase* pgTerrainPatchBase::getBottom() {
	return 0;
}

/* 1000AEC0-1000AEC7 00007	*/
pgTerrainPatchBase* pgTerrainPatchBase::getTop() {
	return 0;
}

/* 1000AED0-1000B150 00280	*/
pgTerrainPatchBase::pgTerrainPatchBase(pgTerrainPatchBase* param_1) {
}

/* 1000B150-1000B3C5 00275	*/
pgTerrainPatchBase* pgTerrainPatchBase::operator=(pgTerrainPatchBase* param_1) {
	return 0;
}

/* 1000B3D0-1000B3F0 00020	*/
void pgTerrainPatchBase::addIndex(ushort param_1) {
}

/* 1000B3F0-1000B411 00021	*/
void pgTerrainPatchBase::addLastIndexAgain() {
}

/* 1007BA40-1007BBB1 00171	*/
pgTerrainPatchBase::pgTerrainPatchBase(pgTerrain* param_1, int param_2, int param_3) {
}

/* 1007BBC0-1007BBEB 0002B	*/
void pgTerrainPatchBase::setNeighbors(pgTerrainPatchBase* param_1, pgTerrainPatchBase* param_2, pgTerrainPatchBase* param_3, pgTerrainPatchBase* param_4) {
}

/* 1007BBF0-1007BCA9 000B9	*/
void pgTerrainPatchBase::init() {
}

/* 1007BCB0-1007BD18 00068	*/
void pgTerrainPatchBase::deinit() {
}

/* 1007BD20-1007BD4E 0002E	*/
void pgTerrainPatchBase::addToActiveList() {
}

/* 1007BD50-1007BD9E 0004E	*/
void pgTerrainPatchBase::removeFromActiveList() {
}

/* 1007BDA0-1007BDD3 00033	*/
int pgTerrainPatchBase::fillBaseVertices(PATCHVERTEX* param_1) {
	return 0;
}

/* 1007BDE0-1007BE01 00021	*/
void pgTerrainPatchBase::setScale(pgVec3* param_1) {
}

/* 1007BE10-1007BE27 00017	*/
void pgTerrainPatchBase::setHeightMapPosition(int param_1, int param_2) {
}

/* 1007BE30-1007BE49 00019	*/
void pgTerrainPatchBase::setRealTessellation(int param_1) {
}

/* 1007BE50-1007BF90 00140	*/
bool pgTerrainPatchBase::updateTessellation() {
	return 0;
}

/* 1007BFA0-1007BFC8 00028	*/
bool pgTerrainPatchBase::checkVisibility(uchar param_1, pgPlane* param_2) {
	return 0;
}

/* 1007BFD0-1007BFFF 0002F	*/
void pgTerrainPatchBase::setVisible(bool param_1) {
}

/* 1007C000-1007C31C 0031C	*/
void pgTerrainPatchBase::updateVisibility(uchar param_1, pgPlane* param_2) {
}

/* 1007C320-1007C3B8 00098	*/
void pgTerrainPatchBase::calcMinMaxY() {
}

/* 1007C3C0-1007C4D4 00114	*/
void pgTerrainPatchBase::calcMinMax() {
}

/* 1007C4E0-1007C5D1 000F1	*/
void pgTerrainPatchBase::updateProjectedErrors(uchar param_1) {
}

/* 1007C5E0-1007C5F7 00017	*/
void pgTerrainPatchBase::calcErrors() {
}

/* 1007C600-1007C8F9 002F9	*/
void pgTerrainPatchBase::calcError(int param_1) {
}

/* 1007C900-1007C936 00036	*/
float pgTerrainPatchBase::getExactTessellation() {
	return 0;
}

/* 1007C940-1007C97B 0003B	*/
int pgTerrainPatchBase::getPowerTwo(int param_1) {
	return 0;
}

/* 1007C9A0-1007CA8B 000EB	*/
void pgTerrainPatchBase::createTessellation(int param_1, int param_2, int param_3, int param_4, int param_5) {
}

/* 1007CA90-1007CABD 0002D	*/
void pgTerrainPatchBase::reduceShapeTo(int param_1, PATCHVERTEX* param_2) {
}

/* 1007CAC0-1007CE2B 0036B	*/
void pgTerrainPatchBase::makeBordersSimpler(PATCHVERTEX* param_1) {
}

/* 1007CE30-1007CE8A 0005A	*/
void pgTerrainPatchBase::makeSimpler(int param_1, PATCHVERTEX* param_2) {
}

/* 1007CE90-1007CEFB 0006B	*/
void pgTerrainPatchBase::calculateInbetweenVertex(int param_1, int param_2, int param_3, int param_4, int param_5, PATCHVERTEX* param_6) {
}

/* 1007CF00-1007D068 00168	*/
int pgTerrainPatchBase::calculateDiagonalVertices(int param_1, int param_2, int param_3, int param_4, int param_5, PATCHVERTEX* param_6, float* param_7, int* param_8, float* param_9, int* param_10) {
	return 0;
}

/* 1007D080-1007D398 00318	*/
void pgTerrainPatchBase::addTriangleRow(int param_1, int param_2, bool param_3, bool param_4, bool param_5, bool param_6) {
}

/* 1007D3A0-1007D713 00373	*/
void pgTerrainPatchBase::addTriangleBottomRow(int param_1, bool param_2, bool param_3) {
}

/* 1007D720-1007DAA4 00384	*/
void pgTerrainPatchBase::addTriangleTopRow(int param_1, bool param_2, bool param_3) {
}

/* 1007DAB0-1007E4DE 00A2E	*/
void pgTerrainPatchBase::addLevel4PatchTriangles(bool param_1, bool param_2, bool param_3, bool param_4) {
}

/* 1007E520-1007E568 00048	*/
float pgTerrainPatchBase::getHeight(int param_1, int param_2) {
	return 0;
}

/* 1007E570-1007E5F2 00082	*/
void pgTerrainPatchBase::getVertex(int param_1, int param_2, pgVec3* param_3) {
}

/* 1007E600-1007E652 00052	*/
void pgTerrainPatchBase::getTexCoord(int param_1, int param_2, pgVec2* param_3) {
}

/* 1007E660-1007E6A2 00042	*/
void pgTerrainPatchBase::getNormal(int param_1, int param_2, pgVec3* param_3) {
}

/* 1007E6B0-1007E7EA 0013A	*/
ushort pgTerrainPatchBase::getIndex(int param_1, int param_2) {
	return 0;
}

/* 1007E7F0-1007E80F 0001F	*/
int pgTerrainPatchBase::getNewTessellationSafe() {
	return 0;
}

