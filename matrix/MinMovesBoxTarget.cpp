/*
Leetcode Hard 1263. Minimum Moves to Move a Box to Their Target Location

A storekeeper is a game in which the player pushes boxes around in a warehouse trying to get them to target locations.

The game is represented by an m x n grid of characters grid where each element is a wall, floor, or box.

Your task is to move the box 'B' to the target position 'T' under the following rules:

The character 'S' represents the player. The player can move up, down, left, right in grid if it is a floor (empty cell).
The character '.' represents the floor which means a free cell to walk.
The character '#' represents the wall which means an obstacle (impossible to walk there).
There is only one box 'B' and one target cell 'T' in the grid.
The box can be moved to an adjacent free cell by standing next to the box and then moving in the direction of the box. This is a push.
The player cannot walk through the box.
Return the minimum number of pushes to move the box to the target. If there is no way to reach the target, return -1.

Constraints:
    m == grid.length
    n == grid[i].length
    1 <= m, n <= 20
    grid contains only characters '.', '#', 'S', 'T', or 'B'.
    There is only one character 'S', 'B', and 'T' in the grid.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
    vector<vector<char>> findReachable(vector<vector<char>>& grid, pair<int, int> box = {-1, -1}, pair<int, int> person = {-1, -1}, pair<int, int> target = {-1, -1}){
        int m = grid.size(), n = grid[0].size();
        char reach = 1;
        vector<vector<char>> reachable(m, vector<char>(n, 0));
        vector<vector<char>> visited(m, vector<char>(n, 0));
        queue<pair<int, int>> que;
        que.push(person);
        reachable[person.first][person.second] = 1;
        vector<pair<int, int>> dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

        while (!que.empty()){
            auto [x, y] = que.front();
            que.pop();
            if (visited[x][y]) continue;
            visited[x][y] = 1;
            reachable[x][y] = 1;

            for (auto [dx, dy]: dirs){
                int nx = x + dx;
                int ny = y + dy;

                if (nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] != '#' ){
                    if (nx == box.first && ny == box.second) continue;
                    que.push({nx, ny});
                }
            }
        }

        return reachable;
    }
public:
    int minPushBox(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(), pushes = -1;
        pair<int, int> box = {-1, -1}, person = {-1, -1}, target = {-1, -1};
        vector<vector<char>> reachable(m, vector<char>(n, 0));
        vector<vector<vector<vector<char>>>> visited(
            m,
            vector<vector<vector<char>>>(
                n,
                vector<vector<char>>(
                    m,
                    vector<char>(n, 0)
                )
            )
        );
        queue<tuple<int, int, int, int>> que;
        
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (grid[i][j] == 'T') {
                    target.first = i;
                    target.second = j;
                } else if (grid[i][j] == 'B') {
                    box.first = i;
                    box.second = j;
                } else if (grid[i][j] == 'S') {
                    person.first = i;
                    person.second = j;
                }
                if (target.first != -1 && box.first != -1 && person.first != -1) break;
            }
            if (target.first != -1 && box.first != -1 && person.first != -1) break;
        }

        que.push({box.first, box.second, person.first, person.second});
        vector<pair<int, int>> dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        reachable = findReachable(grid, box, person, target);

        while (!que.empty()){
            int size = que.size();
            pushes++;

            for (int i=0;i<size;i++){
                auto [x, y, personx, persony] = que.front();
                que.pop();
                if (visited[x][y][personx][persony]) continue;
                visited[x][y][personx][persony] = 1;
                if (x == target.first && y == target.second) return pushes;
                
                for (auto [dx, dy]: dirs){
                    int nx = x + dx; int px = x - dx;
                    int ny = y + dy; int py = y - dy;
                    
                    if (nx >= 0 && ny >= 0 && nx < m && ny < n && px >= 0 && py >= 0 && px < m && py < n){
                        if (grid[nx][ny] == '#' || grid[px][py] == '#') continue;
                        reachable = findReachable(grid, {x, y}, {personx, persony}, target);
                        if (reachable[px][py]) {
                            que.push({nx, ny, x, y});
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
    vector<vector<char>> grid;

    grid = {{'#','#','#','#','#','#'},
            {'#','T','#','#','#','#'},
            {'#','.','.','B','.','#'},
            {'#','.','#','#','.','#'},
            {'#','.','.','.','S','#'},
            {'#','#','#','#','#','#'}};
    cout << sol.minPushBox(grid) << endl; // Output: 3

    grid = {{'#','#','#','#','#','#'},
            {'#','T','#','#','#','#'},
            {'#','.','.','B','.','#'},
            {'#','#','#','#','.','#'},
            {'#','.','.','.','S','#'},
            {'#','#','#','#','#','#'}};
    cout << sol.minPushBox(grid) << endl; // Output: -1

    grid = {{'#','#','#','#','#','#'},
            {'#','T','.','.','#','#'},
            {'#','.','#','B','.','#'},
            {'#','.','.','.','.','#'},
            {'#','.','.','.','S','#'},
            {'#','#','#','#','#','#'}};
    cout << sol.minPushBox(grid) << endl; // Output: 5

    return 0;
}
