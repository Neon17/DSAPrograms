/*
    Leetcode Medium 4021. Minimum Operations to Make a Rotated Palindrome I

    You are given a string s consisting of lowercase English letters.

    You can perform the following operations any number of times (including zero) and in any order:

    Increment: Choose any index i and replace s[i] with the next lowercase English letter. The letter after 'z' is 'a'.
    Left rotate: Move the first character of the string to the end.
    Return the minimum number of operations required to make s a palindrome.

    Constraints:
        2 <= s.length <= 2000
        s consists only of lowercase English letters.
*/
#include <iostream>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int res = INT_MAX, temp = 0, left = 0, right = 0;
        int size = s.size(), nl = 0, nr = 0;
        int local = 0;

        for (int i=0;i<size;i++){
            left = 0; right = size-1; temp = i;

            while (left < right){
                nl = (left + i) % size;
                nr = (right + i) % size;
                if (s[nl] != s[nr]) {
                    if (s[nl] > s[nr]) local = 'z' - s[nl] + 1 + s[nr] - 'a';
                    else local = 'z' - s[nr] + 1 + s[nl] - 'a'; 
                    local = min(local, abs(s[nr] - s[nl]));
                    temp += local;
                }
                left++;
                right--;
            }
            res = min(res, temp);
        }
        return res;
    }
};

int main(){
    Solution sol;
    string s;

    s = "abc";
    cout<<sol.minOperations(s)<<endl;

    s = "yb";
    cout<<sol.minOperations(s)<<endl;

    return 0;
}

