#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<cassert>
using namespace std;

class Solution {
public:
	//easy implemation with vector, but cost more time
	string convert(string s, int nRows) {
		if(nRows == 1)
			return s;

		string answer;
		int unit = 2 * nRows - 2;
		int len = s.length();
		int quotient, remainder;

		vector<int> rows[nRows];

		for (int i = 0; i < len; i++) {
			remainder = i % unit;
			remainder = remainder < (unit - remainder) ? remainder : (unit - remainder);

			assert(remainder < nRows);

			rows[remainder].push_back(i);
		}

		for(int i=0;i<nRows;i++){
			for(int j=0;j<rows[i].size();j++){
				answer.push_back(s[rows[i][j]]);
			}
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
