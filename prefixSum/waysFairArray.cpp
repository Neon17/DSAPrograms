/*
Leetcode Medium 1664. Ways to Make a Fair Array

You are given an integer array nums. 
You can choose exactly one index (0-indexed) and remove the element. 
Notice that the index of the elements may change after the removal.

For example, if nums = [6,1,7,4,1]:

Choosing to remove index 1 results in nums = [6,7,4,1].
Choosing to remove index 2 results in nums = [6,1,4,1].
Choosing to remove index 4 results in nums = [6,1,7,4].
An array is fair if the sum of the odd-indexed values equals the sum of the even-indexed values.

Return the number of indices that you could choose such that after the removal, nums is fair.

Constraints:
1 <= nums.length <= 10^5
1 <= nums[i] <= 10^4
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size(), res = 0, oddsum = 0, evensum = 0;
        vector<int> odd(n, 0), even(n, 0);
        even[0] = nums[0];

        for (int i=1;i<n;i++){
            if (i % 2 == 0) {
                even[i] = even[i-1] + nums[i];
                odd[i] = odd[i-1];
            } else {
                even[i] = even[i-1];
                odd[i] = odd[i-1] + nums[i];
            }
        }
        oddsum = even[n-1] - even[0];
        if (oddsum == odd[n-1]) res++;
        for (int i=1;i<n;i++){
            oddsum = 0; evensum = 0;
            if (i % 2 == 0){
                oddsum = even[n-1] - even[i] + odd[i];
                evensum = odd[n-1] - odd[i] + even[i-1];
            } else {
                oddsum = even[n-1] - even[i] + odd[i-1];
                evensum = odd[n-1] - odd[i] + even[i];
            }
            if (evensum == oddsum) res++;
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<int> nums;
    int res = 0;

    nums = {2,1,6,4};
    cout<< sol.waysToMakeFair(nums) << endl; // 1

    nums = {1,1,1};
    cout<< sol.waysToMakeFair(nums) << endl; // 3

    nums = {1,2,3};
    cout<< sol.waysToMakeFair(nums) << endl; // 0
    return 0;
}

