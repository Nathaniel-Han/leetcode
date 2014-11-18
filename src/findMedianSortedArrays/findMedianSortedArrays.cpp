#include<iostream>
using namespace std;

class Solution {
public:
	// no binary-search version
	double findMedianSortedArrays(int A[], int m, int B[], int n) {
		double answer;
		int a_pos = 0, b_pos = 0, total = 0;
		int mid_index;
		int next; // for even case
		bool isEven;
		if ((m + n) % 2 != 0) {
			// odd
			mid_index = (m + n) / 2;
			isEven = false;
		} else {
			// even
			mid_index = (m + n) / 2 - 1;
			isEven = true;
		}

		while (a_pos < m && b_pos < n && total < mid_index) {
			if (A[a_pos] < B[b_pos]) {
				a_pos++;
				total++;
			} else if (A[a_pos] > B[b_pos]) {
				b_pos++;
				total++;
			}
			else {
				a_pos++;
				total++;
				if(total == mid_index)
					break;
				b_pos++;
				total++;
			}
		}


		if (total == mid_index && a_pos < m && b_pos < n) {
			if (A[a_pos] <= B[b_pos]) {
				answer = A[a_pos];
				a_pos++;
			} else {
				answer = B[b_pos];
				b_pos++;
			}

			if (isEven) {
				if (a_pos < m && b_pos < n) {
					next = A[a_pos] <= B[b_pos] ? A[a_pos] : B[b_pos];
					answer = (answer + next) / 2;
				} else if (a_pos == m) {
					next = B[b_pos];
					answer = (answer + next) / 2;
				} else {
					next = A[a_pos];
					answer = (answer + next) / 2;
				}
			}
		}

		else if (a_pos == m) {
			b_pos += (mid_index - total);
			answer = B[b_pos];

			if (isEven) {
				next = B[b_pos + 1];
				answer = (answer + next) / 2;
			}

		} else {
			a_pos += (mid_index - total);
			answer = A[a_pos];

			if (isEven) {
				next = A[a_pos + 1];
				answer = (answer + next) / 2;
			}
		}

		return answer;
	}
};

int main() {
	//	int A[] = { 1, 4, 6, 8 };
	//	int B[] = { 2, 5, 9, 13 };

	int A[] = { 1, 2};
	int B[] = { 1, 1};

	//	int A[] = {1,3};
	//	int B[] = {2,4};
	Solution s;
	double answer = s.findMedianSortedArrays(A, 2, B, 2);

	cout << answer << endl;

	return 0;
}
