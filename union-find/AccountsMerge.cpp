// Leetcode Medium 721. Accounts Merge
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> parent;
    vector<int> size;

    int find(int x){
        int root = x;
        while (root != parent[root]) root = parent[root];
        int elem = x;
        while (elem != parent[elem]) {
            parent[elem] = root;
            elem = parent[elem];
        }
        return root;
    }

    void unite(int x, int y){
        int rootx = find(x);
        int rooty = find(y);
        if (rootx == rooty) return;
        if (size[rootx] < size[rooty]) swap(rootx, rooty);
        parent[rooty] = rootx;
        size[rootx] += size[rooty];
    }


    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> result;
        unordered_map<string, int> mapemail;
        vector<int> foundindex;
        int n = accounts.size(), j = 0;

        parent.resize(n, 0);
        size.resize(n, 1);

        for (int i=0;i<n;i++) parent[i] = i;
        for (int i=1;i<accounts[0].size();i++) mapemail[accounts[0][i]] = 0;
        for (int i=1;i<n;i++){
            foundindex.clear();

            for (j=1;j<accounts[i].size();j++){
                if (mapemail.count(accounts[i][j])){  
                    foundindex.push_back(mapemail[accounts[i][j]]);
                } else mapemail[accounts[i][j]] = i;
            }
            if (foundindex.empty()) continue;
            for (int k=0;k<foundindex.size();k++){
                unite(foundindex[k], i);
            }
        }

        int tempo = 0, index = 0;
        vector<vector<string>> ans(n);
        for (auto &it: mapemail){
            ans[find(it.second)].push_back(it.first);
        }

        for (int i=0;i<n;i++){
            if (ans[i].empty()) continue;
            sort(ans[i].begin(), ans[i].end());
            ans[i].insert(ans[i].begin(), accounts[i][0]);
            result.push_back(ans[i]);
        }

        parent.clear();
        size.clear();
        return result;
    }
};

int main() {
    Solution solution;
    vector<vector<string>> accounts = {{"John","johnsmith@mail.com","john_newyork@mail.com"}, {"John","johnsmith@mail.com","john00@mail.com"}, {"Mary","mary@mail.com"}, {"John","johnnybravo@mail.com"}};
    vector<vector<string>> result = solution.accountsMerge(accounts);
    for (int i=0;i<result.size();i++){
        cout<<"[";
        for (int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<", ";
        }
        cout<<"], ";
    }
    cout<<endl;

    accounts = {{"Gabe","Gabe0@m.co","Gabe3@m.co","Gabe1@m.co"},{"Kevin","Kevin3@m.co","Kevin5@m.co","Kevin0@m.co"},{"Ethan","Ethan5@m.co","Ethan4@m.co","Ethan0@m.co"},{"Hanzo","Hanzo3@m.co","Hanzo1@m.co","Hanzo0@m.co"},{"Fern","Fern5@m.co","Fern1@m.co","Fern0@m.co"}};
    result = solution.accountsMerge(accounts);
    for (int i=0;i<result.size();i++){
        cout<<"[";
        for (int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<", ";
        }
        cout<<"], ";
    }
    cout<<endl;


    return 0;
}
