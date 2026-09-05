/*
    Leetcode Medium 6. Zigzag Conversion

    The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
        (you may want to display this pattern in a fixed font for better legibility)

    P   A   H   N
    A P L S I I G
    Y   I   R
    And then read line by line: "PAHNAPLSIIGYIR"

    Write the code that will take a string and make this conversion given a number of rows:

    string convert(string s, int numRows);

    Constraints:
        1 <= s.length <= 1000
        s consists of English letters (lower-case and upper-case), ',' and '.'.
        1 <= numRows <= 1000
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    // string convert(string s, int numRows) {
    //     int n = s.size(), pos = 0;
    //     if (numRows == 1 || numRows >= n) return s;
    //     string res = ""; bool up = false;
    //     vector<vector<char>> matrix(numRows);

    //     for (int i=0;i<n;i++){
    //         matrix[pos].push_back(s[i]);
    //         if (!up) {
    //             pos++;
    //             if (pos == numRows){
    //                 pos -= 2; up = true;
    //             }
    //         } else {
    //             pos--;
    //             if (pos < 0){
    //                 pos += 2; up = false;
    //             }
    //         }
    //     }

    //     for (int i=0;i<numRows;i++){
    //         for (int j=0;j<matrix[i].size();j++){
    //             res += matrix[i][j];
    //         }
    //     }
    //     return res;
    // }

    string convert(string s, int numRows) {
        int n = s.size(), pos = 0;
        if (numRows == 1 || numRows >= n) return s;
        bool up = false;
        string res(n, s[0]);
        int cycle_length = 2*numRows-2;
        int cycle = 0, idx = 0, index = 0;

        for (int row = 0; row < numRows; row++){
            if (row == 0 || row == numRows - 1){
                cycle = row;
                while (cycle < n){
                    res[index++] = s[cycle]; 
                    cycle += cycle_length;
                }
            } else {
                cycle = 0; idx = 0; up = false;
                while (idx < n){
                    if (!up){
                        idx = cycle + row;
                        up = true;
                        if (idx < n) res[index++] = s[idx];
                        cycle += cycle_length;
                    } else {
                        idx = cycle - row;
                        up = false;
                        if (idx < n) res[index++] = s[idx];
                    }
                }
            }
        }  
        return res;
    }
};

int main(){
    Solution sol;
    string s; int numRows;

    s = "PAYPALISHIRING"; numRows = 3;
    cout << sol.convert(s, numRows) << endl; // Output: "PAHNAPLSIIGYIR"

    s = "PAYPALISHIRING"; numRows = 4;
    cout << sol.convert(s, numRows) << endl; // Output: "PINALSIGYAHRPI"

    return 0;
}
