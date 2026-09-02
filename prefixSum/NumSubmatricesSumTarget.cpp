/*
    Leetcode Hard 1074. Number of Submatrices That Sum to Target

    Given a matrix and a target, return the number of non-empty submatrices that sum to target.
    A submatrix x1, y1, x2, y2 is the set of all cells matrix[x][y] with x1 <= x <= x2 and y1 <= y <= y2.
    Two submatrices (x1, y1, x2, y2) and (x1', y1', x2', y2') are different 
        if they have some coordinate that is different: for example, if x1 != x1'.

    Constraints:
        1 <= matrix.length <= 100
        1 <= matrix[0].length <= 100
        -1000 <= matrix[i][j] <= 1000
        -10^8 <= target <= 10^8
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size(), count = 0;

        for (int top = 0; top<m;top++){
            vector<int> colSum(n, 0);

            for (int bottom = top; bottom <m;bottom++){
                for (int c=0;c<n;c++){
                    colSum[c] += matrix[bottom][c];
                }
                unordered_map<int, int> prefixCount;
                prefixCount[0] = 1;
                int running = 0;
                for (int c=0;c<n;c++){
                    running += colSum[c];
                    int need = running - target;
                    if (prefixCount.count(need)){
                        count += prefixCount[need];
                    }
                    prefixCount[running]++;
                }
            }
        }
        return count;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> matrix; int target;

    matrix = {{0,1,0},{1,1,1},{0,1,0}};
    target = 0;
    int result = solution.numSubmatrixSumTarget(matrix, target);
    cout << "Number of submatrices that sum to target: " << result << endl;

    matrix = {{1,-1},{-1,1}};
    target = 0;
    result = solution.numSubmatrixSumTarget(matrix, target);
    cout << "Number of submatrices that sum to target: " << result << endl;
    return 0;
}


