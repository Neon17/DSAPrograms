// Leetcode Hard 295. Find Median from Data Stream
/*
    The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.
    For example, for arr = [2,3,4], the median is 3.
    For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
    Implement the MedianFinder class:

    MedianFinder() initializes the MedianFinder object.
    void addNum(int num) adds the integer num from the data stream to the data structure.
    double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.

    Constraints:
    -10^5 <= num <= 10^5
    There will be at least one element in the data structure before calling findMedian.
    At most 5 * 10^4 calls will be made to addNum and findMedian.
    
    Follow up:
    If all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?
    If 99% of all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class MedianFinder {
private:
    int size = 0;
    priority_queue<int, vector<int>, greater<int>> minheap; 
    priority_queue<int> maxheap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        size++;
        maxheap.push(num);
        minheap.push(maxheap.top());
        maxheap.pop();
        if (minheap.size() > maxheap.size()) {
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }
    
    double findMedian() {
        if (size % 2 != 0) return maxheap.top();
        return (double) ( minheap.top() + maxheap.top() )/2.0;
    }
};

int main() {
    MedianFinder mf;
    mf.addNum(1);
    mf.addNum(2);
    cout << "Median: " << mf.findMedian() << endl; // Output: 1.5
    mf.addNum(3);
    cout << "Median: " << mf.findMedian() << endl; // Output: 2.0
    return 0;
}

