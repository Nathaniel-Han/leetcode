/* Given a digit string, return all possible letter combinations that the number could represent.
 * A mapping of digit to letters (just like on the telephone buttons) is given below.*/

/* Input:Digit string "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"] */

/* Note:
 * Although the above answer is in lexicographical order, your answer could be in any order you want.*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:

	/* recursive version */
	/* the code is easy to understand*/

	vector<string> dict;
	Solution() {
		dict.resize(10);
		dict[0] = "";
		dict[1] = "";
		dict[2] = "abc";
		dict[3] = "def";
		dict[4] = "ghi";
		dict[5] = "jkl";
		dict[6] = "mno";
		dict[7] = "pqrs";
		dict[8] = "tuv";
		dict[9] = "wxyz";
	}

	vector<string> letterCombinations(string digits) {
		if (digits.length() == 0) {
			return vector<string>(1, "");
		}

		vector<string> answer;

		string str = dict[digits[0] - 48];
		if (digits.length() == 1) {
			for (int i = 0; i < str.length(); i++) {
				answer.push_back(str.substr(i, 1));
			}
		}

		vector<string> temp = letterCombinations(digits.substr(1));

		for (int i = 0; i < str.length(); i++) {
			if (temp != vector<string>(1, "")) {
				for (int j = 0; j < temp.size(); j++) {
					answer.push_back(str[i] + temp[j]);
				}
			}
		}

		return answer;
	}

};

int main() {
	Solution s;
	vector<string> ans = s.letterCombinations("2");
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}

	cout << ans.size() << endl;

	return 0;
}
