/*
    Leetcode Hard 85. Maximal Rectangle

    Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

    Constraints:
        rows == matrix.length
        cols == matrix[i].length
        1 <= rows, cols <= 200
        matrix[i][j] is '0' or '1'.
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int calculateLargestRectangle(vector<int>& heights){
        int maxval = (-1)* (__INT32_MAX__ - 1), temp = 0, left = 0, width = 0, n = heights.size();
        int count = 0;
        stack<int> st;

        for (int i=0;i<n;i++){
            while (!st.empty() && heights[st.top()] > heights[i]){
                temp = st.top();
                st.pop();
                left = (!st.empty())? st.top(): -1;
                width = i - left - 1;
                maxval = max(maxval, width * heights[temp]);
            }
            st.push(i);
        }
        while (!st.empty()){
            temp = st.top();
            st.pop();
            left = (!st.empty())? st.top(): -1; width = n - left - 1;
            maxval = max(maxval, width*heights[temp]);
        }
        return maxval;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxval = (-1)* (__INT32_MAX__ - 1), temp = 0;
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> heights(n, vector<int>(m, 0));

        for (int i=0;i<m;i++){
            heights[0][i] = (matrix[0][i] == '0')?0:1;
        }        
        for (int i=1;i<n;i++){
            for (int j=0;j<m;j++){
                if (matrix[i][j] == '1'){
                    heights[i][j] = heights[i-1][j] + 1;
                } else heights[i][j] = 0;
            }
        }
        for (int i=0;i<n;i++){
            temp = calculateLargestRectangle(heights[i]);
            maxval = max(maxval, temp);
        }
        return maxval;
    }
};

int main(){
    Solution s;
    vector<vector<char>> matrix;

    matrix = {{'1','0','1','0','0'},
              {'1','0','1','1','1'},
              {'1','1','1','1','1'},
              {'1','0','0','1','0'}};
    cout << s.maximalRectangle(matrix) << endl;

    matrix = {{'0','0'},{'0','0'}};
    cout << s.maximalRectangle(matrix) << endl;

    matrix = {{'1'}};
    cout << s.maximalRectangle(matrix) << endl;

    matrix = {{'0'}};
    cout << s.maximalRectangle(matrix) << endl;

    return 0;
}
