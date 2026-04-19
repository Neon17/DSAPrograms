#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
    vector<vector<int>> tp;

    int dfs(int m, int n, int i, int j) {
        if (i==0 && j==0) return 1;
        if (i<0 || j<0) return 0;
        if (i == m-1 && j == n-1) tp.assign(m, vector<int>(n, -1));
        if (tp[i][j] != -1) return tp[i][j];
        return tp[i][j] = dfs(m, n, i-1, j) + dfs(m, n, i, j-1);
    }

    int convertToBottomUp(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));

        for (int i=1;i<m;i++){
            for (int j=1;j<n;j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }

    int spaceOptimized(int m, int n){
        vector<int> prev(n, 1);
        vector<int> curr(n, 0);

        for (int row=1;row<m;row++){
            for (int i=0;i<n;i++){
                if (i==0) curr[i] = prev[i];
                else curr[i] = prev[i] + curr[i-1];
                prev[i] = curr[i];
            }
        }

        return curr[n-1];
    }

    int uniquePaths(int m, int n, int flag = 0) {
        int ans;

        if (flag == 2) ans = spaceOptimized(m, n);
        if (flag == 1) ans = convertToBottomUp(m, n);
        if (flag == 0) ans = dfs(m, n, m-1, n-1);

        return ans;
    }
};

int main() {
    Solution s;
    int m = 5, n = 5;

    cout << s.uniquePaths(m,n,0) << endl;
    cout << s.uniquePaths(m,n,1) << endl;
    cout << s.uniquePaths(m,n,2) << endl;

    return 0;
}

