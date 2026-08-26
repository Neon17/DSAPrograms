/*
    Leetcode Hard 84. Largest Rectangle in Histogram

    Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, 
    return the area of the largest rectangle in the histogram.

    Constraints:
        1 <= heights.length <= 105
        0 <= heights[i] <= 104
*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxval = (-1)* (__INT32_MAX__ - 1), temp = 0, tempo = 0;

        // monotonic increasing stack with counting and updating its dominations I guess
        // or at time of popping, we can calculate the area of the rectangle with the popped height as the smallest (or minimum height) bar 'h' for count (dominations)
        // build stack, and at time of pop, calculate area and update ans
        // do that until end, and at last, pop all remaining elements in stack and calculate area and update ans

        // BruteForce Approch
        // for (int i=0;i<heights.size();i++){  
        //     temp = heights[i];
        //     for (int j=i;j>=0;j--){
        //         temp = min(heights[j], temp);
        //         tempo = temp * (i-j+1);
        //         maxval = max(maxval, tempo);
        //     }
        // }

        stack<int> st; int size = heights.size();
        int left = 0, width = 0;
        for (int i=0;i<heights.size();i++){
            while (!st.empty() && heights[st.top()] > heights[i]){
                int h = heights[st.top()];
                st.pop();
                left = st.empty() ? -1:st.top();
                width = i - left - 1;
                maxval = max(maxval, h * width);
            }
            st.push(i);
        }
        while (!st.empty()){
            int h = heights[st.top()];
            st.pop();
            left = st.empty() ? -1: st.top();
            width = size - left - 1;
            maxval = max(maxval, h * width);
        }
        return maxval;
    }
};

int main(){
    Solution solution;
    vector<int> heights;
    heights = {2,1,5,6,2,3};
    cout << solution.largestRectangleArea(heights) << endl;
    heights = {2,4};
    cout << solution.largestRectangleArea(heights) << endl;
    return 0;
}
