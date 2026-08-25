// Leetcode Medium 907. Sum of Subarray Minimums
/*
Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. 
Since the answer may be large, return the answer modulo 10^9 + 7.

Example 1:
Input: arr = [3,1,2,4]
Output: 17
Explanation: 
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.

Example 2:
Input: arr = [11,81,94,43,3]
Output: 444
 
Constraints:
1 <= arr.length <= 3 * 10^4
1 <= arr[i] <= 3 * 10^4
*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<pair<int, int>> st; 
        long long res = 0; int dominations = 0;
        long long stack_sum = 0;

        for (int i = 0; i < arr.size(); i++) {
            dominations = 1;
            while (!st.empty() && st.top().first >= arr[i]){
                res += arr[i] * st.top().second;
                dominations += st.top().second;
                stack_sum -= st.top().first * st.top().second;
                st.pop();
            }
            res += arr[i] + stack_sum;
            st.push({arr[i], dominations});
            stack_sum += arr[i] * dominations;
        }

        int total = 1e9 + 7;
        int ans = res % total;
        return ans;
    }
};

int main(){
    Solution solution;
    vector<int> arr;

    arr = {3,1,2,4};
    cout << solution.sumSubarrayMins(arr) << endl;

    arr = {11,81,94,43,3};
    cout << solution.sumSubarrayMins(arr) << endl;

    return 0;
}


