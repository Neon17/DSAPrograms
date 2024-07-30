#include <iostream>
#include <chrono>
using namespace std;

void mergeSort(int arr[], int low, int high);
void merge(int arr[], int low, int high, int mid);

void randomFill(int arr[], int length);
void display(int arr[], int length);

int main(){
    // int length = 10;
    // int arr[length];
    // randomFill(arr,length);
    // display(arr,length);
    // mergeSort(arr,0,length-1);
    // display(arr,length);

    int length = 100000;
    int arr[length];
    randomFill(arr,length);

    cout<<"Number of data = "<<length<<endl;
    auto start2 = std::chrono::high_resolution_clock::now();
    mergeSort(arr,0,length-1);
    auto finish2 = std::chrono::high_resolution_clock::now();
    chrono::duration<double, milli> elapsed2 = finish2 - start2;
    cout << "Time for Merge Sort = " << elapsed2.count() << " milliseconds"<<endl;

    return 0;
}

void randomFill(int arr[], int length){
    int i,temp;
    for (i=0;i<length;i++){
        arr[i] = rand()%(length+1);
    }
}

void display(int arr[], int length){
    cout<<endl;
    cout<<"Elements of Array = {";
    int i;
    for (i=0;i<length;i++){
        if (i==0){
            cout<<arr[i];
            continue;
        }
        cout<<","<<arr[i];
    }
    cout<<"}"<<endl;
}

void merge(int arr[], int low, int high, int mid){
    // low to mid and mid+1 to high is already sorted
    // we have to merge them in order
    int subArrayOne = mid - low + 1;
    int subArrayTwo = high - mid;
    int *leftArray = new int[subArrayOne];
    int *rightArray = new int[subArrayTwo];
    int i;
    for (i=0;i<subArrayOne;i++)
        leftArray[i] = arr[low+i];
    for (i=0;i<subArrayTwo;i++)
        rightArray[i] = arr[mid+1+i];
    int indexa = 0, indexb = 0;
    for (i=low;i<=high;i++){
        if ((indexb<subArrayTwo)&&(rightArray[indexb]<leftArray[indexa])){
            arr[i] = rightArray[indexb];
            indexb++;
        }
        else {
            arr[i] = leftArray[indexa];
            indexa++;
        }
    }
    delete[] leftArray;
    delete[] rightArray;
}

void mergeSort(int arr[], int low, int high){
    if ((high-low)==0)
        return;
    else if ((high-low)==1){
        int temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;
    }
    int mid;
    mid = (high+low)/2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr, low, high, mid);
}