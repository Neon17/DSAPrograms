/**
 * 200. Number of Islands (Medium)
 * 
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded by water. 

Example 1:
Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1

Example 2:
Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
 
Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.

Topics: Array, Depth-First Search, Breadth-First Search, Union-Find, Matrix
 */

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>>& grid, vector<vector<char>>& visited, int x, int y){
        int m = grid.size(), n = grid[0].size();
        if (x < 0 || y < 0 || x >= m || y >= n) return;
        if (grid[x][y] == '0' || visited[x][y]) return;

        visited[x][y] = 1;
        dfs(grid, visited, x+1, y);
        dfs(grid, visited, x, y+1);
        dfs(grid, visited, x-1, y);
        dfs(grid, visited, x, y-1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<char>> visited(m, vector<char>(n, 0));

        int count = 0;
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (grid[i][j] == '1' && !visited[i][j]){
                    dfs(grid, visited, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};

int main() {
    vector<vector<char>> grid;
    Solution s;

    grid = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };
    cout<<"Number of Islands = "<<s.numIslands(grid)<<endl;

    grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    cout<<"Number of Islands = "<<s.numIslands(grid)<<endl;

    return 0;
}
