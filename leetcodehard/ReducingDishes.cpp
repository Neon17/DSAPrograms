/**
 * 
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int dfs(vector<int>& satisfaction, vector<vector<int>>& tp, int i, int time=1){
        if (i < 0) return 0;
        if (tp[i][time-1] != -1) return tp[i][time-1];
        
        int way1 = dfs(satisfaction, tp, i-1, time);
        int way2 = time * satisfaction[i] + dfs(satisfaction, tp, i-1, time+1);

        return tp[i][time-1] = max(way1, way2);
    }

    int convertToBottomUp(vector<int>& satisfaction) {
        int n = satisfaction.size();
        vector<vector<int>> dp (n, vector<int>(n, -1));

        

        return 0;
    }

    int spaceOptimized(vector<int>& satisfaction) {


        return 0;
    }

    int maxSatisfaction(vector<int>& satisfaction, int flag=0) {
        int ans = 0, n = satisfaction.size();
        vector<vector<int>> tp (n, vector<int>(n, -1));
        sort(satisfaction.begin(), satisfaction.end(), greater<int>());

        if (flag == 0) ans = dfs(satisfaction, tp, n-1);
        else if (flag == 1) ans = convertToBottomUp(satisfaction);
        else ans = spaceOptimized(satisfaction);
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> satisfaction;

    satisfaction = {-1,-8,0,5,-9};
    cout << s.maxSatisfaction(satisfaction) << endl;

    satisfaction = {4,3,2};
    cout << s.maxSatisfaction(satisfaction) << endl;

    satisfaction = {2,3,4};
    cout << s.maxSatisfaction(satisfaction) << endl;

    satisfaction = {-1,-4,-5};
    cout << s.maxSatisfaction(satisfaction) << endl;

    return 0;
}
