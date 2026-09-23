/*
Leetcode Medium 647. Palindromic Substrings

Given a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.

Constraints:
1 <= s.length <= 1000
s consists of lowercase English letters.
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
    bool isPalindrome(const string& s, int left, int right){
        if (right < left || right >= s.size() || left < 0) return false;
        
        while (left < right){
            if (s[left] == s[right]){
                left++; right--;
            } else return false;
        }
        return true;
    }
    int bruteforce(const string& s){
        int nums = 0;

        for (int i=0;i<s.size();i++){
            for (int j = i; j<s.size();j++){

                if (i == j){
                    nums++; continue;
                }
                if (isPalindrome(s, i, j)) nums++;
            }
        }
        return nums;
    }
   
    class IntervalDP{
        vector<vector<int>> dp;

    public:
        IntervalDP(const string& s){
            int n = s.size();
            dp = vector<vector<int>>(n, vector<int>(n, -1));
            for (int i=0;i<n;i++){
                for (int j=i;j<n;j++){
                    fillDP(s, i, j);
                }
            }
        }
        void fillDP(const string& s, int left, int right){
            if (left > right) return;
            if (left == right){
                dp[left][right] = 1; return;
            }
            if (dp[left+1][right-1] == -1) fillDP(s, left+1, right-1);
            if (s[left] == s[right] && (left + 1 > right - 1 || dp[left+1][right-1] == 1)) dp[left][right] = 1;
            else dp[left][right] = 0;
        }
        int countPalindromes(){
            int n = dp.size(), count = 0;
            for (int i=0;i<n;i++){
                for (int j=i;j<n;j++){
                    if (dp[i][j]) count++;
                }
            }
            return count;
        }
    };
    int optimalSolution(const string& s){
        int res = 0, center = 0, n =s.size(), left = 0, right = 0;

        while (center < n){
            left = center; right = center;
            while (left >= 0 && right < n){
                if (s[left] == s[right]){
                    left--; right++; res++;
                } else break;
            }            
            left = center-1; right = center;
            while (left >= 0 && right < n){
                if (s[left] == s[right]){
                    left--; right++; res++;
                } else break;
            }
            center++;
        }
        return res;
    }
public:
    int countSubstrings(string s) {
        // return bruteforce(s);
        // IntervalDP idp(s);
        // return idp.countPalindromes();
        return optimalSolution(s);
    }
};

int main(){
    Solution sol;
    string s = "abc";
    cout << sol.countSubstrings(s) << endl; // Output: 3

    s = "aaa";
    cout << sol.countSubstrings(s) << endl; // Output: 6

    return 0;
}
