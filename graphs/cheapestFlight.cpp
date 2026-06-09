/** 787. Cheapest Flights Within K Stops (Leetcode Medium)
 * 
 * There are n cities connected by some flights. 
 * You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that 
 * there is a flight from city fromi to city toi with cost pricei.
 * You are also given three integers src, dst, and k, 
 * return the cheapest price from src to dst with at most k stops. 
 * If there is no such route, return -1.
 * 
 * Example 1: 
 * Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 3, k = 1
 * Output: 200
 * Explanation: The graph is shown above. The cheapest price from city 0 to city 3 with at most 1 stop costs 200, as marked red in the picture.
 * 
 *  Example 2:
 * Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
 * Output: 500
 * Explanation: The graph is shown above. The cheapest price from city 0 to city 2 with at most 0 stops costs 500, as marked blue in the picture.
 * 
 * Example 3:
 * Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 1, k = 1
 * Output: 100
 * Explanation: The graph is shown above. The cheapest price from city 0 to city 1 with at most 1 stop costs 100, as marked red in the picture.
 * 
 * 
 * Constraints:
 * 1 <= n <= 100
 * 0 <= flights.length <= (n * (n - 1) / 2)
 * flights[i].length == 3
 * 0 <= fromi, toi < n
 * fromi != toi
 * 1 <= pricei <= 10^4
 * 0 <= src, dst < n
 * src != dst
 * 0 <= k < n
 * 
 * Topics: Principal, Dynamic Programming, Depth-First Search, Breadth-First Search, Graph Theory, Heap (Priority Queue), Shortest Path, Weekly Contest 72
 */

#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution {
public:
    // // bfs still need to be studied
    // int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    //     // Build graph: from -> list of (to, price)
    //     vector<vector<pair<int, int>>> graph(n);
    //     for (auto& f : flights) {
    //         graph[f[0]].emplace_back(f[1], f[2]);
    //     }
        
    //     // dist[city] = cheapest price known to reach that city
    //     vector<int> dist(n, __INT32_MAX__);
    //     dist[src] = 0;
        
    //     // BFS queue: (city, totalCost)
    //     queue<pair<int, int>> q;
    //     q.push({src, 0});
        
    //     int stops = 0;
    //     while (!q.empty() && stops <= k) {
    //         int size = q.size();
    //         // Make a copy of current distances for this level
    //         vector<int> tempDist = dist;
            
    //         for (int i = 0; i < size; i++) {
    //             auto [city, cost] = q.front(); q.pop();
    //             for (auto& [next, price] : graph[city]) {
    //                 int newCost = cost + price;
    //                 if (newCost < tempDist[next]) {
    //                     tempDist[next] = newCost;
    //                     q.push({next, newCost});
    //                 }
    //             }
    //         }
    //         dist = tempDist;
    //         stops++;
    //     }
        
    //     return dist[dst] == __INT32_MAX__ ? -1 : dist[dst];
    // }

    int dfs(unordered_map<int, vector<pair<int, int>>>& graph, int src, int dst, int k, int& path, unordered_set<int>& visited) {
        if (src == dst) return path;
        if (k < 0 || graph[src].size()==0) {
            return __INT32_MAX__;
        }
        if (visited.count(src)) return __INT32_MAX__;
        visited.insert(src);

        path += graph[src][0].second;
        int minpath = dfs(graph, graph[src][0].first, dst, k-1, path, visited);
        path -= graph[src][0].second;
        for (int i=1;i<graph[src].size();i++){
            path += graph[src][i].second;
            minpath = min(dfs(graph, graph[src][i].first, dst, k-1, path, visited), minpath);
            path -= graph[src][i].second;
        }
        visited.erase(src);
        return minpath;
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int, int>>> graph;
        for (const auto& flight : flights) {
            graph[flight[0]].emplace_back(flight[1], flight[2]);
        }
        int path = 0;
        unordered_set<int> visited;
        int ans = dfs(graph, src, dst, k, path, visited);
        return ans == __INT32_MAX__ ? -1 : ans;
    }
};


int main() {
    Solution sol;
    vector<vector<int>> flights = {{0,1,100},{1,2,100},{0,2,500}};
    vector<vector<int>> flights1 = {{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};
    cout << sol.findCheapestPrice(3, flights1, 0, 3, 1) << endl; // Output: 700
    cout << sol.findCheapestPrice(3, flights, 0, 2, 1) << endl; // Output: 200
    cout << sol.findCheapestPrice(3, flights, 0, 2, 0) << endl; // Output: 500  

    return 0;
}

