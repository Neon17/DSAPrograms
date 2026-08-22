/**
Leetcode Medium 402. Remove K Digits

Given string num representing a non-negative integer num, and an integer k, 
return the smallest possible integer after removing k digits from num.

Example 1:
Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.

Example 2:
Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.

Example 3:
Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
 
Constraints:
1 <= k <= num.length <= 105
num consists of only digits.
num does not have any leading zeros except for the zero itself.
 */

#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        string result = "";
        for (char c: num){
            while (k > 0 && !result.empty() && result.back() > c){
                result.pop_back();
                k--;
            }
            result.push_back(c);
        }
        while (k > 0){
            result.pop_back();
            k--;
        }
        size_t pos = result.find_first_not_of('0');
        return (pos == string::npos)?"0":result.substr(pos);
    }
};

int main(){
    Solution solution;
    string num; int k;

    num = "1432219"; k = 3;
    cout << solution.removeKdigits(num, k) << endl;

    num = "10200"; k = 1;
    cout << solution.removeKdigits(num, k) << endl;

    num = "10"; k = 2;
    cout << solution.removeKdigits(num, k) << endl;

    return 0;
}

