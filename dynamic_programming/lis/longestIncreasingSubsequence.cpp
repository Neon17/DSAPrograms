/*
Leetcode Medium 300. Longest Increasing Subsequence

Given an integer array nums, return the length of the longest strictly increasing subsequence.

A subsequence is a sequence that can be derived from an array by deleting some or no elements 
    without changing the order of the remaining elements.

Constraints:
    0 <= nums.length <= 2500
    -10^4 <= nums[i] <= 10^4

Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?
*/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
    vector<int> dp;
    int bruteforce(vector<int>& nums, int index = 0){
        if (dp[index] != -1) return dp[index];
        int size = nums.size(), res = 1, curr = 0;

        for (int i=index+1;i<size;i++){
            if (nums[i] > nums[index]) { 
                curr = bruteforce(nums, i);
                res = max(res, curr+1); 
            }           
        }    
        return dp[index] = res;
    }
    int convertToDP(vector<int>& nums){
        int res = 0;
        for (int i=0;i<nums.size();i++){
            dp[i] = 1;
            for (int j=i-1;j>=0;j--){
                if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j]+1);
            }
            res = max(res, dp[i]);
        }
        return res;
    }
    int binarySearch(vector<int>& nums){
        int left = INT_MAX, right = INT_MIN, mid = 0;
        vector<int> tails;
        for (int i=0;i<nums.size();i++){

            if (tails.empty() || tails[tails.size()-1] < nums[i]) {
                tails.push_back(nums[i]);
                continue;
            }
            left = 0; right = tails.size()-1;
            while (left < right){
                mid = left + (right - left)/2;

                if (tails[mid] < nums[i]) left = mid+1;
                else if (tails[mid] >= nums[i]) right = mid;
            }
            tails[left] = nums[i];
        }
        return tails.size();
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        int res = 0;
        dp.assign(nums.size(), -1);
        // dp[nums.size()-1] = 1;
        // int curr = 0;
        // for (int i=0;i<nums.size();i++){
        //     curr = bruteforce(nums, i);
        //     res = max(res, curr);
        // }
        // res = convertToDP(nums);
        res = binarySearch(nums);
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums;

    nums = {10,9,2,5,3,7,101,18};
    cout << s.lengthOfLIS(nums) << endl; // Output: 4

    nums = {0,1,0,3,2,3};
    cout << s.lengthOfLIS(nums) << endl; // Output: 4

    nums = {7,7,7,7,7,7,7};
    cout << s.lengthOfLIS(nums) << endl; // Output: 1
    return 0;
}
