#ifndef PG_STRING
#define PG_STRING

#include <globals.h>

#include <cstring>

class DLLEXPORT pgString {
public:
	/* 1000B420-1000B429 00009	*/
	pgString() {
		text = NULL;
	}

	/* 1000B430-1000B435 00005	*/
	int getLength() const {
		return length();
	}

	/* 1000B440-1000B44C 0000C	*/
	operator char const*() const {
		if (text == NULL) {
			return "";
		}
		return  text;
	}

	/* 1000B440-1000B44C 0000C	*/
	char const* get() const {
		if (text == NULL) {
			return "";
		}
		return  text;
	}

	/* 1000B450-1000B45C 0000C	*/
	char operator[](int param_1) const {
		return text[param_1];
	}

	/* 100821E0 */ pgString(pgString const & param_1);
	/* 10082200 */ pgString(char const* param_1);
	/* 10082260 */ ~pgString();
	/* 10082270 */ pgString& set(char const* param_1, ...);
	/* 10082310 */ pgString& cat(char const* param_1);
	/* 100823F0 */ int length() const;
	/* 10082410 */ bool consistsJustOf(pgString const& param_1) const;
	/* 10082490 */ int getIndex(char param_1, bool param_2) const;
	/* 100824D0 */ int getIndex(int param_1, char param_2, bool param_3) const;
	/* 10082550 */ int getIndexNot(char param_1, bool param_2) const;
	/* 10082590 */ int getIndexNot(int param_1, char param_2, bool param_3) const;
	/* 10082610 */ int getIndex(pgString const& param_1, bool param_2) const;
	/* 10082650 */ int getIndex(int param_1, pgString const& param_2, bool param_3) const;
	/* 10082740 */ int getCNum(char param_1) const;
	/* 10082790 */ pgString getSubString(int param_1, int param_2) const;
	/* 10082850 */ pgString& toLower();
	/* 10082890 */ pgString& toUpper();
	/* 100828D0 */ static char toLower(char param_1);
	/* 10082900 */ static char toUpper(char param_1);
	/* 10082930 */ pgString& cutC(char param_1, bool param_2);
	/* 10082A30 */ pgString& cut(char param_1);
	/* 10082A60 */ pgString& cutS(pgString const& param_1, bool param_2);
	/* 10082B80 */ pgString& cut(pgString const& param_1);
	/* 10082BB0 */ int find(pgString const& param_1);
	/* 10082BF0 */ bool operator<(pgString const& param_1) const;
	/* 10082C60 */ bool operator>(pgString const& param_1) const;
	/* 10082CD0 */ bool operator==(pgString const& param_1) const;
	/* 10082D40 */ bool operator==(char const* param_1) const;
	/* 10082DB0 */ bool operator!=(pgString const& param_1) const;
	/* 10082E20 */ bool operator!=(char const* param_1) const;
	/* 10082E90 */ pgString& operator=(pgString const& param_1);
	/* 10082F00 */ pgString& operator+=(pgString const& param_1);
	/* 10082F20 */ void setBuffer(char* param_1);

private:
	/* 0x00 */ char* text;
};

STATIC_ASSERT(sizeof(pgString) == 0x4);

#endif