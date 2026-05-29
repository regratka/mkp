#ifndef _MAG_PROFILE
#define _MAG_PROFILE

#include <globals.h>

class MagProfile {
public:
    static MagProfile* getInstance() {
		return instance;
	}

	/* 10005AE0 */ MagProfile(MagProfile* param_1);
	/* 10005D20 */ MagProfile* operator=(MagProfile* param_1);
	/* 10006120 */ MagProfile* scalar_destructor(uchar param_1);
	/* 1008C3C0 */ MagProfile();
	/* 1008C480 */ MagProfile(char* param_1);
	/* 1008C520 */ ~MagProfile();
	/* 1008C560 */ void ProfileInit();
	/* 1008C5E0 */ void ProfileBegin(char* param_1);
	/* 1008C770 */ void ProfileEnd(char* param_1);
	/* 1008C930 */ void ProfileDumpOutputToBuffer();
	/* 1008CE30 */ void StoreProfileInHistory(char* param_1, float param_2);
	/* 1008D000 */ void GetProfileFromHistory(char* param_1, float* param_2, float* param_3, float* param_4);
	/* 1008D0D0 */ void EnableProfile();
	/* 1008D130 */ void ProfileDumpOutputToFile();
	/* 1008D1B0 */ void ProfileLoadBegin(char* param_1);
	/* 1008D210 */ void ProfileLoadEnd();
	/* 1008D2E0 */ void ProfileDumpLoadResultToFile();

private:
	static MagProfile* instance;
};

MagProfile* MagProfile::instance = NULL;

#endif