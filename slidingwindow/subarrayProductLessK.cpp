/*
    Leetcode Medium 713. Subarray Product Less Than K

    Given an array of integers nums and an integer k, 
    Return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k.

    Constraints:
        1 <= nums.length <= 3 * 10^4
        1 <= nums[i] <= 1000
        0 <= k <= 10^6
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left = 0, right = 0, n = nums.size(), res = 0;
        long long multiple = 1;
        
        for (right=0;right<n;right++){
            multiple *= nums[right];
            while (left < right && multiple >= k){
                multiple /= nums[left];
                left++;
            }
            if (multiple < k) res += (right - left + 1);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums; int k;

    nums = {10, 5, 2, 6}; k = 100;
    cout << s.numSubarrayProductLessThanK(nums, k) << endl; // Output: 8

    nums = {1, 2, 3}; k = 0;
    cout << s.numSubarrayProductLessThanK(nums, k) << endl; // Output: 0

    nums = {1, 2}; k = 2;
    cout << s.numSubarrayProductLessThanK(nums, k) << endl; // Output: 1
    return 0;
}

