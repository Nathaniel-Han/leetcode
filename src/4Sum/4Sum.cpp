#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
#include<string>


using namespace std;

class Solution {
public:
    
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        
        vector<vector<int> > answer;
        if (num.size() < 4) {
            return answer;
        }
        
        vector<int> quad(4);
        
        sort(num.begin(), num.end());
        int size = num.size();
        
        unordered_set<string> test;
        int e1, e2, e3, e4;
        
        for (int i = 0; i < size - 3; i++) {
            for (int j = i + 1; j < size - 2; j++) {
                e1 = num[i];
                e2 = num[j];
                int low = j + 1, high = size - 1;
                while (low < high) {
                    e3 = num[low];
                    e4 = num[high];
                    if (e1 + e2 + e3 + e4 == target) {
                        string str;
                        str += e1;
                        str += e2;
                        str += e3;
                        str += e4;
                        if (test.count(str) == 0) {
                            quad[0] = e1;
                            quad[1] = e2;
                            quad[2] = e3;
                            quad[3] = e4;
                            answer.push_back(quad);
                            test.insert(str);
                        }
                        low++;
                        high--;
                        
                    } else if (e1 + e2 + e3 + e4 < target) {
                        low++;
                        
                    } else {
                        high--;
                       
                    }
                }
            }
        }
        
        return answer;
    }
};

int main() {
    Solution s;

    int a[] = {-1,2,2,-5,0,-1,4};
    vector<int> input(a, a + sizeof(a) / sizeof(int));
    
    vector<vector<int> > answer = s.fourSum(input, 3);
    
    cout << answer.size() << endl;
    
    for (int i = 0; i < answer.size(); i++) {
        for (int j = 0; j < answer[i].size(); j++) {
            cout << answer[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
