#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<cassert>
using namespace std;

class Solution {
public:
	//trade space for time
	string convert(string s, int nRows) {
		if(nRows == 1)
			return s;

		string answer;
		int unit = 2 * nRows - 2;
		int len = s.length();
		int remainder;

		int indicator,rows[nRows][len];
		memset(rows, -1, sizeof(int)*nRows*len);

		//indicate the size of each row
		int flags[nRows];
		memset(flags, 0, sizeof(int)*nRows);

		for(int i=0;i<len;i++){
			remainder = i % unit;
			remainder = remainder < (unit - remainder) ? remainder : (unit - remainder);

			indicator = flags[remainder];
			rows[remainder][indicator] = i;
			flags[remainder]++;
		}

		for(int i=0;i<nRows;i++){
			for(int j=0;j<flags[i];j++)
				answer.push_back(s[rows[i][j]]);
		}

		return answer;

	}
};

int main() {
	Solution s;
	string str1("PAYPALISHIRING"), str2("AB");
	assert(s.convert(str1,3) == "PAHNAPLSIIGYIR");
	assert(s.convert(str2,1) == "AB");


	return 0;
}
