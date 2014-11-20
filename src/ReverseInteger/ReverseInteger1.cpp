#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<cstring>
#include<cassert>
#include<cmath>
using namespace std;

class Solution {
public:
	//instead of numerical computation, manipulate string
	//transfer integer to string, use stack to reverse
	//to detect overflow/underflow, it seems to cost much time
	int reverse(int x) {
		if (x == 0)
			return 0;

		int answer;
		bool isPositive;
		if (x >= 0) {
			isPositive = true;
		} else {
			isPositive = false;
			x = -x;
			//overflow case
			if (x < 0)
				return 0;
		}

		int exp = log(x) / log(10);
		char buf[exp + 2];
		string rev;
		stack<int> helper;
		sprintf(buf, "%d", x);

		for (int i = 0; i < exp + 1; i++) {
			helper.push(buf[i]);
		}

		while (!helper.empty()) {
			rev.push_back(helper.top());
			helper.pop();
		}

		//detect overflow/underflow
		if ((strlen(rev.c_str()) == 10 && strcmp(rev.c_str(), "2147483647") > 0)
				|| strlen(rev.c_str()) > 10) {
			return 0;
		}

		answer = atoi(rev.c_str());

		if (!isPositive)
			return -answer;

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
