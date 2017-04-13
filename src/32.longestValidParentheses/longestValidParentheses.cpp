/*
 Given a string containing just the characters '(' and ')', find the length of the longest valid (well-
 formed) parentheses substring.
 
 For "(()", the longest valid parentheses substring is "()", which has length = 2.
 
 Another example is ")()())", where the longest valid parentheses substring is "()()", which has length 
 = 4.
 */

#include <iostream>
#include <string>
#include <cassert>
using namespace std;

/* DP Algorithm 
   Denote len(i) as the the length of valid parentheses start from s[i].
   There are two cases:
   1) s[i] = ')' in this case, obviously len(i)=0
   2) s[i] = '(' Then we must find a match ")" for this "(" at s[j] where
      j = len[i+1]+i+1. Of course, we should further consider len[j+1]
      if it exists.
*/

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        if (n==0) {
            return 0;
        }
        
        int maxLen = 0;
        int *len = new int[n];
        memset(len, 0, sizeof(int)*n);
        
        for (int i = n-2; i>=0; i--) {
            if (s[i] == ')') {
                len[i] = 0;
            }
            else {
                int j = len[i+1] + i + 1;
                if (j < n && s[j] == ')') {
                    len[i] = len[i+1] + 2;
                    if (j + 1 < n) {
                        len[i] += len[j+1];
                    }
                }
            /* This can be commented because we have 
             initialized *len* with 0 in memset*/
                
//                else
//                    len[i] = 0;
            }
        }
        
        
        for (int i = 0; i < n; i++) {
            if (len[i] > maxLen) {
                maxLen = len[i];
            }
        }
        
        delete[] len;
        return maxLen;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    assert(s.longestValidParentheses("(()")==2);
    assert(s.longestValidParentheses(")()())")==4);
    assert(s.longestValidParentheses("()(()") == 2);
    assert(s.longestValidParentheses("") == 0);

    return 0;
}
