#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j, int k,  vector<vector<vector<int>>>& tp) {
        if (j >= grid[0].size() || k < 0 || k >= grid[0].size()) return -1e9;
        if (tp[i][j][k] != -1) return tp[i][j][k];
        if (i == grid.size()-1){
            if (j!=k) return tp[i][j][k] = grid[i][j] + grid[i][k];
            return tp[i][j][k] = grid[i][j];
        }
        int maxi = -1e9, sumi = 0;
        for (int m = j-1; m<=j+1;m++){
            for (int n=k-1;n<=k+1;n++){
                maxi = max(maxi, dfs(grid, i+1, m, n, tp));
            }
        }
        sumi = maxi + grid[i][j];
        if (j != k) sumi += grid[i][k];
        return tp[i][j][k] = sumi;
    }

    int convertToBottomUp(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        int prefix = 0;
        vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
        for (int i=0;i<c;i++){
            for (int j=0;j<c;j++){
                dp[r-1][i][j] = grid[r-1][j];
                if (i != j) dp[r-1][i][j] += grid[r-1][i];
            }
        }

        for (int i=r-2;i>=0;i--){
            for (int j=c-1;j>=0;j--){
                for (int k=c-1;k>=0;k--){

                    prefix = (__INT32_MAX__-1)*-1;
                    for (int m = j-1; m<=j+1;m++){
                        for (int n=k-1;n<=k+1;n++){
                            if (m < c && n < c && m >= 0 && n >= 0) prefix = max(prefix, dp[i+1][m][n]);
                        }
                    }
                    dp[i][j][k] = grid[i][j] + prefix;
                    if (j != k) dp[i][j][k] += grid[i][k];
                }
            }
        }

        return dp[0][0][c-1];
    }

    int spaceOptimized(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        int prefix = 0;
        vector<vector<int>> prev(c, vector<int>(c, -1)), curr(c, vector<int>(c, -1));
        for (int i=0;i<c;i++){
            for (int j=0;j<c;j++){
                prev[i][j] = grid[r-1][j];
                if (i != j) prev[i][j] += grid[r-1][i];
            }
        }

        for (int i=r-2;i>=0;i--){
            for (int j=c-1;j>=0;j--){
                for (int k=c-1;k>=0;k--){

                    prefix = (__INT32_MAX__-1)*-1;
                    for (int m = j-1; m<=j+1;m++){
                        for (int n=k-1;n<=k+1;n++){
                            if (m < c && n < c && m >= 0 && n >= 0) prefix = max(prefix, prev[m][n]);
                        }
                    }
                    curr[j][k] = grid[i][j] + prefix;
                    if (j != k) curr[j][k] += grid[i][k];
                }
            }
            prev = curr;
        }

        return curr[0][c-1];
    }

    int cherryPickup(vector<vector<int>>& grid, int flag=0) {
        // one starts at 0,0 and another starts at 0,grid[0].size()-1
        int r = grid.size(), c = grid[0].size(), ans = 0;
        vector<vector<vector<int>>> tp(r, vector<vector<int>>(c, vector<int>(c, -1)));
        if (!flag) ans =  dfs(grid, 0, 0, grid[0].size()-1, tp);
        if (flag) ans = convertToBottomUp(grid);
        if (flag==2) ans = spaceOptimized(grid);
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> grid;

    cout<<"Test Example 1"<<endl;
    grid = {{3,1,1},{2,5,1},{1,5,5},{2,1,1}};
    cout<<s.cherryPickup(grid)<<endl;
    cout<<s.cherryPickup(grid, 1)<<endl;
    cout<<s.cherryPickup(grid, 2)<<endl;

    cout<<"Test Example 2"<<endl;
    grid = {{2,3,1,2},{3,4,2,2},{5,6,3,5}};
    cout<<s.cherryPickup(grid)<<endl;
    cout<<s.cherryPickup(grid, 1)<<endl;
    cout<<s.cherryPickup(grid, 2)<<endl;

    return 0;
}
