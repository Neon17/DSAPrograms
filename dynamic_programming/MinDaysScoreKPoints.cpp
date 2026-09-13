/*
Leetcode Medium 4050. Minimum Days to Score Exactly N Points

You are given an integer n representing a target score.

Your score starts at 0, and each day you either earn points or skip.

Points are earned during a streak. 
On the first day of a streak you earn 1 point, on the second day 2 points, on the third day 3 points, and so on. 
Skipping a day earns nothing and resets the streak, so the next time you earn points, you start from 1 again.

Return the minimum number of days, including any skipped days, needed to reach a score of exactly n.

Constraints:
1 <= n <= 10^5
*/

#include<iostream>
#include<climits>
#include <vector>
using namespace std;

class Solution {
    int backtrack(int n, vector<int>& memo){
        if (n==0) return 0;
        if (memo[n] != -1) return memo[n];

        int days = INT_MAX, sum = 0;

        for (int l = 1; l*(l+1)/2<=n;l++){
            sum = l*(l+1)/2;
            sum = l + 1 + backtrack(n-sum, memo);
            days = min(days, sum);
        }
        return memo[n] = days;
    }

    int convertToDP(int n){
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        
        for (int i=1;i <= n;i++){
            
            for (int j=1;(j*(j+1)/2)<=i;j++){
                int tri = j*(j+1)/2;
                dp[i] = min(dp[i], (j+1) + dp[i-tri]);
            }
        }
        return dp[n]-1;
    }
public:
    int minDays(int n) {
        // vector<int> memo(n+1, -1);
        // return backtrack(n,memo)-1;        
        return convertToDP(n);
    }
};

int main(){
    Solution sol;
    int n;

    n = 2;
    cout<<sol.minDays(n)<<endl; // Output: 3

    n = 9;
    cout<<sol.minDays(n)<<endl; // Output: 6

    n = 12;
    cout<<sol.minDays(n)<<endl; // Output: 7
    
    return 0;
}

