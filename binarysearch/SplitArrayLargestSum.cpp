// Leetcode Hard 410. Split Array Largest Sum
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canSplit(vector<int>& nums, int mid, int k){
        int n = nums.size();
        int left = 0, right = 1;
        int subarrays = 1;
        int sum = nums[left];
        for (right = 1; right < nums.size(); right++){
            sum += nums[right];
            if (sum > mid) {
                sum = nums[right];
                left = right;
                subarrays++;
                if (subarrays > k) return false;
            }
        }
        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        int left = INT_MIN, right = 0, n = nums.size(), mid = 0, sum = INT_MAX, temp = 0;
        for (int i = 0;i<nums.size();i++){
            left = max(left, nums[i]);
            right += nums[i];
        }
        while (left < right){
            mid = left + (right - left)/2;
            temp = canSplit(nums, mid, k);
            if (canSplit(nums, mid, k)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};

int main() {
    Solution sol;
    vector<int> nums;
    int k, ans;

    nums = {7, 2, 5, 10, 8};
    k = 2;
    ans = sol.splitArray(nums, k);
    cout << ans << endl;

    nums = {1, 2, 3, 4, 5};
    k = 2;
    ans = sol.splitArray(nums, k);
    cout << ans << endl;

    nums = {1, 4, 4};
    k = 3;
    ans = sol.splitArray(nums, k);
    cout << ans << endl;

    return 0;
}
