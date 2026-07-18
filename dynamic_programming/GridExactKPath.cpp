// Leetcode Hard 3988. Create Grid With Exactly K Paths I
// Return any grid such that there are exactly k valid paths from the top-left cell to the bottom-right cell. If no such grid exists, return an empty array.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> createGrid(int m, int n, int k) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) dp[i][j] = 1;
                else {
                    if (i > 0) dp[i][j] += dp[i-1][j];
                    if (j > 0) dp[i][j] += dp[i][j-1];
                }
            }
        }

        int total = dp[m-1][n-1];
        if (total < k) return {};

        vector<string> grid(m, string(n, '.'));
        int diff = total - k;

        auto computeUp = [&]() {
            vector<vector<int>> up(m, vector<int>(n, 0));
            for (int i = m-1; i >= 0; --i) {
                for (int j = n-1; j >= 0; --j) {
                    if (grid[i][j] == '#') continue;
                    if (i == m-1 && j == n-1) up[i][j] = 1;
                    else {
                        if (i+1 < m) up[i][j] += up[i+1][j];
                        if (j+1 < n) up[i][j] += up[i][j+1];
                    }
                }
            }
            return up;
        };

        vector<vector<int>> up = computeUp();

        for (int i = m-1; i >= 0; --i) {
            for (int j = n-1; j >= 0; --j) {
                if ((i == 0 && j == 0) || (i == m-1 && j == n-1)) continue;
                if (grid[i][j] == '#') continue;

                int removed = dp[i][j] * up[i][j];
                if (removed <= diff) {
                    grid[i][j] = '#';
                    diff -= removed;
                    if (diff == 0) return grid;
                    up = computeUp();
                }
            }
        }

        return (diff == 0) ? grid : vector<string>();
    }
};

int main() {
    return 0;
}