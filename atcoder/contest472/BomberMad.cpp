/*
    There is a grid with 
H rows and W columns. Each cell is an empty cell or a bomb cell. Let (i,j) denote the cell at the i-th row from the top and 
the j-th column from the left. The grid is given by H length- W strings 

(i,j) is a bomb cell. if '#'

For an empty cell 
(i,j), if there is no bomb cell in the 
i-th row nor in the 
j-th column, that cell is called a safe empty cell.

In one move, you can move from the current cell to an adjacent empty cell in the up, down, left, or right direction (you cannot move to a bomb cell). Find the number of empty cells 
(i,j) satisfying the following condition:

A safe empty cell can be reached from 
(i,j) in at most 
K moves.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int h, w, k;
    cin >> h >> w >> k;
    vector<string> grid(h);
    vector<bool> rowBomb(h, false), colBomb(w, false);

    for (int i = 0; i < h; ++i) {
        cin >> grid[i];
        for (int j = 0; j < w; ++j) {
            if (grid[i][j] == '#') {
                rowBomb[i] = true;
                colBomb[j] = true;
            }
        }
    }

    queue<pair<int, int>> q;
    vector<vector<int>> dist(h, vector<int>(w, -1));
    const vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (grid[i][j] == '.' && !rowBomb[i] && !colBomb[j]) {
                dist[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    // BFS
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        int d = dist[x][y];
        if (d == k) continue;  
        for (auto [dx, dy] : directions) {
            int nx = x + dx;
            int ny = y + dy;
            if (nx >= 0 && nx < h && ny >= 0 && ny < w &&
                grid[nx][ny] == '.' && dist[nx][ny] == -1) {
                dist[nx][ny] = d + 1;
                q.push({nx, ny});
            }
        }
    }

    long long emptyCells = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (dist[i][j] != -1) ++emptyCells;
        }
    }

    cout << emptyCells << endl;
    return 0;
}
