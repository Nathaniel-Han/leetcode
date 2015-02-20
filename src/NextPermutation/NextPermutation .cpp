/*
 Implement next permutation, which rearranges numbers into the 
 lexicographically next greater permutation of numbers.
 
 If such arrangement is not possible, it must rearrange it as the 
 lowest possible order (ie, sorted in ascending order).
 
 The replacement must be in-place, do not allocate extra memory.
*/
 
/* 
 
 Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the
 right-hand column.
 
 1,2,3 → 1,3,2
 3,2,1 → 1,2,3
 1,1,5 → 1,5,1
 
*/

#include <iostream>
#include <vector>
#include <cassert>
#include <iostream>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int len = num.size();
        for (int i = len-1; i > 0; i--) {
            /* Search from tail to find the first place that num[i] > num[i-1] */
            if (num[i] > num[i-1]) {
                
                int j = len - 1;
                int low  = i, high = len-1, mid;
                
                /* Find the first element from tail between [end...i] that is larger than num[i-1]*/
                /* Notice that elements between [i..end] is in descending order (So here binary search can be used )*/
                while (j > i && num[j] <= num[i-1]) {
                    j--;
                }
                swap(num[j], num[i-1]);
                sort(num.begin()+i, num.end());
                
                return;
                
            }
            else
                continue;
        }
        
        sort(num.begin(), num.end());
        return;
    }
    
    inline void swap(int& a, int& b){
        int tmp = b;
        b = a;
        a = tmp;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    
    vector<int> num{1,2,3};
    s.nextPermutation(num);
    assert(num == vector<int> ({1,3,2}));
    
    num = vector<int>({3,2,1});
    s.nextPermutation(num);
    assert(num == vector<int> ({1,2,3}));
    
    num=vector<int>({1,1,5});
    s.nextPermutation(num);
    assert(num == vector<int>({1,5,1}));
    
    num=vector<int>({1,3,2});
    s.nextPermutation(num);
    assert(num == vector<int>({2,1,3}));
    
    
    num=vector<int>({2,3,1});
    s.nextPermutation(num);
    assert(num == vector<int>({3,1,2}));
    
    num=vector<int>({1,5,1});
    s.nextPermutation(num);
    assert(num == vector<int>({5,1,1}));
    
    num=vector<int>({1,5,2,1});
    s.nextPermutation(num);
    assert(num == vector<int>({2,1,1,5}));
    
    num=vector<int>({5,4,7,5,3,2});
    s.nextPermutation(num);
    assert(num == vector<int>({5,5,2,3,4,7}));
 
    
    return 0;
}
