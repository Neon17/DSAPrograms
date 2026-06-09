/** 53. Maximum Subarray (Leetcode Medium)
 * 
 * Given an integer array nums, find the subarray with the largest sum, and return its sum.
 * 
 * Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
 * Output: 6
 * Explanation: The subarray [4,-1,2,1] has the largest sum 6.
 * Example 2:
 * 
 * Input: nums = [1]
 * Output: 1
 * Explanation: The subarray [1] has the largest sum 1.
 * Example 3:
 * 
 * Input: nums = [5,4,-1,7,8]
 * Output: 23
 * Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
 *  
 * Constraints:
 * 1 <= nums.length <= 105
 * -104 <= nums[i] <= 104
 * 
 * Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
 * 
 * Topics: Dynamic Programming, Divide and Conquer, Array
 */

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    // int maxSubArray(vector<int>& nums) {
    //     int maxSum = nums[0];
    //     int currentSum = nums[0];

    //     for (int i=1;i<nums.size();i++){
    //         currentSum += nums[i];
    //         if (nums[i] > currentSum){
    //             currentSum = nums[i];
    //         }
    //         if (maxSum < currentSum) maxSum = currentSum;
    //     }
    //     return maxSum;
    // }
    
    struct position {
        int prefixSum;
        int suffixSum;
        int totalSum;
        int maxSum;
    };

    position divideConquer(vector<int>& nums, int l, int r) {
        if (l == r) {
            return {nums[l], nums[l], nums[l], nums[l]};
        }
        int m = l + (r - l) / 2;
        position left = divideConquer(nums, l, m);
        position right = divideConquer(nums, m + 1, r);

        position res;
        res.totalSum = left.totalSum + right.totalSum;
        res.prefixSum = max(left.prefixSum, left.totalSum + right.prefixSum);
        res.suffixSum = max(right.suffixSum, right.totalSum + left.suffixSum);
        res.maxSum = max(max(left.maxSum, right.maxSum), left.suffixSum + right.prefixSum);
        return res;
    }

    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return 0;
        return divideConquer(nums, 0, nums.size() - 1).maxSum;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> testCases = {
        {-2,1,-3,4,-1,2,1,-5,4},
        {1},
        {5,4,-1,7,8}
    };

    for (auto testCase: testCases) {
        cout<<sol.maxSubArray(testCase)<<endl;
    }

    return 0;
}

