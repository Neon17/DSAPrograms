// here I am going to solve fibonacci using dynamic programming
#include <iostream>
#include <vector>
using namespace std;

vector<int> dp;

int fibonacci(int n){
    for (int i=2;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int main(){
    int n;
    cout<<"Enter the term: ";
    cin>>n;

    // Adding first 2 terms 0 and 1 to the dp
    for (int i=0;i<=n;i++){
        if (i==1){
            dp.push_back(1); continue;
        }
        dp.push_back(0);
    }

    cout<<"fibonacci term = "<<fibonacci(n)<<endl;

    // Printing all Fibonacci Term
    for (int i=1;i<dp.size();i++){
        cout<<dp[i]<<", ";
    }
    cout<<endl;

    return 0;
}
