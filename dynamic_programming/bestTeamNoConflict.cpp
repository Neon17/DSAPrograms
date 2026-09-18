/*
Leetcode Medium 1626. Best Team With No Conflicts

You are the manager of a basketball team. 
For the upcoming tournament, you want to choose the team with the highest overall score. 
The score of the team is the sum of scores of all the players in the team.

However, the basketball team is not allowed to have conflicts. 
A conflict exists if a younger player has a strictly higher score than an older player. 
A conflict does not occur between players of the same age.

Given two lists, scores and ages, 
    where each scores[i] and ages[i] represents the score and age of the ith player, respectively, 
    return the highest overall score of all possible basketball teams.

Constraints:
    1 <= scores.length, ages.length <= 1000
    scores.length == ages.length
    1 <= scores[i] <= 10^6
    1 <= ages[i] <= 1000
*/
#include<iostream>
#include<vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        if (scores.size() == 1) return scores[0];
        vector<int> dp(scores.size(), 0);
        vector<pair<int, int>> agescore;
        for (int i=0;i<scores.size();i++) agescore.push_back({ages[i], scores[i]});
        sort(agescore.begin(), agescore.end(), [](const auto& a, const auto& b){
            return a.first == b.first ? a.second < b.second : a.first < b.first;
        });
        for (int i=0;i<agescore.size();i++){
            dp[i] = agescore[i].second;

            for (int j=0;j<i;j++){
                if (agescore[j].first == agescore[i].first || agescore[i].second >= agescore[j].second){
                    dp[i] = max(dp[i], dp[j] + agescore[i].second);
                }
            }
        }
        int maxi = INT_MIN;
        for (int i=0;i<scores.size();i++) maxi = max(maxi, dp[i]);
        return maxi;
    }
};

int main(){
    Solution s;
    vector<int> scores, ages;

    scores = {1,3,5,10,15};
    ages = {1,2,3,4,5};
    cout << s.bestTeamScore(scores, ages) << endl; // 34

    scores = {4,5,6,5};
    ages = {2,1,2,1};
    cout << s.bestTeamScore(scores, ages) << endl; // 16

    scores = {1,2,3,5};
    ages = {8,9,10,1};
    cout << s.bestTeamScore(scores, ages) << endl; // 6

    return 0;
}

