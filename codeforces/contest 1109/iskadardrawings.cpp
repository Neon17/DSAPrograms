// Problem 2244A Iskandar Drawings
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    vector<long long> answer(t, 0);  

    for (int j = 0; j < t; j++){
        int n;
        cin >> n;
        string s;
        cin >> s;

        long long maxTime = 0;
        int i = 0;
        while (i < n){
            if (s[i] == '#'){
                int len = 0;
                while (i < n && s[i] == '#'){
                    len++;
                    i++;
                }

                long long time = (len + 1) / 2; 
                if (time > maxTime) maxTime = time;
            } else {
                i++;
            }
        }
        answer[j] = maxTime;
    }

    for (long long ans : answer){
        cout << ans << '\n';
    }

    return 0;
}