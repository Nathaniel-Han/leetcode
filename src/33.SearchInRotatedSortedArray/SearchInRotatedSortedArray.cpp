/*
 Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 
 (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 
 You are given a target value to search. If found in the array return its index, otherwise return
 -1.
 
 You may assume no duplicate exists in the array.
 
*/

#include <iostream>
using namespace std;

// Binary Search is definitely to be used
// The key condition is A[mid]>=A[low] or not. This helps us distinguish different cases.
 

class Solution {
public:
    int search(int A[], int n, int target) {
        int low = 0, high = n - 1, mid;
        while (low <= high) {
            mid = low + ((high - low)>>1);
            
            if (A[mid] == target) {
                return mid;
            }
            
            if (A[mid] >= A[low]) {
                if (A[low] <= target && target < A[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            else /* A[mid] < A[low]*/
            {
                if (A[mid] < target && target <= A[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        return -1;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    int A[] = {3,1};
    cout << s.search(A, 2, 1) << endl;
    return 0;
}
