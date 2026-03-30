/**
 * This is Leetcode problem 778: Swim in Rising Water
 * Leetcode Hard
 * Topics: Principal, Array, Binary Search, Depth-First Search, Breadth-First Search, Union-Find, Heap (Priority Queue), Matrix, Weekly Contest 70
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        int i=0, j=0, time = 0;
        pair<int, pair<int, int>> p;

        while (i<n-1 || j<n-1){
            if (i+1 < n && !visited[i+1][j]) pq.push({grid[i+1][j], {i+1, j}});
            if (i > 0 && !visited[i-1][j]) pq.push({grid[i-1][j], {i-1, j}});
            if (j > 0 && !visited[i][j-1]) pq.push({grid[i][j-1], {i, j-1}});
            if (j+1 < n && !visited[i][j+1]) pq.push({grid[i][j+1], {i, j+1}});
            p = pq.top();
            int new_time = max(p.first, grid[i][j]);
            time = max(time, new_time);
            visited[i][j] = true;
            i = p.second.first; j = p.second.second;
            while (!pq.empty()) pq.pop();
        }

        return time;
    }
};

int main() {
    Solution s;

    vector<vector<int>> grid = {{0,2},{1,3}};
    cout<<s.swimInWater(grid)<<endl; // expected 3

    vector<vector<int>> grid1 = {{0,1,2,3,4},{24,23,22,21,5},{12,13,14,15,16},{11,17,18,19,20},{10,9,8,7,6}}; 
    cout<<s.swimInWater(grid1)<<endl; // expected 16

    vector<vector<int>> grid2 = {{10,12,4,6},{9,11,3,5},{1,7,13,8},{2,0,15,14}};
    cout<<s.swimInWater(grid2)<<endl; // expected 14, but got 15

    return 0;
}

