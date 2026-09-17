/*
Leetcode Medium 673. Number of Longest Increasing Subsequence

Given an integer array nums, return the number of longest increasing subsequences.

Notice that the sequence has to be strictly increasing.

Constraints:
1 <= nums.length <= 2000
-10^6 <= nums[i] <= 10^6
The answer is guaranteed to fit inside a 32-bit integer.
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> len(nums.size(), 1);
        vector<int> ways(nums.size(), 1);
        int maxi = INT_MIN, res = 0;

        for (int i=0;i<nums.size();i++){

            for (int j=0;j<i;j++){
                if (nums[j] < nums[i]){
                    if (len[j] + 1 > len[i]){
                        ways[i] = ways[j];
                        len[i] = len[j] + 1;
                    } else if (len[j] + 1 == len[i]) ways[i] += ways[j];
                }
            }
        }
        for (int i=0;i<ways.size();i++) maxi = max(maxi, len[i]);
        for (int i=0;i<ways.size();i++) {
            if (len[i] == maxi) res += ways[i];
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums;

    nums = {1,3,5,4,7};
    cout << s.findNumberOfLIS(nums) << endl; // 2

    nums = {2,2,2,2,2};
    cout << s.findNumberOfLIS(nums) << endl; // 5

    nums = {1,2,4,3,5,4,7,2};
    cout << s.findNumberOfLIS(nums) << endl; // 2

    return 0;
}


