#ifndef _C_PARTICLE_EMITTER_TOKEN
#define _C_PARTICLE_EMITTER_TOKEN

#include <globals.h>

#include "cMagUtility.h"

enum TokenType {
	REAL_NUMBER = 1,
	EQUALS = 2,
	COMMA = 3,
	OPEN_PAREN = 4,
	CLOSE_PAREN = 5,
	OPEN_BRACE = 6,
	CLOSE_BRACE = 7,
	QUOTE = 8,
	KEYWORD_PARTICLE_SYSTEM = 9,
	KEYWORD_EVENT_SEQUENCE = 10,
	KEYWORD_RANDOM = 11,
	KEYWORD_XYZ = 12,
	KEYWORD_COLOR = 13,
	KEYWORD_TEXTURE = 14,
	ALPHA_BLEND_MODE = 15,
	KEYWORD_LOOP = 16,
	KEYWORD_ANIM_FRAMES = 17,
	KEYWORD_FRAME_WIDTH = 18,
	KEYWORD_FRAME_HEIGHT = 19,
	KEYWORD_FRAMES_PER_LINE = 20,
	KEYWORD_ANIM_DELAY = 21,
	SYS_VECTOR_PROP = 22,
	SEQ_ALPHA_BLEND_MODE_PROP = 23,
	KEYWORD_FADE = 24,
	KEYWORD_SO = 25,
	KEYWORD_AT = 26,
	KEYWORD_INITIAL = 27,
	KEYWORD_FINAL = 28,
	PARTICLE_NUMERIC_PROP = 29,
	PARTICLE_VECTOR_PROP = 30,
	PARTICLE_COLOR_PROP = 31,
	SEQ_NUMERIC_PROP = 32,
	SEQ_VECTOR_PROP = 33
};

class DLLEXPORT CParticleEmitterToken : public cMagUtility {
public:
	/* 1001B450-1001B503 000B3	*/
	bool CParticleEmitterToken::IsEmitRate() {
		return unk_d4c.find("EMITRATE") != std::string::npos;
	}

	/* 1001B510-1001B5C3 000B3	*/
	bool CParticleEmitterToken::IsPosition() {
		return unk_d4c.find("POSITION") != std::string::npos;
	}

	/* 1001B5D0-1001B683 000B3	*/
	bool CParticleEmitterToken::IsSpawnDir() {
		return unk_d4c.find("SPAWNDIR") != std::string::npos;
	}

	/* 1001B690-1001B743 000B3	*/
	bool CParticleEmitterToken::IsEmitRadius() {
		return unk_d4c.find("EMITRADIUS") != std::string::npos;
	}

	/* 1001B750-1001B803 000B3	*/
	bool CParticleEmitterToken::IsLifeTime() {
		return unk_d4c.find("LIFETIME") != std::string::npos;
	}

	/* 1001B810-1001B8C3 000B3	*/
	bool CParticleEmitterToken::IsNumParticles() {
		return unk_d4c.find("NUMPARTICLES") != std::string::npos;
	}

	/* 1001B8D0-1001B983 000B3	*/
	bool CParticleEmitterToken::IsLoops() {
		return unk_d4c.find("LOOPS") != std::string::npos;
	}

	/* 1001B990-1001BA43 000B3	*/
	bool CParticleEmitterToken::IsLoop() {
		return unk_d4c.find("LOOP") != std::string::npos;
	}

	/* 1001BA50-1001BB03 000B3	*/
	bool CParticleEmitterToken::IsAnimFrames() {
		return unk_d4c.find("ANIMFRAMES") != std::string::npos;
	}

	/* 1001BB10-1001BBC3 000B3	*/
	bool CParticleEmitterToken::IsFrameWidth() {
		return unk_d4c.find("FRAMEWIDTH") != std::string::npos;
	}

	/* 1001BBD0-1001BC83 000B3	*/
	bool CParticleEmitterToken::IsFrameHeight() {
		return unk_d4c.find("FRAMEHEIGHT") != std::string::npos;
	}

