/*
Leetcode Medium 1208. Get Equal Substrings Within Budget

You are given two strings s and t of the same length and an integer maxCost.
You want to change s to t. Changing the ith character of s to ith character of t costs |s[i] - t[i]| 
(i.e., the absolute difference between the ASCII values of the characters).

Return the maximum length of a substring of s that can be changed to be the same as the corresponding substring of t with a cost less than or equal to maxCost. 
If there is no substring from s that can be changed to its corresponding substring from t, return 0.

Constraints:
1 <= s.length <= 105
t.length == s.length
0 <= maxCost <= 106
s and t consist of only lowercase English letters.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int maxval = 0, left = 0, right = 0, cost = 0;

        for (right; right < s.size(); right++){
            cost += abs(s[right] - t[right]);
            while (cost > maxCost){
                cost -= abs(s[left] - t[left]);
                left++;
            }
            maxval = max(maxval, right - left + 1);
        }

        return maxval;   
    }
};

int main(){
    Solution solution;
    string s, t; int maxCost;

    s = "abcd"; t = "bcdf"; maxCost = 3;
    cout << solution.equalSubstring(s, t, maxCost) << endl;

    s = "abcd"; t = "cdef"; maxCost = 3;
    cout << solution.equalSubstring(s, t, maxCost) << endl;

    s = "abcd"; t = "acde"; maxCost = 0;
    cout << solution.equalSubstring(s, t, maxCost) << endl;

    return 0;
}


