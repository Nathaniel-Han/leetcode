#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<assert.h>

class Solution {
public:
	int CharToInt(char c) {
		return c - 48;
	}

	int atoi(const char *str) {

		//clean str
		int len = strlen(str);
		char* ss = new char[len];
		int pos = 0;
		bool isPositive = true;
		bool First = false;
		for (int i = 0; i < len; i++) {

			if (!First) {
				if (isspace(str[i]))
					continue;
				else {
					if (str[i] == '-')
						isPositive = false;
					else if (str[i] == '+')
						isPositive = true;
					else if (str[i] >= 48 && str[i] <= 57) {
						ss[pos] = str[i];
						pos++;
					} else
						// the first character that is not space is not appropriate one
						return 0;

					First = true;

				}

			} else {
				if (str[i] >= 48 && str[i] <= 57) {
					ss[pos] = str[i];
					pos++;
				} else
					break;
			}

		}
		ss[pos] = '\0';
		//clean str ===========================

		len = strlen(ss);

		if (len == 0)
			return 0;

		if (len == 1 && isPositive)
			return CharToInt(ss[0]);

		if (len == 1 && !isPositive)
			return -CharToInt(ss[0]);

		if (isPositive
				&& ((len == 10 && strcmp(ss, "2147483647") > 0) || len > 10))
			return 2147483647;

		if (!isPositive
				&& ((len == 10 && strcmp(ss, "2147483648") > 0) || len > 10))
			return -2147483648;

		int answer = 0;
		for (int i = 0; i < len; i++) {
			answer = CharToInt(ss[i]) + answer * 10;
		}

		if (!isPositive)
			return -answer;

		return answer;
	}
}
;

int main() {
	Solution s;

	assert(s.atoi("1") == 1);
	assert(s.atoi("-1") == -1);
	assert(s.atoi("-0012a42") == -12);
	assert(s.atoi("+-2") == 0);
	assert(s.atoi("      -11919730356x") == -2147483648);

	return 0;
}
