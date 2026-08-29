/*
Leetcode Medium 795. Number of Subarrays with Bounded Maximum

Given an integer array nums and two integers left and right, 
return the number of contiguous non-empty subarrays such that the value of the maximum array element in that subarray is in the range [left, right].
The test cases are generated so that the answer will fit in a 32-bit integer.

Constraints:
1 <= nums.length <= 10^5
0 <= nums[i] <= 10^9
0 <= left <= right <= 10^9
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Below commented lines of code are my made clever 2 pointer approach to solve the problem

    // int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
    //     int count = 0, leftidx = -1, rightidx = 0, n = nums.size();
    //     int lastindex = -1; // last value of nums[rightidx] that is greater than the range [left, right]

    //     for (int i=0;i<nums.size();i++){
    //         if (nums[i] > right) {
    //             leftidx = i; lastindex = i; continue;
    //         }
    //         if (nums[i] < left && (leftidx == -1 || nums[leftidx] > right)) continue;
    //         if (nums[i] >= left && nums[i] <= right){
    //             count += i - lastindex;
    //             leftidx = i;
    //         } else count += leftidx - lastindex;
    //     }
    //     return count;
    // }

    // Below is standard solution to problem
    int calculateBound(vector<int>& nums, int bound){
        int curr = 0, count = 0;
        for (int x: nums){
            curr = x <= bound? curr + 1: 0;
            count += curr;
        }
        return count;
    }

    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        return calculateBound(nums, right) - calculateBound(nums, left-1);
    }
    
};

int main(){
    Solution s;
    vector<int> nums; int left, right;
    nums = {2,1,4,3}; left = 2; right = 3;
    cout << s.numSubarrayBoundedMax(nums, left, right) << endl;
    nums = {2,9,2,5,6}; left = 2; right = 8;
    cout << s.numSubarrayBoundedMax(nums, left, right) << endl;
    nums = {2,9,2,1,5,6}; left = 2; right = 8;
    cout << s.numSubarrayBoundedMax(nums, left, right) << endl;
    nums = {1,2,1,3}; left = 2; right = 3;
    cout << s.numSubarrayBoundedMax(nums, left, right) << endl;
    return 0;
}

