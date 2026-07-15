#include "pgString.h"

#include <stdio.h>
#include <stdarg.h>
#include <cctype>

/* 100821E0-100821F9 00019	*/
pgString::pgString(pgString const& param_1) {
	text = NULL;
	*this = param_1;
}

/* 10082200-10082259 00059	*/
pgString::pgString(char const* param_1) {
	if (param_1 != NULL) {
		text = new char[strlen(param_1)+1];
		strcpy(text, param_1);
	} else {
		text = NULL;
	}
}

/* 10082260-1008226E 0000E	*/
pgString::~pgString() {
	if (text != NULL) {
		delete[] text;
	}
}

/* 10082270-10082304 00094	*/
pgString& pgString::set(char const* param_1, ...) {
	if (text != NULL) {
		delete[] text;
	}

	if (param_1 != NULL) {
		va_list args;
		va_start(args, param_1);
		char buffor[2000];
		vsprintf(buffor, param_1, args);

		text = new char[strlen(buffor)+1];
		strcpy(text, buffor);
	} else {
		text = NULL;
	}

	return *this;
}

/* 10082310-100823E2 000D2	*/
pgString& pgString::cat(char const* param_1) {
	if (text == NULL) {
		text = new char[strlen(param_1)+1];
		strcpy(text, param_1);
	} else {
		char * oldText = text;
		text = new char[strlen(text) + strlen(param_1) + 1];
		strcpy(text, oldText);
		strcat(text, param_1);
		delete[] oldText;
	}
	return *this;
}

/* 100823F0-10082409 00019	*/
int pgString::length() const {
	if (text != NULL) {
		return strlen(text);
	}
	return 0;
}

/* 10082410-10082481 00071	*/
bool pgString::consistsJustOf(pgString const& param_1) const {
	if (text != NULL) {
		for (int iVar3 = 0; iVar3 < length(); iVar3++) {
			int iVar4 = 0;
			bool bVar1 = false;
			while (iVar4 < param_1.length()) {
				if (text[iVar3] == param_1.text[iVar4]) {
					bVar1 = true;
				}
				iVar4++;
			}
			if (!bVar1) {
				return false;
			}
		}
	}
	return true;
}

/* 10082490-100824C6 00036	*/
int pgString::getIndex(char param_1, bool param_2) const {
	if (param_2) {
		return getIndex(0, param_1, param_2);
	} else {
		return getIndex(length(), param_1, param_2);
	}
}

#define B

#ifdef A

/* 100824D0-1008254C 0007C	*/
int pgString::getIndex(int param_1, char param_2, bool param_3) const {
	if (param_1 == -1) {
		if (param_3) {
			param_1 = 0;
		} else {
			param_1 = length()-1;
		}
	}

	if (text != NULL) {
		if (param_3) {
			while (param_1 < length()) {
				if (text[param_1] == param_2) {
					return param_1;
				}
				param_1++;
			}
			return -1;
		} else {
			while (param_1 >= 0) {
				if (text[param_1] == param_2) {
					return param_1;
				}
				param_1--;
			}
			return -1;
		}
	}

	return -1;
}

#endif 

#ifdef B

/* 100824D0-1008254C 0007C	*/
int pgString::getIndex(int param_1, char param_2, bool param_3) const {
	if (param_1 == -1) {
		if (param_3) {
			param_1 = 0;
		} else {
			param_1 = length()-1;
		}
	}

	if (text != NULL) {
		if (param_3) {
			while (param_1 < length()) {
				if (text[param_1] == param_2) {
					return param_1;
				}
				param_1++;
			}
			return -1;
		} else {
			while (param_1 >= 0) {
				if (text[param_1] == param_2) {
					return param_1;
				}
				param_1--;
			}
			return -1;
		}
	}

	return -1;
}

#endif

/* 10082550-10082586 00036	*/
int pgString::getIndexNot(char param_1, bool param_2) const {
	if (param_2) {
		return getIndexNot(0, param_1, param_2);
	} else {
		return getIndexNot(length(), param_1, param_2);
	}
}

