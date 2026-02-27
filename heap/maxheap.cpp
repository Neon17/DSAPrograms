#include <iostream>
#include <vector>
using namespace std;

// Base Level Implementation of Heap using Vector
// Highest Priority is removed first

class MaxHeap
{
    vector<int> priority; 

    /**
     * int * priority;
     * priority = new int[capacity];
     * priority is a dynamic array which will be used to store the heap elements.
     */

    private:

        void heapifyUp(int index){
            // heapifyUp is the operation of putting the latest inserted downward node upward
            int parent = 0;

            while (index != 0){
                parent = (index - 1)/2;
                
                if (priority[parent] < priority[index]){
                    swap(priority[parent], priority[index]);
                } else break;
                index = parent;
            }                        
        }

        void heapifyDown(int index){
            // heapifyDown is the operation of putting the latest removed top node downward
            int child = (index + 1)*2-1;
            int size = getSize();
            int larger = -1;            

            while (child < size){
                larger = -1;
                
                if (child+1 < size){
                    larger = (priority[child] > priority[child+1])? child: child+1;
                } else {
                    larger = child;
                }

                if (priority[index] > priority[larger]) break;
                swap(priority[larger], priority[index]);
                index = larger;

                child = (index + 1)*2-1;
            }
        }

    public:
        MaxHeap() {
            priority.clear();
        }

        bool isEmpty() {
            return getSize() == 0;
        }

        int getSize(){
            return priority.size();
        }

        void insert(int num){
            priority.push_back(num);
            heapifyUp(getSize()-1);
        }

        void remove(){
            if (isEmpty()) return;
            int size = getSize();
            priority[0] = priority[size-1];
            priority.pop_back();
            heapifyDown(0);
        }

        int getMax(){
            if (isEmpty()) return -1;
            return priority[0];
        }
};


int main()
{
    MaxHeap* heap = new MaxHeap();
    int temp;

    int arr[] = {17, 10, 15, 19, 25, 20, 30};
    int n = sizeof(arr)/sizeof(arr[0]);

    // the below loop is heap sort
    for (int i=0;i<n;i++){
        heap->insert(arr[i]); // O(log n) time complexity for insertion using heapify
    }

    vector<int> maxHeap;
    // now checking the heap access, and removal operation
    for (int i=0;i<n;i++){
        temp = heap->getMax();
        heap->remove();
        maxHeap.push_back(temp);
    }

    cout<<"Max Heap popup Operation"<<endl;
    cout<<"[";
    for (int i=0;i<n;i++){
        if (i != 0) cout<<", ";
        cout<<maxHeap[i];
    }
    cout<<"]"<<endl;

    delete heap;
    return 0;
}