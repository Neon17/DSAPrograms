// CodeForces Problem: 2244C: Stepan and Permutation
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t,n,x,y;
    cin>>t;

    for (int i=0;i<t;i++){
        cin>>n>>x>>y;
        
        vector<int> p(n+1);
        for (int i=1;i<=n;i++){
            cin>>p[i];
        }

        int g = gcd(x, y);
        bool ok = true;

        for (int i=1;i<=n;i++){
            if (i % g != p[i] % g){
                ok = false;
                break;
            }
        }
        cout<<(ok? "YES" : "NO")<<endl;
    }

    return 0;
}
