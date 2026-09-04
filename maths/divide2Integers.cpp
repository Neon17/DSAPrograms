/*
Leetcode Medium 29. Divide Two Integers

Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

The integer division should truncate toward zero, which means losing its fractional part. 
For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.

Return the quotient after dividing dividend by divisor.

Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−2^31, 2^31 − 1]. 
For this problem, if the quotient is strictly greater than 2^31 - 1, then return 2^31 - 1, and 
    if the quotient is strictly less than -2^31, then return -2^31.

Constraints:
    -2^31 <= dividend, divisor <= 2^31 - 1
    divisor != 0
*/

#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

class Solution {
public:
    long long findQuotient(long long dividend, long long divisor){
        long long ans = 0, multiple = 0, rem = 0;
        int power = 1;

        while (dividend >= divisor){
            multiple = divisor;
            power = 1;

            while (multiple < dividend){
                power <<= 1;
                multiple <<= 1;
            }
            if (multiple > dividend){
                power >>= 1;
                multiple >>= 1;
            }
            dividend -= multiple;
            ans += power;
        } 
        return ans;
    }

    int divide(int dividend, int divisor) {
        if (dividend == 0) return 0;
        else if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        else if (divisor == 1) return dividend;
        else if (dividend == divisor) return 1;
        else if (divisor == -1) return -dividend;

        int sign = 1, res = 0;
        sign = (dividend < 0) ^ (divisor < 0);

        long long dividend2 = abs((long long) dividend);
        long long divisor2 = abs((long long) divisor);
        long long quotient = findQuotient(dividend2, divisor2);
        if (sign) quotient = -quotient;

        if (quotient > INT_MAX) res = INT_MAX;
        else if (quotient < INT_MIN) res = INT_MIN;
        else res = quotient;

        return res;
    }
};

int main(){
    Solution s;
    int dividend, divisor;

    dividend = 10; divisor = 3;
    cout << s.divide(dividend, divisor)<<endl;

    dividend = 7; divisor = -3;
    cout << s.divide(dividend, divisor)<<endl;

    return 0;
}

