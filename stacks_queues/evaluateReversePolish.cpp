/**
150. Evaluate Reverse Polish Notation (Medium)
Companies: Citadel, LinkedIn, Yandex, Grammarly

You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.
Evaluate the expression. Return an integer that represents the value of the expression.

Note that:

The valid operators are '+', '-', '*', and '/'.
Each operand may be an integer or another expression.
The division between two integers always truncates toward zero.
There will not be any division by zero.
The input represents a valid arithmetic expression in a reverse polish notation.
The answer and all the intermediate calculations can be represented in a 32-bit integer.
 
Example 1:

Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
Output: 22
Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
 
Constraints:

1 <= tokens.length <= 104
tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the range [-200, 200].

Accepted 1,763,292/3.1M Acceptance Rate 57.7%
 */


#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int calculate(int a, int b, string op) {
        if (op == "+")
            return a + b;
        else if (op == "-")
            return a - b;
        else if (op == "*")
            return a * b;
        else if (op == "/")
            return a / b;
        else
            return 0;
    }

    int evalRPN(vector<string>& tokens) {
        int a=0, b=0, ans=0;
        stack<string> st;

        for (const auto& token: tokens){
            string op = token;
            if ((op == "+") || (op == "-") || (op == "*") || (op == "/")) {
                b = atoi(st.top().data());
                st.pop();
                a = atoi(st.top().data());
                st.pop();
                ans = calculate(a, b, op);
                st.push(to_string(ans));
            } else {
                st.push(token);
            }               
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<string> tokens;

    tokens = {"2","1","+","3","*"};
    cout << sol.evalRPN(tokens) << endl; // 9

    tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    cout << sol.evalRPN(tokens) << endl; // 22

    return 0;
}
