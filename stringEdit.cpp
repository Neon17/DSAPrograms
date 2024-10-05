//String Editing Problem using dynamic approach
#include <bits/stdc++.h>
#include <string>
using namespace std;

#define minimum(a,b,c) ((a<b)?(a<c)?a:c:(b<c)?b:c)

int editDistance(string a, string b){
    //minimum insert and delete operations to transform string a to b
    int i,j,temp;
    int m = a.size();
    int n = b.size();
    int table[m+1][n+1];
    cout<<"----------Table----------"<<endl;
    for (i=0;i<=m;i++){
        for (j=0;j<=n;j++){
            if (i==0)
                table[i][j] = j;
            else if (j==0)
                table[i][j] = i;
            else {
                if (a[i-1]==b[j-1]){
                    table[i][j] = table[i-1][j-1];
                }
                else {
                    temp = minimum(table[i-1][j-1],table[i][j-1],table[i-1][j]);
                    table[i][j] = temp+1;
                }
            }
            cout<<table[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<"-------------------------"<<endl;
    return table[m][n];
}

int main(){
    string a = "adceg",b = "abcfg";
    int distance = 0;
    distance = editDistance(a,b);
    cout<<"Edit Distance = "<<distance<<endl;
    return 0;
}

