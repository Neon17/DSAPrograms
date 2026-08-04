// Leetcode Medium 523. Continuous Subarray Sum

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int prefix = 0;
        unordered_set<int> set;
        set.insert(0);
        for (int i = 0;i<nums.size();i++){
            prefix = (prefix + nums[i]) % k;
            if (prefix < 0) prefix += k;
            if (set.count(prefix)) return true;
            set.insert(prefix);
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {23, 2, 4, 6, 7};
    int k = 6;
    bool result = sol.checkSubarraySum(nums, k);
    cout << "Continuous subarray sum divisible by " << k << ": " << (result ? "true" : "false") << endl;

    nums = {23, 2, 6, 4, 7};
    k = 6;
    result = sol.checkSubarraySum(nums, k);
    cout << "Continuous subarray sum divisible by " << k << ": " << (result ? "true" : "false") << endl;

    nums = {23, 2, 6, 4, 7};
    k = 13;
    result = sol.checkSubarraySum(nums, k);
    cout << "Continuous subarray sum divisible by " << k << ": " << (result ? "true" : "false") << endl;

    return 0;
}

