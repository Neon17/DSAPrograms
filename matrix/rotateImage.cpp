// Leetcode Medium 48. Rotate Image
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();

         // make transpose of the matrix
        for (int i=0;i<m;i++){
            for (int j=0;j<i;j++){
                matrix[i][j] = matrix[i][j] + matrix[j][i];
                matrix[j][i] = matrix[i][j] - matrix[j][i];
                matrix[i][j] = matrix[i][j] - matrix[j][i];
            }
        }

        // then reverse the row
        for (int i=0;i<m;i++){
            for (int j=0;j<n/2;j++){
                matrix[i][j] = matrix[i][n-1-j] + matrix[i][j];
                matrix[i][n-1-j] = matrix[i][j] - matrix[i][n-1-j];
                matrix[i][j] = matrix[i][j] - matrix[i][n-1-j];
            }
        }
    }
};

void printMatrix(vector<vector<int>> matrix){
    for (int i=0;i<matrix.size();i++){
        for (int j=0;j<matrix[0].size();j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    Solution s;
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};

    s.rotate(matrix);
    printMatrix(matrix);

    return 0;
}

