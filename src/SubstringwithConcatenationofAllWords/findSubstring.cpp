/* You are given a string, S, and a list of words, L, that are all of the same length. Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.
 
 For example, given:
 S: "barfoothefoobarman"
 L: ["foo", "bar"]
 
 You should return the indices: [0,9].
 (order does not matter) 
 
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> answer;
        /* *n* is the size of query string vec, 
           *m* is the size of individual query string */
        int n = L.size(), m = L[0].length();
        int len = S.length();
        string sub_string;
        
        /* in case of duplicate query string*/
        sort(L.begin(), L.end());
        
        int pos = 0;
        /* these two strings are useful in the case of duplicate query string*/
        string prevStr(""), currentStr;
        /* used for Verification of the priority_queue in the following*/
        int prev, current;
        /* record map position of the last query string, 
         used only in the case of duplicates*/
        int prevAns = -1;
        
        while (pos + n*m - 1 < len) {
            sub_string = S.substr(pos, n*m);
            size_t ans;
            priority_queue<int> positions;
            
            for (int i=0; i<n; i++) {
                currentStr = L[i];
                
                if (i > 0 && currentStr.compare(prevStr) == 0
                    && prevAns != string::npos && prevAns + 1 < n*m) {
                    /* the case of duplicate query string */
                    string sub_string1 = sub_string.substr(prevAns+m);
                    
                    ans = sub_string1.find(currentStr);
                    
                    /* consider *ans % m* because of the fact that 
                     the length of every query string is the same  */
                    while (ans != string::npos && ans % m != 0) {
                        string sub_string2 = sub_string1.substr(ans+1);
                        
                        if (sub_string2.find(currentStr) != string::npos) {
                            ans = ans + sub_string2.find(currentStr) + 1;
                        }
                        else
                            goto while_end;

                    }
                    
                    if (ans != string::npos && ans % m ==0)
                        ans = ans + prevAns + m;
                    
                }
                else {
                    ans = sub_string.find(currentStr);
                    
                    while (ans != string::npos && ans % m != 0) {
                        string sub_string1 = sub_string.substr(ans+1);
                        
                        if (sub_string1.find(currentStr) != string::npos) {
                            ans = ans + sub_string1.find(currentStr) + 1;
                        }
                        else
                            goto while_end;
                        
                    }
                }
                
                if (ans != string::npos && ans % m ==0) {
                    positions.push(ans);
                } else
                    goto while_end;
                
                prevAns = ans;
                prevStr = currentStr;
            }
            
            /* Verification for the position that query string appears */
            /* Take the fact that the length of every query string is the same*/
            prev = positions.top();
            positions.pop();
            while (!positions.empty()) {
                current = positions.top();
                if (prev - current != m) {
                    goto while_end;
                }
                prev = current;
                positions.pop();
            }
            
            /* This *pos* has passed the test, and should be put into the result */
            answer.push_back(pos);
            
        while_end:
            /* move to the next position of *S* */
            pos++;
        }
        
        return answer;
    }
    
};

int main(int argc, const char * argv[]) {
    Solution s;
    
    string S;
    vector<string> L;
    vector<int> ans;
    
    /* TEST1 */
    S = "barfoothefoobarman";
    L = vector<string>{"foo", "bar"};
    ans = vector<int>{0,9};
    assert(s.findSubstring(S, L) == ans);
    
    /* TEST2 */
    S = "lingmindraboofooowingdingbarrwingmonkeypoundcake";
    L = vector<string>{"fooo","barr","wing","ding","wing"};
    ans = vector<int>{13};
    assert(s.findSubstring(S, L) == ans);
    
    
    /* TEST3 */
    S = "abaababbaba";
    L = vector<string>{"ab","ba","ab","ba"};
    ans = vector<int>{1,3};
    assert(s.findSubstring(S, L) == ans);
    
    /* TEST4 */
    S = "abaaabbb";
    L = vector<string>{"ab","bb"};
    ans = vector<int>{4};
    assert(s.findSubstring(S, L) == ans);
    
    
    return 0;
}
