/*
Leetcode Medium 1027. Longest Arithmetic Subsequence

Given an array nums of integers, return the length of the longest arithmetic subsequence in nums.

Note that:

A subsequence is an array that can be derived from another array by deleting some or no elements 
    without changing the order of the remaining elements.
A sequence seq is arithmetic if seq[i + 1] - seq[i] are all the same value (for 0 <= i < seq.length - 1).

Constraints:
2 <= nums.length <= 1500
0 <= nums[i] <= 500
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {

    int bruteforce(vector<int>& nums){
        if (nums.size()==2) return 2;
        int res = 0, target = 0, temp = 0, index = 0, curr = 0, diff = 0;
        unordered_map<int, vector<int>> mp;
        for (int i=0;i<nums.size();i++) mp[nums[i]].push_back(i);

        for (int i=0;i<nums.size()-1;i++){
            res = max(res, 2);
            
            for (int j=i+1;j<nums.size();j++){
                diff = nums[j] - nums[i];
                target = nums[j] + diff;
                curr = 2; index = j;
                if (!mp.count(target)) continue;

                while (index < nums.size()){
                    temp = index;
                    for (auto vec: mp[target]){
                        if (vec <= index) continue;
                        index = vec; break;
                    }         
                    if (index == temp) break;
                    target = nums[index] + diff;    
                    curr++;
                }
                res = max(res, curr);
                if (res == nums.size()) return res;
            }
        }        
        return res;
    }

    int convertToDP(vector<int>& nums){
        // according to constraint we have -500 to 500
        vector<vector<int>> dp(nums.size(), vector<int>(1001, 1));

        for (int i=0;i<nums.size();i++){
            for (int j=0;j<i;j++){
                int diff = nums[i] - nums[j] + 500;
                dp[i][diff] = dp[j][diff] + 1;
            }
        }
        int res = 0;
        for (int i=0;i<nums.size();i++){
            for (int j=0;j<1001;j++){
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }

public:
    int longestArithSeqLength(vector<int>& nums) {
        // return bruteforce(nums);
        return convertToDP(nums);
    }
};

int main(){
    Solution s;
    vector<int> nums;

    nums = {3,6,9,12};
    cout << s.longestArithSeqLength(nums) << endl; // 4

    nums = {9,4,7,2,10};
    cout << s.longestArithSeqLength(nums) << endl; // 3

    nums = {20,1,15,3,10,5,8};
    cout << s.longestArithSeqLength(nums) << endl; // 4

    return 0;
}

