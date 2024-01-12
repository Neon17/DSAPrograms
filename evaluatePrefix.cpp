#include <iostream>
#include <cmath>
using namespace std;

int evaluatePrefix(char a[],int size);
int doOperator(char op, int op1, int op2);

class Stack{
    int *stk;
    int size;
    int tos;

    public:

    Stack(int size){
        this->size = size;
        stk = new int(size);
        tos = -1;
    }

    void push(int data){
        if (isFull()){
            cout<<"Stack is full.."<<endl;
            return;
        }
        tos++;
        stk[tos] = data;
    }
    bool isFull() {
        if (tos==(size-1)){
            return true;
        }
        return false;
    }
    bool isEmpty() {
        if (tos==-1){
            return true;
        }
        return false;
    }
    int pop(){
        if (isEmpty()){
            throw range_error("Invalid Expression..");
        }
        int m = stk[tos];
        stk[tos] = '\0';
        tos--;
        return m;
    }
    void show() {
        int i;
        cout<<"---------------"<<endl;
        cout<<"Elements of Stack..."<<endl;
        for (i=tos;i>=0;i--){
            cout<<stk[i]<<endl;
        }
        cout<<stk<<endl;
        cout<<"---------------"<<endl;
    }
};

int main() {
    cout<<"This program only works for single digit prefix"<<endl;
    char a[] = "65+4*3-";
    cout<<"Postfix Expression = "<<a<<endl;
    cout<<"Answer = "<<evaluatePrefix(a,sizeof(a))<<endl;
    return 0;
}

int evaluatePrefix(char a[],int size){
    cout<<"size = "<<size<<endl;
    Stack s(size);
    int i = 0;
    for (i=0;i<(size-1);i++){
        if (!((a[i]=='$')||(a[i]=='/')||(a[i]=='*')||(a[i]=='+')||(a[i]=='-'))){
            int m = int(a[i])-int('0');
            cout<<m<<endl;
            s.push(m);
        }
        else {
            int m2 = s.pop();
            int m1 = s.pop();
            s.push(doOperator(a[i],m1,m2));
        }
    }
    return s.pop();
}

int doOperator(char op, int op1, int op2){
    int a,b;
    a = op1;
    b = op2;
    if (op=='+')
        return a+b;
    else if (op=='-')
        return a-b;
    else if (op=='*')
        return a*b;
    else if (op=='/')
        return a/b;
    else if (op=='$')
        return pow(a,b);
    return '\0';    
}