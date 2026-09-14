/*
Leetcode Medium 139. Word Break

Given a string s and a dictionary of strings wordDict, 
    return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

Constraints:
    1 <= s.length <= 300
    1 <= wordDict.length <= 1000
    1 <= wordDict[i].length <= 20
    s and wordDict[i] consist of only lowercase English letters.
    All the strings of wordDict are unique.
*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
    vector<vector<int>> dp;
    bool backtrack(string s, unordered_set<string>& dict, int index = 0, string curr=""){
        if (index == s.size()) return dict.count(curr);
        curr += s[index];
        int start = index - curr.size() + 1;
        if (!curr.size()) start = index;
        if (dp[start][index] != -1) return dp[start][index];

        bool a = false, b = false;
        if (dict.count(curr)) a = backtrack(s, dict, index+1);
        if (curr.size() <= 20) b = backtrack(s, dict, index+1, curr);
        return dp[start][index] = a||b;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        dp.assign(s.size(), vector<int>(s.size(), -1));
        for (int i=0;i<wordDict.size();i++) dict.insert(wordDict[i]);
        return backtrack(s, dict);
    }
};

int main(){
    Solution sol;
    string s; vector<string> wordDict;

    s = "leetcode"; wordDict = {"leet", "code"};
    cout << sol.wordBreak(s, wordDict) << endl; // Output: true

    s = "applepenapple"; wordDict = {"apple", "pen"};
    cout << sol.wordBreak(s, wordDict) << endl; // Output: true

    s = "catsandog"; wordDict = {"cats", "dog", "sand", "and", "cat"};
    cout << sol.wordBreak(s, wordDict) << endl; // Output: false

    return 0;
}


