/*
Leetcode Medium 930. Binary Subarrays With Sum

Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.
A subarray is a contiguous part of the array.

Constraints:
1 <= nums.length <= 3 * 10^4
nums[i] is either 0 or 1.
0 <= goal <= nums.length
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int maxval = 0, left = 0, right = 0, sum = 0, n = nums.size();
        vector<int> prefix(n, 0);
        for (int i = 0; i<n;i++){
            prefix[i] = sum;
            if (nums[i] == 0) sum++;
            else sum = 0;
        }
        sum = 0;

        if (goal == 0){
            for (int i = 0; i<n;i++){
                if (nums[i] == 0) maxval += prefix[i] + 1;
            }
            return maxval;
        }

        for (right = 0; right < n; right++){
            sum += nums[right];
            while (sum > goal){
                sum -= nums[left];
                left++;
            }
            while (nums[left] == 0) left++;
            if (sum == goal) maxval = maxval + prefix[left] + 1;
        }

        return maxval;
    }
};

int main(){
    Solution solution;
    vector<int> nums; int goal;

    nums = {1,0,1,0,1}; goal = 2;
    cout << solution.numSubarraysWithSum(nums, goal) << endl;

    nums = {0,0,0,0,0}; goal = 0;
    cout << solution.numSubarraysWithSum(nums, goal) << endl;

    return 0;
}
