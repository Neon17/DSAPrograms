// Leetcode Medium 309. Best Time to Buy and Sell Stock with Cooldown
// After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).

#include <iostream>
#include <vector>
using namespace std;

class Solution {

    // I'm thinking of state = 0 (going to buy), 1 (going to sell) , 2 (cooldown)
    int bruteforce(vector<int>& prices, vector<vector<int>>& visited, int index = 0, int state = 0){
        if (index == prices.size()) return 0;
        if (visited[index][state] != -1) return visited[index][state];
        int temp1=0, temp2=0, res = 0;

        if (state == 2) return visited[index][state] = bruteforce(prices, visited, index+1, (state+1)%3);;
        temp1 = bruteforce(prices, visited, index+1, state);
        temp2 = bruteforce(prices, visited, index+1, (state+1)%3);
        if (state == 0) temp2 -= prices[index];
        else temp2 += prices[index];

        res = max(temp1, temp2);
        return visited[index][state] = res;
    }

    int convertDP(vector<int>& prices){
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(3, 0));
        dp[n-1][1] = prices[n-1];

        for (int i = n-2; i >= 0; i--){
            dp[i][0] = max(-prices[i] + dp[i+1][1], dp[i+1][0]);
            dp[i][1] = max(prices[i] + dp[i+1][2], dp[i+1][1]);
            dp[i][2] = dp[i+1][0];
        }
        return dp[0][0];
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        // vector<vector<int>> visited(n, vector<int>(3, -1));
        // return bruteforce(prices, visited);
        return convertDP(prices);
    }
};

int main() {
    Solution s;
    vector<int> prices;

    prices = {1,2,3,0,2};
    cout << s.maxProfit(prices) << endl; // 3, transactions = [buy, sell, cooldown, buy, sell]

    prices = {1};
    cout << s.maxProfit(prices) << endl; // 0, transactions = []

    return 0;
}

