// Leetcode Medium 1202. Smallest String With Swaps

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> parent;
    vector<int> size;

    int find(int x) {
        int root = x;
        while (root != parent[root]) root = parent[root];
        while (x != parent[x]) {
            int next = parent[x];
            parent[x] = root;
            x = next;
        }
        return root;
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) return;
        if (size[rootX] < size[rootY]) swap(rootX, rootY);
        parent[rootY] = rootX;
        size[rootX] += size[rootY];
    }

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        parent.resize(n);
        size.assign(n, 1);
        for (int i = 0; i < n; ++i) parent[i] = i;

        for (auto& p : pairs) unite(p[0], p[1]);

        string ans = "";
        unordered_map<int, int> ptr;
        unordered_map<int, vector<char>> components;
        for (int i=0;i<n;i++){
            int root = find(i);
            components[root].push_back(s[i]);
        }

        for (auto& [root, chars]: components){
            sort(chars.begin(), chars.end());
            ptr[root] = 0;
        }

        for (int i=0;i<n;i++){
            int root = find(i);
            ans.push_back(components[root][ptr[root]++]);
        }        
       
        return ans;
    }
};

int main(){
    Solution sol;
    string s = "dcab";
    vector<vector<int>> pairs = {{0,3},{1,2}};
    cout << sol.smallestStringWithSwaps(s, pairs) << endl;

    s = "dcab";
    pairs = {{0,3},{1,2},{0,2}};
    cout << sol.smallestStringWithSwaps(s, pairs) << endl;

    s = "cba";
    pairs = {{0,1},{1,2}};
    cout << sol.smallestStringWithSwaps(s, pairs) << endl;
    return 0;
}

