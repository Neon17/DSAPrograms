/*
Problem Statement
There is one stick. This stick has 
N−1 notches, which divide it into 
N parts.

*/

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main(){
    int n, mini = __INT32_MAX__ , sum = 0;
    cin >> n;
    vector<int> a(n);
    vector<int> prefix(n+1, 0);

    for(int i = 0; i < n; i++){
        cin >> a[i];
        prefix[i+1] = prefix[i] + a[i];
    }
    for (int i = n-1; i >= 1; i--){
        sum += a[i];
        mini = min(mini, abs(sum - prefix[i]));
    }
    cout << mini << endl;
    return 0;
}
