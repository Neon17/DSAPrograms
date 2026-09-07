/*
    Leetcode Medium 1405. Longest Happy String

    A string s is called happy if it satisfies the following conditions:

    s only contains the letters 'a', 'b', and 'c'.
    s does not contain any of "aaa", "bbb", or "ccc" as a substring.
    s contains at most a occurrences of the letter 'a'.
    s contains at most b occurrences of the letter 'b'.
    s contains at most c occurrences of the letter 'c'.
    Given three integers a, b, and c, return the longest possible happy string. If there are multiple longest happy strings, return any of them. If there is no such string, return the empty string "".

    A substring is a contiguous sequence of characters within a string.

    Constraints:
        0 <= a, b, c <= 100
        a + b + c > 0
*/
#include <iostream>
using namespace std;

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string res = "";
        int rema = a, remb = b, remc = c;
        int timea = 0, timeb = 0, timec = 0;

        while ((rema > 0 && timea < 2) || (remb > 0 && timeb < 2) || (remc > 0 && timec < 2)){
            if (rema > remb && rema > remc){
                if (timea < 2){
                    timea++; timeb=0; timec=0;
                    rema--;
                    res += 'a';
                } else if (timeb < 2 && (timec >= 2 || remb >= remc)){
                    timeb++; timea = 0; timec = 0;
                    remb--;
                    res += 'b';
                } else {
                    timec++; timea = 0; timeb = 0;
                    remc--;
                    res += 'c';
                }
            } else if (remb > remc){
                if (timeb < 2){
                    timeb++; timea = 0; timec = 0;
                    remb--;
                    res += 'b';
                } else if (timea < 2 && (timec >= 2 || rema >= remc)){
                    timea++; timeb = 0; timec = 0;
                    rema--;
                    res += 'a';
                } else {
                    timec++; timea = 0; timeb = 0;
                    remc--;
                    res += 'c';
                }
            } else {
                if (timec < 2){
                    timec++; timea = 0; timeb = 0;
                    remc--;
                    res += 'c';
                } else if (timea < 2 && (timeb >= 2 || rema >= remb)){
                    timea++; timeb = 0; timec = 0;
                    rema--;
                    res += 'a';
                } else {
                    timeb++; timea = 0; timec = 0;
                    remb--;
                    res += 'b';
                }
            }
        }
        return res;
    }
};

int main(){
    Solution sol;
    int a, b, c;

    a = 1; b = 1; c = 7;
    cout<<sol.longestDiverseString(a,b,c)<<endl;

    a = 7; b = 1; c = 0;
    cout<<sol.longestDiverseString(a,b,c)<<endl;

    a = 2; b = 3; c = 0;
    cout<<sol.longestDiverseString(a,b,c)<<endl;

    return 0;
}
