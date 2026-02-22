#include "pgTerrain.h"

/* 1000C2A0-1000C2A4 00004	*/
pgTerrainPatchBase** pgTerrain::getActiveList() {
	return 0;
}

/* 1000C2B0-1000C2BA 0000A	*/
void pgTerrain::setMaxError(float param_1) {
}

/* 1000C2C0-1000C2C4 00004	*/
float pgTerrain::getMaxError() {
	return 0;
}

/* 1000C2D0-1000C2D4 00004	*/
void pgTerrain::addBufferCreateCount() {
}

/* 1000C2E0-1000C2F1 00011	*/
void pgTerrain::setNumPatches(int param_1, int param_2) {
}

/* 1000C300-1000C304 00004	*/
int pgTerrain::GetNumTris() {
	return 0;
}

/* 1000C310-1000C317 00007	*/
bool pgTerrain::getMergePatches() {
	return 0;
}

/* 1000C320-1000C32D 0000D	*/
void pgTerrain::setMergePatches(bool param_1) {
}

/* 1000C330-1000C337 00007	*/
cMagFrustumCull* pgTerrain::GetFrustumCull() {
	return 0;
}

/* 1000C340-1000C5B4 00274	*/
pgTerrain::pgTerrain(pgTerrain* param_1) {
}

/* 1000C5C0-1000C960 003A0	*/
pgTerrain* pgTerrain::operator=(pgTerrain* param_1) {
	return 0;
}

/* 1000C960-1000C98B 0002B	*/
float pgTerrain::getHeight(int param_1, int param_2) {
	return 0;
}

/* 1000C990-1000C9CB 0003B	*/
void pgTerrain::getTexCoord(int param_1, int param_2, pgVec2* param_3) {
}

/* 1000C9D0-1000C9FF 0002F	*/
void pgTerrain::getNormal(int param_1, int param_2, pgVec3* param_3) {
}

/* 10083C90-10083DFE 0016E	*/
pgTerrain::pgTerrain() {
}

/* 10083E00-10083EED 000ED	*/
pgTerrain::~pgTerrain() {
}

/* 10083EF0-10083F0F 0001F	*/
void pgTerrain::setHeightMap(pgImage* param_1) {
}

/* 10083F10-10083F4E 0003E	*/
void pgTerrain::setGrassMap(pgImage* param_1) {
}

/* 10083F50-10083F93 00043	*/
int pgTerrain::GetColorGrassMap(int param_1, int param_2) {
	return 0;
}

/* 10083FA0-10083FC1 00021	*/
void pgTerrain::setPatchSize(float param_1, float param_2, float param_3) {
}

/* 10083FD0-100841DD 0020D	*/
void pgTerrain::build() {
}

/* 100841E0-1008424E 0006E	*/
pgTerrainPatchBase* pgTerrain::createPatch(int param_1, int param_2) {
	return 0;
}

/* 10084250-10084F3D 00CED	*/
void pgTerrain::update(uchar param_1) {
}

/* 10084F40-10084F5B 0001B	*/
void pgTerrain::setD3DVecFromVec3(_D3DVECTOR* param_1, pgVec3* param_2) {
}

/* 10084F60-10085151 001F1	*/
void pgTerrain::createClippingPlanes(pgPlane* param_1) {
}

/* 100851D0-1008573B 0056B	*/
void pgTerrain::renderSplit() {
}

/* 10085740-10085835 000F5	*/
void pgTerrain::checkBuffers() {
}

/* 10085840-100859FF 001BF	*/
void pgTerrain::addPass(float param_1, float param_2) {
}

/* 10085A00-10085A5C 0005C	*/
void pgTerrain::fillPassInfo(MultiPassInfo* param_1, float param_2, float param_3) {
}

/* 10085A60-10085AC6 00066	*/
void pgTerrain::CreateFrustumCull() {
}

/* 10085AD0-10085CC0 001F0	*/
bool pgTerrain::projectDown(pgVec3* param_1, pgVec3* param_2) {
	return 0;
}

/* 10085CC0-10085D1C 0005C	*/
float pgTerrain::getHeightDif(int param_1, int param_2, int param_3, int param_4) {
	return 0;
}

/* 10085D20-10086049 00329	*/
void pgTerrain::createNormals() {
}

/* 10086050-10086592 00542	*/
uint pgTerrain::Pick(float param_1, float param_2, float param_3, float param_4, float param_5, float param_6, float* param_7, uint param_8, int param_9) {
	return 0;
}

