// Leetcode Medium 621. Task Scheduler
/*
    You are given an array of CPU tasks, each labeled with a letter from A to Z, and a number n. 
    Each CPU interval can be idle or allow the completion of one task. 
    Tasks can be completed in any order, 
    but there's a constraint: there has to be a gap of at least n intervals between two tasks with the same label.
    Return the minimum number of CPU intervals required to complete all tasks.

    Constraints:
        1 <= tasks.length <= 104
        tasks[i] is an uppercase English letter.
        0 <= n <= 100
    Topics: Principal, Hash Table, Greedy, Sorting, Heap (Priority Queue), Counting, Array
*/

#include <iostream>
#include <queue>
#include<vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<pair<int, char>> pq;
        unordered_map<char, int> freq;
        int m = tasks.size(), time = 0;

        for (char c : tasks) freq[c]++;
        for (auto &p : freq) pq.push({p.second, p.first}); 

        queue<pair<int, char>> cooldown;

        while (!pq.empty() || !cooldown.empty()) {
            while (!cooldown.empty() && cooldown.front().first <= time) {
                auto [ready, task] = cooldown.front();
                cooldown.pop();
                pq.push({freq[task], task});
            }

            if (!pq.empty()) {
                auto [cnt, task] = pq.top();
                pq.pop();
                freq[task]--;
                if (freq[task] > 0) {
                    cooldown.push({time + n + 1, task});
                }
                time++;
            } else {
                time = cooldown.front().first;
            }
        }
        return time;
    }
};

int main(){
    Solution s;
    vector<char> tasks; int n;

    tasks = {'A','A','A','B','B','B'}; n = 2;
    cout<<s.leastInterval(tasks, n)<<endl; // 8 (A->B->idle->A->B->idle->A->B)

    tasks = {'A','C','A','B','D','B'}; n = 1;
    cout<<s.leastInterval(tasks, n)<<endl; // 6

    tasks = {'A','A','A', 'B','B','B'}; n = 3;
    cout<<s.leastInterval(tasks, n)<<endl; // 10

    tasks = {'B','C','D','A','A','A','A','G'}; n = 1;
    cout<<s.leastInterval(tasks, n)<<endl; // 8

    return 0;
}
