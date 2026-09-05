/*
    Leetcode Medium 43. Multiply Strings

    Given two non-negative integers num1 and num2 represented as strings, 
        return the product of num1 and num2, also represented as a string.
    Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.

    Constraints:
        1 <= num1.length, num2.length <= 200
        num1 and num2 consist of digits only.
        Both num1 and num2 do not contain any leading zero, except the number 0 itself.
*/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string add(string num1, string num2){
        if (num1 == "" && num2 != "") return num2;
        else if (num1 != "" && num2 == "") return num1;
        string res = "";
        int ind1 = num1.size()-1, ind2 = num2.size()-1, carryover = 0, temp = 0;

        while (ind1 >= 0 || ind2 >= 0){
            temp = carryover;
            if (ind1 >= 0) temp += (num1[ind1] - '0');
            if (ind2 >= 0) temp += (num2[ind2] - '0');
            carryover = temp/10;
            temp = temp%10;
            res = to_string(temp) + res;
            ind1--; ind2--;
        }
        if (carryover > 0) res = to_string(carryover) + res;
        return res; 
    }

    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        else if (num1 == "1" || num2 == "1") return (num1 == "1")?num2:num1;

        string res = "", zeroes = "", curr = "";
        string m1 = num1, m2 = num2;
        if (num2.size() > num1.size()) swap(m1, m2);
        int carryover = 0, tem = 0;

        for (int i=m2.size()-1;i>=0;i--){
            curr = ""; carryover = 0;

            for (int j=m1.size()-1;j>=0;j--){
                tem = (m1[j] - '0') * (m2[i] - '0') + carryover;
                carryover = tem/10;
                tem = tem%10;
                curr = to_string(tem) + curr;
            }
            if (carryover > 0) curr = to_string(carryover) + curr;
            curr += zeroes;
            res = add(res, curr);
            zeroes += "0";
        }
        return res;
    }
};

int main(){
    Solution sol;
    string num1, num2;

    num1 = "123"; num2 = "456";
    cout<<sol.multiply(num1, num2)<<endl;

    num1 = "2"; num2 = "3";
    cout<<sol.multiply(num1, num2)<<endl;
    
    return 0;
}

