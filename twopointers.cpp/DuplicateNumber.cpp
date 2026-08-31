/*
    Leetcode Medium 287. Find the Duplicate Number

    Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
    There is only one repeated number in nums, return this repeated number.
    You must solve the problem without modifying the array nums and using only constant extra space.

    Constraints:
    1 <= n <= 10^5
    nums.length == n + 1
    1 <= nums[i] <= n
    All the integers in nums appear only once except for precisely one integer which appears two or more times.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    int countLess(vector<int>& nums, int n){
        int count = 0;
        for (int i=0;i<nums.size();i++){
            if (nums[i] <= n) count++;
        }
        return count;
    }
public:
    // int findDuplicate(vector<int>& nums) {
    //     sort(nums.begin(), nums.end());
    //     for (int i=1;i<nums.size();i++){
    //         if (nums[i] == nums[i-1]) return nums[i];
    //     }
    //     return 0;
    // }
    int findDuplicate(vector<int>& nums){
        int left = 1, right = nums.size()-1, mid = 0;
        while (left < right){
            mid = left + (right-left)/2;
            if (countLess(nums, mid) <= mid){
                left = mid+1;
            } else {
                right = mid;
            }
        }
        return left;
    }
    int findFloydDuplicate(vector<int>& nums){
        int slow = 0, fast = 0;
        slow = nums[0]; fast = nums[nums[0]];

        while (slow != fast){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        slow = 0;
        while (slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

int main(){
    Solution sol;
    vector<int> nums;

    nums = {1,3,4,2,2};
    cout << sol.findDuplicate(nums) << endl; // Output: 2

    nums = {3,1,3,4,2};
    cout << sol.findDuplicate(nums) << endl; // Output: 3

    nums = {3,3,3,3,3};
    cout << sol.findDuplicate(nums) << endl; // Output: 3

    nums = {1,1};
    cout << sol.findDuplicate(nums) << endl; // Output: 1

    nums = {1,1,2};
    cout << sol.findDuplicate(nums) << endl; // Output: 1

    return 0;
}
