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
 * 
 * Approach 3 (Correct Top‑down DP – “aha!” moment):
 *   Wait… it’s just brute force! We don’t need to track path, mini, or profit.
 *   Trying all buy/sell combinations recursively: buy = subtract price, sell = add price.
 *   The recursion explores every possibility, so the max will naturally appear.
 *   State = (day, transactions left, holding). Clean O(n·k) with memoization.
 *   (Finally got it – sometimes overthinking kills simplicity.)
 *
 * Approach 4 – Bottom‑up DP using local minima (my derived solution):
 *   Observed that optimal buys occur only at local minima. Precompute these indices.
 *   Then dp[t][i] = max(dp[t][i-1], max over local minima m < i of (dp[t-1][m] + prices[i] - prices[m])).
 *   Time complexity O(k·n·m) where m ≈ n/2 → O(k·n²) worst case. Passes given constraints but not optimal.
 *
 * TODO: Derive the standard bottom‑up DP with O(k·n) time and O(k·n) space (or O(n) with space opt).
 *       Key idea: maintain a running maxDiff 
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<string, int> dp; // key: index + k + holding, value: max profit

    string getKey(int index, int k, bool holding){
        return to_string(k) + "-" + to_string(index) + "-" + to_string(holding);
    }

    int dfs( int k, vector<int> prices, int index=0, bool holding = false) {

        if (k<=0 || index >= prices.size()) return 0;
        string key = getKey(index, k, holding);
        if (dp.find(key) != dp.end()) return dp[key];

        int n = prices.size();
        int maxp = 0, dfs1 = 0, dfs2 = 0, temp=0, tempo = 0, newindex = 0;
        
        if (holding){
            // we can ignore or sell
            dfs1 = dfs(k, prices, index+1, true); 
            dfs2 = prices[index] + dfs(k-1, prices, index+1, false);
        } else {
            // we can ignore or buy
            dfs1 = dfs(k, prices, index+1, false);
            dfs2 = dfs(k, prices, index+1, true) - prices[index];
        }

        maxp = max(dfs1, dfs2);
        dp[key] = maxp;
        return maxp;
    }

    int calculateMaxProfit(vector<int>& prices, int start=0, int end=-1){
        if (end <= start) return 0;
        int mini = prices[start], maxi = prices[start], maxprofit = 0;

        for (int i=start+1;i<=end;i++){
            if (mini < prices[i]) mini = prices[i];
            maxprofit = max(maxprofit, prices[i]-mini);
        }
        return maxprofit;
    }

    int convertToBottomUp(int k, vector<int>& prices){
        int n = prices.size(), i=0, j=0, tk=0;
        vector<vector<int>> bp(k+1, vector<int>(n+1, 0));
        vector<int> minindex;
        int maxDiff = 0;

        for (int i=0;i<n-1;i++){
            if (i>0 && prices[i] <= prices[i+1] && prices[i] <= prices[i-1]){
                minindex.push_back(i);
            } else if (i==0){
                if (prices[i] < prices[i+1]) minindex.push_back(i);
            }
        }

        for (int j=1;j<=k;j++){
            for (int i=1;i<=n;i++){
                maxDiff = 0;
                for (int m = 0; m<minindex.size();m++){
                    if (minindex[m] >= i) break;
                    maxDiff = max(bp[j-1][minindex[m]] + prices[i-1] - prices[minindex[m]], maxDiff);
                }
                bp[j][i] = max(bp[j][i-1], maxDiff);
            }
        }

        return bp[k][n];
    }

    int standardBottomUp(int k, vector<int>& prices){
        // todo
        return 0;
    }

    int maxProfit(int k, vector<int>& prices) {
        vector<int> choose;
        dp.clear();
        // return dfs(k, prices);
        return convertToBottomUp(k, prices);
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

    k = 4; prices = {1, 5, 2, 3, 7, 6, 4, 8, 1, 9};
    cout << "Input: k = " << k << ", Output = " << s.maxProfit(k, prices) << endl; // expected output: 21

    k = 5; prices = {5, 4, 3, 2, 1};
    cout << "Input: k = " << k << ", Output = " << s.maxProfit(k, prices) << endl; // expected output: 0

    k = 1; prices = {1,2,2,2,3};
    cout << "Input: k = " << k << ", Output = " << s.maxProfit(k, prices) << endl; // expected output: 2

    k = 3; prices = {1, 10, 2, 9, 3, 8};
    cout << "Input: k = " << k << ", Output = " << s.maxProfit(k, prices) << endl; // expected output: 21

    k = 2; prices = {1, 10, 2, 9, 3, 8};
    cout << "Input: k = " << k << ", Output = " << s.maxProfit(k, prices) << endl; // expected output: 16

    k = 100; prices = {1,2,3,4,5};
    cout << "Input: k = " << k << ", Output = " << s.maxProfit(k, prices) << endl; // expected output: 4

    return 0;
}

