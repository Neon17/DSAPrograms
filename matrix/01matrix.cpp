// Leetcode Medium 542. 01 Matrix

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<int>> dynamic(vector<vector<int>>& mat){
        int m = mat.size(), n = mat[0].size(), mini = 0, temp=0;
        vector<vector<int>> dp(m+2, vector<int>(n+2, (m-1 + n-1)));
        vector<vector<int>> ans(m, vector<int>(n,  m-1 + n-1));

        for (int i=1;i<=m;i++){
            for (int j=1;j<=n;j++){
                if (mat[i-1][j-1] == 0) {
                    dp[i][j] = 0;
                } else {
                    mini = min(dp[i-1][j], dp[i][j-1]);
                    dp[i][j] = (dp[i][j] > mini+1)? mini+1:dp[i][j];
                }
            }
        }
        for (int i=m;i>=1;i--){
            for (int j=n;j>=1;j--){
                mini = min(dp[i+1][j], dp[i][j+1]);
                dp[i][j] = (dp[i][j] > mini+1)? mini+1:dp[i][j];
            }
        }
        for (int i=1;i<=m;i++){
            for (int j=1;j<=n;j++){
                ans[i-1][j-1] = dp[i][j];
            }
        }
        return ans;
    }

    vector<vector<int>> bruteforce(vector<vector<int>>& mat){
        // push 0 on queue, and do bfs from there to whole table
        // we can be careful for continoous 0 elements

        int m = mat.size(), n = mat[0].size(), level = -1;
        vector<vector<int>> ans(m, vector<int>(n, 0));
        queue<pair<int, int>> que;
        unordered_set<string> visited;

        auto convertToString = [](int row, int col){
            return to_string(row)+","+to_string(col);
        };
        auto convertToNumber = [](string col){
            int pos = 0;
            for (int i=0;i<col.size();i++){
                if (col[i] == ','){
                    pos = i; break;
                }
            }
            pair<int, int> p;
            p.first = stoi(col.substr(0, pos));
            p.second = stoi(col.substr(pos+1));
            return p;
        };
        
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (mat[i][j] == 0) que.push({i, j});
            }
        }

        while (!que.empty()){
            int size = que.size();
            level++;

            for (int i=0;i<size;i++){
                auto it = que.front();
                que.pop();
                string test = convertToString(it.first, it.second);
                if (visited.count(test)) continue;
                visited.insert(convertToString(it.first, it.second));
                ans[it.first][it.second] = level;

                if (it.first > 0) que.push({it.first-1, it.second});
                if (it.second > 0) que.push({it.first, it.second-1});
                if (it.first+1 < m) que.push({it.first+1, it.second});
                if (it.second+1 < n) que.push({it.first, it.second+1});
            }
        }
        return ans;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
       vector<vector<int>> ans;
       ans = dynamic(mat);
    //    ans = bruteforce(mat);
       return ans; 
    }
};

int main(){
    Solution sol;
    vector<vector<int>> mat, ans;

    mat = {{0,0,0},{0,1,0},{0,0,0}};
    ans = sol.updateMatrix(mat);
    for (auto row: ans){
        for (auto col: row) cout << col << " ";
        cout << endl;
    }
    cout<<endl;

    mat = {{0,0,0},{0,1,0},{1,1,1}};
    ans = sol.updateMatrix(mat);
    for (auto row: ans){
        for (auto col: row) cout << col << " ";
        cout << endl;
    }
    cout<<endl;

    return 0;
}
