#include<bits/stdc++.h>
using namespace std;

//sum of subset problem solved via backtracking
//but any integer it works but don't put -500 in array
//because -500 is used to break one subset from another in vector in this program

void display(int arr[], int length);
void printSubset(int arr[], int length, int targetSum);
void Subset(int arr[], int x[], int length, int targetSum, vector<int>& subset, int pos=0);

int main(){
    int length = 3;
    int arr[length] = {1,2,3};
    int targetSum = 3;
    display(arr,length);
    cout<<"Target Sum = "<<targetSum<<endl;
    printSubset(arr,length,targetSum);
    return 0;
}

void printSubset(int arr[], int length, int targetSum){
    vector<int> subset;
    int x[length],i;
    Subset(arr,x,length,targetSum,subset);
    cout<<"Subsets"<<endl;
    for (i=0;i<subset.size();i++){
        if ((subset.at(i)!=-500)){
            if (i!=0){
                if (subset.at(i-1)==-500){
                    cout<<"{";
                    cout<<subset.at(i);
                    continue;
                }
            }
            else {
                cout<<"{";
                cout<<subset.at(i);
                continue;
            }
            cout<<",";
            cout<<subset.at(i);
            continue;
        }
        cout<<"}"<<endl;
    }
    if (!(subset.empty()))
        cout<<"Total Subset Found = "<<count(subset.begin(), subset.end(), -500)<<endl;
    else 
        cout<<"No Subset Found.."<<endl;
}

void display(int arr[], int length){
    cout<<"Elements of Array = {";
    int i;
    for (i=0;i<length;i++){
        if (i!=0)
            cout<<",";
        cout<<arr[i];
    }
    cout<<"}"<<endl;
}

void Subset(int arr[], int x[], int length, int targetSum, vector<int>& subset, int pos){
    if (length<1)
        return;

    //I have to put some bounding conditions here
    int tempValue = 0,i;
    for(i=0;i<length;i++){
        if (x[i]==1)
            tempValue+=arr[i];
    }
    if (tempValue > targetSum)
        return;

    //base condition
    if (pos == (length)){
        if (tempValue == targetSum){
            for (i=0;i<pos;i++){
                if (x[i] == 1)
                    subset.push_back(arr[i]);
            }
            subset.push_back(-500);
        }
        return;
    }

    //inductive step
    int a[length],b[length];
    if (pos == 0){
        for (i=0;i<length;i++){
            a[i] = 0;
            b[i] = 0;
        }
    }
    else {
        for (i=0;i<length;i++){
            a[i] = x[i];
            b[i] = x[i];
        }
    }
    a[pos] = 0; b[pos] = 1;
    Subset(arr,a,length,targetSum,subset, pos+1);    
    Subset(arr,b,length,targetSum,subset, pos+1);  
}
