/*
Leetcode Problem 480: Sliding Window Median

The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. 
So the median is the mean of the two middle values.

For examples, if arr = [2,3,4], the median is 3.
For examples, if arr = [1,2,3,4], the median is (2 + 3) / 2 = 2.5.
You are given an integer array nums and an integer k. There is a sliding window of size k which is moving from the very left of the array to the very right. 
You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the median array for each window in the original array. Answers within 10-5 of the actual value will be accepted.

Example 1:
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [1.00000,-1.00000,-1.00000,3.00000,5.00000,6.00000]
Explanation: 
Window position                Median
---------------                -----
[1  3  -1] -3  5  3  6  7        1
 1 [3  -1  -3] 5  3  6  7       -1
 1  3 [-1  -3  5] 3  6  7       -1
 1  3  -1 [-3  5  3] 6  7        3
 1  3  -1  -3 [5  3  6] 7        5
 1  3  -1  -3  5 [3  6  7]       6

Example 2:
Input: nums = [1,2,3,4,2,3,1,4,2], k = 3
Output: [2.00000,3.00000,3.00000,3.00000,2.00000,3.00000,2.00000]
 
Constraints:
1 <= k <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
*/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
    class MedianFinder {
        int index = -1, window = 0, validMaxSize = 0, validMinSize = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minheap;
        priority_queue<pair<int, int>, vector<pair<int, int>>> maxheap;
        unordered_map<int, int> pending; // to keep track of to be deleted elements
        vector<int> vals;

        void cleanMax(){
            while (!maxheap.empty() && pending[maxheap.top().second] > 0){
                pending[maxheap.top().second]--;
                maxheap.pop();
            }
        }

        void cleanMin(){
            while (!minheap.empty() && pending[minheap.top().second] > 0){
                pending[minheap.top().second]--;
                minheap.pop();
            }
        }

        void rebalance(){
            cleanMax();
            cleanMin();

            while (validMaxSize > validMinSize + 1){
                minheap.push(maxheap.top());
                maxheap.pop();
                validMaxSize--;
                validMinSize++;
                cleanMax();
            }
            while (validMinSize > validMaxSize){
                maxheap.push(minheap.top());
                minheap.pop();
                validMaxSize++;
                validMinSize--;
                cleanMin();
            }
        }
    public:
        MedianFinder(int k){
            window = k;
        }

        void addNum(int num, int index){
            this->index = index;
            vals.push_back(num);
            maxheap.push({num, index});
            minheap.push(maxheap.top());
            maxheap.pop();
            validMinSize++;

            if (validMinSize > validMaxSize){
                maxheap.push(minheap.top());
                minheap.pop();

                validMaxSize++;
                validMinSize--;
            }
            cleanMax();
            cleanMin();
            rebalance();
        }
        double findMedian(){
            if (this->index < this->window - 1) return 0.0;
            double ans = 0.0;
            cleanMax();
            cleanMin();
            if (this->window % 2 != 0) ans = maxheap.top().first;
            else ans = (double)maxheap.top().first / 2.0 + (double)minheap.top().first / 2.0;
            int removeindex = this->index - this->window + 1;
            int removeval = vals[removeindex];
            
            if (removeval <= maxheap.top().first) validMaxSize--;
            else validMinSize--;
            pending[removeindex]++;
            return ans;
        }
    };

public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> result;
        MedianFinder md(k);
        for (int i=0;i<nums.size();i++){
            md.addNum(nums[i], i);
            if (i >= k - 1) result.push_back(md.findMedian());
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> nums; int k;

    nums = {1,3,-1,-3,5,3,6,7};
    k = 3;
    vector<double> result = solution.medianSlidingWindow(nums, k);
    
    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << (i == result.size() - 1 ? "" : ", ");
    }
    cout << "]" << endl;

    return 0;
}

