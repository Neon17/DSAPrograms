/*
    Leetcode Medium 399. Evaluate Division

    You are given an array of variable pairs equations and an array of real numbers values,
        where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]. 
    Each Ai or Bi is a string that represents a single variable.

    You are also given some queries, where 
        queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?.

    Return the answers to all queries. If a single answer cannot be determined, return -1.0.

    Note: The input is always valid. 
    You may assume that evaluating the queries will not result in division by zero and that there is no contradiction.

    Note: The variables that do not occur in the list of equations are undefined, so the answer cannot be determined for them.

    Constraints:
        1 <= equations.length <= 20
        equations[i].length == 2
        1 <= Ai.length, Bi.length <= 5
        values.length == equations.length
        0.0 < values[i] <= 20.0
        1 <= queries.length <= 20
        queries[i].length == 2
        1 <= Cj.length, Dj.length <= 5
        Ai, Bi, Cj, Dj consist of lower case English letters and digits.
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    unordered_map<string, vector<pair<string, double>>> graph;

    void dfs(string node, string target, double prod, unordered_set<string>& visited,  bool& found, double& ans){
        if (!graph.count(node) || !graph.count(target)) return;
        if (node == target) {
            ans = prod;
            found = true;
            return;
        }
        visited.insert(node);
        for (auto [nxt, w]: graph[node]){
            if (!visited.count(nxt)){
                dfs(nxt, target, prod*w, visited, found, ans);
                if (found) return;
            }
        }
        visited.erase(node);
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();

        for (int i=0;i<n;i++){
            graph[equations[i][0]].push_back({equations[i][1], values[i]});
            graph[equations[i][1]].push_back({equations[i][0], 1/values[i]});
        }

        vector<double> res;
        for (int i=0;i<queries.size();i++){
            bool found = false;
            double ways = -1.0;
            unordered_set<string> visited;
            dfs(queries[i][0], queries[i][1], 1.0, visited, found, ways);
            res.push_back(ways);
        }
        graph.clear();

        return res;
    }
};

int main(){
    vector<vector<string>> equations; vector<double> values; vector<vector<string>> queries;
    Solution s; vector<double> ans;

    equations = {{"a","b"},{"b","c"}}; values = {2.0,3.0}; queries = {{"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}};
    ans = s.calcEquation(equations, values, queries);
    for (double d: ans) cout << d << " "; cout << endl; // Expected output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]

    equations = {{"a","b"},{"b","c"},{"bc","cd"}}; values = {1.5,2.5,5.0}; queries = {{"a","c"},{"c","b"},{"bc","cd"},{"cd","bc"}};
    ans = s.calcEquation(equations, values, queries);
    for (double d: ans) cout << d << " "; cout << endl; // Expected output: [3.75000,0.40000,5.00000,0.20000]

    equations = {{"a","b"}}; values = {0.5}; queries = {{"a","b"},{"b","a"},{"a","c"},{"x","y"}};
    ans = s.calcEquation(equations, values, queries);
    for (double d: ans) cout << d << " "; cout << endl; // Expected output: [0.50000,2.00000,-1.00000,-1.00000]

    equations = {{"x1", "x2"}}; values = {3.0}; queries = {{"x9", "x2"}, {"x9", "x9"}};
    ans = s.calcEquation(equations, values, queries);
    for (double d: ans) cout << d << " "; cout << endl; // Expected output: [-1.00000,-1.00000]

    return 0;  
}

