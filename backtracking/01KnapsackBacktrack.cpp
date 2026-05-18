#include <bits/stdc++.h>
using namespace std;

//We solved Knapsack problem by backtracking

struct item{
    float profit,weight;
};

void printKnapsack(item arr[], int length, int capacity);
void KnapsackSubset(item arr[], int length, int *x, int capacity, vector<int>& solution, int totalWeight=0, int pos = 0);

int main(){
    item arr[4];
    arr[0].profit = 15;
    arr[1].profit = 20;
    arr[2].profit = 5;
    arr[3].profit = 25;
    arr[0].weight = 5;
    arr[1].weight = 4;
    arr[2].weight = 1;
    arr[3].weight = 5;
    printKnapsack(arr,4,5);
    return 0;
}

void printKnapsack(item arr[], int length, int capacity){
    int x[length],i;
    vector<int> solution;
    KnapsackSubset(arr,length,x,capacity,solution);
    if (solution.empty()){
        cout<<"No solution can be found.."<<endl;
        return;
    }
    cout<<"Solution Size = "<<solution.size()<<endl;
    for (i=0;i<solution.size();i++){
        if (solution.at(i)==-500){
            cout<<"}"<<endl;
            continue;
        }
        if ((i!=0)){
            if ((solution.at(i-1)) == -500){
                cout<<"{";
                cout<<solution.at(i);
                continue;
            }
            cout<<","<<solution.at(i);
            continue;
        }
        cout<<"{"<<solution.at(i);
    }
}

void KnapsackSubset(item arr[], int length, int *x, int capacity, vector<int>& solution, int totalWeight, int pos){
    int i;

    //I have to put some bounding conditions here
    if (totalWeight < 0)
        return;
    
    //base condition
    if (pos == (length)){
        int status = 0,totalProfit=0,currentProfit=0;
        if (!(solution.empty())){
            for (i=0;i<solution.size();i++){
                if (solution.at(i)==-500)
                    break;
                if (solution.at(i)==1)
                    totalProfit += arr[i].profit;
            }
        }
        for (i=0;i<length;i++){
            if (x[i] == 1)
                currentProfit += arr[i].profit;
        }
        if (currentProfit>totalProfit){
            solution.clear();
        }
        if ((currentProfit>=totalProfit)||(solution.empty())){
            for (i=0;i<length;i++){
                solution.push_back(x[i]);
            }
            solution.push_back(-500);
        }
        return;
    }

    //inductive step
    if (pos == 0){
        totalWeight = capacity;
        for (i=0;i<length;i++){
            x[i] = 0;
        }
    }
    int a[length],b[length];
    for (i=0;i<length;i++){
        a[i] = x[i]; b[i] = x[i];
    }
    int tempWeight;
    tempWeight = totalWeight;
    tempWeight -= arr[pos].weight;
    b[pos] = 1;

    //exclude status
    KnapsackSubset(arr,length,a,capacity,solution,totalWeight,pos+1);

    //include status
    totalWeight = tempWeight;
    KnapsackSubset(arr,length,b,capacity,solution,tempWeight,pos+1);
}
