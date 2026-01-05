// I will solve this problem using backtracking
// 37. Sudoku Solver (Hard)
#include <iostream>
#include <vector>
using namespace std;

void solveSudoku(vector<vector<char>>& board, int row, int col);
bool isSafe(vector<vector<char>>& board, int row, int col);
void printBoard(const vector<vector<char>>& board);

vector<vector<char>> ans;

bool isSafe(vector<vector<char>>& board, int row, int col){
    for (int i=0;i<board.size();i++){
        if (i != row){
            if (board[row][col] == board[i][col]) return false;
        }
        if (i != col){
            if (board[row][col] == board[row][i]) return false;
        }
    }
    int startx=0, starty=0;
    if (row < 3){
        if (col < 3){
            startx = 0; starty= 0;
        } else if (col>=3 && col < 6){
            startx = 0; starty= 3;
        } else {
            startx = 0; starty= 6;
        }
    } else if (row >= 3 && row < 6){
        if (col < 3){
            startx = 3; starty= 0;
        } else if (col>=3 && col < 6){
            startx = 3; starty= 3;
        } else {
            startx = 3; starty= 6;
        }
    } else {
        if (col < 3){
            startx = 6; starty= 0;
        } else if (col>=3 && col < 6){
            startx = 6; starty= 3;
        } else {
            startx = 6; starty= 6;
        }
    }
    for (int i=startx; i<(startx+3); i++){
        for (int j=starty; j<(starty+3); j++){
            if (row == i && col == j) continue;
            if (board[i][j] == board[row][col]) return false;
        }
    }
    return true;
}

void solveSudoku(vector<vector<char>>& board, bool& solved, int row=0, int col=0){
    if (solved) return;
    if (row > board.size() || col > board.size()) return;
    if (row != board.size() && col == board.size()){
        row = row + 1; 
        col = 0;
    }
    if (row == board.size()){
        solved = true;
        ans = board;
        return;
    }

    if (board[row][col] != '.'){
        solveSudoku(board, solved, row, col+1);
        return;
    }
    for (int i=1;i<=9;i++){
        board[row][col] = '0' + i;
        if (isSafe(board, row, col)){
            solveSudoku(board, solved, row, col+1);
        }
        board[row][col] = '.';
    }
}

void printBoard(const vector<vector<char>>& board){
    for (int i=0;i<board.size();i++){
        for (int j=0;j<board.size();j++){
            cout<<board[i][j]<<", ";
        }
        cout<<endl;
    }
}

int main() {
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };


    // lets check this: [[".",".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".",".","6"],[".",".",".",".",".","1",".","9","."],[".",".",".",".","7",".","1",".","2"],[".",".","5",".",".","3",".",".","."],[".",".","8",".","4",".",".",".","7"],[".",".",".","8",".","9",".","5","."],[".","7",".",".",".",".",".","4","."],[".","2",".",".",".",".",".",".","."]]
    // vector<vector<char>> board = {
    //     {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
    //     {'.', '.', '.', '.', '.', '.', '.', '.', '6'},
    //     {'.', '.', '.', '.', '.', '1', '.', '9', '.'},
    //     {'.', '.', '.', '.', '7', '.', '1', '.', '2'},
    //     {'.', '.', '5', '.', '.', '3', '.', '.', '.'},
    //     {'.', '.', '8', '.', '4', '.', '.', '.', '7'},
    //     {'.', '.', '.', '8', '.', '9', '.', '5', '.'},
    //     {'.', '7', '.', '.', '.', '.', '.', '4', '.'},
    //     {'.', '2', '.', '.', '.', '.', '.', '.', '.'}
    // }; fails on this

    bool solved = false;
    solveSudoku(board, solved);
    printBoard(ans);

    return 0;
}

