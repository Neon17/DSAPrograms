#include <iostream>
using namespace std;
#include <vector>
#include <math.h>

class Solution {
public:
    vector<long long> dp;

    Solution () {
        long long temp = 0;
        for (int i=1;i<=14;i++){
            temp = pow(10, i-1);
            temp *= 9;
            dp.push_back(temp * i);
        }
    }

    int kthDigit(long long k) {
        int ans = 0, i=0;
        long long rem = k - 1;
        long long finished=0;

        for (i=0;i<14;i++){
            if (rem < dp[i]) break;
            rem -= dp[i];
        }
        int len = i + 1;
        finished = rem / len;
        int pos = rem % len;

        long long base = 1;
        for (int j=1;j<len;j++) base *= 10;
        long long actual = base + finished;

        if ((actual / 10) % 2 == 1) actual = (actual / 10) * 10 + 9 - actual % 10;

        for (int j = len - 1; j > pos; j--) actual /= 10;
        ans = actual % 10;
        return ans;
    }
};

int main(){
    Solution sol;
    long long k;
    int ans;

    k = 4;
    ans = sol.kthDigit(k);
    cout << ans << endl;

    k = 15;
    ans = sol.kthDigit(k);
    cout << ans << endl;

    k = 11;
    ans = sol.kthDigit(k);
    cout << ans << endl;


    return 0;
}