/**
 * This is Leetcode problem 778: Swim in Rising Water
 * Leetcode Hard
 * Topics: Principal, Array, Binary Search, Depth-First Search, Breadth-First Search, Union-Find, Heap (Priority Queue), Matrix, Weekly Contest 70
 */

 /**
  * I tried to solve by taking local minimums at first
  * But that is not correct, because we can have a local minimum that is not on the path to the destination
  * 
  */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    /**
     * In this approach, I am doing a breadth first search to find the minimum time to reach each node from the source node.
     * But, it can't be fully used because visited[][] blocks the update of the node
     * Later I found, putting 0,0 with height on priority queue at first
     * Then, popping the element from min heap (priority queue) and pushing its neighbors with their height on the priority queue
     * This way, we can always get the minimum height node from the priority queue and update the level (time) to reach that node
     * Finally, when we reach the destination node, we can return the level (time) to reach that node
     */
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size(), level = 0;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pair<int, int> temp;
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        pq.push({grid[0][0], {0, 0}});
        level = grid[0][0];

        while (!pq.empty()){
            level = max(level, pq.top().first);
            temp = pq.top().second;
            pq.pop();
            if (visited[temp.first][temp.second]) continue;
            visited[temp.first][temp.second] = true;
            if (temp.first == n - 1 && temp.second == n - 1) break;

            if (temp.first > 0 && !visited[temp.first - 1][temp.second]) pq.push({grid[temp.first - 1][temp.second], {temp.first - 1, temp.second}});
            if (temp.first < n - 1 && !visited[temp.first + 1][temp.second]) pq.push({grid[temp.first + 1][temp.second], {temp.first + 1, temp.second}});
            if (temp.second > 0 && !visited[temp.first][temp.second - 1]) pq.push({grid[temp.first][temp.second - 1], {temp.first, temp.second - 1}});
            if (temp.second < n - 1 && !visited[temp.first][temp.second + 1]) pq.push({grid[temp.first][temp.second + 1], {temp.first, temp.second + 1}});
        }
        
        return level;
    }
};

int main() {
    Solution s;

    vector<vector<int>> grid = {{0,2},{1,3}};
    cout<<s.swimInWater(grid)<<endl; // expected 3

    vector<vector<int>> grid1 = {{0,1,2,3,4},{24,23,22,21,5},{12,13,14,15,16},{11,17,18,19,20},{10,9,8,7,6}}; 
    cout<<s.swimInWater(grid1)<<endl; // expected 16

    vector<vector<int>> grid2 = {{10,12,4,6},{9,11,3,5},{1,7,13,8},{2,0,15,14}};
    cout<<s.swimInWater(grid2)<<endl; // expected 14

    return 0;
}

