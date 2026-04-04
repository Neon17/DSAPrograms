/**
 * 123. Best Time to Buy and Sell Stock III
 * You are given an array prices where prices[i] is the price of a given stock on the ith day.
 * Find the maximum profit you can achieve. You may complete at most two transactions.
 * Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
 * 
 * Topics: Array, Dynamic Programming
 * Accepted 945,631/1.8M Acceptance Rate 53.4%
 * Difficulty: Hard
 * 
 * Constraints:
        1 <= prices.length <= 105
        0 <= prices[i] <= 105
 */

 /**
 * Approach 1(experimental heuristic): (my first tried approach by myself)
 * 
 * 1. Build a dp array where dp[i] = total profit of the current continuous rising streak
 *    ending at day i. When price drops, dp[i] is left as 0 (implicitly resetting the streak).
 * 
 * 2. Identify the best single transaction (max profit) from dp, and locate its exact
 *    range [rangeStart, rangeEnd] by scanning backwards until the streak breaks.
 * 
 * 3. Find the best second transaction from the remaining days (excluding the first range).
 *    Since dp only tracks rising streaks, the value at an index may not be the true max
 *    profit ending there (because resets cut history). So we then scan left from that index
 *    to find the actual minimum price, recalculating the profit.
 * 
 * 4. Re‑evaluate the first transaction's profit by scanning left from its sell day
 *    (rangeEnd) for a minimum price that does not overlap with the second transaction's range.
 * 
 * 5. Return the sum of the two adjusted profits.
 * 
 * Known limitations:
 * - Assumes optimal transactions are contiguous rising runs – not true in general.
 * - The dp reset on drops loses historical profit information, making the second
 *   transaction selection potentially suboptimal.
 * - The overlap avoidance logic is fragile and may break on more complex price patterns.
 * 
 * This solution passes the given test cases but is not guaranteed to be correct for all inputs.
 * It is kept for educational and self‑tracking purposes only.
  */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        vector<int> dp(n, 0);

        for (int i=1;i<n;i++){
            if (prices[i] > prices[i-1]){
                dp[i] = dp[i-1] + prices[i] - prices[i-1];
            }
        }

        int max = 0, rangeStart = 0, rangeEnd = n-1;
        for (int i=0;i<n;i++){
            if (dp[i] >= max){
                max = dp[i];
                rangeEnd = i;
            }
        }

        bool change = false;
        rangeStart = rangeEnd;
        for (int i=n-1;i>=0;i--){
            if (change){
                if (dp[i] > dp[i+1]) break;
                rangeStart = i;
            }
            if (i==rangeEnd) change = true;
        }

        int secondMax = 0, secondMaxIndex = 0;
        for (int i=0;i<n;i++){
            if (i >= rangeStart && i <= rangeEnd) continue;
            if (dp[i] > secondMax){
                secondMax = dp[i];
                secondMaxIndex = i;
            }
        }

        int min = prices[secondMaxIndex], minIndex = secondMaxIndex;
        for (int i=secondMaxIndex-1;i>=0;i--){
            if (i >= rangeStart && i <= rangeEnd) break;
            if (prices[i] < min){
                min = prices[i];
                minIndex = i;
            }
        }
        if (secondMax < prices[secondMaxIndex] - min)
            secondMax = prices[secondMaxIndex] - min;

        min = prices[rangeEnd];
        for (int i=rangeEnd-1;i>=0;i--){
            if (i >= minIndex && i <= secondMaxIndex) break;
            if (prices[i] < min){
                min = prices[i];
            }
        }
        int test = prices[rangeEnd] - min;
        if (max < test) max = test;

        return max + secondMax;
    }
};

int main() {
    Solution s;
    vector<int> prices;

    prices = {3,3,5,0,0,3,1,4};
    cout<<s.maxProfit(prices)<<endl; // expected 6

    prices = {1,2,3,4,5};
    cout<<s.maxProfit(prices)<<endl; // expected 4

    prices = {7,6,4,3,1};
    cout<<s.maxProfit(prices)<<endl; // expected 0

    prices = {1,2,4,2,5,7,2,4,9,0};
    cout<<s.maxProfit(prices)<<endl; /// expected 13

    prices = {1,5,2,6,3,7};
    cout<<s.maxProfit(prices)<<endl; // expected 9

    return 0;
}

