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
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;

class Solution
{
    unordered_set<string> visited; // stored as "i,j"
    unordered_set<string> collected; // already calculated area of and increase level size
    unordered_set<string> calculated;
public:
    int surrounding(vector<vector<int>> &heightMap, int i = 0, int j = 0)
    {
        // returns min height
        int up = __INT32_MAX__, down = __INT32_MAX__, left = __INT32_MAX__, right = __INT32_MAX__;

        if (i > 0)
            up = heightMap[i - 1][j];
        if (i < (heightMap.size() - 1))
            down = heightMap[i + 1][j];
        if (j > 0)
            left = heightMap[i][j - 1];
        if (j < (heightMap[0].size() - 1))
            right = heightMap[i][j + 1];

        int min1, min2, min3, minIndex1, minIndex2, minIndex3;

        min1 = min(up, down);
        min2 = min(left, right);
        min3 = min(min1, min2);
        return min3;
    }

    int maxSurrounding(vector<vector<int>> &heightMap, int i=0, int j=0){
        // returns min height
        int up = __INT32_MAX__, down = __INT32_MAX__, left = __INT32_MAX__, right = __INT32_MAX__;

        if (i > 0 && (collected.find(to_string(i-1) + "," + to_string(j)) == collected.end()))
            up = heightMap[i - 1][j];
        if (i < (heightMap.size() - 1) && (collected.find(to_string(i+1) + "," + to_string(j)) == collected.end()))
            down = heightMap[i + 1][j];
        if (j > 0 && (collected.find(to_string(i) + "," + to_string(j-1)) == collected.end()))
            left = heightMap[i][j - 1];
        if (j < (heightMap[0].size() - 1) && (collected.find(to_string(i) + "," + to_string(j+1)) == collected.end()))
            right = heightMap[i][j + 1];

        int min1, min2, min3, minIndex1, minIndex2, minIndex3;

        min1 = min(up, down);
        min2 = min(left, right);
        min3 = min(min1, min2);

        if (min3 == __INT32_MAX__) return surrounding(heightMap, i, j);
        return min3;
    }

    vector<string> split_string_find(string s, const string& delimiter) {
        vector<string> tokens;
        size_t pos = 0;
        string token;
        while ((pos = s.find(delimiter)) != string::npos) {
            token = s.substr(0, pos);
            tokens.push_back(token);
            s.erase(0, pos + delimiter.length());
        }
        tokens.push_back(s);
        return tokens;
    }

    int findActualHeight(vector<vector<int>> &heightMap, int i=0, int j=0){
        // find actual min height of border that is not in collected
        // after that remove collected
        // because it is end of contiguous one
        // we have do bfs to find border and find min height of border

        int minheight =  __INT32_MAX__;
        int row = 0, col = 0, up = 0, down = 0, left = 0, right = 0;

        // cout<<"collect = ";
        for (auto &collect: collected){
            // cout<<collect<<" ";
            up = __INT32_MAX__, down = __INT32_MAX__, left = __INT32_MAX__, right = __INT32_MAX__;
            vector<string> loc = split_string_find(collect, ",");
            row = stoi(loc[0]); col = stoi(loc[1]);

            if (row > 0 && (collected.find(to_string(row-1) + "," + to_string(col)) == collected.end()))
                up = heightMap[row - 1][col];
            if (row < (heightMap.size() - 1) && (collected.find(to_string(row+1) + "," + to_string(col)) == collected.end()))
                down = heightMap[row + 1][col];
            if (col > 0 && (collected.find(to_string(row) + "," + to_string(col-1)) == collected.end()))
                left = heightMap[row][col - 1];
            if (col < (heightMap[0].size() - 1) && (collected.find(to_string(row) + "," + to_string(col+1)) == collected.end()))
                right = heightMap[row][col + 1];

            int min1, min2, min3, minIndex1, minIndex2, minIndex3;

            min1 = min(up, down);
            min2 = min(left, right);
            min3 = min(min1, min2);

            minheight = min(minheight, min3);           
        }

        return minheight;
    }

