/*Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
 *Find all unique triplets in the array which gives the sum of zero.

 Note:
 Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
 The solution set must not contain duplicate triplets.*/

/* For example, given array S = {-1 0 1 2 -1 -4},
   A solution set is:
   (-1, 0, 1)
   (-1, -1, 2)*/

#include<iostream>
#include<vector>
#include<algorithm>
#include <unordered_set>
#include <string>
#include<cassert>
using namespace std;


class Solution {
public:
    /*Slow version*/
    /*But the idea adoped here is quite useful in 4Sum problem*/
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > answer;
        vector<int> triple(3);
        unordered_set<string> test;

        sort(num.begin(), num.end());


        int size = num.size();
        assert(size >= 3);

        for (int i=0; i<size -2; i++) {
            int low = i+1, high = size -1;
            int searchNum = -num[i];
            while (low < high) {
                if (num[low]+num[high] == searchNum) {
                    string str;
                    str += num[i];
                    str += num[low];
                    str += num[high];
                    if(test.count(str) == 0){
                        triple[0] = num[i];
                        triple[1] = num[low];
                        triple[2] = num[high];
                        answer.push_back(triple);
                        test.insert(str);
                    }
                    low++;
                    high--;
                }
                else if(num[low]+num[high] < searchNum){
                    low++;
                }
                else{
                    high--;
                }
            }
        }
        return answer;

    }
};

int main() {
    Solution s;
    int a[] = { -1, 0, 1, 2, -1, -4 ,-1};
    vector<int> input(a, a + sizeof(a) / sizeof(int));

    vector<vector<int> > answer = s.threeSum(input);

    cout << answer.size() << endl;

    for(int i=0;i<answer.size();i++){
        for(int j=0;j<answer[i].size();j++){
            cout << answer[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}
