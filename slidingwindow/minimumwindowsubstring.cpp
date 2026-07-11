#include<iostream>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int need[128] = {0};
        for (char c : t) need[c]++;
        int required = t.size();
        int have = 0;
        int left = 0, right = 0;
        int minLen = __INT32_MAX__, start = 0;

        while (right < s.size()) {
            char c = s[right++];
            if (--need[c] >= 0) have++;

            while (have == required) {
                if (right - left < minLen) {
                    minLen = right - left;
                    start = left;
                }
                char d = s[left++];
                if (++need[d] > 0) have--;
            }
        }
        return minLen == __INT32_MAX__ ? "" : s.substr(start, minLen);
    }
};

int main(){
    string s = "ADOBECODEBANC";
    string t = "ABC";

    Solution sol;
    cout << sol.minWindow(s,t)<<endl;

    s = "a";
    t = "a";
    cout << sol.minWindow(s,t)<<endl;

    s = "a";
    t = "aa";
    cout << sol.minWindow(s,t)<<endl;

    return 0;
}