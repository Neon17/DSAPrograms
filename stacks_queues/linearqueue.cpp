#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

class Queue {
    int front,rear,data,size;
    int *q;
    public:
        Queue(int size){
            this->size = size;
            q = new int(size);
            front = -1;
            rear = -1;
        }
        void enqueue (int data) {
            if (rear>=(size-1)){
                cout<<"Queue is full..."<<endl;
                return;
            }
            if ((front==-1)&&(rear==-1)){
                front = 0;
            }
            rear++;
            q[rear] = data;
            cout<<"rear = "<<rear;
            cout<<"front = "<<front;
            cout<<"Enqueue success!"<<endl;
        }
        int dequeue () {
            if ((front==-1)&&(rear==-1)){
                cout<<"Queue is Empty.."<<endl;
                throw range_error("Queue is Empty");
            }
            data = q[front];
            front++;
            return data;
        }
        void show() {
            int i;
            cout<<"---------------"<<endl;
            cout<<"Elements of Queue.."<<endl;
            for (i=front;i<=rear;i++){
                cout<<q[i]<<endl;
            }
            cout<<"---------------"<<endl;
        }
};

int main() {
    Queue q(5);
    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(15);
    q.enqueue(20);
    q.show();
    cout<<"Elements Deleted: "<<q.dequeue()<<endl;
    q.show();
    cout<<"Elements Deleted: "<<q.dequeue()<<endl;
    q.show();
    cout<<"Elements Deleted: "<<q.dequeue()<<endl;
    q.show();
    cout<<"Elements Deleted: "<<q.dequeue()<<endl;
    q.show();
    q.enqueue(78);
    q.show();
    q.enqueue(60);
    q.show();
    return 0;
}