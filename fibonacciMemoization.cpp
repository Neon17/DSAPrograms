#include <iostream>
#include <vector>
using namespace std;


vector<pair<int,int>> memo;

int fibonacci(int n){
    if (n<=1) return 0;
    else if (n==2) return 1;

    int temp1 = -1, temp2 = -1;

    for (auto &it: memo){
        if (it.first == n) return it.second;
    }

    int a = fibonacci(n-2) + fibonacci(n-1);
    memo.push_back({n, a});
    return a;
}

int main(){
    int n = 6;

    for (int i=1; i<=n; i++){
        cout<<"Fibonacci of "<<i<<" term = "<<fibonacci(i)<<endl;
    }

    /* Memoization Output */
    cout<<"Memoization Table: "<<endl;
    for (auto &it: memo){
        cout<<"Term: "<<it.first<<" Value: "<<it.second<<endl;
    }

    return 0;
}