/* 10082590-1008260C 0007C	*/
int pgString::getIndexNot(int param_1, char param_2, bool param_3) const {
	if (param_1 == -1) {
		if (param_3) {
			param_1 = 0;
		} else {
			param_1 = length() - 1;
		}
	}

	if (text != NULL) {
		if (param_3) {
			while(param_1 < length()) {
				if (text[param_1] != param_2) {
					return param_1;
				}
				param_1++;
			}
			return -1;
		} else {
			while (param_1 >= 0) {
				if (text[param_1] != param_2) {
					return param_1;
				}
				param_1--;
			}
			return -1;
		}
	}

	return -1;
}

/* 10082610-10082647 00037	*/
int pgString::getIndex(pgString const& param_1, bool param_2) const {
	if (param_2) {
		return getIndex(0, param_1, param_2);
	} else {
		return getIndex(length()-1, param_1, param_2);
	}
}

/* 10082650-10082732 000E2	*/
int pgString::getIndex(int param_1, pgString const& param_2, bool param_3) const {
	if (param_1 == -1) {
		if (param_3) {
			param_1 = 0;
		} else {
			param_1 = length() - 1;
		}
	}

	if (text == NULL || param_1 < 0 || param_1 >= length()) {
		return -1;
	}

	if (param_3) {
		while (param_1 < length()) {
			int iVar4 = 0;
			int iVar1 = param_1;
			while (iVar1 < length() && iVar4 < param_2.length() && text[param_1+iVar4] == param_2.text[iVar4]) {
				iVar4++;
				iVar1 = iVar4 + param_1;
			}
			if (iVar4 == param_2.length()) {
				return param_1;
			}
			param_1++;
		}
	} else {
		while (param_1 >= 0) {
			int iVar4 = 0;
			int iVar1 = param_1;
			while (iVar1 < length() && iVar4 < param_2.length() && text[param_1+iVar4] == param_2.text[iVar4]) {
				iVar4++;
				iVar1 = iVar4 + param_1;
			}
			if (iVar4 == param_2.length()) {
				return param_1;
			}
			param_1--;
		}
	}

	return -1;
}

/* 10082740-10082782 00042	*/
int pgString::getCNum(char param_1) const {
	int iVar2 = 0;
	if (text != NULL) {
		for (int index = 0; index < length(); index++) {
			if (text[index] == param_1) {
				iVar2++;
			}
		}
	}
	return iVar2;
}

/* 10082790-10082850 000C0	*/
pgString pgString::getSubString(int param_1, int param_2) const {
	int len = param_2;
	if (param_2 == -1) {
		len = length() - param_1;
	}

	char* pcVar1 = new char[len+1];
	for (int index = 0; index < len; index++) {
		pcVar1[index] = text[index + param_1];
	}
	pcVar1[len+1] = '\0';
	pgString res;
	res.setBuffer(pcVar1);
	return res;
}

/* 10082850-10082887 00037	*/
pgString& pgString::toLower() {
	char* c = text;
	while (*c != '\0') {
		if (isupper(*c)) {
			*c = tolower(*c);
		}
		c++;
	}
	return *this;
}

/* 10082890-100828C7 00037	*/
pgString& pgString::toUpper() {
	char* c = text;
	while (*c != '\0') {
		if (islower(*c)) {
			*c = toupper(*c);
		}
		c++;
	}
	return *this;
}

/* 100828D0-100828FB 0002B	*/
char pgString::toLower(char param_1) {
	if (isalpha(param_1)) {
		if (isupper(param_1)) {
			param_1 = param_1 + ' ';
		}
	}
	return param_1;
}

/* 10082900-1008292B 0002B	*/
char pgString::toUpper(char param_1) {
	if (isalpha(param_1)) {
		if (islower(param_1)) {
			param_1 = param_1 - ' ';
		}
	}
	return param_1;
}

/* 10082930-10082A21 000F1	*/
pgString& pgString::cutC(char param_1, bool param_2) {
	if (text == NULL) {
		return *this;
	}

	if (param_2) {
		int iVar4 = -1;
		for (int iVar5 = 0; iVar5 < length(); iVar5++) {
			if (text[iVar5] != param_1) {
				break;
			}
			iVar4 = iVar5;
		}

		if (iVar4 == -1) {
			return *this;
		}

		pgString subString = getSubString(iVar4+1, -1);
		*this = subString.text;
		return *this;
	} else {
		int iVar4 = -1;
		for (int iVar5 = length()-1; iVar5 >= 0; iVar5--) {
			if (text[iVar5] != param_1) {
				break;
			}
			iVar4 = iVar5;
		}

		if (iVar4 == -1) {
			return *this;
		}

		pgString subString = getSubString(0, iVar4-1);
		*this = subString.text;
		return *this;
	}
}

