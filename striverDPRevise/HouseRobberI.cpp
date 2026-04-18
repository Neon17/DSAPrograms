#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:

    int dfs(vector<int>& houses, int index=0){
        if (index >= houses.size()) return 0;

        int choose = houses[index] + dfs(houses, index+2);
        int skip = dfs(houses, index+1);

        return max(choose, skip);
    }

    int standard(vector<int>& houses){
        if (houses.size() <= 0) return 0;
        vector<int> dp(houses.size(), 0);
        if (houses.size() == 1) return houses[0];
        dp[0] = houses[0]; dp[1] = houses[1];

        for (int i=2;i<houses.size();i++){
            dp[i] = max(dp[i-1], houses[i]+dp[i-2]);
        }
        return dp[houses.size()-1];
    }
};

int main() {
    vector<int> houses;
    Solution s;

    houses = {2, 4, 5, 12, 7};
    cout<<s.standard(houses)<<endl; //expected 16

    houses = {2, 7, 9, 3, 1};
    cout<<s.standard(houses)<<endl; // expected 12

    return 0;
}   