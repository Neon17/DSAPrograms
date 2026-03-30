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

/**
 * My previous solution was to do BFS from each cell and find the minimum height of the surrounding cells. 
 * I was doing BFS from each cell and continuing until I find a cell that is higher than the current cell. 
 * Then, I was calculating the water trapped in that cell and adding it to the total area.
 * Then, I was updating the height of the current cell to the minimum height of the surrounding cells.
 * This was giving me TLE because of the large input size.
 * Also, it was not giving the correct answer because I was not considering the case where there are multiple cells with the same height.
 */

/**
 * Later, I asked for hint on deepseek and got hint to use priority queue
 * The idea was to push all border cells into the priority queue and then do BFS from the border cells.
 * The priority queue will always give us the cell with the minimum height.
 * We will pop the cell from the priority queue and then check its neighbors and update accordingly.
 */

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;

class Solution
{
   
public:

    int trapRainWater(vector<vector<int>> &heightMap)
    {
        int area = 0, poppedHeight = 0, neighborHeight = 0, height = 0;
        int m = heightMap.size();
        int n = heightMap[0].size();
        pair<int, pair<int, int>> top;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int j=0;j<n;j++){
            pq.push({heightMap[0][j], {0, j}});
            pq.push({heightMap[m-1][j], {m-1, j}});
            visited[0][j] = true;
            visited[m-1][j] = true;
        }

        for (int i=1;i<(m-1);i++){
            pq.push({heightMap[i][0], {i, 0}});
            pq.push({heightMap[i][n-1], {i, n-1}});
            visited[i][n-1] = true;
            visited[i][0] = true;
        }
        
        while (!pq.empty()){
            top = pq.top();
            pq.pop();
            int row = top.second.first, col = top.second.second;

            if (row > 0 && !visited[row-1][col]){
                height = max(top.first, heightMap[row-1][col]);
                area += max(0, top.first - heightMap[row-1][col]);
                pq.push({height, {row-1, col}});
                visited[row-1][col] = true;
            }
            if (row < m-1 && !visited[row+1][col]){
                height = max(top.first, heightMap[row+1][col]);
                area += max(0, top.first - heightMap[row+1][col]);
                pq.push({height, {row+1, col}});
                visited[row+1][col] = true;
            }
            if (col < n-1 && !visited[row][col+1]){
                height = max(top.first, heightMap[row][col+1]);
                area += max(0, top.first - heightMap[row][col+1]);
                pq.push({height, {row, col+1}});
                visited[row][col+1] = true;
            }
            if (col > 0 && !visited[row][col-1]){
                height = max(top.first, heightMap[row][col-1]);
                area += max(0, top.first - heightMap[row][col-1]);
                pq.push({height, {row, col-1}});
                visited[row][col-1] = true;
            }
        }

        return area;
    }
};

int main()
{

    /**
     * [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]
     [[3,3,3,3,3],[3,2,2,2,3],[3,2,1,2,3],[3,2,2,2,3],[3,3,3,3,3]]
     */

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
    
    return 0;
}
