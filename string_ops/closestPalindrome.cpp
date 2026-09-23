/*
Leetcode Hard 564. Find the Closest Palindrome

Given a string n representing an integer, return the closest integer (not including itself), 
    which is a palindrome. If there is a tie, return the smaller one.

The closest is defined as the absolute difference minimized between two integers.

Constraints:
1 <= n.length <= 18
n consists of only digits.
n does not have leading zeros.
n is representing an integer in the range [1, 10^18 - 1].
*/
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

class Solution {
public:
    string nearestPalindromic(string n) {
        if (n.size() == 1 || (n.size() == 2 && n == "10")) return to_string(stoi(n) - 1);
        if (n.size() == 2 && n == "11") return "9";

        string res = "", prefix = "";
        int size = n.size(), left = 0, right = 0, half = 0;

        if (size % 2 == 0) half = size/2;
        else half = size/2 + 1;
        prefix = n.substr(0, half);

        long long int second = stoi(prefix);
        long long int first = second - 1;
        long long int third = second + 1;

        string a = to_string(first);
        string b = to_string(second);
        string c = to_string(third);
        string candidate1 = "", candidate2 = "", candidate3 = "";

        left = 0; right = size-1;
        while (left < right){
            if (left < a.size()) candidate1 = a[left] + candidate1;
            left++; right--;
        } 
        if (a.size() < (size - half)) candidate1 = '9' + candidate1;
        
        left = 0; right = size-1;
        while (left < right){
            candidate2 = b[left] + candidate2;
            left++; right--;
        } 
        
        left = 0; right = size-1;
        while (left < right){
            candidate3 = c[left] + candidate3;
            left++; right--;
        }  

        a += candidate1; b += candidate2; c += candidate3;
        first = stoll(a);
        second = stoll(b);
        third = stoll(c);
        long long int original = stoll(n);     

        long long int diff1 = 0, diff2 = 0, diff3 = 0;
        diff1 = abs(original - first);
        diff2 = abs(original - second);
        diff3 = abs(original - third);
        if (diff2 == 0) diff2 = LLONG_MAX/2;

        if (diff1 <= diff2 && diff1 <= diff3) return to_string(first);
        else if (diff2 <= diff3) return to_string(second);
        return to_string(third);
    }
};

int main(){
    Solution s;
    cout << s.nearestPalindromic("1000") << endl;
    // cout << s.nearestPalindromic("1") << endl;
    // cout << s.nearestPalindromic("10") << endl;
    // cout << s.nearestPalindromic("11") << endl;
    // cout << s.nearestPalindromic("100") << endl;
    // cout << s.nearestPalindromic("99") << endl;
    return 0;
}
