#ifndef _C_PARTICLE_EMITTER_TOKEN
#define _C_PARTICLE_EMITTER_TOKEN

#include <globals.h>

class CParticleEmitterToken {
public:
	/* 1001B450 */ bool IsEmitRate();
	/* 1001B510 */ bool IsPosition();
	/* 1001B5D0 */ bool IsSpawnDir();
	/* 1001B690 */ bool IsEmitRadius();
	/* 1001B750 */ bool IsLifeTime();
	/* 1001B810 */ bool IsNumParticles();
	/* 1001B8D0 */ bool IsLoops();
	/* 1001B990 */ bool IsLoop();
	/* 1001BA50 */ bool IsAnimFrames();
	/* 1001BB10 */ bool IsFrameWidth();
	/* 1001BBD0 */ bool IsFrameHeight();
	/* 1001BC90 */ bool IsFramesPerLine();
	/* 1001BD50 */ bool IsAnimDelay();
	/* 1001BE10 */ bool IsGravity();
	/* 1001BED0 */ bool IsSrcBlendMode();
	/* 1001BF90 */ bool IsDestBlendMode();
	/* 1001C050 */ uchar* TypeAsString(uchar* param_1);
	/* 1001C940 */ CParticleEmitterToken();
	/* 1001C980 */ CParticleEmitterToken(CParticleEmitterToken* param_1);
	/* 1001CB70 */ CParticleEmitterToken* operator=(CParticleEmitterToken* param_1);
	/* 1001CD70 */ ~CParticleEmitterToken();
	/* 1001CDC0 */ CParticleEmitterToken* scalar_destructor(uchar param_1);
};

#endif