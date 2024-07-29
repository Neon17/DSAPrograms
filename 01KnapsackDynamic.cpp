//Solving Knapsack using dynamic programming

#include <bits/stdc++.h>
using namespace std;

class Knapsack {
    int itemCount, capacity;
    int *x, *p, *w;
    public: 
    Knapsack (int itemCount, int capacity){
        this->itemCount = itemCount;
        x = new int[itemCount];
        p = new int[itemCount];
        w = new int[itemCount];
        this->capacity = capacity;
    }
    Knapsack (){
        this->itemCount = 4;
        x = new int[itemCount];
        p = new int[itemCount];
        w = new int[itemCount];
        this->capacity = 8;
    }
    //fill by p,w 1,2 2,3 5,4 6,5
    void fill(){
        int i;
        for (i=0;i<itemCount;i++){
            cout<<"Profit = ";
            cin>>p[i];
            cout<<"Weight = ";
            cin>>w[i];
            x[i] = 0;
        }
    }
    void randomFill(){
        int i;
        p[0] = 1; p[1] = 2; p[2] = 5; p[3] = 6;
        w[0] = 2; w[1] = 3; w[2] = 4; w[3] = 5;
        for (i=0;i<itemCount;i++){
            x[i] = 0;
        }
    }
    void solve(){
        //filling the column
        int a[itemCount+1][capacity+1];
        int i,j,t;
        for (i=0;i<=itemCount;i++){
            for (j=0;j<=capacity;j++){
                if ((j==0)||(i==0)){
                    a[i][j] = 0;
                    continue;
                }
                // cout<<i<<"\t"<<j<<endl;
                if ((j-w[i-1])>=0){
                    t = a[i-1][j-w[i-1]]+p[i-1];
                    if (t>a[i-1][j])
                        a[i][j] = t; 
                    else 
                        a[i][j] = a[i-1][j];
                    continue;
                }
                a[i][j] = a[i-1][j];
            }
        }
        //now evaluating
        //below code works fine if remProfit is exact profit of some item after first subtraction but not combination of 2 or more item
        int totalProfit = a[itemCount][capacity], remProfit = totalProfit;
        int item,change = 0;
        cout<<"Total Profit = "<<totalProfit<<endl;
        while(remProfit!=0){
            if (remProfit == totalProfit){
                for (i=1;i<=itemCount;i++){
                    if (remProfit == a[i][capacity]){
                        x[i-1] = 1;
                        item = i;
                        remProfit -= p[i-1];
                        cout<<remProfit<<endl;
                        break;
                    }
                }
                continue;
            }
            for (i=1;i<item;i++){
                for (j=1;j<=capacity;j++){
                    if (remProfit == a[i][j]){
                        x[i-1] = 1;
                        item = i;
                        change = 1;
                        remProfit -= p[i-1];
                        cout<<remProfit<<endl;
                        break;
                    }
                }
                if (change == 1){change = 0;break;}
            }
        }
    }
    void printSolution(){
        int i;
        cout<<"x = {";
        for (i=0;i<itemCount;i++){
            if (i==0)
                cout<<x[i];
            else
                cout<<","<<x[i];
        }
        cout<<"}"<<endl;
    }
};

int main(){
    Knapsack ks;
    ks.randomFill();
    ks.solve();
    ks.printSolution();
    return 0;
}
