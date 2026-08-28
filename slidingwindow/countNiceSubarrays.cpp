/*
Leetcode Medium 1248. Count Number of Nice Subarrays

Given an array of integers nums and an integer k. 
A continuous subarray is called nice if there are k odd numbers on it.
Return the number of nice sub-arrays.

Constraints:
1 <= nums.length <= 50000
1 <= nums[i] <= 10^5
1 <= k <= nums.length
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int maxval = 0, left = 0, right = 0, oddCount = 0;

        for (right; right < nums.size(); right++){
            if (nums[right] % 2 == 1) oddCount++;
            while (oddCount > k){
                if (nums[left] % 2 == 1) oddCount--;
                left++;
            }
            maxval += right - left + 1;
        }

        return maxval;
    }
};

int main(){
    Solution solution;
    vector<int> nums; int k;

    nums = {1,1,2,1,1}; k = 3;
    cout << solution.numberOfSubarrays(nums, k) << endl;

    nums = {2,4,6}; k = 1;
    cout << solution.numberOfSubarrays(nums, k) << endl;

    nums = {2,2,2,1,2,2,1,2,2,2}; k = 2;
    cout << solution.numberOfSubarrays(nums, k) << endl;

    return 0;
}

