/*
    Leetcode Medium 260. Single Number III

    Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. 
    Find the two elements that appear only once. 
    You can return the answer in any order.
    You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.

    Constraints:
        2 <= nums.length <= 3 * 104
        -231 <= nums[i] <= 231 - 1
        Each integer in nums will appear twice, only two integers will appear once.
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // vector<int> singleNumber(vector<int>& nums) {
    //     unordered_map<int, int> map;
    //     vector<int> res;
    //     for (int i=0;i<nums.size();i++){
    //         map[nums[i]]++;
    //     }
    //     for (int i=0;i<nums.size();i++){
    //         if (map[nums[i]] == 1) res.push_back(nums[i]);
    //     }
    //     return res;
    // }
    vector<int> singleNumber(vector<int>& nums) {
        int xorsum = 0;
        for (int num : nums) {
            xorsum ^= num;
        }    
        unsigned int diff = static_cast<unsigned int>(xorsum);
        unsigned int rightmost = diff & -diff; 
        int a = 0, b = 0;
        for (int num: nums){
            if (num & rightmost){
                a ^= num;
            } else {
                b ^= num;
            }
        }
        return {a,b};
    }
};

void printVector(vector<int> v){
    for (int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main(){
    Solution s;
    vector<int> nums, res;

    nums  = {1,2,1,3,2,5};
    res = s.singleNumber(nums);
    printVector(res);

    nums  = {-1,0};
    res = s.singleNumber(nums);
    printVector(res);

    nums = {0,1};
    res = s.singleNumber(nums);
    printVector(res);

    nums = {-1, -2,-2, 1, -1, 2, 2, 3};
    res = s.singleNumber(nums);
    printVector(res);
    return 0;
}

