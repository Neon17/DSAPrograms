/*
    LeetCode 1192: Critical Connections in a Network (Tarjan's Bridge Algorithm)
    Given an undirected graph with n nodes and connections,
    find all critical connections (bridges) whose removal disconnects the graph.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    int INF = 1e9;
    vector<int> tin, low;
    vector<vector<int>> bridges;
    vector<char> visited;
    int time = 1;

    void dfs(int node, int parent, vector<vector<int>>& graph){
        
        tin[node] = time;
        low[node] = time;
        visited[node] = 1;
        time++;

        for (auto& neighbor: graph[node]){
            if (neighbor != parent && !visited[neighbor]){
                dfs(neighbor, node, graph);
            }
        }

        for (auto& neighbor: graph[node]){
            if (neighbor != parent) low[node] = min(low[node], low[neighbor]);
        }
        if (low[node] == tin[node] && parent != -1)bridges.push_back({parent, node});
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        INF = 1e9;
        tin.assign(n, INF);
        low.assign(n, INF);
        visited.assign(n, 0);
        bridges.clear();
        time = 0;

        vector<vector<int>> graph(n);
        for (int i=0;i<connections.size();i++){
            graph[connections[i][0]].push_back(connections[i][1]);
        }

        dfs(0, -1, graph);
        return bridges;
    }
};

void runTest(int id, vector<vector<int>> actual, vector<vector<int>> expected) {
    for (auto& edge : actual) if (edge[0] > edge[1]) swap(edge[0], edge[1]);
    for (auto& edge : expected) if (edge[0] > edge[1]) swap(edge[0], edge[1]);
    sort(actual.begin(), actual.end());
    sort(expected.begin(), expected.end());

    bool passed = (actual == expected);
    cout << "Test " << id << ": " << (passed ? "[PASSED]" : "[FAILED]") << "\n";
}

int main() {
    Solution s;

    // Test 1: Cycle 0-1-2-0 with bridge 1-3
    int n1 = 4;
    vector<vector<int>> conn1 = {{0, 1}, {1, 2}, {2, 0}, {1, 3}};
    runTest(1, s.criticalConnections(n1, conn1), {{1, 3}});

    // Test 2: Two triangles connected by bridge 2-3
    int n2 = 6;
    vector<vector<int>> conn2 = {{0, 1}, {1, 2}, {2, 0}, {2, 3}, {3, 4}, {4, 5}, {5, 3}};
    runTest(2, s.criticalConnections(n2, conn2), {{2, 3}});

    // Test 3: Simple cycle with no bridges
    int n3 = 3;
    vector<vector<int>> conn3 = {{0, 1}, {1, 2}, {2, 0}};
    runTest(3, s.criticalConnections(n3, conn3), {});

    return 0;
}

