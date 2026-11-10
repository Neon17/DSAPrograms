/*
    Leetcode Medium 108. Minimum Cost to Make Red Nodes Connected

    You are given an integer n representing a tree with n nodes, rooted at node 0.
    edges[i] = [ui, vi] is an undirected edge. colors[i] is 'R' or 'B'.

    You may flip the color of any node:
        'R' -> 'B'  or  'B' -> 'R'
    Flipping node u costs the size of u's subtree (in the tree rooted at 0).

    Goal: perform flips so that the Red nodes form ONE connected component
    (blue nodes may be scattered arbitrarily; zero red nodes is also valid).

    Return the minimum total cost.

    NOTE: flipping node u changes only u's own color, but the BILL is subtree size.
          The tree is n-ary (not binary!) and is given as an edge list, not TreeNode*.

    Approach hint (if you want it):
        sz[u]      = subtree size under root 0
        inside[u]  = cost to blue-ify every ORIGINAL red node in subtree(u)
        dp[u]      = min cost s.t. u is red AND all reds in subtree(u) connect to u
        dp[u] = (sz[u] if colors[u]=='B' else 0) + sum over children v of min(inside[v], dp[v])
                     ^ one min per child (choice), then SUM (obligation)
        answer = min( inside[0] ,
                      min over u of  dp[u] + inside[0] - inside[u] )

    Complexity: O(n) time, O(n) space. No rerooting needed (root fixed at 0).
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

/* ---------------------------------------------------------------
   Helpers: the tree is n-ary & given as an edge list, so unlike the
   binary-tree files here, there is no TreeNode*. The solution below
   builds the adjacency list inline; these two stay as optional tools
   (bfs order = escape hatch if recursion depth ever becomes a worry).
---------------------------------------------------------------- */
void buildAdjacency(int n, const vector<vector<int>>& edges, vector<vector<int>>& adj) {
    adj.assign(n, {});
    for (const auto& e : edges) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
}

// order[0] = 0 (root) and every parent appears before its children
void bfsFromRoot(int n, const vector<vector<int>>& adj, vector<int>& order, vector<int>& parent) {
    parent.assign(n, -1);
    parent[0] = -2;             // sentinel so we never walk back to root
    order.clear();
    order.push_back(0);
    for (size_t i = 0; i < order.size(); ++i) {
        int u = order[i];
        for (int v : adj[u]) {
            if (v == parent[u]) continue;
            parent[v] = u;
            order.push_back(v);
        }
    }
}

class Solution {
    vector<long long> sz, inside, dp;
    long long cost;

    void fillSize(vector<vector<int>>& adj, int parent = -1, int index = 0){
        for (const auto& neighbor: adj[index]){
            if (neighbor == parent) continue;
            fillSize(adj, index, neighbor);
            sz[index] += sz[neighbor];
        }
    }
    void fillInside(const string& colors, const vector<vector<int>>& adj, int parent = -1, int index = 0){
        if (colors[index] == 'R') inside[index] = sz[index];
        for (const auto& neighbor: adj[index]){
            if (neighbor == parent) continue;
            fillInside(colors, adj, index, neighbor);
            inside[index] += inside[neighbor];
        }
    }

    void postorder(const string& colors, const vector<vector<int>>& adj, int parent = -1, int index = 0){
        if (colors[index] == 'B') dp[index] += sz[index];
        for (const auto& neighbor: adj[index]){
            if (neighbor == parent) continue;
            postorder(colors, adj, index, neighbor);
            dp[index] += min(inside[neighbor], dp[neighbor]);
        }
        cost = min(dp[index] + inside[0] - inside[index], cost);
    }
public:
    long long minCost(int n, string colors, vector<vector<int>>& edges) {
        inside.assign(n, 0);
        sz.assign(n, 1);
        dp.assign(n, 0);
        vector<vector<int>> adj(n);

        for (const auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        fillSize(adj);
        fillInside(colors, adj);
        cost = inside[0]; 
        postorder(colors, adj);
        return cost;
    }
};

/* ---------------------------------------------------------------
   Test harness (expected vs actual, like a mini leetcode judge)
---------------------------------------------------------------- */
struct TestCase {
    int n;
    string colors;
    vector<vector<int>> edges;
    long long expected;
};

void printTest(const TestCase& t, size_t idx, long long actual, bool pass) {
    cout << "Test " << (idx + 1) << ": "
         << "n=" << t.n << " colors=\"" << t.colors << "\" edges=[";
    for (size_t i = 0; i < t.edges.size(); ++i) {
        cout << "[" << t.edges[i][0] << "," << t.edges[i][1] << "]";
        if (i + 1 < t.edges.size()) cout << ",";
    }
    cout << "]\n"
         << "   expected: " << t.expected << "\n"
         << "   actual  : " << actual << "\n"
         << (pass ? "   PASS ✓" : "   FAIL ✗") << "\n\n";
}

int main() {
    vector<TestCase> tests = {
        // ---- the four official leetcode examples ----
        {3, "RBR",  {{0,1},{1,2}},          1},  // Ex1: flip node 2 to blue (cost 1)
        {3, "RBR",  {{0,1},{0,2}},          0},  // Ex2: {0,2} already connected
        {4, "BRRR", {{0,1},{0,2},{0,3}},    2},  // Ex3: keep one red leaf, flip other two
        {3, "BBB",  {{0,1},{1,2}},          0},  // Ex4: no red nodes, valid as-is

        // ---- extra hand-verified cases ----
        {4, "RRBR", {{0,1},{1,2},{2,3}},    1},  // gap path 0R-1R-2B-3R: delete red 3 (cost 1)
        {5, "BRRRB",{{0,1},{0,2},{0,3},{1,4}}, 2}, // deep star: keep pair {1,4}, flip 2 & 3
        {4, "BRBR", {{0,1},{0,2},{1,3}},    0},  // reds {1,3} already connected (B glue free!)
        {5, "BRBBR",{{0,1},{0,2},{0,3},{3,4}}, 1}, // star: keep red 1, flip red 4

        // ---- tiny edge cases ----
        {1, "R", {},                        0},  // single red node = one component
        {1, "B", {},                        0},  // single blue node = no reds, valid
    };

    Solution s;
    int failed = 0;
    for (size_t i = 0; i < tests.size(); ++i) {
        TestCase t = tests[i];
        long long actual = s.minCost(t.n, t.colors, t.edges);
        bool pass = (actual == t.expected);
        if (!pass) failed++;
        printTest(t, i, actual, pass);
    }

    cout << "==============================\n"
         << (failed == 0 ? "ALL TESTS PASSED ✓"
                         : to_string(failed) + " TEST(S) FAILED ✗")
         << "\n==============================\n";
    return failed == 0 ? 0 : 1;
}
