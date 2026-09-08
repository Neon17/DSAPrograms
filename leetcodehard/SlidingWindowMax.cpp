/*
    Leetcode Hard 239. Sliding Window Maximum

    You are given an array of integers nums, 
        there is a sliding window of size k which is moving from the very left of the array to the very right. 
    You can only see the k numbers in the window. 
    Each time the sliding window moves right by one position.

    Return the max sliding window.

    Constraints:
    1 <= nums.length <= 105
    -104 <= nums[i] <= 104
    1 <= k <= nums.length
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void printVector(vector<int> &v){
    for (int i=0;i<v.size();i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        priority_queue<pair<int,int>> pq;
        vector<char> deleted(nums.size(), 0);

        for (int i=0;i<nums.size();i++){
            pq.push({nums[i], i});
            if (i < k-1) continue;
            while (!pq.empty() && deleted[pq.top().second]) pq.pop();
            res.push_back(pq.top().first);
            deleted[i-k+1] = 1;
        }
        return res;
    }
};

int main(){
    vector<int> nums; int k;
    Solution s;

    nums = {1,3,-1,-3,5,3,6,7}; k = 3;
    vector<int> ans = s.maxSlidingWindow(nums, k);
    printVector(ans); // Expected output: [3,3,5,5,6,7]

    nums = {1}; k = 1;
    ans = s.maxSlidingWindow(nums, k);
    printVector(ans); // Expected output: [1]

    return 0;
}
