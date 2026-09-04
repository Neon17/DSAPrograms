/*
    Leetcode Medium 50. Pow(x, n)
    Implement pow(x, n), which calculates x raised to the power n (i.e., x^n).

    Constraints:
        -100.0 < x < 100.0
        -2^31 <= n <= 2^31-1
        n is an integer.
        Either x is not zero or n > 0.
        -10^4 <= x^n <= 10^4
*/
#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    double findOut(double x, long long n){
        if (n == 0) return 1.0;
        else if (n == 1) return x;
        else if (n < 0) return (double) (1/findOut(x, -n));
        else if (n % 2 == 0) {
            double half = findOut(x, n/2);
            return half * half;
        } 
        double half = findOut(x, (n-1)/2);
        return x * half * half;     
    }

    double myPow(double x, int n) {
        return findOut(x,n);
    }
};

int main(){
    Solution s; double x, n;

    x = 2.00000; n = 10;
    cout<<s.myPow(x, n)<<endl;

    x = 2.10000; n = 3;
    cout<<s.myPow(x, n)<<endl;

    x = 2.00000; n = -2;
    cout<<s.myPow(x, n)<<endl;

    return 0;
}


