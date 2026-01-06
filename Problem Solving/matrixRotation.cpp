#include <bits/stdc++.h>
//hacker rank matrix rotation problem I solved
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

void matrixRotation(vector<vector<int>> matrix, int r) {
    int m,n;
    m = matrix.size();
    n = matrix[0].size();
    int i,j,k,l,least,temp,status=0;
    int xmin,xmax,ymin,ymax;
    least = (m<n)?m:n;
    least = least/2;
    // cout<<least<<endl;
    int stopStatus = 0;
    for (i=0;i<r;i++){
        xmin = 1; xmax = m; ymin = 1; ymax = n;
        // cout<<"Rotation Layer = "<<(i+1)<<endl;
        for (j=1;j<=least;j++){
            // cout<<"Rim Rotation"<<endl;
            // cout<<"xmin = "<<xmin<<"\tymin = "<<ymin<<endl;
            // cout<<"xmax = "<<xmax<<"\tymax = "<<ymax<<endl;
            k=j;l=k;temp = matrix[k-1][l-1];status = 0;stopStatus = 0;
            do {
                if (status == 0){
                    l = l+1;
                    // cout<<"l = "<<l<<endl;
                    if (l>=ymax) status = 1;
                    if (l<=ymax) 
                        matrix[k-1][l-2] = matrix[k-1][l-1];
                    else l=ymax;
                }
                else if (status == 1){
                    k = k+1;
                    // cout<<"k = "<<k<<endl;
                    if (k>=xmax) status = 2;
                    if (k<=xmax)
                        matrix[k-2][l-1] = matrix[k-1][l-1];
                    else k = xmax;
                }
                else if (status == 2){
                    l = l-1;
                    // cout<<"l = "<<l<<endl;
                    if (l<=ymin) status = 3;
                    if (l>=ymin)
                        matrix[k-1][l] = matrix[k-1][l-1];
                    else l = ymin;
                }
                else if (status == 3){
                    k = k-1;
                    // cout<<"k = "<<k<<endl;
                    if (k<=xmin) status = 4;
                    if (k>=xmin)
                        matrix[k][l-1] = matrix[k-1][l-1];
                    else k = xmin;
                }
                if ((k==j)&&(l==j)){
                    stopStatus = 1;
                }
                // cout<<"status = "<<status<<endl;
            } while (stopStatus == 0);
            matrix[xmin][ymin-1] = temp;
            xmin = xmin+1; ymin = ymin+1;
            xmax = xmax-1; ymax = ymax-1;
        }
    }
    for (i=0;i<m;i++){
        for (j=0;j<n;j++){
            cout<<matrix[i][j]<<"\t";
        }
        cout<<endl;
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

    for (int i = 0; i < m; i++) {
        matrix[i].resize(n);

        string matrix_row_temp_temp;
        getline(cin, matrix_row_temp_temp);

        vector<string> matrix_row_temp = split(rtrim(matrix_row_temp_temp));

        for (int j = 0; j < n; j++) {
            int matrix_row_item = stoi(matrix_row_temp[j]);

            matrix[i][j] = matrix_row_item;
        }
    }

    matrixRotation(matrix, r);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
