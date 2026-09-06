/*
    Leetcode Medium 994. Rotting Oranges

    You are given an m x n grid where each cell can have one of three values:

    0 representing an empty cell,
    1 representing a fresh orange, or
    2 representing a rotten orange.
    Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

    Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

    Constraints:
        m == grid.length
        n == grid[i].length
        1 <= m, n <= 10
        grid[i][j] is 0, 1, or 2.
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> que;
        int m = grid.size(), n = grid[0].size(), minute = 0;
        int fresh = 0;

        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (grid[i][j] == 2) que.push({i, j});
                if (grid[i][j] == 1) fresh++;
            }
        }
        if (!fresh) return 0;

        while (!que.empty() && fresh > 0){
            minute++;
            int size = que.size();

            for (int i=0;i<size;i++){
                auto it = que.front();
                int row = it.first, col = it.second;
                que.pop();
                if (grid[row][col] != 2) continue;
                grid[row][col] = 2;

                if (row > 0 && grid[row-1][col] == 1) {
                    que.push({row-1, col});
                    grid[row-1][col] = 2;
                    fresh--;
                }
                if (col > 0 && grid[row][col-1] == 1) {
                    que.push({row, col-1});
                    grid[row][col-1] = 2;
                    fresh--;
                }
                if (row < m-1 && grid[row+1][col] == 1) {
                    que.push({row+1, col});
                    grid[row+1][col] = 2;
                    fresh--;
                }
                if (col < n-1 && grid[row][col+1] == 1) {
                    que.push({row, col+1});
                    grid[row][col+1] = 2;
                    fresh--;
                }
            }
        }
        return (fresh == 0)?minute:-1;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> grid;

    grid = {{2,1,1},{1,1,0},{0,1,1}};
    cout<<sol.orangesRotting(grid)<<endl; // Expected: 4

    grid = {{2,1,1},{0,1,1},{1,0,1}};
    cout<<sol.orangesRotting(grid)<<endl; // Expected: -1

    grid = {{0,2}};
    cout<<sol.orangesRotting(grid)<<endl; // Expected: 0

    return 0;
}
