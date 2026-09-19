/*
Leetcode Hard 354. Russian Doll Envelopes

You are given a 2D array of integers envelopes where 
    envelopes[i] = [wi, hi] represents the width and the height of an envelope.

One envelope can fit into another if and only if 
    both the width and height of one envelope are greater than the other envelope's width and height.

Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).

Note: You cannot rotate an envelope.

Constraints:
1 <= envelopes.length <= 10^5
envelopes[i].length == 2
1 <= wi, hi <= 10^5
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    int standardDP(vector<vector<int>>& envelopes){
        int res = 0;
        sort(envelopes.begin(), envelopes.end(), [](const auto& a, const auto& b){
            return (a[0] == b[0])? a[1] < b[1] : a[0] < b[0];
        });
        vector<int> dp(envelopes.size(), 0);
        for (int i = 0; i < envelopes.size();i++){
            dp[i] = 1;
            for (int j=0;j<i;j++){
                if (envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        for (int i=0;i<dp.size();i++) res = max(res, dp[i]);
        return res;
    }
    int optimizeDP(vector<vector<int>>& envelopes){
        int left = 0, right = 0, mid = 0;
        sort(envelopes.begin(), envelopes.end(), [](const auto& a, const auto& b){
            return (a[0] == b[0])? a[1] > b[1] : a[0] < b[0];
        });
        vector<int> tails;
        tails.push_back(envelopes[0][1]);

        for (int i=1;i<envelopes.size();i++){
            if (tails[tails.size()-1] < envelopes[i][1]){
                tails.push_back(envelopes[i][1]);
                continue;
            }

            left = 0; right = tails.size()-1;
            while (left < right){
                mid = left + (right - left)/2;
                if (tails[mid] < envelopes[i][1]) left = mid+1;
                else right = mid;
            }
            tails[left] = envelopes[i][1];
        }
        return tails.size();
    }
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // return standardDP(envelopes);
        return optimizeDP(envelopes);
    }
};

int main(){
    Solution s;
    vector<vector<int>> envelopes;

    envelopes = {{5,4},{6,4},{6,7},{2,3}};
    cout << s.maxEnvelopes(envelopes) << endl; // 3

    envelopes = {{1,1},{1,1},{1,1}};
    cout << s.maxEnvelopes(envelopes) << endl; // 1

    return 0;
}
