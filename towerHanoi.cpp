#include <iostream>
using namespace std;

void solveTowerHanoi(int n);
void move(int source, int des, int chipSize, int chipNumber);
void display();
void cleanMemory();

class Stack {
    int tos;
    int *stk;
    int size;
    
    public:

    // static int sourceTower = 0;
    // static int destTower = 2;
    // static int temTower = 1;
    
    Stack(int size) {
        this->size = size;
        stk = new int(size);
        tos = -1;
        int i;
        for (i=0;i<size;i++){
            stk[i] = 0;
        }
    }
    void push(int data){
        if (isFull()){
            cout<<"Stack is full.."<<endl;
            return;
        }
        tos++;
        stk[tos] = data;
    }
    int pop(){
        if (isEmpty()){
            throw range_error("Stack is empty..");
        }
        int m = stk[tos];
        stk[tos] = 0;
        tos--;
        return m;
    }
    bool isFull() {
        if (tos>=(size-1))
            return true;
        return false;
    }
    bool isEmpty() {
        if (tos==-1)
            return true;
        return false;
    }
    void show() {
        cout<<"-------Elements in Stack-------"<<endl;
        int i;
        for (i=tos;i>=0;i--){
            cout<<stk[i]<<endl;
        }
        cout<<"-------------------------------"<<endl;
    }

    int getSize (){
        return size;
    }
    int getIndex(int index){
        if ((index<0)&&(index>tos)){
            return 0;
        }
        return stk[index];
    }
    ~Stack() {
        delete stk;
    }
};

//3 stacks for 3 tower in tower of hanoi
Stack *s[3];

int main() {
    int a;
    cout<<"How many disk you want in tower to solve?"<<endl;
    cout<<"Please don't say much because it will eat your RAM"<<endl;
    cout<<"Enter the number of disk: ";
    cin>>a;
    solveTowerHanoi(a);
    cleanMemory();
    return 0;
}

void initializeStack(int n){
    s[0] = new Stack(n);
    s[1] = new Stack(n);
    s[2] = new Stack(n);

    int i;
    for (i=n;i>=1;i--){
        s[0]->push(i);
    }

    display();
}

void solveTowerHanoi(int n){
    // n is number of disc 
    initializeStack(n);
    move(0,2,n,n);
    //First of all putting all disc in 0 (source)
    //0 = source, 1 = temporary, 2 = destination
}

void move(int source, int des, int chipSize, int chipNumber){
    int tem = 3 - (source+des);
    if (chipNumber==1){
        s[des]->push(s[source]->pop());
        display();
        return;
    }
    if (chipSize == 2){
        //for 2 disks from source to destination
        s[tem]->push(s[source]->pop());
        display();
        s[des]->push(s[source]->pop());
        display();
        s[des]->push(s[tem]->pop());
        display();
    }
    else {
        move(source, tem, (chipSize-1), (chipNumber-1));
        move(source, des, chipSize, 1);
        move(tem, des, chipSize-1, chipNumber-1);
    }
}

void display(){
    int size = s[0]->getSize();
    int a,b,c;
    int i;
    cout<<"----------------------------"<<endl;
    cout<<"       Tower of Hanoi       "<<endl;
    for (i=(size-1);i>=0;i--){
        a = s[0]->getIndex(i);
        b = s[1]->getIndex(i);
        c = s[2]->getIndex(i);
        if (a==0)
            cout<<"-\t";
        else 
            cout<<a<<"\t";
        if (b==0)
            cout<<"-\t";
        else 
            cout<<b<<"\t";
        if (c==0)
            cout<<"-\t";
        else 
            cout<<c<<"\t";

        cout<<endl;
    }
    cout<<"----------------------------"<<endl;
}

void cleanMemory() {
    delete[] s;
}

