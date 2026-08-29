/*
Leetcode Hard 992. Subarrays with K Different Integers

Given an integer array nums and an integer k, return the number of good subarrays of nums.

A good array is an array where the number of different integers in that array is exactly k.

For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.

Constraints:
1 <= nums.length <= 2 * 104
1 <= nums[i], k <= nums.length
*/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // We can go from bruteforce then obviously optimize it for sliding window trick

    int bruteforceSubarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0, sum = 0, temp = 0;

        for (int i=0;i<n;i++){
            unordered_set<int> set; temp = 0;
            sum = 0;

            for (int j=i;j<n;j++){
                if (sum == k) temp++;
                sum += (set.count(nums[j]))?0:1;
                if (sum > k) break;
                set.insert(nums[j]);
            }
            if (sum == k) temp++;
            ans += temp;
        }
        return ans;
    }
    int countBound(vector<int>& nums, int bound){
        if (bound == 0) return 0;
        int n = nums.size(), ans = 0, sum = 0, left = 0;
        unordered_map<int, int> map;
        for (int i=0;i<n;i++) map[nums[i]] = 0;

        for (int i=0;i<n;i++){
            if (map[nums[i]] == 0) sum++;

            while (left < i && sum > bound){
                map[nums[left]]--;
                if (map[nums[left]] == 0) sum--;
                left++;
            }
            ans += (i - left + 1);
            map[nums[i]]++;
        }
        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return countBound(nums, k) - countBound(nums, k-1);
    }
};

int main(){
    Solution s; vector<int> nums; int k;
    nums = {1, 2, 1, 2, 3};
    k = 2;
    cout << s.subarraysWithKDistinct(nums, k) << endl;

    nums = {1, 2, 1, 3, 4};
    k = 3;
    cout << s.subarraysWithKDistinct(nums, k) << endl;
    return 0;
}

