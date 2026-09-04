/*
    Leetcode Medium 1492. The kth Factor of n

    You are given two positive integers n and k. 
    A factor of an integer n is defined as an integer i where n % i == 0.
    Consider a list of all factors of n sorted in ascending order, 
    return the kth factor in this list or return -1 if n has less than k factors.

    Constraints:
        1 <= k <= n <= 1000
*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int kthFactor(int n, int k) {
        int count = 0;
        vector<int> factors;

        for (int i = 1; i * i <= n; ++i) {
            if (n % i == 0) {
                count++;
                factors.push_back(n / i);
                if (count == k) return i;
            }
        }

        int m = sqrt(n);
        int total = (m * m == n) ? (count * 2 - 1) : (count * 2);
        if (total < k) return -1;

        int rem = k - count;
        int idx = (m * m == n) ? (count - rem - 1) : (count - rem);
        return factors[idx];
    }
};

int main(){
    Solution s;
    int n, k, res;

    n = 12; k = 3;
    res = s.kthFactor(n, k);
    cout<<res<<endl;

    n = 7; k = 2;
    res = s.kthFactor(n, k);
    cout<<res<<endl;

    n = 4; k = 4;
    res = s.kthFactor(n, k);
    cout<<res<<endl;

    n = 1; k = 1;
    res = s.kthFactor(n, k);
    cout<<res<<endl;

    n = 1000; k = 3;
    res = s.kthFactor(n, k);
    cout<<res<<endl;

    return 0;
}

