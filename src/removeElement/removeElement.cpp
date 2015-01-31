/* Given an array and a value, remove all instances of that value in place and return the new length.

 The order of elements can be changed. It doesn't matter what you leave beyond the new length. */

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

class Solution {
public:
	int removeElement(int A[], int n, int elem) {

		if (n == 0)
			return 0;

		qsort(A, n, sizeof(int), compare_ints);

		int low = 0, high = n - 1, mid;
		while (low < high) {
			mid = low + ((high - low) >> 1);
			if (elem < A[mid]) {
				high = mid - 1;
			} else if (elem > A[mid]) {
				low = mid + 1;
			} else
				break;
		}

		if (elem == A[low])
			mid = low;

		if (elem == A[mid]) {
			int pos1, pos2;
			pos1 = pos2 = mid;
			do {
				pos1--;
			} while (elem == A[pos1] && pos1 >= 0);

			do {
				pos2++;
			} while (elem == A[pos2] && pos2 < n);

			memmove(A + pos1 + 1, A + pos2, sizeof(int) * (n - pos2));
			return n - pos2 + pos1 + 1;
		}

		else
			return n;

	}

	static int compare_ints(const void* a, const void* b) {
		int arg1 = *(const int*) a;
		int arg2 = *(const int*) b;

		if (arg1 < arg2)
			return -1;
		if (arg1 > arg2)
			return 1;
		return 0;
	}

};

int main() {
	int A[] = { 4, 5 };
	Solution s;
	cout << s.removeElement(A, 2, 5) << endl;
	return 0;
}