	/* 1001BC90-1001BD43 000B3	*/
	bool CParticleEmitterToken::IsFramesPerLine() {
		return unk_d4c.find("FRAMESPERLINE") != std::string::npos;
	}

	/* 1001BD50-1001BE03 000B3	*/
	bool CParticleEmitterToken::IsAnimDelay() {
		return unk_d4c.find("ANIMDELAY") != std::string::npos;
	}

	/* 1001BE10-1001BEC3 000B3	*/
	bool CParticleEmitterToken::IsGravity() {
		return unk_d4c.find("GRAVITY") != std::string::npos;
	}

	/* 1001BED0-1001BF83 000B3	*/
	bool CParticleEmitterToken::IsSrcBlendMode() {
		return unk_d4c.find("SOURCEBLENDMODE") != std::string::npos;
	}

	/* 1001BF90-1001C043 000B3	*/
	bool CParticleEmitterToken::IsDestBlendMode() {
		return unk_d4c.find("DESTBLENDMODE") != std::string::npos;
	}

	/* 1001C050-1001C93C 008EC	*/
	std::string CParticleEmitterToken::TypeAsString() {
		switch (unk_d5c) {
			case REAL_NUMBER:
				return std::string("RealNumber");
			case EQUALS:
				return std::string("Equals");
			case COMMA:
				return std::string("Comma");
			case OPEN_PAREN:
				return std::string("OpenParen");
			case CLOSE_PAREN:
				return std::string("CloseParen");
			case OPEN_BRACE:
				return std::string("OpenBrace");
			case CLOSE_BRACE:
				return std::string("CloseBrace");
			case QUOTE:
				return std::string("Quote");
			case KEYWORD_PARTICLE_SYSTEM:
				return std::string("KeywordParticleSystem");
			case KEYWORD_EVENT_SEQUENCE:
				return std::string("KeywordEventSequence");
			case KEYWORD_RANDOM:
				return std::string("KeywordRandom");
			case KEYWORD_XYZ:
				return std::string("KeywordXYZ");
			case KEYWORD_COLOR:
				return std::string("KeywordColor");
			case KEYWORD_TEXTURE:
				return std::string("KeywordTexture");
			case ALPHA_BLEND_MODE:
				return std::string("AlphaBlendMode");
			case KEYWORD_LOOP:
				return std::string("KeywordLoop");
			case KEYWORD_ANIM_FRAMES:
				return std::string("KeywordAnimFrames");
			case KEYWORD_FRAME_WIDTH:
				return std::string("KeywordFrameWidth");
			case KEYWORD_FRAME_HEIGHT:
				return std::string("KeywordFrameHeight");
			case KEYWORD_FRAMES_PER_LINE:
				return std::string("KeywordFramesPerLine");
			case KEYWORD_ANIM_DELAY:
				return std::string("KeywordAnimDelay");
			case SYS_VECTOR_PROP:
				return std::string("SysVectorProp");
			case SEQ_ALPHA_BLEND_MODE_PROP:
				return std::string("SeqAlphaBlendModeProp");
			case KEYWORD_FADE:
				return std::string("KeywordFade");
			case KEYWORD_SO:
				return std::string("KeywordSo");
			case KEYWORD_AT:
				return std::string("KeywordAt");
			case KEYWORD_INITIAL:
				return std::string("KeywordInitial");
			case KEYWORD_FINAL:
				return std::string("KeywordFinal");
			case PARTICLE_NUMERIC_PROP:
				return std::string("ParticleNumericProp");
			case PARTICLE_VECTOR_PROP:
				return std::string("ParticleVectorProp");
			case PARTICLE_COLOR_PROP:
				return std::string("ParticleColorProp");
			case SEQ_NUMERIC_PROP:
				return std::string("SeqNumericProp");
			case SEQ_VECTOR_PROP:
				return std::string("SeqVectorProp");
		}
		return std::string("**Unknown!**");
	}

public:
	/* 0xd4c */ std::string unk_d4c;
	/* 0xd5c */ int unk_d5c;
};

STATIC_ASSERT(sizeof(CParticleEmitterToken) == 0xd60);

#endif