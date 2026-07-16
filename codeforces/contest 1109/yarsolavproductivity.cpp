// Codeforces Problem 224D: Yaroslav and Productivity
// Interval DP properly learned, max number of segment choose and continue to find the max

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t,n,m, sum=0, temp = 0;
    cin >> t;

    for (int i=0;i<t;i++){
        cin>>n>>m;
        temp = 0;

        vector<int> v(n);
        vector<int> prefix(n+1, 0);

        vector<int> b(m);
        for (int i = 0; i < m; i++) cin >> b[i];
        sort(b.begin(), b.end());

        for (int j=0;j<n;j++){
            cin>>v[j];
            prefix[j+1] = prefix[j] + v[j];
        }

        int last_sum = prefix[prefix.size()-1] - prefix[b.back()];
        int s = 0, prev = 0;
        int include = last_sum, exclude = -1e9;

        for (int i = m - 1; i >= 0; i--){

            prev = (i == 0)? 0 : b[i-1];
            s = prefix[b[i]] - prefix[prev];
            temp = max(include, exclude);
            include = s + temp;
            exclude = -s + temp;
            prev = b[i];
        }
        cout<<max(include, exclude)<<endl;
    }

    return 0;
}
