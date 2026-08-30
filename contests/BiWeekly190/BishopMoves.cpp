#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
    vector<vector<int>> directions = {
        {1, -1},
        {1, 1},
        {-1, -1},
        {-1, 1}
    };

    bool isBlack(vector<int>& move){
        return ((move[0] + move[1])%2 != 0);
    }
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        if (isBlack(source) != isBlack(target)) return -1;

        int x = source[0], y = source[1];

        while (x <= 8 && y >= 1){
            x = x + directions[0][0];
            y = y + directions[0][1];
            if (x == target[0] && y == target[1]) return 1;
        } x = source[0]; y = source[1];

        while (x <= 8 && y <= 8){
            x = x + directions[1][0];
            y = y + directions[1][1];
            if (x == target[0] && y == target[1]) return 1;
        }  x = source[0]; y = source[1];

        while (x >= 1 && y >= 1){
            x = x + directions[2][0];
            y = y + directions[2][1];
            if (x == target[0] && y == target[1]) return 1;
        }  x = source[0]; y = source[1];

        while (x >= 1 && y <= 8){
            x = x + directions[3][0];
            y = y + directions[3][1];
            if (x == target[0] && y == target[1]) return 1;
        }  x = source[0]; y = source[1];

        return 2;
    }
};

int main(){
    Solution s;
    vector<int> source, target;

    source = {8, 1}; target = {1, 8};
    cout << s.minBishopMoves(source, target) << endl; // 1

    source = {4, 2}; target = {1, 3};
    cout << s.minBishopMoves(source, target) << endl; // 2
    return 0;
}
