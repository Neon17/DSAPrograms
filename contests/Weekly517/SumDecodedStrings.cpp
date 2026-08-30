// Leetcode Medium Q2. Sum of Decoded Numbers©leetcode

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
    long long powMod(long long x, long long n, long long M) {
        long long res = 1;
        x = x % M;
        while (n > 0) {
            if (n & 1) res = (res * x) % M;
            x = (x * x) % M;
            n >>= 1;
        }
        return res;
    }

    int sumDecoded(vector<long long>& nums) {
        long long d, x, y, ans;
        int res = 0, width = 0;
        string test = "";
        long long size = 0, placevalue = 0, divide = 0;
        int val = 1e9 + 7;
        
        for (int i=0;i<nums.size();i++){
            width = nums[i]%10;
            d = floor(nums[i]/10);
            test = to_string(d);
            size = test.size();
            placevalue = pow(10, size-1);
            divide = pow(10, size-width);
            x = floor(d/divide);
            y = d % divide;
            ans = powMod(x, y, val);
            res = (res + ans) % val;
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<long long> nums;

    nums = {231};
    cout<<sol.sumDecoded(nums)<<endl;
    
    nums = {2522,2101};
    cout<<sol.sumDecoded(nums)<<endl;

    nums = {2301};
    cout<<sol.sumDecoded(nums)<<endl;

    nums = {55162,86552};
    cout<<sol.sumDecoded(nums)<<endl; // 87497779

    return 0;
}

