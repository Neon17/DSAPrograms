/**
 * 502. IPO
 * 
 * LeetCode Hard
 * Topics: Principal, Array, Greedy, Sorting, Heap (Priority Queue)
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:

    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> projects(n);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        priority_queue<int> maxHeap;
        
        for (int i=0;i<n;i++) pq.push({capital[i], profits[i]});
        for (int i=0;i<k;i++){
            while (!pq.empty() && pq.top().first <= w){
                maxHeap.push(pq.top().second);
                pq.pop();
            }
            if (maxHeap.empty()) break;
            w = maxHeap.top() + w;
            maxHeap.pop();
        }

        return w;
    }
};

int main() {
    Solution s;
    int k = 0, w = 0;
    vector<int> profits, capital;

    k = 3; w = 0; profits = {1,2,3}; capital = {0,1,2};
    cout<<s.findMaximizedCapital(k, w, profits, capital)<<endl;

    return 0;
}

