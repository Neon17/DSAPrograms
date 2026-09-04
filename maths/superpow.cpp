/*
    Leetcode Medium 372. Super Pow

    Your task is to calculate ab mod 1337 where 
    a is a positive integer and b is an extremely large positive integer given in the form of an array.

    Constraints:
        1 <= a <= 2^31 - 1
        1 <= b.length <= 2000
        0 <= b[i] <= 9
        b does not contain leading zeros.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // we don't have to deal with negative exp in this problem
    int powmod(int num, int exp, int mod){
        if (exp == 0) return 1;
        else if (exp == 1) return (num % mod);
        long long half = powmod(num, exp/2, mod);
        half = (half * half) % mod;
        if (exp % 2 == 0) return half;
        return (num % mod * half) % mod;
    }

    int superPow(int a, vector<int>& b) {
        int res = 1;
        for (int i=0;i<b.size();i++){
            res = powmod(res, 10, 1337);
            res = res * powmod(a, b[i], 1337) % 1337;
        }
        return res;
    }
};

int main(){
    Solution s;
    int a; vector<int> b;

    a = 2; b = {3};
    cout<<s.superPow(a, b)<<endl;

    a = 1; b = {4,5,6};
    cout<<s.superPow(a, b)<<endl;

    a = 2147483647; b = {2,0,0};
    cout<<s.superPow(a, b)<<endl;

    return 0;
}

