// Leetcode Medium 1371. Find the Longest Substring Containing Vowels in Even Counts
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<char, int> vowels = {{'a', 0}, {'e', 1}, {'i', 2}, {'o', 3}, {'u', 4}};

    int findTheLongestSubstring(string s) {
        if (s.size() == 1) return !vowels.count(s[0]);
        int ans = 0, mask = 0;
        vector<int> map(32, -2);
        map[0] = -1;

        for (int i = 0;i<s.size();i++){
            if (vowels.count(s[i])){
                mask ^= (1 << vowels[s[i]]);
            }
            if (map[mask] != -2){
                ans = max(ans, i - map[mask]);
            } else {
                map[mask] = i;
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;
    string s = "eleetminicoworoep";
    cout<<sol.findTheLongestSubstring(s)<<endl;

    s = "leetcodeisgreat";
    cout<<sol.findTheLongestSubstring(s)<<endl;

    s = "bcbcbc";
    cout<<sol.findTheLongestSubstring(s)<<endl;

    return 0;
}
