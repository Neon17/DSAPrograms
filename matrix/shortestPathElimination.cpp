/*
Leetcode Hard 1293. Shortest Path in a Grid with Obstacles Elimination

You are given an m x n integer matrix grid where each cell is either 0 (empty) or 1 (obstacle). 
You can move up, down, left, or right from and to an empty cell in one step.

Return the minimum number of steps to walk from the upper left corner (0, 0) to the lower right corner (m - 1, n - 1) given that 
       you can eliminate at most k obstacles. 
If it is not possible to find such walk return -1.

Constraints:
    m == grid.length
    n == grid[i].length
    1 <= m, n <= 40
    1 <= k <= m * n
    grid[i][j] is either 0 or 1.
    grid[0][0] == grid[m - 1][n - 1] == 0
*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <tuple>
using namespace std;

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size(), level = -1;
        if (m == n && m == 1) return 0;
        int obstacles = 0;
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (grid[i][j] == 1) obstacles++;
            }
        }
        if (k >= obstacles) return m+n-2;

        queue<tuple<int, int, int>> que;
        vector<vector<vector<char>>> visited(m, vector<vector<char>>(n, vector<char>(k+1, 0)));
        vector<pair<int, int>> dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        if (grid[0][0] != 1) que.push({0, 0, k});
        else que.push({0, 0, k-1});
        visited[0][0][get<2>(que.front())] = 1;

        while (!que.empty()){
            int size = que.size();
            level++;

            for (int i=0;i<size;i++){
                int x = get<0>(que.front());
                int y = get<1>(que.front());
                int rem = get<2>(que.front());
                que.pop();
                if (x == m-1 && y == n-1) return level;

                for (auto [dx, dy]: dirs){
                    int nx = x + dx;
                    int ny = y + dy;

                    if (nx >= 0 && ny >= 0 && nx < m && ny < n){
                        if (grid[nx][ny] == 1 && rem <= 0) continue;
                        if (grid[nx][ny] == 1) {
                            if (visited[nx][ny][rem-1]) continue;
                            visited[nx][ny][rem-1] = 1;
                            que.push({nx, ny, rem-1});
                        }
                        else {
                            if (visited[nx][ny][rem]) continue;
                            visited[nx][ny][rem] = 1;
                            que.push({nx, ny, rem});
                        }
                    }
                }
            }
        }
        return -1;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> grid;
    int k, ans;

    grid = {{0,0,0},{1,1,0},{0,0,0},{0,1,1},{0,0,0}};
    k = 1;
    ans = sol.shortestPath(grid, k);
    cout << ans << endl; // Output: 6

    grid = {{0,1,1},{1,1,1},{1,0,0}};
    k = 1;
    ans = sol.shortestPath(grid, k);
    cout << ans << endl; // Output: -1

    return 0;
}

