// Problem 2244B: Nikita and Books
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    int sum = 0;
    vector<bool> v(t, false);
    bool flag = true;

    for (int j=0;j<t;j++){
        int n, k;
        cin >> n;
        sum = 0;
        flag = true;

        for (int i=0;i<n;i++){
            cin>>k;
            if (k > i){
                sum += k - i - 1;
            } else {
                sum -= i + 1 - k;
                if (sum < 0){
                    flag = false;
                }
            }
        }
        v[j] = flag;
    }

    for (bool b : v){
        cout << (b? "YES" : "NO") << endl;
    }
    return 0;
}
