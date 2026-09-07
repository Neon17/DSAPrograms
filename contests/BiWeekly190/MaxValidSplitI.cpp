// Leetcode Medium Q2. Maximum Valid Split Positions I

#include<iostream>
#include<vector>
#include <numeric>
#include <climits>
using namespace std;

class Solution {
public:
    int maxValidSplits(vector<int>& nums) {
        int n = nums.size();
        if (n == 2) return (nums[0] == nums[1]) ? 1 : 0;
        vector<int> prefix(n, 1), suffix(n, 1);
        int count = 0, ind = 0, sind = 0, maxi = 0;

        for (int i=0;i<n;i++){
            if (i == 0){
                prefix[i] = nums[i];
                suffix[n-i-1] = nums[n-i-1];
                continue;
            }
            prefix[i] = gcd(prefix[i-1], nums[i]);
            suffix[n-i-1] = gcd(suffix[n-i], nums[n-i-1]);
        }

        for (int i=0;i<n-1;i++){
            if (prefix[i] == suffix[i+1]) count++;
        }
        if (count > maxi) maxi = count;

        for (int i=0;i<n;i++){
            prefix.assign(n, 1);
            suffix.assign(n, 1);
            ind = 0; sind = n - 1; count = 0;

            for (int j=0;j<n;j++){
                if (sind == i) sind--;
                if (i==j) continue;
                if (ind == 0){
                    prefix[ind] = nums[j];
                    suffix[(n-1)-ind-1] = nums[sind--];
                    ind++;
                    continue;
                }
                prefix[ind] = gcd(prefix[ind-1], nums[j]);
                suffix[(n-1)-ind-1] = gcd(suffix[n-1-ind], nums[sind--]);
                ind++;
            }

            for (int i=0;i<n-2;i++){
                if (prefix[i] == suffix[i+1]) count++;
            }
            if (count > maxi) maxi = count;
        }
        return maxi;
    }
};


int main(){
    Solution s;
    vector<int> nums;

    nums = {10, 30, 15, 10};
    cout<<s.maxValidSplits(nums)<<endl;

    nums = {2, 10, 14};
    cout<<s.maxValidSplits(nums)<<endl;

    nums = {2, 4};
    cout<<s.maxValidSplits(nums)<<endl;

    nums = {95,16,40};
    cout<<s.maxValidSplits(nums)<<endl;

    return 0;
}
