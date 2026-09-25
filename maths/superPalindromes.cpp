/*
Leetcode Hard 906. Super Palindromes

Let's say a positive integer is a super-palindrome if it is a palindrome, and it is also the square of a palindrome.

Given two positive integers left and right represented as strings, 
    return the number of super-palindromes integers in the inclusive range [left, right].

Constraints:
1 <= left.length, right.length <= 18
left and right consist of only digits.
left and right cannot have leading zeros.
left and right represent integers in the range [1, 10^18 - 1].
left is less than or equal to right.
*/
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
    bool isPalindrome(string s){
        int i = 0, j = s.size() - 1;
        while(i < j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
public:
    int bruteforce(string left, string right) {
        long long l = stoll(left), r = stoll(right);
        int res = 0;
        for (long long i = l; i <= r; i++) {
            if (isPalindrome(to_string(i))) {
                long long sq = (long long)sqrt((long double)i);
                while (sq * sq > i) sq--;
                while ((sq + 1) * (sq + 1) <= i) sq++;
                if (sq * sq == i && isPalindrome(to_string(sq))) {
                    res++;
                }
            }
        }
        return res;
    }

    int superpalindromesInRange(string left, string right) {
        long long l = stoll(left), r = stoll(right);

        long long sq = (long long)sqrt((long double)l);
        while (sq * sq > l) sq--;
        while ((sq + 1) * (sq + 1) <= l) sq++;
        l = sq; 
        long long pref = sq, preftemp = sq;

        sq = (long long)sqrt((long double)r);
        while (sq * sq > r) sq--;
        while ((sq + 1) * (sq + 1) <= r) sq++;
        r = sq;

        int res = 0;
        int mid = 0;
        bool isOdd = false;

        string prefix = to_string(pref);
        if (prefix.size() % 2 == 1) {
            isOdd = true;
            mid = prefix[prefix.size() / 2] - '0';
        }
        prefix = prefix.substr(0, (prefix.size()) / 2);
        if (prefix.size() > 0) preftemp = stoll(prefix);
        else preftemp = 0;
        string temp = "0", sqtemp = "0";
        string oldprefix = prefix;
        
        while (stoll(temp) <= r) {
            if (mid == 10){
                preftemp++;
                prefix = to_string(preftemp);
                if (prefix.size() > oldprefix.size()) {
                    isOdd = false;
                    oldprefix = prefix;
                }
                mid = 0;
            }
            string reverse = prefix;
            reverse = string(reverse.rbegin(), reverse.rend());
            if (isOdd) temp = prefix + to_string(mid) + reverse;
            else temp = prefix + reverse;
            long long num = stoll(temp);
            num *= num;
            if (num >= stoll(left) && num <= stoll(right)) {
                sqtemp = to_string(num);
                if (isPalindrome(sqtemp)) res++;
            }      

            if (isOdd) mid++;
            else {
                preftemp++;
                prefix = to_string(preftemp);
                if (prefix.size() > oldprefix.size()) {
                    isOdd = true;
                    mid = 0;
                    prefix = "1";
                    for (int i = 1; i < oldprefix.size(); i++) prefix += "0";
                    preftemp = stoll(prefix);
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    string left = "", right = "";

    left = "2"; right = "1000";
    cout << sol.superpalindromesInRange(left, right) << endl; // Output: 4
    return 0;
}


