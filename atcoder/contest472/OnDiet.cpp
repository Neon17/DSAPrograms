/*
    C - On a Diet
*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main(){
    int n, m; long long k, sum = 0; 
    cin >> n >> m >> k;
    vector<int> v(n);
    vector<bool> w(n, false);
    unordered_set<int> taken;

    for(int i = 0; i < n; ++i) {
        cin >> v[i];
        if (i >= m && taken.count(i-m)) sum -= v[i-m];
        sum += v[i];
        if (sum <= k) {
            w[i] = true;
            taken.insert(i);
        } else sum -= v[i];
    }
    for (int i=0; i < n; ++i) {
        if (w[i]) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}

