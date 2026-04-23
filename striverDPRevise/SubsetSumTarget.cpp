#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool dfs(vector<int> &arr, int target, int index, vector<vector<int>>& tp){
        if (target == 0) return true;
        if (index == 0) return arr[0] == target;
        if (tp[index][target] != -1) return tp[index][target];

        bool nottake = dfs(arr, target, index-1, tp);
        bool take = false;
        if (target >= arr[index]) take = dfs(arr, target-arr[index], index-1, tp);
        return tp[index][target] = take || nottake;
    }

    bool convertToBottomUp(vector<int> &arr, int target){
        int m = arr.size();
        vector<vector<bool>> dp(m, vector<bool>(target+1, false));
        for (int i=0;i<m;i++) dp[i][0] = true;
        if (target >= arr[0]) dp[0][arr[0]] = true;

        for (int i=1;i<m;i++){
            for (int j=1;j<=target;j++){
                bool nottake = dp[i-1][j];
                bool take = false;
                if (j >= arr[i]) take = dp[i-1][j-arr[i]];
                dp[i][j] = take || nottake;
            }
        }

        return dp[m-1][target];
    }

    bool spaceOptimised(vector<int> &arr, int target){ 
        vector<bool> prev(target+1, false), curr(target+1, false);
        prev[0] = curr[0] = true;
        if (target >= arr[0]) prev[arr[0]] = true;

        for (int i=1;i<arr.size();i++){
            for (int j=1;j<=target;j++){
                bool nottake = prev[j];
                bool take = false;
                if (j >= arr[i]) take = prev[j-arr[i]];
                curr[j] = take || nottake;
            }
            prev = curr;
        }

        return prev[target];
    }

    bool subsetSumToK(vector<int> &arr, int target, int flag=0)
    {
        vector<vector<int>> tp(arr.size(), vector<int>(target, -1));
        if (flag == 0) return dfs(arr, target, arr.size()-1, tp);
        else if (flag == 1) return convertToBottomUp(arr, target);
        else if (flag == 2) return spaceOptimised(arr, target);
        return false;
    }
};

int main()
{
    int target;
    vector<int> arr;
    Solution sol;

    arr = {1, 2, 3, 4};
    target = 6;
    cout << (sol.subsetSumToK(arr, target) ? "Yes" : "No")<<endl;
    cout << (sol.subsetSumToK(arr, target, 1) ? "Yes" : "No")<<endl;
    cout << (sol.subsetSumToK(arr, target, 2) ? "Yes" : "No")<<endl;

    return 0;
}
