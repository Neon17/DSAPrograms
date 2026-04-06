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
  * My approach: I will try BruteForce first, then I will try to optimize it using Dynamic Programming.
  * BruteForce: I will try all possible combinations of buy and sell, and I will keep track of the maximum profit. This approach will have a time complexity of O(n^k), where n is the number of days and k is the number of transactions.
  */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxBruteforce(vector<int>& prices, int startIndex, int endIndex){
        int maxi = 0;
        if (startIndex < 0) return 0;
        int mini = prices[startIndex];

        // cout<<"startIndex: " << startIndex << ", endIndex: " << endIndex << ", maxProfit: " << maxi << endl;
        
        for (int i=startIndex+1;i<=endIndex;i++){
            if (mini > prices[i]) mini = prices[i];
            else maxi = max(maxi, prices[i] - mini);
        }
        
        return maxi;
    }

    int dfs( int k, vector<int> prices, int index=-1, int step=0, int depth = 0){
        // we can take any steps from 1 to remaining part
        if (depth >= k || (index >= 0 && index+step >= prices.size())) return 0;
        int n = prices.size();
        int maxp = 0, stepp = 0;
        int temp = maxBruteforce(prices, index, index+step);
        int tempp = 0; maxp = temp;
        int depthp = (temp > 0 && index!=-1)? depth+1: depth;

        for (int i=index+step+1;i<n;i++){
            tempp = temp + dfs(k, prices, index+step+1, stepp, depthp);
            maxp = max(tempp, maxp);
            stepp++;
        }

        return maxp;
    }

    int maxProfit(int k, vector<int>& prices) {
        return dfs(k, prices);
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

