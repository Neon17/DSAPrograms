#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    // min cost going from top level to bottom level
    int dfs(vector<vector<int>>& triangle, vector<vector<int>> tp, int i=0, int j=0){        
        if (j>=triangle[i].size()) return __INT32_MAX__;
        if (i==triangle.size()-1) return triangle[i][j];
        if (tp[i][j] != -1) return tp[i][j];
        return tp[i][j] = triangle[i][j] + min(dfs(triangle, tp, i+1, j), dfs(triangle, tp, i+1, j+1));
    }

    int convertToBottomUp(vector<vector<int>>& triangle){
        int n = triangle.size(), temp=0;
        vector<vector<int>> dp(n, vector<int>(triangle[n-1].size(), __INT32_MAX__));
        for (int i=0;i<triangle[n-1].size();i++) dp[n-1][i] = triangle[n-1][i];

        for (int i=triangle.size()-2;i>=0;i--){
            for (int j=i;j>=0;j--){
                dp[i][j] = triangle[i][j] + min(dp[i+1][j], dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }

    int spaceOptimized(vector<vector<int>>& triangle){
        int n = triangle.size(), temp = 0;
        vector<int> prev(triangle[n-1].size(), __INT32_MAX__);
        vector<int> curr(triangle[n-1].size(), __INT32_MAX__);
        for (int i=0;i<triangle[n-1].size();i++) prev[i] = triangle[n-1][i];

        for (int i=n-2;i>=0;i--){
            for (int j=i;j>=0;j--){
                curr[j] = triangle[i][j] + min(prev[j], prev[j+1]);
            }
            prev = curr;
        }
        return prev[0];
    }

    int solve(vector<vector<int>>& triangle, int flag=0){
        int n = triangle.size();
        vector<vector<int>> tp(triangle.size(), vector<int>(triangle[n-1].size(), -1));
        if (!flag) return dfs(triangle, tp);
        else if (flag==1) return convertToBottomUp(triangle);
        else if (flag==2) return spaceOptimized(triangle);
        return 0;
    }
};

int main() {
    Solution s;

    vector<vector<int>> triangle = {{2},{3,4},{6,5,7},{4,1,8,3}};
    cout<<s.solve(triangle)<<endl;
    cout<<s.solve(triangle, 1)<<endl;
    cout<<s.solve(triangle, 2)<<endl;

    return 0;
}
