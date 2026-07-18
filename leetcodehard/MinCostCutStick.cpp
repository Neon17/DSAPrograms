// Leetcode Hard 1547. Minimum Cost to Cut a Stick
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int dfs(vector<int>& cuts, int left, int right, int index, unordered_set<int>& visited){
        int cost = INT_MAX;
        if (index == -1){
            for (int i = 0; i < cuts.size(); i++){
                cost = min(cost, dfs(cuts, left, right, i, visited));
            }
            return cost;
        }
        visited.insert(index);
        for (int i=0;i<cuts.size();i++){
            if (!visited.count(i)) {
                if (i > cuts[index]) cost = min(cost, dfs(cuts, index, right, i, visited));
                else cost = min(cost, dfs(cuts, left, index, i, visited));
            }
        }
        if (cost == INT_MAX) cost = 0;
        cost += right - left;
        return cost;
    }

    // now let's start to think opposite from bottom to the top
    // let's think about remaining segment after cut and then go to the top to reach to DP solution

    vector<vector<int>> dp;
    vector<int> pts;

    int reverse(int left, int right){
        if (right - left <= 1) return dp[left][right] = 0;
        int cost = INT_MAX, temp = 0;
        if (dp[left][right] != -1) return dp[left][right];
        for (int i=left+1;i<right;i++){
            temp = (pts[right] - pts[left]) + reverse(left, i) + reverse(i, right);
            if (cost > temp) cost = temp;
        }
        return dp[left][right] = (cost == INT_MAX) ? 0 : cost;
    }

    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        
        pts.clear();
        pts.push_back(0);
        for (int c : cuts) pts.push_back(c);
        pts.push_back(n);
        
        int m = pts.size(); 
        dp.assign(m, vector<int>(m, -1)); 
        
        return reverse(0, m - 1); 
    }
};

int main(){
    return 0;
}

