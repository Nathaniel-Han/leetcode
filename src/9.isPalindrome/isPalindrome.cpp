#include<stdio.h>
#include<assert.h>


class Solution {
public:

	bool isPalindrome(int x) {
		if(x<0)
			return false;

		int reverse = 0, original = x;
		int remainder;
		while (x) {
			remainder = x % 10;
			reverse = reverse * 10 + remainder;
			x = x / 10;
		}
		//printf("%d\n", reverse);

		return (reverse == original);
	}
};

int main() {
	Solution s;
	assert(s.isPalindrome(123) == false);
	assert(s.isPalindrome(121) == true);
	assert(s.isPalindrome(0) == true);
	assert(s.isPalindrome(-121) == false);
	assert(s.isPalindrome(-123) == false);



	return 0;
}


