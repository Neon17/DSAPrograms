/*
Leetcode Medium 152. Maximum Product Subarray

Given an integer array nums, find a subarray that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

Note that the product of an array with a single element is the value of that element.

Constraints:
1 <= nums.length <= 2 * 10^4
-10 <= nums[i] <= 10
The product of any subarray of nums is guaranteed to fit in a 32-bit integer.
*/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
    long long bruteforce(vector<int>& nums){
        int curr = 1, res = INT_MIN, size = nums.size();

        for (int i=size-1;i>=0;i--){
            curr = 1;

            for (int j=i;j>=0;j--){
                curr *= nums[j];
                res = max(curr, res);
            }
        }
        return res;
    }
    int convertToDP(vector<int>& nums){
        int prevMax = INT_MIN, prevMin = INT_MAX;
        int currMax = nums[0], currMin = nums[0];
        int res = nums[0];

        for (int i=1;i<nums.size();i++){
            prevMax = currMax;
            prevMin = currMin;
            currMax = max(nums[i], max(prevMax * nums[i], prevMin * nums[i]));
            currMin = min(nums[i], min(prevMax * nums[i], prevMin * nums[i]));
            res = max(res, currMax);            
        }
        return res;
    }
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        if (nums.size() == 1) return res;

        // res = bruteforce(nums);
        res = convertToDP(nums);
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums;

    nums = {2,3,-2,4};
    cout << s.maxProduct(nums) << endl; // Output: 6

    nums = {-2,0,-1};
    cout << s.maxProduct(nums) << endl; // Output: 0

    return 0;
}
