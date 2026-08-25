/**
    Leetcode Medium 2104. Sum of Subarray Ranges

    You are given an integer array nums. 
    The range of a subarray of nums is the 
        difference between the largest and smallest element in the subarray.
    Return the sum of all subarray ranges of nums.
    A subarray is a contiguous non-empty sequence of elements within an array.
 
 */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long mini = 0, maxi = 0;
        long long stack_sum = 0;
        int dominations = 0;
        stack<pair<int, int>> st;

        for(int i=0; i<nums.size(); i++){
            dominations = 1;
            while (!st.empty() && st.top().first >= nums[i]){
                mini += nums[i] * st.top().second;
                dominations += st.top().second;
                stack_sum -= st.top().second * st.top().first;
                st.pop();
            }
            mini += nums[i] + stack_sum;
            st.push({nums[i], dominations});
            stack_sum += nums[i] * dominations;
        }
        while (!st.empty()) st.pop();
        stack_sum = 0;
        for (int i=0;i<nums.size();i++){
            dominations = 1;
            while (!st.empty() && st.top().first <= nums[i]){
                maxi += nums[i] * st.top().second;
                dominations += st.top().second;
                stack_sum -= st.top().second * st.top().first;
                st.pop();
            }
            maxi += nums[i] + stack_sum;
            st.push({nums[i], dominations});
            stack_sum += nums[i] * dominations;
        }
        return maxi - mini;
    }
};

int main(){
    Solution solution;
    vector<int> nums;

    nums = {1,2,3};
    cout << solution.subArrayRanges(nums) << endl;

    nums = {1,3,3};
    cout << solution.subArrayRanges(nums) << endl;

    nums = {4,-2,-3,4,1};
    cout << solution.subArrayRanges(nums) << endl;

    return 0;
}
