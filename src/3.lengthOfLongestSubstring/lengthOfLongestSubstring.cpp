#include<iostream>
#include<cmath>
#include<map>
#include<cstring>
using namespace std;

class Solution {
public:
	// traversal the string once
	// trade space for time
	int lengthOfLongestSubstring(string s) {
		// record last index that the corresponding char appears 
		int m_record[256];
		// intialialze m_record
		memset(m_record, -1, sizeof(int) * 256);

		int len = s.length();
		int start = 0;
		int answer = 0;

		for (int i = 0; i < len; i++) {
			// must update the start index of current substring if necessary
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
	string a("wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco");
	cout << s.lengthOfLongestSubstring(a) << endl;

}
