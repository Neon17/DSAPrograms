/*
    LeetCode 207 / GFG: Detect Cycle in a Directed Graph
    Given a directed graph with V vertices and adjacency list adj.
    Return true if the graph contains a directed cycle, else false.
    Graph may contain cross-edges and multiple disconnected components.
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
    bool dfs(int V, vector<vector<int>>& adj, vector<int>& visited){
        if (visited[V] == 2) return false;
        visited[V] = 1;
        for (auto& neighbor: adj[V]){
            if (visited[neighbor] == 1) return true;
            bool ans = dfs(neighbor, adj, visited);
            if (ans) return true;
        }
        visited[V] = 2;
        return false;
    }

public:
    // Approach 1: DFS with 3-state coloring (0: unvisited, 1: visiting, 2: visited)
    bool isCyclicDFS(int V, vector<vector<int>>& adj) {
        vector<int> visited(V, 0);
        for (int i=0;i<V;i++){
            if (visited[i] == 0){
                bool temp = dfs(i, adj, visited);
                if (temp) return true;
            }
        }
        return false;
    }

    // Approach 2: BFS Kahn's Algorithm (In-degree count)
    bool isCyclicBFS(int V, vector<vector<int>>& adj) {
        vector<int> indegree(V, 0);
        queue<int> que;
        int count = 0;

        for (int i=0;i<V;i++){
            for (int j=0;j<adj[i].size();j++) indegree[adj[i][j]]++;
        }
        for (int i=0;i<V;i++){
            if (indegree[i] == 0) que.push(i);
        }
        while (!que.empty()){
            int node = que.front();
            que.pop();
            count++;

            for (int neighbor: adj[node]){
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) que.push(neighbor);
            }
        }
        return count != V;
    }
};

void runTest(int id, bool actual, bool expected) {
    cout << "Test " << id << ": " << (actual == expected ? "[PASSED]" : "[FAILED]")
         << " (Got: " << actual << ", Expected: " << expected << ")\n";
}

int main() {
    Solution s;
    int V;
    vector<vector<int>> adj;

    // Test 1: Directed cycle (1 -> 2 -> 3 -> 1)
    V = 4;
    adj = {{1}, {2}, {3}, {1}};
    runTest(1, s.isCyclicDFS(V, adj), true);
    runTest(1, s.isCyclicBFS(V, adj), true);

    // Test 2: Diamond DAG (Acyclic cross-edges)
    V = 4;
    adj = {{1, 2}, {3}, {3}, {}};
    runTest(2, s.isCyclicDFS(V, adj), false);
    runTest(2, s.isCyclicBFS(V, adj), false);

    // Test 3: Disconnected components with cycle in component 2
    V = 5;
    adj = {{1}, {}, {3}, {4}, {2}};
    runTest(3, s.isCyclicDFS(V, adj), true);
    runTest(3, s.isCyclicBFS(V, adj), true);

    // Test 4: Self-loop (1 -> 1)
    V = 3;
    adj = {{1}, {1}, {0}};
    runTest(4, s.isCyclicDFS(V, adj), true);
    runTest(4, s.isCyclicBFS(V, adj), true);

    return 0;
}
