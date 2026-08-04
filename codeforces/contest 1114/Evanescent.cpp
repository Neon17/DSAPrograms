// Problem 2254B: Evanescent
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--){
        int n = 0, loc = 0;
        // loc means where is best string to be deleted
        // loc = 2 means we have ada like string (best case)
        // loc = 0 means we have baa, aab like string (worst case)
        // loc = 1 means we have aadbcd, abcd like string (medium case)
        cin >> n;
        string s = "", ns = "";
        cin >> s;
        ns.push_back(s[0]);
        for (int i = 1; i < n-1; i++){
            if (s[i] == s[i-1] || s[i] == s[i+1]) continue;

            if (s[i-1] == s[i+1] && s[i] != s[i-1]){
                loc = 2;
            } else if (s[i-1] != s[i] && s[i] != s[i+1] && s[i-1] != s[i+1]){
                loc = max(loc, 1);
            }
        }
        for (int i=1;i<n;i++){
            if (s[i] != ns.back()){
                ns.push_back(s[i]);
            }
        }
        cout << ns.size()-loc << endl;

    }
    return 0;
}

