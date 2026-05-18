#include <iostream>
using namespace std;

struct item {
    int item;
    int priority;
};

class PriorityQueue {
    item *q;
    int size;
    int front = -1, rear = -1;
    
    public:
        PriorityQueue(int size){
            this->size = size;
            q = (item*)malloc(sizeof(item)*size);
        }

        void enqueue (int data, int priority){
            if ((((rear+1)%size))==front){
                cout<<"Stack is full.. Stack Overflow..."<<endl;
                return;
            }
            rear = (rear + 1)%size;
            if (front == -1)
                front = 0;
            int pos = -1, i;
            for (i=front;i!=rear;i=(i+1)%size){
                if (priority>q[i].priority)
                    pos = i;
            }
            if (pos != -1){
                for (i=(rear-1)%size;i!=pos;(i==0)?i=(size-1):i--){
                   q[(i+1)%size] = q[i]; 
                }
                q[(pos+1)%size] = q[pos];
                q[pos].item = data;
                q[pos].priority = priority;
            }
            else {
                q[rear].item = data;
                q[rear].priority = priority;
            }
        }

        int dequeue(){
            if (rear == front){
                front = -1;
                rear = -1;
            }
            int data;
            data = q[front].item;
            front = (front+1)%size;
            return data;
        }

        void display(){
            int i;
            cout<<endl;
            cout<<"Items in Queue: ";
            for (i=front;i!=rear;i++){
                cout<<q[i].item<<",";
            }
            cout<<q[rear].item<<endl;
        }
};

int main() {
    cout<<"Hello World!"<<endl;
    PriorityQueue pq(5);
    pq.enqueue(5,3);
    pq.enqueue(6,4);
    pq.display();
    cout<<"Deleted Item: "<<pq.dequeue()<<endl;
    pq.display();
    return 0;
} 

