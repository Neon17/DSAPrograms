
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size(), count = 0;
        long long prefix = 0, suffix = 0;
        int mid = n/2;

        for (int i=0;i<mid;i++){
            prefix += nums[i];
        }
        for (int i=mid;i<n;i++){
            suffix += nums[i];
        }

        for (int rot = 0; rot < n; rot++){
            if (prefix > suffix) count++;
            prefix = prefix - nums[rot] + nums[(rot + mid) % n];
            suffix = suffix + nums[rot] - nums[(rot + mid) % n];
        }
        return count;
    }
};

int main(){
    Solution sol;
    vector<int> nums; 

    nums = {1,2,3,4,5,6};
    cout<<sol.countGoodRotations(nums)<<endl;

    nums = {1,2,1,2};
    cout<<sol.countGoodRotations(nums)<<endl;

    nums = {3,4,5,1,2};
    cout<<sol.countGoodRotations(nums)<<endl;

    return 0;
}
