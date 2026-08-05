// Leetcode Medium 1590. Make Sum Divisible by P
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    // Below is Brute Force approach which is not optimal and will give TLE for large inputs
    // int minSubarray(vector<int>& nums, int p) {
    //     if (p == 1) return 0;
    //     int ans = -1, n = nums.size(), diff = 0, sum = 0;
    //     vector<int> prefix(n+1, 0);
    //     vector<int> suffix(n+1, 0);

    //     for (int i=0;i<nums.size();i++){
    //         prefix[i+1] = (prefix[i] + nums[i]) % p;
    //         suffix[n-i-1] = (suffix[n-i] + nums[n-1-i]) % p;
    //     }

    //     for (diff = 0; diff < n; diff++){
    //         if (diff == 0){
    //             if (prefix[n] % p == 0) return 0;
    //             continue;
    //         }
    //         for (int i=diff-1;i < (n - diff + 1); i++){
    //             if (i < diff){
    //                 if (suffix[i+1] % p == 0) return diff;
    //                 continue;
    //             } else if (i > n - diff ){
    //                 if (prefix[i+1] % p == 0) return diff;
    //                 continue;
    //             }
    //             if ( (prefix[i] + suffix[i+diff]) % p == 0 ) return diff;
    //         }
    //     }
    //     return ans;
    // }

    // Actually this problem solution lies on mathematical intuition
    // (TotalSum - SubarraySum) % p == 0
    // => TotalSum % p == SubarraySum % p
    // => target (say target equals TotalSum % p) = (prefixSum[i] - prefixSum[j]) % p // i is end and j is start of subarray -- formula 1
    // prefixSum[i] means sum of elements from 0 to i-1
    // using formula 1, we can say that prefixSum[j] % p = (prefixSum[i] - target) % p; 
    // => need = (prefixSum[i] - target) % p 
    // then we have to just store the each need (that is above equation's LHS) in map
    // If we find the need in map, then we can say that we have found a subarray which satisfies the condition

    int minSubarray(vector<int>& nums, int p){
        int n = nums.size(), sum = 0, diff = 0;
        int ans = n+1, cur = 0, need = 0;
        unordered_map<int, int> map;
        map[0] = -1;
        vector<int> prefix(n+1, 0);

        for (int i=0;i<n;i++) prefix[i+1] = (prefix[i] + nums[i]) % p;
        if (prefix[n] == 0) return 0;
        int target = prefix[n];

        for (int i=0;i<n;i++){
            cur = prefix[i+1];
            need = (cur - target + p)%p;
            if (map.find(need) != map.end()){
                int len = i - map[need];
                if (len < n)                   
                    ans = min(ans, len);
            }
            map[cur] = i;
        }

        return (ans == n+1)?-1:ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums;
    nums = {3,1,4,2};
    int p = 6;
    cout << sol.minSubarray(nums, p) << endl;

    nums.clear();
    nums = {6,3,5,2};
    p = 9;
    cout << sol.minSubarray(nums, p) << endl;

    nums.clear();
    nums = {1,2,3};
    p = 3;
    cout << sol.minSubarray(nums, p) << endl;

    return 0;
}
