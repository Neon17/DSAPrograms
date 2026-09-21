/*
Leetcode Medium 1911. Maximum Alternating Subsequence Sum

The alternating sum of a 0-indexed array is defined as 
    the sum of the elements at even indices minus the sum of the elements at odd indices.

For example, the alternating sum of [4,2,5,3] is (4 + 5) - (2 + 3) = 4.
Given an array nums, return the maximum alternating sum of any subsequence of nums 
    (after reindexing the elements of the subsequence).

A subsequence of an array is a new array generated from the original array by 
    deleting some elements (possibly none) without 
        changing the remaining elements' relative order. 

For example, [2,7,4] is a subsequence of [4,2,3,7,2,1,4] (the underlined elements), while [2,4,2] is not.

Constraints:
1 <= nums.length <= 10^5
1 <= nums[i] <= 10^5
*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
    vector<vector<long long>> memo;
    long long bruteforce(vector<int>& nums, int index, int parity = 0){
        if (index >= nums.size()) return 0;
        if (memo[index][parity] != -1) return memo[index][parity];
        long long res = 0, temp = 0;

        temp = nums[index] * (parity == 0? 1: -1) + bruteforce(nums, index+1, !parity);
        res = max(temp, res);
        temp = bruteforce(nums, index+1, parity);
        res = max(temp, res);

        return memo[index][parity] = res;
    }
    long long convertDP(vector<int>& nums){
        int n = nums.size();
        long long pref[2] = {nums[n-1], 0}, temp = 0;

        for (int i=n-2;i>=0;i--){
            temp = pref[0];
            pref[0] = max(pref[0], nums[i] + pref[1]);
            pref[1] = max(pref[1], -nums[i] + temp);
        }
        return pref[0];
    }
public:
    long long maxAlternatingSum(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        memo.assign(nums.size(), vector<long long>(2, -1));        
        // return bruteforce(nums, nums.size()-1);
        return convertDP(nums);
    }
};

int main(){
    Solution sol;
    vector<int> nums;

    // nums = {4,2,5,3};
    // cout << sol.maxAlternatingSum(nums) << endl; // 7

    // nums = {5,6,7,8};
    // cout << sol.maxAlternatingSum(nums) << endl; // 8

    nums = {6,2,1,2,4,5};
    cout << sol.maxAlternatingSum(nums) << endl; // 10
    return 0;
}

