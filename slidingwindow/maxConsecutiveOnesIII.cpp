/*
Leetcode Medium 1004. Max Consecutive Ones III

Given a binary array nums and an integer k, 
return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

Constraints:
1 <= nums.length <= 10^5
nums[i] is either 0 or 1.
0 <= k <= nums.length
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0, maxval = 0, zeroCount = 0;
        queue<int> zeros; 
        // we can directly loop through array to increase left and reduce number of zeros

        for (right; right<nums.size();right++){
            if (nums[right] == 0) {
                zeros.push(right);
                zeroCount++;
            }
            if (zeroCount > k) {
                left = zeros.front() + 1;
                zeros.pop();
                zeroCount--;
            }
            maxval = max(maxval, right - left + 1);
        }
        return maxval;
    }
};

int main(){
    vector<int> nums; int k;
    Solution solution;

    nums = {1,1,1,0,0,0,1,1,1,1,0}; k = 2;
    cout << solution.longestOnes(nums, k) << endl;

    nums = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1}; k = 3;
    cout << solution.longestOnes(nums, k) << endl;

    return 0;
}
