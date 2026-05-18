#include <iostream>
#include <chrono>
#include <cmath>
using namespace std;

void changeArr(int *arr, int length);
void display(int arr[],int length,int low = 0, int high = -1);
void initializeArray(int arr[], int length);
void quickSort(int arr[],int length, int low=0,int high=-1);

int main(){

    int arr1[10];
    initializeArray(arr1,10);
    cout<<"Before Sorting.."<<endl;
    display(arr1,10);
    quickSort(arr1,10);
    cout<<"After Sorting.."<<endl;
    display(arr1,10);

    cout<<"-------Checking Time to Sort Larger Set of Data----------"<<endl;
    int length = 100000;
    int arr[length];
    cout<<"Number of Data = "<<length<<endl;

    initializeArray(arr,length);

    auto start2 = std::chrono::high_resolution_clock::now();
    quickSort(arr,length);
    auto finish2 = std::chrono::high_resolution_clock::now();
    chrono::duration<double, milli> elapsed2 = finish2 - start2;
    cout << "Time for Quick Sort = " << elapsed2.count() << " milliseconds"<<endl;

    return 0;
}

void initializeArray(int arr[], int length){
    srand(time(0));
    int i;
    for (i=0;i<length;i++){
        arr[i] = rand()%length+1;
    }
}

void display(int arr[],int length,int low, int high){
    int i;
    if (high == -1){ high = length - 1;}
    cout<<"Elements of Array: ";
    for (i=low;i<=high;i++){
        cout<<arr[i];
        if (i!=(high)){cout<<",";}
    }
    cout<<endl;
}

void quickSort(int arr[], int length,int low, int high){
    if (length <= 1){ return; }
    if ((high-low)==0){ return; }
    if (high == -1){high = length-1;}
    int down= low, up = high;
    int upStatus = 0, downStatus = 0;
    int key = (high+low)/2;
    int Key = arr[key];
    while (true){
        if ((downStatus==0)&&((arr[down]>arr[key])||(down>=high))){
            downStatus = 1;
        }
        if ((upStatus == 0)&&(arr[up]<=arr[key])){
            upStatus = 1;
        }
        if ((upStatus == 1)&&(downStatus == upStatus)){
            if (up>down){
                if (down == key){ key = up; }
                if (up == key){ key = down; }
                arr[down] = arr[down] + arr[up];
                arr[up] = arr[down] - arr[up];
                arr[down] = arr[down] - arr[up];
                downStatus = 0;
                upStatus = 0;
            }
            else {
                if (up!=key){
                    arr[key] = arr[key] + arr[up];
                    arr[up] = arr[key] - arr[up];
                    arr[key] = arr[key] - arr[up];
                    key = up;
                }
                break;
            }
        }
        if (upStatus == 0){ up--; }
        if (downStatus == 0){ down ++; }
    }
    if (up>1)
        quickSort(arr,up-low,low,up-1);
    if ((high-up)>1)
        quickSort(arr,high-up,up+1,high);
}

