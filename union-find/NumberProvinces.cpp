// Leetcode Medium 547: Number of Provinces
// Let's try DSU for the first time

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    class DSU {
        public:
        vector<int> size;
        vector<int> parent;

        DSU(int n){
            size.resize(n, 1);
            parent.resize(n);
            for(int i = 0; i < n; i++){
                parent[i] = i;
            }
        }

        int find(int x){
            if (parent[x] == x){
                return x;
            }
            return parent[x] = find(parent[x]);
        }

        void unite(int x, int y){
            int parentx = find(x);
            int parenty = find(y);

            if (parentx == parenty) return;
            if (size[parentx] < size[parenty]) swap(parentx, parenty);            
            parent[parenty] = parentx;
            size[parentx] += size[parenty];
        }

        bool connected(int x, int y){
            return (find(x) == find(y));
        } 
    };

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DSU ds(n);
        unordered_set<int> set;
        int cities = 0, temp = 0;

        for (int i=0;i<n;i++){
            for (int j=i+1;j<n;j++){
                if (isConnected[i][j]) ds.unite(i, j);
            }
        }

        for (int i=0;i<n;i++){
            temp = ds.find(i);
            if ( !set.count(temp) ){
                cities++;
                set.insert(temp);
            }
        }

        return cities;   
    }
};

int main() {
    Solution s;
    vector<vector<int>> isConnected = {{1,1,0},{1,1,0},{0,0,1}};
    cout << s.findCircleNum(isConnected) << endl;

    return 0;
}

