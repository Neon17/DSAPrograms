// Leetcode Medium 1834. Single-Threaded CPU

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> processing;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> available;
        int n = tasks.size(), count = 0;
        vector<int> ans(n, -1);
        for (int i=0;i<n;i++) available.push({tasks[i][0], tasks[i][1], i});
        long long time = get<0>(available.top());

        while (!available.empty() || !processing.empty()){
            while (!available.empty() && get<0>(available.top())<=time){
                auto [enqueue, duration, idx] = available.top();
                available.pop();
                processing.push({duration, idx, enqueue});
            }
            if (!processing.empty()){
                auto [duration, idx, enqueue] = processing.top();
                ans[count++] = idx;
                processing.pop();
                time = max(time, (long long)enqueue) + duration;
            } else time = get<0>(available.top());
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> tasks;

    tasks = {{1,2},{2,4},{3,2},{4,1}};
    for (int i : sol.getOrder(tasks)) cout<<i<<" ";
    cout<<endl;

    tasks = {{7,10},{7,12},{7,5},{7,4},{7,2}};
    for (int i : sol.getOrder(tasks)) cout<<i<<" ";
    cout<<endl;
    return 0;
}
