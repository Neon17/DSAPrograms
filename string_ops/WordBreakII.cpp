// Leetcode Hard 140. Word Break II
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    unordered_set<string> dict;
    vector<vector<string>> memo;

    vector<string> backtrack(string& s, int end, string path = ""){
        vector<string> temp1, temp2, combine;
        path = s[end] + path;
        if (end == 0){
            temp1.push_back(path);
            if (dict.count(path)) return temp1;
            return temp2;
        }
        if (dict.count(path)) {
            temp1 = backtrack(s, end-1, "");
            for (int i=0;i<temp1.size();i++) temp1[i] = temp1[i] + " " + path;
        }
        temp2 = backtrack(s, end-1, path);
        for (int i=0;i<temp1.size();i++) combine.push_back(temp1[i]);
        for (int j=0;j<temp2.size();j++) combine.push_back(temp2[j]);
        return combine;
    }

    void standardbacktrack(string& s, int end){
        vector<string> ans;
        string temp = "";
        if (end == 0){
            temp += s[end];
            if (dict.count(temp)) ans.push_back(temp);
            memo[end] = ans;
            return;
        }
        standardbacktrack(s, end-1);
        for (int i=0;i<end;i++){
            temp = s.substr(i+1, (end - i));
            for (int j=0;j<memo[i].size(); j++){
                if (dict.count(temp)){
                    ans.push_back(memo[i][j] + " " + temp);
                }
            }
        }
        temp = s.substr(0, end+1);
        if (dict.count(temp)){
            ans.push_back(temp);
        }
        memo[end] = ans;
        return;
    }

    vector<string> convertDP(string s, vector<string>& wordDict){
        vector<vector<string>> dp(s.size(), vector<string>(0, ""));
        vector<string> temp;
        string tempo = "";

        for (int i = 0;i<s.size();i++){
            temp.clear();
            for (int j=0;j<i;j++){
                tempo = s.substr(j+1, (i - j));
                if (dict.count(tempo)){
                    for (int k=0;k<dp[j].size();k++) temp.push_back(dp[j][k] + " " + tempo);
                }
            }
            string tem = s.substr(0, i+1);
            if (dict.count(tem)) temp.push_back(tem);
            dp[i] = temp;
        }

        return dp[s.size()-1];
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.size()-1;
        dict.clear();
        for (int i=0;i<wordDict.size();i++){
            dict.insert(wordDict[i]);
        }
        memo.clear();
        memo.resize(s.size());
        standardbacktrack(s, n);
        return memo[n];
    }
};

void printVector(const vector<string>& vec) {
    for (const auto& str : vec) {
        cout << "\"" << str << "\""<<", ";
    }
}

int main() {
    Solution sol;
    string s = "catsanddog";
    vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"};
    vector<string> result = sol.wordBreak(s, wordDict);
    printVector(result);
    cout<<endl;

    s = "pineapplepenapple";
    wordDict = {"apple", "pen", "applepen", "pine", "pineapple"};
    result = sol.wordBreak(s, wordDict);
    printVector(result);
    cout<<endl;

    return 0;
}

