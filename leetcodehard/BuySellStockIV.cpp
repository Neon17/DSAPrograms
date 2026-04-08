/**
 * 188. Best Time to Buy and Sell Stock IV
 * 
 * You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.
 * Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.
 * Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
 * 
 * Example 1:
 *
 * Input: k = 2, prices = [2,4,1]
 * Output: 2
 * Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
 * Example 2:
 * 
 * Input: k = 2, prices = [3,2,6,5,0,3]
 * Output: 7
 * Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
 * 
 * Constraints:
 * 
 * 1 <= k <= 100
 * 1 <= prices.length <= 1000
 * 0 <= prices[i] <= 1000
 * 
 * Topics: Array, Dynamic Programming
 * Category: Hard
 * Accepted 707,138/1.4M Acceptance Rate 49.8%
 */

/**
 * Approach 1 (Brute Force – first attempt):
 *   Recursively try all possible non‑overlapping segments as transactions.
 *   For each segment, compute the best profit using a single‑transaction
 *   O(segment length) scan. The recursion explores all ways to choose up to
 *   k segments. Time complexity: O(C(n, 2k)) – exponential, too slow for n=1000.
 *
 * Approach 2 (Top‑down DP with memoization – current):
 *   Memoize the brute‑force recursion using a key (k, index, step, holding).
 *   step represents the length of the current transaction being considered.
 *   This reduces repeated calculations but still has O(n²·k) states, which is
 *   too large for the given constraints (n=1000, k=100). The use of unordered_map
 *   with string keys adds further overhead. Works for small inputs only.
 *
 * TODO: Optimize to O(n·k) using state (i, k, holding) – the standard solution.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<string, int> dp; // key: index + step + k + holding, value: max profit

    int maxBruteforce(vector<int>& prices, int index = 0, int step = 0){
        int maxi = 0;
        if (step <= 0 || index <0 || index+step >= prices.size()) return 0;
        int mini = prices[index];

        
        for (int i=1;i<=step;i++){
            if (mini > prices[index+i]) mini = prices[index+i];
            else maxi = max(maxi, prices[index+i] - mini);
        }
        
        // cout<<"startIndex: " << choose[0] << ", endIndex: " << choose[choose.size()-1] << ", maxProfit: " << maxi << endl;
        return maxi;
    }

    string getKey(int k, int index, int step, bool holding){
        return to_string(k) + "-" + to_string(index) + "-" + to_string(step) + "-" + to_string(holding);
    }

    string setKey(int k, int index, int step, bool holding, int value){
        string key = getKey(k, index, step, holding);
        dp[key] = value;
        return key;
    }

    int dfs( int k, vector<int> prices, int& step, int index=0, bool holding = false){
        // we can memoize it by dp[index][step][k][holding] = maxp; but it will be too large

        if (k<=0 || index+step >= prices.size()) return 0;
        string key = getKey(k, index, step, holding);
        if (dp.find(key) != dp.end()) return dp[key];

        int n = prices.size();
        int maxp = 0, dfs1 = 0, dfs2 = 0, temp=0, tempo = 0, newindex = 0;
        
        if (holding){
            // we can ignore or sell
            step++;
            dfs1 = dfs(k, prices, step, index, true); 
            step--;
            temp = maxBruteforce(prices, index, step);
            newindex = index + step + 1;
            tempo = step; step = 0;
            dfs2 = temp + dfs(k-1, prices, step, newindex, false);
            step = tempo;
        } else {
            // we can ignore or buy
            dfs1 = dfs(k, prices, step, index+1, false);
            step++;
            dfs2 = dfs(k, prices, step, index, true);
            step--;
        }

        maxp = max(dfs1, dfs2);
        dp[key] = maxp;
        return maxp;
    }

    int maxProfit(int k, vector<int>& prices) {
        vector<int> choose;
        int step = 0;
        dp.clear();
        return dfs(k, prices, step);
    }
};

int main() {
    int k; vector<int> prices;
    Solution s;

    k = 2; prices = {2,4,1};
    cout << "Input: k = " << k << ", Output = " << s.maxProfit(k, prices) << endl; // expected output: 2

    k = 2; prices = {1,2};
    cout << "Input: k = " << k << ", Output = " << s.maxProfit(k, prices) << endl; // expected output: 1

    k = 2; prices = {3,2,6,5,0,3};
    cout << "Input: k = " << k << ", Output = " << s.maxProfit(k, prices) << endl; // expected output: 7

    return 0;
}

