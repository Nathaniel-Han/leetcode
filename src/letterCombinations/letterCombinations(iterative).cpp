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
    
    /* iterative version */
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
        vector<string> answer;
        answer.push_back("");
        
        for(int i=0;i<digits.length(); i++){
            //now [answer] stores the result from last iterations (digits[0:i-1])
            string str = dict[digits[i]-48];
            vector<string> temp;
            for (int j=0; j<str.length(); j++) {
                for(int k=0;k<answer.size();k++){
                    temp.push_back(answer[k]+str[j]);
                }
            }
            answer = temp;
        }
        
        return answer;
    }
    
};

int main() {
    Solution s;
    vector<string> ans = s.letterCombinations("23");
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
    
    cout << ans.size() << endl;
    
    return 0;
}
