#include<iostream>
#include<string>
#include<cstring>
using namespace std;

class Solution {
public:
    // this is a solution with O(N^2) complexity
    // there exists O(N) algorithm in http://leetcode.com/2011/11/longest-palindromic-substring-part-ii.html
    
     string longestPalindromeHelper(string s, int length, int left, int right){
        while (left>=0 && right < length && s[left] == s[right]) {
            left--;
            right++;
        }
        
        left++;
        right--;
        
        return s.substr(left, right-left+1);
    }
    
    string longestPalindrome(string s) {
        int len = s.length();
        if (len == 0)
            return 0;
        
        string answer,str1, str2;
        int longest=0;
        
        for (int i=0; i < len; i++) {
            str1 = longestPalindromeHelper(s,len, i, i);
            if (str1.length() > longest){
                answer = str1;
                longest = str1.length();
            }
            
            
            if (i+1 < len) {
                str2 = longestPalindromeHelper(s, len, i, i+1);
                if (str2.length() > longest) {
                    answer = str2;
                    longest = str2.length();
                }
            }
        }
        
        return answer;
        
    }
};

int main() {
    Solution s;
    cout << s.longestPalindrome("a") << endl;
    
    return 0;
}

