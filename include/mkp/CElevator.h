#ifndef _C_ELEVATOR
#define _C_ELEVATOR

#include <globals.h>
#include "_Platform.h"

struct CElevatorChunkData {
	/* 0x00 */ float speedValue;
	/* 0x04 */ float movementUpdateInverval;
	/* 0x08 */ uchar field_0x08[0x0c-0x08];
	/* 0x0c */ BOOL shouldPlayMoveSound;
	/* 0x10 */ int minSoundRange;
	/* 0x14 */ int maxSoundRange;
	/* 0x18 */ char soundFilePath[200];
};

struct CElevatorSaveData {
	/* 0x00 */ D3DXMATRIX rotMatrix;
	/* 0x40 */ D3DXVECTOR3 position;
	/* 0x4c */ bool unk_4c;
	/* 0x4d */ bool reachedDestPos;
	/* 0x50 */ int nextDestinationIndex;
};

class CElevator : public _Platform {
public:
	/* 41AFD0 */ CElevator();
	/* 41B070 */ virtual ~CElevator();
	/* 41B100 */ void* EXP();
	/* 41B160 */ void OnFrame();
	/* 41B320 */ void OnUpdateMenuSettings();
	/* 41B350 */ void OnActivate();
	/* 41B360 */ void OnDestinationPos(D3DXVECTOR3 param_1);
	/* 41B3B0 */ void OnAction();
	/* 41B4E0 */ void OnCollisionObject(cMagMeshObject* param_1);
	/* 41B500 */ void OnAttachChild(cMagMeshObject* param_1);
	/* 41B530 */ void OnDetachChild(cMagMeshObject* param_1);
	/* 41B560 */ void OnActivateLevel();
	/* 41B600 */ void OnCrash();
	/* 41B630 */ void OnLoadChunk(_ED_CHUNK param_1, std::ifstream& param_2);
	/* 41B940 */ void Save(std::ostream& param_1);
	/* 41BA60 */ void Load(std::ifstream& param_1, _ED_CHUNK param_2);

private:

	/* 0x2658 */ CElevatorChunkData chunkData;
	/* 0x2738 */ float* destPositionsBuffer;
	/* 0x273c */ std::vector<D3DXVECTOR3> destinationPositions;
	/* 0x274c */ bool hasPlayer;
	/* 0x2750 */ int nextDestinationIndex;
	/* 0x2754 */ int destPositionsCount;
	/* 0x2758 */ float elevatorSpeedValue;
	/* 0x275c */ bool shouldUpdateMovement;
	/* 0x275d */ bool unk_275d;
	/* 0x2760 */ float lastUpdateTime;
	/* 0x2764 */ int elevatorMoveSoundID;
	/* 0x2768 */ bool unk_2768;
	/* 0x2769 */ bool reachedDestPos;
};

STATIC_ASSERT(sizeof(CElevator) == 0x2770);

#endif