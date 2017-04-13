#include<iostream>
#include<cmath>
#include<map>
using namespace std;

class Solution {
public:
	// traversal the string once
	// save space, but cost more time
	int lengthOfLongestSubstring(string s) {
		map<char, int> test;
		int len = s.length();
		int start = 0;
		int answer = 0;

		for (int i = 0; i < len; i++) {
			if (test.count(s[i]) == 0) {
				test[s[i]] = i;
			} else {
				if (test[s[i]] < start) {
					test[s[i]] = i;
				} else {
					start = test[s[i]] + 1;
					test[s[i]] = i;
				}

			}
			answer = answer > (i - start + 1) ? answer : (i - start + 1);
		}
		return answer;
	}
};

int main() {

	Solution s;
	string a("wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco");
	cout << s.lengthOfLongestSubstring(a) << endl;



}