    int trapRainWater(vector<vector<int>> &heightMap)
    {
        int area = 0;
        if (heightMap.size() <= 2 || heightMap[0].size() <= 2)
            return area;

        vector<pair<int, int>> current;

        int row = heightMap.size();
        int col = heightMap[0].size();
        int maxLevel = __INT32_MAX__;
        int up, down, left, right;
        bool found = false; int minBorder = 0;
        int borderLevel = -1;

        for (int i = 1; i < row - 1; i++)
        {
            up = i;
            down = i;

            for (int j = 1; j < col - 1; j++)
            {
                string prepare = to_string(i) + "," + to_string(j);
                if (calculated.count(prepare)) continue;

                left = j;
                right = j;

                queue<pair<int, int>> que;
                que.push({i, j});
                found = false;
                borderLevel = -1;

                while (!que.empty())
                {
                    int size = que.size();
                    for (int k = 0; k < size; k++)
                    {
                        pair<int, int> p = que.front();
                        que.pop();
                        if (visited.find(to_string(p.first) + "," + to_string(p.second)) != visited.end()) continue;

                        // problem is finding the very min height of border surrounding our selected contiguous region
                        maxLevel = maxSurrounding(heightMap, p.first, p.second);
                        // maxLevel = min(maxLevel, surrounding(heightMap, p.first, p.second));
                        visited.insert(to_string(p.first) + "," + to_string(p.second));
                        collected.insert(to_string(p.first) + "," + to_string(p.second));
                        calculated.insert(to_string(p.first) + "," + to_string(p.second));
                        current.push_back({p.first, p.second});
                        
                        if (maxLevel > heightMap[p.first][p.second]){
                            found = true;
                            borderLevel = findActualHeight(heightMap, p.first, p.second);
                            if (maxLevel > borderLevel) maxLevel = borderLevel;
                            // cout<<"maxlevel = "<<maxLevel<<", borderLevel = "<<borderLevel<<", x,y = "<<p.first<<","<<p.second<<endl;
                            area += maxLevel - heightMap[p.first][p.second];
                            heightMap[p.first][p.second] = maxLevel;
                        } else if (maxLevel < heightMap[p.first][p.second]) continue;
 
                        if ((p.first-1) > 0 && (heightMap[p.first - 1][p.second] <= heightMap[p.first][p.second]))
                        {
                            que.push({p.first - 1, p.second});
                        }
                        if ((p.first+1) < (row - 1) && (heightMap[p.first + 1][p.second] <= heightMap[p.first][p.second]))
                        {
                            que.push({p.first + 1, p.second});
                        }
                        if ((p.second-1) > 0 && (heightMap[p.first][p.second - 1] <= heightMap[p.first][p.second]))
                        {
                            que.push({p.first, p.second - 1});
                        }
                        if ((p.second+1) < (col - 1) && (heightMap[p.first][p.second + 1] <= heightMap[p.first][p.second]))
                        {
                            que.push({p.first, p.second + 1});
                        } 
                    }
                }

                if (found){
                    for (auto &p : current)
                    {
                        if (maxLevel <= heightMap[p.first][p.second]) continue;
                        area += maxLevel - heightMap[p.first][p.second];
                        heightMap[p.first][p.second] = maxLevel;
                    }
    
                }
                maxLevel = __INT32_MAX__;
                borderLevel = -1;
                visited.clear();
                collected.clear();
                current.clear();
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

    // heightMap = {{1, 4, 3, 1, 3, 2}, {3, 2, 1, 3, 2, 4}, {2, 3, 3, 2, 3, 1}};
    // cout << s.trapRainWater(heightMap) << endl;

    heightMap = {{3,3,3,3,3},{3,2,2,2,3},{3,2,1,2,3},{3,2,2,2,3},{3,3,3,3,3}};
    cout<<s.trapRainWater(heightMap)<<endl;

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
