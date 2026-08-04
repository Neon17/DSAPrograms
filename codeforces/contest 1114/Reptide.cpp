// Problem 2254A: Reptide

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    vector<int> counts;
    while (t--){
        int a = 0, b = 0, c = 0;
        cin >> a >> b >> c;

        int count = 0;
        while (!(a == b || a == c || b == c)){
            if (a < b){
                if (a < c){
                    a++;
                    if (b < c) c--;
                    else b--;
                } else {
                    c++;
                    b--;
                }
            } else if (a < c){
                b++;
                c--;
            } else {
                if (b < c) b++;
                else c++;
                a--;
            }
            count++;
        }
        counts.push_back(count);
    }
    
    // cout<<"Answers = "<<endl;
    for (int count : counts) {
        cout << count << endl;
    }

    return 0;
}

