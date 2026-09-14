/**
 * 407. Trapping Rain Water II
 * Given an m x n integer matrix heightMap representing the height of each unit cell in a 2D elevation map, return the volume of water it can trap after raining.
 *
 * Example 1:
 * Input: heightMap = [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]
 * Output: 4
 * Explanation: After the rain, water is trapped between the blocks. The total volume of water trapped is 4.
 *
 * Example 2:
 * Input: heightMap = [[3,3,3,3,3],[3,2,2,2,3],[3,2,1,2,3],[3,2,2,2,3],[3,3,3,3,3]]
 * Output: 10
 * Explanation: After the rain, water is trapped between the blocks. The total volume of water trapped is 10.
 *
 *
 * Constraints:
 * m == heightMap.length
 * n == heightMap[i].length
 * 1 <= m, n <= 200
 * 0 <= heightMap[i][j] <= 2 * 10^4
 *
 *
 * LeetCode: https://leetcode.com/problems/trapping-rain-water-ii/description/
 * Difficulty: Hard
 * Topics: Junior, Array, Breadth-First Search, Heap (Priority Queue), Matrix
 * Acceptance: 64.0%
 *
 */

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        int m = heightMap.size();
        int n = heightMap[0].size();
        vector<vector<char>> visited(m, vector<char>(n, 0));
        vector<pair<int, int>> dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        int newspill = INT_MIN, res = 0;

        for (int i=0;i<m;i++) {
            pq.push({heightMap[i][0], i, 0});
            pq.push({heightMap[i][n-1], i, n-1});
            visited[i][0] = 1;
            visited[i][n-1] = 1;
        }
        for (int i=0;i<n;i++) {
            pq.push({heightMap[0][i], 0, i});
            pq.push({heightMap[m-1][i], m-1, i});
            visited[0][i] = 1;
            visited[m-1][i] = 1;
        }

        while (!pq.empty()){
            auto [height, x, y] = pq.top();
            newspill = height;
            pq.pop();

            for (auto [dx, dy]: dirs){
                int nx = x + dx;
                int ny = y + dy;

                if (nx >= 0 && nx < m && ny >=0 && ny < n){
                    if (!visited[nx][ny]){
                        res += max(0, newspill - heightMap[nx][ny]);
                        visited[nx][ny] = 1;
                        pq.push({max(newspill, heightMap[nx][ny]), nx, ny});
                    }
                }
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> heightMap;

    heightMap = {{1, 4, 3, 1, 3, 2}, {3, 2, 1, 3, 2, 4}, {2, 3, 3, 2, 3, 1}};
    cout << s.trapRainWater(heightMap) << endl;

    // heightMap = {{3,3,3,3,3},{3,2,2,2,3},{3,2,1,2,3},{3,2,2,2,3},{3,3,3,3,3}};
    // cout<<s.trapRainWater(heightMap)<<endl;

    // heightMap = {{12,13,1,12}, {13,4,13,12}, {13,8,10,12}, {12,13,12,12}, {13,13,13,13}};
    // cout<<s.trapRainWater(heightMap)<<endl;

    // heightMap = {{9,9,9,9,9,9,8,9,9,9,9},{9,0,0,0,0,0,1,0,0,0,9},{9,0,0,0,0,0,0,0,0,0,9},{9,0,0,0,0,0,0,0,0,0,9},{9,9,9,9,9,9,9,9,9,9,9}};
    // cout<<s.trapRainWater(heightMap)<<endl;

    // heightMap = {{18,13,13,17,12,11},{17,2,6,10,5,10},{11,10,2,8,8,2},{12,6,10,8,8,7},{18,4,7,6,7,4},{20,5,9,2,3,10}};
    // cout<<s.trapRainWater(heightMap)<<endl;

    // heightMap = {{5,8,7,7},{5,2,1,5},{7,1,7,1},{8,9,6,9},{9,8,9,9}};
    // cout<<s.trapRainWater(heightMap)<<endl;

    // heightMap = {{2,3,4},{5,6,7},{8,9,10},{11,12,13},{14,15,16}};
    // cout<<s.trapRainWater(heightMap)<<endl;
}

