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
 * Approach 1(experimental heuristic): (my first tried approach by myself but failed)
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

/**
 * Approach 2(DP): (actual solution solved from high level algorithm)
 * 
 * Just do this: for each i, calculate max profit for left side 0 to i and store in left[i] (considering one transaction)
 * and calculate max profit for right side i+1 to n-1 and store in left[i] (considering one transaction)
 * then, in another loop, add those left and right and assign to total if total is less than sum
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxHeuristicProfit(vector<int>& prices) {
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

        // I have done one boundary check only, I have to check and expand both boundaries
        // secondMaxIndex is not fixed, It can more or less than that, because we already worked previously by local maxima
        int maxi = prices[secondMaxIndex];
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

    // left[i] has max prices on 0 to equal to ith part
    // right[i] has max prices on i+1 to size-1 part
    int maxProfit(vector<int>& prices){
        int total = 0, n = prices.size();
        if (n <= 1) return total;
        vector<int> left(n, 0), right(n, 0);

        int mini = prices[0];
        for (int i=1;i<n;i++){
            if (mini > prices[i]){
                mini = prices[i];
                left[i] = left[i-1];
            } else {
                left[i] = max(left[i-1], prices[i]-mini);
            }
        }

        int maxi = prices[n-1];
        for (int i=n-2;i>=0;i--){
            if (maxi < prices[i]){
                maxi = prices[i];
                right[i] = right[i+1];
            } else {
                right[i] = max(right[i+1], maxi - prices[i]);
            }
        }

        for (int i=0;i<n; i++){
            total = max(total, left[i]+right[i]);
        }

        return total;
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

    // But Heuristic approach doesn't work on this
    prices = {1,3,5,4,3,7,6,9,2,4};
    cout<<s.maxProfit(prices)<<endl; // expected 10

    return 0;
}

