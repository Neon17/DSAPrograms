// Leetcode Medium 973. K Closest Points to Origin

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>> maxheap;
        for (int i=0;i<points.size();i++){
            long long temp = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            if (maxheap.size() >= k){
                if (maxheap.top().first <= temp) continue;
                maxheap.pop();
            }
            maxheap.push({temp, i});
        }
        vector<vector<int>> ans;
        for (int i=0;i<k;i++){
            auto [_, index] = maxheap.top();
            ans.push_back({points[index][0], points[index][1]});
            maxheap.pop();
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> points = {{1,3},{-2,2}};
    int k = 2;
    vector<vector<int>> result = sol.kClosest(points, k);
    for (const auto& point : result) {
        cout << "[" << point[0] << ", " << point[1] << "] ";
    }
    cout << endl;
    return 0;
}

