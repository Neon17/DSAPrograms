/*
316. Remove Duplicate Letters
Medium - 1585
Topics
premium lock icon
Companies
Hint
ByteDance
BNY Mellon
Expedia
Goldman Sachs
Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

 

Example 1:

Input: s = "bcabc"
Output: "abc"
Example 2:

Input: s = "cbacdcbc"
Output: "acdb"
 

Constraints:

1 <= s.length <= 104
s consists of lowercase English letters.
*/

#include <iostream>
#include <string>
#include <stack>
#include <unordered_set>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> st;
        unordered_set<char> set;
        string temp = "";
        
        for (int i=0;i<s.size();i++){
            if (set.count(s[i]) && st.top() > s[i]) continue;
            st.push(s[i]);
            for (char c: temp) st.push(c);
            set.insert(s[i]);
        }
        temp = ""; unordered_set<char> newset;
        while (!st.empty()){
            if (!newset.count(st.top())) temp = st.top() + temp;
            newset.insert(st.top());
            st.pop();
        }
        return temp;
    }
};

int main(){
    Solution solution;
    string s;

    s = "bcabc";
    cout << solution.removeDuplicateLetters(s) << endl;

    s = "cbacdcbc";
    cout << solution.removeDuplicateLetters(s) << endl;

    return 0;
}
