// Leetcode Medium 743. Network Delay Time
// I am practicing Dijkstra's algorithm

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj = vector(n+1, vector<pair<int,int>>());
        vector<int> dist(n, INT_MAX);
        for (int i=0;i<times.size();i++) adj[times[i][0]].push_back({times[i][1], times[i][2]});
        dist[k-1] = 0;
        int ans = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        minHeap.push({0, k});
        
        while (!minHeap.empty()){
            auto [value, visit] = minHeap.top();
            minHeap.pop();

            if (value > dist[visit-1]) continue;
            for (auto &[first, second]: adj[visit]){
                if (value + second < dist[first-1]) {
                    dist[first-1] = value + second;
                    minHeap.push({dist[first-1], first});
                }
            }
        }
        for (int i=0;i<n;i++) {
            if (dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }      
        return ans;
    }
};

int main(){
    Solution s;
    vector<vector<int>> times = {{2,1,1},{2,3,1},{3,4,1}};
    int n = 4, k = 2;
    cout << s.networkDelayTime(times, n, k) << endl;

    times = {{1,2,1}};
    n = 2, k = 1;
    cout << s.networkDelayTime(times, n, k) << endl;

    times = {{1,2,1}};
    n = 2, k = 2;
    cout << s.networkDelayTime(times, n, k) << endl;

    return 0;
}
