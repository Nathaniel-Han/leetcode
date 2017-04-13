#include<iostream>
#include<vector>
#include<string>
#include<cassert>
using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string> &strs) {
		string answer;
		int size = strs.size();
		if(size == 0)
			return "";
		if (size == 1)
			return strs[0];


		// compute minimal length of strings to make a flag for pointor
		int min_len = strs[0].size() <= strs[1].size() ? strs[0].size() : strs[1].size();

		for(int i = 2; i<size;i++){
			if (strs[i].size() < min_len)
				min_len = strs[i].size();
		}

		if(min_len == 0)
			return "";

		int pos = 0;

		while (pos < min_len) {

			for (int i = 0; i < size - 1; i++) {
				if (strs[i][pos] == strs[i + 1][pos]) {
					continue;
				} else{
					return strs[0].substr(0, pos);
				}
			}

			pos++;
		}

		return strs[0].substr(0, min_len);

	}
};

int main() {
	Solution s;

	vector<string> strs;

	strs.push_back("abcd");
	strs.push_back("abc");

	assert(s.longestCommonPrefix(strs) == "abc");
	return 0;
}
