// Leetcode Medium 974. Subarray Sums Divisible by K

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans = 0, prefix = 0;
        unordered_map<int, int> map;
        map[0] = 1;

        for (int i=0;i<nums.size();i++){
            prefix = (prefix + nums[i]) % k;
            if (prefix < 0) prefix += k;
            ans += map[prefix];
            map[prefix]++;
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {4,5,0,-2,-3,1};
    int k = 5;
    int result = s.subarraysDivByK(nums, k);
    cout << "Number of subarrays divisible by " << k << ": " << result << endl;

    nums = {5};
    k = 9;
    result = s.subarraysDivByK(nums, k);
    cout << "Number of subarrays divisible by " << k << ": " << result << endl;
    
    return 0;
}
