#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Input should be like this
// 5 4 7
// 1 2 3 4
// 7 8 9 10
// 13 14 15 16
// 19 20 21 22
// 25 26 27 28

/*
 * Complete the 'matrixRotation' function below.
 *
 * The function accepts following parameters:
 *  1. 2D_INTEGER_ARRAY matrix
 *  2. INTEGER r
 */

void matrixRotation(vector<vector<int>> matrix, int r)
{
    int m, n;
    m = matrix.size();
    n = matrix[0].size();
    int i, j, k, l, least, temp;
    int xmax, ymax;
    least = (m < n) ? m : n;
    least = least / 2;
    for (i = 0; i < r; i++)
    {
        xmax = m;
        ymax = n;
        for (j = 1; j <= least; j++)
        {
            k = j;
            l = k;
            temp = matrix[k - 1][l - 1];
            l = l + 1;
            for (; l <= ymax; l++)
            {
                matrix[k - 1][l - 2] = matrix[k - 1][l - 1];
            }
            k = j + 1;
            l = ymax;
            for (; k <= xmax; k++)
            {
                matrix[k - 2][l - 1] = matrix[k - 1][l - 1];
            }
            l = ymax - 1;
            k = xmax;
            for (; l >= j; l--)
            {
                matrix[k - 1][l] = matrix[k - 1][l - 1];
            }
            k = xmax - 1;
            l = j;
            for (; k >= j; k--)
            {
                matrix[k][l - 1] = matrix[k - 1][l - 1];
            }
            matrix[j][j - 1] = temp;
            xmax = xmax - 1;
            ymax = ymax - 1;
        }
    }
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

int main()
{
    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int m = stoi(first_multiple_input[0]);

    int n = stoi(first_multiple_input[1]);

    int r = stoi(first_multiple_input[2]);

    vector<vector<int>> matrix(m);

    for (int i = 0; i < m; i++)
    {
        matrix[i].resize(n);

        string matrix_row_temp_temp;
        getline(cin, matrix_row_temp_temp);

        vector<string> matrix_row_temp = split(rtrim(matrix_row_temp_temp));

        for (int j = 0; j < n; j++)
        {
            int matrix_row_item = stoi(matrix_row_temp[j]);

            matrix[i][j] = matrix_row_item;
        }
    }

    matrixRotation(matrix, r);

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}

vector<string> split(const string &str)
{
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos)
    {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
