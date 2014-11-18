#include<iostream>
#include<cmath>
#include<map>
#include<cstring>
using namespace std;

class Solution {
public:

	int lengthOfLongestSubstring(string s) {
		int m_record[256];
		memset(m_record, -1, sizeof(int) * 256);

		int len = s.length();
		int start = 0;
		int answer = 0;

		for (int i = 0; i < len; i++) {
//			if (test.count(s[i]) == 0) {
//				test[s[i]] = i;
//			} else {
//				if (test[s[i]] < start) {
//					test[s[i]] = i;
//				} else {
//					start = test[s[i]] + 1;
//					test[s[i]] = i;
//				}
//
//			}

			if (m_record[s[i]] < start) {
				m_record[s[i]] = i;
			} else {
				start = m_record[s[i]] + 1;
				m_record[s[i]] = i;
			}

			answer = answer > (i - start + 1) ? answer : (i - start + 1);
		}
		return answer;
	}
};

int main() {

	Solution s;
	string a("abcabcbb");
	cout << s.lengthOfLongestSubstring(a) << endl;



}
