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
#include <climits>
using namespace std;

class Solution {
    vector<vector<int>> dp;
    vector<int> dps;
    bool backtrack(string& s, unordered_set<string>& dict, int index = 0, string curr=""){
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
    bool standardBacktrack(string& s, unordered_set<string>& dict, int index = 0){
        if (index == s.size()) return true;
        if (dps[index] != -1) return dps[index];

        for (const string& word: dict){
            int len = word.size();
            if (index + len <= s.size() &&  !s.compare(index, len, word)) {
                if (standardBacktrack(s, dict, index+len)) return dps[index] = 1;
            }
        }        
        return false;
    }
    bool convertToDP(string& s, unordered_set<string>& dict){
        int size = s.size();
        vector<char>dpd(size+1, 0);
        dpd[0] = 1;

        for (int i=0;i<size;i++) {
            if (!dpd[i]) continue;
            
            for (const string& word: dict){
                int len = word.size();
                if (i + len <= size && !s.compare(i, len, word)){
                    dpd[i+len] = 1;
                    if ( (i + len) == size ) return true;
                }
            }
        }
        return dpd[size];
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        // dp.assign(s.size(), vector<int>(s.size(), -1));
        // dps.assign(s.size(), -1);
        // for (int i=0;i<wordDict.size();i++) dict.insert(wordDict[i]);
        // return backtrack(s, dict);
        // return standardBacktrack(s, dict);
        return convertToDP(s, dict);
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


