/*
 Divide two integers without using multiplication, division and mod operator.

 If it is overflow, return MAX_INT.
*/

#include <iostream>
#include <cassert>
using std::cout;
using std::endl;

class Solution {
public:
    int divide(int dividend, int divisor) {

        if (divisor == 0)
            return INT_MAX;


        // in case of overflow
        long long a = dividend >= 0 ? dividend : -(long long)dividend;
        long long b = divisor >= 0 ? divisor : -(long long)divisor;

        long long answer = 0, bb = b;
        int step = 0;
        while (a >= bb) {
            bb <<= 1;
            step++;
        }

        bb >>= 1;
        step--;

        /*always find the nearest one (bb) that is of the left-shift result of divisor
         to the dividend */
        while (a >= b) {
            if (a >= bb) {
                a -= bb;
                answer += 1u << step;
            }

            bb >>= 1;
            step--;
        }

        if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0))
            answer = -answer;

        //handle with integer overflow
        if (answer != int(answer)) {
            return INT_MAX;
        }

        return answer;
    }

};

int main(int argc, const char * argv[]) {
    Solution s;
    assert(s.divide(2, 12) == 0);
    assert(s.divide(12, 2) == 6);
    assert(s.divide(13, 4) == 3);
    assert(s.divide(13, -4) == -3);
    assert(s.divide(2147483647, 1) == 2147483647);
    assert(s.divide(-2147483648, -1) == 2147483647);
//    cout << s.divide(-2147483648, -1) << endl;
    return 0;
}
