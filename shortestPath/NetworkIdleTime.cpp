// Leetcode Medium 2039. The Time When the Network Becomes Idle
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;

class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int ans = 0, temp = 0;
        vector<vector<int>> adj = vector(patience.size(), vector<int>());
        for (int i=0;i<edges.size();i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> dist(patience.size(), INT_MAX);
        queue<int> que;
        dist[0] = 0; que.push(0);

        while (!que.empty()){
            int edge = que.front();
            int weight = dist[edge];
            que.pop();

            for (auto neighbor: adj[edge]){
                if (dist[edge] + 1 < dist[neighbor]){
                    dist[neighbor] = dist[edge] + 1;
                    que.push(neighbor);
                }
            }
        }
        for (int i=0;i<dist.size();i++) ans = max(ans, 2*dist[i]);
        for (int i=0;i<patience.size();i++){
            if (patience[i] >= dist[i]*2) continue;
            temp = dist[i]*2;
            temp = temp / patience[i];
            if (dist[i]*2 % patience[i] != 0) temp++;
            ans = max(ans, (temp-1)*patience[i] + dist[i]*2);
        }

        return ans+1;
    }
};

int main(){
    Solution s;
    vector<vector<int>> edges = {{0,1},{1,2}};
    vector<int> patience = {0,2,1};
    cout << s.networkBecomesIdle(edges, patience) << endl;

    edges = {{0,1},{0,2},{1,2}};
    patience = {0,10,10};
    cout << s.networkBecomesIdle(edges, patience) << endl;

    edges = {{0,1},{1,2},{2,3},{3,4}};
    patience = {0,2,2,2,2};
    cout << s.networkBecomesIdle(edges, patience) << endl;

    edges = {{0,1},{0,2},{1,2},{1,3},{3,4}};
    patience = {0,2,1,4,5};
    cout << s.networkBecomesIdle(edges, patience) << endl;

    return 0;
}

