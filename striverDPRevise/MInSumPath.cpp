#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:

    int dfs(vector<vector<int>>& grid, int i, int j){
        if (i==0 && j==0) return grid[0][0];
        if (i<0 || j<0) return (__INT32_MAX__-1)*-1;

        int cost1 = grid[i][j] + dfs(grid, i-1, j);
        int cost2 = grid[i][j] + dfs(grid, i, j-1);

        if (cost1 <= 0) cost1 = __INT32_MAX__;
        if (cost2 <= 0) cost2 = __INT32_MAX__;
        return min(cost1, cost2);
    }

    int convertToBottomUp(vector<vector<int>>& grid){
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 0));
        // we can easily space optimize this as well, but we will do that in the next revision

        for (int i=0;i<grid.size();i++){
            for (int j=0;j<grid[0].size();j++){
                if (i==0 && j==0) dp[i][j] = grid[0][0];
                if (i==0){
                    dp[i][j] = dp[i][j-1] + grid[i][j];
                } else if (j==0){
                    dp[i][j] = dp[i-1][j] + grid[i][j];
                } else {
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
                }
            }
        }
        return dp[grid.size()-1][grid[0].size()-1];
    }


    int minPathSum(vector<vector<int>>& grid, int flag = 0) {
        int row = grid.size(), col = grid[0].size(), ans=0;

        ans = dfs(grid, row-1, col-1);
        if (flag) ans = convertToBottomUp(grid);

        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> grid;

    grid = {{1, 2, 3}, {4, 8, 2}, {1, 5, 3}};
    cout<<s.minPathSum(grid)<<endl;
    cout<<s.minPathSum(grid, 1)<<endl;

    grid = {{5,9,6},{11,5,2}};
    cout<<s.minPathSum(grid)<<endl;
    cout<<s.minPathSum(grid, 1)<<endl;

    return 0;
}
