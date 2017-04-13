#include<stdio.h>
#include<assert.h>

#define INT_MAX     2147483647
#define INT_MIN     (-INT_MAX - 1)

class Solution {
public:
	int reverse(int x) {
		int answer = 0, remainder;
		while (x) {
			remainder = x % 10;

			if (answer > INT_MAX / 10 || answer < INT_MIN / 10) {
				return 0;
			}
			answer = answer * 10 + remainder;
			x /= 10;
		}
		return answer;
	}
};

int main() {
	Solution s;
	assert(s.reverse(0) == 0);
	assert(s.reverse(1) == 1);
	assert(s.reverse(-23) == -32);
	assert(s.reverse(10) == 1);
	assert(s.reverse(-10) == -1);
	assert(s.reverse(5645654) == 4565465);
	assert(s.reverse(1000000003) == 0);

	return 0;
}
