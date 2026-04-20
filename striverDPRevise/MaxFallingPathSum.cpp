#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int dfs(vector<vector<int>>& matrix, int i, int j,  vector<vector<int>> tp){
        if (j < 0 || j >= matrix[0].size()) return (__INT32_MAX__-1)*-1;
        if (i==0) return matrix[i][j];
        if (tp[i][j] != -1) return tp[i][j];
        return tp[i][j] = matrix[i][j] + max(dfs(matrix, i-1, j, tp), max(dfs(matrix,i-1,j-1, tp), dfs(matrix, i-1, j+1, tp)));
    }

    int convertToBottomUp(vector<vector<int>>& matrix){
        int r = matrix.size(), c = matrix[0].size(), temp = 0, maxi=0;
        vector<vector<int>> dp(r, vector<int>(c, 0));
        for (int i=0;i<c;i++) dp[0][i] = matrix[0][i];

        for (int i=1;i<r;i++){
            for (int j=0;j<c;j++){
                temp = dp[i-1][j];
                if (j>0) temp = max(temp, dp[i-1][j-1]);
                if (j<c-1) temp = max(temp, dp[i-1][j+1]);
                dp[i][j] = matrix[i][j] + temp;
            }
        }
        for (int i=0;i<c;i++) maxi = max(dp[r-1][i], maxi);
        return maxi;
    }

    int spaceOptimized(vector<vector<int>>& matrix){
        int r = matrix.size(), c = matrix[0].size(), temp = 0, maxi=0;
        vector<int> prev(c, 0), curr(c, 0);
        for (int i=0;i<c;i++) prev[i] = matrix[0][i];

        for (int i=1;i<r;i++){
            for (int j=0;j<c;j++){
                temp = prev[j];
                if (j>0) temp = max(temp, prev[j-1]);
                if (j<c-1) temp = max(temp, prev[j+1]);
                curr[j] = matrix[i][j] + temp;
            }
            prev = curr;
        }
        for (int i=0;i<c;i++) maxi = max(prev[i], maxi);
        return maxi;
    }

    int maxPathSum(vector<vector<int>>& matrix, int flag = 0){
        int maxi = 0, n = matrix.size();
        vector<vector<int>> tp (n, vector<int>(matrix[0].size(), -1));

        if (!flag){
            int maxi = (__INT32_MAX__-1)*-1;
            for (int i=0;i<matrix[n-1].size();i++){
                maxi = max(maxi, dfs(matrix, n-1, i, tp));
            }
            return maxi;
        }
        else if (flag==1) return convertToBottomUp(matrix);
        else return spaceOptimized(matrix);

        return maxi;
    }
};

int main() {
    Solution s;
    vector<vector<int>> matrix;

    matrix = {{3,2,5},{1,3,7},{8,10,11}};
    cout<<s.maxPathSum(matrix)<<endl;
    cout<<s.maxPathSum(matrix, 1)<<endl;
    cout<<s.maxPathSum(matrix, 2)<<endl;

    return 0;
}