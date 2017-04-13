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
#include <queue>
#include <unordered_map>
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
        int pos = 0;

        /* construct HashMap based on query strings */
        unordered_map<string, int> HashMap;
        for (int i = 0; i < n; i++) {
            if (HashMap.count(L[i]) == 0) {
                HashMap[L[i]] = 1;
            }
            else
                HashMap[L[i]]++;
        }

        while (pos + n*m - 1 < len){
            unordered_map<string, int> Map = HashMap;

            for (int i=0; i < n; i++) {
                /* every time extract one sub_str of the
                   same length of query length*/
                string str = S.substr(pos + i*m, m);
                auto got = Map.find(str);
                if (got != Map.end()) {
                    if (Map[str]-1 == 0) {
                        Map.erase(got);
                    }
                    else
                        Map[str] -= 1;
                }
                else
                    break;
            }

            if (Map.empty()) {
                answer.push_back(pos);
            }

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
