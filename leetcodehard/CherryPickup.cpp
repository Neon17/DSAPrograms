/**
 * You are given an n x n grid representing a field of cherries, each cell is one of three possible integers.

0 means the cell is empty, so you can pass through,
1 means the cell contains a cherry that you can pick up and pass through, or
-1 means the cell contains a thorn that blocks your way.
Return the maximum number of cherries you can collect by following the rules below:

Starting at the position (0, 0) and reaching (n - 1, n - 1) by moving right or down through valid path cells (cells with value 0 or 1).
After reaching (n - 1, n - 1), returning to (0, 0) by moving left or up through valid path cells.
When passing through a path cell containing a cherry, you pick it up, and the cell becomes an empty cell 0.
If there is no valid path between (0, 0) and (n - 1, n - 1), then no cherries can be collected.


Example 1:
Input: grid = [[0,1,-1],[1,0,-1],[1,1,1]]
Output: 5
Explanation: The player started at (0, 0) and went down, down, right right to reach (2, 2).
4 cherries were picked up during this single trip, and the matrix becomes [[0,1,-1],[0,0,-1],[0,0,0]].
Then, the player went left, up, up, left to return home, picking up one more cherry.
The total number of cherries picked up is 5, and this is the maximum possible.
Example 2:

Input: grid = [[1,1,-1],[1,-1,1],[-1,1,1]]
Output: 0

Constraints:

n == grid.length
n == grid[i].length
1 <= n <= 50
grid[i][j] is -1, 0, or 1.
grid[0][0] != -1
grid[n - 1][n - 1] != -1

Topics: Principal, Array, Dynamic Programming, Matrix, Weekly Contest 61

Accepted 112,036/284.5K 
Acceptance Rate 39.4%
 */

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:

    int dfs(vector<vector<int>>& grid, int i=0, int j=0, int trend=0){
        if (i == 0 && j == 0 && trend == 1) return 0;
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) return -1e9;
        if (grid[i][j] == -1) return -1e9;
        if (i == grid.size()-1 && j == grid[0].size()-1) trend = 1;

        int add = (trend == 0)?1:-1;
        int sumi = grid[i][j];
        grid[i][j] = (grid[i][j] == 1)?0:0;
        int updown = sumi + dfs(grid, i+add, j, trend);
        int leftright = sumi + dfs(grid, i, j+add, trend);
        grid[i][j] = sumi;

        return max(updown, leftright);
    }

    int convertToBottomUp(vector<vector<int>>& grid){
        return 0;
    }

    int spaceOptimized(vector<vector<int>>& grid){
        return 0;
    }

    int cherryPickup(vector<vector<int>>& grid, int flag=0) {
        int ans = 0;
        if (flag == 0) {
            ans = dfs(grid);
            return ans < 0? 0: ans;
        }
        else if (flag == 1) ans = convertToBottomUp(grid);
        else ans = spaceOptimized(grid);
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> grid;

    cout<<"Test Example 1"<<endl;
    grid = {{0,1,-1},{1,0,-1},{1,1,1}};
    cout<<s.cherryPickup(grid)<<endl;
    cout<<s.convertToBottomUp(grid)<<endl;
    cout<<s.spaceOptimized(grid)<<endl;

    cout<<"Test Example 2"<<endl;
    grid = {{1,1,-1},{1,-1,1},{-1,1,1}};
    cout<<s.cherryPickup(grid)<<endl;
    cout<<s.convertToBottomUp(grid)<<endl;
    cout<<s.spaceOptimized(grid)<<endl;

    cout<<"Test Example 3"<<endl;
    grid = {{1,1,1,1,0,0,0},{0,0,0,1,0,0,0},{0,0,0,1,0,0,1},{1,0,0,1,0,0,0},{0,0,0,1,0,0,0},{0,0,0,1,0,0,0},{0,0,0,1,1,1,1}};
    cout<<s.cherryPickup(grid)<<endl;
    cout<<s.convertToBottomUp(grid)<<endl;
    cout<<s.spaceOptimized(grid)<<endl;

    return 0;
}
