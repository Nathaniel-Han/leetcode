/* Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 
 * The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.*/

#include <iostream>
#include <string>
#include <stack>
#include <cassert>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> test;
        for (int i=0;i<s.length();i++) {
            if (s[i] == '(' || s[i]=='{' || s[i] =='[') {
                test.push(s[i]);
            }

            else if (s[i] == ')' ){
                
                if (test.empty()) {
                    return false;
                } else if (test.top() == '(')
                    test.pop();
                else
                    return false;
            }
            
            
            else if (s[i] == '}' ){
                
                if (test.empty()) {
                    return false;
                } else if (test.top() == '{')
                    test.pop();
                else
                    return false;
                
            }
            else if (s[i] == ']' ){
                
                if (test.empty()) {
                    return false;
                } else if (test.top() == '[')
                    test.pop();
                else
                    return false;
            }
            
            else
                return false;
        }
        
        return test.empty()? true:false;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    
    assert(s.isValid("()") == true);
    assert(s.isValid("([])") == true);
    assert(s.isValid("({)}") == false);
    assert(s.isValid("]") ==false);
    
    
    
    return 0;
}
