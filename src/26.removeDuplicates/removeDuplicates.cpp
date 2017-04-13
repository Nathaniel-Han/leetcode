/* Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array A = [1,1,2],

Your function should return length = 2, and A is now [1,2].*/

#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {

        if(n == 0)
            return 0;

        int prev = A[0];
        for (int i = 1;i < n; i++) {

            int j = i;
            while (A[j] == prev && j < n) {
                j++;
            }

            if (j != i) {
                memmove(A+i, A+j, sizeof(int)*(n-j));
                n = n - (j-i);

            }

            prev = A[i];

        }
        return n;

    }
};

int main(int argc, const char * argv[]) {
    int A[] = {1,1,2,3};
    Solution s;
    cout << s.removeDuplicates(A, 4)<<endl;
    return 0;
}
