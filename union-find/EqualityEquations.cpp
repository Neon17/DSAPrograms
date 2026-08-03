// Leetcode Medium 990. Satisfiability of Equality Equations

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    class DSU {
        public:
        vector<int> parent;
        vector<int> sz;
        bool cycle = false;

        DSU(int n){
            parent.resize(n);
            sz.resize(n, 1);
            for (int i=0;i<n;i++) {
                parent[i] = i;
            }
        }

        int find(int x){
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

            if (rootx == rooty) return;
            if (sz[rootx] < sz[rooty]) swap(rootx, rooty);
            parent[rooty] = rootx;
            sz[rootx] += sz[rooty];
        }

        void checkConflict(int x, int y){
            if (find(x) == find(y)) cycle = true;
        }

        bool isCyclic(){ return cycle; }
    };

    bool equationsPossible(vector<string>& equations) {
        bool ans = false;

        DSU ds(26);
        for (auto &eq : equations){
            if (eq[1] == '=') {
                ds.unite(eq[0]-'a', eq[3]-'a');
            }
        }

        for (auto &eq : equations){
            if (eq[1] == '!') {
                ds.checkConflict(eq[0]-'a', eq[3]-'a');
                if (ds.isCyclic()) return false;
            }
        }
        return true;
    }
};

int main(){
    Solution s;
    vector<string> equations = {"a==b","b!=a"};
    cout << s.equationsPossible(equations) << endl;

    equations = {"b==a","a==b"};
    cout << s.equationsPossible(equations) << endl;
    return 0;
}
