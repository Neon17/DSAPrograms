#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class MaxHeap
{
    vector<int> heap;

    void heapifyUp(int index)
    {
        while (index > 0)
        {
            int parent = (index - 1) / 2;
            if (heap[parent] < heap[index])
            {
                swap(heap[parent], heap[index]);
                index = parent;
            }
            else
            {
                break;
            }
        }
    }

    void heapifyDown(int index)
    {
        int size = heap.size();
        while (index < size)
        {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int largest = index;

            if (left < size && heap[left] > heap[largest])
            {
                largest = left;
            }
            if (right < size && heap[right] > heap[largest])
            {
                largest = right;
            }

            if (largest != index)
            {
                swap(heap[index], heap[largest]);
                index = largest;
            }
            else
            {
                break;
            }
        }
    }

public:
    void insertion(int num)
    {
        heap.push_back(num);
        heapifyUp(heap.size() - 1);
    }

    int deletion()
    {
        if (heap.empty())
            throw invalid_argument("Heap is Empty");

        int max = heap[0];
        heap[0] = heap.back();
        heap.pop_back();

        if (!heap.empty())
        {
            heapifyDown(0);
        }
        return max;
    }

    vector<int> heapSort()
    {
        vector<int> result;
        vector<int> temp = heap;

        while (!heap.empty())
        {
            result.push_back(deletion());
        }
        heap = temp;
        return result;
    }

    bool followRules()
    {
        for (int i = 1; i < heap.size(); i++)
        {
            int parent = (i - 1) / 2;
            if (heap[parent] < heap[i])
            {
                return false;
            }
        }
        return true;
    }

    void printHeap()
    {
        cout << "[";
        for (int i = 0; i < heap.size(); i++)
        {
            if (i != 0)
                cout << ", ";
            cout << heap[i];
        }
        cout << "]" << endl;
    }
};

void printVector(vector<int> sorted)
{
    cout<< "[";
    for (int i = 0; i < sorted.size(); i++)
    {
        if (i != 0)
            cout << ", ";
        cout << sorted[i];
    }
    cout << "]" << endl;
}

int main()
{
    MaxHeap *max = new MaxHeap();
    max->insertion(5);
    max->insertion(12);
    max->insertion(11);
    max->insertion(7);
    max->insertion(3);
    max->insertion(10);
    max->insertion(8);
    // max->printHeap();

    int t = max->deletion();

    cout<<"Original Array = ";
    max->printHeap();

    vector<int> sorted = max->heapSort();
    cout<<"Sorted Array = ";
    printVector(sorted);

    return 0;
}
