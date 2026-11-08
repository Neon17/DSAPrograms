/*
    Link: https://www.geeksforgeeks.org/problems/alien-dictionary/1
    Practicing from geeksforgeeks.com

    An alien language uses the lowercase English alphabet, 
        but the order of its letters is unknown. 
    You are given an array of strings words[] that is claimed to be sorted lexicographically according to the rules of the alien language.

    Determine the order of the letters in the alien alphabet.

    If a valid ordering exists, return a string containing all unique letters in lexicographical order according to the alien language.
    Otherwise, return an empty string.
    If a string s1 is lexicographically smaller than a string s2, 
        and the first position at which they differ contains letter a in s1 and letter b in s2, 
            then a must appear before b in the alien alphabet.

    If one word is a prefix of the other, the shorter word must appear before the longer word.
    Note: The driver code prints true if the returned order is valid; otherwise, it prints false.

    Constraints:
        1 ≤ words.size() * words[i].size()  ≤ 10^6
        words[i] consists only of lowercase English letters.
*/
#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
#include<queue>
using namespace std;

class Solution {
  public:
    string findOrder(vector<string> &words) {
        // code here
        vector<unordered_set<char>> graph(26);
        vector<unordered_set<char>> reverse_graph(26);
        string ans = "";
        vector<bool> present(26, false);

        for (auto &w : words)
            for (char c : w)
                present[c - 'a'] = true;

        for (int i=1;i<words.size();i++){

            if (words[i-1].size() > words[i].size() &&
                words[i-1].compare(0, words[i].size(), words[i]) == 0) return "";

            for (int j=0;j<words[i].size();j++){
                if ( j >= words[i-1].size() ) break;

                if ( words[i][j] != words[i-1][j]){
                    graph[words[i-1][j]-'a'].insert(words[i][j]-'a');
                    reverse_graph[words[i][j]-'a'].insert(words[i-1][j]-'a');
                    break;
                }
            }
        }

        vector<char> visited;
        queue<char> que;
        vector<int> indegree(26);
        
        for (int i=0;i<26;i++){
            indegree[i] = reverse_graph[i].size();
            if (indegree[i] == 0) que.push(i);
        }

        while (!que.empty()){
            auto index = que.front();
            que.pop();
            visited.push_back(index);

            for (auto& neighbor: graph[index]){
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) que.push(neighbor);
            }
        }      
        if (visited.size() != 26) return "";

        for (auto& index: visited){
            if (present[index]) {
                ans += (char)(index+'a');
            }
        }
        return ans;
    }
};

int main() {
    vector<string> words;
    string ans;
    Solution obj;

    words = {"baa", "abcd", "abca", "cab", "cad"};
    ans = obj.findOrder(words);
    cout<< "Order of characters in the alien language: " << ans << endl; // Expected output: "bdac"

    words = {"caa", "aaa", "aab"};
    ans = obj.findOrder(words);
    cout<< "Order of characters in the alien language: " << ans << endl; // Expected output: "cab"

    words = {"caa", "aaa", "aab", "a"};
    ans = obj.findOrder(words);
    cout<< "Order of characters in the alien language: " << ans << endl; // Expected output: "" (empty string, as the order is invalid due to prefix issue)
    return 0;
}


