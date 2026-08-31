// Leetcode Medium 75. Sort Colors
/*
You are given an array nums with n objects colored red, white, or blue, 
sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
You must solve this problem without using the library's sort function.
*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void printVector(const vector<int>& nums) {
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

class Solution {
public:
    void sortColors(vector<int>& nums) {
       int low = 0, mid = 0, high = nums.size()-1;

       while (mid <= high){
            if (nums[mid] == 0){
                swap(nums[mid], nums[low]);
                mid++;
                low++;
            } else if (nums[mid] == 1){
                mid++;
            } else {
                swap(nums[mid], nums[high]);
                high--;
            }
       }
    }
};

int main(){
    Solution sol;
    vector<int> nums;

    nums = {2,0,2,1,1,0};
    sol.sortColors(nums);
    printVector(nums); // Output: 0 0 1 1 2 2

    nums = {2,0,1};
    sol.sortColors(nums);
    printVector(nums); // Output: 0 1 2

    nums = {0};
    sol.sortColors(nums);
    printVector(nums); // Output: 0

    return 0;
}

