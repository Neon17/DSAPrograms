#include<iostream>
#include<vector>
using namespace std;


class Solution {
    public:

    vector<vector<int>> tp;
    
    int dfs(vector<vector<int>>& points, int index, int choose=-1) {
        if (index < 0) return 0;
        if (index == points.size()-1) tp.assign(points.size(), vector<int>(points[0].size(), -1));
        if (tp[index][choose + 1] != -1) return tp[index][choose + 1];

        int maxi = 0;
        int col = points[0].size();

        for (int i = 0; i < col; i++) {
            if (i == choose) continue;
            int current = points[index][i] + dfs(points, index - 1, i);
            maxi = max(maxi, current);
        }

        return tp[index][choose + 1] = maxi;
    }

    int convertToBottomUp(vector<vector<int>>& points, int choose = -1){
        int maxi = 0, tempmax = 0;
        int row = points.size(), col = points[0].size();
        vector<vector<int>> dp(row, vector<int>(col, 0));

        for (int i=0;i<col;i++) dp[0][i] = points[0][i];

        for (int i=1;i<row;i++){
            for (int j=0;j<col;j++){

                tempmax = 0;
                for (int k=0;k<col;k++){
                    if (k == j) continue;
                    tempmax = max(tempmax, dp[i-1][k]);
                }
                dp[i][j] = tempmax + points[i][j];
            }
        }

        maxi = 0;
        for (int i=0;i<col;i++) maxi = max(maxi, dp[row-1][i]);

        return maxi;
    }
};

int main() {
    Solution s;
    vector<vector<int>> points;

    points = {{10, 50, 1}, {5, 100, 11}};
    cout<<s.dfs(points, points.size()-1)<<endl;
    cout<<s.convertToBottomUp(points)<<endl;

    return 0;
    
}