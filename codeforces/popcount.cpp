// Codeforces Problem 2240 A. Another Popcount Problem
#include <bits/stdc++.h>
using namespace std;

int solve(int n, int k) {
    int ans = 0;
    int cost = 1;
    while (n >= cost) {
        int take = min(k, n / cost);
        ans += take;
        n -= take * cost;
        cost <<= 1;   // cost *= 2
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        cout << solve(n, k) << '\n';
    }
    return 0;
}

