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
#include <vector>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> st;
        string temp = "";
        vector<int> count(26, 0);
        vector<bool> visited(26, false);
        
        for (int i=0;i<s.size();i++)count[s[i]-'a']++;

        for (int i=0;i<s.size();i++){
            count[s[i] - 'a']--;
            if (visited[s[i] - 'a']) continue;
            while (!st.empty() && st.top() >= s[i] && count[st.top()-'a'] > 0){
                visited[st.top() - 'a'] = false;
                count[st.top()-'a']--;
                st.pop();
            }
            st.push(s[i]);
            visited[s[i] - 'a'] = true;
        }
        while (!st.empty()){
            temp = st.top() + temp;
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
