/**
 * 403. Frog Jump
 * A frog is crossing a river. The river is divided into some number of units, and at each unit, there may or may not exist a stone. The frog can jump on a stone, but it must not jump into the water.

Given a list of stones positions (in units) in sorted ascending order, determine if the frog can cross the river by landing on the last stone. Initially, the frog is on the first stone and assumes the first jump must be 1 unit.

If the frog's last jump was k units, its next jump must be either k - 1, k, or k + 1 units. The frog can only jump in the forward direction.

Topics: Junior, Array, Dynamic Programming
 */

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    map<pair<int, int>, bool> memo;

    bool dfs(vector<int>& stones, int i, int lastDiff = -1){
        if (i == stones.size() - 1) return true;
        if (memo.find({i, lastDiff}) != memo.end()) return memo[{i, lastDiff}];

        if (i == 0) {
            if (stones.size() > 1 && stones[1] - stones[0] == 1) {
                return memo[{i, lastDiff}] = dfs(stones, 1, 1);
            }
            return memo[{i, lastDiff}] = false;
        }

        for (int in = i + 1; in < stones.size(); in++) {
            int diff = stones[in] - stones[i];

            if (diff < lastDiff - 1) continue; 
            if (diff > lastDiff + 1) break; 

            if (dfs(stones, in, diff)) return memo[{i, lastDiff}] = true;
        }
        return memo[{i, lastDiff}] = false;
    }

    bool convertToBottomUp(vector<int>& stones){
        vector<vector<bool>> dp(stones.size(), vector<bool>(stones.size(), false));
        if ((stones[1] - stones[0]) != 1) return false;
        int m = stones.size(), diff = 0;
        dp[0][0] = true;



        return false;
    }

    bool spaceOptimized(vector<int>& stones){
        return false;
    }

    bool canCross(vector<int>& stones, int flag=0) {
        bool ans = false;
        if (!flag) ans = dfs(stones, stones.size()-1);
        return ans;
    }

};

int main() {
    Solution s;
    vector<int> stones;

    stones = {0,1,3,5,6,8,12,17};
    cout << s.canCross(stones) << endl;
    return 0;
}

