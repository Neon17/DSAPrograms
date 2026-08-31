/*
You may recall that an array arr is a mountain array if and only if:

arr.length >= 3
There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given an integer array arr, return the length of the longest subarray, which is a mountain. Return 0 if there is no mountain subarray.

Constraints:
1 <= arr.length <= 104
0 <= arr[i] <= 104

Follow up:
Can you solve it using only one pass?
Can you solve it in O(1) space?
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        if (arr.size() < 3) return 0;
        int right = 0, n = arr.size(), count = 1, maxi = 0;
        bool up = true, started = false;

        for (right = 1; right < n; right++){
            if (arr[right] == arr[right-1]){
                count = 1;
                started = false;
                up = true;
                continue;
            }
            count++;
            if (up && arr[right] > arr[right-1]) {
                started = true;
                continue;
            }
            else if (up && arr[right] < arr[right-1]){
                if (!started) {
                    count = 1;
                    continue;
                }
                up = false;
                maxi = max(maxi, count);
                continue;
            } 
            if (arr[right] < arr[right-1]){
                if (started) maxi = max(maxi, count);
                continue;
            } else {
                count = 2;
                up = true;
                started = true;
            }
        }
        return maxi;
    }
};

int main() {
    Solution sol;
    vector<int> arr;

    arr = {2, 1, 4, 7, 3, 2, 5};
    cout << sol.longestMountain(arr) << endl; // Output: 5

    arr = {2, 2, 2};
    cout << sol.longestMountain(arr) << endl; // Output: 0

    arr = {0, 1, 0};
    cout << sol.longestMountain(arr) << endl; // Output: 3

    arr = {0, 1, 2, 3, 4, 5, 4, 3, 2, 1, 0};
    cout << sol.longestMountain(arr) << endl; // Output: 11

    arr = {2,1};
    cout << sol.longestMountain(arr) << endl; // Output: 0

    arr = {2,1, 0};
    cout << sol.longestMountain(arr) << endl; // Output: 0

    return 0;
}

