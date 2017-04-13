/* Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 
 * For example, given n = 3, a solution set is:
 
 * "((()))", "(()())", "(())()", "()(())", "()()()"*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        
        if (n == 0) {
            return vector<string>(1, "");
        }
        
        if (n == 1) {
            return vector<string>(1, "()");
        }
        
        vector<string> answer;
        answer = generateParenthesis(n - 1);
        unordered_set<string> test;
        
        
        //only one kind of parenthesis exists, so the next codes always generate valid parenthesis
        for (auto str : answer) {
            for (int i = 0; i < str.length(); i++)
                for (int j = i; j < str.length(); j++) {
                    test.insert(
                                SubStr(str, 0, i) + "(" + SubStr(str, i, j) + ")"+ SubStr(str, j, str.length()));
                }
        }
        
        answer.clear();
        for (auto iter : test) {
            answer.push_back(iter);
        }
        
        return answer;
    }
    
    // implement python-style substring function
    inline string SubStr(string s, int index1, int index2) {
        assert(index2 >= index1);
        
        return s.substr(index1, index2 - index1);
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<string> ans = s.generateParenthesis(5);
    cout << ans.size() << endl;
    for (auto iter = ans.begin(); iter != ans.end(); iter++) {
        cout << *iter << " ";
    }
    
    return 0;
}
