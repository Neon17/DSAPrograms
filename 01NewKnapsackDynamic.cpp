#include<iostream>
#include<vector>
using namespace std;

// lets take bag capacity(m) = 8
// number of items (n) = 4
// profits = 1,2,5,6
// weights = 2,3,4,5
// I think we have to sort the weight first before DP function calls

int* knapsack(int p[], int w[], int m, int n){
    int dp[n+1][m+1];
    int *x = new int[n]; 
    
    for (int i=0;i<=n;i++){
        for (int j=0;j<=m;j++){
            if(i==0 || j==0) 
                dp[i][j] = 0;
            else 
                dp[i][j] = (j >= w[i-1]) ? 
                    max(dp[i-1][j], dp[i-1][j-w[i-1]] + p[i-1]) : 
                    dp[i-1][j];
        }
    }
    
    int i = n, j = m;
    while(i > 0 && j > 0){
        if(dp[i][j] != dp[i-1][j]){
            x[i-1] = 1;
            j -= w[i-1];
        } else {
            x[i-1] = 0;
        }
        i--;
    }
    
    return x;
}

int main() {
    int n = 4, m=8;
    int p[n] = {1,2,5,6};
    int w[n] = {2,3,4,5};
    int *x = knapsack(p, w, m, n);
    cout<<"Value = {";
    int maxProfit = 0;
    for (int i=0;i<n;i++){
        cout<<x[i];
        if (i!=n-1) cout<<", ";
        maxProfit += p[i];
    }
    cout<<"}"<<endl;
    cout<<"Maximum Profit = "<<maxProfit<<endl;
    delete[] x;
    return 0;
}
