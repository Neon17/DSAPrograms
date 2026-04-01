/**
    630. Course Schedule III
    You are given an array courses where courses[i] = [durationi, lastDayi] indicate that 
    The ith course should be taken continuously for durationi days and must be finished before or on lastDayi.
    You will start on the 1st day and you cannot take two or more courses simultaneously. 

    Return the maximum number of courses that you can take.

    Topics: Principal, Array, Greedy, Sorting, Heap (Priority Queue)
    Accepted 139,384/335.7K, Acceptance Rate 41.5%
    Difficulty: Hard
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/**
 * I tried to sort by ascending order of last day and then durations
 * I simply incremented count if time is less than or equal to lastDay of next task
 * Then continuously popped until empty
 * 
 * But this approach is a little faulty, it can ignore the case where sometimes 
 * It would be better to replace a previously chosen course (with a longer duration) with this new course (which may have a shorter duration), 
 * so that the total time decreases while keeping the same number of courses.
 */

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(),
            [](const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; });
        priority_queue<int> maxHeap;
        int time = 0;
        for (auto& c : courses) {
            time += c[0];
            maxHeap.push(c[0]);
            if (time > c[1]) {
                time -= maxHeap.top();
                maxHeap.pop();
            }
        }
        return maxHeap.size();
    }
};

int main() {
    Solution s;
    vector<vector<int>> courses;

    courses = {{100, 200}, {200, 1300}, {1000, 1250}, {2000, 3200}};
    cout<<s.scheduleCourse(courses)<<endl; // expected 3

    courses = {{7,16},{2,3},{3,12},{3,14},{10,19},{10,16},{6,8},{6,11},{3,13},{6,16}};
    cout<<s.scheduleCourse(courses)<<endl; // expected 4

    return 0;
}
