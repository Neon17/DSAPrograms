// Leetcode Medium 875. Koko Eating Bananas
/*
    Constraints:
    1 <= piles.length <= 10^4
    piles.length <= h <= 10^9
    1 <= piles[i] <= 10^9
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size(), left = 1, right = 0, mid = 0, temp = 0;
        for (auto& pile: piles) right = max(right, pile);
        while (left < right){
            mid = left + (right - left)/2; temp = 0;
            for (auto& pile: piles) temp += (pile + mid - 1)/mid;
            if (temp <= h) right = mid;
            else left = mid+1;
            mid = left + (right - left)/2;
        }
        return left;
    }
};

int main() {
    Solution sol;
    vector<int> piles;
    int h, ans;

    piles = {3, 6, 7, 11};
    h = 8;
    ans = sol.minEatingSpeed(piles, h);
    cout << ans << endl;

    piles = {30, 11, 23, 4, 20};
    h = 5;
    ans = sol.minEatingSpeed(piles, h);
    cout << ans << endl;

    piles = {30, 11, 23, 4, 20};
    h = 6;
    ans = sol.minEatingSpeed(piles, h);
    cout << ans << endl;

    return 0;
}