/* 10082A30-10082A51 00021	*/
pgString& pgString::cut(char param_1) {
	cutC(param_1, true);
	cutC(param_1, false);
	return *this;
}

/* 10082A60-10082B76 00116	*/
pgString& pgString::cutS(pgString const& param_1, bool param_2) {
	if (text == NULL) {
		return *this;
	}

	if (param_2) {
		int iVar4 = -1;
		for (int iVar5 = 0; iVar5 < length(); iVar5++) {
			if (param_1.getIndex(text[iVar5], true) < 0) {
				break;
			}
			iVar4 = iVar5;
		}

		if (iVar4 == -1) {
			return *this;
		}

		pgString subString = getSubString(iVar4+1, -1);
		*this = subString.text;
		return *this;
	} else {
		int iVar4 = -1;
		for (int iVar5 = length()-1; iVar5 >= 0; iVar5--) {
			if (param_1.getIndex(text[iVar5], true) < 0) {
				break;
			}
			iVar4 = iVar5;
		}

		if (iVar4 == -1) {
			return *this;
		}

		pgString subString = getSubString(0, iVar4-1);
		*this = subString.text;
		return *this;
	}
}

/* 10082B80-10082BA1 00021	*/
pgString& pgString::cut(pgString const& param_1) {
	cutS(param_1, true);
	cutS(param_1, false);
	return *this;
}

/* 10082BB0-10082BE4 00034	*/
int pgString::find(pgString const& param_1) {
	if (text == NULL) {
		return -1;
	}
	char* found = strstr(text, param_1.text == NULL ? "" : param_1.text);
	if (found != NULL) {
		return found - text + 1;
	}
	return -1;
}

/* 10082BF0-10082C53 00063	*/
bool pgString::operator<(pgString const& param_1) const {
	if (text == NULL || param_1.text == NULL) {
		return text < param_1.text;
	}
	return strcmp(text, param_1.text) < 0;
}

/* 10082C60-10082CC3 00063	*/
bool pgString::operator>(pgString const& param_1) const {
	if (text == NULL || param_1.text == NULL) {
		return text > param_1.text;
	}
	return strcmp(text, param_1.text) > 0;
}

/* 10082CD0-10082D38 00068	*/
bool pgString::operator==(pgString const& param_1) const {
	if (text == NULL || param_1.text == NULL) {
		return text == param_1.text;
	}
	return !strcmp(text, param_1.text);
}

/* 10082D40-10082DA4 00064	*/
bool pgString::operator==(char const* param_1) const {
	if (text == NULL || param_1 == NULL) {
		return text == param_1;
	}
	return !strcmp(text, param_1);
}

/* 10082DB0-10082E18 00068	*/
bool pgString::operator!=(pgString const& param_1) const {
	if (text == NULL || param_1.text == NULL) {
		return text != param_1.text;
	}
	return strcmp(text, param_1.text);
}

/* 10082E20-10082E84 00064	*/
bool pgString::operator!=(char const* param_1) const {
	if (text == NULL || param_1 == NULL) {
		return text != param_1;
	}
	return strcmp(text, param_1);
}

/* 10082E90-10082EF5 00065	*/
pgString& pgString::operator=(pgString const& param_1) {
	if (text != NULL) {
		delete text;
	}

	if (param_1.text == NULL) {
		text = NULL;
		return *this;
	}
	text = new char[strlen(param_1.text)+1];

	strcpy(text, param_1.text);


	return *this;
}

/* 10082F00-10082F20 00020	*/
pgString& pgString::operator+=(pgString const& param_1) {
	cat(param_1.text == NULL ? "" : param_1.text);
	return *this;
}

/* 10082F20-10082F46 00026	*/
void pgString::setBuffer(char* param_1) {
	if (text != NULL) {
		delete text;
	}
	text = param_1;
}


