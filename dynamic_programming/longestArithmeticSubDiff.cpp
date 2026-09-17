/*
Leetcode Medium 1218. Longest Arithmetic Subsequence of Given Difference

Given an integer array arr and an integer difference, 
    return the length of the longest subsequence in arr which is an arithmetic sequence such that 
    the difference between adjacent elements in the subsequence equals difference.

A subsequence is a sequence that can be derived from arr by deleting some or no elements without changing the order of the remaining elements.

Constraints:
1 <= arr.length <= 10^5
-10^4 <= arr[i], difference <= 10^4
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int res = 0, target = 0;
        unordered_map<int,int> map;

        for (int i=0;i<arr.size();i++){
            target = arr[i] - difference;
            if (!map.count(target)) map[arr[i]] = 1;
            else map[arr[i]] = map[target] + 1;
        }
        for (auto [num, len]: map) res = max(res, len);
        return res;
    }
};

int main(){
    Solution s;
    vector<int> arr;
    int difference;

    arr = {1,2,3,4};
    difference = 1;
    cout << s.longestSubsequence(arr, difference) << endl; // 4

    arr = {1,3,5,7};
    difference = 1;
    cout << s.longestSubsequence(arr, difference) << endl; // 1

    arr = {1,5,7,8,5,3,4,2,1};
    difference = -2;
    cout << s.longestSubsequence(arr, difference) << endl; // 4

    return 0;
}
