/**
 * 33. Search in Rotated Sorted Array (Medium)

There is an integer array nums sorted in ascending order (with distinct values).
Prior to being passed to your function, nums is possibly left rotated at an unknown index k (1 <= k < nums.length) such that
the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). 
For example, [0,1,2,4,5,6,7] might be left rotated by 3 indices and become [4,5,6,7,0,1,2].
Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

Example 3:
Input: nums = [1], target = 0
Output: -1
 

Constraints:

1 <= nums.length <= 5000
-104 <= nums[i] <= 104
All values of nums are unique.
nums is an ascending array that is possibly rotated.
-104 <= target <= 104

Topics: Array, Binary Search
 * 
 */

 /**
  * I think we have to use 2 binary search
  * First one to find pivot point, start and end
  * Second one to find target from the start and end
  */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findTarget(vector<int>& nums, int target){
        int l = 0;
        int r = nums.size()-1;
        int mid = 0;

        while (l <= r){
            mid = l + (r-l)/2;
            if (nums[mid] == target) return mid;

            if (nums[l] <= nums[mid]){
                if (target >= nums[l] && target < nums[mid]) r = mid-1;
                else l = mid+1;
            } else {
                if (target > nums[mid] && target <= nums[r]) l = mid+1;
                else r = mid-1;
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) return -1;
        if (nums.size() == 1) {
            if (nums[0] == target) return 0;
            else return -1;
        }
        return findTarget(nums, target);
    }
};

int main() {
    vector<int> nums;
    int target = 0, result = 0;
    Solution solution;

    nums = {4,5,6,7,0,1,2}; target = 3;
    result = solution.search(nums, target);
    cout << "Result: " << result << endl;

    nums = {0,1,2,3,4,5}; target = 0;
    result = solution.search(nums, target);
    cout << "Result: " << result << endl;

    nums = {1,2,3,4,5,0}; target = 0;
    result = solution.search(nums, target);
    cout << "Result: " << result << endl;

    return 0;
}
