/**
 *  329. Longest Increasing Path in a Matrix
 * Topics: Array, Dynamic Programming, Matrix, Depth-first Search, Memoization, Topological Sort, Graph, Breadth-first Search
 */

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& tp, int i=0, int j=0, int lastElement = -1) {
        if (i<0 || i>=matrix.size() || j<0 || j>=matrix[0].size()) return 0;
        if (matrix[i][j] <= lastElement) return 0;

        int way1, way2, way3, way4;
        way1 = 1 + dfs(matrix, tp, i+1, j, matrix[i][j]);
        way2 = 1 + dfs(matrix, tp, i, j+1, matrix[i][j]);
        way3 = 1 + dfs(matrix, tp, i-1, j, matrix[i][j]);
        way4 = 1 + dfs(matrix, tp, i, j-1, matrix[i][j]);

        return max(max(way1, way2), max(way3, way4));        
    }

    int convertToBottomUp(vector<vector<int>>& matrix) {
        return 0;
    }

    int spaceOptimized(vector<vector<int>>& matrix) {
        return 0;
    }

    int solve(vector<vector<int>>& matrix, int flag=0) {
        int ans = 0, m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> tp (m, vector<int>(n, -1));

        if (flag == 0){
            int ways = 0;
            for (int i=0;i<matrix.size();i++){
                for (int j=0;j<matrix[0].size();j++){
                    ways = max(ways, dfs(matrix, tp, i, j));
                }
            }
            return ways;
        }
        else if (flag == 1) ans = convertToBottomUp(matrix);
        else ans = spaceOptimized(matrix);
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> matrix;

    cout<<"Test Example 1"<<endl;
    matrix = {{9,9,4},{6,6,8},{2,1,1}};
    cout<<s.solve(matrix)<<endl;
    cout<<s.solve(matrix, 1)<<endl;
    cout<<s.solve(matrix, 2)<<endl;

    cout<<"Test Example 2"<<endl;
    matrix = {{3,4,5},{3,2,6},{2,2,1}};
    cout<<s.solve(matrix)<<endl;
    cout<<s.solve(matrix, 1)<<endl;
    cout<<s.solve(matrix, 2)<<endl;


    return 0;
}
