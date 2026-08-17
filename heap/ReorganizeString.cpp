// Leetcode Medium 767. Reorganize String
/*
    Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.
    Return any possible rearrangement of s or return "" if not possible.
    Constraints:
        1 <= s.length <= 500
        s consists of lowercase English letters.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        string ans = "";
        priority_queue<pair<int, char>> pq;
        queue<pair<int, char>> que; 
        unordered_map<char, int> freq;
        for (int i=0;i<s.size();i++) freq[s[i]]++;
        for (auto& [task, occur]: freq) pq.push({occur, task});
        int time = 0;

        while (!que.empty() || !pq.empty()){
            while (!que.empty() && que.front().first <= time){
                auto it = que.front();
                que.pop();
                pq.push({freq[it.second], it.second});
            }
            if (!pq.empty()){                
                auto [occur, task] = pq.top();
                pq.pop();
                ans += task;
                freq[task]--;
                time++;
                if (freq[task] > 0) que.push({time + 1, task});
            } else break;
        }
        return ans.size() == s.size() ? ans: "";
    }
};

int main() {
    Solution sol;
    string s = "";

    s = "aab";
    cout<<sol.reorganizeString(s)<<endl;

    s = "aaab";
    cout<<sol.reorganizeString(s)<<endl;

    return 0;
}
