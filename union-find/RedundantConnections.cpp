// Leetcode Medium 684. Redundant Connection

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> parent;
    vector<int> sz;
    vector<int> ans;

    int find(int x) {
        int root = x;
        while (parent[root] != root)
            root = parent[root];
        while (parent[x] != x) {
            int next = parent[x];
            parent[x] = root;
            x = next;
        }
        return root;
    }

    void unite(int x, int y){
        int rootx = find(x);
        int rooty = find(y);
        if (rootx == rooty) {
            ans = {x, y};
            return;
        }
        if (sz[rootx] < sz[rooty]) swap(rootx, rooty);
        parent[rooty] = rootx;
        sz[rootx] += sz[rooty];
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n+1);
        sz.resize(n+1, 1);
        for (int i=0;i<=n;i++) parent[i] = i;
        for (int i=0;i<n;i++) unite(edges[i][0], edges[i][1]);
        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> edges = {{1,2}, {1,3}, {2,3}};
    vector<int> result = sol.findRedundantConnection(edges);
    cout << "Redundant connection: [" << result[0] << ", " << result[1] << "]" << endl;

    edges = {{1,2}, {2,3}, {3,4}, {1,4}, {1,5}};
    result = sol.findRedundantConnection(edges);
    cout << "Redundant connection: [" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}

