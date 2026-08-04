// Leetcode Medium 525. Contiguous Array

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int ans = 0, prefix = 0;
        unordered_map<int, int> first;
        first[0] = -1;

        for (int i=0;i<nums.size();i++){
            prefix += (nums[i] == 0? -1: 1);

            if (first.find(prefix) != first.end()){
                ans = max(ans, i - first[prefix]);
            } else {
                first[prefix] = i;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {0, 1};
    int result = sol.findMaxLength(nums);
    cout << "Max length of contiguous array: " << result << endl;

    nums = {0, 1, 0};
    result = sol.findMaxLength(nums);
    cout << "Max length of contiguous array: " << result << endl;

    nums = {0, 1, 0, 1, 0, 1};
    result = sol.findMaxLength(nums);
    cout << "Max length of contiguous array: " << result << endl;

    return 0;
}
