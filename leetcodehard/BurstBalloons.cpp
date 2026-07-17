// Leetcode Hard: 312. Burst Balloons
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> dp;

    int backtrack(vector<int>& nums, int left, int right){
        if (right - left <= 1) return dp[left][right] = 0;
        if (dp[left][right] != -1) return dp[left][right];

        int coins = 0;
        for (int i = left + 1; i < right; i++){
            int lefte = (left <= 0)? 1: nums[left-1];
            int righte = (right > nums.size())? 1: nums[right-1];
            coins = max(coins, backtrack(nums, left, i) + backtrack(nums, i, right) + lefte * righte * nums[i-1]);
        }

        return dp[left][right] = coins;
    }

    int maxCoins(vector<int>& nums) {
        dp.resize(nums.size()+2, vector<int>(nums.size()+2, -1));
        return backtrack(nums, 0, nums.size()+1);
    }
};

int main() {
    return 0;
}

