// Here, I will solve NQueens problem using backtracking

#include <iostream>
#include <vector>
using namespace std;

// pos is the position in each row for the current one
bool isValid(vector<int> &pos, int row)
{
    if (row <= 1) return true;
    int up = row-2;
    int dpx1 = row-2, dpy1 = pos[row-1]-1;
    int dsx2 = row-2, dsy2 = pos[row-1]+1;

    while (true)
    {
        if (up >= 0){
            if (pos[up] == pos[row-1])
                return false;
            up--;
        }
        if (dpx1 >= 0 && dpy1 >= 0){
            if (pos[dpx1] == dpy1)
                return false;
            dpx1--;
            dpy1--;
        }
        if (dsx2 >= 0 && dsy2 < pos.size()){
            if (pos[dsx2] == dsy2)
                return false;
            dsx2--;
            dsy2++;
        }
        if (up < 0 && (dpx1 < 0 || dpy1 < 0) && (dsx2 < 0 || dsy2 >= pos.size())) break;
    }
    return true;
}

void fill(vector<vector<string>> &queens, vector<int> &pos)
{
    vector<string> qu;
    string temp = ".";
    for (int i = 0; i < pos.size(); i++)
    {
        temp = "";
        for (int j = 0; j < pos.size(); j++)
        {
            if (pos[i] == j)
            {
                temp += "Q";
            }
            else
            {
                temp += ".";
            }
        }
        qu.push_back(temp);
    }
    queens.push_back(qu);
}

void backtrack(vector<vector<string>> &queens, vector<int> &pos, int row = 0)
{
    if (row < 0)
        return;
    if (!isValid(pos, row))
    {
        return;
    }
    if (row >= pos.size())
    {
        fill(queens, pos);
        return;
    }
    for (int i = 0; i < pos.size(); i++)
    {
        pos[row] = i;
        backtrack(queens, pos, row + 1);
        pos[row] = -1;
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<int> pos(n, -1);
    vector<vector<string>> queens;
    backtrack(queens, pos);
    return queens;
}

int main()
{
    int n = 1;
    vector<vector<string>> ans = solveNQueens(n);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < n; j++)
        {
            cout << "\"" << ans[i][j] << "\"";
            if (j < n - 1)
            {
                cout << ", ";
            }
        }
        cout << "]," << endl;
    }
    if (ans.size() == 0){
        cout << "No solution found" << endl;
    }
}
