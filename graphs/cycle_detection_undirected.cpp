/*
    LeetCode / GFG: Detect Cycle in an Undirected Graph
    Given an undirected graph with V vertices and adjacency list adj.
    Return true if the graph contains a cycle, else false.
    Graph may contain multiple disconnected components.
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
    bool dfs(int V, vector<vector<int>>& adj, vector<char>& visited, int parent = -1){
        if (visited[V]) return true;
        visited[V] = 1;
        for (int neighbor: adj[V]){
            if (parent != neighbor){              
                if (visited[neighbor]) return true;
                bool ans = dfs(neighbor, adj, visited, V);
                if (ans) return true;
            }
        }
        return false;
    }

public:
    // Approach 1: DFS with parent tracking
    bool isCycleDFS(int V, vector<vector<int>>& adj) {
        vector<char> visited(V, 0);
        for (int i=0;i<V;i++){
            if (!visited[i]){
                if (dfs(i, adj, visited, -1)) return true;
            }
        }
        return false;
    }

    // Approach 2: BFS with queue storing {node, parent}
    bool isCycleBFS(int V, vector<vector<int>>& adj) {
        vector<char> visited(V, 0);

        for (int i=0;i<V;i++){
            if (visited[i]) continue;

            queue<pair<int, int>> que; 
            que.push({i, -1});
            visited[i] = 1;

            while (!que.empty()){
                auto [node, parent] = que.front();
                que.pop();

                for (auto& neighbor: adj[node]){
                    if (!visited[neighbor]){
                        visited[neighbor] = 1;
                        que.push({neighbor, node});
                    } else if (neighbor != parent) return true;
                }
            }
        }
        return false;
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

    // Test 1: Cycle present (1-2-3-4-1)
    V = 5;
    adj = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}};
    runTest(1, s.isCycleDFS(V, adj), true);
    runTest(1, s.isCycleBFS(V, adj), true);

    // Test 2: Tree / Acyclic
    V = 4;
    adj = {{1, 2}, {0}, {0, 3}, {2}};
    runTest(2, s.isCycleDFS(V, adj), false);
    runTest(2, s.isCycleBFS(V, adj), false);

    // Test 3: Disconnected graph with cycle in component 2
    V = 6;
    adj = {{1}, {0}, {3}, {2, 4}, {3, 5}, {4, 2}};
    runTest(3, s.isCycleDFS(V, adj), true);
    runTest(3, s.isCycleBFS(V, adj), true);

    // Test 4: Disconnected forest (Acyclic)
    V = 5;
    adj = {{1}, {0}, {3}, {2}, {}};
    runTest(4, s.isCycleDFS(V, adj), false);
    runTest(4, s.isCycleBFS(V, adj), false);

    return 0;
}
