#include "AIControlPoint.h"

/* 419BA0-419BA1 00001	*/
void AIControlPoint::OnActivate() {
}

/* 43CE20-43CE39 00019	*/
AIControlPoint::AIControlPoint() {
	unk_2658 = true;
}

/* 43CE60-43CE6B 0000B	*/
AIControlPoint::~AIControlPoint() {
}

/* 43CE70-43CECA 0005A	*/
void* AIControlPoint::EXP() {
	return new AIControlPoint();
}

/* 43CED0-43CED8 00008	*/
void AIControlPoint::OnActivateLevel() {
	enableRendering = false;
}

/* 43CEE0-43CEE7 00007	*/
bool AIControlPoint::FUN0043cee0() {
	return unk_2658;
}

/* 43CEF0-43CEFD 0000D	*/
void AIControlPoint::FUN0043cef0(bool param_1) {
	unk_2658 = param_1;
}